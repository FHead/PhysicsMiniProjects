void Thrust_Multiplicity_0_999_v123_Zoom()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Sep 19 10:21:32 2023) by ROOT version 6.24/06
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->SetHighLightColor(2);
   c1->Range(-0.5294118,-0.9894201,4.764706,0.6786397);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.07);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *HWorld__1 = new TH2D("HWorld__1","",100,0,4.5,100,-0.8226141,0.5618755);
   HWorld__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   HWorld__1->SetLineColor(ci);
   HWorld__1->GetXaxis()->SetTitle("p_{T} (GeV)");
   HWorld__1->GetXaxis()->SetLabelFont(42);
   HWorld__1->GetXaxis()->SetTitleOffset(1.2);
   HWorld__1->GetXaxis()->SetTitleFont(42);
   HWorld__1->GetYaxis()->SetTitle("v_{n}");
   HWorld__1->GetYaxis()->SetLabelFont(42);
   HWorld__1->GetYaxis()->SetTitleOffset(1.2);
   HWorld__1->GetYaxis()->SetTitleFont(42);
   HWorld__1->GetZaxis()->SetLabelFont(42);
   HWorld__1->GetZaxis()->SetTitleOffset(1);
   HWorld__1->GetZaxis()->SetTitleFont(42);
   HWorld__1->Draw("");
   
   Double_t _fx1[2] = {
   0,
   4.5};
   Double_t _fy1[2] = {
   0,
   0};
   TGraph *graph = new TGraph(2,_fx1,_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0,4.95);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(1.1);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("l");
   
   Double_t _fx3001[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3001[5] = {
   -0.1426682,
   -0.3292146,
   -0.4024621,
   -0.3721218,
   -0.2812217};
   Double_t _felx3001[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3001[5] = {
   0.001897506,
   0.001677961,
   0.004805095,
   0.01045753,
   0.009718452};
   Double_t _fehx3001[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3001[5] = {
   0.001897506,
   0.001677961,
   0.004805095,
   0.01045753,
   0.009718452};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,_fx3001,_fy3001,_felx3001,_fehx3001,_fely3001,_fehy3001);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1185;
   color = new TColor(ci, 0.2470588, 0.2470588, 0.2470588, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#3f3f3f");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#3f3f3f");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","",100,0,1098.9);
   Graph_Graph3001->SetMinimum(-0.4339169);
   Graph_Graph3001->SetMaximum(-0.114121);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3001->SetLineColor(ci);
   Graph_Graph3001->GetXaxis()->SetLabelFont(42);
   Graph_Graph3001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3001->GetXaxis()->SetTitleFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelFont(42);
   Graph_Graph3001->GetYaxis()->SetTitleFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelFont(42);
   Graph_Graph3001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3001);
   
   grae->Draw("2");
   
   Double_t _fx3002[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3002[5] = {
   -0.1426682,
   -0.3292146,
   -0.4024621,
   -0.3721218,
   -0.2812217};
   Double_t _felx3002[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3002[5] = {
   0.005348629,
   0.003985844,
   0.004578772,
   0.01202519,
   0.01109017};
   Double_t _fehx3002[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3002[5] = {
   0.006017208,
   0.004311219,
   0.004578772,
   0.01226569,
   0.01004393};
   grae = new TGraphAsymmErrors(5,_fx3002,_fy3002,_felx3002,_fehx3002,_fely3002,_fehy3002);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#3f3f3f");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#3f3f3f");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","",100,0,1098.9);
   Graph_Graph3002->SetMinimum(-0.4340799);
   Graph_Graph3002->SetMaximum(-0.109612);
   Graph_Graph3002->SetDirectory(0);
   Graph_Graph3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3002->SetLineColor(ci);
   Graph_Graph3002->GetXaxis()->SetLabelFont(42);
   Graph_Graph3002->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3002->GetXaxis()->SetTitleFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelFont(42);
   Graph_Graph3002->GetYaxis()->SetTitleFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelFont(42);
   Graph_Graph3002->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3002);
   
   grae->Draw("p");
   TArrow *arrow = new TArrow(4.4,-0.2812217,4.5,-0.2812217,0.015,"|>");

   ci = TColor::GetColor("#3f3f3f");
   arrow->SetFillColor(ci);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#3f3f3f");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   
   Double_t _fx3003[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3003[5] = {
   0.0731583,
   0.1881469,
   0.2698613,
   0.2671436,
   0.122238};
   Double_t _felx3003[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3003[5] = {
   0.00636863,
   0.004348741,
   0.005070148,
   0.007336318,
   0.04381091};
   Double_t _fehx3003[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3003[5] = {
   0.00636863,
   0.004348741,
   0.005070148,
   0.007336318,
   0.04381091};
   grae = new TGraphAsymmErrors(5,_fx3003,_fy3003,_felx3003,_fehx3003,_fely3003,_fehy3003);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1186;
   color = new TColor(ci, 0.9058824, 0.2980392, 0.2352941, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#e74c3c");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#e74c3c");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","",100,0,1098.9);
   Graph_Graph3003->SetMinimum(0.04597549);
   Graph_Graph3003->SetMaximum(0.2957456);
   Graph_Graph3003->SetDirectory(0);
   Graph_Graph3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3003->SetLineColor(ci);
   Graph_Graph3003->GetXaxis()->SetLabelFont(42);
   Graph_Graph3003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3003->GetXaxis()->SetTitleFont(42);
   Graph_Graph3003->GetYaxis()->SetLabelFont(42);
   Graph_Graph3003->GetYaxis()->SetTitleFont(42);
   Graph_Graph3003->GetZaxis()->SetLabelFont(42);
   Graph_Graph3003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3003);
   
   grae->Draw("2");
   
   Double_t _fx3004[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3004[5] = {
   0.0731583,
   0.1881469,
   0.2698613,
   0.2671436,
   0.122238};
   Double_t _felx3004[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3004[5] = {
   0.01124659,
   0.00755551,
   0.006894784,
   0.01829483,
   0.02423917};
   Double_t _fehx3004[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3004[5] = {
   0.01124659,
   0.006842726,
   0.006894784,
   0.01558448,
   0.02529305};
   grae = new TGraphAsymmErrors(5,_fx3004,_fy3004,_felx3004,_fehx3004,_fely3004,_fehy3004);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#e74c3c");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#e74c3c");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3004 = new TH1F("Graph_Graph3004","",100,0,1098.9);
   Graph_Graph3004->SetMinimum(0.03983006);
   Graph_Graph3004->SetMaximum(0.3048098);
   Graph_Graph3004->SetDirectory(0);
   Graph_Graph3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3004->SetLineColor(ci);
   Graph_Graph3004->GetXaxis()->SetLabelFont(42);
   Graph_Graph3004->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3004->GetXaxis()->SetTitleFont(42);
   Graph_Graph3004->GetYaxis()->SetLabelFont(42);
   Graph_Graph3004->GetYaxis()->SetTitleFont(42);
   Graph_Graph3004->GetZaxis()->SetLabelFont(42);
   Graph_Graph3004->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3004);
   
   grae->Draw("p");
   arrow = new TArrow(4.4,0.122238,4.5,0.122238,0.015,"|>");

   ci = TColor::GetColor("#e74c3c");
   arrow->SetFillColor(ci);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#e74c3c");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   
   Double_t _fx3005[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3005[5] = {
   0.05156218,
   -0.1194772,
   -0.2313416,
   -0.2605144,
   -0.2295331};
   Double_t _felx3005[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3005[5] = {
   0.01236567,
   0.009781393,
   0.008019778,
   0.01207975,
   0.005439678};
   Double_t _fehx3005[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3005[5] = {
   0.01236567,
   0.009781393,
   0.008019778,
   0.01207975,
   0.005439678};
   grae = new TGraphAsymmErrors(5,_fx3005,_fy3005,_felx3005,_fehx3005,_fely3005,_fehy3005);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1187;
   color = new TColor(ci, 0.5568628, 0.2666667, 0.6784314, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#8e44ad");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#8e44ad");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","",100,0,1098.9);
   Graph_Graph3005->SetMinimum(-0.3062463);
   Graph_Graph3005->SetMaximum(0.09758005);
   Graph_Graph3005->SetDirectory(0);
   Graph_Graph3005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3005->SetLineColor(ci);
   Graph_Graph3005->GetXaxis()->SetLabelFont(42);
   Graph_Graph3005->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3005->GetXaxis()->SetTitleFont(42);
   Graph_Graph3005->GetYaxis()->SetLabelFont(42);
   Graph_Graph3005->GetYaxis()->SetTitleFont(42);
   Graph_Graph3005->GetZaxis()->SetLabelFont(42);
   Graph_Graph3005->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3005);
   
   grae->Draw("2");
   
   Double_t _fx3006[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3006[5] = {
   0.05156218,
   -0.1194772,
   -0.2313416,
   -0.2605144,
   -0.2295331};
   Double_t _felx3006[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3006[5] = {
   0.01632062,
   0.01355151,
   0.007586386,
   0.01492439,
   0.01635207};
   Double_t _fehx3006[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3006[5] = {
   0.04151115,
   0.01079527,
   0.008850784,
   0.0268639,
   0.01193961};
   grae = new TGraphAsymmErrors(5,_fx3006,_fy3006,_felx3006,_fehx3006,_fely3006,_fehy3006);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#8e44ad");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#8e44ad");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3006 = new TH1F("Graph_Graph3006","",100,0,1098.9);
   Graph_Graph3006->SetMinimum(-0.31229);
   Graph_Graph3006->SetMaximum(0.1299245);
   Graph_Graph3006->SetDirectory(0);
   Graph_Graph3006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3006->SetLineColor(ci);
   Graph_Graph3006->GetXaxis()->SetLabelFont(42);
   Graph_Graph3006->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3006->GetXaxis()->SetTitleFont(42);
   Graph_Graph3006->GetYaxis()->SetLabelFont(42);
   Graph_Graph3006->GetYaxis()->SetTitleFont(42);
   Graph_Graph3006->GetZaxis()->SetLabelFont(42);
   Graph_Graph3006->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3006);
   
   grae->Draw("p");
   arrow = new TArrow(4.4,-0.2295331,4.5,-0.2295331,0.015,"|>");

   ci = TColor::GetColor("#8e44ad");
   arrow->SetFillColor(ci);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#8e44ad");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   
   Double_t _fx3007[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3007[5] = {
   -0.1368688,
   -0.3203937,
   -0.4037914,
   -0.3643424,
   -0.2815802};
   Double_t _felx3007[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3007[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehx3007[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3007[5] = {
   0,
   0,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(5,_fx3007,_fy3007,_felx3007,_fehx3007,_fely3007,_fehy3007);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#3f3f3f");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#3f3f3f");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3007 = new TH1F("Graph_Graph3007","",100,0,3.825);
   Graph_Graph3007->SetMinimum(-0.4304837);
   Graph_Graph3007->SetMaximum(-0.1101765);
   Graph_Graph3007->SetDirectory(0);
   Graph_Graph3007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3007->SetLineColor(ci);
   Graph_Graph3007->GetXaxis()->SetLabelFont(42);
   Graph_Graph3007->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3007->GetXaxis()->SetTitleFont(42);
   Graph_Graph3007->GetYaxis()->SetLabelFont(42);
   Graph_Graph3007->GetYaxis()->SetTitleFont(42);
   Graph_Graph3007->GetZaxis()->SetLabelFont(42);
   Graph_Graph3007->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3007);
   
   grae->Draw("l");
   
   Double_t _fx3008[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3008[5] = {
   0.0778816,
   0.2006146,
   0.2849776,
   0.2389061,
   -0.125232};
   Double_t _felx3008[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3008[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehx3008[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3008[5] = {
   0,
   0,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(5,_fx3008,_fy3008,_felx3008,_fehx3008,_fely3008,_fehy3008);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#e74c3c");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#e74c3c");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3008 = new TH1F("Graph_Graph3008","",100,0,3.825);
   Graph_Graph3008->SetMinimum(-0.166253);
   Graph_Graph3008->SetMaximum(0.3259986);
   Graph_Graph3008->SetDirectory(0);
   Graph_Graph3008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3008->SetLineColor(ci);
   Graph_Graph3008->GetXaxis()->SetLabelFont(42);
   Graph_Graph3008->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3008->GetXaxis()->SetTitleFont(42);
   Graph_Graph3008->GetYaxis()->SetLabelFont(42);
   Graph_Graph3008->GetYaxis()->SetTitleFont(42);
   Graph_Graph3008->GetZaxis()->SetLabelFont(42);
   Graph_Graph3008->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3008);
   
   grae->Draw("l");
   
   Double_t _fx3009[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3009[5] = {
   -0.02331463,
   -0.1070608,
   -0.2264212,
   -0.2560297,
   -0.2230669};
   Double_t _felx3009[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3009[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehx3009[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3009[5] = {
   0,
   0,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(5,_fx3009,_fy3009,_felx3009,_fehx3009,_fely3009,_fehy3009);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#8e44ad");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#8e44ad");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(1.25);
   
   TH1F *Graph_Graph3009 = new TH1F("Graph_Graph3009","",100,0,3.825);
   Graph_Graph3009->SetMinimum(-0.2793012);
   Graph_Graph3009->SetMaximum(-4.312407e-05);
   Graph_Graph3009->SetDirectory(0);
   Graph_Graph3009->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3009->SetLineColor(ci);
   Graph_Graph3009->GetXaxis()->SetLabelFont(42);
   Graph_Graph3009->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3009->GetXaxis()->SetTitleFont(42);
   Graph_Graph3009->GetYaxis()->SetLabelFont(42);
   Graph_Graph3009->GetYaxis()->SetTitleFont(42);
   Graph_Graph3009->GetZaxis()->SetLabelFont(42);
   Graph_Graph3009->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3009->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3009);
   
   grae->Draw("l");
   
   TLegend *leg = new TLegend(0.14,0.14,0.44,0.38,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("","Data v_{1}","plf");

   ci = 1185;
   color = new TColor(ci, 0.2470588, 0.2470588, 0.2470588, " ", 0.25);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#3f3f3f");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#3f3f3f");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.25);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","v_{2}","plf");

   ci = 1186;
   color = new TColor(ci, 0.9058824, 0.2980392, 0.2352941, " ", 0.25);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#e74c3c");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#e74c3c");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.25);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","v_{3}","plf");

   ci = 1187;
   color = new TColor(ci, 0.5568628, 0.2666667, 0.6784314, " ", 0.25);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#8e44ad");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#8e44ad");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.25);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Archived MC","l");

   ci = TColor::GetColor("#3f3f3f");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.15,0.86,"#font[52]{Preliminary}");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.81,"N_{track} #geq 0");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.76,"Thrust axis");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.11,0.955,"Archived ALEPH data");
tex->SetNDC();
   tex->SetTextAlign(12);
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.95,0.955,"LEP2, #sqrt{s} = 183-209 GeV");
tex->SetNDC();
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
