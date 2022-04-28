HEPData=https://www.hepdata.net/record/ins1487278
HEPTable=https://www.hepdata.net/download/table/ins1487278

for i in 8a 8b 8c 8d 8e 8f 9a 9b 10
do
   echo $i
   # curl $HEPTable/Table$i/1/yaml > YAML${i}.yaml
done

# vs PT
for i in 8a 8b 8c 8d 8e 8f 10
do
   echo $i

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX

   N=`grep 'low' YAML${i}.yaml | grep high | wc -l`

   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" > AllY
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYStat
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYSys
   grep ' Centrality' YAML${i}.yaml | awk '{print $5}' | tr -d ',' > AllCentrality
   grep ' anti-k' YAML${i}.yaml | awk '{print $6 * 10}' | tr -d '}' > AllR

   if [ $i == "10" ];
   then
      grep ' total' YAML${i}.yaml | awk '{print 0}' | tr -d ',}' > AllEYStat
      grep ' total' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYSys
   fi

   Global=
   if [ $i == "8a" ]; then Global=0.055; fi
   if [ $i == "8b" ]; then Global=0.059; fi
   if [ $i == "8c" ]; then Global=0.069; fi
   if [ $i == "8d" ]; then Global=0.100; fi
   if [ $i == "8e" ]; then Global=0.150; fi
   if [ $i == "8f" ]; then Global=0.180; fi
   if [ $i == "10" ]; then Global=0.057; fi

   G=`wc -l AllCentrality | awk '{print $1}'`

   for j in `seq 1 $G`
   do
      R=`cat AllR | head -n$j | tail -n1`
      Centrality=`cat AllCentrality | head -n$j | tail -n1`

      JN=`echo $N $j | awk '{print $1*$2}'`

      cat AllY | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > Y
      cat AllEYStat | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > EYStat
      cat AllEYSys | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > EYSys

      FileName=CMSJetRAA2016-${i}-${j}.json

      echo "{" > $FileName
      echo "   \"System\": \"PbPb\"," >> $FileName
      echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
      echo "   \"Subject\": \"JetR$R\"," >> $FileName
      echo "   \"Observable\": \"RAA\"," >> $FileName
      echo "   \"Dependency\": \"PT\"," >> $FileName
      echo "   \"Centrality\": \"$Centrality%\"," >> $FileName
      echo "   \"Record\": \"CMS 2016\"," >> $FileName
      echo "   \"Selection\": \"eta < 2.0\"," >> $FileName
      echo "   \"Comment\": \"Old code!\"," >> $FileName
      echo "   \"HEPData\": \"$HEPData\"," >> $FileName
      echo "   \"X\": ["`cat X`"]," >> $FileName
      echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
      echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
      echo "   \"Y\": ["`cat Y`"]," >> $FileName
      echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
      echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
      echo "   \"GlobalUncertainty\": $Global" >> $FileName
      echo "}," >> $FileName
   done
done

# vs centrality
for i in 9a 9b
do
   echo $i

   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1+$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > X
   grep 'low' YAML${i}.yaml | grep high | awk '{print $3,$5}' | tr -d ',}' | awk '{print ($1-$2)/2}' \
      | tr '\n' ',' | sed "s/,$//" > EX

   N=`grep 'low' YAML${i}.yaml | grep high | wc -l`

   grep '^[ ]*value' YAML${i}.yaml | awk '{print $2}' | grep -v "^$" > AllY
   grep ' stat' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYStat
   grep ' sys' YAML${i}.yaml | awk '{print $5}' | tr -d ',}' > AllEYSys
   grep ' anti-k' YAML${i}.yaml | awk '{print $6 * 10}' | tr -d '}' > AllR
   grep ' Jet \$p_T\$' YAML${i}.yaml | awk '{print $6}' | tr -d ',' > AllPT

   grep ' global' YAML${i}.yaml | awk '{print $5}' | tr -d '}' > AllGlobal

   Global=0

   G=`wc -l AllPT | awk '{print $1}'`
   echo $G

   for j in `seq 1 $G`
   do
      R=`cat AllR | head -n$j | tail -n1`
      Centrality=`cat AllCentrality | head -n$j | tail -n1`
      PT=`cat AllPT | head -n$j | tail -n1`

      JN=`echo $N $j | awk '{print $1*$2}'`

      cat AllY | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > Y
      cat AllEYStat | head -n$JN | tail -n$N | tr '\n' ',' | sed 's/,$//' > EYStat
      cat AllEYSys | head -n$JN | tail -n$N > EYSysTemp
      FileLineAppend EYSysTemp AllGlobal EYSysWithGlobal
      cat EYSysWithGlobal | awk '{print sqrt($1*$1+$2*$2)}' | tr '\n' ',' | sed 's/,$//' > EYSys

      FileName=CMSJetRAA2016-${i}-${j}.json

      echo "{" > $FileName
      echo "   \"System\": \"PbPb\"," >> $FileName
      echo "   \"Energy\": \"2.76 TeV\"," >> $FileName
      echo "   \"Subject\": \"JetR$R\"," >> $FileName
      echo "   \"Observable\": \"RAA\"," >> $FileName
      echo "   \"Dependency\": \"NPart\"," >> $FileName
      echo "   \"Centrality\": \"0-100%\"," >> $FileName
      echo "   \"Record\": \"CMS 2016\"," >> $FileName
      echo "   \"Selection\": \"eta < 2.0, PT = $PT\"," >> $FileName
      echo "   \"Comment\": \"$HEPData\"," >> $FileName
      echo "   \"X\": ["`cat X`"]," >> $FileName
      echo "   \"EXLow\": ["`cat EX`"]," >> $FileName
      echo "   \"EXHigh\": ["`cat EX`"]," >> $FileName
      echo "   \"Y\": ["`cat Y`"]," >> $FileName
      echo "   \"EYStatLow\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYStatHigh\": ["`cat EYStat`"]," >> $FileName
      echo "   \"EYSysLow\": ["`cat EYSys`"]," >> $FileName
      echo "   \"EYSysHigh\": ["`cat EYSys`"]," >> $FileName
      echo "   \"GlobalUncertainty\": $Global" >> $FileName
      echo "}," >> $FileName
   done
done

