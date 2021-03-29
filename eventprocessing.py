from nail.nail import *
import ROOT
import sys

def getFlow(year):
    FSR=True
    FSRnew=False
    FSRnew=True
    #flow=SampleProcessing("VBF Hmumu Analysis","/scratch/arizzi/Hmm/nail/samples/6B8A2AC8-35E6-1146-B8A8-B1BA90E3F3AA.root"
    flow=SampleProcessing("VBF Hmumu Analysis","/scratchssd/thakore/PROD_2_2/vbfHmm_2026POWPY.root")
    
#    ##FIXME## SD
    #variables that we will add file by file before passing the RNode to the event processor
    
    flow.AddExpectedInput("year","int")
    flow.AddExpectedInput("TriggerSel","bool")
    
    #Higgs to mumu reconstruction
    #flow.DefaultConfig(muIsoCut=0.25,muIdCut=2,muPtCut=20, dzCut=1e99,dxyCut=1e99) #cuts value should not be hardcoded below but rather being declared here so that scans and optimizations are possible
    flow.Define("Muon_mass","0.f*Muon_pt")
    flow.Define("Muon_iso","Muon_isolationvarrhocorr") ## Delphes variables: Muon_sumptneutral, Muon_sumpt, Muon_sumptchargedpu, Muon_sumptcharged, Muon_isolationvarrhocorr, Muon_isolationvar. No Muon ID variables available!
    flow.Define("Muon_p4","vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Muon_pt , Muon_eta, Muon_phi, Muon_mass)")
    
    ###################################   Phase1 ##################
    ##Jet Selection. FIXME: Missing Muon ID, Muon Isolation
    #see https://github.com/delphes/delphes/blob/master/modules/Isolation.cc#L247
    #https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideMuonIdRun2#Particle_Flow_isolation
    flow.SubCollection("SelectedMuonPhase1","Muon",sel="abs(Muon_eta) < 2.4 && (Muon_isolationvar)<0.25") ### I've put a simple selection as example
    flow.Selection("twoUnpreselMuonsPhase1","nMuon>=2")
    flow.Selection("twoMuonsPhase1","nSelectedMuonPhase1==2")

    ## Get the pair of opposite side muons, 
    flow.Distinct("MuMuPhase1","SelectedMuonPhase1")
    flow.Define("OppositeSignMuMuPhase1","Nonzero(MuMuPhase10_charge != MuMuPhase11_charge)",requires=["twoMuonsPhase1"])
    flow.Selection("twoOppositeSignMuonsPhase1","OppositeSignMuMuPhase1.size() > 0")
    flow.TakePair("MuPhase1","SelectedMuonPhase1","MuMuPhase1","At(OppositeSignMuMuPhase1,0,-200)",requires=["twoOppositeSignMuonsPhase1"])
             
    flow.Define("Higgs_Phase1","MuPhase10_p4+MuPhase11_p4")
    
#    flow.Define("Jet_p4","vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Jet_pt , Jet_eta, Jet_phi, Jet_mass)")
#    flow.Define("JetPUPPI_p4","vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(JetPUPPI_pt , JetPUPPI_eta, JetPUPPI_phi, JetPUPPI_mass)")
    

    
    #VBF Jets kinematics
    flow.DefaultConfig(jetPtCut=25)

## Jet Cleaning:    
#    flow.SubCollection("JetToUse","JetPUPPI","JetPUPPI_pt>0") ### Redefinition

#    ###For jet cleaning
#    flow.MergeCollections("Lepton",["Muon","Electron"])
#    flow.SubCollection("SelectedLepton","Lepton","Lepton_pt > 10")
#    flow.MatchDeltaR("JetToUse","SelectedLepton")
        
#    flow.Define("JetToUse_p4","vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(JetToUse_pt , JetToUse_eta, JetToUse_phi, JetToUse_mass)")

