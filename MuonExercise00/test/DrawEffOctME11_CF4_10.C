void DrawEffOctME11_CF4_10()
{
  TFile *file0=new TFile("output_ME11_40_Oct_HV0_CF4_10.root");
  TFile *file1=new TFile("output_ME11_40_Oct_175_CF4_10.root");
  TFile *file2=new TFile("output_ME11_40_Oct_200_CF4_10.root");
  TFile *file3=new TFile("output_ME11_40_Oct_225_CF4_10.root");
  TFile *file4=new TFile("output_ME11_40_Oct_250_CF4_10.root");
  TFile *file5=new TFile("output_ME11_40_Oct_300_CF4_10.root");
  TFile *file6=new TFile("output_ME11_40_Oct_400_CF4_10.root");
  TFile *file7=new TFile("output_ME11_40_Oct_100_CF4_10.root");
  TFile *file8=new TFile("output_ME11_40_Oct_150_CF4_10.root");
  
  /*
  TH2D *hist1 = (TH2D*)file1->GetDirectory("demo;")->Get("C1Test1xy");
  hist1->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist1->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist1->SetTitle("ME1/1 x-y coordinates, Test 27: Measurement 7242");
  */
  
  TH1D *hist0 = (TH1D*)file0->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_HV0=hist0->GetBinContent(1)/3.0;
  float n_correlatedlcts_c2_tot_Oct_HV0=hist0->GetBinContent(2)/3.0;
  
  TH1D *hist1 = (TH1D*)file1->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_175=hist1->GetBinContent(1);
  float n_correlatedlcts_c2_tot_Oct_175=hist1->GetBinContent(2);
  
  TH1D *hist2 = (TH1D*)file2->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_200=hist2->GetBinContent(1);
  float n_correlatedlcts_c2_tot_Oct_200=hist2->GetBinContent(2);
  
  TH1D *hist3 = (TH1D*)file3->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_225=hist3->GetBinContent(1);
  float n_correlatedlcts_c2_tot_Oct_225=hist3->GetBinContent(2);
  
  TH1D *hist4 = (TH1D*)file4->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_250=hist4->GetBinContent(1);
  float n_correlatedlcts_c2_tot_Oct_250=hist4->GetBinContent(2);
  
  TH1D *hist5 = (TH1D*)file5->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_300=hist5->GetBinContent(1)/2.0;
  float n_correlatedlcts_c2_tot_Oct_300=hist5->GetBinContent(2)/2.0;
  
  TH1D *hist6 = (TH1D*)file6->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_400=hist6->GetBinContent(1)/2.0;
  float n_correlatedlcts_c2_tot_Oct_400=hist6->GetBinContent(2)/2.0;
  
  TH1D *hist7 = (TH1D*)file7->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_100=hist7->GetBinContent(1);
  float n_correlatedlcts_c2_tot_Oct_100=hist7->GetBinContent(2);
  
  TH1D *hist8 = (TH1D*)file8->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  float n_correlatedlcts_c1_tot_Oct_150=hist8->GetBinContent(1);
  float n_correlatedlcts_c2_tot_Oct_150=hist8->GetBinContent(2);
  
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
  
  TH1F* h1 = new TH1F("h1","ME1/1 Correlated LCT Digi Found, Test 40", 8, 0,8);
  h1->SetBinContent(1, (n_correlatedlcts_c1_tot_Oct_150/(float)n_correlatedlcts_c2_tot_Oct_150));
  h1->SetBinContent(2, (n_correlatedlcts_c1_tot_Oct_175/(float)n_correlatedlcts_c2_tot_Oct_175));
  h1->SetBinContent(3, (n_correlatedlcts_c1_tot_Oct_200/(float)n_correlatedlcts_c2_tot_Oct_200));
  h1->SetBinContent(4, (n_correlatedlcts_c1_tot_Oct_225/(float)n_correlatedlcts_c2_tot_Oct_225));
  h1->SetBinContent(5, (n_correlatedlcts_c1_tot_Oct_250/(float)n_correlatedlcts_c2_tot_Oct_250));
  h1->SetBinContent(6, (n_correlatedlcts_c1_tot_Oct_300/(float)n_correlatedlcts_c2_tot_Oct_300));
  h1->SetBinContent(7, (n_correlatedlcts_c1_tot_Oct_400/(float)n_correlatedlcts_c2_tot_Oct_400));
  h1->SetBinContent(8, (n_correlatedlcts_c1_tot_Oct_HV0/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  
  TH1F* h2 = new TH1F("h2","ME2/1 Correlated LCT Digi Found, Test 40", 8, 0,8);
  h2->SetBinContent(1, (n_correlatedlcts_c2_tot_Oct_150/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(2, (n_correlatedlcts_c2_tot_Oct_175/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(3, (n_correlatedlcts_c2_tot_Oct_200/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(4, (n_correlatedlcts_c2_tot_Oct_225/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(5, (n_correlatedlcts_c2_tot_Oct_250/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(6, (n_correlatedlcts_c2_tot_Oct_300/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(7, (n_correlatedlcts_c2_tot_Oct_400/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  h2->SetBinContent(8, (n_correlatedlcts_c2_tot_Oct_HV0/(float)n_correlatedlcts_c2_tot_Oct_HV0));
  
  h1->SetLineWidth(3);
  h1->SetLineColor(kBlue);
  
  h2->SetLineWidth(3);
  h2->SetLineColor(kRed);
  
  Double_t x[100], y[100];
  Int_t n = 8;
  x[0] = n_correlatedlcts_c1_tot_Oct_150/(float)n_correlatedlcts_c2_tot_Oct_150;
  x[1] = n_correlatedlcts_c1_tot_Oct_175/(float)n_correlatedlcts_c2_tot_Oct_175;
  x[2] = n_correlatedlcts_c1_tot_Oct_200/(float)n_correlatedlcts_c2_tot_Oct_200;
  x[3] = n_correlatedlcts_c1_tot_Oct_225/(float)n_correlatedlcts_c2_tot_Oct_225;
  x[4] = n_correlatedlcts_c1_tot_Oct_250/(float)n_correlatedlcts_c2_tot_Oct_250;
  x[5] = n_correlatedlcts_c1_tot_Oct_300/(float)n_correlatedlcts_c2_tot_Oct_300;
  x[6] = n_correlatedlcts_c1_tot_Oct_HV0/(float)n_correlatedlcts_c2_tot_Oct_HV0;
  x[7] = n_correlatedlcts_c1_tot_Oct_400/(float)n_correlatedlcts_c2_tot_Oct_400;
  
  
  y[0] = 2735.33;
  y[1] = 2759.33;
  y[2] = 2779.83;
  y[3] = 2798.33;
  y[4] = 2814.66;
  y[5] = 2843.0;
  y[6] = 2869.16;
  y[7] = 2887.83;
  
  
  TGraph* gr = new TGraph(n,y,x);
  gr->SetMaximum(1.00);
  gr->SetTitle("ME1/1 LCT Digi Efficiency");
  
  THStack *hs = new THStack("hs","ME1/1 LCT Digi Efficiency");//Test 40, ME2/1 at HV0
  hs->Add(h1);
  hs->SetMinimum(0.96);
  hs->SetMaximum(1.01);
  //hs->GetXaxis()->SetTitle("ME21 HV");
  //hs->Getyaxis()->SetTitle("LCT Efficiency");
  
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->Divide(1,1);
  
  c1->cd(1);
  gr->Draw("AC*");
  //hs->Draw("nostack");
  
  
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