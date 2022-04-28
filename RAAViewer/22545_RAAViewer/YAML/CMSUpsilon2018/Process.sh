HEPData=https://www.hepdata.net/record/ins1674529
TableVersion=2
HEPTable=https://www.hepdata.net/download/table/ins1674529
FileTag=CMSUpsilonRAA2018
System=PbPb
Energy='5.02 TeV'

for i in 13 14 16 17 19 20
do
   echo $i
   # curl $HEPTable/Table$i/$TableVersion/yaml > Table${i}.yaml
done

# PT dependence
for i in 13 14
do
   echo $i

   State=Upsilon
   if [ $i == 13 ]; then State=Upsilon1S; else State=Upsilon2S; fi

   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed 's/,$//' > X
   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' | Abs \
      | tr '\n' ',' | sed 's/,$//' > EX
   grep "^[ ]*value:" Table${i}.yaml | awk '{print $2}' | tr '\n' ',' | sed 's/,$//' > Y
   grep "label: stat" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYStat
   G1=`grep "GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $6}' | tr -d '%}' | awk '{print $1*0.01}'`
   G2=`grep "GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $8}' | tr -d '%}' | awk '{print $1*0.01}'`
   grep "label: syst" Table${i}.yaml | awk '{print $5}' | tr -d '}' | awk '{print sqrt($1*$1+'$G1'*'$G1')}'\
      | tr '\n' ',' | sed 's/,$//' > EYSysLow
   grep "label: syst" Table${i}.yaml | awk '{print $5}' | tr -d '}' | awk '{print sqrt($1*$1+'$G1'*'$G1')}'\
      | tr '\n' ',' | sed 's/,$//' > EYSysHigh

   FileName=$FileTag-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"$System\"," >> $FileName
   echo "   \"Energy\": \"$Energy\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2018\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
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

# y dependence
for i in 16 17
do
   echo $i

   State=Upsilon
   if [ $i == 16 ]; then State=Upsilon1S; else State=Upsilon2S; fi

   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed 's/,$//' > X
   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' | Abs \
      | tr '\n' ',' | sed 's/,$//' > EX
   grep "^[ ]*value:" Table${i}.yaml | awk '{print $2}' | tr '\n' ',' | sed 's/,$//' > Y
   grep "label: stat" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYStat
   G1=`grep "GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $6}' | tr -d '%}' | awk '{print $1*0.01}'`
   G2=`grep "GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $8}' | tr -d '%}' | awk '{print $1*0.01}'`
   grep "label: syst" Table${i}.yaml | awk '{print $5}' | tr -d '}' | awk '{print sqrt($1*$1+'$G1'*'$G1')}'\
      | tr '\n' ',' | sed 's/,$//' > EYSysLow
   grep "label: syst" Table${i}.yaml | awk '{print $5}' | tr -d '}' | awk '{print sqrt($1*$1+'$G2'*'$G2')}'\
      | tr '\n' ',' | sed 's/,$//' > EYSysHigh

   FileName=$FileTag-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"$System\"," >> $FileName
   echo "   \"Energy\": \"$Energy\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"y\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2018\"," >> $FileName
   echo "   \"Selection\": \"Inclusive\"," >> $FileName
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

# centrality dependence
for i in 19 20
do
   echo $i

   State=Upsilon
   if [ $i == 19 ]; then State=Upsilon1S; else State=Upsilon2S; fi

   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed 's/,$//' > X
   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' | Abs \
      | tr '\n' ',' | sed 's/,$//' > EX

   NPoint=`cat X | tr ',' '\n' | wc -l | AddConst 1`

   G1=`grep "name: GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $6}' | tr -d '%}' | awk '{print $1*0.01}'`
   G2=`grep "name: PP Y(1S) GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $8}' | tr -d '%}' | awk '{print $1*0.01}'`
   GG=`echo $G1 $G2 | awk '{print $1*$1+$2*$2}'`
   
   grep "^[ ]*value:" Table${i}.yaml | awk '{print $2}' | head -n$NPoint | tr '\n' ',' | sed 's/,$//' > Y
   grep "label: stat" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYStat
   grep "label: sys" Table${i}.yaml | awk '{print $8}' | tr -d ',}' | head -n$NPoint | Abs \
      | awk '{print sqrt($1*$1+'$GG')}' \
      | tr '\n' ',' | sed 's/,$//' > EYSysLow
   grep "label: sys" Table${i}.yaml | awk '{print $6}' | tr -d ',}' | head -n$NPoint | Abs \
      | awk '{print sqrt($1*$1+'$GG')}' \
      | tr '\n' ',' | sed 's/,$//' > EYSysHigh
   
   grep "^[ ]*value:" Table${i}.yaml | awk '{print $2}' | tail -n$NPoint | tr '\n' ',' | sed 's/,$//' > N
   grep "label: sys" Table${i}.yaml | awk '{print $8}' | tr -d ',}' | tail -n$NPoint | Abs \
      | tr '\n' ',' | sed 's/,$//' > ENLow
   grep "label: sys" Table${i}.yaml | awk '{print $6}' | tr -d ',}' | tail -n$NPoint | Abs \
      | tr '\n' ',' | sed 's/,$//' > ENHigh

   FileName=$FileTag-${i}-1.json

   echo "{" > $FileName
   echo "   \"System\": \"$System\"," >> $FileName
   echo "   \"Energy\": \"$Energy\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"Centrality\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2018\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
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

   FileName=$FileTag-${i}-2.json

   echo "{" > $FileName
   echo "   \"System\": \"$System\"," >> $FileName
   echo "   \"Energy\": \"$Energy\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"NPart\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2018\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat N`"]," >> $FileName
   echo "   \"EXLow\": ["`cat ENLow`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat ENHigh`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSysLow`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSysHigh`"]," >> $FileName
   echo "   \"GlobalUncertainty\": 0" >> $FileName
   echo "}," >> $FileName
done

