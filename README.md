# muon-short-exercises
Muon short exercise for DAS

Q1
========
vector<pat::PackedGenParticle>        "packedGenParticles"       ""                "PAT" 
vector<reco::GenParticle>             "prunedGenParticles"        ""                "PAT"      
vector<pat::Muon>                     "slimmedMuons"             ""                "PAT"    
BXVector<l1t::Muon>                   "gmtStage2Digis"           "Muon"            "RECO"
edm::TriggerResults                   "TriggerResults"           ""                "HLT"
vector<pat::TriggerObjectStandAlone>  "slimmedPatTrigger"        ""                "PAT"

The branch vector<pat::Muon> "slimmedMuons" containd muons of intrest to us.

Q2
========
Tracker Muons = 134654		14229
Global Muons = 61141		87742
StandAlone Muons = 70685	78198

Q3
========
3. Events->Scan("patMuons_slimmedMuons__PAT.obj.pt():patMuons_slimmedMuons__PAT.obj.eta()", "patMuons_slimmedMuons__PAT.obj.pt()>20 && TMath::Abs(patMuons_slimmedMuons__PAT.obj.eta())<2.4 && patMuons_slimmedMuons__PAT.obj.isGlobalMuon()==1","",5);

6. Events->Scan("recoGenParticles_prunedGenParticles__PAT.obj.pt():recoGenParticles_prunedGenParticles__PAT.obj.eta()","TMath::Abs(recoGenParticles_prunedGenParticles__PAT.obj.pdgId())==13 && recoGenParticles_prunedGenParticles__PAT.obj.status()==1 && recoGenParticles_prunedGenParticles__PAT.obj.pt()>20 && TMath::Abs(recoGenParticles_prunedGenParticles__PAT.obj.eta())<2.4 && recoGenParticles_prunedGenParticles__PAT.obj.isPromptFinalState()==1","",5)