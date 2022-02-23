void DrawHist()
{
  TFile *file1=new TFile("output_27_1.root");
  TFile *file2=new TFile("output_27_2.root");
  TFile *file3=new TFile("output_40_0.root");
  
  TH2D *hist1 = (TH2D*)file1->GetDirectory("demo;")->Get("C1Test1xy");
  hist1->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist1->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist1->SetTitle("ME1/1 x-y coordinates, Test 27: Measurement 7242");
  TH2D *hist2 = (TH2D*)file3->GetDirectory("demo;")->Get("C1Test2xy");
  hist2->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist2->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist2->SetTitle("ME1/1 x-y coordinates, Test 40: Measurement 7347");
  TH2D *hist3 = (TH2D*)file2->GetDirectory("demo;")->Get("C2Test1xy");
  hist3->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist3->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist3->SetTitle("ME2/1 x-y coordinates, Test 27: Measurement 7315");
  TH2D *hist4 = (TH2D*)file3->GetDirectory("demo;")->Get("C2Test2xy");
  hist4->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist4->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist4->SetTitle("ME2/1 x-y coordinates, Test 40: Measurement 7347");
  
  TH2D *hist5 = (TH2D*)file1->GetDirectory("demo;")->Get("C1Test1xy_1");
  hist5->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist5->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist5->SetTitle("ME1/1 x-y coordinates, Test 27: Measurement 7242");
  TH2D *hist6 = (TH2D*)file3->GetDirectory("demo;")->Get("C1Test2xy_1");
  hist6->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist6->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist6->SetTitle("ME1/1 x-y coordinates, Test 40: Measurement 7347");
  TH2D *hist7 = (TH2D*)file2->GetDirectory("demo;")->Get("C2Test1xy_1");
  hist7->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist7->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist7->SetTitle("ME2/1 x-y coordinates, Test 27: Measurement 7315");
  TH2D *hist8 = (TH2D*)file3->GetDirectory("demo;")->Get("C2Test2xy_1");
  hist8->GetXaxis()->SetTitle("x-coordinate (cm)");
  hist8->GetYaxis()->SetTitle("y-coordinate (cm)");
  hist8->SetTitle("ME2/1 x-y coordinates, Test 40: Measurement 7347");
  
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->Divide(2,2);
  
  c1->cd(1);
  hist1->Draw("COLZ1");
  c1->cd(2);
  hist2->Draw("COLZ1");
  c1->cd(3);
  hist3->Draw("COLZ1");
  c1->cd(4);
  hist4->Draw("COLZ1");
  
  
  TCanvas *c2 = new TCanvas("c2","c2");
  c2->Divide(2,2);
  
  c2->cd(1);
  hist5->Draw("COLZ1");
  c2->cd(2);
  hist6->Draw("COLZ1");
  c2->cd(3);
  hist7->Draw("COLZ1");
  c2->cd(4);
  hist8->Draw("COLZ1");
  
  /*
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->Divide(2,2);
  
  c1->cd(1);
  hist1->Draw();
  c1->cd(2);
  hist2->Draw();
  c1->cd(3);
  hist3->Draw();
  c1->cd(4);
  hist4->Draw();
  
  
  TCanvas *c2 = new TCanvas("c2","c2");
  c2->Divide(2,2);
  
  c2->cd(1);
  hist5->Draw();
  c2->cd(2);
  hist6->Draw();
  c2->cd(3);
  hist7->Draw();
  c2->cd(4);
  hist8->Draw();
  */
  
}