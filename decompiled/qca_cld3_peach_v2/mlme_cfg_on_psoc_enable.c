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
  __int16 v66; // w8
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
  __int64 v82; // x0
  unsigned __int64 v83; // x9
  unsigned __int64 v84; // x8
  int v85; // w9
  char v86; // w8
  int v87; // w9
  int v88; // w8
  int v89; // w8
  __int64 v90; // x0
  __int64 v91; // x4
  __int64 v92; // x5
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  char epcs_capability; // w0
  int v102; // w8
  __int64 v103; // x0
  int v104; // w8
  int v105; // w8
  int v106; // w8
  __int64 v107; // x0
  char v108; // w8
  int v109; // w8
  char v110; // w8
  char v111; // w8
  int v112; // w8
  int v113; // w8
  int v114; // w8
  __int64 v115; // x0
  void *v116; // x22
  _DWORD *v117; // x25
  __int64 v118; // x0
  unsigned __int8 v119; // w28
  unsigned __int8 v120; // w21
  __int64 v121; // x8
  char *v122; // x0
  const char *v123; // x26
  char *v124; // x0
  unsigned __int64 v125; // x10
  unsigned __int64 v126; // x9
  int *v127; // x12
  int v128; // t1
  unsigned int *v129; // x9
  __int64 result; // x0
  char v131; // w8
  char v132; // w9
  __int64 v133; // x0
  int v134; // w21
  char v135; // w22
  char v136; // w23
  char v137; // w25
  char v138; // w26
  char v139; // w27
  char v140; // w8
  unsigned int v141; // w21
  __int64 v142; // x0
  __int64 v143; // x0
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  int v152; // w5
  __int64 v153; // x0
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  int v162; // w5
  __int64 v163; // x0
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  int v172; // w5
  __int64 v173; // x0
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  int v182; // w5
  __int64 v183; // x0
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  __int64 v192; // x0
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  char *v201; // x8
  unsigned __int64 v202; // x25
  int v203; // w8
  int v204; // w1
  int v205; // w8
  __int64 v206; // x0
  char *v207; // x8
  unsigned __int64 v208; // x9
  unsigned __int64 v209; // x11
  __int64 v210; // x11
  _DWORD *v211; // x13
  __int64 cmpt_obj; // x0
  int v213; // w9
  int v214; // w9
  int v215; // w9
  int v216; // w9
  int v217; // w9
  int v218; // w8
  double v219; // d0
  double v220; // d1
  double v221; // d2
  double v222; // d3
  double v223; // d4
  double v224; // d5
  double v225; // d6
  double v226; // d7
  const char *v227; // x2
  unsigned int v228; // w1
  __int64 v229; // x0
  int v230; // w6
  int v231; // w7
  int v232; // w8
  __int64 v233; // x4
  __int64 v234; // x0
  const void *v235; // x22
  unsigned int v236; // w0
  unsigned int v237; // w23
  char *v238; // x0
  char *v239; // x21
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  __int64 v248; // x22
  char *v249; // x8
  char *v250; // x8
  int v251; // t1
  char *v252; // x0
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  char *v261; // x26
  size_t v262; // x0
  unsigned __int64 v263; // x27
  size_t v264; // x28
  char *v265; // x0
  char *v266; // x25
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  char *v275; // x0
  char *v276; // x25
  double v277; // d0
  double v278; // d1
  double v279; // d2
  double v280; // d3
  double v281; // d4
  double v282; // d5
  double v283; // d6
  double v284; // d7
  size_t v285; // x28
  _DWORD *v286; // x25
  unsigned int v287; // w0
  double v288; // d0
  double v289; // d1
  double v290; // d2
  double v291; // d3
  double v292; // d4
  double v293; // d5
  double v294; // d6
  double v295; // d7
  int v296; // w8
  const char *v297; // x2
  __int64 v298; // x8
  __int64 v299; // [xsp+0h] [xbp-90h]
  __int64 v300; // [xsp+30h] [xbp-60h] BYREF
  char *stringp; // [xsp+38h] [xbp-58h] BYREF
  unsigned int v302; // [xsp+44h] [xbp-4Ch] BYREF
  char *s; // [xsp+48h] [xbp-48h] BYREF
  __int64 v304; // [xsp+50h] [xbp-40h]
  __int64 v305; // [xsp+58h] [xbp-38h]
  __int64 v306; // [xsp+60h] [xbp-30h]
  __int64 v307; // [xsp+68h] [xbp-28h]
  __int64 v308; // [xsp+70h] [xbp-20h]
  __int64 v309; // [xsp+78h] [xbp-18h]
  __int64 v310; // [xsp+80h] [xbp-10h]
  __int64 v311; // [xsp+88h] [xbp-8h]

  v311 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: Failed to get MLME Obj", v3, v4, v5, v6, v7, v8, v9, v10, "mlme_cfg_on_psoc_enable");
    result = 16;
    goto LABEL_125;
  }
  v11 = ext_hdl;
  *(_BYTE *)(ext_hdl + 1049) = 1;
  *(_BYTE *)(ext_hdl + 1048) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7448);
  v12 = *(_DWORD *)(cfg_psoc_get_values(a1) + 7452);
  if ( v12 )
    v13 = v12;
  else
    v13 = 7;
  *(_DWORD *)(v11 + 1032) = v13;
  *(_DWORD *)(v11 + 1036) = v13;
  *(_BYTE *)(v11 + 1040) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7460);
  *(_BYTE *)(v11 + 1041) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7480);
  *(_BYTE *)(v11 + 1042) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7492);
  *(_WORD *)(v11 + 1046) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7488);
  *(_BYTE *)(v11 + 1050) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7456);
  *(_BYTE *)(v11 + 1051) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7464);
  *(_BYTE *)(v11 + 1052) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7465);
  *(_BYTE *)(v11 + 1053) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7466);
  *(_BYTE *)(v11 + 1055) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7468);
  *(_BYTE *)(v11 + 1056) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7476);
  *(_BYTE *)(v11 + 1057) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7477);
  *(_BYTE *)(v11 + 1058) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7484);
  *(_BYTE *)(v11 + 1059) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7485);
  *(_BYTE *)(v11 + 1060) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7432);
  *(_BYTE *)(v11 + 1063) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7469);
  *(_BYTE *)(v11 + 1088) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7516);
  *(_BYTE *)(v11 + 1043) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7436);
  *(_WORD *)(v11 + 1044) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7440);
  *(_DWORD *)(v11 + 1132) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7444);
  v14 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7467);
  *(_WORD *)(v11 + 1089) = -256;
  *(_BYTE *)(v11 + 1054) = v14;
  *(_BYTE *)(v11 + 1061) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7449);
  *(_BYTE *)(v11 + 1062) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7450);
  *(_BYTE *)(v11 + 1064) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7496);
  *(_DWORD *)(v11 + 1068) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7472);
  *(_BYTE *)(v11 + 1073) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7500);
  *(_BYTE *)(v11 + 1075) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7505);
  *(_BYTE *)(v11 + 1076) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7506);
  *(_BYTE *)(v11 + 1077) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4464);
  *(_BYTE *)(v11 + 1078) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7508);
  *(_DWORD *)(v11 + 1084) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7512);
  *(_DWORD *)(v11 + 1092) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7520);
  *(_DWORD *)(v11 + 1108) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7524);
  *(_BYTE *)(v11 + 1074) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7504);
  v15 = *(_DWORD *)(cfg_psoc_get_values(a1) + 7596);
  stringp = nullptr;
  v309 = 0;
  v310 = 0;
  *(_DWORD *)(v11 + 1148) = v15;
  v307 = 0;
  v308 = 0;
  v305 = 0;
  v306 = 0;
  s = nullptr;
  v304 = 0;
  values = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(values + 7528), (__int64)&s, 64, &stringp);
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
  *(_BYTE *)(v11 + 1120) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8653);
  *(_BYTE *)(v11 + 1129) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7594);
  *(_DWORD *)(v11 + 1124) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7600);
  *(_BYTE *)(v11 + 1115) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7593);
  *(_BYTE *)(v11 + 1285) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7605);
  *(_BYTE *)(v11 + 1130) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7604);
  v29 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10132);
  *(_DWORD *)(v11 + 3684) = 200;
  *(_DWORD *)(v11 + 3680) = v29;
  *(_DWORD *)(v11 + 3688) = v29;
  *(_DWORD *)(v11 + 3692) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10136);
  *(_DWORD *)(v11 + 3696) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10140);
  *(_DWORD *)(v11 + 3700) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10144);
  *(_DWORD *)(v11 + 3704) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10148);
  *(_DWORD *)(v11 + 3708) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10152);
  *(_DWORD *)(v11 + 3712) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10156);
  *(_DWORD *)(v11 + 3716) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10160);
  *(_DWORD *)(v11 + 3720) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10164);
  *(_DWORD *)(v11 + 3724) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10168);
  *(_DWORD *)(v11 + 3728) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10172);
  *(_DWORD *)(v11 + 3732) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10176);
  v30 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10180);
  *(_QWORD *)(v11 + 56) = 17;
  *(_QWORD *)(v11 + 16) = 17;
  *(_QWORD *)(v11 + 96) = 17;
  *(_DWORD *)(v11 + 3736) = v30;
  *(_QWORD *)(v11 + 136) = 17;
  *(_QWORD *)(v11 + 216) = 17;
  *(_QWORD *)(v11 + 176) = 17;
  *(_QWORD *)(v11 + 256) = 17;
  *(_QWORD *)(v11 + 296) = 17;
  v31 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v31 + 5100), v11 + 32, 17, (_QWORD *)(v11 + 24));
  v32 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v32 + 5188), v11 + 72, 17, (_QWORD *)(v11 + 64));
  v33 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v33 + 5279), v11 + 112, 17, (_QWORD *)(v11 + 104));
  v34 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v34 + 5367), v11 + 152, 17, (_QWORD *)(v11 + 144));
  v35 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v35 + 5454), v11 + 192, 17, (_QWORD *)(v11 + 184));
  v36 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v36 + 5542), v11 + 232, 17, (_QWORD *)(v11 + 224));
  v37 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v37 + 5633), v11 + 272, 17, (_QWORD *)(v11 + 264));
  v38 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v38 + 5721), v11 + 312, 17, (_QWORD *)(v11 + 304));
  *(_QWORD *)(v11 + 336) = 17;
  *(_QWORD *)(v11 + 376) = 17;
  *(_QWORD *)(v11 + 416) = 17;
  *(_QWORD *)(v11 + 456) = 17;
  *(_QWORD *)(v11 + 496) = 17;
  *(_QWORD *)(v11 + 536) = 17;
  *(_QWORD *)(v11 + 576) = 17;
  *(_QWORD *)(v11 + 616) = 17;
  v39 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v39 + 5808), v11 + 352, 17, (_QWORD *)(v11 + 344));
  v40 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v40 + 5896), v11 + 392, 17, (_QWORD *)(v11 + 384));
  v41 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v41 + 5984), v11 + 432, 17, (_QWORD *)(v11 + 424));
  v42 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v42 + 6071), v11 + 472, 17, (_QWORD *)(v11 + 464));
  v43 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v43 + 6158), v11 + 512, 17, (_QWORD *)(v11 + 504));
  v44 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v44 + 6245), v11 + 552, 17, (_QWORD *)(v11 + 544));
  v45 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v45 + 6332), v11 + 592, 17, (_QWORD *)(v11 + 584));
  v46 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v46 + 6419), v11 + 632, 17, (_QWORD *)(v11 + 624));
  *(_QWORD *)(v11 + 696) = 17;
  *(_QWORD *)(v11 + 656) = 17;
  *(_QWORD *)(v11 + 736) = 17;
  *(_QWORD *)(v11 + 776) = 17;
  *(_QWORD *)(v11 + 856) = 17;
  *(_QWORD *)(v11 + 816) = 17;
  *(_QWORD *)(v11 + 896) = 17;
  *(_QWORD *)(v11 + 936) = 17;
  v47 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v47 + 6506), v11 + 672, 17, (_QWORD *)(v11 + 664));
  v48 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v48 + 6595), v11 + 712, 17, (_QWORD *)(v11 + 704));
  v49 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v49 + 6684), v11 + 752, 17, (_QWORD *)(v11 + 744));
  v50 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v50 + 6771), v11 + 792, 17, (_QWORD *)(v11 + 784));
  v51 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v51 + 6858), v11 + 832, 17, (_QWORD *)(v11 + 824));
  v52 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v52 + 6946), v11 + 872, 17, (_QWORD *)(v11 + 864));
  v53 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v53 + 7034), v11 + 912, 17, (_QWORD *)(v11 + 904));
  v54 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v54 + 7121), v11 + 952, 17, (_QWORD *)(v11 + 944));
  *(_BYTE *)(v11 + 976) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7208);
  *(_BYTE *)(v11 + 977) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7256);
  *(_DWORD *)(v11 + 980) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7212);
  *(_DWORD *)(v11 + 984) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7216);
  *(_DWORD *)(v11 + 988) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7220);
  *(_DWORD *)(v11 + 992) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7224);
  *(_DWORD *)(v11 + 996) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7228);
  *(_DWORD *)(v11 + 1000) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7232);
  *(_DWORD *)(v11 + 1004) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7236);
  *(_DWORD *)(v11 + 1008) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7240);
  *(_DWORD *)(v11 + 1012) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7244);
  *(_DWORD *)(v11 + 1016) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7248);
  *(_DWORD *)(v11 + 1020) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7252);
  *(_DWORD *)(v11 + 1024) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7260);
  *(_DWORD *)(v11 + 1028) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7264);
  v55 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 7612);
  v56 = v55 | (*(unsigned __int8 *)(cfg_psoc_get_values(a1) + 7614) << 8);
  v57 = v56 & 0xFFFFFF7F | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 7613) & 1) << 7);
  v58 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7615);
  LOWORD(v57) = v57 & 0xFF9F | (32 * (v58 & 1)) & 0xBF | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 7616) & 1) << 6);
  v59 = v11 + 1291;
  *(_WORD *)(v11 + 1288) = v57 & 0xFFF3 | (4 * (*(_WORD *)(cfg_psoc_get_values(a1) + 7620) & 3));
  *(_BYTE *)(v11 + 1290) = *(_BYTE *)(v11 + 1290) & 0xFC | *(_BYTE *)(cfg_psoc_get_values(a1) + 7628) & 3;
  v60 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7632);
  v61 = *(_BYTE *)(v11 + 1290) & 3;
  *(_WORD *)(v11 + 1291) = 1024;
  *(_BYTE *)(v11 + 1293) = 15;
  *(_DWORD *)(v11 + 1294) = 0;
  *(_BYTE *)(v11 + 1290) = v61 & 0xE3 | (4 * (v60 & 7));
  *(_BYTE *)(v11 + 1298) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7617);
  *(_BYTE *)(v11 + 1299) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7416);
  *(_BYTE *)(v11 + 1300) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7618);
  *(_BYTE *)(v11 + 1301) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7620);
  *(_BYTE *)(v11 + 1302) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7624);
  *(_BYTE *)(v11 + 1303) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7608);
  v62 = *(_BYTE *)(cfg_psoc_get_values(a1) + 7636);
  *(_DWORD *)(v11 + 5668) = 256;
  *(_DWORD *)(v11 + 5672) = 1;
  *(_BYTE *)(v11 + 1304) = v62;
  *(_BYTE *)(v11 + 5696) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10284);
  *(_WORD *)(v11 + 5698) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10288);
  *(_DWORD *)(v11 + 5700) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10292);
  *(_DWORD *)(v11 + 5704) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10296);
  *(_WORD *)(v11 + 5708) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10300);
  *(_DWORD *)(v11 + 5712) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10304);
  *(_DWORD *)(v11 + 5716) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10308);
  *(_BYTE *)(v11 + 5720) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10312);
  *(_WORD *)(v11 + 5722) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10316);
  *(_DWORD *)(v11 + 5724) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10320);
  *(_DWORD *)(v11 + 5728) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10324);
  *(_WORD *)(v11 + 5732) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10328);
  *(_DWORD *)(v11 + 5736) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10332);
  *(_DWORD *)(v11 + 5740) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10336);
  *(_BYTE *)(v11 + 5744) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10340);
  *(_WORD *)(v11 + 5746) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10344);
  *(_DWORD *)(v11 + 5748) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10348);
  *(_DWORD *)(v11 + 5752) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10352);
  *(_WORD *)(v11 + 5756) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10356);
  *(_DWORD *)(v11 + 5760) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10360);
  *(_DWORD *)(v11 + 5764) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10364);
  *(_BYTE *)(v11 + 5768) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10368);
  *(_WORD *)(v11 + 5770) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10372);
  *(_DWORD *)(v11 + 5772) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10376);
  *(_DWORD *)(v11 + 5776) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10380);
  *(_WORD *)(v11 + 5780) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10384);
  *(_DWORD *)(v11 + 5784) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10388);
  *(_DWORD *)(v11 + 5788) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10392);
  *(_BYTE *)(v11 + 5676) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10396);
  *(_BYTE *)(v11 + 5677) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10400);
  *(_BYTE *)(v11 + 5678) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10404);
  *(_DWORD *)(v11 + 5680) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10408);
  *(_BYTE *)(v11 + 5684) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10412);
  *(_DWORD *)(v11 + 5688) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10416);
  *(_BYTE *)(v11 + 5692) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10420);
  *(_DWORD *)(v11 + 5792) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10424);
  *(_BYTE *)(v11 + 2816) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8504);
  *(_BYTE *)(v11 + 2817) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8508);
  *(_BYTE *)(v11 + 2818) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8512);
  *(_BYTE *)(v11 + 2819) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8516);
  *(_DWORD *)(v11 + 2892) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8656);
  *(_DWORD *)(v11 + 2896) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8660);
  *(_DWORD *)(v11 + 2900) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8664);
  *(_DWORD *)(v11 + 2904) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8668);
  *(_DWORD *)(v11 + 2908) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8672);
  *(_DWORD *)(v11 + 2912) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8676);
  *(_DWORD *)(v11 + 2916) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8680);
  *(_DWORD *)(v11 + 2920) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8684);
  *(_DWORD *)(v11 + 2924) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8688);
  *(_DWORD *)(v11 + 2928) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8692);
  *(_DWORD *)(v11 + 2932) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8696);
  *(_DWORD *)(v11 + 2936) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8700);
  *(_DWORD *)(v11 + 2940) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8704);
  *(_DWORD *)(v11 + 2944) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8708);
  *(_DWORD *)(v11 + 2948) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8712);
  *(_DWORD *)(v11 + 2952) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8716);
  *(_BYTE *)(v11 + 2956) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8654);
  v63 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8720);
  *(_BYTE *)(v11 + 2960) = 1;
  *(_WORD *)(v11 + 2962) = 30000;
  *(_BYTE *)(v11 + 2957) = v63;
  *(_WORD *)(v11 + 2964) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9224);
  *(_BYTE *)(v11 + 2966) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9228);
  *(_WORD *)(v11 + 2968) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9232);
  v64 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9236);
  *(_QWORD *)(v11 + 2976) = 4;
  *(_BYTE *)(v11 + 2970) = v64;
  qdf_uint8_array_parse("2, 4, 11, 22", v11 + 2992, 17, (_QWORD *)(v11 + 2984));
  *(_QWORD *)(v11 + 3016) = 8;
  qdf_uint8_array_parse("12, 18, 24, 36, 48, 72, 96, 108", v11 + 3032, 17, (_QWORD *)(v11 + 3024));
  *(_QWORD *)(v11 + 3056) = 16;
  qdf_uint8_array_parse(
    "0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0",
    v11 + 3072,
    17,
    (_QWORD *)(v11 + 3064));
  *(_QWORD *)(v11 + 3096) = 16;
  qdf_uint8_array_parse(
    "0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0",
    v11 + 3112,
    17,
    (_QWORD *)(v11 + 3104));
  *(_QWORD *)(v11 + 3136) = 16;
  qdf_uint8_array_parse(
    "0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0",
    v11 + 3152,
    17,
    (_QWORD *)(v11 + 3144));
  *(_BYTE *)(v11 + 3370) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5069);
  *(_BYTE *)(v11 + 3368) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5081);
  *(_BYTE *)(v11 + 3369) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5070);
  *(_BYTE *)(v11 + 3371) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5083);
  *(_BYTE *)(v11 + 3373) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5080);
  *(_BYTE *)(v11 + 3372) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5071);
  *(_BYTE *)(v11 + 3374) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5082);
  *(_DWORD *)(v11 + 3376) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5072);
  *(_DWORD *)(v11 + 3380) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5076);
  *(_BYTE *)(v11 + 3375) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5084);
  *(_BYTE *)(v11 + 3384) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5088);
  v65 = *(_DWORD *)(cfg_psoc_get_values(a1) + 5092);
  *(_DWORD *)(v11 + 3396) = 0xFFFF;
  *(_BYTE *)(v11 + 7338) = v65;
  *(_BYTE *)(v11 + 3390) = 5;
  *(_BYTE *)(v11 + 3388) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9817);
  *(_BYTE *)(v11 + 3389) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9824);
  *(_BYTE *)(v11 + 3391) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9818);
  v66 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9820);
  *(_BYTE *)(v11 + 2820) = 0;
  *(_WORD *)(v11 + 3392) = v66;
  *(_QWORD *)(v11 + 2844) = 0x30C0000030CLL;
  *(_DWORD *)(v11 + 2831) = 0x1000000;
  *(_QWORD *)(v11 + 2836) = 0xFFFE0000FFFELL;
  *(_BYTE *)(v11 + 2835) = 1;
  *(_BYTE *)(v11 + 2829) = 0;
  *(_DWORD *)(v11 + 2852) = 65534;
  *(_BYTE *)(v11 + 2828) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10216);
  *(_BYTE *)(v11 + 2856) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10221);
  *(_BYTE *)(v11 + 2878) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10264);
  *(_BYTE *)(v11 + 2821) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7612);
  *(_BYTE *)(v11 + 2822) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7616);
  *(_BYTE *)(v11 + 2823) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7616);
  *(_BYTE *)(v11 + 2824) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7613);
  *(_BYTE *)(v11 + 2825) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7614);
  v67 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10212);
  *(_BYTE *)(v11 + 2830) = 0;
  *(_BYTE *)(v11 + 2827) = v67;
  *(_BYTE *)(v11 + 2872) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10252);
  *(_BYTE *)(v11 + 2877) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10260);
  *(_BYTE *)(v11 + 2857) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10224);
  *(_DWORD *)(v11 + 2860) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10228);
  *(_DWORD *)(v11 + 2864) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10232);
  *(_BYTE *)(v11 + 2868) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10236);
  *(_BYTE *)(v11 + 2869) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10240);
  *(_BYTE *)(v11 + 2870) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10244);
  *(_BYTE *)(v11 + 2871) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10248);
  *(_BYTE *)(v11 + 2873) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10253);
  *(_BYTE *)(v11 + 2874) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10254);
  *(_BYTE *)(v11 + 2875) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10255);
  *(_BYTE *)(v11 + 2876) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10256);
  *(_BYTE *)(v11 + 2879) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10268);
  v68 = cfg_psoc_get_values(a1);
  v69 = *(unsigned __int8 *)(v11 + 2871);
  *(_BYTE *)(v11 + 2880) = *(_BYTE *)(v68 + 10269);
  if ( v69 )
  {
    v70 = cfg_psoc_get_values(a1);
    v71 = *(unsigned __int8 *)(v11 + 2871);
    v72 = *(unsigned __int8 *)(v70 + 10220);
    *(_BYTE *)(v11 + 2826) = v72;
    if ( v71 )
    {
      if ( v72 )
        *(_BYTE *)(v11 + 2829) = 1;
    }
  }
  *(_WORD *)(v11 + 2881) = 0;
  *(_BYTE *)(v11 + 2883) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10270);
  *(_BYTE *)v11 = *(_DWORD *)(cfg_psoc_get_values(a1) + 5028);
  *(_BYTE *)(v11 + 1) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5032);
  *(_BYTE *)(v11 + 2) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5036);
  *(_BYTE *)(v11 + 3) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5040);
  *(_WORD *)(v11 + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5044);
  *(_WORD *)(v11 + 6) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5048);
  *(_BYTE *)(v11 + 8) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5052);
  *(_BYTE *)(v11 + 9) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5056);
  *(_BYTE *)(v11 + 10) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5060);
  *(_BYTE *)(v11 + 11) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5064);
  *(_BYTE *)(v11 + 12) = *(_BYTE *)(cfg_psoc_get_values(a1) + 5068);
  v73 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9736);
  *(_DWORD *)(v11 + 3402) = 65537;
  *(_WORD *)(v11 + 3400) = v73;
  *(_WORD *)(v11 + 3406) = 2560;
  *(_BYTE *)(v11 + 3408) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9740);
  *(_BYTE *)(v11 + 3409) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9744);
  *(_BYTE *)(v11 + 3410) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9748);
  *(_BYTE *)(v11 + 3411) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9752);
  *(_BYTE *)(v11 + 3412) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9756);
  *(_BYTE *)(v11 + 3413) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9760);
  *(_BYTE *)(v11 + 3414) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9768);
  *(_BYTE *)(v11 + 3415) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9769);
  *(_BYTE *)(v11 + 3416) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9772);
  *(_BYTE *)(v11 + 3417) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9776);
  *(_BYTE *)(v11 + 3418) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9780);
  *(_BYTE *)(v11 + 3419) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9784);
  *(_BYTE *)(v11 + 3421) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9788);
  *(_BYTE *)(v11 + 3420) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9789);
  *(_BYTE *)(v11 + 3422) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9790);
  *(_BYTE *)(v11 + 3423) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9792);
  *(_BYTE *)(v11 + 3424) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9796);
  *(_BYTE *)(v11 + 3425) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9800);
  *(_BYTE *)(v11 + 3426) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9804);
  *(_BYTE *)(v11 + 3427) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9808);
  *(_BYTE *)(v11 + 3428) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9810);
  *(_BYTE *)(v11 + 3429) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9734);
  *(_BYTE *)(v11 + 3430) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9764);
  *(_BYTE *)(v11 + 3431) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9809);
  *(_BYTE *)(v11 + 3432) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9811);
  *(_BYTE *)(v11 + 3433) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9733);
  *(_BYTE *)(v11 + 3434) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9812);
  *(_BYTE *)(v11 + 3435) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9813);
  *(_BYTE *)(v11 + 3436) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9815);
  *(_BYTE *)(v11 + 3437) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9816);
  *(_WORD *)(v11 + 3440) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7664);
  *(_BYTE *)(v11 + 3439) = *(_BYTE *)(cfg_psoc_get_values(a1) + 3998);
  *(_DWORD *)(v11 + 3452) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8560);
  *(_DWORD *)(v11 + 3456) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8564);
  *(_DWORD *)(v11 + 3444) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8552);
  *(_DWORD *)(v11 + 3448) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8556);
  *(_DWORD *)(v11 + 3460) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8572);
  *(_DWORD *)(v11 + 3464) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8568);
  *(_DWORD *)(v11 + 3468) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8580);
  *(_DWORD *)(v11 + 3472) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8576);
  *(_DWORD *)(v11 + 3476) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8584);
  *(_DWORD *)(v11 + 3480) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8588);
  *(_DWORD *)(v11 + 3484) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8592);
  *(_BYTE *)(v11 + 3488) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8597);
  *(_BYTE *)(v11 + 3489) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8599);
  *(_BYTE *)(v11 + 3490) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8596);
  *(_BYTE *)(v11 + 3491) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8598);
  *(_BYTE *)(v11 + 3492) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8600);
  *(_BYTE *)(v11 + 3493) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8601);
  *(_BYTE *)(v11 + 3494) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8602);
  *(_DWORD *)(v11 + 3496) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8604);
  v74 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10196);
  *(_BYTE *)(v11 + 3740) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10184);
  *(_DWORD *)(v11 + 3752) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10192);
  v75 = *(_BYTE *)(cfg_psoc_get_values(a1) + 10200);
  *(_BYTE *)(v11 + 3742) = v74 & 1;
  *(_BYTE *)(v11 + 3741) = (v74 & 2) != 0;
  *(_BYTE *)(v11 + 3757) = v75;
  v76 = cfg_psoc_get_values(a1);
  v77 = *(_QWORD *)(v11 + 1309) & 0xFFFFFFFFFFFFFFFELL;
  *(_BYTE *)(v11 + 3759) = *(_BYTE *)(v76 + 10202);
  *(_QWORD *)(v11 + 1309) = v77;
  *(_QWORD *)(v11 + 1309) = *(_QWORD *)(v11 + 1309) & 0xFFFFFFFFFFFFFFFDLL
                          | (2LL * (*(_BYTE *)(cfg_psoc_get_values(a1) + 10185) & 1));
  *(_QWORD *)(v11 + 1309) = *(_QWORD *)(v11 + 1309) & 0xFFFFFFFFFFEFFFFBLL
                          | (4LL * (*(_DWORD *)(cfg_psoc_get_values(a1) + 10188) != 0));
  v78 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 10184);
  v79 = *(_QWORD *)(v11 + 1309);
  if ( v78 )
    v79 |= 0x40000000uLL;
  *(_QWORD *)(v11 + 1309) = v79 & 0xFE02008041100007LL | 0x18000800;
  v80 = *(_QWORD *)(v11 + 1309) & 0x1FFFFFFFFFFFFFFLL
      | ((unsigned __int64)(*(_DWORD *)(cfg_psoc_get_values(a1) + 7644) & 0xF) << 57);
  *(_QWORD *)(v11 + 1317) &= 0xFFFFFFFFFFFFFF80LL;
  *(_QWORD *)(v11 + 1309) = v80;
  v81 = *(_QWORD *)(v11 + 1317) & 0xC0007FLL
      | ((unsigned __int64)(*(_DWORD *)(cfg_psoc_get_values(a1) + 7648) & 3) << 7);
  *(_BYTE *)(v11 + 1325) &= ~1u;
  *(_QWORD *)(v11 + 1317) = v81;
  *(_WORD *)(v11 + 1328) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7652);
  *(_WORD *)(v11 + 1330) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7656);
  LOWORD(s) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7660);
  qdf_mem_copy((void *)(v11 + 1332), &s, 2u);
  LOWORD(s) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7668);
  qdf_mem_copy((void *)(v11 + 1334), &s, 2u);
  LOWORD(s) = -256;
  qdf_mem_copy((void *)(v11 + 1336), &s, 2u);
  LOWORD(s) = -256;
  qdf_mem_copy((void *)(v11 + 1338), &s, 2u);
  *(_DWORD *)(v11 + 1480) = 65532;
  *(_BYTE *)(v11 + 1484) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7672);
  *(_BYTE *)(v11 + 1485) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7676);
  *(_BYTE *)(v11 + 1486) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7677);
  *(_DWORD *)(v11 + 1488) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7680);
  qdf_mem_set((void *)(v11 + 1428), 0x19u, 0);
  qdf_mem_set((void *)(v11 + 1453), 0x19u, 0);
  *(_DWORD *)(v11 + 1492) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7684);
  v82 = cfg_psoc_get_values(a1);
  v83 = *(_QWORD *)(v11 + 1509) & 0xFFFFFFFFFFF8FFFFLL;
  v84 = *(_QWORD *)(v11 + 1501) & 0xFFFFFC00009FFFFFLL | 0xDB000000;
  *(_DWORD *)(v11 + 1496) = *(_DWORD *)(v82 + 7688);
  *(_QWORD *)(v11 + 1509) = v83;
  *(_QWORD *)(v11 + 1501) = v84;
  *(_DWORD *)(v11 + 2780) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8608);
  *(_DWORD *)(v11 + 2784) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8612);
  v85 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8616);
  *(_QWORD *)(v11 + 2792) = 0x14000000C8LL;
  *(_DWORD *)(v11 + 2788) = v85;
  *(_QWORD *)(v11 + 2800) = 0x1900000005LL;
  v86 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8620);
  *(_WORD *)(v11 + 2809) = 0;
  *(_BYTE *)(v11 + 2808) = v86;
  *(_BYTE *)(v11 + 2811) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8621);
  sized_strscpy(v11 + 3176, "Qualcomm Atheros", 17);
  sized_strscpy(v11 + 3304, "11n-AP", 7);
  sized_strscpy(v11 + 3336, "SN1234", 7);
  sized_strscpy(v11 + 3272, "WFR4031", 8);
  sized_strscpy(v11 + 3240, "MN1234", 7);
  *(_BYTE *)(v11 + 5632) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8633);
  *(_BYTE *)(v11 + 5633) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8634);
  *(_DWORD *)(v11 + 5636) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8636);
  *(_DWORD *)(v11 + 5640) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8640);
  *(_DWORD *)(v11 + 5644) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8644);
  *(_DWORD *)(v11 + 5648) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8648);
  *(_DWORD *)(v11 + 3500) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10024);
  *(_DWORD *)(v11 + 3504) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10028);
  *(_DWORD *)(v11 + 3508) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10032);
  *(_DWORD *)(v11 + 3512) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10036);
  *(_BYTE *)(v11 + 3532) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10040);
  *(_BYTE *)(v11 + 3531) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10044);
  *(_BYTE *)(v11 + 3533) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10048);
  *(_BYTE *)(v11 + 3534) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10049);
  *(_DWORD *)(v11 + 3524) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10052);
  *(_BYTE *)(v11 + 3535) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10060);
  *(_BYTE *)(v11 + 3536) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10061);
  *(_BYTE *)(v11 + 3528) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10068);
  *(_BYTE *)(v11 + 3530) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10056);
  *(_BYTE *)(v11 + 3537) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10072);
  v87 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10064);
  *(_DWORD *)(v11 + 3516) = 1000;
  *(_DWORD *)(v11 + 3520) = v87;
  *(_BYTE *)(v11 + 3529) = 0;
  *(_BYTE *)(v11 + 3538) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10080);
  *(_DWORD *)(v11 + 3540) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10076);
  *(_WORD *)(v11 + 3588) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10084);
  *(_BYTE *)(v11 + 3592) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10088);
  v88 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10092);
  *(_BYTE *)(v11 + 3594) = 1;
  *(_BYTE *)(v11 + 3593) = v88;
  v89 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10096);
  *(_BYTE *)(v11 + 3590) = 0;
  *(_BYTE *)(v11 + 3595) = v89;
  *(_BYTE *)(v11 + 3596) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10100);
  v90 = cfg_psoc_get_values(a1);
  v91 = *(unsigned __int8 *)(v11 + 3592);
  v92 = *(unsigned __int8 *)(v11 + 3593);
  *(_BYTE *)(v11 + 3598) = *(_BYTE *)(v90 + 10101);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: mlo_support_link_num: %d, mlo_support_link_band: 0x%x",
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    "mlme_init_sta_mlo_cfg",
    v91,
    v92);
  epcs_capability = wlan_mlme_get_epcs_capability(a1);
  wlan_mlme_set_epcs_capability(a1, epcs_capability & 1);
  wlan_mlme_set_usr_disable_sta_eht(a1, 0);
  wlan_mlme_set_eht_disable_punct_in_us_lpi(a1, 0);
  *(_DWORD *)(v11 + 3604) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10104);
  *(_DWORD *)(v11 + 3608) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10108);
  *(_DWORD *)(v11 + 3612) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10112);
  *(_DWORD *)(v11 + 3616) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10116);
  v102 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10120);
  s = nullptr;
  *(_DWORD *)(v11 + 3620) = v102;
  *(_BYTE *)(v11 + 1684) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7692);
  *(_BYTE *)(v11 + 1685) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7720);
  *(_BYTE *)(v11 + 1764) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7721);
  *(_BYTE *)(v11 + 1765) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7812);
  *(_BYTE *)(v11 + 1767) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7848);
  *(_BYTE *)(v11 + 1768) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7849);
  *(_BYTE *)(v11 + 1769) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7850);
  *(_BYTE *)(v11 + 1770) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7868);
  *(_DWORD *)(v11 + 1772) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7696);
  *(_DWORD *)(v11 + 1776) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7700);
  *(_BYTE *)(v11 + 1780) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7704);
  *(_BYTE *)(v11 + 1781) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7708);
  *(_DWORD *)(v11 + 1784) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7712);
  *(_BYTE *)(v11 + 1788) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7716);
  *(_BYTE *)(v11 + 1789) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7724);
  *(_BYTE *)(v11 + 1790) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7728);
  *(_DWORD *)(v11 + 1792) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7732);
  *(_DWORD *)(v11 + 1796) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7736);
  *(_DWORD *)(v11 + 1800) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7740);
  *(_DWORD *)(v11 + 1804) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7744);
  *(_DWORD *)(v11 + 1808) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7748);
  *(_DWORD *)(v11 + 1812) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7752);
  *(_DWORD *)(v11 + 1816) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7756);
  *(_DWORD *)(v11 + 1820) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7760);
  *(_DWORD *)(v11 + 1824) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7764);
  *(_DWORD *)(v11 + 1828) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7768);
  *(_DWORD *)(v11 + 1832) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7772);
  *(_DWORD *)(v11 + 1836) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7776);
  *(_DWORD *)(v11 + 1840) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7780);
  *(_DWORD *)(v11 + 1844) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7784);
  *(_DWORD *)(v11 + 1848) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7788);
  *(_DWORD *)(v11 + 1852) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7792);
  *(_DWORD *)(v11 + 1856) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7796);
  *(_DWORD *)(v11 + 1860) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7800);
  *(_DWORD *)(v11 + 1864) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7804);
  v103 = cfg_psoc_get_values(a1);
  v104 = *(unsigned __int8 *)(v11 + 1765);
  *(_DWORD *)(v11 + 1868) = *(_DWORD *)(v103 + 7808);
  if ( v104 == 1 )
  {
    *(_DWORD *)(v11 + 1872) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7816);
    *(_DWORD *)(v11 + 1876) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7820);
    *(_DWORD *)(v11 + 1880) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7824);
    *(_DWORD *)(v11 + 1884) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7828);
    *(_DWORD *)(v11 + 1888) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7832);
    *(_DWORD *)(v11 + 1892) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7836);
  }
  *(_DWORD *)(v11 + 1896) = 64;
  *(_DWORD *)(v11 + 1904) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7844);
  *(_DWORD *)(v11 + 1900) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7840);
  *(_BYTE *)(v11 + 1908) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7852);
  *(_BYTE *)(v11 + 1909) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7856);
  *(_BYTE *)(v11 + 1910) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7860);
  *(_BYTE *)(v11 + 1911) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7864);
  *(_BYTE *)(v11 + 1912) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7869);
  *(_DWORD *)(v11 + 1916) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8272);
  *(_DWORD *)(v11 + 1920) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8276);
  v105 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8280);
  if ( v105 < 0 )
    v105 = -v105;
  *(_DWORD *)(v11 + 1924) = v105;
  v106 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8500);
  if ( v106 < 0 )
    v106 = -v106;
  *(_BYTE *)(v11 + 2772) = v106;
  *(_DWORD *)(v11 + 1928) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8284);
  *(_DWORD *)(v11 + 1932) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8288);
  *(_DWORD *)(v11 + 2768) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10020);
  *(_WORD *)(v11 + 1936) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8292);
  *(_WORD *)(v11 + 1938) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8296);
  *(_DWORD *)(v11 + 1940) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8408);
  *(_DWORD *)(v11 + 1944) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8300);
  *(_DWORD *)(v11 + 1948) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8304);
  *(_BYTE *)(v11 + 1952) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8312);
  *(_BYTE *)(v11 + 1953) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8316);
  *(_DWORD *)(v11 + 1956) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8320);
  *(_DWORD *)(v11 + 1960) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8324);
  *(_DWORD *)(v11 + 1964) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8328);
  *(_DWORD *)(v11 + 1968) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8332);
  *(_DWORD *)(v11 + 1972) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8336);
  *(_BYTE *)(v11 + 1976) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8340);
  *(_BYTE *)(v11 + 1977) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8341);
  *(_WORD *)(v11 + 1982) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8348);
  *(_DWORD *)(v11 + 1984) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8344);
  *(_BYTE *)(v11 + 1988) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8352);
  v107 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v107 + 7870), v11 + 1989, 100, &s);
  *(_BYTE *)(v11 + 2089) = (_BYTE)s;
  *(_BYTE *)(v11 + 2091) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8376);
  *(_BYTE *)(v11 + 2092) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8380);
  *(_DWORD *)(v11 + 2096) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8384);
  *(_BYTE *)(v11 + 2100) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8388);
  *(_BYTE *)(v11 + 2101) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8389);
  *(_BYTE *)(v11 + 2132) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8390);
  *(_DWORD *)(v11 + 2136) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8392);
  *(_QWORD *)(v11 + 2140) = *(unsigned int *)(cfg_psoc_get_values(a1) + 8404);
  v108 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8400);
  *(_BYTE *)(v11 + 2756) = 0;
  *(_BYTE *)(v11 + 1980) = v108;
  *(_BYTE *)(v11 + 1714) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8433);
  *(_BYTE *)(v11 + 1715) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8472) != 0;
  *(_BYTE *)(v11 + 1716) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8476);
  *(_BYTE *)(v11 + 1717) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8434);
  *(_BYTE *)(v11 + 1740) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8480);
  *(_BYTE *)(v11 + 1718) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8435);
  *(_BYTE *)(v11 + 1719) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8436);
  *(_DWORD *)(v11 + 1720) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8440);
  *(_DWORD *)(v11 + 1752) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8492);
  *(_DWORD *)(v11 + 1724) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8444);
  *(_DWORD *)(v11 + 1728) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8452);
  *(_DWORD *)(v11 + 1736) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8456);
  v109 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8464);
  *(_DWORD *)(v11 + 1708) = 2;
  *(_DWORD *)(v11 + 1744) = v109;
  *(_DWORD *)(v11 + 1732) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8460);
  *(_DWORD *)(v11 + 1748) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8468);
  *(_BYTE *)(v11 + 2564) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8479);
  qdf_mem_set((void *)(v11 + 1712), 2u, 0);
  *(_BYTE *)(v11 + 1766) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8477);
  *(_BYTE *)(v11 + 2104) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8356);
  *(_DWORD *)(v11 + 2108) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8360);
  *(_DWORD *)(v11 + 2116) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8364);
  *(_DWORD *)(v11 + 2112) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8368);
  *(_DWORD *)(v11 + 2120) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8416);
  *(_DWORD *)(v11 + 2124) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8420);
  *(_DWORD *)(v11 + 2128) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8424);
  *(_BYTE *)(v11 + 1978) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8432);
  v110 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8478);
  *(_BYTE *)(v11 + 2712) = 30;
  *(_BYTE *)(v11 + 2090) = v110;
  *(_BYTE *)(v11 + 2757) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8484);
  *(_BYTE *)(v11 + 2758) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8488);
  v111 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8496);
  *(_DWORD *)(v11 + 1760) = 0;
  *(_DWORD *)(v11 + 5600) = 0;
  *(_BYTE *)(v11 + 5604) = 1;
  *(_BYTE *)(v11 + 2765) = v111;
  *(_QWORD *)(v11 + 5612) = 0;
  *(_BYTE *)(v11 + 5605) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7416);
  *(_BYTE *)(v11 + 5607) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7404);
  *(_BYTE *)(v11 + 5608) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7408);
  *(_BYTE *)(v11 + 5606) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7412) != 0;
  *(_DWORD *)(v11 + 5620) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7420);
  *(_DWORD *)(v11 + 5624) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7424);
  *(_BYTE *)(v11 + 5628) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7428);
  *(_BYTE *)(v11 + 3624) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9844);
  *(_DWORD *)(v11 + 3628) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9828);
  v112 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9832);
  *(_BYTE *)(v11 + 3636) = 0;
  *(_DWORD *)(v11 + 3632) = v112;
  *(_DWORD *)(v11 + 3640) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9836);
  *(_DWORD *)(v11 + 3644) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10016);
  v113 = *(_DWORD *)(cfg_psoc_get_values(a1) + 10012);
  *(_DWORD *)(v11 + 5964) = 0;
  *(_DWORD *)(v11 + 3648) = v113;
  *(_DWORD *)(v11 + 5968) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5096);
  *(_DWORD *)(v11 + 3672) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10124);
  *(_DWORD *)(v11 + 3676) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10128);
  *(_BYTE *)(v11 + 4632) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4465);
  *(_DWORD *)(v11 + 4636) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4468);
  *(_BYTE *)(v11 + 4640) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4472);
  *(_BYTE *)(v11 + 5586) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4976);
  *(_BYTE *)(v11 + 4641) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4473);
  *(_BYTE *)(v11 + 4642) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4474);
  v114 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4980);
  *(_BYTE *)(v11 + 5587) = 1;
  s = nullptr;
  v302 = 0;
  *(_DWORD *)(v11 + 5588) = v114;
  v300 = 0;
  if ( *(_BYTE *)(cfg_psoc_get_values(a1) + 4475) )
  {
    v115 = _qdf_mem_malloc(0x1F4u, "mlme_acs_parse_weight_list", 2532);
    if ( v115 )
    {
      v116 = (void *)v115;
      v117 = (_DWORD *)(v11 + 4644);
      v118 = cfg_psoc_get_values(a1);
      qdf_mem_copy(v116, (const void *)(v118 + 4475), 0x1F4u);
      v119 = 0;
      v120 = 0;
      stringp = (char *)v116;
      while ( 1 )
      {
        v122 = strsep(&stringp, ",");
        s = v122;
        if ( !v122 )
        {
LABEL_56:
          _qdf_mem_free((__int64)v116);
          v59 = v11 + 1291;
          break;
        }
        v123 = v122;
        v302 = 0;
        HIDWORD(v300) = 0;
        if ( strchr(v122, 45) )
        {
          v124 = strsep(&s, "-");
          sscanf(v124, "%d", &v302);
          sscanf(s, "%d", (char *)&v300 + 4);
          strsep(&s, "=");
          if ( !s )
            goto LABEL_56;
          sscanf(s, "%d", &v300);
          if ( v119 == 10 )
          {
            v119 = 10;
          }
          else
          {
            v121 = v11 + 5464 + 12LL * v119++;
            *(_BYTE *)(v121 + 8) = v300;
            *(_DWORD *)v121 = v302;
            *(_DWORD *)(v121 + 4) = HIDWORD(v300);
          }
          goto LABEL_33;
        }
        sscanf(v123, "%d", &v302);
        strsep(&s, "=");
        if ( !s )
          goto LABEL_56;
        sscanf(s, "%d", &v300);
        if ( !v120 )
          goto LABEL_53;
        if ( v120 >= 0x66u )
          v125 = 102;
        else
          v125 = v120;
        if ( *v117 == v302 )
        {
          LOBYTE(v126) = 0;
LABEL_46:
          LOBYTE(v117[2 * (unsigned __int8)v126 + 1]) = v300;
          goto LABEL_33;
        }
        v127 = (int *)(v11 + 4652);
        v126 = 0;
        while ( v125 - 1 != v126 )
        {
          v128 = *v127;
          v127 += 2;
          ++v126;
          if ( v128 == v302 )
          {
            if ( v126 < v125 )
              goto LABEL_46;
            break;
          }
        }
        if ( v120 == 102 )
        {
          v120 = 102;
        }
        else
        {
LABEL_53:
          v129 = &v117[2 * v120++];
          *v129 = v302;
          *((_BYTE *)v129 + 4) = v300;
        }
LABEL_33:
        if ( !stringp )
        {
          *(_WORD *)(v11 + 5460) = v120;
          *(_WORD *)(v11 + 5584) = v119;
          goto LABEL_56;
        }
      }
    }
  }
  v131 = *(_BYTE *)(cfg_psoc_get_values(a1) + 4984);
  *(_BYTE *)(v11 + 5592) = v131 & 1;
  *(_BYTE *)(v11 + 5593) = (v131 & 2) != 0;
  *(_BYTE *)(v11 + 5594) = (v131 & 4) != 0;
  *(_BYTE *)(v11 + 5595) = (v131 & 8) != 0;
  *(_BYTE *)(v11 + 5596) = (v131 & 0x10) != 0;
  *(_WORD *)(v11 + 5598) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4988);
  *(_BYTE *)(v59 + 3333) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8524);
  v132 = *(_DWORD *)(cfg_psoc_get_values(a1) + 8528);
  *(_QWORD *)(v11 + 4184) = 128;
  *(_BYTE *)(v59 + 3334) = v132;
  qdf_uint8_array_parse("1, 14, 20", v11 + 4200, 128, (_QWORD *)(v11 + 4192));
  *(_QWORD *)(v11 + 4328) = 256;
  qdf_uint8_array_parse("36, 126, 20", v11 + 4344, 256, (_QWORD *)(v11 + 4336));
  *(_QWORD *)(v11 + 4600) = 4;
  *(_QWORD *)(v11 + 4608) = 4;
  v133 = cfg_psoc_get_values(a1);
  qdf_mem_copy((void *)(v11 + 4616), (const void *)(v133 + 8520), *(unsigned int *)(v11 + 4608));
  *(_WORD *)(v59 + 3335) = 27;
  *(_BYTE *)(v59 + 3337) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8532);
  *(_BYTE *)(v11 + 3664) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8622);
  *(_BYTE *)(v11 + 3665) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8623);
  *(_BYTE *)(v11 + 3666) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8624);
  *(_BYTE *)(v11 + 3667) = *(_BYTE *)(cfg_psoc_get_values(a1) + 8632);
  v134 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 8625);
  v135 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8626);
  v136 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8627);
  v137 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8628);
  v138 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8629);
  v139 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8630);
  v140 = *(_BYTE *)(cfg_psoc_get_values(a1) + 8631);
  if ( v134 != 1 || (*(_BYTE *)(v11 + 3664) & 1) == 0 )
    *(_BYTE *)(v11 + 3665) = 0;
  *(_BYTE *)(v11 + 5652) = 0;
  *(_DWORD *)(v11 + 5653) = 257;
  *(_BYTE *)(v11 + 3668) = (v135 | (2 * v136) | (4 * v137) | (8 * v138) | (16 * v139) | (32 * v140))
                         + ((_BYTE)v134 << 6);
  *(_DWORD *)(v11 + 5660) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10272);
  *(_BYTE *)(v11 + 5664) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10276);
  *(_BYTE *)(v11 + 5665) = *(_BYTE *)(cfg_psoc_get_values(a1) + 10278);
  v141 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 10277);
  v142 = cfg_psoc_get_values(a1);
  wifi_pos_set_rsta_11az_ranging_cap(*(unsigned int *)(v142 + 10280));
  wifi_pos_set_rsta_sec_ltf_cap(v141);
  *(_WORD *)(v11 + 5800) = 256;
  *(_WORD *)(v11 + 5816) = 1;
  *(_DWORD *)(v11 + 5804) = 8;
  *(_QWORD *)(v11 + 5808) = 0x50F20400000001LL;
  *(_DWORD *)(v11 + 5820) = 0;
  *(_BYTE *)(v11 + 5802) = 16;
  *(_QWORD *)(v11 + 5824) = 16;
  qdf_uint8_array_parse("0xa, 0xb, 0xc, 0xd, 0xe, 0xf", v11 + 5840, 16, (_QWORD *)(v11 + 5832));
  s = nullptr;
  *(_BYTE *)(v11 + 5900) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7317);
  *(_BYTE *)(v11 + 5901) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7318);
  *(_BYTE *)(v11 + 5902) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7320);
  *(_BYTE *)(v11 + 5936) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7324);
  v143 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v143 + 7325, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: normal latency flags parsing failed",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "mlme_init_fe_wlm_in_cfg");
  }
  v152 = HIDWORD(s);
  *(_DWORD *)(v11 + 5904) = (_DWORD)s;
  *(_DWORD *)(v11 + 5920) = v152;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: normal latency flags 0x%x host flags 0x%x",
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    v150,
    v151,
    "mlme_init_fe_wlm_in_cfg");
  v153 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v153 + 7344, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: xr latency flags parsing failed",
      v154,
      v155,
      v156,
      v157,
      v158,
      v159,
      v160,
      v161,
      "mlme_init_fe_wlm_in_cfg");
  }
  v162 = HIDWORD(s);
  *(_DWORD *)(v11 + 5908) = (_DWORD)s;
  *(_DWORD *)(v11 + 5924) = v162;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: xr latency flags 0x%x host flags 0x%x",
    v154,
    v155,
    v156,
    v157,
    v158,
    v159,
    v160,
    v161,
    "mlme_init_fe_wlm_in_cfg");
  v163 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v163 + 7363, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: low latency flags parsing failed",
      v164,
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      v171,
      "mlme_init_fe_wlm_in_cfg");
  }
  v172 = HIDWORD(s);
  *(_DWORD *)(v11 + 5912) = (_DWORD)s;
  *(_DWORD *)(v11 + 5928) = v172;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: low latency flags 0x%x host flags 0x%x",
    v164,
    v165,
    v166,
    v167,
    v168,
    v169,
    v170,
    v171,
    "mlme_init_fe_wlm_in_cfg");
  v173 = cfg_psoc_get_values(a1);
  if ( (unsigned int)qdf_uint64_parse(v173 + 7382, (unsigned __int64 *)&s) )
  {
    s = nullptr;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: ultra-low latency flags parsing failed",
      v174,
      v175,
      v176,
      v177,
      v178,
      v179,
      v180,
      v181,
      "mlme_init_fe_wlm_in_cfg");
  }
  v182 = HIDWORD(s);
  *(_DWORD *)(v11 + 5916) = (_DWORD)s;
  *(_DWORD *)(v11 + 5932) = v182;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: ultra-low latency flags 0x%x host flags 0x%x",
    v174,
    v175,
    v176,
    v177,
    v178,
    v179,
    v180,
    v181,
    "mlme_init_fe_wlm_in_cfg");
  s = nullptr;
  *(_BYTE *)(v11 + 5940) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7268);
  *(_BYTE *)(v11 + 5941) = *(_BYTE *)(cfg_psoc_get_values(a1) + 7269);
  *(_BYTE *)(v11 + 5942) = *(_DWORD *)(cfg_psoc_get_values(a1) + 7272);
  v183 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v183 + 7276), v11 + 5943, 5, &s);
  if ( (unsigned __int64)s <= 4 )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: Incorrect RM capability, using default",
      v184,
      v185,
      v186,
      v187,
      v188,
      v189,
      v190,
      v191,
      "mlme_init_fe_rrm_in_cfg");
    qdf_uint8_array_parse("0x73,0x1A,0x91,0x00,0x04", v11 + 5943, 5, &s);
  }
  *(_DWORD *)(v11 + 5948) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8536);
  *(_DWORD *)(v11 + 5952) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8540);
  *(_DWORD *)(v11 + 5956) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8544);
  *(_DWORD *)(v11 + 5960) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8548);
  *(_DWORD *)(v11 + 5972) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9300);
  *(_BYTE *)(v11 + 5976) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9308);
  *(_BYTE *)(v11 + 5977) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9313);
  *(_DWORD *)(v11 + 5980) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9316);
  *(_BYTE *)(v11 + 5984) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9320);
  *(_BYTE *)(v11 + 6396) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9305);
  *(_DWORD *)(v11 + 5988) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9324);
  *(_BYTE *)(v11 + 6600) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9304);
  *(_BYTE *)(v11 + 6599) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9328);
  *(_BYTE *)(v11 + 6601) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9329);
  *(_BYTE *)(v11 + 6603) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9312);
  *(_BYTE *)(v11 + 6602) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9732);
  s = nullptr;
  v192 = cfg_psoc_get_values(a1);
  qdf_uint16_array_parse((_BYTE *)(v192 + 9330), v11 + 6398, 100, &s);
  v201 = s;
  *(_BYTE *)(v11 + 6598) = (_BYTE)s;
  if ( v201 )
  {
    v202 = 0;
    while ( v202 != 100 )
    {
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: avoid_acs_freq %d",
        v193,
        v194,
        v195,
        v196,
        v197,
        v198,
        v199,
        v200,
        "mlme_init_acs_avoid_freq_list",
        *(unsigned __int16 *)(v11 + 6398 + 2 * v202++));
      if ( (unsigned __int64)s <= v202 )
        goto LABEL_74;
    }
    goto LABEL_126;
  }
