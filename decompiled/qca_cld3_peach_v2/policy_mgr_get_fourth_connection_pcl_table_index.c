__int64 __fastcall policy_mgr_get_fourth_connection_pcl_table_index(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 *v11; // x19
  unsigned int v12; // w0
  unsigned int v13; // w21
  int v14; // w0
  int v15; // w26
  unsigned int v16; // w21
  unsigned int v17; // w22
  unsigned int v18; // w23
  unsigned int v19; // w24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 is_24ghz_ch_freq; // x0
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w22
  unsigned int v42; // w21
  unsigned int v43; // w20
  unsigned int v44; // w20
  unsigned int v45; // w20
  char v46; // w21
  int v47; // w8
  char v48; // w22
  unsigned int sbs_cut_off_freq; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w21
  unsigned __int64 v59; // x8
  bool v60; // zf
  int v61; // w8
  int v62; // w21
  _BOOL4 v63; // w21
  char v64; // w21
  const char *v65; // x3
  int v66; // w9
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  _BOOL4 v75; // w21
  int v76; // w22
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w23
  unsigned __int64 v86; // x8
  unsigned int v87; // w24
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // w4
  __int64 v97; // x8
  __int64 v98; // x9
  const char *v99; // x2
  bool v101; // w8
  int v102; // w9
  __int64 v103; // [xsp+0h] [xbp-D0h]
  __int64 v104; // [xsp+8h] [xbp-C8h]
  unsigned int v105; // [xsp+2Ch] [xbp-A4h] BYREF
  unsigned int v106; // [xsp+30h] [xbp-A0h] BYREF
  int v107; // [xsp+34h] [xbp-9Ch] BYREF
  int v108; // [xsp+38h] [xbp-98h] BYREF
  char v109; // [xsp+3Ch] [xbp-94h]
  int v110; // [xsp+40h] [xbp-90h] BYREF
  char v111; // [xsp+44h] [xbp-8Ch]
  int v112; // [xsp+48h] [xbp-88h] BYREF
  char v113; // [xsp+4Ch] [xbp-84h]
  _QWORD v114[2]; // [xsp+50h] [xbp-80h] BYREF
  int v115; // [xsp+60h] [xbp-70h]
  _QWORD v116[2]; // [xsp+68h] [xbp-68h] BYREF
  int v117; // [xsp+78h] [xbp-58h]
  _QWORD v118[2]; // [xsp+80h] [xbp-50h] BYREF
  int v119; // [xsp+90h] [xbp-40h]
  _QWORD v120[2]; // [xsp+98h] [xbp-38h] BYREF
  int v121; // [xsp+A8h] [xbp-28h]
  __int64 v122; // [xsp+B0h] [xbp-20h] BYREF
  __int64 v123; // [xsp+B8h] [xbp-18h]
  int v124; // [xsp+C0h] [xbp-10h]
  __int64 v125; // [xsp+C8h] [xbp-8h]

  v125 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v107 = 34;
  LOBYTE(v106) = 0;
  LOBYTE(v105) = 0;
  v124 = 0;
  v122 = 0;
  v123 = 0;
  v121 = 0;
  v120[0] = 0;
  v120[1] = 0;
  v119 = 0;
  v118[0] = 0;
  v118[1] = 0;
  v117 = 0;
  v116[0] = 0;
  v116[1] = 0;
  v113 = 0;
  v112 = 0;
  v111 = 0;
  v110 = 0;
  v115 = 0;
  v114[0] = 0;
  v114[1] = 0;
  v109 = 0;
  v108 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "policy_mgr_get_fourth_connection_pcl_table_index");
    v44 = 34;
