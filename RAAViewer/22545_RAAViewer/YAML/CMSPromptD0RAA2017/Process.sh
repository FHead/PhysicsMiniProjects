HEPData=https://www.hepdata.net/record/ins1616207
HEPTable=https://www.hepdata.net/download/table/ins1616207

for i in 1
do
   # curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml

   grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($2-$1)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX

   grep '^[ ]*- value:' YAML${i}.yaml | awk '{print $3}' | grep -v "^$" > AllY
   grep ' stat' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' > AllEYStat
   grep ' sys' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' > AllEYSys
   grep ' CENTRALITY' YAML${i}.yaml | awk '{print $7"-"$9}' | tr -d ',}' > AllCentrality
   grep ' GLOBAL UNCERTAINTY ' YAML${i}.yaml | awk '{print $11,$12}' | tr -d ',}' | awk '{print 0.01*$1,0.01*$2} '> AllGlobal

   FileLineAppend AllEYSys AllY AllEYSysTemp

   N=`grep high YAML${i}.yaml | grep low | wc -l`
   Count=`cat AllCentrality | wc -l`

   for j in `seq 1 $Count`
   do
      GlobalLow=`cat AllGlobal | head -n$j | tail -n1 | awk '{print $1}'`
      GlobalHigh=`cat AllGlobal | head -n$j | tail -n1 | awk '{print $2}'`

      GN=`echo $N $j | awk '{print $1*$2}'`
      cat AllY | head -n$GN | tail -n$N | tr '\n' ',' | sed 's/,$//' > Y
      cat AllEYStat | head -n$GN | tail -n$N | tr '\n' ',' | sed 's/,$//' > EYStat
      cat AllEYSysTemp | head -n$GN | tail -n$N | awk '{print sqrt($1*$1+'$GlobalLow'*'$GlobalLow'*$2*$2)}' \
         | tr '\n' ',' | sed 's/,$//' > EYSysLow
      cat AllEYSysTemp | head -n$GN | tail -n$N | awk '{print sqrt($1*$1+'$GlobalHigh'*'$GlobalHigh'*$2*$2)}' \
         | tr '\n' ',' | sed 's/,$//' > EYSysHigh
      cat AllCentrality | head -n$j | tail -n1 | sed "s/\.0//g" > Centrality

      FileName=CMSPromptD0RAA2017-${i}-${j}.json
   
      echo "{" > $FileName
      echo "   \"System\": \"PbPb\"," >> $FileName
      echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
      echo "   \"Subject\": \"PromptD0\"," >> $FileName
      echo "   \"Observable\": \"RAA\"," >> $FileName
      echo "   \"Dependency\": \"PT\"," >> $FileName
      echo "   \"Centrality\": \"`cat Centrality`%\"," >> $FileName
      echo "   \"Record\": \"CMS 2017\"," >> $FileName
      echo "   \"Selection\": \"y < 1.0\"," >> $FileName
      echo "   \"Comment\": \"$HEPData\"," >> $FileName
      echo "   \"X\": ["`cat X`"]," >> $FileName
      echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
      echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
      echo "   \"Y\": ["`cat Y`"]," >> $FileName
      echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
      echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
      echo "   \"GlobalUncertainty\": 0" >> $FileName
      echo "}," >> $FileName
   done
done


