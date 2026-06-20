__int64 *__fastcall dp_get_peer_extd_stats(
        __int64 *result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v11; // x20
  __int64 v12; // x22
  int v13; // w8
  __int64 *v14; // x8
  __int64 v15; // x21
  unsigned __int64 v16; // x17
  __int64 v17; // x15
  __int64 v18; // x16
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x20
  __int64 v25; // x23
  int v26; // w26
  int v27; // w26
  int v28; // w25
  int v29; // w24
  int v30; // w25
  int v31; // w24
  int v32; // w25
  int v33; // w24
  int v34; // w25
  int v35; // w24
  int v36; // w25
  int v37; // w24
  int v38; // w25
  int v39; // w24
  int v40; // w25
  int v41; // w24
  int v42; // w25
  unsigned int v43; // w25
  unsigned int v44; // w25
  unsigned int v45; // w25
  unsigned int v46; // w25
  int v47; // w25
  int v48; // w24
  __int64 v49; // x20
  _DWORD *v50; // x24
  _DWORD *v51; // x25
  int v52; // w28
  int v53; // w28
  int v54; // w28
  int v55; // w28
  int v56; // w28
  int v57; // w28
  int v58; // w28
  int v59; // w28
  __int64 v60; // x23
  __int64 v61; // x25
  __int64 v62; // x24
  __int64 v63; // x25
  __int64 v64; // x24
  __int64 v65; // x25
  __int64 v66; // x24
  __int64 v67; // x25
  __int64 v68; // x24
  _DWORD *v69; // x25
  _DWORD *v70; // x24
  int v71; // w28
  __int64 v72; // x23
  int v73; // w25
  int v74; // w24
  int v75; // w25
  int v76; // w24
  int v77; // w25
  int v78; // w24
  int v79; // w25
  int v80; // w24
  int v81; // w25
  int v82; // w24
  int v83; // w25
  int v84; // w24
  int v85; // w25
  int v86; // w24
  int v87; // w25
  int v88; // w24
  int v89; // w25
  int v90; // w24
  int v91; // w25
  int v92; // w24
  int v93; // w25
  int v94; // w24
  int v95; // w25
  int v96; // w24
  int v97; // w25
  int v98; // w24
  int v99; // w25
  int v100; // w24
  int v101; // w25
  int v102; // w24
  int v103; // w25
  int v104; // w24
  int v105; // w25
  int v106; // w24
  int v107; // w25
  int v108; // w24
  int v109; // w25
  int v110; // w24
  int v111; // w25
  int v112; // w24
  int v113; // w25
  int v114; // w24
  int v115; // w25
  int v116; // w24
  int v117; // w25
  int v118; // w24
  int v119; // w25
  int v120; // w24
  int v121; // w25
  int v122; // w24
  int v123; // w25
  __int64 v124; // x23
  int v125; // w26
  __int64 v126; // x25
  __int64 v127; // x24
  __int64 v128; // x25
  __int64 v129; // x24
  __int64 v130; // x25
  __int64 v131; // x24
  __int64 v132; // x25
  __int64 v133; // x24
  __int64 v134; // x25
  __int64 v135; // x24
  __int64 v136; // x25
  __int64 v137; // x24
  unsigned int v138; // w26
  unsigned int v139; // w26
  unsigned int v140; // w26
  unsigned int v141; // w26
  _DWORD *v142; // x24
  _DWORD *v143; // x25
  int v144; // w28
  int v145; // w28
  int v146; // w28
  int v147; // w28
  int v148; // w28
  int v149; // w28
  int v150; // w28
  int v151; // w28
  __int64 v152; // x23
  __int64 v153; // x25
  __int64 v154; // x24
  __int64 v155; // x25
  __int64 v156; // x24
  __int64 v157; // x25
  __int64 v158; // x24
  __int64 v159; // x25
  _DWORD *v160; // x24
  _DWORD *v161; // x25
  __int64 v162; // x25
  char v163; // w24
  __int64 v164; // x25
  _DWORD *v165; // x26
  _DWORD *v166; // x25
  int v167; // w30
  int v168; // w30
  int v169; // w30
  int v170; // w30
  int v171; // w30
  int v172; // w30
  int v173; // w30
  int v174; // w30
  int v175; // w30
  int v176; // w30
  int v177; // w30
  int v178; // w30
  int v179; // w30
  char v180; // w28
  __int64 v181; // x23
  int v182; // w25
  int v183; // w24
  int v184; // w25
  int v185; // w24
  int v186; // w25
  int v187; // w24
  int v188; // w25
  int v189; // w24
  int v190; // w25
  int v191; // w24
  int v192; // w25
  int v193; // w24
  int v194; // w25
  int v195; // w24
  int v196; // w25
  int v197; // w24
  int v198; // w25
  int v199; // w24
  int v200; // w25
  int v201; // w24
  int v202; // w25
  int v203; // w24
  int v204; // w25
  int v205; // w24
  int v206; // w25
  int v207; // w24
  int v208; // w25
  int v209; // w24
  int v210; // w25
  int v211; // w24
  int v212; // w25
  int v213; // w24
  int v214; // w25
  int v215; // w24
  int v216; // w25
  int v217; // w24
  int v218; // w25
  int v219; // w24
  int v220; // w25
  int v221; // w24
  int v222; // w25
  int v223; // w24
  int v224; // w25
  int v225; // w24
  int v226; // w25
  int v227; // w24
  int v228; // w25
  int v229; // w24
  int v230; // w25
  int v231; // w24
  int v232; // w25
  int v233; // w24
  int v234; // w25
  int v235; // w24
  int v236; // w25
  int v237; // w24
  int v238; // w25
  int v239; // w24
  int v240; // w25
  int v241; // w24
  int v242; // w25
  int v243; // w24
  int v244; // w25
  int v245; // w24
  int v246; // w25
  int v247; // w24
  int v248; // w25
  int v249; // w24
  int v250; // w25
  int v251; // w24
  int v252; // w25
  int v253; // w24
  __int64 v254; // x25
  _DWORD *v255; // x24
  __int64 v256; // x25
  __int64 k; // x23
  _DWORD *v258; // x24
  __int64 v259; // x25
  __int64 m; // x23
  _DWORD *v261; // x24
  __int64 v262; // x25
  int v263; // w25
  int v264; // w24
  int v265; // w23
  int v266; // w24
  int v267; // w23
  int v268; // w24
  int v269; // w23
  int v270; // w24
  int v271; // w23
  int v272; // w24
  int v273; // w23
  int v274; // w24
  int v275; // w23
  int v276; // w24
  int v277; // w23
  int v278; // w24
  int v279; // w24
  bool v280; // cf
  unsigned int peer_link_id; // w9
  __int64 v282; // x10
  __int64 v283; // x11
  int v284; // w13
  int v285; // w13
  int v286; // w12
  int v287; // w8
  int v288; // w12
  int v289; // w8
  int v290; // w12
  int v291; // w8
  int v292; // w12
  int v293; // w8
  int v294; // w12
  int v295; // w8
  int v296; // w12
  int v297; // w8
  int v298; // w12
  int v299; // w8
  int v300; // w12
  unsigned int v301; // w12
  unsigned int v302; // w12
  unsigned int v303; // w12
  unsigned int v304; // w12
  int v305; // w12
  __int64 v306; // x8
  int v307; // w12
  __int64 v308; // x11
  _DWORD *v309; // x12
  _DWORD *v310; // x13
  int v311; // w16
  int v312; // w16
  int v313; // w16
  int v314; // w16
  int v315; // w16
  int v316; // w15
  int v317; // w14
  int v318; // w15
  int v319; // w14
  int v320; // w15
  int v321; // w14
  int v322; // w15
  int v323; // w14
  int v324; // w15
  int v325; // w14
  int v326; // w15
  __int64 v327; // x10
  __int64 v328; // x12
  __int64 v329; // x11
  __int64 v330; // x12
  __int64 v331; // x11
  __int64 v332; // x12
  __int64 v333; // x11
  __int64 v334; // x12
  __int64 v335; // x11
  _DWORD *v336; // x12
  _DWORD *v337; // x13
  int v338; // w15
  __int64 v339; // x10
  int v340; // w12
  int v341; // w11
  int v342; // w12
  int v343; // w11
  int v344; // w12
  int v345; // w11
  int v346; // w12
  int v347; // w11
  int v348; // w12
  int v349; // w11
  int v350; // w12
  int v351; // w11
  int v352; // w12
  int v353; // w11
  int v354; // w12
  int v355; // w11
  int v356; // w12
  int v357; // w11
  int v358; // w12
  int v359; // w11
  int v360; // w12
  int v361; // w11
  int v362; // w12
  int v363; // w11
  int v364; // w12
  int v365; // w11
  int v366; // w12
  int v367; // w11
  int v368; // w12
  int v369; // w11
  int v370; // w12
  int v371; // w11
  int v372; // w12
  int v373; // w11
  int v374; // w12
  int v375; // w11
  int v376; // w12
  int v377; // w11
  int v378; // w12
  int v379; // w11
  int v380; // w12
  int v381; // w11
  int v382; // w12
  int v383; // w11
  int v384; // w12
  int v385; // w11
  int v386; // w12
  int v387; // w11
  int v388; // w12
  int v389; // w11
  int v390; // w12
  int v391; // w12
  __int64 v392; // x13
  __int64 v393; // x10
  int v394; // w13
  __int64 v395; // x12
  __int64 v396; // x11
  __int64 v397; // x12
  __int64 v398; // x11
  __int64 v399; // x12
  __int64 v400; // x11
  __int64 v401; // x12
  __int64 v402; // x11
  __int64 v403; // x12
  __int64 v404; // x11
  __int64 v405; // x12
  __int64 v406; // x11
  unsigned int v407; // w13
  unsigned int v408; // w13
  unsigned int v409; // w13
  unsigned int v410; // w13
  __int64 v411; // x9
  _DWORD *v412; // x12
  _DWORD *v413; // x11
  int v414; // w14
  int v415; // w13
  int v416; // w14
  int v417; // w13
  int v418; // w14
  int v419; // w13
  int v420; // w14
  int v421; // w13
  int v422; // w14
  int v423; // w13
  int v424; // w14
  int v425; // w13
  int v426; // w14
  int v427; // w13
  int v428; // w14
  int v429; // w13
  int v430; // w14
  int v431; // w13
  int v432; // w14
  int v433; // w13
  int v434; // w14
  int v435; // w13
  int v436; // w14
  int v437; // w13
  int v438; // w14
  int v439; // w13
  int v440; // w14
  int v441; // w13
  int v442; // w14
  __int64 v443; // x9
  __int64 v444; // x11
  __int64 v445; // x10
  __int64 v446; // x11
  __int64 v447; // x10
  __int64 v448; // x11
  __int64 v449; // x10
  __int64 v450; // x11
  _DWORD *v451; // x11
  __int64 v452; // x12
  __int64 v453; // x13
  char v454; // w12
  __int64 v455; // x13
  _DWORD *v456; // x14
  _DWORD *v457; // x13
  int v458; // w17
  int v459; // w17
  int v460; // w17
  int v461; // w17
  int v462; // w17
  int v463; // w17
  int v464; // w17
  int v465; // w17
  int v466; // w17
  int v467; // w17
  int v468; // w17
  int v469; // w17
  int v470; // w17
  char v471; // w16
  __int64 v472; // x9
  int v473; // w11
  int v474; // w10
  int v475; // w11
  int v476; // w10
  int v477; // w11
  int v478; // w10
  int v479; // w11
  int v480; // w10
  int v481; // w11
  int v482; // w10
  int v483; // w11
  int v484; // w10
  int v485; // w11
  int v486; // w10
  int v487; // w11
  int v488; // w10
  int v489; // w11
  int v490; // w10
  int v491; // w11
  int v492; // w10
  int v493; // w11
  int v494; // w10
  int v495; // w11
  int v496; // w10
  int v497; // w11
  int v498; // w10
  int v499; // w11
  int v500; // w10
  int v501; // w11
  int v502; // w10
  int v503; // w11
  int v504; // w10
  int v505; // w11
  int v506; // w10
  int v507; // w11
  int v508; // w10
  int v509; // w11
  int v510; // w10
  int v511; // w11
  int v512; // w10
  int v513; // w11
  int v514; // w10
  int v515; // w11
  int v516; // w10
  int v517; // w11
  int v518; // w10
  int v519; // w11
  int v520; // w10
  int v521; // w11
  int v522; // w10
  int v523; // w11
  int v524; // w10
  int v525; // w11
  int v526; // w10
  int v527; // w11
  int v528; // w10
  int v529; // w11
  int v530; // w10
  int v531; // w11
  int v532; // w10
  int v533; // w11
  int v534; // w10
  int v535; // w11
  int v536; // w10
  int v537; // w11
  int v538; // w10
  int v539; // w11
  int v540; // w10
  int v541; // w11
  int v542; // w10
  int v543; // w11
  int v544; // w10
  __int64 v545; // x11
  _DWORD *v546; // x11
  __int64 v547; // x12
  __int64 i; // x9
  _DWORD *v549; // x11
  __int64 v550; // x12
  __int64 j; // x9
  _DWORD *v552; // x11
  __int64 v553; // x12
  int v554; // w10
  int v555; // w9
  int v556; // w10
  int v557; // w9
  int v558; // w10
  int v559; // w9
  int v560; // w10
  int v561; // w9
  int v562; // w10
  int v563; // w9
  int v564; // w10
  int v565; // w9
  int v566; // w10
  int v567; // w9
  int v568; // w10
  __int64 v569; // x21
  __int64 *v570; // [xsp+0h] [xbp-30h] BYREF
  __int64 *v571; // [xsp+8h] [xbp-28h]
  __int64 *v572; // [xsp+10h] [xbp-20h]
  __int64 *v573; // [xsp+18h] [xbp-18h]
  __int64 v574; // [xsp+20h] [xbp-10h]
  __int64 v575; // [xsp+28h] [xbp-8h]

  v11 = (unsigned __int64)result;
  v12 = a2 + 4096;
  v575 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *((_DWORD *)result + 102);
  v573 = nullptr;
  v574 = 0;
  v571 = nullptr;
  v572 = nullptr;
  v570 = nullptr;
  if ( v13 == 1 )
  {
    v14 = (__int64 *)result[52];
    if ( v14 )
    {
      v15 = *v14;
      if ( !*v14 )
      {
LABEL_66:
        v569 = jiffies;
        if ( dp_get_peer_extd_stats___last_ticks - jiffies + 125 < 0 )
        {
          result = (__int64 *)qdf_trace_msg(
                                0x45u,
                                2u,
                                "%s: txrx_peer NULL for peer MAC: %02x:%02x:%02x:**:**:%02x",
                                a3,
                                a4,
                                a5,
                                a6,
                                a7,
                                a8,
                                a9,
                                a10,
                                "dp_get_peer_extd_stats",
                                *(unsigned __int8 *)(v11 + 44),
                                *(unsigned __int8 *)(v11 + 45),
                                *(unsigned __int8 *)(v11 + 46),
                                *(unsigned __int8 *)(v11 + 49));
          dp_get_peer_extd_stats___last_ticks = v569;
        }
        goto LABEL_51;
      }
    }
    else
    {
      v15 = *result;
      if ( !*result )
        goto LABEL_66;
    }
LABEL_32:
    peer_link_id = (unsigned __int8)dp_get_peer_link_id(result);
    v282 = 0;
    v283 = v15 + 4072LL * peer_link_id;
    v284 = *(_DWORD *)(a2 + 120);
    *(_DWORD *)(a2 + 116) += *(_DWORD *)(v283 + 3328);
    *(_DWORD *)(a2 + 120) = v284 + *(_DWORD *)(v283 + 3332);
    v285 = *(_DWORD *)(a2 + 128);
    v286 = *(_DWORD *)(a2 + 948);
    *(_DWORD *)(a2 + 124) += *(_DWORD *)(v283 + 3336);
    v287 = v286 + *(_DWORD *)(v283 + 3780);
    v288 = *(_DWORD *)(a2 + 952);
    *(_DWORD *)(a2 + 948) = v287;
    v289 = v288 + *(_DWORD *)(v283 + 3784);
    v290 = *(_DWORD *)(a2 + 1560);
    *(_DWORD *)(a2 + 952) = v289;
    v291 = v290 + *(_DWORD *)(v283 + 3788);
    v292 = *(_DWORD *)(a2 + 984);
    *(_DWORD *)(a2 + 1560) = v291;
    v293 = v292 + *(_DWORD *)(v283 + 3792);
    v294 = *(_DWORD *)(a2 + 988);
    *(_DWORD *)(a2 + 984) = v293;
    v295 = v294 + *(_DWORD *)(v283 + 3796);
    v296 = *(_DWORD *)(a2 + 992);
    *(_DWORD *)(a2 + 988) = v295;
    v297 = v296 + *(_DWORD *)(v283 + 3800);
    v298 = *(_DWORD *)(a2 + 644);
    *(_DWORD *)(a2 + 992) = v297;
    *(_DWORD *)(a2 + 140) = *(_DWORD *)(v283 + 3804);
    *(_DWORD *)(a2 + 144) = *(_DWORD *)(v283 + 3808);
    *(_DWORD *)(a2 + 148) = *(_DWORD *)(v283 + 3812);
    *(_DWORD *)(a2 + 152) = *(_DWORD *)(v283 + 3816);
    *(_DWORD *)(a2 + 156) = *(_DWORD *)(v283 + 3820);
    *(_QWORD *)(a2 + 168) = *(_QWORD *)(v283 + 3824);
    *(_QWORD *)(a2 + 176) = *(_QWORD *)(v283 + 3832);
    *(_WORD *)(a2 + 944) = *(_WORD *)(v283 + 3840);
    v299 = v298 + *(_DWORD *)(v283 + 3864);
    v300 = *(_DWORD *)(a2 + 1832);
    *(_DWORD *)(a2 + 644) = v299;
    *(_DWORD *)(a2 + 1360) = *(_DWORD *)(v283 + 3932);
    *(_DWORD *)(a2 + 1364) = *(_DWORD *)(v283 + 3936);
    *(_DWORD *)(a2 + 184) = *(_DWORD *)(v283 + 4496);
    *(_DWORD *)(a2 + 188) = *(_DWORD *)(v283 + 4500);
    v301 = v300 & 0xFFFFFFF0 | *(_DWORD *)(v283 + 4508) & 0xF;
    *(_DWORD *)(a2 + 1832) = v301;
    v302 = v301 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v283 + 4508) >> 4) & 0xF));
    *(_DWORD *)(a2 + 1832) = v302;
    v303 = v302 & 0xFFFFF0FF | (((*(_DWORD *)(v283 + 4508) >> 8) & 0xF) << 8);
    *(_DWORD *)(a2 + 1832) = v303;
    v304 = v303 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v283 + 4508)) >> 4 << 12);
    *(_DWORD *)(a2 + 1832) = v304;
    *(_DWORD *)(a2 + 1832) = v304 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v283 + 4508)) & 0xF) << 16);
    v305 = *(_DWORD *)(a2 + 1836);
    *(_DWORD *)(a2 + 128) = v285 + *(_DWORD *)(v283 + 4512);
    *(_DWORD *)(a2 + 1836) = v305 + *(_DWORD *)(v283 + 4516);
    *(_DWORD *)(a2 + 2080) = *(_DWORD *)(v283 + 4776);
    *(_DWORD *)(a2 + 2084) = *(_DWORD *)(v283 + 4780);
    *(_DWORD *)(a2 + 2088) = *(_DWORD *)(v283 + 4784);
    v306 = v283 + 3328;
    v307 = *(_DWORD *)(v283 + 4788);
    v308 = v283 + 3404;
    *(_DWORD *)(a2 + 2092) = v307;
    do
    {
      v309 = (_DWORD *)(a2 + v282);
      v310 = (_DWORD *)(v308 + v282);
      v282 += 68;
      v311 = v309[55];
      v309[54] += *(v310 - 16);
      v309[55] = v311 + *(v310 - 15);
      v312 = v309[57];
      v309[56] += *(v310 - 14);
      v309[57] = v312 + *(v310 - 13);
      v313 = v309[59];
      v309[58] += *(v310 - 12);
      v309[59] = v313 + *(v310 - 11);
      v314 = v309[61];
      v309[60] += *(v310 - 10);
      v309[61] = v314 + *(v310 - 9);
      v315 = v309[63];
      v316 = v309[64];
      v309[62] += *(v310 - 8);
      v309[63] = v315 + *(v310 - 7);
      v317 = v316 + *(v310 - 6);
      v318 = v309[65];
      v309[64] = v317;
      v319 = v318 + *(v310 - 5);
      v320 = v309[66];
      v309[65] = v319;
      v321 = v320 + *(v310 - 4);
      v322 = v309[67];
      v309[66] = v321;
      v323 = v322 + *(v310 - 3);
      v324 = v309[68];
      v309[67] = v323;
      v325 = v324 + *(v310 - 2);
      v326 = v309[69];
      v309[68] = v325;
      v309[69] = v326 + *(v310 - 1);
      v309[70] += *v310;
    }
    while ( v282 != 408 );
    v327 = 0;
    v328 = *(_QWORD *)(a2 + 2104);
    *(_DWORD *)(a2 + 712) += *(_DWORD *)(v306 + 420);
    v329 = v328 + *(_QWORD *)(v306 + 1496);
    LODWORD(v328) = *(_DWORD *)(a2 + 728);
    *(_QWORD *)(a2 + 2104) = v329;
    LODWORD(v329) = v328 + *(_DWORD *)(v306 + 436);
    LODWORD(v328) = *(_DWORD *)(a2 + 716);
    *(_DWORD *)(a2 + 728) = v329;
    LODWORD(v329) = v328 + *(_DWORD *)(v306 + 424);
    v330 = *(_QWORD *)(a2 + 2112);
    *(_DWORD *)(a2 + 716) = v329;
    v331 = v330 + *(_QWORD *)(v306 + 1504);
    LODWORD(v330) = *(_DWORD *)(a2 + 732);
    *(_QWORD *)(a2 + 2112) = v331;
    LODWORD(v331) = v330 + *(_DWORD *)(v306 + 440);
    LODWORD(v330) = *(_DWORD *)(a2 + 720);
    *(_DWORD *)(a2 + 732) = v331;
    LODWORD(v331) = v330 + *(_DWORD *)(v306 + 428);
    v332 = *(_QWORD *)(a2 + 2120);
    *(_DWORD *)(a2 + 720) = v331;
    v333 = v332 + *(_QWORD *)(v306 + 1512);
    LODWORD(v332) = *(_DWORD *)(a2 + 736);
    *(_QWORD *)(a2 + 2120) = v333;
    LODWORD(v333) = v332 + *(_DWORD *)(v306 + 444);
    LODWORD(v332) = *(_DWORD *)(a2 + 724);
    *(_DWORD *)(a2 + 736) = v333;
    LODWORD(v333) = v332 + *(_DWORD *)(v306 + 432);
    v334 = *(_QWORD *)(a2 + 2128);
    *(_DWORD *)(a2 + 724) = v333;
    v335 = v334 + *(_QWORD *)(v306 + 1520);
    LODWORD(v334) = *(_DWORD *)(a2 + 740);
    *(_QWORD *)(a2 + 2128) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 448);
    LODWORD(v334) = *(_DWORD *)(a2 + 624);
    *(_DWORD *)(a2 + 740) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 516);
    LODWORD(v334) = *(_DWORD *)(a2 + 628);
    *(_DWORD *)(a2 + 624) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 520);
    LODWORD(v334) = *(_DWORD *)(a2 + 632);
    *(_DWORD *)(a2 + 628) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 524);
    LODWORD(v334) = *(_DWORD *)(a2 + 636);
    *(_DWORD *)(a2 + 632) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 528);
    LODWORD(v334) = *(_DWORD *)(a2 + 640);
    *(_DWORD *)(a2 + 636) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 532);
    LODWORD(v334) = *(_DWORD *)(a2 + 648);
    *(_DWORD *)(a2 + 640) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 540);
    LODWORD(v334) = *(_DWORD *)(a2 + 652);
    *(_DWORD *)(a2 + 648) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 544);
    LODWORD(v334) = *(_DWORD *)(a2 + 656);
    *(_DWORD *)(a2 + 652) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 548);
    LODWORD(v334) = *(_DWORD *)(a2 + 660);
    *(_DWORD *)(a2 + 656) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 552);
    LODWORD(v334) = *(_DWORD *)(a2 + 664);
    *(_DWORD *)(a2 + 660) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 556);
    LODWORD(v334) = *(_DWORD *)(a2 + 668);
    *(_DWORD *)(a2 + 664) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 560);
    LODWORD(v334) = *(_DWORD *)(a2 + 672);
    *(_DWORD *)(a2 + 668) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 564);
    LODWORD(v334) = *(_DWORD *)(a2 + 676);
    *(_DWORD *)(a2 + 672) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 568);
    LODWORD(v334) = *(_DWORD *)(a2 + 680);
    *(_DWORD *)(a2 + 676) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 572);
    LODWORD(v334) = *(_DWORD *)(a2 + 684);
    *(_DWORD *)(a2 + 680) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 576);
    LODWORD(v334) = *(_DWORD *)(a2 + 688);
    *(_DWORD *)(a2 + 684) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 580);
    LODWORD(v334) = *(_DWORD *)(a2 + 692);
    *(_DWORD *)(a2 + 688) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 584);
    LODWORD(v334) = *(_DWORD *)(a2 + 696);
    *(_DWORD *)(a2 + 692) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 588);
    LODWORD(v334) = *(_DWORD *)(a2 + 700);
    *(_DWORD *)(a2 + 696) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 592);
    LODWORD(v334) = *(_DWORD *)(a2 + 704);
    *(_DWORD *)(a2 + 700) = v335;
    LODWORD(v335) = v334 + *(_DWORD *)(v306 + 596);
    LODWORD(v334) = *(_DWORD *)(a2 + 708);
    *(_DWORD *)(a2 + 704) = v335;
    *(_DWORD *)(a2 + 708) = v334 + *(_DWORD *)(v306 + 600);
    do
    {
      v336 = (_DWORD *)(v306 + 612 + v327);
      v337 = (_DWORD *)(a2 + v327);
      v327 += 12;
      v338 = v337[343];
      v337[342] += *v336;
      v337[343] = v338 + v336[1];
      v337[344] += v336[2];
    }
    while ( v327 != 192 );
    v339 = 0;
    v340 = *(_DWORD *)(a2 + 1000);
    *(_DWORD *)(a2 + 996) += *(_DWORD *)(v306 + 804);
    v341 = v340 + *(_DWORD *)(v306 + 808);
    v342 = *(_DWORD *)(a2 + 1004);
    *(_DWORD *)(a2 + 1000) = v341;
    v343 = v342 + *(_DWORD *)(v306 + 812);
    v344 = *(_DWORD *)(a2 + 1008);
    *(_DWORD *)(a2 + 1004) = v343;
    v345 = v344 + *(_DWORD *)(v306 + 816);
    v346 = *(_DWORD *)(a2 + 1012);
    *(_DWORD *)(a2 + 1008) = v345;
    v347 = v346 + *(_DWORD *)(v306 + 820);
    v348 = *(_DWORD *)(a2 + 1016);
    *(_DWORD *)(a2 + 1012) = v347;
    v349 = v348 + *(_DWORD *)(v306 + 824);
    v350 = *(_DWORD *)(a2 + 1020);
    *(_DWORD *)(a2 + 1016) = v349;
    v351 = v350 + *(_DWORD *)(v306 + 828);
    v352 = *(_DWORD *)(a2 + 1024);
    *(_DWORD *)(a2 + 1020) = v351;
    v353 = v352 + *(_DWORD *)(v306 + 832);
    v354 = *(_DWORD *)(a2 + 1028);
    *(_DWORD *)(a2 + 1024) = v353;
    v355 = v354 + *(_DWORD *)(v306 + 836);
    v356 = *(_DWORD *)(a2 + 1032);
    *(_DWORD *)(a2 + 1028) = v355;
    v357 = v356 + *(_DWORD *)(v306 + 840);
    v358 = *(_DWORD *)(a2 + 1036);
    *(_DWORD *)(a2 + 1032) = v357;
    v359 = v358 + *(_DWORD *)(v306 + 844);
    v360 = *(_DWORD *)(a2 + 1040);
    *(_DWORD *)(a2 + 1036) = v359;
    v361 = v360 + *(_DWORD *)(v306 + 848);
    v362 = *(_DWORD *)(a2 + 1044);
    *(_DWORD *)(a2 + 1040) = v361;
    v363 = v362 + *(_DWORD *)(v306 + 852);
    v364 = *(_DWORD *)(a2 + 1048);
    *(_DWORD *)(a2 + 1044) = v363;
    v365 = v364 + *(_DWORD *)(v306 + 856);
    v366 = *(_DWORD *)(a2 + 1052);
    *(_DWORD *)(a2 + 1048) = v365;
    v367 = v366 + *(_DWORD *)(v306 + 860);
    v368 = *(_DWORD *)(a2 + 1056);
    *(_DWORD *)(a2 + 1052) = v367;
    v369 = v368 + *(_DWORD *)(v306 + 864);
    v370 = *(_DWORD *)(a2 + 1060);
    *(_DWORD *)(a2 + 1056) = v369;
    v371 = v370 + *(_DWORD *)(v306 + 868);
    v372 = *(_DWORD *)(a2 + 1064);
    *(_DWORD *)(a2 + 1060) = v371;
    v373 = v372 + *(_DWORD *)(v306 + 872);
    v374 = *(_DWORD *)(a2 + 1068);
    *(_DWORD *)(a2 + 1064) = v373;
    v375 = v374 + *(_DWORD *)(v306 + 876);
    v376 = *(_DWORD *)(a2 + 1072);
    *(_DWORD *)(a2 + 1068) = v375;
    v377 = v376 + *(_DWORD *)(v306 + 880);
    v378 = *(_DWORD *)(a2 + 1076);
    *(_DWORD *)(a2 + 1072) = v377;
    v379 = v378 + *(_DWORD *)(v306 + 884);
    v380 = *(_DWORD *)(a2 + 1080);
    *(_DWORD *)(a2 + 1076) = v379;
    v381 = v380 + *(_DWORD *)(v306 + 888);
    v382 = *(_DWORD *)(a2 + 1084);
    *(_DWORD *)(a2 + 1080) = v381;
    v383 = v382 + *(_DWORD *)(v306 + 892);
    v384 = *(_DWORD *)(a2 + 1088);
    *(_DWORD *)(a2 + 1084) = v383;
    v385 = v384 + *(_DWORD *)(v306 + 896);
    v386 = *(_DWORD *)(a2 + 1092);
    *(_DWORD *)(a2 + 1088) = v385;
    v387 = v386 + *(_DWORD *)(v306 + 900);
    v388 = *(_DWORD *)(a2 + 1096);
    *(_DWORD *)(a2 + 1092) = v387;
    v389 = v388 + *(_DWORD *)(v306 + 904);
    v390 = *(_DWORD *)(a2 + 1100);
    *(_DWORD *)(a2 + 1096) = v389;
    *(_DWORD *)(a2 + 1100) = v390 + *(_DWORD *)(v306 + 908);
    do
    {
      v391 = *(_DWORD *)(v306 + 912 + v339);
      v392 = a2 + v339;
      v339 += 4;
      *(_DWORD *)(v392 + 1104) = v391;
    }
    while ( v339 != 256 );
    v393 = 0;
    v394 = *(_DWORD *)(a2 + 4204);
    v395 = *(_QWORD *)(a2 + 2144);
    *(_QWORD *)(a2 + 2136) += *(_QWORD *)(v306 + 1192);
    v396 = v395 + *(_QWORD *)(v306 + 1200);
    v397 = *(_QWORD *)(a2 + 2152);
    *(_QWORD *)(a2 + 2144) = v396;
    v398 = v397 + *(_QWORD *)(v306 + 1208);
    v399 = *(_QWORD *)(a2 + 2160);
    *(_QWORD *)(a2 + 2152) = v398;
    v400 = v399 + *(_QWORD *)(v306 + 1216);
    v401 = *(_QWORD *)(a2 + 2744);
    *(_QWORD *)(a2 + 2160) = v400;
    *(_DWORD *)(a2 + 884) = *(_DWORD *)(v306 + 1464);
    *(_DWORD *)(a2 + 888) = *(_DWORD *)(v306 + 1468);
    *(_DWORD *)(a2 + 892) = *(_DWORD *)(v306 + 1472);
    *(_DWORD *)(a2 + 896) = *(_DWORD *)(v306 + 1476);
    *(_DWORD *)(a2 + 900) = *(_DWORD *)(v306 + 1480);
    *(_DWORD *)(a2 + 904) = *(_DWORD *)(v306 + 1484);
    *(_DWORD *)(a2 + 908) = *(_DWORD *)(v306 + 1488);
    *(_DWORD *)(a2 + 912) = *(_DWORD *)(v306 + 1492);
    v402 = v401 + *(_QWORD *)(v306 + 1528);
    LODWORD(v401) = *(_DWORD *)(a2 + 3664);
    *(_QWORD *)(a2 + 2744) = v402;
    LODWORD(v402) = v401 + *(_DWORD *)(v306 + 1960);
    LODWORD(v401) = *(_DWORD *)(a2 + 3668);
    *(_DWORD *)(a2 + 3664) = v402;
    LODWORD(v402) = v401 + *(_DWORD *)(v306 + 1964);
    v403 = *(_QWORD *)(a2 + 4504);
    *(_DWORD *)(a2 + 3668) = v402;
    v404 = v403 + *(_QWORD *)(v306 + 2816);
    v405 = *(_QWORD *)(a2 + 4512);
    *(_QWORD *)(a2 + 4504) = v404;
    v406 = v405 + *(_QWORD *)(v306 + 2824);
    LODWORD(v405) = *(_DWORD *)(a2 + 4004);
    *(_QWORD *)(a2 + 4512) = v406;
    LODWORD(v406) = v405 + *(_DWORD *)(v306 + 1968);
    LODWORD(v405) = *(_DWORD *)(a2 + 4008);
    *(_DWORD *)(a2 + 4004) = v406;
    LODWORD(v406) = v405 + *(_DWORD *)(v306 + 1972);
    LODWORD(v405) = *(_DWORD *)(a2 + 4084);
    *(_DWORD *)(a2 + 4008) = v406;
    LODWORD(v406) = v405 + *(_DWORD *)(v306 + 1976);
    LODWORD(v405) = *(_DWORD *)(a2 + 4088);
    *(_DWORD *)(a2 + 4084) = v406;
    LODWORD(v406) = v405 + *(_DWORD *)(v306 + 1980);
    LODWORD(v405) = *(_DWORD *)(a2 + 4536);
    *(_DWORD *)(a2 + 4088) = v406;
    *(_DWORD *)(a2 + 4028) = *(_DWORD *)(v306 + 2484);
    *(_DWORD *)(a2 + 4032) = *(_DWORD *)(v306 + 2488);
    *(_DWORD *)(a2 + 4036) = *(_DWORD *)(v306 + 2492);
    *(_DWORD *)(a2 + 4040) = *(_DWORD *)(v306 + 2496);
    *(_DWORD *)(a2 + 4100) = *(_DWORD *)(v306 + 2500);
    *(_DWORD *)(a2 + 4024) = *(_DWORD *)(v306 + 2504);
    *(_QWORD *)(a2 + 4112) = *(_QWORD *)(v306 + 2512);
    *(_DWORD *)(a2 + 4536) = v405 + *(_DWORD *)(v306 + 2808);
    *(_BYTE *)(v12 + 24) = *(_BYTE *)(v306 + 2520);
    *(_BYTE *)(v12 + 25) = *(_BYTE *)(v306 + 2521);
    v407 = v394 & 0xFFFFFFF0 | *(_DWORD *)(v306 + 2522) & 0xF;
    *(_DWORD *)(a2 + 4204) = v407;
    v408 = v407 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v306 + 2522) >> 4) & 0xF));
    *(_DWORD *)(a2 + 4204) = v408;
    v409 = v408 & 0xFFFFF0FF | (((*(_DWORD *)(v306 + 2522) >> 8) & 0xF) << 8);
    *(_DWORD *)(a2 + 4204) = v409;
    v410 = v409 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v306 + 2522)) >> 4 << 12);
    LODWORD(v405) = *(_DWORD *)(a2 + 4224);
    *(_DWORD *)(a2 + 4204) = v410;
    *(_DWORD *)(a2 + 4204) = v410 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v306 + 2522)) & 0xF) << 16);
    *(_DWORD *)(a2 + 4224) = v405 + *(_DWORD *)(v306 + 2528);
    *(_DWORD *)(a2 + 4456) = *(_DWORD *)(v306 + 2756);
    v411 = v15 + 4072LL * peer_link_id + 4928;
    *(_DWORD *)(a2 + 4460) = *(_DWORD *)(v306 + 2760);
    do
    {
      v412 = (_DWORD *)(v411 + v393);
      v413 = (_DWORD *)(a2 + v393);
      v393 += 68;
      v414 = v413[794];
      v413[793] += *(v412 - 16);
      v415 = v414 + *(v412 - 15);
      v416 = v413[795];
      v413[794] = v415;
      v417 = v416 + *(v412 - 14);
      v418 = v413[796];
      v413[795] = v417;
      v419 = v418 + *(v412 - 13);
      v420 = v413[797];
      v413[796] = v419;
      v421 = v420 + *(v412 - 12);
      v422 = v413[798];
      v413[797] = v421;
      v423 = v422 + *(v412 - 11);
      v424 = v413[799];
      v413[798] = v423;
      v425 = v424 + *(v412 - 10);
      v426 = v413[800];
      v413[799] = v425;
      v427 = v426 + *(v412 - 9);
      v428 = v413[801];
      v413[800] = v427;
      v429 = v428 + *(v412 - 8);
      v430 = v413[802];
      v413[801] = v429;
      v431 = v430 + *(v412 - 7);
      v432 = v413[803];
      v413[802] = v431;
      v433 = v432 + *(v412 - 6);
      v434 = v413[804];
      v413[803] = v433;
      v435 = v434 + *(v412 - 5);
      v436 = v413[805];
      v413[804] = v435;
      v437 = v436 + *(v412 - 4);
      v438 = v413[806];
      v413[805] = v437;
      v439 = v438 + *(v412 - 3);
      v440 = v413[807];
      v413[806] = v439;
      v441 = v440 + *(v412 - 2);
      v442 = v413[808];
      v413[807] = v441;
      v413[808] = v442 + *(v412 - 1);
      v413[809] += *v412;
    }
    while ( v393 != 408 );
    v443 = 0;
    v444 = *(_QWORD *)(a2 + 4472);
    *(_DWORD *)(a2 + 3140) += *(_DWORD *)(v306 + 1944);
    v445 = v444 + *(_QWORD *)(v306 + 2768);
    LODWORD(v444) = *(_DWORD *)(a2 + 3144);
    *(_QWORD *)(a2 + 4472) = v445;
    LODWORD(v445) = v444 + *(_DWORD *)(v306 + 1948);
    v446 = *(_QWORD *)(a2 + 4480);
    *(_DWORD *)(a2 + 3144) = v445;
    v447 = v446 + *(_QWORD *)(v306 + 2776);
    LODWORD(v446) = *(_DWORD *)(a2 + 3148);
    *(_QWORD *)(a2 + 4480) = v447;
    LODWORD(v447) = v446 + *(_DWORD *)(v306 + 1952);
    v448 = *(_QWORD *)(a2 + 4488);
    *(_DWORD *)(a2 + 3148) = v447;
    v449 = v448 + *(_QWORD *)(v306 + 2784);
    LODWORD(v448) = *(_DWORD *)(a2 + 3152);
    *(_QWORD *)(a2 + 4488) = v449;
    LODWORD(v449) = v448 + *(_DWORD *)(v306 + 1956);
    v450 = *(_QWORD *)(a2 + 4496);
    *(_DWORD *)(a2 + 3152) = v449;
    *(_QWORD *)(a2 + 4496) = v450 + *(_QWORD *)(v306 + 2792);
    do
    {
      v451 = (_DWORD *)(v306 + 1984 + v443);
      v452 = a2 + v443;
      v443 += 4;
      *(_DWORD *)(v452 + 3672) += *v451;
      *(_DWORD *)(v452 + 4136) += v451[108];
    }
    while ( v443 != 68 );
    v453 = 0;
    v454 = 1;
    do
    {
      v455 = 108 * v453;
      v456 = (_DWORD *)(v306 + 2052 + v455);
      v457 = (_DWORD *)(a2 + 3756 + v455);
      v458 = v457[9];
      v457[8] += v456[8];
      v457[9] = v458 + v456[9];
      v459 = v457[1];
      *v457 += *v456;
      v457[1] = v459 + v456[1];
      v460 = v457[3];
      v457[2] += v456[2];
      v457[3] = v460 + v456[3];
      v461 = v457[5];
      v457[4] += v456[4];
      v457[5] = v461 + v456[5];
      v462 = v457[7];
      v457[6] += v456[6];
      v457[7] = v462 + v456[7];
      v463 = v457[11];
      v457[10] += v456[10];
      v457[11] = v463 + v456[11];
      v464 = v457[13];
      v457[12] += v456[12];
      v457[13] = v464 + v456[13];
      v465 = v457[15];
      v457[14] += v456[14];
      v457[15] = v465 + v456[15];
      v466 = v457[17];
      v457[16] += v456[16];
      v457[17] = v466 + v456[17];
      v467 = v457[19];
      v457[18] += v456[18];
      v457[19] = v467 + v456[19];
      v468 = v457[21];
      v457[20] += v456[20];
      v457[21] = v468 + v456[21];
      v469 = v457[23];
      v457[22] += v456[22];
      v457[23] = v469 + v456[23];
      v470 = v457[25];
      v471 = v454;
      v457[24] += v456[24];
      v457[25] = v470 + v456[25];
      v457[26] += v456[26];
      v453 = 1;
      v454 = 0;
    }
    while ( (v471 & 1) != 0 );
    v472 = 0;
    v473 = *(_DWORD *)(a2 + 3740);
    *(_DWORD *)(a2 + 3156) += *(_DWORD *)(v306 + 2268);
    v474 = v473 + *(_DWORD *)(v306 + 2284);
    v475 = *(_DWORD *)(a2 + 3160);
    *(_DWORD *)(a2 + 3740) = v474;
    v476 = v475 + *(_DWORD *)(v306 + 2272);
    v477 = *(_DWORD *)(a2 + 3744);
    *(_DWORD *)(a2 + 3160) = v476;
    v478 = v477 + *(_DWORD *)(v306 + 2288);
    v479 = *(_DWORD *)(a2 + 3164);
    *(_DWORD *)(a2 + 3744) = v478;
    v480 = v479 + *(_DWORD *)(v306 + 2276);
    v481 = *(_DWORD *)(a2 + 3748);
    *(_DWORD *)(a2 + 3164) = v480;
    v482 = v481 + *(_DWORD *)(v306 + 2292);
    v483 = *(_DWORD *)(a2 + 3168);
    *(_DWORD *)(a2 + 3748) = v482;
    v484 = v483 + *(_DWORD *)(v306 + 2280);
    v485 = *(_DWORD *)(a2 + 3752);
    *(_DWORD *)(a2 + 3168) = v484;
    v486 = v485 + *(_DWORD *)(v306 + 2296);
    v487 = *(_DWORD *)(a2 + 3580);
    *(_DWORD *)(a2 + 3752) = v486;
    v488 = v487 + *(_DWORD *)(v306 + 2300);
    v489 = *(_DWORD *)(a2 + 3584);
    *(_DWORD *)(a2 + 3580) = v488;
    v490 = v489 + *(_DWORD *)(v306 + 2304);
    v491 = *(_DWORD *)(a2 + 3588);
    *(_DWORD *)(a2 + 3584) = v490;
    v492 = v491 + *(_DWORD *)(v306 + 2308);
    v493 = *(_DWORD *)(a2 + 3592);
    *(_DWORD *)(a2 + 3588) = v492;
    v494 = v493 + *(_DWORD *)(v306 + 2312);
    v495 = *(_DWORD *)(a2 + 3596);
    *(_DWORD *)(a2 + 3592) = v494;
    v496 = v495 + *(_DWORD *)(v306 + 2316);
    v497 = *(_DWORD *)(a2 + 3600);
    *(_DWORD *)(a2 + 3596) = v496;
    v498 = v497 + *(_DWORD *)(v306 + 2320);
    v499 = *(_DWORD *)(a2 + 3632);
    *(_DWORD *)(a2 + 3600) = v498;
    v500 = v499 + *(_DWORD *)(v306 + 2352);
    v501 = *(_DWORD *)(a2 + 3604);
    *(_DWORD *)(a2 + 3632) = v500;
    v502 = v501 + *(_DWORD *)(v306 + 2324);
    v503 = *(_DWORD *)(a2 + 3636);
    *(_DWORD *)(a2 + 3604) = v502;
    v504 = v503 + *(_DWORD *)(v306 + 2356);
    v505 = *(_DWORD *)(a2 + 3608);
    *(_DWORD *)(a2 + 3636) = v504;
    v506 = v505 + *(_DWORD *)(v306 + 2328);
    v507 = *(_DWORD *)(a2 + 3640);
    *(_DWORD *)(a2 + 3608) = v506;
    v508 = v507 + *(_DWORD *)(v306 + 2360);
    v509 = *(_DWORD *)(a2 + 3612);
    *(_DWORD *)(a2 + 3640) = v508;
    v510 = v509 + *(_DWORD *)(v306 + 2332);
    v511 = *(_DWORD *)(a2 + 3644);
    *(_DWORD *)(a2 + 3612) = v510;
    v512 = v511 + *(_DWORD *)(v306 + 2364);
    v513 = *(_DWORD *)(a2 + 3616);
    *(_DWORD *)(a2 + 3644) = v512;
    v514 = v513 + *(_DWORD *)(v306 + 2336);
    v515 = *(_DWORD *)(a2 + 3648);
    *(_DWORD *)(a2 + 3616) = v514;
    v516 = v515 + *(_DWORD *)(v306 + 2368);
    v517 = *(_DWORD *)(a2 + 3620);
    *(_DWORD *)(a2 + 3648) = v516;
    v518 = v517 + *(_DWORD *)(v306 + 2340);
    v519 = *(_DWORD *)(a2 + 3652);
    *(_DWORD *)(a2 + 3620) = v518;
    v520 = v519 + *(_DWORD *)(v306 + 2372);
    v521 = *(_DWORD *)(a2 + 3624);
    *(_DWORD *)(a2 + 3652) = v520;
    v522 = v521 + *(_DWORD *)(v306 + 2344);
    v523 = *(_DWORD *)(a2 + 3656);
    *(_DWORD *)(a2 + 3624) = v522;
    v524 = v523 + *(_DWORD *)(v306 + 2376);
    v525 = *(_DWORD *)(a2 + 3628);
    *(_DWORD *)(a2 + 3656) = v524;
    v526 = v525 + *(_DWORD *)(v306 + 2348);
    v527 = *(_DWORD *)(a2 + 3660);
    *(_DWORD *)(a2 + 3628) = v526;
    v528 = v527 + *(_DWORD *)(v306 + 2380);
    v529 = *(_DWORD *)(a2 + 3972);
    *(_DWORD *)(a2 + 3660) = v528;
    v530 = v529 + *(_DWORD *)(v306 + 2384);
    v531 = *(_DWORD *)(a2 + 3976);
    *(_DWORD *)(a2 + 3972) = v530;
    v532 = v531 + *(_DWORD *)(v306 + 2388);
    v533 = *(_DWORD *)(a2 + 3980);
    *(_DWORD *)(a2 + 3976) = v532;
    v534 = v533 + *(_DWORD *)(v306 + 2392);
    v535 = *(_DWORD *)(a2 + 3984);
    *(_DWORD *)(a2 + 3980) = v534;
    v536 = v535 + *(_DWORD *)(v306 + 2396);
    v537 = *(_DWORD *)(a2 + 3988);
    *(_DWORD *)(a2 + 3984) = v536;
    v538 = v537 + *(_DWORD *)(v306 + 2400);
    v539 = *(_DWORD *)(a2 + 3992);
    *(_DWORD *)(a2 + 3988) = v538;
    v540 = v539 + *(_DWORD *)(v306 + 2404);
    v541 = *(_DWORD *)(a2 + 3996);
    *(_DWORD *)(a2 + 3992) = v540;
    v542 = v541 + *(_DWORD *)(v306 + 2408);
    v543 = *(_DWORD *)(a2 + 4000);
    *(_DWORD *)(a2 + 3996) = v542;
    v544 = v543 + *(_DWORD *)(v306 + 2412);
    v545 = *(_QWORD *)(a2 + 4528);
    *(_DWORD *)(a2 + 4000) = v544;
    *(_QWORD *)(a2 + 4528) = v545 + *(_QWORD *)(v306 + 2800);
    do
    {
      v546 = (_DWORD *)(v306 + 1224 + v472);
      v547 = a2 + v472;
      v472 += 4;
      *(_DWORD *)(v547 + 1848) += *v546;
      *(_DWORD *)(v547 + 4228) += v546[327];
    }
    while ( v472 != 68 );
    for ( i = 0; i != 68; i += 4 )
    {
      v549 = (_DWORD *)(v306 + 1292 + i);
      v550 = a2 + i;
      *(_DWORD *)(v550 + 1916) += *v549;
      *(_DWORD *)(v550 + 4296) += v549[327];
    }
    for ( j = 0; j != 68; j += 4 )
    {
      v552 = (_DWORD *)(v306 + 1360 + j);
      v553 = a2 + j;
      *(_DWORD *)(v553 + 1984) += *v552;
      *(_DWORD *)(v553 + 4364) += v552[327];
    }
    v554 = *(_DWORD *)(a2 + 4432);
    *(_DWORD *)(a2 + 2052) += *(_DWORD *)(v306 + 1428);
    v555 = v554 + *(_DWORD *)(v306 + 2736);
    v556 = *(_DWORD *)(a2 + 2056);
    *(_DWORD *)(a2 + 4432) = v555;
    v557 = v556 + *(_DWORD *)(v306 + 1432);
    v558 = *(_DWORD *)(a2 + 4436);
    *(_DWORD *)(a2 + 2056) = v557;
    v559 = v558 + *(_DWORD *)(v306 + 2740);
    v560 = *(_DWORD *)(a2 + 2060);
    *(_DWORD *)(a2 + 4436) = v559;
    v561 = v560 + *(_DWORD *)(v306 + 1436);
    v562 = *(_DWORD *)(a2 + 4440);
    *(_DWORD *)(a2 + 2060) = v561;
    v563 = v562 + *(_DWORD *)(v306 + 2744);
    v564 = *(_DWORD *)(a2 + 2064);
    *(_DWORD *)(a2 + 4440) = v563;
    v565 = v564 + *(_DWORD *)(v306 + 1440);
    v566 = *(_DWORD *)(a2 + 4444);
    *(_DWORD *)(a2 + 2064) = v565;
    v567 = v566 + *(_DWORD *)(v306 + 2748);
    v568 = *(_DWORD *)(a2 + 2068);
    *(_DWORD *)(a2 + 4444) = v567;
    *(_DWORD *)(a2 + 2068) = v568 + *(_DWORD *)(v306 + 1444);
    *(_DWORD *)(a2 + 4448) += *(_DWORD *)(v306 + 2752);
    result = (__int64 *)qdf_mem_copy((void *)a2, (const void *)(v11 + 44), 6u);
    goto LABEL_51;
  }
  v15 = *result;
  if ( !*result )
    goto LABEL_66;
  if ( v13 != 2 )
    goto LABEL_32;
  result = (__int64 *)dp_get_link_peers_ref_from_mld_peer(
                        *(_QWORD *)(*(_QWORD *)(result[3] + 24) + 8LL),
                        (int)result,
                        (int)&v570);
  if ( (_BYTE)v574 )
  {
    v16 = 0;
    v17 = v15 + 3404;
    v18 = v15 + 3948;
    result = (__int64 *)(v15 + 4240);
    v19 = v15 + 4928;
    v20 = v15 + 5312;
    v21 = v15 + 4552;
    v22 = v15 + 4620;
    v23 = v15 + 4688;
    while ( 1 )
    {
      v24 = v15 + 2288 + 4072 * v16;
      v25 = 0;
      v26 = *(_DWORD *)(a2 + 120);
      *(_DWORD *)(a2 + 116) += *(_DWORD *)(v24 + 1040);
      *(_DWORD *)(a2 + 120) = v26 + *(_DWORD *)(v24 + 1044);
      v27 = *(_DWORD *)(a2 + 128);
      v28 = *(_DWORD *)(a2 + 948);
      *(_DWORD *)(a2 + 124) += *(_DWORD *)(v24 + 1048);
      v29 = v28 + *(_DWORD *)(v24 + 1492);
      v30 = *(_DWORD *)(a2 + 952);
      *(_DWORD *)(a2 + 948) = v29;
      v31 = v30 + *(_DWORD *)(v24 + 1496);
      v32 = *(_DWORD *)(a2 + 1560);
      *(_DWORD *)(a2 + 952) = v31;
      v33 = v32 + *(_DWORD *)(v24 + 1500);
      v34 = *(_DWORD *)(a2 + 984);
      *(_DWORD *)(a2 + 1560) = v33;
      v35 = v34 + *(_DWORD *)(v24 + 1504);
      v36 = *(_DWORD *)(a2 + 988);
      *(_DWORD *)(a2 + 984) = v35;
      v37 = v36 + *(_DWORD *)(v24 + 1508);
      v38 = *(_DWORD *)(a2 + 992);
      *(_DWORD *)(a2 + 988) = v37;
      v39 = v38 + *(_DWORD *)(v24 + 1512);
      v40 = *(_DWORD *)(a2 + 644);
      *(_DWORD *)(a2 + 992) = v39;
      *(_DWORD *)(a2 + 140) = *(_DWORD *)(v24 + 1516);
      *(_DWORD *)(a2 + 144) = *(_DWORD *)(v24 + 1520);
      *(_DWORD *)(a2 + 148) = *(_DWORD *)(v24 + 1524);
      *(_DWORD *)(a2 + 152) = *(_DWORD *)(v24 + 1528);
      *(_DWORD *)(a2 + 156) = *(_DWORD *)(v24 + 1532);
      *(_QWORD *)(a2 + 168) = *(_QWORD *)(v24 + 1536);
      *(_QWORD *)(a2 + 176) = *(_QWORD *)(v24 + 1544);
      *(_WORD *)(a2 + 944) = *(_WORD *)(v24 + 1552);
      v41 = v40 + *(_DWORD *)(v24 + 1576);
      v42 = *(_DWORD *)(a2 + 1832);
      *(_DWORD *)(a2 + 644) = v41;
      *(_DWORD *)(a2 + 1360) = *(_DWORD *)(v24 + 1644);
      *(_DWORD *)(a2 + 1364) = *(_DWORD *)(v24 + 1648);
      *(_DWORD *)(a2 + 184) = *(_DWORD *)(v24 + 2208);
      *(_DWORD *)(a2 + 188) = *(_DWORD *)(v24 + 2212);
      v43 = v42 & 0xFFFFFFF0 | *(_DWORD *)(v24 + 2220) & 0xF;
      *(_DWORD *)(a2 + 1832) = v43;
      v44 = v43 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v24 + 2220) >> 4) & 0xF));
      *(_DWORD *)(a2 + 1832) = v44;
      v45 = v44 & 0xFFFFF0FF | (((*(_DWORD *)(v24 + 2220) >> 8) & 0xF) << 8);
      *(_DWORD *)(a2 + 1832) = v45;
      v46 = v45 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v24 + 2220)) >> 4 << 12);
      *(_DWORD *)(a2 + 1832) = v46;
      *(_DWORD *)(a2 + 1832) = v46 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v24 + 2220)) & 0xF) << 16);
      v47 = *(_DWORD *)(a2 + 1836);
      *(_DWORD *)(a2 + 128) = v27 + *(_DWORD *)(v24 + 2224);
      *(_DWORD *)(a2 + 1836) = v47 + *(_DWORD *)(v24 + 2228);
      *(_DWORD *)(a2 + 2080) = *(_DWORD *)(v24 + 2488);
      *(_DWORD *)(a2 + 2084) = *(_DWORD *)(v24 + 2492);
      *(_DWORD *)(a2 + 2088) = *(_DWORD *)(v24 + 2496);
      v48 = *(_DWORD *)(v24 + 2500);
      v49 = v24 + 1040;
      *(_DWORD *)(a2 + 2092) = v48;
      do
      {
        v50 = (_DWORD *)(a2 + 216 + v25);
        v51 = (_DWORD *)(v17 + v25);
        v25 += 68;
        v52 = v50[1];
        *v50 += *(v51 - 16);
        v50[1] = v52 + *(v51 - 15);
        v53 = v50[3];
        v50[2] += *(v51 - 14);
        v50[3] = v53 + *(v51 - 13);
        v54 = v50[5];
        v50[4] += *(v51 - 12);
        v50[5] = v54 + *(v51 - 11);
        v55 = v50[7];
        v50[6] += *(v51 - 10);
        v50[7] = v55 + *(v51 - 9);
        v56 = v50[9];
        v50[8] += *(v51 - 8);
        v50[9] = v56 + *(v51 - 7);
        v57 = v50[11];
        v50[10] += *(v51 - 6);
        v50[11] = v57 + *(v51 - 5);
        v58 = v50[13];
        v50[12] += *(v51 - 4);
        v50[13] = v58 + *(v51 - 3);
        v59 = v50[15];
        v50[14] += *(v51 - 2);
        v50[15] = v59 + *(v51 - 1);
        v50[16] += *v51;
      }
      while ( v25 != 408 );
      v60 = 0;
      v61 = *(_QWORD *)(a2 + 2104);
      *(_DWORD *)(a2 + 712) += *(_DWORD *)(v49 + 420);
      v62 = v61 + *(_QWORD *)(v49 + 1496);
      LODWORD(v61) = *(_DWORD *)(a2 + 728);
      *(_QWORD *)(a2 + 2104) = v62;
      LODWORD(v62) = v61 + *(_DWORD *)(v49 + 436);
      LODWORD(v61) = *(_DWORD *)(a2 + 716);
      *(_DWORD *)(a2 + 728) = v62;
      LODWORD(v62) = v61 + *(_DWORD *)(v49 + 424);
      v63 = *(_QWORD *)(a2 + 2112);
      *(_DWORD *)(a2 + 716) = v62;
      v64 = v63 + *(_QWORD *)(v49 + 1504);
      LODWORD(v63) = *(_DWORD *)(a2 + 732);
      *(_QWORD *)(a2 + 2112) = v64;
      LODWORD(v64) = v63 + *(_DWORD *)(v49 + 440);
      LODWORD(v63) = *(_DWORD *)(a2 + 720);
      *(_DWORD *)(a2 + 732) = v64;
      LODWORD(v64) = v63 + *(_DWORD *)(v49 + 428);
      v65 = *(_QWORD *)(a2 + 2120);
      *(_DWORD *)(a2 + 720) = v64;
      v66 = v65 + *(_QWORD *)(v49 + 1512);
      LODWORD(v65) = *(_DWORD *)(a2 + 736);
      *(_QWORD *)(a2 + 2120) = v66;
      LODWORD(v66) = v65 + *(_DWORD *)(v49 + 444);
      LODWORD(v65) = *(_DWORD *)(a2 + 724);
      *(_DWORD *)(a2 + 736) = v66;
      LODWORD(v66) = v65 + *(_DWORD *)(v49 + 432);
      v67 = *(_QWORD *)(a2 + 2128);
      *(_DWORD *)(a2 + 724) = v66;
      v68 = v67 + *(_QWORD *)(v49 + 1520);
      LODWORD(v67) = *(_DWORD *)(a2 + 740);
      *(_QWORD *)(a2 + 2128) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 448);
      LODWORD(v67) = *(_DWORD *)(a2 + 624);
      *(_DWORD *)(a2 + 740) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 516);
      LODWORD(v67) = *(_DWORD *)(a2 + 628);
      *(_DWORD *)(a2 + 624) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 520);
      LODWORD(v67) = *(_DWORD *)(a2 + 632);
      *(_DWORD *)(a2 + 628) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 524);
      LODWORD(v67) = *(_DWORD *)(a2 + 636);
      *(_DWORD *)(a2 + 632) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 528);
      LODWORD(v67) = *(_DWORD *)(a2 + 640);
      *(_DWORD *)(a2 + 636) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 532);
      LODWORD(v67) = *(_DWORD *)(a2 + 648);
      *(_DWORD *)(a2 + 640) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 540);
      LODWORD(v67) = *(_DWORD *)(a2 + 652);
      *(_DWORD *)(a2 + 648) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 544);
      LODWORD(v67) = *(_DWORD *)(a2 + 656);
      *(_DWORD *)(a2 + 652) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 548);
      LODWORD(v67) = *(_DWORD *)(a2 + 660);
      *(_DWORD *)(a2 + 656) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 552);
      LODWORD(v67) = *(_DWORD *)(a2 + 664);
      *(_DWORD *)(a2 + 660) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 556);
      LODWORD(v67) = *(_DWORD *)(a2 + 668);
      *(_DWORD *)(a2 + 664) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 560);
      LODWORD(v67) = *(_DWORD *)(a2 + 672);
      *(_DWORD *)(a2 + 668) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 564);
      LODWORD(v67) = *(_DWORD *)(a2 + 676);
      *(_DWORD *)(a2 + 672) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 568);
      LODWORD(v67) = *(_DWORD *)(a2 + 680);
      *(_DWORD *)(a2 + 676) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 572);
      LODWORD(v67) = *(_DWORD *)(a2 + 684);
      *(_DWORD *)(a2 + 680) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 576);
      LODWORD(v67) = *(_DWORD *)(a2 + 688);
      *(_DWORD *)(a2 + 684) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 580);
      LODWORD(v67) = *(_DWORD *)(a2 + 692);
      *(_DWORD *)(a2 + 688) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 584);
      LODWORD(v67) = *(_DWORD *)(a2 + 696);
      *(_DWORD *)(a2 + 692) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 588);
      LODWORD(v67) = *(_DWORD *)(a2 + 700);
      *(_DWORD *)(a2 + 696) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 592);
      LODWORD(v67) = *(_DWORD *)(a2 + 704);
      *(_DWORD *)(a2 + 700) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v49 + 596);
      LODWORD(v67) = *(_DWORD *)(a2 + 708);
      *(_DWORD *)(a2 + 704) = v68;
      *(_DWORD *)(a2 + 708) = v67 + *(_DWORD *)(v49 + 600);
      do
      {
        v69 = (_DWORD *)(a2 + 1368 + v60);
        v70 = (_DWORD *)(v18 + v60);
        v60 += 12;
        v71 = v69[1];
        *v69 += *(v70 - 2);
        v69[1] = v71 + *(v70 - 1);
        v69[2] += *v70;
      }
      while ( v60 != 192 );
      v72 = 0;
      v73 = *(_DWORD *)(a2 + 1000);
      *(_DWORD *)(a2 + 996) += *(_DWORD *)(v49 + 804);
      v74 = v73 + *(_DWORD *)(v49 + 808);
      v75 = *(_DWORD *)(a2 + 1004);
      *(_DWORD *)(a2 + 1000) = v74;
      v76 = v75 + *(_DWORD *)(v49 + 812);
      v77 = *(_DWORD *)(a2 + 1008);
      *(_DWORD *)(a2 + 1004) = v76;
      v78 = v77 + *(_DWORD *)(v49 + 816);
      v79 = *(_DWORD *)(a2 + 1012);
      *(_DWORD *)(a2 + 1008) = v78;
      v80 = v79 + *(_DWORD *)(v49 + 820);
      v81 = *(_DWORD *)(a2 + 1016);
      *(_DWORD *)(a2 + 1012) = v80;
      v82 = v81 + *(_DWORD *)(v49 + 824);
      v83 = *(_DWORD *)(a2 + 1020);
      *(_DWORD *)(a2 + 1016) = v82;
      v84 = v83 + *(_DWORD *)(v49 + 828);
      v85 = *(_DWORD *)(a2 + 1024);
      *(_DWORD *)(a2 + 1020) = v84;
      v86 = v85 + *(_DWORD *)(v49 + 832);
      v87 = *(_DWORD *)(a2 + 1028);
      *(_DWORD *)(a2 + 1024) = v86;
      v88 = v87 + *(_DWORD *)(v49 + 836);
      v89 = *(_DWORD *)(a2 + 1032);
      *(_DWORD *)(a2 + 1028) = v88;
      v90 = v89 + *(_DWORD *)(v49 + 840);
      v91 = *(_DWORD *)(a2 + 1036);
      *(_DWORD *)(a2 + 1032) = v90;
      v92 = v91 + *(_DWORD *)(v49 + 844);
      v93 = *(_DWORD *)(a2 + 1040);
      *(_DWORD *)(a2 + 1036) = v92;
      v94 = v93 + *(_DWORD *)(v49 + 848);
      v95 = *(_DWORD *)(a2 + 1044);
      *(_DWORD *)(a2 + 1040) = v94;
      v96 = v95 + *(_DWORD *)(v49 + 852);
      v97 = *(_DWORD *)(a2 + 1048);
      *(_DWORD *)(a2 + 1044) = v96;
      v98 = v97 + *(_DWORD *)(v49 + 856);
      v99 = *(_DWORD *)(a2 + 1052);
      *(_DWORD *)(a2 + 1048) = v98;
      v100 = v99 + *(_DWORD *)(v49 + 860);
      v101 = *(_DWORD *)(a2 + 1056);
      *(_DWORD *)(a2 + 1052) = v100;
      v102 = v101 + *(_DWORD *)(v49 + 864);
      v103 = *(_DWORD *)(a2 + 1060);
      *(_DWORD *)(a2 + 1056) = v102;
      v104 = v103 + *(_DWORD *)(v49 + 868);
      v105 = *(_DWORD *)(a2 + 1064);
      *(_DWORD *)(a2 + 1060) = v104;
      v106 = v105 + *(_DWORD *)(v49 + 872);
      v107 = *(_DWORD *)(a2 + 1068);
      *(_DWORD *)(a2 + 1064) = v106;
      v108 = v107 + *(_DWORD *)(v49 + 876);
      v109 = *(_DWORD *)(a2 + 1072);
      *(_DWORD *)(a2 + 1068) = v108;
      v110 = v109 + *(_DWORD *)(v49 + 880);
      v111 = *(_DWORD *)(a2 + 1076);
      *(_DWORD *)(a2 + 1072) = v110;
      v112 = v111 + *(_DWORD *)(v49 + 884);
      v113 = *(_DWORD *)(a2 + 1080);
      *(_DWORD *)(a2 + 1076) = v112;
      v114 = v113 + *(_DWORD *)(v49 + 888);
      v115 = *(_DWORD *)(a2 + 1084);
      *(_DWORD *)(a2 + 1080) = v114;
      v116 = v115 + *(_DWORD *)(v49 + 892);
      v117 = *(_DWORD *)(a2 + 1088);
      *(_DWORD *)(a2 + 1084) = v116;
      v118 = v117 + *(_DWORD *)(v49 + 896);
      v119 = *(_DWORD *)(a2 + 1092);
      *(_DWORD *)(a2 + 1088) = v118;
      v120 = v119 + *(_DWORD *)(v49 + 900);
      v121 = *(_DWORD *)(a2 + 1096);
      *(_DWORD *)(a2 + 1092) = v120;
      v122 = v121 + *(_DWORD *)(v49 + 904);
      v123 = *(_DWORD *)(a2 + 1100);
      *(_DWORD *)(a2 + 1096) = v122;
      *(_DWORD *)(a2 + 1100) = v123 + *(_DWORD *)(v49 + 908);
      do
      {
        *(_DWORD *)(a2 + 1104 + v72) = *(_DWORD *)((char *)result + v72);
        v72 += 4;
      }
      while ( v72 != 256 );
      v124 = 0;
      v125 = *(_DWORD *)(a2 + 4204);
      v126 = *(_QWORD *)(a2 + 2144);
      *(_QWORD *)(a2 + 2136) += *(_QWORD *)(v49 + 1192);
      v127 = v126 + *(_QWORD *)(v49 + 1200);
      v128 = *(_QWORD *)(a2 + 2152);
      *(_QWORD *)(a2 + 2144) = v127;
      v129 = v128 + *(_QWORD *)(v49 + 1208);
      v130 = *(_QWORD *)(a2 + 2160);
      *(_QWORD *)(a2 + 2152) = v129;
      v131 = v130 + *(_QWORD *)(v49 + 1216);
      v132 = *(_QWORD *)(a2 + 2744);
      *(_QWORD *)(a2 + 2160) = v131;
      *(_DWORD *)(a2 + 884) = *(_DWORD *)(v49 + 1464);
      *(_DWORD *)(a2 + 888) = *(_DWORD *)(v49 + 1468);
      *(_DWORD *)(a2 + 892) = *(_DWORD *)(v49 + 1472);
      *(_DWORD *)(a2 + 896) = *(_DWORD *)(v49 + 1476);
      *(_DWORD *)(a2 + 900) = *(_DWORD *)(v49 + 1480);
      *(_DWORD *)(a2 + 904) = *(_DWORD *)(v49 + 1484);
      *(_DWORD *)(a2 + 908) = *(_DWORD *)(v49 + 1488);
      *(_DWORD *)(a2 + 912) = *(_DWORD *)(v49 + 1492);
      v133 = v132 + *(_QWORD *)(v49 + 1528);
      LODWORD(v132) = *(_DWORD *)(a2 + 3664);
      *(_QWORD *)(a2 + 2744) = v133;
      LODWORD(v133) = v132 + *(_DWORD *)(v49 + 1960);
      LODWORD(v132) = *(_DWORD *)(a2 + 3668);
      *(_DWORD *)(a2 + 3664) = v133;
      LODWORD(v133) = v132 + *(_DWORD *)(v49 + 1964);
      v134 = *(_QWORD *)(a2 + 4504);
      *(_DWORD *)(a2 + 3668) = v133;
      v135 = v134 + *(_QWORD *)(v49 + 2816);
      v136 = *(_QWORD *)(a2 + 4512);
      *(_QWORD *)(a2 + 4504) = v135;
      v137 = v136 + *(_QWORD *)(v49 + 2824);
      LODWORD(v136) = *(_DWORD *)(a2 + 4004);
      *(_QWORD *)(a2 + 4512) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v49 + 1968);
      LODWORD(v136) = *(_DWORD *)(a2 + 4008);
      *(_DWORD *)(a2 + 4004) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v49 + 1972);
      LODWORD(v136) = *(_DWORD *)(a2 + 4084);
      *(_DWORD *)(a2 + 4008) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v49 + 1976);
      LODWORD(v136) = *(_DWORD *)(a2 + 4088);
      *(_DWORD *)(a2 + 4084) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v49 + 1980);
      LODWORD(v136) = *(_DWORD *)(a2 + 4536);
      *(_DWORD *)(a2 + 4088) = v137;
      *(_DWORD *)(a2 + 4028) = *(_DWORD *)(v49 + 2484);
      *(_DWORD *)(a2 + 4032) = *(_DWORD *)(v49 + 2488);
      *(_DWORD *)(a2 + 4036) = *(_DWORD *)(v49 + 2492);
      *(_DWORD *)(a2 + 4040) = *(_DWORD *)(v49 + 2496);
      *(_DWORD *)(a2 + 4100) = *(_DWORD *)(v49 + 2500);
      *(_DWORD *)(a2 + 4024) = *(_DWORD *)(v49 + 2504);
      *(_QWORD *)(a2 + 4112) = *(_QWORD *)(v49 + 2512);
      *(_DWORD *)(a2 + 4536) = v136 + *(_DWORD *)(v49 + 2808);
      *(_BYTE *)(v12 + 24) = *(_BYTE *)(v49 + 2520);
      *(_BYTE *)(v12 + 25) = *(_BYTE *)(v49 + 2521);
      v138 = v125 & 0xFFFFFFF0 | *(_DWORD *)(v49 + 2522) & 0xF;
      *(_DWORD *)(a2 + 4204) = v138;
      v139 = v138 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v49 + 2522) >> 4) & 0xF));
      *(_DWORD *)(a2 + 4204) = v139;
      v140 = v139 & 0xFFFFF0FF | (((*(_DWORD *)(v49 + 2522) >> 8) & 0xF) << 8);
      *(_DWORD *)(a2 + 4204) = v140;
      v141 = v140 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v49 + 2522)) >> 4 << 12);
      LODWORD(v136) = *(_DWORD *)(a2 + 4224);
      *(_DWORD *)(a2 + 4204) = v141;
      *(_DWORD *)(a2 + 4204) = v141 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v49 + 2522)) & 0xF) << 16);
      *(_DWORD *)(a2 + 4224) = v136 + *(_DWORD *)(v49 + 2528);
      *(_DWORD *)(a2 + 4456) = *(_DWORD *)(v49 + 2756);
      *(_DWORD *)(a2 + 4460) = *(_DWORD *)(v49 + 2760);
      do
      {
        v142 = (_DWORD *)(a2 + 3172 + v124);
        v143 = (_DWORD *)(v19 + v124);
        v124 += 68;
        v144 = v142[1];
        *v142 += *(v143 - 16);
        v142[1] = v144 + *(v143 - 15);
        v145 = v142[3];
        v142[2] += *(v143 - 14);
        v142[3] = v145 + *(v143 - 13);
        v146 = v142[5];
        v142[4] += *(v143 - 12);
        v142[5] = v146 + *(v143 - 11);
        v147 = v142[7];
        v142[6] += *(v143 - 10);
        v142[7] = v147 + *(v143 - 9);
        v148 = v142[9];
        v142[8] += *(v143 - 8);
        v142[9] = v148 + *(v143 - 7);
        v149 = v142[11];
        v142[10] += *(v143 - 6);
        v142[11] = v149 + *(v143 - 5);
        v150 = v142[13];
        v142[12] += *(v143 - 4);
        v142[13] = v150 + *(v143 - 3);
        v151 = v142[15];
        v142[14] += *(v143 - 2);
        v142[15] = v151 + *(v143 - 1);
        v142[16] += *v143;
      }
      while ( v124 != 408 );
      v152 = 0;
      v153 = *(_QWORD *)(a2 + 4472);
      *(_DWORD *)(a2 + 3140) += *(_DWORD *)(v49 + 1944);
      v154 = v153 + *(_QWORD *)(v49 + 2768);
      LODWORD(v153) = *(_DWORD *)(a2 + 3144);
      *(_QWORD *)(a2 + 4472) = v154;
      LODWORD(v154) = v153 + *(_DWORD *)(v49 + 1948);
      v155 = *(_QWORD *)(a2 + 4480);
      *(_DWORD *)(a2 + 3144) = v154;
      v156 = v155 + *(_QWORD *)(v49 + 2776);
      LODWORD(v155) = *(_DWORD *)(a2 + 3148);
      *(_QWORD *)(a2 + 4480) = v156;
      LODWORD(v156) = v155 + *(_DWORD *)(v49 + 1952);
      v157 = *(_QWORD *)(a2 + 4488);
      *(_DWORD *)(a2 + 3148) = v156;
      v158 = v157 + *(_QWORD *)(v49 + 2784);
      LODWORD(v157) = *(_DWORD *)(a2 + 3152);
      *(_QWORD *)(a2 + 4488) = v158;
      LODWORD(v158) = v157 + *(_DWORD *)(v49 + 1956);
      v159 = *(_QWORD *)(a2 + 4496);
      *(_DWORD *)(a2 + 3152) = v158;
      *(_QWORD *)(a2 + 4496) = v159 + *(_QWORD *)(v49 + 2792);
      do
      {
        v160 = (_DWORD *)(v20 + v152);
        v161 = (_DWORD *)(a2 + 3672 + v152);
        v152 += 4;
        *v161 += *v160;
        v161[116] += v160[108];
      }
      while ( v152 != 68 );
      v162 = 0;
      v163 = 1;
      do
      {
        v164 = 108 * v162;
        v165 = (_DWORD *)(v49 + 2052 + v164);
        v166 = (_DWORD *)(a2 + 3756 + v164);
        v167 = v166[9];
        v166[8] += v165[8];
        v166[9] = v167 + v165[9];
        v168 = v166[1];
        *v166 += *v165;
        v166[1] = v168 + v165[1];
        v169 = v166[3];
        v166[2] += v165[2];
        v166[3] = v169 + v165[3];
        v170 = v166[5];
        v166[4] += v165[4];
        v166[5] = v170 + v165[5];
        v171 = v166[7];
        v166[6] += v165[6];
        v166[7] = v171 + v165[7];
        v172 = v166[11];
        v166[10] += v165[10];
        v166[11] = v172 + v165[11];
        v173 = v166[13];
        v166[12] += v165[12];
        v166[13] = v173 + v165[13];
        v174 = v166[15];
        v166[14] += v165[14];
        v166[15] = v174 + v165[15];
        v175 = v166[17];
        v166[16] += v165[16];
        v166[17] = v175 + v165[17];
        v176 = v166[19];
        v166[18] += v165[18];
        v166[19] = v176 + v165[19];
        v177 = v166[21];
        v166[20] += v165[20];
        v166[21] = v177 + v165[21];
        v178 = v166[23];
        v166[22] += v165[22];
        v166[23] = v178 + v165[23];
        v179 = v166[25];
        v180 = v163;
        v166[24] += v165[24];
        v166[25] = v179 + v165[25];
        v166[26] += v165[26];
        v162 = 1;
        v163 = 0;
      }
      while ( (v180 & 1) != 0 );
      v181 = 0;
      v182 = *(_DWORD *)(a2 + 3740);
      *(_DWORD *)(a2 + 3156) += *(_DWORD *)(v49 + 2268);
      v183 = v182 + *(_DWORD *)(v49 + 2284);
      v184 = *(_DWORD *)(a2 + 3160);
      *(_DWORD *)(a2 + 3740) = v183;
      v185 = v184 + *(_DWORD *)(v49 + 2272);
      v186 = *(_DWORD *)(a2 + 3744);
      *(_DWORD *)(a2 + 3160) = v185;
      v187 = v186 + *(_DWORD *)(v49 + 2288);
      v188 = *(_DWORD *)(a2 + 3164);
      *(_DWORD *)(a2 + 3744) = v187;
      v189 = v188 + *(_DWORD *)(v49 + 2276);
      v190 = *(_DWORD *)(a2 + 3748);
      *(_DWORD *)(a2 + 3164) = v189;
      v191 = v190 + *(_DWORD *)(v49 + 2292);
      v192 = *(_DWORD *)(a2 + 3168);
      *(_DWORD *)(a2 + 3748) = v191;
      v193 = v192 + *(_DWORD *)(v49 + 2280);
      v194 = *(_DWORD *)(a2 + 3752);
      *(_DWORD *)(a2 + 3168) = v193;
      v195 = v194 + *(_DWORD *)(v49 + 2296);
      v196 = *(_DWORD *)(a2 + 3580);
      *(_DWORD *)(a2 + 3752) = v195;
      v197 = v196 + *(_DWORD *)(v49 + 2300);
      v198 = *(_DWORD *)(a2 + 3584);
      *(_DWORD *)(a2 + 3580) = v197;
      v199 = v198 + *(_DWORD *)(v49 + 2304);
      v200 = *(_DWORD *)(a2 + 3588);
      *(_DWORD *)(a2 + 3584) = v199;
      v201 = v200 + *(_DWORD *)(v49 + 2308);
      v202 = *(_DWORD *)(a2 + 3592);
      *(_DWORD *)(a2 + 3588) = v201;
      v203 = v202 + *(_DWORD *)(v49 + 2312);
      v204 = *(_DWORD *)(a2 + 3596);
      *(_DWORD *)(a2 + 3592) = v203;
      v205 = v204 + *(_DWORD *)(v49 + 2316);
      v206 = *(_DWORD *)(a2 + 3600);
      *(_DWORD *)(a2 + 3596) = v205;
      v207 = v206 + *(_DWORD *)(v49 + 2320);
      v208 = *(_DWORD *)(a2 + 3632);
      *(_DWORD *)(a2 + 3600) = v207;
      v209 = v208 + *(_DWORD *)(v49 + 2352);
      v210 = *(_DWORD *)(a2 + 3604);
      *(_DWORD *)(a2 + 3632) = v209;
      v211 = v210 + *(_DWORD *)(v49 + 2324);
      v212 = *(_DWORD *)(a2 + 3636);
      *(_DWORD *)(a2 + 3604) = v211;
      v213 = v212 + *(_DWORD *)(v49 + 2356);
      v214 = *(_DWORD *)(a2 + 3608);
      *(_DWORD *)(a2 + 3636) = v213;
      v215 = v214 + *(_DWORD *)(v49 + 2328);
      v216 = *(_DWORD *)(a2 + 3640);
      *(_DWORD *)(a2 + 3608) = v215;
      v217 = v216 + *(_DWORD *)(v49 + 2360);
      v218 = *(_DWORD *)(a2 + 3612);
      *(_DWORD *)(a2 + 3640) = v217;
      v219 = v218 + *(_DWORD *)(v49 + 2332);
      v220 = *(_DWORD *)(a2 + 3644);
      *(_DWORD *)(a2 + 3612) = v219;
      v221 = v220 + *(_DWORD *)(v49 + 2364);
      v222 = *(_DWORD *)(a2 + 3616);
      *(_DWORD *)(a2 + 3644) = v221;
      v223 = v222 + *(_DWORD *)(v49 + 2336);
      v224 = *(_DWORD *)(a2 + 3648);
      *(_DWORD *)(a2 + 3616) = v223;
      v225 = v224 + *(_DWORD *)(v49 + 2368);
      v226 = *(_DWORD *)(a2 + 3620);
      *(_DWORD *)(a2 + 3648) = v225;
      v227 = v226 + *(_DWORD *)(v49 + 2340);
      v228 = *(_DWORD *)(a2 + 3652);
      *(_DWORD *)(a2 + 3620) = v227;
      v229 = v228 + *(_DWORD *)(v49 + 2372);
      v230 = *(_DWORD *)(a2 + 3624);
      *(_DWORD *)(a2 + 3652) = v229;
      v231 = v230 + *(_DWORD *)(v49 + 2344);
      v232 = *(_DWORD *)(a2 + 3656);
      *(_DWORD *)(a2 + 3624) = v231;
      v233 = v232 + *(_DWORD *)(v49 + 2376);
      v234 = *(_DWORD *)(a2 + 3628);
      *(_DWORD *)(a2 + 3656) = v233;
      v235 = v234 + *(_DWORD *)(v49 + 2348);
      v236 = *(_DWORD *)(a2 + 3660);
      *(_DWORD *)(a2 + 3628) = v235;
      v237 = v236 + *(_DWORD *)(v49 + 2380);
      v238 = *(_DWORD *)(a2 + 3972);
      *(_DWORD *)(a2 + 3660) = v237;
      v239 = v238 + *(_DWORD *)(v49 + 2384);
      v240 = *(_DWORD *)(a2 + 3976);
      *(_DWORD *)(a2 + 3972) = v239;
      v241 = v240 + *(_DWORD *)(v49 + 2388);
      v242 = *(_DWORD *)(a2 + 3980);
      *(_DWORD *)(a2 + 3976) = v241;
      v243 = v242 + *(_DWORD *)(v49 + 2392);
      v244 = *(_DWORD *)(a2 + 3984);
      *(_DWORD *)(a2 + 3980) = v243;
      v245 = v244 + *(_DWORD *)(v49 + 2396);
      v246 = *(_DWORD *)(a2 + 3988);
      *(_DWORD *)(a2 + 3984) = v245;
      v247 = v246 + *(_DWORD *)(v49 + 2400);
      v248 = *(_DWORD *)(a2 + 3992);
      *(_DWORD *)(a2 + 3988) = v247;
      v249 = v248 + *(_DWORD *)(v49 + 2404);
      v250 = *(_DWORD *)(a2 + 3996);
      *(_DWORD *)(a2 + 3992) = v249;
      v251 = v250 + *(_DWORD *)(v49 + 2408);
      v252 = *(_DWORD *)(a2 + 4000);
      *(_DWORD *)(a2 + 3996) = v251;
      v253 = v252 + *(_DWORD *)(v49 + 2412);
      v254 = *(_QWORD *)(a2 + 4528);
      *(_DWORD *)(a2 + 4000) = v253;
      *(_QWORD *)(a2 + 4528) = v254 + *(_QWORD *)(v49 + 2800);
      do
      {
        v255 = (_DWORD *)(v21 + v181);
        v256 = a2 + v181;
        v181 += 4;
        *(_DWORD *)(v256 + 1848) += *v255;
        *(_DWORD *)(v256 + 4228) += v255[327];
      }
      while ( v181 != 68 );
      for ( k = 0; k != 68; k += 4 )
      {
        v258 = (_DWORD *)(v22 + k);
        v259 = a2 + k;
        *(_DWORD *)(v259 + 1916) += *v258;
        *(_DWORD *)(v259 + 4296) += v258[327];
      }
      for ( m = 0; m != 68; m += 4 )
      {
        v261 = (_DWORD *)(v23 + m);
        v262 = a2 + m;
        *(_DWORD *)(v262 + 1984) += *v261;
        *(_DWORD *)(v262 + 4364) += v261[327];
      }
      v263 = *(_DWORD *)(a2 + 4448);
      v264 = *(_DWORD *)(a2 + 4432);
      *(_DWORD *)(a2 + 2052) += *(_DWORD *)(v49 + 1428);
      v265 = v264 + *(_DWORD *)(v49 + 2736);
      v266 = *(_DWORD *)(a2 + 2056);
      *(_DWORD *)(a2 + 4432) = v265;
      v267 = v266 + *(_DWORD *)(v49 + 1432);
      v268 = *(_DWORD *)(a2 + 4436);
      *(_DWORD *)(a2 + 2056) = v267;
      v269 = v268 + *(_DWORD *)(v49 + 2740);
      v270 = *(_DWORD *)(a2 + 2060);
      *(_DWORD *)(a2 + 4436) = v269;
      v271 = v270 + *(_DWORD *)(v49 + 1436);
      v272 = *(_DWORD *)(a2 + 4440);
      *(_DWORD *)(a2 + 2060) = v271;
      v273 = v272 + *(_DWORD *)(v49 + 2744);
      v274 = *(_DWORD *)(a2 + 2064);
      *(_DWORD *)(a2 + 4440) = v273;
      v275 = v274 + *(_DWORD *)(v49 + 1440);
      v276 = *(_DWORD *)(a2 + 4444);
      *(_DWORD *)(a2 + 2064) = v275;
      v277 = v276 + *(_DWORD *)(v49 + 2748);
      v278 = *(_DWORD *)(a2 + 2068);
      *(_DWORD *)(a2 + 4444) = v277;
      *(_DWORD *)(a2 + 2068) = v278 + *(_DWORD *)(v49 + 1444);
      v279 = *(_DWORD *)(v49 + 2752);
      v11 = (unsigned __int8)v574;
      v280 = v16 + 1 >= (unsigned __int8)v574;
      *(_DWORD *)(a2 + 4448) = v263 + v279;
      if ( v280 )
        break;
      v17 += 4072;
      v18 += 4072;
      result += 509;
      v19 += 4072;
      v20 += 4072;
      v21 += 4072;
      v280 = v16 >= *(unsigned __int8 *)(v15 + 2281);
      v22 += 4072;
      v23 += 4072;
      ++v16;
      if ( v280 )
        goto LABEL_53;
    }
    if ( !(_DWORD)v11 )
      goto LABEL_51;