LABEL_311:
    _ReadStatusReg(SP_EL0);
    return v44;
  }
  v11 = (__int64 *)context;
  qdf_mutex_acquire(context + 56);
  v12 = policy_mgr_mode_specific_connection_count(a1, 1, &v122);
  if ( v12 >= 6 )
    goto LABEL_379;
  v13 = v12;
  v14 = policy_mgr_mode_specific_connection_count(a1, 3, (_DWORD *)&v122 + v12);
  if ( v14 + v13 > 5 )
    goto LABEL_379;
  v15 = policy_mgr_mode_specific_connection_count(a1, 2, (_DWORD *)&v122 + v14 + v13) + v14;
  v16 = v15 + v13;
  v17 = policy_mgr_mode_specific_connection_count(a1, 0, v120);
  policy_mgr_get_ml_and_non_ml_mode_count(
    a1,
    &v106,
    (__int64)&v112,
    &v105,
    (__int64)&v110,
    (unsigned __int64)v114,
    (unsigned __int64)&v108,
    0);
  v18 = policy_mgr_mode_specific_connection_count(a1, 4, v118);
  v19 = policy_mgr_mode_specific_connection_count(a1, 5, v116);
  is_24ghz_ch_freq = qdf_trace_msg(
                       0x4Fu,
                       8u,
                       "%s: sap/go/cli:%d sta:%d ndi:%d nan disc:%d ml_sta:%d",
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       "policy_mgr_get_fourth_connection_pcl_table_index",
                       v16,
                       v17,
                       v18,
                       v19,
                       (unsigned __int8)v106);
  if ( v16 == 2 && (unsigned __int8)v106 == 1 )
  {
    if ( (unsigned __int8)v112 <= 4uLL && (unsigned int)v122 <= 4 && HIDWORD(v122) <= 4 )
    {
      v41 = *((_DWORD *)v114 + (unsigned __int8)v112);
      v42 = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1);
      v43 = *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: channel: ML sta0: %d, SAP0: %d, SAP1: %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "policy_mgr_get_index_for_ml_sta_sap_sap",
        v41,
        v42,
        v43);
      if ( ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(*v11) & 1) != 0 )
        policy_mgr_get_index_for_3_given_freq_sbs(v11, &v107, v41, v42, v43);
      else
        policy_mgr_get_index_for_3_given_freq_dbs(&v107, v41, v42, v43);
      goto LABEL_310;
    }
