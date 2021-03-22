#define hist mapping

genericHistos=["Higgs_Phase1_m","pTbalanceAllPhase1","LeadMuonPhase1_pt","LeadMuonPhase1_eta","SubMuonPhase1_pt","SubMuonPhase1_eta","QJetPhase1_0_eta","QJetPhase1_1_eta","QJetPhase1_0_pt","QJetPhase1_1_pt", "CS_theta_Phase1", "CS_phi_Phase1"]
bdtInputHistos=["Mqq_Phase1_over400_log","Rpt","mmjj_Phase1_pt","qqDeltaEtaPhase1","NSoft5Phase1","ll_zstarPhase1","Higgs_Phase1_pt","theta2Phase1","mmjj_Phase1_pz","MaxJetAbsEtaPhase1","Higgs_Phase1_m_uncalib","NSoft5NewPhase1","ll_zstarPhase1_log", "Higgs_Phase1_mReso","QJetPhase1_0_qgl","QJetPhase1_1_qgl","Jet_jetIdPhase1","Jet_puIdPhase1"]


histosPerSelection={
#"PreSel" : ["Higgs_m"],
#"SignalRegionPhase1DNNWeighted" : ["Higgs_m"],
#"SRplusSBDNNWeighted" : ["Higgs_m","Higgs_m38"],
#"TightMassRegion" : ["DNN18AtanNoMass"],
"SignalRegionPhase1": ["METPhase1_met", "QJetPhase1_0_pt", "qq_ptPhase1", "qqDeltaEtaPhase1", "qqDeltaPhiPhase1"]+genericHistos,
#"SignalRegionPhase2": ["METPhase1_met", "QJetPhase1_0_pt", "qq_ptPhase1", "qqDeltaEtaPhase1", "qqDeltaPhiPhase1"]+genericHistos,
"InclusiveRegion_Phase1": ["METPhase1_met"],
"VBFRegion_Phase1": ["METPhase1_met"],
"MassWindowZ_Phase1": ["METPhase1_met"],
"PreSel_Phase1": ["METPhase1_met"],
"SelectionTest1Phase1": ["LeadMuonPhase1_pt"],
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
      "SignalRegionPhase1":      ["METPhase1_pt"],
  }    
      #ericHistos+bdtInputHistos,
#      "SideBand":      ["Higgs_m_noGF","Mqq_over400_log","DNN18Atan"],#ericHistos+bdtInputHistos,
  #}

#'''
#genericHistos=["Higgs_m",]
  
