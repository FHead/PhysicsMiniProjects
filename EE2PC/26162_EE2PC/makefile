
default: TextToTree Figure2 Figure3 Figure4 Figure5

TextToTree: TextToTree.cpp
	g++ TextToTree.cpp -o TextToTree `root-config --cflags --libs`

RunFigure2: MakeFigure2.cpp
	g++ MakeFigure2.cpp -o RunFigure2 `root-config --cflags --libs`

Figure2: TextToTree RunFigure2
	cat Fig2.txt | TextToTree Fig2.root 8 "x:y:exl:exh:eyl:eyh:nmin:data"
	./RunFigure2
	xelatex Figure2.tex

RunFigure3: TextToTree MakeFigure3.cpp
	g++ MakeFigure3.cpp -o RunFigure3 `root-config --cflags --libs`

Figure3: RunFigure3
	cat Fig3.txt | TextToTree Fig3.root 6 "x:y:ex:ey:type:data"
	./RunFigure3
	xelatex Figure3.tex

RunFigure4: TextToTree MakeFigure4.cpp
	g++ MakeFigure4.cpp -o RunFigure4 `root-config --cflags --libs`

Figure4: RunFigure4
	cat Fig4.txt | TextToTree Fig4.root 12 "x:exl:exh:y:eyl:eyh:syl:syh:MC:vn:Nmin:Nmax"
	./RunFigure4
	xelatex Figure4.tex

RunFigure5: TextToTree MakeFigure5.cpp
	g++ MakeFigure5.cpp -o RunFigure5 `root-config --cflags --libs`

Figure5: RunFigure5
	cat Fig5.txt | TextToTree Fig5.root 9 "x:exl:exh:y:eyl:eyh:syl:syh:energy"
	./RunFigure5
	xelatex Figure5.tex

