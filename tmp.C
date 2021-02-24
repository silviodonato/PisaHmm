
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
ROOT::VecOps::RVec<int> func__GenLepton(unsigned int __slot , const ROOT::VecOps::RVec<Int_t> & GenPart_pdgId) {  return (abs(GenPart_pdgId)==13 || abs(GenPart_pdgId)==11 || abs(GenPart_pdgId)==15); }
ROOT::VecOps::RVec<float> func__GenLepton_eta(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenLepton, const ROOT::VecOps::RVec<Float_t> & GenPart_eta) {  return At(GenPart_eta,GenLepton); }
ROOT::VecOps::RVec<float> func__GenLepton_phi(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenLepton, const ROOT::VecOps::RVec<Float_t> & GenPart_phi) {  return At(GenPart_phi,GenLepton); }
int func__nGenLepton(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenLepton) {  return Sum(GenLepton); }
ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > func__GenLeptonGenJetPair(unsigned int __slot , const UInt_t & nGenJet, const int & nGenLepton) {  return Combinations(nGenLepton,nGenJet); }
ROOT::VecOps::RVec<float> func__GenLeptonGenJetPair_dr(unsigned int __slot , const ROOT::VecOps::RVec<Float_t> & GenJet_eta, const ROOT::VecOps::RVec<Float_t> & GenJet_phi, const ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > & GenLeptonGenJetPair, const ROOT::VecOps::RVec<float> & GenLepton_eta, const ROOT::VecOps::RVec<float> & GenLepton_phi) {  return DeltaR(Take(GenLepton_eta,At(GenLeptonGenJetPair,0)),Take(GenJet_eta,At(GenLeptonGenJetPair,1)),Take(GenLepton_phi,At(GenLeptonGenJetPair,0)),Take(GenJet_phi,At(GenLeptonGenJetPair,1))  ); }
ROOT::VecOps::RVec<float> func__GenJet_GenLeptonDr(unsigned int __slot , const ROOT::VecOps::RVec<float> & GenLeptonGenJetPair_dr, const UInt_t & nGenJet, const int & nGenLepton) {  return matrix_map(nGenLepton,nGenJet,0,[](const ROOT::VecOps::RVec<float> & v) {return v.size()>0?(-Max(-v)):-99;},GenLeptonGenJetPair_dr); }
ROOT::VecOps::RVec<unsigned long> func__GenJet_GenLeptonIdx(unsigned int __slot , const ROOT::VecOps::RVec<float> & GenLeptonGenJetPair_dr, const UInt_t & nGenJet, const int & nGenLepton) {  return matrix_map(nGenLepton,nGenJet,0,[](const ROOT::VecOps::RVec<float> & v) {return v.size()>0?Argmax(-v):-1;},GenLeptonGenJetPair_dr); }
ROOT::VecOps::RVec<int> func__GenJetVBFFilter(unsigned int __slot , const ROOT::VecOps::RVec<float> & GenJet_GenLeptonDr, const ROOT::VecOps::RVec<unsigned long> & GenJet_GenLeptonIdx) {  return GenJet_GenLeptonDr>0.3 || GenJet_GenLeptonIdx==-1 ; }
ROOT::VecOps::RVec<float> func__GenJetVBFFilter_eta(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenJetVBFFilter, const ROOT::VecOps::RVec<Float_t> & GenJet_eta) {  return At(GenJet_eta,GenJetVBFFilter); }
ROOT::VecOps::RVec<float> func__GenJetVBFFilter_mass(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenJetVBFFilter, const ROOT::VecOps::RVec<Float_t> & GenJet_mass) {  return At(GenJet_mass,GenJetVBFFilter); }
ROOT::VecOps::RVec<float> func__GenJetVBFFilter_phi(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenJetVBFFilter, const ROOT::VecOps::RVec<Float_t> & GenJet_phi) {  return At(GenJet_phi,GenJetVBFFilter); }
ROOT::VecOps::RVec<float> func__GenJetVBFFilter_pt(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenJetVBFFilter, const ROOT::VecOps::RVec<Float_t> & GenJet_pt) {  return At(GenJet_pt,GenJetVBFFilter); }
int func__nGenJetVBFFilter(unsigned int __slot , const ROOT::VecOps::RVec<int> & GenJetVBFFilter) {  return Sum(GenJetVBFFilter); }
ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > func__GenJetVBFFilter_p4(unsigned int __slot , const ROOT::VecOps::RVec<float> & GenJetVBFFilter_eta, const ROOT::VecOps::RVec<float> & GenJetVBFFilter_mass, const ROOT::VecOps::RVec<float> & GenJetVBFFilter_phi, const ROOT::VecOps::RVec<float> & GenJetVBFFilter_pt) {  return vector_map_t<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >	>(GenJetVBFFilter_pt , GenJetVBFFilter_eta, GenJetVBFFilter_phi, GenJetVBFFilter_mass); }
bool func__twoVBFFilterGenJet(unsigned int __slot , const int & nGenJetVBFFilter) {  return nGenJetVBFFilter > 1; }
int func__justPass(unsigned int __slot ) {  return 1; }
float func__VBFFilterjj_mass(unsigned int __slot , const ROOT::VecOps::RVec<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > & GenJetVBFFilter_p4, const bool & twoVBFFilterGenJet) {  return twoVBFFilterGenJet?(At(GenJetVBFFilter_p4,0)+At(GenJetVBFFilter_p4,1)).M():-1; }
bool func__VBFFilterFlag(unsigned int __slot , const float & VBFFilterjj_mass) {  return VBFFilterjj_mass>350; }
double func__justPassWeight__Central(unsigned int __slot ) {  return 1.; }
double func__VBFFilterFlagWeight__Central(unsigned int __slot ) {  return 1.; }

