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
  const char *v16; // x2
  __int64 v17; // x0
  _WORD *v18; // x0
  _WORD *v19; // x21
  _BYTE *v20; // x26
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  int v30; // w27
  _BYTE *v31; // x11
  unsigned int v32; // w9
  int v33; // w24
  int v34; // w25
  char v35; // w8
  char v36; // w8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  char *v45; // x2
  __int64 v46; // x0
  __int64 v47; // x1
  unsigned int v48; // w8
  char v49; // w9
  __int64 v50; // x1
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w2
  int v60; // w3
  int v61; // w5
  int v62; // w4
  int v63; // w0
  int v64; // w1
  unsigned __int8 *v65; // x8
  unsigned __int8 *v66; // x24
  int v67; // w8
  __int64 v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x8
  unsigned int v78; // w9
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned __int8 *v88; // x0
  int v89; // w3
  __int64 v90; // x25
  unsigned __int16 v91; // w27
  int v92; // w19
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x26
  __int64 v102; // x24
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x27
  __int64 v112; // x28
  __int64 v113; // x19
  size_t v114; // x2
  __int64 v115; // x8
  __int64 v116; // x10
  unsigned __int16 v117; // w19
  __int16 v118; // w25
  __int64 v119; // x24
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int16 v128; // w8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  size_t v137; // x2
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  int v146; // w25
  int v147; // w8
  __int64 v148; // x0
  unsigned __int16 v149; // w28
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  unsigned __int16 v158; // w28
  _WORD *v159; // x0
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  unsigned int v168; // w25
  unsigned int v169; // w0
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  unsigned int packed_assoc_request_size; // w0
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  unsigned __int8 v187; // w19
  unsigned int v188; // w27
  int v189; // w28
  double v190; // d0
  double v191; // d1
  double v192; // d2
  double v193; // d3
  double v194; // d4
  double v195; // d5
  double v196; // d6
  double v197; // d7
  int v198; // w3
  __int16 v199; // w2
  char v200; // w8
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  unsigned int v209; // w0
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  unsigned int v218; // w8
  unsigned __int16 v219; // w2
  __int64 v220; // x0
  void *v221; // x0
  bool is_24ghz_ch_freq; // w0
  int v223; // w8
  unsigned int v224; // w9
  int v225; // w8
  char v226; // w9
  char v227; // w25
  char *v228; // x24
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  double v245; // d0
  char v246; // w27
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  _QWORD *context; // x0
  unsigned int v255; // w24
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  __int64 result; // x0
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  __int64 v273; // [xsp+0h] [xbp-150h]
  __int64 v274; // [xsp+0h] [xbp-150h]
  int v275; // [xsp+0h] [xbp-150h]
  int v276; // [xsp+8h] [xbp-148h]
  int v277; // [xsp+8h] [xbp-148h]
  int v278; // [xsp+10h] [xbp-140h]
  int v279; // [xsp+10h] [xbp-140h]
  int v280; // [xsp+18h] [xbp-138h]
  int v281; // [xsp+20h] [xbp-130h]
  int n; // [xsp+48h] [xbp-108h]
  int n_4; // [xsp+4Ch] [xbp-104h]
  __int64 v284; // [xsp+50h] [xbp-100h]
  __int64 v285; // [xsp+58h] [xbp-F8h]
  const void *v286; // [xsp+60h] [xbp-F0h]
  char v287; // [xsp+6Ch] [xbp-E4h]
  unsigned int v288; // [xsp+70h] [xbp-E0h]
  unsigned int v289; // [xsp+74h] [xbp-DCh]
  unsigned __int8 v290; // [xsp+78h] [xbp-D8h]
  unsigned int v291; // [xsp+78h] [xbp-D8h]
  unsigned int v292; // [xsp+7Ch] [xbp-D4h]
  unsigned __int16 v293; // [xsp+80h] [xbp-D0h]
  char *v294; // [xsp+80h] [xbp-D0h]
  const void *v295; // [xsp+88h] [xbp-C8h]
  const void *v296; // [xsp+90h] [xbp-C0h]
  int v297; // [xsp+9Ch] [xbp-B4h]
  unsigned int v298; // [xsp+9Ch] [xbp-B4h]
  _BOOL4 v299; // [xsp+ACh] [xbp-A4h]
  _BYTE *v300; // [xsp+B0h] [xbp-A0h]
  void *v301; // [xsp+B8h] [xbp-98h]
  __int64 v302; // [xsp+C0h] [xbp-90h] BYREF
  __int64 v303; // [xsp+C8h] [xbp-88h]
  __int64 v304; // [xsp+D0h] [xbp-80h]
  __int64 v305; // [xsp+D8h] [xbp-78h]
  unsigned __int16 v306[2]; // [xsp+E4h] [xbp-6Ch] BYREF
  __int64 v307; // [xsp+E8h] [xbp-68h] BYREF
  unsigned int v308; // [xsp+F4h] [xbp-5Ch] BYREF
  __int64 v309; // [xsp+F8h] [xbp-58h] BYREF
  char *v310; // [xsp+100h] [xbp-50h] BYREF
  _DWORD v311[2]; // [xsp+108h] [xbp-48h] BYREF
  _QWORD v312[2]; // [xsp+110h] [xbp-40h] BYREF
  char v313; // [xsp+120h] [xbp-30h]
  __int128 v314; // [xsp+128h] [xbp-28h] BYREF
  char v315; // [xsp+138h] [xbp-18h]
  __int64 v316; // [xsp+140h] [xbp-10h]

  v316 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v309 = 0;
  v310 = nullptr;
  *(_DWORD *)((char *)v311 + 3) = 2923119;
  v308 = 0;
  v307 = 0;
  v306[0] = 0;
  v315 = 0;
  v314 = 0u;
  v313 = 0;
  v312[0] = 0;
  v312[1] = 0;
  v304 = 0;
  v305 = 0;
  v302 = 0;
  v303 = 0;
  v311[0] = 1867515357;
  if ( !a3 )
  {
    v16 = "%s: pe_session is NULL";
LABEL_8:
    qdf_trace_msg(0x35u, 2u, v16, a4, a5, a6, a7, a8, a9, a10, a11, "lim_send_assoc_req_mgmt_frame");
    v17 = a2;
    goto LABEL_204;
  }
  v12 = *(_QWORD *)(a3 + 112);
  if ( !v12 )
  {
    v16 = "%s: pe_session->lim_join_req is NULL";
    goto LABEL_8;
  }
  v15 = *(unsigned __int8 *)(a3 + 10);
  v306[0] = *(_WORD *)(v12 + 2312);
  if ( v306[0] )
  {
    v301 = (void *)_qdf_mem_malloc(v306[0], "lim_send_assoc_req_mgmt_frame", 3214);
    if ( !v301 )
    {
      v17 = a2;
      goto LABEL_204;
    }
    qdf_mem_copy(v301, (const void *)(*(_QWORD *)(a3 + 112) + 2314LL), v306[0]);
  }
  else
  {
    v301 = nullptr;
  }
  v18 = (_WORD *)_qdf_mem_malloc(0x16CCu, "lim_send_assoc_req_mgmt_frame", 3229);
  if ( v18 )
  {
    v19 = v18;
    v20 = (_BYTE *)(a3 + 7024);
    qdf_mem_set(v18, 0x16CCu, 0);
    if ( v306[0] && *(_BYTE *)(a3 + 8654) == 1 )
    {
      qdf_mem_set(&v314, 0x11u, 0);
      if ( (unsigned int)lim_strip_extcap_update_struct(a1, v301, v306, &v314) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Unable to Stripoff ExtCap IE from Assoc Req",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "lim_send_assoc_req_mgmt_frame");
        v299 = 0;
      }
      else
      {
        if ( (*(_DWORD *)((_BYTE *)&v314 + 2) & 0x80000000) != 0 )
          *(_QWORD *)((char *)&v314 + 2) |= 0x100000000uLL;
        BYTE1(v314) = lim_compute_ext_cap_ie_length(&v314);
        v299 = BYTE1(v314) != 0;
      }
    }
    else
    {
      v299 = 0;
    }
    if ( *(_DWORD *)(a3 + 424) == 5 )
      v29 = *(_WORD *)(a2 + 6) & 0xFFEF;
    else
      v29 = *(unsigned __int16 *)(a2 + 6);
    swap_bit_field16(v29, v19);
    v19[1] = *(_WORD *)(a2 + 8);
    populate_dot11f_ssid2(a3, v19 + 2);
    populate_dot11f_supp_rates(a1, 255, v19 + 19, a3);
    if ( (*v20 & 1) != 0 )
    {
      v30 = (*(unsigned __int16 *)(a3 + 176) >> 9) & 1;
      v31 = (_BYTE *)(a1 + 20136);
      if ( (*v20 & 2) != 0 )
        goto LABEL_21;
    }
    else
    {
      v30 = 0;
      v31 = (_BYTE *)(a1 + 20136);
      if ( (*v20 & 2) != 0 )
      {
LABEL_21:
        v32 = *(unsigned __int8 *)(a3 + 178);
        v33 = 0;
        v34 = (v32 >> 1) & 1 & ~v30;
        if ( (*v20 & 4) != 0 && v34 )
        {
          v33 = (v32 >> 2) & 1;
          v34 = 1;
        }
LABEL_27:
        v300 = v31;
        if ( *(_DWORD *)(a3 + 7028) && *(_BYTE *)(a3 + 7192) == 1 )
        {
          populate_dot11f_power_caps(a1, v19 + 33, 0, a3);
          populate_dot11f_supp_channels(a1, (char *)v19 + 69, 0, a3);
          v35 = 0;
          if ( !*v300 )
            goto LABEL_36;
        }
        else
        {
          v35 = 1;
          if ( !*v31 )
            goto LABEL_36;
        }
        v36 = v35 ^ 1;
        if ( (*(_WORD *)(a3 + 176) & 0x1000) == 0 )
          v36 = 1;
        if ( (v36 & 1) == 0 )
          populate_dot11f_power_caps(a1, v19 + 33, 0, a3);
LABEL_36:
        if ( v30 )
          populate_dot11f_qos_caps_station(a1, a3, v19 + 211);
        populate_dot11f_ext_supp_rates(a1, 255, v19 + 26, a3);
        if ( *v300 && (*(_WORD *)(a3 + 176) & 0x1000) != 0 )
          populate_dot11f_rrm_ie(a1, v19 + 212, a3);
        if ( !v301 || !v306[0] || !wlan_get_vendor_ie_ptr_from_oui(&unk_A0A0D0, 4u, (unsigned __int8 *)v301, v306[0]) )
        {
          populate_dot11f_rsn_opaque(a1, *(_QWORD *)(a3 + 112), (char *)v19 + 167);
          populate_dot11f_wpa_opaque(a1, *(_QWORD *)(a3 + 112), v19 + 1988);
          populate_dot11f_wapi_opaque(a1, *(_QWORD *)(a3 + 112), v19 + 1082);
        }
        if ( v34 )
        {
          populate_dot11f_wmm_info_station_per_session(a1, a3, v19 + 2115);
          if ( v33 )
            populate_dot11f_wmm_caps((char *)v19 + 4227);
        }
        if ( *(_BYTE *)(a3 + 155) && *(_BYTE *)(a1 + 12209) )
        {
          v45 = (char *)(v19 + 236);
          v46 = a1;
          v47 = a3;
        }
        else
        {
          if ( *(_BYTE *)(a3 + 9968) != 1 )
          {
LABEL_54:
            if ( *(_BYTE *)(a3 + 7170) && *(_BYTE *)(a3 + 7173) )
            {
              populate_dot11f_vht_caps(a1, a3, v19 + 276);
              if ( *(_BYTE *)(a3 + 7171) )
              {
                if ( !*(_DWORD *)(a3 + 7180) )
                {
                  if ( *((_BYTE *)v19 + 552) )
                  {
                    v48 = *(unsigned __int8 *)(a3 + 154);
                    if ( v48 >= 0xE || ((0x3C01u >> v48) & 1) == 0 )
                      populate_dot11f_operating_mode(a1, v19 + 284, a3);
                  }
                }
              }
            }
            else
            {
              if ( *(_BYTE *)(a3 + 9968) == 1 )
                populate_dot11f_vht_caps(a1, 0, v19 + 276);
              if ( *(_BYTE *)(a3 + 8626) != 1 )
              {
                v50 = 0;
LABEL_72:
                if ( *(_BYTE *)(a3 + 8654) == 1 )
                  populate_dot11f_ext_cap(a1, v50, v19 + 266, a3);
                populate_dot11f_qcn_ie(a1, a3, v19 + 2638, 255);
                populate_dot11f_bss_max_idle(a1, a3, v19 + 682);
                if ( (unsigned int)*(unsigned __int8 *)(a3 + 154) - 10 < 4 || !*(_BYTE *)(a3 + 154) )
                  lim_update_session_he_capable(a1, a3);
                if ( *(_BYTE *)(a3 + 8676) == 1 )
                {
                  v59 = *(_DWORD *)(a3 + 7036);
                  v60 = *(_DWORD *)(a3 + 284);
                  v61 = (_DWORD)v19 + 2100;
                  v62 = *(_DWORD *)(a3 + 7176);
                  v63 = a1;
                  v64 = a3;
                }
                else
                {
                  if ( *(_BYTE *)(a3 + 9968) != 1 )
                  {
LABEL_82:
                    if ( (unsigned int)*(unsigned __int8 *)(a3 + 154) - 10 < 4 || !*(_BYTE *)(a3 + 154) )
                      populate_dot11f_reg_connectivity(a1, v19 + 1987);
                    if ( *(_BYTE *)(a3 + 7041) == 1 )
                    {
                      v65 = *(unsigned __int8 **)(a3 + 112);
                      v66 = v65 + 4096;
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: mdie = %02x %02x %02x",
                        v51,
                        v52,
                        v53,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        "lim_send_assoc_req_mgmt_frame",
                        v65[4409],
                        v65[4410],
                        v65[4411]);
                      populate_mdie(a1, v19 + 215, *(_QWORD *)(a3 + 112) + 4409LL);
                      v67 = v66[312];
                      if ( v66[312] )
                      {
                        LOBYTE(v303) = 1;
                        v67 = *(unsigned __int16 *)(v66 + 313);
                      }
                      else
                      {
                        LOBYTE(v303) = 0;
                      }
                      v68 = *(_QWORD *)(a1 + 21552);
                      LODWORD(v302) = v67;
                      wlan_cm_roam_cfg_set_value(v68, v15, 0x14u, (unsigned int *)&v302);
                      if ( **(_BYTE **)(a3 + 9976) == 1 )
                        populate_fils_ft_info(a1, v19 + 685, a3);
                    }
                    if ( *(_BYTE *)(a3 + 8624) && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1562LL) == 1 )
                      populate_dot11f_ese_version((char *)v19 + 4487);
                    if ( (wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21560), *(_BYTE *)(a3 + 10)) & 1) != 0 )
                    {
                      populate_dot11f_ese_rad_mgmt_cap(v19 + 2242);
                      if ( !v299 )
                        goto LABEL_96;
                    }
                    else if ( !v299 )
                    {
LABEL_96:
                      if ( !*((_BYTE *)v19 + 532) )
                        goto LABEL_105;
LABEL_100:
                      if ( *(_BYTE *)(a3 + 8654) == 1 )
                      {
                        qdf_mem_set(v312, 0x11u, 0);
                        v77 = *(_QWORD *)(a3 + 320);
                        if ( v77 )
                        {
                          v78 = *(_DWORD *)(a3 + 312);
                          if ( v78 >= 0x25 )
                          {
                            ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(
                                                0x7Fu,
                                                (unsigned __int8 *)(v77 + 36),
                                                (unsigned __int16)v78 - 36);
                            lim_update_extcap_struct(a1, ie_ptr_from_eid, v312);
                            lim_merge_extcap_struct(v19 + 266, v312, 0);
                          }
                        }
                        populate_dot11f_btm_extended_caps(a1, a3, v19 + 266);
                        populate_dot11f_twt_extended_caps(a1, a3, v19 + 266);
LABEL_106:
                        if ( (unsigned int)lim_strip_supp_op_class_update_struct(a1, v301, v306, v19 + 218) )
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Unable to Stripoff supp op classes IE from Assoc Req",
                            v80,
                            v81,
                            v82,
                            v83,
                            v84,
                            v85,
                            v86,
                            v87,
                            "lim_send_assoc_req_mgmt_frame");
                        if ( **(_BYTE **)(a3 + 9976) == 1 )
                        {
                          populate_dot11f_fils_params(a1, v19, a3);
                          if ( v306[0] )
                          {
                            v88 = wlan_get_ie_ptr_from_eid(0xF2u, (unsigned __int8 *)v301, v306[0]);
                            v89 = v306[0];
                            v90 = 0;
                            v91 = 0;
                            v92 = 16;
                            if ( !v88 || !v306[0] )
                            {
LABEL_120:
                              if ( !v89 )
                                goto LABEL_134;
                              goto LABEL_121;
                            }
                            if ( wlan_get_ext_ie_ptr_from_ext_id(&unk_89A9F4, 1u, (unsigned __int8 *)v301, v306[0]) )
                            {
                              v90 = _qdf_mem_malloc(0x800u, "lim_send_assoc_req_mgmt_frame", 3554);
                              if ( !v90 )
                              {
LABEL_116:
                                v101 = 0;
                                v102 = 0;
LABEL_126:
                                v113 = 0;
LABEL_141:
                                v111 = 0;
                                v112 = 0;
                                goto LABEL_203;
                              }
                              if ( (unsigned int)lim_strip_ie(a1, v301, v306, 255, 1, &unk_89A9F4, 1, v90, 2046) )
                              {
                                qdf_trace_msg(
                                  0x35u,
                                  2u,
                                  "%s: Failed to strip FILS HLP container IE",
                                  v93,
                                  v94,
                                  v95,
                                  v96,
                                  v97,
                                  v98,
                                  v99,
                                  v100,
                                  "lim_send_assoc_req_mgmt_frame");
                                goto LABEL_116;
                              }
                              v115 = *(unsigned __int8 *)(v90 + 1);
                              v116 = v90;
                              v117 = v306[0];
                              v118 = v115 + 2;
                              v119 = v116;
                              if ( (unsigned int)lim_strip_ie(
                                                   a1,
                                                   v301,
                                                   v306,
                                                   242,
                                                   1,
                                                   0,
                                                   0,
                                                   v116 + v115 + 2,
                                                   2044 - (int)v115) )
                              {
                                qdf_trace_msg(
                                  0x35u,
                                  2u,
                                  "%s: Failed to strip fragment IE of HLP container IE",
                                  v120,
                                  v121,
                                  v122,
                                  v123,
                                  v124,
                                  v125,
                                  v126,
                                  v127,
                                  "lim_send_assoc_req_mgmt_frame");
                                v101 = 0;
                                v113 = 0;
                                v111 = 0;
                                v112 = 0;
                                v90 = v119;
                                v102 = 0;
                                goto LABEL_203;
                              }
                              LOWORD(v89) = v306[0];
                              v128 = v118 + v117;
                              v90 = v119;
                              v92 = 16;
                              v91 = v128 - v306[0];
                              if ( !v306[0] )
                                goto LABEL_134;
LABEL_121:
                              if ( wlan_get_ie_ptr_from_eid(0xF4u, (unsigned __int8 *)v301, v89) )
                              {
                                v102 = _qdf_mem_malloc(0x101u, "lim_send_assoc_req_mgmt_frame", 3586);
                                if ( !v102 )
                                {
                                  v101 = 0;
                                  goto LABEL_126;
                                }
                                v297 = v92;
                                if ( (unsigned int)lim_strip_ie(a1, v301, v306, 244, 1, 0, 0, v102, 255) )
                                {
                                  qdf_trace_msg(
                                    0x35u,
                                    2u,
                                    "%s: Failed to strip Vendor IEs",
                                    v103,
                                    v104,
                                    v105,
                                    v106,
                                    v107,
                                    v108,
                                    v109,
                                    v110,
                                    "lim_send_assoc_req_mgmt_frame");
                                  v101 = 0;
                                  v111 = 0;
                                  v112 = 0;
                                  v113 = 0;
LABEL_203:
                                  _qdf_mem_free(0);
                                  _qdf_mem_free(v90);
                                  _qdf_mem_free(v102);
                                  _qdf_mem_free(v112);
                                  _qdf_mem_free(v111);
                                  _qdf_mem_free(v113);
                                  _qdf_mem_free(v101);
                                  _qdf_mem_free(a2);
                                  _qdf_mem_free((__int64)v301);
                                  v17 = (__int64)v19;
                                  goto LABEL_204;
                                }
                                *((_BYTE *)v19 + 1590) = 1;
                                v114 = *(unsigned __int8 *)(v102 + 1);
                                *((_BYTE *)v19 + 1591) = v114;
                                qdf_mem_copy(v19 + 796, (const void *)(v102 + 2), v114);
LABEL_135:
                                if ( v306[0] )
                                {
                                  if ( wlan_get_ext_ie_ptr_from_ext_id("X", 1u, (unsigned __int8 *)v301, v306[0]) )
                                  {
                                    v113 = _qdf_mem_malloc(0x101u, "lim_send_assoc_req_mgmt_frame", 3609);
                                    if ( !v113 )
                                    {
LABEL_140:
                                      v101 = 0;
                                      goto LABEL_141;
                                    }
                                    if ( (unsigned int)lim_strip_ie(a1, v301, v306, 255, 1, "X", 1, v113, 255) )
                                    {
                                      qdf_trace_msg(
                                        0x35u,
                                        2u,
                                        "%s: Failed to strip MSCS ext IE",
                                        v129,
                                        v130,
                                        v131,
                                        v132,
                                        v133,
                                        v134,
                                        v135,
                                        v136,
                                        "lim_send_assoc_req_mgmt_frame");
                                      goto LABEL_140;
                                    }
                                    *((_BYTE *)v19 + 1845) = 1;
                                    v137 = *(unsigned __int8 *)(v113 + 1);
                                    *((_BYTE *)v19 + 1846) = v137;
                                    qdf_mem_copy((char *)v19 + 1847, (const void *)(v113 + 2), v137);
                                  }
                                  else
                                  {
                                    v113 = 0;
                                  }
                                  v293 = v91;
                                  if ( v306[0] )
                                  {
                                    if ( wlan_get_vendor_ie_ptr_from_oui(
                                           &unk_90BDBA,
                                           4u,
                                           (unsigned __int8 *)v301,
                                           v306[0]) )
                                    {
                                      v111 = _qdf_mem_malloc(0x127u, "lim_send_assoc_req_mgmt_frame", 3640);
                                      if ( !v111 )
                                      {
LABEL_150:
                                        v101 = 0;
                                        v112 = 0;
                                        goto LABEL_203;
                                      }
                                      if ( (unsigned int)lim_strip_ie(a1, v301, v306, 221, 1, &unk_90BDBA, 4, v111, 293) )
                                      {
                                        qdf_trace_msg(
                                          0x35u,
                                          2u,
                                          "%s: Failed to strip MBO IE",
                                          v138,
                                          v139,
                                          v140,
                                          v141,
                                          v142,
                                          v143,
                                          v144,
                                          v145,
                                          "lim_send_assoc_req_mgmt_frame");
                                        goto LABEL_150;
                                      }
                                      v290 = *(_BYTE *)(v111 + 1) + 2;
                                      if ( !*(_DWORD *)(a3 + 156) )
                                      {
                                        v288 = 1;
                                        goto LABEL_211;
                                      }
                                      if ( (lim_get_vdev_rmf_capable(a1, a3) & 1) != 0 )
                                      {
                                        v288 = 0;
                                        goto LABEL_211;
                                      }
                                      qdf_trace_msg(
                                        0x35u,
                                        8u,
                                        "%s: Peer doesn't support PMF, Don't add MBO IE",
                                        v265,
                                        v266,
                                        v267,
                                        v268,
                                        v269,
                                        v270,
                                        v271,
                                        v272,
                                        "lim_send_assoc_req_mgmt_frame");
                                      _qdf_mem_free(v111);
                                    }
                                    v111 = 0;
                                    v288 = 0;
                                    v290 = 0;
LABEL_211:
                                    v296 = (const void *)v90;
                                    if ( v306[0] )
                                      lim_strip_ie(a1, v301, v306, 221, 1, &unk_940622, 4, 0, 0);
LABEL_153:
                                    v146 = *(unsigned __int8 *)(a3 + 10076);
                                    if ( *(_BYTE *)(a3 + 10076) )
                                    {
                                      BYTE2(v311[1]) = v146 - 1;
                                      v147 = 7;
                                    }
                                    else
                                    {
                                      v147 = 0;
                                    }
                                    v292 = v147;
                                    v287 = v15;
                                    if ( v306[0]
                                      && wlan_get_ie_ptr_from_eid(0xDDu, (unsigned __int8 *)v301, v306[0])
                                      && (v148 = _qdf_mem_malloc(0x5FEu, "lim_send_assoc_req_mgmt_frame", 3695)) != 0 )
                                    {
                                      v149 = v306[0];
                                      v295 = (const void *)v148;
                                      if ( (unsigned int)lim_strip_ie(a1, v301, v306, 221, 1, 0, 0, v148, 1532) )
                                      {
                                        qdf_trace_msg(
                                          0x35u,
                                          2u,
                                          "%s: Failed to strip Vendor IEs",
                                          v150,
                                          v151,
                                          v152,
                                          v153,
                                          v154,
                                          v155,
                                          v156,
                                          v157,
                                          "lim_send_assoc_req_mgmt_frame");
                                        v90 = (__int64)v296;
                                        v101 = 0;
                                        goto LABEL_202;
                                      }
                                      v158 = v149 - v306[0];
                                    }
                                    else
                                    {
                                      v158 = 0;
                                      v295 = nullptr;
                                    }
                                    if ( *(_BYTE *)(a3 + 7042) == 1 )
                                    {
                                      v159 = (_WORD *)_qdf_mem_malloc(0xDu, "lim_fill_adaptive_11r_ie", 3086);
                                      v101 = (__int64)v159;
                                      if ( !v159 )
                                      {
                                        qdf_trace_msg(
                                          0x35u,
                                          2u,
                                          "%s: Failed to fill adaptive 11r IE",
                                          v160,
                                          v161,
                                          v162,
                                          v163,
                                          v164,
                                          v165,
                                          v166,
                                          v167,
                                          "lim_send_assoc_req_mgmt_frame");
                                        v90 = (__int64)v296;
                                        goto LABEL_202;
                                      }
                                      n_4 = v146;
                                      *v159 = 3037;
                                      qdf_mem_copy(v159 + 1, &unk_A0A0DB, 4u);
                                      *(_WORD *)(v101 + 6) = 256;
                                      *(_BYTE *)(v101 + 8) = 4;
                                      qdf_mem_copy((void *)(v101 + 9), &unk_A0A0E0, 4u);
                                      v168 = 13;
                                    }
                                    else
                                    {
                                      n_4 = v146;
                                      v101 = 0;
                                      v168 = 0;
                                    }
                                    if ( v306[0] )
                                    {
                                      v169 = dot11f_unpack_assoc_request(a1, v301);
                                      if ( (v169 & 0x10000000) != 0 )
                                      {
                                        qdf_trace_msg(
                                          0x35u,
                                          2u,
                                          "%s: unpack failed, ret: 0x%x",
                                          v170,
                                          v171,
                                          v172,
                                          v173,
                                          v174,
                                          v175,
                                          v176,
                                          v177,
                                          "lim_send_assoc_req_mgmt_frame",
                                          v169);
                                        v90 = (__int64)v296;
                                        goto LABEL_202;
                                      }
                                    }
                                    packed_assoc_request_size = dot11f_get_packed_assoc_request_size(a1, v19, &v308);
                                    v289 = v168;
                                    v285 = v113;
                                    v286 = (const void *)v111;
                                    v284 = v102;
                                    if ( (packed_assoc_request_size & 0x10000000) != 0 )
                                    {
                                      qdf_trace_msg(
                                        0x35u,
                                        2u,
                                        "%s: Association Request packet size failure(0x%08x)",
                                        v179,
                                        v180,
                                        v181,
                                        v182,
                                        v183,
                                        v184,
                                        v185,
                                        v186,
                                        "lim_send_assoc_req_mgmt_frame",
                                        packed_assoc_request_size);
                                      v187 = v290;
                                      v308 = 5836;
                                    }
                                    else
                                    {
                                      v187 = v290;
                                      if ( packed_assoc_request_size )
                                        qdf_trace_msg(
                                          0x35u,
                                          3u,
                                          "%s: Association request packet size warning (0x%08x)",
                                          v179,
                                          v180,
                                          v181,
                                          v182,
                                          v183,
                                          v184,
                                          v185,
                                          v186,
                                          "lim_send_assoc_req_mgmt_frame");
                                    }
                                    v188 = v158;
                                    v189 = v297 + v293 + v187 + v292 + v158 + v168 + v308;
                                    if ( (unsigned int)cds_packet_alloc(
                                                         (unsigned __int16)v297
                                                       + v293
                                                       + v187
                                                       + (unsigned __int16)v292
                                                       + (unsigned __int16)v188
                                                       + (unsigned __int16)v168
                                                       + (unsigned __int16)v308
                                                       + 24,
                                                         &v310,
                                                         &v307) )
                                    {
                                      qdf_trace_msg(
                                        0x35u,
                                        2u,
                                        "%s: Failed to allocate %d bytes",
                                        v190,
                                        v191,
                                        v192,
                                        v193,
                                        v194,
                                        v195,
                                        v196,
                                        v197,
                                        "lim_send_assoc_req_mgmt_frame",
                                        (unsigned int)(v189 + 24));
                                      v198 = *(_DWORD *)(a3 + 76);
                                      v199 = *(_WORD *)(a3 + 8);
                                      *(_DWORD *)(a3 + 72) = v198;
                                      qdf_trace(53, 0, v199, v198);
                                      v200 = *(_BYTE *)(a3 + 8);
                                      LODWORD(v309) = 502;
                                      BYTE6(v309) = v200;
                                      lim_process_mlm_rsp_messages(
                                        a1,
                                        1010,
                                        (unsigned __int8 *)&v309,
                                        v201,
                                        v202,
                                        v203,
                                        v204,
                                        v205,
                                        v206,
                                        v207,
                                        v208);
                                    }
                                    else
                                    {
                                      n = v293;
                                      v291 = v188;
                                      v298 = v187;
                                      qdf_mem_set(v310, (unsigned int)(v189 + 24), 0);
                                      lim_populate_mac_header(
                                        a1,
                                        (__int64)v310,
                                        0,
                                        0,
                                        (const void *)(a3 + 24),
                                        (_BYTE *)(a3 + 30));
                                      v209 = dot11f_pack_assoc_request(a1, v19, v310 + 24, v308, &v308);
                                      if ( (v209 & 0x10000000) == 0 )
                                      {
                                        v113 = v285;
                                        v111 = (__int64)v286;
                                        v112 = (__int64)v295;
                                        if ( v209 )
                                          qdf_trace_msg(
                                            0x35u,
                                            3u,
                                            "%s: Assoc request pack warning (0x%08x)",
                                            v210,
                                            v211,
                                            v212,
                                            v213,
                                            v214,
                                            v215,
                                            v216,
                                            v217,
                                            "lim_send_assoc_req_mgmt_frame");
                                        v218 = v308;
                                        if ( v296 && v293 )
                                        {
                                          qdf_mem_copy(&v310[v308 + 24], v296, v293);
                                          v218 = v308 + v293;
                                          v308 = v218;
                                        }
                                        if ( n_4 )
                                        {
                                          qdf_mem_copy(&v310[v218 + 24], v311, v292);
                                          v218 = v308 + v292;
                                          v308 += v292;
                                        }
                                        qdf_mem_copy(&v310[v218 + 24], v286, v298);
                                        v308 += v298;
                                        qdf_mem_copy(&v310[v308 + 24], v295, v291);
                                        v308 += v291;
                                        qdf_mem_copy(&v310[v308 + 24], (const void *)v101, v168);
                                        v219 = v308 + v168 - 4;
                                        v308 += v168;
                                        lim_reorder_vendor_ies(a1, (__int64)(v310 + 28), v219);
                                        v220 = *(_QWORD *)(a3 + 336);
                                        v90 = (__int64)v296;
                                        if ( v220 )
                                        {
                                          _qdf_mem_free(v220);
                                          *(_QWORD *)(a3 + 336) = 0;
                                          *(_DWORD *)(a3 + 328) = 0;
                                        }
                                        if ( **(_BYTE **)(a3 + 9976) == 1
                                          && (unsigned int)aead_encrypt_assoc_req(a1, a3, v310, &v308) )
                                        {
                                          cds_packet_free(v307);
                                          goto LABEL_203;
                                        }
                                        v221 = (void *)_qdf_mem_malloc(v308, "lim_send_assoc_req_mgmt_frame", 3895);
                                        *(_QWORD *)(a3 + 336) = v221;
                                        if ( v221 )
                                        {
                                          qdf_mem_copy(v221, v310 + 24, v308);
                                          *(_DWORD *)(a3 + 328) = v308;
                                        }
                                        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284));
                                        v223 = *(_DWORD *)(a3 + 7036);
                                        v224 = v223 & 0xFFFFFFFE;
                                        v225 = v223 | 2;
                                        v226 = (v224 == 2) << 6;
                                        if ( is_24ghz_ch_freq )
                                          v227 = v226;
                                        else
                                          v227 = 64;
                                        if ( v225 == 2 )
                                          v227 |= 0x80u;
                                        v294 = v310;
                                        v228 = v310 + 10;
                                        qdf_trace(53, 2u, *(_WORD *)(a3 + 8), (unsigned __int8)*(_WORD *)v310 >> 4);
                                        LODWORD(v273) = v291;
                                        qdf_trace_msg(
                                          0x35u,
                                          8u,
                                          "%s: Assoc Req IEs: dot11mode %d, extcap %d, open %d, IE len:: mbo %d vendor %d"
                                          ", rsn_sel %d, ft11r %d, mlo %d, eht %d, fils %d",
                                          v229,
                                          v230,
                                          v231,
                                          v232,
                                          v233,
                                          v234,
                                          v235,
                                          v236,
                                          "lim_send_assoc_req_mgmt_frame",
                                          *(unsigned __int8 *)(a3 + 154),
                                          v299,
                                          v288,
                                          v298,
                                          v273,
                                          v292,
                                          v289,
                                          0,
                                          0,
                                          n);
                                        LODWORD(v274) = *((unsigned __int16 *)v300 + 698);
                                        qdf_trace_msg(
                                          0x35u,
                                          4u,
                                          "Assoc req TX: vdev %d to %02x:%02x:%02x:**:**:%02x seq num %d",
                                          v237,
                                          v238,
                                          v239,
                                          v240,
                                          v241,
                                          v242,
                                          v243,
                                          v244,
                                          *(unsigned __int8 *)(a3 + 10),
                                          *(unsigned __int8 *)(a3 + 24),
                                          *(unsigned __int8 *)(a3 + 25),
                                          *(unsigned __int8 *)(a3 + 26),
                                          *(unsigned __int8 *)(a3 + 29),
                                          v274);
                                        LOBYTE(v278) = 0;
                                        LOBYTE(v275) = *((_BYTE *)v19 + 2100) != 0;
                                        LOBYTE(v276) = *((_BYTE *)v19 + 3108) != 0;
                                        lim_cp_stats_cstats_log_assoc_req_evt(
                                          a3,
                                          0,
                                          a3 + 24,
                                          v228,
                                          *((unsigned __int8 *)v19 + 5),
                                          v19 + 3,
                                          *((_BYTE *)v19 + 472) != 0,
                                          *((_BYTE *)v19 + 552) != 0,
                                          v275,
                                          v276,
                                          v278);
                                        LODWORD(v228) = ((__int64 (__fastcall *)(__int64, _QWORD))lim_get_min_session_txrate)(
                                                          a3,
                                                          0);
                                        lim_diag_event_report(a1, 66, a3, 0);
                                        v245 = lim_diag_mgmt_tx_event_report(a1, v294, a3, 0, 0);
                                        v246 = *(_BYTE *)(a1 + 12208);
                                        context = _cds_get_context(
                                                    54,
                                                    (__int64)"lim_send_assoc_req_mgmt_frame",
                                                    v245,
                                                    v247,
                                                    v248,
                                                    v249,
                                                    v250,
                                                    v251,
                                                    v252,
                                                    v253);
                                        LOWORD(v281) = 0;
                                        LOBYTE(v279) = v287;
                                        LOBYTE(v277) = v227;
                                        LOBYTE(v280) = 0;
                                        v255 = wma_tx_packet(
                                                 context,
                                                 v307,
                                                 (unsigned int)(unsigned __int16)v308 + 24,
                                                 3,
                                                 1,
                                                 7,
                                                 lim_tx_complete,
                                                 v310,
                                                 lim_assoc_tx_complete_cnf,
                                                 v277,
                                                 v279,
                                                 v280,
                                                 v281,
                                                 (_DWORD)v228,
                                                 v246,
                                                 0);
                                        qdf_trace(53, 5u, *(_WORD *)(a3 + 8), v255);
                                        if ( v255 )
                                        {
                                          qdf_trace_msg(
                                            0x35u,
                                            2u,
                                            "%s: Failed to send Association Request (%X)!",
                                            v256,
                                            v257,
                                            v258,
                                            v259,
                                            v260,
                                            v261,
                                            v262,
                                            v263,
                                            "lim_send_assoc_req_mgmt_frame",
                                            v255);
                                          *((_DWORD *)v300 + 364) = 3;
                                          lim_diag_event_report(a1, 79, a3, 2);
                                        }
                                        v90 = (__int64)v296;
                                        v102 = v284;
                                        v111 = (__int64)v286;
LABEL_202:
                                        v112 = (__int64)v295;
                                        goto LABEL_203;
                                      }
                                      qdf_trace_msg(
                                        0x35u,
                                        2u,
                                        "%s: Assoc request pack failure (0x%08x)",
                                        v210,
                                        v211,
                                        v212,
                                        v213,
                                        v214,
                                        v215,
                                        v216,
                                        v217,
                                        "lim_send_assoc_req_mgmt_frame",
                                        v209);
                                      cds_packet_free(v307);
                                    }
                                    v112 = (__int64)v295;
                                    v90 = (__int64)v296;
                                    v113 = v285;
                                    v111 = (__int64)v286;
                                    goto LABEL_203;
                                  }
                                  v296 = (const void *)v90;
                                  v111 = 0;
                                }
                                else
                                {
                                  v293 = v91;
                                  v111 = 0;
                                  v113 = 0;
                                  v296 = (const void *)v90;
                                }
                                v290 = 0;
                                v288 = 0;
                                goto LABEL_153;
                              }
LABEL_134:
                              v297 = v92;
                              v102 = 0;
                              goto LABEL_135;
                            }
                          }
                          else
                          {
                            v92 = 16;
                          }
                        }
                        else
                        {
                          v92 = 0;
                        }
                        v89 = v306[0];
                        v91 = 0;
                        v90 = 0;
                        goto LABEL_120;
                      }
LABEL_105:
                      wlan_cm_set_assoc_btm_cap(*(_QWORD *)(a3 + 16), 0, v69, v70, v71, v72, v73, v74, v75, v76);
                      goto LABEL_106;
                    }
                    lim_merge_extcap_struct(v19 + 266, &v314, 1);
                    if ( !*((_BYTE *)v19 + 532) )
                      goto LABEL_105;
                    goto LABEL_100;
                  }
                  v59 = *(_DWORD *)(a3 + 7036);
                  v61 = (_DWORD)v19 + 2100;
                  v63 = a1;
                  v64 = 0;
                  v60 = 0;
                  v62 = 0;
                }
                populate_dot11f_he_caps(v63, v64, v59, v60, v62, v61);
                populate_dot11f_he_6ghz_cap(a1, a3, v19 + 1080);
                goto LABEL_82;
              }
              *((_BYTE *)v19 + 5244) = 1;
              v49 = *(_BYTE *)(a3 + 8627);
              *((_BYTE *)v19 + 5248) = 1;
              *((_BYTE *)v19 + 5245) = v49;
              if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2676LL) & 1) == 0 && (*(_BYTE *)(a3 + 7269) & 0x10) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Disable SU beamformee for vendor IE",
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  "lim_send_assoc_req_mgmt_frame");
                *(_DWORD *)(a3 + 7268) &= ~0x1000u;
              }
              populate_dot11f_vht_caps(a1, a3, v19 + 2624);
            }
            v50 = 1;
            goto LABEL_72;
          }
          v45 = (char *)(v19 + 236);
          v46 = a1;
          v47 = 0;
        }
        populate_dot11f_ht_caps(v46, v47, v45);
        goto LABEL_54;
      }
    }
    v34 = 0;
    v33 = 0;
    goto LABEL_27;
  }
  _qdf_mem_free(a2);
  v17 = (__int64)v301;
LABEL_204:
  result = _qdf_mem_free(v17);
  _ReadStatusReg(SP_EL0);
  return result;
}
