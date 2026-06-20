__int64 __fastcall mlme_cfg_on_psoc_enable(__int64 a1)
{
  __int64 ext_hdl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  int v12; // w9
  int v13; // w8
  char v14; // w8
  int v15; // w8
  __int64 values; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int64 v25; // x27
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x8
  char v28; // w9
  int v29; // w9
  int v30; // w8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  int v55; // w21
  int v56; // w21
  unsigned int v57; // w21
  char v58; // w25
  __int64 v59; // x28
  char v60; // w8
  char v61; // w9
  char v62; // w8
  char v63; // w8
  int v64; // w9
  int v65; // w9
  __int16 v66; // w9
  char v67; // w8
  __int64 v68; // x0
  int v69; // w9
  __int64 v70; // x0
  int v71; // w9
  int v72; // w8
  int v73; // w10
  char v74; // w22
  char v75; // w8
  __int64 v76; // x0
  unsigned __int64 v77; // x9
  int v78; // w9
  __int64 v79; // x8
  unsigned __int64 v80; // x8
  unsigned __int64 v81; // x8
  int v82; // w10
  char v83; // w8
  int v84; // w9
  int v85; // w8
  __int64 v86; // x0
  int v87; // w8
  int v88; // w8
  int v89; // w8
  __int64 v90; // x0
  char v91; // w8
  int v92; // w8
  char v93; // w8
  char v94; // w8
  int v95; // w8
  int v96; // w8
  int v97; // w8
  __int64 v98; // x0
  void *v99; // x22
  _DWORD *v100; // x28
  __int64 v101; // x0
  unsigned __int8 v102; // w25
  unsigned __int8 v103; // w21
  __int64 v104; // x8
  char *v105; // x0
  const char *v106; // x26
  char *v107; // x0
  unsigned __int64 v108; // x10
  unsigned __int64 v109; // x9
  int *v110; // x12
  int v111; // t1
  unsigned int *v112; // x9
  __int64 result; // x0
  char v114; // w8
  int v115; // w9
  __int64 v116; // x0
  int v117; // w21
  char v118; // w22
  char v119; // w23
  char v120; // w25
  char v121; // w26
  char v122; // w27
  char v123; // w8
  unsigned int v124; // w21
  __int64 v125; // x0
  __int64 v126; // x0
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  int v135; // w5
  __int64 v136; // x0
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  int v145; // w5
  __int64 v146; // x0
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  int v155; // w5
  __int64 v156; // x0
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  int v165; // w5
  __int64 v166; // x0
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  __int64 v175; // x0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  char *v184; // x8
  unsigned __int64 v185; // x25
  int v186; // w8
  int v187; // w1
  int v188; // w8
  __int64 v189; // x0
  char *v190; // x8
  unsigned __int64 v191; // x9
  unsigned __int64 v192; // x11
  __int64 v193; // x11
  _DWORD *v194; // x13
  __int64 cmpt_obj; // x0
  int v196; // w9
  int v197; // w9
  int v198; // w9
  int v199; // w9
  int v200; // w9
  int v201; // w8
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  const char *v210; // x2
  unsigned int v211; // w1
  __int64 v212; // x0
  int v213; // w6
  int v214; // w7
  int v215; // w8
  __int64 v216; // x4
  __int64 v217; // x0
  const void *v218; // x22
  unsigned int v219; // w0
  unsigned int v220; // w23
  char *v221; // x0
  char *v222; // x21
  double v223; // d0
  double v224; // d1
  double v225; // d2
  double v226; // d3
  double v227; // d4
  double v228; // d5
  double v229; // d6
  double v230; // d7
  __int64 v231; // x22
  char *v232; // x8
  char *v233; // x8
  int v234; // t1
  char *v235; // x0
  double v236; // d0
  double v237; // d1
  double v238; // d2
  double v239; // d3
  double v240; // d4
  double v241; // d5
  double v242; // d6
  double v243; // d7
  char *v244; // x26
  size_t v245; // x0
  unsigned __int64 v246; // x27
  size_t v247; // x28
  char *v248; // x0
  char *v249; // x25
  double v250; // d0
  double v251; // d1
  double v252; // d2
  double v253; // d3
  double v254; // d4
  double v255; // d5
  double v256; // d6
  double v257; // d7
  char *v258; // x0
  char *v259; // x25
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  size_t v268; // x28
  _DWORD *v269; // x25
  unsigned int v270; // w0
  double v271; // d0
  double v272; // d1
  double v273; // d2
  double v274; // d3
  double v275; // d4
  double v276; // d5
  double v277; // d6
  double v278; // d7
  int v279; // w8
  const char *v280; // x2
  __int64 v281; // x8
  __int64 v282; // [xsp+0h] [xbp-90h]
  __int64 v283; // [xsp+30h] [xbp-60h] BYREF
  char *stringp; // [xsp+38h] [xbp-58h] BYREF
  unsigned int v285; // [xsp+44h] [xbp-4Ch] BYREF
  char *s; // [xsp+48h] [xbp-48h] BYREF
  __int64 v287; // [xsp+50h] [xbp-40h]
  __int64 v288; // [xsp+58h] [xbp-38h]
  __int64 v289; // [xsp+60h] [xbp-30h]
  __int64 v290; // [xsp+68h] [xbp-28h]
  __int64 v291; // [xsp+70h] [xbp-20h]
  __int64 v292; // [xsp+78h] [xbp-18h]
  __int64 v293; // [xsp+80h] [xbp-10h]
  __int64 v294; // [xsp+88h] [xbp-8h]

  v294 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: Failed to get MLME Obj", v3, v4, v5, v6, v7, v8, v9, v10, "mlme_cfg_on_psoc_enable");
    result = 16;
    goto LABEL_125;
  }
  v11 = ext_hdl;
  *(_BYTE *)(ext_hdl + 1049) = 1;
  *(_BYTE *)(ext_hdl + 1048) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7360);
  v12 = *(_DWORD *)(cfg_psoc_get_values(a1) + 7364);
  if ( v12 )
    v13 = v12;
  else
    v13 = 7;
  *(_DWORD *)(v11 + 1032) = v13;
  *(_DWORD *)(v11 + 1036) = v13;
  *(_BYTE *)(v11 + 1040) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7372);
  *(_BYTE *)(v11 + 1041) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7392);
  *(_BYTE *)(v11 + 1042) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7404);
  *(_WORD *)(v11 + 1046) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7400);
  *(_BYTE *)(v11 + 1050) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7368);
  *(_BYTE *)(v11 + 1051) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7376);
  *(_BYTE *)(v11 + 1052) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7377);
  *(_BYTE *)(v11 + 1053) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7378);
  *(_BYTE *)(v11 + 1055) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7380);
  *(_BYTE *)(v11 + 1056) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7388);
  *(_BYTE *)(v11 + 1057) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7389);
  *(_BYTE *)(v11 + 1058) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7396);
  *(_BYTE *)(v11 + 1059) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7397);
  *(_BYTE *)(v11 + 1060) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7348);
  *(_BYTE *)(v11 + 1063) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7381);
  *(_BYTE *)(v11 + 1088) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7428);
  *(_BYTE *)(v11 + 1043) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7352);
  *(_WORD *)(v11 + 1044) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7356);
  v14 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7379);
  *(_WORD *)(v11 + 1089) = -256;
  *(_BYTE *)(v11 + 1054) = v14;
  *(_BYTE *)(v11 + 1061) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7361);
  *(_BYTE *)(v11 + 1062) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7362);
  *(_BYTE *)(v11 + 1064) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7408);
  *(_DWORD *)(v11 + 1068) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7384);
  *(_BYTE *)(v11 + 1073) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7412);
  *(_BYTE *)(v11 + 1075) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7417);
  *(_BYTE *)(v11 + 1076) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7418);
  *(_BYTE *)(v11 + 1077) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4380);
  *(_BYTE *)(v11 + 1078) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7420);
  *(_DWORD *)(v11 + 1084) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7424);
  *(_DWORD *)(v11 + 1092) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7432);
  *(_DWORD *)(v11 + 1108) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7436);
  *(_BYTE *)(v11 + 1074) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7416);
  v15 = *(_DWORD *)(cfg_psoc_get_values(a1) + 7508);
  stringp = nullptr;
  v292 = 0;
  v293 = 0;
  *(_DWORD *)(v11 + 1128) = v15;
  v290 = 0;
  v291 = 0;
  v288 = 0;
  v289 = 0;
  s = nullptr;
  v287 = 0;
  values = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(values + 7440), (__int64)&s, 64, &stringp);
  if ( (unsigned __int64)stringp >= 2 )
  {
    v25 = 0;
    while ( v25 < 0x40 )
    {
      if ( *((unsigned __int8 *)&s + v25) >= 3u )
      {
        qdf_trace_msg(
          0x1Fu,
          8u,
          "%s: invalid frm type %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "mlme_init_mgmt_hw_tx_retry_count_cfg",
          *((unsigned __int8 *)&s + v25));
      }
      else
      {
        if ( *((unsigned __int8 *)&s + v25 + 1) < 0x7Fu )
        {
          qdf_trace_msg(
            0x1Fu,
            8u,
            "%s: mgmt hw tx retry count %d for frm %d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "mlme_init_mgmt_hw_tx_retry_count_cfg");
          v27 = *((unsigned __int8 *)&s + v25);
          if ( v27 > 2 )
            break;
          v28 = *((_BYTE *)&s + v25 + 1);
        }
        else
        {
          qdf_trace_msg(
            0x1Fu,
            8u,
            "%s: mgmt hw tx retry count %d for frm %d, limit to %d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "mlme_init_mgmt_hw_tx_retry_count_cfg");
          v27 = *((unsigned __int8 *)&s + v25);
          if ( v27 > 2 )
            break;
          v28 = 127;
        }
        *(_BYTE *)(v11 + 1112 + v27) = v28;
      }
      v26 = v25 + 3;
      v25 += 2LL;
      if ( (unsigned __int64)stringp <= v26 )
        goto LABEL_17;
    }
LABEL_126:
    __break(0x5512u);
  }
LABEL_17:
  *(_BYTE *)(v11 + 1115) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7505);
  *(_BYTE *)(v11 + 1265) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7512);
  v29 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10024);
  *(_DWORD *)(v11 + 3472) = 200;
  *(_DWORD *)(v11 + 3468) = v29;
  *(_DWORD *)(v11 + 3476) = v29;
  *(_DWORD *)(v11 + 3480) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10028);
  *(_DWORD *)(v11 + 3484) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10032);
  *(_DWORD *)(v11 + 3488) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10036);
  *(_DWORD *)(v11 + 3492) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10040);
  *(_DWORD *)(v11 + 3496) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10044);
  *(_DWORD *)(v11 + 3500) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10048);
  *(_DWORD *)(v11 + 3504) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10052);
  *(_DWORD *)(v11 + 3508) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10056);
  *(_DWORD *)(v11 + 3512) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10060);
  *(_DWORD *)(v11 + 3516) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10064);
  *(_DWORD *)(v11 + 3520) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10068);
  v30 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10072);
  *(_QWORD *)(v11 + 56) = 17;
  *(_QWORD *)(v11 + 16) = 17;
  *(_QWORD *)(v11 + 96) = 17;
  *(_DWORD *)(v11 + 3524) = v30;
  *(_QWORD *)(v11 + 136) = 17;
  *(_QWORD *)(v11 + 216) = 17;
  *(_QWORD *)(v11 + 176) = 17;
  *(_QWORD *)(v11 + 256) = 17;
  *(_QWORD *)(v11 + 296) = 17;
  v31 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v31 + 5016), v11 + 32, 17, (_QWORD *)(v11 + 24));
  v32 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v32 + 5104), v11 + 72, 17, (_QWORD *)(v11 + 64));
  v33 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v33 + 5195), v11 + 112, 17, (_QWORD *)(v11 + 104));
  v34 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v34 + 5283), v11 + 152, 17, (_QWORD *)(v11 + 144));
  v35 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v35 + 5370), v11 + 192, 17, (_QWORD *)(v11 + 184));
  v36 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v36 + 5458), v11 + 232, 17, (_QWORD *)(v11 + 224));
  v37 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v37 + 5549), v11 + 272, 17, (_QWORD *)(v11 + 264));
  v38 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v38 + 5637), v11 + 312, 17, (_QWORD *)(v11 + 304));
  *(_QWORD *)(v11 + 336) = 17;
  *(_QWORD *)(v11 + 376) = 17;
  *(_QWORD *)(v11 + 416) = 17;
  *(_QWORD *)(v11 + 456) = 17;
  *(_QWORD *)(v11 + 496) = 17;
  *(_QWORD *)(v11 + 536) = 17;
  *(_QWORD *)(v11 + 576) = 17;
  *(_QWORD *)(v11 + 616) = 17;
  v39 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v39 + 5724), v11 + 352, 17, (_QWORD *)(v11 + 344));
  v40 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v40 + 5812), v11 + 392, 17, (_QWORD *)(v11 + 384));
  v41 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v41 + 5900), v11 + 432, 17, (_QWORD *)(v11 + 424));
  v42 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v42 + 5987), v11 + 472, 17, (_QWORD *)(v11 + 464));
  v43 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v43 + 6074), v11 + 512, 17, (_QWORD *)(v11 + 504));
  v44 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v44 + 6161), v11 + 552, 17, (_QWORD *)(v11 + 544));
  v45 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v45 + 6248), v11 + 592, 17, (_QWORD *)(v11 + 584));
  v46 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v46 + 6335), v11 + 632, 17, (_QWORD *)(v11 + 624));
  *(_QWORD *)(v11 + 696) = 17;
  *(_QWORD *)(v11 + 656) = 17;
  *(_QWORD *)(v11 + 736) = 17;
  *(_QWORD *)(v11 + 776) = 17;
  *(_QWORD *)(v11 + 856) = 17;
  *(_QWORD *)(v11 + 816) = 17;
  *(_QWORD *)(v11 + 896) = 17;
  *(_QWORD *)(v11 + 936) = 17;
  v47 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v47 + 6422), v11 + 672, 17, (_QWORD *)(v11 + 664));
  v48 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v48 + 6511), v11 + 712, 17, (_QWORD *)(v11 + 704));
  v49 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v49 + 6600), v11 + 752, 17, (_QWORD *)(v11 + 744));
  v50 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v50 + 6687), v11 + 792, 17, (_QWORD *)(v11 + 784));
  v51 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v51 + 6774), v11 + 832, 17, (_QWORD *)(v11 + 824));
  v52 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v52 + 6862), v11 + 872, 17, (_QWORD *)(v11 + 864));
  v53 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v53 + 6950), v11 + 912, 17, (_QWORD *)(v11 + 904));
  v54 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v54 + 7037), v11 + 952, 17, (_QWORD *)(v11 + 944));
  *(_BYTE *)(v11 + 976) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7124);
  *(_BYTE *)(v11 + 977) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7172);
  *(_DWORD *)(v11 + 980) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7128);
  *(_DWORD *)(v11 + 984) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7132);
  *(_DWORD *)(v11 + 988) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7136);
  *(_DWORD *)(v11 + 992) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7140);
  *(_DWORD *)(v11 + 996) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7144);
  *(_DWORD *)(v11 + 1000) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7148);
  *(_DWORD *)(v11 + 1004) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7152);
  *(_DWORD *)(v11 + 1008) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7156);
  *(_DWORD *)(v11 + 1012) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7160);
  *(_DWORD *)(v11 + 1016) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7164);
  *(_DWORD *)(v11 + 1020) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7168);
  *(_DWORD *)(v11 + 1024) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7176);
  *(_DWORD *)(v11 + 1028) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7180);
  v55 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 7520);
  v56 = v55 | (*(unsigned __int8 *)(cfg_psoc_get_values(a1) + 7522) << 8);
  v57 = v56 & 0xFFFFFF7F | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 7521) & 1) << 7);
  v58 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7523);
  LOWORD(v57) = v57 & 0xFF9F | (32 * (v58 & 1)) & 0xBF | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 7524) & 1) << 6);
  v59 = v11 + 1271;
  *(_WORD *)(v11 + 1268) = v57 & 0xFFF3 | (4 * (*(_WORD *)(cfg_psoc_get_values(a1) + 7528) & 3));
  *(_BYTE *)(v11 + 1270) = *(_BYTE *)(v11 + 1270) & 0xFC | *(_BYTE *)(cfg_psoc_get_values(a1) + 7536) & 3;
  v60 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7540);
  v61 = *(_BYTE *)(v11 + 1270) & 3;
  *(_WORD *)(v11 + 1271) = 1024;
  *(_BYTE *)(v11 + 1273) = 15;
  *(_DWORD *)(v11 + 1274) = 0;
  *(_BYTE *)(v11 + 1270) = v61 & 0xE3 | (4 * (v60 & 7));
  *(_BYTE *)(v11 + 1278) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7525);
  *(_BYTE *)(v11 + 1279) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7332);
  *(_BYTE *)(v11 + 1280) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7526);
  *(_BYTE *)(v11 + 1281) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7528);
  *(_BYTE *)(v11 + 1282) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7532);
  *(_BYTE *)(v11 + 1283) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7516);
  v62 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7544);
  *(_DWORD *)(v11 + 5452) = 256;
  *(_DWORD *)(v11 + 5456) = 1;
  *(_BYTE *)(v11 + 1284) = v62;
  *(_BYTE *)(v11 + 5480) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10176);
  *(_WORD *)(v11 + 5482) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10180);
  *(_DWORD *)(v11 + 5484) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10184);
  *(_DWORD *)(v11 + 5488) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10188);
  *(_WORD *)(v11 + 5492) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10192);
  *(_DWORD *)(v11 + 5496) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10196);
  *(_DWORD *)(v11 + 5500) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10200);
  *(_BYTE *)(v11 + 5504) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10204);
  *(_WORD *)(v11 + 5506) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10208);
  *(_DWORD *)(v11 + 5508) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10212);
  *(_DWORD *)(v11 + 5512) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10216);
  *(_WORD *)(v11 + 5516) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10220);
  *(_DWORD *)(v11 + 5520) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10224);
  *(_DWORD *)(v11 + 5524) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10228);
  *(_BYTE *)(v11 + 5528) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10232);
  *(_WORD *)(v11 + 5530) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10236);
  *(_DWORD *)(v11 + 5532) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10240);
  *(_DWORD *)(v11 + 5536) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10244);
  *(_WORD *)(v11 + 5540) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10248);
  *(_DWORD *)(v11 + 5544) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10252);
  *(_DWORD *)(v11 + 5548) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10256);
  *(_BYTE *)(v11 + 5552) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10260);
  *(_WORD *)(v11 + 5554) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10264);
  *(_DWORD *)(v11 + 5556) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10268);
  *(_DWORD *)(v11 + 5560) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10272);
  *(_WORD *)(v11 + 5564) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10276);
  *(_DWORD *)(v11 + 5568) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10280);
  *(_DWORD *)(v11 + 5572) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10284);
  *(_BYTE *)(v11 + 5460) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10288);
  *(_BYTE *)(v11 + 5461) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10292);
  *(_BYTE *)(v11 + 5462) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10296);
  *(_DWORD *)(v11 + 5464) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10300);
  *(_BYTE *)(v11 + 5468) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10304);
  *(_DWORD *)(v11 + 5472) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10308);
  *(_BYTE *)(v11 + 5476) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10312);
  *(_DWORD *)(v11 + 5576) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10316);
  *(_BYTE *)(v11 + 2612) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8412);
  *(_BYTE *)(v11 + 2613) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8416);
  *(_BYTE *)(v11 + 2614) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8420);
  *(_BYTE *)(v11 + 2615) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8424);
  *(_DWORD *)(v11 + 2688) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8564);
  *(_DWORD *)(v11 + 2692) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8568);
  *(_DWORD *)(v11 + 2696) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8572);
  *(_DWORD *)(v11 + 2700) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8576);
  *(_DWORD *)(v11 + 2704) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8580);
  *(_DWORD *)(v11 + 2708) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8584);
  *(_DWORD *)(v11 + 2712) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8588);
  *(_DWORD *)(v11 + 2716) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8592);
  *(_DWORD *)(v11 + 2720) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8596);
  *(_DWORD *)(v11 + 2724) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8600);
  *(_DWORD *)(v11 + 2728) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8604);
  *(_DWORD *)(v11 + 2732) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8608);
  *(_DWORD *)(v11 + 2736) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8612);
  *(_DWORD *)(v11 + 2740) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8616);
  *(_DWORD *)(v11 + 2744) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8620);
  *(_DWORD *)(v11 + 2748) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8624);
  *(_BYTE *)(v11 + 2752) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8562);
  v63 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8628);
  *(_BYTE *)(v11 + 2760) = 1;
  *(_WORD *)(v11 + 2762) = 30000;
  *(_BYTE *)(v11 + 2753) = v63;
  *(_WORD *)(v11 + 2764) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9132);
  *(_BYTE *)(v11 + 2766) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9136);
  *(_WORD *)(v11 + 2768) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9140);
  v64 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9144);
  *(_QWORD *)(v11 + 2776) = 4;
  *(_BYTE *)(v11 + 2770) = v64;
  qdf_uint8_array_parse("2, 4, 11, 22", v11 + 2792, 17, (_QWORD *)(v11 + 2784));
  *(_QWORD *)(v11 + 2816) = 8;
  qdf_uint8_array_parse("12, 18, 24, 36, 48, 72, 96, 108", v11 + 2832, 17, (_QWORD *)(v11 + 2824));
  *(_QWORD *)(v11 + 2856) = 16;
  qdf_uint8_array_parse(
    "0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0",
    v11 + 2872,
    17,
    (_QWORD *)(v11 + 2864));
  *(_QWORD *)(v11 + 2896) = 16;
  qdf_uint8_array_parse(
    "0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0",
    v11 + 2912,
    17,
    (_QWORD *)(v11 + 2904));
  *(_QWORD *)(v11 + 2936) = 16;
  qdf_uint8_array_parse(
    "0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0",
    v11 + 2952,
    17,
    (_QWORD *)(v11 + 2944));
  *(_BYTE *)(v11 + 3170) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4985);
  *(_BYTE *)(v11 + 3168) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4997);
  *(_BYTE *)(v11 + 3169) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4986);
  *(_BYTE *)(v11 + 3171) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4999);
  *(_BYTE *)(v11 + 3173) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4996);
  *(_BYTE *)(v11 + 3172) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4987);
  *(_BYTE *)(v11 + 3174) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4998);
  *(_DWORD *)(v11 + 3176) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4988);
  *(_DWORD *)(v11 + 3180) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4992);
  *(_BYTE *)(v11 + 3175) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5000);
  *(_BYTE *)(v11 + 3184) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5004);
  v65 = *(_DWORD *)(cfg_psoc_get_values(a1) + 5008);
  *(_DWORD *)(v11 + 3196) = 0xFFFF;
  *(_BYTE *)(v11 + 7122) = v65;
  *(_BYTE *)(v11 + 3190) = 5;
  *(_BYTE *)(v11 + 3188) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9725);
  *(_BYTE *)(v11 + 3189) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9732);
  *(_BYTE *)(v11 + 3191) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9726);
  v66 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9728);
  *(_BYTE *)(v11 + 2631) = 1;
  *(_WORD *)(v11 + 3192) = v66;
  *(_QWORD *)(v11 + 2640) = 0x30C0000030CLL;
  *(_DWORD *)(v11 + 2627) = 0x1000000;
  *(_QWORD *)(v11 + 2632) = 0xFFFE0000FFFELL;
  *(_BYTE *)(v11 + 2616) = 0;
  *(_BYTE *)(v11 + 2625) = 0;
  *(_DWORD *)(v11 + 2648) = 65534;
  *(_BYTE *)(v11 + 2624) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10108);
  *(_BYTE *)(v11 + 2652) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10113);
  *(_BYTE *)(v11 + 2674) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10156);
  *(_BYTE *)(v11 + 2617) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7520);
  *(_BYTE *)(v11 + 2618) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7524);
  *(_BYTE *)(v11 + 2619) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7524);
  *(_BYTE *)(v11 + 2620) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7521);
  *(_BYTE *)(v11 + 2621) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7522);
  v67 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10104);
  *(_BYTE *)(v11 + 2626) = 0;
  *(_BYTE *)(v11 + 2623) = v67;
  *(_BYTE *)(v11 + 2668) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10144);
  *(_BYTE *)(v11 + 2673) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10152);
  *(_BYTE *)(v11 + 2653) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10116);
  *(_DWORD *)(v11 + 2656) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10120);
  *(_DWORD *)(v11 + 2660) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10124);
  *(_BYTE *)(v11 + 2664) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10128);
  *(_BYTE *)(v11 + 2665) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10132);
  *(_BYTE *)(v11 + 2666) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10136);
  *(_BYTE *)(v11 + 2667) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10140);
  *(_BYTE *)(v11 + 2669) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10145);
  *(_BYTE *)(v11 + 2670) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10146);
  *(_BYTE *)(v11 + 2671) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10147);
  *(_BYTE *)(v11 + 2672) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10148);
  *(_BYTE *)(v11 + 2675) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10160);
  v68 = cfg_psoc_get_values(a1);
  v69 = *(unsigned __int8 *)(v11 + 2667);
  *(_BYTE *)(v11 + 2676) = *(_BYTE *)(v68 + 10161);
  if ( v69 )
  {
    v70 = cfg_psoc_get_values(a1);
    v71 = *(unsigned __int8 *)(v11 + 2667);
    v72 = *(unsigned __int8 *)(v70 + 10112);
    *(_BYTE *)(v11 + 2622) = v72;
    if ( v71 )
    {
      if ( v72 )
        *(_BYTE *)(v11 + 2625) = 1;
    }
  }
  *(_WORD *)(v11 + 2677) = 0;
  *(_BYTE *)(v11 + 2679) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10162);
  *(_BYTE *)v11 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4944);
  *(_BYTE *)(v11 + 1) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4948);
  *(_BYTE *)(v11 + 2) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4952);
  *(_BYTE *)(v11 + 3) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4956);
  *(_WORD *)(v11 + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4960);
  *(_WORD *)(v11 + 6) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4964);
  *(_BYTE *)(v11 + 8) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4968);
  *(_BYTE *)(v11 + 9) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4972);
  *(_BYTE *)(v11 + 10) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4976);
  *(_BYTE *)(v11 + 11) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4980);
  *(_BYTE *)(v11 + 12) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4984);
  v73 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9644);
  *(_DWORD *)(v11 + 3202) = 65537;
  *(_WORD *)(v11 + 3200) = v73;
  *(_WORD *)(v11 + 3206) = 2560;
  *(_BYTE *)(v11 + 3208) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9648);
  *(_BYTE *)(v11 + 3209) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9652);
  *(_BYTE *)(v11 + 3210) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9656);
  *(_BYTE *)(v11 + 3211) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9660);
  *(_BYTE *)(v11 + 3212) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9664);
  *(_BYTE *)(v11 + 3213) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9668);
  *(_BYTE *)(v11 + 3214) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9676);
  *(_BYTE *)(v11 + 3215) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9677);
  *(_BYTE *)(v11 + 3216) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9680);
  *(_BYTE *)(v11 + 3217) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9684);
  *(_BYTE *)(v11 + 3218) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9688);
  *(_BYTE *)(v11 + 3219) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9692);
  *(_BYTE *)(v11 + 3221) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9696);
  *(_BYTE *)(v11 + 3220) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9697);
  *(_BYTE *)(v11 + 3222) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9698);
  *(_BYTE *)(v11 + 3223) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9700);
  *(_BYTE *)(v11 + 3224) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9704);
  *(_BYTE *)(v11 + 3225) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9708);
  *(_BYTE *)(v11 + 3226) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9712);
  *(_BYTE *)(v11 + 3227) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9716);
  *(_BYTE *)(v11 + 3228) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9718);
  *(_BYTE *)(v11 + 3229) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9642);
  *(_BYTE *)(v11 + 3230) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9672);
  *(_BYTE *)(v11 + 3231) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9717);
  *(_BYTE *)(v11 + 3232) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9719);
  *(_BYTE *)(v11 + 3233) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9641);
  *(_BYTE *)(v11 + 3234) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9720);
  *(_BYTE *)(v11 + 3235) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9721);
  *(_BYTE *)(v11 + 3236) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9723);
  *(_BYTE *)(v11 + 3237) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9724);
  *(_WORD *)(v11 + 3240) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7572);
  *(_BYTE *)(v11 + 3239) = *(_BYTE *)(cfg_psoc_get_values(a1) + 3915);
  *(_DWORD *)(v11 + 3252) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8468);
  *(_DWORD *)(v11 + 3256) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8472);
  *(_DWORD *)(v11 + 3244) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8460);
  *(_DWORD *)(v11 + 3248) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8464);
  *(_DWORD *)(v11 + 3260) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8480);
  *(_DWORD *)(v11 + 3264) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8476);
  *(_DWORD *)(v11 + 3268) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8488);
  *(_DWORD *)(v11 + 3272) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8484);
  *(_DWORD *)(v11 + 3276) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8492);
  *(_DWORD *)(v11 + 3280) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8496);
  *(_DWORD *)(v11 + 3284) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8500);
  *(_BYTE *)(v11 + 3288) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8505);
  *(_BYTE *)(v11 + 3289) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8507);
  *(_BYTE *)(v11 + 3290) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8504);
  *(_BYTE *)(v11 + 3291) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8506);
  *(_BYTE *)(v11 + 3292) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8508);
  *(_BYTE *)(v11 + 3293) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8509);
  *(_BYTE *)(v11 + 3294) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8510);
  *(_DWORD *)(v11 + 3296) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8512);
  v74 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10088);
  *(_BYTE *)(v11 + 3528) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10076);
  *(_DWORD *)(v11 + 3540) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10084);
  v75 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10092);
  *(_BYTE *)(v11 + 3530) = v74 & 1;
  *(_BYTE *)(v11 + 3529) = (v74 & 2) != 0;
  *(_BYTE *)(v11 + 3545) = v75;
  v76 = cfg_psoc_get_values(a1);
  v77 = *(_QWORD *)(v11 + 1289) & 0xFFFFFFFFFFFFFFFELL;
  *(_BYTE *)(v11 + 3547) = *(_BYTE *)(v76 + 10094);
  *(_QWORD *)(v11 + 1289) = v77;
  *(_QWORD *)(v11 + 1289) = *(_QWORD *)(v11 + 1289) & 0xFFFFFFFFFFFFFFFDLL
                          | (2LL * (*(_BYTE *)(cfg_psoc_get_values(a1) + 10077) & 1));
  *(_QWORD *)(v11 + 1289) = *(_QWORD *)(v11 + 1289) & 0xFFFFFFFFFFEFFFFBLL
                          | (4LL * (*(_DWORD *)(cfg_psoc_get_values(a1) + 10080) != 0));
  v78 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 10076);
  v79 = *(_QWORD *)(v11 + 1289);
  if ( v78 )
    v79 |= 0x40000000uLL;
  *(_QWORD *)(v11 + 1289) = v79 & 0xFE02008041100007LL | 0x18000800;
  v80 = *(_QWORD *)(v11 + 1289) & 0x1FFFFFFFFFFFFFFLL
      | ((unsigned __int64)(*(_DWORD *)(cfg_psoc_get_values(a1) + 7552) & 0xF) << 57);
  *(_QWORD *)(v11 + 1297) &= 0xFFFFFFFFFFFFFF80LL;
  *(_QWORD *)(v11 + 1289) = v80;
  v81 = *(_QWORD *)(v11 + 1297) & 0xC0007FLL
      | ((unsigned __int64)(*(_DWORD *)(cfg_psoc_get_values(a1) + 7556) & 3) << 7);
  *(_BYTE *)(v11 + 1305) &= ~1u;
  *(_QWORD *)(v11 + 1297) = v81;
  *(_WORD *)(v11 + 1308) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7560);
  *(_WORD *)(v11 + 1310) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7564);
  LOWORD(s) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7568);
  qdf_mem_copy((void *)(v11 + 1312), &s, 2u);
  LOWORD(s) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7576);
  qdf_mem_copy((void *)(v11 + 1314), &s, 2u);
  LOWORD(s) = -256;
  qdf_mem_copy((void *)(v11 + 1316), &s, 2u);
  LOWORD(s) = -256;
  qdf_mem_copy((void *)(v11 + 1318), &s, 2u);
  *(_DWORD *)(v11 + 1460) = 65532;
  *(_BYTE *)(v11 + 1464) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7580);
  *(_BYTE *)(v11 + 1465) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7584);
  *(_BYTE *)(v11 + 1466) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7585);
  *(_DWORD *)(v11 + 1468) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7588);
  qdf_mem_set((void *)(v11 + 1408), 0x19u, 0);
  qdf_mem_set((void *)(v11 + 1433), 0x19u, 0);
  *(_DWORD *)(v11 + 1472) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7592);
  *(_DWORD *)(v11 + 1476) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7596);
  *(_DWORD *)(v11 + 2576) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8516);
  *(_DWORD *)(v11 + 2580) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8520);
  v82 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8524);
  *(_QWORD *)(v11 + 2588) = 0x14000000C8LL;
  *(_DWORD *)(v11 + 2584) = v82;
  *(_QWORD *)(v11 + 2596) = 0x1900000005LL;
  v83 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8528);
  *(_WORD *)(v11 + 2605) = 0;
  *(_BYTE *)(v11 + 2604) = v83;
  *(_BYTE *)(v11 + 2607) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8529);
  sized_strscpy(v11 + 2976, "Qualcomm Atheros", 17);
  sized_strscpy(v11 + 3104, "11n-AP", 7);
  sized_strscpy(v11 + 3136, "SN1234", 7);
  sized_strscpy(v11 + 3072, "WFR4031", 8);
  sized_strscpy(v11 + 3040, "MN1234", 7);
  *(_BYTE *)(v11 + 5416) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8541);
  *(_BYTE *)(v11 + 5417) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8542);
  *(_DWORD *)(v11 + 5420) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8544);
  *(_DWORD *)(v11 + 5424) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8548);
  *(_DWORD *)(v11 + 5428) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8552);
  *(_DWORD *)(v11 + 5432) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8556);
  *(_DWORD *)(v11 + 3300) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9932);
  *(_DWORD *)(v11 + 3304) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9936);
  *(_DWORD *)(v11 + 3308) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9940);
  *(_DWORD *)(v11 + 3312) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9944);
  *(_BYTE *)(v11 + 3332) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9948);
  *(_BYTE *)(v11 + 3331) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9952);
  *(_BYTE *)(v11 + 3333) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9956);
  *(_BYTE *)(v11 + 3334) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9957);
  *(_DWORD *)(v11 + 3324) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9960);
  *(_BYTE *)(v11 + 3335) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9968);
  *(_BYTE *)(v11 + 3336) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9969);
  *(_BYTE *)(v11 + 3328) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9976);
  *(_BYTE *)(v11 + 3330) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9964);
  *(_BYTE *)(v11 + 3337) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9980);
  v84 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9972);
  *(_DWORD *)(v11 + 3316) = 1000;
  *(_DWORD *)(v11 + 3320) = v84;
  *(_BYTE *)(v11 + 3329) = 0;
  *(_BYTE *)(v11 + 3338) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9988);
  *(_DWORD *)(v11 + 3340) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9984);
  *(_WORD *)(v11 + 3388) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9992);
  *(_DWORD *)(v11 + 3392) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9996);
  *(_DWORD *)(v11 + 3396) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10000);
  *(_DWORD *)(v11 + 3400) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10004);
  *(_DWORD *)(v11 + 3404) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10008);
  v85 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10012);
  s = nullptr;
  *(_DWORD *)(v11 + 3408) = v85;
  *(_BYTE *)(v11 + 1480) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7600);
  *(_BYTE *)(v11 + 1481) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7628);
  *(_BYTE *)(v11 + 1560) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7629);
  *(_BYTE *)(v11 + 1561) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7720);
  *(_BYTE *)(v11 + 1563) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7756);
  *(_BYTE *)(v11 + 1564) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7757);
  *(_BYTE *)(v11 + 1565) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7758);
  *(_BYTE *)(v11 + 1566) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7776);
  *(_DWORD *)(v11 + 1568) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7604);
  *(_DWORD *)(v11 + 1572) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7608);
  *(_BYTE *)(v11 + 1576) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7612);
  *(_BYTE *)(v11 + 1577) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7616);
  *(_DWORD *)(v11 + 1580) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7620);
  *(_BYTE *)(v11 + 1584) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7624);
  *(_BYTE *)(v11 + 1585) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7632);
  *(_BYTE *)(v11 + 1586) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7636);
  *(_DWORD *)(v11 + 1588) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7640);
  *(_DWORD *)(v11 + 1592) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7644);
  *(_DWORD *)(v11 + 1596) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7648);
  *(_DWORD *)(v11 + 1600) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7652);
  *(_DWORD *)(v11 + 1604) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7656);
  *(_DWORD *)(v11 + 1608) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7660);
  *(_DWORD *)(v11 + 1612) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7664);
  *(_DWORD *)(v11 + 1616) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7668);
  *(_DWORD *)(v11 + 1620) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7672);
  *(_DWORD *)(v11 + 1624) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7676);
  *(_DWORD *)(v11 + 1628) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7680);
  *(_DWORD *)(v11 + 1632) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7684);
  *(_DWORD *)(v11 + 1636) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7688);
  *(_DWORD *)(v11 + 1640) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7692);
  *(_DWORD *)(v11 + 1644) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7696);
  *(_DWORD *)(v11 + 1648) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7700);
  *(_DWORD *)(v11 + 1652) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7704);
  *(_DWORD *)(v11 + 1656) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7708);
  *(_DWORD *)(v11 + 1660) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7712);
  v86 = cfg_psoc_get_values(a1);
  v87 = *(unsigned __int8 *)(v11 + 1561);
  *(_DWORD *)(v11 + 1664) = *(_DWORD *)(v86 + 7716);
  if ( v87 == 1 )
  {
    *(_DWORD *)(v11 + 1668) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7724);
    *(_DWORD *)(v11 + 1672) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7728);
    *(_DWORD *)(v11 + 1676) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7732);
    *(_DWORD *)(v11 + 1680) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7736);
    *(_DWORD *)(v11 + 1684) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7740);
    *(_DWORD *)(v11 + 1688) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7744);
  }
  *(_DWORD *)(v11 + 1692) = 64;
  *(_DWORD *)(v11 + 1700) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7752);
  *(_DWORD *)(v11 + 1696) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7748);
  *(_BYTE *)(v11 + 1704) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7760);
  *(_BYTE *)(v11 + 1705) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7764);
  *(_BYTE *)(v11 + 1706) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7768);
  *(_BYTE *)(v11 + 1707) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7772);
  *(_BYTE *)(v11 + 1708) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7777);
  *(_DWORD *)(v11 + 1712) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8180);
  *(_DWORD *)(v11 + 1716) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8184);
  v88 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8188);
  if ( v88 < 0 )
    v88 = -v88;
  *(_DWORD *)(v11 + 1720) = v88;
  v89 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8408);
  if ( v89 < 0 )
    v89 = -v89;
  *(_BYTE *)(v11 + 2568) = v89;
  *(_DWORD *)(v11 + 1724) = *(_DWORD *)(cfg_psoc_get_values(a1) + 0x2000);
  *(_DWORD *)(v11 + 1728) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8196);
  *(_DWORD *)(v11 + 2564) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9928);
  *(_WORD *)(v11 + 1732) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8200);
  *(_WORD *)(v11 + 1734) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8204);
  *(_DWORD *)(v11 + 1736) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8316);
  *(_DWORD *)(v11 + 1740) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8208);
  *(_DWORD *)(v11 + 1744) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8212);
  *(_BYTE *)(v11 + 1748) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8220);
  *(_BYTE *)(v11 + 1749) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8224);
  *(_DWORD *)(v11 + 1752) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8228);
  *(_DWORD *)(v11 + 1756) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8232);
  *(_DWORD *)(v11 + 1760) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8236);
  *(_DWORD *)(v11 + 1764) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8240);
  *(_DWORD *)(v11 + 1768) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8244);
  *(_BYTE *)(v11 + 1772) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8248);
  *(_BYTE *)(v11 + 1773) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8249);
  *(_WORD *)(v11 + 1778) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8256);
  *(_DWORD *)(v11 + 1780) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8252);
  *(_BYTE *)(v11 + 1784) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8260);
  v90 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v90 + 7778), v11 + 1785, 100, &s);
  *(_BYTE *)(v11 + 1885) = (_BYTE)s;
  *(_BYTE *)(v11 + 1887) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8284);
  *(_BYTE *)(v11 + 1888) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8288);
  *(_DWORD *)(v11 + 1892) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8292);
  *(_BYTE *)(v11 + 1896) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8296);
  *(_BYTE *)(v11 + 1897) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8297);
  *(_BYTE *)(v11 + 1928) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8298);
  *(_DWORD *)(v11 + 1932) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8300);
  *(_QWORD *)(v11 + 1936) = *(unsigned int *)(cfg_psoc_get_values(a1) + 8312);
  v91 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8308);
  *(_BYTE *)(v11 + 2552) = 0;
  *(_BYTE *)(v11 + 1776) = v91;
  *(_BYTE *)(v11 + 1510) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8341);
  *(_BYTE *)(v11 + 1511) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8380) != 0;
  *(_BYTE *)(v11 + 1512) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8384);
  *(_BYTE *)(v11 + 1513) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8342);
  *(_BYTE *)(v11 + 1536) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8388);
  *(_BYTE *)(v11 + 1514) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8343);
  *(_BYTE *)(v11 + 1515) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8344);
  *(_DWORD *)(v11 + 1516) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8348);
  *(_DWORD *)(v11 + 1548) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8400);
  *(_DWORD *)(v11 + 1520) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8352);
  *(_DWORD *)(v11 + 1524) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8360);
  *(_DWORD *)(v11 + 1532) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8364);
  v92 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8372);
  *(_DWORD *)(v11 + 1504) = 2;
  *(_DWORD *)(v11 + 1540) = v92;
  *(_DWORD *)(v11 + 1528) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8368);
  *(_DWORD *)(v11 + 1544) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8376);
  *(_BYTE *)(v11 + 2360) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8387);
  qdf_mem_set((void *)(v11 + 1508), 2u, 0);
  *(_BYTE *)(v11 + 1562) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8385);
  *(_BYTE *)(v11 + 1900) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8264);
  *(_DWORD *)(v11 + 1904) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8268);
  *(_DWORD *)(v11 + 1912) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8272);
  *(_DWORD *)(v11 + 1908) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8276);
  *(_DWORD *)(v11 + 1916) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8324);
  *(_DWORD *)(v11 + 1920) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8328);
  *(_DWORD *)(v11 + 1924) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8332);
  *(_BYTE *)(v11 + 1774) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8340);
  v93 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8386);
  *(_BYTE *)(v11 + 2508) = 30;
  *(_BYTE *)(v11 + 1886) = v93;
  *(_BYTE *)(v11 + 2553) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8392);
  *(_BYTE *)(v11 + 2554) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8396);
  v94 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8404);
  *(_DWORD *)(v11 + 1556) = 0;
  *(_DWORD *)(v11 + 5384) = 0;
  *(_BYTE *)(v11 + 5388) = 1;
  *(_BYTE *)(v11 + 2561) = v94;
  *(_QWORD *)(v11 + 5396) = 0;
  *(_BYTE *)(v11 + 5389) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7332);
  *(_BYTE *)(v11 + 5391) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7320);
  *(_BYTE *)(v11 + 5392) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7324);
  *(_BYTE *)(v11 + 5390) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7328) != 0;
  *(_DWORD *)(v11 + 5404) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7336);
  *(_DWORD *)(v11 + 5408) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7340);
  *(_BYTE *)(v11 + 5412) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7344);
  *(_BYTE *)(v11 + 3412) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9752);
  *(_DWORD *)(v11 + 3416) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9736);
  v95 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9740);
  *(_BYTE *)(v11 + 3424) = 0;
  *(_DWORD *)(v11 + 3420) = v95;
  *(_DWORD *)(v11 + 3428) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9744);
  *(_DWORD *)(v11 + 3432) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9924);
  v96 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9920);
  *(_DWORD *)(v11 + 5748) = 0;
  *(_DWORD *)(v11 + 3436) = v96;
  *(_DWORD *)(v11 + 5752) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5012);
  *(_DWORD *)(v11 + 3460) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10016);
  *(_DWORD *)(v11 + 3464) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10020);
  *(_BYTE *)(v11 + 4416) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4381);
  *(_DWORD *)(v11 + 4420) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4384);
  *(_BYTE *)(v11 + 4424) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4388);
  *(_BYTE *)(v11 + 5370) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4892);
  *(_BYTE *)(v11 + 4425) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4389);
  *(_BYTE *)(v11 + 4426) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4390);
  v97 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4896);
  *(_BYTE *)(v11 + 5371) = 1;
  s = nullptr;
  v285 = 0;
  *(_DWORD *)(v11 + 5372) = v97;
  v283 = 0;
  if ( *(_BYTE *)(cfg_psoc_get_values(a1) + 4391) )
  {
    v98 = _qdf_mem_malloc(0x1F4u, "mlme_acs_parse_weight_list", 2532);
    if ( v98 )
    {
      v99 = (void *)v98;
      v100 = (_DWORD *)(v11 + 4428);
      v101 = cfg_psoc_get_values(a1);
      qdf_mem_copy(v99, (const void *)(v101 + 4391), 0x1F4u);
      v102 = 0;
      v103 = 0;
      stringp = (char *)v99;
      while ( 1 )
      {
        v105 = strsep(&stringp, ",");
        s = v105;
        if ( !v105 )
        {
LABEL_56:
          _qdf_mem_free((__int64)v99);
          v59 = v11 + 1271;
          break;
        }
        v106 = v105;
        v285 = 0;
        HIDWORD(v283) = 0;
        if ( strchr(v105, 45) )
        {
          v107 = strsep(&s, "-");
          sscanf(v107, "%d", &v285);
          sscanf(s, "%d", (char *)&v283 + 4);
          strsep(&s, "=");
          if ( !s )
            goto LABEL_56;
          sscanf(s, "%d", &v283);
          if ( v102 == 10 )
          {
            v102 = 10;
          }
          else
          {
            v104 = v11 + 5248 + 12LL * v102++;
            *(_BYTE *)(v104 + 8) = v283;
            *(_DWORD *)v104 = v285;
            *(_DWORD *)(v104 + 4) = HIDWORD(v283);
          }
          goto LABEL_33;
        }
        sscanf(v106, "%d", &v285);
        strsep(&s, "=");
        if ( !s )
          goto LABEL_56;
        sscanf(s, "%d", &v283);
        if ( !v103 )
          goto LABEL_53;
        if ( v103 >= 0x66u )
          v108 = 102;
        else
          v108 = v103;
        if ( *v100 == v285 )
        {
          LOBYTE(v109) = 0;
LABEL_46:
          LOBYTE(v100[2 * (unsigned __int8)v109 + 1]) = v283;
          goto LABEL_33;
        }
        v110 = (int *)(v11 + 4436);
        v109 = 0;
        while ( v108 - 1 != v109 )
        {
          v111 = *v110;
          v110 += 2;
          ++v109;
          if ( v111 == v285 )
          {
            if ( v109 < v108 )
              goto LABEL_46;
            break;
          }
        }
        if ( v103 == 102 )
        {
          v103 = 102;
        }
        else
        {
LABEL_53:
          v112 = &v100[2 * v103++];
          *v112 = v285;
          *((_BYTE *)v112 + 4) = v283;
        }
LABEL_33:
        if ( !stringp )
        {
          *(_WORD *)(v11 + 5244) = v103;
          *(_WORD *)(v11 + 5368) = v102;
          goto LABEL_56;
        }
      }
    }
  }
  v114 = *(_BYTE *)(cfg_psoc_get_values(a1) + 4900);
  *(_BYTE *)(v11 + 5376) = v114 & 1;
  *(_BYTE *)(v11 + 5377) = (v114 & 2) != 0;
  *(_BYTE *)(v11 + 5378) = (v114 & 4) != 0;
  *(_BYTE *)(v11 + 5379) = (v114 & 8) != 0;
  *(_BYTE *)(v11 + 5380) = (v114 & 0x10) != 0;
  *(_WORD *)(v11 + 5382) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4904);
  *(_BYTE *)(v59 + 3137) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8432);
  v115 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8436);
  *(_QWORD *)(v11 + 3968) = 128;
  *(_BYTE *)(v59 + 3138) = v115;
  qdf_uint8_array_parse("1, 14, 20", v11 + 3984, 128, (_QWORD *)(v11 + 3976));
  *(_QWORD *)(v11 + 4112) = 256;
  qdf_uint8_array_parse("36, 126, 20", v11 + 4128, 256, (_QWORD *)(v11 + 4120));
  *(_QWORD *)(v11 + 4384) = 4;
  *(_QWORD *)(v11 + 4392) = 4;
  v116 = cfg_psoc_get_values(a1);
  qdf_mem_copy((void *)(v11 + 4400), (const void *)(v116 + 8428), *(unsigned int *)(v11 + 4392));
  *(_WORD *)(v59 + 3139) = 27;
  *(_BYTE *)(v59 + 3141) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8440);
  *(_BYTE *)(v11 + 3452) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8530);
  *(_BYTE *)(v11 + 3453) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8531);
  *(_BYTE *)(v11 + 3454) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8532);
  *(_BYTE *)(v11 + 3455) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8540);
  v117 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 8533);
  v118 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8534);
  v119 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8535);
  v120 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8536);
  v121 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8537);
  v122 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8538);
  v123 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8539);
  if ( v117 != 1 || (*(_BYTE *)(v11 + 3452) & 1) == 0 )
    *(_BYTE *)(v11 + 3453) = 0;
  *(_BYTE *)(v11 + 5436) = 0;
  *(_DWORD *)(v11 + 5437) = 257;
  *(_BYTE *)(v11 + 3456) = (v118 | (2 * v119) | (4 * v120) | (8 * v121) | (16 * v122) | (32 * v123))
                         + ((_BYTE)v117 << 6);
  *(_DWORD *)(v11 + 5444) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10164);
  *(_BYTE *)(v11 + 5448) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10168);
  *(_BYTE *)(v11 + 5449) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10170);
  v124 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 10169);
  v125 = cfg_psoc_get_values(a1);
  wifi_pos_set_rsta_11az_ranging_cap(*(unsigned int *)(v125 + 10172));
  wifi_pos_set_rsta_sec_ltf_cap(v124);
  *(_WORD *)(v11 + 5584) = 256;
  *(_WORD *)(v11 + 5600) = 1;
  *(_DWORD *)(v11 + 5588) = 8;
  *(_QWORD *)(v11 + 5592) = 0x50F20400000001LL;
  *(_DWORD *)(v11 + 5604) = 0;
  *(_BYTE *)(v11 + 5586) = 16;
  *(_QWORD *)(v11 + 5608) = 16;
  qdf_uint8_array_parse("0xa, 0xb, 0xc, 0xd, 0xe, 0xf", v11 + 5624, 16, (_QWORD *)(v11 + 5616));
  s = nullptr;
  *(_BYTE *)(v11 + 5684) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7233);
  *(_BYTE *)(v11 + 5685) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7234);
  *(_BYTE *)(v11 + 5686) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7236);
  *(_BYTE *)(v11 + 5720) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7240);
  v126 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v126 + 7241, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: normal latency flags parsing failed",
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      "mlme_init_fe_wlm_in_cfg");
  }
  v135 = HIDWORD(s);
  *(_DWORD *)(v11 + 5688) = (_DWORD)s;
  *(_DWORD *)(v11 + 5704) = v135;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: normal latency flags 0x%x host flags 0x%x",
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    v134,
    "mlme_init_fe_wlm_in_cfg");
  v136 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v136 + 7260, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: xr latency flags parsing failed",
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      "mlme_init_fe_wlm_in_cfg");
  }
  v145 = HIDWORD(s);
  *(_DWORD *)(v11 + 5692) = (_DWORD)s;
  *(_DWORD *)(v11 + 5708) = v145;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: xr latency flags 0x%x host flags 0x%x",
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    "mlme_init_fe_wlm_in_cfg");
  v146 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v146 + 7279, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: low latency flags parsing failed",
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      "mlme_init_fe_wlm_in_cfg");
  }
  v155 = HIDWORD(s);
  *(_DWORD *)(v11 + 5696) = (_DWORD)s;
  *(_DWORD *)(v11 + 5712) = v155;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: low latency flags 0x%x host flags 0x%x",
    v147,
    v148,
    v149,
    v150,
    v151,
    v152,
    v153,
    v154,
    "mlme_init_fe_wlm_in_cfg");
  v156 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v156 + 7298, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: ultra-low latency flags parsing failed",
      v157,
      v158,
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      "mlme_init_fe_wlm_in_cfg");
  }
  v165 = HIDWORD(s);
  *(_DWORD *)(v11 + 5700) = (_DWORD)s;
  *(_DWORD *)(v11 + 5716) = v165;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: ultra-low latency flags 0x%x host flags 0x%x",
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    v164,
    "mlme_init_fe_wlm_in_cfg");
  s = nullptr;
  *(_BYTE *)(v11 + 5724) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7184);
  *(_BYTE *)(v11 + 5725) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7185);
  *(_BYTE *)(v11 + 5726) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7188);
  v166 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v166 + 7192), v11 + 5727, 5, &s);
  if ( (unsigned __int64)s <= 4 )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: Incorrect RM capability, using default",
      v167,
      v168,
      v169,
      v170,
      v171,
      v172,
      v173,
      v174,
      "mlme_init_fe_rrm_in_cfg");
    qdf_uint8_array_parse("0x73,0x1A,0x91,0x00,0x04", v11 + 5727, 5, &s);
  }
  *(_DWORD *)(v11 + 5732) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8444);
  *(_DWORD *)(v11 + 5736) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8448);
  *(_DWORD *)(v11 + 5740) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8452);
  *(_DWORD *)(v11 + 5744) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8456);
  *(_DWORD *)(v11 + 5756) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9208);
  *(_BYTE *)(v11 + 5760) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9216);
  *(_BYTE *)(v11 + 5761) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9221);
  *(_DWORD *)(v11 + 5764) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9224);
  *(_BYTE *)(v11 + 5768) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9228);
  *(_BYTE *)(v11 + 6180) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9213);
  *(_DWORD *)(v11 + 5772) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9232);
  *(_BYTE *)(v11 + 6384) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9212);
  *(_BYTE *)(v11 + 6383) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9236);
  *(_BYTE *)(v11 + 6385) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9237);
  *(_BYTE *)(v11 + 6387) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9220);
  *(_BYTE *)(v11 + 6386) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9640);
  s = nullptr;
  v175 = cfg_psoc_get_values(a1);
  qdf_uint16_array_parse((_BYTE *)(v175 + 9238), v11 + 6182, 100, &s);
  v184 = s;
  *(_BYTE *)(v11 + 6382) = (_BYTE)s;
  if ( v184 )
  {
    v185 = 0;
    while ( v185 != 100 )
    {
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: avoid_acs_freq %d",
        v176,
        v177,
        v178,
        v179,
        v180,
        v181,
        v182,
        v183,
        "mlme_init_acs_avoid_freq_list",
        *(unsigned __int16 *)(v11 + 6182 + 2 * v185++));
      if ( (unsigned __int64)s <= v185 )
        goto LABEL_74;
    }
    goto LABEL_126;
  }
