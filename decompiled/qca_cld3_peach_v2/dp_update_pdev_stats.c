__int64 __fastcall dp_update_pdev_stats(__int64 result, __int64 a2)
{
  __int64 i; // x10
  __int64 v3; // x12
  _DWORD *v4; // x13
  __int64 j; // x10
  __int64 v6; // x12
  _DWORD *v7; // x13
  __int64 k; // x10
  __int64 v9; // x12
  _DWORD *v10; // x13
  __int64 m; // x10
  __int64 v12; // x12
  _DWORD *v13; // x13
  __int64 n; // x10
  __int64 v15; // x12
  _DWORD *v16; // x13
  __int64 ii; // x10
  _DWORD *v18; // x13
  _DWORD *v19; // x14
  __int64 v20; // x10
  int v21; // w12
  int v22; // w11
  int v23; // w12
  int v24; // w11
  int v25; // w12
  int v26; // w11
  int v27; // w12
  int v28; // w11
  int v29; // w12
  int v30; // w11
  int v31; // w12
  int v32; // w11
  int v33; // w12
  int v34; // w11
  int v35; // w12
  int v36; // w11
  int v37; // w12
  int v38; // w11
  int v39; // w12
  int v40; // w11
  int v41; // w12
  int v42; // w11
  int v43; // w12
  int v44; // w11
  int v45; // w12
  int v46; // w11
  int v47; // w12
  int v48; // w11
  int v49; // w12
  int v50; // w11
  int v51; // w12
  int v52; // w11
  int v53; // w12
  int v54; // w11
  int v55; // w12
  int v56; // w11
  int v57; // w12
  int v58; // w11
  int v59; // w12
  int v60; // w11
  int v61; // w12
  int v62; // w11
  int v63; // w12
  int v64; // w11
  int v65; // w12
  int v66; // w11
  int v67; // w12
  int v68; // w11
  int v69; // w12
  int v70; // w11
  int v71; // w12
  int v72; // w11
  int v73; // w12
  int v74; // w11
  int v75; // w12
  int v76; // w11
  int v77; // w12
  int v78; // w11
  int v79; // w12
  int v80; // w11
  int v81; // w12
  int v82; // w11
  int v83; // w12
  int v84; // w11
  int v85; // w12
  int v86; // w11
  int v87; // w12
  int v88; // w11
  int v89; // w12
  int v90; // w11
  int v91; // w12
  int v92; // w11
  int v93; // w12
  int v94; // w11
  int v95; // w12
  int v96; // w11
  int v97; // w12
  int v98; // w11
  int v99; // w12
  int v100; // w11
  __int64 v101; // x12
  __int64 v102; // x11
  __int64 v103; // x12
  __int64 v104; // x11
  __int64 v105; // x12
  __int64 v106; // x11
  __int64 v107; // x12
  __int64 v108; // x11
  __int64 v109; // x12
  __int64 v110; // x11
  __int64 v111; // x12
  __int64 v112; // x11
  __int64 v113; // x12
  __int64 v114; // x11
  __int64 v115; // x12
  __int64 v116; // x11
  __int64 jj; // x10
  __int64 v118; // x10
  _DWORD *v119; // x14
  _DWORD *v120; // x13
  int v121; // w17
  int v122; // w11
  int v123; // w10
  int v124; // w11
  int v125; // w10
  int v126; // w11
  int v127; // w10
  int v128; // w11
  int v129; // w10
  int v130; // w11
  unsigned int v131; // w11
  unsigned int v132; // w11
  unsigned int v133; // w11
  unsigned int v134; // w11
  __int64 v135; // x11
  __int64 v136; // x10
  __int64 v137; // x11
  __int64 v138; // x10
  __int64 v139; // x11
  __int64 v140; // x10
  __int64 v141; // x11
  __int64 v142; // x10
  __int64 v143; // x11
  __int64 v144; // x10
  __int64 v145; // x11
  __int64 v146; // x10
  __int64 v147; // x11
  __int64 v148; // x10
  __int64 v149; // x11
  __int64 v150; // x10
  __int64 v151; // x11
  __int64 v152; // x10
  __int64 v153; // x11
  __int64 v154; // x10
  __int64 v155; // x11
  __int64 v156; // x10
  __int64 v157; // x11
  __int64 v158; // x10
  __int64 v159; // x11
  __int64 v160; // x10
  __int64 v161; // x11
  __int64 v162; // x10
  __int64 v163; // x11
  __int64 v164; // x10
  __int64 v165; // x11
  __int64 v166; // x10
  __int64 v167; // x11
  __int64 v168; // x10
  __int64 v169; // x11
  __int64 v170; // x10
  __int64 v171; // x11
  __int64 v172; // x10
  unsigned int v173; // w9
  unsigned int v174; // w9
  unsigned int v175; // w9
  unsigned int v176; // w9
  int v177; // w9
  int v178; // w8
  int v179; // w9
  int v180; // w8
  int v181; // w9
  int v182; // w8
  int v183; // w9
  int v184; // w8
  int v185; // w9
  int v186; // w8
  __int64 v187; // x9
  __int64 v188; // x8
  __int64 v189; // x9
  __int64 v190; // x8
  __int64 v191; // x9
  __int64 v192; // x8
  __int64 v193; // x9
  __int64 v194; // x8
  __int64 v195; // x9
  __int64 v196; // x8
  __int64 v197; // x9
  __int64 v198; // x8
  __int64 v199; // x9
  __int64 v200; // x8
  __int64 v201; // x9
  __int64 v202; // x8
  __int64 v203; // x9
  __int64 v204; // x8
  __int64 v205; // x9
  __int64 v206; // x8
  __int64 v207; // x9
  __int64 v208; // x8
  __int64 v209; // x9
  __int64 v210; // x8
  __int64 v211; // x9
  __int64 v212; // x8
  __int64 v213; // x9
  __int64 v214; // x8
  __int64 v215; // x9
  __int64 v216; // x8
  __int64 v217; // x9
  __int64 v218; // x8
  __int64 v219; // x9
  __int64 v220; // x8
  __int64 v221; // x9
  __int64 v222; // x8
  __int64 v223; // x9
  __int64 v224; // x8
  __int64 v225; // x9
  __int64 v226; // x8
  __int64 v227; // x9
  __int64 v228; // x8
  __int64 v229; // x9
  __int64 v230; // x8
  __int64 v231; // x9
  __int64 v232; // x8
  __int64 v233; // x9
  unsigned __int64 v234; // x8
  unsigned __int64 v235; // x9
  bool v236; // cf
  unsigned __int64 v237; // x8
  unsigned __int64 v238; // x8
  unsigned __int64 v239; // x9
  unsigned __int64 v240; // x8
  __int64 v241; // x12
  char v242; // w11
  __int64 v243; // x12
  _DWORD *v244; // x13
  _DWORD *v245; // x12
  int v246; // w16
  int v247; // w16
  int v248; // w16
  int v249; // w16
  int v250; // w16
  int v251; // w16
  int v252; // w16
  int v253; // w16
  int v254; // w16
  int v255; // w16
  int v256; // w16
  int v257; // w16
  int v258; // w16
  char v259; // w15
  __int64 kk; // x8
  _DWORD *v261; // x11
  _DWORD *v262; // x12
  __int64 v263; // x8
  int v264; // w10
  int v265; // w9
  int v266; // w10
  int v267; // w9
  int v268; // w10
  int v269; // w9
  int v270; // w10
  int v271; // w9
  int v272; // w10
  _DWORD *v273; // x11
  _DWORD *v274; // x12
  __int64 mm; // x8
  _DWORD *v276; // x11
  _DWORD *v277; // x12
  __int64 nn; // x8
  _DWORD *v279; // x11
  _DWORD *v280; // x12
  int v281; // w9
  int v282; // w8
  int v283; // w9
  int v284; // w8
  int v285; // w9
  int v286; // w8
  int v287; // w9
  int v288; // w8
  int v289; // w9
  int v290; // w8
  int v291; // w9
  int v292; // w8
  int v293; // w9
  int v294; // w8
  int v295; // w9
  int v296; // w8
  int v297; // w9

  for ( i = 0; i != 68; i += 4 )
  {
    v3 = a2 + i;
    v4 = (_DWORD *)(result + 3200 + i);
    *v4 += *(_DWORD *)(v3 + 2680);
    v4[739] += *(_DWORD *)(v3 + 5636);
  }
  for ( j = 0; j != 68; j += 4 )
  {
    v6 = a2 + j;
    v7 = (_DWORD *)(result + 3268 + j);
    *v7 += *(_DWORD *)(v6 + 2748);
    v7[739] += *(_DWORD *)(v6 + 5704);
  }
  for ( k = 0; k != 68; k += 4 )
  {
    v9 = a2 + k;
    v10 = (_DWORD *)(result + 3336 + k);
    *v10 += *(_DWORD *)(v9 + 2816);
    v10[739] += *(_DWORD *)(v9 + 5772);
  }
  for ( m = 0; m != 68; m += 4 )
  {
    v12 = a2 + m;
    v13 = (_DWORD *)(result + 3404 + m);
    *v13 += *(_DWORD *)(v12 + 2884);
    v13[739] += *(_DWORD *)(v12 + 5840);
  }
  for ( n = 0; n != 68; n += 4 )
  {
    v15 = a2 + n;
    v16 = (_DWORD *)(result + 3472 + n);
    *v16 += *(_DWORD *)(v15 + 2952);
    v16[739] += *(_DWORD *)(v15 + 5908);
  }
  for ( ii = 0; ii != 68; ii += 4 )
  {
    v18 = (_DWORD *)(a2 + 3020 + ii);
    v19 = (_DWORD *)(result + 3540 + ii);
    *v19 += *v18;
    v19[739] += v18[739];
  }
  v20 = 0;
  v21 = *(_DWORD *)(result + 6956);
  *(_DWORD *)(result + 3664) += *(_DWORD *)(a2 + 3144);
  v22 = v21 + *(_DWORD *)(a2 + 6436);
  v23 = *(_DWORD *)(result + 3668);
  *(_DWORD *)(result + 6956) = v22;
  v24 = v23 + *(_DWORD *)(a2 + 3148);
  v25 = *(_DWORD *)(result + 6960);
  *(_DWORD *)(result + 3668) = v24;
  v26 = v25 + *(_DWORD *)(a2 + 6440);
  v27 = *(_DWORD *)(result + 3672);
  *(_DWORD *)(result + 6960) = v26;
  v28 = v27 + *(_DWORD *)(a2 + 3152);
  v29 = *(_DWORD *)(result + 6964);
  *(_DWORD *)(result + 3672) = v28;
  v30 = v29 + *(_DWORD *)(a2 + 6444);
  v31 = *(_DWORD *)(result + 3676);
  *(_DWORD *)(result + 6964) = v30;
  v32 = v31 + *(_DWORD *)(a2 + 3156);
  v33 = *(_DWORD *)(result + 6968);
  *(_DWORD *)(result + 3676) = v32;
  v34 = v33 + *(_DWORD *)(a2 + 6448);
  v35 = *(_DWORD *)(result + 3680);
  *(_DWORD *)(result + 6968) = v34;
  v36 = v35 + *(_DWORD *)(a2 + 3160);
  v37 = *(_DWORD *)(result + 6972);
  *(_DWORD *)(result + 3680) = v36;
  v38 = v37 + *(_DWORD *)(a2 + 6452);
  v39 = *(_DWORD *)(result + 3684);
  *(_DWORD *)(result + 6972) = v38;
  v40 = v39 + *(_DWORD *)(a2 + 3164);
  v41 = *(_DWORD *)(result + 6976);
  *(_DWORD *)(result + 3684) = v40;
  v42 = v41 + *(_DWORD *)(a2 + 6456);
  v43 = *(_DWORD *)(result + 3688);
  *(_DWORD *)(result + 6976) = v42;
  v44 = v43 + *(_DWORD *)(a2 + 3168);
  v45 = *(_DWORD *)(result + 6980);
  *(_DWORD *)(result + 3688) = v44;
  v46 = v45 + *(_DWORD *)(a2 + 6460);
  v47 = *(_DWORD *)(result + 3692);
  *(_DWORD *)(result + 6980) = v46;
  v48 = v47 + *(_DWORD *)(a2 + 3172);
  v49 = *(_DWORD *)(result + 6984);
  *(_DWORD *)(result + 3692) = v48;
  v50 = v49 + *(_DWORD *)(a2 + 6464);
  v51 = *(_DWORD *)(result + 3632);
  *(_DWORD *)(result + 6984) = v50;
  v52 = v51 + *(_DWORD *)(a2 + 3112);
  v53 = *(_DWORD *)(result + 6584);
  *(_DWORD *)(result + 3632) = v52;
  v54 = v53 + *(_DWORD *)(a2 + 6064);
  v55 = *(_DWORD *)(result + 6616);
  *(_DWORD *)(result + 6584) = v54;
  v56 = v55 + *(_DWORD *)(a2 + 6096);
  v57 = *(_DWORD *)(result + 3636);
  *(_DWORD *)(result + 6616) = v56;
  v58 = v57 + *(_DWORD *)(a2 + 3116);
  v59 = *(_DWORD *)(result + 6588);
  *(_DWORD *)(result + 3636) = v58;
  v60 = v59 + *(_DWORD *)(a2 + 6068);
  v61 = *(_DWORD *)(result + 6620);
  *(_DWORD *)(result + 6588) = v60;
  v62 = v61 + *(_DWORD *)(a2 + 6100);
  v63 = *(_DWORD *)(result + 3640);
  *(_DWORD *)(result + 6620) = v62;
  v64 = v63 + *(_DWORD *)(a2 + 3120);
  v65 = *(_DWORD *)(result + 6592);
  *(_DWORD *)(result + 3640) = v64;
  v66 = v65 + *(_DWORD *)(a2 + 6072);
  v67 = *(_DWORD *)(result + 6624);
  *(_DWORD *)(result + 6592) = v66;
  v68 = v67 + *(_DWORD *)(a2 + 6104);
  v69 = *(_DWORD *)(result + 3644);
  *(_DWORD *)(result + 6624) = v68;
  v70 = v69 + *(_DWORD *)(a2 + 3124);
  v71 = *(_DWORD *)(result + 6596);
  *(_DWORD *)(result + 3644) = v70;
  v72 = v71 + *(_DWORD *)(a2 + 6076);
  v73 = *(_DWORD *)(result + 6628);
  *(_DWORD *)(result + 6596) = v72;
  v74 = v73 + *(_DWORD *)(a2 + 6108);
  v75 = *(_DWORD *)(result + 3648);
  *(_DWORD *)(result + 6628) = v74;
  v76 = v75 + *(_DWORD *)(a2 + 3128);
  v77 = *(_DWORD *)(result + 6600);
  *(_DWORD *)(result + 3648) = v76;
  v78 = v77 + *(_DWORD *)(a2 + 6080);
  v79 = *(_DWORD *)(result + 6632);
  *(_DWORD *)(result + 6600) = v78;
  v80 = v79 + *(_DWORD *)(a2 + 6112);
  v81 = *(_DWORD *)(result + 3652);
  *(_DWORD *)(result + 6632) = v80;
  v82 = v81 + *(_DWORD *)(a2 + 3132);
  v83 = *(_DWORD *)(result + 6604);
  *(_DWORD *)(result + 3652) = v82;
  v84 = v83 + *(_DWORD *)(a2 + 6084);
  v85 = *(_DWORD *)(result + 6636);
  *(_DWORD *)(result + 6604) = v84;
  v86 = v85 + *(_DWORD *)(a2 + 6116);
  v87 = *(_DWORD *)(result + 3656);
  *(_DWORD *)(result + 6636) = v86;
  v88 = v87 + *(_DWORD *)(a2 + 3136);
  v89 = *(_DWORD *)(result + 6608);
  *(_DWORD *)(result + 3656) = v88;
  v90 = v89 + *(_DWORD *)(a2 + 6088);
  v91 = *(_DWORD *)(result + 6640);
  *(_DWORD *)(result + 6608) = v90;
  v92 = v91 + *(_DWORD *)(a2 + 6120);
  v93 = *(_DWORD *)(result + 3660);
  *(_DWORD *)(result + 6640) = v92;
  v94 = v93 + *(_DWORD *)(a2 + 3140);
  v95 = *(_DWORD *)(result + 6612);
  *(_DWORD *)(result + 3660) = v94;
  v96 = v95 + *(_DWORD *)(a2 + 6092);
  v97 = *(_DWORD *)(result + 6644);
  *(_DWORD *)(result + 6612) = v96;
  v98 = v97 + *(_DWORD *)(a2 + 6124);
  v99 = *(_DWORD *)(result + 3696);
  *(_DWORD *)(result + 6644) = v98;
  v100 = v99 + *(_DWORD *)(a2 + 3176);
  v101 = *(_QWORD *)(result + 5088);
  *(_DWORD *)(result + 3696) = v100;
  v102 = v101 + *(_QWORD *)(a2 + 4568);
  LODWORD(v101) = *(_DWORD *)(result + 6124);
  *(_QWORD *)(result + 5088) = v102;
  LODWORD(v102) = v101 + *(_DWORD *)(a2 + 5604);
  v103 = *(_QWORD *)(result + 7456);
  *(_DWORD *)(result + 6124) = v102;
  v104 = v103 + *(_QWORD *)(a2 + 6936);
  LODWORD(v103) = *(_DWORD *)(result + 3712);
  *(_QWORD *)(result + 7456) = v104;
  LODWORD(v104) = v103 + *(_DWORD *)(a2 + 3192);
  LODWORD(v103) = *(_DWORD *)(result + 3700);
  *(_DWORD *)(result + 3712) = v104;
  LODWORD(v104) = v103 + *(_DWORD *)(a2 + 3180);
  v105 = *(_QWORD *)(result + 5096);
  *(_DWORD *)(result + 3700) = v104;
  v106 = v105 + *(_QWORD *)(a2 + 4576);
  LODWORD(v105) = *(_DWORD *)(result + 6128);
  *(_QWORD *)(result + 5096) = v106;
  LODWORD(v106) = v105 + *(_DWORD *)(a2 + 5608);
  v107 = *(_QWORD *)(result + 7464);
  *(_DWORD *)(result + 6128) = v106;
  v108 = v107 + *(_QWORD *)(a2 + 6944);
  LODWORD(v107) = *(_DWORD *)(result + 3716);
  *(_QWORD *)(result + 7464) = v108;
  LODWORD(v108) = v107 + *(_DWORD *)(a2 + 3196);
  LODWORD(v107) = *(_DWORD *)(result + 3704);
  *(_DWORD *)(result + 3716) = v108;
  LODWORD(v108) = v107 + *(_DWORD *)(a2 + 3184);
  v109 = *(_QWORD *)(result + 5104);
  *(_DWORD *)(result + 3704) = v108;
  v110 = v109 + *(_QWORD *)(a2 + 4584);
  LODWORD(v109) = *(_DWORD *)(result + 6132);
  *(_QWORD *)(result + 5104) = v110;
  LODWORD(v110) = v109 + *(_DWORD *)(a2 + 5612);
  v111 = *(_QWORD *)(result + 7472);
  *(_DWORD *)(result + 6132) = v110;
  v112 = v111 + *(_QWORD *)(a2 + 6952);
  LODWORD(v111) = *(_DWORD *)(result + 3720);
  *(_QWORD *)(result + 7472) = v112;
  LODWORD(v112) = v111 + *(_DWORD *)(a2 + 3200);
  LODWORD(v111) = *(_DWORD *)(result + 3708);
  *(_DWORD *)(result + 3720) = v112;
  LODWORD(v112) = v111 + *(_DWORD *)(a2 + 3188);
  v113 = *(_QWORD *)(result + 5112);
  *(_DWORD *)(result + 3708) = v112;
  v114 = v113 + *(_QWORD *)(a2 + 4592);
  LODWORD(v113) = *(_DWORD *)(result + 6136);
  *(_QWORD *)(result + 5112) = v114;
  LODWORD(v114) = v113 + *(_DWORD *)(a2 + 5616);
  v115 = *(_QWORD *)(result + 7480);
  *(_DWORD *)(result + 6136) = v114;
  v116 = v115 + *(_QWORD *)(a2 + 6960);
  LODWORD(v115) = *(_DWORD *)(result + 3724);
  *(_QWORD *)(result + 7480) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3204);
  LODWORD(v115) = *(_DWORD *)(result + 3608);
  *(_DWORD *)(result + 3724) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3088);
  LODWORD(v115) = *(_DWORD *)(result + 6564);
  *(_DWORD *)(result + 3608) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6044);
  LODWORD(v115) = *(_DWORD *)(result + 3612);
  *(_DWORD *)(result + 6564) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3092);
  LODWORD(v115) = *(_DWORD *)(result + 6568);
  *(_DWORD *)(result + 3612) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6048);
  LODWORD(v115) = *(_DWORD *)(result + 3616);
  *(_DWORD *)(result + 6568) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3096);
  LODWORD(v115) = *(_DWORD *)(result + 6572);
  *(_DWORD *)(result + 3616) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6052);
  LODWORD(v115) = *(_DWORD *)(result + 3620);
  *(_DWORD *)(result + 6572) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3100);
  LODWORD(v115) = *(_DWORD *)(result + 6576);
  *(_DWORD *)(result + 3620) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6056);
  LODWORD(v115) = *(_DWORD *)(result + 3624);
  *(_DWORD *)(result + 6576) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3104);
  LODWORD(v115) = *(_DWORD *)(result + 6580);
  *(_DWORD *)(result + 3624) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6060);
  LODWORD(v115) = *(_DWORD *)(result + 6140);
  *(_DWORD *)(result + 6580) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 5620);
  LODWORD(v115) = *(_DWORD *)(result + 6724);
  *(_DWORD *)(result + 6140) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6204);
  LODWORD(v115) = *(_DWORD *)(result + 6144);
  *(_DWORD *)(result + 6724) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 5624);
  LODWORD(v115) = *(_DWORD *)(result + 6728);
  *(_DWORD *)(result + 6144) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6208);
  LODWORD(v115) = *(_DWORD *)(result + 6148);
  *(_DWORD *)(result + 6728) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 5628);
  LODWORD(v115) = *(_DWORD *)(result + 6732);
  *(_DWORD *)(result + 6148) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6212);
  LODWORD(v115) = *(_DWORD *)(result + 6152);
  *(_DWORD *)(result + 6732) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 5632);
  LODWORD(v115) = *(_DWORD *)(result + 6736);
  *(_DWORD *)(result + 6152) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 6216);
  LODWORD(v115) = *(_DWORD *)(result + 3980);
  *(_DWORD *)(result + 6736) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3460);
  LODWORD(v115) = *(_DWORD *)(result + 3984);
  *(_DWORD *)(result + 3980) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3464);
  LODWORD(v115) = *(_DWORD *)(result + 3988);
  *(_DWORD *)(result + 3984) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3468);
  LODWORD(v115) = *(_DWORD *)(result + 3992);
  *(_DWORD *)(result + 3988) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3472);
  LODWORD(v115) = *(_DWORD *)(result + 3996);
  *(_DWORD *)(result + 3992) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3476);
  LODWORD(v115) = *(_DWORD *)(result + 4000);
  *(_DWORD *)(result + 3996) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3480);
  LODWORD(v115) = *(_DWORD *)(result + 4004);
  *(_DWORD *)(result + 4000) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3484);
  LODWORD(v115) = *(_DWORD *)(result + 4008);
  *(_DWORD *)(result + 4004) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3488);
  LODWORD(v115) = *(_DWORD *)(result + 4012);
  *(_DWORD *)(result + 4008) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3492);
  LODWORD(v115) = *(_DWORD *)(result + 4016);
  *(_DWORD *)(result + 4012) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3496);
  LODWORD(v115) = *(_DWORD *)(result + 4020);
  *(_DWORD *)(result + 4016) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3500);
  LODWORD(v115) = *(_DWORD *)(result + 4024);
  *(_DWORD *)(result + 4020) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3504);
  LODWORD(v115) = *(_DWORD *)(result + 4028);
  *(_DWORD *)(result + 4024) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3508);
  LODWORD(v115) = *(_DWORD *)(result + 4032);
  *(_DWORD *)(result + 4028) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3512);
  LODWORD(v115) = *(_DWORD *)(result + 4036);
  *(_DWORD *)(result + 4032) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3516);
  LODWORD(v115) = *(_DWORD *)(result + 4040);
  *(_DWORD *)(result + 4036) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3520);
  LODWORD(v115) = *(_DWORD *)(result + 4044);
  *(_DWORD *)(result + 4040) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3524);
  LODWORD(v115) = *(_DWORD *)(result + 4048);
  *(_DWORD *)(result + 4044) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3528);
  LODWORD(v115) = *(_DWORD *)(result + 4052);
  *(_DWORD *)(result + 4048) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3532);
  LODWORD(v115) = *(_DWORD *)(result + 4056);
  *(_DWORD *)(result + 4052) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3536);
  LODWORD(v115) = *(_DWORD *)(result + 4060);
  *(_DWORD *)(result + 4056) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3540);
  LODWORD(v115) = *(_DWORD *)(result + 4064);
  *(_DWORD *)(result + 4060) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3544);
  LODWORD(v115) = *(_DWORD *)(result + 4068);
  *(_DWORD *)(result + 4064) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3548);
  LODWORD(v115) = *(_DWORD *)(result + 4072);
  *(_DWORD *)(result + 4068) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3552);
  LODWORD(v115) = *(_DWORD *)(result + 4076);
  *(_DWORD *)(result + 4072) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3556);
  LODWORD(v115) = *(_DWORD *)(result + 4080);
  *(_DWORD *)(result + 4076) = v116;
  LODWORD(v116) = v115 + *(_DWORD *)(a2 + 3560);
  LODWORD(v115) = *(_DWORD *)(result + 4084);
  *(_DWORD *)(result + 4080) = v116;
  *(_DWORD *)(result + 4084) = v115 + *(_DWORD *)(a2 + 3564);
  do
  {
    *(_DWORD *)(result + 4548 + v20) += *(_DWORD *)(a2 + 4028 + v20);
    v20 += 4;
  }
  while ( v20 != 252 );
  for ( jj = 0; jj != 256; jj += 4 )
    *(_DWORD *)(result + 4088 + jj) = *(_DWORD *)(a2 + 3568 + jj);
  v118 = 0;
  do
  {
    v119 = (_DWORD *)(result + 4352 + v118);
    v120 = (_DWORD *)(a2 + 3840 + v118);
    v118 += 12;
    v121 = v119[1];
    *v119 += *(v120 - 2);
    v119[1] = v121 + *(v120 - 1);
    v119[2] += *v120;
  }
  while ( v118 != 192 );
  v122 = *(_DWORD *)(result + 3972);
  *(_DWORD *)(result + 3968) += *(_DWORD *)(a2 + 3448);
  v123 = v122 + *(_DWORD *)(a2 + 3452);
  v124 = *(_DWORD *)(result + 3976);
  *(_DWORD *)(result + 3972) = v123;
  v125 = v124 + *(_DWORD *)(a2 + 3456);
  v126 = *(_DWORD *)(result + 3112);
  *(_DWORD *)(result + 3976) = v125;
  v127 = v126 + *(_DWORD *)(a2 + 2592);
  v128 = *(_DWORD *)(result + 4820);
  *(_DWORD *)(result + 3112) = v127;
  v129 = v128 + *(_DWORD *)(a2 + 4300);
  v130 = *(_DWORD *)(result + 4816);
  *(_DWORD *)(result + 4820) = v129;
  *(_QWORD *)(result + 4824) = *(_QWORD *)(a2 + 4304);
  *(_DWORD *)(result + 3124) = *(_DWORD *)(a2 + 2604);
  *(_DWORD *)(result + 3128) = *(_DWORD *)(a2 + 2608);
  *(_DWORD *)(result + 3132) = *(_DWORD *)(a2 + 2612);
  *(_DWORD *)(result + 3136) = *(_DWORD *)(a2 + 2616);
  *(_DWORD *)(result + 3140) = *(_DWORD *)(a2 + 2620);
  *(_QWORD *)(result + 3152) = *(_QWORD *)(a2 + 2632);
  *(_QWORD *)(result + 3160) = *(_QWORD *)(a2 + 2640);
  *(_WORD *)(result + 3928) = *(_WORD *)(a2 + 3408);
  *(_DWORD *)(result + 4344) = *(_DWORD *)(a2 + 3824);
  *(_DWORD *)(result + 4348) = *(_DWORD *)(a2 + 3828);
  *(_DWORD *)(result + 3168) = *(_DWORD *)(a2 + 2648);
  *(_DWORD *)(result + 3172) = *(_DWORD *)(a2 + 2652);
  v131 = v130 & 0xFFFFFFF0 | *(_DWORD *)(a2 + 4296) & 0xF;
  *(_DWORD *)(result + 4816) = v131;
  v132 = v131 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(a2 + 4296) >> 4) & 0xF));
  *(_DWORD *)(result + 4816) = v132;
  v133 = v132 & 0xFFFFF0FF | (((*(_DWORD *)(a2 + 4296) >> 8) & 0xF) << 8);
  *(_DWORD *)(result + 4816) = v133;
  v134 = v133 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(a2 + 4296)) >> 4 << 12);
  *(_DWORD *)(result + 4816) = v134;
  *(_DWORD *)(result + 4816) = v134 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(a2 + 4296)) & 0xF) << 16);
  v135 = *(_QWORD *)(result + 2992);
  *(_QWORD *)(result + 3000) += *(_QWORD *)(a2 + 2480);
  v136 = v135 + *(_QWORD *)(a2 + 2472);
  v137 = *(_QWORD *)(result + 3008);
  *(_QWORD *)(result + 2992) = v136;
  v138 = v137 + *(_QWORD *)(a2 + 2488);
  v139 = *(_QWORD *)(result + 3016);
  *(_QWORD *)(result + 3008) = v138;
  v140 = v139 + *(_QWORD *)(a2 + 2496);
  v141 = *(_QWORD *)(result + 3024);
  *(_QWORD *)(result + 3016) = v140;
  v142 = v141 + *(_QWORD *)(a2 + 2504);
  v143 = *(_QWORD *)(result + 3032);
  *(_QWORD *)(result + 3024) = v142;
  v144 = v143 + *(_QWORD *)(a2 + 2512);
  v145 = *(_QWORD *)(result + 3040);
  *(_QWORD *)(result + 3032) = v144;
  v146 = v145 + *(_QWORD *)(a2 + 2520);
  v147 = *(_QWORD *)(result + 3048);
  *(_QWORD *)(result + 3040) = v146;
  v148 = v147 + *(_QWORD *)(a2 + 2528);
  v149 = *(_QWORD *)(result + 3072);
  *(_QWORD *)(result + 3048) = v148;
  v150 = v149 + *(_QWORD *)(a2 + 2552);
  v151 = *(_QWORD *)(result + 3080);
  *(_QWORD *)(result + 3072) = v150;
  v152 = v151 + *(_QWORD *)(a2 + 2560);
  v153 = *(_QWORD *)(result + 5136);
  *(_QWORD *)(result + 3080) = v152;
  v154 = v153 + *(_QWORD *)(a2 + 4616);
  v155 = *(_QWORD *)(result + 5144);
  *(_QWORD *)(result + 5136) = v154;
  v156 = v155 + *(_QWORD *)(a2 + 4624);
  v157 = *(_QWORD *)(result + 5120);
  *(_QWORD *)(result + 5144) = v156;
  v158 = v157 + *(_QWORD *)(a2 + 4600);
  v159 = *(_QWORD *)(result + 5128);
  *(_QWORD *)(result + 5120) = v158;
  v160 = v159 + *(_QWORD *)(a2 + 4608);
  v161 = *(_QWORD *)(result + 3056);
  *(_QWORD *)(result + 5128) = v160;
  v162 = v161 + *(_QWORD *)(a2 + 2536);
  v163 = *(_QWORD *)(result + 3064);
  *(_QWORD *)(result + 3056) = v162;
  v164 = v163 + *(_QWORD *)(a2 + 2544);
  LODWORD(v163) = *(_DWORD *)(result + 3088);
  *(_QWORD *)(result + 3064) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2568);
  LODWORD(v163) = *(_DWORD *)(result + 4544);
  *(_DWORD *)(result + 3088) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 4024);
  LODWORD(v163) = *(_DWORD *)(result + 3092);
  *(_DWORD *)(result + 4544) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2572);
  LODWORD(v163) = *(_DWORD *)(result + 3096);
  *(_DWORD *)(result + 3092) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2576);
  LODWORD(v163) = *(_DWORD *)(result + 3100);
  *(_DWORD *)(result + 3096) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2580);
  LODWORD(v163) = *(_DWORD *)(result + 3104);
  *(_DWORD *)(result + 3100) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2584);
  LODWORD(v163) = *(_DWORD *)(result + 3628);
  *(_DWORD *)(result + 3104) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 3108);
  LODWORD(v163) = *(_DWORD *)(result + 3108);
  *(_DWORD *)(result + 3628) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2588);
  LODWORD(v163) = *(_DWORD *)(result + 3116);
  *(_DWORD *)(result + 3108) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2596);
  LODWORD(v163) = *(_DWORD *)(result + 3120);
  *(_DWORD *)(result + 3116) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 2600);
  LODWORD(v163) = *(_DWORD *)(result + 3936);
  *(_DWORD *)(result + 3120) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 3416);
  LODWORD(v163) = *(_DWORD *)(result + 3932);
  *(_DWORD *)(result + 3936) = v164;
  LODWORD(v164) = v163 + *(_DWORD *)(a2 + 3412);
  v165 = *(_QWORD *)(result + 3744);
  *(_DWORD *)(result + 3932) = v164;
  v166 = v165 + *(_QWORD *)(a2 + 3224);
  v167 = *(_QWORD *)(result + 3752);
  *(_QWORD *)(result + 3744) = v166;
  v168 = v167 + *(_QWORD *)(a2 + 3232);
  v169 = *(_QWORD *)(result + 3768);
  *(_QWORD *)(result + 3752) = v168;
  v170 = v169 + *(_QWORD *)(a2 + 3248);
  v171 = *(_QWORD *)(result + 3776);
  *(_QWORD *)(result + 3768) = v170;
  v172 = v171 + *(_QWORD *)(a2 + 3256);
  LODWORD(v171) = *(_DWORD *)(result + 3760);
  *(_QWORD *)(result + 3776) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3240);
  LODWORD(v171) = *(_DWORD *)(result + 3788);
  *(_DWORD *)(result + 3760) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3268);
  LODWORD(v171) = *(_DWORD *)(result + 3792);
  *(_DWORD *)(result + 3788) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3272);
  LODWORD(v171) = *(_DWORD *)(result + 3796);
  *(_DWORD *)(result + 3792) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3276);
  LODWORD(v171) = *(_DWORD *)(result + 3800);
  *(_DWORD *)(result + 3796) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3280);
  LODWORD(v171) = *(_DWORD *)(result + 3804);
  *(_DWORD *)(result + 3800) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3284);
  LODWORD(v171) = *(_DWORD *)(result + 3808);
  *(_DWORD *)(result + 3804) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3288);
  LODWORD(v171) = *(_DWORD *)(result + 3812);
  *(_DWORD *)(result + 3808) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3292);
  LODWORD(v171) = *(_DWORD *)(result + 3816);
  *(_DWORD *)(result + 3812) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3296);
  LODWORD(v171) = *(_DWORD *)(result + 3820);
  *(_DWORD *)(result + 3816) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3300);
  LODWORD(v171) = *(_DWORD *)(result + 3824);
  *(_DWORD *)(result + 3820) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3304);
  LODWORD(v171) = *(_DWORD *)(result + 3784);
  *(_DWORD *)(result + 3824) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 3264);
  LODWORD(v171) = *(_DWORD *)(result + 5156);
  *(_DWORD *)(result + 3784) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4636);
  LODWORD(v171) = *(_DWORD *)(result + 5160);
  *(_DWORD *)(result + 5156) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4640);
  LODWORD(v171) = *(_DWORD *)(result + 5164);
  *(_DWORD *)(result + 5160) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4644);
  LODWORD(v171) = *(_DWORD *)(result + 5168);
  *(_DWORD *)(result + 5164) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4648);
  LODWORD(v171) = *(_DWORD *)(result + 5172);
  *(_DWORD *)(result + 5168) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4652);
  LODWORD(v171) = *(_DWORD *)(result + 5176);
  *(_DWORD *)(result + 5172) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4656);
  LODWORD(v171) = *(_DWORD *)(result + 5180);
  *(_DWORD *)(result + 5176) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4660);
  LODWORD(v171) = *(_DWORD *)(result + 5184);
  *(_DWORD *)(result + 5180) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4664);
  LODWORD(v171) = *(_DWORD *)(result + 5188);
  *(_DWORD *)(result + 5184) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4668);
  LODWORD(v171) = *(_DWORD *)(result + 5192);
  *(_DWORD *)(result + 5188) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4672);
  LODWORD(v171) = *(_DWORD *)(result + 5196);
  *(_DWORD *)(result + 5192) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4676);
  LODWORD(v171) = *(_DWORD *)(result + 5200);
  *(_DWORD *)(result + 5196) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4680);
  LODWORD(v171) = *(_DWORD *)(result + 5204);
  *(_DWORD *)(result + 5200) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4684);
  LODWORD(v171) = *(_DWORD *)(result + 5208);
  *(_DWORD *)(result + 5204) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 4688);
  LODWORD(v171) = *(_DWORD *)(result + 6096);
  *(_DWORD *)(result + 5208) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 5576);
  LODWORD(v171) = *(_DWORD *)(result + 6100);
  *(_DWORD *)(result + 6096) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 5580);
  LODWORD(v171) = *(_DWORD *)(result + 6104);
  *(_DWORD *)(result + 6100) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 5584);
  LODWORD(v171) = *(_DWORD *)(result + 6108);
  *(_DWORD *)(result + 6104) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 5588);
  LODWORD(v171) = *(_DWORD *)(result + 6112);
  *(_DWORD *)(result + 6108) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 5592);
  LODWORD(v171) = *(_DWORD *)(result + 6116);
  *(_DWORD *)(result + 6112) = v172;
  LODWORD(v172) = v171 + *(_DWORD *)(a2 + 5596);
  LODWORD(v171) = *(_DWORD *)(result + 6120);
  *(_DWORD *)(result + 6116) = v172;
  *(_DWORD *)(result + 6120) = v171 + *(_DWORD *)(a2 + 5600);
  if ( *(_BYTE *)(a2 + 6584) )
    *(_BYTE *)(result + 7104) = *(_BYTE *)(a2 + 6584);
  *(_DWORD *)(result + 7012) = *(_DWORD *)(a2 + 6492);
  *(_DWORD *)(result + 7016) = *(_DWORD *)(a2 + 6496);
  *(_DWORD *)(result + 7020) = *(_DWORD *)(a2 + 6500);
  *(_DWORD *)(result + 7024) = *(_DWORD *)(a2 + 6504);
  *(_DWORD *)(result + 7084) = *(_DWORD *)(a2 + 6564);
  *(_DWORD *)(result + 7008) = *(_DWORD *)(a2 + 6488);
  *(_QWORD *)(result + 7096) = *(_QWORD *)(a2 + 6576);
  *(_BYTE *)(result + 7105) = *(_BYTE *)(a2 + 6585);
  v173 = *(_DWORD *)(result + 7188) & 0xFFFFFFF0 | *(_DWORD *)(a2 + 6668) & 0xF;
  *(_DWORD *)(result + 7188) = v173;
  v174 = v173 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(a2 + 6668) >> 4) & 0xF));
  *(_DWORD *)(result + 7188) = v174;
  v175 = v174 & 0xFFFFF0FF | (((*(_DWORD *)(a2 + 6668) >> 8) & 0xF) << 8);
  *(_DWORD *)(result + 7188) = v175;
  v176 = v175 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(a2 + 6668)) >> 4 << 12);
  *(_DWORD *)(result + 7188) = v176;
  *(_DWORD *)(result + 7188) = v176 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(a2 + 6668)) & 0xF) << 16);
  v177 = *(_DWORD *)(result + 6992);
  *(_DWORD *)(result + 6988) += *(_DWORD *)(a2 + 6468);
  v178 = v177 + *(_DWORD *)(a2 + 6472);
  v179 = *(_DWORD *)(result + 6996);
  *(_DWORD *)(result + 6992) = v178;
  v180 = v179 + *(_DWORD *)(a2 + 6476);
  v181 = *(_DWORD *)(result + 7000);
  *(_DWORD *)(result + 6996) = v180;
  v182 = v181 + *(_DWORD *)(a2 + 6480);
  v183 = *(_DWORD *)(result + 5992);
  *(_DWORD *)(result + 7000) = v182;
  v184 = v183 + *(_DWORD *)(a2 + 5472);
  v185 = *(_DWORD *)(result + 7436);
  *(_DWORD *)(result + 5992) = v184;
  v186 = v185 + *(_DWORD *)(a2 + 6916);
  v187 = *(_QWORD *)(result + 5736);
  *(_DWORD *)(result + 7436) = v186;
  v188 = v187 + *(_QWORD *)(a2 + 5216);
  v189 = *(_QWORD *)(result + 5744);
  *(_QWORD *)(result + 5736) = v188;
  v190 = v189 + *(_QWORD *)(a2 + 5224);
  v191 = *(_QWORD *)(result + 7488);
  *(_QWORD *)(result + 5744) = v190;
  v192 = v191 + *(_QWORD *)(a2 + 6968);
  v193 = *(_QWORD *)(result + 7496);
  *(_QWORD *)(result + 7488) = v192;
  v194 = v193 + *(_QWORD *)(a2 + 6976);
  v195 = *(_QWORD *)(result + 5752);
  *(_QWORD *)(result + 7496) = v194;
  v196 = v195 + *(_QWORD *)(a2 + 5232);
  v197 = *(_QWORD *)(result + 5760);
  *(_QWORD *)(result + 5752) = v196;
  v198 = v197 + *(_QWORD *)(a2 + 5240);
  v199 = *(_QWORD *)(result + 5768);
  *(_QWORD *)(result + 5760) = v198;
  v200 = v199 + *(_QWORD *)(a2 + 5248);
  v201 = *(_QWORD *)(result + 5776);
  *(_QWORD *)(result + 5768) = v200;
  v202 = v201 + *(_QWORD *)(a2 + 5256);
  v203 = *(_QWORD *)(result + 5784);
  *(_QWORD *)(result + 5776) = v202;
  v204 = v203 + *(_QWORD *)(a2 + 5264);
  v205 = *(_QWORD *)(result + 5792);
  *(_QWORD *)(result + 5784) = v204;
  v206 = v205 + *(_QWORD *)(a2 + 5272);
  v207 = *(_QWORD *)(result + 5800);
  *(_QWORD *)(result + 5792) = v206;
  v208 = v207 + *(_QWORD *)(a2 + 5280);
  v209 = *(_QWORD *)(result + 5808);
  *(_QWORD *)(result + 5800) = v208;
  v210 = v209 + *(_QWORD *)(a2 + 5288);
  v211 = *(_QWORD *)(result + 5816);
  *(_QWORD *)(result + 5808) = v210;
  v212 = v211 + *(_QWORD *)(a2 + 5296);
  v213 = *(_QWORD *)(result + 5824);
  *(_QWORD *)(result + 5816) = v212;
  v214 = v213 + *(_QWORD *)(a2 + 5304);
  v215 = *(_QWORD *)(result + 5832);
  *(_QWORD *)(result + 5824) = v214;
  v216 = v215 + *(_QWORD *)(a2 + 5312);
  v217 = *(_QWORD *)(result + 5840);
  *(_QWORD *)(result + 5832) = v216;
  v218 = v217 + *(_QWORD *)(a2 + 5320);
  v219 = *(_QWORD *)(result + 5848);
  *(_QWORD *)(result + 5840) = v218;
  v220 = v219 + *(_QWORD *)(a2 + 5328);
  v221 = *(_QWORD *)(result + 5856);
  *(_QWORD *)(result + 5848) = v220;
  v222 = v221 + *(_QWORD *)(a2 + 5336);
  v223 = *(_QWORD *)(result + 5864);
  *(_QWORD *)(result + 5856) = v222;
  v224 = v223 + *(_QWORD *)(a2 + 5344);
  v225 = *(_QWORD *)(result + 5872);
  *(_QWORD *)(result + 5864) = v224;
  v226 = v225 + *(_QWORD *)(a2 + 5352);
  v227 = *(_QWORD *)(result + 5896);
  *(_QWORD *)(result + 5872) = v226;
  v228 = v227 + *(_QWORD *)(a2 + 5376);
  v229 = *(_QWORD *)(result + 5904);
  *(_QWORD *)(result + 5896) = v228;
  v230 = v229 + *(_QWORD *)(a2 + 5384);
  v231 = *(_QWORD *)(result + 5912);
  *(_QWORD *)(result + 5904) = v230;
  v232 = v231 + *(_QWORD *)(a2 + 5392);
  v233 = *(_QWORD *)(result + 5920);
  *(_QWORD *)(result + 5912) = v232;
  *(_QWORD *)(result + 5920) = v233 + *(_QWORD *)(a2 + 5400);
  v234 = *(_QWORD *)(a2 + 5216);
  v235 = *(_QWORD *)(a2 + 5424);
  v236 = v234 >= v235;
  v237 = v234 - v235;
  if ( v236 )
    *(_QWORD *)(a2 + 5408) = v237;
  v238 = *(_QWORD *)(a2 + 5224);
  v239 = *(_QWORD *)(a2 + 5432);
  v236 = v238 >= v239;
  v240 = v238 - v239;
  if ( v236 )
    *(_QWORD *)(a2 + 5416) = v240;
  v241 = 0;
  *(_QWORD *)(result + 5928) += *(_QWORD *)(a2 + 5408);
  *(_QWORD *)(result + 5936) += *(_QWORD *)(a2 + 5416);
  *(_QWORD *)(result + 5944) += *(_QWORD *)(a2 + 5424);
  *(_QWORD *)(result + 5952) += *(_QWORD *)(a2 + 5432);
  *(_QWORD *)(result + 5960) += *(_QWORD *)(a2 + 5440);
  *(_QWORD *)(result + 5968) += *(_QWORD *)(a2 + 5448);
  *(_QWORD *)(result + 5976) += *(_QWORD *)(a2 + 5456);
  *(_QWORD *)(result + 5984) += *(_QWORD *)(a2 + 5464);
  *(_QWORD *)(result + 6056) += *(_QWORD *)(a2 + 5536);
  *(_DWORD *)(result + 7520) += *(_DWORD *)(a2 + 7000);
  *(_QWORD *)(result + 6064) += *(_QWORD *)(a2 + 5544);
  *(_QWORD *)(result + 6072) += *(_QWORD *)(a2 + 5552);
  *(_QWORD *)(result + 6080) += *(_QWORD *)(a2 + 5560);
  *(_DWORD *)(result + 3168) = *(_DWORD *)(a2 + 2648);
  *(_DWORD *)(result + 3172) = *(_DWORD *)(a2 + 2652);
  *(_QWORD *)(result + 6000) += *(_QWORD *)(a2 + 5480);
  *(_QWORD *)(result + 6008) += *(_QWORD *)(a2 + 5488);
  *(_QWORD *)(result + 6016) += *(_QWORD *)(a2 + 5496);
  *(_QWORD *)(result + 6024) += *(_QWORD *)(a2 + 5504);
  *(_DWORD *)(result + 7108) += *(_DWORD *)(a2 + 6588);
  *(_DWORD *)(result + 7112) += *(_DWORD *)(a2 + 6592);
  *(_DWORD *)(result + 7116) += *(_DWORD *)(a2 + 6596);
  v242 = 1;
  do
  {
    v243 = 108 * v241;
    v244 = (_DWORD *)(a2 + 6220 + v243);
    v245 = (_DWORD *)(result + 6740 + v243);
    v246 = v245[9];
    v245[8] += v244[8];
    v245[9] = v246 + v244[9];
    v247 = v245[1];
    *v245 += *v244;
    v245[1] = v247 + v244[1];
    v248 = v245[3];
    v245[2] += v244[2];
    v245[3] = v248 + v244[3];
    v249 = v245[5];
    v245[4] += v244[4];
    v245[5] = v249 + v244[5];
    v250 = v245[7];
    v245[6] += v244[6];
    v245[7] = v250 + v244[7];
    v251 = v245[11];
    v245[10] += v244[10];
    v245[11] = v251 + v244[11];
    v252 = v245[13];
    v245[12] += v244[12];
    v245[13] = v252 + v244[13];
    v253 = v245[15];
    v245[14] += v244[14];
    v245[15] = v253 + v244[15];
    v254 = v245[17];
    v245[16] += v244[16];
    v245[17] = v254 + v244[17];
    v255 = v245[19];
    v245[18] += v244[18];
    v245[19] = v255 + v244[19];
    v256 = v245[21];
    v245[20] += v244[20];
    v245[21] = v256 + v244[21];
    v257 = v245[23];
    v245[22] += v244[22];
    v245[23] = v257 + v244[23];
    v258 = v245[25];
    v259 = v242;
    v245[24] += v244[24];
    v245[25] = v258 + v244[25];
    v245[26] += v244[26];
    v241 = 1;
    v242 = 0;
  }
  while ( (v259 & 1) != 0 );
  for ( kk = 0; kk != 68; kk += 4 )
  {
    v261 = (_DWORD *)(a2 + 6136 + kk);
    v262 = (_DWORD *)(result + 6656 + kk);
    *v262 += *v261;
    v262[116] += v261[116];
  }
  v263 = 0;
  v264 = *(_DWORD *)(result + 6652);
  *(_DWORD *)(result + 6648) += *(_DWORD *)(a2 + 6128);
  v265 = v264 + *(_DWORD *)(a2 + 6132);
  v266 = *(_DWORD *)(result + 7068);
  *(_DWORD *)(result + 6652) = v265;
  v267 = v266 + *(_DWORD *)(a2 + 6548);
  v268 = *(_DWORD *)(result + 7072);
  *(_DWORD *)(result + 7068) = v267;
  v269 = v268 + *(_DWORD *)(a2 + 6552);
  v270 = *(_DWORD *)(result + 7208);
  *(_DWORD *)(result + 7072) = v269;
  v271 = v270 + *(_DWORD *)(a2 + 6688);
  v272 = *(_DWORD *)(result + 7064);
  *(_DWORD *)(result + 7208) = v271;
  *(_DWORD *)(result + 7064) = v272 + *(_DWORD *)(a2 + 6544);
  do
  {
    v273 = (_DWORD *)(a2 + 4312 + v263);
    v274 = (_DWORD *)(result + 4832 + v263);
    v263 += 4;
    *v274 += *v273;
    v274[595] += v273[595];
  }
  while ( v263 != 68 );
  for ( mm = 0; mm != 68; mm += 4 )
  {
    v276 = (_DWORD *)(a2 + 4380 + mm);
    v277 = (_DWORD *)(result + 4900 + mm);
    *v277 += *v276;
    v277[595] += v276[595];
  }
  for ( nn = 0; nn != 68; nn += 4 )
  {
    v279 = (_DWORD *)(a2 + 4448 + nn);
    v280 = (_DWORD *)(result + 4968 + nn);
    *v280 += *v279;
    v280[595] += v279[595];
  }
  v281 = *(_DWORD *)(result + 7416);
  *(_DWORD *)(result + 5036) += *(_DWORD *)(a2 + 4516);
  v282 = v281 + *(_DWORD *)(a2 + 6896);
  v283 = *(_DWORD *)(result + 5040);
  *(_DWORD *)(result + 7416) = v282;
  v284 = v283 + *(_DWORD *)(a2 + 4520);
  v285 = *(_DWORD *)(result + 7420);
  *(_DWORD *)(result + 5040) = v284;
  v286 = v285 + *(_DWORD *)(a2 + 6900);
  v287 = *(_DWORD *)(result + 5044);
  *(_DWORD *)(result + 7420) = v286;
  v288 = v287 + *(_DWORD *)(a2 + 4524);
  v289 = *(_DWORD *)(result + 7424);
  *(_DWORD *)(result + 5044) = v288;
  v290 = v289 + *(_DWORD *)(a2 + 6904);
  v291 = *(_DWORD *)(result + 5048);
  *(_DWORD *)(result + 7424) = v290;
  v292 = v291 + *(_DWORD *)(a2 + 4528);
  v293 = *(_DWORD *)(result + 7428);
  *(_DWORD *)(result + 5048) = v292;
  v294 = v293 + *(_DWORD *)(a2 + 6908);
  v295 = *(_DWORD *)(result + 5052);
  *(_DWORD *)(result + 7428) = v294;
  v296 = v295 + *(_DWORD *)(a2 + 4532);
  v297 = *(_DWORD *)(result + 7432);
  *(_DWORD *)(result + 5052) = v296;
  *(_DWORD *)(result + 7432) = v297 + *(_DWORD *)(a2 + 6912);
  return result;
}
