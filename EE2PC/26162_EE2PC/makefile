
default: Figure2 Figure3 Figure4 Figure5

RunFigure2: MakeFigure2.cpp
	CompileRootMacro MakeFigure2.cpp RunFigure2

Figure2: RunFigure2
	cat Fig2.txt | TextToTree Fig2.root 8 "x:y:exl:exh:eyl:eyh:nmin:data"
	./RunFigure2
	xelatex Figure2.tex

RunFigure3: MakeFigure3.cpp
	CompileRootMacro MakeFigure3.cpp RunFigure3

Figure3: RunFigure3
	cat Fig3.txt | TextToTree Fig3.root 5 "x:y:ey:type:data"
	./RunFigure3
	xelatex Figure3.tex

RunFigure4: MakeFigure4.cpp
	CompileRootMacro MakeFigure4.cpp RunFigure4

Figure4: RunFigure4
	cat Fig4.txt | TextToTree Fig4.root 12 "x:exl:exh:y:eyl:eyh:syl:syh:MC:vn:Nmin:Nmax"
	./RunFigure4
	xelatex Figure4.tex

RunFigure5: MakeFigure5.cpp
	CompileRootMacro MakeFigure5.cpp RunFigure5

Figure5: RunFigure5
	cat Fig5.txt | TextToTree Fig5.root 9 "x:exl:exh:y:eyl:eyh:syl:syh:energy"
	./RunFigure5
	xelatex Figure5.tex