LABEL_74:
  *(_DWORD *)(v11 + 6388) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9200);
  *(_BYTE *)(v11 + 6392) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9204);
  *(_BYTE *)(v11 + 6393) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9639);
  *(_DWORD *)(v11 + 5652) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4912);
  v186 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 4908);
  *(_BYTE *)(v11 + 5648) = v186;
  if ( v186 == 1 )
    *(_DWORD *)(v11 + 5652) |= 0x100u;
  v187 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 4909);
  *(_BYTE *)(v11 + 5649) = v187;
  if ( v187 == 1 )
    *(_DWORD *)(v11 + 5652) |= 0x80u;
  wlan_mlme_set_btm_abridge_flag(a1);
  *(_DWORD *)(v11 + 5656) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4916);
  *(_DWORD *)(v11 + 5660) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4920);
  *(_DWORD *)(v11 + 5664) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4924);
  *(_DWORD *)(v11 + 5668) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4928);
  *(_DWORD *)(v11 + 5672) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4932);
  *(_DWORD *)(v11 + 5676) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4936);
  v188 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4940);
  v289 = 0;
  v290 = 0;
  v287 = 0;
  v288 = 0;
  *(_DWORD *)(v11 + 5680) = v188;
  s = nullptr;
  stringp = nullptr;
  *(_DWORD *)(v11 + 6396) = -1;
  *(_DWORD *)(v11 + 6404) = -1;
  *(_DWORD *)(v11 + 6412) = -1;
  *(_DWORD *)(v11 + 6420) = -1;
  *(_DWORD *)(v11 + 6428) = -1;
  *(_DWORD *)(v11 + 6436) = -1;
  *(_DWORD *)(v11 + 6444) = -1;
  *(_DWORD *)(v11 + 6452) = -1;
  *(_DWORD *)(v11 + 6460) = -1;
  *(_DWORD *)(v11 + 6468) = -1;
  *(_DWORD *)(v11 + 6476) = -1;
  *(_DWORD *)(v11 + 6484) = -1;
  *(_DWORD *)(v11 + 6492) = -1;
  *(_DWORD *)(v11 + 6500) = -1;
  *(_DWORD *)(v11 + 6508) = -1;
  *(_DWORD *)(v11 + 6516) = -1;
  *(_DWORD *)(v11 + 6524) = -1;
  *(_DWORD *)(v11 + 6532) = -1;
  *(_DWORD *)(v11 + 6540) = -1;
  *(_DWORD *)(v11 + 6548) = -1;
  v189 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v189 + 9776), (__int64)&s, 40, &stringp);
  v190 = stringp;
  if ( (unsigned __int64)stringp >= 2 )
  {
    v191 = 0;
    while ( v191 <= 0x27 )
    {
      v193 = *((unsigned __int8 *)&s + v191);
      if ( (unsigned int)(v193 - 1) <= 0x12 )
      {
        v194 = (_DWORD *)(v11 + 6396 + 8 * v193);
        *v194 = *((unsigned __int8 *)&s + v191 + 1);
        v194[1] = v193;
      }
      v192 = v191 + 3;
      v191 += 2LL;
      if ( (unsigned __int64)v190 <= v192 )
        goto LABEL_84;
    }
    goto LABEL_126;
  }
