path2018 = "/home/sdonato/Hmm/fileSkimFromNanoAOD/PROD_13_4/" #reduced JES

samples={

"DY105VBF_2018AMCPY"  : {"xsec": 2.03, "filter": "VBFFilterFlag" },# "files":["/scratchssd/mandorli/Hmumu/fileSkimFromNanoAOD/PROD_7_2/DY105VBF_2018AMCPY.root"], "training":False}, #this name has to change
"DY105VBF_2018MGPY"   : {"xsec": 2.03, "filter": "VBFFilterFlag"},

"EWKZ105_2018MGPYDIPOLE"   : {"xsec": 0.0789, "files":["/home/sdonato/Hmm/fileSkimFromNanoAOD/PROD_13_4/EWKZ105_2018MGPYDIPOLE.root"]},

#data2018V16": {"lumi":59970.,"data":True},


"vbfHmm_2018POWPYDIPOLE"  : {"xsec":0.0008210722},

"data2018": {"lumi":59970.,"data":True,"files":["/home/sdonato/Hmm/fileSkimFromNanoAOD/PROD_13_4/data2018.root"]},

}

## Add "files" automatically if not defined
for sample in samples:
    if not "files" in list(samples[sample].keys()):
        if "nameforfile" in list(samples[sample].keys()) :
            samples[sample]["files"] = [path2018+samples[sample]["nameforfile"]+".root"]
        else:
            samples[sample]["files"] = [path2018+sample+".root"]