#    flow.SubCollection("SelectedJet","JetToUse",'''
#    JetToUse_pt > jetPtCut && abs(JetToUse_eta) < 4.7
#    &&     (JetToUse_SelectedLeptonIdx==-1 || JetToUse_SelectedLeptonDr > 0.4)

    flow.Define("Jet_p4","vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Jet_pt , Jet_eta, Jet_phi, Jet_mass)")

    ##Jet Selection. FIXME: Missing Jet ID, JetPU ID
    flow.SubCollection("SelectedJetPhase1","Jet",'''
    Jet_pt > jetPtCut && abs(Jet_eta) < 4.7
    ''')
    
    flow.Selection("twoJetsPhase1","nSelectedJetPhase1>=2")
    
    flow.Distinct("JetPairPhase1","SelectedJetPhase1")
    flow.Define("SortedSelectedJetPhase1Indices","Argsort(-SelectedJetPhase1_pt)")
    flow.ObjectAt("QJetPhase1_0","SelectedJetPhase1",'At(SortedSelectedJetPhase1Indices,0)',requires=["twoJetsPhase1"])
    flow.ObjectAt("QJetPhase1_1","SelectedJetPhase1",'At(SortedSelectedJetPhase1Indices,1)',requires=["twoJetsPhase1"])

    #compute number of softjets removing signal footprint
    flow.Define("SoftActivityJet_mass","SoftActivityJet_pt*0")
    flow.Define("SoftActivityJet_p4","@p4v(SoftActivityJet)")
    flow.Match("SelectedJetPhase1","SoftActivityJet") #associate signal jets
    flow.Match("SelectedMuonPhase1","SoftActivityJet") #associate signal muons
    
    flow.Define("qqPhase1","QJetPhase1_0_p4+QJetPhase1_1_p4")
    flow.Define("MqqPhase1","qqPhase1.M()")
    flow.Define("qqPhase1_pt","qqPhase1.Pt()")
    flow.Define("qqDeltaEtaPhase1","abs(QJetPhase1_0_eta-QJetPhase1_1_eta)")
    flow.Define("qqDeltaPhiPhase1","abs(ROOT::Math::VectorUtil::DeltaPhi(QJetPhase1_0_p4,QJetPhase1_1_p4))")

    #QQ vs ll kinematic
    flow.Define("ll_ystarPhase1","Higgs_Phase1.Rapidity() - (QJetPhase1_0_p4.Rapidity() + QJetPhase1_1_p4.Rapidity())/2.f")
    flow.Define("ll_zstarPhase1"," abs( ll_ystar/ (QJetPhase1_0_p4.Rapidity()-QJetPhase1_1_p4.Rapidity() )) ")
    flow.Define("ll_zstarPhase1_log"," log(ll_zstarPhase1) ")
    flow.Define("ll_zstarbugPhase1_log","log(abs( (  Higgs_Phase1.Rapidity() - (QJetPhase1_0_p4.Rapidity() + QJetPhase1_1_p4.Rapidity())  )/ (QJetPhase1_0_p4.Rapidity()-QJetPhase1_1_p4.Rapidity() )))")
    flow.Define("DeltaEtaQQSumPhase1","abs(QJetPhase1_0_eta) +  abs(QJetPhase1_1_eta)")
    flow.Define("PhiHQ1Phase1","abs(ROOT::Math::VectorUtil::DeltaPhi(Higgs_Phase1,QJetPhase1_0_p4))")
    flow.Define("PhiHQ2Phase1","abs(ROOT::Math::VectorUtil::DeltaPhi(Higgs_Phase1,QJetPhase1_1_p4))")
    flow.Define("EtaHQ1Phase1","abs(Higgs_Phase1.Eta() - QJetPhase1_0_eta)")
    flow.Define("EtaHQ2Phase1","abs(Higgs_Phase1.Eta() - QJetPhase1_1_eta)")
    flow.Define("DeltaRelQQPhase1","(QJetPhase1_0_p4+QJetPhase1_1_p4).Pt()/( QJetPhase1_0_p4.Pt()+QJetPhase1_1_p4.Pt())")
    flow.Define("RptPhase1","(QJetPhase1_0_p4+QJetPhase1_1_p4+ Higgs).Pt()/( QJetPhase1_0_p4.Pt()+QJetPhase1_1_p4.Pt() + Higgs_Phase1.Pt())")
    #flow.Define("mmjj","Higgs+qq")
    flow.Define("theta2Phase1","Higgs_Phase1.Vect().Dot(QJetPhase1_1_p4.Vect())/QJetPhase1_1_p4.Vect().R()/HiggsPhase1.Vect().R()")
    flow.ObjectAt("LeadMuonPhase1","SelectedMuonPhase1","0",requires=["twoMuonsPhase1"])
    flow.ObjectAt("SubMuonPhase1","SelectedMuonPhase1","1",requires=["twoMuonsPhase1"])
    flow.Define("Higgs_Phase1_pt","Higgs_Phase1.Pt()")
    flow.Define("Higgs_Phase1_rapidity","Higgs_Phase1.Rapidity()")

    #HT definition in the generator: https://github.com/cms-sw/genproductions/blob/master/bin/MadGraph5_aMCatNLO/cards/production/2017/13TeV/DYJets_HT_LO_MLM/DYJets_HT_mll50/DYJets_HT-400to600/DYJets_HT-400to600_run_card.dat
    flow.SubCollection("GenJetForHT","GenJet",'''
    GenJet_pt > 30 && abs(GenJet_eta) < 5.0 && GenJet_mass>1.5
    ''')
    flow.MatchDeltaR("GenJetForHT","SelectedLepton")
    flow.SubCollection("CleanGenJetForHT","GenJetForHT",'''
    (GenJetForHT_SelectedLeptonIdx==-1 || GenJetForHT_SelectedLeptonDr > 0.4)
    ''')
    
    flow.Define("GenJetHT","Sum(CleanGenJetForHT_pt)")

    flow.SubCollection("JetForHT","Jet",'''
    Jet_pt > 0 && abs(Jet_eta) < 5.0 && Jet_flavour!=0
    ''')
    flow.MatchDeltaR("JetForHT","SelectedLepton")
    flow.SubCollection("CleanJetForHT","JetForHT",'''
    (JetForHT_SelectedLeptonIdx==-1 || JetForHT_SelectedLeptonDr > 0.4)
    ''')
    
    flow.Define("JetHT","Sum(CleanJetForHT_pt)")
    
    flow.SubCollection("JetPUPPIForHT","JetPUPPI",'''
    JetPUPPI_pt > 0 && abs(JetPUPPI_eta) < 5.0 && JetPUPPI_flavour!=0
    ''')
    flow.MatchDeltaR("JetPUPPIForHT","SelectedLepton")
    flow.SubCollection("CleanJetPUPPIForHT","JetPUPPIForHT",'''
    (JetPUPPIForHT_SelectedLeptonIdx==-1 || JetPUPPIForHT_SelectedLeptonDr > 0.4)
    ''')
    flow.Define("JetPUPPIHT","Sum(CleanJetPUPPIForHT_pt)")

    flow.Define("pTbalanceLead","QJet0_pt/Higgs_pt")
    #flow.Define("pTbalance","qq.Pt()/Higgs_pt")
    flow.Define("yield","1")
    flow.Define("pTbalanceLeadPhase1","QJetPhase1_0_pt/Higgs_Phase1_pt")
    #flow.Define("pTbalance","qq.Pt()/Higgs_pt")
    flow.Define("pTbalanceAllPhase1","SumDef(SelectedJetPhase1_p4).pt()/Higgs_Phase1_pt")
    flow.Define("pTbalanceAllPhase1Log","log(pTbalanceAllPhase1)")
    flow.Define("pTbalancePhase1Log","log(pTbalancePhase1)")
    flow.Define("pTbalanceLeadPhase1Log","log(pTbalanceLeadPhase1)")
    flow.Define("Higgs_Phase1_m","Higgs_Phase1.M()")
    flow.Define("Higgs_Phase1_eta","Higgs_Phase1.Eta()")
    flow.Define("Higgs_Phase1_m_uncalib","Higgs_Phase1_Uncalib.M()")
    flow.Define("MqqPhase1_log","log(MqqPhase1)")
    flow.Define("MqqPhase1_over400_log","log(MqqPhase1/400)")
    flow.Define("mmjj_Phase1_pt","mmjj_Phase1.Pt()")
    flow.Define("mmjj_Phase1_pt_log","log(mmjj_Phase1_pt)")
    flow.Define("mmjj_Phase1_pz","mmjj_Phase1.Pz()")
    flow.Define("mmjj_Phase1_pz_logabs","log(abs(mmjj_Phase1_pz))")
    flow.Define("MaxJetAbsEta_Phase1","std::max(std::abs(QJetPhase1_0_eta), std::abs(QJetPhase1_1_eta))")
    flow.Define("minEtaHQPhase1","std::min(abs(EtaHQ1Phase1),(EtaHQ2Phase1))")
    flow.Define("minPhiHQPhase1","std::min(abs(PhiHQ1Phase1),abs(PhiHQ2Phase1))")


    flow.AddCppCode('\n#include "boost_to_CS.h"\n')
    flow.Define("CS_Phase1_theta","boost_to_CS(LeadMuonPhase1_p4, SubMuonPhase1_p4,  SubMuonPhase1_charge).first",requires=["twoOppositeSignMuonsPhase1"])
    flow.Define("CS_Phase1_phi","boost_to_CS(LeadMuonPhase1_p4, SubMuonPhase1_p4, SubMuonPhase1_charge).second",requires=["twoOppositeSignMuonsPhase1"])

    flow.DefaultConfig(higgsMassWindowWidth=10,mQQcut=400,nominalHMass=125.03) #,btagCut=0.8)
    ## no b-tag discriminant in delphes, just 0 or 1
    flow.Define("SelectedJetPhase1btagDeepB","SelectedJetPhase1_btag") ##FIXME: use actual b-tagging
    flow.Define("btagCut","0.5")
    flow.Define("btagCutL","0.5")
    #adding for sync
    flow.Define("nbtaggedPhase1","int(Nonzero(SelectedJetPhase1btagDeepB > btagCut && abs(SelectedJetPhase1_eta)< 2.5).size())")
    flow.Define("nbtaggedLPhase1","int(Nonzero(SelectedJetPhase1btagDeepB > btagCutL && abs(SelectedJetPhase1_eta)< 2.5).size())")
    flow.Define("nelectronsPhase1","int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size())")


    #flow.Selection("MassWindow","Higgs.M()")
    flow.Selection("MassWindowZPhase1","abs(Higgs_Phase1.M()-91)<15")
    flow.Selection("VBFRegionPhase1","MqqPhase1 > mQQcut && QJetPhase1_0_pt> 35 && QJetPhase1_1_pt > 25")
    flow.Selection("PreSelPhase1","nelectronsPhase1==0 && nbtaggedLPhase1 < 2 && VBFRegionPhase1 && twoOppositeSignMuonsPhase1 && nbtaggedPhase1 < 1 && (( year == 2016 && LeadMuonPhase1_pt > 26 ) || ( year == 2017 && LeadMuonPhase1_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuonPhase1_pt > 26 )) && SubMuonPhase1_pt > 20 && TriggerSel && abs(SubMuonPhase1_eta) <2.4 && abs(LeadMuonPhase1_eta) < 2.4",requires=["VBFRegionPhase1","twoOppositeSignMuonsPhase1"])
    #flow.Selection("SideBand","Higgs_m < 150 && Higgs_m > 110 && ! MassWindow && VBFRegion &&  qqDeltaEta > 2.5",requires=["VBFRegion","PreSel"])
    flow.Selection("SignalRegionPhase1","VBFRegionPhase1 && qqDeltaEtaPhase1 > 2.5", requires=["VBFRegionPhase1","PreSelPhase1"]) ##FIXME qqDeltaEta > 2.5
    flow.Selection("InclusiveRegionPhase1","1")    #flow.Selection("ZRegion","VBFRegion && MassWindowZ  && qqDeltaEta > 2.5", requires=["VBFRegion","MassWindowZ","PreSel"])

    #flow.Define("Muonsum_ptHT", "LeadMuon_pt + SubMuon_pt")
    #flow.Selection("SelectionTest1", "LeadMuon_pt > 50")
    
