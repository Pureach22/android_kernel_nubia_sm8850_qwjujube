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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  const char *v22; // x3
  unsigned int v23; // w0
  unsigned int v24; // w1
  _QWORD *context; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  _DWORD *v35; // x8
  __int64 v36; // x1
  unsigned int v37; // w0
  unsigned int v38; // w8
  __int64 v39; // x5
  __int64 v40; // x22

  result = ucfg_mlme_stats_is_link_speed_report_actual(**(_QWORD **)(*(_QWORD *)a1 + 24LL));
  if ( (result & 1) != 0 )
  {
    v3 = _qdf_mem_malloc(0xE90u, "wlan_hdd_get_peer_rx_rate_stats", 10186);
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
    if ( (unsigned int)_wlan_hdd_validate_context(
                         *(_QWORD *)(*(_QWORD *)a1 + 24LL),
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
      v21 = "%s: invalid hdd_ctx";
      v22 = "wlan_hdd_get_per_peer_stats";
      v23 = 51;
      v24 = 2;
    }
    else
    {
      context = _cds_get_context(71, (__int64)"wlan_hdd_get_per_peer_stats", v13, v14, v15, v16, v17, v18, v19, v20);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: mlo per link stats is not supported by FW",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_hdd_get_per_peer_stats");
      if ( context && *context )
      {
        v34 = *(_QWORD *)(*context + 32LL);
        if ( v34 )
        {
          v35 = *(_DWORD **)(v34 + 144);
          if ( v35 )
          {
            v36 = *(unsigned __int8 *)(a1 + 8);
            if ( *(v35 - 1) != -1642106733 )
              __break(0x8228u);
            v37 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))v35)(context, v36, a1 + 300, v12);
            if ( v37 )
            {
              v39 = v37;
            }
            else
            {
              v38 = *(_DWORD *)(v12 + 3452);
              if ( v38 )
              {
                *(_DWORD *)(a1 + 2552) = v38 / 0x64;
                *(_DWORD *)(a1 + 2560) = (unsigned __int8)*(_DWORD *)(v12 + 3612) >> 4;
                *(_BYTE *)(a1 + 2537) = *(_BYTE *)(v12 + 3612) & 0xF;
                *(_DWORD *)(a1 + 2580) = (unsigned __int16)*(_DWORD *)(v12 + 3612) >> 12;
                *(_BYTE *)(a1 + 2539) = *(_BYTE *)(v12 + 3614) & 0xF;
                *(_BYTE *)(a1 + 2541) = *(_BYTE *)(v12 + 3613) & 0xF;
                return _qdf_mem_free(v12);
              }
              v39 = 0;
            }
LABEL_18:
            v40 = jiffies;
            if ( wlan_hdd_get_peer_rx_rate_stats___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Failed to get rx rates, rx mcs=%d, status=%d",
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                "wlan_hdd_get_peer_rx_rate_stats",
                *(unsigned int *)(a1 + 2560),
                v39);
              wlan_hdd_get_peer_rx_rate_stats___last_ticks = v40;
            }
            *(_BYTE *)(a1 + 2539) = -1;
            return _qdf_mem_free(v12);
          }
        }
LABEL_17:
        v39 = 16;
        goto LABEL_18;
      }
      v21 = "%s: Invalid Instance";
      v22 = "cdp_host_get_peer_stats";
      v23 = 137;
      v24 = 8;
    }
    qdf_trace_msg(v23, v24, v21, v13, v14, v15, v16, v17, v18, v19, v20, v22);
    goto LABEL_17;
  }
  return result;
}
