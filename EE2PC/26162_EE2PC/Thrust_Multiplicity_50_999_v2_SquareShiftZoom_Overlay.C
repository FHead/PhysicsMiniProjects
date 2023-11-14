void Thrust_Multiplicity_50_999_v2_SquareShiftZoom_Overlay()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Sep 19 10:23:38 2023) by ROOT version 6.24/06
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->SetHighLightColor(2);
   c1->Range(-0.7058824,-0.766208,6.352941,1.048922);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.07);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *HWorld__1 = new TH2D("HWorld__1","",100,0,6,100,-0.584695,0.9218625);
   HWorld__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   HWorld__1->SetLineColor(ci);
   HWorld__1->GetXaxis()->SetTitle("p_{T} (GeV)");
   HWorld__1->GetXaxis()->SetLabelFont(42);
   HWorld__1->GetXaxis()->SetTitleOffset(1.2);
   HWorld__1->GetXaxis()->SetTitleFont(42);
   HWorld__1->GetYaxis()->SetTitle("sign(#DeltaV_{2}) #sqrt{|#DeltaV_{2}|}");
   HWorld__1->GetYaxis()->SetLabelFont(42);
   HWorld__1->GetYaxis()->SetTitleOffset(1.2);
   HWorld__1->GetYaxis()->SetTitleFont(42);
   HWorld__1->GetZaxis()->SetLabelFont(42);
   HWorld__1->GetZaxis()->SetTitleOffset(1);
   HWorld__1->GetZaxis()->SetTitleFont(42);
   HWorld__1->Draw("");
   
   Double_t _fx1[2] = {
   0,
   6};
   Double_t _fy1[2] = {
   0,
   0};
   TGraph *graph = new TGraph(2,_fx1,_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0,6.6);
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
   
   Double_t _fx3001[11] = {
   0.296,
   0.494,
   0.694,
   0.895,
   1.18,
   1.58,
   1.98,
   2.46,
   3.14,
   4.02,
   5.17};
   Double_t _fy3001[11] = {
   0.0207,
   0.0303,
   0.0385,
   0.0468,
   0.0577,
   0.0695,
   0.0789,
   0.0845,
   0.0929,
   0.0867,
   0.0703};
   Double_t _felx3001[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fely3001[11] = {
   0.00205845,
   0.00301128,
   0.00383291,
   0.00465451,
   0.00574147,
   0.00691361,
   0.00784575,
   0.0115267,
   0.0126731,
   0.0170246,
   0.0260422};
   Double_t _fehx3001[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fehy3001[11] = {
   0.00205845,
   0.00301128,
   0.00383291,
   0.00465451,
   0.00574147,
   0.00691361,
   0.00784575,
   0.0115267,
   0.0126731,
   0.0170246,
   0.0260422};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(11,_fx3001,_fy3001,_felx3001,_fehx3001,_fely3001,_fehy3001);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1186;
   color = new TColor(ci, 0.2039216, 0.5960785, 0.8588235, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#3498db");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3498db");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","",100,0,5.7174);
   Graph_Graph3001->SetMinimum(0.009948395);
   Graph_Graph3001->SetMaximum(0.1142663);
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
   
   Double_t _fx3002[11] = {
   0.296,
   0.494,
   0.694,
   0.895,
   1.18,
   1.58,
   1.98,
   2.46,
   3.14,
   4.02,
   5.17};
   Double_t _fy3002[11] = {
   0.0207,
   0.0303,
   0.0385,
   0.0468,
   0.0577,
   0.0695,
   0.0789,
   0.0845,
   0.0929,
   0.0867,
   0.0703};
   Double_t _felx3002[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fely3002[11] = {
   0.000279175,
   0.000307433,
   0.00036263,
   0.000433623,
   0.000400655,
   0.000559635,
   0.000771996,
   0.000917843,
   0.00124438,
   0.00179962,
   0.00263416};
   Double_t _fehx3002[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fehy3002[11] = {
   0.000279175,
   0.000307433,
   0.00036263,
   0.000433623,
   0.000400655,
   0.000559635,
   0.000771996,
   0.000917843,
   0.00124438,
   0.00179962,
   0.00263416};
   grae = new TGraphAsymmErrors(11,_fx3002,_fy3002,_felx3002,_fehx3002,_fely3002,_fehy3002);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1185;
   color = new TColor(ci, 0.2039216, 0.5960785, 0.8588235, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#3498db");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3498db");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","",100,0,5.7174);
   Graph_Graph3002->SetMinimum(0.01304847);
   Graph_Graph3002->SetMaximum(0.1015167);
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
   
   Double_t _fx3003[11] = {
   0.297,
   0.494,
   0.694,
   0.894,
   1.18,
   1.58,
   1.98,
   2.46,
   3.14,
   4.02,
   5.17};
   Double_t _fy3003[11] = {
   0.02,
   0.0282,
   0.0344,
   0.0403,
   0.05,
   0.0631,
   0.0802,
   0.0756,
   0.0787,
   0.0659,
   0.0605};
   Double_t _felx3003[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fely3003[11] = {
   0.00199212,
   0.0028021,
   0.00342673,
   0.00401382,
   0.00497736,
   0.0062773,
   0.00798066,
   0.0103124,
   0.0107406,
   0.0129551,
   0.0223915};
   Double_t _fehx3003[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fehy3003[11] = {
   0.00199212,
   0.0028021,
   0.00342673,
   0.00401382,
   0.00497736,
   0.0062773,
   0.00798066,
   0.0103124,
   0.0107406,
   0.0129551,
   0.0223915};
   grae = new TGraphAsymmErrors(11,_fx3003,_fy3003,_felx3003,_fehx3003,_fely3003,_fehy3003);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1188;
   color = new TColor(ci, 0.1803922, 0.8, 0.4431373, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#2ecc71");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#2ecc71");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","",100,0,5.7173);
   Graph_Graph3003->SetMinimum(0.01086461);
   Graph_Graph3003->SetMaximum(0.09658387);
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
   
   Double_t _fx3004[11] = {
   0.297,
   0.494,
   0.694,
   0.894,
   1.18,
   1.58,
   1.98,
   2.46,
   3.14,
   4.02,
   5.17};
   Double_t _fy3004[11] = {
   0.02,
   0.0282,
   0.0344,
   0.0403,
   0.05,
   0.0631,
   0.0802,
   0.0756,
   0.0787,
   0.0659,
   0.0605};
   Double_t _felx3004[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fely3004[11] = {
   0.00074638,
   0.000775209,
   0.000941067,
   0.00112883,
   0.00104387,
   0.00146238,
   0.00205573,
   0.00244476,
   0.00333596,
   0.00492243,
   0.00727271};
   Double_t _fehx3004[11] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fehy3004[11] = {
   0.00074638,
   0.000775209,
   0.000941067,
   0.00112883,
   0.00104387,
   0.00146238,
   0.00205573,
   0.00244476,
   0.00333596,
   0.00492243,
   0.00727271};
   grae = new TGraphAsymmErrors(11,_fx3004,_fy3004,_felx3004,_fehx3004,_fely3004,_fehy3004);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1187;
   color = new TColor(ci, 0.1803922, 0.8, 0.4431373, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#2ecc71");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#2ecc71");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3004 = new TH1F("Graph_Graph3004","",100,0,5.7173);
   Graph_Graph3004->SetMinimum(0.01295341);
   Graph_Graph3004->SetMaximum(0.08855594);
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
   
   Double_t _fx3005[6] = {
   0.387,
   0.777,
   1.32,
   2.19,
   3.43,
   5.18};
   Double_t _fy3005[6] = {
   0.0252,
   0.038,
   0.0584,
   0.0706,
   0.0724,
   0.0348};
   Double_t _felx3005[6] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fely3005[6] = {
   0.00250496,
   0.00378509,
   0.00580458,
   0.00963763,
   0.0142317,
   0.0128724};
   Double_t _fehx3005[6] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fehy3005[6] = {
   0.00250496,
   0.00378509,
   0.00580458,
   0.00963763,
   0.0142317,
   0.0128724};
   grae = new TGraphAsymmErrors(6,_fx3005,_fy3005,_felx3005,_fehx3005,_fely3005,_fehy3005);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1190;
   color = new TColor(ci, 0.945098, 0.7686275, 0.05882353, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#f1c40f");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#f1c40f");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","",100,0,5.7193);
   Graph_Graph3005->SetMinimum(0.01545719);
   Graph_Graph3005->SetMaximum(0.09310211);
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
   
   Double_t _fx3006[6] = {
   0.387,
   0.777,
   1.32,
   2.19,
   3.43,
   5.18};
   Double_t _fy3006[6] = {
   0.0252,
   0.038,
   0.0584,
   0.0706,
   0.0724,
   0.0348};
   Double_t _felx3006[6] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fely3006[6] = {
   0.00122214,
   0.00148812,
   0.00172515,
   0.00305615,
   0.0056406,
   0.0130776};
   Double_t _fehx3006[6] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t _fehy3006[6] = {
   0.00122214,
   0.00148812,
   0.00172515,
   0.00305615,
   0.0056406,
   0.0130776};
   grae = new TGraphAsymmErrors(6,_fx3006,_fy3006,_felx3006,_fehx3006,_fely3006,_fehy3006);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1189;
   color = new TColor(ci, 0.945098, 0.7686275, 0.05882353, " ", 0.25);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);

   ci = TColor::GetColor("#f1c40f");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#f1c40f");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3006 = new TH1F("Graph_Graph3006","",100,0,5.7193);
   Graph_Graph3006->SetMinimum(0.01609058);
   Graph_Graph3006->SetMaximum(0.08367242);
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
   
   Double_t _fx3007[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3007[5] = {
   0.07624134,
   0.115049,
   0.1334407,
   0.1945589,
   0.3603987};
   Double_t _felx3007[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3007[5] = {
   0.0247188,
   0.01300342,
   0.02039434,
   0.02695878,
   0.04077509};
   Double_t _fehx3007[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3007[5] = {
   0.0247188,
   0.01300342,
   0.02039434,
   0.02695878,
   0.04077509};
   grae = new TGraphAsymmErrors(5,_fx3007,_fy3007,_felx3007,_fehx3007,_fely3007,_fehy3007);
   grae->SetName("");
   grae->SetTitle("");

   ci = 1191;
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
   
   TH1F *Graph_Graph3007 = new TH1F("Graph_Graph3007","",100,0,1098.9);
   Graph_Graph3007->SetMinimum(0.01655742);
   Graph_Graph3007->SetMaximum(0.4361389);
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
   
   grae->Draw("2");
   
   Double_t _fx3008[5] = {
   0.25,
   0.75,
   1.5,
   2.5,
   3.5};
   Double_t _fy3008[5] = {
   0.07624134,
   0.115049,
   0.1334407,
   0.1945589,
   0.3603987};
   Double_t _felx3008[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   0.5};
   Double_t _fely3008[5] = {
   0.1311226,
   0.0876609,
   0.1153631,
   0.5195026,
   0.07476548};
   Double_t _fehx3008[5] = {
   0.25,
   0.25,
   0.5,
   0.5,
   995.5};
   Double_t _fehy3008[5] = {
   0.1311226,
   0.0876609,
   0.1153631,
   0.5195026,
   0.07476548};
   grae = new TGraphAsymmErrors(5,_fx3008,_fy3008,_felx3008,_fehx3008,_fely3008,_fehy3008);
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
   
   TH1F *Graph_Graph3008 = new TH1F("Graph_Graph3008","",100,0,1098.9);
   Graph_Graph3008->SetMinimum(-0.4288442);
   Graph_Graph3008->SetMaximum(0.817962);
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
   
   grae->Draw("p");
   TArrow *arrow = new TArrow(5.9,0.3603987,6,0.3603987,0.015,"|>");

   ci = TColor::GetColor("#e74c3c");
   arrow->SetFillColor(ci);
   arrow->SetFillStyle(1001);

   ci = TColor::GetColor("#e74c3c");
   arrow->SetLineColor(ci);
   arrow->SetLineWidth(2);
   arrow->Draw();
   
   TLegend *leg = new TLegend(0.15,0.15,0.45,0.21,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("","Data - Archived MC","plf");

   ci = 1191;
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
   leg->Draw();
   
   leg = new TLegend(0.6,0.7,0.9,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("","CMS pp 13 TeV, v_{2}^{sub}{2}","plf");

   ci = 1186;
   color = new TColor(ci, 0.2039216, 0.5960785, 0.8588235, " ", 0.25);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#3498db");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#3498db");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","CMS pp 7 TeV, v_{2}^{sub}{2}","plf");

   ci = 1188;
   color = new TColor(ci, 0.1803922, 0.8, 0.4431373, " ", 0.25);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#2ecc71");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#2ecc71");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","CMS pp 5 TeV, v_{2}^{sub}{2}","plf");

   ci = 1190;
   color = new TColor(ci, 0.945098, 0.7686275, 0.05882353, " ", 0.25);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);

   ci = TColor::GetColor("#f1c40f");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#f1c40f");
   entry->SetMarkerColor(ci);
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
