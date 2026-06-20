__int64 *__fastcall dp_get_peer_per_pkt_stats(__int64 *result, __int64 a2)
{
  __int64 v3; // x20
  int v4; // w8
  __int64 *v5; // x8
  __int64 v6; // x23
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int64 v15; // x20
  __int64 v16; // x26
  __int64 v17; // x8
  __int64 v18; // x12
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x11
  __int64 v22; // x12
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x12
  __int64 v32; // x10
  __int64 v33; // x11
  __int64 v34; // x10
  __int64 v35; // x11
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x12
  int v39; // w10
  int v40; // w9
  int v41; // w10
  int v42; // w9
  int v43; // w10
  int v44; // w9
  int v45; // w10
  int v46; // w9
  int v47; // w10
  int v48; // w9
  int v49; // w10
  int v50; // w9
  int v51; // w10
  int v52; // w9
  int v53; // w10
  int v54; // w9
  int v55; // w10
  int v56; // w9
  int v57; // w10
  int v58; // w9
  int v59; // w10
  int v60; // w9
  int v61; // w10
  int v62; // w9
  int v63; // w10
  int v64; // w9
  __int64 v65; // x10
  __int64 v66; // x9
  __int64 v67; // x10
  __int64 v68; // x9
  __int64 v69; // x10
  __int64 v70; // x9
  __int64 v71; // x10
  __int64 v72; // x9
  __int64 v73; // x10
  __int64 v74; // x9
  __int64 v75; // x10
  __int64 v76; // x9
  __int64 v77; // x10
  __int64 v78; // x9
  __int64 v79; // x10
  __int64 v80; // x9
  __int64 v81; // x10
  __int64 v82; // x9
  __int64 v83; // x10
  __int64 v84; // x9
  __int64 v85; // x10
  __int64 v86; // x9
  __int64 v87; // x10
  __int64 v88; // x9
  __int64 v89; // x10
  __int64 v90; // x9
  __int64 v91; // x10
  __int64 v92; // x9
  __int64 v93; // x10
  __int64 v94; // x9
  __int64 v95; // x10
  __int64 v96; // x9
  __int64 v97; // x10
  __int64 v98; // x9
  __int64 v99; // x10
  __int64 v100; // x9
  __int64 v101; // x10
  __int64 v102; // x9
  __int64 v103; // x10
  __int64 v104; // x9
  __int64 v105; // x10
  __int64 v106; // x9
  __int64 v107; // x10
  __int64 v108; // x9
  __int64 v109; // x10
  __int64 v110; // x9
  __int64 v111; // x10
  __int64 v112; // x11
  __int64 v113; // x12
  __int64 v114; // x11
  __int64 v115; // x12
  __int64 v116; // x9
  __int64 v117; // x10
  __int64 v118; // x11
  __int64 v119; // x12
  __int64 v120; // x11
  __int64 v121; // x12
  __int64 v122; // x9
  __int64 v123; // x10
  __int64 v124; // x11
  __int64 v125; // x12
  __int64 v126; // x11
  __int64 v127; // x12
  __int64 v128; // x9
  __int64 v129; // x10
  __int64 v130; // x11
  __int64 v131; // x12
  __int64 v132; // x11
  __int64 v133; // x12
  __int64 v134; // x9
  __int64 v135; // x10
  __int64 v136; // x11
  __int64 v137; // x12
  __int64 v138; // x11
  __int64 v139; // x12
  __int64 v140; // x9
  __int64 v141; // x10
  __int64 v142; // x11
  __int64 v143; // x12
  __int64 v144; // x11
  __int64 v145; // x12
  __int64 v146; // x9
  __int64 v147; // x10
  __int64 v148; // x11
  __int64 v149; // x12
  __int64 v150; // x9
  __int64 v151; // x10
  __int64 v152; // x9
  __int64 v153; // x10
  __int64 v154; // x9
  __int64 v155; // x10
  __int64 v156; // x9
  __int64 v157; // x10
  __int64 v158; // x9
  __int64 v159; // x10
  __int64 v160; // x9
  __int64 v161; // x10
  __int64 v162; // x9
  __int64 v163; // x10
  __int64 v164; // x9
  __int64 v165; // x10
  __int64 v166; // x9
  __int64 v167; // x10
  __int64 v168; // x9
  __int64 v169; // x10
  __int64 v170; // x9
  unsigned int v171; // w8
  unsigned __int8 peer_link_id; // w0
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  __int64 v182; // x9
  __int64 v183; // x10
  __int64 v184; // x12
  __int64 v185; // x8
  __int64 v186; // x11
  __int64 v187; // x12
  __int64 v188; // x8
  __int64 v189; // x11
  __int64 v190; // x12
  __int64 v191; // x8
  __int64 v192; // x11
  __int64 v193; // x12
  __int64 v194; // x8
  __int64 v195; // x11
  __int64 v196; // x12
  __int64 v197; // x8
  __int64 v198; // x11
  __int64 v199; // x8
  __int64 v200; // x11
  __int64 v201; // x8
  __int64 v202; // x8
  __int64 v203; // x10
  __int64 v204; // x11
  int v205; // w12
  __int64 v206; // x11
  __int64 v207; // x12
  int v208; // w10
  int v209; // w9
  int v210; // w10
  int v211; // w9
  int v212; // w10
  int v213; // w9
  int v214; // w10
  int v215; // w9
  int v216; // w10
  int v217; // w9
  int v218; // w10
  int v219; // w9
  int v220; // w10
  int v221; // w9
  int v222; // w10
  int v223; // w9
  int v224; // w10
  int v225; // w9
  int v226; // w10
  int v227; // w9
  int v228; // w10
  int v229; // w9
  int v230; // w10
  int v231; // w9
  int v232; // w10
  int v233; // w9
  __int64 v234; // x10
  __int64 v235; // x9
  __int64 v236; // x10
  __int64 v237; // x9
  __int64 v238; // x10
  __int64 v239; // x9
  __int64 v240; // x10
  __int64 v241; // x9
  __int64 v242; // x10
  __int64 v243; // x9
  __int64 v244; // x10
  __int64 v245; // x9
  __int64 v246; // x10
  __int64 v247; // x9
  __int64 v248; // x10
  __int64 v249; // x9
  __int64 v250; // x10
  __int64 v251; // x9
  __int64 v252; // x10
  __int64 v253; // x9
  __int64 v254; // x10
  __int64 v255; // x9
  __int64 v256; // x10
  __int64 v257; // x9
  __int64 v258; // x10
  __int64 v259; // x9
  __int64 v260; // x10
  __int64 v261; // x9
  __int64 v262; // x10
  __int64 v263; // x9
  __int64 v264; // x10
  __int64 v265; // x9
  __int64 v266; // x10
  __int64 v267; // x9
  __int64 v268; // x10
  __int64 v269; // x9
  __int64 v270; // x10
  __int64 v271; // x9
  __int64 v272; // x10
  __int64 v273; // x9
  __int64 v274; // x10
  __int64 v275; // x9
  __int64 v276; // x10
  __int64 v277; // x9
  __int64 v278; // x10
  __int64 v279; // x9
  __int64 v280; // x10
  __int64 v281; // x11
  __int64 v282; // x12
  __int64 v283; // x11
  __int64 v284; // x12
  __int64 v285; // x9
  __int64 v286; // x10
  __int64 v287; // x11
  __int64 v288; // x12
  __int64 v289; // x11
  __int64 v290; // x12
  __int64 v291; // x9
  __int64 v292; // x10
  __int64 v293; // x11
  __int64 v294; // x12
  __int64 v295; // x11
  __int64 v296; // x12
  __int64 v297; // x9
  __int64 v298; // x10
  __int64 v299; // x11
  __int64 v300; // x12
  __int64 v301; // x11
  __int64 v302; // x12
  __int64 v303; // x9
  __int64 v304; // x10
  __int64 v305; // x11
  __int64 v306; // x12
  __int64 v307; // x11
  __int64 v308; // x12
  __int64 v309; // x9
  __int64 v310; // x10
  __int64 v311; // x11
  __int64 v312; // x12
  __int64 v313; // x11
  __int64 v314; // x12
  __int64 v315; // x9
  __int64 v316; // x10
  __int64 v317; // x11
  __int64 v318; // x12
  __int64 v319; // x9
  __int64 v320; // x10
  __int64 v321; // x9
  __int64 v322; // x10
  __int64 v323; // x9
  __int64 v324; // x10
  __int64 v325; // x9
  __int64 v326; // x10
  __int64 v327; // x9
  __int64 v328; // x10
  __int64 v329; // x9
  __int64 v330; // x10
  __int64 v331; // x9
  __int64 v332; // x10
  __int64 v333; // x9
  __int64 v334; // x10
  __int64 v335; // x9
  __int64 v336; // x10
  __int64 v337; // x9
  __int64 v338; // x10
  __int64 v339; // x9
  __int64 *v340; // [xsp+0h] [xbp-30h] BYREF
  __int64 *v341; // [xsp+8h] [xbp-28h]
  __int64 *v342; // [xsp+10h] [xbp-20h]
  __int64 *v343; // [xsp+18h] [xbp-18h]
  __int64 v344; // [xsp+20h] [xbp-10h]
  __int64 v345; // [xsp+28h] [xbp-8h]

  v3 = (__int64)result;
  v345 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_DWORD *)result + 102);
  v343 = nullptr;
  v344 = 0;
  v341 = nullptr;
  v342 = nullptr;
  v340 = nullptr;
  if ( v4 == 1 )
  {
    v5 = (__int64 *)result[52];
    if ( v5 )
    {
      v6 = *v5;
      if ( !*v5 )
        goto LABEL_19;
    }
    else
    {
      v6 = *result;
      if ( !*result )
        goto LABEL_19;
    }
LABEL_16:
    peer_link_id = dp_get_peer_link_id(result);
    v182 = 0;
    v183 = v6 + 4072LL * peer_link_id;
    v184 = *(_QWORD *)(a2 + 32);
    *(_QWORD *)(a2 + 24) += *(_QWORD *)(v183 + 2288);
    v185 = v184 + *(_QWORD *)(v183 + 2296);
    v186 = *(_QWORD *)(a2 + 40);
    v187 = *(_QWORD *)(a2 + 48);
    *(_QWORD *)(a2 + 32) = v185;
    *(_QWORD *)(a2 + 40) = v186 + *(_QWORD *)(v183 + 2304);
    v188 = v187 + *(_QWORD *)(v183 + 2312);
    v189 = *(_QWORD *)(a2 + 56);
    v190 = *(_QWORD *)(a2 + 64);
    *(_QWORD *)(a2 + 48) = v188;
    *(_QWORD *)(a2 + 56) = v189 + *(_QWORD *)(v183 + 2320);
    v191 = v190 + *(_QWORD *)(v183 + 2328);
    v192 = *(_QWORD *)(a2 + 72);
    v193 = *(_QWORD *)(a2 + 80);
    *(_QWORD *)(a2 + 64) = v191;
    *(_QWORD *)(a2 + 72) = v192 + *(_QWORD *)(v183 + 2336);
    v194 = v193 + *(_QWORD *)(v183 + 2344);
    v195 = *(_QWORD *)(a2 + 88);
    v196 = *(_QWORD *)(a2 + 96);
    *(_QWORD *)(a2 + 80) = v194;
    v197 = v195 + *(_QWORD *)(v183 + 2352);
    LODWORD(v195) = *(_DWORD *)(a2 + 104);
    *(_QWORD *)(a2 + 88) = v197;
    *(_QWORD *)(a2 + 96) = v196 + *(_QWORD *)(v183 + 2360);
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2368);
    LODWORD(v195) = *(_DWORD *)(a2 + 112);
    *(_DWORD *)(a2 + 104) = v197;
    *(_DWORD *)(a2 + 112) = v195 + *(_DWORD *)(v183 + 2372);
    LODWORD(v196) = *(_DWORD *)(a2 + 136);
    LODWORD(v195) = *(_DWORD *)(a2 + 956);
    *(_DWORD *)(a2 + 132) += *(_DWORD *)(v183 + 2376);
    *(_DWORD *)(a2 + 136) = v196 + *(_DWORD *)(v183 + 2380);
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2464);
    LODWORD(v195) = *(_DWORD *)(a2 + 960);
    *(_DWORD *)(a2 + 956) = v197;
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2468);
    LODWORD(v195) = *(_DWORD *)(a2 + 964);
    *(_DWORD *)(a2 + 960) = v197;
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2472);
    LODWORD(v195) = *(_DWORD *)(a2 + 2096);
    *(_DWORD *)(a2 + 964) = v197;
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2836);
    LODWORD(v195) = *(_DWORD *)(a2 + 968);
    *(_DWORD *)(a2 + 2096) = v197;
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2476);
    LODWORD(v195) = *(_DWORD *)(a2 + 972);
    *(_DWORD *)(a2 + 968) = v197;
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2480);
    LODWORD(v195) = *(_DWORD *)(a2 + 976);
    *(_DWORD *)(a2 + 972) = v197;
    LODWORD(v197) = v195 + *(_DWORD *)(v183 + 2484);
    v198 = *(_QWORD *)(a2 + 1816);
    *(_DWORD *)(a2 + 976) = v197;
    v199 = v198 + *(_QWORD *)(v183 + 2744);
    v200 = *(_QWORD *)(a2 + 1824);
    *(_QWORD *)(a2 + 1816) = v199;
    v201 = v200 + *(_QWORD *)(v183 + 2752);
    LODWORD(v200) = *(_DWORD *)(a2 + 2072);
    *(_QWORD *)(a2 + 1824) = v201;
    *(_QWORD *)(a2 + 1840) = *(_QWORD *)(v183 + 2760);
    LODWORD(v200) = v200 + *(_DWORD *)(v183 + 2832);
    v202 = v183 + 2288;
    v203 = v183 + 2488;
    *(_DWORD *)(a2 + 2072) = v200;
    do
    {
      v204 = a2 + v182;
      v205 = *(_DWORD *)(v203 + v182);
      v182 += 4;
      *(_DWORD *)(v204 + 1564) += v205;
    }
    while ( v182 != 252 );
    v206 = *(_QWORD *)(a2 + 2904);
    v207 = *(_QWORD *)(a2 + 2784);
    v208 = *(_DWORD *)(a2 + 2176);
    *(_DWORD *)(a2 + 2172) += *(_DWORD *)(v202 + 552);
    v209 = v208 + *(_DWORD *)(v202 + 556);
    v210 = *(_DWORD *)(a2 + 2180);
    *(_DWORD *)(a2 + 2176) = v209;
    v211 = v210 + *(_DWORD *)(v202 + 560);
    v212 = *(_DWORD *)(a2 + 2184);
    *(_DWORD *)(a2 + 2180) = v211;
    v213 = v212 + *(_DWORD *)(v202 + 564);
    v214 = *(_DWORD *)(a2 + 2188);
    *(_DWORD *)(a2 + 2184) = v213;
    v215 = v214 + *(_DWORD *)(v202 + 568);
    v216 = *(_DWORD *)(a2 + 2192);
    *(_DWORD *)(a2 + 2188) = v215;
    v217 = v216 + *(_DWORD *)(v202 + 572);
    v218 = *(_DWORD *)(a2 + 2196);
    *(_DWORD *)(a2 + 2192) = v217;
    v219 = v218 + *(_DWORD *)(v202 + 576);
    v220 = *(_DWORD *)(a2 + 2200);
    *(_DWORD *)(a2 + 2196) = v219;
    v221 = v220 + *(_DWORD *)(v202 + 580);
    v222 = *(_DWORD *)(a2 + 2204);
    *(_DWORD *)(a2 + 2200) = v221;
    v223 = v222 + *(_DWORD *)(v202 + 584);
    v224 = *(_DWORD *)(a2 + 2208);
    *(_DWORD *)(a2 + 2204) = v223;
    v225 = v224 + *(_DWORD *)(v202 + 588);
    v226 = *(_DWORD *)(a2 + 2212);
    *(_DWORD *)(a2 + 2208) = v225;
    v227 = v226 + *(_DWORD *)(v202 + 592);
    v228 = *(_DWORD *)(a2 + 2216);
    *(_DWORD *)(a2 + 2212) = v227;
    v229 = v228 + *(_DWORD *)(v202 + 596);
    v230 = *(_DWORD *)(a2 + 2220);
    *(_DWORD *)(a2 + 2216) = v229;
    v231 = v230 + *(_DWORD *)(v202 + 600);
    v232 = *(_DWORD *)(a2 + 2224);
    *(_DWORD *)(a2 + 2220) = v231;
    v233 = v232 + *(_DWORD *)(v202 + 604);
    v234 = *(_QWORD *)(a2 + 2960);
    *(_DWORD *)(a2 + 2224) = v233;
    v235 = v234 + *(_QWORD *)(v202 + 784);
    v236 = *(_QWORD *)(a2 + 2968);
    *(_QWORD *)(a2 + 2960) = v235;
    v237 = v236 + *(_QWORD *)(v202 + 792);
    v238 = *(_QWORD *)(a2 + 3048);
    *(_QWORD *)(a2 + 2968) = v237;
    v239 = v238 + *(_QWORD *)(v202 + 992);
    v240 = *(_QWORD *)(a2 + 3056);
    *(_QWORD *)(a2 + 3048) = v239;
    v241 = v240 + *(_QWORD *)(v202 + 1000);
    v242 = *(_QWORD *)(a2 + 2976);
    *(_QWORD *)(a2 + 3056) = v241;
    v243 = v242 + *(_QWORD *)(v202 + 800);
    v244 = *(_QWORD *)(a2 + 2984);
    *(_QWORD *)(a2 + 2976) = v243;
    v245 = v244 + *(_QWORD *)(v202 + 808);
    v246 = *(_QWORD *)(a2 + 2944);
    *(_QWORD *)(a2 + 2984) = v245;
    v247 = v246 + *(_QWORD *)(v202 + 768);
    v248 = *(_QWORD *)(a2 + 2952);
    *(_QWORD *)(a2 + 2944) = v247;
    v249 = v248 + *(_QWORD *)(v202 + 776);
    v250 = *(_QWORD *)(a2 + 2992);
    *(_QWORD *)(a2 + 2952) = v249;
    v251 = v250 + *(_QWORD *)(v202 + 816);
    v252 = *(_QWORD *)(a2 + 3000);
    *(_QWORD *)(a2 + 2992) = v251;
    v253 = v252 + *(_QWORD *)(v202 + 824);
    LODWORD(v252) = *(_DWORD *)(a2 + 3008);
    *(_QWORD *)(a2 + 3000) = v253;
    LODWORD(v253) = v252 + *(_DWORD *)(v202 + 832);
    LODWORD(v252) = *(_DWORD *)(a2 + 4452);
    *(_DWORD *)(a2 + 3008) = v253;
    LODWORD(v253) = v252 + *(_DWORD *)(v202 + 1008);
    v254 = *(_QWORD *)(a2 + 3016);
    *(_DWORD *)(a2 + 4452) = v253;
    v255 = v254 + *(_QWORD *)(v202 + 840);
    v256 = *(_QWORD *)(a2 + 3024);
    *(_QWORD *)(a2 + 3016) = v255;
    v257 = v256 + *(_QWORD *)(v202 + 848);
    v258 = *(_QWORD *)(a2 + 3032);
    *(_QWORD *)(a2 + 3024) = v257;
    v259 = v258 + *(_QWORD *)(v202 + 856);
    v260 = *(_QWORD *)(a2 + 3040);
    *(_QWORD *)(a2 + 3032) = v259;
    v261 = v260 + *(_QWORD *)(v202 + 864);
    v262 = *(_QWORD *)(a2 + 3072);
    *(_QWORD *)(a2 + 3040) = v261;
    v263 = v262 + *(_QWORD *)(v202 + 880);
    v264 = *(_QWORD *)(a2 + 3080);
    *(_QWORD *)(a2 + 3072) = v263;
    v265 = v264 + *(_QWORD *)(v202 + 888);
    v266 = *(_QWORD *)(a2 + 3088);
    *(_QWORD *)(a2 + 3080) = v265;
    v267 = v266 + *(_QWORD *)(v202 + 896);
    v268 = *(_QWORD *)(a2 + 3096);
    *(_QWORD *)(a2 + 3088) = v267;
    v269 = v268 + *(_QWORD *)(v202 + 904);
    LODWORD(v268) = *(_DWORD *)(a2 + 3104);
    *(_QWORD *)(a2 + 3096) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 912);
    LODWORD(v268) = *(_DWORD *)(a2 + 3112);
    *(_DWORD *)(a2 + 3104) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 920);
    LODWORD(v268) = *(_DWORD *)(a2 + 3116);
    *(_DWORD *)(a2 + 3112) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 924);
    LODWORD(v268) = *(_DWORD *)(a2 + 3120);
    *(_DWORD *)(a2 + 3116) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 928);
    LODWORD(v268) = *(_DWORD *)(a2 + 3124);
    *(_DWORD *)(a2 + 3120) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 932);
    LODWORD(v268) = *(_DWORD *)(a2 + 3128);
    *(_DWORD *)(a2 + 3124) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 936);
    LODWORD(v268) = *(_DWORD *)(a2 + 3132);
    *(_DWORD *)(a2 + 3128) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 940);
    LODWORD(v268) = *(_DWORD *)(a2 + 3136);
    *(_DWORD *)(a2 + 3132) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 944);
    LODWORD(v268) = *(_DWORD *)(a2 + 4012);
    *(_DWORD *)(a2 + 3136) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 948);
    LODWORD(v268) = *(_DWORD *)(a2 + 4016);
    *(_DWORD *)(a2 + 4012) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 952);
    LODWORD(v268) = *(_DWORD *)(a2 + 4080);
    *(_DWORD *)(a2 + 4016) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 956);
    LODWORD(v268) = *(_DWORD *)(a2 + 4124);
    *(_DWORD *)(a2 + 4080) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 960);
    LODWORD(v268) = *(_DWORD *)(a2 + 4128);
    *(_DWORD *)(a2 + 4124) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 964);
    LODWORD(v268) = *(_DWORD *)(a2 + 4132);
    *(_DWORD *)(a2 + 4128) = v269;
    LODWORD(v269) = v268 + *(_DWORD *)(v202 + 968);
    v270 = *(_QWORD *)(a2 + 4208);
    *(_DWORD *)(a2 + 4132) = v269;
    v271 = v270 + *(_QWORD *)(v202 + 976);
    v272 = *(_QWORD *)(a2 + 4216);
    *(_QWORD *)(a2 + 4208) = v271;
    v273 = v272 + *(_QWORD *)(v202 + 984);
    LODWORD(v272) = *(_DWORD *)(a2 + 4464);
    *(_QWORD *)(a2 + 4216) = v273;
    *(_QWORD *)(a2 + 3064) = *(_QWORD *)(v202 + 872);
    LODWORD(v273) = v272 + *(_DWORD *)(v202 + 1032);
    v274 = *(_QWORD *)(a2 + 2768);
    *(_DWORD *)(a2 + 4464) = v273;
    v275 = v274 + *(_QWORD *)(v202 + 608);
    v276 = *(_QWORD *)(a2 + 2776);
    *(_QWORD *)(a2 + 2768) = v275;
    v277 = v276 + *(_QWORD *)(v202 + 616);
    v278 = *(_QWORD *)(a2 + 2896);
    *(_QWORD *)(a2 + 2776) = v277;
    v279 = v278 + *(_QWORD *)(v202 + 608);
    *(_QWORD *)(a2 + 2896) = v279;
    v280 = v206 + *(_QWORD *)(v202 + 616);
    *(_QWORD *)(a2 + 2904) = v280;
    v281 = v207 + *(_QWORD *)(v202 + 624);
    v282 = *(_QWORD *)(a2 + 2792);
    *(_QWORD *)(a2 + 2784) = v281;
    v283 = v282 + *(_QWORD *)(v202 + 632);
    v284 = *(_QWORD *)(a2 + 2800);
    *(_QWORD *)(a2 + 2792) = v283;
    v285 = v279 + *(_QWORD *)(v202 + 624);
    *(_QWORD *)(a2 + 2896) = v285;
    v286 = v280 + *(_QWORD *)(v202 + 632);
    *(_QWORD *)(a2 + 2904) = v286;
    v287 = v284 + *(_QWORD *)(v202 + 640);
    v288 = *(_QWORD *)(a2 + 2808);
    *(_QWORD *)(a2 + 2800) = v287;
    v289 = v288 + *(_QWORD *)(v202 + 648);
    v290 = *(_QWORD *)(a2 + 2816);
    *(_QWORD *)(a2 + 2808) = v289;
    v291 = v285 + *(_QWORD *)(v202 + 640);
    *(_QWORD *)(a2 + 2896) = v291;
    v292 = v286 + *(_QWORD *)(v202 + 648);
    *(_QWORD *)(a2 + 2904) = v292;
    v293 = v290 + *(_QWORD *)(v202 + 656);
    v294 = *(_QWORD *)(a2 + 2824);
    *(_QWORD *)(a2 + 2816) = v293;
    v295 = v294 + *(_QWORD *)(v202 + 664);
    v296 = *(_QWORD *)(a2 + 2832);
    *(_QWORD *)(a2 + 2824) = v295;
    v297 = v291 + *(_QWORD *)(v202 + 656);
    *(_QWORD *)(a2 + 2896) = v297;
    v298 = v292 + *(_QWORD *)(v202 + 664);
    *(_QWORD *)(a2 + 2904) = v298;
    v299 = v296 + *(_QWORD *)(v202 + 672);
    v300 = *(_QWORD *)(a2 + 2840);
    *(_QWORD *)(a2 + 2832) = v299;
    v301 = v300 + *(_QWORD *)(v202 + 680);
    v302 = *(_QWORD *)(a2 + 2848);
    *(_QWORD *)(a2 + 2840) = v301;
    v303 = v297 + *(_QWORD *)(v202 + 672);
    *(_QWORD *)(a2 + 2896) = v303;
    v304 = v298 + *(_QWORD *)(v202 + 680);
    *(_QWORD *)(a2 + 2904) = v304;
    v305 = v302 + *(_QWORD *)(v202 + 688);
    v306 = *(_QWORD *)(a2 + 2856);
    *(_QWORD *)(a2 + 2848) = v305;
    v307 = v306 + *(_QWORD *)(v202 + 696);
    v308 = *(_QWORD *)(a2 + 2864);
    *(_QWORD *)(a2 + 2856) = v307;
    v309 = v303 + *(_QWORD *)(v202 + 688);
    *(_QWORD *)(a2 + 2896) = v309;
    v310 = v304 + *(_QWORD *)(v202 + 696);
    *(_QWORD *)(a2 + 2904) = v310;
    v311 = v308 + *(_QWORD *)(v202 + 704);
    v312 = *(_QWORD *)(a2 + 2872);
    *(_QWORD *)(a2 + 2864) = v311;
    v313 = v312 + *(_QWORD *)(v202 + 712);
    v314 = *(_QWORD *)(a2 + 2880);
    *(_QWORD *)(a2 + 2872) = v313;
    v315 = v309 + *(_QWORD *)(v202 + 704);
    *(_QWORD *)(a2 + 2896) = v315;
    v316 = v310 + *(_QWORD *)(v202 + 712);
    *(_QWORD *)(a2 + 2904) = v316;
    v317 = v314 + *(_QWORD *)(v202 + 720);
    v318 = *(_QWORD *)(a2 + 2888);
    *(_QWORD *)(a2 + 2880) = v317;
    *(_QWORD *)(a2 + 2888) = v318 + *(_QWORD *)(v202 + 728);
    *(_QWORD *)(a2 + 2896) = v315 + *(_QWORD *)(v202 + 720);
    v319 = v316 + *(_QWORD *)(v202 + 728);
    v320 = *(_QWORD *)(a2 + 2912);
    *(_QWORD *)(a2 + 2904) = v319;
    v321 = v320 + *(_QWORD *)(v202 + 736);
    v322 = *(_QWORD *)(a2 + 2920);
    *(_QWORD *)(a2 + 2912) = v321;
    v323 = v322 + *(_QWORD *)(v202 + 744);
    v324 = *(_QWORD *)(a2 + 2928);
    *(_QWORD *)(a2 + 2920) = v323;
    v325 = v324 + *(_QWORD *)(v202 + 752);
    v326 = *(_QWORD *)(a2 + 2936);
    *(_QWORD *)(a2 + 2928) = v325;
    v327 = v326 + *(_QWORD *)(v202 + 760);
    v328 = *(_QWORD *)(a2 + 4504);
    *(_QWORD *)(a2 + 2936) = v327;
    v329 = v328 + *(_QWORD *)(v202 + 1016);
    v330 = *(_QWORD *)(a2 + 4512);
    *(_QWORD *)(a2 + 4504) = v329;
    v331 = v330 + *(_QWORD *)(v202 + 1024);
    v332 = *(_QWORD *)(a2 + 760);
    *(_QWORD *)(a2 + 4512) = v331;
    v333 = v332 + *(unsigned int *)(v202 + 100);
    v334 = *(_QWORD *)(a2 + 768);
    *(_QWORD *)(a2 + 760) = v333;
    v335 = v334 + *(_QWORD *)(v202 + 160);
    LODWORD(v334) = *(_DWORD *)(a2 + 776);
    *(_QWORD *)(a2 + 768) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v202 + 108);
    v336 = *(_QWORD *)(a2 + 784);
    *(_DWORD *)(a2 + 776) = v335;
    v337 = v336 + *(unsigned int *)(v202 + 104);
    v338 = *(_QWORD *)(a2 + 792);
    *(_QWORD *)(a2 + 784) = v337;
    v339 = v338 + *(_QWORD *)(v202 + 168);
    LODWORD(v338) = *(_DWORD *)(a2 + 800);
    *(_QWORD *)(a2 + 792) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 112);
    LODWORD(v338) = *(_DWORD *)(a2 + 804);
    *(_DWORD *)(a2 + 800) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 116);
    LODWORD(v338) = *(_DWORD *)(a2 + 808);
    *(_DWORD *)(a2 + 804) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 120);
    LODWORD(v338) = *(_DWORD *)(a2 + 812);
    *(_DWORD *)(a2 + 808) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 124);
    LODWORD(v338) = *(_DWORD *)(a2 + 816);
    *(_DWORD *)(a2 + 812) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 128);
    LODWORD(v338) = *(_DWORD *)(a2 + 820);
    *(_DWORD *)(a2 + 816) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 132);
    LODWORD(v338) = *(_DWORD *)(a2 + 824);
    *(_DWORD *)(a2 + 820) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 136);
    LODWORD(v338) = *(_DWORD *)(a2 + 828);
    *(_DWORD *)(a2 + 824) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 140);
    LODWORD(v338) = *(_DWORD *)(a2 + 832);
    *(_DWORD *)(a2 + 828) = v339;
    LODWORD(v339) = v338 + *(_DWORD *)(v202 + 144);
    LODWORD(v338) = *(_DWORD *)(a2 + 836);
    *(_DWORD *)(a2 + 832) = v339;
    *(_DWORD *)(a2 + 836) = v338 + *(_DWORD *)(v202 + 148);
    *(_DWORD *)(a2 + 840) += *(_DWORD *)(v202 + 156);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: get stats from peer %d link_id %d",
      v174,
      v175,
      v176,
      v177,
      v178,
      v179,
      v180,
      v181,
      "dp_get_peer_per_pkt_stats",
      *(unsigned __int16 *)(v6 + 8),
      peer_link_id);
    result = (__int64 *)qdf_mem_copy((void *)a2, (const void *)(v3 + 44), 6u);
    goto LABEL_19;
  }
  v6 = *result;
  if ( !*result )
    goto LABEL_19;
  if ( v4 != 2 )
    goto LABEL_16;
  result = (__int64 *)dp_get_link_peers_ref_from_mld_peer(
                        *(_QWORD *)(*(_QWORD *)(result[3] + 24) + 8LL),
                        (int)result,
                        (int)&v340);
  if ( (_BYTE)v344 )
  {
    v15 = 0;
    v16 = v6 + 2488;
    while ( 1 )
    {
      v17 = v6 + 2288 + 4072 * v15;
      v18 = *(_QWORD *)(a2 + 32);
      v19 = 0;
      *(_QWORD *)(a2 + 24) += *(_QWORD *)v17;
      v20 = v18 + *(_QWORD *)(v17 + 8);
      v21 = *(_QWORD *)(a2 + 40);
      v22 = *(_QWORD *)(a2 + 48);
      *(_QWORD *)(a2 + 32) = v20;
      *(_QWORD *)(a2 + 40) = v21 + *(_QWORD *)(v17 + 16);
      v23 = v22 + *(_QWORD *)(v17 + 24);
      v24 = *(_QWORD *)(a2 + 56);
      v25 = *(_QWORD *)(a2 + 64);
      *(_QWORD *)(a2 + 48) = v23;
      *(_QWORD *)(a2 + 56) = v24 + *(_QWORD *)(v17 + 32);
      v26 = v25 + *(_QWORD *)(v17 + 40);
      v27 = *(_QWORD *)(a2 + 72);
      v28 = *(_QWORD *)(a2 + 80);
      *(_QWORD *)(a2 + 64) = v26;
      *(_QWORD *)(a2 + 72) = v27 + *(_QWORD *)(v17 + 48);
      v29 = v28 + *(_QWORD *)(v17 + 56);
      v30 = *(_QWORD *)(a2 + 88);
      v31 = *(_QWORD *)(a2 + 96);
      *(_QWORD *)(a2 + 80) = v29;
      v32 = v30 + *(_QWORD *)(v17 + 64);
      LODWORD(v30) = *(_DWORD *)(a2 + 104);
      *(_QWORD *)(a2 + 88) = v32;
      *(_QWORD *)(a2 + 96) = v31 + *(_QWORD *)(v17 + 72);
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 80);
      LODWORD(v30) = *(_DWORD *)(a2 + 112);
      *(_DWORD *)(a2 + 104) = v32;
      *(_DWORD *)(a2 + 112) = v30 + *(_DWORD *)(v17 + 84);
      LODWORD(v31) = *(_DWORD *)(a2 + 136);
      LODWORD(v30) = *(_DWORD *)(a2 + 956);
      *(_DWORD *)(a2 + 132) += *(_DWORD *)(v17 + 88);
      *(_DWORD *)(a2 + 136) = v31 + *(_DWORD *)(v17 + 92);
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 176);
      LODWORD(v30) = *(_DWORD *)(a2 + 960);
      *(_DWORD *)(a2 + 956) = v32;
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 180);
      LODWORD(v30) = *(_DWORD *)(a2 + 964);
      *(_DWORD *)(a2 + 960) = v32;
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 184);
      LODWORD(v30) = *(_DWORD *)(a2 + 2096);
      *(_DWORD *)(a2 + 964) = v32;
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 548);
      LODWORD(v30) = *(_DWORD *)(a2 + 968);
      *(_DWORD *)(a2 + 2096) = v32;
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 188);
      LODWORD(v30) = *(_DWORD *)(a2 + 972);
      *(_DWORD *)(a2 + 968) = v32;
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 192);
      LODWORD(v30) = *(_DWORD *)(a2 + 976);
      *(_DWORD *)(a2 + 972) = v32;
      LODWORD(v32) = v30 + *(_DWORD *)(v17 + 196);
      v33 = *(_QWORD *)(a2 + 1816);
      *(_DWORD *)(a2 + 976) = v32;
      v34 = v33 + *(_QWORD *)(v17 + 456);
      v35 = *(_QWORD *)(a2 + 1824);
      *(_QWORD *)(a2 + 1816) = v34;
      v36 = v35 + *(_QWORD *)(v17 + 464);
      LODWORD(v35) = *(_DWORD *)(a2 + 2072);
      *(_QWORD *)(a2 + 1824) = v36;
      *(_QWORD *)(a2 + 1840) = *(_QWORD *)(v17 + 472);
      *(_DWORD *)(a2 + 2072) = v35 + *(_DWORD *)(v17 + 544);
      do
      {
        *(_DWORD *)(a2 + 1564 + v19) += *(_DWORD *)(v16 + v19);
        v19 += 4;
      }
      while ( v19 != 252 );
      v37 = *(_QWORD *)(a2 + 2904);
      v38 = *(_QWORD *)(a2 + 2784);
      v39 = *(_DWORD *)(a2 + 2176);
      *(_DWORD *)(a2 + 2172) += *(_DWORD *)(v17 + 552);
      v40 = v39 + *(_DWORD *)(v17 + 556);
      v41 = *(_DWORD *)(a2 + 2180);
      *(_DWORD *)(a2 + 2176) = v40;
      v42 = v41 + *(_DWORD *)(v17 + 560);
      v43 = *(_DWORD *)(a2 + 2184);
      *(_DWORD *)(a2 + 2180) = v42;
      v44 = v43 + *(_DWORD *)(v17 + 564);
      v45 = *(_DWORD *)(a2 + 2188);
      *(_DWORD *)(a2 + 2184) = v44;
      v46 = v45 + *(_DWORD *)(v17 + 568);
      v47 = *(_DWORD *)(a2 + 2192);
      *(_DWORD *)(a2 + 2188) = v46;
      v48 = v47 + *(_DWORD *)(v17 + 572);
      v49 = *(_DWORD *)(a2 + 2196);
      *(_DWORD *)(a2 + 2192) = v48;
      v50 = v49 + *(_DWORD *)(v17 + 576);
      v51 = *(_DWORD *)(a2 + 2200);
      *(_DWORD *)(a2 + 2196) = v50;
      v52 = v51 + *(_DWORD *)(v17 + 580);
      v53 = *(_DWORD *)(a2 + 2204);
      *(_DWORD *)(a2 + 2200) = v52;
      v54 = v53 + *(_DWORD *)(v17 + 584);
      v55 = *(_DWORD *)(a2 + 2208);
      *(_DWORD *)(a2 + 2204) = v54;
      v56 = v55 + *(_DWORD *)(v17 + 588);
      v57 = *(_DWORD *)(a2 + 2212);
      *(_DWORD *)(a2 + 2208) = v56;
      v58 = v57 + *(_DWORD *)(v17 + 592);
      v59 = *(_DWORD *)(a2 + 2216);
      *(_DWORD *)(a2 + 2212) = v58;
      v60 = v59 + *(_DWORD *)(v17 + 596);
      v61 = *(_DWORD *)(a2 + 2220);
      *(_DWORD *)(a2 + 2216) = v60;
      v62 = v61 + *(_DWORD *)(v17 + 600);
      v63 = *(_DWORD *)(a2 + 2224);
      *(_DWORD *)(a2 + 2220) = v62;
      v64 = v63 + *(_DWORD *)(v17 + 604);
      v65 = *(_QWORD *)(a2 + 2960);
      *(_DWORD *)(a2 + 2224) = v64;
      v66 = v65 + *(_QWORD *)(v17 + 784);
      v67 = *(_QWORD *)(a2 + 2968);
      *(_QWORD *)(a2 + 2960) = v66;
      v68 = v67 + *(_QWORD *)(v17 + 792);
      v69 = *(_QWORD *)(a2 + 3048);
      *(_QWORD *)(a2 + 2968) = v68;
      v70 = v69 + *(_QWORD *)(v17 + 992);
      v71 = *(_QWORD *)(a2 + 3056);
      *(_QWORD *)(a2 + 3048) = v70;
      v72 = v71 + *(_QWORD *)(v17 + 1000);
      v73 = *(_QWORD *)(a2 + 2976);
      *(_QWORD *)(a2 + 3056) = v72;
      v74 = v73 + *(_QWORD *)(v17 + 800);
      v75 = *(_QWORD *)(a2 + 2984);
      *(_QWORD *)(a2 + 2976) = v74;
      v76 = v75 + *(_QWORD *)(v17 + 808);
      v77 = *(_QWORD *)(a2 + 2944);
      *(_QWORD *)(a2 + 2984) = v76;
      v78 = v77 + *(_QWORD *)(v17 + 768);
      v79 = *(_QWORD *)(a2 + 2952);
      *(_QWORD *)(a2 + 2944) = v78;
      v80 = v79 + *(_QWORD *)(v17 + 776);
      v81 = *(_QWORD *)(a2 + 2992);
      *(_QWORD *)(a2 + 2952) = v80;
      v82 = v81 + *(_QWORD *)(v17 + 816);
      v83 = *(_QWORD *)(a2 + 3000);
      *(_QWORD *)(a2 + 2992) = v82;
      v84 = v83 + *(_QWORD *)(v17 + 824);
      LODWORD(v83) = *(_DWORD *)(a2 + 3008);
      *(_QWORD *)(a2 + 3000) = v84;
      LODWORD(v84) = v83 + *(_DWORD *)(v17 + 832);
      LODWORD(v83) = *(_DWORD *)(a2 + 4452);
      *(_DWORD *)(a2 + 3008) = v84;
      LODWORD(v84) = v83 + *(_DWORD *)(v17 + 1008);
      v85 = *(_QWORD *)(a2 + 3016);
      *(_DWORD *)(a2 + 4452) = v84;
      v86 = v85 + *(_QWORD *)(v17 + 840);
      v87 = *(_QWORD *)(a2 + 3024);
      *(_QWORD *)(a2 + 3016) = v86;
      v88 = v87 + *(_QWORD *)(v17 + 848);
      v89 = *(_QWORD *)(a2 + 3032);
      *(_QWORD *)(a2 + 3024) = v88;
      v90 = v89 + *(_QWORD *)(v17 + 856);
      v91 = *(_QWORD *)(a2 + 3040);
      *(_QWORD *)(a2 + 3032) = v90;
      v92 = v91 + *(_QWORD *)(v17 + 864);
      v93 = *(_QWORD *)(a2 + 3072);
      *(_QWORD *)(a2 + 3040) = v92;
      v94 = v93 + *(_QWORD *)(v17 + 880);
      v95 = *(_QWORD *)(a2 + 3080);
      *(_QWORD *)(a2 + 3072) = v94;
      v96 = v95 + *(_QWORD *)(v17 + 888);
      v97 = *(_QWORD *)(a2 + 3088);
      *(_QWORD *)(a2 + 3080) = v96;
      v98 = v97 + *(_QWORD *)(v17 + 896);
      v99 = *(_QWORD *)(a2 + 3096);
      *(_QWORD *)(a2 + 3088) = v98;
      v100 = v99 + *(_QWORD *)(v17 + 904);
      LODWORD(v99) = *(_DWORD *)(a2 + 3104);
      *(_QWORD *)(a2 + 3096) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 912);
      LODWORD(v99) = *(_DWORD *)(a2 + 3112);
      *(_DWORD *)(a2 + 3104) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 920);
      LODWORD(v99) = *(_DWORD *)(a2 + 3116);
      *(_DWORD *)(a2 + 3112) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 924);
      LODWORD(v99) = *(_DWORD *)(a2 + 3120);
      *(_DWORD *)(a2 + 3116) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 928);
      LODWORD(v99) = *(_DWORD *)(a2 + 3124);
      *(_DWORD *)(a2 + 3120) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 932);
      LODWORD(v99) = *(_DWORD *)(a2 + 3128);
      *(_DWORD *)(a2 + 3124) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 936);
      LODWORD(v99) = *(_DWORD *)(a2 + 3132);
      *(_DWORD *)(a2 + 3128) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 940);
      LODWORD(v99) = *(_DWORD *)(a2 + 3136);
      *(_DWORD *)(a2 + 3132) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 944);
      LODWORD(v99) = *(_DWORD *)(a2 + 4012);
      *(_DWORD *)(a2 + 3136) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 948);
      LODWORD(v99) = *(_DWORD *)(a2 + 4016);
      *(_DWORD *)(a2 + 4012) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 952);
      LODWORD(v99) = *(_DWORD *)(a2 + 4080);
      *(_DWORD *)(a2 + 4016) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 956);
      LODWORD(v99) = *(_DWORD *)(a2 + 4124);
      *(_DWORD *)(a2 + 4080) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 960);
      LODWORD(v99) = *(_DWORD *)(a2 + 4128);
      *(_DWORD *)(a2 + 4124) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 964);
      LODWORD(v99) = *(_DWORD *)(a2 + 4132);
      *(_DWORD *)(a2 + 4128) = v100;
      LODWORD(v100) = v99 + *(_DWORD *)(v17 + 968);
      v101 = *(_QWORD *)(a2 + 4208);
      *(_DWORD *)(a2 + 4132) = v100;
      v102 = v101 + *(_QWORD *)(v17 + 976);
      v103 = *(_QWORD *)(a2 + 4216);
      *(_QWORD *)(a2 + 4208) = v102;
      v104 = v103 + *(_QWORD *)(v17 + 984);
      LODWORD(v103) = *(_DWORD *)(a2 + 4464);
      *(_QWORD *)(a2 + 4216) = v104;
      *(_QWORD *)(a2 + 3064) = *(_QWORD *)(v17 + 872);
      LODWORD(v104) = v103 + *(_DWORD *)(v17 + 1032);
      v105 = *(_QWORD *)(a2 + 2768);
      *(_DWORD *)(a2 + 4464) = v104;
      v106 = v105 + *(_QWORD *)(v17 + 608);
      v107 = *(_QWORD *)(a2 + 2776);
      *(_QWORD *)(a2 + 2768) = v106;
      v108 = v107 + *(_QWORD *)(v17 + 616);
      v109 = *(_QWORD *)(a2 + 2896);
      *(_QWORD *)(a2 + 2776) = v108;
      v110 = v109 + *(_QWORD *)(v17 + 608);
      *(_QWORD *)(a2 + 2896) = v110;
      v111 = v37 + *(_QWORD *)(v17 + 616);
      *(_QWORD *)(a2 + 2904) = v111;
      v112 = v38 + *(_QWORD *)(v17 + 624);
      v113 = *(_QWORD *)(a2 + 2792);
      *(_QWORD *)(a2 + 2784) = v112;
      v114 = v113 + *(_QWORD *)(v17 + 632);
      v115 = *(_QWORD *)(a2 + 2800);
      *(_QWORD *)(a2 + 2792) = v114;
      v116 = v110 + *(_QWORD *)(v17 + 624);
      *(_QWORD *)(a2 + 2896) = v116;
      v117 = v111 + *(_QWORD *)(v17 + 632);
      *(_QWORD *)(a2 + 2904) = v117;
      v118 = v115 + *(_QWORD *)(v17 + 640);
      v119 = *(_QWORD *)(a2 + 2808);
      *(_QWORD *)(a2 + 2800) = v118;
      v120 = v119 + *(_QWORD *)(v17 + 648);
      v121 = *(_QWORD *)(a2 + 2816);
      *(_QWORD *)(a2 + 2808) = v120;
      v122 = v116 + *(_QWORD *)(v17 + 640);
      *(_QWORD *)(a2 + 2896) = v122;
      v123 = v117 + *(_QWORD *)(v17 + 648);
      *(_QWORD *)(a2 + 2904) = v123;
      v124 = v121 + *(_QWORD *)(v17 + 656);
      v125 = *(_QWORD *)(a2 + 2824);
      *(_QWORD *)(a2 + 2816) = v124;
      v126 = v125 + *(_QWORD *)(v17 + 664);
      v127 = *(_QWORD *)(a2 + 2832);
      *(_QWORD *)(a2 + 2824) = v126;
      v128 = v122 + *(_QWORD *)(v17 + 656);
      *(_QWORD *)(a2 + 2896) = v128;
      v129 = v123 + *(_QWORD *)(v17 + 664);
      *(_QWORD *)(a2 + 2904) = v129;
      v130 = v127 + *(_QWORD *)(v17 + 672);
      v131 = *(_QWORD *)(a2 + 2840);
      *(_QWORD *)(a2 + 2832) = v130;
      v132 = v131 + *(_QWORD *)(v17 + 680);
      v133 = *(_QWORD *)(a2 + 2848);
      *(_QWORD *)(a2 + 2840) = v132;
      v134 = v128 + *(_QWORD *)(v17 + 672);
      *(_QWORD *)(a2 + 2896) = v134;
      v135 = v129 + *(_QWORD *)(v17 + 680);
      *(_QWORD *)(a2 + 2904) = v135;
      v136 = v133 + *(_QWORD *)(v17 + 688);
      v137 = *(_QWORD *)(a2 + 2856);
      *(_QWORD *)(a2 + 2848) = v136;
      v138 = v137 + *(_QWORD *)(v17 + 696);
      v139 = *(_QWORD *)(a2 + 2864);
      *(_QWORD *)(a2 + 2856) = v138;
      v140 = v134 + *(_QWORD *)(v17 + 688);
      *(_QWORD *)(a2 + 2896) = v140;
      v141 = v135 + *(_QWORD *)(v17 + 696);
      *(_QWORD *)(a2 + 2904) = v141;
      v142 = v139 + *(_QWORD *)(v17 + 704);
      v143 = *(_QWORD *)(a2 + 2872);
      *(_QWORD *)(a2 + 2864) = v142;
      v144 = v143 + *(_QWORD *)(v17 + 712);
      v145 = *(_QWORD *)(a2 + 2880);
      *(_QWORD *)(a2 + 2872) = v144;
      v146 = v140 + *(_QWORD *)(v17 + 704);
      *(_QWORD *)(a2 + 2896) = v146;
      v147 = v141 + *(_QWORD *)(v17 + 712);
      *(_QWORD *)(a2 + 2904) = v147;
      v148 = v145 + *(_QWORD *)(v17 + 720);
      v149 = *(_QWORD *)(a2 + 2888);
      *(_QWORD *)(a2 + 2880) = v148;
      *(_QWORD *)(a2 + 2888) = v149 + *(_QWORD *)(v17 + 728);
      *(_QWORD *)(a2 + 2896) = v146 + *(_QWORD *)(v17 + 720);
      v150 = v147 + *(_QWORD *)(v17 + 728);
      v151 = *(_QWORD *)(a2 + 2912);
      *(_QWORD *)(a2 + 2904) = v150;
      v152 = v151 + *(_QWORD *)(v17 + 736);
      v153 = *(_QWORD *)(a2 + 2920);
      *(_QWORD *)(a2 + 2912) = v152;
      v154 = v153 + *(_QWORD *)(v17 + 744);
      v155 = *(_QWORD *)(a2 + 2928);
      *(_QWORD *)(a2 + 2920) = v154;
      v156 = v155 + *(_QWORD *)(v17 + 752);
      v157 = *(_QWORD *)(a2 + 2936);
      *(_QWORD *)(a2 + 2928) = v156;
      v158 = v157 + *(_QWORD *)(v17 + 760);
      v159 = *(_QWORD *)(a2 + 4504);
      *(_QWORD *)(a2 + 2936) = v158;
      v160 = v159 + *(_QWORD *)(v17 + 1016);
      v161 = *(_QWORD *)(a2 + 4512);
      *(_QWORD *)(a2 + 4504) = v160;
      v162 = v161 + *(_QWORD *)(v17 + 1024);
      v163 = *(_QWORD *)(a2 + 760);
      *(_QWORD *)(a2 + 4512) = v162;
      v164 = v163 + *(unsigned int *)(v17 + 100);
      v165 = *(_QWORD *)(a2 + 768);
      *(_QWORD *)(a2 + 760) = v164;
      v166 = v165 + *(_QWORD *)(v17 + 160);
      LODWORD(v165) = *(_DWORD *)(a2 + 776);
      *(_QWORD *)(a2 + 768) = v166;
      LODWORD(v166) = v165 + *(_DWORD *)(v17 + 108);
      v167 = *(_QWORD *)(a2 + 784);
      *(_DWORD *)(a2 + 776) = v166;
      v168 = v167 + *(unsigned int *)(v17 + 104);
      v169 = *(_QWORD *)(a2 + 792);
      *(_QWORD *)(a2 + 784) = v168;
      v170 = v169 + *(_QWORD *)(v17 + 168);
      LODWORD(v169) = *(_DWORD *)(a2 + 800);
      *(_QWORD *)(a2 + 792) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 112);
      LODWORD(v169) = *(_DWORD *)(a2 + 804);
      *(_DWORD *)(a2 + 800) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 116);
      LODWORD(v169) = *(_DWORD *)(a2 + 808);
      *(_DWORD *)(a2 + 804) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 120);
      LODWORD(v169) = *(_DWORD *)(a2 + 812);
      *(_DWORD *)(a2 + 808) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 124);
      LODWORD(v169) = *(_DWORD *)(a2 + 816);
      *(_DWORD *)(a2 + 812) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 128);
      LODWORD(v169) = *(_DWORD *)(a2 + 820);
      *(_DWORD *)(a2 + 816) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 132);
      LODWORD(v169) = *(_DWORD *)(a2 + 824);
      *(_DWORD *)(a2 + 820) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 136);
      LODWORD(v169) = *(_DWORD *)(a2 + 828);
      *(_DWORD *)(a2 + 824) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 140);
      LODWORD(v169) = *(_DWORD *)(a2 + 832);
      *(_DWORD *)(a2 + 828) = v170;
      LODWORD(v170) = v169 + *(_DWORD *)(v17 + 144);
      LODWORD(v169) = *(_DWORD *)(a2 + 836);
      *(_DWORD *)(a2 + 832) = v170;
      *(_DWORD *)(a2 + 836) = v169 + *(_DWORD *)(v17 + 148);
      *(_DWORD *)(a2 + 840) += *(_DWORD *)(v17 + 156);
      result = (__int64 *)qdf_trace_msg(
                            0x45u,
                            5u,
                            "%s: MLO get stats from peer %d link_id %d",
                            v7,
                            v8,
                            v9,
                            v10,
                            v11,
                            v12,
                            v13,
                            v14,
                            "dp_get_peer_per_pkt_stats",
                            *(unsigned __int16 *)(v6 + 8),
                            (unsigned int)v15);
      v171 = (unsigned __int8)v344;
      if ( v15 + 1 >= (unsigned __int8)v344 )
        break;
      v16 += 4072;
      if ( v15++ >= *(unsigned __int8 *)(v6 + 2281) )
        goto LABEL_21;
    }
    if ( !(_BYTE)v344 )
      goto LABEL_19;