LABEL_53:
    result = v570;
    if ( v570 )
    {
      result = (__int64 *)dp_peer_unref_delete((__int64)v570, 8u, a3, a4, a5, a6, a7, a8, a9, a10);
      v11 = (unsigned __int8)v574;
    }
    v570 = nullptr;
    if ( (unsigned int)v11 >= 2 )
    {
      result = v571;
      if ( v571 )
      {
        result = (__int64 *)dp_peer_unref_delete((__int64)v571, 8u, a3, a4, a5, a6, a7, a8, a9, a10);
        v11 = (unsigned __int8)v574;
      }
      v571 = nullptr;
      if ( (unsigned int)v11 >= 3 )
      {
        result = v572;
        if ( v572 )
        {
          result = (__int64 *)dp_peer_unref_delete((__int64)v572, 8u, a3, a4, a5, a6, a7, a8, a9, a10);
          v11 = (unsigned __int8)v574;
        }
        v572 = nullptr;
        if ( (unsigned int)v11 >= 4 )
        {
          result = v573;
          if ( v573 )
          {
            result = (__int64 *)dp_peer_unref_delete((__int64)v573, 8u, a3, a4, a5, a6, a7, a8, a9, a10);
            v11 = (unsigned __int8)v574;
          }
          v573 = nullptr;
          if ( (unsigned int)v11 > 4 )
          {
            __break(0x5512u);
            goto LABEL_66;
          }
        }
      }
    }
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