LABEL_74:
  *(_DWORD *)(v11 + 6604) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9292);
  *(_BYTE *)(v11 + 6608) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9296);
  *(_BYTE *)(v11 + 6609) = *(_BYTE *)(cfg_psoc_get_values(a1) + 9731);
  *(_DWORD *)(v11 + 5868) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4996);
  v203 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 4992);
  *(_BYTE *)(v11 + 5864) = v203;
  if ( v203 == 1 )
    *(_DWORD *)(v11 + 5868) |= 0x100u;
  v204 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 4993);
  *(_BYTE *)(v11 + 5865) = v204;
  if ( v204 == 1 )
    *(_DWORD *)(v11 + 5868) |= 0x80u;
  wlan_mlme_set_btm_abridge_flag(a1);
  *(_DWORD *)(v11 + 5872) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5000);
  *(_DWORD *)(v11 + 5876) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5004);
  *(_DWORD *)(v11 + 5880) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5008);
  *(_DWORD *)(v11 + 5884) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5012);
  *(_DWORD *)(v11 + 5888) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5016);
  *(_DWORD *)(v11 + 5892) = *(_DWORD *)(cfg_psoc_get_values(a1) + 5020);
  v205 = *(_DWORD *)(cfg_psoc_get_values(a1) + 5024);
  v306 = 0;
  v307 = 0;
  v304 = 0;
  v305 = 0;
  *(_DWORD *)(v11 + 5896) = v205;
  s = nullptr;
  stringp = nullptr;
  *(_DWORD *)(v11 + 6612) = -1;
  *(_DWORD *)(v11 + 6620) = -1;
  *(_DWORD *)(v11 + 6628) = -1;
  *(_DWORD *)(v11 + 6636) = -1;
  *(_DWORD *)(v11 + 6644) = -1;
  *(_DWORD *)(v11 + 6652) = -1;
  *(_DWORD *)(v11 + 6660) = -1;
  *(_DWORD *)(v11 + 6668) = -1;
  *(_DWORD *)(v11 + 6676) = -1;
  *(_DWORD *)(v11 + 6684) = -1;
  *(_DWORD *)(v11 + 6692) = -1;
  *(_DWORD *)(v11 + 6700) = -1;
  *(_DWORD *)(v11 + 6708) = -1;
  *(_DWORD *)(v11 + 6716) = -1;
  *(_DWORD *)(v11 + 6724) = -1;
  *(_DWORD *)(v11 + 6732) = -1;
  *(_DWORD *)(v11 + 6740) = -1;
  *(_DWORD *)(v11 + 6748) = -1;
  *(_DWORD *)(v11 + 6756) = -1;
  *(_DWORD *)(v11 + 6764) = -1;
  v206 = cfg_psoc_get_values(a1);
  qdf_uint8_array_parse((_BYTE *)(v206 + 9868), (__int64)&s, 40, &stringp);
  v207 = stringp;
  if ( (unsigned __int64)stringp >= 2 )
  {
    v208 = 0;
    while ( v208 <= 0x27 )
    {
      v210 = *((unsigned __int8 *)&s + v208);
      if ( (unsigned int)(v210 - 1) <= 0x12 )
      {
        v211 = (_DWORD *)(v11 + 6612 + 8 * v210);
        *v211 = *((unsigned __int8 *)&s + v208 + 1);
        v211[1] = v210;
      }
      v209 = v208 + 3;
      v208 += 2LL;
      if ( (unsigned __int64)v207 <= v209 )
        goto LABEL_84;
    }
    goto LABEL_126;
  }
