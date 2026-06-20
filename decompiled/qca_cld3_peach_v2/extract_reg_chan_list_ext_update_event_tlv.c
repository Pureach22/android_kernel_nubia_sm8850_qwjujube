__int64 __fastcall extract_reg_chan_list_ext_update_event_tlv(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned int *v12; // x21
  __int64 v16; // x8
  __int64 v17; // x22
  unsigned int v18; // w4
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x9
  unsigned int v47; // w22
  __int64 v48; // x20
  unsigned int v49; // w8
  __int64 v50; // x6
  __int64 v51; // x5
  unsigned int v52; // w10
  __int64 v53; // x20
  __int64 result; // x0
  unsigned int v55; // w12
  __int64 v56; // x0
  int v57; // w8
  unsigned int i; // w8
  __int64 v59; // x16
  int v60; // w17
  _DWORD *v61; // x15
  int v62; // w16
  __int64 v63; // x16
  unsigned int v64; // w13
  unsigned int v65; // w15
  unsigned int v66; // w16
  unsigned int v67; // w0
  unsigned int v68; // w1
  unsigned int v69; // w4
  __int64 v70; // x20
  __int64 v71; // x20
  __int64 v72; // x20
  unsigned int v73; // w24
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x1
  __int64 (__fastcall *v83)(__int64, __int64); // x8
  __int64 v84; // x3
  __int64 v85; // x4
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  __int64 ext_reg_rules_from_wmi; // x0
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  __int64 v167; // x23
  unsigned int v168; // w24
  __int64 v169; // x25
  __int64 v170; // x0
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x27
  unsigned int v180; // w23
  __int64 v181; // x22
  __int64 v182; // x23
  __int64 v183; // x28
  __int64 v184; // x22
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  __int64 v193; // x25
  __int64 v194; // x0
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 *v203; // x24
  __int64 v204; // x8
  __int64 v205; // x9
  __int64 v206; // x11
  __int16 v207; // w10
  __int64 v208; // x22
  __int64 v209; // x28
  __int64 v210; // x22
  __int64 v211; // x27
  unsigned __int16 *v212; // x8
  __int64 v213; // x23
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  __int64 v222; // x28
  __int64 v223; // x27
  char v224; // w8
  const char *v225; // x3
  __int64 v226; // x23
  __int64 v227; // x8
  __int64 v228; // x25
  __int64 v229; // x0
  __int64 v230; // x8
  __int64 v231; // x9
  __int64 v232; // x11
  __int16 v233; // w10
  unsigned int v234; // w22
  __int64 v235; // x24
  unsigned __int64 v236; // x25
  __int64 v237; // x8
  unsigned __int16 *v238; // x8
  int v239; // w11
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  unsigned int v248; // w8
  unsigned int v249; // w9
  __int64 v250; // x6
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  unsigned int v259; // w8
  unsigned int v260; // w9
  __int64 v261; // x6
  double v262; // d0
  double v263; // d1
  double v264; // d2
  double v265; // d3
  double v266; // d4
  double v267; // d5
  double v268; // d6
  double v269; // d7
  __int64 v270; // [xsp+0h] [xbp-80h]
  __int64 v271; // [xsp+0h] [xbp-80h]
  __int64 v272; // [xsp+0h] [xbp-80h]
  __int64 v273; // [xsp+0h] [xbp-80h]
  __int64 v274; // [xsp+8h] [xbp-78h]
  __int64 v275; // [xsp+10h] [xbp-70h]
  __int64 v276; // [xsp+18h] [xbp-68h]
  __int64 v277; // [xsp+30h] [xbp-50h]
  char v278; // [xsp+3Ch] [xbp-44h]
  __int64 v279; // [xsp+40h] [xbp-40h]
  __int64 v280; // [xsp+40h] [xbp-40h]
  __int64 v281; // [xsp+48h] [xbp-38h]
  __int64 v282; // [xsp+50h] [xbp-30h]
  __int64 v283; // [xsp+58h] [xbp-28h]
  __int64 v284; // [xsp+60h] [xbp-20h]
  __int64 v285; // [xsp+68h] [xbp-18h]
  __int64 v286; // [xsp+70h] [xbp-10h]
  __int64 v287; // [xsp+78h] [xbp-8h]

  v287 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid channel list event buf",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_reg_chan_list_ext_update_event_tlv");
    goto LABEL_22;
  }
  v11 = *(_QWORD *)(a2 + 32);
  v12 = *(unsigned int **)a2;
  if ( v11 )
  {
    *(_DWORD *)(a3 + 56) = *(unsigned __int16 *)(v11 + 4);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: VLP cut-off frequency %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_reg_chan_list_ext_update_event_tlv");
  }
  *(_DWORD *)(a3 + 48) = v12[13];
  *(_DWORD *)(a3 + 52) = v12[14];
  *(_DWORD *)(a3 + 204) = v12[64];
  *(_DWORD *)(a3 + 200) = v12[65];
  *(_DWORD *)(a3 + 208) = v12[66];
  v16 = *(_QWORD *)(a2 + 64);
  if ( v16 )
  {
    if ( *(_DWORD *)(a2 + 72) )
    {
      v17 = *(_QWORD *)(a2 + 80);
      if ( v17 )
      {
        v18 = *(_DWORD *)(a2 + 88);
        if ( v18 )
        {
          if ( v18 >= 4 )
          {
            qdf_trace_msg(
              0x31u,
              2u,
              "%s: Num reg meta data : %d, greater than limit %d",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "extract_additional_reg_rules_meta_info");
LABEL_22:
            result = 16;
            goto LABEL_23;
          }
          if ( (*(_BYTE *)(v16 + 4) & 1) == 0 )
          {
            qdf_trace_msg(
              0x31u,
              2u,
              "%s: Invalid additional rules meta info received.",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "extract_additional_reg_rules_meta_info");
            goto LABEL_13;
          }
          *(_BYTE *)(a3 + 372) = 1;
          qdf_trace_msg(0x31u, 8u, "Additional cap, C2C :  %u", a4, a5, a6, a7, a8, a9, a10, a11, 1);
          v56 = _qdf_mem_malloc(4LL * *(unsigned int *)(a2 + 88), "extract_additional_reg_rules_meta_info", 17672);
          *(_QWORD *)(a3 + 360) = v56;
          if ( !v56 )
            goto LABEL_22;
          v57 = *(_DWORD *)(a2 + 88);
          *(_DWORD *)(a3 + 368) = v57;
          if ( v57 )
          {
            for ( i = 0; i < *(_DWORD *)(a2 + 88); ++i )
            {
              v61 = (_DWORD *)(v17 + 24LL * (int)i);
              v62 = v61[1];
              if ( v62 == 2 )
              {
                v60 = 12;
                v59 = 1;
              }
              else
              {
                if ( v62 != 1 )
                {
                  if ( !v62 )
                  {
                    *(_DWORD *)(a3 + 212) = v61[5];
                    *(_DWORD *)(a3 + 116) = v61[3];
                    *(_DWORD *)(a3 + 132) = v61[4];
                    v63 = *(_QWORD *)(a3 + 360);
                    *(_BYTE *)(a3 + 89) = v61[2];
                    *(_DWORD *)(v63 + 4LL * (unsigned __int8)i) = 10;
                  }
                  continue;
                }
                v59 = 0;
                v60 = 11;
              }
              *(_DWORD *)(*(_QWORD *)(a3 + 360) + 4LL * (unsigned __int8)i) = v60;
              *(_DWORD *)(a3 + 240 + 4 * v59) = v61[5];
              *(_DWORD *)(a3 + 160 + 4 * v59) = v61[3];
              *(_DWORD *)(a3 + 192 + 4 * v59) = v61[4];
              *(_BYTE *)(a3 + 96 + v59) = v61[2];
            }
          }
        }
      }
    }
  }
