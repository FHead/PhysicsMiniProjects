HEPData=https://www.hepdata.net/record/ins1495866
TableVersion=2
HEPTable=https://www.hepdata.net/download/table/ins1495866

for i in `seq 11 17`
do
   echo $i
   # curl $HEPTable/Table$i/$TableVersion/yaml > Table${i}.yaml
done

# PT dependence
for i in 11 12
do
   echo $i

   State=Upsilon
   if [ $i == 11 ]; then State=Upsilon1S; else State=Upsilon2S; fi

   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed 's/,$//' > X
   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($2-$1)/2}' \
      | tr '\n' ',' | sed 's/,$//' > EX
   grep "^[ ]*value:" Table${i}.yaml | awk '{print $2}' | tr '\n' ',' | sed 's/,$//' > Y
   grep "label: stat" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYStat
   grep "label: syst" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYSys
   grep "GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $6}' | tr -d '%}' | awk '{print $1*0.01}' > Global

   FileName=CMSUpsilonRAA2016-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"0-100%\"," >> $FileName
   echo "   \"Record\": \"CMS 2016\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat Global`" >> $FileName
   echo "}," >> $FileName
done

# y dependence
for i in 13 14
do
   echo $i

   State=Upsilon
   if [ $i == 13 ]; then State=Upsilon1S; else State=Upsilon2S; fi

   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed 's/,$//' > X
   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($2-$1)/2}' \
      | tr '\n' ',' | sed 's/,$//' > EX
   grep "^[ ]*value:" Table${i}.yaml | awk '{print $2}' | tr '\n' ',' | sed 's/,$//' > Y
   grep "label: stat" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYStat
   grep "label: syst" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYSys
   grep "GLOBAL UNCERTAINTY" Table${i}.yaml | awk '{print $6}' | tr -d '%}' | awk '{print $1*0.01}' > Global

   FileName=CMSUpsilonRAA2016-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"y\"," >> $FileName
   echo "   \"Centrality\": \"0-100%\"," >> $FileName
   echo "   \"Record\": \"CMS 2016\"," >> $FileName
   echo "   \"Selection\": \"Inclusive\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat Global`" >> $FileName
   echo "}," >> $FileName
done

# centrality / NPart dependence
for i in 15 16
do
   echo $i

   State=Upsilon
   if [ $i == 15 ]; then State=Upsilon1S; else State=Upsilon2S; fi

   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed 's/,$//' > X
   grep "low" Table${i}.yaml | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($2-$1)/2}' \
      | tr '\n' ',' | sed 's/,$//' > EX
   grep " - {value:" Table${i}.yaml | awk '{print $3}' | tr -d ',}' | tr '\n' ',' | sed 's/,$//' > N
   grep " - {value:" Table${i}.yaml | awk '{print 0}' | tr -d ',}' | tr '\n' ',' | sed 's/,$//' > EN
   grep "^[ ]*value:" Table${i}.yaml | awk '{print $2}' | tr '\n' ',' | sed 's/,$//' > Y
   grep "label: stat" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYStat
   grep "label: syst" Table${i}.yaml | awk '{print $5}' | tr -d '}' | tr '\n' ',' | sed 's/,$//' > EYSys
   grep "GLOBAL PP UNCERTAINTY" Table${i}.yaml | awk '{print $7}' | tr -d '%}' | awk '{print $1*0.01}' > GlobalPP
   grep "GLOBAL PBPB UNCERTAINTY" Table${i}.yaml | awk '{print $7}' | tr -d '%}' | awk '{print $1*0.01}' > GlobalPbPb
   cat GlobalPP GlobalPbPb | tr '\n' ' ' | awk '{print sqrt($1*$1+$2*$2)}' > Global

   FileName=CMSUpsilonRAA2016-${i}-1.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"Centrality\"," >> $FileName
   echo "   \"Centrality\": \"0-100%\"," >> $FileName
   echo "   \"Record\": \"CMS 2016\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat X`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat Global`" >> $FileName
   echo "}," >> $FileName

   FileName=CMSUpsilonRAA2016-${i}-2.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
   echo "   \"Subject\": \"$State\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"NPart\"," >> $FileName
   echo "   \"Centrality\": \"0-100%\"," >> $FileName
   echo "   \"Record\": \"CMS 2016\"," >> $FileName
   echo "   \"Selection\": \"y < 2.4\"," >> $FileName
   echo "   \"Comment\": \"$HEPData\"," >> $FileName
   echo "   \"X\": ["`cat N`"]," >> $FileName
   echo "   \"EXLow\": ["`cat EN`"]," >> $FileName
   echo "   \"EXHigh\": ["`cat EN`"]," >> $FileName
   echo "   \"Y\": ["`cat Y`"]," >> $FileName
   echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
   echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
   echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
   echo "   \"GlobalUncertainty\": `cat Global`" >> $FileName
   echo "}," >> $FileName
done

# inclusive point
for i in 17
do
   echo $i
done