LABEL_84:
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj && (*(_BYTE *)(cmpt_obj + 2048) & 4) != 0 )
  {
    v213 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9860);
    *(_DWORD *)(v11 + 6728) = 14;
    *(_DWORD *)(v11 + 6724) = v213;
    v214 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9864);
    *(_DWORD *)(v11 + 6696) = 10;
    *(_DWORD *)(v11 + 6692) = v214;
  }
  v215 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9848);
  *(_DWORD *)(v11 + 6776) = 13;
  *(_DWORD *)(v11 + 6772) = v215;
  v216 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9852);
  *(_DWORD *)(v11 + 6784) = 2;
  *(_DWORD *)(v11 + 6780) = v216;
  v217 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9856);
  *(_DWORD *)(v11 + 6792) = 4;
  *(_DWORD *)(v11 + 6788) = v217;
  s = nullptr;
  v304 = 0;
  stringp = nullptr;
  v218 = *(_DWORD *)(cfg_psoc_get_values(a1) + 9240);
  *(_DWORD *)(v11 + 6796) = v218;
  if ( (unsigned int)(v218 - 5) > 0xFFFFFFFB )
  {
    v229 = cfg_psoc_get_values(a1);
    if ( !(unsigned int)qdf_uint32_array_parse((_BYTE *)(v229 + 9244), (__int64)&s, 4, &stringp)
      && stringp == (_BYTE *)&off_0 + 4 )
    {
      v230 = HIDWORD(s);
      v231 = v304;
      v232 = HIDWORD(v304);
      v233 = *(unsigned int *)(v11 + 6796);
      *(_DWORD *)(v11 + 6800) = (_DWORD)s;
      *(_DWORD *)(v11 + 6804) = v230;
      *(_DWORD *)(v11 + 6808) = v231;
      *(_DWORD *)(v11 + 6812) = v232;
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: Ratemask type: %d, masks:0x%x, 0x%x, 0x%x, 0x%x",
        v219,
        v220,
        v221,
        v222,
        v223,
        v224,
        v225,
        v226,
        "mlme_init_ratemask_cfg",
        v233,
        v232);
      goto LABEL_94;
    }
    v227 = "%s: Failed to parse ratemask";
    v228 = 2;
    *(_DWORD *)(v11 + 6796) = 0;
  }
  else
  {
    v227 = "%s: Ratemask disabled";
    v228 = 8;
  }
  qdf_trace_msg(0x1Fu, v228, v227, v219, v220, v221, v222, v223, v224, v225, v226, "mlme_init_ratemask_cfg");
