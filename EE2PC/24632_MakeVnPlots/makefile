
DeployBase = ~/DropBox/Work/EE2PC/20220628

default: TestRun

RunAll: Execute
	bash RunAll.sh

AddAllMOD:
	bash AddAllMOD.sh

TestRun: Execute
	./Execute \
		--File Graphs.root \
		--Curve Data_Beam_Multiplicity_10_20_v2 \
		--Label "Data - MC" \
		--Type 1 \
		--DoSquareShift true \
		--ShiftFile Graphs.root \
		--ShiftCurve MC_Beam_Multiplicity_10_20_v2 \
		--Output Plots/TestRun \
		--Title ";p_{T} (GeV);v_{2}" \
		--XMin 0 --XMax 4 --YMin -2 --YMax 2 \
		--Color -1,-1 \
		--Marker 20,1 \
		--Text 0.5,0.5," " \
		--LegendX 0.2 --LegendY 0.5

Execute: MakePlot.cpp
	CompileRootMacro MakePlot.cpp Execute
	mkdir -p Plots

Deploy:
	mkdir -p $(DeployBase)/DeltaVNZoom
	mv Plots/*_ShiftZoom.pdf $(DeployBase)/DeltaVNZoom/
	mkdir -p $(DeployBase)/DeltaVN
	mv Plots/*_Shift.pdf     $(DeployBase)/DeltaVN/
	mkdir -p $(DeployBase)/VNZoom
	mv Plots/*_Zoom.pdf      $(DeployBase)/VNZoom/
	mkdir -p $(DeployBase)/VN
	mv Plots/*.pdf           $(DeployBase)/VN/
	cp Graphs.root           $(DeployBase)
