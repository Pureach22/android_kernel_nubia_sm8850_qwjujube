__int64 __fastcall drv_cmd_set_disable_chan_list(
        __int64 *a1,
        int a2,
        char *s,
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
  __int64 *v12; // x19
  size_t v14; // x0
  const char *v15; // x0
  int v16; // w8
  int v17; // t1
  const char *v18; // x23
  const char *v19; // x2
  unsigned int v20; // w1
  __int64 result; // x0
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
  signed int *v38; // x28
  signed int v39; // w21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w9
  int v49; // w8
  __int64 v50; // x0
  __int64 v51; // x20
  __int64 v52; // x22
  char *v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w8
  int v63; // t1
  __int64 v64; // x24
  unsigned int v65; // w27
  unsigned __int8 v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x5
  unsigned int v76; // w0
  char *v77; // x0
  const char *v78; // x2
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 i; // x8
  int *v88; // x13
  __int64 v89; // x14
  int v90; // t1
  __int64 v91; // x8
  int *v92; // x10
  int v93; // t1
  unsigned int v94; // w19
  unsigned int v95; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v96; // [xsp+8h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a1;
  v95 = 0;
  v12 = *(__int64 **)(v11 + 24);
  if ( !v12 )
  {
    v19 = "%s: HDD Context is NULL";
    goto LABEL_10;
  }
  v14 = strlen(s);
  v15 = (const char *)strnchr(s, v14, 32);
  if ( !v15 || *v15 != 32 )
    goto LABEL_12;
  do
  {
    v17 = *(unsigned __int8 *)++v15;
    v16 = v17;
  }
  while ( v17 == 32 );
  if ( !v16 )
    goto LABEL_12;
  v18 = v15;
  if ( sscanf(v15, "%d ", &v95) != 1 )
  {
    v19 = "%s: Cannot get number of channels from input";
    goto LABEL_10;
  }
  if ( v95 >= 0x67 )
  {
    v19 = "%s: Invalid Number of channel received";
LABEL_10:
    v20 = 2;
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Number of channel to disable are: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "hdd_parse_disable_chan_cmd");
  if ( !v95 )
  {
    wlan_hdd_restore_channels(v12, v22, v23, v24, v25, v26, v27, v28, v29);
    result = 0;
    goto LABEL_13;
  }
  qdf_mutex_acquire((__int64)(v12 + 453));
  v38 = (signed int *)v12[452];
  if ( v38 )
  {
    v39 = *v38;
    if ( *v38 != v95 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid Number of channels",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_parse_disable_chan_cmd");
      goto LABEL_49;
    }
  }
  else
  {
    if ( (unsigned int)hdd_alloc_chan_cache(v12, v95) )
    {
      qdf_mutex_release((__int64)(v12 + 453));
      v48 = -12;
LABEL_22:
      v49 = v48;
      if ( v12[452] )
      {
        result = wlan_hdd_disable_channels(v12, v40, v41, v42, v43, v44, v45, v46, v47);
        if ( (_DWORD)result )
          goto LABEL_13;
        disconnect_sta_and_restart_sap(v12);
        v49 = 0;
      }
LABEL_66:
      v94 = v49;
      qdf_trace_msg(0x33u, 8u, "%s: exit", v40, v41, v42, v43, v44, v45, v46, v47, "hdd_parse_disable_chan_cmd");
      result = v94;
      goto LABEL_13;
    }
    v39 = v95;
  }
  v50 = _qdf_mem_malloc(4LL * v39, "hdd_parse_disable_chan_cmd", 6979);
  if ( !v50 )
  {
    result = 4294967284LL;
    goto LABEL_13;
  }
  v51 = v50;
  if ( v39 < 1 )
  {
LABEL_41:
    v77 = strchr(v18, 32);
    if ( v77 )
    {
      while ( *v77 == 32 )
        ++v77;
      if ( *v77 )
      {
        v78 = "%s: Invalid argument received";
        goto LABEL_46;
      }
    }
    if ( v38 )
    {
      if ( v39 >= 1 )
      {
        for ( i = 0; i != v39; ++i )
        {
          v88 = (int *)v51;
          v89 = (unsigned int)v39;
          while ( 1 )
          {
            v90 = *v88++;
            if ( *(_DWORD *)(*(_QWORD *)(v12[452] + 8) + 12 * i) == v90 )
              break;
            if ( !--v89 )
              goto LABEL_48;
          }
        }
      }
    }
    else
    {
      if ( v39 >= 1 )
      {
        v91 = 0;
        v92 = (int *)v51;
        do
        {
          v93 = *v92++;
          *(_DWORD *)(*(_QWORD *)(v12[452] + 8) + v91) = v93;
          v91 += 12;
        }
        while ( 12LL * (unsigned int)v39 != v91 );
      }
      ucfg_reg_cache_channel_freq_state(v12[1], v51, v39, v54, v55, v56, v57, v58, v59, v60, v61);
    }
    _qdf_mem_free(v51);
    qdf_mutex_release((__int64)(v12 + 453));
    v48 = 0;
    v49 = 0;
    if ( v38 )
      goto LABEL_66;
    goto LABEL_22;
  }
  v52 = 0;
  while ( 1 )
  {
    v53 = strchr(v18, 32);
    if ( !v53 )
    {
      v78 = "%s: Invalid No of channel provided in the list";
      goto LABEL_46;
    }
    do
    {
      v63 = (unsigned __int8)*++v53;
      v62 = v63;
    }
    while ( v63 == 32 );
    if ( !v62 )
    {
      v78 = "%s: No channel is provided in the list";
      goto LABEL_46;
    }
    v18 = v53;
    if ( sscanf(v53, "%d ", &v95) != 1 )
    {
      v78 = "%s: Cannot read channel number";
      goto LABEL_46;
    }
    v64 = v12[1];
    if ( v95 < 0xF || v95 - 36 <= 0x94 )
    {
      v76 = wlan_reg_legacy_chan_to_freq(v12[1], v95, v54, v55, v56, v57, v58, v59, v60, v61);
      v75 = v95;
      v65 = v76;
      goto LABEL_40;
    }
    if ( !wlan_reg_is_24ghz_ch_freq(v95) && !wlan_reg_is_5ghz_ch_freq(v95) && !wlan_reg_is_6ghz_chan_freq(v95) )
      break;
    v65 = v95;
    v66 = wlan_reg_freq_to_chan(v64, v95, v54, v55, v56, v57, v58, v59, v60, v61);
    v75 = v66;
    v95 = v66;
LABEL_40:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: channel[%d] = %d Frequency[%d] = %d",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "hdd_parse_disable_chan_cmd",
      (unsigned int)v52,
      v75,
      (unsigned int)v52,
      v65);
    *(_DWORD *)(v51 + 4 * v52++) = v65;
    if ( v52 == v39 )
      goto LABEL_41;
  }
  v78 = "%s: Invalid channel number received";
LABEL_46:
  qdf_trace_msg(0x33u, 2u, v78, v54, v55, v56, v57, v58, v59, v60, v61, "hdd_parse_disable_chan_cmd");
  if ( !v38 )
    wlan_hdd_free_cache_channels((__int64)v12, v79, v80, v81, v82, v83, v84, v85, v86);
LABEL_48:
  _qdf_mem_free(v51);
LABEL_49:
  qdf_mutex_release((__int64)(v12 + 453));
  v19 = "%s: exit";
  v20 = 8;
LABEL_11:
  qdf_trace_msg(0x33u, v20, v19, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_parse_disable_chan_cmd");
LABEL_12:
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
