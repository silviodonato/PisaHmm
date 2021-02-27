
#include <Math/VectorUtil.h>
#include <ROOT/RVec.hxx>
#include "Math/Vector4D.h"
#include <ROOT/RDataFrame.hxx>
#include "helpers.h"
#define MemberMap(vector,member) Map(vector,[](auto x){return x.member;})
#define P4DELTAR ROOT::Math::VectorUtil::DeltaR<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float>>,ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float>>> 
//ROOT::Math::PtEtaPhiMVector,ROOT::Math::PtEtaPhiMVector> 
#include <vector>
#include <map>
#include <utility>
using namespace std;
#ifndef NAILSTUFF
#define NAILSTUFF
using RNode = ROOT::RDF::RNode;
struct Result {
 Result() {}
// Result(RNode  rdf_) {rdf[""]=rdf_;}
 std::map<std::string,RNode> rdf;
 ROOT::RDF::RResultPtr<TH1D> histo;
 std::vector<ROOT::RDF::RResultPtr<TH1D>> histos;
};
template <typename T>
class NodeCaster {
   public:
    static ROOT::RDF::RNode Cast(T rdf)
    {
              return ROOT::RDF::RNode(rdf);
    }
};
#endif

#include "geoFitCorr.h"

#include "muonEfficiency.h"

#include "prefiring.h"

#include "qglJetWeight.h"

#include "muresolution.h"

#include "boost_to_CS.h"

#include "mva.h"

#include "eval_lwtnn.h"
ROOT::VecOps::RVec<int> func__SelectedMuon(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta) {  return abs(Muon_eta) < 2.4; }
ROOT::VecOps::RVec<int> func__SelectedMuon_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & Muon_charge, const ROOT::VecOps::RVec<int> & SelectedMuon) {  return At(Muon_charge,SelectedMuon); }
ROOT::VecOps::RVec<float> func__SelectedMuon_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<int> & SelectedMuon) {  return At(Muon_eta,SelectedMuon); }
ROOT::VecOps::RVec<float> func__SelectedMuon_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_pt, const ROOT::VecOps::RVec<int> & SelectedMuon) {  return At(Muon_pt,SelectedMuon); }
int func__nSelectedMuon(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuon) {  return Sum(SelectedMuon); }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > func__MuMu_allpairs(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuon) {  return Combinations(Nonzero(SelectedMuon),Nonzero(SelectedMuon)); }
ROOT::VecOps::RVec<int> func__MuMu(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(MuMu_allpairs,0) < At(MuMu_allpairs,1); }
ROOT::VecOps::RVec<unsigned long> func__MuMu0(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(At(MuMu_allpairs,0),MuMu); }
ROOT::VecOps::RVec<unsigned long> func__MuMu1(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(At(MuMu_allpairs,1),MuMu); }
ROOT::VecOps::RVec<int> func__MuMu0_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu0, const ROOT::VecOps::RVec<int> & SelectedMuon_charge) {  return Take(SelectedMuon_charge,MuMu0); }
ROOT::VecOps::RVec<int> func__MuMu1_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu1, const ROOT::VecOps::RVec<int> & SelectedMuon_charge) {  return Take(SelectedMuon_charge,MuMu1); }
ROOT::VecOps::RVec<unsigned long> func__OppositeSignMuMu(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu0_charge, const ROOT::VecOps::RVec<int> & MuMu1_charge) {  return Nonzero(MuMu0_charge != MuMu1_charge); }
bool func__twoOppositeSignMuons(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMu) {  return OppositeSignMuMu.size() > 0; }
bool func__twoMuons(unsigned int __slot , const int & nSelectedMuon) {  return nSelectedMuon==2; }
ROOT::VecOps::RVec<float> func__Jet_pt_touse(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_pt) {  return Jet_pt; }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__Jet_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_mass, const ROOT::VecOps::RVec<float> & Jet_phi, const ROOT::VecOps::RVec<float> & Jet_pt_touse) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Jet_pt_touse , Jet_eta, Jet_phi, Jet_mass); }
int func__jetPtCut(unsigned int __slot ) {  return 25; }
ROOT::VecOps::RVec<int> func__SelectedJet(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_pt, const ROOT::VecOps::RVec<float> & Jet_pt_touse, const int & jetPtCut, const int & year) {  return 
    (year != 2017 ||  abs(Jet_eta) < 2.6 || abs(Jet_eta) > 3.0) &&
    Jet_pt_touse > jetPtCut && ( Jet_pt > 50)
    ; }
