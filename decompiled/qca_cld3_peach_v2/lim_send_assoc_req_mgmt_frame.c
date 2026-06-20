__int64 __fastcall lim_send_assoc_req_mgmt_frame(
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
  __int64 v12; // x8
  unsigned int v15; // w28
  unsigned __int8 *v16; // x0
  unsigned __int8 *v17; // x20
  const char *v18; // x2
  __int64 v19; // x0
  char *v20; // x0
  char *v21; // x21
  _BYTE *v22; // x25
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  int v32; // w27
  _BYTE *v33; // x11
  unsigned int v34; // w9
  int v35; // w24
  int v36; // w26
  char v37; // w8
  char v38; // w8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  char *v47; // x2
  __int64 v48; // x0
  __int64 v49; // x1
  unsigned int v50; // w8
  char v51; // w9
  __int64 v52; // x1
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w2
  int v62; // w3
  int v63; // w5
  int v64; // w4
  int v65; // w0
  int v66; // w1
  unsigned __int8 *v67; // x8
  unsigned __int8 *v68; // x24
  int v69; // w8
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  unsigned int v80; // w9
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  unsigned __int8 *v90; // x0
  int v91; // w3
  unsigned __int16 v92; // w27
  int v93; // w24
  __int64 v94; // x0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  const char *v103; // x2
  __int64 v104; // x26
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  __int64 v113; // x23
  size_t v114; // x2
  unsigned __int16 v115; // w24
  __int64 v116; // x8
  __int16 v117; // w26
  __int16 v118; // w8
  __int64 v119; // x24
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int64 v128; // x22
  unsigned __int8 v129; // w24
  size_t v130; // x2
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  unsigned int v139; // w24
  unsigned __int16 v140; // w2
  _BYTE *v141; // x28
  __int64 v142; // x0
  unsigned __int16 v143; // w27
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  const char *v152; // x2
  _WORD *v153; // x0
  _WORD *v154; // x24
  int v155; // w8
  unsigned int v156; // w27
  unsigned int v157; // w0
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  __int64 v166; // x0
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  _BYTE *v175; // x25
  bool is_24ghz_ch_freq; // w0
  __int64 v177; // x9
  __int64 v178; // x10
  __int64 v179; // x9
  __int64 v180; // x9
  __int64 v181; // x9
  __int64 v182; // x8
  __int64 v183; // x11
  __int64 v184; // x8
  __int64 v185; // x11
  __int64 v186; // x8
  __int64 v187; // x8
  char v188; // w8
  unsigned __int8 v189; // w8
  __int64 v190; // x4
  const char *v191; // x2
  unsigned int packed_assoc_request_size; // w0
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  int v201; // w28
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  int v210; // w3
  __int16 v211; // w2
  char v212; // w8
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  unsigned int v221; // w0
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  unsigned int v230; // w8
  unsigned __int16 v231; // w25
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 result; // x0
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  unsigned __int16 v249; // w2
  __int64 v250; // x0
  void *v251; // x0
  bool v252; // w0
  int v253; // w8
  unsigned int v254; // w9
  int v255; // w8
  char v256; // w9
  char *v257; // x27
  double v258; // d0
  double v259; // d1
  double v260; // d2
  double v261; // d3
  double v262; // d4
  double v263; // d5
  double v264; // d6
  double v265; // d7
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  int v274; // w28
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  _QWORD *context; // x0
  unsigned int v284; // w25
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
  __int64 v293; // [xsp+0h] [xbp-210h]
  __int64 v294; // [xsp+0h] [xbp-210h]
  int v295; // [xsp+0h] [xbp-210h]
  int v296; // [xsp+8h] [xbp-208h]
  int v297; // [xsp+8h] [xbp-208h]
  int v298; // [xsp+10h] [xbp-200h]
  int v299; // [xsp+10h] [xbp-200h]
  int v300; // [xsp+18h] [xbp-1F8h]
  int v301; // [xsp+20h] [xbp-1F0h]
  int v302; // [xsp+44h] [xbp-1CCh]
  const void *v303; // [xsp+60h] [xbp-1B0h]
  unsigned __int8 v304; // [xsp+68h] [xbp-1A8h]
  char v305; // [xsp+6Ch] [xbp-1A4h]
  unsigned int v306; // [xsp+70h] [xbp-1A0h]
  unsigned int v307; // [xsp+74h] [xbp-19Ch]
  int v308; // [xsp+78h] [xbp-198h]
  char *v309; // [xsp+78h] [xbp-198h]
  unsigned int v310; // [xsp+80h] [xbp-190h]
  char v311; // [xsp+84h] [xbp-18Ch]
  unsigned __int16 v312; // [xsp+88h] [xbp-188h]
  unsigned __int8 v313; // [xsp+8Ch] [xbp-184h]
  const void *v314; // [xsp+90h] [xbp-180h]
  unsigned __int16 v315; // [xsp+9Ch] [xbp-174h]
  int v316; // [xsp+9Ch] [xbp-174h]
  const void *v317; // [xsp+A0h] [xbp-170h]
  int v318; // [xsp+ACh] [xbp-164h]
  _BOOL4 v319; // [xsp+BCh] [xbp-154h]
  __int64 v320; // [xsp+C0h] [xbp-150h]
  unsigned __int8 *v321; // [xsp+C8h] [xbp-148h]
  _BYTE *v322; // [xsp+D0h] [xbp-140h]
  _BYTE *v323; // [xsp+D8h] [xbp-138h]
  __int64 v324; // [xsp+E0h] [xbp-130h] BYREF
  __int64 v325; // [xsp+E8h] [xbp-128h]
  __int64 v326; // [xsp+F0h] [xbp-120h]
  __int64 v327; // [xsp+F8h] [xbp-118h]
  unsigned __int16 n[8]; // [xsp+104h] [xbp-10Ch] BYREF
  unsigned int v329; // [xsp+114h] [xbp-FCh] BYREF
  __int64 v330; // [xsp+118h] [xbp-F8h] BYREF
  char *v331; // [xsp+120h] [xbp-F0h] BYREF
  _DWORD v332[2]; // [xsp+128h] [xbp-E8h] BYREF
  _QWORD v333[7]; // [xsp+130h] [xbp-E0h] BYREF
  int v334; // [xsp+168h] [xbp-A8h]
  _QWORD v335[11]; // [xsp+170h] [xbp-A0h] BYREF
  int v336; // [xsp+1C8h] [xbp-48h]
  _QWORD v337[2]; // [xsp+1D0h] [xbp-40h] BYREF
  char v338; // [xsp+1E0h] [xbp-30h]
  __int128 v339; // [xsp+1E8h] [xbp-28h] BYREF
  char v340; // [xsp+1F8h] [xbp-18h]
  __int64 v341; // [xsp+200h] [xbp-10h]

  v341 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v330 = 0;
  v331 = nullptr;
  *(_DWORD *)((char *)v332 + 3) = 2923119;
  v329 = 0;
  *(_QWORD *)&n[2] = 0;
  n[0] = 0;
  v340 = 0;
  v339 = 0u;
  v338 = 0;
  v337[0] = 0;
  v337[1] = 0;
  v326 = 0;
  v327 = 0;
  v324 = 0;
  v325 = 0;
  v332[0] = 1867515357;
  if ( !a3 )
  {
    v18 = "%s: pe_session is NULL";
LABEL_8:
    qdf_trace_msg(0x35u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "lim_send_assoc_req_mgmt_frame");
    v19 = a2;
    goto LABEL_213;
  }
  v12 = *(_QWORD *)(a3 + 112);
  if ( !v12 )
  {
    v18 = "%s: pe_session->lim_join_req is NULL";
    goto LABEL_8;
  }
  v15 = *(unsigned __int8 *)(a3 + 10);
  n[0] = *(_WORD *)(v12 + 2312);
  if ( n[0] )
  {
    v16 = (unsigned __int8 *)_qdf_mem_malloc(n[0], "lim_send_assoc_req_mgmt_frame", 3214);
    if ( !v16 )
    {
      v19 = a2;
      goto LABEL_213;
    }
    v17 = v16;
    qdf_mem_copy(v16, (const void *)(*(_QWORD *)(a3 + 112) + 2314LL), n[0]);
  }
  else
  {
    v17 = nullptr;
  }
  v20 = (char *)_qdf_mem_malloc(0x16CCu, "lim_send_assoc_req_mgmt_frame", 3229);
  if ( v20 )
  {
    v21 = v20;
    v22 = (_BYTE *)(a3 + 7024);
    qdf_mem_set(v20, 0x16CCu, 0);
    if ( n[0] && *(_BYTE *)(a3 + 8654) == 1 )
    {
      qdf_mem_set(&v339, 0x11u, 0);
      if ( (unsigned int)lim_strip_extcap_update_struct(a1, v17, n, &v339) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Unable to Stripoff ExtCap IE from Assoc Req",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "lim_send_assoc_req_mgmt_frame");
        v319 = 0;
      }
      else
      {
        if ( (*(_DWORD *)((_BYTE *)&v339 + 2) & 0x80000000) != 0 )
          *(_QWORD *)((char *)&v339 + 2) |= 0x100000000uLL;
        BYTE1(v339) = lim_compute_ext_cap_ie_length(&v339);
        v319 = BYTE1(v339) != 0;
      }
    }
    else
    {
      v319 = 0;
    }
    if ( *(_DWORD *)(a3 + 424) == 5 )
      v31 = *(_WORD *)(a2 + 6) & 0xFFEF;
    else
      v31 = *(unsigned __int16 *)(a2 + 6);
    swap_bit_field16(v31, v21);
    *((_WORD *)v21 + 1) = *(_WORD *)(a2 + 8);
    populate_dot11f_ssid2(a3, v21 + 4);
    populate_dot11f_supp_rates(a1, 255, v21 + 38, a3);
    if ( (*v22 & 1) != 0 )
    {
      v32 = (*(unsigned __int16 *)(a3 + 176) >> 9) & 1;
      v33 = (_BYTE *)(a1 + 20208);
      if ( (*v22 & 2) != 0 )
        goto LABEL_21;
    }
    else
    {
      v32 = 0;
      v33 = (_BYTE *)(a1 + 20208);
      if ( (*v22 & 2) != 0 )
      {
LABEL_21:
        v34 = *(unsigned __int8 *)(a3 + 178);
        v35 = 0;
        v36 = (v34 >> 1) & 1 & ~v32;
        if ( (*v22 & 4) != 0 && v36 )
        {
          v35 = (v34 >> 2) & 1;
          v36 = 1;
        }
LABEL_27:
        v322 = v33;
        if ( *(_DWORD *)(a3 + 7028) && *(_BYTE *)(a3 + 7194) == 1 )
        {
          populate_dot11f_power_caps(a1, v21 + 66, 0, a3);
          populate_dot11f_supp_channels(a1, v21 + 69, 0, a3);
          v37 = 0;
          if ( !*v322 )
            goto LABEL_36;
        }
        else
        {
          v37 = 1;
          if ( !*v33 )
            goto LABEL_36;
        }
        v38 = v37 ^ 1;
        if ( (*(_WORD *)(a3 + 176) & 0x1000) == 0 )
          v38 = 1;
        if ( (v38 & 1) == 0 )
          populate_dot11f_power_caps(a1, v21 + 66, 0, a3);
LABEL_36:
        if ( v32 )
          populate_dot11f_qos_caps_station(a1, a3, v21 + 422);
        populate_dot11f_ext_supp_rates(a1, 255, v21 + 52, a3);
        if ( *v322 && (*(_WORD *)(a3 + 176) & 0x1000) != 0 )
          populate_dot11f_rrm_ie(a1, v21 + 424, a3);
        if ( !v17 || !n[0] || !wlan_get_vendor_ie_ptr_from_oui(&unk_AFC188, 4u, v17, n[0]) )
        {
          populate_dot11f_rsn_opaque(a1, *(_QWORD *)(a3 + 112), v21 + 167);
          populate_dot11f_wpa_opaque(a1, *(_QWORD *)(a3 + 112), v21 + 3976);
          populate_dot11f_wapi_opaque(a1, *(_QWORD *)(a3 + 112), v21 + 2164);
        }
        if ( v36 )
        {
          populate_dot11f_wmm_info_station_per_session(a1, a3, v21 + 4230);
          if ( v35 )
            populate_dot11f_wmm_caps(v21 + 4227);
        }
        if ( *(_BYTE *)(a3 + 155) && *(_BYTE *)(a1 + 12209) )
        {
          v47 = v21 + 472;
          v48 = a1;
          v49 = a3;
        }
        else
        {
          if ( *(_BYTE *)(a3 + 9968) != 1 )
          {
LABEL_54:
            if ( *(_BYTE *)(a3 + 7170) && *(_BYTE *)(a3 + 7173) )
            {
              populate_dot11f_vht_caps(a1, a3, v21 + 552);
              if ( *(_BYTE *)(a3 + 7171) )
              {
                if ( !*(_DWORD *)(a3 + 7180) )
                {
                  if ( v21[552] )
                  {
                    v50 = *(unsigned __int8 *)(a3 + 154);
                    if ( v50 >= 0xE || ((0x3C01u >> v50) & 1) == 0 )
                      populate_dot11f_operating_mode(a1, v21 + 568, a3);
                  }
                }
              }
            }
            else
            {
              if ( *(_BYTE *)(a3 + 9968) == 1 )
                populate_dot11f_vht_caps(a1, 0, v21 + 552);
              if ( *(_BYTE *)(a3 + 8626) != 1 )
              {
                v52 = 0;
LABEL_72:
                if ( *(_BYTE *)(a3 + 8654) == 1 )
                  populate_dot11f_ext_cap(a1, v52, v21 + 532, a3);
                populate_dot11f_qcn_ie(a1, a3, v21 + 5276, 255);
                populate_dot11f_bss_max_idle(a1, a3, v21 + 1364);
                if ( (unsigned int)*(unsigned __int8 *)(a3 + 154) - 10 < 4 || !*(_BYTE *)(a3 + 154) )
                  lim_update_session_he_capable(a1, a3);
                if ( *(_BYTE *)(a3 + 8676) == 1 )
                {
                  v61 = *(_DWORD *)(a3 + 7036);
                  v62 = *(_DWORD *)(a3 + 284);
                  v63 = (_DWORD)v21 + 2100;
                  v64 = *(_DWORD *)(a3 + 7176);
                  v65 = a1;
                  v66 = a3;
                }
                else
                {
                  if ( *(_BYTE *)(a3 + 9968) != 1 )
                  {
LABEL_82:
                    if ( n[0] && *(_BYTE *)(a3 + 10071) == 1 )
                    {
                      populate_dot11f_eht_caps(a1, a3, (_DWORD)v21 + 3108);
                      lim_strip_mlo_ie(a1, v17, n);
                    }
                    if ( (unsigned int)*(unsigned __int8 *)(a3 + 154) - 10 < 4 || !*(_BYTE *)(a3 + 154) )
                      populate_dot11f_reg_connectivity(a1, v21 + 3974);
                    if ( *(_BYTE *)(a3 + 7041) == 1 )
                    {
                      v67 = *(unsigned __int8 **)(a3 + 112);
                      v68 = v67 + 4096;
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: mdie = %02x %02x %02x",
                        v53,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        "lim_send_assoc_req_mgmt_frame",
                        v67[4593],
                        v67[4594],
                        v67[4595]);
                      populate_mdie(a1, v21 + 430, *(_QWORD *)(a3 + 112) + 4593LL);
                      v69 = v68[496];
                      if ( v68[496] )
                      {
                        LOBYTE(v325) = 1;
                        v69 = *(unsigned __int16 *)(v68 + 497);
                      }
                      else
                      {
                        LOBYTE(v325) = 0;
                      }
                      v70 = *(_QWORD *)(a1 + 21624);
                      LODWORD(v324) = v69;
                      wlan_cm_roam_cfg_set_value(v70, v15, 0x14u, (unsigned int *)&v324);
                      if ( **(_BYTE **)(a3 + 9976) == 1 )
                        populate_fils_ft_info(a1, v21 + 1370, a3);
                    }
                    if ( *(_BYTE *)(a3 + 8624) && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1766LL) == 1 )
                      populate_dot11f_ese_version(v21 + 4487);
                    if ( (wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21632), *(_BYTE *)(a3 + 10)) & 1) != 0 )
                    {
                      populate_dot11f_ese_rad_mgmt_cap(v21 + 4484);
                      if ( !v319 )
                        goto LABEL_99;
                    }
                    else if ( !v319 )
                    {
LABEL_99:
                      if ( !v21[532] )
                        goto LABEL_108;
LABEL_103:
                      if ( *(_BYTE *)(a3 + 8654) == 1 )
                      {
                        qdf_mem_set(v337, 0x11u, 0);
                        v79 = *(_QWORD *)(a3 + 320);
                        if ( v79 )
                        {
                          v80 = *(_DWORD *)(a3 + 312);
                          if ( v80 >= 0x25 )
                          {
                            ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(
                                                0x7Fu,
                                                (unsigned __int8 *)(v79 + 36),
                                                (unsigned __int16)v80 - 36);
                            lim_update_extcap_struct(a1, ie_ptr_from_eid, v337);
                            lim_merge_extcap_struct(v21 + 532, v337, 0);
                          }
                        }
                        populate_dot11f_btm_extended_caps(a1, a3, v21 + 532);
                        populate_dot11f_twt_extended_caps(a1, a3, v21 + 532);
LABEL_109:
                        if ( (unsigned int)lim_strip_supp_op_class_update_struct(a1, v17, n, v21 + 436) )
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Unable to Stripoff supp op classes IE from Assoc Req",
                            v82,
                            v83,
                            v84,
                            v85,
                            v86,
                            v87,
                            v88,
                            v89,
                            "lim_send_assoc_req_mgmt_frame");
                        if ( **(_BYTE **)(a3 + 9976) == 1 )
                        {
                          populate_dot11f_fils_params(a1, v21, a3);
                          if ( n[0] )
                          {
                            v90 = wlan_get_ie_ptr_from_eid(0xF2u, v17, n[0]);
                            v91 = n[0];
                            v92 = 0;
                            v93 = 16;
                            v321 = nullptr;
                            if ( !v90 || !n[0] )
                            {
LABEL_122:
                              if ( !v91 )
                                goto LABEL_137;
                              goto LABEL_123;
                            }
                            if ( wlan_get_ext_ie_ptr_from_ext_id(&unk_969B80, 1u, v17, n[0]) )
                            {
                              v94 = _qdf_mem_malloc(0x800u, "lim_send_assoc_req_mgmt_frame", 3554);
                              v321 = (unsigned __int8 *)v94;
                              if ( !v94 )
                              {
                                v113 = 0;
                                v104 = 0;
                                v320 = 0;
                                v321 = nullptr;
                                goto LABEL_147;
                              }
                              if ( (unsigned int)lim_strip_ie(a1, v17, n, 255, 1, &unk_969B80, 1, v94, 2046) )
                              {
                                v103 = "%s: Failed to strip FILS HLP container IE";
LABEL_134:
                                qdf_trace_msg(
                                  0x35u,
                                  2u,
                                  v103,
                                  v95,
                                  v96,
                                  v97,
                                  v98,
                                  v99,
                                  v100,
                                  v101,
                                  v102,
                                  "lim_send_assoc_req_mgmt_frame");
                                v113 = 0;
                                v104 = 0;
                                goto LABEL_135;
                              }
                              v115 = n[0];
                              v116 = v321[1];
                              v117 = v116 + 2;
                              if ( (unsigned int)lim_strip_ie(
                                                   a1,
                                                   v17,
                                                   n,
                                                   242,
                                                   1,
                                                   0,
                                                   0,
                                                   &v321[v116 + 2],
                                                   2044 - (int)v116) )
                              {
                                v103 = "%s: Failed to strip fragment IE of HLP container IE";
                                goto LABEL_134;
                              }
                              LOWORD(v91) = n[0];
                              v118 = v117 + v115;
                              v93 = 16;
                              v92 = v118 - n[0];
                              if ( !n[0] )
                                goto LABEL_137;
LABEL_123:
                              if ( wlan_get_ie_ptr_from_eid(0xF4u, v17, v91) )
                              {
                                v94 = _qdf_mem_malloc(0x101u, "lim_send_assoc_req_mgmt_frame", 3586);
                                v104 = v94;
                                if ( !v94 )
                                  goto LABEL_146;
                                v318 = v93;
                                if ( (unsigned int)lim_strip_ie(a1, v17, n, 244, 1, 0, 0, v94, 255) )
                                {
                                  qdf_trace_msg(
                                    0x35u,
                                    2u,
                                    "%s: Failed to strip Vendor IEs",
                                    v105,
                                    v106,
                                    v107,
                                    v108,
                                    v109,
                                    v110,
                                    v111,
                                    v112,
                                    "lim_send_assoc_req_mgmt_frame");
                                  v113 = 0;
LABEL_135:
                                  v320 = 0;
LABEL_143:
                                  v323 = nullptr;
LABEL_144:
                                  v128 = 0;
                                  v94 = 0;
                                  goto LABEL_212;
                                }
                                v21[1590] = 1;
                                v114 = *(unsigned __int8 *)(v104 + 1);
                                v21[1591] = v114;
                                qdf_mem_copy(v21 + 1592, (const void *)(v104 + 2), v114);
LABEL_138:
                                if ( !n[0] )
                                {
                                  v315 = v92;
                                  v129 = 0;
                                  v311 = v15;
                                  v323 = nullptr;
                                  v307 = 0;
                                  v320 = 0;
                                  goto LABEL_160;
                                }
                                if ( !wlan_get_ext_ie_ptr_from_ext_id("X", 1u, v17, n[0]) )
                                {
                                  v320 = 0;
LABEL_150:
                                  v315 = v92;
                                  if ( !n[0] )
                                  {
                                    v311 = v15;
                                    v129 = 0;
                                    v323 = nullptr;
                                    v307 = 0;
                                    goto LABEL_160;
                                  }
                                  if ( !wlan_get_vendor_ie_ptr_from_oui(&unk_9E723A, 4u, v17, n[0]) )
                                  {
                                    v311 = v15;
                                    goto LABEL_157;
                                  }
                                  v94 = _qdf_mem_malloc(0x127u, "lim_send_assoc_req_mgmt_frame", 3640);
                                  v323 = (_BYTE *)v94;
                                  if ( v94 )
                                  {
                                    if ( (unsigned int)lim_strip_ie(a1, v17, n, 221, 1, &unk_9E723A, 4, v94, 293) )
                                    {
                                      qdf_trace_msg(
                                        0x35u,
                                        2u,
                                        "%s: Failed to strip MBO IE",
                                        v131,
                                        v132,
                                        v133,
                                        v134,
                                        v135,
                                        v136,
                                        v137,
                                        v138,
                                        "lim_send_assoc_req_mgmt_frame");
                                      v113 = 0;
                                      goto LABEL_144;
                                    }
                                    v311 = v15;
                                    v129 = v323[1] + 2;
                                    if ( !*(_DWORD *)(a3 + 156) )
                                    {
                                      v307 = 1;
LABEL_158:
                                      if ( n[0] )
                                        lim_strip_ie(a1, v17, n, 221, 1, &unk_A21B39, 4, 0, 0);
LABEL_160:
                                      v313 = v129;
                                      v308 = *(unsigned __int8 *)(a3 + 13285);
                                      if ( *(_BYTE *)(a3 + 13285) )
                                      {
                                        v139 = 7;
                                        BYTE2(v332[1]) = *(_BYTE *)(a3 + 13285) - 1;
                                        v140 = n[0];
                                        if ( !n[0] )
                                          goto LABEL_168;
                                      }
                                      else
                                      {
                                        v139 = 0;
                                        v140 = n[0];
                                        if ( !n[0] )
                                          goto LABEL_168;
                                      }
                                      if ( wlan_get_ie_ptr_from_eid(0xDDu, v17, v140) )
                                      {
                                        v141 = v323;
                                        v142 = _qdf_mem_malloc(0x5FEu, "lim_send_assoc_req_mgmt_frame", 3695);
                                        if ( v142 )
                                        {
                                          v143 = n[0];
                                          v317 = (const void *)v142;
                                          if ( (unsigned int)lim_strip_ie(a1, v17, n, 221, 1, 0, 0, v142, 1532) )
                                          {
                                            v152 = "%s: Failed to strip Vendor IEs";
                                            goto LABEL_195;
                                          }
                                          v312 = v143 - n[0];
LABEL_170:
                                          v323 = v141;
                                          if ( *(_BYTE *)(a3 + 7042) != 1 )
                                          {
                                            v314 = nullptr;
                                            v155 = 0;
                                            goto LABEL_174;
                                          }
                                          v306 = v139;
                                          v153 = (_WORD *)_qdf_mem_malloc(0xDu, "lim_fill_adaptive_11r_ie", 3086);
                                          if ( v153 )
                                          {
                                            v154 = v153;
                                            *v153 = 3037;
                                            qdf_mem_copy(v153 + 1, &unk_AFC193, 4u);
                                            v154[3] = 256;
                                            *((_BYTE *)v154 + 8) = 4;
                                            v314 = v154;
                                            qdf_mem_copy((char *)v154 + 9, &unk_AFC198, 4u);
                                            v139 = v306;
                                            v155 = 13;
LABEL_174:
                                            v310 = v155;
                                            if ( *(_DWORD *)(*(_QWORD *)(a3 + 112) + 4648LL)
                                              && *(_BYTE *)(a3 + 13285) != 2 )
                                            {
                                              v156 = ((__int64 (__fastcall *)(__int64, __int64, char *))lim_fill_assoc_req_mlo_ie)(
                                                       a1,
                                                       a3,
                                                       v21);
                                              if ( (mlo_is_mld_sta(*(_QWORD *)(a3 + 16)) & 1) != 0 && !(_WORD)v156 )
                                              {
                                                v190 = *(unsigned __int8 *)(a3 + 10);
                                                v191 = "%s: Failed to add ML IE for vdev:%d";
                                                goto LABEL_190;
                                              }
                                            }
                                            else
                                            {
                                              v156 = 0;
                                            }
                                            if ( !n[0]
                                              || (v157 = dot11f_unpack_assoc_request(a1, v17), (v157 & 0x10000000) == 0) )
                                            {
                                              if ( *(_BYTE *)(a3 + 10071) != 1 )
                                              {
                                                v175 = nullptr;
                                                v189 = 0;
                                                goto LABEL_186;
                                              }
                                              v166 = _qdf_mem_malloc(0x101u, "lim_send_assoc_req_mgmt_frame", 3752);
                                              if ( v166 )
                                              {
                                                v175 = (_BYTE *)v166;
                                                is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284));
                                                v177 = *(_QWORD *)(v21 + 3172);
                                                v178 = *(_QWORD *)(v21 + 3180);
                                                v335[10] = *(_QWORD *)(v21 + 3188);
                                                v335[8] = v177;
                                                v335[9] = v178;
                                                v336 = *((_DWORD *)v21 + 799);
                                                v179 = *(_QWORD *)(v21 + 3148);
                                                v335[4] = *(_QWORD *)(v21 + 3140);
                                                v335[5] = v179;
                                                v180 = *(_QWORD *)(v21 + 3164);
                                                v335[6] = *(_QWORD *)(v21 + 3156);
                                                v335[7] = v180;
                                                v181 = *(_QWORD *)(v21 + 3116);
                                                v183 = *(_QWORD *)(v21 + 3124);
                                                v182 = *(_QWORD *)(v21 + 3132);
                                                v335[0] = *(_QWORD *)(v21 + 3108);
                                                v335[1] = v181;
                                                v335[2] = v183;
                                                v335[3] = v182;
                                                v184 = *(_QWORD *)(v21 + 2140);
                                                v185 = *(_QWORD *)(v21 + 2148);
                                                v333[4] = *(_QWORD *)(v21 + 2132);
                                                v333[5] = v184;
                                                LODWORD(v184) = *((_DWORD *)v21 + 539);
                                                v333[6] = v185;
                                                v334 = v184;
                                                v186 = *(_QWORD *)(v21 + 2108);
                                                v333[0] = *(_QWORD *)(v21 + 2100);
                                                v333[1] = v186;
                                                v187 = *(_QWORD *)(v21 + 2124);
                                                v333[2] = *(_QWORD *)(v21 + 2116);
                                                v333[3] = v187;
                                                lim_ieee80211_pack_ehtcap(v175, v335, v333, is_24ghz_ch_freq, 1);
                                                v188 = v175[1];
                                                v21[3108] = 0;
                                                v189 = v188 + 2;
LABEL_186:
                                                v304 = v189;
                                                packed_assoc_request_size = dot11f_get_packed_assoc_request_size(
                                                                              a1,
                                                                              v21,
                                                                              &v329);
                                                v303 = v175;
                                                if ( (packed_assoc_request_size & 0x10000000) != 0 )
                                                {
                                                  qdf_trace_msg(
                                                    0x35u,
                                                    2u,
                                                    "%s: Association Request packet size failure(0x%08x)",
                                                    v193,
                                                    v194,
                                                    v195,
                                                    v196,
                                                    v197,
                                                    v198,
                                                    v199,
                                                    v200,
                                                    "lim_send_assoc_req_mgmt_frame",
                                                    packed_assoc_request_size);
                                                  v329 = 5836;
                                                }
                                                else if ( packed_assoc_request_size )
                                                {
                                                  qdf_trace_msg(
                                                    0x35u,
                                                    3u,
                                                    "%s: Association request packet size warning (0x%08x)",
                                                    v193,
                                                    v194,
                                                    v195,
                                                    v196,
                                                    v197,
                                                    v198,
                                                    v199,
                                                    v200,
                                                    "lim_send_assoc_req_mgmt_frame");
                                                }
                                                v201 = v318
                                                     + v315
                                                     + v313
                                                     + v139
                                                     + v312
                                                     + v310
                                                     + (unsigned __int16)v156
                                                     + v304
                                                     + v329;
                                                if ( (unsigned int)cds_packet_alloc(
                                                                     (unsigned __int16)v318
                                                                   + v315
                                                                   + v313
                                                                   + (unsigned __int16)v139
                                                                   + v312
                                                                   + (unsigned __int16)v310
                                                                   + (unsigned __int16)v156
                                                                   + v304
                                                                   + (unsigned __int16)v329
                                                                   + 24,
                                                                     &v331,
                                                                     &n[2]) )
                                                {
                                                  qdf_trace_msg(
                                                    0x35u,
                                                    2u,
                                                    "%s: Failed to allocate %d bytes",
                                                    v202,
                                                    v203,
                                                    v204,
                                                    v205,
                                                    v206,
                                                    v207,
                                                    v208,
                                                    v209,
                                                    "lim_send_assoc_req_mgmt_frame",
                                                    (unsigned int)(v201 + 24));
                                                  v210 = *(_DWORD *)(a3 + 76);
                                                  v211 = *(_WORD *)(a3 + 8);
                                                  *(_DWORD *)(a3 + 72) = v210;
                                                  qdf_trace(53, 0, v211, v210);
                                                  v212 = *(_BYTE *)(a3 + 8);
                                                  LODWORD(v330) = 502;
                                                  BYTE6(v330) = v212;
                                                  lim_process_mlm_rsp_messages(
                                                    a1,
                                                    1010,
                                                    (unsigned __int8 *)&v330,
                                                    v213,
                                                    v214,
                                                    v215,
                                                    v216,
                                                    v217,
                                                    v218,
                                                    v219,
                                                    v220);
                                                }
                                                else
                                                {
                                                  v302 = v315;
                                                  qdf_mem_set(v331, (unsigned int)(v201 + 24), 0);
                                                  lim_populate_mac_header(
                                                    a1,
                                                    (__int64)v331,
                                                    0,
                                                    0,
                                                    (const void *)(a3 + 24),
                                                    (_BYTE *)(a3 + 30));
                                                  v221 = dot11f_pack_assoc_request(a1, v21, v331 + 24, v329, &v329);
                                                  if ( (v221 & 0x10000000) == 0 )
                                                  {
                                                    if ( v221 )
                                                      qdf_trace_msg(
                                                        0x35u,
                                                        3u,
                                                        "%s: Assoc request pack warning (0x%08x)",
                                                        v222,
                                                        v223,
                                                        v224,
                                                        v225,
                                                        v226,
                                                        v227,
                                                        v228,
                                                        v229,
                                                        "lim_send_assoc_req_mgmt_frame");
                                                    v230 = v329;
                                                    if ( v321 && v315 )
                                                    {
                                                      qdf_mem_copy(&v331[v329 + 24], v321, v315);
                                                      v230 = v329 + v315;
                                                      v329 = v230;
                                                    }
                                                    v231 = v156;
                                                    if ( (_WORD)v156 )
                                                    {
                                                      if ( (unsigned int)lim_fill_complete_mlo_ie(
                                                                           a3,
                                                                           v156,
                                                                           &v331[v230 + 24]) )
                                                      {
                                                        qdf_trace_msg(
                                                          0x35u,
                                                          8u,
                                                          "%s: assemble ml ie error",
                                                          v232,
                                                          v233,
                                                          v234,
                                                          v235,
                                                          v236,
                                                          v237,
                                                          v238,
                                                          v239,
                                                          "lim_send_assoc_req_mgmt_frame");
                                                        v231 = 0;
                                                      }
                                                      v316 = v231;
                                                      v230 = v329 + v231;
                                                      v329 = v230;
                                                    }
                                                    else
                                                    {
                                                      v316 = 0;
                                                    }
                                                    if ( v304 )
                                                    {
                                                      qdf_mem_copy(&v331[v230 + 24], v303, v304);
                                                      v230 = v329 + v304;
                                                      v329 = v230;
                                                    }
                                                    if ( v308 )
                                                    {
                                                      qdf_mem_copy(&v331[v230 + 24], v332, v139);
                                                      v230 = v329 + v139;
                                                      v329 += v139;
                                                    }
                                                    qdf_mem_copy(&v331[v230 + 24], v323, v313);
                                                    v329 += v313;
                                                    qdf_mem_copy(&v331[v329 + 24], v317, v312);
                                                    v329 += v312;
                                                    qdf_mem_copy(&v331[v329 + 24], v314, v310);
                                                    v249 = v329 + v310 - 4;
                                                    v329 += v310;
                                                    lim_reorder_vendor_ies(a1, (__int64)(v331 + 28), v249);
                                                    v250 = *(_QWORD *)(a3 + 336);
                                                    if ( v250 )
                                                    {
                                                      _qdf_mem_free(v250);
                                                      *(_QWORD *)(a3 + 336) = 0;
                                                      *(_DWORD *)(a3 + 328) = 0;
                                                    }
                                                    if ( **(_BYTE **)(a3 + 9976) == 1
                                                      && (unsigned int)aead_encrypt_assoc_req(a1, a3, v331, &v329) )
                                                    {
                                                      cds_packet_free(*(__int64 *)&n[2]);
                                                    }
                                                    else
                                                    {
                                                      v251 = (void *)_qdf_mem_malloc(
                                                                       v329,
                                                                       "lim_send_assoc_req_mgmt_frame",
                                                                       3895);
                                                      *(_QWORD *)(a3 + 336) = v251;
                                                      if ( v251 )
                                                      {
                                                        qdf_mem_copy(v251, v331 + 24, v329);
                                                        *(_DWORD *)(a3 + 328) = v329;
                                                      }
                                                      v252 = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284));
                                                      v253 = *(_DWORD *)(a3 + 7036);
                                                      v254 = v253 & 0xFFFFFFFE;
                                                      v255 = v253 | 2;
                                                      v256 = (v254 == 2) << 6;
                                                      if ( !v252 )
                                                        v256 = 64;
                                                      if ( v255 == 2 )
                                                        v256 |= 0x80u;
                                                      v305 = v256;
                                                      v309 = v331;
                                                      v257 = v331 + 10;
                                                      qdf_trace(
                                                        53,
                                                        2u,
                                                        *(_WORD *)(a3 + 8),
                                                        (unsigned __int8)*(_WORD *)v331 >> 4);
                                                      LODWORD(v293) = v312;
                                                      qdf_trace_msg(
                                                        0x35u,
                                                        8u,
                                                        "%s: Assoc Req IEs: dot11mode %d, extcap %d, open %d, IE len:: mb"
                                                        "o %d vendor %d, rsn_sel %d, ft11r %d, mlo %d, eht %d, fils %d",
                                                        v258,
                                                        v259,
                                                        v260,
                                                        v261,
                                                        v262,
                                                        v263,
                                                        v264,
                                                        v265,
                                                        "lim_send_assoc_req_mgmt_frame",
                                                        *(unsigned __int8 *)(a3 + 154),
                                                        v319,
                                                        v307,
                                                        v313,
                                                        v293,
                                                        v139,
                                                        v310,
                                                        v316,
                                                        v304,
                                                        v302);
                                                      LODWORD(v294) = *((unsigned __int16 *)v322 + 698);
                                                      qdf_trace_msg(
                                                        0x35u,
                                                        4u,
                                                        "Assoc req TX: vdev %d to %02x:%02x:%02x:**:**:%02x seq num %d",
                                                        v266,
                                                        v267,
                                                        v268,
                                                        v269,
                                                        v270,
                                                        v271,
                                                        v272,
                                                        v273,
                                                        *(unsigned __int8 *)(a3 + 10),
                                                        *(unsigned __int8 *)(a3 + 24),
                                                        *(unsigned __int8 *)(a3 + 25),
                                                        *(unsigned __int8 *)(a3 + 26),
                                                        *(unsigned __int8 *)(a3 + 29),
                                                        v294);
                                                      LOBYTE(v298) = 0;
                                                      LOBYTE(v295) = v21[2100] != 0;
                                                      LOBYTE(v296) = v21[3108] != 0;
                                                      lim_cp_stats_cstats_log_assoc_req_evt(
                                                        a3,
                                                        0,
                                                        a3 + 24,
                                                        v257,
                                                        (unsigned __int8)v21[5],
                                                        v21 + 6,
                                                        v21[472] != 0,
                                                        v21[552] != 0,
                                                        v295,
                                                        v296,
                                                        v298);
                                                      v274 = ((__int64 (__fastcall *)(__int64, _QWORD))lim_get_min_session_txrate)(
                                                               a3,
                                                               0);
                                                      lim_diag_event_report(a1, 66, a3, 0);
                                                      v275 = lim_diag_mgmt_tx_event_report(a1, v309, a3, 0, 0);
                                                      LOBYTE(v257) = *(_BYTE *)(a1 + 12208);
                                                      context = _cds_get_context(
                                                                  54,
                                                                  (__int64)"lim_send_assoc_req_mgmt_frame",
                                                                  v275,
                                                                  v276,
                                                                  v277,
                                                                  v278,
                                                                  v279,
                                                                  v280,
                                                                  v281,
                                                                  v282);
                                                      LOBYTE(v299) = v311;
                                                      LOWORD(v301) = 0;
                                                      LOBYTE(v297) = v305;
                                                      LOBYTE(v300) = 0;
                                                      v284 = wma_tx_packet(
                                                               context,
                                                               *(_QWORD *)&n[2],
                                                               (unsigned int)(unsigned __int16)v329 + 24,
                                                               3,
                                                               1,
                                                               7,
                                                               lim_tx_complete,
                                                               v331,
                                                               lim_assoc_tx_complete_cnf,
                                                               v297,
                                                               v299,
                                                               v300,
                                                               v301,
                                                               v274,
                                                               (_BYTE)v257,
                                                               0);
                                                      qdf_trace(53, 5u, *(_WORD *)(a3 + 8), v284);
                                                      if ( v284 )
                                                      {
                                                        qdf_trace_msg(
                                                          0x35u,
                                                          2u,
                                                          "%s: Failed to send Association Request (%X)!",
                                                          v285,
                                                          v286,
                                                          v287,
                                                          v288,
                                                          v289,
                                                          v290,
                                                          v291,
                                                          v292,
                                                          "lim_send_assoc_req_mgmt_frame",
                                                          v284);
                                                        *((_DWORD *)v322 + 364) = 3;
                                                        lim_diag_event_report(a1, 79, a3, 2);
                                                      }
                                                    }
                                                    v128 = (__int64)v317;
                                                    v113 = (__int64)v314;
                                                    v94 = (__int64)v303;
                                                    goto LABEL_212;
                                                  }
                                                  qdf_trace_msg(
                                                    0x35u,
                                                    2u,
                                                    "%s: Assoc request pack failure (0x%08x)",
                                                    v222,
                                                    v223,
                                                    v224,
                                                    v225,
                                                    v226,
                                                    v227,
                                                    v228,
                                                    v229,
                                                    "lim_send_assoc_req_mgmt_frame",
                                                    v221);
                                                  cds_packet_free(*(__int64 *)&n[2]);
                                                }
                                                v94 = (__int64)v175;
                                                v128 = (__int64)v317;
                                                v113 = (__int64)v314;
LABEL_212:
                                                _qdf_mem_free(v94);
                                                _qdf_mem_free((__int64)v321);
                                                _qdf_mem_free(v104);
                                                _qdf_mem_free(v128);
                                                _qdf_mem_free((__int64)v323);
                                                _qdf_mem_free(v320);
                                                _qdf_mem_free(v113);
                                                _qdf_mem_free(a2);
                                                _qdf_mem_free((__int64)v17);
                                                v19 = (__int64)v21;
                                                goto LABEL_213;
                                              }
                                              qdf_trace_msg(
                                                0x35u,
                                                2u,
                                                "%s: malloc failed for eht_cap_ie",
                                                v167,
                                                v168,
                                                v169,
                                                v170,
                                                v171,
                                                v172,
                                                v173,
                                                v174,
                                                "lim_send_assoc_req_mgmt_frame");
LABEL_209:
                                              v128 = (__int64)v317;
                                              v113 = (__int64)v314;
                                              v94 = 0;
                                              goto LABEL_212;
                                            }
                                            v190 = v157;
                                            v191 = "%s: unpack failed, ret: 0x%x";
LABEL_190:
                                            qdf_trace_msg(
                                              0x35u,
                                              2u,
                                              v191,
                                              v158,
                                              v159,
                                              v160,
                                              v161,
                                              v162,
                                              v163,
                                              v164,
                                              v165,
                                              "lim_send_assoc_req_mgmt_frame",
                                              v190);
                                            goto LABEL_209;
                                          }
                                          v152 = "%s: Failed to fill adaptive 11r IE";
LABEL_195:
                                          qdf_trace_msg(
                                            0x35u,
                                            2u,
                                            v152,
                                            v144,
                                            v145,
                                            v146,
                                            v147,
                                            v148,
                                            v149,
                                            v150,
                                            v151,
                                            "lim_send_assoc_req_mgmt_frame");
                                          v128 = (__int64)v317;
                                          v113 = 0;
                                          v94 = 0;
                                          goto LABEL_212;
                                        }
LABEL_169:
                                        v312 = 0;
                                        v317 = nullptr;
                                        goto LABEL_170;
                                      }
LABEL_168:
                                      v141 = v323;
                                      goto LABEL_169;
                                    }
                                    if ( (lim_get_vdev_rmf_capable(a1, a3) & 1) != 0 )
                                    {
                                      v307 = 0;
                                      goto LABEL_158;
                                    }
                                    qdf_trace_msg(
                                      0x35u,
                                      8u,
                                      "%s: Peer doesn't support PMF, Don't add MBO IE",
                                      v241,
                                      v242,
                                      v243,
                                      v244,
                                      v245,
                                      v246,
                                      v247,
                                      v248,
                                      "lim_send_assoc_req_mgmt_frame");
                                    _qdf_mem_free((__int64)v323);
LABEL_157:
                                    v129 = 0;
                                    v307 = 0;
                                    v323 = nullptr;
                                    goto LABEL_158;
                                  }
                                  v113 = 0;
LABEL_147:
                                  v323 = nullptr;
                                  v128 = 0;
                                  goto LABEL_212;
                                }
                                v94 = _qdf_mem_malloc(0x101u, "lim_send_assoc_req_mgmt_frame", 3609);
                                if ( v94 )
                                {
                                  v119 = v94;
                                  v320 = v94;
                                  if ( (unsigned int)lim_strip_ie(a1, v17, n, 255, 1, "X", 1, v94, 255) )
                                  {
                                    qdf_trace_msg(
                                      0x35u,
                                      2u,
                                      "%s: Failed to strip MSCS ext IE",
                                      v120,
                                      v121,
                                      v122,
                                      v123,
                                      v124,
                                      v125,
                                      v126,
                                      v127,
                                      "lim_send_assoc_req_mgmt_frame");
                                    v113 = 0;
                                    goto LABEL_143;
                                  }
                                  v21[1845] = 1;
                                  v130 = *(unsigned __int8 *)(v119 + 1);
                                  v21[1846] = v130;
                                  qdf_mem_copy(v21 + 1847, (const void *)(v119 + 2), v130);
                                  goto LABEL_150;
                                }
LABEL_146:
                                v113 = 0;
                                v320 = 0;
                                goto LABEL_147;
                              }
LABEL_137:
                              v318 = v93;
                              v104 = 0;
                              goto LABEL_138;
                            }
                          }
                          else
                          {
                            v93 = 16;
                          }
                        }
                        else
                        {
                          v93 = 0;
                        }
                        v91 = n[0];
                        v92 = 0;
                        v321 = nullptr;
                        goto LABEL_122;
                      }
LABEL_108:
                      wlan_cm_set_assoc_btm_cap(*(_QWORD *)(a3 + 16), 0, v71, v72, v73, v74, v75, v76, v77, v78);
                      goto LABEL_109;
                    }
                    lim_merge_extcap_struct(v21 + 532, &v339, 1);
                    if ( !v21[532] )
                      goto LABEL_108;
                    goto LABEL_103;
                  }
                  v61 = *(_DWORD *)(a3 + 7036);
                  v63 = (_DWORD)v21 + 2100;
                  v65 = a1;
                  v66 = 0;
                  v62 = 0;
                  v64 = 0;
                }
                populate_dot11f_he_caps(v65, v66, v61, v62, v64, v63);
                populate_dot11f_he_6ghz_cap(a1, a3, v21 + 2160);
                goto LABEL_82;
              }
              v21[5244] = 1;
              v51 = *(_BYTE *)(a3 + 8627);
              v21[5248] = 1;
              v21[5245] = v51;
              if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2880LL) & 1) == 0 && (*(_BYTE *)(a3 + 7269) & 0x10) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Disable SU beamformee for vendor IE",
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  "lim_send_assoc_req_mgmt_frame");
                *(_DWORD *)(a3 + 7268) &= ~0x1000u;
              }
              populate_dot11f_vht_caps(a1, a3, v21 + 5248);
            }
            v52 = 1;
            goto LABEL_72;
          }
          v47 = v21 + 472;
          v48 = a1;
          v49 = 0;
        }
        populate_dot11f_ht_caps(v48, v49, v47);
        goto LABEL_54;
      }
    }
    v36 = 0;
    v35 = 0;
    goto LABEL_27;
  }
  _qdf_mem_free(a2);
  v19 = (__int64)v17;
LABEL_213:
  result = _qdf_mem_free(v19);
  _ReadStatusReg(SP_EL0);
  return result;
}
