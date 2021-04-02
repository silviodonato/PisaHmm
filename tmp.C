
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

#include "boost_to_CS.h"
ROOT::VecOps::RVec<float> func__Muon_mass(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_pt) {  return 0.f*Muon_pt; }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__Muon_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<float> & Muon_mass, const ROOT::VecOps::RVec<float> & Muon_phi, const ROOT::VecOps::RVec<float> & Muon_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(Muon_pt , Muon_eta, Muon_phi, Muon_mass); }
ROOT::VecOps::RVec<int> func__SelectedMuonPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<float> & Muon_isolationvar) {  return abs(Muon_eta) < 2.4 && (Muon_isolationvar)<0.25; }
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
int func__jetPtCut(unsigned int __slot ) {  return 25; }
ROOT::VecOps::RVec<int> func__JetToUsePhase1Central(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_eta) {  return abs(JetPUPPI_eta)<2.4; }
ROOT::VecOps::RVec<unsigned int> func__JetToUsePhase1Central_btag(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & JetPUPPI_btag, const ROOT::VecOps::RVec<int> & JetToUsePhase1Central) {  return At(JetPUPPI_btag,JetToUsePhase1Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Central_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_eta, const ROOT::VecOps::RVec<int> & JetToUsePhase1Central) {  return At(JetPUPPI_eta,JetToUsePhase1Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Central_mass(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_mass, const ROOT::VecOps::RVec<int> & JetToUsePhase1Central) {  return At(JetPUPPI_mass,JetToUsePhase1Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Central_phi(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_phi, const ROOT::VecOps::RVec<int> & JetToUsePhase1Central) {  return At(JetPUPPI_phi,JetToUsePhase1Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Central_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_pt, const ROOT::VecOps::RVec<int> & JetToUsePhase1Central) {  return At(JetPUPPI_pt,JetToUsePhase1Central); }
int func__nJetToUsePhase1Central(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase1Central) {  return Sum(JetToUsePhase1Central); }
ROOT::VecOps::RVec<int> func__JetToUsePhase1Forward(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta) {  return abs(Jet_eta)>2.4; }
ROOT::VecOps::RVec<unsigned int> func__JetToUsePhase1Forward_btag(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase1Forward, const ROOT::VecOps::RVec<unsigned int> & Jet_btag) {  return At(Jet_btag,JetToUsePhase1Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Forward_eta(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase1Forward, const ROOT::VecOps::RVec<float> & Jet_eta) {  return At(Jet_eta,JetToUsePhase1Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Forward_mass(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase1Forward, const ROOT::VecOps::RVec<float> & Jet_mass) {  return At(Jet_mass,JetToUsePhase1Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Forward_phi(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase1Forward, const ROOT::VecOps::RVec<float> & Jet_phi) {  return At(Jet_phi,JetToUsePhase1Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1Forward_pt(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase1Forward, const ROOT::VecOps::RVec<float> & Jet_pt) {  return At(Jet_pt,JetToUsePhase1Forward); }
int func__nJetToUsePhase1Forward(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase1Forward) {  return Sum(JetToUsePhase1Forward); }
int func__nJetToUsePhase1(unsigned int __slot , const int & nJetToUsePhase1Central, const int & nJetToUsePhase1Forward) {  return nJetToUsePhase1Central+nJetToUsePhase1Forward; }
ROOT::VecOps::RVec<unsigned int> func__JetToUsePhase1_btag(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & JetToUsePhase1Central_btag, const ROOT::VecOps::RVec<unsigned int> & JetToUsePhase1Forward_btag) {  return Concat(JetToUsePhase1Central_btag,JetToUsePhase1Forward_btag); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1_mass(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1Central_mass, const ROOT::VecOps::RVec<float> & JetToUsePhase1Forward_mass) {  return Concat(JetToUsePhase1Central_mass,JetToUsePhase1Forward_mass); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1Central_pt, const ROOT::VecOps::RVec<float> & JetToUsePhase1Forward_pt) {  return Concat(JetToUsePhase1Central_pt,JetToUsePhase1Forward_pt); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1_phi(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1Central_phi, const ROOT::VecOps::RVec<float> & JetToUsePhase1Forward_phi) {  return Concat(JetToUsePhase1Central_phi,JetToUsePhase1Forward_phi); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1Central_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase1Forward_eta) {  return Concat(JetToUsePhase1Central_eta,JetToUsePhase1Forward_eta); }
ROOT::VecOps::RVec<float> func__Lepton_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_pt, const ROOT::VecOps::RVec<float> & Muon_pt) {  return Concat(Muon_pt,Electron_pt); }
ROOT::VecOps::RVec<float> func__Lepton_phi(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_phi, const ROOT::VecOps::RVec<float> & Muon_phi) {  return Concat(Muon_phi,Electron_phi); }
ROOT::VecOps::RVec<float> func__Lepton_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_eta, const ROOT::VecOps::RVec<float> & Muon_eta) {  return Concat(Muon_eta,Electron_eta); }
ROOT::VecOps::RVec<int> func__SelectedLeptonPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & Lepton_pt) {  return Lepton_pt > 10; }
ROOT::VecOps::RVec<float> func__SelectedLeptonPhase1_phi(unsigned int __slot , const ROOT::VecOps::RVec<float> & Lepton_phi, const ROOT::VecOps::RVec<int> & SelectedLeptonPhase1) {  return At(Lepton_phi,SelectedLeptonPhase1); }
ROOT::VecOps::RVec<float> func__SelectedLeptonPhase1_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Lepton_eta, const ROOT::VecOps::RVec<int> & SelectedLeptonPhase1) {  return At(Lepton_eta,SelectedLeptonPhase1); }
int func__nSelectedLeptonPhase1(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedLeptonPhase1) {  return Sum(SelectedLeptonPhase1); }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > func__JetToUsePhase1SelectedLeptonPhase1Pair(unsigned int __slot , const int & nJetToUsePhase1, const int & nSelectedLeptonPhase1) {  return Combinations(nJetToUsePhase1,nSelectedLeptonPhase1); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1SelectedLeptonPhase1Pair_dr(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > & JetToUsePhase1SelectedLeptonPhase1Pair, const ROOT::VecOps::RVec<float> & JetToUsePhase1_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase1_phi, const ROOT::VecOps::RVec<float> & SelectedLeptonPhase1_eta, const ROOT::VecOps::RVec<float> & SelectedLeptonPhase1_phi) {  return DeltaR(Take(JetToUsePhase1_eta,At(JetToUsePhase1SelectedLeptonPhase1Pair,0)),Take(SelectedLeptonPhase1_eta,At(JetToUsePhase1SelectedLeptonPhase1Pair,1)),Take(JetToUsePhase1_phi,At(JetToUsePhase1SelectedLeptonPhase1Pair,0)),Take(SelectedLeptonPhase1_phi,At(JetToUsePhase1SelectedLeptonPhase1Pair,1))  ); }
ROOT::VecOps::RVec<float> func__JetToUsePhase1_SelectedLeptonPhase1Dr(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1SelectedLeptonPhase1Pair_dr, const int & nJetToUsePhase1, const int & nSelectedLeptonPhase1) {  return matrix_map(nJetToUsePhase1,nSelectedLeptonPhase1,1,[](const ROOT::VecOps::RVec<float> & v) {return v.size()>0?(-Max(-v)):-99;},JetToUsePhase1SelectedLeptonPhase1Pair_dr); }
ROOT::VecOps::RVec<unsigned long> func__JetToUsePhase1_SelectedLeptonPhase1Idx(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1SelectedLeptonPhase1Pair_dr, const int & nJetToUsePhase1, const int & nSelectedLeptonPhase1) {  return matrix_map(nJetToUsePhase1,nSelectedLeptonPhase1,1,[](const ROOT::VecOps::RVec<float> & v) {return v.size()>0?Argmax(-v):-1;},JetToUsePhase1SelectedLeptonPhase1Pair_dr); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__JetToUsePhase1_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase1_mass, const ROOT::VecOps::RVec<float> & JetToUsePhase1_phi, const ROOT::VecOps::RVec<float> & JetToUsePhase1_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(JetToUsePhase1_pt , JetToUsePhase1_eta, JetToUsePhase1_phi, JetToUsePhase1_mass); }
ROOT::VecOps::RVec<int> func__SelectedJetPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1_SelectedLeptonPhase1Dr, const ROOT::VecOps::RVec<unsigned long> & JetToUsePhase1_SelectedLeptonPhase1Idx, const ROOT::VecOps::RVec<float> & JetToUsePhase1_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase1_pt, const int & jetPtCut) {  return 
    JetToUsePhase1_pt > jetPtCut && abs(JetToUsePhase1_eta) < 4.7 && (JetToUsePhase1_SelectedLeptonPhase1Idx==-1 || JetToUsePhase1_SelectedLeptonPhase1Dr > 0.4)
    ; }
ROOT::VecOps::RVec<unsigned int> func__SelectedJetPhase1_btag(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & JetToUsePhase1_btag, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(JetToUsePhase1_btag,SelectedJetPhase1); }
ROOT::VecOps::RVec<float> func__SelectedJetPhase1_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1_pt, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(JetToUsePhase1_pt,SelectedJetPhase1); }
ROOT::VecOps::RVec<float> func__SelectedJetPhase1_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase1_eta, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(JetToUsePhase1_eta,SelectedJetPhase1); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedJetPhase1_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & JetToUsePhase1_p4, const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return At(JetToUsePhase1_p4,SelectedJetPhase1); }
int func__nSelectedJetPhase1(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedJetPhase1) {  return Sum(SelectedJetPhase1); }
bool func__twoJetsPhase1(unsigned int __slot , const int & nSelectedJetPhase1) {  return nSelectedJetPhase1>=2; }
ROOT::VecOps::RVec<unsigned long> func__SortedSelectedJetPhase1Indices(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return Argsort(-SelectedJetPhase1_pt); }
unsigned long func__QJetPhase1_0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase1Indices) {  return At(SortedSelectedJetPhase1Indices,0); }
float func__QJetPhase1_0_pt(unsigned int __slot , const unsigned long & QJetPhase1_0, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return At(SelectedJetPhase1_pt,QJetPhase1_0); }
float func__QJetPhase1_0_eta(unsigned int __slot , const unsigned long & QJetPhase1_0, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta) {  return At(SelectedJetPhase1_eta,QJetPhase1_0); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJetPhase1_0_p4(unsigned int __slot , const unsigned long & QJetPhase1_0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase1_p4) {  return At(SelectedJetPhase1_p4,QJetPhase1_0); }
unsigned long func__QJetPhase1_1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase1Indices) {  return At(SortedSelectedJetPhase1Indices,1); }
float func__QJetPhase1_1_pt(unsigned int __slot , const unsigned long & QJetPhase1_1, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_pt) {  return At(SelectedJetPhase1_pt,QJetPhase1_1); }
float func__QJetPhase1_1_eta(unsigned int __slot , const unsigned long & QJetPhase1_1, const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta) {  return At(SelectedJetPhase1_eta,QJetPhase1_1); }
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
ROOT::VecOps::RVec<unsigned int> func__SelectedJetPhase1btagDeepB(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase1_btag) {  return SelectedJetPhase1_btag; }
double func__btagCut(unsigned int __slot ) {  return 0.5; }
double func__btagCutL(unsigned int __slot ) {  return 0.5; }
int func__nbtaggedPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta, const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase1btagDeepB, const double & btagCut) {  return int(Nonzero(SelectedJetPhase1btagDeepB > btagCut && abs(SelectedJetPhase1_eta)< 2.5).size()); }
int func__nbtaggedLPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase1_eta, const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase1btagDeepB, const double & btagCutL) {  return int(Nonzero(SelectedJetPhase1btagDeepB > btagCutL && abs(SelectedJetPhase1_eta)< 2.5).size()); }
int func__nelectronsPhase1(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_eta, const ROOT::VecOps::RVec<float> & Electron_pt) {  return int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size()); }
bool func__MassWindowZPhase1(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs_Phase1) {  return abs(Higgs_Phase1.M()-91)<15; }
bool func__VBFRegionPhase1(unsigned int __slot , const float & MqqPhase1, const float & QJetPhase1_0_pt, const float & QJetPhase1_1_pt, const int & mQQcut) {  return MqqPhase1 > mQQcut && QJetPhase1_0_pt> 35 && QJetPhase1_1_pt > 25; }
bool func__PreSelPhase1(unsigned int __slot , const float & LeadMuonPhase1_eta, const float & LeadMuonPhase1_pt, const float & SubMuonPhase1_eta, const float & SubMuonPhase1_pt, const bool & TriggerSel, const bool & VBFRegionPhase1, const int & nbtaggedLPhase1, const int & nbtaggedPhase1, const int & nelectronsPhase1, const bool & twoOppositeSignMuonsPhase1, const int & year) {  return nelectronsPhase1==0 && nbtaggedLPhase1 < 2 && VBFRegionPhase1 && twoOppositeSignMuonsPhase1 && nbtaggedPhase1 < 1 && (( year == 2016 && LeadMuonPhase1_pt > 26 ) || ( year == 2017 && LeadMuonPhase1_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuonPhase1_pt > 26 )) && SubMuonPhase1_pt > 20 && TriggerSel && abs(SubMuonPhase1_eta) <2.4 && abs(LeadMuonPhase1_eta) < 2.4; }
bool func__SignalRegionPhase1(unsigned int __slot , const bool & VBFRegionPhase1, const float & qqDeltaEtaPhase1) {  return VBFRegionPhase1 && qqDeltaEtaPhase1 > 2.5; }
int func__InclusiveRegionPhase1(unsigned int __slot ) {  return 1; }
ROOT::VecOps::RVec<int> func__SelectedMuonPhase2(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<float> & Muon_isolationvar) {  return abs(Muon_eta) < 2.8 && (Muon_isolationvar)<0.25; }
ROOT::VecOps::RVec<int> func__SelectedMuonPhase2_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & Muon_charge, const ROOT::VecOps::RVec<int> & SelectedMuonPhase2) {  return At(Muon_charge,SelectedMuonPhase2); }
ROOT::VecOps::RVec<float> func__SelectedMuonPhase2_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_eta, const ROOT::VecOps::RVec<int> & SelectedMuonPhase2) {  return At(Muon_eta,SelectedMuonPhase2); }
ROOT::VecOps::RVec<float> func__SelectedMuonPhase2_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & Muon_pt, const ROOT::VecOps::RVec<int> & SelectedMuonPhase2) {  return At(Muon_pt,SelectedMuonPhase2); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedMuonPhase2_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & Muon_p4, const ROOT::VecOps::RVec<int> & SelectedMuonPhase2) {  return At(Muon_p4,SelectedMuonPhase2); }
int func__nSelectedMuonPhase2(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase2) {  return Sum(SelectedMuonPhase2); }
bool func__twoMuonsPhase2(unsigned int __slot , const int & nSelectedMuonPhase2) {  return nSelectedMuonPhase2==2; }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > func__MuMuPhase2_allpairs(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase2) {  return Combinations(Nonzero(SelectedMuonPhase2),Nonzero(SelectedMuonPhase2)); }
ROOT::VecOps::RVec<int> func__MuMuPhase2(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMuPhase2_allpairs) {  return At(MuMuPhase2_allpairs,0) < At(MuMuPhase2_allpairs,1); }
ROOT::VecOps::RVec<unsigned long> func__MuMuPhase20(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMuPhase2, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMuPhase2_allpairs) {  return At(At(MuMuPhase2_allpairs,0),MuMuPhase2); }
ROOT::VecOps::RVec<unsigned long> func__MuMuPhase21(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMuPhase2, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long> > & MuMuPhase2_allpairs) {  return At(At(MuMuPhase2_allpairs,1),MuMuPhase2); }
ROOT::VecOps::RVec<int> func__MuMuPhase20_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase20, const ROOT::VecOps::RVec<int> & SelectedMuonPhase2_charge) {  return Take(SelectedMuonPhase2_charge,MuMuPhase20); }
ROOT::VecOps::RVec<int> func__MuMuPhase21_charge(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase21, const ROOT::VecOps::RVec<int> & SelectedMuonPhase2_charge) {  return Take(SelectedMuonPhase2_charge,MuMuPhase21); }
ROOT::VecOps::RVec<unsigned long> func__OppositeSignMuMuPhase2(unsigned int __slot , const ROOT::VecOps::RVec<int> & MuMuPhase20_charge, const ROOT::VecOps::RVec<int> & MuMuPhase21_charge) {  return Nonzero(MuMuPhase20_charge != MuMuPhase21_charge); }
bool func__twoOppositeSignMuonsPhase2(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMuPhase2) {  return OppositeSignMuMuPhase2.size() > 0; }
unsigned long func__MuPhase2_index(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & OppositeSignMuMuPhase2) {  return At(OppositeSignMuMuPhase2,0,-200); }
int func__MuPhase20(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase20, const unsigned long & MuPhase2_index) {  return int(At(MuMuPhase20,MuPhase2_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__MuPhase20_p4(unsigned int __slot , const int & MuPhase20, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase2_p4) {  return At(SelectedMuonPhase2_p4,MuPhase20); }
int func__MuPhase21(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & MuMuPhase21, const unsigned long & MuPhase2_index) {  return int(At(MuMuPhase21,MuPhase2_index)); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__MuPhase21_p4(unsigned int __slot , const int & MuPhase21, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase2_p4) {  return At(SelectedMuonPhase2_p4,MuPhase21); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__Higgs_Phase2(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & MuPhase20_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & MuPhase21_p4) {  return MuPhase20_p4+MuPhase21_p4; }
ROOT::VecOps::RVec<int> func__JetToUsePhase2Central(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_eta) {  return abs(JetPUPPI_eta)<4; }
ROOT::VecOps::RVec<unsigned int> func__JetToUsePhase2Central_btag(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & JetPUPPI_btag, const ROOT::VecOps::RVec<int> & JetToUsePhase2Central) {  return At(JetPUPPI_btag,JetToUsePhase2Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Central_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_eta, const ROOT::VecOps::RVec<int> & JetToUsePhase2Central) {  return At(JetPUPPI_eta,JetToUsePhase2Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Central_mass(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_mass, const ROOT::VecOps::RVec<int> & JetToUsePhase2Central) {  return At(JetPUPPI_mass,JetToUsePhase2Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Central_phi(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_phi, const ROOT::VecOps::RVec<int> & JetToUsePhase2Central) {  return At(JetPUPPI_phi,JetToUsePhase2Central); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Central_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetPUPPI_pt, const ROOT::VecOps::RVec<int> & JetToUsePhase2Central) {  return At(JetPUPPI_pt,JetToUsePhase2Central); }
int func__nJetToUsePhase2Central(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase2Central) {  return Sum(JetToUsePhase2Central); }
ROOT::VecOps::RVec<int> func__JetToUsePhase2Forward(unsigned int __slot , const ROOT::VecOps::RVec<float> & Jet_eta) {  return abs(Jet_eta)>4; }
ROOT::VecOps::RVec<unsigned int> func__JetToUsePhase2Forward_btag(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase2Forward, const ROOT::VecOps::RVec<unsigned int> & Jet_btag) {  return At(Jet_btag,JetToUsePhase2Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Forward_eta(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase2Forward, const ROOT::VecOps::RVec<float> & Jet_eta) {  return At(Jet_eta,JetToUsePhase2Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Forward_mass(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase2Forward, const ROOT::VecOps::RVec<float> & Jet_mass) {  return At(Jet_mass,JetToUsePhase2Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Forward_phi(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase2Forward, const ROOT::VecOps::RVec<float> & Jet_phi) {  return At(Jet_phi,JetToUsePhase2Forward); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2Forward_pt(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase2Forward, const ROOT::VecOps::RVec<float> & Jet_pt) {  return At(Jet_pt,JetToUsePhase2Forward); }
int func__nJetToUsePhase2Forward(unsigned int __slot , const ROOT::VecOps::RVec<int> & JetToUsePhase2Forward) {  return Sum(JetToUsePhase2Forward); }
int func__nJetToUsePhase2(unsigned int __slot , const int & nJetToUsePhase2Central, const int & nJetToUsePhase2Forward) {  return nJetToUsePhase2Central+nJetToUsePhase2Forward; }
ROOT::VecOps::RVec<unsigned int> func__JetToUsePhase2_btag(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & JetToUsePhase2Central_btag, const ROOT::VecOps::RVec<unsigned int> & JetToUsePhase2Forward_btag) {  return Concat(JetToUsePhase2Central_btag,JetToUsePhase2Forward_btag); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2_mass(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2Central_mass, const ROOT::VecOps::RVec<float> & JetToUsePhase2Forward_mass) {  return Concat(JetToUsePhase2Central_mass,JetToUsePhase2Forward_mass); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2Central_pt, const ROOT::VecOps::RVec<float> & JetToUsePhase2Forward_pt) {  return Concat(JetToUsePhase2Central_pt,JetToUsePhase2Forward_pt); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2_phi(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2Central_phi, const ROOT::VecOps::RVec<float> & JetToUsePhase2Forward_phi) {  return Concat(JetToUsePhase2Central_phi,JetToUsePhase2Forward_phi); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2Central_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase2Forward_eta) {  return Concat(JetToUsePhase2Central_eta,JetToUsePhase2Forward_eta); }
ROOT::VecOps::RVec<int> func__SelectedLeptonPhase2(unsigned int __slot , const ROOT::VecOps::RVec<float> & Lepton_pt) {  return Lepton_pt > 10; }
ROOT::VecOps::RVec<float> func__SelectedLeptonPhase2_phi(unsigned int __slot , const ROOT::VecOps::RVec<float> & Lepton_phi, const ROOT::VecOps::RVec<int> & SelectedLeptonPhase2) {  return At(Lepton_phi,SelectedLeptonPhase2); }
ROOT::VecOps::RVec<float> func__SelectedLeptonPhase2_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & Lepton_eta, const ROOT::VecOps::RVec<int> & SelectedLeptonPhase2) {  return At(Lepton_eta,SelectedLeptonPhase2); }
int func__nSelectedLeptonPhase2(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedLeptonPhase2) {  return Sum(SelectedLeptonPhase2); }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > func__JetToUsePhase2SelectedLeptonPhase2Pair(unsigned int __slot , const int & nJetToUsePhase2, const int & nSelectedLeptonPhase2) {  return Combinations(nJetToUsePhase2,nSelectedLeptonPhase2); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2SelectedLeptonPhase2Pair_dr(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > & JetToUsePhase2SelectedLeptonPhase2Pair, const ROOT::VecOps::RVec<float> & JetToUsePhase2_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase2_phi, const ROOT::VecOps::RVec<float> & SelectedLeptonPhase2_eta, const ROOT::VecOps::RVec<float> & SelectedLeptonPhase2_phi) {  return DeltaR(Take(JetToUsePhase2_eta,At(JetToUsePhase2SelectedLeptonPhase2Pair,0)),Take(SelectedLeptonPhase2_eta,At(JetToUsePhase2SelectedLeptonPhase2Pair,1)),Take(JetToUsePhase2_phi,At(JetToUsePhase2SelectedLeptonPhase2Pair,0)),Take(SelectedLeptonPhase2_phi,At(JetToUsePhase2SelectedLeptonPhase2Pair,1))  ); }
ROOT::VecOps::RVec<float> func__JetToUsePhase2_SelectedLeptonPhase2Dr(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2SelectedLeptonPhase2Pair_dr, const int & nJetToUsePhase2, const int & nSelectedLeptonPhase2) {  return matrix_map(nJetToUsePhase2,nSelectedLeptonPhase2,1,[](const ROOT::VecOps::RVec<float> & v) {return v.size()>0?(-Max(-v)):-99;},JetToUsePhase2SelectedLeptonPhase2Pair_dr); }
ROOT::VecOps::RVec<unsigned long> func__JetToUsePhase2_SelectedLeptonPhase2Idx(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2SelectedLeptonPhase2Pair_dr, const int & nJetToUsePhase2, const int & nSelectedLeptonPhase2) {  return matrix_map(nJetToUsePhase2,nSelectedLeptonPhase2,1,[](const ROOT::VecOps::RVec<float> & v) {return v.size()>0?Argmax(-v):-1;},JetToUsePhase2SelectedLeptonPhase2Pair_dr); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__JetToUsePhase2_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase2_mass, const ROOT::VecOps::RVec<float> & JetToUsePhase2_phi, const ROOT::VecOps::RVec<float> & JetToUsePhase2_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >        >(JetToUsePhase2_pt , JetToUsePhase2_eta, JetToUsePhase2_phi, JetToUsePhase2_mass); }
ROOT::VecOps::RVec<int> func__SelectedJetPhase2(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2_SelectedLeptonPhase2Dr, const ROOT::VecOps::RVec<unsigned long> & JetToUsePhase2_SelectedLeptonPhase2Idx, const ROOT::VecOps::RVec<float> & JetToUsePhase2_eta, const ROOT::VecOps::RVec<float> & JetToUsePhase2_pt, const int & jetPtCut) {  return 
    JetToUsePhase2_pt > jetPtCut && abs(JetToUsePhase2_eta) < 4.7 && (JetToUsePhase2_SelectedLeptonPhase2Idx==-1 || JetToUsePhase2_SelectedLeptonPhase2Dr > 0.4)
    ; }
ROOT::VecOps::RVec<unsigned int> func__SelectedJetPhase2_btag(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & JetToUsePhase2_btag, const ROOT::VecOps::RVec<int> & SelectedJetPhase2) {  return At(JetToUsePhase2_btag,SelectedJetPhase2); }
ROOT::VecOps::RVec<float> func__SelectedJetPhase2_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2_pt, const ROOT::VecOps::RVec<int> & SelectedJetPhase2) {  return At(JetToUsePhase2_pt,SelectedJetPhase2); }
ROOT::VecOps::RVec<float> func__SelectedJetPhase2_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & JetToUsePhase2_eta, const ROOT::VecOps::RVec<int> & SelectedJetPhase2) {  return At(JetToUsePhase2_eta,SelectedJetPhase2); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__SelectedJetPhase2_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & JetToUsePhase2_p4, const ROOT::VecOps::RVec<int> & SelectedJetPhase2) {  return At(JetToUsePhase2_p4,SelectedJetPhase2); }
int func__nSelectedJetPhase2(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedJetPhase2) {  return Sum(SelectedJetPhase2); }
bool func__twoJetsPhase2(unsigned int __slot , const int & nSelectedJetPhase2) {  return nSelectedJetPhase2>=2; }
ROOT::VecOps::RVec<unsigned long> func__SortedSelectedJetPhase2Indices(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase2_pt) {  return Argsort(-SelectedJetPhase2_pt); }
unsigned long func__QJetPhase2_0(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase2Indices) {  return At(SortedSelectedJetPhase2Indices,0); }
float func__QJetPhase2_0_pt(unsigned int __slot , const unsigned long & QJetPhase2_0, const ROOT::VecOps::RVec<float> & SelectedJetPhase2_pt) {  return At(SelectedJetPhase2_pt,QJetPhase2_0); }
float func__QJetPhase2_0_eta(unsigned int __slot , const unsigned long & QJetPhase2_0, const ROOT::VecOps::RVec<float> & SelectedJetPhase2_eta) {  return At(SelectedJetPhase2_eta,QJetPhase2_0); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJetPhase2_0_p4(unsigned int __slot , const unsigned long & QJetPhase2_0, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase2_p4) {  return At(SelectedJetPhase2_p4,QJetPhase2_0); }
unsigned long func__QJetPhase2_1(unsigned int __slot , const ROOT::VecOps::RVec<unsigned long> & SortedSelectedJetPhase2Indices) {  return At(SortedSelectedJetPhase2Indices,1); }
float func__QJetPhase2_1_pt(unsigned int __slot , const unsigned long & QJetPhase2_1, const ROOT::VecOps::RVec<float> & SelectedJetPhase2_pt) {  return At(SelectedJetPhase2_pt,QJetPhase2_1); }
float func__QJetPhase2_1_eta(unsigned int __slot , const unsigned long & QJetPhase2_1, const ROOT::VecOps::RVec<float> & SelectedJetPhase2_eta) {  return At(SelectedJetPhase2_eta,QJetPhase2_1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__QJetPhase2_1_p4(unsigned int __slot , const unsigned long & QJetPhase2_1, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase2_p4) {  return At(SelectedJetPhase2_p4,QJetPhase2_1); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__qqPhase2(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase2_0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase2_1_p4) {  return QJetPhase2_0_p4+QJetPhase2_1_p4; }
float func__MqqPhase2(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qqPhase2) {  return qqPhase2.M(); }
float func__qqPhase2_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & qqPhase2) {  return qqPhase2.Pt(); }
float func__qqDeltaEtaPhase2(unsigned int __slot , const float & QJetPhase2_0_eta, const float & QJetPhase2_1_eta) {  return abs(QJetPhase2_0_eta-QJetPhase2_1_eta); }
float func__qqDeltaPhiPhase2(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase2_0_p4, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & QJetPhase2_1_p4) {  return abs(ROOT::Math::VectorUtil::DeltaPhi(QJetPhase2_0_p4,QJetPhase2_1_p4)); }
int func__LeadMuonPhase2(unsigned int __slot ) {  return 0; }
float func__LeadMuonPhase2_eta(unsigned int __slot , const int & LeadMuonPhase2, const ROOT::VecOps::RVec<float> & SelectedMuonPhase2_eta) {  return At(SelectedMuonPhase2_eta,LeadMuonPhase2); }
float func__LeadMuonPhase2_pt(unsigned int __slot , const int & LeadMuonPhase2, const ROOT::VecOps::RVec<float> & SelectedMuonPhase2_pt) {  return At(SelectedMuonPhase2_pt,LeadMuonPhase2); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__LeadMuonPhase2_p4(unsigned int __slot , const int & LeadMuonPhase2, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase2_p4) {  return At(SelectedMuonPhase2_p4,LeadMuonPhase2); }
int func__SubMuonPhase2(unsigned int __slot ) {  return 1; }
int func__SubMuonPhase2_charge(unsigned int __slot , const ROOT::VecOps::RVec<int> & SelectedMuonPhase2_charge, const int & SubMuonPhase2) {  return At(SelectedMuonPhase2_charge,SubMuonPhase2); }
float func__SubMuonPhase2_eta(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuonPhase2_eta, const int & SubMuonPhase2) {  return At(SelectedMuonPhase2_eta,SubMuonPhase2); }
float func__SubMuonPhase2_pt(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedMuonPhase2_pt, const int & SubMuonPhase2) {  return At(SelectedMuonPhase2_pt,SubMuonPhase2); }
ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > func__SubMuonPhase2_p4(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedMuonPhase2_p4, const int & SubMuonPhase2) {  return At(SelectedMuonPhase2_p4,SubMuonPhase2); }
float func__Higgs_Phase2_pt(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs_Phase2) {  return Higgs_Phase2.Pt(); }
float func__pTbalanceAllPhase2(unsigned int __slot , const float & Higgs_Phase2_pt, const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & SelectedJetPhase2_p4) {  return SumDef(SelectedJetPhase2_p4).pt()/Higgs_Phase2_pt; }
float func__Higgs_Phase2_m(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & Higgs_Phase2) {  return Higgs_Phase2.M(); }
float func__CS_Phase2_theta(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuonPhase2_p4, const int & SubMuonPhase2_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuonPhase2_p4) {  return boost_to_CS(LeadMuonPhase2_p4, SubMuonPhase2_p4,  SubMuonPhase2_charge).first; }
float func__CS_Phase2_phi(unsigned int __slot , const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & LeadMuonPhase2_p4, const int & SubMuonPhase2_charge, const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > & SubMuonPhase2_p4) {  return boost_to_CS(LeadMuonPhase2_p4, SubMuonPhase2_p4, SubMuonPhase2_charge).second; }
ROOT::VecOps::RVec<unsigned int> func__SelectedJetPhase2btagDeepB(unsigned int __slot , const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase2_btag) {  return SelectedJetPhase2_btag; }
int func__nbtaggedPhase2(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase2_eta, const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase2btagDeepB, const double & btagCut) {  return int(Nonzero(SelectedJetPhase2btagDeepB > btagCut && abs(SelectedJetPhase2_eta)< 2.5).size()); }
int func__nbtaggedLPhase2(unsigned int __slot , const ROOT::VecOps::RVec<float> & SelectedJetPhase2_eta, const ROOT::VecOps::RVec<unsigned int> & SelectedJetPhase2btagDeepB, const double & btagCutL) {  return int(Nonzero(SelectedJetPhase2btagDeepB > btagCutL && abs(SelectedJetPhase2_eta)< 2.5).size()); }
int func__nelectronsPhase2(unsigned int __slot , const ROOT::VecOps::RVec<float> & Electron_eta, const ROOT::VecOps::RVec<float> & Electron_pt) {  return int(Nonzero(Electron_pt > 20 && abs(Electron_eta) < 2.5 ).size()); }
bool func__VBFRegionPhase2(unsigned int __slot , const float & MqqPhase2, const float & QJetPhase2_0_pt, const float & QJetPhase2_1_pt, const int & mQQcut) {  return MqqPhase2 > mQQcut && QJetPhase2_0_pt> 35 && QJetPhase2_1_pt > 25; }
bool func__PreSelPhase2(unsigned int __slot , const float & LeadMuonPhase2_pt, const float & SubMuonPhase2_pt, const bool & TriggerSel, const bool & VBFRegionPhase2, const int & nbtaggedLPhase2, const int & nbtaggedPhase2, const int & nelectronsPhase2, const bool & twoOppositeSignMuonsPhase2, const int & year) {  return nelectronsPhase2==0 && nbtaggedLPhase2 < 2 && VBFRegionPhase2 && twoOppositeSignMuonsPhase2 && nbtaggedPhase2 < 1 && (( year == 2016 && LeadMuonPhase2_pt > 26 ) || ( year == 2017 && LeadMuonPhase2_pt > 29 ) || ( (year == 2018||year==2026) && LeadMuonPhase2_pt > 26 )) && SubMuonPhase2_pt > 20 &&  TriggerSel; }
bool func__SignalRegionPhase2(unsigned int __slot , const bool & VBFRegionPhase2, const float & qqDeltaEtaPhase2) {  return VBFRegionPhase2 && qqDeltaEtaPhase2 > 2.5; }
double func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegionPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase2_twoOppositeSignMuonsPhase2Weight__Central(unsigned int __slot ) {  return 1.; }
double func__Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoJetsPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoJetsPhase2Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase1_twoOppositeSignMuonsPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase2Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase2_twoOppositeSignMuonsPhase2_twoJetsPhase2_VBFRegionPhase2_PreSelPhase2Weight__Central(unsigned int __slot ) {  return 1.; }
double func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegionPhase1_PreSelPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__SignalRegionPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__InclusiveRegionPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__VBFRegionPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__MassWindowZPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__PreSelPhase1Weight__Central(unsigned int __slot ) {  return 1.; }
double func__SignalRegionPhase2Weight__Central(unsigned int __slot ) {  return 1.; }

Result eventProcessor2026_nail(RNode rdf,int nThreads) {
     Result r;
     if(nThreads > 0)
     ROOT::EnableImplicitMT(nThreads);
	
	   auto rdf0 =rdf.DefineSlot("Muon_mass",func__Muon_mass,{"Muon_pt"});
auto rdf1 =rdf0.DefineSlot("Muon_p4",func__Muon_p4,{"Muon_eta","Muon_mass","Muon_phi","Muon_pt"});
auto rdf2 =rdf1.DefineSlot("SelectedMuonPhase1",func__SelectedMuonPhase1,{"Muon_eta","Muon_isolationvar"});
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
auto rdf23 =rdf22.DefineSlot("jetPtCut",func__jetPtCut,{});
auto rdf24 =rdf23.DefineSlot("JetToUsePhase1Central",func__JetToUsePhase1Central,{"JetPUPPI_eta"});
auto rdf25 =rdf24.DefineSlot("JetToUsePhase1Central_btag",func__JetToUsePhase1Central_btag,{"JetPUPPI_btag","JetToUsePhase1Central"});
auto rdf26 =rdf25.DefineSlot("JetToUsePhase1Central_eta",func__JetToUsePhase1Central_eta,{"JetPUPPI_eta","JetToUsePhase1Central"});
auto rdf27 =rdf26.DefineSlot("JetToUsePhase1Central_mass",func__JetToUsePhase1Central_mass,{"JetPUPPI_mass","JetToUsePhase1Central"});
auto rdf28 =rdf27.DefineSlot("JetToUsePhase1Central_phi",func__JetToUsePhase1Central_phi,{"JetPUPPI_phi","JetToUsePhase1Central"});
auto rdf29 =rdf28.DefineSlot("JetToUsePhase1Central_pt",func__JetToUsePhase1Central_pt,{"JetPUPPI_pt","JetToUsePhase1Central"});
auto rdf30 =rdf29.DefineSlot("nJetToUsePhase1Central",func__nJetToUsePhase1Central,{"JetToUsePhase1Central"});
auto rdf31 =rdf30.DefineSlot("JetToUsePhase1Forward",func__JetToUsePhase1Forward,{"Jet_eta"});
auto rdf32 =rdf31.DefineSlot("JetToUsePhase1Forward_btag",func__JetToUsePhase1Forward_btag,{"JetToUsePhase1Forward","Jet_btag"});
auto rdf33 =rdf32.DefineSlot("JetToUsePhase1Forward_eta",func__JetToUsePhase1Forward_eta,{"JetToUsePhase1Forward","Jet_eta"});
auto rdf34 =rdf33.DefineSlot("JetToUsePhase1Forward_mass",func__JetToUsePhase1Forward_mass,{"JetToUsePhase1Forward","Jet_mass"});
auto rdf35 =rdf34.DefineSlot("JetToUsePhase1Forward_phi",func__JetToUsePhase1Forward_phi,{"JetToUsePhase1Forward","Jet_phi"});
auto rdf36 =rdf35.DefineSlot("JetToUsePhase1Forward_pt",func__JetToUsePhase1Forward_pt,{"JetToUsePhase1Forward","Jet_pt"});
auto rdf37 =rdf36.DefineSlot("nJetToUsePhase1Forward",func__nJetToUsePhase1Forward,{"JetToUsePhase1Forward"});
auto rdf38 =rdf37.DefineSlot("nJetToUsePhase1",func__nJetToUsePhase1,{"nJetToUsePhase1Central","nJetToUsePhase1Forward"});
auto rdf39 =rdf38.DefineSlot("JetToUsePhase1_btag",func__JetToUsePhase1_btag,{"JetToUsePhase1Central_btag","JetToUsePhase1Forward_btag"});
auto rdf40 =rdf39.DefineSlot("JetToUsePhase1_mass",func__JetToUsePhase1_mass,{"JetToUsePhase1Central_mass","JetToUsePhase1Forward_mass"});
auto rdf41 =rdf40.DefineSlot("JetToUsePhase1_pt",func__JetToUsePhase1_pt,{"JetToUsePhase1Central_pt","JetToUsePhase1Forward_pt"});
auto rdf42 =rdf41.DefineSlot("JetToUsePhase1_phi",func__JetToUsePhase1_phi,{"JetToUsePhase1Central_phi","JetToUsePhase1Forward_phi"});
auto rdf43 =rdf42.DefineSlot("JetToUsePhase1_eta",func__JetToUsePhase1_eta,{"JetToUsePhase1Central_eta","JetToUsePhase1Forward_eta"});
auto rdf44 =rdf43.DefineSlot("Lepton_pt",func__Lepton_pt,{"Electron_pt","Muon_pt"});
auto rdf45 =rdf44.DefineSlot("Lepton_phi",func__Lepton_phi,{"Electron_phi","Muon_phi"});
auto rdf46 =rdf45.DefineSlot("Lepton_eta",func__Lepton_eta,{"Electron_eta","Muon_eta"});
auto rdf47 =rdf46.DefineSlot("SelectedLeptonPhase1",func__SelectedLeptonPhase1,{"Lepton_pt"});
auto rdf48 =rdf47.DefineSlot("SelectedLeptonPhase1_phi",func__SelectedLeptonPhase1_phi,{"Lepton_phi","SelectedLeptonPhase1"});
auto rdf49 =rdf48.DefineSlot("SelectedLeptonPhase1_eta",func__SelectedLeptonPhase1_eta,{"Lepton_eta","SelectedLeptonPhase1"});
auto rdf50 =rdf49.DefineSlot("nSelectedLeptonPhase1",func__nSelectedLeptonPhase1,{"SelectedLeptonPhase1"});
auto rdf51 =rdf50.DefineSlot("JetToUsePhase1SelectedLeptonPhase1Pair",func__JetToUsePhase1SelectedLeptonPhase1Pair,{"nJetToUsePhase1","nSelectedLeptonPhase1"});
auto rdf52 =rdf51.DefineSlot("JetToUsePhase1SelectedLeptonPhase1Pair_dr",func__JetToUsePhase1SelectedLeptonPhase1Pair_dr,{"JetToUsePhase1SelectedLeptonPhase1Pair","JetToUsePhase1_eta","JetToUsePhase1_phi","SelectedLeptonPhase1_eta","SelectedLeptonPhase1_phi"});
auto rdf53 =rdf52.DefineSlot("JetToUsePhase1_SelectedLeptonPhase1Dr",func__JetToUsePhase1_SelectedLeptonPhase1Dr,{"JetToUsePhase1SelectedLeptonPhase1Pair_dr","nJetToUsePhase1","nSelectedLeptonPhase1"});
auto rdf54 =rdf53.DefineSlot("JetToUsePhase1_SelectedLeptonPhase1Idx",func__JetToUsePhase1_SelectedLeptonPhase1Idx,{"JetToUsePhase1SelectedLeptonPhase1Pair_dr","nJetToUsePhase1","nSelectedLeptonPhase1"});
auto rdf55 =rdf54.DefineSlot("JetToUsePhase1_p4",func__JetToUsePhase1_p4,{"JetToUsePhase1_eta","JetToUsePhase1_mass","JetToUsePhase1_phi","JetToUsePhase1_pt"});
auto rdf56 =rdf55.DefineSlot("SelectedJetPhase1",func__SelectedJetPhase1,{"JetToUsePhase1_SelectedLeptonPhase1Dr","JetToUsePhase1_SelectedLeptonPhase1Idx","JetToUsePhase1_eta","JetToUsePhase1_pt","jetPtCut"});
auto rdf57 =rdf56.DefineSlot("SelectedJetPhase1_btag",func__SelectedJetPhase1_btag,{"JetToUsePhase1_btag","SelectedJetPhase1"});
auto rdf58 =rdf57.DefineSlot("SelectedJetPhase1_pt",func__SelectedJetPhase1_pt,{"JetToUsePhase1_pt","SelectedJetPhase1"});
auto rdf59 =rdf58.DefineSlot("SelectedJetPhase1_eta",func__SelectedJetPhase1_eta,{"JetToUsePhase1_eta","SelectedJetPhase1"});
auto rdf60 =rdf59.DefineSlot("SelectedJetPhase1_p4",func__SelectedJetPhase1_p4,{"JetToUsePhase1_p4","SelectedJetPhase1"});
auto rdf61 =rdf60.DefineSlot("nSelectedJetPhase1",func__nSelectedJetPhase1,{"SelectedJetPhase1"});
auto rdf62 =rdf61.DefineSlot("twoJetsPhase1",func__twoJetsPhase1,{"nSelectedJetPhase1"});
auto rdf63 =rdf62.DefineSlot("SortedSelectedJetPhase1Indices",func__SortedSelectedJetPhase1Indices,{"SelectedJetPhase1_pt"});
auto rdf64 =rdf63.DefineSlot("QJetPhase1_0",func__QJetPhase1_0,{"SortedSelectedJetPhase1Indices"});
auto rdf65 =rdf64.DefineSlot("QJetPhase1_0_pt",func__QJetPhase1_0_pt,{"QJetPhase1_0","SelectedJetPhase1_pt"});
auto rdf66 =rdf65.DefineSlot("QJetPhase1_0_eta",func__QJetPhase1_0_eta,{"QJetPhase1_0","SelectedJetPhase1_eta"});
auto rdf67 =rdf66.DefineSlot("QJetPhase1_0_p4",func__QJetPhase1_0_p4,{"QJetPhase1_0","SelectedJetPhase1_p4"});
auto rdf68 =rdf67.DefineSlot("QJetPhase1_1",func__QJetPhase1_1,{"SortedSelectedJetPhase1Indices"});
auto rdf69 =rdf68.DefineSlot("QJetPhase1_1_pt",func__QJetPhase1_1_pt,{"QJetPhase1_1","SelectedJetPhase1_pt"});
auto rdf70 =rdf69.DefineSlot("QJetPhase1_1_eta",func__QJetPhase1_1_eta,{"QJetPhase1_1","SelectedJetPhase1_eta"});
auto rdf71 =rdf70.DefineSlot("QJetPhase1_1_p4",func__QJetPhase1_1_p4,{"QJetPhase1_1","SelectedJetPhase1_p4"});
auto rdf72 =rdf71.DefineSlot("qqPhase1",func__qqPhase1,{"QJetPhase1_0_p4","QJetPhase1_1_p4"});
auto rdf73 =rdf72.DefineSlot("MqqPhase1",func__MqqPhase1,{"qqPhase1"});
auto rdf74 =rdf73.DefineSlot("qqPhase1_pt",func__qqPhase1_pt,{"qqPhase1"});
auto rdf75 =rdf74.DefineSlot("qqDeltaEtaPhase1",func__qqDeltaEtaPhase1,{"QJetPhase1_0_eta","QJetPhase1_1_eta"});
auto rdf76 =rdf75.DefineSlot("qqDeltaPhiPhase1",func__qqDeltaPhiPhase1,{"QJetPhase1_0_p4","QJetPhase1_1_p4"});
auto rdf77 =rdf76.DefineSlot("LeadMuonPhase1",func__LeadMuonPhase1,{});
auto rdf78 =rdf77.DefineSlot("LeadMuonPhase1_eta",func__LeadMuonPhase1_eta,{"LeadMuonPhase1","SelectedMuonPhase1_eta"});
auto rdf79 =rdf78.DefineSlot("LeadMuonPhase1_pt",func__LeadMuonPhase1_pt,{"LeadMuonPhase1","SelectedMuonPhase1_pt"});
auto rdf80 =rdf79.DefineSlot("LeadMuonPhase1_p4",func__LeadMuonPhase1_p4,{"LeadMuonPhase1","SelectedMuonPhase1_p4"});
auto rdf81 =rdf80.DefineSlot("SubMuonPhase1",func__SubMuonPhase1,{});
auto rdf82 =rdf81.DefineSlot("SubMuonPhase1_charge",func__SubMuonPhase1_charge,{"SelectedMuonPhase1_charge","SubMuonPhase1"});
auto rdf83 =rdf82.DefineSlot("SubMuonPhase1_eta",func__SubMuonPhase1_eta,{"SelectedMuonPhase1_eta","SubMuonPhase1"});
auto rdf84 =rdf83.DefineSlot("SubMuonPhase1_pt",func__SubMuonPhase1_pt,{"SelectedMuonPhase1_pt","SubMuonPhase1"});
auto rdf85 =rdf84.DefineSlot("SubMuonPhase1_p4",func__SubMuonPhase1_p4,{"SelectedMuonPhase1_p4","SubMuonPhase1"});
auto rdf86 =rdf85.DefineSlot("Higgs_Phase1_pt",func__Higgs_Phase1_pt,{"Higgs_Phase1"});
auto rdf87 =rdf86.DefineSlot("pTbalanceAllPhase1",func__pTbalanceAllPhase1,{"Higgs_Phase1_pt","SelectedJetPhase1_p4"});
auto rdf88 =rdf87.DefineSlot("Higgs_Phase1_m",func__Higgs_Phase1_m,{"Higgs_Phase1"});
auto rdf89 =rdf88.DefineSlot("CS_Phase1_theta",func__CS_Phase1_theta,{"LeadMuonPhase1_p4","SubMuonPhase1_charge","SubMuonPhase1_p4"});
auto rdf90 =rdf89.DefineSlot("CS_Phase1_phi",func__CS_Phase1_phi,{"LeadMuonPhase1_p4","SubMuonPhase1_charge","SubMuonPhase1_p4"});
auto rdf91 =rdf90.DefineSlot("mQQcut",func__mQQcut,{});
auto rdf92 =rdf91.DefineSlot("SelectedJetPhase1btagDeepB",func__SelectedJetPhase1btagDeepB,{"SelectedJetPhase1_btag"});
auto rdf93 =rdf92.DefineSlot("btagCut",func__btagCut,{});
auto rdf94 =rdf93.DefineSlot("btagCutL",func__btagCutL,{});
auto rdf95 =rdf94.DefineSlot("nbtaggedPhase1",func__nbtaggedPhase1,{"SelectedJetPhase1_eta","SelectedJetPhase1btagDeepB","btagCut"});
auto rdf96 =rdf95.DefineSlot("nbtaggedLPhase1",func__nbtaggedLPhase1,{"SelectedJetPhase1_eta","SelectedJetPhase1btagDeepB","btagCutL"});
auto rdf97 =rdf96.DefineSlot("nelectronsPhase1",func__nelectronsPhase1,{"Electron_eta","Electron_pt"});
auto rdf98 =rdf97.DefineSlot("MassWindowZPhase1",func__MassWindowZPhase1,{"Higgs_Phase1"});
auto rdf99 =rdf98.DefineSlot("VBFRegionPhase1",func__VBFRegionPhase1,{"MqqPhase1","QJetPhase1_0_pt","QJetPhase1_1_pt","mQQcut"});
auto rdf100 =rdf99.DefineSlot("PreSelPhase1",func__PreSelPhase1,{"LeadMuonPhase1_eta","LeadMuonPhase1_pt","SubMuonPhase1_eta","SubMuonPhase1_pt","TriggerSel","VBFRegionPhase1","nbtaggedLPhase1","nbtaggedPhase1","nelectronsPhase1","twoOppositeSignMuonsPhase1","year"});
auto rdf101 =rdf100.DefineSlot("SignalRegionPhase1",func__SignalRegionPhase1,{"VBFRegionPhase1","qqDeltaEtaPhase1"});
auto rdf102 =rdf101.DefineSlot("InclusiveRegionPhase1",func__InclusiveRegionPhase1,{});
auto rdf103 =rdf102.DefineSlot("SelectedMuonPhase2",func__SelectedMuonPhase2,{"Muon_eta","Muon_isolationvar"});
auto rdf104 =rdf103.DefineSlot("SelectedMuonPhase2_charge",func__SelectedMuonPhase2_charge,{"Muon_charge","SelectedMuonPhase2"});
auto rdf105 =rdf104.DefineSlot("SelectedMuonPhase2_eta",func__SelectedMuonPhase2_eta,{"Muon_eta","SelectedMuonPhase2"});
auto rdf106 =rdf105.DefineSlot("SelectedMuonPhase2_pt",func__SelectedMuonPhase2_pt,{"Muon_pt","SelectedMuonPhase2"});
auto rdf107 =rdf106.DefineSlot("SelectedMuonPhase2_p4",func__SelectedMuonPhase2_p4,{"Muon_p4","SelectedMuonPhase2"});
auto rdf108 =rdf107.DefineSlot("nSelectedMuonPhase2",func__nSelectedMuonPhase2,{"SelectedMuonPhase2"});
auto rdf109 =rdf108.DefineSlot("twoMuonsPhase2",func__twoMuonsPhase2,{"nSelectedMuonPhase2"});
auto rdf110 =rdf109.DefineSlot("MuMuPhase2_allpairs",func__MuMuPhase2_allpairs,{"SelectedMuonPhase2"});
auto rdf111 =rdf110.DefineSlot("MuMuPhase2",func__MuMuPhase2,{"MuMuPhase2_allpairs"});
auto rdf112 =rdf111.DefineSlot("MuMuPhase20",func__MuMuPhase20,{"MuMuPhase2","MuMuPhase2_allpairs"});
auto rdf113 =rdf112.DefineSlot("MuMuPhase21",func__MuMuPhase21,{"MuMuPhase2","MuMuPhase2_allpairs"});
auto rdf114 =rdf113.DefineSlot("MuMuPhase20_charge",func__MuMuPhase20_charge,{"MuMuPhase20","SelectedMuonPhase2_charge"});
auto rdf115 =rdf114.DefineSlot("MuMuPhase21_charge",func__MuMuPhase21_charge,{"MuMuPhase21","SelectedMuonPhase2_charge"});
auto rdf116 =rdf115.DefineSlot("OppositeSignMuMuPhase2",func__OppositeSignMuMuPhase2,{"MuMuPhase20_charge","MuMuPhase21_charge"});
auto rdf117 =rdf116.DefineSlot("twoOppositeSignMuonsPhase2",func__twoOppositeSignMuonsPhase2,{"OppositeSignMuMuPhase2"});
auto rdf118 =rdf117.DefineSlot("MuPhase2_index",func__MuPhase2_index,{"OppositeSignMuMuPhase2"});
auto rdf119 =rdf118.DefineSlot("MuPhase20",func__MuPhase20,{"MuMuPhase20","MuPhase2_index"});
auto rdf120 =rdf119.DefineSlot("MuPhase20_p4",func__MuPhase20_p4,{"MuPhase20","SelectedMuonPhase2_p4"});
auto rdf121 =rdf120.DefineSlot("MuPhase21",func__MuPhase21,{"MuMuPhase21","MuPhase2_index"});
auto rdf122 =rdf121.DefineSlot("MuPhase21_p4",func__MuPhase21_p4,{"MuPhase21","SelectedMuonPhase2_p4"});
auto rdf123 =rdf122.DefineSlot("Higgs_Phase2",func__Higgs_Phase2,{"MuPhase20_p4","MuPhase21_p4"});
auto rdf124 =rdf123.DefineSlot("JetToUsePhase2Central",func__JetToUsePhase2Central,{"JetPUPPI_eta"});
auto rdf125 =rdf124.DefineSlot("JetToUsePhase2Central_btag",func__JetToUsePhase2Central_btag,{"JetPUPPI_btag","JetToUsePhase2Central"});
auto rdf126 =rdf125.DefineSlot("JetToUsePhase2Central_eta",func__JetToUsePhase2Central_eta,{"JetPUPPI_eta","JetToUsePhase2Central"});
auto rdf127 =rdf126.DefineSlot("JetToUsePhase2Central_mass",func__JetToUsePhase2Central_mass,{"JetPUPPI_mass","JetToUsePhase2Central"});
auto rdf128 =rdf127.DefineSlot("JetToUsePhase2Central_phi",func__JetToUsePhase2Central_phi,{"JetPUPPI_phi","JetToUsePhase2Central"});
auto rdf129 =rdf128.DefineSlot("JetToUsePhase2Central_pt",func__JetToUsePhase2Central_pt,{"JetPUPPI_pt","JetToUsePhase2Central"});
auto rdf130 =rdf129.DefineSlot("nJetToUsePhase2Central",func__nJetToUsePhase2Central,{"JetToUsePhase2Central"});
auto rdf131 =rdf130.DefineSlot("JetToUsePhase2Forward",func__JetToUsePhase2Forward,{"Jet_eta"});
auto rdf132 =rdf131.DefineSlot("JetToUsePhase2Forward_btag",func__JetToUsePhase2Forward_btag,{"JetToUsePhase2Forward","Jet_btag"});
auto rdf133 =rdf132.DefineSlot("JetToUsePhase2Forward_eta",func__JetToUsePhase2Forward_eta,{"JetToUsePhase2Forward","Jet_eta"});
auto rdf134 =rdf133.DefineSlot("JetToUsePhase2Forward_mass",func__JetToUsePhase2Forward_mass,{"JetToUsePhase2Forward","Jet_mass"});
auto rdf135 =rdf134.DefineSlot("JetToUsePhase2Forward_phi",func__JetToUsePhase2Forward_phi,{"JetToUsePhase2Forward","Jet_phi"});
auto rdf136 =rdf135.DefineSlot("JetToUsePhase2Forward_pt",func__JetToUsePhase2Forward_pt,{"JetToUsePhase2Forward","Jet_pt"});
auto rdf137 =rdf136.DefineSlot("nJetToUsePhase2Forward",func__nJetToUsePhase2Forward,{"JetToUsePhase2Forward"});
auto rdf138 =rdf137.DefineSlot("nJetToUsePhase2",func__nJetToUsePhase2,{"nJetToUsePhase2Central","nJetToUsePhase2Forward"});
auto rdf139 =rdf138.DefineSlot("JetToUsePhase2_btag",func__JetToUsePhase2_btag,{"JetToUsePhase2Central_btag","JetToUsePhase2Forward_btag"});
auto rdf140 =rdf139.DefineSlot("JetToUsePhase2_mass",func__JetToUsePhase2_mass,{"JetToUsePhase2Central_mass","JetToUsePhase2Forward_mass"});
auto rdf141 =rdf140.DefineSlot("JetToUsePhase2_pt",func__JetToUsePhase2_pt,{"JetToUsePhase2Central_pt","JetToUsePhase2Forward_pt"});
auto rdf142 =rdf141.DefineSlot("JetToUsePhase2_phi",func__JetToUsePhase2_phi,{"JetToUsePhase2Central_phi","JetToUsePhase2Forward_phi"});
auto rdf143 =rdf142.DefineSlot("JetToUsePhase2_eta",func__JetToUsePhase2_eta,{"JetToUsePhase2Central_eta","JetToUsePhase2Forward_eta"});
auto rdf144 =rdf143.DefineSlot("SelectedLeptonPhase2",func__SelectedLeptonPhase2,{"Lepton_pt"});
auto rdf145 =rdf144.DefineSlot("SelectedLeptonPhase2_phi",func__SelectedLeptonPhase2_phi,{"Lepton_phi","SelectedLeptonPhase2"});
auto rdf146 =rdf145.DefineSlot("SelectedLeptonPhase2_eta",func__SelectedLeptonPhase2_eta,{"Lepton_eta","SelectedLeptonPhase2"});
auto rdf147 =rdf146.DefineSlot("nSelectedLeptonPhase2",func__nSelectedLeptonPhase2,{"SelectedLeptonPhase2"});
auto rdf148 =rdf147.DefineSlot("JetToUsePhase2SelectedLeptonPhase2Pair",func__JetToUsePhase2SelectedLeptonPhase2Pair,{"nJetToUsePhase2","nSelectedLeptonPhase2"});
auto rdf149 =rdf148.DefineSlot("JetToUsePhase2SelectedLeptonPhase2Pair_dr",func__JetToUsePhase2SelectedLeptonPhase2Pair_dr,{"JetToUsePhase2SelectedLeptonPhase2Pair","JetToUsePhase2_eta","JetToUsePhase2_phi","SelectedLeptonPhase2_eta","SelectedLeptonPhase2_phi"});
auto rdf150 =rdf149.DefineSlot("JetToUsePhase2_SelectedLeptonPhase2Dr",func__JetToUsePhase2_SelectedLeptonPhase2Dr,{"JetToUsePhase2SelectedLeptonPhase2Pair_dr","nJetToUsePhase2","nSelectedLeptonPhase2"});
auto rdf151 =rdf150.DefineSlot("JetToUsePhase2_SelectedLeptonPhase2Idx",func__JetToUsePhase2_SelectedLeptonPhase2Idx,{"JetToUsePhase2SelectedLeptonPhase2Pair_dr","nJetToUsePhase2","nSelectedLeptonPhase2"});
auto rdf152 =rdf151.DefineSlot("JetToUsePhase2_p4",func__JetToUsePhase2_p4,{"JetToUsePhase2_eta","JetToUsePhase2_mass","JetToUsePhase2_phi","JetToUsePhase2_pt"});
auto rdf153 =rdf152.DefineSlot("SelectedJetPhase2",func__SelectedJetPhase2,{"JetToUsePhase2_SelectedLeptonPhase2Dr","JetToUsePhase2_SelectedLeptonPhase2Idx","JetToUsePhase2_eta","JetToUsePhase2_pt","jetPtCut"});
auto rdf154 =rdf153.DefineSlot("SelectedJetPhase2_btag",func__SelectedJetPhase2_btag,{"JetToUsePhase2_btag","SelectedJetPhase2"});
auto rdf155 =rdf154.DefineSlot("SelectedJetPhase2_pt",func__SelectedJetPhase2_pt,{"JetToUsePhase2_pt","SelectedJetPhase2"});
auto rdf156 =rdf155.DefineSlot("SelectedJetPhase2_eta",func__SelectedJetPhase2_eta,{"JetToUsePhase2_eta","SelectedJetPhase2"});
auto rdf157 =rdf156.DefineSlot("SelectedJetPhase2_p4",func__SelectedJetPhase2_p4,{"JetToUsePhase2_p4","SelectedJetPhase2"});
auto rdf158 =rdf157.DefineSlot("nSelectedJetPhase2",func__nSelectedJetPhase2,{"SelectedJetPhase2"});
auto rdf159 =rdf158.DefineSlot("twoJetsPhase2",func__twoJetsPhase2,{"nSelectedJetPhase2"});
auto rdf160 =rdf159.DefineSlot("SortedSelectedJetPhase2Indices",func__SortedSelectedJetPhase2Indices,{"SelectedJetPhase2_pt"});
auto rdf161 =rdf160.DefineSlot("QJetPhase2_0",func__QJetPhase2_0,{"SortedSelectedJetPhase2Indices"});
auto rdf162 =rdf161.DefineSlot("QJetPhase2_0_pt",func__QJetPhase2_0_pt,{"QJetPhase2_0","SelectedJetPhase2_pt"});
auto rdf163 =rdf162.DefineSlot("QJetPhase2_0_eta",func__QJetPhase2_0_eta,{"QJetPhase2_0","SelectedJetPhase2_eta"});
auto rdf164 =rdf163.DefineSlot("QJetPhase2_0_p4",func__QJetPhase2_0_p4,{"QJetPhase2_0","SelectedJetPhase2_p4"});
auto rdf165 =rdf164.DefineSlot("QJetPhase2_1",func__QJetPhase2_1,{"SortedSelectedJetPhase2Indices"});
auto rdf166 =rdf165.DefineSlot("QJetPhase2_1_pt",func__QJetPhase2_1_pt,{"QJetPhase2_1","SelectedJetPhase2_pt"});
auto rdf167 =rdf166.DefineSlot("QJetPhase2_1_eta",func__QJetPhase2_1_eta,{"QJetPhase2_1","SelectedJetPhase2_eta"});
auto rdf168 =rdf167.DefineSlot("QJetPhase2_1_p4",func__QJetPhase2_1_p4,{"QJetPhase2_1","SelectedJetPhase2_p4"});
auto rdf169 =rdf168.DefineSlot("qqPhase2",func__qqPhase2,{"QJetPhase2_0_p4","QJetPhase2_1_p4"});
auto rdf170 =rdf169.DefineSlot("MqqPhase2",func__MqqPhase2,{"qqPhase2"});
auto rdf171 =rdf170.DefineSlot("qqPhase2_pt",func__qqPhase2_pt,{"qqPhase2"});
auto rdf172 =rdf171.DefineSlot("qqDeltaEtaPhase2",func__qqDeltaEtaPhase2,{"QJetPhase2_0_eta","QJetPhase2_1_eta"});
auto rdf173 =rdf172.DefineSlot("qqDeltaPhiPhase2",func__qqDeltaPhiPhase2,{"QJetPhase2_0_p4","QJetPhase2_1_p4"});
auto rdf174 =rdf173.DefineSlot("LeadMuonPhase2",func__LeadMuonPhase2,{});
auto rdf175 =rdf174.DefineSlot("LeadMuonPhase2_eta",func__LeadMuonPhase2_eta,{"LeadMuonPhase2","SelectedMuonPhase2_eta"});
auto rdf176 =rdf175.DefineSlot("LeadMuonPhase2_pt",func__LeadMuonPhase2_pt,{"LeadMuonPhase2","SelectedMuonPhase2_pt"});
auto rdf177 =rdf176.DefineSlot("LeadMuonPhase2_p4",func__LeadMuonPhase2_p4,{"LeadMuonPhase2","SelectedMuonPhase2_p4"});
auto rdf178 =rdf177.DefineSlot("SubMuonPhase2",func__SubMuonPhase2,{});
auto rdf179 =rdf178.DefineSlot("SubMuonPhase2_charge",func__SubMuonPhase2_charge,{"SelectedMuonPhase2_charge","SubMuonPhase2"});
auto rdf180 =rdf179.DefineSlot("SubMuonPhase2_eta",func__SubMuonPhase2_eta,{"SelectedMuonPhase2_eta","SubMuonPhase2"});
auto rdf181 =rdf180.DefineSlot("SubMuonPhase2_pt",func__SubMuonPhase2_pt,{"SelectedMuonPhase2_pt","SubMuonPhase2"});
auto rdf182 =rdf181.DefineSlot("SubMuonPhase2_p4",func__SubMuonPhase2_p4,{"SelectedMuonPhase2_p4","SubMuonPhase2"});
auto rdf183 =rdf182.DefineSlot("Higgs_Phase2_pt",func__Higgs_Phase2_pt,{"Higgs_Phase2"});
auto rdf184 =rdf183.DefineSlot("pTbalanceAllPhase2",func__pTbalanceAllPhase2,{"Higgs_Phase2_pt","SelectedJetPhase2_p4"});
auto rdf185 =rdf184.DefineSlot("Higgs_Phase2_m",func__Higgs_Phase2_m,{"Higgs_Phase2"});
auto rdf186 =rdf185.DefineSlot("CS_Phase2_theta",func__CS_Phase2_theta,{"LeadMuonPhase2_p4","SubMuonPhase2_charge","SubMuonPhase2_p4"});
auto rdf187 =rdf186.DefineSlot("CS_Phase2_phi",func__CS_Phase2_phi,{"LeadMuonPhase2_p4","SubMuonPhase2_charge","SubMuonPhase2_p4"});
auto rdf188 =rdf187.DefineSlot("SelectedJetPhase2btagDeepB",func__SelectedJetPhase2btagDeepB,{"SelectedJetPhase2_btag"});
auto rdf189 =rdf188.DefineSlot("nbtaggedPhase2",func__nbtaggedPhase2,{"SelectedJetPhase2_eta","SelectedJetPhase2btagDeepB","btagCut"});
auto rdf190 =rdf189.DefineSlot("nbtaggedLPhase2",func__nbtaggedLPhase2,{"SelectedJetPhase2_eta","SelectedJetPhase2btagDeepB","btagCutL"});
auto rdf191 =rdf190.DefineSlot("nelectronsPhase2",func__nelectronsPhase2,{"Electron_eta","Electron_pt"});
auto rdf192 =rdf191.DefineSlot("VBFRegionPhase2",func__VBFRegionPhase2,{"MqqPhase2","QJetPhase2_0_pt","QJetPhase2_1_pt","mQQcut"});
auto rdf193 =rdf192.DefineSlot("PreSelPhase2",func__PreSelPhase2,{"LeadMuonPhase2_pt","SubMuonPhase2_pt","TriggerSel","VBFRegionPhase2","nbtaggedLPhase2","nbtaggedPhase2","nelectronsPhase2","twoOppositeSignMuonsPhase2","year"});
auto rdf194 =rdf193.DefineSlot("SignalRegionPhase2",func__SignalRegionPhase2,{"VBFRegionPhase2","qqDeltaEtaPhase2"});
auto rdf195 =rdf194.DefineSlot("twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegionPhase1Weight__Central",func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegionPhase1Weight__Central,{});
auto rdf196 =rdf195.DefineSlot("twoMuonsPhase2_twoOppositeSignMuonsPhase2Weight__Central",func__twoMuonsPhase2_twoOppositeSignMuonsPhase2Weight__Central,{});
auto rdf197 =rdf196.DefineSlot("Weight__Central",func__Weight__Central,{});
auto rdf198 =rdf197.DefineSlot("twoJetsPhase1Weight__Central",func__twoJetsPhase1Weight__Central,{});
auto rdf199 =rdf198.DefineSlot("twoJetsPhase2Weight__Central",func__twoJetsPhase2Weight__Central,{});
auto rdf200 =rdf199.DefineSlot("twoMuonsPhase1Weight__Central",func__twoMuonsPhase1Weight__Central,{});
auto rdf201 =rdf200.DefineSlot("twoMuonsPhase1_twoOppositeSignMuonsPhase1Weight__Central",func__twoMuonsPhase1_twoOppositeSignMuonsPhase1Weight__Central,{});
auto rdf202 =rdf201.DefineSlot("twoMuonsPhase2Weight__Central",func__twoMuonsPhase2Weight__Central,{});
auto rdf203 =rdf202.DefineSlot("twoMuonsPhase2_twoOppositeSignMuonsPhase2_twoJetsPhase2_VBFRegionPhase2_PreSelPhase2Weight__Central",func__twoMuonsPhase2_twoOppositeSignMuonsPhase2_twoJetsPhase2_VBFRegionPhase2_PreSelPhase2Weight__Central,{});
auto rdf204 =rdf203.DefineSlot("twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegionPhase1_PreSelPhase1Weight__Central",func__twoMuonsPhase1_twoOppositeSignMuonsPhase1_twoJetsPhase1_VBFRegionPhase1_PreSelPhase1Weight__Central,{});
auto rdf205 =rdf204.DefineSlot("SignalRegionPhase1Weight__Central",func__SignalRegionPhase1Weight__Central,{});
auto rdf206 =rdf205.DefineSlot("InclusiveRegionPhase1Weight__Central",func__InclusiveRegionPhase1Weight__Central,{});
auto rdf207 =rdf206.DefineSlot("VBFRegionPhase1Weight__Central",func__VBFRegionPhase1Weight__Central,{});
auto rdf208 =rdf207.DefineSlot("MassWindowZPhase1Weight__Central",func__MassWindowZPhase1Weight__Central,{});
auto rdf209 =rdf208.DefineSlot("PreSelPhase1Weight__Central",func__PreSelPhase1Weight__Central,{});
auto rdf210 =rdf209.DefineSlot("SignalRegionPhase2Weight__Central",func__SignalRegionPhase2Weight__Central,{});
auto toplevel=rdf210;
std::vector<ROOT::RDF::RResultPtr<TH1D>> histos;
{}auto selection_SignalRegionPhase1=rdf210.Filter("twoMuonsPhase1","twoMuonsPhase1").Filter("twoOppositeSignMuonsPhase1","twoOppositeSignMuonsPhase1").Filter("twoJetsPhase1","twoJetsPhase1").Filter("VBFRegionPhase1","VBFRegionPhase1").Filter("PreSelPhase1","PreSelPhase1").Filter("SignalRegionPhase1","SignalRegionPhase1");
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
}auto selection_InclusiveRegionPhase1=rdf210.Filter("InclusiveRegionPhase1","InclusiveRegionPhase1");
r.rdf.emplace("InclusiveRegionPhase1",selection_InclusiveRegionPhase1);
{histos.emplace_back(selection_InclusiveRegionPhase1.Histo1D({"MET_met___InclusiveRegionPhase1", "MET_met {InclusiveRegionPhase1}", 1000,0,1000},"MET_met","InclusiveRegionPhase1Weight__Central"));
}auto selection_VBFRegionPhase1=rdf210.Filter("twoJetsPhase1","twoJetsPhase1").Filter("VBFRegionPhase1","VBFRegionPhase1");
r.rdf.emplace("VBFRegionPhase1",selection_VBFRegionPhase1);
{histos.emplace_back(selection_VBFRegionPhase1.Histo1D({"MET_met___VBFRegionPhase1", "MET_met {VBFRegionPhase1}", 1000,0,1000},"MET_met","VBFRegionPhase1Weight__Central"));
}auto selection_MassWindowZPhase1=rdf210.Filter("twoMuonsPhase1","twoMuonsPhase1").Filter("twoOppositeSignMuonsPhase1","twoOppositeSignMuonsPhase1").Filter("MassWindowZPhase1","MassWindowZPhase1");
r.rdf.emplace("MassWindowZPhase1",selection_MassWindowZPhase1);
{histos.emplace_back(selection_MassWindowZPhase1.Histo1D({"MET_met___MassWindowZPhase1", "MET_met {MassWindowZPhase1}", 1000,0,1000},"MET_met","MassWindowZPhase1Weight__Central"));
}auto selection_PreSelPhase1=rdf210.Filter("twoMuonsPhase1","twoMuonsPhase1").Filter("twoOppositeSignMuonsPhase1","twoOppositeSignMuonsPhase1").Filter("twoJetsPhase1","twoJetsPhase1").Filter("VBFRegionPhase1","VBFRegionPhase1").Filter("PreSelPhase1","PreSelPhase1");
r.rdf.emplace("PreSelPhase1",selection_PreSelPhase1);
{histos.emplace_back(selection_PreSelPhase1.Histo1D({"MET_met___PreSelPhase1", "MET_met {PreSelPhase1}", 1000,0,1000},"MET_met","PreSelPhase1Weight__Central"));
}auto selection_SignalRegionPhase2=rdf210.Filter("twoMuonsPhase2","twoMuonsPhase2").Filter("twoOppositeSignMuonsPhase2","twoOppositeSignMuonsPhase2").Filter("twoJetsPhase2","twoJetsPhase2").Filter("VBFRegionPhase2","VBFRegionPhase2").Filter("PreSelPhase2","PreSelPhase2").Filter("SignalRegionPhase2","SignalRegionPhase2");
r.rdf.emplace("SignalRegionPhase2",selection_SignalRegionPhase2);
{histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"Higgs_Phase2_m___SignalRegionPhase2", "Higgs_Phase2_m {SignalRegionPhase2}", 30 , 0,500},"Higgs_Phase2_m","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"pTbalanceAllPhase2___SignalRegionPhase2", "pTbalanceAllPhase2 {SignalRegionPhase2}", 30 , 0 , 4},"pTbalanceAllPhase2","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"LeadMuonPhase2_pt___SignalRegionPhase2", "LeadMuonPhase2_pt {SignalRegionPhase2}", 30 , 0 , 300},"LeadMuonPhase2_pt","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"LeadMuonPhase2_eta___SignalRegionPhase2", "LeadMuonPhase2_eta {SignalRegionPhase2}", 30 , -5 , 5},"LeadMuonPhase2_eta","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"SubMuonPhase2_pt___SignalRegionPhase2", "SubMuonPhase2_pt {SignalRegionPhase2}", 30 , 0 , 300},"SubMuonPhase2_pt","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"SubMuonPhase2_eta___SignalRegionPhase2", "SubMuonPhase2_eta {SignalRegionPhase2}", 30 , -5 , 5},"SubMuonPhase2_eta","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"QJetPhase2_0_eta___SignalRegionPhase2", "QJetPhase2_0_eta {SignalRegionPhase2}", 30 , -5 , 5},"QJetPhase2_0_eta","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"QJetPhase2_1_eta___SignalRegionPhase2", "QJetPhase2_1_eta {SignalRegionPhase2}", 30 , -5 , 5},"QJetPhase2_1_eta","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"QJetPhase2_0_pt___SignalRegionPhase2", "QJetPhase2_0_pt {SignalRegionPhase2}", 30 , 0 , 300},"QJetPhase2_0_pt","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"QJetPhase2_1_pt___SignalRegionPhase2", "QJetPhase2_1_pt {SignalRegionPhase2}", 30 , 0 , 300},"QJetPhase2_1_pt","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"CS_Phase2_theta___SignalRegionPhase2", "CS_Phase2_theta {SignalRegionPhase2}", 30 , -3.2 , 3.2},"CS_Phase2_theta","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"CS_Phase2_phi___SignalRegionPhase2", "CS_Phase2_phi {SignalRegionPhase2}", 30 , -3.2 , 3.2},"CS_Phase2_phi","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"MET_met___SignalRegionPhase2", "MET_met {SignalRegionPhase2}", 1000,0,1000},"MET_met","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"QJetPhase2_0_pt___SignalRegionPhase2", "QJetPhase2_0_pt {SignalRegionPhase2}", 30 , 0 , 300},"QJetPhase2_0_pt","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"qqPhase2_pt___SignalRegionPhase2", "qqPhase2_pt {SignalRegionPhase2}", 30 , 0 , 300},"qqPhase2_pt","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"qqDeltaEtaPhase2___SignalRegionPhase2", "qqDeltaEtaPhase2 {SignalRegionPhase2}", 30 , 0,10},"qqDeltaEtaPhase2","SignalRegionPhase2Weight__Central"));
histos.emplace_back(selection_SignalRegionPhase2.Histo1D({"qqDeltaPhiPhase2___SignalRegionPhase2", "qqDeltaPhiPhase2 {SignalRegionPhase2}", 1000,0,1000},"qqDeltaPhiPhase2","SignalRegionPhase2Weight__Central"));
}
;
r.rdf.emplace("",rdf210);
r.histos=histos; return r;}