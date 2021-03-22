
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
bool func__twoMuonsPhase1(unsigned int __slot , const int & nSelectedMuonPhase1) {  return nSelectedMuonPhase1==2; }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > func__MuMuPhase1_allpairs(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase1) {  return Combinations(Nonzero(SelectedMuonPhase1),Nonzero(SelectedMuonPhase1)); }
ROOT::VecOps::RVec<int> func__MuMuPhase1(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMuPhase1_allpairs) {  return At(MuMuPhase1_allpairs,0) < At(MuMuPhase1_allpairs,1); }
ROOT::VecOps::RVec<unsigned long> func__MuMuPhase10(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMuPhase1, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMuPhase1_allpairs) {  return At(At(MuMuPhase1_allpairs,0),MuMuPhase1); }
ROOT::VecOps::RVec<unsigned long> func__MuMuPhase11(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMuPhase1, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMuPhase1_allpairs) {  return At(At(MuMuPhase1_allpairs,1),MuMuPhase1); }
ROOT::VecOps::RVec<int> func__MuMuPhase10_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase10, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1_charge) {  return Take(SelectedMuonPhase1_charge,MuMuPhase10); }
ROOT::VecOps::RVec<int> func__MuMuPhase11_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase11, const ROOT::VecOps::RVec<int> & SelectedMuonPhase1_charge) {  return Take(SelectedMuonPhase1_charge,MuMuPhase11); }
ROOT::VecOps::RVec<unsigned long> func__OppositeSignMuMuPhase1(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMuPhase10_charge, const ROOT::VecOps::RVec<int> & MuMuPhase11_charge) {  return Nonzero(MuMuPhase10_charge != MuMuPhase11_charge); }
bool func__twoOppositeSignMuonsPhase1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMuPhase1) {  return OppositeSignMuMuPhase1.size() > 0; }
unsigned long func__MuPhase1_index(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMuPhase1) {  return At(OppositeSignMuMuPhase1,0,-200); }
int func__MuPhase10(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase10, const unsigned long & MuPhase1_index) {  return int(At(MuMuPhase10,MuPhase1_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__MuPhase10_p4(unsigned int __slot , const int & MuPhase10, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4) {  return At(SelectedMuonPhase1_p4,MuPhase10); }
int func__MuPhase11(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase11, const unsigned long & MuPhase1_index) {  return int(At(MuMuPhase11,MuPhase1_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__MuPhase11_p4(unsigned int __slot , const int & MuPhase11, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4) {  return At(SelectedMuonPhase1_p4,MuPhase11); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Higgs_Phase1(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & MuPhase10_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & MuPhase11_p4) {  return MuPhase10_p4+MuPhase11_p4; }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__Jet_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_mass, const ROOT::VecOps::RVec<float> & Jet_phi, const ROOT::VecOps::RVec<float> & Jet_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Jet_pt , Jet_eta, Jet_phi, Jet_mass); }
int func__jetPtCut(unsigned int __slot ) {  return 25; }
ROOT::VecOps::RVec<int> func__SelectedJetPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<float> & Jet_pt, const int & jetPtCut) {  return 
    Jet_pt > jetPtCut && abs(Jet_eta) < 4.7
    ; }
ROOT::VecOps::RVec<float> func__SelectedJetPhase1_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(Jet_eta,SelectedJetPhase1); }
ROOT::VecOps::RVec<float> func__SelectedJetPhase1_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_pt, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(Jet_pt,SelectedJetPhase1); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedJetPhase1_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & Jet_p4, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(Jet_p4,SelectedJetPhase1); }
int func__nSelectedJetPhase1(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return Sum(SelectedJetPhase1); }
bool func__twoJetsPhase1(unsigned int __slot , const int & nSelectedJetPhase1) {  return nSelectedJetPhase1>=2; }
ROOT::VecOps::RVec<unsigned long> func__SortedSelectedJetPhase1Indices(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return Argsort(-SelectedJetPhase1_pt); }
unsigned long func__QJetPhase1_0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase1Indices) {  return At(SortedSelectedJetPhase1Indices,0); }
float func__QJetPhase1_0_eta(unsigned int __slot , const unsigned long & QJetPhase1_0, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta) {  return At(SelectedJetPhase1_eta,QJetPhase1_0); }
float func__QJetPhase1_0_pt(unsigned int __slot , const unsigned long & QJetPhase1_0, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return At(SelectedJetPhase1_pt,QJetPhase1_0); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJetPhase1_0_p4(unsigned int __slot , const unsigned long & QJetPhase1_0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase1_p4) {  return At(SelectedJetPhase1_p4,QJetPhase1_0); }
unsigned long func__QJetPhase1_1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase1Indices) {  return At(SortedSelectedJetPhase1Indices,1); }
float func__QJetPhase1_1_eta(unsigned int __slot , const unsigned long & QJetPhase1_1, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta) {  return At(SelectedJetPhase1_eta,QJetPhase1_1); }
float func__QJetPhase1_1_pt(unsigned int __slot , const unsigned long & QJetPhase1_1, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return At(SelectedJetPhase1_pt,QJetPhase1_1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJetPhase1_1_p4(unsigned int __slot , const unsigned long & QJetPhase1_1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase1_p4) {  return At(SelectedJetPhase1_p4,QJetPhase1_1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__qqPhase1(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase1_0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase1_1_p4) {  return QJetPhase1_0_p4+QJetPhase1_1_p4; }
float func__MqqPhase1(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qqPhase1) {  return qqPhase1.M(); }
float func__qqPhase1_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qqPhase1) {  return qqPhase1.Pt(); }
float func__qqDeltaEtaPhase1(unsigned int __slot , const float & QJetPhase1_0_eta, const float & QJetPhase1_1_eta) {  return abs(QJetPhase1_0_eta-QJetPhase1_1_eta); }
float func__qqDeltaPhiPhase1(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase1_0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase1_1_p4) {  return abs(ROOT::Math::VectorUtil::DeltaPhi(QJetPhase1_0_p4,QJetPhase1_1_p4)); }
int func__LeadMuonPhase1(unsigned int __slot ) {  return 0; }
float func__LeadMuonPhase1_eta(unsigned int __slot , const int & LeadMuonPhase1, const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_eta) {  return At(SelectedMuonPhase1_eta,LeadMuonPhase1); }
float func__LeadMuonPhase1_pt(unsigned int __slot , const int & LeadMuonPhase1, const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_pt) {  return At(SelectedMuonPhase1_pt,LeadMuonPhase1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__LeadMuonPhase1_p4(unsigned int __slot , const int & LeadMuonPhase1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4) {  return At(SelectedMuonPhase1_p4,LeadMuonPhase1); }
int func__SubMuonPhase1(unsigned int __slot ) {  return 1; }
int func__SubMuonPhase1_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase1_charge, const int & SubMuonPhase1) {  return At(SelectedMuonPhase1_charge,SubMuonPhase1); }
float func__SubMuonPhase1_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_eta, const int & SubMuonPhase1) {  return At(SelectedMuonPhase1_eta,SubMuonPhase1); }
float func__SubMuonPhase1_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuonPhase1_pt, const int & SubMuonPhase1) {  return At(SelectedMuonPhase1_pt,SubMuonPhase1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__SubMuonPhase1_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase1_p4, const int & SubMuonPhase1) {  return At(SelectedMuonPhase1_p4,SubMuonPhase1); }
float func__Higgs_Phase1_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs_Phase1) {  return Higgs_Phase1.Pt(); }
float func__pTbalanceAllPhase1(unsigned int __slot , const float & Higgs_Phase1_pt, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase1_p4) {  return SumDef(SelectedJetPhase1_p4).pt()/Higgs_Phase1_pt; }
float func__Higgs_Phase1_m(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs_Phase1) {  return Higgs_Phase1.M(); }
float func__CS_Phase1_theta(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuonPhase1_p4, const int & SubMuonPhase1_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuonPhase1_p4) {  return boost_to_CS(LeadMuonPhase1_p4, SubMuonPhase1_p4,  SubMuonPhase1_charge).first; }
float func__CS_Phase1_phi(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuonPhase1_p4, const int & SubMuonPhase1_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuonPhase1_p4) {  return boost_to_CS(LeadMuonPhase1_p4, SubMuonPhase1_p4, SubMuonPhase1_charge).second; }
int func__mQQcut(unsigned int __slot ) {  return 400; }
ROOT::VecOps::RVec<unsigned int> func__SelectedJetPhase1_btagDeepB(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & Jet_btag) {  return Jet_btag; }
double func__btagCut(unsigned int __slot ) {  return 0.5; }
double func__btagCutL(unsigned int __slot ) {  return 0.5; }
int func__nbtaggedPhase1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase1_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta, const double & btagCut) {  return int(Nonzero(SelectedJetPhase1_btagDeepB > btagCut && abs(SelectedJetPhase1_eta)< 2.5).size()); }
int func__nbtaggedLPhase1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase1_btagDeepB, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta, const double & btagCutL) {  return int(Nonzero(SelectedJetPhase1_btagDeepB > btagCutL && abs(SelectedJetPhase1_eta)< 2.5).size()); }
int func__nelectronsPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_eta, const ROOT::VecOps::RVec<float> & Electron_pt) {  return int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size()); }
bool func__MassWindowZ_Phase1(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs_Phase1) {  return abs(Higgs_Phase1.M()-91)<15; }
bool func__VBFRegion_Phase1(unsigned int __slot , const float & MqqPhase1, const float & QJetPhase1_0_pt, const float & QJetPhase1_1_pt, const int & mQQcut) {  return MqqPhase1 > mQQcut && QJetPhase1_0_pt> 35 && QJetPhase1_1_pt > 25; }
bool func__PreSel_Phase1(unsigned int __slot , const float & LeadMuonPhase1_eta, const float & LeadMuonPhase1_pt, const float & SubMuonPhase1_eta, const float & SubMuonPhase1_pt, const bool & TriggerSel, const bool & VBFRegion_Phase1, const int & nbtaggedLPhase1, const int & nbtaggedPhase1, const int & nelectronsPhase1, const bool & twoOppositeSignMuonsPhase1, const int & year) {  return nelectronsPhase1==0 && nbtaggedLPhase1 < 2 && VBFRegion_Phase1 && twoOppositeSignMuonsPhase1 && nbtaggedPhase1 < 1 && (( year == 2016 && LeadMuonPhase1_pt > 26 ) || ( year == 2017 && LeadMuonPhase1_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuonPhase1_pt > 26 )) && SubMuonPhase1_pt > 20 && TriggerSel && abs(SubMuonPhase1_eta) <2.4 && abs(LeadMuonPhase1_eta) < 2.4; }
bool func__SignalRegionPhase1(unsigned int __slot , const bool & VBFRegion_Phase1, const float & qqDeltaEtaPhase1) {  return VBFRegion_Phase1 && qqDeltaEtaPhase1 > 2.5; }
int func__InclusiveRegion_Phase1(unsigned int __slot ) {  return 1; }
double func__twoJetsPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase1_twoOppositeSignMuonsPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegion_Phase1_PreSel_Phase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegion_Phase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__SignalRegionPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__InclusiveRegion_Phase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__VBFRegion_Phase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__MassWindowZ_Phase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__PreSel_Phase1Weight__Central(unsigned int __slot ) {  return 1.; }

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
auto rdf8 =rdf7.DefineSlot("twoMuonsPhase1",func__twoMuonsPhase1,{"nSelectedMuonPhase1"});
auto rdf9 =rdf8.DefineSlot("MuMuPhase1_allpairs",func__MuMuPhase1_allpairs,{"SelectedMuonPhase1"});
auto rdf10 =rdf9.DefineSlot("MuMuPhase1",func__MuMuPhase1,{"MuMuPhase1_allpairs"});
auto rdf11 =rdf10.DefineSlot("MuMuPhase10",func__MuMuPhase10,{"MuMuPhase1","MuMuPhase1_allpairs"});
auto rdf12 =rdf11.DefineSlot("MuMuPhase11",func__MuMuPhase11,{"MuMuPhase1","MuMuPhase1_allpairs"});
auto rdf13 =rdf12.DefineSlot("MuMuPhase10_charge",func__MuMuPhase10_charge,{"MuMuPhase10","SelectedMuonPhase1_charge"});
auto rdf14 =rdf13.DefineSlot("MuMuPhase11_charge",func__MuMuPhase11_charge,{"MuMuPhase11","SelectedMuonPhase1_charge"});
auto rdf15 =rdf14.DefineSlot("OppositeSignMuMuPhase1",func__OppositeSignMuMuPhase1,{"MuMuPhase10_charge","MuMuPhase11_charge"});
auto rdf16 =rdf15.DefineSlot("twoOppositeSignMuonsPhase1",func__twoOppositeSignMuonsPhase1,{"OppositeSignMuMuPhase1"});
auto rdf17 =rdf16.DefineSlot("MuPhase1_index",func__MuPhase1_index,{"OppositeSignMuMuPhase1"});
auto rdf18 =rdf17.DefineSlot("MuPhase10",func__MuPhase10,{"MuMuPhase10","MuPhase1_index"});
auto rdf19 =rdf18.DefineSlot("MuPhase10_p4",func__MuPhase10_p4,{"MuPhase10","SelectedMuonPhase1_p4"});
auto rdf20 =rdf19.DefineSlot("MuPhase11",func__MuPhase11,{"MuMuPhase11","MuPhase1_index"});
auto rdf21 =rdf20.DefineSlot("MuPhase11_p4",func__MuPhase11_p4,{"MuPhase11","SelectedMuonPhase1_p4"});
auto rdf22 =rdf21.DefineSlot("Higgs_Phase1",func__Higgs_Phase1,{"MuPhase10_p4","MuPhase11_p4"});
auto rdf23 =rdf22.DefineSlot("Jet_p4",func__Jet_p4,{"Jet_eta","Jet_mass","Jet_phi","Jet_pt"});
auto rdf24 =rdf23.DefineSlot("jetPtCut",func__jetPtCut,{});
auto rdf25 =rdf24.DefineSlot("SelectedJetPhase1",func__SelectedJetPhase1,{"Jet_eta","Jet_pt","jetPtCut"});
auto rdf26 =rdf25.DefineSlot("SelectedJetPhase1_eta",func__SelectedJetPhase1_eta,{"Jet_eta","SelectedJetPhase1"});
auto rdf27 =rdf26.DefineSlot("SelectedJetPhase1_pt",func__SelectedJetPhase1_pt,{"Jet_pt","SelectedJetPhase1"});
auto rdf28 =rdf27.DefineSlot("SelectedJetPhase1_p4",func__SelectedJetPhase1_p4,{"Jet_p4","SelectedJetPhase1"});
auto rdf29 =rdf28.DefineSlot("nSelectedJetPhase1",func__nSelectedJetPhase1,{"SelectedJetPhase1"});
auto rdf30 =rdf29.DefineSlot("twoJetsPhase1",func__twoJetsPhase1,{"nSelectedJetPhase1"});
auto rdf31 =rdf30.DefineSlot("SortedSelectedJetPhase1Indices",func__SortedSelectedJetPhase1Indices,{"SelectedJetPhase1_pt"});
auto rdf32 =rdf31.DefineSlot("QJetPhase1_0",func__QJetPhase1_0,{"SortedSelectedJetPhase1Indices"});
auto rdf33 =rdf32.DefineSlot("QJetPhase1_0_eta",func__QJetPhase1_0_eta,{"QJetPhase1_0","SelectedJetPhase1_eta"});
auto rdf34 =rdf33.DefineSlot("QJetPhase1_0_pt",func__QJetPhase1_0_pt,{"QJetPhase1_0","SelectedJetPhase1_pt"});
auto rdf35 =rdf34.DefineSlot("QJetPhase1_0_p4",func__QJetPhase1_0_p4,{"QJetPhase1_0","SelectedJetPhase1_p4"});
auto rdf36 =rdf35.DefineSlot("QJetPhase1_1",func__QJetPhase1_1,{"SortedSelectedJetPhase1Indices"});
auto rdf37 =rdf36.DefineSlot("QJetPhase1_1_eta",func__QJetPhase1_1_eta,{"QJetPhase1_1","SelectedJetPhase1_eta"});
auto rdf38 =rdf37.DefineSlot("QJetPhase1_1_pt",func__QJetPhase1_1_pt,{"QJetPhase1_1","SelectedJetPhase1_pt"});
auto rdf39 =rdf38.DefineSlot("QJetPhase1_1_p4",func__QJetPhase1_1_p4,{"QJetPhase1_1","SelectedJetPhase1_p4"});
auto rdf40 =rdf39.DefineSlot("qqPhase1",func__qqPhase1,{"QJetPhase1_0_p4","QJetPhase1_1_p4"});
auto rdf41 =rdf40.DefineSlot("MqqPhase1",func__MqqPhase1,{"qqPhase1"});
auto rdf42 =rdf41.DefineSlot("qqPhase1_pt",func__qqPhase1_pt,{"qqPhase1"});
auto rdf43 =rdf42.DefineSlot("qqDeltaEtaPhase1",func__qqDeltaEtaPhase1,{"QJetPhase1_0_eta","QJetPhase1_1_eta"});
auto rdf44 =rdf43.DefineSlot("qqDeltaPhiPhase1",func__qqDeltaPhiPhase1,{"QJetPhase1_0_p4","QJetPhase1_1_p4"});
auto rdf45 =rdf44.DefineSlot("LeadMuonPhase1",func__LeadMuonPhase1,{});
auto rdf46 =rdf45.DefineSlot("LeadMuonPhase1_eta",func__LeadMuonPhase1_eta,{"LeadMuonPhase1","SelectedMuonPhase1_eta"});
auto rdf47 =rdf46.DefineSlot("LeadMuonPhase1_pt",func__LeadMuonPhase1_pt,{"LeadMuonPhase1","SelectedMuonPhase1_pt"});
auto rdf48 =rdf47.DefineSlot("LeadMuonPhase1_p4",func__LeadMuonPhase1_p4,{"LeadMuonPhase1","SelectedMuonPhase1_p4"});
auto rdf49 =rdf48.DefineSlot("SubMuonPhase1",func__SubMuonPhase1,{});
auto rdf50 =rdf49.DefineSlot("SubMuonPhase1_charge",func__SubMuonPhase1_charge,{"SelectedMuonPhase1_charge","SubMuonPhase1"});
auto rdf51 =rdf50.DefineSlot("SubMuonPhase1_eta",func__SubMuonPhase1_eta,{"SelectedMuonPhase1_eta","SubMuonPhase1"});
auto rdf52 =rdf51.DefineSlot("SubMuonPhase1_pt",func__SubMuonPhase1_pt,{"SelectedMuonPhase1_pt","SubMuonPhase1"});
auto rdf53 =rdf52.DefineSlot("SubMuonPhase1_p4",func__SubMuonPhase1_p4,{"SelectedMuonPhase1_p4","SubMuonPhase1"});
auto rdf54 =rdf53.DefineSlot("Higgs_Phase1_pt",func__Higgs_Phase1_pt,{"Higgs_Phase1"});
auto rdf55 =rdf54.DefineSlot("pTbalanceAllPhase1",func__pTbalanceAllPhase1,{"Higgs_Phase1_pt","SelectedJetPhase1_p4"});
auto rdf56 =rdf55.DefineSlot("Higgs_Phase1_m",func__Higgs_Phase1_m,{"Higgs_Phase1"});
auto rdf57 =rdf56.DefineSlot("CS_Phase1_theta",func__CS_Phase1_theta,{"LeadMuonPhase1_p4","SubMuonPhase1_charge","SubMuonPhase1_p4"});
auto rdf58 =rdf57.DefineSlot("CS_Phase1_phi",func__CS_Phase1_phi,{"LeadMuonPhase1_p4","SubMuonPhase1_charge","SubMuonPhase1_p4"});
auto rdf59 =rdf58.DefineSlot("mQQcut",func__mQQcut,{});
auto rdf60 =rdf59.DefineSlot("SelectedJetPhase1_btagDeepB",func__SelectedJetPhase1_btagDeepB,{"Jet_btag"});
auto rdf61 =rdf60.DefineSlot("btagCut",func__btagCut,{});
auto rdf62 =rdf61.DefineSlot("btagCutL",func__btagCutL,{});
auto rdf63 =rdf62.DefineSlot("nbtaggedPhase1",func__nbtaggedPhase1,{"SelectedJetPhase1_btagDeepB","SelectedJetPhase1_eta","btagCut"});
auto rdf64 =rdf63.DefineSlot("nbtaggedLPhase1",func__nbtaggedLPhase1,{"SelectedJetPhase1_btagDeepB","SelectedJetPhase1_eta","btagCutL"});
auto rdf65 =rdf64.DefineSlot("nelectronsPhase1",func__nelectronsPhase1,{"Electron_eta","Electron_pt"});
auto rdf66 =rdf65.DefineSlot("MassWindowZ_Phase1",func__MassWindowZ_Phase1,{"Higgs_Phase1"});
auto rdf67 =rdf66.DefineSlot("VBFRegion_Phase1",func__VBFRegion_Phase1,{"MqqPhase1","QJetPhase1_0_pt","QJetPhase1_1_pt","mQQcut"});
auto rdf68 =rdf67.DefineSlot("PreSel_Phase1",func__PreSel_Phase1,{"LeadMuonPhase1_eta","LeadMuonPhase1_pt","SubMuonPhase1_eta","SubMuonPhase1_pt","TriggerSel","VBFRegion_Phase1","nbtaggedLPhase1","nbtaggedPhase1","nelectronsPhase1","twoOppositeSignMuonsPhase1","year"});
auto rdf69 =rdf68.DefineSlot("SignalRegionPhase1",func__SignalRegionPhase1,{"VBFRegion_Phase1","qqDeltaEtaPhase1"});
auto rdf70 =rdf69.DefineSlot("InclusiveRegion_Phase1",func__InclusiveRegion_Phase1,{});
auto rdf71 =rdf70.DefineSlot("twoJetsPhase1Weight__Central",func__twoJetsPhase1Weight__Central,{});
auto rdf72 =rdf71.DefineSlot("twoMuonsPhase1Weight__Central",func__twoMuonsPhase1Weight__Central,{});
auto rdf73 =rdf72.DefineSlot("Weight__Central",func__Weight__Central,{});
auto rdf74 =rdf73.DefineSlot("twoMuonsPhase1_twoOppositeSignMuonsPhase1Weight__Central",func__twoMuonsPhase1_twoOppositeSignMuonsPhase1Weight__Central,{});
auto rdf75 =rdf74.DefineSlot("twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegion_Phase1_PreSel_Phase1Weight__Central",func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegion_Phase1_PreSel_Phase1Weight__Central,{});
auto rdf76 =rdf75.DefineSlot("twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegion_Phase1Weight__Central",func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegion_Phase1Weight__Central,{});
auto rdf77 =rdf76.DefineSlot("SignalRegionPhase1Weight__Central",func__SignalRegionPhase1Weight__Central,{});
auto rdf78 =rdf77.DefineSlot("InclusiveRegion_Phase1Weight__Central",func__InclusiveRegion_Phase1Weight__Central,{});
auto rdf79 =rdf78.DefineSlot("VBFRegion_Phase1Weight__Central",func__VBFRegion_Phase1Weight__Central,{});
auto rdf80 =rdf79.DefineSlot("MassWindowZ_Phase1Weight__Central",func__MassWindowZ_Phase1Weight__Central,{});
auto rdf81 =rdf80.DefineSlot("PreSel_Phase1Weight__Central",func__PreSel_Phase1Weight__Central,{});
auto toplevel=rdf81;
std::vector<ROOT::RDF::RResultPtr<TH1D>> histos;
{}auto selection_SignalRegionPhase1=rdf81.Filter("twoMuonsPhase1","twoMuonsPhase1").Filter("twoOppositeSignMuonsPhase1","twoOppositeSignMuonsPhase1").Filter("twoJetsPhase1","twoJetsPhase1").Filter("VBFRegion_Phase1","VBFRegion_Phase1").Filter("PreSel_Phase1","PreSel_Phase1").Filter("SignalRegionPhase1","SignalRegionPhase1");
r.rdf.emplace("SignalRegionPhase1",selection_SignalRegionPhase1);
{histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"MET_met___SignalRegionPhase1", "MET_met {SignalRegionPhase1}", 1000,0,1000},"MET_met","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJetPhase1_0_pt___SignalRegionPhase1", "QJetPhase1_0_pt {SignalRegionPhase1}", 30 , 0 , 300},"QJetPhase1_0_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"qqPhase1_pt___SignalRegionPhase1", "qqPhase1_pt {SignalRegionPhase1}", 30 , 0 , 300},"qqPhase1_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"qqDeltaEtaPhase1___SignalRegionPhase1", "qqDeltaEtaPhase1 {SignalRegionPhase1}", 30 , 0,10},"qqDeltaEtaPhase1","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"qqDeltaPhiPhase1___SignalRegionPhase1", "qqDeltaPhiPhase1 {SignalRegionPhase1}", 1000,0,1000},"qqDeltaPhiPhase1","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"Higgs_Phase1_m___SignalRegionPhase1", "Higgs_Phase1_m {SignalRegionPhase1}", 30 , 0,500},"Higgs_Phase1_m","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"pTbalanceAllPhase1___SignalRegionPhase1", "pTbalanceAllPhase1 {SignalRegionPhase1}", 30 , 0 , 4},"pTbalanceAllPhase1","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"LeadMuonPhase1_pt___SignalRegionPhase1", "LeadMuonPhase1_pt {SignalRegionPhase1}", 30 , 0 , 300},"LeadMuonPhase1_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"LeadMuonPhase1_eta___SignalRegionPhase1", "LeadMuonPhase1_eta {SignalRegionPhase1}", 30 , -5 , 5},"LeadMuonPhase1_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"SubMuonPhase1_pt___SignalRegionPhase1", "SubMuonPhase1_pt {SignalRegionPhase1}", 30 , 0 , 300},"SubMuonPhase1_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"SubMuonPhase1_eta___SignalRegionPhase1", "SubMuonPhase1_eta {SignalRegionPhase1}", 30 , -5 , 5},"SubMuonPhase1_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJetPhase1_0_eta___SignalRegionPhase1", "QJetPhase1_0_eta {SignalRegionPhase1}", 30 , -5 , 5},"QJetPhase1_0_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJetPhase1_1_eta___SignalRegionPhase1", "QJetPhase1_1_eta {SignalRegionPhase1}", 30 , -5 , 5},"QJetPhase1_1_eta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJetPhase1_0_pt___SignalRegionPhase1", "QJetPhase1_0_pt {SignalRegionPhase1}", 30 , 0 , 300},"QJetPhase1_0_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"QJetPhase1_1_pt___SignalRegionPhase1", "QJetPhase1_1_pt {SignalRegionPhase1}", 30 , 0 , 300},"QJetPhase1_1_pt","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"CS_Phase1_theta___SignalRegionPhase1", "CS_Phase1_theta {SignalRegionPhase1}", 30 , -3.2 , 3.2},"CS_Phase1_theta","SignalRegionPhase1Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase1.Histo1D({"CS_Phase1_phi___SignalRegionPhase1", "CS_Phase1_phi {SignalRegionPhase1}", 30 , -3.2 , 3.2},"CS_Phase1_phi","SignalRegionPhase1Weight__Central"));
}auto selection_InclusiveRegion_Phase1=rdf81.Filter("InclusiveRegion_Phase1","InclusiveRegion_Phase1");
r.rdf.emplace("InclusiveRegion_Phase1",selection_InclusiveRegion_Phase1);
{histos.emplace_back(selection_InclusiveRegion_Phase1.Histo1D({"MET_met___InclusiveRegion_Phase1", "MET_met {InclusiveRegion_Phase1}", 1000,0,1000},"MET_met","InclusiveRegion_Phase1Weight__Central"));
}auto selection_VBFRegion_Phase1=rdf81.Filter("twoJetsPhase1","twoJetsPhase1").Filter("VBFRegion_Phase1","VBFRegion_Phase1");
r.rdf.emplace("VBFRegion_Phase1",selection_VBFRegion_Phase1);
{histos.emplace_back(selection_VBFRegion_Phase1.Histo1D({"MET_met___VBFRegion_Phase1", "MET_met {VBFRegion_Phase1}", 1000,0,1000},"MET_met","VBFRegion_Phase1Weight__Central"));
}auto selection_MassWindowZ_Phase1=rdf81.Filter("twoMuonsPhase1","twoMuonsPhase1").Filter("twoOppositeSignMuonsPhase1","twoOppositeSignMuonsPhase1").Filter("MassWindowZ_Phase1","MassWindowZ_Phase1");
r.rdf.emplace("MassWindowZ_Phase1",selection_MassWindowZ_Phase1);
{histos.emplace_back(selection_MassWindowZ_Phase1.Histo1D({"MET_met___MassWindowZ_Phase1", "MET_met {MassWindowZ_Phase1}", 1000,0,1000},"MET_met","MassWindowZ_Phase1Weight__Central"));
}auto selection_PreSel_Phase1=rdf81.Filter("twoMuonsPhase1","twoMuonsPhase1").Filter("twoOppositeSignMuonsPhase1","twoOppositeSignMuonsPhase1").Filter("twoJetsPhase1","twoJetsPhase1").Filter("VBFRegion_Phase1","VBFRegion_Phase1").Filter("PreSel_Phase1","PreSel_Phase1");
r.rdf.emplace("PreSel_Phase1",selection_PreSel_Phase1);
{histos.emplace_back(selection_PreSel_Phase1.Histo1D({"MET_met___PreSel_Phase1", "MET_met {PreSel_Phase1}", 1000,0,1000},"MET_met","PreSel_Phase1Weight__Central"));
}
;
r.rdf.emplace("",rdf81);
r.histos=histos; return r;}