#    flow.Selection("SelectionTest2","VBFRegion ", requires=["VBFRegion","PreSel"])
#    flow.Selection("SelectionTest3","qqDeltaEta > 2.5", requires=["VBFRegion","PreSel"])
#    flow.Selection("SelectionTest4","1", requires=["VBFRegion","PreSel"])
#    flow.Selection("SelectionTest5","VBFRegion &&  qqDeltaEta > 2.5")
#    flow.Selection("SelectionTest6","qqDeltaEta > 2.5", requires=["PreSel"])

    #flow.Selection("ZRegionSMP","Mqq > 250 && MassWindowZ && QJet0_pt> 50 && QJet1_pt > 30 && twoOppositeSignMuons && twoJets && TriggerSel&& abs(SubMuon_eta) <2.4 && abs(LeadMuon_eta) < 2.4 ", requires=["twoOppositeSignMuons","twoJets"])
    flow.Selection("TwoJetsTwoMuPhase1","twoJetsPhase1 && twoOppositeSignMuonsPhase1", requires=["twoJetsPhase1","twoOppositeSignMuonsPhase1"])
    #flow.Selection("SignalRegionPhase1T","SignalRegionPhase1 && QJet0_pt>45 && QJet1_pt > 27",requires=["SignalRegionPhase1"])
    flow.Selection("ZRegionTPhase1","ZRegionPhase1 && QJetPhase1_0_pt>45 && QJetPhase1_1_pt > 27",requires=["ZRegionPhase1"])
    flow.Selection("SideBandTPhase1","SideBandPhase1 && QJetPhase1_0_pt>45 && QJetPhase1_1_pt > 27",requires=["SideBandPhase1"])
        #with bug
    #flow.Define("HT","Sum(qq_pt)")