LABEL_379:
    __break(0x5512u);
  }
  if ( v16 == 2 && v17 == 1 && !(_BYTE)v106 )
  {
    if ( (unsigned int)v122 > 4 )
      goto LABEL_379;
    if ( HIDWORD(v122) > 4 )
      goto LABEL_379;
    if ( LODWORD(v120[0]) > 4 )
      goto LABEL_379;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: channel: sap0: %d, sap1: %d, sta0: %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "policy_mgr_get_fourth_connection_pcl_table_index",
      *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1),
      *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1),
      *((unsigned int *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1));
    if ( (unsigned int)v122 > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
    {
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      {
        if ( HIDWORD(v122) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
          goto LABEL_34;
        if ( HIDWORD(v122) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
          goto LABEL_34;
      }
    }
    if ( HIDWORD(v122) > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
    {
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      {
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
          goto LABEL_34;
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
LABEL_34:
          v107 = 0;
          goto LABEL_310;
        }
      }
    }
    if ( (unsigned int)v122 > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
    {
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      {
        if ( HIDWORD(v122) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
          goto LABEL_71;
      }
    }
    if ( HIDWORD(v122) > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
    {
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      {
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
          goto LABEL_71;
      }
    }
    if ( (unsigned int)v122 > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
    {
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      {
        if ( HIDWORD(v122) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
          goto LABEL_71;
      }
    }
    if ( HIDWORD(v122) > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
    {
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      {
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
LABEL_71:
          v47 = 1;
LABEL_309:
          v107 = v47;
          goto LABEL_310;
        }
      }
    }
    if ( (unsigned int)v122 > 4 )
      goto LABEL_379;
    if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
      goto LABEL_92;
    if ( LODWORD(v120[0]) > 4 )
      goto LABEL_379;
    if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      goto LABEL_92;
    if ( HIDWORD(v122) > 4 )
      goto LABEL_379;
    if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
    {
LABEL_92:
      if ( HIDWORD(v122) > 4 )
        goto LABEL_379;
      if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
        goto LABEL_93;
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
        goto LABEL_93;
      if ( (unsigned int)v122 > 4 )
        goto LABEL_379;
      if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
      {
LABEL_93:
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
          goto LABEL_104;
        if ( LODWORD(v120[0]) > 4 )
          goto LABEL_379;
        if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
          goto LABEL_104;
        if ( HIDWORD(v122) > 4 )
          goto LABEL_379;
        if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
        {
LABEL_104:
          if ( HIDWORD(v122) > 4 )
            goto LABEL_379;
          if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
            goto LABEL_263;
          if ( LODWORD(v120[0]) > 4 )
            goto LABEL_379;
          if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
            goto LABEL_263;
          if ( (unsigned int)v122 > 4 )
            goto LABEL_379;
          if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
            goto LABEL_263;
        }
LABEL_308:
        v47 = 30;
        goto LABEL_309;
      }
    }
LABEL_252:
    v47 = 31;
    goto LABEL_309;
  }
  if ( (unsigned __int8)v106 != 2 || v16 != 1 )
  {
    if ( v19 == 1 && (unsigned __int8)v106 == 2 )
    {
      v47 = 29;
      goto LABEL_309;
    }
    if ( v16 != 1 || v17 != 2 || (unsigned __int8)v106 > 1u )
    {
      v60 = v19 == 1 && v18 == 1;
      v61 = v60;
      if ( v60 && !v15 && v16 == 1 )
      {
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
          if ( LODWORD(v118[0]) > 4 )
            goto LABEL_379;
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
          {
            v47 = 5;
            goto LABEL_309;
          }
        }
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
          if ( LODWORD(v118[0]) > 4 )
            goto LABEL_379;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
          {
            v47 = 6;
            goto LABEL_309;
          }
        }
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
          if ( LODWORD(v118[0]) > 4 )
            goto LABEL_379;
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
          {
            v47 = 7;
            goto LABEL_309;
          }
        }
      }
      else
      {
        if ( v15 == 1 )
          v66 = v61;
        else
          v66 = 0;
        if ( v66 != 1 )
        {
          if ( v17 != 1 )
            v61 = 0;
          if ( v61 == 1 )
          {
            if ( LODWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
            {
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
                goto LABEL_298;
            }
            if ( LODWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
            {
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
                goto LABEL_298;
            }
            if ( LODWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
            {
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
                goto LABEL_298;
            }
            if ( LODWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
            {
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
              {
LABEL_298:
                v47 = 8;
                goto LABEL_309;
              }
            }
          }
          else
          {
            if ( v19 == 1 && v16 == 1 && v17 == 1 )
            {
              v47 = 28;
              goto LABEL_309;
            }
            if ( v19 == 1 && v18 == 2 )
            {
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
              {
                if ( HIDWORD(v118[0]) > 4 )
                  goto LABEL_379;
                if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v118[0]) + 1)) )
                  goto LABEL_337;
              }
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
              {
                if ( LODWORD(v118[0]) > 4 )
                  goto LABEL_379;
                if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
                  goto LABEL_337;
              }
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
              {
                if ( LODWORD(v118[0]) > 4 )
                  goto LABEL_379;
                if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
                  goto LABEL_337;
              }
              if ( LODWORD(v118[0]) > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
              {
                if ( LODWORD(v118[0]) > 4 )
                  goto LABEL_379;
                if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
                {
LABEL_337:
                  v47 = 9;
                  goto LABEL_309;
                }
              }
            }
            else if ( v16 == 3 )
            {
              if ( ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(a1) & 1) != 0 )
              {
                if ( (unsigned int)v122 > 4 || HIDWORD(v122) > 4 || (unsigned int)v123 > 4 )
                  goto LABEL_379;
                policy_mgr_get_index_for_3_given_freq_sbs(
                  v11,
                  &v107,
                  *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1),
                  *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1),
                  *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v123 + 1));
              }
              else if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
              {
                if ( (unsigned int)v122 > 4 || HIDWORD(v122) > 4 || (unsigned int)v123 > 4 )
                  goto LABEL_379;
                policy_mgr_get_index_for_3_given_freq_dbs(
                  &v107,
                  *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1),
                  *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1),
                  *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v123 + 1));
              }
              if ( v107 == 34 )
              {
                if ( (unsigned int)v122 > 4 )
                  goto LABEL_379;
                if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
                {
                  if ( HIDWORD(v122) > 4 )
                    goto LABEL_379;
                  if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
                  {
                    if ( (unsigned int)v123 > 4 )
                      goto LABEL_379;
                    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v123 + 1)) )
                    {
                      v47 = 12;
                      goto LABEL_309;
                    }
                  }
                }
                if ( (unsigned int)v122 > 4 )
                  goto LABEL_379;
                if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
                {
                  if ( HIDWORD(v122) > 4 )
                    goto LABEL_379;
                  if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v122) + 1)) )
                  {
                    if ( (unsigned int)v123 > 4 )
                      goto LABEL_379;
                    if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v123 + 1)) )
                    {
                      v47 = 13;
                      goto LABEL_309;
                    }
                  }
                }
              }
            }
          }
