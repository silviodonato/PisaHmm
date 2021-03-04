
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

#include "boost_to_CS.h"
ROOT::VecOps::RVec<float> func__Muon_mass(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_pt) {  return 0.f*Muon_pt; }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__Muon_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<float> & Muon_mass, const ROOT::VecOps::RVec<float> & Muon_phi, const ROOT::VecOps::RVec<float> & Muon_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Muon_pt , Muon_eta, Muon_phi, Muon_mass); }
ROOT::VecOps::RVec<int> func__SelectedMuon(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta) {  return abs(Muon_eta) < 2.4; }
ROOT::VecOps::RVec<int> func__SelectedMuon_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & Muon_charge, const ROOT::VecOps::RVec<int> & SelectedMuon) {  return At(Muon_charge,SelectedMuon); }
ROOT::VecOps::RVec<float> func__SelectedMuon_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<int> & SelectedMuon) {  return At(Muon_eta,SelectedMuon); }
ROOT::VecOps::RVec<float> func__SelectedMuon_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_pt, const ROOT::VecOps::RVec<int> & SelectedMuon) {  return At(Muon_pt,SelectedMuon); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedMuon_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & Muon_p4, const ROOT::VecOps::RVec<int> & SelectedMuon) {  return At(Muon_p4,SelectedMuon); }
int func__nSelectedMuon(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuon) {  return Sum(SelectedMuon); }
bool func__twoMuons(unsigned int __slot , const int & nSelectedMuon) {  return nSelectedMuon==2; }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > func__MuMu_allpairs(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuon) {  return Combinations(Nonzero(SelectedMuon),Nonzero(SelectedMuon)); }
ROOT::VecOps::RVec<int> func__MuMu(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(MuMu_allpairs,0) < At(MuMu_allpairs,1); }
ROOT::VecOps::RVec<unsigned long> func__MuMu0(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(At(MuMu_allpairs,0),MuMu); }
ROOT::VecOps::RVec<unsigned long> func__MuMu1(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(At(MuMu_allpairs,1),MuMu); }
ROOT::VecOps::RVec<int> func__MuMu0_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu0, const ROOT::VecOps::RVec<int> & SelectedMuon_charge) {  return Take(SelectedMuon_charge,MuMu0); }
ROOT::VecOps::RVec<int> func__MuMu1_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu1, const ROOT::VecOps::RVec<int> & SelectedMuon_charge) {  return Take(SelectedMuon_charge,MuMu1); }
ROOT::VecOps::RVec<unsigned long> func__OppositeSignMuMu(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu0_charge, const ROOT::VecOps::RVec<int> & MuMu1_charge) {  return Nonzero(MuMu0_charge != MuMu1_charge); }
bool func__twoOppositeSignMuons(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMu) {  return OppositeSignMuMu.size() > 0; }
unsigned long func__Mu_index(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMu) {  return At(OppositeSignMuMu,0,-200); }
int func__Mu0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu0, const unsigned long & Mu_index) {  return int(At(MuMu0,Mu_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Mu0_p4(unsigned int __slot , const int & Mu0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuon_p4) {  return At(SelectedMuon_p4,Mu0); }
int func__Mu1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu1, const unsigned long & Mu_index) {  return int(At(MuMu1,Mu_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Mu1_p4(unsigned int __slot , const int & Mu1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuon_p4) {  return At(SelectedMuon_p4,Mu1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Higgs(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Mu0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Mu1_p4) {  return Mu0_p4+Mu1_p4; }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__Jet_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_mass, const ROOT::VecOps::RVec<float> & Jet_phi, const ROOT::VecOps::RVec<float> & Jet_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Jet_pt , Jet_eta, Jet_phi, Jet_mass); }
int func__jetPtCut(unsigned int __slot ) {  return 25; }
ROOT::VecOps::RVec<int> func__SelectedJet(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_pt, const int & jetPtCut) {  return 
    Jet_pt > jetPtCut && abs(Jet_eta) < 4.7
    ; }
ROOT::VecOps::RVec<float> func__SelectedJet_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<int> & SelectedJet) {  return At(Jet_eta,SelectedJet); }
ROOT::VecOps::RVec<float> func__SelectedJet_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_pt, const ROOT::VecOps::RVec<int> & SelectedJet) {  return At(Jet_pt,SelectedJet); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedJet_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & Jet_p4, const ROOT::VecOps::RVec<int> & SelectedJet) {  return At(Jet_p4,SelectedJet); }
int func__nSelectedJet(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedJet) {  return Sum(SelectedJet); }
bool func__twoJets(unsigned int __slot , const int & nSelectedJet) {  return nSelectedJet>=2; }
ROOT::VecOps::RVec<unsigned long> func__SortedSelectedJetIndices(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJet_pt) {  return Argsort(-SelectedJet_pt); }
unsigned long func__QJet0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetIndices) {  return At(SortedSelectedJetIndices,0); }
float func__QJet0_eta(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<float> & SelectedJet_eta) {  return At(SelectedJet_eta,QJet0); }
float func__QJet0_pt(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<float> & SelectedJet_pt) {  return At(SelectedJet_pt,QJet0); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJet0_p4(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJet_p4) {  return At(SelectedJet_p4,QJet0); }
unsigned long func__QJet1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetIndices) {  return At(SortedSelectedJetIndices,1); }
float func__QJet1_eta(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<float> & SelectedJet_eta) {  return At(SelectedJet_eta,QJet1); }
float func__QJet1_pt(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<float> & SelectedJet_pt) {  return At(SelectedJet_pt,QJet1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJet1_p4(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJet_p4) {  return At(SelectedJet_p4,QJet1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__qq(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet1_p4) {  return QJet0_p4+QJet1_p4; }
float func__Mqq(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qq) {  return qq.M(); }
float func__qq_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qq) {  return qq.Pt(); }
float func__qqDeltaEta(unsigned int __slot , const float & QJet0_eta, const float & QJet1_eta) {  return abs(QJet0_eta-QJet1_eta); }
float func__qqDeltaPhi(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet1_p4) {  return abs(ROOT::Math::VectorUtil::DeltaPhi(QJet0_p4,QJet1_p4)); }
int func__LeadMuon(unsigned int __slot ) {  return 0; }
float func__LeadMuon_eta(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<float> & SelectedMuon_eta) {  return At(SelectedMuon_eta,LeadMuon); }
float func__LeadMuon_pt(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<float> & SelectedMuon_pt) {  return At(SelectedMuon_pt,LeadMuon); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__LeadMuon_p4(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuon_p4) {  return At(SelectedMuon_p4,LeadMuon); }
int func__SubMuon(unsigned int __slot ) {  return 1; }
int func__SubMuon_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuon_charge, const int & SubMuon) {  return At(SelectedMuon_charge,SubMuon); }
float func__SubMuon_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuon_eta, const int & SubMuon) {  return At(SelectedMuon_eta,SubMuon); }
float func__SubMuon_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuon_pt, const int & SubMuon) {  return At(SelectedMuon_pt,SubMuon); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__SubMuon_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuon_p4, const int & SubMuon) {  return At(SelectedMuon_p4,SubMuon); }
float func__Higgs_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs) {  return Higgs.Pt(); }
float func__pTbalanceAll(unsigned int __slot , const float & Higgs_pt, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJet_p4) {  return SumDef(SelectedJet_p4).pt()/Higgs_pt; }
float func__Higgs_m(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs) {  return Higgs.M(); }
float func__CS_theta(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuon_p4, const int & SubMuon_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuon_p4) {  return boost_to_CS(LeadMuon_p4, SubMuon_p4,  SubMuon_charge).first; }
float func__CS_phi(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuon_p4, const int & SubMuon_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuon_p4) {  return boost_to_CS(LeadMuon_p4, SubMuon_p4, SubMuon_charge).second; }
int func__mQQcut(unsigned int __slot ) {  return 400; }
int func__SelectedJet_btagDeepB(unsigned int __slot ) {  return 0; }
double func__btagCut(unsigned int __slot ) {  return 0.5; }
double func__btagCutL(unsigned int __slot ) {  return 0.5; }
int func__nbtagged(unsigned int __slot , const int & SelectedJet_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJet_eta, const double & btagCut) {  return int(Nonzero(SelectedJet_btagDeepB > btagCut && abs(SelectedJet_eta)< 2.5).size()); }
int func__nbtaggedL(unsigned int __slot , const int & SelectedJet_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJet_eta, const double & btagCutL) {  return int(Nonzero(SelectedJet_btagDeepB > btagCutL && abs(SelectedJet_eta)< 2.5).size()); }
int func__nelectrons(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_eta, const ROOT::VecOps::RVec<float> & Electron_pt) {  return int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size()); }
bool func__MassWindowZ(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs) {  return abs(Higgs.M()-91)<15; }
bool func__VBFRegion(unsigned int __slot , const float & Mqq, const float & QJet0_pt, const float & QJet1_pt, const int & mQQcut) {  return Mqq > mQQcut && QJet0_pt> 35 && QJet1_pt > 25; }
bool func__PreSel(unsigned int __slot , const float & LeadMuon_eta, const float & LeadMuon_pt, const float & SubMuon_eta, const float & SubMuon_pt, const bool & TriggerSel, const bool & VBFRegion, const int & nbtagged, const int & nbtaggedL, const int & nelectrons, const bool & twoOppositeSignMuons, const int & year) {  return nelectrons==0 && nbtaggedL < 2 && VBFRegion && twoOppositeSignMuons && nbtagged < 1 && (( year == 2016 && LeadMuon_pt > 26 ) || ( year == 2017 && LeadMuon_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuon_pt > 26 )) && SubMuon_pt > 20 && TriggerSel && abs(SubMuon_eta) <2.4 && abs(LeadMuon_eta) < 2.4; }
bool func__SignalRegion(unsigned int __slot , const bool & VBFRegion, const float & qqDeltaEta) {  return VBFRegion && qqDeltaEta > 2.5; }
int func__InclusiveRegion(unsigned int __slot ) {  return 1; }
double func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegionWeight__Central(unsigned int __slot ) {  return 1.; }
double func__twoJetsWeight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuons_twoOppositeSignMuonsWeight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsWeight__Central(unsigned int __slot ) {  return 1.; }
double func__Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegion_PreSelWeight__Central(unsigned int __slot ) {  return 1.; }
double func__SignalRegionWeight__Central(unsigned int __slot ) {  return 1.; }
double func__InclusiveRegionWeight__Central(unsigned int __slot ) {  return 1.; }
double func__VBFRegionWeight__Central(unsigned int __slot ) {  return 1.; }
double func__MassWindowZWeight__Central(unsigned int __slot ) {  return 1.; }
double func__PreSelWeight__Central(unsigned int __slot ) {  return 1.; }

Result eventProcessor2026_nail(RNode rdf,int nThreads) {
     Result r;
     if(nThreads > 0)
     ROOT::EnableImplicitMT(nThreads);
	
	   auto rdf0 =rdf.DefineSlot("Muon_mass",func__Muon_mass,{"Muon_pt"});
auto rdf1 =rdf0.DefineSlot("Muon_p4",func__Muon_p4,{"Muon_eta","Muon_mass","Muon_phi","Muon_pt"});
auto rdf2 =rdf1.DefineSlot("SelectedMuon",func__SelectedMuon,{"Muon_eta"});
auto rdf3 =rdf2.DefineSlot("SelectedMuon_charge",func__SelectedMuon_charge,{"Muon_charge","SelectedMuon"});
auto rdf4 =rdf3.DefineSlot("SelectedMuon_eta",func__SelectedMuon_eta,{"Muon_eta","SelectedMuon"});
auto rdf5 =rdf4.DefineSlot("SelectedMuon_pt",func__SelectedMuon_pt,{"Muon_pt","SelectedMuon"});
auto rdf6 =rdf5.DefineSlot("SelectedMuon_p4",func__SelectedMuon_p4,{"Muon_p4","SelectedMuon"});
auto rdf7 =rdf6.DefineSlot("nSelectedMuon",func__nSelectedMuon,{"SelectedMuon"});
auto rdf8 =rdf7.DefineSlot("twoMuons",func__twoMuons,{"nSelectedMuon"});
auto rdf9 =rdf8.DefineSlot("MuMu_allpairs",func__MuMu_allpairs,{"SelectedMuon"});
auto rdf10 =rdf9.DefineSlot("MuMu",func__MuMu,{"MuMu_allpairs"});
auto rdf11 =rdf10.DefineSlot("MuMu0",func__MuMu0,{"MuMu","MuMu_allpairs"});
auto rdf12 =rdf11.DefineSlot("MuMu1",func__MuMu1,{"MuMu","MuMu_allpairs"});
auto rdf13 =rdf12.DefineSlot("MuMu0_charge",func__MuMu0_charge,{"MuMu0","SelectedMuon_charge"});
auto rdf14 =rdf13.DefineSlot("MuMu1_charge",func__MuMu1_charge,{"MuMu1","SelectedMuon_charge"});
auto rdf15 =rdf14.DefineSlot("OppositeSignMuMu",func__OppositeSignMuMu,{"MuMu0_charge","MuMu1_charge"});
auto rdf16 =rdf15.DefineSlot("twoOppositeSignMuons",func__twoOppositeSignMuons,{"OppositeSignMuMu"});
auto rdf17 =rdf16.DefineSlot("Mu_index",func__Mu_index,{"OppositeSignMuMu"});
auto rdf18 =rdf17.DefineSlot("Mu0",func__Mu0,{"MuMu0","Mu_index"});
auto rdf19 =rdf18.DefineSlot("Mu0_p4",func__Mu0_p4,{"Mu0","SelectedMuon_p4"});
auto rdf20 =rdf19.DefineSlot("Mu1",func__Mu1,{"MuMu1","Mu_index"});
auto rdf21 =rdf20.DefineSlot("Mu1_p4",func__Mu1_p4,{"Mu1","SelectedMuon_p4"});
auto rdf22 =rdf21.DefineSlot("Higgs",func__Higgs,{"Mu0_p4","Mu1_p4"});
auto rdf23 =rdf22.DefineSlot("Jet_p4",func__Jet_p4,{"Jet_eta","Jet_mass","Jet_phi","Jet_pt"});
auto rdf24 =rdf23.DefineSlot("jetPtCut",func__jetPtCut,{});
auto rdf25 =rdf24.DefineSlot("SelectedJet",func__SelectedJet,{"Jet_eta","Jet_pt","jetPtCut"});
auto rdf26 =rdf25.DefineSlot("SelectedJet_eta",func__SelectedJet_eta,{"Jet_eta","SelectedJet"});
auto rdf27 =rdf26.DefineSlot("SelectedJet_pt",func__SelectedJet_pt,{"Jet_pt","SelectedJet"});
auto rdf28 =rdf27.DefineSlot("SelectedJet_p4",func__SelectedJet_p4,{"Jet_p4","SelectedJet"});
auto rdf29 =rdf28.DefineSlot("nSelectedJet",func__nSelectedJet,{"SelectedJet"});
auto rdf30 =rdf29.DefineSlot("twoJets",func__twoJets,{"nSelectedJet"});
auto rdf31 =rdf30.DefineSlot("SortedSelectedJetIndices",func__SortedSelectedJetIndices,{"SelectedJet_pt"});
auto rdf32 =rdf31.DefineSlot("QJet0",func__QJet0,{"SortedSelectedJetIndices"});
auto rdf33 =rdf32.DefineSlot("QJet0_eta",func__QJet0_eta,{"QJet0","SelectedJet_eta"});
auto rdf34 =rdf33.DefineSlot("QJet0_pt",func__QJet0_pt,{"QJet0","SelectedJet_pt"});
auto rdf35 =rdf34.DefineSlot("QJet0_p4",func__QJet0_p4,{"QJet0","SelectedJet_p4"});
auto rdf36 =rdf35.DefineSlot("QJet1",func__QJet1,{"SortedSelectedJetIndices"});
auto rdf37 =rdf36.DefineSlot("QJet1_eta",func__QJet1_eta,{"QJet1","SelectedJet_eta"});
auto rdf38 =rdf37.DefineSlot("QJet1_pt",func__QJet1_pt,{"QJet1","SelectedJet_pt"});
auto rdf39 =rdf38.DefineSlot("QJet1_p4",func__QJet1_p4,{"QJet1","SelectedJet_p4"});
auto rdf40 =rdf39.DefineSlot("qq",func__qq,{"QJet0_p4","QJet1_p4"});
auto rdf41 =rdf40.DefineSlot("Mqq",func__Mqq,{"qq"});
auto rdf42 =rdf41.DefineSlot("qq_pt",func__qq_pt,{"qq"});
auto rdf43 =rdf42.DefineSlot("qqDeltaEta",func__qqDeltaEta,{"QJet0_eta","QJet1_eta"});
auto rdf44 =rdf43.DefineSlot("qqDeltaPhi",func__qqDeltaPhi,{"QJet0_p4","QJet1_p4"});
auto rdf45 =rdf44.DefineSlot("LeadMuon",func__LeadMuon,{});
auto rdf46 =rdf45.DefineSlot("LeadMuon_eta",func__LeadMuon_eta,{"LeadMuon","SelectedMuon_eta"});
auto rdf47 =rdf46.DefineSlot("LeadMuon_pt",func__LeadMuon_pt,{"LeadMuon","SelectedMuon_pt"});
auto rdf48 =rdf47.DefineSlot("LeadMuon_p4",func__LeadMuon_p4,{"LeadMuon","SelectedMuon_p4"});
auto rdf49 =rdf48.DefineSlot("SubMuon",func__SubMuon,{});
auto rdf50 =rdf49.DefineSlot("SubMuon_charge",func__SubMuon_charge,{"SelectedMuon_charge","SubMuon"});
auto rdf51 =rdf50.DefineSlot("SubMuon_eta",func__SubMuon_eta,{"SelectedMuon_eta","SubMuon"});
auto rdf52 =rdf51.DefineSlot("SubMuon_pt",func__SubMuon_pt,{"SelectedMuon_pt","SubMuon"});
auto rdf53 =rdf52.DefineSlot("SubMuon_p4",func__SubMuon_p4,{"SelectedMuon_p4","SubMuon"});
auto rdf54 =rdf53.DefineSlot("Higgs_pt",func__Higgs_pt,{"Higgs"});
auto rdf55 =rdf54.DefineSlot("pTbalanceAll",func__pTbalanceAll,{"Higgs_pt","SelectedJet_p4"});
auto rdf56 =rdf55.DefineSlot("Higgs_m",func__Higgs_m,{"Higgs"});
auto rdf57 =rdf56.DefineSlot("CS_theta",func__CS_theta,{"LeadMuon_p4","SubMuon_charge","SubMuon_p4"});
auto rdf58 =rdf57.DefineSlot("CS_phi",func__CS_phi,{"LeadMuon_p4","SubMuon_charge","SubMuon_p4"});
auto rdf59 =rdf58.DefineSlot("mQQcut",func__mQQcut,{});
auto rdf60 =rdf59.DefineSlot("SelectedJet_btagDeepB",func__SelectedJet_btagDeepB,{});
auto rdf61 =rdf60.DefineSlot("btagCut",func__btagCut,{});
auto rdf62 =rdf61.DefineSlot("btagCutL",func__btagCutL,{});
auto rdf63 =rdf62.DefineSlot("nbtagged",func__nbtagged,{"SelectedJet_btagDeepB","SelectedJet_eta","btagCut"});
auto rdf64 =rdf63.DefineSlot("nbtaggedL",func__nbtaggedL,{"SelectedJet_btagDeepB","SelectedJet_eta","btagCutL"});
auto rdf65 =rdf64.DefineSlot("nelectrons",func__nelectrons,{"Electron_eta","Electron_pt"});
auto rdf66 =rdf65.DefineSlot("MassWindowZ",func__MassWindowZ,{"Higgs"});
auto rdf67 =rdf66.DefineSlot("VBFRegion",func__VBFRegion,{"Mqq","QJet0_pt","QJet1_pt","mQQcut"});
auto rdf68 =rdf67.DefineSlot("PreSel",func__PreSel,{"LeadMuon_eta","LeadMuon_pt","SubMuon_eta","SubMuon_pt","TriggerSel","VBFRegion","nbtagged","nbtaggedL","nelectrons","twoOppositeSignMuons","year"});
auto rdf69 =rdf68.DefineSlot("SignalRegion",func__SignalRegion,{"VBFRegion","qqDeltaEta"});
auto rdf70 =rdf69.DefineSlot("InclusiveRegion",func__InclusiveRegion,{});
auto rdf71 =rdf70.DefineSlot("twoMuons_twoOppositeSignMuons_twoJets_VBFRegionWeight__Central",func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegionWeight__Central,{});
auto rdf72 =rdf71.DefineSlot("twoJetsWeight__Central",func__twoJetsWeight__Central,{});
auto rdf73 =rdf72.DefineSlot("twoMuons_twoOppositeSignMuonsWeight__Central",func__twoMuons_twoOppositeSignMuonsWeight__Central,{});
auto rdf74 =rdf73.DefineSlot("twoMuonsWeight__Central",func__twoMuonsWeight__Central,{});
auto rdf75 =rdf74.DefineSlot("Weight__Central",func__Weight__Central,{});
auto rdf76 =rdf75.DefineSlot("twoMuons_twoOppositeSignMuons_twoJets_VBFRegion_PreSelWeight__Central",func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegion_PreSelWeight__Central,{});
auto rdf77 =rdf76.DefineSlot("SignalRegionWeight__Central",func__SignalRegionWeight__Central,{});
auto rdf78 =rdf77.DefineSlot("InclusiveRegionWeight__Central",func__InclusiveRegionWeight__Central,{});
auto rdf79 =rdf78.DefineSlot("VBFRegionWeight__Central",func__VBFRegionWeight__Central,{});
auto rdf80 =rdf79.DefineSlot("MassWindowZWeight__Central",func__MassWindowZWeight__Central,{});
auto rdf81 =rdf80.DefineSlot("PreSelWeight__Central",func__PreSelWeight__Central,{});
auto toplevel=rdf81;
std::vector<ROOT::RDF::RResultPtr<TH1D>> histos;
{}auto selection_SignalRegion=rdf81.Filter("twoMuons","twoMuons").Filter("twoOppositeSignMuons","twoOppositeSignMuons").Filter("twoJets","twoJets").Filter("VBFRegion","VBFRegion").Filter("PreSel","PreSel").Filter("SignalRegion","SignalRegion");
r.rdf.emplace("SignalRegion",selection_SignalRegion);
{histos.emplace_back(selection_SignalRegion.Histo1D({"MET_met___SignalRegion", "MET_met {SignalRegion}", 1000,0,1000},"MET_met","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"QJet0_pt___SignalRegion", "QJet0_pt {SignalRegion}", 30 , 0 , 300},"QJet0_pt","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"qq_pt___SignalRegion", "qq_pt {SignalRegion}", 30 , 0 , 300},"qq_pt","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"qqDeltaEta___SignalRegion", "qqDeltaEta {SignalRegion}", 30 , 0,10},"qqDeltaEta","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"qqDeltaPhi___SignalRegion", "qqDeltaPhi {SignalRegion}", 1000,0,1000},"qqDeltaPhi","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"Higgs_m___SignalRegion", "Higgs_m {SignalRegion}", 80 , 70,150},"Higgs_m","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"pTbalanceAll___SignalRegion", "pTbalanceAll {SignalRegion}", 30 , 0 , 4},"pTbalanceAll","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"LeadMuon_pt___SignalRegion", "LeadMuon_pt {SignalRegion}", 30 , 0 , 300},"LeadMuon_pt","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"LeadMuon_eta___SignalRegion", "LeadMuon_eta {SignalRegion}", 30 , -5 , 5},"LeadMuon_eta","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"SubMuon_pt___SignalRegion", "SubMuon_pt {SignalRegion}", 30 , 0 , 300},"SubMuon_pt","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"SubMuon_eta___SignalRegion", "SubMuon_eta {SignalRegion}", 30 , -5 , 5},"SubMuon_eta","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"QJet0_eta___SignalRegion", "QJet0_eta {SignalRegion}", 30 , -5 , 5},"QJet0_eta","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"QJet1_eta___SignalRegion", "QJet1_eta {SignalRegion}", 30 , -5 , 5},"QJet1_eta","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"QJet0_pt___SignalRegion", "QJet0_pt {SignalRegion}", 30 , 0 , 300},"QJet0_pt","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"QJet1_pt___SignalRegion", "QJet1_pt {SignalRegion}", 30 , 0 , 300},"QJet1_pt","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"CS_theta___SignalRegion", "CS_theta {SignalRegion}", 30 , -3.2 , 3.2},"CS_theta","SignalRegionWeight__Central"));
histos.emplace_back(selection_SignalRegion.Histo1D({"CS_phi___SignalRegion", "CS_phi {SignalRegion}", 30 , -3.2 , 3.2},"CS_phi","SignalRegionWeight__Central"));
}auto selection_InclusiveRegion=rdf81.Filter("InclusiveRegion","InclusiveRegion");
r.rdf.emplace("InclusiveRegion",selection_InclusiveRegion);
{histos.emplace_back(selection_InclusiveRegion.Histo1D({"MET_met___InclusiveRegion", "MET_met {InclusiveRegion}", 1000,0,1000},"MET_met","InclusiveRegionWeight__Central"));
}auto selection_VBFRegion=rdf81.Filter("twoJets","twoJets").Filter("VBFRegion","VBFRegion");
r.rdf.emplace("VBFRegion",selection_VBFRegion);
{histos.emplace_back(selection_VBFRegion.Histo1D({"MET_met___VBFRegion", "MET_met {VBFRegion}", 1000,0,1000},"MET_met","VBFRegionWeight__Central"));
}auto selection_MassWindowZ=rdf81.Filter("twoMuons","twoMuons").Filter("twoOppositeSignMuons","twoOppositeSignMuons").Filter("MassWindowZ","MassWindowZ");
r.rdf.emplace("MassWindowZ",selection_MassWindowZ);
{histos.emplace_back(selection_MassWindowZ.Histo1D({"MET_met___MassWindowZ", "MET_met {MassWindowZ}", 1000,0,1000},"MET_met","MassWindowZWeight__Central"));
}auto selection_PreSel=rdf81.Filter("twoMuons","twoMuons").Filter("twoOppositeSignMuons","twoOppositeSignMuons").Filter("twoJets","twoJets").Filter("VBFRegion","VBFRegion").Filter("PreSel","PreSel");
r.rdf.emplace("PreSel",selection_PreSel);
{histos.emplace_back(selection_PreSel.Histo1D({"MET_met___PreSel", "MET_met {PreSel}", 1000,0,1000},"MET_met","PreSelWeight__Central"));
}
;
r.rdf.emplace("",rdf81);
r.histos=histos; return r;}