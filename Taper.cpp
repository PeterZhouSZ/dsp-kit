#include "Taper.hpp"

using namespace dspkit;

const unsigned int Taper::Vu::ampPosTableSize = 32;

const float Taper::Vu::ampPosTable[] = {
        0.0, 0.3018581857609061, 0.3962114306366651, 0.49056467551242405, 0.5335667553239385, 0.5708631501283147,
        0.6081595449326909, 0.645455939737067, 0.6827523345414431, 0.7200487293458193, 0.7523227322011328,
        0.7641168878106025, 0.7759110434200724, 0.7877051990295422, 0.7994993546390121, 0.8112935102484821,
        0.8230876658579519, 0.8348818214674217, 0.8466759770768917, 0.8584701326863615, 0.8702642882958314,
        0.8820584439053013, 0.8938525995147711, 0.9056467551242411, 0.9174409107337109, 0.9292350663431808,
        0.9410292219526505, 0.9528233775621207, 0.9646175331715904, 0.9764116887810603, 0.9882058443905303, 1.0
};


const unsigned int Taper::LevelControl::posAmpTableSize = 256;

const float Taper::LevelControl::posAmpTable[] = {
        -9.480268995460547e-20, -0.0002033494299272541, -0.00034673615988545725, -0.0004335644036170834,
        -0.0004672383748646062, -0.00045116228737050013, -0.00038874035487723865, -0.0002833767911272958,
        -0.00013847580986314596, 4.255837517273749e-05, 0.00025632155023788054, 0.0004994095015898089,
        0.000768418015486049, 0.0010599428781841265, 0.0013705798759415678, 0.0016969247950158993, 0.002035573421664646,
        0.002383121542145335, 0.0027361649427154917, 0.0030912994096326434, 0.0034454397764059302, 0.003797858835138468,
        0.004148886221954352, 0.0044988565580909795, 0.004848104464785753, 0.005196964563276069, 0.0055457714747993315,
        0.0058948598205929344, 0.0062445642218942835, 0.006595219299940776, 0.006947159675969812, 0.007300719971218791,
        0.007656234806925111, 0.008014038804326174, 0.008374466584659382, 0.00873785276916213, 0.009104531979071823,
        0.009474838835625856, 0.00984910796006163, 0.010227676563334178, 0.010610920606247555, 0.010999245879316326,
        0.011393058940378797, 0.011792766347273274, 0.01219877465783806, 0.012611490429911474, 0.013031320221331813,
        0.013458670589937386, 0.013893948093566501, 0.014337559290057467, 0.01478991073724859, 0.015251408992978173,
        0.01572246061508453, 0.016203472161405958, 0.016694850189780775, 0.017197001258047285, 0.017710331924043792,
        0.018235248745608598, 0.018772158280580025, 0.01932146708679637, 0.019883581722095936, 0.020458908744317043,
        0.021047854711297987, 0.021650826180877082, 0.022268229710892623, 0.022900471859182946, 0.023547959183586317,
        0.024211098241941068, 0.024890295592085512, 0.025585957791857943, 0.02629849139909667, 0.02702830297164,
        0.02777579906732623, 0.028541386243993695, 0.029325471059480683, 0.0301284600716255, 0.03095075983826645,
        0.03179277629706578, 0.032654783908357146, 0.03353676378918925, 0.03443865736534184, 0.03536040606259461,
        0.03630195130672729, 0.037263234523519595, 0.03824419713875123, 0.03924478057820194, 0.04026492626765141,
        0.04130457563287936, 0.042363670099665546, 0.04344215109378964, 0.0445399600410314, 0.0456570383671705,
        0.04679332749798668, 0.04794876885925967, 0.049123303876769164, 0.0503168739762949, 0.05152942058361657,
        0.05276088512451392, 0.054011209024766645, 0.05528033371015448, 0.05656820060645712, 0.0578747511394543,
        0.05919992673492573, 0.060543668818651135, 0.061905918816410235, 0.06328661815398273, 0.06468570825714837,
        0.0661031305516868, 0.06753882646337785, 0.06899273741800112, 0.07046480484133642, 0.07195497015916341,
        0.07346317479726182, 0.07498936018141139, 0.07653346773739182, 0.07809543889098283, 0.07967521506796413,
        0.08127273769411546, 0.0828879481952165, 0.08452078799704699, 0.08617119852538666, 0.0878391212060152,
        0.08952449746471236, 0.09122726872725784, 0.09294737641943132, 0.09468476196701256, 0.0964393667957813,
        0.09821113233151721, 0.10000000000000002, 0.10180617386187978, 0.10363090851728766, 0.10547572120122525,
        0.10734212914869404, 0.10923164959469556, 0.11114579977423139, 0.11308609692230302, 0.11505405827391196,
        0.1170512010640598, 0.11907904252774804, 0.1211390998999782, 0.12323289041575183, 0.12536193131007042,
        0.12752773981793555, 0.12973183317434875, 0.1319757286143115, 0.1342609433728254, 0.13658899468489194,
        0.13896139978551264, 0.14137967590968906, 0.14384534029242269, 0.1463599101687151, 0.14892490277356785,
        0.1515418353419824, 0.15421222510896032, 0.15693758930950308, 0.1597194451786123, 0.16255930995128948,
        0.16545870086253617, 0.16841913514735382, 0.17144213004074405, 0.17452920277770834, 0.17768187059324822,
        0.1809016507223653, 0.184190060400061, 0.1875486168613369, 0.19097883734119453, 0.1944822390746354,
        0.19806033929666111, 0.2017146552422731, 0.20544670414647298, 0.20925800324426225, 0.21315006977064238,
        0.21712442096061502, 0.22118257404918157, 0.2253260462713437, 0.22955635486210282, 0.23387501705646047,
        0.23828355008941826, 0.2427834711959777, 0.24737629761114027, 0.2520635465699076, 0.256846735307281,
        0.2617273810582623, 0.26670700105785283, 0.27178711254105414, 0.27696923274286783, 0.2822548788982954,
        0.2876455682423384, 0.2931428180099983, 0.29874814543627665, 0.30446306775617504, 0.31028910220469497,
        0.3162277660168379, 0.32228057642760544, 0.32844905067199914, 0.3347347059850205, 0.341139059601671,
        0.3476636287569522, 0.3543099306858657, 0.36107948262341294, 0.3679738018045955, 0.37499440546441487,
        0.38214281083787266, 0.38942053515997027, 0.39682909566570934, 0.4043700095900914, 0.4120447941681179,
        0.4198549666347905, 0.4278020442251106, 0.4358875441740798, 0.4441129837166996, 0.4524798800879716,
        0.46098975052289715, 0.469644112256478, 0.4784444825237156, 0.48739237855961143, 0.49648931759916703,
        0.505736816877384, 0.5151363936292638, 0.524689565089808, 0.5343978484940182, 0.5442627610768958,
        0.5542858200734423, 0.5644685427186594, 0.5748124462475486, 0.5853190478951112, 0.5959898648963491,
        0.6068264144862635, 0.6178302138998562, 0.6290027803721284, 0.640345631138082, 0.6518602834327183,
        0.6635482544910388, 0.6754110615480452, 0.687450221838739, 0.6996672525981217, 0.7120636710611947,
        0.7246409944629597, 0.7374007400384183, 0.7503444250225717, 0.7634735666504218, 0.7767896821569696,
        0.7902942887772173, 0.8039889037461662, 0.8178750442988176, 0.8319542276701732, 0.8462279710952347,
        0.8606977918090035, 0.8753652070464808, 0.8902317340426685, 0.9052988900325681, 0.920568192251181,
        0.936041157933509, 0.9517193043145532, 0.9676041486293154, 0.9836972081127973, 1.0,
};