LABEL_310:
          v44 = v107;
          LODWORD(v104) = HIDWORD(qword_8D4F30);
          LODWORD(v103) = HIDWORD(qword_8D4F0C);
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: mode0:%d mode1:%d mode2:%d chan0:%d chan1:%d chan2:%d chain:%d index:%d",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "policy_mgr_get_fourth_connection_pcl_table_index",
            (unsigned int)pm_conc_connection_list,
            (unsigned int)qword_8D4F0C,
            (unsigned int)qword_8D4F30,
            HIDWORD(pm_conc_connection_list),
            v103,
            v104,
            dword_8D4EF8,
            v107);
          qdf_mutex_release((__int64)(v11 + 7));
          goto LABEL_311;
        }
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
          if ( LODWORD(v118[0]) > 4 )
            goto LABEL_379;
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
            goto LABEL_247;
        }
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
          if ( LODWORD(v118[0]) > 4 )
            goto LABEL_379;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
            goto LABEL_247;
        }
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
          if ( LODWORD(v118[0]) > 4 )
            goto LABEL_379;
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
            goto LABEL_247;
        }
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        {
          if ( LODWORD(v118[0]) > 4 )
            goto LABEL_379;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v118[0]) + 1)) )
          {
LABEL_247:
            v47 = 11;
            goto LABEL_309;
          }
        }
      }
