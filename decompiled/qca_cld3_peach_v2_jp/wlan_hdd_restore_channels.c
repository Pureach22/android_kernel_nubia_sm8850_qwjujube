__int64 __fastcall wlan_hdd_restore_channels(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 v19; // x23
  int v20; // w8
  __int64 v21; // x25
  __int64 wiphy_channel; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_restore_channels");
  if ( !a1 )
  {
    v31 = "%s: HDD Context is NULL";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v31, v10, v11, v12, v13, v14, v15, v16, v17, "wlan_hdd_restore_channels");
    return 4294967274LL;
  }
  v18 = a1[3];
  if ( !v18 )
  {
    v31 = "%s: Wiphy is NULL";
    goto LABEL_13;
  }
  qdf_mutex_acquire((__int64)(a1 + 453));
  v19 = a1[452];
  if ( v19 && *(_DWORD *)v19 )
  {
    v20 = 0;
    do
    {
      v21 = v20;
      if ( *(_DWORD *)(*(_QWORD *)(v19 + 8) + 12LL * v20) )
      {
        wiphy_channel = wlan_hdd_get_wiphy_channel(v18);
        if ( wiphy_channel )
        {
          *(_DWORD *)(wiphy_channel + 12) = *(_DWORD *)(*(_QWORD *)(v19 + 8) + 12 * v21 + 8);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Restore channel_freq %d reg_stat %d wiphy_stat 0x%x",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "wlan_hdd_restore_channels",
            *(unsigned int *)(*(_QWORD *)(v19 + 8) + 12 * v21),
            *(unsigned int *)(*(_QWORD *)(v19 + 8) + 12 * v21 + 4));
        }
      }
      v20 = v21 + 1;
    }
    while ( (unsigned int)(v21 + 1) < *(_DWORD *)v19 );
    qdf_mutex_release((__int64)(a1 + 453));
    ucfg_reg_restore_cached_channels(a1[1], v41, v42, v43, v44, v45, v46, v47, v48);
    if ( (unsigned int)sme_update_channel_list(a1[2]) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Can't Restore channel list",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "wlan_hdd_restore_channels");
    else
      wlan_hdd_free_cache_channels(a1);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v57, v58, v59, v60, v61, v62, v63, v64, "wlan_hdd_restore_channels");
    return 0;
  }
  else
  {
    qdf_mutex_release((__int64)(a1 + 453));
    qdf_trace_msg(0x33u, 8u, "channel list is NULL or num channels are zero", v32, v33, v34, v35, v36, v37, v38, v39);
    return 4294967274LL;
  }
}