ROOT::VecOps::RVec<float> func__SelectedJet_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<int> & SelectedJet) {  return At(Jet_eta,SelectedJet); }
ROOT::VecOps::RVec<float> func__SelectedJet_pt_touse(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_pt_touse, const ROOT::VecOps::RVec<int> & SelectedJet) {  return At(Jet_pt_touse,SelectedJet); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedJet_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & Jet_p4, const ROOT::VecOps::RVec<int> & SelectedJet) {  return At(Jet_p4,SelectedJet); }
int func__nSelectedJet(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedJet) {  return Sum(SelectedJet); }
bool func__twoJets(unsigned int __slot , const int & nSelectedJet) {  return nSelectedJet>=2; }
ROOT::VecOps::RVec<unsigned long> func__SortedSelectedJetIndices(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJet_pt_touse) {  return Argsort(-SelectedJet_pt_touse); }
unsigned long func__QJet0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetIndices) {  return At(SortedSelectedJetIndices,0); }
float func__QJet0_eta(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<float> & SelectedJet_eta) {  return At(SelectedJet_eta,QJet0); }
float func__QJet0_pt_touse(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<float> & SelectedJet_pt_touse) {  return At(SelectedJet_pt_touse,QJet0); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJet0_p4(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJet_p4) {  return At(SelectedJet_p4,QJet0); }
unsigned long func__QJet1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetIndices) {  return At(SortedSelectedJetIndices,1); }
float func__QJet1_eta(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<float> & SelectedJet_eta) {  return At(SelectedJet_eta,QJet1); }
float func__QJet1_pt_touse(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<float> & SelectedJet_pt_touse) {  return At(SelectedJet_pt_touse,QJet1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJet1_p4(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJet_p4) {  return At(SelectedJet_p4,QJet1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__qq(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet1_p4) {  return QJet0_p4+QJet1_p4; }
float func__Mqq(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qq) {  return qq.M(); }
float func__qqDeltaEta(unsigned int __slot , const float & QJet0_eta, const float & QJet1_eta) {  return abs(QJet0_eta-QJet1_eta); }
int func__LeadMuon(unsigned int __slot ) {  return 0; }
float func__LeadMuon_eta(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<float> & SelectedMuon_eta) {  return At(SelectedMuon_eta,LeadMuon); }
float func__LeadMuon_pt(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<float> & SelectedMuon_pt) {  return At(SelectedMuon_pt,LeadMuon); }
int func__SubMuon(unsigned int __slot ) {  return 1; }
float func__SubMuon_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuon_eta, const int & SubMuon) {  return At(SelectedMuon_eta,SubMuon); }
float func__SubMuon_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuon_pt, const int & SubMuon) {  return At(SelectedMuon_pt,SubMuon); }
int func__mQQcut(unsigned int __slot ) {  return 400; }
float func__btagCut(unsigned int __slot , const int & year) {  return (year==2018||year==2026)?0.4184f:((year==2017)?0.4941f:0.6321f); }
float func__btagCutL(unsigned int __slot , const int & year) {  return (year==2018||year==2026)?0.1241f:((year==2017)?0.1522f:0.2217f); }
int func__SelectedJet_btagDeepB(unsigned int __slot ) {  return 1; }
int func__nbtagged(unsigned int __slot , const int & SelectedJet_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJet_eta, const float & btagCut) {  return int(Nonzero(SelectedJet_btagDeepB > btagCut && abs(SelectedJet_eta)< 2.5).size()); }
int func__nbtaggedL(unsigned int __slot , const int & SelectedJet_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJet_eta, const float & btagCutL) {  return int(Nonzero(SelectedJet_btagDeepB > btagCutL && abs(SelectedJet_eta)< 2.5).size()); }
int func__nelectrons(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_eta, const ROOT::VecOps::RVec<float> & Electron_pt) {  return int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size()); }
bool func__VBFRegion(unsigned int __slot , const float & Mqq, const float & QJet0_pt_touse, const float & QJet1_pt_touse, const int & mQQcut) {  return Mqq > mQQcut && QJet0_pt_touse> 35 && QJet1_pt_touse > 25; }
bool func__PreSel(unsigned int __slot , const float & LeadMuon_eta, const float & LeadMuon_pt, const float & SubMuon_eta, const float & SubMuon_pt, const bool & TriggerSel, const bool & VBFRegion, const int & nbtagged, const int & nbtaggedL, const int & nelectrons, const bool & twoOppositeSignMuons, const int & year) {  return nelectrons==0 && nbtaggedL < 2 && VBFRegion && twoOppositeSignMuons && nbtagged < 1 && (( year == 2016 && LeadMuon_pt > 26 ) || ( year == 2017 && LeadMuon_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuon_pt > 26 )) && SubMuon_pt > 20 && TriggerSel && abs(SubMuon_eta) <2.4 && abs(LeadMuon_eta) < 2.4; }
bool func__SignalRegion(unsigned int __slot , const bool & VBFRegion, const float & qqDeltaEta) {  return VBFRegion &&  qqDeltaEta > 2.5; }
double func__Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoOppositeSignMuons_twoMuons_twoJets_VBFRegion_PreSelWeight__Central(unsigned int __slot ) {  return 1.; }
double func__SignalRegionWeight__Central(unsigned int __slot ) {  return 1.; }

Result eventProcessor2026_nail(RNode rdf,int nThreads) {
     Result r;
     if(nThreads > 0)
     ROOT::EnableImplicitMT(nThreads);
	
	   auto rdf0 =rdf.DefineSlot("SelectedMuon",func__SelectedMuon,{"Muon_eta"});
auto rdf1 =rdf0.DefineSlot("SelectedMuon_charge",func__SelectedMuon_charge,{"Muon_charge","SelectedMuon"});
auto rdf2 =rdf1.DefineSlot("SelectedMuon_eta",func__SelectedMuon_eta,{"Muon_eta","SelectedMuon"});
auto rdf3 =rdf2.DefineSlot("SelectedMuon_pt",func__SelectedMuon_pt,{"Muon_pt","SelectedMuon"});
auto rdf4 =rdf3.DefineSlot("nSelectedMuon",func__nSelectedMuon,{"SelectedMuon"});
auto rdf5 =rdf4.DefineSlot("MuMu_allpairs",func__MuMu_allpairs,{"SelectedMuon"});
auto rdf6 =rdf5.DefineSlot("MuMu",func__MuMu,{"MuMu_allpairs"});
auto rdf7 =rdf6.DefineSlot("MuMu0",func__MuMu0,{"MuMu","MuMu_allpairs"});
auto rdf8 =rdf7.DefineSlot("MuMu1",func__MuMu1,{"MuMu","MuMu_allpairs"});
auto rdf9 =rdf8.DefineSlot("MuMu0_charge",func__MuMu0_charge,{"MuMu0","SelectedMuon_charge"});
auto rdf10 =rdf9.DefineSlot("MuMu1_charge",func__MuMu1_charge,{"MuMu1","SelectedMuon_charge"});
auto rdf11 =rdf10.DefineSlot("OppositeSignMuMu",func__OppositeSignMuMu,{"MuMu0_charge","MuMu1_charge"});
auto rdf12 =rdf11.DefineSlot("twoOppositeSignMuons",func__twoOppositeSignMuons,{"OppositeSignMuMu"});
auto rdf13 =rdf12.DefineSlot("twoMuons",func__twoMuons,{"nSelectedMuon"});
auto rdf14 =rdf13.DefineSlot("Jet_pt_touse",func__Jet_pt_touse,{"Jet_pt"});
auto rdf15 =rdf14.DefineSlot("Jet_p4",func__Jet_p4,{"Jet_eta","Jet_mass","Jet_phi","Jet_pt_touse"});
auto rdf16 =rdf15.DefineSlot("jetPtCut",func__jetPtCut,{});
auto rdf17 =rdf16.DefineSlot("SelectedJet",func__SelectedJet,{"Jet_eta","Jet_pt","Jet_pt_touse","jetPtCut","year"});
auto rdf18 =rdf17.DefineSlot("SelectedJet_eta",func__SelectedJet_eta,{"Jet_eta","SelectedJet"});
auto rdf19 =rdf18.DefineSlot("SelectedJet_pt_touse",func__SelectedJet_pt_touse,{"Jet_pt_touse","SelectedJet"});
auto rdf20 =rdf19.DefineSlot("SelectedJet_p4",func__SelectedJet_p4,{"Jet_p4","SelectedJet"});
auto rdf21 =rdf20.DefineSlot("nSelectedJet",func__nSelectedJet,{"SelectedJet"});
auto rdf22 =rdf21.DefineSlot("twoJets",func__twoJets,{"nSelectedJet"});
auto rdf23 =rdf22.DefineSlot("SortedSelectedJetIndices",func__SortedSelectedJetIndices,{"SelectedJet_pt_touse"});
auto rdf24 =rdf23.DefineSlot("QJet0",func__QJet0,{"SortedSelectedJetIndices"});
auto rdf25 =rdf24.DefineSlot("QJet0_eta",func__QJet0_eta,{"QJet0","SelectedJet_eta"});
auto rdf26 =rdf25.DefineSlot("QJet0_pt_touse",func__QJet0_pt_touse,{"QJet0","SelectedJet_pt_touse"});
auto rdf27 =rdf26.DefineSlot("QJet0_p4",func__QJet0_p4,{"QJet0","SelectedJet_p4"});
auto rdf28 =rdf27.DefineSlot("QJet1",func__QJet1,{"SortedSelectedJetIndices"});
auto rdf29 =rdf28.DefineSlot("QJet1_eta",func__QJet1_eta,{"QJet1","SelectedJet_eta"});
auto rdf30 =rdf29.DefineSlot("QJet1_pt_touse",func__QJet1_pt_touse,{"QJet1","SelectedJet_pt_touse"});
auto rdf31 =rdf30.DefineSlot("QJet1_p4",func__QJet1_p4,{"QJet1","SelectedJet_p4"});
auto rdf32 =rdf31.DefineSlot("qq",func__qq,{"QJet0_p4","QJet1_p4"});
auto rdf33 =rdf32.DefineSlot("Mqq",func__Mqq,{"qq"});
auto rdf34 =rdf33.DefineSlot("qqDeltaEta",func__qqDeltaEta,{"QJet0_eta","QJet1_eta"});
auto rdf35 =rdf34.DefineSlot("LeadMuon",func__LeadMuon,{});
auto rdf36 =rdf35.DefineSlot("LeadMuon_eta",func__LeadMuon_eta,{"LeadMuon","SelectedMuon_eta"});
auto rdf37 =rdf36.DefineSlot("LeadMuon_pt",func__LeadMuon_pt,{"LeadMuon","SelectedMuon_pt"});
auto rdf38 =rdf37.DefineSlot("SubMuon",func__SubMuon,{});
auto rdf39 =rdf38.DefineSlot("SubMuon_eta",func__SubMuon_eta,{"SelectedMuon_eta","SubMuon"});
auto rdf40 =rdf39.DefineSlot("SubMuon_pt",func__SubMuon_pt,{"SelectedMuon_pt","SubMuon"});
auto rdf41 =rdf40.DefineSlot("mQQcut",func__mQQcut,{});
auto rdf42 =rdf41.DefineSlot("btagCut",func__btagCut,{"year"});
auto rdf43 =rdf42.DefineSlot("btagCutL",func__btagCutL,{"year"});
auto rdf44 =rdf43.DefineSlot("SelectedJet_btagDeepB",func__SelectedJet_btagDeepB,{});
auto rdf45 =rdf44.DefineSlot("nbtagged",func__nbtagged,{"SelectedJet_btagDeepB","SelectedJet_eta","btagCut"});
auto rdf46 =rdf45.DefineSlot("nbtaggedL",func__nbtaggedL,{"SelectedJet_btagDeepB","SelectedJet_eta","btagCutL"});
auto rdf47 =rdf46.DefineSlot("nelectrons",func__nelectrons,{"Electron_eta","Electron_pt"});
auto rdf48 =rdf47.DefineSlot("VBFRegion",func__VBFRegion,{"Mqq","QJet0_pt_touse","QJet1_pt_touse","mQQcut"});
auto rdf49 =rdf48.DefineSlot("PreSel",func__PreSel,{"LeadMuon_eta","LeadMuon_pt","SubMuon_eta","SubMuon_pt","TriggerSel","VBFRegion","nbtagged","nbtaggedL","nelectrons","twoOppositeSignMuons","year"});
auto rdf50 =rdf49.DefineSlot("SignalRegion",func__SignalRegion,{"VBFRegion","qqDeltaEta"});
auto rdf51 =rdf50.DefineSlot("Weight__Central",func__Weight__Central,{});
auto rdf52 =rdf51.DefineSlot("twoOppositeSignMuons_twoMuons_twoJets_VBFRegion_PreSelWeight__Central",func__twoOppositeSignMuons_twoMuons_twoJets_VBFRegion_PreSelWeight__Central,{});
auto rdf53 =rdf52.DefineSlot("SignalRegionWeight__Central",func__SignalRegionWeight__Central,{});
auto toplevel=rdf53;
std::vector<ROOT::RDF::RResultPtr<TH1D>> histos;
{}auto selection_SignalRegion=rdf53.Filter("twoOppositeSignMuons","twoOppositeSignMuons").Filter("twoMuons","twoMuons").Filter("twoJets","twoJets").Filter("VBFRegion","VBFRegion").Filter("PreSel","PreSel").Filter("SignalRegion","SignalRegion");
r.rdf.emplace("SignalRegion",selection_SignalRegion);
{histos.emplace_back(selection_SignalRegion.Histo1D({"MET_met___SignalRegion", "MET_met {SignalRegion}", 1000,0,1000},"MET_met","SignalRegionWeight__Central"));
}
;
r.rdf.emplace("",rdf53);
r.histos=histos; return r;}