LABEL_263:
      v47 = 34;
      goto LABEL_309;
    }
    if ( (unsigned int)v122 > 4 )
      goto LABEL_379;
    if ( LODWORD(v120[0]) > 4 )
      goto LABEL_379;
    if ( HIDWORD(v120[0]) > 4 )
      goto LABEL_379;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: channel: sap0: %d, sta0: %d, sta1: %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "policy_mgr_get_fourth_connection_pcl_table_index",
      *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1),
      *((unsigned int *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1),
      *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1));
    if ( LODWORD(v120[0]) > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
    {
      if ( (unsigned int)v122 > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
      {
        if ( HIDWORD(v120[0]) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
          goto LABEL_218;
        if ( HIDWORD(v120[0]) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
          goto LABEL_218;
      }
    }
    if ( HIDWORD(v120[0]) > 4 )
      goto LABEL_379;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
    {
      if ( (unsigned int)v122 > 4 )
        goto LABEL_379;
      if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
      {
        if ( LODWORD(v120[0]) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
          goto LABEL_218;
        if ( LODWORD(v120[0]) > 4 )
          goto LABEL_379;
        if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
        {
LABEL_218:
          v47 = 2;
          goto LABEL_309;
        }
      }
    }
    if ( LODWORD(v120[0]) > 4 )
      goto LABEL_379;
    if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      goto LABEL_156;
    if ( (unsigned int)v122 > 4 )
      goto LABEL_379;
    if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
      goto LABEL_156;
    if ( HIDWORD(v120[0]) > 4 )
      goto LABEL_379;
    if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
    {
LABEL_156:
      if ( HIDWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
        goto LABEL_160;
      if ( (unsigned int)v122 > 4 )
        goto LABEL_379;
      if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
        goto LABEL_160;
      if ( LODWORD(v120[0]) > 4 )
        goto LABEL_379;
      if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
      {
LABEL_160:
        if ( LODWORD(v120[0]) > 4 )
          goto LABEL_379;
        if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
          goto LABEL_166;
        if ( (unsigned int)v122 > 4 )
          goto LABEL_379;
        if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
          goto LABEL_166;
        if ( HIDWORD(v120[0]) > 4 )
          goto LABEL_379;
        if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
        {
LABEL_166:
          if ( HIDWORD(v120[0]) > 4 )
            goto LABEL_379;
          if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
            goto LABEL_169;
          if ( (unsigned int)v122 > 4 )
            goto LABEL_379;
          if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
            goto LABEL_169;
          if ( LODWORD(v120[0]) > 4 )
            goto LABEL_379;
          if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
          {
LABEL_169:
            if ( LODWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
            {
              if ( (unsigned int)v122 > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
              {
                if ( HIDWORD(v120[0]) > 4 )
                  goto LABEL_379;
                if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
                  goto LABEL_308;
              }
            }
            if ( HIDWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
            {
              if ( (unsigned int)v122 > 4 )
                goto LABEL_379;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
              {
                if ( LODWORD(v120[0]) > 4 )
                  goto LABEL_379;
                if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
                  goto LABEL_308;
              }
            }
            if ( LODWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
              goto LABEL_192;
            if ( (unsigned int)v122 > 4 )
              goto LABEL_379;
            if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
              goto LABEL_192;
            if ( HIDWORD(v120[0]) > 4 )
              goto LABEL_379;
            if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
            {
LABEL_192:
              if ( HIDWORD(v120[0]) > 4 )
                goto LABEL_379;
              if ( !wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v120[0]) + 1)) )
                goto LABEL_263;
              if ( (unsigned int)v122 > 4 )
                goto LABEL_379;
              if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1)) )
                goto LABEL_263;
              if ( LODWORD(v120[0]) > 4 )
                goto LABEL_379;
              if ( !wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v120[0]) + 1)) )
                goto LABEL_263;
            }
            goto LABEL_252;
          }
        }
      }
    }
LABEL_80:
    v47 = 3;
    goto LABEL_309;
  }
  if ( (unsigned int)v122 > 4 )
    goto LABEL_379;
  if ( (unsigned __int8)v112 > 4uLL )
    goto LABEL_380;
  is_24ghz_ch_freq = *((unsigned int *)v114 + (unsigned __int8)v112);
  v45 = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v122 + 1);
  if ( !(_DWORD)is_24ghz_ch_freq )
    goto LABEL_75;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(is_24ghz_ch_freq);
  if ( (is_24ghz_ch_freq & 1) != 0 )
    goto LABEL_75;
  if ( BYTE1(v112) > 4uLL )
    goto LABEL_380;
  is_24ghz_ch_freq = *((unsigned int *)v114 + BYTE1(v112));
  if ( (_DWORD)is_24ghz_ch_freq
    && (is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(is_24ghz_ch_freq), (is_24ghz_ch_freq & 1) == 0)
    && (is_24ghz_ch_freq = policy_mgr_is_mlo_in_mode_emlsr(*v11, 0, nullptr), (is_24ghz_ch_freq & 1) != 0) )
  {
    is_24ghz_ch_freq = wlan_mlme_is_aux_emlsr_support(*v11);
    v46 = is_24ghz_ch_freq;
  }
  else
  {
LABEL_75:
    v46 = 0;
  }
  if ( (unsigned __int8)v112 > 4uLL || BYTE1(v112) > 4uLL )
    goto LABEL_380;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: channel: sap0: %d, ML STA link0: %d, ML STA link1: %d aux emlsr %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "policy_mgr_get_index_for_ml_sta_sap",
    v45,
    *((unsigned int *)v114 + (unsigned __int8)v112),
    *((unsigned int *)v114 + BYTE1(v112)),
    v46 & 1);
  if ( (v46 & 1) != 0 && wlan_reg_is_24ghz_ch_freq(v45) )
    goto LABEL_80;
  is_24ghz_ch_freq = (__int64)policy_mgr_is_current_hwmode_sbs(*v11);
  if ( (is_24ghz_ch_freq & 1) == 0 )
  {
    if ( (unsigned __int8)v112 > 4uLL || BYTE1(v112) > 4uLL )
      goto LABEL_380;
    is_24ghz_ch_freq = policy_mgr_are_sbs_chan(
                         *v11,
                         *((_DWORD *)v114 + (unsigned __int8)v112),
                         *((_DWORD *)v114 + BYTE1(v112)));
    if ( (is_24ghz_ch_freq & 1) == 0 )
    {
      if ( (unsigned __int8)v112 > 4uLL )
        goto LABEL_380;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + (unsigned __int8)v112));
      if ( BYTE1(v112) > 4uLL )
        goto LABEL_380;
      v62 = is_24ghz_ch_freq;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + BYTE1(v112)));
      if ( ((v62 ^ (unsigned int)is_24ghz_ch_freq) & 1) != 0 )
        goto LABEL_383;
      if ( (unsigned __int8)v112 > 4uLL )
        goto LABEL_380;
      v63 = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + (unsigned __int8)v112));
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v45);
      if ( ((v63 ^ (unsigned int)is_24ghz_ch_freq) & 1) != 0 )
      {
LABEL_383:
        if ( (unsigned __int8)v112 > 4uLL )
          goto LABEL_380;
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + (unsigned __int8)v112));
        if ( BYTE1(v112) > 4uLL )
          goto LABEL_380;
        v64 = is_24ghz_ch_freq ^ wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + BYTE1(v112)));
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v45);
        if ( (v64 & 1) != 0 )
        {
          if ( (is_24ghz_ch_freq & 1) != 0 )
            goto LABEL_218;
          goto LABEL_80;
        }
        if ( (is_24ghz_ch_freq & 1) != 0 )
          goto LABEL_80;
        v97 = (unsigned __int8)v112;
        if ( (unsigned __int8)v112 > 4uLL )
          goto LABEL_380;
        v98 = BYTE1(v112);
        if ( BYTE1(v112) > 4uLL )
          goto LABEL_380;
        v99 = "%s: Invalid mode for ML STA %d and %d are on 2.4 GHZ, sap freq %d";
      }
      else
      {
        v97 = (unsigned __int8)v112;
        if ( (unsigned __int8)v112 > 4uLL )
          goto LABEL_380;
        v98 = BYTE1(v112);
        if ( BYTE1(v112) > 4uLL )
          goto LABEL_380;
        v99 = "%s: Invalid mode for ML STA %d and %d are on same band as SAP %d";
      }
      qdf_trace_msg(
        0x4Fu,
        2u,
        v99,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "policy_mgr_get_index_for_ml_sta_sap_dbs",
        *((unsigned int *)v114 + v97),
        *((unsigned int *)v114 + v98),
        v45);
      goto LABEL_310;
    }
  }
  is_24ghz_ch_freq = policy_mgr_can_2ghz_share_low_high_5ghz_sbs((__int64)v11);
  if ( (unsigned __int8)v112 > 4uLL || BYTE1(v112) > 4uLL )
    goto LABEL_380;
  v48 = is_24ghz_ch_freq;
  is_24ghz_ch_freq = policy_mgr_are_sbs_chan(
                       *v11,
                       *((_DWORD *)v114 + (unsigned __int8)v112),
                       *((_DWORD *)v114 + BYTE1(v112)));
  if ( (is_24ghz_ch_freq & 1) == 0 )
  {
    if ( (unsigned __int8)v112 > 4uLL )
      goto LABEL_380;
    is_24ghz_ch_freq = policy_mgr_are_sbs_chan(*v11, v45, *((_DWORD *)v114 + (unsigned __int8)v112));
    if ( (is_24ghz_ch_freq & 1) == 0 )
    {
      if ( BYTE1(v112) > 4uLL )
        goto LABEL_380;
      if ( (policy_mgr_are_sbs_chan(*v11, v45, *((_DWORD *)v114 + BYTE1(v112))) & 1) == 0 )
      {
        is_24ghz_ch_freq = (__int64)policy_mgr_is_current_hwmode_sbs(*v11);
        if ( (is_24ghz_ch_freq & 1) == 0 )
        {
          if ( (unsigned __int8)v112 <= 4uLL && BYTE1(v112) <= 4uLL )
          {
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: SAP freq (%d) and ML STA freq %d and %d, none of the 2 connections/3 vdevs are leading to SBS",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "policy_mgr_get_index_for_ml_sta_sap_sbs",
              v45,
              *((unsigned int *)v114 + (unsigned __int8)v112),
              *((unsigned int *)v114 + BYTE1(v112)));
            goto LABEL_310;
          }
          goto LABEL_380;
        }
        v75 = policy_mgr_sbs_24_shared_with_high_5((__int64)v11);
        is_24ghz_ch_freq = policy_mgr_sbs_24_shared_with_low_5((__int64)v11);
        if ( (unsigned __int8)v112 > 4uLL )
          goto LABEL_380;
        v76 = is_24ghz_ch_freq;
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + (unsigned __int8)v112));
        if ( (is_24ghz_ch_freq & 1) == 0 )
        {
          if ( BYTE1(v112) > 4uLL )
            goto LABEL_380;
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + BYTE1(v112)));
          if ( (is_24ghz_ch_freq & 1) == 0 )
          {
            if ( (unsigned __int8)v112 <= 4uLL && BYTE1(v112) <= 4uLL )
            {
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: unexpected ml sta home freq to handle (%d %d)",
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                "policy_mgr_get_index_for_ml_sta_sap_hwmode_sbs",
                *((unsigned int *)v114 + (unsigned __int8)v112),
                *((unsigned int *)v114 + BYTE1(v112)));
              goto LABEL_310;
            }
            goto LABEL_380;
          }
        }
        if ( ((v76 | v75) & 1) == 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: unexpected sbs mode: low share %d high share %d",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "policy_mgr_get_index_for_ml_sta_sap_hwmode_sbs",
            0,
            0);
          goto LABEL_310;
        }
        is_24ghz_ch_freq = policy_mgr_get_sbs_cut_off_freq(*v11);
        if ( (_DWORD)is_24ghz_ch_freq )
        {
          if ( (unsigned __int8)v112 <= 4uLL )
          {
            v85 = is_24ghz_ch_freq;
            is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + (unsigned __int8)v112));
            v86 = *(unsigned __int8 *)((unsigned __int64)&v112 | is_24ghz_ch_freq & 1);
            if ( v86 <= 4 )
            {
              v87 = *((_DWORD *)v114 + v86);
              if ( wlan_reg_is_24ghz_ch_freq(v45) )
              {
                v96 = 32;
              }
              else
              {
                if ( v87 >= v85 )
                  v101 = v76;
                else
                  v101 = v75;
                if ( v85 <= v45 )
                  v102 = 30;
                else
                  v102 = 31;
                if ( v101 )
                  v96 = v102;
                else
                  v96 = 33;
              }
              v107 = v96;
              LODWORD(v103) = v75;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: 4th index %d sap freq %d ml sta 5g %d sbs_cut_off_freq %d support high share %d low share %d",
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                v94,
                v95,
                "policy_mgr_get_index_for_ml_sta_sap_hwmode_sbs",
                v103,
                v76 & 1);
              goto LABEL_310;
            }
          }
          goto LABEL_380;
        }
        v65 = "policy_mgr_get_index_for_ml_sta_sap_hwmode_sbs";
