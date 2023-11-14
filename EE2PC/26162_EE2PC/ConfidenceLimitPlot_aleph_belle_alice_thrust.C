void ConfidenceLimitPlot_aleph_belle_alice_thrust()
{
//=========Macro generated from canvas: canvB/canvB
//=========  (Tue Sep 19 10:17:57 2023) by ROOT version 6.24/06
   TCanvas *canvB = new TCanvas("canvB", "canvB",0,0,600,600);
   canvB->SetHighLightColor(2);
   canvB->Range(-13.6,-10,77.06667,3.333333);
   canvB->SetFillColor(0);
   canvB->SetBorderMode(0);
   canvB->SetBorderSize(2);
   canvB->SetLogy();
   canvB->SetTickx(1);
   canvB->SetTicky(1);
   canvB->SetLeftMargin(0.15);
   canvB->SetBottomMargin(0.15);
   canvB->SetFrameBorderMode(0);
   canvB->SetFrameBorderMode(0);
   
   TH1D *dummy__3 = new TH1D("dummy__3","",1,0,68);
   dummy__3->SetMinimum(1e-08);
   dummy__3->SetMaximum(100);
   dummy__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   dummy__3->SetLineColor(ci);
   dummy__3->GetXaxis()->SetTitle("#LT N_{trk}^{corr} #GT");
   dummy__3->GetXaxis()->CenterTitle(true);
   dummy__3->GetXaxis()->SetLabelFont(42);
   dummy__3->GetXaxis()->SetLabelSize(0.04);
   dummy__3->GetXaxis()->SetTitleSize(0.05);
   dummy__3->GetXaxis()->SetTitleOffset(1.2);
   dummy__3->GetXaxis()->SetTitleFont(42);
   dummy__3->GetYaxis()->SetTitle("Associated yield");
   dummy__3->GetYaxis()->CenterTitle(true);
   dummy__3->GetYaxis()->SetLabelFont(42);
   dummy__3->GetYaxis()->SetLabelSize(0.04);
   dummy__3->GetYaxis()->SetTitleSize(0.05);
   dummy__3->GetYaxis()->SetTitleOffset(1.4);
   dummy__3->GetYaxis()->SetTitleFont(42);
   dummy__3->GetZaxis()->SetLabelFont(42);
   dummy__3->GetZaxis()->SetTitleOffset(1);
   dummy__3->GetZaxis()->SetTitleFont(42);
   dummy__3->Draw("p");
   TArrow *arrow = new TArrow(1.925926,2.849781e-05,1.925926,6.139666e-07,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1189;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   TLine *line = new TLine(1.425926,2.849781e-05,2.425926,2.849781e-05);

   ci = 1190;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(1.925926,3.448235e-05,"");
   tex->SetTextAlign(20);

   ci = 1191;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(5.333333,3.25258e-05,5.333333,7.007472e-07,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1189;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(4.833333,3.25258e-05,5.833333,3.25258e-05);

   ci = 1190;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(5.333333,4.553612e-05,"95%");
   tex->SetTextAlign(20);

   ci = 1191;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(8.888889,5.015923e-05,8.888889,1.080648e-06,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1189;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(8.388889,5.015923e-05,9.388889,5.015923e-05);

   ci = 1190;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(8.888889,6.069267e-05,"");
   tex->SetTextAlign(20);

   ci = 1191;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t Graph0_fx3001[8] = {
   14.37037,
   21.62963,
   29.18519,
   36.44444,
   44,
   51.25926,
   58.81481,
   66.37037};
   Double_t Graph0_fy3001[8] = {
   4.376413e-05,
   0.0002246496,
   0.0003127791,
   0.000795315,
   0.00130898,
   0.001884681,
   0.00253771,
   0.002890725};
   Double_t Graph0_felx3001[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fely3001[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fehx3001[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fehy3001[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(8,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillStyle(1000);

   ci = 1192;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = 1193;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph03001 = new TH1F("Graph_Graph03001","Graph",100,9.17037,71.57037);
   Graph_Graph03001->SetMinimum(3.938772e-05);
   Graph_Graph03001->SetMaximum(0.003175421);
   Graph_Graph03001->SetDirectory(0);
   Graph_Graph03001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph03001->SetLineColor(ci);
   Graph_Graph03001->GetXaxis()->SetLabelFont(42);
   Graph_Graph03001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph03001->GetXaxis()->SetTitleFont(42);
   Graph_Graph03001->GetYaxis()->SetLabelFont(42);
   Graph_Graph03001->GetYaxis()->SetTitleFont(42);
   Graph_Graph03001->GetZaxis()->SetLabelFont(42);
   Graph_Graph03001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph03001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph03001);
   
   grae->Draw("p ");
   arrow = new TArrow(8.9,0.001195229,8.9,2.575043e-05,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1194;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(8.4,0.001195229,9.4,0.001195229);

   ci = 1195;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(8.9,0.001446227,"95%");
   tex->SetTextAlign(20);

   ci = 1196;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(15.8,1e-05,15.8,2.154435e-07,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1194;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(15.3,1e-05,16.3,1e-05);

   ci = 1195;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(15.8,1.21e-05,"96%");
   tex->SetTextAlign(20);

   ci = 1196;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(23.4,5.221903e-05,23.4,1.125025e-06,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1194;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(22.9,5.221903e-05,23.9,5.221903e-05);

   ci = 1195;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(23.4,6.318503e-05,"95%");
   tex->SetTextAlign(20);

   ci = 1196;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(32.6,0.002284824,32.6,4.922504e-05,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1194;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(32.1,0.002284824,33.1,0.002284824);

   ci = 1195;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(32.6,0.002764637,"95%");
   tex->SetTextAlign(20);

   ci = 1196;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(37.2,0.008600333,37.2,0.0001852886,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1194;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(36.7,0.008600333,37.7,0.008600333);

   ci = 1195;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(37.2,0.0104064,"95%");
   tex->SetTextAlign(20);

   ci = 1196;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(7.0487,1e-07,7.0487,1e-08,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1197;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(6.5487,1e-07,7.5487,1e-07);

   ci = 1198;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(7.0487,1.21e-07,">5#sigma");
   tex->SetTextAlign(20);

   ci = 1199;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(10.1232,9.6986e-05,10.1232,2.0895e-06,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1197;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(9.6232,9.6986e-05,10.6232,9.6986e-05);

   ci = 1198;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(10.1232,0.0001173531,"95%");
   tex->SetTextAlign(20);

   ci = 1199;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(11.9039,0.000357619,11.9039,7.704668e-06,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1197;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(11.4039,0.000357619,12.4039,0.000357619);

   ci = 1198;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(11.9039,0.000432719,"95%");
   tex->SetTextAlign(20);

   ci = 1199;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(14.2404,0.00625448,14.2404,0.0001347487,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = 1197;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(13.7404,0.00625448,14.7404,0.00625448);

   ci = 1198;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(14.2404,0.007567921,"95%");
   tex->SetTextAlign(20);

   ci = 1199;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(15.6814,1e-07,15.6814,1e-08,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#ff0000");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(15.1814,1e-07,16.1814,1e-07);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(15.6814,1.21e-07,">99%");
   tex->SetTextAlign(20);

   ci = TColor::GetColor("#ff0000");
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(23.5278,1e-07,23.5278,1e-08,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#ff0000");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(23.0278,1e-07,24.0278,1e-07);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(23.5278,1.21e-07,"98.4%");
   tex->SetTextAlign(20);

   ci = TColor::GetColor("#ff0000");
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(33.2015,1e-07,33.2015,1e-08,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#ff0000");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(32.7015,1e-07,33.7015,1e-07);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(33.2015,1.21e-07,">99%");
   tex->SetTextAlign(20);

   ci = TColor::GetColor("#ff0000");
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   arrow = new TArrow(43.6099,0.0045738,43.6099,9.853953e-05,0.02,">");
   arrow->SetFillColor(19);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#ff0000");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   line = new TLine(43.1099,0.0045738,44.1099,0.0045738);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(43.6099,0.005534298,"95%");
   tex->SetTextAlign(20);

   ci = TColor::GetColor("#ff0000");
   tex->SetTextColor(ci);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t Graph1_fx3002[1] = {
   54.0776};
   Double_t Graph1_fy3002[1] = {
   0.038372};
   Double_t Graph1_felx3002[1] = {
   0};
   Double_t Graph1_fely3002[1] = {
   0.03749412};
   Double_t Graph1_fehx3002[1] = {
   0};
   Double_t Graph1_fehy3002[1] = {
   0.03749412};
   grae = new TGraphAsymmErrors(1,Graph1_fx3002,Graph1_fy3002,Graph1_felx3002,Graph1_fehx3002,Graph1_fely3002,Graph1_fehy3002);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph13002 = new TH1F("Graph_Graph13002","Graph",100,53.9776,55.1776);
   Graph_Graph13002->SetMinimum(0.0007900897);
   Graph_Graph13002->SetMaximum(0.08336495);
   Graph_Graph13002->SetDirectory(0);
   Graph_Graph13002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13002->SetLineColor(ci);
   Graph_Graph13002->GetXaxis()->SetLabelFont(42);
   Graph_Graph13002->GetXaxis()->SetTitleOffset(1);
   Graph_Graph13002->GetXaxis()->SetTitleFont(42);
   Graph_Graph13002->GetYaxis()->SetLabelFont(42);
   Graph_Graph13002->GetYaxis()->SetTitleFont(42);
   Graph_Graph13002->GetZaxis()->SetLabelFont(42);
   Graph_Graph13002->GetZaxis()->SetTitleOffset(1);
   Graph_Graph13002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph13002);
   
   grae->Draw("p ");
   
   TLegend *leg = new TLegend(0.2,0.67,0.625,0.89,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.036);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("legDummy_belle","BELLE, e^{+}e^{-} #sqrt{s}=10.52 GeV","l");

   ci = 1205;
   color = new TColor(ci, 0, 0.4, 1, " ", 0.5);
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("legDummy_aleph","ALEPH, e^{+}e^{-} #sqrt{s}=91.2 GeV","l");

   ci = 1206;
   color = new TColor(ci, 0, 0, 0.2, " ", 0.5);
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("legDummy_alice","ALICE, pp #sqrt{s}=13 TeV","l");

   ci = 1207;
   color = new TColor(ci, 1, 0.6, 0.2, " ", 0.5);
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("legDummy_lep2","ALEPH, e^{+}e^{-} #sqrt{s}=183-209 GeV","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *dummy_copy__4 = new TH1D("dummy_copy__4","",1,0,68);
   dummy_copy__4->SetMinimum(1e-08);
   dummy_copy__4->SetMaximum(100);
   dummy_copy__4->SetDirectory(0);
   dummy_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   dummy_copy__4->SetLineColor(ci);
   dummy_copy__4->GetXaxis()->SetTitle("#LT N_{trk}^{corr} #GT");
   dummy_copy__4->GetXaxis()->CenterTitle(true);
   dummy_copy__4->GetXaxis()->SetLabelFont(42);
   dummy_copy__4->GetXaxis()->SetLabelSize(0.04);
   dummy_copy__4->GetXaxis()->SetTitleSize(0.05);
   dummy_copy__4->GetXaxis()->SetTitleOffset(1.2);
   dummy_copy__4->GetXaxis()->SetTitleFont(42);
   dummy_copy__4->GetYaxis()->SetTitle("Associated yield");
   dummy_copy__4->GetYaxis()->CenterTitle(true);
   dummy_copy__4->GetYaxis()->SetLabelFont(42);
   dummy_copy__4->GetYaxis()->SetLabelSize(0.04);
   dummy_copy__4->GetYaxis()->SetTitleSize(0.05);
   dummy_copy__4->GetYaxis()->SetTitleOffset(1.4);
   dummy_copy__4->GetYaxis()->SetTitleFont(42);
   dummy_copy__4->GetZaxis()->SetLabelFont(42);
   dummy_copy__4->GetZaxis()->SetTitleOffset(1);
   dummy_copy__4->GetZaxis()->SetTitleFont(42);
   dummy_copy__4->Draw("sameaxis");
   canvB->Modified();
   canvB->cd();
   canvB->SetSelected(canvB);
}
