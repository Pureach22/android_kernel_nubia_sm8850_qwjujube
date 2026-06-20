__int64 __fastcall sch_set_fixed_beacon_fields(__int64 a1, __int64 a2)
{
  __int64 v4; // x24
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x0
  _BYTE *v10; // x28
  __int16 v11; // w8
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x24
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w9
  int v33; // w8
  int v34; // w8
  int v35; // w26
  _BYTE *v36; // x24
  unsigned __int16 tpe_ie_length; // w21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  int v47; // w8
  unsigned __int8 *v48; // x26
  unsigned int v49; // w22
  __int64 v50; // x0
  int v51; // w0
  _BOOL4 v52; // w26
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  unsigned int v173; // w27
  __int64 is_6ghz_chan_freq; // x0
  unsigned __int8 *v175; // x0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  unsigned int v192; // w0
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  __int64 v201; // x0
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  _BYTE *v210; // x28
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  const char *v219; // x2
  const char *v220; // x2
  __int64 v221; // x11
  __int64 v222; // x13
  __int64 v223; // x8
  __int64 v224; // x1
  __int64 v225; // x11
  __int64 v226; // x12
  __int16 v227; // w14
  __int64 v228; // x2
  __int16 v229; // w10
  __int64 v230; // x10
  __int64 v231; // x11
  __int64 v232; // x9
  __int64 v233; // x12
  int v234; // w21
  __int64 v235; // x0
  bool is_24ghz_ch_freq; // w0
  __int64 v237; // x9
  __int64 v238; // x10
  int v239; // w8
  __int64 v240; // x9
  __int64 v241; // x10
  __int64 v242; // x8
  __int64 v243; // x8
  __int64 v244; // x9
  __int64 v245; // x8
  __int64 v246; // x10
  __int64 v247; // x8
  __int64 v248; // x8
  __int64 v249; // x10
  __int64 v250; // x8
  __int64 v251; // x8
  int v252; // w21
  unsigned int v253; // w8
  __int64 v254; // x0
  __int64 v255; // x24
  __int64 v256; // x27
  int v257; // w21
  unsigned __int16 v258; // w28
  unsigned int v259; // w9
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  __int16 v268; // w8
  double v269; // d0
  double v270; // d1
  double v271; // d2
  double v272; // d3
  double v273; // d4
  double v274; // d5
  double v275; // d6
  double v276; // d7
  double v277; // d0
  double v278; // d1
  double v279; // d2
  double v280; // d3
  double v281; // d4
  double v282; // d5
  double v283; // d6
  double v284; // d7
  int v285; // w8
  __int64 v286; // [xsp+0h] [xbp-140h]
  __int64 v287; // [xsp+0h] [xbp-140h]
  __int64 v288; // [xsp+8h] [xbp-138h]
  __int64 v289; // [xsp+10h] [xbp-130h]
  __int64 v290; // [xsp+18h] [xbp-128h]
  _BYTE *v291; // [xsp+40h] [xbp-100h]
  unsigned __int16 v292; // [xsp+48h] [xbp-F8h]
  _BYTE *v293; // [xsp+50h] [xbp-F0h]
  unsigned __int16 v294[2]; // [xsp+58h] [xbp-E8h] BYREF
  _WORD v295[2]; // [xsp+5Ch] [xbp-E4h] BYREF
  unsigned __int16 n[2]; // [xsp+60h] [xbp-E0h] BYREF
  int n_4; // [xsp+64h] [xbp-DCh] BYREF
  int v298; // [xsp+68h] [xbp-D8h] BYREF
  __int16 v299; // [xsp+6Ch] [xbp-D4h] BYREF
  unsigned int v300; // [xsp+70h] [xbp-D0h] BYREF
  __int16 v301; // [xsp+74h] [xbp-CCh] BYREF
  char v302; // [xsp+76h] [xbp-CAh]
  __int64 v303; // [xsp+78h] [xbp-C8h] BYREF
  __int64 v304; // [xsp+80h] [xbp-C0h]
  __int64 v305; // [xsp+88h] [xbp-B8h]
  __int64 v306; // [xsp+90h] [xbp-B0h]
  __int64 v307; // [xsp+98h] [xbp-A8h]
  __int64 v308; // [xsp+A0h] [xbp-A0h]
  __int64 v309; // [xsp+A8h] [xbp-98h]
  int v310; // [xsp+B0h] [xbp-90h]
  __int64 v311; // [xsp+B8h] [xbp-88h] BYREF
  __int64 v312; // [xsp+C0h] [xbp-80h]
  __int64 v313; // [xsp+C8h] [xbp-78h]
  __int64 v314; // [xsp+D0h] [xbp-70h]
  __int64 v315; // [xsp+D8h] [xbp-68h]
  __int64 v316; // [xsp+E0h] [xbp-60h]
  __int64 v317; // [xsp+E8h] [xbp-58h]
  __int64 v318; // [xsp+F0h] [xbp-50h]
  __int64 v319; // [xsp+F8h] [xbp-48h]
  __int64 v320; // [xsp+100h] [xbp-40h]
  __int64 v321; // [xsp+108h] [xbp-38h]
  int v322; // [xsp+110h] [xbp-30h]
  _QWORD v323[2]; // [xsp+118h] [xbp-28h] BYREF
  char v324; // [xsp+128h] [xbp-18h]
  __int64 v325; // [xsp+130h] [xbp-10h]

  v325 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 7344);
  v300 = 0;
  v299 = 0;
  n_4 = 0;
  v298 = 0;
  n[0] = 0;
  v324 = 0;
  v323[0] = 0;
  v323[1] = 0;
  v295[0] = 0;
  v302 = 0;
  v301 = 0;
  v294[0] = 0;
  v5 = _qdf_mem_malloc(0x40u, "sch_set_fixed_beacon_fields", 698);
  if ( !v5 )
  {
    result = 2;
    goto LABEL_195;
  }
  v6 = v5;
  v7 = _qdf_mem_malloc(0xC2Cu, "sch_set_fixed_beacon_fields", 702);
  if ( !v7 )
  {
    v13 = v6;
LABEL_11:
    _qdf_mem_free(v13);
    result = 2;
    goto LABEL_195;
  }
  v8 = v7;
  v9 = _qdf_mem_malloc(0x110u, "sch_set_fixed_beacon_fields", 708);
  if ( !v9 )
  {
    _qdf_mem_free(v6);
    v13 = v8;
    goto LABEL_11;
  }
  v10 = (_BYTE *)v9;
  qdf_mem_set((void *)(v4 + 4), 0x18u, 0);
  v11 = *(_WORD *)(v4 + 4);
  *(_DWORD *)(v4 + 8) = -1;
  *(_WORD *)(v4 + 12) = -1;
  *(_WORD *)(v4 + 4) = v11 & 0xFF03 | 0x80;
  qdf_mem_copy((void *)(v4 + 14), (const void *)(a2 + 30), 6u);
  qdf_mem_copy((void *)(v4 + 20), (const void *)(a2 + 24), 6u);
  *(_WORD *)(v4 + 4) &= 0xFCFFu;
  *(_WORD *)(v6 + 8) = *(_WORD *)(a2 + 7158);
  populate_dot11f_capabilities(a1, v6 + 10, a2, 0);
  if ( *(_BYTE *)(a2 + 7020) )
  {
    *(_BYTE *)(v6 + 12) = 1;
    if ( *(_BYTE *)(a2 + 36) && *(_BYTE *)(a2 + 7020) == 2 )
      *(_BYTE *)(v6 + 13) = *(_BYTE *)(a2 + 36);
  }
  else
  {
    populate_dot11f_ssid(a1, a2 + 36, v6 + 12);
  }
  populate_dot11f_supp_rates(a1, 255, v6 + 46, a2);
  populate_dot11f_ds_params(a1, v6 + 60, *(unsigned int *)(a2 + 284));
  v14 = *(_QWORD *)(a2 + 7344);
  if ( *(_DWORD *)(a2 + 88) == 1 )
  {
    qdf_mem_set((void *)(a2 + 1952), 0x20u, 0);
    qdf_mem_set((void *)(a2 + 1988), 0x13A8u, 0);
    if ( (unsigned int)lim_update_probe_rsp_template_ie_bitmap_beacon1(a1, v6, a2) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to build ProbeRsp template",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sch_set_fixed_beacon_fields");
  }
  v23 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, unsigned int *))dot11f_pack_beacon1)(
          a1,
          v6,
          v14 + 28,
          484,
          &v300);
  if ( (v23 & 0x10000000) == 0 )
  {
    if ( v23 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Warnings while packing a tDot11fBeacon1(0x%08x)",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "sch_set_fixed_beacon_fields");
    v32 = *(_DWORD *)(a2 + 88);
    *(_WORD *)(a2 + 7360) = v300 + 28;
    if ( v32 == 1 && (*(_BYTE *)(a2 + 7282) == 1 || *(_BYTE *)(a2 + 7284) == 1) )
    {
      populate_dot_11_f_ext_chann_switch_ann(a1, v8 + 622, a2);
      if ( a2 )
      {
        if ( *(_BYTE *)(a2 + 10071) == 1 )
        {
          populate_dot11f_bw_ind_element(a1, a2, v8 + 1280);
          if ( *(_BYTE *)(v8 + 1280) )
            *(_BYTE *)(v8 + 1056) = 1;
        }
      }
      if ( *(_BYTE *)(a2 + 8675) )
      {
        populate_dot11f_chan_switch_ann(a1, v8 + 250, a2);
        if ( *(_BYTE *)(a2 + 7283) )
          populate_dot11f_chan_switch_wrapper(a1, v8 + 1056, a2);
      }
    }
    populate_dot11_supp_operating_classes(a1, v8 + 627, a2);
    populate_dot11f_country(a1, v8, a2);
    if ( (*(_WORD *)(v6 + 10) & 0x200) != 0 )
      populate_dot11f_edca_param_set(a1, v8 + 536, a2);
    if ( *(_DWORD *)(a2 + 7028) )
    {
      populate_dot11f_power_constraints(a1, v8 + 248);
      populate_dot11f_tpc_report(a1, v8 + 262, a2);
      v33 = *(_DWORD *)(a2 + 88);
      if ( v33 != 4 && v33 != 1 || !*(_BYTE *)(a2 + 7282) )
        goto LABEL_41;
      populate_dot11f_chan_switch_ann(a1, v8 + 250, a2);
    }
    else
    {
      v34 = *(_DWORD *)(a2 + 88);
      if ( v34 != 4 && v34 != 1 )
        goto LABEL_41;
    }
    if ( *(_BYTE *)(a2 + 7283) )
      populate_dot11f_chan_switch_wrapper(a1, v8 + 1056, a2);
LABEL_41:
    if ( *(_BYTE *)(v8 + 622) || *(_BYTE *)(v8 + 250) )
      populate_dot11f_max_chan_switch_time(a1, v8 + 1556, a2);
    if ( *(_BYTE *)(a1 + 17481) == 1 )
      populate_dot11f_rrm_ie(a1, v8 + 609, a2);
    if ( *(_BYTE *)(a2 + 154) != 3 )
      populate_dot11f_erp_info(a1, v8 + 265, a2);
    populate_dot11f_qcn_ie(a1, a2, v8 + 3012, 255);
    if ( *(_BYTE *)(a2 + 155) )
    {
      populate_dot11f_ht_caps(a1, a2, v8 + 664);
      populate_dot11f_ht_info(a1, v8 + 724, a2);
    }
    v35 = *(unsigned __int8 *)(a2 + 7170);
    if ( *(_BYTE *)(a2 + 7170)
      && (populate_dot11f_vht_caps(a1, a2, v8 + 816),
          populate_dot11f_vht_operation(a1, a2, v8 + 832),
          *(_BYTE *)(a2 + 7170))
      || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284)) )
    {
      v36 = (_BYTE *)_qdf_mem_malloc(0xD8u, "sch_set_fixed_beacon_fields", 875);
      if ( !v36 )
      {
        v48 = nullptr;
        v49 = 2;
        goto LABEL_194;
      }
      populate_dot11f_tx_power_env(a1, a2, v36, *(unsigned int *)(a2 + 7176), *(unsigned int *)(a2 + 284), v294, 0);
      tpe_ie_length = lim_get_tpe_ie_length(*(unsigned int *)(a2 + 7176), v36, v294[0]);
    }
    else
    {
      tpe_ie_length = 0;
      v36 = nullptr;
    }
    if ( *(_BYTE *)(a2 + 8676) == 1 )
    {
      populate_dot11f_he_caps(a1, a2, *(_DWORD *)(a2 + 7036), *(_DWORD *)(a2 + 284), *(_DWORD *)(a2 + 7176), v8 + 1660);
      populate_dot11f_he_operation(a1, a2, v8 + 1720);
      populate_dot11f_sr_info(a1, a2, v8 + 1738);
      populate_dot11f_he_6ghz_cap(a1, a2, v8 + 1776);
      populate_dot11f_he_bss_color_change(a1, a2, v8 + 1759);
    }
    else if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284))
           && policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a2 + 10)) )
    {
      populate_dot11f_he_operation(a1, a2, v8 + 1720);
    }
    if ( a2 && *(_BYTE *)(a2 + 10071) == 1 )
    {
      populate_dot11f_eht_caps(a1, a2, v8 + 1904);
      populate_dot11f_eht_operation(a1, a2, v8 + 1996);
    }
    populate_dot11f_ext_cap(a1, v35 != 0, v8 + 798, a2);
    populate_dot11f_ext_supp_rates(a1, 255, v8 + 267, a2);
    v46 = *(_QWORD *)(a2 + 104);
    if ( v46 )
    {
      populate_dot11f_wpa(a1, v46 + 56, v8 + 2782);
      populate_dot11f_rsn_opaque(a1, *(_QWORD *)(a2 + 104) + 56LL, v8 + 281);
      populate_dot11f_wapi(a1, *(_QWORD *)(a2 + 104) + 56LL, v8 + 1782);
    }
    if ( (*(_BYTE *)(a2 + 7024) & 2) != 0 )
      populate_dot11f_wmm(a1, v8 + 2830, v8 + 2834, v8 + 2854, a2);
    if ( *(_DWORD *)(a2 + 88) == 1 )
    {
      if ( *(_BYTE *)(a2 + 7022) )
        populate_dot11f_beacon_wpsi_es(a1, v8 + 2866, a2);
    }
    else
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 5800LL) & 1) != 0 )
        populate_dot11f_wsc(a1, v8 + 2866);
      v47 = *(_DWORD *)(a1 + 12248);
      if ( v47 == 3 )
      {
        de_populate_dot11f_wsc_registrar_info(a1, v8 + 2866);
        *(_DWORD *)(a1 + 12248) = 0;
      }
      else if ( v47 == 1 )
      {
        populate_dot11f_wsc_registrar_info(a1, v8 + 2866);
        *(_DWORD *)(a1 + 12248) = 2;
      }
    }
    if ( *(_DWORD *)(a2 + 88) == 1 )
    {
      v50 = *(_QWORD *)(a2 + 16);
      if ( *(_DWORD *)(v50 + 16) == 1
        && (wlan_vdev_mlme_is_mlo_vdev(v50, v38, v39, v40, v41, v42, v43, v44, v45) & 1) != 0 )
      {
        LODWORD(v311) = 0;
        *(_BYTE *)(a2 + 10176) = 0;
        v51 = qdf_mem_cmp((const void *)(a2 + 10184), (const void *)(v6 + 60), 2u);
        v52 = v51 != 0;
        if ( v51 )
        {
          qdf_mem_copy((void *)(a2 + 10184), (const void *)(v6 + 60), 2u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d DSParams changed, critical update",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10206), (const void *)(v8 + 2834), 0x14u) )
        {
          qdf_mem_copy((void *)(a2 + 10206), (const void *)(v8 + 2834), 0x14u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d WMMParamSet changed, critical update",
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
          v52 = 1;
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
        }
        qdf_mem_copy((void *)(a2 + 10226), (const void *)(v8 + 2854), 3u);
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10186), (const void *)(v8 + 536), 0x14u) )
        {
          qdf_mem_copy((void *)(a2 + 10186), (const void *)(v8 + 536), 0x14u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d EDCAParamSet changed, critical update",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
          v52 = 1;
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10229), (const void *)(v8 + 250), 4u) )
        {
          *(_BYTE *)(a2 + 10176) = 1;
          if ( *(unsigned __int8 *)(a2 + 10229) != *(unsigned __int8 *)(v8 + 250) )
          {
            v52 = 1;
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x80000u;
          }
          qdf_mem_copy((void *)(a2 + 10229), (const void *)(v8 + 250), 4u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d csa added, critical update",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10233), (const void *)(v8 + 622), 5u) )
        {
          *(_BYTE *)(a2 + 10176) = 1;
          if ( *(unsigned __int8 *)(a2 + 10233) != *(unsigned __int8 *)(v8 + 622) )
          {
            v52 = 1;
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x80000u;
          }
          qdf_mem_copy((void *)(a2 + 10233), (const void *)(v8 + 622), 5u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d ecsa added, critical update",
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10238), (const void *)(v8 + 1556), 4u) )
        {
          *(_BYTE *)(a2 + 10176) = 1;
          if ( *(unsigned __int8 *)(a2 + 10238) != *(unsigned __int8 *)(v8 + 1556) )
          {
            v52 = 1;
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x80000u;
          }
          qdf_mem_copy((void *)(a2 + 10238), (const void *)(v8 + 1556), 4u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d max channel switch time added",
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10246), (const void *)(v8 + 254), 8u) )
        {
          *(_BYTE *)(a2 + 10176) = 1;
          if ( *(unsigned __int8 *)(a2 + 10246) != *(unsigned __int8 *)(v8 + 254) )
          {
            v52 = 1;
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x80000u;
          }
          qdf_mem_copy((void *)(a2 + 10246), (const void *)(v8 + 254), 8u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d quiet added, critical update",
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            v108,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10242), (const void *)(v8 + 1759), 3u) )
        {
          *(_BYTE *)(a2 + 10176) = 1;
          if ( *(unsigned __int8 *)(a2 + 10242) != *(unsigned __int8 *)(v8 + 1759) )
          {
            v52 = 1;
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
          }
          qdf_mem_copy((void *)(a2 + 10242), (const void *)(v8 + 1759), 3u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d bss color change changed",
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            "lim_update_cu_for_additional_inclusion_type_ie",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10254), (const void *)(v8 + 1294), 2u) )
        {
          *(_BYTE *)(a2 + 10176) = 1;
          if ( *(unsigned __int8 *)(a2 + 10254) != *(unsigned __int8 *)(v8 + 1294) )
          {
            v52 = 1;
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
          }
          qdf_mem_copy((void *)(a2 + 10254), (const void *)(v8 + 1294), 2u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d operating mode changed",
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            "lim_update_cu_for_additional_inclusion_type_ie",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10256), (const void *)(v8 + 1897), 4u) )
        {
          *(_BYTE *)(a2 + 10176) = 1;
          if ( *(unsigned __int8 *)(a2 + 10256) != *(unsigned __int8 *)(v8 + 1897) )
          {
            v52 = 1;
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
          }
          qdf_mem_copy((void *)(a2 + 10256), (const void *)(v8 + 1897), 4u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d wide bandwidth channel switch changed",
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            "lim_update_cu_for_additional_inclusion_type_ie",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10320), (const void *)(v8 + 724), 0x3Au) )
        {
          qdf_mem_copy((void *)(a2 + 10320), (const void *)(v8 + 724), 0x3Au);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d HTInfo changed, critical update",
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
          v52 = 1;
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10416), (const void *)(v8 + 832), 6u) )
        {
          qdf_mem_copy((void *)(a2 + 10416), (const void *)(v8 + 832), 6u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d VHTOperation changed, critical update",
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
          v52 = 1;
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10528), (const void *)(v8 + 1720), 0x12u) )
        {
          qdf_mem_copy((void *)(a2 + 10528), (const void *)(v8 + 1720), 0x12u);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d he_op changed, critical update",
            v149,
            v150,
            v151,
            v152,
            v153,
            v154,
            v155,
            v156,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
          v52 = 1;
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
        }
        if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 10644), (const void *)(v8 + 1996), 0xCu) )
        {
          qdf_mem_copy((void *)(a2 + 10644), (const void *)(v8 + 1996), 0xCu);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d eht_op changed, critical update",
            v157,
            v158,
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            "lim_update_link_info",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL));
          v52 = 1;
          *(_DWORD *)(*(_QWORD *)(a2 + 16) + 64LL) |= 0x100000u;
        }
        if ( *(_BYTE *)(a2 + 10178) == 1 )
        {
          if ( ((*(unsigned __int8 *)(a2 + 10176) | v52) & 1) != 0 )
          {
            *(_WORD *)(v6 + 10) |= 0x40u;
            v165 = dot11f_pack_beacon1(a1, v6, *(_QWORD *)(a2 + 7344) + 28LL, 484, &v311);
            *(_WORD *)(v6 + 10) &= ~0x40u;
            mlme_set_notify_co_located_ap_update_rnr(
              *(_QWORD *)(a2 + 16),
              1,
              v165,
              v166,
              v167,
              v168,
              v169,
              v170,
              v171,
              v172);
          }
        }
        else
        {
          *(_BYTE *)(a2 + 10178) = 1;
          *(_BYTE *)(a2 + 10660) = 0;
          qdf_mem_copy((void *)(a2 + 10378), (const void *)(v6 + 10), 2u);
          qdf_mem_copy((void *)(a2 + 10424), (const void *)(v8 + 3012), 0x2Cu);
          qdf_mem_copy((void *)(a2 + 10260), (const void *)(v8 + 664), 0x3Cu);
          qdf_mem_copy((void *)(a2 + 10380), (const void *)(v8 + 798), 0x11u);
          qdf_mem_copy((void *)(a2 + 10400), (const void *)(v8 + 816), 0x10u);
          qdf_mem_copy((void *)(a2 + 10468), (const void *)(v8 + 1660), 0x3Cu);
          qdf_mem_copy((void *)(a2 + 10546), (const void *)(v8 + 1776), 4u);
          qdf_mem_copy((void *)(a2 + 10552), (const void *)(v8 + 1904), 0x5Cu);
        }
        v173 = lim_send_bcn_frame_mlo(a1, a2);
        is_6ghz_chan_freq = populate_dot11f_mlo_rnr(a1, a2, v8 + 3060, v8 + 3056);
      }
      else
      {
        is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284));
        if ( (is_6ghz_chan_freq & 1) == 0 )
          is_6ghz_chan_freq = populate_dot11f_6g_rnr(a1, a2, v8 + 3060, v8 + 3056);
        v173 = 0;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))lim_update_probe_rsp_template_ie_bitmap_beacon2)(
        is_6ghz_chan_freq,
        v8,
        a2 + 1952,
        a2 + 1988);
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, v8 + 3060, 28);
      if ( *(_BYTE *)(a2 + 7022) )
      {
        if ( *(_DWORD *)(a2 + 1648) )
        {
          populate_dot11f_probe_res_wpsi_es(a1, v10, a2);
          if ( *v10 )
          {
            *(_DWORD *)(a2 + 1976) |= 0x20000000u;
            qdf_mem_copy((void *)(a2 + 5192), v10, 0x110u);
          }
        }
        else
        {
          *v10 = 0;
        }
      }
    }
    else
    {
      v173 = 0;
    }
    if ( *(_WORD *)(a2 + 7320) )
    {
      lim_strip_he_ies_from_add_ies(a1, a2);
      lim_strip_eht_ies_from_add_ies(a1, a2);
      lim_strip_wapi_ies_from_add_ies(a1, a2);
      n[0] = *(_WORD *)(a2 + 7320);
      v175 = (unsigned __int8 *)_qdf_mem_malloc(n[0], "sch_set_fixed_beacon_fields", 1024);
      v48 = v175;
      if ( !v175 )
      {
        v49 = 2;
        goto LABEL_194;
      }
      qdf_mem_copy(v175, *(const void **)(a2 + 7328), n[0]);
      qdf_mem_set(v323, 0x11u, 0);
      if ( (unsigned int)lim_strip_extcap_update_struct(a1, v48, n, (__int64)v323) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: extcap not extracted",
          v176,
          v177,
          v178,
          v179,
          v180,
          v181,
          v182,
          v183,
          "sch_set_fixed_beacon_fields");
        if ( !*(_BYTE *)(a2 + 7170) )
          goto LABEL_148;
      }
      else
      {
        lim_merge_extcap_struct(v8 + 798, v323, 1, v176, v177, v178, v179, v180, v181, v182, v183);
        populate_dot11f_bcn_prot_extcaps(a1, a2, v8 + 798);
        populate_dot11f_twt_extended_caps(a1, a2, v8 + 798);
        if ( !*(_BYTE *)(a2 + 7170) )
        {
LABEL_148:
          v192 = dot11f_pack_beacon2(a1, v8, *(_QWORD *)(a2 + 7352), 512, &v300);
          if ( (v192 & 0x10000000) == 0 )
          {
            if ( v192 )
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Warnings while packing a tDot11fBeacon2(0x%08x)",
                v193,
                v194,
                v195,
                v196,
                v197,
                v198,
                v199,
                v200,
                "sch_set_fixed_beacon_fields");
            v293 = v10;
            if ( !a2 || *(_BYTE *)(a2 + 10071) != 1 )
              goto LABEL_166;
            v292 = tpe_ie_length;
            v295[0] = v300;
            v201 = _qdf_mem_malloc(0x101u, "sch_set_fixed_beacon_fields", 1087);
            if ( v201 )
            {
              v210 = (_BYTE *)v201;
              if ( (unsigned int)lim_strip_eht_op_ie(a1, *(_QWORD *)(a2 + 7352), (__int64)v295, v201) )
              {
                v219 = "%s: Failed to strip EHT op IE";
LABEL_156:
                qdf_trace_msg(
                  0x35u,
                  2u,
                  v219,
                  v211,
                  v212,
                  v213,
                  v214,
                  v215,
                  v216,
                  v217,
                  v218,
                  "sch_set_fixed_beacon_fields");
                _qdf_mem_free((__int64)v210);
LABEL_160:
                v10 = v293;
                v49 = 16;
                goto LABEL_194;
              }
              v221 = *(_QWORD *)(v8 + 1728);
              v222 = *(unsigned __int16 *)(v8 + 836);
              v223 = *(unsigned int *)(v8 + 832);
              v224 = *(_QWORD *)(v8 + 1996);
              v303 = *(_QWORD *)(v8 + 1720);
              v304 = v221;
              v225 = *(_QWORD *)(v8 + 764);
              v226 = *(_QWORD *)(v8 + 772);
              v227 = *(_WORD *)(v8 + 1736);
              v228 = *(unsigned int *)(v8 + 2004);
              v315 = *(_QWORD *)(v8 + 756);
              v316 = v225;
              v229 = *(_WORD *)(v8 + 780);
              v317 = v226;
              LOWORD(v318) = v229;
              v231 = *(_QWORD *)(v8 + 724);
              v230 = *(_QWORD *)(v8 + 732);
              v233 = *(_QWORD *)(v8 + 740);
              v232 = *(_QWORD *)(v8 + 748);
              LOWORD(v305) = v227;
              v311 = v231;
              v312 = v230;
              v313 = v233;
              v314 = v232;
              lim_ieee80211_pack_ehtop(v210, v224, v228, v223 | (v222 << 32), &v303, &v311);
              v234 = (unsigned __int8)(v210[1] + 2);
              qdf_mem_copy((void *)(*(_QWORD *)(a2 + 7352) + v295[0]), v210, (unsigned __int8)(v210[1] + 2));
              _qdf_mem_free((__int64)v210);
              v300 = v295[0] + v234;
              v295[0] += v234;
              v235 = _qdf_mem_malloc(0x101u, "sch_set_fixed_beacon_fields", 1117);
              if ( v235 )
              {
                v210 = (_BYTE *)v235;
                if ( (unsigned int)lim_strip_eht_cap_ie(a1, *(_QWORD *)(a2 + 7352), (__int64)v295, v235) )
                {
                  v219 = "%s: Failed to strip EHT cap IE";
                  goto LABEL_156;
                }
                is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284));
                v237 = *(_QWORD *)(v8 + 1976);
                v238 = *(_QWORD *)(v8 + 1984);
                v319 = *(_QWORD *)(v8 + 1968);
                v320 = v237;
                v239 = *(_DWORD *)(v8 + 1992);
                v240 = *(_QWORD *)(v8 + 1936);
                v321 = v238;
                v241 = *(_QWORD *)(v8 + 1952);
                v322 = v239;
                v242 = *(_QWORD *)(v8 + 1944);
                v315 = v240;
                v316 = v242;
                v243 = *(_QWORD *)(v8 + 1960);
                v244 = *(_QWORD *)(v8 + 1904);
                v317 = v241;
                v318 = v243;
                v245 = *(_QWORD *)(v8 + 1912);
                v246 = *(_QWORD *)(v8 + 1920);
                v311 = v244;
                v312 = v245;
                v247 = *(_QWORD *)(v8 + 1928);
                v313 = v246;
                v314 = v247;
                v248 = *(_QWORD *)(v8 + 1700);
                v249 = *(_QWORD *)(v8 + 1708);
                v307 = *(_QWORD *)(v8 + 1692);
                v308 = v248;
                LODWORD(v248) = *(_DWORD *)(v8 + 1716);
                v309 = v249;
                v310 = v248;
                v250 = *(_QWORD *)(v8 + 1668);
                v303 = *(_QWORD *)(v8 + 1660);
                v304 = v250;
                v251 = *(_QWORD *)(v8 + 1684);
                v305 = *(_QWORD *)(v8 + 1676);
                v306 = v251;
                lim_ieee80211_pack_ehtcap(v210, &v311, &v303, is_24ghz_ch_freq, 0);
                v252 = (unsigned __int8)(v210[1] + 2);
                qdf_mem_copy((void *)(*(_QWORD *)(a2 + 7352) + v295[0]), v210, (unsigned __int8)(v210[1] + 2));
                _qdf_mem_free((__int64)v210);
                v253 = v295[0] + v252;
                tpe_ie_length = v292;
                v300 = v253;
LABEL_166:
                if ( tpe_ie_length )
                {
                  if ( (unsigned int)lim_fill_complete_tpe_ie(
                                       v193,
                                       v194,
                                       v195,
                                       v196,
                                       v197,
                                       v198,
                                       v199,
                                       v200,
                                       *(unsigned int *)(a2 + 7176),
                                       tpe_ie_length,
                                       (__int64)v36,
                                       v294[0],
                                       (char *)(*(_QWORD *)(a2 + 7352) + v300)) )
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: assemble tpe ie error",
                      v193,
                      v194,
                      v195,
                      v196,
                      v197,
                      v198,
                      v199,
                      v200,
                      "sch_set_fixed_beacon_fields");
                    tpe_ie_length = 0;
                  }
                  v300 += tpe_ie_length;
                }
                if ( (_WORD)v173 )
                {
                  if ( (unsigned int)lim_fill_complete_mlo_ie(a2, v173, *(_QWORD *)(a2 + 7352) + v300) )
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: assemble ml ie error",
                      v193,
                      v194,
                      v195,
                      v196,
                      v197,
                      v198,
                      v199,
                      v200,
                      "sch_set_fixed_beacon_fields");
                    LOWORD(v173) = 0;
                  }
                  v300 += (unsigned __int16)v173;
                }
                *(_QWORD *)(a1 + 12456) = 0;
                if ( *(_BYTE *)(a2 + 7282) )
                  sch_get_csa_ecsa_count_offset(*(_QWORD *)(a2 + 7352), v300, &v298, &n_4);
                if ( v298 )
                  *(_DWORD *)(a1 + 12456) = v298 + *(unsigned __int16 *)(a2 + 7360) + 10;
                if ( n_4 )
                  *(_DWORD *)(a1 + 12460) = n_4 + *(unsigned __int16 *)(a2 + 7360) + 10;
                v254 = *(_QWORD *)(a2 + 16);
                v291 = v36;
                if ( *(_DWORD *)(v254 + 16) == 1
                  && (wlan_vdev_mlme_is_mlo_vdev(v254, v193, v194, v195, v196, v197, v198, v199, v200) & 1) != 0 )
                {
                  lim_upt_mlo_partner_info(
                    a1,
                    a2,
                    *(_QWORD *)(a2 + 7352),
                    v300,
                    (unsigned int)*(unsigned __int16 *)(a2 + 7360) + 10);
                }
                v255 = v300;
                v256 = *(_QWORD *)(a2 + 7352);
                v257 = (unsigned __int16)v300;
                v258 = 502 - (*(_WORD *)(a2 + 7360) + v300);
                if ( n[0] )
                  sch_append_addn_ie(
                    a1,
                    a2,
                    v256 + v300,
                    (unsigned __int16)(502 - (*(_WORD *)(a2 + 7360) + v300)),
                    &v300,
                    v48);
                v259 = v300;
                *(_WORD *)(a2 + 7362) = v300;
                if ( (unsigned int)sch_get_p2p_ie_offset(v256 + v255, v259 - v257, &v299) )
                  v268 = 0;
                else
                  v268 = v255 + *(_WORD *)(a2 + 7360) + v299 + 10;
                *(_WORD *)(a1 + 12452) = v268;
                v36 = v291;
                LODWORD(v286) = *(_DWORD *)(a1 + 12460);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: vdev %d: beacon begin offset %d fixed size %d csa_count_offset %d ecsa_count_offset %d max_bcn_siz"
                  "e_left %d addn_ielen %d beacon end offset %d HT %d VHT %d HE %d EHT %d",
                  v260,
                  v261,
                  v262,
                  v263,
                  v264,
                  v265,
                  v266,
                  v267,
                  "sch_set_fixed_beacon_fields",
                  *(unsigned __int8 *)(a2 + 10),
                  28,
                  *(unsigned __int16 *)(a2 + 7360),
                  *(unsigned int *)(a1 + 12456),
                  v286,
                  v258,
                  n[0],
                  *(unsigned __int16 *)(a2 + 7362),
                  *(unsigned __int8 *)(v8 + 664),
                  *(unsigned __int8 *)(v8 + 816),
                  *(unsigned __int8 *)(v8 + 1660),
                  *(unsigned __int8 *)(v8 + 1904));
                v10 = v293;
                if ( *(_DWORD *)(a1 + 12460) || *(_DWORD *)(a1 + 12456) )
                {
                  wlan_reg_read_current_country(
                    *(_QWORD *)(a1 + 21624),
                    &v301,
                    v269,
                    v270,
                    v271,
                    v272,
                    v273,
                    v274,
                    v275,
                    v276);
                  v285 = *(unsigned __int8 *)(v8 + 622);
                  if ( *(_BYTE *)(v8 + 622) )
                    v285 = *(unsigned __int8 *)(v8 + 624);
                  LODWORD(v290) = *(unsigned __int8 *)(a2 + 7224);
                  LODWORD(v289) = *(char *)(a2 + 7218);
                  LODWORD(v288) = *(unsigned __int8 *)(a2 + 7211);
                  LODWORD(v287) = v285;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: ECSA/CSA : country:%s chan:%d freq %d width:%d reg:%d off:%d count %d mode %d",
                    v277,
                    v278,
                    v279,
                    v280,
                    v281,
                    v282,
                    v283,
                    v284,
                    "sch_set_fixed_beacon_fields",
                    &v301,
                    *(unsigned __int8 *)(a2 + 7208),
                    *(unsigned int *)(a2 + 7204),
                    *(unsigned int *)(a2 + 7212),
                    v287,
                    v288,
                    v289,
                    v290);
                }
                v49 = 0;
                *(_BYTE *)(a1 + 12450) = 1;
                goto LABEL_194;
              }
              v220 = "%s: malloc failed for eht_cap_ie";
            }
            else
            {
              v220 = "%s: malloc failed for eht_op_ie";
            }
            qdf_trace_msg(
              0x35u,
              2u,
              v220,
              v202,
              v203,
              v204,
              v205,
              v206,
              v207,
              v208,
              v209,
              "sch_set_fixed_beacon_fields");
            goto LABEL_160;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to packed a tDot11fBeacon2 (0x%08x)",
            v193,
            v194,
            v195,
            v196,
            v197,
            v198,
            v199,
            v200,
            "sch_set_fixed_beacon_fields",
            v192);
          v49 = 16;
LABEL_194:
          _qdf_mem_free(v6);
          _qdf_mem_free(v8);
          _qdf_mem_free((__int64)v10);
          _qdf_mem_free((__int64)v48);
          _qdf_mem_free((__int64)v36);
          result = v49;
          goto LABEL_195;
        }
      }
    }
    else
    {
      v48 = nullptr;
      if ( !*(_BYTE *)(a2 + 7170) )
        goto LABEL_148;
    }
    if ( *(_BYTE *)(a2 + 7171) )
    {
      populate_dot11f_operating_mode(a1, v8 + 1294, a2);
      lim_strip_ie(a1, v48, n, 0xC7u, 1, nullptr, 0, nullptr, v184, v185, v186, v187, v188, v189, v190, v191, 1);
    }
    goto LABEL_148;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to packed a tDot11fBeacon1 (0x%08x)",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "sch_set_fixed_beacon_fields",
    v23);
  _qdf_mem_free(v6);
  _qdf_mem_free(v8);
  _qdf_mem_free((__int64)v10);
  result = 16;
LABEL_195:
  _ReadStatusReg(SP_EL0);
  return result;
}
