__int64 __fastcall cm_update_roam_scan_channel_list(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 *a4,
        int *a5,
        unsigned __int8 a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  int v20; // w4
  unsigned int v21; // w9
  unsigned __int64 v22; // x8
  __int64 v23; // x11
  int v24; // w10
  int *v25; // x12
  __int64 v26; // x13
  int v27; // t1
  __int64 v28; // x27
  void *v29; // x0
  __int64 v30; // x26
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  __int64 v40; // x23
  unsigned int v41; // w21
  unsigned int v42; // w28
  int channel_state_for_pwrmode; // w0
  int *v44; // x8
  __int64 v45; // x9
  int v46; // t1
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v49; // x9
  __int64 v50; // x10
  _DWORD *v51; // x11
  int *v52; // x10
  unsigned __int64 v53; // x12
  int v54; // w13
  int v55; // w14
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  char v72; // w22
  __int64 v73; // x23
  unsigned int *v74; // x24
  __int64 v75; // x23
  unsigned int *v76; // x24
  __int64 v77; // x22
  int *v78; // x21
  __int64 v79; // x23
  int *v80; // x8
  int v81; // w9
  int v82; // t1
  __int64 v83; // x10
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x8
  __int64 v94; // [xsp+0h] [xbp-1F0h]
  int v96; // [xsp+24h] [xbp-1CCh] BYREF
  _QWORD v97[4]; // [xsp+28h] [xbp-1C8h] BYREF
  _DWORD s[102]; // [xsp+48h] [xbp-1A8h] BYREF
  __int64 v99; // [xsp+1E0h] [xbp-10h]

  v94 = a1;
  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *a4;
  memset(v97, 0, sizeof(v97));
  v96 = 0;
  if ( v20 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Current channel num: %d",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "cm_update_roam_scan_channel_list",
      a1);
    cm_dump_freq_list(a4);
  }
  if ( (a7 & 1) != 0 )
  {
    v21 = *a4;
    if ( *a4 )
    {
      v22 = 0;
      do
      {
        v24 = *(_DWORD *)(*((_QWORD *)a4 + 1) + 4 * v22);
        if ( a6 )
        {
          v23 = a6;
          v25 = a5;
          v26 = a6;
          while ( 1 )
          {
            v27 = *v25++;
            if ( v24 == v27 )
              break;
            if ( !--v26 )
            {
              if ( a6 != 100 )
                goto LABEL_7;
              a6 = 100;
              goto LABEL_15;
            }
          }
        }
        else
        {
          v23 = 0;
LABEL_7:
          a5[v23] = v24;
          ++a6;
          v21 = *a4;
        }
        ++v22;
      }
      while ( v22 < v21 );
    }
  }
LABEL_15:
  v28 = *(_QWORD *)(a2 + 216);
  memset(s, 0, sizeof(s));
  v29 = (void *)_qdf_mem_malloc(0xE58u, "cm_remove_disabled_channels", 1336);
  if ( !v29 )
    goto LABEL_18;
  v30 = (__int64)v29;
  if ( (unsigned int)wlan_reg_get_current_chan_list(v28, v29) )
    goto LABEL_17;
  v40 = 0;
  v41 = 0;
  do
  {
    v42 = *(_DWORD *)(v30 + 36 * v40);
    channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                  v28,
                                  v42,
                                  0,
                                  v31,
                                  v32,
                                  v33,
                                  v34,
                                  v35,
                                  v36,
                                  v37,
                                  v38);
    if ( a6 )
    {
      v44 = a5;
      v45 = a6;
      if ( (channel_state_for_pwrmode & 0xFFFFFFFB) != 0 )
      {
        while ( 1 )
        {
          v46 = *v44++;
          if ( v42 == v46 )
            break;
          if ( !--v45 )
            goto LABEL_23;
        }
        if ( v41 >= 0x66 )
          goto LABEL_70;
        s[v41++] = v42;
      }
    }
