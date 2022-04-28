HEPData=https://www.hepdata.net/record/ins1692558
HEPTable=https://www.hepdata.net/download/table/ins1692558

for i in 3 4 5 6 7 8 9
do
   echo $i
   # curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml
done

for i in 3 4 5 6 7 8 9
do
   echo $i

   Observable=RAA
   if [ $i -ge 6 ]; then
      Observable=RXePb
   fi

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX

   N=`grep 'low' YAML${i}.yaml | grep high | wc -l`

   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" | sed "s/empty/0/g" > AllY
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYStat
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYSysPartial
   grep ' norm' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYNorm
   grep ' Centrality' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' | cut --delim '%' --field 1 > AllCentrality
   if [ $i -ge 7 ]; then
      grep ' Centrality' YAML${i}.yaml | awk '{print $6}' | tr -d ',}' | cut --delim '%' --field 1 > AllCentrality
   fi

   FileLineAppend AllEYSysPartial AllEYNorm AllEYSysTemp
   cat AllEYSysTemp | awk '{print sqrt($1*$1+$2*$2)}' > AllEYSys

   G=`wc -l AllCentrality | awk '{print $1}'`

   for j in `seq 1 $G`
   do
      Centrality=`cat AllCentrality | head -n$j | tail -n1`

      JN=`echo $N $j | awk '{print $1*$2}'`

      cat AllY | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > Y
      cat AllEYStat | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > EYStat
      cat AllEYSys | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > EYSys

      FileName=CMSHadronXeXeRAA2018-${i}-${j}.json

      echo "{" > $FileName
      echo "   \"System\": \"XeXe\"," >> $FileName
      echo "   \"Energy\": \"5.44 TeV\"," >> $FileName
      echo "   \"Subject\": \"Hadron\"," >> $FileName
      echo "   \"Observable\": \"$Observable\"," >> $FileName
      echo "   \"Dependency\": \"PT\"," >> $FileName
      echo "   \"Centrality\": \"$Centrality%\"," >> $FileName
      echo "   \"Record\": \"CMS 2018\"," >> $FileName
      echo "   \"Selection\": \"eta < 1.0\"," >> $FileName
      echo "   \"Comment\": \"$HEPData\"," >> $FileName
      echo "   \"X\": ["`cat X`"]," >> $FileName
      echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
      echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
      echo "   \"Y\": ["`cat Y`"]," >> $FileName
      echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
      echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
      echo "   \"GlobalUncertainty\": 0" >> $FileName
      echo "}," >> $FileName
   done
done

