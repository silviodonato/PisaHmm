
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
ROOT::VecOps::RVec<int> func__SelectedMuonPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta) {  return abs(Muon_eta) < 2.4; }
ROOT::VecOps::RVec<int> func__SelectedMuonPhase1_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & Muon_charge, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1) {  return At(Muon_charge,SelectedMuonPhase1); }
ROOT::VecOps::RVec<float> func__SelectedMuonPhase1_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1) {  return At(Muon_eta,SelectedMuonPhase1); }
ROOT::VecOps::RVec<float> func__SelectedMuonPhase1_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_pt, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1) {  return At(Muon_pt,SelectedMuonPhase1); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedMuonPhase1_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & Muon_p4, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1) {  return At(Muon_p4,SelectedMuonPhase1); }
int func__nSelectedMuonPhase1(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase1) {  return Sum(SelectedMuonPhase1); }
bool func__twoMuons(unsigned int __slot , const int & nSelectedMuonPhase1) {  return nSelectedMuonPhase1==2; }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > func__MuMu_allpairs(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase1) {  return Combinations(Nonzero(SelectedMuonPhase1),Nonzero(SelectedMuonPhase1)); }
ROOT::VecOps::RVec<int> func__MuMu(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(MuMu_allpairs,0) < At(MuMu_allpairs,1); }
ROOT::VecOps::RVec<unsigned long> func__MuMu0(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(At(MuMu_allpairs,0),MuMu); }
ROOT::VecOps::RVec<unsigned long> func__MuMu1(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMu_allpairs) {  return At(At(MuMu_allpairs,1),MuMu); }
ROOT::VecOps::RVec<int> func__MuMu0_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu0, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1_charge) {  return Take(SelectedMuonPhase1_charge,MuMu0); }
ROOT::VecOps::RVec<int> func__MuMu1_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu1, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1_charge) {  return Take(SelectedMuonPhase1_charge,MuMu1); }
ROOT::VecOps::RVec<unsigned long> func__OppositeSignMuMu(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMu0_charge, const ROOT::VecOps::RVec<int> & MuMu1_charge) {  return Nonzero(MuMu0_charge != MuMu1_charge); }
bool func__twoOppositeSignMuons(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMu) {  return OppositeSignMuMu.size() > 0; }
unsigned long func__Mu_index(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMu) {  return At(OppositeSignMuMu,0,-200); }
int func__Mu0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu0, const unsigned long & Mu_index) {  return int(At(MuMu0,Mu_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Mu0_p4(unsigned int __slot , const int & Mu0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4) {  return At(SelectedMuonPhase1_p4,Mu0); }
int func__Mu1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMu1, const unsigned long & Mu_index) {  return int(At(MuMu1,Mu_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Mu1_p4(unsigned int __slot , const int & Mu1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4) {  return At(SelectedMuonPhase1_p4,Mu1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Higgs(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Mu0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Mu1_p4) {  return Mu0_p4+Mu1_p4; }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__Jet_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_mass, const ROOT::VecOps::RVec<float> & Jet_phi, const ROOT::VecOps::RVec<float> & Jet_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Jet_pt , Jet_eta, Jet_phi, Jet_mass); }
int func__jetPtCut(unsigned int __slot ) {  return 25; }
ROOT::VecOps::RVec<int> func__SelectedJetPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_pt, const int & jetPtCut) {  return 
    Jet_pt > jetPtCut && abs(Jet_eta) < 4.7
    ; }
ROOT::VecOps::RVec<float> func__SelectedJetPhase1_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(Jet_eta,SelectedJetPhase1); }
ROOT::VecOps::RVec<float> func__SelectedJetPhase1_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_pt, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(Jet_pt,SelectedJetPhase1); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedJetPhase1_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & Jet_p4, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(Jet_p4,SelectedJetPhase1); }
int func__nSelectedJetPhase1(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return Sum(SelectedJetPhase1); }
bool func__twoJets(unsigned int __slot , const int & nSelectedJetPhase1) {  return nSelectedJetPhase1>=2; }
ROOT::VecOps::RVec<unsigned long> func__SortedSelectedJetPhase1Indices(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return Argsort(-SelectedJetPhase1_pt); }
unsigned long func__QJet0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase1Indices) {  return At(SortedSelectedJetPhase1Indices,0); }
float func__QJet0_eta(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta) {  return At(SelectedJetPhase1_eta,QJet0); }
float func__QJet0_pt(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return At(SelectedJetPhase1_pt,QJet0); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJet0_p4(unsigned int __slot , const unsigned long & QJet0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase1_p4) {  return At(SelectedJetPhase1_p4,QJet0); }
unsigned long func__QJet1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase1Indices) {  return At(SortedSelectedJetPhase1Indices,1); }
float func__QJet1_eta(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta) {  return At(SelectedJetPhase1_eta,QJet1); }
float func__QJet1_pt(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return At(SelectedJetPhase1_pt,QJet1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJet1_p4(unsigned int __slot , const unsigned long & QJet1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase1_p4) {  return At(SelectedJetPhase1_p4,QJet1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__qq(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet1_p4) {  return QJet0_p4+QJet1_p4; }
float func__Mqq(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qq) {  return qq.M(); }
float func__qq_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qq) {  return qq.Pt(); }
float func__qqDeltaEta(unsigned int __slot , const float & QJet0_eta, const float & QJet1_eta) {  return abs(QJet0_eta-QJet1_eta); }
float func__qqDeltaPhi(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJet1_p4) {  return abs(ROOT::Math::VectorUtil::DeltaPhi(QJet0_p4,QJet1_p4)); }
int func__LeadMuon(unsigned int __slot ) {  return 0; }
float func__LeadMuon_eta(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_eta) {  return At(SelectedMuonPhase1_eta,LeadMuon); }
float func__LeadMuon_pt(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_pt) {  return At(SelectedMuonPhase1_pt,LeadMuon); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__LeadMuon_p4(unsigned int __slot , const int & LeadMuon, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4) {  return At(SelectedMuonPhase1_p4,LeadMuon); }
int func__SubMuon(unsigned int __slot ) {  return 1; }
int func__SubMuon_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase1_charge, const int & SubMuon) {  return At(SelectedMuonPhase1_charge,SubMuon); }
float func__SubMuon_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_eta, const int & SubMuon) {  return At(SelectedMuonPhase1_eta,SubMuon); }
float func__SubMuon_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_pt, const int & SubMuon) {  return At(SelectedMuonPhase1_pt,SubMuon); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__SubMuon_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4, const int & SubMuon) {  return At(SelectedMuonPhase1_p4,SubMuon); }
float func__Higgs_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs) {  return Higgs.Pt(); }
float func__pTbalanceAll(unsigned int __slot , const float & Higgs_pt, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase1_p4) {  return SumDef(SelectedJetPhase1_p4).pt()/Higgs_pt; }
float func__Higgs_m(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs) {  return Higgs.M(); }
float func__CS_theta(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuon_p4, const int & SubMuon_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuon_p4) {  return boost_to_CS(LeadMuon_p4, SubMuon_p4,  SubMuon_charge).first; }
float func__CS_phi(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuon_p4, const int & SubMuon_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuon_p4) {  return boost_to_CS(LeadMuon_p4, SubMuon_p4, SubMuon_charge).second; }
int func__mQQcut(unsigned int __slot ) {  return 400; }
ROOT::VecOps::RVec<unsigned int> func__SelectedJetPhase1_btagDeepB(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & Jet_btag) {  return Jet_btag; }
double func__btagCut(unsigned int __slot ) {  return 0.5; }
double func__btagCutL(unsigned int __slot ) {  return 0.5; }
int func__nbtagged(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase1_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta, const double & btagCut) {  return int(Nonzero(SelectedJetPhase1_btagDeepB > btagCut && abs(SelectedJetPhase1_eta)< 2.5).size()); }
int func__nbtaggedL(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase1_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta, const double & btagCutL) {  return int(Nonzero(SelectedJetPhase1_btagDeepB > btagCutL && abs(SelectedJetPhase1_eta)< 2.5).size()); }
int func__nelectrons(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_eta, const ROOT::VecOps::RVec<float> & Electron_pt) {  return int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size()); }
bool func__MassWindowZ(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs) {  return abs(Higgs.M()-91)<15; }
bool func__VBFRegion(unsigned int __slot , const float & Mqq, const float & QJet0_pt, const float & QJet1_pt, const int & mQQcut) {  return Mqq > mQQcut && QJet0_pt> 35 && QJet1_pt > 25; }
bool func__PreSel(unsigned int __slot , const float & LeadMuon_eta, const float & LeadMuon_pt, const float & SubMuon_eta, const float & SubMuon_pt, const bool & TriggerSel, const bool & VBFRegion, const int & nbtagged, const int & nbtaggedL, const int & nelectrons, const bool & twoOppositeSignMuons, const int & year) {  return nelectrons==0 && nbtaggedL < 2 && VBFRegion && twoOppositeSignMuons && nbtagged < 1 && (( year == 2016 && LeadMuon_pt > 26 ) || ( year == 2017 && LeadMuon_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuon_pt > 26 )) && SubMuon_pt > 20 && TriggerSel && abs(SubMuon_eta) <2.4 && abs(LeadMuon_eta) < 2.4; }
bool func__SignalRegionPhase1(unsigned int __slot , const bool & VBFRegion, const float & qqDeltaEta) {  return VBFRegion && qqDeltaEta > 2.5; }
int func__InclusiveRegion(unsigned int __slot ) {  return 1; }
bool func__SelectionTest1(unsigned int __slot , const float & LeadMuon_pt) {  return LeadMuon_pt > 50; }
double func__twoJetsWeight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsWeight__Central(unsigned int __slot ) {  return 1.; }
double func__Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuons_twoOppositeSignMuonsWeight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegion_PreSelWeight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegionWeight__Central(unsigned int __slot ) {  return 1.; }
double func__SignalRegionPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__InclusiveRegionWeight__Central(unsigned int __slot ) {  return 1.; }
double func__VBFRegionWeight__Central(unsigned int __slot ) {  return 1.; }
double func__MassWindowZWeight__Central(unsigned int __slot ) {  return 1.; }
double func__PreSelWeight__Central(unsigned int __slot ) {  return 1.; }
double func__SelectionTest1Weight__Central(unsigned int __slot ) {  return 1.; }

