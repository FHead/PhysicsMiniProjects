void Thrust_Multiplicity_50_999_v123_Zoom()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Sep 19 10:23:25 2023) by ROOT version 6.24/06
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->SetHighLightColor(2);
   c1->Range(-0.5294118,-1.548312,4.764706,1.778336);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.07);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *HWorld__1 = new TH2D("HWorld__1","",100,0,4.5,100,-1.215647,1.545471);
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
   -0.1252018,
   -0.180923,
   -0.2324071,
   -0.2024052,
   0.4165397};
   Double_t _felx3001[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3001[5] = {
   0.009347487,
   0.02633142,
   0.01204745,
   0.04862894,
   0.0212875};
   Double_t _fehx3001[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3001[5] = {
   0.009347487,
   0.02633142,
   0.01204745,
   0.04862894,
   0.0212875};
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
   Graph_Graph3001->SetMinimum(-0.3199203);
   Graph_Graph3001->SetMaximum(0.5067133);
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
   -0.1252018,
   -0.180923,
   -0.2324071,
   -0.2024052,
   0.4165397};
   Double_t _felx3002[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3002[5] = {
   0.04505744,
   0.04217007,
   0.03853014,
   0.1849064,
   0.05448856};
   Double_t _fehx3002[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3002[5] = {
   0.0398585,
   0.03892622,
   0.04324812,
   0.2664827,
   0.1374059};
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
   Graph_Graph3002->SetMinimum(-0.4814373);
   Graph_Graph3002->SetMaximum(0.6480714);
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
   TArrow *arrow = new TArrow(4.4,0.4165397,4.5,0.4165397,0.015,"|>");

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
   0.09760643,
   0.1566242,
   0.1791154,
   0.2194505,
   0.3516955};
   Double_t _felx3003[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3003[5] = {
   0.01506395,
   0.009338129,
   0.01456453,
   0.02337947,
   0.04107704};
   Double_t _fehx3003[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3003[5] = {
   0.01506395,
   0.009338129,
   0.01456453,
   0.02337947,
   0.04107704};
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
   Graph_Graph3003->SetMinimum(0.05151947);
   Graph_Graph3003->SetMaximum(0.4237956);
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
   0.09760643,
   0.1566242,
   0.1791154,
   0.2194505,
   0.3516955};
   Double_t _felx3004[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3004[5] = {
   0.1298463,
   0.04652028,
   0.05637669,
   0.1667665,
   0.06650644};
   Double_t _fehx3004[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3004[5] = {
   0.1141074,
   0.04378379,
   0.06088682,
   0.7737967,
   0.06821173};
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
   Graph_Graph3004->SetMinimum(-0.1347886);
   Graph_Graph3004->SetMaximum(1.095796);
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
   arrow = new TArrow(4.4,0.3516955,4.5,0.3516955,0.015,"|>");

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
   -0.1194769,
   -0.1319083,
   -0.2210093,
   -0.175471,
   0.3263011};
   Double_t _felx3005[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3005[5] = {
   0.009705665,
   0.02580737,
   0.01097091,
   0.07215785,
   0.0578032};
   Double_t _fehx3005[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3005[5] = {
   0.009705665,
   0.02580737,
   0.01097091,
   0.07215785,
   0.0578032};
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
   Graph_Graph3005->SetMinimum(-0.3108021);
   Graph_Graph3005->SetMaximum(0.4472776);
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
   -0.1194769,
   -0.1319083,
   -0.2210093,
   -0.175471,
   0.3263011};
   Double_t _felx3006[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3006[5] = {
   0.05074918,
   0.04924454,
   0.04552031,
   0.185938,
   0.0779785};
   Double_t _fehx3006[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3006[5] = {
   0.04199932,
   0.06379407,
   0.04637918,
   0.2885245,
   0.06421759};
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
   Graph_Graph3006->SetMinimum(-0.4366017);
   Graph_Graph3006->SetMaximum(0.4657115);
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
   arrow = new TArrow(4.4,0.3263011,4.5,0.3263011,0.015,"|>");

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
   -0.09020667,
   -0.1767875,
   -0.1782805,
   -0.1375555,
   0.1522629};
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
   Graph_Graph3007->SetMinimum(-0.2113349);
   Graph_Graph3007->SetMaximum(0.1853173);
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
   0.06094483,
   0.1062773,
   0.1194818,
   0.1015154,
   -0.07872402};
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
   Graph_Graph3008->SetMinimum(-0.09854461);
   Graph_Graph3008->SetMaximum(0.1393024);
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
   -0.02846083,
   -0.04444097,
   -0.07211477,
   -0.08888259,
   -0.08083541};
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
   Graph_Graph3009->SetMinimum(-0.09492477);
   Graph_Graph3009->SetMaximum(-0.02241866);
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
      tex = new TLatex(0.15,0.81,"N_{track} #geq 50");
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
