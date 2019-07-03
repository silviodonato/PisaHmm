from nail import *
import ROOT
import sys


def addLheScale(flow):  
    flow.Define("LHERenUp","LHEScaleWeightSafe[6+int(nLHEScaleWeight>8)]*lhefactor")
    flow.Define("LHERenDown","LHEScaleWeightSafe[1]*lhefactor")
    flow.Define("LHEFacUp","LHEScaleWeightSafe[4+int(nLHEScaleWeight>8)]*lhefactor")
    flow.Define("LHEFacDown","LHEScaleWeightSafe[3]*lhefactor")
    flow.VariationWeight("LHERenUp")
    flow.VariationWeight("LHERenDown")
    flow.VariationWeight("LHEFacUp")
    flow.VariationWeight("LHEFacDown")



def addPSWeights(flow):
     flow.Define("PSWeightToFix","PSWeight[0]!=1.0f && genWeight!=LHEWeight_originalXWGTUP ")
     flow.Define("PSWeightISRDown","PSWeightToFix?PSWeight[0]:PSWeight[0]*LHEWeight_originalXWGTUP")
     flow.Define("PSWeightFSRDown","PSWeightToFix?PSWeight[1]:PSWeight[1]*LHEWeight_originalXWGTUP")
     flow.Define("PSWeightISRUp","PSWeightToFix?PSWeight[2]:PSWeight[2]*LHEWeight_originalXWGTUP")
     flow.Define("PSWeightFSRUp","PSWeightToFix?PSWeight[3]:PSWeight[3]*LHEWeight_originalXWGTUP")
     flow.VariationWeight("PSWeightISRUp")
     flow.VariationWeight("PSWeightISRDown")
     flow.VariationWeight("PSWeightFSRUp")
     flow.VariationWeight("PSWeightFSRDown")

    #we really need only 0,1,3
    #flow.VariationWeightArray("LHEScaleWeightSafe",4,filt=lambda sname,hname,wname : "__syst__" not in hname and "__syst__" not in sname ) #systematic variations are 1D, let's avoid systematics of systematic
    #this is not obvious as N replicas can change... think about it
    #flow.AddVariationWeightArray("LHEPdfWeight",30,filt=lambda hname,wname : "__syst__" not in hname ) #systematic variations are 1D, let's avoid systematics of systematic


#create btag systematics
#this should be simplified
def addBtag(flow):
    pass
#    flow.Define("SelectedJet_btagWeight_up","vector_map(btagWeightUp,SelectedJet_btagCSVV2,SelectedJet_pt,SelectedJet_eta)")
    #flow.Define("btagEventWeightUp","std::accumulate(SelectedJet_btagWeight.begin(),SelectedJet_btagWeight.end(),1, std::multiplies<double>())")
#    flow.Systematic("BTagUp","SelectedJet_btagWeight","SelectedJet_btagWeight_up")
   #flow.createVariationBranch("BTagUp",["btagWeight"])
#    flow.VariationWeight("btagEventWeight__syst__BTagUP","btagEventWeight")


def addMuScale(flow):
#Define Systematic variations
    flow.Systematic("MuScaleDown","Muon_corrected_pt","Muon_correctedDown_pt") #name, target, replacement
    flow.Systematic("MuScaleUp","Muon_corrected_pt","Muon_correctedUp_pt") #name, target, replacement

def addCompleteJecs(flow):
      # flow.Systematic("JERDown","Jet_pt_touse","Jet_pt_jerDown") #name, target, replacement
      # flow.Systematic("JERUp","Jet_pt_touse","Jet_pt_jerUp") #name, target, replacement
      # flow.Systematic("JESDown","Jet_pt_touse","Jet_pt_jesTotalDown") #name, target, replacement
      # flow.Systematic("JESUp","Jet_pt_touse","Jet_pt_jesTotalUp") #name, target, replacement
      # flow.Systematic("WithJER","Jet_pt_touse","Jet_pt_nom") #name, target, replacement
      # #flow.Systematic("noJER","Jet_pt_touse","Jet_pt") #name, target, replacement
      # flow.Systematic("WithOutJER","Jet_pt_touse","Jet_pt") #name, target, replacement
       flow.Define("Jet_genPt","TakeDef(GenJet_pt,Jet_genJetIdx,Jet_pt)") 
       flow.Define("Jet_jerSF","(Jet_pt_nom-Jet_genPt)/(Jet_pt-Jet_genPt+(Jet_pt==Jet_genPt)*(Jet_pt_nom-Jet_pt))") 
       flow.Define("Jet_jerDownSF","(Jet_pt_jerDown-Jet_genPt)/(Jet_pt-Jet_genPt+(Jet_pt==Jet_genPt)*10.f)") 
       flow.Define("Jet_jerUpSF","(Jet_pt_jerUp-Jet_genPt)/(Jet_pt-Jet_genPt+(Jet_pt==Jet_genPt)*10.f)") 
       flow.Define("Jet_pt_jerDown_touse","Jet_genPt+(Jet_pt_touse-Jet_genPt)*(Jet_jerDownSF/Jet_jerSF)") 
       flow.Define("Jet_pt_jerUp_touse","Jet_genPt+(Jet_pt_touse-Jet_genPt)*(Jet_jerUpSF/Jet_jerSF)+(Jet_genPt==Jet_pt)*Map(Jet_pt, [](float sigma) {return float(gRandom->Gaus(0,0.15*sigma));} )") 
       flow.Define("Jet_pt_jesTotalDown_touse","Jet_pt_touse*Jet_pt_jesTotalDown/Jet_pt_nom") 
       flow.Define("Jet_pt_jesTotalUp_touse","Jet_pt_touse*Jet_pt_jesTotalUp/Jet_pt_nom") 
#       flow.Define("Jet_pt_jerDown_touseLimited","((Jet_pt_jerDown_touse/Jet_pt_touse)>0.8&& (Jet_pt_jerDown_touse/Jet_pt_touse)<1.2)?Jet_pt_jerDown_touse:Jet_pt_touse"	
#       flow.Define("Jet_pt_jerDown_touseLimited","((Jet_pt_jerDown_touse/Jet_pt_touse)>0.8&& (Jet_pt_jerDown_touse/Jet_pt_touse)<1.2)?Jet_pt_jerDown_touse:Jet_pt_touse"	

       flow.Systematic("JERDown","Jet_pt_touse","Jet_pt_jerDown_touse") #name, target, replacement 
#      flow.Systematic("JERUp","Jet_pt_touse","Jet_pt_jerUp_touse") #name, target, replacement 
       flow.Systematic("JERUp","Jet_pt_touse","Jet_pt_nom") #name, target, replacement
       flow.Systematic("JESDown","Jet_pt_touse","Jet_pt_jesTotalDown_touse") #name, target, replacement 
       flow.Systematic("JESUp","Jet_pt_touse","Jet_pt_jesTotalUp_touse") #name, target, replacement 
       #flow.Systematic("WithJER","Jet_pt_touse","Jet_pt_nom") #name, target, replacement


def addPUvariation(flow):
    flow.VariationWeight("puWeightDown","puWeight")  #name of the replacement, target
    flow.VariationWeight("puWeightUp","puWeight") 
