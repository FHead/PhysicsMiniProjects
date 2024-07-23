
default: TestRun

Convert:
	python3 convert.py Fragments/ALICEJetRAA2020-33-1.json ALICEJetRAA2020-33-1
	DHSet Data.dh temp.config
	python3 convert.py Fragments/ATLASJetRAA2018-19-1.json ATLASJetRAA2018-19-1
	DHSet Data.dh temp.config
	python3 convert.py Fragments/CMSJetRAA2016-8a-3.json CMSJetRAA2016-8a-3
	DHSet Data.dh temp.config
	python3 convert.py Fragments/CMSJetRAA2020-2-0.json CMSJetRAA2020-2-0
	DHSet Data.dh temp.config

Execute: MakePlot.cpp
	CompileRootMacro MakePlot.cpp Execute

TestRun: Execute
	./Execute