Result DY105VBF_2018MGPYProcessor_nail(RNode rdf,int nThreads) {
     Result r;
     if(nThreads > 0)
     ROOT::EnableImplicitMT(nThreads);
	
	   auto rdf0 =rdf.DefineSlot("GenLepton",func__GenLepton,{"GenPart_pdgId"});
auto rdf1 =rdf0.DefineSlot("GenLepton_eta",func__GenLepton_eta,{"GenLepton","GenPart_eta"});
auto rdf2 =rdf1.DefineSlot("GenLepton_phi",func__GenLepton_phi,{"GenLepton","GenPart_phi"});
auto rdf3 =rdf2.DefineSlot("nGenLepton",func__nGenLepton,{"GenLepton"});
auto rdf4 =rdf3.DefineSlot("GenLeptonGenJetPair",func__GenLeptonGenJetPair,{"nGenJet","nGenLepton"});
auto rdf5 =rdf4.DefineSlot("GenLeptonGenJetPair_dr",func__GenLeptonGenJetPair_dr,{"GenJet_eta","GenJet_phi","GenLeptonGenJetPair","GenLepton_eta","GenLepton_phi"});
auto rdf6 =rdf5.DefineSlot("GenJet_GenLeptonDr",func__GenJet_GenLeptonDr,{"GenLeptonGenJetPair_dr","nGenJet","nGenLepton"});
auto rdf7 =rdf6.DefineSlot("GenJet_GenLeptonIdx",func__GenJet_GenLeptonIdx,{"GenLeptonGenJetPair_dr","nGenJet","nGenLepton"});
auto rdf8 =rdf7.DefineSlot("GenJetVBFFilter",func__GenJetVBFFilter,{"GenJet_GenLeptonDr","GenJet_GenLeptonIdx"});
auto rdf9 =rdf8.DefineSlot("GenJetVBFFilter_eta",func__GenJetVBFFilter_eta,{"GenJetVBFFilter","GenJet_eta"});
auto rdf10 =rdf9.DefineSlot("GenJetVBFFilter_mass",func__GenJetVBFFilter_mass,{"GenJetVBFFilter","GenJet_mass"});
auto rdf11 =rdf10.DefineSlot("GenJetVBFFilter_phi",func__GenJetVBFFilter_phi,{"GenJetVBFFilter","GenJet_phi"});
auto rdf12 =rdf11.DefineSlot("GenJetVBFFilter_pt",func__GenJetVBFFilter_pt,{"GenJetVBFFilter","GenJet_pt"});
auto rdf13 =rdf12.DefineSlot("nGenJetVBFFilter",func__nGenJetVBFFilter,{"GenJetVBFFilter"});
auto rdf14 =rdf13.DefineSlot("GenJetVBFFilter_p4",func__GenJetVBFFilter_p4,{"GenJetVBFFilter_eta","GenJetVBFFilter_mass","GenJetVBFFilter_phi","GenJetVBFFilter_pt"});
auto rdf15 =rdf14.DefineSlot("twoVBFFilterGenJet",func__twoVBFFilterGenJet,{"nGenJetVBFFilter"});
auto rdf16 =rdf15.DefineSlot("justPass",func__justPass,{});
auto rdf17 =rdf16.DefineSlot("VBFFilterjj_mass",func__VBFFilterjj_mass,{"GenJetVBFFilter_p4","twoVBFFilterGenJet"});
auto rdf18 =rdf17.DefineSlot("VBFFilterFlag",func__VBFFilterFlag,{"VBFFilterjj_mass"});
auto rdf19 =rdf18.DefineSlot("justPassWeight__Central",func__justPassWeight__Central,{});
auto rdf20 =rdf19.DefineSlot("VBFFilterFlagWeight__Central",func__VBFFilterFlagWeight__Central,{});
auto toplevel=rdf20;
std::vector<ROOT::RDF::RResultPtr<TH1D>> histos;
{}auto selection_VBFFilterFlag=rdf20.Filter("justPass","justPass").Filter("VBFFilterFlag","VBFFilterFlag");
r.rdf.emplace("VBFFilterFlag",selection_VBFFilterFlag);
{histos.emplace_back(selection_VBFFilterFlag.Histo1D({"VBFFilterFlag___VBFFilterFlag", "VBFFilterFlag {VBFFilterFlag}", 1000,0,1000},"VBFFilterFlag","VBFFilterFlagWeight__Central"));
}
;
r.rdf.emplace("",selection_VBFFilterFlag);
r.histos=histos; return r;}