import ROOT
import os
import imp
import copy

#aa = os.popen('text2workspace.py workspace/datacard2018H.txt --dump-datacard | grep "DC\." | sed  's/DC.//g' | head -n -1 > datacard2018H.py')
#aa.read()

from systematicGrouping import getAllPossibleNuisanceParameters,systematicGrouping
allPossibleNuisances = getAllPossibleNuisanceParameters()
systematicDetail = systematicGrouping([],[])

postFitNuisancePy = "altro2.py"
outputFit = imp.load_source('outputFit', postFitNuisancePy).outputFit

postFitNuisancePy   = "datacard2018.py"
DCprocesses         = imp.load_source('outputFit', postFitNuisancePy).processes
DCsysts             = imp.load_source('outputFit', postFitNuisancePy).systs
DCbins              = imp.load_source('outputFit', postFitNuisancePy).bins

class Dummy(): pass

#~ bin_ = DCbins[0]
#bin_ = 'LeadMuon_pt___SignalRegion'
bin_ = 'ch2_LeadMuon_pt___SignalRegion'


nuisances = {}
for DCsyst in DCsysts:
    (name, boh, type_, boh2, datacardValues) = DCsyst
    nuisances[name] = Dummy()
    nuisances[name].boh = boh
    nuisances[name].type = type_
    nuisances[name].boh2 = boh2
    nuisances[name].datacardValues = datacardValues[bin_]
    nuisances[name].postfit_central = outputFit[name][0]
    nuisances[name].postfit_down = outputFit[name][1]
    nuisances[name].postfit_up = outputFit[name][2]

folder = "out"

newfolder = "out/postfit"
os.popen("mkdir -p %s"%(newfolder))

fNames = os.listdir(folder)

'''
def checkSystsWithNuisanceParameters(systs, nuisances):
    missingItems = systs - set(nuisances.keys())
    print("Warning: %s nuisance parameters are missing in %s."%(", ".join(missingItems), postFitNuisancePy))
    systs = systs - missingItems
    
    missingItems = set(nuisances.keys()) - systs
    print("Warning: %s nuisance parameters are missing in FitResult."%(", ".join(missingItems)))
'''



#~ def checkSystsWithNuisanceParameters(fileSysts, nuisances, allPossibleNuisances):
    #~ mcStat = set([i for i in nuisances.keys() if "prop_binch" in i])
    #~ missingItems = fileSysts - set(nuisances.keys())
    #~ print("Warning: %s nuisance parameters are missing in %s."%(", ".join(missingItems), postFitNuisancePy))
    #~ all = allSysts['lnN'].union(allSysts['shape'])
    #~ missingItems = all - set(nuisances.keys())
    #~ print("Warning: %s nuisance parameters are missing in %s."%(", ".join(missingItems), postFitNuisancePy))
    #~ for missingItem in missingItems: systs.remove(missingItem)
    
    #~ missingItems = set(nuisances.keys())  - mcStat - allSysts['lnN'] - allSysts['shape']
    #~ print("Warning: %s nuisance parameters are missing in FitResult."%(", ".join(missingItems)))

#~ #    print("Warning: %s nuisance parameters for MC stat."%(", ".join(mcStat)))
    
#~ #    print("Warning: %s nuisance parameters lnN syst."%(", ".join(allSysts['lnN'])))


def getSystHistoName(histos, nominalHistoName, nuis, ud):
    syst_ud = nuis + ud
    histoName  = nominalHistoName + "__syst__%s"%syst_ud
    histoName2 = nominalHistoName.replace("___","__syst__%s___"%syst_ud) + "__syst__%s"%syst_ud
    if histoName in histos:
        return histoName
    elif histoName2 in histos:
        return histoName2
    else:
        for histoName in histos:
            if histoName[:len(nominalHistoName)] == nominalHistoName:
                if histoName[-2:] == "Up":
                    lastWord = histoName.split("_")[-1]
                    if lastWord[:-2] in nuis: return histoName[:-2]+ud
    print('X'*20)
    print("Failed looking for %s of %s."%(nuis,nominalHistoName))
    print("%s nor %s found in."%(histoName,histoName2))
    print('X'*20)
    for histo in histos: print(histo)
    return "HistoSystNotFound"


#~ def getSystHistoName(histos, nominalHistoName, nuis, ud):
    #~ if nuis in systematicDetail
    #~ histoName  = nominalHistoName + "__syst__%s"%syst_ud
    #~ histoName2 = nominalHistoName.replace("___","__syst__%s___"%syst_ud) + "__syst__%s"%syst_ud
    #~ if histoName in histos:
        #~ return histoName
    #~ elif histoName2 in histos:
        #~ return histoName2
    #~ else:
        #~ print('X'*20)
        #~ print("%s nor %s found in."%(histoName,histoName2))
        #~ print('X'*20)
        #~ for histo in histos: print(histo)
        #~ return

