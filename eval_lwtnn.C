#include <eval_lwtnn.h>
#include <mva.h>
std::vector<std::string> v = {"/home/sdonato/fromlgiannini/output_fix_finalepoch.json"} ;
LwtnnWrapper lwtnn = LwtnnWrapper(v);

std::vector<std::string> v18 = {
"/home/sdonato/fromlgiannini/nn_evt0.json",
"/home/sdonato/fromlgiannini/nn_evt1.json",
"/home/sdonato/fromlgiannini/nn_evt2.json",
"/home/sdonato/fromlgiannini/nn_evt3.json"};
LwtnnWrapper lwtnn18 = LwtnnWrapper(v18);

std::vector<std::string> vall = {
"/home/sdonato/fromMandorli/nn_evt0_all.json",
"/home/sdonato/fromMandorli/nn_evt1_all.json",
"/home/sdonato/fromMandorli/nn_evt2_all.json",
"/home/sdonato/fromMandorli/nn_evt3_all.json"
};



// std::vector<std::string> vall = {
// "/home/sdonato/fromMandorli/nn_evt0_focal.json",
// "/home/sdonato/fromMandorli/nn_evt1_focal.json",
// "/home/sdonato/fromMandorli/nn_evt2_focal.json",
// "/home/sdonato/fromMandorli/nn_evt3_focal.json"
// };
LwtnnWrapper lwtnn_all = LwtnnWrapper(vall);



std::vector<std::string> vZ = {
"/home/sdonato/fromMandorli/NNZpeak_evt0.json",
"/home/sdonato/fromMandorli/NNZpeak_evt1.json",
"/home/sdonato/fromMandorli/NNZpeak_evt2.json",
"/home/sdonato/fromMandorli/NNZpeak_evt3.json"
};
LwtnnWrapper lwtnn_Z = LwtnnWrapper(vZ);


std::vector<std::string> vWithZ = {
"/home/sdonato/fromMandorli/nn_withZpeak_evt0.json",
"/home/sdonato/fromMandorli/nn_withZpeak_evt1.json",
"/home/sdonato/fromMandorli/nn_withZpeak_evt2.json",
"/home/sdonato/fromMandorli/nn_withZpeak_evt3.json"
};
LwtnnWrapper lwtnn_withZ = LwtnnWrapper(vWithZ);


std::vector<std::string> vNov = {
"/home/sdonato/fromMandorli/nn_evt0_nov.json",
"/home/sdonato/fromMandorli/nn_evt1_nov.json",
"/home/sdonato/fromMandorli/nn_evt2_nov.json",
"/home/sdonato/fromMandorli/nn_evt3_nov.json"
};
LwtnnWrapper lwtnn_nov = LwtnnWrapper(vNov);

std::vector<std::string> vFeb = {
"/home/sdonato/fromMandorli/nn_evt0_feb.json",
"/home/sdonato/fromMandorli/nn_evt1_feb.json",
"/home/sdonato/fromMandorli/nn_evt2_feb.json",
"/home/sdonato/fromMandorli/nn_evt3_feb.json"

//re-add ROCC
/*"/home/sdonato/fromMandorli/nn_evt0_may.json",
"/home/sdonato/fromMandorli/nn_evt1_may.json",
"/home/sdonato/fromMandorli/nn_evt2_may.json",
"/home/sdonato/fromMandorli/nn_evt3_may.json"
*/
};

std::vector<std::string> vFeb2 = {
"/home/sdonato/fromMandorli/nn_evt0_febNLO20.json",
"/home/sdonato/fromMandorli/nn_evt1_febNLO20.json",
"/home/sdonato/fromMandorli/nn_evt2_febNLO20.json",
"/home/sdonato/fromMandorli/nn_evt3_febNLO20.json"};

LwtnnWrapper lwtnn_feb2 = LwtnnWrapper(vFeb2);
LwtnnWrapper lwtnn_feb = LwtnnWrapper(vFeb);


