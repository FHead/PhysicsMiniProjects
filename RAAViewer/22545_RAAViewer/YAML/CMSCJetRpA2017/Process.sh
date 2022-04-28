HEPData=https://www.hepdata.net/record/ins1507091
HEPTable=https://www.hepdata.net/download/table/ins1507091

for i in 0
do
   # curl https://www.hepdata.net/download/table/ins1507091/cjet%20pPb%20xsec%20and%20rpa/1/yaml > YAML${i}.yaml

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($2-$1)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX

   N=`grep 'low' YAML${i}.yaml | grep high | wc -l`
   echo $N

   grep '^[ ]*- value' YAML${i}.yaml | awk '{print $3}' | grep -v "^$" | tail -n $N | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | tail -n $N | tr '\n' ',' | sed "s/,$//" > EYStat
   grep ' sys' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | tail -n $N | tr '\n' ',' | sed "s/,$//" > EYSys

   FileName=CMSCJetRpA2017-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"pPb\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"CJetR3\"," >> $FileName
   echo "   \"Observable\": \"RpA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2017\"," >> $FileName
   echo "   \"Selection\": \"eta < 1.5\"," >> $FileName
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