Result eventProcessor2026_nail(RNode rdf,int nThreads) {
     Result r;
     if(nThreads > 0)
     ROOT::EnableImplicitMT(nThreads);
	
	   auto rdf0 =rdf.DefineSlot("Muon_mass",func__Muon_mass,{"Muon_pt"});
auto rdf1 =rdf0.DefineSlot("Muon_p4",func__Muon_p4,{"Muon_eta","Muon_mass","Muon_phi","Muon_pt"});
auto rdf2 =rdf1.DefineSlot("SelectedMuonPhase1",func__SelectedMuonPhase1,{"Muon_eta"});
auto rdf3 =rdf2.DefineSlot("SelectedMuonPhase1_charge",func__SelectedMuonPhase1_charge,{"Muon_charge","SelectedMuonPhase1"});
auto rdf4 =rdf3.DefineSlot("SelectedMuonPhase1_eta",func__SelectedMuonPhase1_eta,{"Muon_eta","SelectedMuonPhase1"});
auto rdf5 =rdf4.DefineSlot("SelectedMuonPhase1_pt",func__SelectedMuonPhase1_pt,{"Muon_pt","SelectedMuonPhase1"});
auto rdf6 =rdf5.DefineSlot("SelectedMuonPhase1_p4",func__SelectedMuonPhase1_p4,{"Muon_p4","SelectedMuonPhase1"});
auto rdf7 =rdf6.DefineSlot("nSelectedMuonPhase1",func__nSelectedMuonPhase1,{"SelectedMuonPhase1"});
auto rdf8 =rdf7.DefineSlot("twoMuonsPhase1",func__twoMuons,{"nSelectedMuonPhase1"});
auto rdf9 =rdf8.DefineSlot("MuMuPhase1_allpairs",func__MuMu_allpairs,{"SelectedMuonPhase1"});
auto rdf10 =rdf9.DefineSlot("MuMuPhase1",func__MuMu,{"MuMu_allpairs"});
auto rdf11 =rdf10.DefineSlot("MuMuPhase1_0",func__MuMu0,{"MuMu","MuMuPhase1_allpairs"});
auto rdf12 =rdf11.DefineSlot("MuMuPhase1_1",func__MuMu1,{"MuMu","MuMuPhase1_allpairs"});
auto rdf13 =rdf12.DefineSlot("MuMuPhase1_0_charge",func__MuMu0_charge,{"MuMuPhase1_0","SelectedMuonPhase1_charge"});
auto rdf14 =rdf13.DefineSlot("MuMuPhase1_1_charge",func__MuMu1_charge,{"MuMuPhase1_1","SelectedMuonPhase1_charge"});
auto rdf15 =rdf14.DefineSlot("OppositeSignMuMuPhase1",func__OppositeSignMuMu,{"MuMuPhase1_0_charge","MuMuPhase1_1_charge"});
auto rdf16 =rdf15.DefineSlot("twoOppositeSignMuonsPhase1",func__twoOppositeSignMuons,{"OppositeSignMuMuPhase1"});
auto rdf17 =rdf16.DefineSlot("MuPhase1_index",func__Mu_index,{"OppositeSignMuMuPhase1"});
auto rdf18 =rdf17.DefineSlot("MuPhase1_0",func__Mu0,{"MuMu0","Mu_index"});
auto rdf19 =rdf18.DefineSlot("MuPhase1_0_p4",func__Mu0_p4,{"Mu0","SelectedMuonPhase1_p4"});
auto rdf20 =rdf19.DefineSlot("MuPhase1_1",func__Mu1,{"MuMuPhase1_1","MuPhase1_index"});
auto rdf21 =rdf20.DefineSlot("MuPhase1_1_p4",func__Mu1_p4,{"MuPhase1_1","SelectedMuonPhase1_p4"});
auto rdf22 =rdf21.DefineSlot("Higgs_Phase1",func__Higgs,{"MuPhase1_0_p4","MuPhase1_1_p4"});
auto rdf23 =rdf22.DefineSlot("Jet_p4",func__Jet_p4,{"Jet_eta","Jet_mass","Jet_phi","Jet_pt"});
auto rdf24 =rdf23.DefineSlot("jetPtCut",func__jetPtCut,{});
auto rdf25 =rdf24.DefineSlot("SelectedJetPhase1",func__SelectedJetPhase1,{"Jet_eta","Jet_pt","jetPtCut"});
auto rdf26 =rdf25.DefineSlot("SelectedJetPhase1_eta",func__SelectedJetPhase1_eta,{"Jet_eta","SelectedJetPhase1"});
auto rdf27 =rdf26.DefineSlot("SelectedJetPhase1_pt",func__SelectedJetPhase1_pt,{"Jet_pt","SelectedJetPhase1"});
auto rdf28 =rdf27.DefineSlot("SelectedJetPhase1_p4",func__SelectedJetPhase1_p4,{"Jet_p4","SelectedJetPhase1"});
auto rdf29 =rdf28.DefineSlot("nSelectedJetPhase1",func__nSelectedJetPhase1,{"SelectedJetPhase1"});
auto rdf30 =rdf29.DefineSlot("twoJets",func__twoJets,{"nSelectedJetPhase1"});
auto rdf31 =rdf30.DefineSlot("SortedSelectedJetPhase1Indices",func__SortedSelectedJetPhase1Indices,{"SelectedJetPhase1_pt"});
auto rdf32 =rdf31.DefineSlot("QJet0",func__QJet0,{"SortedSelectedJetPhase1Indices"});
auto rdf33 =rdf32.DefineSlot("QJet0_eta",func__QJet0_eta,{"QJet0","SelectedJetPhase1_eta"});
auto rdf34 =rdf33.DefineSlot("QJet0_pt",func__QJet0_pt,{"QJet0","SelectedJetPhase1_pt"});
auto rdf35 =rdf34.DefineSlot("QJet0_p4",func__QJet0_p4,{"QJet0","SelectedJetPhase1_p4"});
auto rdf36 =rdf35.DefineSlot("QJet1",func__QJet1,{"SortedSelectedJetPhase1Indices"});
auto rdf37 =rdf36.DefineSlot("QJet1_eta",func__QJet1_eta,{"QJet1","SelectedJetPhase1_eta"});
auto rdf38 =rdf37.DefineSlot("QJet1_pt",func__QJet1_pt,{"QJet1","SelectedJetPhase1_pt"});
auto rdf39 =rdf38.DefineSlot("QJet1_p4",func__QJet1_p4,{"QJet1","SelectedJetPhase1_p4"});
auto rdf40 =rdf39.DefineSlot("qq",func__qq,{"QJet0_p4","QJet1_p4"});
auto rdf41 =rdf40.DefineSlot("Mqq",func__Mqq,{"qq"});
auto rdf42 =rdf41.DefineSlot("qq_pt",func__qq_pt,{"qq"});
auto rdf43 =rdf42.DefineSlot("qqDeltaEta",func__qqDeltaEta,{"QJet0_eta","QJet1_eta"});
auto rdf44 =rdf43.DefineSlot("qqDeltaPhi",func__qqDeltaPhi,{"QJet0_p4","QJet1_p4"});
auto rdf45 =rdf44.DefineSlot("LeadMuon",func__LeadMuon,{});
auto rdf46 =rdf45.DefineSlot("LeadMuon_eta",func__LeadMuon_eta,{"LeadMuon","SelectedMuonPhase1_eta"});
auto rdf47 =rdf46.DefineSlot("LeadMuon_pt",func__LeadMuon_pt,{"LeadMuon","SelectedMuonPhase1_pt"});
auto rdf48 =rdf47.DefineSlot("LeadMuon_p4",func__LeadMuon_p4,{"LeadMuon","SelectedMuonPhase1_p4"});
auto rdf49 =rdf48.DefineSlot("SubMuon",func__SubMuon,{});
auto rdf50 =rdf49.DefineSlot("SubMuon_charge",func__SubMuon_charge,{"SelectedMuonPhase1_charge","SubMuon"});
auto rdf51 =rdf50.DefineSlot("SubMuon_eta",func__SubMuon_eta,{"SelectedMuonPhase1_eta","SubMuon"});
auto rdf52 =rdf51.DefineSlot("SubMuon_pt",func__SubMuon_pt,{"SelectedMuonPhase1_pt","SubMuon"});
auto rdf53 =rdf52.DefineSlot("SubMuon_p4",func__SubMuon_p4,{"SelectedMuonPhase1_p4","SubMuon"});
auto rdf54 =rdf53.DefineSlot("Higgs_pt",func__Higgs_pt,{"Higgs"});
auto rdf55 =rdf54.DefineSlot("pTbalanceAll",func__pTbalanceAll,{"Higgs_pt","SelectedJetPhase1_p4"});
auto rdf56 =rdf55.DefineSlot("Higgs_m",func__Higgs_m,{"Higgs"});
auto rdf57 =rdf56.DefineSlot("CS_theta",func__CS_theta,{"LeadMuon_p4","SubMuon_charge","SubMuon_p4"});
auto rdf58 =rdf57.DefineSlot("CS_phi",func__CS_phi,{"LeadMuon_p4","SubMuon_charge","SubMuon_p4"});
auto rdf59 =rdf58.DefineSlot("mQQcut",func__mQQcut,{});
auto rdf60 =rdf59.DefineSlot("SelectedJetPhase1_btagDeepB",func__SelectedJetPhase1_btagDeepB,{"Jet_btag"});
auto rdf61 =rdf60.DefineSlot("btagCut",func__btagCut,{});
auto rdf62 =rdf61.DefineSlot("btagCutL",func__btagCutL,{});
auto rdf63 =rdf62.DefineSlot("nbtagged",func__nbtagged,{"SelectedJetPhase1_btagDeepB","SelectedJetPhase1_eta","btagCut"});
auto rdf64 =rdf63.DefineSlot("nbtaggedL",func__nbtaggedL,{"SelectedJetPhase1_btagDeepB","SelectedJetPhase1_eta","btagCutL"});
auto rdf65 =rdf64.DefineSlot("nelectrons",func__nelectrons,{"Electron_eta","Electron_pt"});
auto rdf66 =rdf65.DefineSlot("MassWindowZ",func__MassWindowZ,{"Higgs"});
auto rdf67 =rdf66.DefineSlot("VBFRegion",func__VBFRegion,{"Mqq","QJet0_pt","QJet1_pt","mQQcut"});
auto rdf68 =rdf67.DefineSlot("PreSel",func__PreSel,{"LeadMuon_eta","LeadMuon_pt","SubMuon_eta","SubMuon_pt","TriggerSel","VBFRegion","nbtagged","nbtaggedL","nelectrons","twoOppositeSignMuons","year"});
auto rdf69 =rdf68.DefineSlot("SignalRegionPhase1",func__SignalRegionPhase1,{"VBFRegion","qqDeltaEta"});
auto rdf70 =rdf69.DefineSlot("InclusiveRegion",func__InclusiveRegion,{});
auto rdf71 =rdf70.DefineSlot("SelectionTest1",func__SelectionTest1,{"LeadMuon_pt"});
auto rdf72 =rdf71.DefineSlot("twoJetsWeight__Central",func__twoJetsWeight__Central,{});
auto rdf73 =rdf72.DefineSlot("twoMuonsWeight__Central",func__twoMuonsWeight__Central,{});
auto rdf74 =rdf73.DefineSlot("Weight__Central",func__Weight__Central,{});
auto rdf75 =rdf74.DefineSlot("twoMuons_twoOppositeSignMuonsWeight__Central",func__twoMuons_twoOppositeSignMuonsWeight__Central,{});
auto rdf76 =rdf75.DefineSlot("twoMuons_twoOppositeSignMuons_twoJets_VBFRegion_PreSelWeight__Central",func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegion_PreSelWeight__Central,{});
auto rdf77 =rdf76.DefineSlot("twoMuons_twoOppositeSignMuons_twoJets_VBFRegionWeight__Central",func__twoMuons_twoOppositeSignMuons_twoJets_VBFRegionWeight__Central,{});
auto rdf78 =rdf77.DefineSlot("SignalRegionPhase1Weight__Central",func__SignalRegionPhase1Weight__Central,{});
auto rdf79 =rdf78.DefineSlot("InclusiveRegionWeight__Central",func__InclusiveRegionWeight__Central,{});
auto rdf80 =rdf79.DefineSlot("VBFRegionWeight__Central",func__VBFRegionWeight__Central,{});
auto rdf81 =rdf80.DefineSlot("MassWindowZWeight__Central",func__MassWindowZWeight__Central,{});
auto rdf82 =rdf81.DefineSlot("PreSelWeight__Central",func__PreSelWeight__Central,{});
auto rdf83 =rdf82.DefineSlot("SelectionTest1Weight__Central",func__SelectionTest1Weight__Central,{});
auto toplevel=rdf83;
std::vector<ROOT::RDF::RResultPtr<TH1D>> histos;
{}auto selection_SignalRegionPhase1=rdf83.Filter("twoMuons","twoMuons").Filter("twoOppositeSignMuons","twoOppositeSignMuons").Filter("twoJets","twoJets").Filter("VBFRegion","VBFRegion").Filter("PreSel","PreSel").Filter("SignalRegionPhase1","SignalRegionPhase1");
r.rdf.emplace("SignalRegionPhase1",selection_SignalRegionPhase1);
{histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"MET_met___SignalRegionPhase1", "MET_met {SignalRegionPhase1}", 1000,0,1000},"MET_met","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJet0_pt___SignalRegionPhase1", "QJet0_pt {SignalRegionPhase1}", 30 , 0 , 300},"QJet0_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"qq_pt___SignalRegionPhase1", "qq_pt {SignalRegionPhase1}", 30 , 0 , 300},"qq_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"qqDeltaEta___SignalRegionPhase1", "qqDeltaEta {SignalRegionPhase1}", 30 , 0,10},"qqDeltaEta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"qqDeltaPhi___SignalRegionPhase1", "qqDeltaPhi {SignalRegionPhase1}", 1000,0,1000},"qqDeltaPhi","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"Higgs_m___SignalRegionPhase1", "Higgs_m {SignalRegionPhase1}", 80 , 70,150},"Higgs_m","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"pTbalanceAll___SignalRegionPhase1", "pTbalanceAll {SignalRegionPhase1}", 30 , 0 , 4},"pTbalanceAll","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"LeadMuon_pt___SignalRegionPhase1", "LeadMuon_pt {SignalRegionPhase1}", 30 , 0 , 300},"LeadMuon_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"LeadMuon_eta___SignalRegionPhase1", "LeadMuon_eta {SignalRegionPhase1}", 30 , -5 , 5},"LeadMuon_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"SubMuon_pt___SignalRegionPhase1", "SubMuon_pt {SignalRegionPhase1}", 30 , 0 , 300},"SubMuon_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"SubMuon_eta___SignalRegionPhase1", "SubMuon_eta {SignalRegionPhase1}", 30 , -5 , 5},"SubMuon_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJet0_eta___SignalRegionPhase1", "QJet0_eta {SignalRegionPhase1}", 30 , -5 , 5},"QJet0_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJet1_eta___SignalRegionPhase1", "QJet1_eta {SignalRegionPhase1}", 30 , -5 , 5},"QJet1_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJet0_pt___SignalRegionPhase1", "QJet0_pt {SignalRegionPhase1}", 30 , 0 , 300},"QJet0_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJet1_pt___SignalRegionPhase1", "QJet1_pt {SignalRegionPhase1}", 30 , 0 , 300},"QJet1_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"CS_theta___SignalRegionPhase1", "CS_theta {SignalRegionPhase1}", 30 , -3.2 , 3.2},"CS_theta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"CS_phi___SignalRegionPhase1", "CS_phi {SignalRegionPhase1}", 30 , -3.2 , 3.2},"CS_phi","SignalRegionPhase1Weight__Central"));
}auto selection_InclusiveRegion=rdf83.Filter("InclusiveRegion","InclusiveRegion");
r.rdf.emplace("InclusiveRegion",selection_InclusiveRegion);
{histos.emplace_back(selection_InclusiveRegion.Histo1D({"MET_met___InclusiveRegion", "MET_met {InclusiveRegion}", 1000,0,1000},"MET_met","InclusiveRegionWeight__Central"));
}auto selection_VBFRegion=rdf83.Filter("twoJets","twoJets").Filter("VBFRegion","VBFRegion");
r.rdf.emplace("VBFRegion",selection_VBFRegion);
{histos.emplace_back(selection_VBFRegion.Histo1D({"MET_met___VBFRegion", "MET_met {VBFRegion}", 1000,0,1000},"MET_met","VBFRegionWeight__Central"));
}auto selection_MassWindowZ=rdf83.Filter("twoMuons","twoMuons").Filter("twoOppositeSignMuons","twoOppositeSignMuons").Filter("MassWindowZ","MassWindowZ");
r.rdf.emplace("MassWindowZ",selection_MassWindowZ);
{histos.emplace_back(selection_MassWindowZ.Histo1D({"MET_met___MassWindowZ", "MET_met {MassWindowZ}", 1000,0,1000},"MET_met","MassWindowZWeight__Central"));
}auto selection_PreSel=rdf83.Filter("twoMuons","twoMuons").Filter("twoOppositeSignMuons","twoOppositeSignMuons").Filter("twoJets","twoJets").Filter("VBFRegion","VBFRegion").Filter("PreSel","PreSel");
r.rdf.emplace("PreSel",selection_PreSel);
{histos.emplace_back(selection_PreSel.Histo1D({"MET_met___PreSel", "MET_met {PreSel}", 1000,0,1000},"MET_met","PreSelWeight__Central"));
}auto selection_SelectionTest1=rdf83.Filter("twoMuons","twoMuons").Filter("SelectionTest1","SelectionTest1");
r.rdf.emplace("SelectionTest1",selection_SelectionTest1);
{histos.emplace_back(selection_SelectionTest1.Histo1D({"LeadMuon_pt___SelectionTest1", "LeadMuon_pt {SelectionTest1}", 30 , 0 , 300},"LeadMuon_pt","SelectionTest1Weight__Central"));
}
;
r.rdf.emplace("",rdf83);
r.histos=histos; return r;}