LABEL_94:
  LODWORD(stringp) = 0;
  v302 = 0;
  v234 = cfg_psoc_get_values(a1);
  v235 = (const void *)(v234 + 8721);
  if ( v234 == -8721 )
    goto LABEL_124;
  v236 = strlen((const char *)(v234 + 8721));
  v237 = v236;
  if ( !v236 )
    goto LABEL_124;
  v238 = (char *)_qdf_mem_malloc(v236 + 1, "mlme_iot_parse_aggr_info", 4185);
  if ( !v238 )
    goto LABEL_124;
  v239 = v238;
  qdf_mem_copy(v238, v235, v237);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: aggr_info=[%s]",
    v240,
    v241,
    v242,
    v243,
    v244,
    v245,
    v246,
    v247,
    "mlme_iot_parse_aggr_info",
    v239);
  v248 = 0;
  s = v239;
  v249 = v239;
  while ( 1 )
  {
    if ( *v249 == 32 )
    {
      v250 = v249 + 1;
      do
      {
        s = v250;
        v251 = (unsigned __int8)*v250++;
      }
      while ( v251 == 32 );
    }
    v252 = strsep(&s, ",");
    if ( !v252 )
    {
      v297 = "%s: oui error";
LABEL_118:
      qdf_trace_msg(0x1Fu, 2u, v297, v253, v254, v255, v256, v257, v258, v259, v260, "mlme_iot_parse_aggr_info");
      goto LABEL_123;
    }
    v261 = v252;
    v262 = strlen(v252);
    v263 = (unsigned int)(v262 >> 1);
    if ( v263 >= 5 )
    {
      v297 = "%s: size error";
      goto LABEL_118;
    }
    v264 = v262;
    v302 = 0;
    v265 = strsep(&s, ",");
    if ( !v265 )
    {
      v297 = "%s: msdu error";
      goto LABEL_118;
    }
    v266 = v265;
    if ( (unsigned int)kstrtouint(v265, 10, &v302) || v302 >= 7 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: invalid msdu no. %s [%u]",
        v267,
        v268,
        v269,
        v270,
        v271,
        v272,
        v273,
        v274,
        "mlme_iot_parse_aggr_info",
        v266,
        v302);
      goto LABEL_123;
    }
    LODWORD(stringp) = 0;
    v275 = strsep(&s, ",");
    if ( !v275 )
    {
      v297 = "%s: mpdu error";
      goto LABEL_118;
    }
    v276 = v275;
    if ( (unsigned int)kstrtouint(v275, 10, &stringp) || (unsigned int)stringp >= 0x201 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: invalid mpdu no. %s [%u]",
        v277,
        v278,
        v279,
        v280,
        v281,
        v282,
        v283,
        v284,
        "mlme_iot_parse_aggr_info",
        v276,
        (unsigned int)stringp);
      goto LABEL_123;
    }
    v285 = v264 >> 1;
    LODWORD(v299) = (_DWORD)stringp;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: id %u oui[%s] len %u msdu %u mpdu %u",
      v277,
      v278,
      v279,
      v280,
      v281,
      v282,
      v283,
      v284,
      "mlme_iot_parse_aggr_info",
      (unsigned int)v248,
      v261,
      (unsigned int)v285,
      v302,
      v299);
    v286 = (_DWORD *)(v11 + 6816 + 16 * v248);
    v287 = hex2bin(v286, v261, v263);
    if ( v287 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: oui error: %d",
        v288,
        v289,
        v290,
        v291,
        v292,
        v293,
        v294,
        v295,
        "mlme_iot_parse_aggr_info",
        v287);
      goto LABEL_123;
    }
    v286[3] = v302;
    v296 = (int)stringp;
    v286[1] = v285;
    v286[2] = v296;
    if ( v248 == 31 )
      break;
    v249 = s;
    ++v248;
    if ( !s )
      goto LABEL_122;
  }
  LODWORD(v248) = 32;
  qdf_trace_msg(
    0x1Fu,
    2u,
    "%s: exceed max num, index = %d",
    v288,
    v289,
    v290,
    v291,
    v292,
    v293,
    v294,
    v295,
    "mlme_iot_parse_aggr_info",
    32);
LABEL_122:
  *(_DWORD *)(v11 + 7328) = v248;
LABEL_123:
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: configured aggr num %d",
    v288,
    v289,
    v290,
    v291,
    v292,
    v293,
    v294,
    v295,
    "mlme_iot_parse_aggr_info",
    *(unsigned int *)(v11 + 7328));
  _qdf_mem_free((__int64)v239);
LABEL_124:
  *(_WORD *)(v11 + 1104) = -255;
  *(_WORD *)(v11 + 1140) = -256;
  *(_DWORD *)(v11 + 1136) = 17;
  v298 = cfg_psoc_get_values(a1);
  result = 0;
  *(_BYTE *)(v11 + 7337) = *(_BYTE *)(v298 + 7606);
LABEL_125:
  _ReadStatusReg(SP_EL0);
  return result;
}