LABEL_13:
  v20 = *(unsigned int *)(a3 + 200);
  v19 = *(unsigned int *)(a3 + 204);
  v21 = *(unsigned int *)(a3 + 208);
  v285 = 0;
  v286 = 0;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: num reg rules from fw, AP: SP %d, LPI %d, VLP %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "extract_reg_chan_list_ext_update_event_tlv",
    v19,
    v20,
    v21);
  *(_DWORD *)(a3 + 224) = v12[67];
  *(_DWORD *)(a3 + 216) = v12[71];
  *(_DWORD *)(a3 + 232) = v12[75];
  qdf_trace_msg(
    0x31u,
    8u,
    "client %d SP %d, LPI %d, VLP %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    0,
    v12[67],
    v12[71]);
  *(_DWORD *)(a3 + 228) = v12[68];
  *(_DWORD *)(a3 + 220) = v12[72];
  *(_DWORD *)(a3 + 236) = v12[76];
  qdf_trace_msg(
    0x31u,
    8u,
    "client %d SP %d, LPI %d, VLP %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    1,
    v12[68],
    v12[72]);
  v47 = *(_DWORD *)(a3 + 48);
  v46 = *(unsigned int *)(a3 + 52);
  LODWORD(v285) = *(_DWORD *)(a3 + 200);
  if ( (unsigned int)v285 >= 6 )
    goto LABEL_14;
  v49 = *(_DWORD *)(a3 + 216);
  v283 = 0;
  v284 = 0;
  v281 = a3 + 216;
  v282 = 0;
  if ( v49 >= 6 )
  {
    v50 = 0;
    v51 = 0;
    goto LABEL_20;
  }
  v52 = *(_DWORD *)(a3 + 220);
  if ( v52 > 5 )
  {
    v50 = 0;
    v51 = 1;
    v49 = *(_DWORD *)(a3 + 220);
    goto LABEL_20;
  }
  HIDWORD(v285) = *(_DWORD *)(a3 + 204);
  if ( HIDWORD(v285) > 5 )
    goto LABEL_14;
  v55 = *(_DWORD *)(a3 + 224);
  v282 = a3 + 224;
  if ( v55 > 5 )
  {
    v51 = 0;
    v50 = 1;
    v49 = v55;
    goto LABEL_20;
  }
  v64 = *(_DWORD *)(a3 + 228);
  if ( v64 > 5 )
  {
    v50 = 1;
    v51 = 1;
    v49 = *(_DWORD *)(a3 + 228);
    goto LABEL_20;
  }
  LODWORD(v286) = *(_DWORD *)(a3 + 208);
  if ( (unsigned int)v286 > 5 )
    goto LABEL_14;
  v65 = *(_DWORD *)(a3 + 232);
  v283 = a3 + 232;
  if ( v65 > 5 )
  {
    v51 = 0;
    v50 = 2;
    v49 = v65;
    goto LABEL_20;
  }
  v66 = *(_DWORD *)(a3 + 236);
  if ( v66 > 5 )
  {
    v51 = 1;
    v50 = 2;
    v49 = *(_DWORD *)(a3 + 236);
    goto LABEL_20;
  }
  HIDWORD(v286) = *(_DWORD *)(a3 + 212);
  if ( HIDWORD(v286) > 5 )
  {
LABEL_14:
    v48 = jiffies;
    if ( extract_reg_chan_list_ext_update_event_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid num_6g_reg_rules_ap: %u, power type: %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "extract_reg_chan_list_ext_update_event_tlv");
      extract_reg_chan_list_ext_update_event_tlv___last_ticks = v48;
    }
    goto LABEL_22;
  }
  v67 = *(_DWORD *)(a3 + 240);
  v284 = a3 + 240;
  if ( v67 > 5 )
  {
    v51 = 0;
    v50 = 3;
    v49 = v67;
    goto LABEL_20;
  }
  v68 = *(_DWORD *)(a3 + 244);
  if ( v68 > 5 )
  {
    v51 = 1;
    v50 = 3;
    v49 = *(_DWORD *)(a3 + 244);
LABEL_20:
    v53 = jiffies;
    if ( extract_reg_chan_list_ext_update_event_tlv___last_ticks_406 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid num reg rules %u for client_type : %d, power type : %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "extract_reg_chan_list_ext_update_event_tlv",
        v49,
        v51,
        v50);
      extract_reg_chan_list_ext_update_event_tlv___last_ticks_406 = v53;
    }
    goto LABEL_22;
  }
  v69 = v68 + v67 + HIDWORD(v286) + v66 + v65 + v286 + v64 + v55 + HIDWORD(v285) + v52 + v49 + v285 + v46 + v47;
  if ( v69 != *(_DWORD *)(a2 + 24) )
  {
    v71 = jiffies;
    if ( extract_reg_chan_list_ext_update_event_tlv___last_ticks_408 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Total reg rules %u does not match event params num reg rule %u",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "extract_reg_chan_list_ext_update_event_tlv");
      extract_reg_chan_list_ext_update_event_tlv___last_ticks_408 = v71;
    }
    goto LABEL_22;
  }
  if ( v47 > 0xA || (unsigned int)v46 >= 0xB )
  {
    v72 = jiffies;
    if ( extract_reg_chan_list_ext_update_event_tlv___last_ticks_410 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid num_2g_reg_rules: %u, num_5g_reg_rules: %u",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "extract_reg_chan_list_ext_update_event_tlv",
        v47,
        v46);
      extract_reg_chan_list_ext_update_event_tlv___last_ticks_410 = v72;
    }
    goto LABEL_22;
  }
  v279 = v46;
  if ( v69 >= 0x3E )
  {
    v70 = jiffies;
    if ( extract_reg_chan_list_ext_update_event_tlv___last_ticks_411 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid ext_num_reg_rule_array: %u",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "extract_reg_chan_list_ext_update_event_tlv");
      extract_reg_chan_list_ext_update_event_tlv___last_ticks_411 = v70;
    }
    goto LABEL_22;
  }
  qdf_mem_copy((void *)(a3 + 18), v12 + 3, 2u);
  *(_DWORD *)(a3 + 24) = v12[7];
  v73 = v12[8];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Target phybitmap: 0x%x",
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    "convert_phybitmap_tlv",
    v73);
  *(_DWORD *)(a3 + 28) = v73 & 0x7F;
  *(_BYTE *)(a3 + 21) = 1;
  *(_BYTE *)(a3 + 12) = v12[4];
  v82 = v12[2];
  v83 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3704LL);
  if ( *((_DWORD *)v83 - 1) != -2112860426 )
    __break(0x8228u);
  *(_BYTE *)(a3 + 13) = v83(a1, v82);
  *(_WORD *)(a3 + 16) = v12[5];
  *(_WORD *)(a3 + 14) = v12[6];
  *(_DWORD *)(a3 + 8) = wmi_reg_status_to_reg_status(v12[1]);
  v84 = *(unsigned __int8 *)(a3 + 12);
  v85 = *(unsigned __int8 *)(a3 + 13);
  *(_DWORD *)(a3 + 32) = v12[9];
  *(_DWORD *)(a3 + 36) = v12[10];
  *(_DWORD *)(a3 + 40) = v12[11];
  *(_DWORD *)(a3 + 44) = v12[12];
  *(_DWORD *)(a3 + 108) = v12[34];
  *(_DWORD *)(a3 + 124) = v12[35];
  *(_DWORD *)(a3 + 104) = v12[36];
  *(_DWORD *)(a3 + 120) = v12[37];
  *(_DWORD *)(a3 + 112) = v12[38];
  *(_DWORD *)(a3 + 128) = v12[39];
  *(_DWORD *)(a3 + 144) = v12[40];
  *(_DWORD *)(a3 + 176) = v12[44];
  *(_DWORD *)(a3 + 136) = v12[48];
  *(_DWORD *)(a3 + 168) = v12[52];
  *(_DWORD *)(a3 + 152) = v12[56];
  *(_DWORD *)(a3 + 184) = v12[60];
  *(_DWORD *)(a3 + 148) = v12[41];
  *(_DWORD *)(a3 + 180) = v12[45];
  *(_DWORD *)(a3 + 140) = v12[49];
  *(_DWORD *)(a3 + 172) = v12[53];
  *(_DWORD *)(a3 + 156) = v12[57];
  *(_DWORD *)(a3 + 188) = v12[61];
  qdf_trace_msg(0x31u, 8u, "num_phys = %u and phy_id = %u", v86, v87, v88, v89, v90, v91, v92, v93, v84, v85);
  qdf_trace_msg(
    0x31u,
    8u,
    "cc %s dfs_region %d reg_dmn_pair %x BW: min_2g %d max_2g %d min_5g %d max_5g %d",
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    v101,
    a3 + 18,
    *(unsigned int *)(a3 + 24),
    *(unsigned __int16 *)(a3 + 14),
    *(unsigned int *)(a3 + 32),
    *(unsigned int *)(a3 + 36),
    *(_DWORD *)(a3 + 40),
    *(_DWORD *)(a3 + 44));
  LODWORD(v270) = *(_DWORD *)(a3 + 128);
  qdf_trace_msg(
    0x31u,
    8u,
    "AP POWER TYPE-[MIN BW, MAX BW] SP:[%d, %d] LPI:[%d, %d], VLP:[%d, %d]",
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    *(unsigned int *)(a3 + 108),
    *(unsigned int *)(a3 + 124),
    *(unsigned int *)(a3 + 104),
    *(unsigned int *)(a3 + 120),
    *(unsigned int *)(a3 + 112),
    v270);
  LODWORD(v271) = *(_DWORD *)(a3 + 184);
  qdf_trace_msg(
    0x31u,
    8u,
    "DEF CLI POWER TYPE-[MIN BW, MAX BW] SP:[%d, %d] LPI:[%d, %d], VLP:[%d, %d]",
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    v116,
    v117,
    *(unsigned int *)(a3 + 144),
    *(unsigned int *)(a3 + 176),
    *(unsigned int *)(a3 + 136),
    *(unsigned int *)(a3 + 168),
    *(unsigned int *)(a3 + 152),
    v271);
  LODWORD(v272) = *(_DWORD *)(a3 + 188);
  qdf_trace_msg(
    0x31u,
    8u,
    "SUB CLI POWER TYPE-[MIN BW, MAX BW] SP:[%d, %d] LPI:[%d, %d], VLP:[%d, %d]",
    v118,
    v119,
    v120,
    v121,
    v122,
    v123,
    v124,
    v125,
    *(unsigned int *)(a3 + 148),
    *(unsigned int *)(a3 + 180),
    *(unsigned int *)(a3 + 140),
    *(unsigned int *)(a3 + 172),
    *(unsigned int *)(a3 + 156),
    v272);
  qdf_trace_msg(
    0x31u,
    8u,
    "num_2g_reg_rules %d num_5g_reg_rules %d",
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    v47,
    v279);
  qdf_trace_msg(
    0x31u,
    8u,
    "AP NUM 6 GHz REG RULES SP[%d] LPI[%d] VLP[%d]",
    v134,
    v135,
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    *(unsigned int *)(a3 + 204),
    *(unsigned int *)(a3 + 200),
    *(unsigned int *)(a3 + 208));
  qdf_trace_msg(
    0x31u,
    8u,
    "DEF CLI NUM 6 GHz REG RULES SP[%d] LPI[%d] VLP[%d]",
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    *(unsigned int *)(a3 + 224),
    *(unsigned int *)(a3 + 216),
    *(unsigned int *)(a3 + 232));
  qdf_trace_msg(
    0x31u,
    8u,
    "SUB CLI CLI 6 GHz REG RULES SP[%d] LPI[%d] VLP[%d]",
    v150,
    v151,
    v152,
    v153,
    v154,
    v155,
    v156,
    v157,
    *(unsigned int *)(a3 + 228),
    *(unsigned int *)(a3 + 220),
    *(unsigned int *)(a3 + 236));
  ext_reg_rules_from_wmi = create_ext_reg_rules_from_wmi(v47, v12 + 80);
  *(_QWORD *)(a3 + 64) = ext_reg_rules_from_wmi;
  v167 = (__int64)&v12[5 * v47 + 80];
  if ( v47 )
  {
    if ( ext_reg_rules_from_wmi )
    {
      v168 = 0;
      v169 = 0;
      do
      {
        LODWORD(v274) = *(unsigned __int16 *)(ext_reg_rules_from_wmi + v169 + 8);
        LODWORD(v276) = *(unsigned __int16 *)(ext_reg_rules_from_wmi + v169 + 12);
        LODWORD(v275) = *(unsigned __int8 *)(ext_reg_rules_from_wmi + v169 + 10);
        LODWORD(v273) = *(unsigned __int8 *)(ext_reg_rules_from_wmi + v169 + 7);
        qdf_trace_msg(
          0x31u,
          8u,
          "2 GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u psd_flag %u psd_eirp %u",
          v159,
          v160,
          v161,
          v162,
          v163,
          v164,
          v165,
          v166,
          v168,
          *(unsigned __int16 *)(ext_reg_rules_from_wmi + v169),
          *(unsigned __int16 *)(ext_reg_rules_from_wmi + v169 + 2),
          *(unsigned __int16 *)(ext_reg_rules_from_wmi + v169 + 4),
          *(unsigned __int8 *)(ext_reg_rules_from_wmi + v169 + 6),
          v273,
          v274,
          v275,
          v276);
        if ( 14LL * v47 - 14 == v169 )
          break;
        ext_reg_rules_from_wmi = *(_QWORD *)(a3 + 64);
        v169 += 14;
        ++v168;
      }
      while ( ext_reg_rules_from_wmi );
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 8u, "No 2ghz reg rule", v159, v160, v161, v162, v163, v164, v165, v166);
  }
  v170 = create_ext_reg_rules_from_wmi((unsigned int)v279, v167);
  *(_QWORD *)(a3 + 72) = v170;
  v179 = v167 + 20LL * (unsigned int)v279;
  if ( (_DWORD)v279 )
  {
    if ( v170 )
    {
      v180 = 0;
      v181 = 0;
      do
      {
        LODWORD(v274) = *(unsigned __int16 *)(v170 + v181 + 8);
        LODWORD(v276) = *(unsigned __int16 *)(v170 + v181 + 12);
        LODWORD(v275) = *(unsigned __int8 *)(v170 + v181 + 10);
        LODWORD(v273) = *(unsigned __int8 *)(v170 + v181 + 7);
        qdf_trace_msg(
          0x31u,
          8u,
          "5 GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u psd_flag %u psd_eirp %u",
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v178,
          v180,
          *(unsigned __int16 *)(v170 + v181),
          *(unsigned __int16 *)(v170 + v181 + 2),
          *(unsigned __int16 *)(v170 + v181 + 4),
          *(unsigned __int8 *)(v170 + v181 + 6),
          v273,
          v274,
          v275,
          v276);
        if ( 14LL * (unsigned int)v279 - 14 == v181 )
          break;
        v170 = *(_QWORD *)(a3 + 72);
        v181 += 14;
        ++v180;
      }
      while ( v170 );
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 8u, "No 5ghz reg rule", v171, v172, v173, v174, v175, v176, v177, v178);
  }
  v182 = 0;
  v183 = a3 + 248;
  v184 = v179;
  do
  {
    reg_print_ap_power_type_6ghz((unsigned int)v182);
    v193 = *((unsigned int *)&v285 + v182);
    if ( (_DWORD)v193 )
    {
      v194 = _qdf_mem_malloc(14 * v193, "create_ext_reg_rules_from_wmi", 17267);
      v203 = (__int64 *)(v183 + 8 * v182);
      if ( v194 )
      {
        v204 = 0;
        v205 = v184 + 8;
        do
        {
          v206 = v194 + v204;
          v204 += 14;
          *(_WORD *)v206 = *(_DWORD *)(v205 - 4);
          *(_WORD *)(v206 + 2) = *(_WORD *)(v205 - 2);
          *(_WORD *)(v206 + 4) = *(_DWORD *)v205;
          *(_BYTE *)(v206 + 6) = *(_WORD *)(v205 + 2);
          *(_BYTE *)(v206 + 7) = *(_BYTE *)(v205 + 3);
          *(_WORD *)(v206 + 8) = *(_DWORD *)(v205 + 4);
          *(_BYTE *)(v206 + 10) = *(_BYTE *)(v205 + 8) & 1;
          v207 = *(_WORD *)(v205 + 10);
          v205 += 20;
          *(_WORD *)(v206 + 12) = v207;
        }
        while ( 14 * v193 != v204 );
        *v203 = v194;
        v208 = v184 + 20LL * (unsigned int)v193;
      }
      else
      {
        *v203 = 0;
        v208 = v184 + 20LL * (unsigned int)v193;
      }
      v209 = v208;
      v210 = 0;
      v211 = 0;
      do
      {
        if ( !*v203 )
          break;
        v212 = (unsigned __int16 *)(*v203 + v210);
        LODWORD(v274) = v212[4];
        LODWORD(v276) = v212[6];
        LODWORD(v275) = *((unsigned __int8 *)v212 + 10);
        LODWORD(v273) = *((unsigned __int8 *)v212 + 7);
        qdf_trace_msg(
          0x31u,
          8u,
          "AP 6GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u psd_flag %u psd_eirp %u",
          v195,
          v196,
          v197,
          v198,
          v199,
          v200,
          v201,
          v202,
          (unsigned int)v211++,
          *v212,
          v212[1],
          v212[2],
          *((unsigned __int8 *)v212 + 6),
          v273,
          v274,
          v275,
          v276);
        v210 += 14;
      }
      while ( v193 != v211 );
      v184 = v209;
      v183 = a3 + 248;
    }
    else
    {
      *(_QWORD *)(v183 + 8 * v182) = 0;
      qdf_trace_msg(0x31u, 8u, "No 6ghz reg rule", v185, v186, v187, v188, v189, v190, v191, v192);
    }
    ++v182;
  }
  while ( v182 != 3 );
  v213 = 0;
  do
  {
    reg_print_ap_power_type_6ghz((unsigned int)v213);
    v222 = 0;
    v277 = v213;
    v223 = a3 + 280 + 16 * v213;
    v224 = 1;
    do
    {
      v278 = v224;
      if ( (v224 & 1) != 0 )
        v225 = "DEFAULT CLIENT";
      else
        v225 = "SUBORDINATE CLIENT";
      qdf_trace_msg(0x31u, 8u, "Client type %s", v214, v215, v216, v217, v218, v219, v220, v221, v225);
      v280 = v184;
      v226 = *(&v281 + v213);
      v227 = *(unsigned int *)(v226 + 4 * v222);
      if ( (_DWORD)v227 )
      {
        v228 = 14 * v227;
        v229 = _qdf_mem_malloc(14 * v227, "create_ext_reg_rules_from_wmi", 17267);
        if ( v229 )
        {
          v230 = 0;
          v231 = v184 + 8;
          do
          {
            v232 = v229 + v230;
            v230 += 14;
            *(_WORD *)v232 = *(_DWORD *)(v231 - 4);
            *(_WORD *)(v232 + 2) = *(_WORD *)(v231 - 2);
            *(_WORD *)(v232 + 4) = *(_DWORD *)v231;
            *(_BYTE *)(v232 + 6) = *(_WORD *)(v231 + 2);
            *(_BYTE *)(v232 + 7) = *(_BYTE *)(v231 + 3);
            *(_WORD *)(v232 + 8) = *(_DWORD *)(v231 + 4);
            *(_BYTE *)(v232 + 10) = *(_BYTE *)(v231 + 8) & 1;
            v233 = *(_WORD *)(v231 + 10);
            v231 += 20;
            *(_WORD *)(v232 + 12) = v233;
          }
          while ( v228 != v230 );
        }
      }
      else
      {
        v229 = 0;
      }
      *(_QWORD *)(v223 + 8 * v222) = v229;
      v234 = *(_DWORD *)(v226 + 4 * v222);
      if ( v234
        || (qdf_trace_msg(
              0x31u,
              8u,
              "No 6ghz reg rule for [%d][%d]",
              v214,
              v215,
              v216,
              v217,
              v218,
              v219,
              v220,
              v221,
              v277,
              (unsigned int)v222),
            *(_DWORD *)(v226 + 4 * v222)) )
      {
        v235 = 0;
        v236 = 0;
        do
        {
          v237 = *(_QWORD *)(v223 + 8 * v222);
          if ( !v237 )
            break;
          v238 = (unsigned __int16 *)(v237 + v235);
          LODWORD(v274) = v238[4];
          LODWORD(v276) = v238[6];
          LODWORD(v275) = *((unsigned __int8 *)v238 + 10);
          LODWORD(v273) = *((unsigned __int8 *)v238 + 7);
          qdf_trace_msg(
            0x31u,
            8u,
            "CLI 6GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u psd_flag %u psd_eirp %u",
            v214,
            v215,
            v216,
            v217,
            v218,
            v219,
            v220,
            v221,
            (unsigned int)v236++,
            *v238,
            v238[1],
            v238[2],
            *((unsigned __int8 *)v238 + 6),
            v273,
            v274,
            v275,
            v276);
          v235 += 14;
        }
        while ( v236 < *(unsigned int *)(v226 + 4 * v222) );
      }
      v213 = v277;
      v184 = v280 + 20LL * v234;
      v224 = 0;
      v222 = 1;
    }
    while ( (v278 & 1) != 0 );
    v213 = v277 + 1;
  }
  while ( v277 != 2 );
  extract_additional_reg_rules(v184, a3);
  *(_DWORD *)(a3 + 80) = v12[15];
  *(_BYTE *)(a3 + 84) = v12[16] != 0;
  *(_BYTE *)(a3 + 85) = v12[17] != 0;
  *(_BYTE *)(a3 + 87) = v12[19];
  *(_BYTE *)(a3 + 86) = v12[18];
  v239 = (unsigned __int8)v12[20];
  *(_BYTE *)(a3 + 88) = v12[20];
  LODWORD(v273) = v239;
  qdf_trace_msg(
    0x31u,
    8u,
    "client type %d, RNR TPE usable %d, unspecified AP usable %d, domain code AP SP %d, LPI %d, VLP %d",
    v240,
    v241,
    v242,
    v243,
    v244,
    v245,
    v246,
    v247,
    v273);
  v248 = v12[25];
  *(_BYTE *)(a3 + 92) = v248;
  v249 = v12[21];
  *(_BYTE *)(a3 + 90) = v249;
  v250 = (unsigned __int8)v12[29];
  *(_BYTE *)(a3 + 94) = v12[29];
  qdf_trace_msg(
    0x31u,
    8u,
    "domain code client %d SP %d, LPI %d, VLP %d",
    v251,
    v252,
    v253,
    v254,
    v255,
    v256,
    v257,
    v258,
    0,
    (unsigned __int8)v248,
    (unsigned __int8)v249,
    v250);
  v259 = v12[26];
  *(_BYTE *)(a3 + 93) = v259;
  v260 = v12[22];
  *(_BYTE *)(a3 + 91) = v260;
  v261 = (unsigned __int8)v12[30];
  *(_BYTE *)(a3 + 95) = v12[30];
  qdf_trace_msg(
    0x31u,
    8u,
    "domain code client %d SP %d, LPI %d, VLP %d",
    v262,
    v263,
    v264,
    v265,
    v266,
    v267,
    v268,
    v269,
    1,
    (unsigned __int8)v259,
    (unsigned __int8)v260,
    v261);
  print_c2c_reg_rules_info(a3);
  *(_DWORD *)(a3 + 100) = v12[33];
  result = extract_reg_fcc_rules_tlv(a2, v12, a3);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
