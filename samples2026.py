path2026 = "/scratchssd/thakore/PROD_2_0/" #reduced JES

samples={

"vbfHmm_powheg" : {"xsec": 0.0008210722 , "files": ["/scratchssd/thakore/PROD_2_0/vbfHmm_powheg_merged.root"] }, #xsec need to be set later on with actual values

"GluGluHToMuMu_powheg" : {"xsec": 0.0008210722 , "files": ["/scratchssd/thakore/PROD_2_0/GluGluHToMuMu_powheg_merged.root"] }, #xsec need to be set later on with actual values

"DYToLL_madgraphMLM" : {"xsec": 32.95, "files":["/scratchssd/thakore/PROD_2_0/DYToLL_madgraphMLM_merged.root"] },

"EWKZ2Jets_ZToLL_madgraph" : {"xsec": 4.38 , "files": ["/scratchssd/thakore/PROD_2_0/EWKZ2Jets_ZToLL_madgraph_merged.root"] },

"DYJets_MLL_50_madgraphMLM" : {"xsec": 5711, "files": ["/scratchssd/thakore/PROD_2_0/DYJets_MLL_50_madgraphMLM_merged.root"] }, 

"DYJetsToLL_M_100_madgraphMLM" : {"xsec": 246.5 , "files": ["/scratchssd/thakore/PROD_2_0/DYJetsToLL_M_100_madgraphMLM_merged.root"] },

"TT_Tune_powheg" : {"xsec": 864.4, "files": ["/scratchssd/thakore/PROD_2_0/TT_Tune_powheg_merged.root"] },

}


## Add "files" automatically if not defined
for sample in samples:
    if not "files" in list(samples[sample].keys()):
        if "nameforfile" in list(samples[sample].keys()) :
            samples[sample]["files"] = [path2026+samples[sample]["nameforfile"]+".root"]
        else:
            samples[sample]["files"] = [path2026+sample+".root"]
