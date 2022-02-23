void DrawEffOctME11()
{
  TFile *file0=new TFile("output_ME11_40_Oct_HV0.root");
  TFile *file1=new TFile("output_ME11_40_Oct_175.root");
  TFile *file2=new TFile("output_ME11_40_Oct_200.root");
  TFile *file3=new TFile("output_ME11_40_Oct_225.root");
  TFile *file4=new TFile("output_ME11_40_Oct_250.root");
  TFile *file5=new TFile("output_ME11_40_Oct_300.root");
  TFile *file6=new TFile("output_ME11_40_Oct_400.root");
  
  /*
  TH2D *hist1 = (TH2D*)file1->GetDirectory("demo;")->Get("C1Test1xy");
  hist1->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist1->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist1->SetTitle("ME1/1 x-y coordinates, Test 27: Measurement 7242");
  */
  
  TH1D *hist0 = (TH1D*)file0->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_HV0=hist0->GetBinContent(1)/6.0;
  float n_correlatedlcts_c2_tot_Oct_HV0=hist0->GetBinContent(2)/6.0;
  
  TH1D *hist1 = (TH1D*)file1->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  int n_correlatedlcts_c1_tot_Oct_175=hist1->GetBinContent(1);
  int n_correlatedlcts_c2_tot_Oct_175=hist1->GetBinContent(2);
  
  TH1D *hist2 = (TH1D*)file2->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  int n_correlatedlcts_c1_tot_Oct_200=hist2->GetBinContent(1);
  int n_correlatedlcts_c2_tot_Oct_200=hist2->GetBinContent(2);
  
  TH1D *hist3 = (TH1D*)file3->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  int n_correlatedlcts_c1_tot_Oct_225=hist3->GetBinContent(1);
  int n_correlatedlcts_c2_tot_Oct_225=hist3->GetBinContent(2);
  
  TH1D *hist4 = (TH1D*)file4->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  int n_correlatedlcts_c1_tot_Oct_250=hist4->GetBinContent(1);
  int n_correlatedlcts_c2_tot_Oct_250=hist4->GetBinContent(2);
  
  TH1D *hist5 = (TH1D*)file5->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  int n_correlatedlcts_c1_tot_Oct_300=hist5->GetBinContent(1);
  int n_correlatedlcts_c2_tot_Oct_300=hist5->GetBinContent(2);
  
  TH1D *hist6 = (TH1D*)file6->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  int n_correlatedlcts_c1_tot_Oct_400=hist6->GetBinContent(1);
  int n_correlatedlcts_c2_tot_Oct_400=hist6->GetBinContent(2);
  
  std::cout << "No. of correlated LCTs in ME1/1: " <<n_correlatedlcts_c1_tot_Oct_HV0 << " No. of correlated LCTs in ME2/1: " <<n_correlatedlcts_c2_tot_Oct_HV0 << std::endl;
  
  Float_t Lower[7];

  Lower[0] = 162.5;
  Lower[1] = 187.5;
  Lower[2] = 212.5;
  Lower[3] = 237.5;
  Lower[4] = 275;
  Lower[5] = 350;
  Lower[6] = 450;
  
  /*
  TH1F* h1 = new TH1F("h1","ME1/1 Correlated LCT Digi Found, Test 40", 7, 0,7);
  h1->SetBinContent(1, n_correlatedlcts_c1_tot_Oct_175);
  h1->SetBinContent(2, n_correlatedlcts_c1_tot_Oct_200);
  h1->SetBinContent(3, n_correlatedlcts_c1_tot_Oct_225);
  h1->SetBinContent(4, n_correlatedlcts_c1_tot_Oct_250);
  h1->SetBinContent(5, n_correlatedlcts_c1_tot_Oct_300);
  h1->SetBinContent(6, n_correlatedlcts_c1_tot_Oct_400);
  h1->SetBinContent(7, n_correlatedlcts_c1_tot_Oct_HV0);
  //h1->SetMinimum(162.5);
  
  TH1F* h2 = new TH1F("h2","ME2/1 Correlated LCT Digi Found, Test 40", 7, 0,7);
  h2->SetBinContent(1, n_correlatedlcts_c2_tot_Oct_175);
  h2->SetBinContent(2, n_correlatedlcts_c2_tot_Oct_200);
  h2->SetBinContent(3, n_correlatedlcts_c2_tot_Oct_225);
  h2->SetBinContent(4, n_correlatedlcts_c2_tot_Oct_250);
  h2->SetBinContent(5, n_correlatedlcts_c2_tot_Oct_300);
  h2->SetBinContent(6, n_correlatedlcts_c2_tot_Oct_400);
  h2->SetBinContent(7, n_correlatedlcts_c2_tot_Oct_HV0);
  //h2->SetMinimum(162.5);
  */
  
  TH1F* h1 = new TH1F("h1","ME1/1 Correlated LCT Digi Found, Test 40", 7, 0,7);
  h1->SetBinContent(1, (n_correlatedlcts_c1_tot_Oct_175/(float)n_correlatedlcts_c2_tot_Oct_175));
  h1->SetBinContent(2, (n_correlatedlcts_c1_tot_Oct_200/(float)n_correlatedlcts_c2_tot_Oct_200));
  h1->SetBinContent(3, (n_correlatedlcts_c1_tot_Oct_225/(float)n_correlatedlcts_c2_tot_Oct_225));
  h1->SetBinContent(4, (n_correlatedlcts_c1_tot_Oct_250/(float)n_correlatedlcts_c2_tot_Oct_250));
  h1->SetBinContent(5, (n_correlatedlcts_c1_tot_Oct_300/(float)n_correlatedlcts_c2_tot_Oct_300));
  h1->SetBinContent(6, (n_correlatedlcts_c1_tot_Oct_400/(float)n_correlatedlcts_c2_tot_Oct_400));
  h1->SetBinContent(7, (n_correlatedlcts_c1_tot_Oct_HV0/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  
  TH1F* h2 = new TH1F("h2","ME2/1 Correlated LCT Digi Found, Test 40", 7, 0,7);
  h2->SetBinContent(1, (n_correlatedlcts_c2_tot_Oct_175/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(2, (n_correlatedlcts_c2_tot_Oct_200/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(3, (n_correlatedlcts_c2_tot_Oct_225/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(4, (n_correlatedlcts_c2_tot_Oct_250/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(5, (n_correlatedlcts_c2_tot_Oct_300/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(6, (n_correlatedlcts_c2_tot_Oct_400/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(7, (n_correlatedlcts_c2_tot_Oct_HV0/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  
  h1->SetLineWidth(3);
  h1->SetLineColor(kBlue);
  
  h2->SetLineWidth(3);
  h2->SetLineColor(kRed);
  
  THStack *hs = new THStack("hs","No of Correlated LCT Digi, Test 40, ME2/1 at HV0");
  hs->Add(h1);
  hs->Add(h2);
  hs->SetMinimum(0.9);
  //hs->GetXaxis()->SetTitle("ME21 HV");
  
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->Divide(1,1);
  
  c1->cd(1);
  hs->Draw("nostack");
  
  
  /*
  h1->Fill(175,n_correlatedlcts_c1_tot_Oct_175);
  h1->Fill(200,n_correlatedlcts_c1_tot_Oct_200);
  h1->Fill(225,n_correlatedlcts_c1_tot_Oct_225);
  h1->Fill(250,n_correlatedlcts_c1_tot_Oct_250);
  h1->Fill(300,n_correlatedlcts_c1_tot_Oct_300);
  h1->Fill(400,n_correlatedlcts_c1_tot_Oct_400);
  */
  
  /*
  
  TCanvas *c3 = new TCanvas("c3","c3");
  c3->Divide(2,2);
  
  c3->cd(1);
  hist9->Draw();
  c3->cd(2);
  hist10->Draw();
  c3->cd(3);
  hist11->Draw();
  c3->cd(4);
  hist12->Draw();
  
  */
  
}