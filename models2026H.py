from samples2026 import *
import samples2016,samples2017,samples2018
samples.update(samples2016.samples)

name="H"
background= {

"DY": ["DY50_2026MGPY", "DY100_2026MGPY"], 

"DYHT": ["DY50HT70_2026MGPY", "DY50HT100_2026MGPY", "DY50HT200_2026MGPY", "DY50HT400_2026MGPY", "DY50HT600_2026MGPY", "DY50HT800_2026MGPY", "DY50HT1200_2026MGPY", "DY50HT2500_2026MGPY"], 

"DY0J": ["DY0J50_2026MGPY", "DY0J50_2026MGPY_FNAL"],

"DY01J": ["DY1J50_2026MGPY"],

"DY2J": ["DY2J50_2026MGPY"],

"DY3J": ["DY3J50_2026MGPY", "DY3J50_2026MGPY_FNAL"],

"Top": ["TT_2026POWPY", "TTlep_2026MGPY"], 

"VBF Z": ["EWKZ2JetsZToLL_2026MGPY"] 

}

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
backgroundSorted=["DY", "DYHT", "DY0J", "DY01J", "DY2J", "DY3J", "VBF Z", "Top"]
backgroundSorted+=[x for x in background if x not in backgroundSorted]


signal={
"VBF H":["vbfHmm_2026POWPY"], "gg H": ["ggHmm_2026POWPY"]
}

#legend sorting
backgroundSortedForLegend=["DY", "DYHT", "DY0J", "DY01J", "DY2J", "DY3J", "VBF Z", "Top"]
backgroundSortedForLegend+=[x for x in background if x not in backgroundSortedForLegend]
signalSortedForLegend=["VBF H", "gg H"]
signalSortedForLegend+=[x for x in signal if x not in signalSortedForLegend]




data={
"2026":150E3 ##nb-1. If list => take histogram. If number => just take the lumi
}
import ROOT
fillcolor={
"DY": ROOT.kOrange,
"DYHT": ROOT.kOrange-1,
"DY0J": ROOT.kOrange-2,
"DY01J": ROOT.kOrange-3,
"DY2J": ROOT.kOrange-4,
"DY3J": ROOT.kOrange-5,
"DYVBF": ROOT.kOrange-6,
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

systematicsToPlot = []
systematicsForDC = systematicsToPlot

#systematicsToPlot=["JESUp","JESDown"]

#systematicsForDC = ["JESUp","JESDown"]
#jesList = []

linecolor=fillcolor
markercolor=fillcolor

from rebinning import *
#rebin["DNN18Atan"]=dnnnewfew18
#rebin["DNN18AtanNoMass"]=dnnnewfew18
#rebin["DNN18Atan"]=dnn062018
#rebin["DNN18AtanNoMass"]=dnn062018

#rebin["DNN18Atan2"]= [0 , 0.311666666667 , 0.635 , 0.845 , 1.04166666667 , 1.185 , 1.31666666667 , 1.42666666667 , 1.53166666667 , 1.645 , 1.76166666667 , 1.87 , 1.97666666667 , 2.07833333333 , 2.17666666667 , 2.27666666667 , 2.37666666667 , 2.485 , 2.61333333333 , 2.76333333333 , 2.96833333333 , 5.0 ]
#rebin["DNN18Atan2"]=  [0 , 0.49 , 0.768333333333 , 0.993333333333 , 1.15333333333 , 1.295 , 1.41 , 1.515 , 1.61833333333 , 1.73 , 1.83166666667 , 1.925 , 2.01166666667 , 2.09666666667 , 2.175 , 2.255 , 2.32666666667 , 2.40166666667 , 2.475 , 2.55666666667 , 2.645 , 2.73666666667 , 2.83833333333 , 2.96 , 3.13166666667 , 5.0 ]

#ebin["DNN18Atan"]=dnn032018
from histograms import genericHistos

#for i in  genericHistos :
#    rebin[i]=rebin["DNN18Atan"]

#from systematicGrouping import *
#systematicDetail = systematicGrouping(background, signal,jesList,"2018")