LABEL_21:
    result = v340;
    if ( v340 )
    {
      result = (__int64 *)dp_peer_unref_delete((__int64)v340, 8u, v7, v8, v9, v10, v11, v12, v13, v14);
      v171 = (unsigned __int8)v344;
    }
    v340 = nullptr;
    if ( v171 >= 2 )
    {
      result = v341;
      if ( v341 )
      {
        result = (__int64 *)dp_peer_unref_delete((__int64)v341, 8u, v7, v8, v9, v10, v11, v12, v13, v14);
        v171 = (unsigned __int8)v344;
      }
      v341 = nullptr;
      if ( v171 >= 3 )
      {
        result = v342;
        if ( v342 )
        {
          result = (__int64 *)dp_peer_unref_delete((__int64)v342, 8u, v7, v8, v9, v10, v11, v12, v13, v14);
          v171 = (unsigned __int8)v344;
        }
        v342 = nullptr;
        if ( v171 >= 4 )
        {
          result = v343;
          if ( v343 )
          {
            result = (__int64 *)dp_peer_unref_delete((__int64)v343, 8u, v7, v8, v9, v10, v11, v12, v13, v14);
            v171 = (unsigned __int8)v344;
          }
          v343 = nullptr;
          if ( v171 > 4 )
            __break(0x5512u);
        }
      }
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
