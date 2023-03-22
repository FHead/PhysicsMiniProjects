#!/bin/bash

for i in Plots/*pdf
do
   bash AddMOD.sh $i
done