LABEL_84:
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj && (*(_BYTE *)(cmpt_obj + 2000) & 4) != 0 )
  {
    v196 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9768);
    *(_DWORD *)(v11 + 6512) = 14;
    *(_DWORD *)(v11 + 6508) = v196;
    v197 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9772);
    *(_DWORD *)(v11 + 6480) = 10;
    *(_DWORD *)(v11 + 6476) = v197;
  }
  v198 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9756);
  *(_DWORD *)(v11 + 6560) = 13;
  *(_DWORD *)(v11 + 6556) = v198;
  v199 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9760);
  *(_DWORD *)(v11 + 6568) = 2;
  *(_DWORD *)(v11 + 6564) = v199;
  v200 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9764);
  *(_DWORD *)(v11 + 6576) = 4;
  *(_DWORD *)(v11 + 6572) = v200;
  s = nullptr;
  v287 = 0;
  stringp = nullptr;
  v201 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9148);
  *(_DWORD *)(v11 + 6580) = v201;
  if ( (unsigned int)(v201 - 5) > 0xFFFFFFFB )
  {
    v212 = cfg_psoc_get_values(a1);
    if ( !(unsigned int)qdf_uint32_array_parse((_BYTE *)(v212 + 9152), (__int64)&s, 4, &stringp)
      && stringp == (_BYTE *)&off_0 + 4 )
    {
      v213 = HIDWORD(s);
      v214 = v287;
      v215 = HIDWORD(v287);
      v216 = *(unsigned int *)(v11 + 6580);
      *(_DWORD *)(v11 + 6584) = (_DWORD)s;
      *(_DWORD *)(v11 + 6588) = v213;
      *(_DWORD *)(v11 + 6592) = v214;
      *(_DWORD *)(v11 + 6596) = v215;
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: Ratemask type: %d, masks:0x%x, 0x%x, 0x%x, 0x%x",
        v202,
        v203,
        v204,
        v205,
        v206,
        v207,
        v208,
        v209,
        "mlme_init_ratemask_cfg",
        v216,
        v215);
      goto LABEL_94;
    }
    v210 = "%s: Failed to parse ratemask";
    v211 = 2;
    *(_DWORD *)(v11 + 6580) = 0;
  }
  else
  {
    v210 = "%s: Ratemask disabled";
    v211 = 8;
  }
  qdf_trace_msg(0x1Fu, v211, v210, v202, v203, v204, v205, v206, v207, v208, v209, "mlme_init_ratemask_cfg");