############################################################################ Phase2 ################################################################################
   
    ##Jet Selection. FIXME: Missing Muon ID, Muon Isolation
    flow.SubCollection("SelectedMuonPhase2","Muon",sel="abs(Muon_eta) < 2.8") ### I've put a simple selection as example
    flow.Selection("twoUnpreselMuonsPhase2","nMuon>=2")
    flow.Selection("twoMuonsPhase2","nSelectedMuonPhase2==2")

    ## Get the pair of opposite side muons, 
    flow.Distinct("MuMuPhase2","SelectedMuonPhase2")
    flow.Define("OppositeSignMuMuPhase2","Nonzero(MuMuPhase20_charge != MuMuPhase21_charge)",requires=["twoMuonsPhase2"])
    flow.Selection("twoOppositeSignMuonsPhase2","OppositeSignMuMuPhase2.size() > 0")
    flow.TakePair("MuPhase2","SelectedMuonPhase2","MuMuPhase2","At(OppositeSignMuMuPhase2,0,-200)",requires=["twoOppositeSignMuonsPhase2"])
             
    flow.Define("Higgs_Phase2","MuPhase20_p4+MuPhase21_p4")
          
    #VBF Jets kinematics
    #flow.DefaultConfig(jetPtCut=25)
    
    ##Jet Selection. FIXME: Missing Jet ID, JetPU ID
    flow.SubCollection("SelectedJetPhase2","Jet",'''
    Jet_pt > jetPtCut && abs(Jet_eta) < 4.7
    ''')
    
    flow.Selection("twoJetsPhase2","nSelectedJetPhase2>=2")
    
    flow.Distinct("JetPairPhase2","SelectedJetPhase2")
    flow.Define("SortedSelectedJetPhase2Indices","Argsort(-SelectedJetPhase2_pt)")
    flow.ObjectAt("QJetPhase2_0","SelectedJetPhase2",'At(SortedSelectedJetPhase2Indices,0)',requires=["twoJetsPhase2"])
    flow.ObjectAt("QJetPhase2_1","SelectedJetPhase2",'At(SortedSelectedJetPhase2Indices,1)',requires=["twoJetsPhase2"])

    #compute number of softjets removing signal footprint
    #flow.Define("SoftActivityJet_mass","SoftActivityJet_pt*0")
    #flow.Define("SoftActivityJet_p4","@p4v(SoftActivityJet)")
    #flow.Match("SelectedJetPhase2","SoftActivityJet") #associate signal jets
    #flow.Match("SelectedMuonPhase2","SoftActivityJet") #associate signal muons
    
    flow.Define("qqPhase2","QJetPhase2_0_p4+QJetPhase2_1_p4")
    flow.Define("MqqPhase2","qqPhase2.M()")
    flow.Define("qqPhase2_pt","qqPhase2.Pt()")
    flow.Define("qqDeltaEtaPhase2","abs(QJetPhase2_0_eta-QJetPhase2_1_eta)")
    flow.Define("qqDeltaPhiPhase2","abs(ROOT::Math::VectorUtil::DeltaPhi(QJetPhase2_0_p4,QJetPhase2_1_p4))")

    #QQ vs ll kinematic
    flow.Define("ll_ystarPhase2","Higgs_Phase2.Rapidity() - (QJetPhase2_0_p4.Rapidity() + QJetPhase2_1_p4.Rapidity())/2.f")
    flow.Define("ll_zstarPhase2"," abs( ll_ystar/ (QJetPhase2_0_p4.Rapidity()-QJetPhase2_1_p4.Rapidity() )) ")
    flow.Define("ll_zstarPhase2_log"," log(ll_zstarPhase2) ")
    flow.Define("ll_zstarbugPhase2_log","log(abs( (  Higgs_Phase2.Rapidity() - (QJetPhase2_0_p4.Rapidity() + QJetPhase2_1_p4.Rapidity())  )/ (QJetPhase2_0_p4.Rapidity()-QJetPhase2_1_p4.Rapidity() )))")
    flow.Define("DeltaEtaQQSumPhase2","abs(QJetPhase2_0_eta) +  abs(QJetPhase2_1_eta)")
    flow.Define("PhiHQ1Phase2","abs(ROOT::Math::VectorUtil::DeltaPhi(Higgs_Phase2,QJetPhase2_0_p4))")
    flow.Define("PhiHQ2Phase2","abs(ROOT::Math::VectorUtil::DeltaPhi(Higgs_Phase2,QJetPhase2_1_p4))")
    flow.Define("EtaHQ1Phase2","abs(Higgs_Phase2.Eta() - QJetPhase2_0_eta)")
    flow.Define("EtaHQ2Phase2","abs(Higgs_Phase2.Eta() - QJetPhase2_1_eta)")
    flow.Define("DeltaRelQQPhase2","(QJetPhase2_0_p4+QJetPhase2_1_p4).Pt()/( QJetPhase2_0_p4.Pt()+QJetPhase2_1_p4.Pt())")
    flow.Define("RptPhase2","(QJetPhase2_0_p4+QJetPhase2_1_p4+ Higgs).Pt()/( QJetPhase2_0_p4.Pt()+QJetPhase2_1_p4.Pt() + Higgs_Phase2.Pt())")
    #flow.Define("mmjj","Higgs+qq")
    flow.Define("theta2Phase2","Higgs_Phase2.Vect().Dot(QJetPhase2_1_p4.Vect())/QJetPhase2_1_p4.Vect().R()/HiggsPhase2.Vect().R()")
    flow.ObjectAt("LeadMuonPhase2","SelectedMuonPhase2","0",requires=["twoMuonsPhase2"])
    flow.ObjectAt("SubMuonPhase2","SelectedMuonPhase2","1",requires=["twoMuonsPhase2"])
    flow.Define("Higgs_Phase2_pt","Higgs_Phase2.Pt()")
    flow.Define("Higgs_Phase2_rapidity","Higgs_Phase2.Rapidity()")

    flow.Define("pTbalanceLeadPhase2","QJetPhase2_0_pt/Higgs_Phase2_pt")
    #flow.Define("pTbalance","qq.Pt()/Higgs_pt")
    flow.Define("pTbalanceAllPhase2","SumDef(SelectedJetPhase2_p4).pt()/Higgs_Phase2_pt")
    flow.Define("pTbalanceAllPhase2Log","log(pTbalanceAllPhase2)")
    flow.Define("pTbalancePhase2Log","log(pTbalancePhase2)")
    flow.Define("pTbalanceLeadPhase2Log","log(pTbalanceLeadPhase2)")
    flow.Define("Higgs_Phase2_m","Higgs_Phase2.M()")
    flow.Define("Higgs_Phase2_eta","Higgs_Phase2.Eta()")
    flow.Define("Higgs_Phase2_m_uncalib","Higgs_Phase2_Uncalib.M()")
    flow.Define("MqqPhase2_log","log(MqqPhase2)")
    flow.Define("MqqPhase2_over400_log","log(MqqPhase2/400)")
    flow.Define("mmjj_Phase2_pt","mmjj_Phase2.Pt()")
    flow.Define("mmjj_Phase2_pt_log","log(mmjj_Phase2_pt)")
    flow.Define("mmjj_Phase2_pz","mmjj_Phase2.Pz()")
    flow.Define("mmjj_Phase2_pz_logabs","log(abs(mmjj_Phase2_pz))")
    flow.Define("MaxJetAbsEta_Phase2","std::max(std::abs(QJetPhase2_0_eta), std::abs(QJetPhase2_1_eta))")
    flow.Define("minEtaHQPhase2","std::min(abs(EtaHQ1Phase2),(EtaHQ2Phase2))")
    flow.Define("minPhiHQPhase2","std::min(abs(PhiHQ1Phase2),abs(PhiHQ2Phase2))")


    flow.AddCppCode('\n#include "boost_to_CS.h"\n')
    flow.Define("CS_Phase2_theta","boost_to_CS(LeadMuonPhase2_p4, SubMuonPhase2_p4,  SubMuonPhase2_charge).first",requires=["twoOppositeSignMuonsPhase2"])
    flow.Define("CS_Phase2_phi","boost_to_CS(LeadMuonPhase2_p4, SubMuonPhase2_p4, SubMuonPhase2_charge).second",requires=["twoOppositeSignMuonsPhase2"])

    #flow.DefaultConfig(higgsMassWindowWidth=10,mQQcut=400,nominalHMass=125.03) #,btagCut=0.8)
    ## no b-tag discriminant in delphes, just 0 or 1
    flow.Define("SelectedJetPhase2btagDeepB","SelectedJetPhase2_btag") ##FIXME: use actual b-tagging
    #flow.Define("btagCut","0.5")
    #flow.Define("btagCutL","0.5")
    #adding for sync
    flow.Define("nbtaggedPhase2","int(Nonzero(SelectedJetPhase2btagDeepB > btagCut && abs(SelectedJetPhase2_eta)< 2.5).size())")
    flow.Define("nbtaggedLPhase2","int(Nonzero(SelectedJetPhase2btagDeepB > btagCutL && abs(SelectedJetPhase2_eta)< 2.5).size())")
    flow.Define("nelectronsPhase2","int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size())")


    #flow.Selection("MassWindow","Higgs.M()")
    flow.Selection("MassWindowZPhase2","abs(Higgs_Phase2.M()-91)<15")
    flow.Selection("VBFRegionPhase2","MqqPhase2 > mQQcut && QJetPhase2_0_pt> 35 && QJetPhase2_1_pt > 25")
    flow.Selection("PreSelPhase2","nelectronsPhase2==0 && nbtaggedLPhase2 < 2 && VBFRegionPhase2 && twoOppositeSignMuonsPhase2 && nbtaggedPhase2 < 1 && (( year == 2016 && LeadMuonPhase2_pt > 26 ) || ( year == 2017 && LeadMuonPhase2_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuonPhase2_pt > 26 )) && SubMuonPhase2_pt > 20 && TriggerSel && abs(SubMuonPhase2_eta) <2.4 && abs(LeadMuonPhase2_eta) < 2.4",requires=["VBFRegionPhase2","twoOppositeSignMuonsPhase2"])
    #flow.Selection("SideBand","Higgs_m < 150 && Higgs_m > 110 && ! MassWindow && VBFRegion &&  qqDeltaEta > 2.5",requires=["VBFRegion","PreSel"])
    flow.Selection("SignalRegionPhase2","VBFRegionPhase2 && qqDeltaEtaPhase2 > 2.5", requires=["VBFRegionPhase2","PreSelPhase2"]) ##FIXME qqDeltaEta > 2.5
    flow.Selection("InclusiveRegionPhase2","1")    #flow.Selection("ZRegion","VBFRegion && MassWindowZ  && qqDeltaEta > 2.5", requires=["VBFRegion","MassWindowZ","PreSel"])

    #flow.Define("Muonsum_ptHT", "LeadMuon_pt + SubMuon_pt")
    #flow.Selection("SelectionTest1", "LeadMuon_pt > 50")
    
