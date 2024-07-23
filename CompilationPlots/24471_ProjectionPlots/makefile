
default: MakePhotonJetPlot MakeZJetPlot

ProcessJetRAA:
	python3 convert.py Fragments/ALICEJetRAA2020-33-1.json ALICEJetRAA2020-33-1
	DHSet Data.dh temp.config
	python3 convert.py Fragments/ATLASJetRAA2018-19-1.json ATLASJetRAA2018-19-1
	DHSet Data.dh temp.config
	python3 convert.py Fragments/CMSJetRAA2016-8a-3.json CMSJetRAA2016-8a-3
	DHSet Data.dh temp.config
	python3 convert.py Fragments/CMSJetRAA2020-2-0.json CMSJetRAA2020-2-0
	DHSet Data.dh temp.config

ProcessJetRRAA:
	python3 ParseYAML.py --HEPDataID 1848440 --TableVersion 1 --TableNumber "Figure%208-5" \
		--FileNumber 85 --FileNameBase CMSJetRAA2020 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2020" --Object Jet
	python3 Convert.py Fragments/CMSJetRAA2020-85-1.json CMSJetRAA2020-85-1
	DHSet Data.dh temp.config

ProcessZG:
	python3 ParseYAML.py --HEPDataID 1620905 --TableVersion 1 --TableNumber "6" --FileNameBase CMSZG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 Convert.py Fragments/CMSZG2018-6-1.json CMSZG2018-6-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSZG2018-6-2.json CMSZG2018-6-2
	DHSet Data.dh temp.config

ProcessZGRatio:
	python3 ParseYAML.py --HEPDataID 1620905 --TableVersion 1 --TableNumber 11 --FileNameBase CMSZG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 ParseYAML.py --HEPDataID 1620905 --TableVersion 1 --TableNumber 12 --FileNameBase CMSZG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 ParseYAML.py --HEPDataID 1620905 --TableVersion 1 --TableNumber 15 --FileNameBase CMSZG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 ParseYAML.py --HEPDataID 1620905 --TableVersion 1 --TableNumber 16 --FileNameBase CMSZG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 Convert.py Fragments/CMSZG2018-11-1.json CMSZG2018-11-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSZG2018-12-1.json CMSZG2018-12-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSZG2018-15-1.json CMSZG2018-15-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSZG2018-16-1.json CMSZG2018-16-1
	DHSet Data.dh temp.config

ProcessMGE:
	python3 ParseYAML.py --HEPDataID 1672962 --TableVersion 1 --TableNumber "Figure%203a" \
		--FileNumber 3a --FileNameBase CMSMG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 ParseYAML.py --HEPDataID 1672962 --TableVersion 1 --TableNumber "Figure%204a" \
		--FileNumber 4a --FileNameBase CMSMG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 ParseYAML.py --HEPDataID 1672962 --TableVersion 1 --TableNumber "Figure%205a" \
		--FileNumber 5a --FileNameBase CMSMG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 ParseYAML.py --HEPDataID 1672962 --TableVersion 1 --TableNumber "Figure%206a" \
		--FileNumber 6a --FileNameBase CMSMG2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR4
	python3 Convert.py Fragments/CMSMG2018-3a-1.json CMSMG2018-3a-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSMG2018-3a-2.json CMSMG2018-3a-2
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSMG2018-4a-1.json CMSMG2018-4a-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSMG2018-4a-2.json CMSMG2018-4a-2
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSMG2018-5a-1.json CMSMG2018-5a-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSMG2018-5a-2.json CMSMG2018-5a-2
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSMG2018-6a-1.json CMSMG2018-6a-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSMG2018-6a-2.json CMSMG2018-6a-2
	DHSet Data.dh temp.config

ProcessJetShape:
	python3 ParseYAML.py --HEPDataID 1695278 --TableVersion 1 --TableNumber 1 --FileNameBase CMSJetShape2019 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2019" --Object JetR3
	python3 ParseYAML.py --HEPDataID 1695278 --TableVersion 1 --TableNumber 5 --FileNameBase CMSJetShape2019 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2019" --Object JetR3
	python3 Convert.py Fragments/CMSJetShape2019-1-1.json CMSJetShape2019-1-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSJetShape2019-5-1.json CMSJetShape2019-5-1
	DHSet Data.dh temp.config

