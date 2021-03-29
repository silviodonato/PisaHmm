rm -rf workspaceForPostFitHisto
rm -rf workspace/*root
rm -rf workspace/*txt
rm -rf workspace/*png
rm -rf workspace/*pyc
rm -rf workspace/datacard*
rm -rf workspace/combine*

python plot.py models2018H -f out/  -v LeadMuonPhase1_pt___SignalRegionPhase1 -o figure_prefit >& logPlotPrefit

cp -r workspace workspaceForPostFitHisto

### remove MC stat ###
#cat workspace/datacard2018H.txt | grep -v autoMC | grep -v -P "shape\t" > workspaceForPostFitHisto/datacard2018H.txt
cat workspace/datacard2018H.txt | grep -v autoMC > workspaceForPostFitHisto/datacard2018H.txt

python savePostFitHistos.py   >& logMakePostFitPlot

python plot.py models2018H -f out/postfit/  -v LeadMuonPhase1_pt___SignalRegionPhase1 -o figure_postfit  >& logPlotPostfit

