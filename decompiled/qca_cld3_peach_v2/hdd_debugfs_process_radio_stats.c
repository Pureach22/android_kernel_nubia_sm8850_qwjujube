__int64 __fastcall hdd_debugfs_process_radio_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        int a12)
{
  __int64 v15; // x27
  int v16; // w0
  __int64 v17; // x8
  int v18; // w22
  int v19; // w17
  __int64 v20; // x27
  int v21; // w5
  int v22; // w6
  int v23; // w0
  __int64 v24; // x8
  unsigned int v25; // w19
  __int64 v26; // x10
  int v27; // w0
  int v28; // w3
  __int64 v29; // x1
  int v30; // w0
  unsigned int v31; // w25
  _DWORD *v32; // x19
  int v33; // w0
  __int64 v34; // x9
  int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  unsigned int v45; // w1
  int v47; // [xsp+4Ch] [xbp-4h]

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_debugfs_process_radio_stats");
  mutex_lock(&llstats_mutex);
  if ( ll_stats_1 )
  {
    v15 = ll_stats_1 + ll_stats_0;
    scnprintf(ll_stats_1 + ll_stats_0, 0x8000 - ll_stats_0, "\n\n===LL_STATS_RADIO: number of radios: %u===", a12);
    v17 = v16;
    if ( a12 )
    {
      v18 = 0;
      v47 = a12;
      do
      {
        v19 = *(_DWORD *)(a11 + 48);
        v20 = v15 + v17;
        v21 = *(_DWORD *)(a11 + 8);
        v22 = *(_DWORD *)(a11 + 12);
        ll_stats_0 += v17;
        scnprintf(
          v20,
          0x8000 - ll_stats_0,
          "\n"
          "Radio: %u on_time: %u, tx_time: %u, rx_time: %u, on_time_scan: %u, on_time_nbd: %u, on_time_gscan: %u, on_time"
          "_roam_scan: %u, on_time_pno_scan: %u  on_time_hs20: %u, on_time_host_scan: %u, on_time_lpi_scan: %u\n"
          "total_num_tx_pwr_levels: %u\n",
          *(_DWORD *)a11,
          *(_DWORD *)(a11 + 4),
          v21,
          v22,
          *(_DWORD *)(a11 + 16),
          *(_DWORD *)(a11 + 20),
          *(_DWORD *)(a11 + 24),
          *(_DWORD *)(a11 + 28),
          *(_DWORD *)(a11 + 32),
          *(_DWORD *)(a11 + 36),
          *(_DWORD *)(a11 + 40),
          *(_DWORD *)(a11 + 44),
          v19);
        v24 = v23;
        if ( *(_DWORD *)(a11 + 48) )
        {
          v25 = 0;
          do
          {
            v26 = *(_QWORD *)(a11 + 56);
            v20 += v24;
            ll_stats_0 += v24;
            scnprintf(v20, 0x8000 - ll_stats_0, "%d ", *(_DWORD *)(v26 + 4LL * (int)v25++));
            v24 = v27;
          }
          while ( v25 < *(_DWORD *)(a11 + 48) );
        }
        v28 = *(_DWORD *)(a11 + 68);
        v15 = v20 + v24;
        v29 = 0x8000 - (ll_stats_0 + v24);
        ll_stats_0 += v24;
        scnprintf(v15, v29, "\nNum channels: %d", v28);
        v17 = v30;
        if ( *(_DWORD *)(a11 + 68) )
        {
          v31 = 0;
          do
          {
            v15 += v17;
            v32 = (_DWORD *)(*(_QWORD *)(a11 + 72) + 32LL * (int)v31);
            ll_stats_0 += v17;
            scnprintf(
              v15,
              0x8000 - ll_stats_0,
              "\nChan width: %u, center_freq: %u, center_freq0: %u, center_freq1: %u, on_time: %u, cca_busy_time: %u",
              *v32,
              v32[1],
              v32[2],
              v32[3],
              v32[4],
              v32[5]);
            v34 = *(_QWORD *)(a1 + 24);
            v17 = v33;
            if ( v34 && *(_BYTE *)(v34 + 6944) == 1 )
            {
              v15 += v33;
              ll_stats_0 += v33;
              scnprintf(v15, 0x8000 - ll_stats_0, ", tx_time: %u, rx_time: %u", v32[6], v32[7]);
              v17 = v35;
            }
            ++v31;
          }
          while ( v31 < *(_DWORD *)(a11 + 68) );
        }
        ++v18;
        a11 += 80;
      }
      while ( v18 != v47 );
    }
    ll_stats_0 += v17;
    mutex_unlock(&llstats_mutex);
    v44 = "%s: exit";
    v45 = 8;
  }
  else
  {
    mutex_unlock(&llstats_mutex);
    v44 = "%s: LL statistics buffer is NULL";
    v45 = 2;
  }
  return qdf_trace_msg(0x33u, v45, v44, v36, v37, v38, v39, v40, v41, v42, v43, "hdd_debugfs_process_radio_stats");
}