'''
I calculate the post-fit histo as
nom' = nom*(N - nuis_1 - ... - - nuis_N) + nuis_1*syst_1 + ... + nuis_N*syst_N
where N is the number of nuisance
'''

def calculatePostFitHisto(sample, nominalHistoName, histos, nuisances):
    newHisto = histos[nominalHistoName].Clone()
    normSyst = 1.0
    debug = False
    if nominalHistoName == 'LeadMuon_pt___SignalRegion': debug = True
    if debug: print "*"*5+"   "+sample+"   "+"*"*5
    for nuis in nuisances:
#        print("%s"%(nuis))
#        print("%s"%(nuisances[nuis].datacardValues))
#        print("%s"%(nuisances[nuis].datacardValues[sample]))
        if sample in nuisances[nuis].datacardValues:
            if nuisances[nuis].datacardValues[sample]!=0:
                postFit = nuisances[nuis].postfit_central
                if nuisances[nuis].type == "shape":
                    ud = "Up" if postFit>0 else "Down"
                    nuisHistoName = getSystHistoName(histos, nominalHistoName, nuis, ud)
                    newHisto.Scale(1. - abs(postFit))
                    if debug: print("%s = (1 - %f) * %s + %f * %s"%(nominalHistoName, abs(postFit), nominalHistoName, abs(postFit), nuisHistoName))
                    newHisto.Add(histos[nuisHistoName], abs(postFit))
    #                print("done.")
                elif nuisances[nuis].type == "lnN":
                    if debug: print("%s:    normSyst = normSyst + normSyst * (%f - 1.) * %f"%(nuis, nuisances[nuis].datacardValues[sample], postFit))
                    normSyst = normSyst + normSyst * (nuisances[nuis].datacardValues[sample] - 1.) * postFit
                else:
                    if debug: print(nuis, nuisances[nuis].type, nuisances[nuis].datacardValues)
        else:
            #~ print(sample,nuis,nuisances[nuis].datacardValues)
            pass
        
    if debug: print("total SF = %f"%(normSyst))
    newHisto.Scale(normSyst)
    
    return newHisto

def createPostFitFile(inputFile, outputFile, nuisances):
    sample = inputFile.split("/")[-1].replace(".root","").replace("Histos","")
    if not sample in DCprocesses:
        print("Skipping %s"%outputFile)
        return
    print("Creating %s"%outputFile)
    inFile =  ROOT.TFile.Open(inputFile)
    outFile = ROOT.TFile.Open(outputFile,"recreate")
    histos = {}
    fileSysts = set()
    nominalHistoNames = set()
    for hKey in inFile.GetListOfKeys():
        histo = hKey.ReadObj()
        hName = histo.GetName()
        histos[hName] = histo
        if "_syst_" in hName:
            fileSysts.add(hName.split("_")[-1].replace("Up","").replace("Down",""))
            pass
        else:
            nominalHistoNames.add(histo.GetName())
#    checkSystsWithNuisanceParameters(fileSysts, nuisances, checkSystsWithNuisanceParameters)
#    1/0

    outFile.cd()
    # for hName in histos:
    #     print hName

    for nominalHistoName in nominalHistoNames:
        newHisto = calculatePostFitHisto(sample, nominalHistoName, histos, nuisances)
        newHisto.Write()
        for fileSyst in fileSysts:
            for ud in ["Up","Down"]:
                histoSysName = getSystHistoName(histos, nominalHistoName, fileSyst, ud)
                newHisto = histos[histoSysName].Clone()
                newHisto.Write()


    # print(systs)
    # print(nominalHistoNames)

    # print("len(histos) = %d"%len(histos))
    # print("len(systs) = %d"%len(systs))
    # print("len(nominalHistoNames) = %d"%len(nominalHistoNames))

    inFile.Close()
    outFile.Close()


os.popen("cp %s %s"%(postFitNuisancePy,newfolder))
for fName in fNames[:]:
    if ".root" in fName:
        createPostFitFile("%s/%s"%(folder,fName), "%s/%s"%(newfolder,fName), nuisances)
    elif ".txt" in fName:
        os.popen("cp %s/%s %s/%s"%(folder,fName,newfolder,fName))
    else:
        print("Please check file %s in %s"%(fName,folder))


#print(outputFit)
