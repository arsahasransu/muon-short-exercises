// -*- C++ -*-
//
// Package:    CMSDASExercises/MuonExercise2
// Class:      MuonExercise2
// 
/**\class MuonExercise3 MuonExercise2.cc CMSDASExercises/MuonExercise3/plugins/MuonExercise2.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Norbert Neumeister
//         Created:  Thu, 10 Dec 2016 21:10:01 GMT
//
//

// system include files
#include <memory>
#include <iomanip>

#include <TLorentzVector.h>
#include <TVector3.h>
#include <TProfile.h>
#include <TTree.h>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

//
// class declaration
//

class MuonExercise2 : public edm::one::EDAnalyzer<edm::one::SharedResources> {

   public:

      explicit MuonExercise2(const edm::ParameterSet&);
      ~MuonExercise2();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:

      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
      
      edm::EDGetTokenT<pat::MuonCollection> muonCollToken;
      edm::EDGetTokenT<pat::PackedGenParticleCollection> genCollToken;
      edm::EDGetTokenT<std::vector<reco::Vertex>> vertexToken;
  //edm::EDGetTokenT<reco::Vertex> vertexToken;
  
      TH1F* h_RecDiMuonM;
      TH1F* h_GenDiMuonM;
      
  
  
};

//
// constructors and destructor
//
MuonExercise2::MuonExercise2(const edm::ParameterSet& iConfig) {

  edm::InputTag theMuonLabel("slimmedMuons");
  edm::InputTag theGenMuonLabel("packedGenParticles");
  edm::InputTag VertexTag ("offlineSlimmedPrimaryVertices");
  
  muonCollToken = consumes<pat::MuonCollection>(theMuonLabel);
  genCollToken = consumes<pat::PackedGenParticleCollection>(theGenMuonLabel);
  vertexToken = consumes<std::vector<reco::Vertex>>(VertexTag);

  edm::Service<TFileService> fs;
  
  h_RecDiMuonM = fs->make<TH1F>("h_RecDiMuonM",";m_{#mu^{+}#mu^{-}};",80,70,110);
  h_GenDiMuonM = fs->make<TH1F>("h_GenDiMuonM",";m_{#mu^{+}#mu^{-}};",80,70,110);
 
}


MuonExercise2::~MuonExercise2() {
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void MuonExercise2::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {

  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;
   
  edm::Handle<vector<pat::Muon>> muons;
  iEvent.getByToken(muonCollToken, muons);
   
  edm::Handle <pat::PackedGenParticleCollection> genColl;
  iEvent.getByToken(genCollToken, genColl);

  edm::Handle<vector<reco::Vertex>> vertices;
  iEvent.getByToken(vertexToken, vertices);
  if(!vertices.isValid()) {
    throw cms::Exception("Vertex collection not valid!"); 
  } 



   // Let's check that we have at least one good vertex! 
  
  std::vector<reco::Vertex>::const_iterator firstGoodVertex = vertices->end();

   for (std::vector<reco::Vertex>::const_iterator it=vertices->begin(); it!=firstGoodVertex; ++it) {
    if (!it->isFake() && it->ndof()>4 && it->position().Rho()<2. && std::abs(it->position().Z())<24.) {
      if(firstGoodVertex == vertices->end()) firstGoodVertex = it;
      break;
    }
  }
  // Require a good vertex
  if(firstGoodVertex == vertices->end()) return;

  /////////////////////////////////////////////////
  // Dimuon pairs /////////////////////////////////
  /////////////////////////////////////////////////
    
  //put your code here
  

}


// ------------ method called once each job just before starting event loop  ------------
void MuonExercise2::beginJob() {
}

// ------------ method called once each job just after ending the event loop  ------------
void MuonExercise2::endJob() {
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void MuonExercise2::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {

  // The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

}

//define this as a plug-in
DEFINE_FWK_MODULE(MuonExercise2);
