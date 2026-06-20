__int64 __fastcall wlan_hdd_disable_channels(
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
  _QWORD *v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x25
  int v28; // w8
  __int64 v29; // x27
  unsigned int v30; // w24
  unsigned __int64 wiphy_channel; // x0
  unsigned __int64 v32; // x23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int updated; // w19
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_disable_channels");
  if ( !a1 )
  {
    v41 = "%s: HDD Context is NULL";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v41, v10, v11, v12, v13, v14, v15, v16, v17, "wlan_hdd_disable_channels");
    return 4294967274LL;
  }
  v18 = (_QWORD *)a1[3];
  if ( !v18 )
  {
    v41 = "%s: Wiphy is NULL";
    goto LABEL_13;
  }
  qdf_mutex_acquire((__int64)(a1 + 453));
  v27 = a1[452];
  if ( !v27 || !*(_DWORD *)v27 )
  {
    qdf_mutex_release((__int64)(a1 + 453));
    v41 = "%s: channel list is NULL or num channels are zero";
    goto LABEL_13;
  }
  v28 = 0;
  do
  {
    v29 = v28;
    v30 = *(_DWORD *)(*(_QWORD *)(v27 + 8) + 12LL * v28);
    if ( v30 )
    {
      wiphy_channel = wlan_hdd_get_wiphy_channel(v18, v30, v19, v20, v21, v22, v23, v24, v25, v26);
      if ( wiphy_channel )
      {
        v32 = wiphy_channel;
        *(_DWORD *)(*(_QWORD *)(v27 + 8) + 12 * v29 + 4) = wlan_reg_get_channel_state_from_secondary_list_for_freq(
                                                             a1[1],
                                                             v30,
                                                             v19,
                                                             v20,
                                                             v21,
                                                             v22,
                                                             v23,
                                                             v24,
                                                             v25,
                                                             v26);
        *(_DWORD *)(*(_QWORD *)(v27 + 8) + 12 * v29 + 8) = *(_DWORD *)(v32 + 12);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Disable channel_freq %d reg_stat %d wiphy_stat 0x%x",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "wlan_hdd_disable_channels",
          *(unsigned int *)(*(_QWORD *)(v27 + 8) + 12 * v29),
          *(unsigned int *)(*(_QWORD *)(v27 + 8) + 12 * v29 + 4));
        *(_DWORD *)(v32 + 12) |= 1u;
      }
    }
    v28 = v29 + 1;
  }
  while ( (unsigned int)(v29 + 1) < *(_DWORD *)v27 );
  qdf_mutex_release((__int64)(a1 + 453));
  ucfg_reg_disable_cached_channels(a1[1], v43, v44, v45, v46, v47, v48, v49, v50);
  updated = sme_update_channel_list(a1[2]);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v52, v53, v54, v55, v56, v57, v58, v59, "wlan_hdd_disable_channels");
  return updated;
}