LABEL_94:
  LODWORD(stringp) = 0;
  v285 = 0;
  v217 = cfg_psoc_get_values(a1);
  v218 = (const void *)(v217 + 8629);
  if ( v217 == -8629 )
    goto LABEL_124;
  v219 = strlen((const char *)(v217 + 8629));
  v220 = v219;
  if ( !v219 )
    goto LABEL_124;
  v221 = (char *)_qdf_mem_malloc(v219 + 1, "mlme_iot_parse_aggr_info", 4185);
  if ( !v221 )
    goto LABEL_124;
  v222 = v221;
  qdf_mem_copy(v221, v218, v220);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: aggr_info=[%s]",
    v223,
    v224,
    v225,
    v226,
    v227,
    v228,
    v229,
    v230,
    "mlme_iot_parse_aggr_info",
    v222);
  v231 = 0;
  s = v222;
  v232 = v222;
  while ( 1 )
  {
    if ( *v232 == 32 )
    {
      v233 = v232 + 1;
      do
      {
        s = v233;
        v234 = (unsigned __int8)*v233++;
      }
      while ( v234 == 32 );
    }
    v235 = strsep(&s, ",");
    if ( !v235 )
    {
      v280 = "%s: oui error";
LABEL_118:
      qdf_trace_msg(0x1Fu, 2u, v280, v236, v237, v238, v239, v240, v241, v242, v243, "mlme_iot_parse_aggr_info");
      goto LABEL_123;
    }
    v244 = v235;
    v245 = strlen(v235);
    v246 = (unsigned int)(v245 >> 1);
    if ( v246 >= 5 )
    {
      v280 = "%s: size error";
      goto LABEL_118;
    }
    v247 = v245;
    v285 = 0;
    v248 = strsep(&s, ",");
    if ( !v248 )
    {
      v280 = "%s: msdu error";
      goto LABEL_118;
    }
    v249 = v248;
    if ( (unsigned int)kstrtouint(v248, 10, &v285) || v285 >= 7 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: invalid msdu no. %s [%u]",
        v250,
        v251,
        v252,
        v253,
        v254,
        v255,
        v256,
        v257,
        "mlme_iot_parse_aggr_info",
        v249,
        v285);
      goto LABEL_123;
    }
    LODWORD(stringp) = 0;
    v258 = strsep(&s, ",");
    if ( !v258 )
    {
      v280 = "%s: mpdu error";
      goto LABEL_118;
    }
    v259 = v258;
    if ( (unsigned int)kstrtouint(v258, 10, &stringp) || (unsigned int)stringp >= 0x201 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: invalid mpdu no. %s [%u]",
        v260,
        v261,
        v262,
        v263,
        v264,
        v265,
        v266,
        v267,
        "mlme_iot_parse_aggr_info",
        v259,
        (unsigned int)stringp);
      goto LABEL_123;
    }
    v268 = v247 >> 1;
    LODWORD(v282) = (_DWORD)stringp;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: id %u oui[%s] len %u msdu %u mpdu %u",
      v260,
      v261,
      v262,
      v263,
      v264,
      v265,
      v266,
      v267,
      "mlme_iot_parse_aggr_info",
      (unsigned int)v231,
      v244,
      (unsigned int)v268,
      v285,
      v282);
    v269 = (_DWORD *)(v11 + 6600 + 16 * v231);
    v270 = hex2bin(v269, v244, v246);
    if ( v270 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: oui error: %d",
        v271,
        v272,
        v273,
        v274,
        v275,
        v276,
        v277,
        v278,
        "mlme_iot_parse_aggr_info",
        v270);
      goto LABEL_123;
    }
    v269[3] = v285;
    v279 = (int)stringp;
    v269[1] = v268;
    v269[2] = v279;
    if ( v231 == 31 )
      break;
    v232 = s;
    ++v231;
    if ( !s )
      goto LABEL_122;
  }
  LODWORD(v231) = 32;
  qdf_trace_msg(
    0x1Fu,
    2u,
    "%s: exceed max num, index = %d",
    v271,
    v272,
    v273,
    v274,
    v275,
    v276,
    v277,
    v278,
    "mlme_iot_parse_aggr_info",
    32);
LABEL_122:
  *(_DWORD *)(v11 + 7112) = v231;
LABEL_123:
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: configured aggr num %d",
    v271,
    v272,
    v273,
    v274,
    v275,
    v276,
    v277,
    v278,
    "mlme_iot_parse_aggr_info",
    *(unsigned int *)(v11 + 7112));
  _qdf_mem_free((__int64)v222);
LABEL_124:
  *(_WORD *)(v11 + 1104) = -255;
  *(_WORD *)(v11 + 1120) = -256;
  *(_DWORD *)(v11 + 1116) = 17;
  v281 = cfg_psoc_get_values(a1);
  result = 0;
  *(_BYTE *)(v11 + 7121) = *(_BYTE *)(v281 + 7513);
LABEL_125:
  _ReadStatusReg(SP_EL0);
  return result;
}