#    flow.Selection("SelectionTest2","VBFRegion ", requires=["VBFRegion","PreSel"])
#    flow.Selection("SelectionTest3","qqDeltaEta > 2.5", requires=["VBFRegion","PreSel"])
#    flow.Selection("SelectionTest4","1", requires=["VBFRegion","PreSel"])
#    flow.Selection("SelectionTest5","VBFRegion &&  qqDeltaEta > 2.5")
#    flow.Selection("SelectionTest6","qqDeltaEta > 2.5", requires=["PreSel"])

    #flow.Selection("ZRegionSMP","Mqq > 250 && MassWindowZ && QJet0_pt> 50 && QJet1_pt > 30 && twoOppositeSignMuons && twoJets && TriggerSel&& abs(SubMuon_eta) <2.4 && abs(LeadMuon_eta) < 2.4 ", requires=["twoOppositeSignMuons","twoJets"])
    flow.Selection("TwoJetsTwoMuPhase2","twoJetsPhase2 && twoOppositeSignMuonsPhase2", requires=["twoJetsPhase2","twoOppositeSignMuonsPhase2"])
    #flow.Selection("SignalRegionPhase2T","SignalRegionPhase2 && QJet0_pt>45 && QJet1_pt > 27",requires=["SignalRegionPhase2"])
    flow.Selection("ZRegionTPhase2","ZRegionPhase2 && QJetPhase2_0_pt>45 && QJetPhase2_1_pt > 27",requires=["ZRegionPhase2"])
    flow.Selection("SideBandTPhase2","SideBandPhase2 && QJetPhase2_0_pt>45 && QJetPhase2_1_pt > 27",requires=["SideBandPhase2"])
        #with bug
    #flow.Define("HT","Sum(qq_pt)")

    return flow
