void resultsVBF(int nsel = 0){

const int Npoints = 21;
double mass[Npoints]  = {110,115,120,125,130,135,140,150,160,170,180,190,200,250,300,350,400,450,500,550,600};
double error[Npoints] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double study01[21]={0.41742987265348225, 0.67823829486564791, 1.1392679658826348, 1.6971583081814103, 2.2824614775445795, 2.6670253967437403, 3.0185511256815314, 3.8027987173527902, 4.6740103410607796, 4.5494804353894889, 4.1722301811069356, 3.4330598391439215, 2.8984541917956221, 1.6494554480535797, 1.4228820035318865, 1.427173190178719, 1.3350855677491296, 1.2560726454375351, 1.134283627065974, 1.0967144135348694, 1.0270777592154401};
double study02[21]={0.41904033781756315, 0.68464024983237658, 1.1576437551504662, 1.7433012490195989, 2.5318917573616662, 3.0342040303953404, 3.5470997211690496, 4.5860680040986495, 5.6285663763566918, 5.4925495343923103, 4.6806864904775463, 3.602803341260024, 2.99786442273017, 1.9304895448818866, 1.9504483273317765, 2.0385939516949518, 1.7877059754712536, 1.5912563027741633, 1.461410722178855, 1.2738101609050023, 1.1497225438839458};

double theStudy01[Npoints],theStudy02[Npoints];
TString whichAna = "2-jet bin";
if    (nsel == 0){
 whichAna = "2-jet bin   ";
 for(int i=0; i<Npoints; i++) {
   theStudy01[i] = study01[i];
   theStudy02[i] = study02[i]/theStudy01[i];
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

TGraph *H_mva01 = new TGraph (Npoints, mass, theStudy02);
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
H_mva01->SetMinimum(0.9);
H_mva01->SetMaximum(1.5);
H_mva01->Draw("APL");

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
leg->AddEntry(H_mva01, "shape-based/cut-based","p");
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
