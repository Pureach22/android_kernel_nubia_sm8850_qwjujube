_BYTE *__fastcall wma_derive_ext_he_cap(_BYTE *result, __int64 a2, char a3)
{
  unsigned __int64 v3; // x8
  __int64 v4; // x9
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x9
  unsigned int v7; // w10
  __int64 v8; // x10
  unsigned __int64 v9; // x9
  unsigned int v10; // w10
  unsigned int v11; // w12
  bool v12; // cf
  unsigned __int64 v13; // x10
  unsigned int v14; // w9
  __int64 v15; // x11
  unsigned __int64 v16; // x10
  unsigned __int64 v17; // x11
  unsigned int v18; // w10
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x11
  unsigned int v21; // w9
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x11
  unsigned int v24; // w10
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x11
  unsigned int v27; // w9
  unsigned __int64 v28; // x10
  unsigned __int64 v29; // x11
  unsigned int v30; // w10
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x10
  unsigned int v33; // w11
  unsigned __int64 v34; // x9
  unsigned int v35; // w10
  __int64 v36; // x11
  unsigned __int64 v37; // x9
  unsigned int v38; // w11
  unsigned __int64 v39; // x10
  unsigned int v40; // w9
  __int64 v41; // x11
  unsigned __int64 v42; // x10
  unsigned int v43; // w11
  unsigned __int64 v44; // x9
  unsigned int v45; // w10
  __int64 v46; // x11
  unsigned __int64 v47; // x9
  unsigned int v48; // w11
  unsigned __int64 v49; // x10
  unsigned int v50; // w9
  __int64 v51; // x11
  unsigned __int64 v52; // x10
  unsigned int v53; // w11
  unsigned __int64 v54; // x9
  unsigned int v55; // w10
  __int64 v56; // x11
  unsigned __int64 v57; // x9
  unsigned int v58; // w11
  unsigned __int64 v59; // x10
  unsigned int v60; // w9
  __int64 v61; // x11
  unsigned __int64 v62; // x10
  unsigned int v63; // w11
  unsigned __int64 v64; // x9
  unsigned int v65; // w10
  __int64 v66; // x11
  unsigned __int64 v67; // x9
  unsigned int v68; // w11
  unsigned __int64 v69; // x10
  unsigned int v70; // w9
  __int64 v71; // x11
  unsigned __int64 v72; // x10
  unsigned int v73; // w11
  unsigned __int64 v74; // x9
  unsigned int v75; // w10
  __int64 v76; // x11
  unsigned __int64 v77; // x9
  unsigned __int64 v78; // x10
  unsigned int v79; // w11
  unsigned __int64 v80; // x9
  unsigned int v81; // w10
  __int64 v82; // x11
  unsigned __int64 v83; // x9
  unsigned __int64 v84; // x9
  unsigned int v85; // w11
  __int64 v86; // x10
  unsigned __int64 v87; // x9
  unsigned __int64 v88; // x9
  __int64 v89; // x10
  unsigned __int64 v90; // x9
  unsigned int v91; // w10
  unsigned __int64 v92; // x9
  __int64 v93; // x10
  unsigned __int64 v94; // x9
  __int64 v95; // x10
  unsigned __int64 v96; // x9
  __int64 v97; // x10
  unsigned __int64 v98; // x9
  __int64 v99; // x10
  unsigned __int64 v100; // x9
  __int64 v101; // x10
  unsigned __int64 v102; // x9
  bool v103; // w11
  unsigned __int64 v104; // x10
  unsigned __int64 v105; // x10
  unsigned __int64 v106; // x10
  unsigned __int64 v107; // x10
  unsigned __int64 v108; // x10
  unsigned __int64 v109; // x10
  unsigned __int64 v110; // x10
  __int64 v111; // x9
  unsigned __int64 v112; // x10
  __int64 v113; // x9
  unsigned __int64 v114; // x10
  unsigned __int64 v115; // x11
  unsigned __int64 v116; // x9
  unsigned __int64 v117; // x9
  unsigned __int64 v118; // x10
  unsigned __int64 v119; // x9
  __int64 v120; // x11
  unsigned __int64 v121; // x11
  unsigned __int64 v122; // x11
  unsigned int v123; // w12
  __int64 v124; // x12
  unsigned __int64 v125; // x11
  unsigned int v126; // w12
  unsigned int v127; // w14
  unsigned __int64 v128; // x12
  unsigned int v129; // w11
  __int64 v130; // x13
  unsigned __int64 v131; // x12
  unsigned int v132; // w13
  unsigned __int64 v133; // x11
  unsigned int v134; // w12
  __int64 v135; // x13
  unsigned __int64 v136; // x11
  unsigned __int64 v137; // x13
  unsigned int v138; // w11
  unsigned __int64 v139; // x12
  unsigned __int64 v140; // x13
  unsigned int v141; // w12
  unsigned __int64 v142; // x11
  unsigned __int64 v143; // x13
  unsigned int v144; // w11
  unsigned __int64 v145; // x12
  unsigned __int64 v146; // x11
  unsigned int v147; // w13
  unsigned __int64 v148; // x12
  unsigned int v149; // w11
  __int64 v150; // x13
  unsigned __int64 v151; // x12
  unsigned int v152; // w13
  unsigned __int64 v153; // x11
  unsigned int v154; // w12
  __int64 v155; // x13
  unsigned __int64 v156; // x11
  unsigned int v157; // w13
  unsigned __int64 v158; // x12
  unsigned int v159; // w11
  __int64 v160; // x13
  unsigned __int64 v161; // x12
  unsigned int v162; // w13
  unsigned __int64 v163; // x11
  unsigned int v164; // w12
  __int64 v165; // x13
  unsigned __int64 v166; // x11
  unsigned __int64 v167; // x13
  unsigned int v168; // w11
  unsigned __int64 v169; // x12
  unsigned __int64 v170; // x13
  unsigned int v171; // w12
  unsigned __int64 v172; // x11
  unsigned __int64 v173; // x11
  unsigned __int64 v174; // x11
  __int64 v175; // x12
  unsigned __int64 v176; // x11
  __int64 v177; // x12
  unsigned __int64 v178; // x11
  __int64 v179; // x12
  unsigned __int64 v180; // x11
  __int64 v181; // x12
  unsigned __int64 v182; // x11
  __int64 v183; // x12
  unsigned __int64 v184; // x11
  __int64 v185; // x12
  unsigned __int64 v186; // x11
  __int64 v187; // x12
  unsigned __int64 v188; // x11
  __int64 v189; // x12
  unsigned __int64 v190; // x11
  __int64 v191; // x12
  unsigned __int64 v192; // x11
  __int64 v193; // x12
  unsigned __int64 v194; // x11
  unsigned __int64 v195; // x11
  unsigned __int64 v196; // x12
  __int64 v197; // x14
  __int64 v198; // x12
  unsigned __int64 v199; // x11
  unsigned __int64 v200; // x11
  unsigned __int64 v201; // x12
  __int64 v202; // x14
  __int64 v203; // x12
  unsigned __int64 v204; // x11
  unsigned __int64 v205; // x11
  unsigned __int64 v206; // x12
  __int64 v207; // x14
  __int64 v208; // x12
  unsigned __int64 v209; // x11
  unsigned __int64 v210; // x11
  unsigned __int64 v211; // x12
  __int64 v212; // x14
  __int64 v213; // x12
  unsigned __int64 v214; // x11
  unsigned __int64 v215; // x11
  unsigned __int64 v216; // x12
  __int64 v217; // x14
  __int64 v218; // x12
  unsigned __int64 v219; // x11
  unsigned __int64 v220; // x11
  unsigned __int64 v221; // x12
  __int64 v222; // x14
  __int64 v223; // x12
  __int64 v224; // x13
  __int64 v225; // x10
  unsigned __int64 v226; // x11
  unsigned __int64 v227; // x11
  unsigned __int64 v228; // x12
  __int64 v229; // x14
  __int64 v230; // x12
  unsigned __int64 v231; // x11
  unsigned __int64 v232; // x12
  __int64 v233; // x13
  __int64 v234; // x12
  unsigned __int64 v235; // x10
  __int64 v236; // x11
  unsigned __int64 v237; // x11
  unsigned int v238; // w10
  unsigned __int64 v239; // x2
  unsigned int v240; // w11
  int v241; // w16
  __int64 v242; // x5
  __int64 v243; // x2
  unsigned int v244; // w25
  unsigned int v245; // w26
  unsigned int v246; // w5
  __int64 v247; // x15
  unsigned __int64 v248; // x8
  int v249; // w17
  unsigned int v250; // w15
  int v251; // w7
  __int16 v252; // w23
  int v253; // w30
  __int16 v254; // w1
  char v255; // w3
  int v256; // w30
  __int16 v257; // w24
  __int16 v258; // w16
  int v259; // w2
  int v260; // w6
  __int16 v261; // w21
  int v262; // w19
  int v263; // w22
  int v264; // w6
  int v265; // w9
  int v266; // w30
  char v267; // w20
  __int16 v268; // w12
  int v269; // w5
  int v270; // w22
  int v271; // w2
  int v272; // w9
  int v273; // w25
  int v274; // w22
  int v275; // w26
  unsigned __int16 v276; // w4
  unsigned int v277; // w9
  unsigned int v278; // w12
  int v279; // w25
  int v280; // w22
  __int16 v281; // w14
  int v282; // w27
  int v283; // w28
  int v284; // w11
  unsigned int v285; // w13
  int v286; // w10
  unsigned __int16 v287; // w16
  unsigned int v288; // w10
  __int16 v289; // w23
  __int16 v290; // w24
  __int16 v291; // w14
  int v292; // w17
  int v293; // w7
  int v294; // w3
  int v295; // w5
  __int16 v296; // w14
  int v297; // w28
  int v298; // w2
  int v299; // w14
  int v300; // w12
  unsigned int v301; // w13
  int v302; // w9
  __int16 v303; // w20
  int v304; // w3
  int v305; // w6
  int v306; // w11
  __int16 v307; // w16
  __int16 v308; // w4
  __int64 v309; // x9
  unsigned int v310; // w8
  unsigned int v311; // w15
  int v312; // w13
  int v313; // w17
  int v314; // w12
  __int16 v315; // w7
  int v316; // w3
  unsigned int v317; // w9
  int v318; // w4
  __int16 v319; // w6
  int v320; // w24
  int v321; // w21
  int v322; // w11
  int v323; // w21
  __int16 v324; // w10
  int v325; // w13
  int v326; // w3
  int v327; // w12
  int v328; // w4
  int v329; // w19
  int v330; // w20
  __int16 v331; // w14
  unsigned __int16 v332; // w15
  int v333; // w3
  int v334; // w22
  int v335; // w23
  int v336; // w3
  int v337; // w19
  int v338; // w2
  int v339; // w20
  int v340; // w21
  unsigned __int16 v341; // w5
  int v342; // w22
  unsigned int v343; // w24
  unsigned int v344; // w19
  unsigned int v345; // w8
  unsigned int v346; // w9
  int v347; // w2
  int v348; // w3
  int v349; // w12
  __int16 v350; // w10
  int v351; // w13
  int v352; // w17
  int v353; // w2
  int v354; // w3
  int v355; // w12
  int v356; // w3
  int v357; // w14
  int v358; // w12
  int v359; // w4
  int v360; // w19
  int v361; // w20
  unsigned __int16 v362; // w15
  int v363; // w3
  int v364; // w22
  int v365; // w23
  int v366; // w3
  int v367; // w19
  int v368; // w2
  unsigned __int16 v369; // w5
  int v370; // w20
  int v371; // w21
  int v372; // w22
  unsigned int v373; // w19
  unsigned int v374; // w24
  unsigned int v375; // w8
  unsigned int v376; // w9
  int v377; // w2
  int v378; // w3
  int v379; // w12
  int v380; // w10
  int v381; // w13
  int v382; // w17
  int v383; // w2
  int v384; // w3
  int v385; // w12
  int v386; // w3
  int v387; // w14
  int v388; // w12
  int v389; // w4
  int v390; // w19
  int v391; // w20
  unsigned __int16 v392; // w15
  int v393; // w3
  int v394; // w22
  int v395; // w23
  int v396; // w3
  int v397; // w19
  int v398; // w2
  unsigned __int16 v399; // w5
  int v400; // w20
  int v401; // w21
  int v402; // w22
  unsigned int v403; // w19
  unsigned int v404; // w24
  unsigned int v405; // w8
  unsigned int v406; // w9
  int v407; // w2
  int v408; // w3
  int v409; // w12
  int v410; // w13
  int v411; // w17
  int v412; // w2
  int v413; // w3
  int v414; // w12
  int v415; // w3
  int v416; // w14
  int v417; // w12
  int v418; // w4
  int v419; // w19
  int v420; // w20
  unsigned __int16 v421; // w15
  int v422; // w3
  int v423; // w2
  int v424; // w19
  int v425; // w21
  int v426; // w7
  int v427; // w2
  int v428; // w4
  int v429; // w19
  int v430; // w20
  int v431; // w21
  unsigned int v432; // w23
  unsigned int v433; // w24
  _BYTE *v434; // x19
  unsigned __int64 v435; // [xsp+8h] [xbp-48h]
  unsigned __int64 v436; // [xsp+10h] [xbp-40h]
  __int16 v437; // [xsp+1Ch] [xbp-34h]
  __int16 v438; // [xsp+20h] [xbp-30h]
  int v439; // [xsp+24h] [xbp-2Ch]
  int v440; // [xsp+24h] [xbp-2Ch]
  int v441; // [xsp+28h] [xbp-28h]
  unsigned __int16 v442; // [xsp+2Ch] [xbp-24h]
  __int16 v443; // [xsp+2Ch] [xbp-24h]
  int v445; // [xsp+38h] [xbp-18h]
  __int16 v446; // [xsp+3Ch] [xbp-14h]
  __int16 v447; // [xsp+3Ch] [xbp-14h]
  unsigned __int16 v448; // [xsp+40h] [xbp-10h]
  int v449; // [xsp+44h] [xbp-Ch]
  unsigned __int16 v450; // [xsp+44h] [xbp-Ch]
  __int16 v451; // [xsp+48h] [xbp-8h]

  if ( *result )
  {
    v3 = *(_QWORD *)(result + 1);
    LODWORD(v4) = *(_DWORD *)(a2 + 1) & 1;
    v436 = v3;
    if ( (v3 & 1) >= (unsigned int)v4 )
      v4 = (unsigned int)v4;
    else
      v4 = 0;
    v5 = v3 & 0xFFFFFFFFFFFFFFFELL | v4;
    *(_QWORD *)(result + 1) = v5;
    v6 = v5 & 0xFFFFFFFFFFFFFFFDLL;
    v7 = (*(_DWORD *)(a2 + 1) >> 1) & 1;
    if ( (((unsigned int)v3 >> 1) & 1) >= v7 )
      v8 = 2 * v7;
    else
      v8 = 0;
    v9 = v6 | v8;
    *(_QWORD *)(result + 1) = v9;
    v10 = (*(_DWORD *)(a2 + 1) >> 2) & 1;
    v11 = 4 * v10;
    v12 = (((unsigned int)v3 >> 2) & 1) >= v10;
    v13 = v9 & 0xFFFFFFFFFFFFFFFBLL;
    v14 = ((unsigned int)v9 >> 3) & 3;
    if ( v12 )
      v15 = v11;
    else
      v15 = 0;
    v16 = v13 | v15;
    *(_QWORD *)(result + 1) = v16;
    if ( v14 >= ((*(_DWORD *)(a2 + 1) >> 3) & 3u) )
      v14 = (*(_DWORD *)(a2 + 1) >> 3) & 3;
    v17 = v16 & 0xFFFFFFFFFFFFFFE7LL;
    v18 = (unsigned __int8)v16 >> 5;
    v19 = v17 | (8 * v14);
    *(_QWORD *)(result + 1) = v19;
    if ( v18 >= (unsigned __int8)*(_DWORD *)(a2 + 1) >> 5 )
      v18 = (unsigned __int8)*(_DWORD *)(a2 + 1) >> 5;
    v20 = v19 & 0xFFFFFFFFFFFFFF1FLL;
    v21 = ((unsigned int)v19 >> 8) & 3;
    v22 = v20 | (32 * v18);
    *(_QWORD *)(result + 1) = v22;
    if ( v21 >= ((*(_DWORD *)(a2 + 1) >> 8) & 3u) )
      v21 = (*(_DWORD *)(a2 + 1) >> 8) & 3;
    v23 = v22 & 0xFFFFFFFFFFFFFCFFLL;
    v24 = ((unsigned int)v22 >> 10) & 3;
    v25 = v23 | (v21 << 8);
    *(_QWORD *)(result + 1) = v25;
    if ( v24 >= ((*(_DWORD *)(a2 + 1) >> 10) & 3u) )
      v24 = (*(_DWORD *)(a2 + 1) >> 10) & 3;
    v26 = v25 & 0xFFFFFFFFFFFFF3FFLL;
    v27 = ((unsigned int)v25 >> 12) & 7;
    v28 = v26 | (v24 << 10);
    *(_QWORD *)(result + 1) = v28;
    if ( v27 >= ((*(_DWORD *)(a2 + 1) >> 12) & 7u) )
      v27 = (*(_DWORD *)(a2 + 1) >> 12) & 7;
    v29 = v28 & 0xFFFFFFFFFFFF8FFFLL;
    v30 = ((unsigned int)v28 >> 15) & 3;
    v31 = v29 | (v27 << 12);
    *(_QWORD *)(result + 1) = v31;
    if ( v30 >= ((*(_DWORD *)(a2 + 1) >> 15) & 3u) )
      v30 = (*(_DWORD *)(a2 + 1) >> 15) & 3;
    v32 = v31 & 0xFFFFFFFFFFFE7FFFLL | (v30 << 15);
    *(_QWORD *)(result + 1) = v32;
    v33 = (*(_DWORD *)(a2 + 1) >> 17) & 1;
    v12 = (((unsigned int)v31 >> 17) & 1) >= v33;
    v34 = v32 & 0xFFFFFFFFFFFDFFFFLL;
    v35 = ((unsigned int)v32 >> 18) & 1;
    if ( v12 )
      v36 = v33 << 17;
    else
      v36 = 0;
    v37 = v34 | v36;
    *(_QWORD *)(result + 1) = v37;
    v38 = (*(_DWORD *)(a2 + 1) >> 18) & 1;
    v12 = v35 >= v38;
    v39 = v37 & 0xFFFFFFFFFFFBFFFFLL;
    v40 = ((unsigned int)v37 >> 19) & 1;
    if ( v12 )
      v41 = v38 << 18;
    else
      v41 = 0;
    v42 = v39 | v41;
    *(_QWORD *)(result + 1) = v42;
    v43 = (*(_DWORD *)(a2 + 1) >> 19) & 1;
    v12 = v40 >= v43;
    v44 = v42 & 0xFFFFFFFFFFF7FFFFLL;
    v45 = ((unsigned int)v42 >> 20) & 1;
    if ( v12 )
      v46 = v43 << 19;
    else
      v46 = 0;
    v47 = v44 | v46;
    *(_QWORD *)(result + 1) = v47;
    v48 = (*(_DWORD *)(a2 + 1) >> 20) & 1;
    v12 = v45 >= v48;
    v49 = v47 & 0xFFFFFFFFFFEFFFFFLL;
    v50 = ((unsigned int)v47 >> 21) & 1;
    if ( v12 )
      v51 = v48 << 20;
    else
      v51 = 0;
    v52 = v49 | v51;
    *(_QWORD *)(result + 1) = v52;
    v53 = (*(_DWORD *)(a2 + 1) >> 21) & 1;
    v12 = v50 >= v53;
    v54 = v52 & 0xFFFFFFFFFFDFFFFFLL;
    v55 = ((unsigned int)v52 >> 22) & 1;
    if ( v12 )
      v56 = v53 << 21;
    else
      v56 = 0;
    v57 = v54 | v56;
    *(_QWORD *)(result + 1) = v57;
    v58 = (*(_DWORD *)(a2 + 1) >> 22) & 1;
    v12 = v55 >= v58;
    v59 = v57 & 0xFFFFFFFFFFBFFFFFLL;
    v60 = ((unsigned int)v57 >> 23) & 1;
    if ( v12 )
      v61 = v58 << 22;
    else
      v61 = 0;
    v62 = v59 | v61;
    *(_QWORD *)(result + 1) = v62;
    v63 = (*(_DWORD *)(a2 + 1) >> 23) & 1;
    v12 = v60 >= v63;
    v64 = v62 & 0xFFFFFFFFFF7FFFFFLL;
    v65 = ((unsigned int)v62 >> 25) & 1;
    if ( v12 )
      v66 = v63 << 23;
    else
      v66 = 0;
    v67 = v64 | v66;
    *(_QWORD *)(result + 1) = v67;
    v68 = (*(_DWORD *)(a2 + 1) >> 25) & 1;
    v12 = v65 >= v68;
    v69 = v67 & 0xFFFFFFFFFDFFFFFFLL;
    v70 = ((unsigned int)v67 >> 26) & 1;
    if ( v12 )
      v71 = v68 << 25;
    else
      v71 = 0;
    v72 = v69 | v71;
    *(_QWORD *)(result + 1) = v72;
    v73 = (*(_DWORD *)(a2 + 1) >> 26) & 1;
    v12 = v70 >= v73;
    v74 = v72 & 0xFFFFFFFFFBFFFFFFLL;
    v75 = ((unsigned int)v72 >> 27) & 3;
    if ( v12 )
      v76 = v73 << 26;
    else
      v76 = 0;
    v77 = v74 | v76;
    *(_QWORD *)(result + 1) = v77;
    if ( v75 >= ((*(_DWORD *)(a2 + 1) >> 27) & 3u) )
      v75 = (*(_DWORD *)(a2 + 1) >> 27) & 3;
    v78 = v77 & 0xFFFFFFFFE7FFFFFFLL | (v75 << 27);
    *(_QWORD *)(result + 1) = v78;
    v79 = (*(_DWORD *)(a2 + 1) >> 29) & 1;
    v12 = (((unsigned int)v77 >> 29) & 1) >= v79;
    v80 = v78 & 0xFFFFFFFFDFFFFFFFLL;
    v81 = ((unsigned int)v78 >> 30) & 1;
    if ( v12 )
      v82 = v79 << 29;
    else
      v82 = 0;
    v83 = v80 | v82;
    *(_QWORD *)(result + 1) = v83;
    v84 = v83 & 0xFFFFFFFFBFFFFFFFLL;
    v85 = (*(_DWORD *)(a2 + 1) >> 30) & 1;
    if ( v81 >= v85 )
      v86 = v85 << 30;
    else
      v86 = 0;
    v87 = v84 | v86;
    *(_QWORD *)(result + 1) = v87;
    v88 = v87 & 0xFFFFFFFF7FFFFFFFLL;
    if ( ((v3 >> 31) & 1) >= (unsigned int)*(_QWORD *)(a2 + 1) >> 31 )
      v89 = *(_QWORD *)(a2 + 1) & 0x80000000LL;
    else
      v89 = 0;
    v90 = v88 | v89;
    *(_QWORD *)(result + 1) = v90;
    v91 = *(_DWORD *)(a2 + 5) & 1;
    if ( (BYTE4(v3) & 1u) < v91 )
      LOBYTE(v91) = 0;
    v92 = v90 & 0xFFFFFFFEFFFFFFFFLL | ((unsigned __int64)(v91 & 1) << 32);
    *(_QWORD *)(result + 1) = v92;
    v93 = (*(_QWORD *)(a2 + 1) >> 33) & 1LL;
    if ( ((v3 >> 33) & 1) < (unsigned int)v93 )
      LOBYTE(v93) = 0;
    v94 = v92 & 0xFFFFFFFDFFFFFFFFLL | ((unsigned __int64)(v93 & 1) << 33);
    *(_QWORD *)(result + 1) = v94;
    v95 = (*(_QWORD *)(a2 + 1) >> 34) & 1LL;
    if ( ((v3 >> 34) & 1) < (unsigned int)v95 )
      LOBYTE(v95) = 0;
    v96 = v94 & 0xFFFFFFFBFFFFFFFFLL | ((unsigned __int64)(v95 & 1) << 34);
    *(_QWORD *)(result + 1) = v96;
    v97 = (*(_QWORD *)(a2 + 1) >> 35) & 1LL;
    if ( ((v3 >> 35) & 1) < (unsigned int)v97 )
      LOBYTE(v97) = 0;
    v98 = v96 & 0xFFFFFFF7FFFFFFFFLL | ((unsigned __int64)(v97 & 1) << 35);
    *(_QWORD *)(result + 1) = v98;
    v99 = (*(_QWORD *)(a2 + 1) >> 36) & 1LL;
    if ( ((v3 >> 36) & 1) < (unsigned int)v99 )
      LOBYTE(v99) = 0;
    v100 = v98 & 0xFFFFFFEFFFFFFFFFLL | ((unsigned __int64)(v99 & 1) << 36);
    *(_QWORD *)(result + 1) = v100;
    v101 = (*(_QWORD *)(a2 + 1) >> 37) & 1LL;
    if ( ((v3 >> 37) & 1) < (unsigned int)v101 )
      LOBYTE(v101) = 0;
    v102 = v100 & 0xFFFFFFDFFFFFFFFFLL | ((unsigned __int64)(v101 & 1) << 37);
    *(_QWORD *)(result + 1) = v102;
    v103 = ((v3 >> 38) & 1) >= ((unsigned int)(*(_QWORD *)(a2 + 1) >> 38) & 1)
        && (*(_QWORD *)(a2 + 1) & 0x4000000000LL) != 0;
    *(_QWORD *)(result + 1) = v102 & 0xFFFFFFBFFFFFFFFFLL | ((unsigned __int64)v103 << 38);
    v104 = v102 & 0xFFFBFFBFFFFFFFFFLL
         | ((unsigned __int64)v103 << 38) & 0xFFFBFFFFFFFFFFFFLL
         | ((((v102 | *(_QWORD *)(a2 + 1)) >> 50) & 1) << 50);
    *(_QWORD *)(result + 1) = v104;
    v105 = v104 & 0xFFF7FFFFFFFFFFFFLL | ((((v102 | *(_QWORD *)(a2 + 1)) >> 51) & 1) << 51);
    *(_QWORD *)(result + 1) = v105;
    v106 = v105 & 0xFFEFFFFFFFFFFFFFLL | ((((v102 | *(_QWORD *)(a2 + 1)) >> 52) & 1) << 52);
    *(_QWORD *)(result + 1) = v106;
    v107 = v106 & 0xFFDFFFFFFFFFFFFFLL | ((((v102 | *(_QWORD *)(a2 + 1)) >> 53) & 1) << 53);
    *(_QWORD *)(result + 1) = v107;
    v108 = v107 & 0xFFBFFFFFFFFFFFFFLL | ((((v102 | *(_QWORD *)(a2 + 1)) >> 54) & 1) << 54);
    *(_QWORD *)(result + 1) = v108;
    v109 = v108 & 0xFF7FFFFFFFFFFFFFLL | ((((v102 | *(_QWORD *)(a2 + 1)) >> 55) & 1) << 55);
    *(_QWORD *)(result + 1) = v109;
    v110 = v109 & 0xFEFFFFFFFFFFFFFFLL | ((((v102 | *(_QWORD *)(a2 + 1)) >> 56) & 1) << 56);
    *(_QWORD *)(result + 1) = v110;
    v111 = (*(_QWORD *)(a2 + 1) >> 61) & 1LL;
    if ( ((v3 & 0x2000000000000000LL) != 0) < (unsigned int)v111 )
      LOBYTE(v111) = 0;
    v112 = v110 & 0xDFFFFFFFFFFFFFFFLL | ((unsigned __int64)(v111 & 1) << 61);
    *(_QWORD *)(result + 1) = v112;
    v113 = (*(_QWORD *)(a2 + 1) >> 62) & 1LL;
    if ( ((v3 & 0x4000000000000000LL) != 0) < (unsigned int)v113 )
      LOBYTE(v113) = 0;
    v114 = v112 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)(v113 & 1) << 62);
    *(_QWORD *)(result + 1) = v114;
    v115 = *(_QWORD *)(a2 + 1);
    if ( v3 >> 63 >= v115 >> 63 )
      v116 = v115 & 0x8000000000000000LL;
    else
      v116 = 0;
    v117 = v116 & 0x8000000000000000LL | v114 & 0x7FFFFFFFFFFFFFFFLL;
    v118 = *(_QWORD *)(result + 9);
    *(_QWORD *)(result + 1) = v117;
    v119 = v117 & 0xFFFDFFFFFFFFFFFFLL;
    LODWORD(v120) = *(_DWORD *)(a2 + 9) & 3;
    if ( (v118 & 3) >= (unsigned int)v120 )
      v120 = (unsigned int)v120;
    else
      v120 = v118 & 3;
    v121 = v118 & 0xFFFFFFFFFFFFFFFCLL | v120;
    *(_QWORD *)(result + 9) = v121;
    v122 = v121 & 0xFFFFFFFFFFFFFFFBLL;
    v123 = (*(_DWORD *)(a2 + 9) >> 2) & 1;
    if ( (((unsigned int)v118 >> 2) & 1) >= v123 )
      v124 = 4 * v123;
    else
      v124 = 0;
    v125 = v122 | v124;
    *(_QWORD *)(result + 9) = v125;
    v126 = (*(_DWORD *)(a2 + 9) >> 3) & 1;
    v127 = 8 * v126;
    v12 = (((unsigned int)v118 >> 3) & 1) >= v126;
    v128 = v125 & 0xFFFFFFFFFFFFFFF7LL;
    v129 = ((unsigned int)v125 >> 4) & 1;
    if ( v12 )
      v130 = v127;
    else
      v130 = 0;
    v131 = v128 | v130;
    *(_QWORD *)(result + 9) = v131;
    v132 = (*(_DWORD *)(a2 + 9) >> 4) & 1;
    v12 = v129 >= v132;
    v133 = v131 & 0xFFFFFFFFFFFFFFEFLL;
    v134 = ((unsigned int)v131 >> 5) & 3;
    if ( v12 )
      v135 = 16 * v132;
    else
      v135 = 0;
    v136 = v133 | v135;
    *(_QWORD *)(result + 9) = v136;
    if ( v134 >= ((*(_DWORD *)(a2 + 9) >> 5) & 3u) )
      v134 = (*(_DWORD *)(a2 + 9) >> 5) & 3;
    v137 = v136 & 0xFFFFFFFFFFFFFF9FLL;
    v138 = ((unsigned int)v136 >> 7) & 3;
    v139 = v137 | (32 * v134);
    *(_QWORD *)(result + 9) = v139;
    if ( v138 >= ((*(_DWORD *)(a2 + 9) >> 7) & 3u) )
      v138 = (*(_DWORD *)(a2 + 9) >> 7) & 3;
    v140 = v139 & 0xFFFFFFFFFFFFFE7FLL;
    v141 = ((unsigned int)v139 >> 9) & 7;
    v142 = v140 | (v138 << 7);
    *(_QWORD *)(result + 9) = v142;
    if ( v141 >= ((*(_DWORD *)(a2 + 9) >> 9) & 7u) )
      v141 = (*(_DWORD *)(a2 + 9) >> 9) & 7;
    v143 = v142 & 0xFFFFFFFFFFFFF1FFLL;
    v144 = ((unsigned int)v142 >> 12) & 7;
    v145 = v143 | (v141 << 9);
    *(_QWORD *)(result + 9) = v145;
    if ( v144 >= ((*(_DWORD *)(a2 + 9) >> 12) & 7u) )
      v144 = (*(_DWORD *)(a2 + 9) >> 12) & 7;
    v146 = v145 & 0xFFFFFFFFFFFF8FFFLL | (v144 << 12);
    *(_QWORD *)(result + 9) = v146;
    v147 = (*(_DWORD *)(a2 + 9) >> 15) & 1;
    v12 = (((unsigned int)v145 >> 15) & 1) >= v147;
    v148 = v146 & 0xFFFFFFFFFFFF7FFFLL;
    v149 = WORD1(v146) & 1;
    if ( v12 )
      v150 = v147 << 15;
    else
      v150 = 0;
    v151 = v148 | v150;
    *(_QWORD *)(result + 9) = v151;
    v152 = HIWORD(*(_DWORD *)(a2 + 9)) & 1;
    v12 = v149 >= v152;
    v153 = v151 & 0xFFFFFFFFFFFEFFFFLL;
    v154 = ((unsigned int)v151 >> 17) & 1;
    if ( v12 )
      v155 = v152 << 16;
    else
      v155 = 0;
    v156 = v153 | v155;
    *(_QWORD *)(result + 9) = v156;
    v157 = (*(_DWORD *)(a2 + 9) >> 17) & 1;
    v12 = v154 >= v157;
    v158 = v156 & 0xFFFFFFFFFFFDFFFFLL;
    v159 = ((unsigned int)v156 >> 18) & 1;
    if ( v12 )
      v160 = v157 << 17;
    else
      v160 = 0;
    v161 = v158 | v160;
    *(_QWORD *)(result + 9) = v161;
    v162 = (*(_DWORD *)(a2 + 9) >> 18) & 1;
    v12 = v159 >= v162;
    v163 = v161 & 0xFFFFFFFFFFFBFFFFLL;
    v164 = ((unsigned int)v161 >> 19) & 7;
    if ( v12 )
      v165 = v162 << 18;
    else
      v165 = 0;
    v166 = v163 | v165;
    *(_QWORD *)(result + 9) = v166;
    if ( v164 >= ((*(_DWORD *)(a2 + 9) >> 19) & 7u) )
      v164 = (*(_DWORD *)(a2 + 9) >> 19) & 7;
    v167 = v166 & 0xFFFFFFFFFFC7FFFFLL;
    v168 = BYTE3(v166) & 7;
    v169 = v167 | (v164 << 19);
    *(_QWORD *)(result + 9) = v169;
    if ( v168 >= (*(_BYTE *)(a2 + 12) & 7u) )
      v168 = *(_BYTE *)(a2 + 12) & 7;
    v170 = v169 & 0xFFFFFFFFF8FFFFFFLL;
    v171 = ((unsigned int)v169 >> 27) & 7;
    v172 = v170 | (v168 << 24);
    *(_QWORD *)(result + 9) = v172;
    v173 = v172 & 0xFFFFFFFFC7FFFFFFLL;
    if ( v171 >= ((*(_DWORD *)(a2 + 9) >> 27) & 7u) )
      v171 = (*(_DWORD *)(a2 + 9) >> 27) & 7;
    v174 = v173 | (v171 << 27);
    *(_QWORD *)(result + 9) = v174;
    v175 = (*(_QWORD *)(a2 + 9) >> 30) & 7LL;
    if ( ((v118 >> 30) & 7) < (unsigned int)v175 )
      LOBYTE(v175) = (v118 >> 30) & 7;
    v176 = v174 & 0xFFFFFFFE3FFFFFFFLL | ((unsigned __int64)(v175 & 7) << 30);
    *(_QWORD *)(result + 9) = v176;
    v177 = (*(_QWORD *)(a2 + 9) >> 33) & 1LL;
    if ( ((v118 >> 33) & 1) < (unsigned int)v177 )
      LOBYTE(v177) = 0;
    v178 = v176 & 0xFFFFFFFDFFFFFFFFLL | ((unsigned __int64)(v177 & 1) << 33);
    *(_QWORD *)(result + 9) = v178;
    v179 = (*(_QWORD *)(a2 + 9) >> 34) & 1LL;
    if ( ((v118 >> 34) & 1) < (unsigned int)v179 )
      LOBYTE(v179) = 0;
    v180 = v178 & 0xFFFFFFFBFFFFFFFFLL | ((unsigned __int64)(v179 & 1) << 34);
    *(_QWORD *)(result + 9) = v180;
    v181 = (*(_QWORD *)(a2 + 9) >> 35) & 1LL;
    if ( ((v118 >> 35) & 1) < (unsigned int)v181 )
      LOBYTE(v181) = 0;
    v182 = v180 & 0xFFFFFFF7FFFFFFFFLL | ((unsigned __int64)(v181 & 1) << 35);
    *(_QWORD *)(result + 9) = v182;
    v183 = (*(_QWORD *)(a2 + 9) >> 36) & 1LL;
    if ( ((v118 >> 36) & 1) < (unsigned int)v183 )
      LOBYTE(v183) = 0;
    v184 = v182 & 0xFFFFFFEFFFFFFFFFLL | ((unsigned __int64)(v183 & 1) << 36);
    *(_QWORD *)(result + 9) = v184;
    v185 = (*(_QWORD *)(a2 + 9) >> 37) & 7LL;
    if ( ((v118 >> 37) & 7) < (unsigned int)v185 )
      LOBYTE(v185) = (v118 >> 37) & 7;
    v186 = v184 & 0xFFFFFF1FFFFFFFFFLL | ((unsigned __int64)(v185 & 7) << 37);
    *(_QWORD *)(result + 9) = v186;
    v187 = (*(_QWORD *)(a2 + 9) >> 40) & 1LL;
    if ( ((v118 >> 40) & 1) < (unsigned int)v187 )
      LOBYTE(v187) = 0;
    v188 = v186 & 0xFFFFFEFFFFFFFFFFLL | ((unsigned __int64)(v187 & 1) << 40);
    *(_QWORD *)(result + 9) = v188;
    v189 = (*(_QWORD *)(a2 + 9) >> 41) & 1LL;
    if ( ((v118 >> 41) & 1) < (unsigned int)v189 )
      LOBYTE(v189) = 0;
    v190 = v188 & 0xFFFFFDFFFFFFFFFFLL | ((unsigned __int64)(v189 & 1) << 41);
    *(_QWORD *)(result + 9) = v190;
    v191 = (*(_QWORD *)(a2 + 9) >> 42) & 1LL;
    if ( ((v118 >> 42) & 1) < (unsigned int)v191 )
      LOBYTE(v191) = 0;
    v192 = v190 & 0xFFFFFBFFFFFFFFFFLL | ((unsigned __int64)(v191 & 1) << 42);
    *(_QWORD *)(result + 9) = v192;
    v193 = (*(_QWORD *)(a2 + 9) >> 43) & 1LL;
    if ( ((v118 >> 43) & 1) < (unsigned int)v193 )
      LOBYTE(v193) = 0;
    v194 = v192 & 0xFFFFF7FFFFFFFFFFLL | ((unsigned __int64)(v193 & 1) << 43);
    *(_QWORD *)(result + 9) = v194;
    v195 = v194 & 0xFFFFEFFFFFFFFFFFLL;
    v196 = *(_QWORD *)(a2 + 9);
    v197 = (v196 >> 44) & 1;
    v198 = v196 & 0x100000000000LL;
    if ( ((v118 >> 44) & 1) < (unsigned int)v197 )
      v198 = 0;
    v199 = v195 | v198;
    *(_QWORD *)(result + 9) = v199;
    v200 = v199 & 0xFFFFDFFFFFFFFFFFLL;
    v201 = *(_QWORD *)(a2 + 9);
    v202 = (v201 >> 45) & 1;
    v203 = v201 & 0x200000000000LL;
    if ( ((v118 >> 45) & 1) < (unsigned int)v202 )
      v203 = 0;
    v204 = v200 | v203;
    *(_QWORD *)(result + 9) = v204;
    v205 = v204 & 0xFFF7FFFFFFFFFFFFLL;
    v206 = *(_QWORD *)(a2 + 9);
    v207 = (v206 >> 51) & 1;
    v208 = v206 & 0x8000000000000LL;
    if ( ((v118 >> 51) & 1) < (unsigned int)v207 )
      v208 = 0;
    v209 = v205 | v208;
    *(_QWORD *)(result + 9) = v209;
    v210 = v209 & 0xFFEFFFFFFFFFFFFFLL;
    v211 = *(_QWORD *)(a2 + 9);
    v212 = (v211 >> 52) & 1;
    v213 = v211 & 0x10000000000000LL;
    if ( ((v118 >> 52) & 1) < (unsigned int)v212 )
      v213 = 0;
    v214 = v210 | v213;
    *(_QWORD *)(result + 9) = v214;
    v215 = v214 & 0xFFDFFFFFFFFFFFFFLL;
    v216 = *(_QWORD *)(a2 + 9);
    v217 = (v216 >> 53) & 1;
    v218 = v216 & 0x20000000000000LL;
    if ( ((v118 >> 53) & 1) < (unsigned int)v217 )
      v218 = 0;
    v219 = v215 | v218;
    *(_QWORD *)(result + 9) = v219;
    v220 = v219 & 0xFFBFFFFFFFFFFFFFLL;
    v221 = *(_QWORD *)(a2 + 9);
    v222 = (v221 >> 54) & 1;
    v223 = v221 & 0x40000000000000LL;
    v12 = ((v118 >> 54) & 1) >= (unsigned int)v222;
    v224 = (v118 >> 55) & 1;
    v225 = HIBYTE(v118) & 1;
    if ( !v12 )
      v223 = 0;
    v226 = v220 | v223;
    *(_QWORD *)(result + 9) = v226;
    v227 = v226 & 0xFF7FFFFFFFFFFFFFLL;
    v228 = *(_QWORD *)(a2 + 9);
    v229 = (v228 >> 55) & 1;
    v230 = v228 & 0x80000000000000LL;
    if ( (unsigned int)v224 < (unsigned int)v229 )
      v230 = 0;
    v231 = v227 | v230;
    *(_QWORD *)(result + 9) = v231;
    v232 = *(_QWORD *)(a2 + 9);
    v233 = HIBYTE(v232) & 1;
    v234 = v232 & 0x100000000000000LL;
    v12 = (unsigned int)v225 >= (unsigned int)v233;
    v235 = v231 & 0xFEFFFFFFFFFFFFFFLL;
    if ( v12 )
      v236 = v234;
    else
      v236 = 0;
    v237 = v235 | v236;
    v238 = *((unsigned __int16 *)result + 10);
    *(_QWORD *)(result + 9) = v237;
    v239 = *(_QWORD *)(a2 + 1);
    v240 = v238 >> 3;
    v241 = (v238 >> 1) & 1;
    v242 = (v239 >> 49) & 1;
    v449 = (v238 >> 2) & 1;
    v243 = v239 & 0x2000000000000LL;
    v244 = v238 >> 9;
    v245 = v238 >> 11;
    v12 = ((v3 >> 49) & 1) >= (unsigned int)v242;
    v246 = v238 >> 5;
    if ( v12 )
      v247 = v243;
    else
      v247 = 0;
    v248 = v247 | v119;
    v446 = v238 & 1;
    *(_QWORD *)(result + 1) = v247 | v119;
    v249 = (v238 >> 3) & 1;
    v250 = *(unsigned __int16 *)(a2 + 20);
    v435 = v248;
    v251 = (v238 >> 5) & 1;
    v252 = *(_WORD *)(a2 + 20) & 1;
    v253 = (v250 >> 1) & 1;
    LOWORD(v248) = v253 & ((v238 >> 1) | ~v252);
    v254 = v253 | v241;
    v255 = (v238 >> 10) | ~(v245 | (v250 >> 11));
    v256 = (v250 >> 3) & 1;
    v257 = v249 & ~(_WORD)v449;
    v451 = v248 | v241 & ~v446;
    v258 = v256 | v249;
    v259 = (v250 >> 5) & 1;
    v260 = (v238 >> 4) & 1;
    v261 = (v240 | ~(unsigned __int16)(v250 >> 2)) & v256;
    LOWORD(v256) = v259 | v251;
    v262 = (v238 >> 6) & 1;
    v263 = (v238 >> 7) & 1;
    v439 = (v250 >> 4) & ((v238 >> 4) | ~(v246 | (v250 >> 5)));
    v441 = (v250 >> 2) & ((v238 >> 2) | ~(v240 | (v250 >> 3)));
    LOWORD(v251) = v251 & ~(_WORD)v260;
    LOWORD(v248) = v260 & ~(_WORD)v256;
    v264 = (v250 >> 7) & 1;
    v437 = v449 & ~v258;
    v265 = (v238 >> 8) & 1;
    v438 = v248;
    v266 = (v246 | ~(v250 >> 4)) & v259;
    LOWORD(v248) = v263 & ~(_WORD)v262;
    v267 = (v250 >> 6) & ((v238 >> 6) | ~((v238 >> 7) | (v250 >> 7)));
    v268 = v264 | v263;
    v269 = (v238 >> 9) & 1;
    v270 = (v250 >> 9) & 1;
    v450 = v248;
    LODWORD(v248) = ((v238 >> 7) | ~(v250 >> 6)) & v264;
    LOWORD(v262) = v262 & ~v268;
    LOWORD(v264) = v269 & ~(_WORD)v265;
    v448 = v248;
    v271 = v244 | ~(v250 >> 8);
    v445 = (v250 >> 8) & ((v238 >> 8) | ~(v244 | (v250 >> 9)));
    LOWORD(v248) = v265 & ~(v270 | v269);
    v272 = (v238 >> 11) & 1;
    v273 = (v250 >> 11) & 1;
    LOWORD(v249) = v271 & v270;
    v274 = v245 | ~(v250 >> 10);
    v275 = (v238 >> 10) & 1;
    LOBYTE(v269) = (v250 >> 10) & v255;
    v442 = v248;
    LOWORD(v271) = v273 | v272;
    v276 = v272 & ~(_WORD)v275;
    v277 = v238 >> 15;
    v278 = v250 >> 15;
    LOWORD(v275) = v275 & ~(_WORD)v271;
    LOWORD(v271) = v274 & v273;
    v279 = (v238 >> 13) | ~(v250 >> 12);
    v280 = (v250 >> 12) & ((v238 >> 12) | ~((v238 >> 13) | (v250 >> 13)));
    v281 = v238 | ~v254;
    v282 = (v238 >> 12) & 1;
    v283 = (v238 >> 13) & 1;
    v284 = (v250 >> 13) & 1;
    v285 = v238 >> 14;
    v286 = (v238 >> 14) & 1;
    v250 >>= 14;
    v287 = v283 & ~(_WORD)v282;
    LOWORD(v283) = v284 | v283;
    LOWORD(v284) = v279 & v284;
    LOBYTE(v285) = v285 | ~(v278 | v277);
    LOWORD(v279) = v286 & ~(v278 | v277);
    LOWORD(v248) = v277 & ~(_WORD)v286;
    v288 = *((unsigned __int16 *)result + 11);
    LOWORD(v277) = (v277 | ~(_WORD)v250) & v278;
    LOWORD(v278) = v281 & v252;
    v289 = v261 | v257;
    v290 = v266 | v251;
    LOWORD(v277) = v277 | v248;
    LOWORD(v282) = v282 & ~(_WORD)v283;
    LOWORD(v248) = v446 & ~v254 | v278;
    LOWORD(v283) = v249 | v264;
    v291 = ((v269 & 1 | (unsigned __int16)v275) << 10) | (((unsigned __int16)v271 | v276) << 11);
    v292 = (v288 >> 2) & 1;
    v293 = (v288 >> 3) & 1;
    v294 = (v288 >> 4) & 1;
    v295 = (v288 >> 9) & 1;
    v296 = v291 | ((v445 & 1 | v442) << 8) | ((_WORD)v283 << 9);
    v297 = (v288 >> 6) & 1;
    v298 = (v288 >> 8) & 1;
    LOWORD(v278) = v296 | ((v267 & 1 | (unsigned __int16)v262) << 6) | ((v448 | v450) << 7);
    v299 = (v288 >> 5) & 1;
    LOWORD(v248) = (((unsigned __int8)v250 & (unsigned __int8)v285 & 1 | (unsigned __int16)v279) << 14)
                 | ((_WORD)v277 << 15)
                 | ((v280 & 1 | (unsigned __int16)v282) << 12)
                 | (((unsigned __int16)v284 | v287) << 13)
                 | v248
                 | (2 * v451)
                 | (4 * (v441 & 1 | v437))
                 | (8 * v289)
                 | (16 * (v439 & 1 | v438))
                 | (32 * v290)
                 | v278;
    v300 = (v288 >> 7) & 1;
    *((_WORD *)result + 10) = v248;
    v443 = v293 & ~(_WORD)v292;
    v301 = *(unsigned __int16 *)(a2 + 22);
    LOWORD(v445) = v299 & ~(_WORD)v294;
    LODWORD(v248) = (v301 >> 3) & 1;
    v447 = v292 & ~(v248 | v293);
    v302 = (v301 >> 5) & 1;
    v303 = ((v288 >> 3) | ~(*(_WORD *)(a2 + 22) >> 2)) & v248;
    LOWORD(v292) = v295 & ~(_WORD)v298;
    LOWORD(v441) = v294 & ~(v302 | v299);
    LOBYTE(v289) = (v288 >> 6) | ~((v301 >> 7) | (v288 >> 7));
    v304 = (v301 >> 9) & 1;
    v440 = v297 & ~((v301 >> 7) & 1 | v300);
    LOWORD(v298) = v298 & ~(v304 | v295);
    LOWORD(v295) = ((v288 >> 9) | ~HIBYTE(*(_WORD *)(a2 + 22))) & v304;
    v305 = (v288 >> 10) & 1;
    LODWORD(v248) = (v288 >> 11) & 1;
    v306 = (v301 >> 11) & 1;
    LOWORD(v250) = v248 & ~(_WORD)v305;
    LOWORD(v305) = v305 & ~(v306 | v248);
    v307 = ((v288 >> 11) | ~(*(_WORD *)(a2 + 22) >> 10)) & v306 | v250;
    LOWORD(v298) = BYTE1(v301) & (unsigned __int8)(BYTE1(v288) | ~((v301 >> 9) | (v288 >> 9))) & 1 | v298;
    LOWORD(v250) = v288 & 1 & ~((v301 >> 1) & 1 | (v288 >> 1) & 1)
                 | (v288 | ~((v301 >> 1) & 1 | (v288 >> 1) & 1)) & v301 & 1
                 | (2 * ((v301 >> 1) & 1 & ((v288 >> 1) | ~(v301 & 1)) | (v288 >> 1) & 1 & ~(v288 & 1)));
    LODWORD(v248) = (v288 >> 7) | ~(v301 >> 6);
    LOWORD(v299) = (unsigned __int8)(v301 >> 10) & (unsigned __int8)((v288 >> 10) | ~((v301 >> 11) | (v288 >> 11))) & 1
                 | v305;
    v308 = (4 * ((unsigned __int8)(v301 >> 2) & (unsigned __int8)((v288 >> 2) | ~((v301 >> 3) | (v288 >> 3))) & 1 | v447))
         | (8 * (v303 | v443));
    LOWORD(v293) = (16
                  * ((unsigned __int8)(v301 >> 4) & (unsigned __int8)((v288 >> 4) | ~((v301 >> 5) | (v288 >> 5))) & 1
                   | v441))
                 | (32 * (((v288 >> 5) | ~(*(_WORD *)(a2 + 22) >> 4)) & v302 | v445));
    *((_WORD *)result + 11) = (((unsigned __int8)(v301 >> 14)
                              & (unsigned __int8)((v288 >> 14) | ~((v301 >> 15) | (v288 >> 15)))
                              & 1
                              | (v288 >> 14) & 1 & (unsigned __int16)~((v301 >> 15) | (v288 >> 15))) << 14)
                            | ((((v288 >> 15) | (unsigned __int16)~(unsigned __int16)(v301 >> 14))
                              & (unsigned __int16)(v301 >> 15)
                              | (v288 >> 15) & (unsigned __int16)~((v288 >> 14) & 1)) << 15)
                            | (((unsigned __int8)(v301 >> 12)
                              & (unsigned __int8)((v288 >> 12) | ~((v301 >> 13) | (v288 >> 13)))
                              & 1
                              | (v288 >> 12) & 1 & (unsigned __int16)~((v301 >> 13) & 1 | (v288 >> 13) & 1)) << 12)
                            | (((unsigned __int16)((v288 >> 13) | ~(unsigned __int16)(v301 >> 12)) & (v301 >> 13) & 1
                              | (v288 >> 13) & 1 & (unsigned __int16)~((v288 >> 12) & 1)) << 13)
                            | v250
                            | v308
                            | v293
                            | ((_WORD)v299 << 10)
                            | (v307 << 11)
                            | ((_WORD)v298 << 8)
                            | (((unsigned __int16)v295 | (unsigned __int16)v292) << 9)
                            | (((unsigned __int8)(v301 >> 6) & (unsigned __int8)v289 & 1 | (unsigned __int16)v440) << 6)
                            | (((unsigned __int16)v248 & (*(_WORD *)(a2 + 22) >> 7) & 1
                              | (unsigned __int16)(v300 & ~(_WORD)v297)) << 7);
    if ( (a3 & 1) != 0 )
    {
      v309 = (*(_QWORD *)(a2 + 1) >> 57) & 0xFLL;
      v310 = *((unsigned __int16 *)result + 12);
      v311 = v310 >> 3;
      if ( ((v436 >> 57) & 0xF) < (unsigned int)v309 )
        LOBYTE(v309) = (v436 >> 57) & 0xF;
      v312 = (v310 >> 2) & 1;
      v313 = (v310 >> 3) & 1;
      v314 = (v310 >> 1) & 1;
      *(_QWORD *)(result + 1) = v435 & 0xE1FFFFFFFFFFFFFFLL | ((unsigned __int64)(v309 & 0xF) << 57);
      v315 = v313 & ~(_WORD)v312;
      v316 = (v310 >> 4) & 1;
      v317 = *(unsigned __int16 *)(a2 + 24);
      v318 = (v310 >> 5) & 1;
      v319 = v314 & ~(v310 & 1);
      v320 = (v317 >> 3) & 1;
      v321 = (v317 >> 1) & 1;
      LOWORD(v314) = v321 | v314;
      v322 = v321 & ((v310 >> 1) | ~(v317 & 1));
      v323 = (v317 >> 5) & 1;
      LOWORD(v312) = (unsigned __int8)(v317 >> 2) & (unsigned __int8)((v310 >> 2) | ~(v311 | (v317 >> 3))) & 1
                   | v312 & ~(v320 | v313);
      LOWORD(v313) = (unsigned __int8)(v317 >> 4) & (unsigned __int8)((v310 >> 4) | ~((v310 >> 5) | (v317 >> 5))) & 1
                   | v316 & ~(v323 | v318);
      v324 = v310 & 1 & ~(_WORD)v314 | (v310 | ~(_WORD)v314) & *(_WORD *)(a2 + 24) & 1 | (2 * (v322 | v319));
      LOWORD(v322) = (4 * v312) | (8 * ((v311 | ~(*(_WORD *)(a2 + 24) >> 2)) & v320 | v315));
      v325 = ((v310 >> 5) | ~(v317 >> 4)) & v323 | v318 & ~v316;
      v326 = (v310 >> 7) & 1;
      v327 = (v317 >> 7) & 1;
      v328 = (v310 >> 6) & 1;
      LOWORD(v325) = (16 * v313) | (32 * v325);
      v329 = (v310 >> 9) & 1;
      v330 = (v317 >> 9) & 1;
      v331 = (unsigned __int8)(v317 >> 6) & (unsigned __int8)((v310 >> 6) | ~((v310 >> 7) | (v317 >> 7))) & 1
           | v328 & ~(v327 | v326);
      v332 = v326 & ~(_WORD)v328;
      v333 = (v310 >> 8) & 1;
      LOWORD(v313) = BYTE1(v317) & (unsigned __int8)(BYTE1(v310) | ~((v310 >> 9) | (v317 >> 9))) & 1
                   | v333 & ~(v330 | v329);
      v334 = (v310 >> 11) & 1;
      v335 = (v317 >> 11) & 1;
      v336 = v329 & ~v333;
      v337 = (v310 >> 10) & 1;
      v338 = ((v310 >> 9) | ~(v317 >> 8)) & v330 | v336;
      v339 = (v310 >> 13) & 1;
      v340 = (v317 >> 13) & 1;
      LOWORD(v336) = (unsigned __int8)(v317 >> 10)
                   & (unsigned __int8)((v310 >> 10) | ~((v310 >> 11) | (v317 >> 11)))
                   & 1
                   | v337 & ~(v335 | v334);
      v341 = v334 & ~(_WORD)v337;
      v342 = (v310 >> 12) & 1;
      v343 = v317 >> 15;
      v344 = v310 >> 15;
      *((_WORD *)result + 12) = (((unsigned __int8)(v317 >> 14)
                                & (unsigned __int8)((v310 >> 14) | ~(v343 | (v310 >> 15)))
                                & 1
                                | (v310 >> 14) & 1 & (unsigned __int16)~(v343 | (v310 >> 15))) << 14)
                              | (((v344 | (unsigned __int16)~(unsigned __int16)(v317 >> 14)) & (unsigned __int16)v343
                                | v344 & (unsigned __int16)~((v310 >> 14) & 1)) << 15)
                              | (((unsigned __int8)(v317 >> 12)
                                & (unsigned __int8)((v310 >> 12) | ~((v310 >> 13) | (v317 >> 13)))
                                & 1
                                | (unsigned __int16)(v342 & ~(v340 | v339))) << 12)
                              | ((((v310 >> 13) | (unsigned __int16)~(unsigned __int16)(v317 >> 12))
                                & (unsigned __int16)v340
                                | (unsigned __int16)(v339 & ~(_WORD)v342)) << 13)
                              | v324
                              | v322
                              | v325
                              | ((_WORD)v336 << 10)
                              | ((((v310 >> 11) | (unsigned __int16)~(unsigned __int16)(v317 >> 10))
                                & (unsigned __int16)v335
                                | v341) << 11)
                              | ((_WORD)v313 << 8)
                              | ((_WORD)v338 << 9)
                              | (v331 << 6)
                              | ((((v310 >> 7) | (unsigned __int16)~(unsigned __int16)(v317 >> 6))
                                & (unsigned __int16)v327
                                | v332) << 7);
      v345 = *((unsigned __int16 *)result + 13);
      v346 = *(unsigned __int16 *)(a2 + 26);
      v347 = (v345 >> 3) & 1;
      v348 = (v346 >> 3) & 1;
      v349 = (v345 >> 2) & 1;
      v350 = v345 & 1 & ~((v346 >> 1) & 1 | (v345 >> 1) & 1)
           | (v345 | ~((v346 >> 1) & 1 | (v345 >> 1) & 1)) & v346 & 1
           | (2 * ((v346 >> 1) & 1 & ((v345 >> 1) | ~(v346 & 1)) | (v345 >> 1) & 1 & ~(v345 & 1)));
      LOWORD(v322) = (unsigned __int8)(v346 >> 2) & (unsigned __int8)((v345 >> 2) | ~((v345 >> 3) | (v346 >> 3))) & 1
                   | v349 & ~(v348 | v347);
      LOWORD(v349) = v347 & ~(_WORD)v349;
      v351 = ((v345 >> 3) | ~(v346 >> 2)) & v348;
      v352 = (v345 >> 5) & 1;
      v353 = (v346 >> 5) & 1;
      v354 = (v345 >> 4) & 1;
      LOWORD(v322) = (4 * v322) | (8 * (v351 | v349));
      LOWORD(v351) = (unsigned __int8)(v346 >> 4) & (unsigned __int8)((v345 >> 4) | ~((v345 >> 5) | (v346 >> 5))) & 1
                   | v354 & ~(v353 | v352);
      v355 = v352 & ~v354;
      v356 = (v345 >> 7) & 1;
      v357 = ((v345 >> 5) | ~(v346 >> 4)) & v353 | v355;
      v358 = (v346 >> 7) & 1;
      v359 = (v345 >> 6) & 1;
      LOWORD(v351) = (16 * v351) | (32 * v357);
      v360 = (v345 >> 9) & 1;
      v361 = (v346 >> 9) & 1;
      LOWORD(v357) = (unsigned __int8)(v346 >> 6) & (unsigned __int8)((v345 >> 6) | ~((v345 >> 7) | (v346 >> 7))) & 1
                   | v359 & ~(v358 | v356);
      v362 = v356 & ~(_WORD)v359;
      v363 = (v345 >> 8) & 1;
      LOWORD(v352) = BYTE1(v346) & (unsigned __int8)(BYTE1(v345) | ~((v345 >> 9) | (v346 >> 9))) & 1
                   | v363 & ~(v361 | v360);
      v364 = (v345 >> 11) & 1;
      v365 = (v346 >> 11) & 1;
      v366 = v360 & ~v363;
      v367 = (v345 >> 10) & 1;
      v368 = ((v345 >> 9) | ~(v346 >> 8)) & v361 | v366;
      LOWORD(v366) = (unsigned __int8)(v346 >> 10)
                   & (unsigned __int8)((v345 >> 10) | ~((v345 >> 11) | (v346 >> 11)))
                   & 1
                   | v367 & ~(v365 | v364);
      v369 = v364 & ~(_WORD)v367;
      v370 = (v345 >> 13) & 1;
      v371 = (v346 >> 13) & 1;
      v372 = (v345 >> 12) & 1;
      v373 = v345 >> 15;
      v374 = v346 >> 15;
      *((_WORD *)result + 13) = (((unsigned __int8)(v346 >> 14)
                                & (unsigned __int8)((v345 >> 14) | ~(v374 | (v345 >> 15)))
                                & 1
                                | (v345 >> 14) & 1 & (unsigned __int16)~(v374 | (v345 >> 15))) << 14)
                              | (((v373 | (unsigned __int16)~(unsigned __int16)(v346 >> 14)) & (unsigned __int16)v374
                                | v373 & (unsigned __int16)~((v345 >> 14) & 1)) << 15)
                              | (((unsigned __int8)(v346 >> 12)
                                & (unsigned __int8)((v345 >> 12) | ~((v345 >> 13) | (v346 >> 13)))
                                & 1
                                | (unsigned __int16)(v372 & ~(v371 | v370))) << 12)
                              | ((((v345 >> 13) | (unsigned __int16)~(unsigned __int16)(v346 >> 12))
                                & (unsigned __int16)v371
                                | (unsigned __int16)(v370 & ~(_WORD)v372)) << 13)
                              | v350
                              | v322
                              | v351
                              | ((_WORD)v366 << 10)
                              | ((((v345 >> 11) | (unsigned __int16)~(unsigned __int16)(v346 >> 10))
                                & (unsigned __int16)v365
                                | v369) << 11)
                              | ((_WORD)v352 << 8)
                              | ((_WORD)v368 << 9)
                              | ((_WORD)v357 << 6)
                              | ((((v345 >> 7) | (unsigned __int16)~(unsigned __int16)(v346 >> 6))
                                & (unsigned __int16)v358
                                | v362) << 7);
      v375 = *((unsigned __int16 *)result + 14);
      v376 = *(unsigned __int16 *)(a2 + 28);
      v377 = (v375 >> 3) & 1;
      v378 = (v376 >> 3) & 1;
      v379 = (v375 >> 2) & 1;
      v380 = v375 & 1 & ~((v376 >> 1) & 1 | (v375 >> 1) & 1)
           | (v375 | ~((v376 >> 1) & 1 | (v375 >> 1) & 1)) & v376 & 1
           | (2 * ((v376 >> 1) & 1 & ((v375 >> 1) | ~(v376 & 1)) | (v375 >> 1) & 1 & ~(v375 & 1)));
      LOWORD(v322) = (unsigned __int8)(v376 >> 2) & (unsigned __int8)((v375 >> 2) | ~((v375 >> 3) | (v376 >> 3))) & 1
                   | v379 & ~(v378 | v377);
      LOWORD(v379) = v377 & ~(_WORD)v379;
      v381 = ((v375 >> 3) | ~(v376 >> 2)) & v378;
      v382 = (v375 >> 5) & 1;
      v383 = (v376 >> 5) & 1;
      v384 = (v375 >> 4) & 1;
      LOWORD(v322) = (4 * v322) | (8 * (v381 | v379));
      LOWORD(v381) = (unsigned __int8)(v376 >> 4) & (unsigned __int8)((v375 >> 4) | ~((v375 >> 5) | (v376 >> 5))) & 1
                   | v384 & ~(v383 | v382);
      v385 = v382 & ~v384;
      v386 = (v375 >> 7) & 1;
      v387 = ((v375 >> 5) | ~(v376 >> 4)) & v383 | v385;
      v388 = (v376 >> 7) & 1;
      v389 = (v375 >> 6) & 1;
      LOWORD(v381) = (16 * v381) | (32 * v387);
      v390 = (v375 >> 9) & 1;
      v391 = (v376 >> 9) & 1;
      LOWORD(v387) = (unsigned __int8)(v376 >> 6) & (unsigned __int8)((v375 >> 6) | ~((v375 >> 7) | (v376 >> 7))) & 1
                   | v389 & ~(v388 | v386);
      v392 = v386 & ~(_WORD)v389;
      v393 = (v375 >> 8) & 1;
      LOWORD(v382) = BYTE1(v376) & (unsigned __int8)(BYTE1(v375) | ~((v375 >> 9) | (v376 >> 9))) & 1
                   | v393 & ~(v391 | v390);
      v394 = (v375 >> 11) & 1;
      v395 = (v376 >> 11) & 1;
      v396 = v390 & ~v393;
      v397 = (v375 >> 10) & 1;
      v398 = ((v375 >> 9) | ~(v376 >> 8)) & v391 | v396;
      LOWORD(v396) = (unsigned __int8)(v376 >> 10)
                   & (unsigned __int8)((v375 >> 10) | ~((v375 >> 11) | (v376 >> 11)))
                   & 1
                   | v397 & ~(v395 | v394);
      v399 = v394 & ~(_WORD)v397;
      v400 = (v375 >> 13) & 1;
      v401 = (v376 >> 13) & 1;
      v402 = (v375 >> 12) & 1;
      v403 = v375 >> 15;
      v404 = v376 >> 15;
      *((_WORD *)result + 14) = (((unsigned __int8)(v376 >> 14) & (unsigned __int8)((v375 >> 14) | ~(v404 | v403)) & 1
                                | (v375 >> 14) & 1 & (unsigned __int16)~(v404 | v403)) << 14)
                              | (((v403 | (unsigned __int16)~(unsigned __int16)(v376 >> 14)) & (unsigned __int16)v404
                                | v403 & (unsigned __int16)~((v375 >> 14) & 1)) << 15)
                              | (((unsigned __int8)(v376 >> 12)
                                & (unsigned __int8)((v375 >> 12) | ~((v375 >> 13) | (v376 >> 13)))
                                & 1
                                | (unsigned __int16)(v402 & ~(v401 | v400))) << 12)
                              | ((((v375 >> 13) | (unsigned __int16)~(unsigned __int16)(v376 >> 12))
                                & (unsigned __int16)v401
                                | (unsigned __int16)(v400 & ~(_WORD)v402)) << 13)
                              | v380
                              | v322
                              | v381
                              | ((_WORD)v396 << 10)
                              | ((((v375 >> 11) | (unsigned __int16)~(unsigned __int16)(v376 >> 10))
                                & (unsigned __int16)v395
                                | v399) << 11)
                              | ((_WORD)v382 << 8)
                              | ((_WORD)v398 << 9)
                              | ((_WORD)v387 << 6)
                              | ((((v375 >> 7) | (unsigned __int16)~(unsigned __int16)(v376 >> 6))
                                & (unsigned __int16)v388
                                | v392) << 7);
      v405 = *((unsigned __int16 *)result + 15);
      v406 = *(unsigned __int16 *)(a2 + 30);
      v407 = (v405 >> 3) & 1;
      v408 = (v406 >> 3) & 1;
      v409 = (v405 >> 2) & 1;
      LOWORD(v322) = (unsigned __int8)(v406 >> 2) & (unsigned __int8)((v405 >> 2) | ~((v405 >> 3) | (v406 >> 3))) & 1
                   | v409 & ~(v408 | v407);
      LOWORD(v409) = v407 & ~(_WORD)v409;
      v410 = ((v405 >> 3) | ~(v406 >> 2)) & v408;
      v411 = (v405 >> 5) & 1;
      v412 = (v406 >> 5) & 1;
      v413 = (v405 >> 4) & 1;
      LOWORD(v322) = (4 * v322) | (8 * (v410 | v409));
      LOWORD(v410) = (unsigned __int8)(v406 >> 4) & (unsigned __int8)((v405 >> 4) | ~((v405 >> 5) | (v406 >> 5))) & 1
                   | v413 & ~(v412 | v411);
      v414 = v411 & ~v413;
      v415 = (v405 >> 7) & 1;
      v416 = ((v405 >> 5) | ~(v406 >> 4)) & v412 | v414;
      v417 = (v406 >> 7) & 1;
      v418 = (v405 >> 6) & 1;
      LOWORD(v410) = (16 * v410) | (32 * v416);
      v419 = (v405 >> 9) & 1;
      v420 = (v406 >> 9) & 1;
      LOWORD(v416) = (unsigned __int8)(v406 >> 6) & (unsigned __int8)((v405 >> 6) | ~((v405 >> 7) | (v406 >> 7))) & 1
                   | v418 & ~(v417 | v415);
      v421 = v415 & ~(_WORD)v418;
      v422 = (v405 >> 8) & 1;
      LOWORD(v411) = BYTE1(v406) & (unsigned __int8)(BYTE1(v405) | ~((v405 >> 9) | (v406 >> 9))) & 1
                   | v422 & ~(v420 | v419);
      v423 = v419 & ~v422;
      v424 = (v405 >> 11) & 1;
      v425 = (v406 >> 11) & 1;
      v426 = (v405 >> 10) & 1;
      v427 = ((v405 >> 9) | ~(v406 >> 8)) & v420 | v423;
      LOWORD(v422) = (unsigned __int8)(v406 >> 10)
                   & (unsigned __int8)((v405 >> 10) | ~((v405 >> 11) | (v406 >> 11)))
                   & 1
                   | v426 & ~(v425 | v424);
      v428 = ((v405 >> 11) | ~(v406 >> 10)) & v425 | v424 & ~v426;
      v429 = (v405 >> 13) & 1;
      v430 = (v406 >> 13) & 1;
      v431 = (v405 >> 12) & 1;
      v432 = v405 >> 15;
      v433 = v406 >> 15;
      *((_WORD *)result + 15) = (((unsigned __int8)(v406 >> 14) & (unsigned __int8)((v405 >> 14) | ~(v433 | v432)) & 1
                                | (v405 >> 14) & 1 & (unsigned __int16)~(v433 | v432)) << 14)
                              | (((v432 | (unsigned __int16)~(unsigned __int16)(v406 >> 14)) & (unsigned __int16)v433
                                | v432 & (unsigned __int16)~((v405 >> 14) & 1)) << 15)
                              | (((unsigned __int8)(v406 >> 12)
                                & (unsigned __int8)((v405 >> 12) | ~((v405 >> 13) | (v406 >> 13)))
                                & 1
                                | (unsigned __int16)(v431 & ~(v430 | v429))) << 12)
                              | ((((v405 >> 13) | (unsigned __int16)~(unsigned __int16)(v406 >> 12))
                                & (unsigned __int16)v430
                                | (unsigned __int16)(v429 & ~(_WORD)v431)) << 13)
                              | v405 & 1 & ~((v406 >> 1) & 1 | (v405 >> 1) & 1)
                              | (v405 | ~((v406 >> 1) & 1 | (v405 >> 1) & 1)) & v406 & 1
                              | (2 * ((v406 >> 1) & 1 & ((v405 >> 1) | ~(v406 & 1)) | (v405 >> 1) & 1 & ~(v405 & 1)))
                              | v322
                              | v410
                              | ((_WORD)v422 << 10)
                              | ((_WORD)v428 << 11)
                              | ((_WORD)v411 << 8)
                              | ((_WORD)v427 << 9)
                              | ((_WORD)v416 << 6)
                              | ((((v405 >> 7) | (unsigned __int16)~(unsigned __int16)(v406 >> 6))
                                & (unsigned __int16)v417
                                | v421) << 7);
      *((_WORD *)result + 15) = *(_WORD *)(a2 + 30);
    }
  }
  else
  {
    v434 = result;
    result = qdf_mem_copy(result, (const void *)a2, 0x3Cu);
    *v434 = 1;
  }
  return result;
}
