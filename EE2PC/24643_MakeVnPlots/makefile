
DeployBase = ~/DropBox/Work/EE2PC/20220708

default: TestRun

RunAll: Execute
	bash RunAll.sh

AddAllMOD:
	bash AddAllMOD.sh

TestRun: Execute
	./Execute \
		--File Graphs.root \
		--Curve Data_Thrust_Multiplicity_50_None_v2 \
		--DoSquareShift true \
		--ShiftFile Graphs.root \
		--ShiftCurve MC_Thrust_Multiplicity_50_None_v2 \
		--Label "Data - Archived MC" \
		--Type 1 \
		--Output Plots/Thrust_Multiplicity_50_None_v2_SquareShiftZoom_Overlay \
		--Title ";p_{T} (GeV);sign(#DeltaV_{2}) #sqrt{|#DeltaV_{2}|}" \
		--XMin 0 --XMax 6 --AutoY true \
		--Color -2\
		--Marker 20 \
		--Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"N_{track} #geq 50",0.15,0.76,"Thrust axis" \
		--LegendX 0.15 --LegendY 0.15 \
		--AddPPVN true
	./Execute \
		--File Graphs.root \
		--Curve Data_Thrust_Multiplicity_50_None_v2 \
		--DoShift true \
		--ShiftFile Graphs.root \
		--ShiftCurve MC_Thrust_Multiplicity_50_None_v2 \
		--Label "Data - Archived MC" \
		--Type 1 \
		--Output Plots/Thrust_Multiplicity_50_None_v2_ShiftZoom_Overlay \
		--Title ";p_{T} (GeV);#Deltav_{2}" \
		--XMin 0 --XMax 6 --AutoY true \
		--Color -2\
		--Marker 20 \
		--Text 0.15,0.86,"#font[52]{Preliminary}",0.15,0.81,"N_{track} #geq 50",0.15,0.76,"Thrust axis" \
		--LegendX 0.15 --LegendY 0.15 \
		--AddPPVN true
	bash AddMODLow.sh Plots/Thrust_Multiplicity_50_None_v2_ShiftZoom_Overlay.pdf
	bash AddMODLow.sh Plots/Thrust_Multiplicity_50_None_v2_SquareShiftZoom_Overlay.pdf

Execute: MakePlot.cpp
	CompileRootMacro MakePlot.cpp Execute
	mkdir -p Plots

Deploy:
	mkdir -p $(DeployBase)/DeltaVNZoom
	mv Plots/*_ShiftZoom.pdf       $(DeployBase)/DeltaVNZoom/
	mkdir -p $(DeployBase)/DeltaVN
	mv Plots/*_Shift.pdf           $(DeployBase)/DeltaVN/
	mkdir -p $(DeployBase)/VNZoom
	mv Plots/*_Zoom.pdf            $(DeployBase)/VNZoom/
	mkdir -p $(DeployBase)/SquareDeltaVN
	mv Plots/*_SquareShiftZoom.pdf $(DeployBase)/SquareDeltaVN/
	mkdir -p $(DeployBase)/VN
	mv Plots/*.pdf                 $(DeployBase)/VN/
	cp -f Graphs.root              $(DeployBase)/
