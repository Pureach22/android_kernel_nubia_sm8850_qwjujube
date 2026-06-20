__int64 __fastcall wlan_hdd_init_chan_info(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int *v20; // x8
  __int64 i; // x9
  int v22; // t1
  _DWORD *v23; // x8
  __int64 v24; // x8
  _DWORD *v25; // x8
  __int64 j; // x9
  int v27; // w11
  __int64 v28; // x4

  v2 = *a1;
  a1[217] = 0;
  if ( (wlan_scan_is_snr_monitor_enabled(v2) & 1) == 0 )
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: SNR monitoring is disabled",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "wlan_hdd_init_chan_info");
  result = _qdf_mem_malloc(0x27D8u, "wlan_hdd_init_chan_info", 33352);
  a1[217] = result;
  if ( result )
  {
    _mutex_init(a1 + 218, "&hdd_ctx->chan_info_lock", &wlan_hdd_init_chan_info___key);
    *(_DWORD *)a1[217] = 2412;
    *(_DWORD *)(a1[217] + 100) = 2417;
    *(_DWORD *)(a1[217] + 200) = 2422;
    *(_DWORD *)(a1[217] + 300) = 2427;
    *(_DWORD *)(a1[217] + 400) = 2432;
    *(_DWORD *)(a1[217] + 500) = 2437;
    *(_DWORD *)(a1[217] + 600) = 2442;
    *(_DWORD *)(a1[217] + 700) = 2447;
    *(_DWORD *)(a1[217] + 800) = 2452;
    *(_DWORD *)(a1[217] + 900) = 2457;
    *(_DWORD *)(a1[217] + 1000) = 2462;
    *(_DWORD *)(a1[217] + 1100) = 2467;
    *(_DWORD *)(a1[217] + 1200) = 2472;
    *(_DWORD *)(a1[217] + 1300) = 2484;
    v20 = (int *)&unk_A04C6C;
    for ( i = 1400; i != 3900; i += 100 )
    {
      v22 = *v20;
      v20 += 16;
      *(_DWORD *)(a1[217] + i) = v22;
    }
    v23 = (_DWORD *)a1[217];
    v23[975] = 5845;
    v23[1000] = 5865;
    v23[1025] = 5885;
    v24 = *(_QWORD *)(a1[3] + 352);
    if ( v24 && *(_DWORD *)(v24 + 20) )
    {
      v25 = (_DWORD *)(a1[217] + 4200);
      for ( j = 4; j != 3844; j += 64 )
      {
        v27 = *(_DWORD *)((char *)&hdd_channels_6_ghz + j);
        *v25 = v27;
        v25 += 25;
      }
      v28 = 102;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: 6GHz channel list not populated to wiphy",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_hdd_populate_6g_chan_info");
      v28 = 42;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Number of channels populated : %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_init_chan_info",
      v28);
    return sme_set_chan_info_callback(a1[2], wlan_hdd_chan_info_cb);
  }
  return result;
}