ProcessFragmentation:
	python3 ParseYAML.py --HEPDataID 1648162 --TableVersion 1 --TableNumber 4 --FileNameBase CMSFragmentation2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR3
	python3 ParseYAML.py --HEPDataID 1648162 --TableVersion 1 --TableNumber 12 --FileNameBase CMSFragmentation2018 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2018" --Object JetR3
	python3 Convert.py Fragments/CMSFragmentation2018-4-1.json CMSFragmentation2018-4-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSFragmentation2018-4-2.json CMSFragmentation2018-4-2
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSFragmentation2018-12-1.json CMSFragmentation2018-12-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSFragmentation2018-12-2.json CMSFragmentation2018-12-2
	DHSet Data.dh temp.config

ProcessPhotonJet:
	python3 ParseYAML.py --HEPDataID 1638996 --TableVersion 1 --TableNumber 3 --FileNameBase CMSPhotonJet2017 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2017" --Object JetR3
	python3 Convert.py Fragments/CMSPhotonJet2017-3-1.json CMSPhotonJet2017-3-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhotonJet2017-3-3.json CMSPhotonJet2017-3-3
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhotonJet2017-3-5.json CMSPhotonJet2017-3-5
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhotonJet2017-3-7.json CMSPhotonJet2017-3-7
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhotonJet2017-3-9.json CMSPhotonJet2017-3-9
	DHSet Data.dh temp.config

ProcessZJet:
	python3 ParseYAML.py --HEPDataID 1512112 --TableVersion 1 --TableNumber 3 --FileNameBase CMSZJet2017 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2017" --Object JetR3
	python3 ParseYAML.py --HEPDataID 1512112 --TableVersion 1 --TableNumber 4 --FileNameBase CMSZJet2017 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2017" --Object JetR3
	python3 Convert.py Fragments/CMSZJet2017-3-1.json CMSZJet2017-3-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSZJet2017-4-1.json CMSZJet2017-4-1
	DHSet Data.dh temp.config

ProcessPhoton:
	python3 ParseYAML.py --HEPDataID 1788620 --TableVersion 1 --TableNumber "Figure%206" \
		--FileNumber 6 --FileNameBase CMSPhoton2020 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2020" --Object Photon
	python3 ParseYAML.py --HEPDataID 1788620 --TableVersion 1 --TableNumber "Figure%205" \
		--FileNumber 5 --FileNameBase CMSPhoton2020 \
		--System PbPb --Energy "5.02 TeV" --Record "CMS 2020" --Object Photon
	python3 Convert.py Fragments/CMSPhoton2020-6-1.json CMSPhoton2020-6-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhoton2020-5-1.json CMSPhoton2020-5-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhoton2020-5-2.json CMSPhoton2020-5-2
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhoton2020-5-3.json CMSPhoton2020-5-3
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/CMSPhoton2020-5-4.json CMSPhoton2020-5-4
	DHSet Data.dh temp.config

ProcessParticle:
	python3 ParseYAML.py --HEPDataID 1276299 --TableVersion 1 --TableNumber 1 --FileNameBase ALICEParticle2014 \
		--System PbPb --Energy "2.76 TeV" --Record "ALICE 2014" --Object Pion
	python3 ParseYAML.py --HEPDataID 1276299 --TableVersion 1 --TableNumber 2 --FileNameBase ALICEParticle2014 \
		--System PbPb --Energy "2.76 TeV" --Record "ALICE 2014" --Object Kaon
	python3 ParseYAML.py --HEPDataID 1276299 --TableVersion 1 --TableNumber 3 --FileNameBase ALICEParticle2014 \
		--System PbPb --Energy "2.76 TeV" --Record "ALICE 2014" --Object Proton
	python3 Convert.py Fragments/ALICEParticle2014-1-1.json ALICEParticle2014-1-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/ALICEParticle2014-1-3.json ALICEParticle2014-1-3
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/ALICEParticle2014-2-1.json ALICEParticle2014-2-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/ALICEParticle2014-2-3.json ALICEParticle2014-2-3
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/ALICEParticle2014-3-1.json ALICEParticle2014-3-1
	DHSet Data.dh temp.config
	python3 Convert.py Fragments/ALICEParticle2014-3-3.json ALICEParticle2014-3-3
	DHSet Data.dh temp.config

MakeJetRAAPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSJetRAA2020-2-0,CMSJetRAA2016-8a-3,ALICEJetRAA2020-33-1,ATLASJetRAA2018-19-1 \
		--Labels "CMS 5.02 TeV 0-10%","CMS 2.76 TeV 0-5%","ALICE 5.02 TeV 0-10%","ATLAS 5.02 TeV 0-10%" \
		--Output MeowJetRAA.pdf \
		--XMin 50 --XMax 1200 --YMin 0 --YMax 1.05 --LogX true \
		--LegendX 0.52 --LegendY 0.18 --LegendW 0.20 --LegendH 0.25 \
		--Texts 0.15,0.8,"Inclusive anti-k_{T} jet R = 0.4",0.15,0.75,"PbPb Collisions" \
		--XLabel "Jet p_{T} (GeV)" --YLabel "R_{AA} = QGP / No QGP" --Wide true

MakeJetRRAAPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSJetRAA2020-85-1 \
		--Labels "CMS" \
		--Output MeowJetRRAA.pdf \
		--XMin 0.15 --XMax 1.1 --YMin 0 --YMax 2 --DXOverride 0.05 \
		--LegendX 0.5 --LegendY 0.3 --LegendW 0.25 --LegendH 0.06 \
		--Texts 0.25,0.8,"Inclusive anti-k_{T} jet R = 0.2-1.0",0.25,0.755,"PbPb Collisions 0-10%",0.25,0.70,"Jet p_{T} = 500-1000 GeV" \
		--XLabel "Jet R" --YLabel "Ratio of suppression to R = 0.2"

MakeZGPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSZG2018-6-1,CMSZG2018-6-2 \
		--Labels "Smeared pp","PbPb 0-10%" \
		--Output MeowJetZG.pdf \
		--XMin 0.1 --XMax 0.5 --YMin 0.2 --YMax 35 --LogY true \
		--LegendX 0.20 --LegendY 0.20 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.45,0.78,"Inclusive anti-k_{T} jet R = 0.4",0.45,0.83,"CMS",0.45,0.73,"SoftDrop z_{cut} = 0.1 #beta = 0.0",0.45,0.68,"Jet p_{T} = 160-180 GeV",0.45,0.63,"#Delta R > 0.1" \
		--XLabel "Jet z_{G}" --YLabel "1/N_{jet} dN/dz_{G}"
	./Execute --DHFile Data.dh \
		--States CMSZG2018-6-1,CMSZG2018-6-2 \
		--Labels "Reference","PbPb 0-10%" \
		--Output MeowJetZGSimplified.pdf \
		--XMin 0.1 --XMax 0.5 --YMin 0.2 --YMax 35 --LogY true \
		--LegendX 0.20 --LegendY 0.20 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.45,0.78,"Inclusive anti-k_{T} jet R = 0.4",0.45,0.83,"CMS",0.45,0.73,"SoftDrop z_{cut} = 0.1 #beta = 0.0",0.45,0.68,"Jet p_{T} = 160-180 GeV",0.45,0.63,"#Delta R > 0.1" \
		--XLabel "Momentum Balance z_{g}" --YLabel "Normalized shape"

MakeZGRatioPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSZG2018-11-1,CMSZG2018-12-1,CMSZG2018-15-1 \
		--Labels "140-160 GeV","160-180 GeV","200-300 GeV" \
		--Output MeowJetZGRatio.pdf \
		--XMin 0.1 --XMax 0.5 --YMin 0.5 --YMax 1.5 \
		--LegendX 0.20 --LegendY 0.20 --LegendW 0.25 --LegendH 0.18 \
		--Texts 0.45,0.78,"Inclusive anti-k_{T} jet R = 0.4",0.45,0.83,"CMS PbPb 0-10%",0.45,0.73,"SoftDrop z_{cut} = 0.1 #beta = 0.0",0.45,0.63,"#Delta R > 0.1" \
		--XLabel "Jet z_{G}" --YLabel "1/N_{jet} dN/dz_{G}"

MakeMGPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSMG2018-5a-2,CMSMG2018-5a-1 \
		--Labels "Reference","PbPb 0-10%" \
		--Output MeowJetMG.pdf \
		--XMin 0.0 --XMax 0.3 --YMin 0.2 --YMax 15 \
		--LegendX 0.55 --LegendY 0.6 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.20,0.79,"Inclusive anti-k_{T} jet R = 0.4",0.20,0.84,"CMS",0.20,0.74,"SoftDrop z_{cut} = 0.1 #beta = 0.0",0.20,0.69,"Jet p_{T} = 140-160 GeV",0.20,0.634"#Delta R > 0.1" \
		--XLabel "Jet M_{G}/p_{T}" --YLabel "Normalized shape"
	./Execute --DHFile Data.dh \
		--States CMSMG2018-6a-2,CMSMG2018-6a-1 \
		--Labels "Reference","PbPb 0-10%" \
		--Output MeowJetMG2.pdf \
		--XMin 0.0 --XMax 0.3 --YMin 0.2 --YMax 22 \
		--LegendX 0.5 --LegendY 0.4 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.45,0.78,"Inclusive anti-k_{T} jet R = 0.4",0.45,0.83,"CMS",0.45,0.73,"SoftDrop z_{cut} = 0.5 #beta = 1.5",0.45,0.68,"Jet p_{T} = 140-160 GeV",0.45,0.63,"#Delta R > 0.1" \
		--XLabel "Jet M_{G}/p_{T}" --YLabel "Normalized shape"

MakeJetShapePlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSJetShape2019-1-1,CMSJetShape2019-5-1 \
		--Labels "Reference","PbPb 0-10%" \
		--Output MeowJetShape.pdf \
		--XMin 0.0 --XMax 0.3 --YMin 0.2 --YMax 20 --LogY true \
		--LegendX 0.25 --LegendY 0.2 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.45,0.78,"Photon-tagged jet R = 0.3",0.45,0.83,"CMS",0.45,0.73,"Photon |#eta| < 1.44 p_{T} > 60 GeV",0.45,0.68,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.45,0.63,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "Distance from jet center (r)" --YLabel "Momentum density #rho(r)"
	./Execute --DHFile Data.dh \
		--States CMSJetShape2019-1-1,CMSJetShape2019-5-1 \
		--Labels "Reference","PbPb 0-10%" \
		--Output MeowJetShapeLinear.pdf \
		--XMin 0.0 --XMax 0.3 --YMin 0 --YMax 12 \
		--LegendX 0.50 --LegendY 0.4 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.45,0.78,"Photon-tagged jet R = 0.3",0.45,0.83,"CMS",0.45,0.73,"Photon |#eta| < 1.44 p_{T} > 60 GeV",0.45,0.68,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.45,0.63,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "Distance from jet center (r)" --YLabel "Momentum density #rho(r)"

MakeFragmentationPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSFragmentation2018-12-1,CMSFragmentation2018-12-2 \
		--Labels "Reference","PbPb 0-10%" \
		--Output MeowFragmentation.pdf \
		--XMin 0.0 --XMax 5.0 --YMin 0.08 --YMax 12 --LogY true \
		--LegendX 0.45 --LegendY 0.25 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.20,0.78,"Photon-tagged jet R = 0.3",0.20,0.83,"CMS",0.20,0.73,"Photon |#eta| < 1.44 p_{T} > 60 GeV",0.20,0.68,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.20,0.63,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "#xi_{T} = -ln(#color[51]{Projected p_{T}} / #color[8]{Photon p_{T}})" --YLabel "Normalized shape"
	./Execute --DHFile Data.dh \
		--States CMSFragmentation2018-4-1,CMSFragmentation2018-4-2 \
		--Labels "Reference","PbPb 0-10%" \
		--Output MeowFragmentationJet.pdf \
		--XMin 0.0 --XMax 5.0 --YMin 0.15 --YMax 15 --LogY true \
		--LegendX 0.45 --LegendY 0.25 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.20,0.78,"Photon-tagged jet R = 0.3",0.20,0.83,"CMS",0.20,0.73,"Photon |#eta| < 1.44 p_{T} > 60 GeV",0.20,0.68,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.20,0.63,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "#xi = -ln(#color[51]{Projected p} / #color[8]{Jet p})" --YLabel "Normalized shape"
	./Execute --DHFile Data.dh \
		--States CMSFragmentation2018-4-2,CMSFragmentation2018-4-2 \
		--StatScale 1,0.225 \
		--SysScale 1,0 \
		--Labels "404 #mub^{-1}","8 nb^{-1} (stat)" \
		--Output FragmentationJetProjection.pdf \
		--XMin 0.0 --XMax 5.0 --YMin 0.15 --YMax 15 --LogY true \
		--LegendX 0.45 --LegendY 0.25 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.20,0.78,"Photon-tagged jet R = 0.3",0.20,0.83,"CMS PbPb 0-10%",0.20,0.73,"Photon |#eta| < 1.44 p_{T} > 60 GeV",0.20,0.68,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.20,0.63,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "#xi = -ln(#color[51]{Projected p} / #color[8]{Jet p})" --YLabel "Normalized shape"

MakeZJetPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSZJet2017-3-1,CMSZJet2017-4-1 \
		--Labels "Smeared pp","PbPb 0-30%" \
		--Output MeowZJet.pdf \
		--XMin 0.0 --XMax 2.0 --YMin 0.0 --YMax 1.4 --DXOverride 0.1 \
		--LegendX 0.55 --LegendY 0.48 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.52,0.79,"Z-tagged jet R = 0.3",0.52,0.84,"CMS",0.52,0.74,"Z p_{T} > 60 GeV",0.52,0.69,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.52,0.64,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "Jet p_{T} / Z p_{T}" --YLabel "1/N_{Z} dN_{pair}/d(Jet p_{T} / Z p_{T})"
	./Execute --DHFile Data.dh \
		--States CMSZJet2017-3-1,CMSZJet2017-4-1 \
		--Labels "Reference","PbPb" \
		--Output MeowZJetSimplified.pdf \
		--XMin 0.0 --XMax 2.0 --YMin 0.0 --YMax 1.4 --DXOverride 0.1 \
		--LegendX 0.6 --LegendY 0.48 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.52,0.79,"Z-tagged jet R = 0.3",0.52,0.84,"CMS",0.52,0.74,"Z p_{T} > 60 GeV",0.52,0.69,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.52,0.64,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "Jet p_{T} / Z p_{T}" --YLabel "Normalized shape"
	./Execute --DHFile Data.dh \
		--States CMSZJet2017-4-1,CMSZJet2017-4-1 \
		--Labels "404 #mub^{-1}","8 nb^{-1} (stat)" \
		--StatScale 1,0.223 \
		--SysScale 1,0.0 \
		--XShift -0.2,0.2 \
		--Output ZJetProjection.pdf \
		--XMin 0.0 --XMax 2.0 --YMin 0.0 --YMax 1.4 --DXOverride 0.1 \
		--LegendX 0.55 --LegendY 0.48 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.52,0.84,"Z-tagged jet R = 0.3",0.52,0.79,"Z p_{T} > 60 GeV",0.52,0.74,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.52,0.69,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "Jet p_{T} / Z p_{T}" --YLabel "1/N_{Z} dN_{pair}/d(Jet p_{T} / Z p_{T})"

MakePhotonJetPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSPhotonJet2017-3-5,CMSPhotonJet2017-3-5 \
		--Labels "404 #mub^{-1}","8 nb^{-1} (stat)" \
		--StatScale 1,0.223 \
		--SysScale 1,0.0 \
		--Output PhotonJetProjection.pdf \
		--XMin 0.0 --XMax 2.0 --YMin 0.0 --YMax 1.4 --DXOverride 0.1 \
		--LegendX 0.55 --LegendY 0.48 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.47,0.79,"#gamma-tagged jet R = 0.3",0.47,0.84,"CMS PbPb 0-30%",0.47,0.74,"#gamma p_{T} = 60-80 GeV |#eta| < 1.44",0.47,0.69,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.47,0.64,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "Jet p_{T} / #gamma p_{T}" --YLabel "1/N_{#gamma} dN_{pair}/d(Jet p_{T} / #gamma p_{T})"
	./Execute --DHFile Data.dh \
		--States CMSPhotonJet2017-3-9,CMSPhotonJet2017-3-9 \
		--Labels "404 #mub^{-1}","8 nb^{-1} (stat)" \
		--StatScale 1,0.223 \
		--SysScale 1,0.0 \
		--XShift -0.3,0.3 \
		--Output PhotonJetProjection2.pdf \
		--XMin 0.0 --XMax 2.0 --YMin 0.0 --YMax 1.4 --DXOverride 0.1 \
		--LegendX 0.55 --LegendY 0.48 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.52,0.84,"#gamma-tagged jet R = 0.3",0.52,0.79,"#gamma p_{T} > 100 GeV |#eta| < 1.44",0.52,0.74,"Jet p_{T} > 30 GeV |#eta| < 1.6",0.52,0.69,"#Delta#phi > #frac{7}{8}#pi" \
		--XLabel "Jet p_{T} / #gamma p_{T}" --YLabel "1/N_{#gamma} dN_{pair}/d(Jet p_{T} / #gamma p_{T})"

