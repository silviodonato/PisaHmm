#define hist mapping

genericHistos=["Higgs_Phase1_m","pTbalanceAllPhase1","LeadMuonPhase1_pt","LeadMuonPhase1_eta","SubMuonPhase1_pt","SubMuonPhase1_eta","QJetPhase1_0_eta","QJetPhase1_1_eta","QJetPhase1_0_pt","QJetPhase1_1_pt", "CS_Phase1_theta", "CS_Phase1_phi"]
bdtInputHistos=["MqqPhase1_over400_log","Rpt","mmjj_Phase1_pt","qqDeltaEtaPhase1","NSoft5Phase1","ll_zstarPhase1","Higgs_Phase1_pt","theta2Phase1","mmjj_Phase1_pz","MaxJetAbsEtaPhase1","Higgs_Phase1_m_uncalib","NSoft5NewPhase1","ll_zstarPhase1_log", "Higgs_Phase1_mReso","QJetPhase1_0_qgl","QJetPhase1_1_qgl","Jet_jetIdPhase1","Jet_puIdPhase1"]


histosPerSelection={
#"PreSel" : ["Higgs_m"],
#"SignalRegionPhase1DNNWeighted" : ["Higgs_m"],
#"SRplusSBDNNWeighted" : ["Higgs_m","Higgs_m38"],
#"TightMassRegion" : ["DNN18AtanNoMass"],
"SignalRegionPhase1": ["MET_met", "QJetPhase1_0_pt", "qqPhase1_pt", "qqDeltaEtaPhase1", "qqDeltaPhiPhase1"]+genericHistos,
"InclusiveRegionPhase1": ["MET_met"],
"VBFRegionPhase1": ["MET_met"],
"MassWindowZPhase1": ["MET_met"],
"PreSelPhase1": ["MET_met"],

"SignalRegionPhase2": ["Higgs_Phase2_m","pTbalanceAllPhase2","LeadMuonPhase2_pt","LeadMuonPhase2_eta","SubMuonPhase2_pt","SubMuonPhase2_eta","QJetPhase2_0_eta","QJetPhase2_1_eta","QJetPhase2_0_pt","QJetPhase2_1_pt", "CS_Phase2_theta", "CS_Phase2_phi","MET_met", "QJetPhase2_0_pt", "qqPhase2_pt", "qqDeltaEtaPhase2", "qqDeltaPhiPhase2"],
#"InclusiveRegionPhase2": ["MET_met"],
#"VBFRegionPhase2": ["MET_met"],
#"MassWindowZPhase2": ["MET_met"],
#"PreSelPhase2": ["MET_met"],

#"SelectionTest1Phase1": ["LeadMuonPhase1_pt"],
#"SelectionTest2": ["MET_met"],
#"SelectionTest3": ["MET_met"],
#"SelectionTest4": ["MET_met"],
#"SelectionTest5": ["MET_met"],
#"SelectionTest6": ["MET_met"],
#"SignalRegionPhase1": signalHistos+signalHistosVariations+signalHistosMassScan, #+bdtInputHistos+ genericHistos,
#"ZRegion": signalHistosVariations+balance,#+genericHistos +bdtInputHistos,
#"SideBand" : signalHistosVariations, #+ ["DNN18AtanMassSpread","DNN18AtanMassSpread2"],#+genericHistos+bdtInputHistos,
#"SignalRegionPhase1T": signalHistos+signalHistosVariations+signalHistosMassScan, #+bdtInputHistos+ genericHistos,
#"ZRegionT": signalHistosVariations+balance,#+genericHistos +bdtInputHistos,
#"SideBandT" : signalHistosVariations, #+ ["DNN18AtanMassSpread","DNN18AtanMassSpread2"],#+genericHistos+bdtInputHistos,
#"ZRegionSMP": signalHistosVariations+["pTbalanceAll"]+bdtInputHistos,
#"BDT1p1" : bdtInputHistos+genericHistos,
#"BDT1p2" : bdtInputHistos+genericHistos,
}

 
#manyZregions={
#"ZRegionSLJeta0pt0":signalHistosVariations+balance,
#"ZRegionSLJeta1pt0":signalHistosVariations+balance,
#"ZRegionSLJeta2pt0":signalHistosVariations+balance,
#"ZRegionSLJeta2pt1":signalHistosVariations+balance,
#"ZRegionSLJeta3pt0":signalHistosVariations+balance,
#"ZRegionSLJeta3pt1":signalHistosVariations+balance,
#}
#histosPerSelection.update(manyZregions)


#histosPerSelectionFullJecs={
#"SignalRegionPhase1DNNWeighted" : ["Higgs_m"],
#"SignalRegionPhase1DNNWeighted" : ["Higgs_m"],
#"SRplusSBDNNWeighted" : ["Higgs_m"],
#"SignalRegionPhase1":signalHistos+signalHistosMassScan,
#"SideBand":signalHistosVariations, #+["DNN18AtanMassSpread","DNN18AtanMassSpread2"],
#"ZRegion":signalHistosVariations+balance,
#"SignalRegionPhase1T":signalHistos+signalHistosMassScan,
#"SideBandT":signalHistosVariations, #+["DNN18AtanMassSpread","DNN18AtanMassSpread2"],
#"ZRegionT":signalHistosVariations+balance,
#"ZRegionSMP":["pTbalanceAll","DNN18AtanNoMass"],
#"SignalRegionPhase1":["BDTAtan","DNNAtan","DNN18Atan"],#,"DNN18AtanNoQGL"],
#"SideBand":["BDTAtanNoMass","DNNAtanNoMass","DNN18AtanNoMass"],
#"ZRegion":["BDTAtanNoMass","pTbalanceAll","DNNAtanNoMass","DNN18AtanNoMass"],
#ZRegionSMP":["BDTAtanNoMass","pTbalanceAll","DNNAtanNoMass"],
#}
#histosPerSelectionFullJecs.update(manyZregions)

#quick override for missing plots
if False:
#    histosPerSelectionFullJecs={
 # }
    histosPerSelection={
      "SignalRegionPhase1":      ["MET_pt"],
      #"SignalRegionPhase2":      ["MET_pt"],
  }    
      #ericHistos+bdtInputHistos,
#      "SideBand":      ["Higgs_m_noGF","Mqq_over400_log","DNN18Atan"],#ericHistos+bdtInputHistos,
  #}

#'''
#genericHistos=["Higgs_m",]
  
