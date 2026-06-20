__int64 __fastcall populate_dot11f_assoc_req_mlo_ie(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  __int64 result; // x0
  __int64 v5; // x23
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x22
  _WORD *v19; // x27
  __int16 v20; // w8
  __int64 v21; // x19
  char v22; // w8
  __int16 v23; // w11
  __int64 v24; // x9
  __int64 v25; // x26
  unsigned int v26; // w24
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char sta_mlo_simultaneous_links; // w0
  char t2lm_negotiation_supported; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x9
  __int16 v46; // w24
  __int16 v47; // w11
  __int16 v48; // w10
  char v49; // w9
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w4
  unsigned __int16 v59; // w8
  __int64 v60; // x26
  __int64 v61; // x26
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned __int8 *v70; // x25
  char v71; // w23
  const char *v72; // x2
  __int64 v73; // x8
  __int64 v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  _DWORD *v83; // x9
  unsigned int v84; // w10
  _DWORD *v85; // x8
  unsigned int v86; // w9
  char v87; // w8
  __int16 v88; // w10
  char v89; // w9
  char v90; // w10
  char v91; // w9
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned int v100; // w8
  _WORD *v101; // x19
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v110; // w8
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int16 v119; // w8
  __int64 v120; // x9
  unsigned __int64 v121; // x19
  unsigned int v122; // w24
  unsigned __int8 *v123; // x22
  unsigned __int64 v124; // x27
  __int64 ap_link_by_link_id; // x0
  unsigned __int8 *v126; // x23
  __int64 v127; // x28
  __int16 v128; // w8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x8
  __int16 v138; // w11
  __int16 v139; // w10
  bool v140; // zf
  int v141; // w9
  __int16 v142; // w8
  __int16 v143; // w9
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  unsigned __int8 v152; // w0
  unsigned int v153; // w0
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  unsigned __int64 v170; // x26
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x3
  __int64 v180; // x19
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  size_t v189; // x2
  int v190; // w8
  _BYTE *v191; // x26
  int v192; // w0
  unsigned int v193; // w24
  unsigned __int16 v194; // w19
  __int64 v195; // x5
  __int64 v196; // x6
  __int64 v197; // x7
  int v198; // w8
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  char cb_mode_for_freq; // w25
  double v208; // d0
  double v209; // d1
  double v210; // d2
  double v211; // d3
  double v212; // d4
  double v213; // d5
  double v214; // d6
  double v215; // d7
  __int16 v216; // w9
  int v217; // w8
  __int64 v218; // x8
  size_t v219; // x2
  int v220; // w8
  int v221; // w0
  __int64 v222; // x8
  int v223; // w10
  __int64 v224; // x8
  char ftm_cap; // w0
  bool v226; // w23
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  __int64 v235; // x8
  double v236; // d0
  double v237; // d1
  double v238; // d2
  double v239; // d3
  double v240; // d4
  double v241; // d5
  double v242; // d6
  double v243; // d7
  int v244; // w8
  char sta_cb_mode_for_24ghz; // w0
  char v246; // w25
  __int64 v247; // x9
  int v248; // w8
  unsigned int v249; // w25
  double v250; // d0
  double v251; // d1
  double v252; // d2
  double v253; // d3
  double v254; // d4
  double v255; // d5
  double v256; // d6
  double v257; // d7
  __int64 v258; // x8
  __int16 v259; // w9
  int v260; // w8
  __int64 v261; // x8
  _BOOL8 v262; // x4
  __int64 v263; // x23
  __int64 v264; // x0
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  bool is_6ghz_chan_freq; // w0
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  unsigned __int64 v282; // x8
  unsigned __int8 *v283; // x0
  unsigned __int8 *v284; // x23
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
  unsigned int v293; // w1
  const char *v294; // x2
  __int64 v295; // x8
  char *v296; // x0
  char v297; // w8
  __int16 v298; // w8
  double v299; // d0
  double v300; // d1
  double v301; // d2
  double v302; // d3
  double v303; // d4
  double v304; // d5
  double v305; // d6
  double v306; // d7
  __int64 v307; // [xsp+0h] [xbp-5A0h]
  _QWORD *v308; // [xsp+20h] [xbp-580h]
  char v309; // [xsp+2Ch] [xbp-574h]
  __int64 v310; // [xsp+30h] [xbp-570h]
  unsigned __int64 v311; // [xsp+38h] [xbp-568h]
  unsigned int v312; // [xsp+44h] [xbp-55Ch]
  bool is_24ghz_ch_freq; // [xsp+54h] [xbp-54Ch]
  unsigned int v314; // [xsp+64h] [xbp-53Ch]
  unsigned __int8 *v315; // [xsp+68h] [xbp-538h]
  __int64 v316; // [xsp+70h] [xbp-530h] BYREF
  __int64 v317; // [xsp+78h] [xbp-528h]
  __int64 v318; // [xsp+80h] [xbp-520h]
  __int64 v319; // [xsp+88h] [xbp-518h]
  __int16 v320[2]; // [xsp+90h] [xbp-510h] BYREF
  int v321; // [xsp+94h] [xbp-50Ch] BYREF
  __int16 v322[2]; // [xsp+98h] [xbp-508h] BYREF
  unsigned int v323; // [xsp+9Ch] [xbp-504h] BYREF
  unsigned __int8 v324[4]; // [xsp+A0h] [xbp-500h] BYREF
  _BYTE v325[4]; // [xsp+A4h] [xbp-4FCh] BYREF
  _QWORD v326[2]; // [xsp+A8h] [xbp-4F8h] BYREF
  __int128 v327; // [xsp+B8h] [xbp-4E8h] BYREF
  __int64 v328; // [xsp+C8h] [xbp-4D8h]
  __int64 v329; // [xsp+D0h] [xbp-4D0h]
  __int64 v330; // [xsp+D8h] [xbp-4C8h]
  __int64 v331; // [xsp+E0h] [xbp-4C0h]
  __int64 v332; // [xsp+E8h] [xbp-4B8h]
  int v333; // [xsp+F0h] [xbp-4B0h]
  __int128 v334; // [xsp+F8h] [xbp-4A8h] BYREF
  __int64 v335; // [xsp+108h] [xbp-498h]
  __int64 v336; // [xsp+110h] [xbp-490h]
  __int64 v337; // [xsp+118h] [xbp-488h]
  __int64 v338; // [xsp+120h] [xbp-480h]
  __int64 v339; // [xsp+128h] [xbp-478h]
  __int64 v340; // [xsp+130h] [xbp-470h]
  __int64 v341; // [xsp+138h] [xbp-468h]
  __int64 v342; // [xsp+140h] [xbp-460h]
  __int64 v343; // [xsp+148h] [xbp-458h]
  int v344; // [xsp+150h] [xbp-450h]
  _BYTE v345[16]; // [xsp+158h] [xbp-448h] BYREF
  _BYTE v346[16]; // [xsp+168h] [xbp-438h] BYREF
  __int128 v347; // [xsp+178h] [xbp-428h] BYREF
  __int64 v348; // [xsp+188h] [xbp-418h]
  __int64 v349; // [xsp+190h] [xbp-410h]
  __int64 v350; // [xsp+198h] [xbp-408h]
  __int64 v351; // [xsp+1A0h] [xbp-400h]
  __int64 v352; // [xsp+1A8h] [xbp-3F8h]
  __int64 v353; // [xsp+1B0h] [xbp-3F0h]
  __int64 v354; // [xsp+1B8h] [xbp-3E8h]
  __int64 v355; // [xsp+1C0h] [xbp-3E0h]
  __int64 v356; // [xsp+1C8h] [xbp-3D8h]
  int v357; // [xsp+1D0h] [xbp-3D0h]
  __int128 v358; // [xsp+1D8h] [xbp-3C8h] BYREF
  __int64 v359; // [xsp+1E8h] [xbp-3B8h]
  __int64 v360; // [xsp+1F0h] [xbp-3B0h]
  __int64 v361; // [xsp+1F8h] [xbp-3A8h] BYREF
  __int64 v362; // [xsp+200h] [xbp-3A0h]
  __int64 v363; // [xsp+208h] [xbp-398h]
  int v364; // [xsp+210h] [xbp-390h]
  __int128 v365; // [xsp+218h] [xbp-388h] BYREF
  char v366; // [xsp+228h] [xbp-378h]
  _QWORD v367[7]; // [xsp+230h] [xbp-370h] BYREF
  int v368; // [xsp+268h] [xbp-338h]
  _WORD s[130]; // [xsp+26Ch] [xbp-334h] BYREF
  _QWORD v370[32]; // [xsp+370h] [xbp-230h] BYREF
  _QWORD v371[30]; // [xsp+470h] [xbp-130h] BYREF
  _QWORD v372[2]; // [xsp+560h] [xbp-40h]
  unsigned __int8 v373[16]; // [xsp+570h] [xbp-30h] BYREF
  _QWORD v374[4]; // [xsp+580h] [xbp-20h] BYREF

  result = 29;
  v374[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 112);
  v320[0] = 0;
  v318 = 0;
  v319 = 0;
  v316 = 0;
  v317 = 0;
  if ( !a1 || !a2 || !a3 )
    goto LABEL_11;
  memset(v373, 0, 13);
  v372[0] = 0;
  *(_QWORD *)((char *)v372 + 7) = 0;
  memset(v374, 0, 13);
  memset(v371, 0, sizeof(v371));
  memset(v370, 0, 255);
  v325[0] = 0;
  v324[0] = 0;
  v323 = 0;
  memset(s, 0, 0x101u);
  v16 = *(_QWORD *)(a2 + 16);
  v322[0] = 0;
  memset(v367, 0, sizeof(v367));
  v17 = *(_QWORD *)(v16 + 216);
  v368 = 0;
  v326[0] = 0;
  v326[1] = 0;
  v365 = 0u;
  v366 = 0;
  v358 = 0u;
  v359 = 0;
  v360 = 0;
  v361 = 0;
  v362 = 0;
  v363 = 0;
  v364 = 0;
  v321 = 0;
  v347 = 0u;
  v348 = 0;
  v349 = 0;
  v350 = 0;
  v351 = 0;
  v352 = 0;
  v353 = 0;
  v354 = 0;
  v355 = 0;
  v356 = 0;
  v357 = 0;
  memset(v346, 0, 14);
  memset(v345, 0, 14);
  if ( !v17 || (v18 = *(_QWORD *)(v17 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid psoc",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "populate_dot11f_assoc_req_mlo_ie");
    goto LABEL_10;
  }
  v19 = (_WORD *)(a2 + 10874);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Populate Assoc req MLO IEs",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "populate_dot11f_assoc_req_mlo_ie");
  v20 = *(_WORD *)(a2 + 10874);
  v21 = *(_QWORD *)(a2 + 16);
  *(_BYTE *)(a2 + 10876) = 1;
  *(_WORD *)(a2 + 10874) = v20 & 0xFFF8;
  qdf_mem_copy((void *)(a2 + 10877), (const void *)(v21 + 80), 6u);
  v22 = *(_BYTE *)(a2 + 10876);
  v23 = *(_WORD *)(a2 + 10874) & 0xF80F;
  v24 = *(_QWORD *)(a2 + 112);
  *(_BYTE *)(a2 + 10876) = v22 + 6;
  *(_WORD *)(a2 + 10874) = v23 | 0x100;
  if ( !v24 )
  {
LABEL_10:
    result = 16;
    goto LABEL_11;
  }
  v25 = v24 + 4096;
  v315 = a3;
  *(_BYTE *)(a2 + 10876) = v22 + 8;
  v26 = *(unsigned __int8 *)(v24 + 4368);
  if ( v26 >= (unsigned __int8)wlan_mlme_get_sta_mlo_simultaneous_links(v18) )
    sta_mlo_simultaneous_links = wlan_mlme_get_sta_mlo_simultaneous_links(v18);
  else
    sta_mlo_simultaneous_links = *(_BYTE *)(v25 + 272);
  *(_WORD *)(a2 + 10890) = *(_WORD *)(a2 + 10890) & 0xFFF0 | sta_mlo_simultaneous_links & 0xF;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: max_simultaneous_link_num %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "populate_dot11f_assoc_req_mlo_ie",
    sta_mlo_simultaneous_links & 0xF);
  *(_WORD *)(a2 + 10890) &= ~0x10u;
  t2lm_negotiation_supported = wlan_mlme_get_t2lm_negotiation_supported(*(_QWORD *)(a1 + 21624));
  v45 = *(_QWORD *)(a2 + 16);
  *(_WORD *)(a2 + 10890) = (32 * (t2lm_negotiation_supported & 3)) | *(_WORD *)(a2 + 10890) & 0xC01F;
  if ( (*(_BYTE *)(v45 + 49) & 4) != 0 )
  {
    wlan_mlme_get_eml_params(v18, v320);
    v47 = LOBYTE(v320[0]);
    v46 = 24;
    v48 = *(_WORD *)(a2 + 10888) & 0x8700;
    v49 = *(_BYTE *)(a2 + 10876) + 2;
    *v19 |= 0x80u;
    *(_BYTE *)(a2 + 10876) = v49;
    *(_WORD *)(a2 + 10888) = v48 | v47;
  }
  else
  {
    v46 = 16;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: num partner links: %d",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "populate_dot11f_assoc_req_mlo_ie",
    *(unsigned __int8 *)(v25 + 272));
  v310 = v25;
  if ( v5 == -4548 )
  {
    v61 = jiffies;
    if ( wlan_get_ielen_from_bss_description___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Bss_desc is NULL",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "wlan_get_ielen_from_bss_description");
      v59 = 0;
      wlan_get_ielen_from_bss_description___last_ticks = v61;
      goto LABEL_23;
    }
    goto LABEL_21;
  }
  v58 = *(unsigned __int16 *)(v5 + 4548);
  v59 = v58 - 102;
  if ( v58 > 0x66 )
    goto LABEL_24;
  v60 = jiffies;
  if ( wlan_get_ielen_from_bss_description___last_ticks_146 - jiffies + 125 >= 0 )
  {
LABEL_21:
    v59 = 0;
    goto LABEL_23;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Invalid bss_desc len:%d ie_fields_offset:%d",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "wlan_get_ielen_from_bss_description");
  v59 = 0;
  wlan_get_ielen_from_bss_description___last_ticks_146 = v60;
LABEL_23:
  v25 = v310;
LABEL_24:
  LODWORD(v317) = v59;
  v316 = v5 + 4652;
  v70 = v315;
  if ( (wlan_mlme_get_ext_mld_cap_supp(v18) & 1) != 0 )
  {
    v71 = 0;
    v72 = "%s: ext mld capability support is set";
  }
  else
  {
    v73 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 1360LL);
    if ( v73 && (*(_BYTE *)(v73 + 3897) & 1) != 0 )
    {
      v71 = 0;
      v72 = "%s: AP advertises ext mld caps";
    }
    else if ( *(unsigned __int8 *)(v25 + 272) >= 2u
           && ((wlan_action_oui_search(v18, &v316, 25) & 1) == 0
            || (v74 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 1360LL)) != 0
            && *(_BYTE *)(v74 + 3898) == 1
            && (wlan_action_oui_search(v18, &v316, 25) & 1) != 0) )
    {
      v71 = 0;
      v72 = "%s: STA is connecting with >= 3 links";
    }
    else
    {
      v71 = 1;
      v72 = "%s: Do not advertise ext mld caps";
    }
  }
  qdf_trace_msg(0x35u, 8u, v72, v62, v63, v64, v65, v66, v67, v68, v69, "populate_dot11f_assoc_req_mlo_ie");
  v83 = *(_DWORD **)(v18 + 2800);
  if ( v83 )
  {
    v84 = v83[126];
    v85 = v83 + 780;
    if ( v84 <= 0xA )
    {
      if ( *v85 == v84 )
      {
        v86 = 0;
      }
      else if ( v83[826] == v84 )
      {
        v86 = 1;
      }
      else if ( v83[872] == v84 )
      {
        v86 = 2;
      }
      else if ( v83[918] == v84 )
      {
        v86 = 3;
      }
      else if ( v83[964] == v84 )
      {
        v86 = 4;
      }
      else if ( v83[1010] == v84 )
      {
        v86 = 5;
      }
      else if ( v83[1056] == v84 )
      {
        v86 = 6;
      }
      else
      {
        if ( v83[1102] != v84 )
          goto LABEL_61;
        v86 = 7;
      }
      v85 += 46 * v86;
    }
    if ( v85 )
    {
      v87 = (v85[45] & 0x80) != 0 ? v71 : 1;
      if ( (v87 & 1) == 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Set ext mld caps",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "populate_dot11f_assoc_req_mlo_ie");
        v46 |= 0x40u;
        v88 = *(_WORD *)(a2 + 10894);
        v89 = *(_BYTE *)(a2 + 10876) + 2;
        *v19 |= 0x400u;
        *(_BYTE *)(a2 + 10876) = v89;
        *(_WORD *)(a2 + 10894) = v88 | 0x80;
      }
    }
  }
LABEL_61:
  v90 = *v19;
  v91 = *(_WORD *)(a2 + 12967);
  *(_BYTE *)(a2 + 12966) = 107;
  *(_WORD *)(a2 + 12964) = 255;
  *(_BYTE *)(a2 + 12969) = *(_BYTE *)(a2 + 10876);
  *(_WORD *)(a2 + 12967) = v91 & 8 | v90 & 7 | (16 * v46);
  qdf_mem_copy((void *)(a2 + 12970), (const void *)(v21 + 80), 6u);
  v100 = *(unsigned __int16 *)(a2 + 10888);
  if ( (*v19 & 0x80) != 0 )
  {
    v101 = (_WORD *)(a2 + 12978);
    *(_WORD *)(a2 + 12976) = *(_WORD *)(a2 + 12976) & 0x8000 | v100 & 0x7FFF;
  }
  else
  {
    v101 = (_WORD *)(a2 + 12976);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: EMLSR support: %d, padding delay: %d, transition delay: %d",
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    "populate_dot11f_assoc_req_mlo_ie",
    v100 & 1,
    (v100 >> 1) & 7,
    (v100 >> 4) & 7);
  v110 = *(unsigned __int16 *)(a2 + 10890);
  if ( (*v19 & 0x100) != 0 )
  {
    *v101 = v110 & 0x206F | *v101 & 0xDF90;
    ++v101;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: link_reconfig_operation_support %d",
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    "populate_dot11f_assoc_req_mlo_ie",
    (v110 >> 13) & 1);
  if ( (*v19 & 0x400) != 0 )
  {
    v119 = *v101 & 0xFF7F;
    *v101 = v119;
    *v101 = *(_WORD *)(a2 + 10894) & 0x80 | v119;
    LOWORD(v101) = (_WORD)v101 + 2;
  }
  v120 = *(_QWORD *)(a2 + 16);
  *(_WORD *)(a2 + 12962) = (_WORD)v101 - (a2 + 12964);
  if ( *(_QWORD *)(v120 + 1360) )
  {
    v121 = *(unsigned __int8 *)(v25 + 272);
    if ( *(_BYTE *)(v25 + 272) )
    {
      v122 = 0;
      v123 = (unsigned __int8 *)(v25 + 280);
      v124 = 1;
      v309 = 0;
      v311 = *(unsigned __int8 *)(v25 + 272);
      v308 = v315 + 534;
      while ( 1 )
      {
        if ( !*(_BYTE *)(v25 + 272) )
          goto LABEL_277;
        if ( v122 >= 5 || v124 - 1 > 3 )
          __break(0x5512u);
        ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(*(_QWORD *)(a2 + 16) + 1360LL), v123[6]);
        if ( !ap_link_by_link_id )
          goto LABEL_277;
        v126 = (unsigned __int8 *)ap_link_by_link_id;
        v127 = a2 + 10898 + 516LL * v122;
        *(_WORD *)(v127 + 2) = 0;
        qdf_mem_set(v371, 0xFFu, 0);
        qdf_mem_set(v370, 0xFFu, 0);
        v128 = *(_WORD *)(v127 + 4);
        *(_WORD *)(v127 + 4) = v128 & 0xFFF0;
        *(_WORD *)(v127 + 4) = v128 & 0xFFC0 | v123[6] & 0xF | 0x30;
        *(_BYTE *)(v127 + 6) = 7;
        qdf_mem_copy((void *)(v127 + 7), v126, 6u);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Sta profile mac: %02x:%02x:%02x:**:**:%02x",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "populate_dot11f_assoc_req_mlo_ie",
          *v126,
          v126[1],
          v126[2],
          v126[5]);
        *(_WORD *)(v127 + 4) &= 0xF8BFu;
        qdf_mem_set(v322, 2u, 0);
        qdf_mem_set(v374, 0xDu, 0);
        qdf_mem_set(v373, 0xDu, 0);
        qdf_mem_set(v346, 0xEu, 0);
        qdf_mem_set(v345, 0xEu, 0);
        qdf_mem_set(s, 0x101u, 0);
        qdf_mem_set(v367, 0x3Cu, 0);
        qdf_mem_set(&v365, 0x11u, 0);
        qdf_mem_set(v326, 0x10u, 0);
        qdf_mem_set(&v358, 0x3Cu, 0);
        qdf_mem_set(&v321, 4u, 0);
        qdf_mem_set(&v347, 0x5Cu, 0);
        v137 = *(_QWORD *)(a1 + 8);
        if ( *(_BYTE *)(v137 + 5652) )
          v138 = 17;
        else
          v138 = 1;
        if ( *(_BYTE *)(v137 + 1298) )
          v138 |= 0x20u;
        if ( *(_BYTE *)(v137 + 5604) )
          v138 |= 0x400u;
        if ( *(_BYTE *)(v137 + 1061) )
          v139 = v138 | 0x100;
        else
          v139 = v138;
        v140 = *(_BYTE *)(v137 + 5668) == 0;
        v141 = *(unsigned __int8 *)(v137 + 3636);
        v142 = *(_WORD *)(v137 + 5616);
        if ( !v140 )
          v139 |= 0x200u;
        v143 = v141 ? v139 | 0x800 : v139;
        v322[0] = v143 & 0x2FFF | ((*(_BYTE *)(a1 + 17480) & 1) << 12) | (v142 << 14);
        dot11f_pack_ff_capabilities(a1, v322, (void *)(v127 + 13));
        wlan_get_chan_by_bssid_from_rnr(*(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 4), (__int64)v123, v325, v324);
        v152 = v325[0];
        if ( v325[0] )
          break;
        wlan_get_chan_by_link_id_from_rnr(*(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 4), v123[6], v325, v324);
        v152 = v325[0];
        if ( v325[0] )
          break;
        if ( v123 )
        {
          v195 = *v123;
          v196 = v123[1];
          v197 = v123[2];
          v198 = v123[5];
        }
        else
        {
          v197 = 0;
          v195 = 0;
          v196 = 0;
          v198 = 0;
        }
        LODWORD(v307) = v198;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid parter link id %d link mac: %02x:%02x:%02x:**:**:%02x",
          v144,
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          "populate_dot11f_assoc_req_mlo_ie",
          v123[6],
          v195,
          v196,
          v197,
          v307);
LABEL_277:
        if ( v124 < v121 )
        {
          ++v124;
          v123 += 48;
          if ( (_DWORD)v121 != v122 )
            continue;
        }
        goto LABEL_282;
      }
      v153 = wlan_reg_chan_opclass_to_freq_auto(v152, v324[0], 0, v144, v145, v146, v147, v148, v149, v150, v151);
      if ( !v153 )
      {
        v180 = jiffies;
        if ( populate_dot11f_assoc_req_mlo_ie___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Invalid op_class %d",
            v154,
            v155,
            v156,
            v157,
            v158,
            v159,
            v160,
            v161,
            "populate_dot11f_assoc_req_mlo_ie",
            v324[0]);
          populate_dot11f_assoc_req_mlo_ie___last_ticks = v180;
        }
        v121 = v311;
        goto LABEL_277;
      }
      v314 = v153;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v153);
      if ( is_24ghz_ch_freq )
      {
        LODWORD(v334) = 369820674;
        LOBYTE(v374[0]) = 4;
        qdf_mem_copy((char *)v374 + 1, &v334, 4u);
        *(_WORD *)((char *)v374 + 1) |= 0x8080u;
        *(_WORD *)((char *)v374 + 3) |= 0x8080u;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Default CCK Rates",
          v162,
          v163,
          v164,
          v165,
          v166,
          v167,
          v168,
          v169,
          "wlan_populate_basic_rates");
        ((void (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(
          53,
          8,
          (char *)v374 + 1,
          LOBYTE(v374[0]));
        v170 = (unsigned __int64)v373;
        *(_QWORD *)&v334 = 0x6C6048302418120CLL;
        v373[0] = 8;
        qdf_mem_copy(&v373[1], &v334, 8u);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Default OFDM Rates",
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v178,
          "wlan_populate_basic_rates");
        v179 = v373[0];
      }
      else
      {
        v170 = (unsigned __int64)v374;
        *(_QWORD *)&v334 = 0x6C6048302418120CLL;
        LOBYTE(v374[0]) = 8;
        qdf_mem_copy((char *)v374 + 1, &v334, 8u);
        BYTE1(v374[0]) |= 0x80u;
        BYTE3(v374[0]) |= 0x80u;
        BYTE5(v374[0]) |= 0x80u;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Default OFDM Rates",
          v181,
          v182,
          v183,
          v184,
          v185,
          v186,
          v187,
          v188,
          "wlan_populate_basic_rates");
        v179 = LOBYTE(v374[0]);
      }
      ((void (__fastcall *)(__int64, __int64, unsigned __int64, __int64))qdf_trace_hex_dump)(53, 8, v170 | 1, v179);
      v189 = LOBYTE(v374[0]);
      v190 = v70[38];
      v191 = (_BYTE *)(v127 + 15);
      v312 = v122;
      if ( !LOBYTE(v374[0]) )
        goto LABEL_108;
      if ( !v70[38] )
        goto LABEL_102;
      v192 = qdf_mem_cmp(v70 + 40, (char *)v374 + 1, LOBYTE(v374[0]));
      v189 = LOBYTE(v374[0]);
      if ( v192 )
        goto LABEL_102;
      v190 = v70[38];
      if ( LOBYTE(v374[0]) )
      {
        if ( !v70[38] )
        {
LABEL_102:
          v346[1] = v189;
          qdf_mem_copy(&v346[2], (char *)v374 + 1, v189);
          v346[0] = 1;
          v323 = 0;
          dot11f_pack_ie_supp_rates(a1, v346, (_BYTE *)(v127 + 15), 0x1F5u, (int *)&v323);
          v193 = 0;
          v191 += v323;
          v194 = 501 - v323;
          goto LABEL_112;
        }
      }
      else
      {
LABEL_108:
        if ( v190 )
        {
          v193 = 1;
          LOBYTE(v371[0]) = 1;
LABEL_111:
          v194 = 501;
LABEL_112:
          if ( !wlan_reg_is_6ghz_chan_freq(v314) )
          {
            cb_mode_for_freq = lim_get_cb_mode_for_freq(a1, a2, v314);
            populate_dot11f_ht_caps((_QWORD *)a1, 0, (__int64)v367, v208, v209, v210, v211, v212, v213, v214, v215);
            v140 = cb_mode_for_freq == 0;
            v70 = v315;
            if ( v140 )
              v216 = 0;
            else
              v216 = 66;
            *(_WORD *)((char *)v367 + 1) = *(_WORD *)((_BYTE *)v367 + 1) & 0xFFBD | v216;
          }
          v217 = v70[472];
          if ( LOBYTE(v367[0]) )
          {
            if ( !v70[472] || (unsigned int)qdf_mem_cmp(v367, v70 + 472, 0x3Cu) )
            {
LABEL_120:
              v323 = 0;
              dot11f_pack_ie_ht_caps(a1, (__int64)v367, v191, v194, (int *)&v323);
              v191 += v323;
              v194 -= v323;
LABEL_126:
              v219 = v373[0];
              v220 = v70[52];
              if ( !v373[0] )
                goto LABEL_133;
              if ( !v70[52] )
                goto LABEL_129;
              v221 = qdf_mem_cmp(v70 + 54, &v373[1], v373[0]);
              v219 = v373[0];
              if ( v221 )
                goto LABEL_129;
              v220 = v70[52];
              if ( v373[0] )
              {
                if ( !v70[52] )
                {
LABEL_129:
                  v345[1] = v219;
                  qdf_mem_copy(&v345[2], &v373[1], v219);
                  v345[0] = 1;
                  v323 = 0;
                  dot11f_pack_ie_ext_supp_rates(a1, v345, v191, v194, (int *)&v323);
                  v191 += v323;
                  v194 -= v323;
                  goto LABEL_135;
                }
              }
              else
              {
LABEL_133:
                if ( !v220 )
                  goto LABEL_135;
              }
              v222 = v193++;
              *(_BYTE *)((unsigned __int64)v371 | v222) = 50;
LABEL_135:
              LOBYTE(v365) = 1;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: 11MC - enabled for non-SAP cases",
                v199,
                v200,
                v201,
                v202,
                v203,
                v204,
                v205,
                v206,
                "populate_dot11f_ext_cap");
              v223 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1049LL);
              BYTE1(v365) = 15;
              v224 = *(_QWORD *)((char *)&v365 + 2) | 0x4000000000000000LL;
              *(_QWORD *)((char *)&v365 + 2) |= 0x4000000000000000uLL;
              if ( v223 == 1 )
              {
                ftm_cap = ucfg_wifi_pos_get_ftm_cap(*(_QWORD *)(a1 + 21624));
                v224 = *(_QWORD *)((char *)&v365 + 2);
                WORD5(v365) = WORD5(v365) & 0xFF3F | (__rbit32(ftm_cap & 3) >> 24);
              }
              v226 = is_24ghz_ch_freq;
              *(_QWORD *)((char *)&v365 + 2) = *(unsigned __int8 *)(a1 + 17230) | (unsigned __int64)v224 | 4;
              if ( (_BYTE)v365 )
                BYTE1(v365) = lim_compute_ext_cap_ie_length(&v365);
              populate_dot11f_btm_extended_caps(a1, a2, (__int64)&v365);
              if ( ((*v308 ^ *(_QWORD *)((char *)&v365 + 2)) & 0x40000000000000LL) != 0 )
                *(_QWORD *)((char *)&v365 + 2) = *(_QWORD *)((_BYTE *)&v365 + 2) & 0xFFBFFFFFFFFFFFFFLL
                                               | (((*v308 >> 54) & 1LL) << 54);
              if ( (_BYTE)v365 )
              {
                if ( !v70[532] || (unsigned int)qdf_mem_cmp(&v365, v70 + 532, 0x11u) )
                {
LABEL_144:
                  v323 = 0;
                  dot11f_pack_ie_ext_cap(a1, &v365, v191, v194, (int *)&v323);
                  v191 += v323;
                  v194 -= v323;
                  goto LABEL_150;
                }
                if ( (_BYTE)v365 )
                {
                  if ( v70[532] )
                    goto LABEL_150;
                  goto LABEL_144;
                }
              }
              if ( v70[532] )
              {
                v235 = v193++;
                *(_BYTE *)((unsigned __int64)v371 | v235) = 127;
              }
LABEL_150:
              if ( is_24ghz_ch_freq && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2875LL) == 1 )
              {
                populate_dot11f_vht_caps(a1, 0, (__int64)v326, v227, v228, v229, v230, v231, v232, v233, v234);
              }
              else if ( !wlan_reg_is_5ghz_ch_freq(v314)
                     || (populate_dot11f_vht_caps(a1, 0, (__int64)v326, v236, v237, v238, v239, v240, v241, v242, v243),
                         !is_24ghz_ch_freq) )
              {
LABEL_156:
                v244 = v70[552];
                if ( LOBYTE(v326[0]) )
                {
                  if ( !v70[552] || (unsigned int)qdf_mem_cmp(v326, v70 + 552, 0x10u) )
                  {
LABEL_159:
                    v323 = 0;
                    dot11f_pack_ie_vht_caps(a1, (__int64)v326, v191, v194, (int *)&v323);
                    v191 += v323;
                    v194 -= v323;
LABEL_165:
                    if ( is_24ghz_ch_freq )
                    {
                      qdf_mem_copy(&v358, (const void *)(a1 + 21788), 0x3Cu);
                      sta_cb_mode_for_24ghz = lim_get_sta_cb_mode_for_24ghz(a1, *(unsigned __int8 *)(a2 + 10));
                      *(_QWORD *)((char *)&v358 + 1) = *(_QWORD *)((_BYTE *)&v358 + 1) & 0xFFFBFFFFFFFFFFFFLL
                                                     | ((unsigned __int64)(sta_cb_mode_for_24ghz & 1) << 50);
                    }
                    else
                    {
                      qdf_mem_copy(&v358, (const void *)(a1 + 21848), 0x3Cu);
                    }
                    populate_dot11f_twt_he_cap(a1, a2, (__int64)&v358);
                    if ( (BYTE14(v358) & 4) != 0 )
                    {
                      v247 = 1453;
                      v246 = 25;
                      if ( is_24ghz_ch_freq )
                        v247 = 1428;
                      qdf_mem_copy((char *)&v361 + 1, (const void *)(*(_QWORD *)(a1 + 8) + v247), 0x19u);
                      if ( !BYTE1(v364) )
                      {
                        if ( (_BYTE)v364 )
                        {
                          v246 = 24;
                        }
                        else if ( HIBYTE(v363) )
                        {
                          v246 = 23;
                        }
                        else if ( BYTE6(v363) )
                        {
                          v246 = 22;
                        }
                        else if ( BYTE5(v363) )
                        {
                          v246 = 21;
                        }
                        else if ( BYTE4(v363) )
                        {
                          v246 = 20;
                        }
                        else if ( BYTE3(v363) )
                        {
                          v246 = 19;
                        }
                        else if ( BYTE2(v363) )
                        {
                          v246 = 18;
                        }
                        else
                        {
                          if ( BYTE1(v363) )
                          {
                            v246 = 17;
                          }
                          else if ( (_BYTE)v363 )
                          {
                            v246 = 16;
                          }
                          else if ( HIBYTE(v362) )
                          {
                            v246 = 15;
                          }
                          else if ( BYTE6(v362) )
                          {
                            v246 = 14;
                          }
                          else if ( BYTE5(v362) )
                          {
                            v246 = 13;
                          }
                          else if ( BYTE4(v362) )
                          {
                            v246 = 12;
                          }
                          else if ( BYTE3(v362) )
                          {
                            v246 = 11;
                          }
                          else if ( BYTE2(v362) )
                          {
                            v246 = 10;
                          }
                          else if ( BYTE1(v362) )
                          {
                            v246 = 9;
                          }
                          else if ( (_BYTE)v362 )
                          {
                            v246 = 8;
                          }
                          else if ( HIBYTE(v361) )
                          {
                            v246 = 7;
                          }
                          else if ( BYTE6(v361) )
                          {
                            v246 = 6;
                          }
                          else if ( BYTE5(v361) )
                          {
                            v246 = 5;
                          }
                          else if ( BYTE4(v361) )
                          {
                            v246 = 4;
                          }
                          else if ( BYTE3(v361) )
                          {
                            v246 = 3;
                          }
                          else if ( BYTE2(v361) )
                          {
                            v246 = 2;
                          }
                          else
                          {
                            v246 = BYTE1(v361) != 0;
                          }
                          v226 = is_24ghz_ch_freq;
                        }
                      }
                    }
                    else
                    {
                      v246 = 0;
                    }
                    LOBYTE(v361) = v246;
                    v248 = v315[2100];
                    if ( !(_BYTE)v358 )
                      goto LABEL_230;
                    if ( !v315[2100] || (unsigned int)qdf_mem_cmp(&v358, v315 + 2100, 0x3Cu) )
                      goto LABEL_226;
                    v248 = v315[2100];
                    if ( (_BYTE)v358 )
                    {
                      if ( !v315[2100] )
                      {
LABEL_226:
                        v323 = 0;
                        dot11f_pack_ie_he_cap(a1, (__int64)&v358, v191, v194, (int *)&v323);
                        v249 = 0;
                        v191 += v323;
                        v194 -= v323;
                        v309 = 1;
LABEL_233:
                        if ( wlan_reg_is_6ghz_chan_freq(v314) )
                        {
                          v258 = *(_QWORD *)(a1 + 8);
                          v259 = BYTE1(v321) & 0xC0
                               | (*(_BYTE *)(v258 + 1290) >> 2) & 7
                               | (*(_WORD *)(v258 + 1288) << 9) & 0x18C7
                               | (unsigned __int8)(8 * (*(_BYTE *)(v258 + 2877) & 7))
                               | ((*(_BYTE *)(v258 + 2878) & 7) << 8);
                          LOBYTE(v321) = 1;
                          *(_WORD *)((char *)&v321 + 1) = v259;
                          lim_log_he_6g_cap(v250, v251, v252, v253, v254, v255, v256, v257, a1, (__int64)&v321);
                        }
                        v260 = v315[2160];
                        if ( !(_BYTE)v321 )
                          goto LABEL_242;
                        if ( !v315[2160] || (unsigned int)qdf_mem_cmp(&v321, v315 + 2160, 4u) )
                          goto LABEL_238;
                        v260 = v315[2160];
                        if ( (_BYTE)v321 )
                        {
                          if ( !v315[2160] )
                          {
LABEL_238:
                            v323 = 0;
                            dot11f_pack_ie_he_6ghz_band_cap(a1, (__int64)&v321, v191, v194, (int *)&v323);
                            v191 += v323;
                            v194 -= v323;
                          }
                        }
                        else
                        {
LABEL_242:
                          if ( v260 )
                          {
                            v261 = v249++;
                            *(_BYTE *)((unsigned __int64)v370 | v261) = 59;
                          }
                        }
                        v262 = v226;
                        if ( v226 )
                          v263 = 22064;
                        else
                          v263 = 22156;
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: is_2g %d",
                          v250,
                          v251,
                          v252,
                          v253,
                          v254,
                          v255,
                          v256,
                          v257,
                          "populate_dot11f_eht_caps_by_band",
                          v262);
                        qdf_mem_copy(&v347, (const void *)(a1 + v263), 0x5Cu);
                        v264 = *(_QWORD *)(a1 + 21624);
                        LOBYTE(v334) = 0;
                        wlan_twt_get_rtwt_support(v264, &v334);
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: rTWT support: %d",
                          v265,
                          v266,
                          v267,
                          v268,
                          v269,
                          v270,
                          v271,
                          v272,
                          "populate_dot11f_rtwt_eht_cap",
                          (unsigned __int8)v334);
                        *(_QWORD *)((char *)&v347 + 1) = *(_QWORD *)((_BYTE *)&v347 + 1) & 0xFFFFFFFFFFFFFFEFLL
                                                       | (16 * (v334 & 1));
                        is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(v314);
                        v282 = *(_QWORD *)((char *)&v347 + 1);
                        if ( !is_6ghz_chan_freq )
                          v282 = *(_QWORD *)((_BYTE *)&v347 + 1) & 0xFFFFFFFE3FFDFFFFLL;
                        if ( (v282 & 0x220000) != 0x220000 || !is_6ghz_chan_freq )
                        {
                          if ( (v282 & 0x220000) != 0x220000 )
                            v282 &= 0xFFFFFC7FFFFFFFFFLL;
                          *(_QWORD *)((char *)&v347 + 1) = v282;
                        }
                        if ( (_BYTE)v347 )
                        {
                          if ( !v315[3108] )
                            goto LABEL_258;
                          if ( (unsigned int)qdf_mem_cmp(&v347, v315 + 3108, 0x5Cu) )
                          {
LABEL_261:
                            v283 = (unsigned __int8 *)_qdf_mem_malloc(0x101u, "populate_dot11f_assoc_req_mlo_ie", 14542);
                            if ( !v283 )
                            {
                              v293 = 2;
                              v294 = "%s: malloc failed for eht_cap_ie";
LABEL_267:
                              qdf_trace_msg(
                                0x35u,
                                v293,
                                v294,
                                v274,
                                v275,
                                v276,
                                v277,
                                v278,
                                v279,
                                v280,
                                v281,
                                "populate_dot11f_assoc_req_mlo_ie");
                              goto LABEL_268;
                            }
                            v323 = 0;
                            v284 = v283;
                            v341 = v354;
                            v342 = v355;
                            v343 = v356;
                            v344 = v357;
                            v337 = v350;
                            v338 = v351;
                            v339 = v352;
                            v340 = v353;
                            v334 = v347;
                            v335 = v348;
                            v336 = v349;
                            v330 = v361;
                            v331 = v362;
                            v332 = v363;
                            v333 = v364;
                            v327 = v358;
                            v328 = v359;
                            v329 = v360;
                            lim_ieee80211_pack_ehtcap(
                              v283,
                              &v334,
                              (__int64)&v327,
                              is_24ghz_ch_freq,
                              1,
                              v274,
                              v275,
                              v276,
                              v277,
                              v278,
                              v279,
                              v280,
                              v281);
                            v323 = v284[1] + 2;
                            qdf_mem_copy(v191, v284, v323);
                            _qdf_mem_free((__int64)v284);
                            v191 += v323;
                            v194 -= v323;
                            goto LABEL_268;
                          }
                          if ( (_BYTE)v347 )
                          {
LABEL_258:
                            if ( !((v315[3108] == 0) | v309 & 1) )
                              goto LABEL_266;
                            goto LABEL_261;
                          }
                        }
                        if ( (v309 & 1) == 0 )
                        {
                          if ( !v315[3108] )
                          {
LABEL_266:
                            v293 = 8;
                            v294 = "%s: eht ie not included";
                            goto LABEL_267;
                          }
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: eht non inher",
                            v274,
                            v275,
                            v276,
                            v277,
                            v278,
                            v279,
                            v280,
                            v281,
                            "populate_dot11f_assoc_req_mlo_ie");
                          v295 = v249++;
                          *(_BYTE *)((unsigned __int64)v370 | v295) = 108;
LABEL_268:
                          if ( v315[568] )
                          {
                            qdf_trace_msg(
                              0x35u,
                              4u,
                              "%s: opmode in assoc req, add to non inher list",
                              v285,
                              v286,
                              v287,
                              v288,
                              v289,
                              v290,
                              v291,
                              v292,
                              "populate_dot11f_assoc_req_mlo_ie");
                            *((_BYTE *)v371 + v193++) = -57;
                          }
                          s[0] = 257;
                          LOBYTE(s[1]) = v193;
                          qdf_mem_copy((char *)&s[1] + 1, v371, v193);
                          v296 = (char *)&s[1] + v193 + 1;
                          v297 = v193 + HIBYTE(s[0]);
                          *v296 = v249;
                          HIBYTE(s[0]) = v297 + 1;
                          qdf_mem_copy(v296 + 1, v370, v249);
                          HIBYTE(s[0]) += v249;
                          if ( LOBYTE(s[0]) )
                          {
                            v323 = 0;
                            dot11f_pack_ie_non_inheritance(a1, s, v191, v194, (int *)&v323);
                            LOWORD(v191) = (_WORD)v191 + v323;
                          }
                          v70 = v315;
                          v298 = (_WORD)v191 - (v127 + 2);
                          v121 = v311;
                          *(_WORD *)v127 = v298;
                          if ( (v298 & 0xFFFEu) < 0x102uLL )
                          {
                            v25 = v310;
                            *(_BYTE *)(v127 + 3) = v298 - 2;
                          }
                          else
                          {
                            *(_BYTE *)(v127 + 3) = -1;
                            v25 = v310;
                            if ( (unsigned int)lim_add_frag_ie_for_sta_profile(v127 + 2, v127) )
                            {
                              qdf_trace_msg(
                                0x35u,
                                8u,
                                "%s: STA profile frag error",
                                v299,
                                v300,
                                v301,
                                v302,
                                v303,
                                v304,
                                v305,
                                v306,
                                "populate_dot11f_assoc_req_mlo_ie");
                              *(_WORD *)v127 = 257;
                            }
                          }
                          v122 = v312 + 1;
                          goto LABEL_277;
                        }
                        goto LABEL_261;
                      }
                    }
                    else
                    {
LABEL_230:
                      if ( v248 )
                      {
                        v249 = 1;
                        LOBYTE(v370[0]) = 35;
                        goto LABEL_233;
                      }
                    }
                    v249 = 0;
                    goto LABEL_233;
                  }
                  v244 = v70[552];
                  if ( LOBYTE(v326[0]) )
                  {
                    if ( v70[552] )
                      goto LABEL_165;
                    goto LABEL_159;
                  }
                }
                if ( v244 )
                  *((_BYTE *)v371 + v193++) = -65;
                goto LABEL_165;
              }
              *(_WORD *)((char *)v326 + 1) &= 0xFF93u;
              goto LABEL_156;
            }
            v217 = v70[472];
            if ( LOBYTE(v367[0]) )
            {
              if ( v70[472] )
                goto LABEL_126;
              goto LABEL_120;
            }
          }
          if ( v217 )
          {
            v218 = v193++;
            *(_BYTE *)((unsigned __int64)v371 | v218) = 45;
          }
          goto LABEL_126;
        }
      }
      v193 = 0;
      goto LABEL_111;
    }
    LOBYTE(v122) = 0;
LABEL_282:
    result = 0;
    *(_WORD *)(a2 + 10896) = (unsigned __int8)v122;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: mlo_dev_ctx is null",
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      "populate_dot11f_assoc_req_mlo_ie");
    result = 29;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