MakePhotonPlot: Execute
	./Execute --DHFile Data.dh \
		--States CMSPhoton2020-5-1,CMSPhoton2020-5-4 \
		--Labels "0-10%","50-100%" \
		--Output MeowPhoton.pdf \
		--XMin 10 --XMax 200 --YMin 0.25 --YMax 1.75 \
		--LegendX 0.20 --LegendY 0.20 --LegendW 0.25 --LegendH 0.12 \
		--Texts 0.52,0.84,"CMS PbPb 5.02 TeV",0.52,0.79,"Prompt photon |#eta| < 1.44" \
		--XLabel "E_{T} (GeV)" --YLabel "R_{AA}"
	./Execute --DHFile Data.dh \
		--States CMSPhoton2020-5-1 \
		--Labels "PbPb 0-10% / pp" \
		--Output MeowPhotonCentral.pdf \
		--XMin 10 --XMax 200 --YMin 0.25 --YMax 1.75 \
		--LegendX 0.20 --LegendY 0.20 --LegendW 0.25 --LegendH 0.06 \
		--Texts 0.52,0.84,"CMS 5.02 TeV",0.52,0.79,"Prompt photon |#eta| < 1.44" \
		--XLabel "E_{T} (GeV)" --YLabel "R_{AA}"

MakeParticlePlot: Execute
	./Execute --DHFile Data.dh \
		--States ALICEParticle2014-1-1,ALICEParticle2014-1-3,ALICEParticle2014-3-1,ALICEParticle2014-3-3 \
		--Labels "#pi - PbPb 0-5%","#pi - reference (x300)","p - PbPb 0-5% (x0.1)","p - reference (x30)" \
		--Scales 1,300,0.1,30 \
		--Output MeowParticle.pdf \
		--XMin 0.3 --XMax 20 --YMin 1e-8 --YMax 10000 \
		--LegendX 0.20 --LegendY 0.20 --LegendW 0.25 --LegendH 0.24 --LogY true --LogX true \
		--Texts 0.60,0.84,"ALICE 2.76 TeV",0.60,0.79,"|y| < 0.8" \
		--XLabel "p_{T} (GeV)" --YLabel "1/N_{event} 1/(2#pip_{T}) d^{2}N/dp_{T}/dy "
	./Execute --DHFile Data.dh \
		--States ALICEParticle2014-1-1,ALICEParticle2014-1-3,ALICEParticle2014-3-1,ALICEParticle2014-3-3 \
		--Labels "#pi - PbPb","#pi - reference","proton - PbPb","proton - reference" \
		--Scales 1,300,0.1,30 \
		--Output MeowParticleSimplified.pdf \
		--XMin 0.3 --XMax 20 --YMin 1e-8 --YMax 10000 \
		--LegendX 0.20 --LegendY 0.20 --LegendW 0.25 --LegendH 0.24 --LogY true --LogX true \
		--Texts 0.60,0.84,"ALICE 2.76 TeV",0.60,0.79,"|y| < 0.8" \
		--XLabel "p_{T} (GeV)" --YLabel "Spectra shape"
	./Execute --DHFile Data.dh \
		--States ALICEParticle2014-1-1,ALICEParticle2014-1-3 \
		--Labels "#pi - PbPb","#pi - reference" \
		--Scales 1,300,0.1,30 \
		--Output MeowParticleSimplifiedPion.pdf \
		--XMin 0.3 --XMax 20 --YMin 1e-8 --YMax 10000 \
		--LegendX 0.20 --LegendY 0.32 --LegendW 0.25 --LegendH 0.12 --LogY true --LogX true \
		--Texts 0.60,0.84,"ALICE 2.76 TeV",0.60,0.79,"|y| < 0.8" \
		--XLabel "p_{T} (GeV)" --YLabel "Spectra shape"

Execute: MakePlot.cpp
	CompileRootMacro MakePlot.cpp Execute


