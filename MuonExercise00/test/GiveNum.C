void GiveNum()
{
  TFile *file0=new TFile("output_ME11_40_Oct_175_CF4_10.root");
  
  /*
  TH2D *hist1 = (TH2D*)file1->GetDirectory("demo;")->Get("C1Test1xy");
  hist1->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist1->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist1->SetTitle("ME1/1 x-y coordinates, Test 27: Measurement 7242");
  */
  
  TH1D *hist0 = (TH1D*)file0->GetDirectory("demo;")->Get("CorrelatedLCTC1C2");
  int n_correlatedlcts_c1_tot_Oct=hist0->GetBinContent(1);
  int n_correlatedlcts_c2_tot_Oct=hist0->GetBinContent(2);
  
  std::cout << "No. of correlated LCTs in ME1/1: " <<n_correlatedlcts_c1_tot_Oct << " No. of correlated LCTs in ME2/1: " <<n_correlatedlcts_c2_tot_Oct << std::endl;
  
  
  
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