LABEL_23:
    ++v40;
  }
  while ( v40 != 102 );
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: [ROAM_BAND]: num channel :%d",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "cm_remove_disabled_channels",
    v41);
  if ( !v41 )
  {
LABEL_17:
    _qdf_mem_free(v30);
    goto LABEL_18;
  }
  if ( v41 >= 3 )
  {
    v48 = v41 - 1LL;
    if ( v48 >= 0x66 )
      v48 = 102;
    v49 = v48 + 1;
    v50 = v49 & 1;
    if ( (v49 & 1) == 0 )
      v50 = 2;
    v51 = a5 + 1;
    v47 = v49 - v50;
    v52 = &s[1];
    v53 = v47;
    do
    {
      v54 = *(v52 - 1);
      v55 = *v52;
      v53 -= 2LL;
      v52 += 2;
      *(v51 - 1) = v54;
      *v51 = v55;
      v51 += 2;
    }
    while ( v53 );
  }
  else
  {
    v47 = 0;
  }
  do
  {
    if ( v47 == 102 )
      goto LABEL_70;
    if ( (v47 & 0x3FFFFFFFFFFFFFFFLL) == 0x66 )
    {
      __break(1u);
LABEL_70:
      __break(0x5512u);
    }
    a5[v47] = s[v47];
    ++v47;
  }
  while ( v41 != v47 );
  _qdf_mem_free(v30);
  if ( !(_BYTE)v41 )
  {
LABEL_18:
    result = 16;
    goto LABEL_19;
  }
  wlan_cm_roam_cfg_get_value(v94, a3, 0x1Bu, v97);
  ucfg_reg_get_band(*(_QWORD *)(a2 + 216), &v96, v56, v57, v58, v59, v60, v61, v62, v63);
  v72 = v97[0];
  if ( LODWORD(v97[0]) != v96 )
  {
    if ( (v97[0] & 1) == 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: disabling 2G",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "cm_modify_chan_list_based_on_band");
      v73 = (unsigned __int8)v41;
      v74 = (unsigned int *)a5;
      do
      {
        if ( wlan_reg_is_24ghz_ch_freq(*v74) )
          *v74 = 0;
        --v73;
        ++v74;
      }
      while ( v73 );
    }
    if ( (v72 & 2) == 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: disabling 5G",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "cm_modify_chan_list_based_on_band");
      v75 = (unsigned __int8)v41;
      v76 = (unsigned int *)a5;
      do
      {
        if ( wlan_reg_is_5ghz_ch_freq(*v76) )
          *v76 = 0;
        --v75;
        ++v76;
      }
      while ( v75 );
    }
    if ( (v72 & 4) != 0 )
    {
      v77 = (unsigned __int8)v41;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: disabling 6G",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "cm_modify_chan_list_based_on_band");
      v77 = (unsigned __int8)v41;
      v78 = a5;
      v79 = v77;
      do
      {
        if ( wlan_reg_is_6ghz_chan_freq(*v78) )
          *v78 = 0;
        --v79;
        ++v78;
      }
      while ( v79 );
    }
    LOBYTE(v41) = 0;
    v80 = a5;
    do
    {
      v82 = *v80++;
      v81 = v82;
      if ( v82 )
      {
        v83 = (unsigned __int8)v41;
        LOBYTE(v41) = v41 + 1;
        a5[v83] = v81;
      }
      --v77;
    }
    while ( v77 );
    if ( !(_BYTE)v41 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: No valid channels left to send to the fw",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "cm_update_roam_scan_channel_list");
      goto LABEL_18;
    }
  }
  cm_flush_roam_channel_list((__int64)a4);
  v84 = _qdf_mem_malloc(4LL * (unsigned __int8)v41, "cm_create_bg_scan_roam_channel_list", 1303);
  *((_QWORD *)a4 + 1) = v84;
  if ( v84 )
  {
    v93 = 0;
    *a4 = v41;
    do
    {
      *(_DWORD *)(*((_QWORD *)a4 + 1) + 4 * v93) = a5[v93];
      ++v93;
    }
    while ( (unsigned __int8)v41 != v93 );
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: New channel num: %d",
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    "cm_update_roam_scan_channel_list",
    (unsigned __int8)v41,
    v94);
  cm_dump_freq_list(a4);
  result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
