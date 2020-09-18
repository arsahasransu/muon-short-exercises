#include <iostream>
#include <cmath>

void FitInvMass() {

  TFile* file = TFile::Open("./histos2.root","READ");
  file->cd("demo");
  auto RecM = (TH1F*)file->Get("demo/h_RecDiMuonM");
  auto GenM = (TH1F*)file->Get("demo/h_GenDiMuonM");

  auto recFit = new TF1("Reco_Fit","[0]*TMath::Voigt(x-[1], [2], [3])", 75., 105.);
  recFit->SetParameter(1, 91.);
  recFit->SetParameter(2, 3.);
  recFit->SetParameter(3, 3.);
  RecM->Fit(recFit,"","", 75., 105.);
  /*
  auto c1 = new TCanvas();
  RecM->Draw();
  recFit->Draw("SAME");
  */
  
  auto genFit = new TF1("Genp_Fit","[0]*TMath::BreitWigner(x, [1], [2])", 75., 105.);
  genFit->SetParameter(1, 90.);
  genFit->SetParameter(2, 3.);
  GenM->Fit(genFit,"","", 75., 105.);
  /*
  auto c1 = new TCanvas();
  GenM->Draw();
  genFit->Draw("SAME");
  */
  
  std::cout<<RecM->Integral()<<std::endl;
  std::cout<<GenM->Integral()<<std::endl;
}
