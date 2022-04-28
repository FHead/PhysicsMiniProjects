HEPData=https://www.hepdata.net/record/ins1599548
HEPTable=https://www.hepdata.net/download/table/ins1599548

for i in 3
do
   # curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml

   grep '^[ ]*- {value: ' YAML${i}.yaml | awk '{print $3}' | tr -d '}' | tr '\n' ',' | sed "s/,$//" > X
   grep '^[ ]*- {value: ' YAML${i}.yaml | awk '{print 0}' | tr -d '}' | tr '\n' ',' | sed "s/,$//" > EX
   # grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
   #    | tr '\n' ',' | sed "s/,$//" > X
   # grep high YAML${i}.yaml | grep low | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
   #    | tr '\n' ',' | sed "s/,$//" > EX

   grep '^[ ]*- value:' YAML${i}.yaml | awk '{print $3}' | grep -v "^$" | tr '\n' ',' | sed "s/,$//" > Y
   grep ' stat' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | tr '\n' ',' | sed "s/,$//" > EYStat
   grep 'correlated sys' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | Reformat 2 \
      | awk '{print sqrt($1*$1+$2*$2+0.041*0.041)}' | tr '\n' ',' | sed "s/,$//" > EYSysLow
   grep 'correlated sys' YAML${i}.yaml | awk '{print $3}' | tr -d ',}' | Reformat 2 \
      | awk '{print sqrt($1*$1+$2*$2+0.046*0.046)}' | tr '\n' ',' | sed "s/,$//" > EYSysHigh

   FileName=CMSBPlusRAA2017-${i}.json

   echo "{" > $FileName
   echo "   \"System\": \"PbPb\"," >> $FileName
   echo "   \"Energy\": \"5.02 TeV\"," >> $FileName
   echo "   \"Subject\": \"BPlus\"," >> $FileName
   echo "   \"Observable\": \"RAA\"," >> $FileName
   echo "   \"Dependency\": \"PT\"," >> $FileName
   echo "   \"Centrality\": \"Inclusive\"," >> $FileName
   echo "   \"Record\": \"CMS 2017\"," >> $FileName
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


