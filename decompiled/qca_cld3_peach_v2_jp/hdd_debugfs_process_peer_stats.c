__int64 __fastcall hdd_debugfs_process_peer_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _DWORD *a10)
{
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w0
  __int64 v21; // x28
  _DWORD *v22; // x11
  int v23; // w25
  unsigned int *v24; // x24
  _DWORD *v25; // x8
  _DWORD *v26; // x19
  __int64 v27; // x21
  int v28; // w3
  int v29; // w4
  int v30; // w5
  int v31; // w6
  int v32; // w7
  __int64 v33; // x27
  int v34; // w0
  _DWORD *v35; // x24
  __int64 v36; // x21
  int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  unsigned int v47; // w1
  _DWORD *v49; // [xsp+38h] [xbp-8h]

  qdf_trace_msg(0x33u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_debugfs_process_peer_stats");
  mutex_lock(&llstats_mutex);
  if ( ll_stats_1 )
  {
    v11 = ll_stats_1 + ll_stats_0;
    v12 = scnprintf(ll_stats_1 + ll_stats_0, 0x4000 - ll_stats_0, "\n\n===LL_STATS_PEER_ALL : num_peers %u===", *a10);
    v21 = v20;
    v22 = a10 + 1;
    if ( *a10 )
    {
      v23 = 1;
      v24 = a10 + 1;
      v49 = a10;
      do
      {
        v26 = v22;
        v27 = ll_stats_0 + v21;
        ll_stats_0 += v21;
        v28 = wmi_to_sir_peer_type(*v24, v12, v13, v14, v15, v16, v17, v18, v19);
        if ( v24 == (unsigned int *)-4LL )
        {
          v31 = 0;
          v29 = 0;
          v30 = 0;
          v32 = 0;
        }
        else
        {
          v29 = *((unsigned __int8 *)v24 + 4);
          v30 = *((unsigned __int8 *)v24 + 5);
          v31 = *((unsigned __int8 *)v24 + 6);
          v32 = *((unsigned __int8 *)v24 + 9);
        }
        v11 += v21;
        v12 = scnprintf(
                v11,
                0x4000 - v27,
                "\nType: %d, peer_mac: %02x:%02x:%02x:**:**:%02x, capabilities: %u\nnum_rates: %d",
                v28,
                v29,
                v30,
                v31,
                v32,
                v24[3],
                v24[4]);
        v33 = v24[4];
        v21 = v34;
        if ( (int)v33 >= 1 )
        {
          v35 = v24 + 6;
          v36 = v33;
          do
          {
            v11 += v21;
            ll_stats_0 += v21;
            v12 = scnprintf(
                    v11,
                    0x4000 - ll_stats_0,
                    "\n"
                    "preamble: %0x, nss: %0x, bw: %0x, mcs: %0x, bitrate: %0x, txmpdu: %u, rxmpdu: %u, mpdu_lost: %u, ret"
                    "ries: %u, retries_short: %u, retries_long: %u",
                    *(v35 - 1) & 7,
                    (*(v35 - 1) >> 3) & 3,
                    (unsigned __int8)*(v35 - 1) >> 5,
                    (unsigned __int8)BYTE1(*(v35 - 1)),
                    *v35,
                    v35[1],
                    v35[2],
                    v35[3],
                    v35[4],
                    v35[5],
                    v35[6]);
            v21 = v37;
            --v36;
            v35 += 8;
          }
          while ( v36 );
        }
        v22 = v26;
        v25 = &v26[5 * v23++];
        v24 = &v25[8 * (int)v33];
      }
      while ( (unsigned int)v23 <= *v49 );
    }
    ll_stats_0 += v21;
    mutex_unlock(&llstats_mutex);
    v46 = "%s: exit";
    v47 = 8;
  }
  else
  {
    mutex_unlock(&llstats_mutex);
    v46 = "%s: LL statistics buffer is NULL";
    v47 = 2;
  }
  return qdf_trace_msg(0x33u, v47, v46, v38, v39, v40, v41, v42, v43, v44, v45, "hdd_debugfs_process_peer_stats");
}