LABEL_220:
        qdf_trace_msg(0x4Fu, 2u, "%s: Invalid cutoff freq", v50, v51, v52, v53, v54, v55, v56, v57, v65);
        goto LABEL_310;
      }
    }
  }
  sbs_cut_off_freq = policy_mgr_get_sbs_cut_off_freq(*v11);
  if ( !sbs_cut_off_freq )
  {
    v65 = "policy_mgr_get_index_for_ml_sta_sap_sbs";
    goto LABEL_220;
  }
  v58 = sbs_cut_off_freq;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v45);
  if ( (is_24ghz_ch_freq & 1) != 0 )
  {
    if ( (v48 & 1) == 0 )
    {
      if ( (unsigned __int8)v112 <= 4uLL )
      {
        is_24ghz_ch_freq = policy_mgr_2_freq_same_mac_in_sbs(*v11, v45, *((_DWORD *)v114 + (unsigned __int8)v112));
        v59 = (is_24ghz_ch_freq & 1) != 0 ? (unsigned __int8)v112 : BYTE1(v112);
        if ( v59 <= 4 )
        {
          if ( *((_DWORD *)v114 + v59) >= v58 )
            goto LABEL_308;
          goto LABEL_252;
        }
      }
      goto LABEL_380;
    }
LABEL_226:
    v47 = 32;
    goto LABEL_309;
  }
  if ( (unsigned __int8)v112 > 4uLL )
    goto LABEL_380;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + (unsigned __int8)v112));
  if ( (is_24ghz_ch_freq & 1) != 0 )
    goto LABEL_225;
  if ( BYTE1(v112) > 4uLL )
    goto LABEL_380;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v114 + BYTE1(v112)));
  if ( (is_24ghz_ch_freq & 1) != 0 )
  {
LABEL_225:
    if ( (v48 & 1) != 0 )
      goto LABEL_226;
  }
  if ( (unsigned __int8)v112 <= 4uLL && BYTE1(v112) <= 4uLL )
  {
    if ( (policy_mgr_2_freq_same_mac_in_sbs(
            *v11,
            *((_DWORD *)v114 + (unsigned __int8)v112),
            *((_DWORD *)v114 + BYTE1(v112)))
        & 1) != 0 )
    {
      if ( v58 > v45 )
        goto LABEL_308;
    }
    else if ( v58 <= v45 )
    {
      goto LABEL_308;
    }
    goto LABEL_252;
  }
LABEL_380:
  __break(1u);
  return policy_mgr_get_index_for_3_given_freq_sbs(is_24ghz_ch_freq, v29, v30, v31, v32);
}
