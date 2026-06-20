__int64 __fastcall wlan_hdd_get_peer_rx_rate_stats(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  const char *v23; // x3
  unsigned int v24; // w0
  unsigned int v25; // w1
  __int64 v26; // x5
  __int64 v27; // x22
  _QWORD *context; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int per_link_peer_stats; // w0
  unsigned int v38; // w8
  _QWORD *v39; // x22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  _DWORD *v49; // x8
  __int64 v50; // x1
  unsigned int v51; // w0

  result = ucfg_mlme_stats_is_link_speed_report_actual(**(_QWORD **)(*(_QWORD *)a1 + 24LL));
  if ( (result & 1) != 0 )
  {
    v3 = _qdf_mem_malloc(0x11C0u, "wlan_hdd_get_peer_rx_rate_stats", 10186);
    if ( !v3 )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: Failed to malloc peer_stats",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wlan_hdd_get_peer_rx_rate_stats");
    v12 = v3;
    v13 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         v13,
                         (__int64)"wlan_hdd_get_per_peer_stats",
                         v4,
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11) )
    {
      v22 = "%s: invalid hdd_ctx";
      v23 = "wlan_hdd_get_per_peer_stats";
      v24 = 51;
      v25 = 2;
LABEL_5:
      qdf_trace_msg(v24, v25, v22, v14, v15, v16, v17, v18, v19, v20, v21, v23);
LABEL_6:
      v26 = 16;
      goto LABEL_7;
    }
    context = _cds_get_context(71, (__int64)"wlan_hdd_get_per_peer_stats", v14, v15, v16, v17, v18, v19, v20, v21);
    if ( (*(_BYTE *)(v13 + 8238) & 1) != 0 )
    {
      per_link_peer_stats = ucfg_dp_get_per_link_peer_stats((__int64)context, v29, v30, v31, v32, v33, v34, v35, v36);
      v26 = per_link_peer_stats;
      if ( per_link_peer_stats )
        goto LABEL_7;
    }
    else
    {
      v39 = context;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: mlo per link stats is not supported by FW",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "wlan_hdd_is_per_link_stats_supported");
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: mlo per link stats is not supported by FW",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "wlan_hdd_get_per_peer_stats");
      if ( !v39 || !*v39 )
      {
        v22 = "%s: Invalid Instance";
        v23 = "cdp_host_get_peer_stats";
        v24 = 137;
        v25 = 8;
        goto LABEL_5;
      }
      v48 = *(_QWORD *)(*v39 + 32LL);
      if ( !v48 )
        goto LABEL_6;
      v49 = *(_DWORD **)(v48 + 144);
      if ( !v49 )
        goto LABEL_6;
      v50 = *(unsigned __int8 *)(a1 + 8);
      if ( *(v49 - 1) != -1642106733 )
        __break(0x8228u);
      v51 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))v49)(v39, v50, a1 + 308, v12);
      v26 = v51;
      if ( v51 )
        goto LABEL_7;
    }
    v38 = *(_DWORD *)(v12 + 4032);
    if ( v38 )
    {
      *(_DWORD *)(a1 + 2824) = v38 / 0x64;
      *(_DWORD *)(a1 + 2832) = (unsigned __int8)*(_DWORD *)(v12 + 4204) >> 4;
      *(_BYTE *)(a1 + 2809) = *(_BYTE *)(v12 + 4204) & 0xF;
      *(_DWORD *)(a1 + 2852) = (unsigned __int16)*(_DWORD *)(v12 + 4204) >> 12;
      *(_BYTE *)(a1 + 2811) = *(_BYTE *)(v12 + 4206) & 0xF;
      *(_BYTE *)(a1 + 2813) = *(_BYTE *)(v12 + 4205) & 0xF;
      return _qdf_mem_free(v12);
    }
    v26 = 0;
LABEL_7:
    v27 = jiffies;
    if ( wlan_hdd_get_peer_rx_rate_stats___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Failed to get rx rates, rx mcs=%d, status=%d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_hdd_get_peer_rx_rate_stats",
        *(unsigned int *)(a1 + 2832),
        v26);
      wlan_hdd_get_peer_rx_rate_stats___last_ticks = v27;
    }
    *(_BYTE *)(a1 + 2811) = -1;
    return _qdf_mem_free(v12);
  }
  return result;
}
