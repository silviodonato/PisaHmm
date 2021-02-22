from samples2026 import *
import samples2016,samples2017,samples2018
samples.update(samples2016.samples)

name="H"
background= {"DY": ["DYToLL_madgraphMLM", "DYJetsToLL_M_100_madgraphMLM"], "ttH": ["TT_Tune_powheg"], "VBF Z": ["EWKZ2Jets_ZToLL_madgraph"]}

#"DYVBF":[
#    "DY105VBF_2026MGPY"
#],
#"VBF Z":[
 #  "EWKZ105_2026MGPYDIPOLE",
#],
#"Top":[
#],
#"Other":[
#],


#sorting
##SD test
backgroundSorted=["DY", "VBF Z", "ttH"]
backgroundSorted+=[x for x in background if x not in backgroundSorted]


signal={
"VBF H":["vbfHmm_powheg"], "gg H": ["GluGluHToMuMu_powheg"]
}

#legend sorting
backgroundSortedForLegend=["DY","VBF Z", "ttH"]
backgroundSortedForLegend+=[x for x in background if x not in backgroundSortedForLegend]
signalSortedForLegend=["VBF H", "gg H"]
signalSortedForLegend+=[x for x in signal if x not in signalSortedForLegend]




#data={
#"2018":["data2018"]
#}

import ROOT
fillcolor={
"DY": ROOT.kOrange,
"DY01J": ROOT.kOrange-1,
"DY2J": ROOT.kOrange-2,
"DYVBF": ROOT.kOrange-3,
"VBF Z": ROOT.kMagenta+2,
"Top": ROOT.kGreen+1,
"Other" : ROOT.kGreen+3,
"VBF H":ROOT.kRed,
"gg H":ROOT.kRed+4,
"ZH":ROOT.kPink+4,
"WH":ROOT.kPink+9,
"VH":ROOT.kPink+5,
"ttH":ROOT.kRed-4,
}

systematicsToPlot=["JESUp","JESDown"]

systematicsForDC = ["JESUp","JESDown"]
jesList = []

linecolor=fillcolor
markercolor=fillcolor

from rebinning import *
#rebin["DNN18Atan"]=dnnnewfew18
#rebin["DNN18AtanNoMass"]=dnnnewfew18
rebin["DNN18Atan"]=dnn062018
rebin["DNN18AtanNoMass"]=dnn062018

rebin["DNN18Atan2"]= [0 , 0.311666666667 , 0.635 , 0.845 , 1.04166666667 , 1.185 , 1.31666666667 , 1.42666666667 , 1.53166666667 , 1.645 , 1.76166666667 , 1.87 , 1.97666666667 , 2.07833333333 , 2.17666666667 , 2.27666666667 , 2.37666666667 , 2.485 , 2.61333333333 , 2.76333333333 , 2.96833333333 , 5.0 ]
#rebin["DNN18Atan2"]=  [0 , 0.49 , 0.768333333333 , 0.993333333333 , 1.15333333333 , 1.295 , 1.41 , 1.515 , 1.61833333333 , 1.73 , 1.83166666667 , 1.925 , 2.01166666667 , 2.09666666667 , 2.175 , 2.255 , 2.32666666667 , 2.40166666667 , 2.475 , 2.55666666667 , 2.645 , 2.73666666667 , 2.83833333333 , 2.96 , 3.13166666667 , 5.0 ]

#ebin["DNN18Atan"]=dnn032018
from histograms import signalHistosMassScanAll

for i in  signalHistosMassScanAll :
    rebin[i]=rebin["DNN18Atan"]

from systematicGrouping import *
systematicDetail = systematicGrouping(background, signal,jesList,"2018")
