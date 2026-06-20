__int64 __fastcall dp_update_pdev_stats(__int64 result, __int64 a2)
{
  __int64 v2; // x10
  _DWORD *v3; // x13
  _DWORD *v4; // x14
  int v5; // w17
  int v6; // w16
  int v7; // w15
  int v8; // w16
  int v9; // w17
  int v10; // w16
  int v11; // w15
  int v12; // w16
  int v13; // w17
  int v14; // w16
  int v15; // w15
  int v16; // w16
  int v17; // w17
  int v18; // w16
  int v19; // w15
  int v20; // w16
  int v21; // w17
  int v22; // w16
  int v23; // w15
  int v24; // w16
  int v25; // w17
  int v26; // w16
  int v27; // w15
  int v28; // w16
  int v29; // w17
  int v30; // w16
  int v31; // w15
  int v32; // w16
  int v33; // w15
  int v34; // w16
  __int64 v35; // x10
  int v36; // w12
  int v37; // w11
  int v38; // w12
  int v39; // w11
  int v40; // w12
  int v41; // w11
  int v42; // w12
  int v43; // w11
  int v44; // w12
  int v45; // w11
  int v46; // w12
  int v47; // w11
  int v48; // w12
  int v49; // w11
  int v50; // w12
  int v51; // w11
  int v52; // w12
  int v53; // w11
  int v54; // w12
  int v55; // w11
  int v56; // w12
  int v57; // w11
  int v58; // w12
  int v59; // w11
  int v60; // w12
  int v61; // w11
  int v62; // w12
  int v63; // w11
  int v64; // w12
  int v65; // w11
  int v66; // w12
  int v67; // w11
  int v68; // w12
  int v69; // w11
  int v70; // w12
  int v71; // w11
  int v72; // w12
  int v73; // w11
  int v74; // w12
  int v75; // w11
  int v76; // w12
  int v77; // w11
  int v78; // w12
  int v79; // w11
  int v80; // w12
  int v81; // w11
  int v82; // w12
  int v83; // w11
  int v84; // w12
  int v85; // w11
  int v86; // w12
  int v87; // w11
  int v88; // w12
  int v89; // w11
  int v90; // w12
  int v91; // w11
  int v92; // w12
  int v93; // w11
  int v94; // w12
  int v95; // w11
  int v96; // w12
  int v97; // w11
  int v98; // w12
  int v99; // w11
  int v100; // w12
  int v101; // w11
  int v102; // w12
  int v103; // w11
  int v104; // w12
  int v105; // w11
  int v106; // w12
  int v107; // w11
  int v108; // w12
  int v109; // w11
  int v110; // w12
  int v111; // w11
  int v112; // w12
  int v113; // w11
  int v114; // w12
  int v115; // w11
  __int64 v116; // x12
  __int64 v117; // x11
  __int64 v118; // x12
  __int64 v119; // x11
  __int64 v120; // x12
  __int64 v121; // x11
  __int64 v122; // x12
  __int64 v123; // x11
  __int64 v124; // x12
  __int64 v125; // x11
  __int64 v126; // x12
  __int64 v127; // x11
  __int64 v128; // x12
  __int64 v129; // x11
  __int64 v130; // x12
  __int64 v131; // x11
  __int64 i; // x10
  int v133; // w11
  int v134; // w10
  int v135; // w11
  int v136; // w10
  int v137; // w11
  int v138; // w10
  int v139; // w11
  int v140; // w10
  int v141; // w11
  int v142; // w10
  int v143; // w11
  int v144; // w10
  int v145; // w11
  int v146; // w10
  int v147; // w11
  int v148; // w10
  int v149; // w11
  int v150; // w10
  int v151; // w11
  int v152; // w10
  int v153; // w11
  int v154; // w10
  int v155; // w11
  int v156; // w10
  int v157; // w11
  int v158; // w10
  int v159; // w11
  int v160; // w10
  int v161; // w11
  int v162; // w10
  int v163; // w11
  int v164; // w10
  int v165; // w11
  int v166; // w10
  int v167; // w11
  int v168; // w10
  int v169; // w11
  int v170; // w10
  int v171; // w11
  int v172; // w10
  int v173; // w11
  int v174; // w10
  int v175; // w11
  int v176; // w10
  int v177; // w11
  unsigned int v178; // w11
  unsigned int v179; // w11
  unsigned int v180; // w11
  unsigned int v181; // w11
  __int64 v182; // x11
  __int64 v183; // x10
  __int64 v184; // x11
  __int64 v185; // x10
  __int64 v186; // x11
  __int64 v187; // x10
  __int64 v188; // x11
  __int64 v189; // x10
  __int64 v190; // x11
  __int64 v191; // x10
  __int64 v192; // x11
  __int64 v193; // x10
  __int64 v194; // x11
  __int64 v195; // x10
  __int64 v196; // x11
  __int64 v197; // x10
  __int64 v198; // x11
  __int64 v199; // x10
  __int64 v200; // x11
  __int64 v201; // x10
  __int64 v202; // x11
  __int64 v203; // x10
  __int64 v204; // x11
  __int64 v205; // x10
  __int64 v206; // x11
  __int64 v207; // x10
  __int64 v208; // x11
  __int64 v209; // x10
  __int64 v210; // x11
  __int64 v211; // x10
  __int64 v212; // x11
  __int64 v213; // x10
  __int64 v214; // x11
  __int64 v215; // x10
  __int64 v216; // x11
  __int64 v217; // x10
  __int64 v218; // x11
  __int64 v219; // x10
  unsigned int v220; // w9
  unsigned int v221; // w9
  unsigned int v222; // w9
  unsigned int v223; // w9
  int v224; // w9
  int v225; // w8
  int v226; // w9
  int v227; // w8
  int v228; // w9
  int v229; // w8
  int v230; // w9
  int v231; // w8
  int v232; // w9
  int v233; // w8
  __int64 v234; // x9
  __int64 v235; // x8
  __int64 v236; // x9
  __int64 v237; // x8
  __int64 v238; // x9
  __int64 v239; // x8
  __int64 v240; // x9
  __int64 v241; // x8
  __int64 v242; // x9
  __int64 v243; // x8
  __int64 v244; // x9
  __int64 v245; // x8
  __int64 v246; // x9
  __int64 v247; // x8
  __int64 v248; // x9
  __int64 v249; // x8
  __int64 v250; // x9
  __int64 v251; // x8
  __int64 v252; // x9
  __int64 v253; // x8
  __int64 v254; // x9
  __int64 v255; // x8
  __int64 v256; // x9
  __int64 v257; // x8
  __int64 v258; // x9
  __int64 v259; // x8
  __int64 v260; // x9
  __int64 v261; // x8
  __int64 v262; // x9
  __int64 v263; // x8
  __int64 v264; // x9
  __int64 v265; // x8
  __int64 v266; // x9
  __int64 v267; // x8
  __int64 v268; // x9
  __int64 v269; // x8
  __int64 v270; // x9
  __int64 v271; // x8
  __int64 v272; // x9
  __int64 v273; // x8
  __int64 v274; // x9
  __int64 v275; // x8
  __int64 v276; // x9
  __int64 v277; // x8
  __int64 v278; // x9
  __int64 v279; // x8
  __int64 v280; // x9
  unsigned __int64 v281; // x8
  unsigned __int64 v282; // x9
  bool v283; // cf
  unsigned __int64 v284; // x8
  unsigned __int64 v285; // x8
  unsigned __int64 v286; // x9
  unsigned __int64 v287; // x8
  __int64 v288; // x12
  char v289; // w11
  __int64 v290; // x12
  _DWORD *v291; // x13
  _DWORD *v292; // x12
  int v293; // w16
  int v294; // w16
  int v295; // w16
  int v296; // w16
  int v297; // w16
  int v298; // w16
  int v299; // w16
  int v300; // w16
  int v301; // w16
  int v302; // w16
  int v303; // w16
  int v304; // w16
  char v305; // w15
  int v306; // w9
  int v307; // w8
  int v308; // w9
  int v309; // w8
  int v310; // w9
  int v311; // w8
  int v312; // w9
  int v313; // w8
  int v314; // w9
  int v315; // w8
  int v316; // w9
  int v317; // w8
  int v318; // w9
  int v319; // w8
  int v320; // w9
  int v321; // w8
  int v322; // w9
  int v323; // w8
  int v324; // w9
  int v325; // w8
  int v326; // w9
  int v327; // w8
  int v328; // w9
  int v329; // w8
  int v330; // w9
  int v331; // w8
  int v332; // w9
  int v333; // w8
  int v334; // w9
  int v335; // w8
  int v336; // w9
  int v337; // w8
  int v338; // w9
  int v339; // w8
  int v340; // w9
  int v341; // w8
  int v342; // w9
  int v343; // w8
  int v344; // w9
  int v345; // w8
  int v346; // w9
  int v347; // w8
  int v348; // w9
  int v349; // w8
  int v350; // w9
  int v351; // w8
  int v352; // w9
  int v353; // w8
  int v354; // w9
  int v355; // w8
  int v356; // w9
  int v357; // w8
  int v358; // w9
  int v359; // w8
  int v360; // w9
  int v361; // w8
  int v362; // w9
  int v363; // w8
  int v364; // w9
  int v365; // w8
  int v366; // w9
  int v367; // w8
  int v368; // w9
  int v369; // w8
  int v370; // w9
  int v371; // w8
  int v372; // w9
  int v373; // w8
  int v374; // w9

  v2 = 0;
  do
  {
    v3 = (_DWORD *)(result + 3200 + v2);
    v4 = (_DWORD *)(a2 + 2680 + v2);
    v2 += 60;
    v5 = v3[1];
    v6 = v3[627];
    *v3 += *v4;
    v7 = v6 + v4[627];
    v8 = v3[628];
    v3[627] = v7;
    v3[1] = v5 + v4[1];
    v3[628] = v8 + v4[628];
    v9 = v3[3];
    v10 = v3[629];
    v3[2] += v4[2];
    v11 = v10 + v4[629];
    v12 = v3[630];
    v3[629] = v11;
    v3[3] = v9 + v4[3];
    v3[630] = v12 + v4[630];
    v13 = v3[5];
    v14 = v3[631];
    v3[4] += v4[4];
    v15 = v14 + v4[631];
    v16 = v3[632];
    v3[631] = v15;
    v3[5] = v13 + v4[5];
    v3[632] = v16 + v4[632];
    v17 = v3[7];
    v18 = v3[633];
    v3[6] += v4[6];
    v19 = v18 + v4[633];
    v20 = v3[634];
    v3[633] = v19;
    v3[7] = v17 + v4[7];
    v3[634] = v20 + v4[634];
    v21 = v3[9];
    v22 = v3[635];
    v3[8] += v4[8];
    v23 = v22 + v4[635];
    v24 = v3[636];
    v3[635] = v23;
    v3[9] = v21 + v4[9];
    v3[636] = v24 + v4[636];
    v25 = v3[11];
    v26 = v3[637];
    v3[10] += v4[10];
    v27 = v26 + v4[637];
    v28 = v3[638];
    v3[637] = v27;
    v3[11] = v25 + v4[11];
    v3[638] = v28 + v4[638];
    v29 = v3[13];
    v30 = v3[639];
    v3[12] += v4[12];
    v31 = v30 + v4[639];
    v32 = v3[640];
    v3[639] = v31;
    v3[13] = v29 + v4[13];
    v33 = v32 + v4[640];
    v34 = v3[14];
    v3[640] = v33;
    v3[14] = v34 + v4[14];
    v3[641] += v4[641];
  }
  while ( v2 != 300 );
  v35 = 0;
  v36 = *(_DWORD *)(result + 6376);
  *(_DWORD *)(result + 3556) += *(_DWORD *)(a2 + 3036);
  v37 = v36 + *(_DWORD *)(a2 + 5856);
  v38 = *(_DWORD *)(result + 3560);
  *(_DWORD *)(result + 6376) = v37;
  v39 = v38 + *(_DWORD *)(a2 + 3040);
  v40 = *(_DWORD *)(result + 6380);
  *(_DWORD *)(result + 3560) = v39;
  v41 = v40 + *(_DWORD *)(a2 + 5860);
  v42 = *(_DWORD *)(result + 3564);
  *(_DWORD *)(result + 6380) = v41;
  v43 = v42 + *(_DWORD *)(a2 + 3044);
  v44 = *(_DWORD *)(result + 6384);
  *(_DWORD *)(result + 3564) = v43;
  v45 = v44 + *(_DWORD *)(a2 + 5864);
  v46 = *(_DWORD *)(result + 3568);
  *(_DWORD *)(result + 6384) = v45;
  v47 = v46 + *(_DWORD *)(a2 + 3048);
  v48 = *(_DWORD *)(result + 6388);
  *(_DWORD *)(result + 3568) = v47;
  v49 = v48 + *(_DWORD *)(a2 + 5868);
  v50 = *(_DWORD *)(result + 3572);
  *(_DWORD *)(result + 6388) = v49;
  v51 = v50 + *(_DWORD *)(a2 + 3052);
  v52 = *(_DWORD *)(result + 6392);
  *(_DWORD *)(result + 3572) = v51;
  v53 = v52 + *(_DWORD *)(a2 + 5872);
  v54 = *(_DWORD *)(result + 3576);
  *(_DWORD *)(result + 6392) = v53;
  v55 = v54 + *(_DWORD *)(a2 + 3056);
  v56 = *(_DWORD *)(result + 6396);
  *(_DWORD *)(result + 3576) = v55;
  v57 = v56 + *(_DWORD *)(a2 + 5876);
  v58 = *(_DWORD *)(result + 3580);
  *(_DWORD *)(result + 6396) = v57;
  v59 = v58 + *(_DWORD *)(a2 + 3060);
  v60 = *(_DWORD *)(result + 6400);
  *(_DWORD *)(result + 3580) = v59;
  v61 = v60 + *(_DWORD *)(a2 + 5880);
  v62 = *(_DWORD *)(result + 3584);
  *(_DWORD *)(result + 6400) = v61;
  v63 = v62 + *(_DWORD *)(a2 + 3064);
  v64 = *(_DWORD *)(result + 6404);
  *(_DWORD *)(result + 3584) = v63;
  v65 = v64 + *(_DWORD *)(a2 + 5884);
  v66 = *(_DWORD *)(result + 3524);
  *(_DWORD *)(result + 6404) = v65;
  v67 = v66 + *(_DWORD *)(a2 + 3004);
  v68 = *(_DWORD *)(result + 6028);
  *(_DWORD *)(result + 3524) = v67;
  v69 = v68 + *(_DWORD *)(a2 + 5508);
  v70 = *(_DWORD *)(result + 6060);
  *(_DWORD *)(result + 6028) = v69;
  v71 = v70 + *(_DWORD *)(a2 + 5540);
  v72 = *(_DWORD *)(result + 3528);
  *(_DWORD *)(result + 6060) = v71;
  v73 = v72 + *(_DWORD *)(a2 + 3008);
  v74 = *(_DWORD *)(result + 6032);
  *(_DWORD *)(result + 3528) = v73;
  v75 = v74 + *(_DWORD *)(a2 + 5512);
  v76 = *(_DWORD *)(result + 6064);
  *(_DWORD *)(result + 6032) = v75;
  v77 = v76 + *(_DWORD *)(a2 + 5544);
  v78 = *(_DWORD *)(result + 3532);
  *(_DWORD *)(result + 6064) = v77;
  v79 = v78 + *(_DWORD *)(a2 + 3012);
  v80 = *(_DWORD *)(result + 6036);
  *(_DWORD *)(result + 3532) = v79;
  v81 = v80 + *(_DWORD *)(a2 + 5516);
  v82 = *(_DWORD *)(result + 6068);
  *(_DWORD *)(result + 6036) = v81;
  v83 = v82 + *(_DWORD *)(a2 + 5548);
  v84 = *(_DWORD *)(result + 3536);
  *(_DWORD *)(result + 6068) = v83;
  v85 = v84 + *(_DWORD *)(a2 + 3016);
  v86 = *(_DWORD *)(result + 6040);
  *(_DWORD *)(result + 3536) = v85;
  v87 = v86 + *(_DWORD *)(a2 + 5520);
  v88 = *(_DWORD *)(result + 6072);
  *(_DWORD *)(result + 6040) = v87;
  v89 = v88 + *(_DWORD *)(a2 + 5552);
  v90 = *(_DWORD *)(result + 3540);
  *(_DWORD *)(result + 6072) = v89;
  v91 = v90 + *(_DWORD *)(a2 + 3020);
  v92 = *(_DWORD *)(result + 6044);
  *(_DWORD *)(result + 3540) = v91;
  v93 = v92 + *(_DWORD *)(a2 + 5524);
  v94 = *(_DWORD *)(result + 6076);
  *(_DWORD *)(result + 6044) = v93;
  v95 = v94 + *(_DWORD *)(a2 + 5556);
  v96 = *(_DWORD *)(result + 3544);
  *(_DWORD *)(result + 6076) = v95;
  v97 = v96 + *(_DWORD *)(a2 + 3024);
  v98 = *(_DWORD *)(result + 6048);
  *(_DWORD *)(result + 3544) = v97;
  v99 = v98 + *(_DWORD *)(a2 + 5528);
  v100 = *(_DWORD *)(result + 6080);
  *(_DWORD *)(result + 6048) = v99;
  v101 = v100 + *(_DWORD *)(a2 + 5560);
  v102 = *(_DWORD *)(result + 3548);
  *(_DWORD *)(result + 6080) = v101;
  v103 = v102 + *(_DWORD *)(a2 + 3028);
  v104 = *(_DWORD *)(result + 6052);
  *(_DWORD *)(result + 3548) = v103;
  v105 = v104 + *(_DWORD *)(a2 + 5532);
  v106 = *(_DWORD *)(result + 6084);
  *(_DWORD *)(result + 6052) = v105;
  v107 = v106 + *(_DWORD *)(a2 + 5564);
  v108 = *(_DWORD *)(result + 3552);
  *(_DWORD *)(result + 6084) = v107;
  v109 = v108 + *(_DWORD *)(a2 + 3032);
  v110 = *(_DWORD *)(result + 6056);
  *(_DWORD *)(result + 3552) = v109;
  v111 = v110 + *(_DWORD *)(a2 + 5536);
  v112 = *(_DWORD *)(result + 6088);
  *(_DWORD *)(result + 6056) = v111;
  v113 = v112 + *(_DWORD *)(a2 + 5568);
  v114 = *(_DWORD *)(result + 3588);
  *(_DWORD *)(result + 6088) = v113;
  v115 = v114 + *(_DWORD *)(a2 + 3068);
  v116 = *(_QWORD *)(result + 4640);
  *(_DWORD *)(result + 3588) = v115;
  v117 = v116 + *(_QWORD *)(a2 + 4120);
  LODWORD(v116) = *(_DWORD *)(result + 5676);
  *(_QWORD *)(result + 4640) = v117;
  LODWORD(v117) = v116 + *(_DWORD *)(a2 + 5156);
  v118 = *(_QWORD *)(result + 6640);
  *(_DWORD *)(result + 5676) = v117;
  v119 = v118 + *(_QWORD *)(a2 + 6120);
  LODWORD(v118) = *(_DWORD *)(result + 3604);
  *(_QWORD *)(result + 6640) = v119;
  LODWORD(v119) = v118 + *(_DWORD *)(a2 + 3084);
  LODWORD(v118) = *(_DWORD *)(result + 3592);
  *(_DWORD *)(result + 3604) = v119;
  LODWORD(v119) = v118 + *(_DWORD *)(a2 + 3072);
  v120 = *(_QWORD *)(result + 4648);
  *(_DWORD *)(result + 3592) = v119;
  v121 = v120 + *(_QWORD *)(a2 + 4128);
  LODWORD(v120) = *(_DWORD *)(result + 5680);
  *(_QWORD *)(result + 4648) = v121;
  LODWORD(v121) = v120 + *(_DWORD *)(a2 + 5160);
  v122 = *(_QWORD *)(result + 6648);
  *(_DWORD *)(result + 5680) = v121;
  v123 = v122 + *(_QWORD *)(a2 + 6128);
  LODWORD(v122) = *(_DWORD *)(result + 3608);
  *(_QWORD *)(result + 6648) = v123;
  LODWORD(v123) = v122 + *(_DWORD *)(a2 + 3088);
  LODWORD(v122) = *(_DWORD *)(result + 3596);
  *(_DWORD *)(result + 3608) = v123;
  LODWORD(v123) = v122 + *(_DWORD *)(a2 + 3076);
  v124 = *(_QWORD *)(result + 4656);
  *(_DWORD *)(result + 3596) = v123;
  v125 = v124 + *(_QWORD *)(a2 + 4136);
  LODWORD(v124) = *(_DWORD *)(result + 5684);
  *(_QWORD *)(result + 4656) = v125;
  LODWORD(v125) = v124 + *(_DWORD *)(a2 + 5164);
  v126 = *(_QWORD *)(result + 6656);
  *(_DWORD *)(result + 5684) = v125;
  v127 = v126 + *(_QWORD *)(a2 + 6136);
  LODWORD(v126) = *(_DWORD *)(result + 3612);
  *(_QWORD *)(result + 6656) = v127;
  LODWORD(v127) = v126 + *(_DWORD *)(a2 + 3092);
  LODWORD(v126) = *(_DWORD *)(result + 3600);
  *(_DWORD *)(result + 3612) = v127;
  LODWORD(v127) = v126 + *(_DWORD *)(a2 + 3080);
  v128 = *(_QWORD *)(result + 4664);
  *(_DWORD *)(result + 3600) = v127;
  v129 = v128 + *(_QWORD *)(a2 + 4144);
  LODWORD(v128) = *(_DWORD *)(result + 5688);
  *(_QWORD *)(result + 4664) = v129;
  LODWORD(v129) = v128 + *(_DWORD *)(a2 + 5168);
  v130 = *(_QWORD *)(result + 6664);
  *(_DWORD *)(result + 5688) = v129;
  v131 = v130 + *(_QWORD *)(a2 + 6144);
  LODWORD(v130) = *(_DWORD *)(result + 3616);
  *(_QWORD *)(result + 6664) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3096);
  LODWORD(v130) = *(_DWORD *)(result + 3500);
  *(_DWORD *)(result + 3616) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 2980);
  LODWORD(v130) = *(_DWORD *)(result + 6008);
  *(_DWORD *)(result + 3500) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5488);
  LODWORD(v130) = *(_DWORD *)(result + 3504);
  *(_DWORD *)(result + 6008) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 2984);
  LODWORD(v130) = *(_DWORD *)(result + 6012);
  *(_DWORD *)(result + 3504) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5492);
  LODWORD(v130) = *(_DWORD *)(result + 3508);
  *(_DWORD *)(result + 6012) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 2988);
  LODWORD(v130) = *(_DWORD *)(result + 6016);
  *(_DWORD *)(result + 3508) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5496);
  LODWORD(v130) = *(_DWORD *)(result + 3512);
  *(_DWORD *)(result + 6016) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 2992);
  LODWORD(v130) = *(_DWORD *)(result + 6020);
  *(_DWORD *)(result + 3512) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5500);
  LODWORD(v130) = *(_DWORD *)(result + 3516);
  *(_DWORD *)(result + 6020) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 2996);
  LODWORD(v130) = *(_DWORD *)(result + 6024);
  *(_DWORD *)(result + 3516) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5504);
  LODWORD(v130) = *(_DWORD *)(result + 5692);
  *(_DWORD *)(result + 6024) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5172);
  LODWORD(v130) = *(_DWORD *)(result + 6160);
  *(_DWORD *)(result + 5692) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5640);
  LODWORD(v130) = *(_DWORD *)(result + 5696);
  *(_DWORD *)(result + 6160) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5176);
  LODWORD(v130) = *(_DWORD *)(result + 6164);
  *(_DWORD *)(result + 5696) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5644);
  LODWORD(v130) = *(_DWORD *)(result + 5700);
  *(_DWORD *)(result + 6164) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5180);
  LODWORD(v130) = *(_DWORD *)(result + 6168);
  *(_DWORD *)(result + 5700) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5648);
  LODWORD(v130) = *(_DWORD *)(result + 5704);
  *(_DWORD *)(result + 6168) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5184);
  LODWORD(v130) = *(_DWORD *)(result + 6172);
  *(_DWORD *)(result + 5704) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 5652);
  LODWORD(v130) = *(_DWORD *)(result + 3876);
  *(_DWORD *)(result + 6172) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3356);
  LODWORD(v130) = *(_DWORD *)(result + 3880);
  *(_DWORD *)(result + 3876) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3360);
  LODWORD(v130) = *(_DWORD *)(result + 3884);
  *(_DWORD *)(result + 3880) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3364);
  LODWORD(v130) = *(_DWORD *)(result + 3888);
  *(_DWORD *)(result + 3884) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3368);
  LODWORD(v130) = *(_DWORD *)(result + 3892);
  *(_DWORD *)(result + 3888) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3372);
  LODWORD(v130) = *(_DWORD *)(result + 3896);
  *(_DWORD *)(result + 3892) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3376);
  LODWORD(v130) = *(_DWORD *)(result + 3900);
  *(_DWORD *)(result + 3896) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3380);
  LODWORD(v130) = *(_DWORD *)(result + 3904);
  *(_DWORD *)(result + 3900) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3384);
  LODWORD(v130) = *(_DWORD *)(result + 3908);
  *(_DWORD *)(result + 3904) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3388);
  LODWORD(v130) = *(_DWORD *)(result + 3912);
  *(_DWORD *)(result + 3908) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3392);
  LODWORD(v130) = *(_DWORD *)(result + 3916);
  *(_DWORD *)(result + 3912) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3396);
  LODWORD(v130) = *(_DWORD *)(result + 3920);
  *(_DWORD *)(result + 3916) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3400);
  LODWORD(v130) = *(_DWORD *)(result + 3924);
  *(_DWORD *)(result + 3920) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3404);
  LODWORD(v130) = *(_DWORD *)(result + 3928);
  *(_DWORD *)(result + 3924) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3408);
  LODWORD(v130) = *(_DWORD *)(result + 3932);
  *(_DWORD *)(result + 3928) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3412);
  LODWORD(v130) = *(_DWORD *)(result + 3936);
  *(_DWORD *)(result + 3932) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3416);
  LODWORD(v130) = *(_DWORD *)(result + 3940);
  *(_DWORD *)(result + 3936) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3420);
  LODWORD(v130) = *(_DWORD *)(result + 3944);
  *(_DWORD *)(result + 3940) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3424);
  LODWORD(v130) = *(_DWORD *)(result + 3948);
  *(_DWORD *)(result + 3944) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3428);
  LODWORD(v130) = *(_DWORD *)(result + 3952);
  *(_DWORD *)(result + 3948) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3432);
  LODWORD(v130) = *(_DWORD *)(result + 3956);
  *(_DWORD *)(result + 3952) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3436);
  LODWORD(v130) = *(_DWORD *)(result + 3960);
  *(_DWORD *)(result + 3956) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3440);
  LODWORD(v130) = *(_DWORD *)(result + 3964);
  *(_DWORD *)(result + 3960) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3444);
  LODWORD(v130) = *(_DWORD *)(result + 3968);
  *(_DWORD *)(result + 3964) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3448);
  LODWORD(v130) = *(_DWORD *)(result + 3972);
  *(_DWORD *)(result + 3968) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3452);
  LODWORD(v130) = *(_DWORD *)(result + 3976);
  *(_DWORD *)(result + 3972) = v131;
  LODWORD(v131) = v130 + *(_DWORD *)(a2 + 3456);
  LODWORD(v130) = *(_DWORD *)(result + 3980);
  *(_DWORD *)(result + 3976) = v131;
  *(_DWORD *)(result + 3980) = v130 + *(_DWORD *)(a2 + 3460);
  do
  {
    *(_DWORD *)(result + 4324 + v35) += *(_DWORD *)(a2 + 3804 + v35);
    v35 += 4;
  }
  while ( v35 != 252 );
  for ( i = 0; i != 256; i += 4 )
    *(_DWORD *)(result + 3984 + i) = *(_DWORD *)(a2 + 3464 + i);
  v133 = *(_DWORD *)(result + 4252);
  *(_DWORD *)(result + 4248) += *(_DWORD *)(a2 + 3728);
  v134 = v133 + *(_DWORD *)(a2 + 3732);
  v135 = *(_DWORD *)(result + 4256);
  *(_DWORD *)(result + 4252) = v134;
  v136 = v135 + *(_DWORD *)(a2 + 3736);
  v137 = *(_DWORD *)(result + 4260);
  *(_DWORD *)(result + 4256) = v136;
  v138 = v137 + *(_DWORD *)(a2 + 3740);
  v139 = *(_DWORD *)(result + 4264);
  *(_DWORD *)(result + 4260) = v138;
  v140 = v139 + *(_DWORD *)(a2 + 3744);
  v141 = *(_DWORD *)(result + 4268);
  *(_DWORD *)(result + 4264) = v140;
  v142 = v141 + *(_DWORD *)(a2 + 3748);
  v143 = *(_DWORD *)(result + 4272);
  *(_DWORD *)(result + 4268) = v142;
  v144 = v143 + *(_DWORD *)(a2 + 3752);
  v145 = *(_DWORD *)(result + 4276);
  *(_DWORD *)(result + 4272) = v144;
  v146 = v145 + *(_DWORD *)(a2 + 3756);
  v147 = *(_DWORD *)(result + 4280);
  *(_DWORD *)(result + 4276) = v146;
  v148 = v147 + *(_DWORD *)(a2 + 3760);
  v149 = *(_DWORD *)(result + 4284);
  *(_DWORD *)(result + 4280) = v148;
  v150 = v149 + *(_DWORD *)(a2 + 3764);
  v151 = *(_DWORD *)(result + 4288);
  *(_DWORD *)(result + 4284) = v150;
  v152 = v151 + *(_DWORD *)(a2 + 3768);
  v153 = *(_DWORD *)(result + 4292);
  *(_DWORD *)(result + 4288) = v152;
  v154 = v153 + *(_DWORD *)(a2 + 3772);
  v155 = *(_DWORD *)(result + 4296);
  *(_DWORD *)(result + 4292) = v154;
  v156 = v155 + *(_DWORD *)(a2 + 3776);
  v157 = *(_DWORD *)(result + 4300);
  *(_DWORD *)(result + 4296) = v156;
  v158 = v157 + *(_DWORD *)(a2 + 3780);
  v159 = *(_DWORD *)(result + 4304);
  *(_DWORD *)(result + 4300) = v158;
  v160 = v159 + *(_DWORD *)(a2 + 3784);
  v161 = *(_DWORD *)(result + 4308);
  *(_DWORD *)(result + 4304) = v160;
  v162 = v161 + *(_DWORD *)(a2 + 3788);
  v163 = *(_DWORD *)(result + 4312);
  *(_DWORD *)(result + 4308) = v162;
  v164 = v163 + *(_DWORD *)(a2 + 3792);
  v165 = *(_DWORD *)(result + 4316);
  *(_DWORD *)(result + 4312) = v164;
  v166 = v165 + *(_DWORD *)(a2 + 3796);
  v167 = *(_DWORD *)(result + 3864);
  *(_DWORD *)(result + 4316) = v166;
  v168 = v167 + *(_DWORD *)(a2 + 3344);
  v169 = *(_DWORD *)(result + 3868);
  *(_DWORD *)(result + 3864) = v168;
  v170 = v169 + *(_DWORD *)(a2 + 3348);
  v171 = *(_DWORD *)(result + 3872);
  *(_DWORD *)(result + 3868) = v170;
  v172 = v171 + *(_DWORD *)(a2 + 3352);
  v173 = *(_DWORD *)(result + 3112);
  *(_DWORD *)(result + 3872) = v172;
  v174 = v173 + *(_DWORD *)(a2 + 2592);
  v175 = *(_DWORD *)(result + 4596);
  *(_DWORD *)(result + 3112) = v174;
  v176 = v175 + *(_DWORD *)(a2 + 4076);
  v177 = *(_DWORD *)(result + 4592);
  *(_DWORD *)(result + 4596) = v176;
  *(_QWORD *)(result + 4600) = *(_QWORD *)(a2 + 4080);
  *(_DWORD *)(result + 3124) = *(_DWORD *)(a2 + 2604);
  *(_DWORD *)(result + 3128) = *(_DWORD *)(a2 + 2608);
  *(_DWORD *)(result + 3132) = *(_DWORD *)(a2 + 2612);
  *(_DWORD *)(result + 3136) = *(_DWORD *)(a2 + 2616);
  *(_DWORD *)(result + 3140) = *(_DWORD *)(a2 + 2620);
  *(_QWORD *)(result + 3152) = *(_QWORD *)(a2 + 2632);
  *(_QWORD *)(result + 3160) = *(_QWORD *)(a2 + 2640);
  *(_WORD *)(result + 3824) = *(_WORD *)(a2 + 3304);
  *(_DWORD *)(result + 4240) = *(_DWORD *)(a2 + 3720);
  *(_DWORD *)(result + 4244) = *(_DWORD *)(a2 + 3724);
  *(_DWORD *)(result + 3168) = *(_DWORD *)(a2 + 2648);
  *(_DWORD *)(result + 3172) = *(_DWORD *)(a2 + 2652);
  v178 = v177 & 0xFFFFFFF0 | *(_DWORD *)(a2 + 4072) & 0xF;
  *(_DWORD *)(result + 4592) = v178;
  v179 = v178 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(a2 + 4072) >> 4) & 0xF));
  *(_DWORD *)(result + 4592) = v179;
  v180 = v179 & 0xFFFFF0FF | (((*(_DWORD *)(a2 + 4072) >> 8) & 0xF) << 8);
  *(_DWORD *)(result + 4592) = v180;
  v181 = v180 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(a2 + 4072)) >> 4 << 12);
  *(_DWORD *)(result + 4592) = v181;
  *(_DWORD *)(result + 4592) = v181 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(a2 + 4072)) & 0xF) << 16);
  v182 = *(_QWORD *)(result + 2992);
  *(_QWORD *)(result + 3000) += *(_QWORD *)(a2 + 2480);
  v183 = v182 + *(_QWORD *)(a2 + 2472);
  v184 = *(_QWORD *)(result + 3008);
  *(_QWORD *)(result + 2992) = v183;
  v185 = v184 + *(_QWORD *)(a2 + 2488);
  v186 = *(_QWORD *)(result + 3016);
  *(_QWORD *)(result + 3008) = v185;
  v187 = v186 + *(_QWORD *)(a2 + 2496);
  v188 = *(_QWORD *)(result + 3024);
  *(_QWORD *)(result + 3016) = v187;
  v189 = v188 + *(_QWORD *)(a2 + 2504);
  v190 = *(_QWORD *)(result + 3032);
  *(_QWORD *)(result + 3024) = v189;
  v191 = v190 + *(_QWORD *)(a2 + 2512);
  v192 = *(_QWORD *)(result + 3040);
  *(_QWORD *)(result + 3032) = v191;
  v193 = v192 + *(_QWORD *)(a2 + 2520);
  v194 = *(_QWORD *)(result + 3048);
  *(_QWORD *)(result + 3040) = v193;
  v195 = v194 + *(_QWORD *)(a2 + 2528);
  v196 = *(_QWORD *)(result + 3072);
  *(_QWORD *)(result + 3048) = v195;
  v197 = v196 + *(_QWORD *)(a2 + 2552);
  v198 = *(_QWORD *)(result + 3080);
  *(_QWORD *)(result + 3072) = v197;
  v199 = v198 + *(_QWORD *)(a2 + 2560);
  v200 = *(_QWORD *)(result + 4688);
  *(_QWORD *)(result + 3080) = v199;
  v201 = v200 + *(_QWORD *)(a2 + 4168);
  v202 = *(_QWORD *)(result + 4696);
  *(_QWORD *)(result + 4688) = v201;
  v203 = v202 + *(_QWORD *)(a2 + 4176);
  v204 = *(_QWORD *)(result + 4672);
  *(_QWORD *)(result + 4696) = v203;
  v205 = v204 + *(_QWORD *)(a2 + 4152);
  v206 = *(_QWORD *)(result + 4680);
  *(_QWORD *)(result + 4672) = v205;
  v207 = v206 + *(_QWORD *)(a2 + 4160);
  v208 = *(_QWORD *)(result + 3056);
  *(_QWORD *)(result + 4680) = v207;
  v209 = v208 + *(_QWORD *)(a2 + 2536);
  v210 = *(_QWORD *)(result + 3064);
  *(_QWORD *)(result + 3056) = v209;
  v211 = v210 + *(_QWORD *)(a2 + 2544);
  LODWORD(v210) = *(_DWORD *)(result + 3088);
  *(_QWORD *)(result + 3064) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2568);
  LODWORD(v210) = *(_DWORD *)(result + 4320);
  *(_DWORD *)(result + 3088) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 3800);
  LODWORD(v210) = *(_DWORD *)(result + 3092);
  *(_DWORD *)(result + 4320) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2572);
  LODWORD(v210) = *(_DWORD *)(result + 3096);
  *(_DWORD *)(result + 3092) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2576);
  LODWORD(v210) = *(_DWORD *)(result + 3100);
  *(_DWORD *)(result + 3096) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2580);
  LODWORD(v210) = *(_DWORD *)(result + 3104);
  *(_DWORD *)(result + 3100) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2584);
  LODWORD(v210) = *(_DWORD *)(result + 3520);
  *(_DWORD *)(result + 3104) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 3000);
  LODWORD(v210) = *(_DWORD *)(result + 3108);
  *(_DWORD *)(result + 3520) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2588);
  LODWORD(v210) = *(_DWORD *)(result + 3116);
  *(_DWORD *)(result + 3108) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2596);
  LODWORD(v210) = *(_DWORD *)(result + 3120);
  *(_DWORD *)(result + 3116) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 2600);
  LODWORD(v210) = *(_DWORD *)(result + 3832);
  *(_DWORD *)(result + 3120) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 3312);
  LODWORD(v210) = *(_DWORD *)(result + 3828);
  *(_DWORD *)(result + 3832) = v211;
  LODWORD(v211) = v210 + *(_DWORD *)(a2 + 3308);
  v212 = *(_QWORD *)(result + 3640);
  *(_DWORD *)(result + 3828) = v211;
  v213 = v212 + *(_QWORD *)(a2 + 3120);
  v214 = *(_QWORD *)(result + 3648);
  *(_QWORD *)(result + 3640) = v213;
  v215 = v214 + *(_QWORD *)(a2 + 3128);
  v216 = *(_QWORD *)(result + 3664);
  *(_QWORD *)(result + 3648) = v215;
  v217 = v216 + *(_QWORD *)(a2 + 3144);
  v218 = *(_QWORD *)(result + 3672);
  *(_QWORD *)(result + 3664) = v217;
  v219 = v218 + *(_QWORD *)(a2 + 3152);
  LODWORD(v218) = *(_DWORD *)(result + 3656);
  *(_QWORD *)(result + 3672) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3136);
  LODWORD(v218) = *(_DWORD *)(result + 3684);
  *(_DWORD *)(result + 3656) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3164);
  LODWORD(v218) = *(_DWORD *)(result + 3688);
  *(_DWORD *)(result + 3684) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3168);
  LODWORD(v218) = *(_DWORD *)(result + 3692);
  *(_DWORD *)(result + 3688) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3172);
  LODWORD(v218) = *(_DWORD *)(result + 3696);
  *(_DWORD *)(result + 3692) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3176);
  LODWORD(v218) = *(_DWORD *)(result + 3700);
  *(_DWORD *)(result + 3696) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3180);
  LODWORD(v218) = *(_DWORD *)(result + 3704);
  *(_DWORD *)(result + 3700) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3184);
  LODWORD(v218) = *(_DWORD *)(result + 3708);
  *(_DWORD *)(result + 3704) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3188);
  LODWORD(v218) = *(_DWORD *)(result + 3712);
  *(_DWORD *)(result + 3708) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3192);
  LODWORD(v218) = *(_DWORD *)(result + 3716);
  *(_DWORD *)(result + 3712) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3196);
  LODWORD(v218) = *(_DWORD *)(result + 3720);
  *(_DWORD *)(result + 3716) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3200);
  LODWORD(v218) = *(_DWORD *)(result + 3680);
  *(_DWORD *)(result + 3720) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 3160);
  LODWORD(v218) = *(_DWORD *)(result + 4708);
  *(_DWORD *)(result + 3680) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4188);
  LODWORD(v218) = *(_DWORD *)(result + 4712);
  *(_DWORD *)(result + 4708) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4192);
  LODWORD(v218) = *(_DWORD *)(result + 4716);
  *(_DWORD *)(result + 4712) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4196);
  LODWORD(v218) = *(_DWORD *)(result + 4720);
  *(_DWORD *)(result + 4716) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4200);
  LODWORD(v218) = *(_DWORD *)(result + 4724);
  *(_DWORD *)(result + 4720) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4204);
  LODWORD(v218) = *(_DWORD *)(result + 4728);
  *(_DWORD *)(result + 4724) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4208);
  LODWORD(v218) = *(_DWORD *)(result + 4732);
  *(_DWORD *)(result + 4728) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4212);
  LODWORD(v218) = *(_DWORD *)(result + 4736);
  *(_DWORD *)(result + 4732) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4216);
  LODWORD(v218) = *(_DWORD *)(result + 4740);
  *(_DWORD *)(result + 4736) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4220);
  LODWORD(v218) = *(_DWORD *)(result + 4744);
  *(_DWORD *)(result + 4740) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4224);
  LODWORD(v218) = *(_DWORD *)(result + 4748);
  *(_DWORD *)(result + 4744) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4228);
  LODWORD(v218) = *(_DWORD *)(result + 4752);
  *(_DWORD *)(result + 4748) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4232);
  LODWORD(v218) = *(_DWORD *)(result + 4756);
  *(_DWORD *)(result + 4752) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4236);
  LODWORD(v218) = *(_DWORD *)(result + 4760);
  *(_DWORD *)(result + 4756) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 4240);
  LODWORD(v218) = *(_DWORD *)(result + 5648);
  *(_DWORD *)(result + 4760) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 5128);
  LODWORD(v218) = *(_DWORD *)(result + 5652);
  *(_DWORD *)(result + 5648) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 5132);
  LODWORD(v218) = *(_DWORD *)(result + 5656);
  *(_DWORD *)(result + 5652) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 5136);
  LODWORD(v218) = *(_DWORD *)(result + 5660);
  *(_DWORD *)(result + 5656) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 5140);
  LODWORD(v218) = *(_DWORD *)(result + 5664);
  *(_DWORD *)(result + 5660) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 5144);
  LODWORD(v218) = *(_DWORD *)(result + 5668);
  *(_DWORD *)(result + 5664) = v219;
  LODWORD(v219) = v218 + *(_DWORD *)(a2 + 5148);
  LODWORD(v218) = *(_DWORD *)(result + 5672);
  *(_DWORD *)(result + 5668) = v219;
  *(_DWORD *)(result + 5672) = v218 + *(_DWORD *)(a2 + 5152);
  if ( *(_BYTE *)(a2 + 6000) )
    *(_BYTE *)(result + 6520) = *(_BYTE *)(a2 + 6000);
  *(_DWORD *)(result + 6432) = *(_DWORD *)(a2 + 5912);
  *(_DWORD *)(result + 6436) = *(_DWORD *)(a2 + 5916);
  *(_DWORD *)(result + 6440) = *(_DWORD *)(a2 + 5920);
  *(_DWORD *)(result + 6444) = *(_DWORD *)(a2 + 5924);
  *(_DWORD *)(result + 6500) = *(_DWORD *)(a2 + 5980);
  *(_DWORD *)(result + 6428) = *(_DWORD *)(a2 + 5908);
  *(_QWORD *)(result + 6512) = *(_QWORD *)(a2 + 5992);
  *(_BYTE *)(result + 6521) = *(_BYTE *)(a2 + 6001);
  v220 = *(_DWORD *)(result + 6596) & 0xFFFFFFF0 | *(_DWORD *)(a2 + 6076) & 0xF;
  *(_DWORD *)(result + 6596) = v220;
  v221 = v220 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(a2 + 6076) >> 4) & 0xF));
  *(_DWORD *)(result + 6596) = v221;
  v222 = v221 & 0xFFFFF0FF | (((*(_DWORD *)(a2 + 6076) >> 8) & 0xF) << 8);
  *(_DWORD *)(result + 6596) = v222;
  v223 = v222 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(a2 + 6076)) >> 4 << 12);
  *(_DWORD *)(result + 6596) = v223;
  *(_DWORD *)(result + 6596) = v223 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(a2 + 6076)) & 0xF) << 16);
  v224 = *(_DWORD *)(result + 6412);
  *(_DWORD *)(result + 6408) += *(_DWORD *)(a2 + 5888);
  v225 = v224 + *(_DWORD *)(a2 + 5892);
  v226 = *(_DWORD *)(result + 6416);
  *(_DWORD *)(result + 6412) = v225;
  v227 = v226 + *(_DWORD *)(a2 + 5896);
  v228 = *(_DWORD *)(result + 6420);
  *(_DWORD *)(result + 6416) = v227;
  v229 = v228 + *(_DWORD *)(a2 + 5900);
  v230 = *(_DWORD *)(result + 5544);
  *(_DWORD *)(result + 6420) = v229;
  v231 = v230 + *(_DWORD *)(a2 + 5024);
  v232 = *(_DWORD *)(result + 6620);
  *(_DWORD *)(result + 5544) = v231;
  v233 = v232 + *(_DWORD *)(a2 + 6100);
  v234 = *(_QWORD *)(result + 5288);
  *(_DWORD *)(result + 6620) = v233;
  v235 = v234 + *(_QWORD *)(a2 + 4768);
  v236 = *(_QWORD *)(result + 5296);
  *(_QWORD *)(result + 5288) = v235;
  v237 = v236 + *(_QWORD *)(a2 + 4776);
  v238 = *(_QWORD *)(result + 6672);
  *(_QWORD *)(result + 5296) = v237;
  v239 = v238 + *(_QWORD *)(a2 + 6152);
  v240 = *(_QWORD *)(result + 6680);
  *(_QWORD *)(result + 6672) = v239;
  v241 = v240 + *(_QWORD *)(a2 + 6160);
  v242 = *(_QWORD *)(result + 5304);
  *(_QWORD *)(result + 6680) = v241;
  v243 = v242 + *(_QWORD *)(a2 + 4784);
  v244 = *(_QWORD *)(result + 5312);
  *(_QWORD *)(result + 5304) = v243;
  v245 = v244 + *(_QWORD *)(a2 + 4792);
  v246 = *(_QWORD *)(result + 5320);
  *(_QWORD *)(result + 5312) = v245;
  v247 = v246 + *(_QWORD *)(a2 + 4800);
  v248 = *(_QWORD *)(result + 5328);
  *(_QWORD *)(result + 5320) = v247;
  v249 = v248 + *(_QWORD *)(a2 + 4808);
  v250 = *(_QWORD *)(result + 5336);
  *(_QWORD *)(result + 5328) = v249;
  v251 = v250 + *(_QWORD *)(a2 + 4816);
  v252 = *(_QWORD *)(result + 5344);
  *(_QWORD *)(result + 5336) = v251;
  v253 = v252 + *(_QWORD *)(a2 + 4824);
  v254 = *(_QWORD *)(result + 5352);
  *(_QWORD *)(result + 5344) = v253;
  v255 = v254 + *(_QWORD *)(a2 + 4832);
  v256 = *(_QWORD *)(result + 5360);
  *(_QWORD *)(result + 5352) = v255;
  v257 = v256 + *(_QWORD *)(a2 + 4840);
  v258 = *(_QWORD *)(result + 5368);
  *(_QWORD *)(result + 5360) = v257;
  v259 = v258 + *(_QWORD *)(a2 + 4848);
  v260 = *(_QWORD *)(result + 5376);
  *(_QWORD *)(result + 5368) = v259;
  v261 = v260 + *(_QWORD *)(a2 + 4856);
  v262 = *(_QWORD *)(result + 5384);
  *(_QWORD *)(result + 5376) = v261;
  v263 = v262 + *(_QWORD *)(a2 + 4864);
  v264 = *(_QWORD *)(result + 5392);
  *(_QWORD *)(result + 5384) = v263;
  v265 = v264 + *(_QWORD *)(a2 + 4872);
  v266 = *(_QWORD *)(result + 5400);
  *(_QWORD *)(result + 5392) = v265;
  v267 = v266 + *(_QWORD *)(a2 + 4880);
  v268 = *(_QWORD *)(result + 5408);
  *(_QWORD *)(result + 5400) = v267;
  v269 = v268 + *(_QWORD *)(a2 + 4888);
  v270 = *(_QWORD *)(result + 5416);
  *(_QWORD *)(result + 5408) = v269;
  v271 = v270 + *(_QWORD *)(a2 + 4896);
  v272 = *(_QWORD *)(result + 5424);
  *(_QWORD *)(result + 5416) = v271;
  v273 = v272 + *(_QWORD *)(a2 + 4904);
  v274 = *(_QWORD *)(result + 5448);
  *(_QWORD *)(result + 5424) = v273;
  v275 = v274 + *(_QWORD *)(a2 + 4928);
  v276 = *(_QWORD *)(result + 5456);
  *(_QWORD *)(result + 5448) = v275;
  v277 = v276 + *(_QWORD *)(a2 + 4936);
  v278 = *(_QWORD *)(result + 5464);
  *(_QWORD *)(result + 5456) = v277;
  v279 = v278 + *(_QWORD *)(a2 + 4944);
  v280 = *(_QWORD *)(result + 5472);
  *(_QWORD *)(result + 5464) = v279;
  *(_QWORD *)(result + 5472) = v280 + *(_QWORD *)(a2 + 4952);
  v281 = *(_QWORD *)(a2 + 4768);
  v282 = *(_QWORD *)(a2 + 4976);
  v283 = v281 >= v282;
  v284 = v281 - v282;
  if ( v283 )
    *(_QWORD *)(a2 + 4960) = v284;
  v285 = *(_QWORD *)(a2 + 4776);
  v286 = *(_QWORD *)(a2 + 4984);
  v283 = v285 >= v286;
  v287 = v285 - v286;
  if ( v283 )
    *(_QWORD *)(a2 + 4968) = v287;
  v288 = 0;
  *(_QWORD *)(result + 5480) += *(_QWORD *)(a2 + 4960);
  *(_QWORD *)(result + 5488) += *(_QWORD *)(a2 + 4968);
  *(_QWORD *)(result + 5496) += *(_QWORD *)(a2 + 4976);
  *(_QWORD *)(result + 5504) += *(_QWORD *)(a2 + 4984);
  *(_QWORD *)(result + 5512) += *(_QWORD *)(a2 + 4992);
  *(_QWORD *)(result + 5520) += *(_QWORD *)(a2 + 5000);
  *(_QWORD *)(result + 5528) += *(_QWORD *)(a2 + 5008);
  *(_QWORD *)(result + 5536) += *(_QWORD *)(a2 + 5016);
  *(_QWORD *)(result + 5608) += *(_QWORD *)(a2 + 5088);
  *(_DWORD *)(result + 6704) += *(_DWORD *)(a2 + 6184);
  *(_QWORD *)(result + 5616) += *(_QWORD *)(a2 + 5096);
  *(_QWORD *)(result + 5624) += *(_QWORD *)(a2 + 5104);
  *(_QWORD *)(result + 5632) += *(_QWORD *)(a2 + 5112);
  *(_DWORD *)(result + 3168) = *(_DWORD *)(a2 + 2648);
  *(_DWORD *)(result + 3172) = *(_DWORD *)(a2 + 2652);
  *(_QWORD *)(result + 5552) += *(_QWORD *)(a2 + 5032);
  *(_QWORD *)(result + 5560) += *(_QWORD *)(a2 + 5040);
  *(_QWORD *)(result + 5568) += *(_QWORD *)(a2 + 5048);
  *(_QWORD *)(result + 5576) += *(_QWORD *)(a2 + 5056);
  *(_DWORD *)(result + 6524) += *(_DWORD *)(a2 + 6004);
  *(_DWORD *)(result + 6528) += *(_DWORD *)(a2 + 6008);
  *(_DWORD *)(result + 6532) += *(_DWORD *)(a2 + 6012);
  v289 = 1;
  do
  {
    v290 = 100 * v288;
    v291 = (_DWORD *)(a2 + 5656 + v290);
    v292 = (_DWORD *)(result + 6176 + v290);
    v293 = v292[9];
    v292[8] += v291[8];
    v292[9] = v293 + v291[9];
    v294 = v292[1];
    *v292 += *v291;
    v292[1] = v294 + v291[1];
    v295 = v292[3];
    v292[2] += v291[2];
    v292[3] = v295 + v291[3];
    v296 = v292[5];
    v292[4] += v291[4];
    v292[5] = v296 + v291[5];
    v297 = v292[7];
    v292[6] += v291[6];
    v292[7] = v297 + v291[7];
    v298 = v292[11];
    v292[10] += v291[10];
    v292[11] = v298 + v291[11];
    v299 = v292[13];
    v292[12] += v291[12];
    v292[13] = v299 + v291[13];
    v300 = v292[15];
    v292[14] += v291[14];
    v292[15] = v300 + v291[15];
    v301 = v292[17];
    v292[16] += v291[16];
    v292[17] = v301 + v291[17];
    v302 = v292[19];
    v292[18] += v291[18];
    v292[19] = v302 + v291[19];
    v303 = v292[21];
    v292[20] += v291[20];
    v292[21] = v303 + v291[21];
    v304 = v292[23];
    v305 = v289;
    v292[22] += v291[22];
    v292[23] = v304 + v291[23];
    v292[24] += v291[24];
    v288 = 1;
    v289 = 0;
  }
  while ( (v305 & 1) != 0 );
  v306 = *(_DWORD *)(result + 6536);
  *(_DWORD *)(result + 6100) += *(_DWORD *)(a2 + 5580);
  v307 = v306 + *(_DWORD *)(a2 + 6016);
  v308 = *(_DWORD *)(result + 6104);
  *(_DWORD *)(result + 6536) = v307;
  v309 = v308 + *(_DWORD *)(a2 + 5584);
  v310 = *(_DWORD *)(result + 6540);
  *(_DWORD *)(result + 6104) = v309;
  v311 = v310 + *(_DWORD *)(a2 + 6020);
  v312 = *(_DWORD *)(result + 6108);
  *(_DWORD *)(result + 6540) = v311;
  v313 = v312 + *(_DWORD *)(a2 + 5588);
  v314 = *(_DWORD *)(result + 6544);
  *(_DWORD *)(result + 6108) = v313;
  v315 = v314 + *(_DWORD *)(a2 + 6024);
  v316 = *(_DWORD *)(result + 6112);
  *(_DWORD *)(result + 6544) = v315;
  v317 = v316 + *(_DWORD *)(a2 + 5592);
  v318 = *(_DWORD *)(result + 6548);
  *(_DWORD *)(result + 6112) = v317;
  v319 = v318 + *(_DWORD *)(a2 + 6028);
  v320 = *(_DWORD *)(result + 6116);
  *(_DWORD *)(result + 6548) = v319;
  v321 = v320 + *(_DWORD *)(a2 + 5596);
  v322 = *(_DWORD *)(result + 6552);
  *(_DWORD *)(result + 6116) = v321;
  v323 = v322 + *(_DWORD *)(a2 + 6032);
  v324 = *(_DWORD *)(result + 6120);
  *(_DWORD *)(result + 6552) = v323;
  v325 = v324 + *(_DWORD *)(a2 + 5600);
  v326 = *(_DWORD *)(result + 6556);
  *(_DWORD *)(result + 6120) = v325;
  v327 = v326 + *(_DWORD *)(a2 + 6036);
  v328 = *(_DWORD *)(result + 6124);
  *(_DWORD *)(result + 6556) = v327;
  v329 = v328 + *(_DWORD *)(a2 + 5604);
  v330 = *(_DWORD *)(result + 6560);
  *(_DWORD *)(result + 6124) = v329;
  v331 = v330 + *(_DWORD *)(a2 + 6040);
  v332 = *(_DWORD *)(result + 6128);
  *(_DWORD *)(result + 6560) = v331;
  v333 = v332 + *(_DWORD *)(a2 + 5608);
  v334 = *(_DWORD *)(result + 6564);
  *(_DWORD *)(result + 6128) = v333;
  v335 = v334 + *(_DWORD *)(a2 + 6044);
  v336 = *(_DWORD *)(result + 6132);
  *(_DWORD *)(result + 6564) = v335;
  v337 = v336 + *(_DWORD *)(a2 + 5612);
  v338 = *(_DWORD *)(result + 6568);
  *(_DWORD *)(result + 6132) = v337;
  v339 = v338 + *(_DWORD *)(a2 + 6048);
  v340 = *(_DWORD *)(result + 6136);
  *(_DWORD *)(result + 6568) = v339;
  v341 = v340 + *(_DWORD *)(a2 + 5616);
  v342 = *(_DWORD *)(result + 6572);
  *(_DWORD *)(result + 6136) = v341;
  v343 = v342 + *(_DWORD *)(a2 + 6052);
  v344 = *(_DWORD *)(result + 6140);
  *(_DWORD *)(result + 6572) = v343;
  v345 = v344 + *(_DWORD *)(a2 + 5620);
  v346 = *(_DWORD *)(result + 6576);
  *(_DWORD *)(result + 6140) = v345;
  v347 = v346 + *(_DWORD *)(a2 + 6056);
  v348 = *(_DWORD *)(result + 6144);
  *(_DWORD *)(result + 6576) = v347;
  v349 = v348 + *(_DWORD *)(a2 + 5624);
  v350 = *(_DWORD *)(result + 6580);
  *(_DWORD *)(result + 6144) = v349;
  v351 = v350 + *(_DWORD *)(a2 + 6060);
  v352 = *(_DWORD *)(result + 6148);
  *(_DWORD *)(result + 6580) = v351;
  v353 = v352 + *(_DWORD *)(a2 + 5628);
  v354 = *(_DWORD *)(result + 6584);
  *(_DWORD *)(result + 6148) = v353;
  v355 = v354 + *(_DWORD *)(a2 + 6064);
  v356 = *(_DWORD *)(result + 6152);
  *(_DWORD *)(result + 6584) = v355;
  v357 = v356 + *(_DWORD *)(a2 + 5632);
  v358 = *(_DWORD *)(result + 6588);
  *(_DWORD *)(result + 6152) = v357;
  v359 = v358 + *(_DWORD *)(a2 + 6068);
  v360 = *(_DWORD *)(result + 6156);
  *(_DWORD *)(result + 6588) = v359;
  v361 = v360 + *(_DWORD *)(a2 + 5636);
  v362 = *(_DWORD *)(result + 6592);
  *(_DWORD *)(result + 6156) = v361;
  v363 = v362 + *(_DWORD *)(a2 + 6072);
  v364 = *(_DWORD *)(result + 6092);
  *(_DWORD *)(result + 6592) = v363;
  v365 = v364 + *(_DWORD *)(a2 + 5572);
  v366 = *(_DWORD *)(result + 6096);
  *(_DWORD *)(result + 6092) = v365;
  v367 = v366 + *(_DWORD *)(a2 + 5576);
  v368 = *(_DWORD *)(result + 6484);
  *(_DWORD *)(result + 6096) = v367;
  v369 = v368 + *(_DWORD *)(a2 + 5964);
  v370 = *(_DWORD *)(result + 6488);
  *(_DWORD *)(result + 6484) = v369;
  v371 = v370 + *(_DWORD *)(a2 + 5968);
  v372 = *(_DWORD *)(result + 6616);
  *(_DWORD *)(result + 6488) = v371;
  v373 = v372 + *(_DWORD *)(a2 + 6096);
  v374 = *(_DWORD *)(result + 6480);
  *(_DWORD *)(result + 6616) = v373;
  *(_DWORD *)(result + 6480) = v374 + *(_DWORD *)(a2 + 5960);
  return result;
}
