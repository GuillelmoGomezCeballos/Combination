void results(int nsel = 0){

const int Npoints = 21;
double mass[Npoints]  = {110,115,120,125,130,135,140,150,160,170,180,190,200,250,300,350,400,450,500,550,600};
double error[Npoints] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double study01[21]={1.05,1.11,1.19,1.12,1.15,1.17,1.12,0.95,0.88,0.87,0.89,0.89,0.91,0.95,0.88,0.93,0.87,0.79,0.73,0.73,0.70};
double study02[21]={0.98,1.11,1.97,1.03,1.05,1.07,1.09,1.19,1.26,1.38,1.65,1.96,2.03,1.40,1.75,1.75,1.75,1.74,1.76,1.82,1.96};
double study03[21]={1.20,1.24,1.20,1.31,1.36,1.36,1.40,1.44,1.41,1.13,0.96,0.88,0.89,1.40,1.44,1.15,1.09,1.07,1.11,1.22,1.35};
double study04[21]={1.41,1.44,1.41,1.43,1.47,1.51,1.55,1.68,1.70,1.47,1.28,1.21,1.15,1.26,1.29,1.09,0.97,0.80,0.73,0.73,0.77};
double study05[21]={1.01,1.06,1.13,1.10,1.12,1.21,1.10,0.97,0.87,0.90,0.92,0.97,1.03,0.91,0.85,0.96,0.90,0.85,0.78,0.79,0.73};
double study06[21]={1.12,1.07,1.01,1.01,1.02,1.07,1.10,1.22,1.35,1.54,1.88,2.11,2.19,1.39,1.71,1.59,1.55,1.54,1.53,1.58,1.72};
double study07[21]={1.26,1.36,1.35,1.47,1.52,1.56,1.59,1.61,1.57,1.22,1.00,0.90,0.90,1.39,1.43,1.10,1.03,1.03,1.07,1.15,1.28};
double study08[21]={1.40,1.41,1.37,1.42,1.45,1.50,1.52,1.74,1.84,1.55,1.36,1.31,1.28,1.21,1.26,1.09,0.99,0.85,0.77,0.76,0.81};
double study09[21]={1.16,1.14,1.25,1.22,1.25,1.23,1.15,1.05,0.96,0.87,0.88,0.88,0.89,1.00,0.95,0.94,0.88,0.77,0.72,0.69,0.69};
double study10[21]={0.94,1.28,1.24,1.17,1.23,1.17,1.14,1.21,1.29,1.38,1.52,1.71,1.64,1.37,1.71,1.95,2.14,2.11,2.12,2.10,2.20};
double study11[21]={1.27,1.25,1.17,1.29,1.34,1.30,1.32,1.30,1.30,1.11,0.99,0.91,0.91,1.38,1.42,1.24,1.16,1.11,1.11,1.24,1.37};
double study12[21]={1.45,1.48,1.41,1.35,1.39,1.37,1.41,1.45,1.69,1.57,1.38,1.27,1.19,1.34,1.33,1.21,1.04,0.80,0.72,0.72,0.77};

double theStudy01[Npoints],theStudy02[Npoints],theStudy03[Npoints],theStudy04[Npoints];
TString whichAna = "0/1-jet bins   ";
if    (nsel == 0){
 whichAna = "0-jet bin   ";
 for(int i=0; i<Npoints; i++) {
   theStudy01[i] = study01[i];
   theStudy02[i] = study02[i];
   theStudy03[i] = study03[i];
   theStudy04[i] = study04[i];
 }
}
else if(nsel == 1){
 whichAna = "1-jet bin   ";
 for(int i=0; i<Npoints; i++) {
   theStudy01[i] = study05[i];
   theStudy02[i] = study06[i];
   theStudy03[i] = study07[i];
   theStudy04[i] = study08[i];
 }
}
else if(nsel == 2){
 for(int i=0; i<Npoints; i++) {
   theStudy01[i] = study09[i];
   theStudy02[i] = study10[i];
   theStudy03[i] = study11[i];
   theStudy04[i] = study12[i];
 }
}
// set colors	       
Int_t black  = 1;       
Int_t red    = 2;       
Int_t green  = 3;       
Int_t blue   = 4;
Int_t yellow = 5;
Int_t purple = 6;       
Int_t skyblue= 7;      
Int_t ngreen = 8;       
Int_t violet = 9;       
Int_t gray   = 12;       
Int_t brown  = 41;       
Int_t bred   = 46;       
// set marker shapes   
Int_t ball	  = 20; 
Int_t box         = 21; 
Int_t triangleUp  = 22; 
Int_t triangleDown= 23; 

TGraph *H_mva01 = new TGraph (Npoints, mass, theStudy01);
H_mva01->SetMarkerStyle(triangleDown);
H_mva01->SetMarkerColor(bred);
H_mva01->SetLineStyle(1);
H_mva01->SetTitle("");
H_mva01->GetXaxis()->SetRange(110,600);
H_mva01->GetXaxis()->SetTitleOffset(0.9);
H_mva01->GetXaxis()->SetTitleSize(0.04);
H_mva01->GetXaxis()->SetLabelSize(0.04);
H_mva01->GetYaxis()->SetTitleOffset(1.5);
H_mva01->GetYaxis()->SetTitleSize(0.04);
H_mva01->GetYaxis()->SetLabelSize(0.04);
H_mva01->GetYaxis()->CenterTitle(kTRUE);
H_mva01->SetMinimum(0.6);
H_mva01->SetMaximum(1.8);
H_mva01->Draw("APL");
TGraph *H_mva02 = new TGraph (Npoints, mass, theStudy02);
H_mva02->SetMarkerStyle(triangleUp);
H_mva02->SetMarkerColor(red);
H_mva02->SetLineStyle(1);
H_mva02->Draw("PL");
TGraph *H_mva03 = new TGraph (Npoints, mass, theStudy03);
H_mva03->SetMarkerStyle(box);
H_mva03->SetMarkerColor(blue);
H_mva03->SetLineStyle(1);
H_mva03->Draw("PL");
TGraph *H_mva04 = new TGraph (Npoints, mass, theStudy04);
H_mva04->SetMarkerStyle(ball);
H_mva04->SetMarkerColor(purple);
H_mva04->SetLineStyle(1);
H_mva04->Draw("PL");

TAxis *axisX=H_mva01->GetXaxis();
TAxis *axisY=H_mva01->GetYaxis();
axisX->SetTitle("Mass [GeV]");
axisX->Draw();
axisY->SetTitle("Significance ratio");
axisY->SetTitleOffset(1.);
axisY->Draw();
TLegend *leg = new TLegend(0.5,0.65,0.8,0.85);
leg->SetFillColor(0);
leg->SetTextSize(0.03);
leg->AddEntry(H_mva01, "2D/BDT","p");
leg->AddEntry(H_mva02, "2D/2D BDT125","p");
leg->AddEntry(H_mva03, "2D/2D BDT200","p");
leg->AddEntry(H_mva04, "2D/2D BDT500","p");
leg->Draw();

TLine *line = new TLine(110, 1, 600, 1);
line->SetLineColor(kRed+1);
line->SetLineWidth(2);
line->Draw("same");

labelcms  = new TPaveText(0.30,0.95,0.50,0.95,"NDCBR");
labelcms->SetTextAlign(12);
labelcms->SetTextSize(0.05);
labelcms->SetFillColor(0);
labelcms->AddText(whichAna.Data());
labelcms->SetBorderSize(0);
labelcms->Draw("same");
}
