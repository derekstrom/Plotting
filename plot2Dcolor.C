{

  TCanvas *c1 = new TCanvas("c1","c1",600,600);

  int nbins = 100;

  TH2F *hcol1 = new TH2F("hcol1","2D Color",nbins,0,nbins,nbins,0,nbins);

  for(int i=0; i<nbins; ++i){
    for(int j=0; j<nbins; ++j){
      for(int k=0; k<=i; ++k){
	for(int l=0; l<=j; ++l){
	  //	  std::cout << i << " " << j << std::endl;
	  hcol1->Fill(i,j);
	}
      }
    }
  }

  const Int_t NRGBs = 5;
  const Int_t NCont = 255;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);


  //  gStyle->SetPalette(1);
  hcol1->Draw("COLZ");
  return c1;
}
