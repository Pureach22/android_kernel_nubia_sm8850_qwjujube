__int64 __fastcall wlan_hdd_set_channel(
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
        unsigned int *a12,
        unsigned int a13)
{
  const char *v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 *v26; // x22
  __int64 result; // x0
  __int64 v28; // x19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w0
  unsigned int v38; // w4
  const char *v39; // x2
  unsigned int v40; // w0
  unsigned int v41; // w4
  char v42; // w23
  __int64 v43; // x8
  char v44; // w0
  int v45; // w9
  __int64 v46; // x0
  __int64 v47; // x20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  int v57; // w8

  if ( a11 )
  {
    qdf_mtrace(51, 51, 0x26u, *(_BYTE *)(a1 + 8), a13);
    v17 = qdf_opmode_str(*(_DWORD *)(a11 + 2728));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Dev_mode %s(%d) freq %d, ch_bw %d ccfs1 %d ccfs2 %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_hdd_set_channel",
      v17,
      *(unsigned int *)(a11 + 2728),
      *(unsigned int *)(*(_QWORD *)a12 + 4LL),
      a12[2],
      a12[3],
      a12[4]);
    v26 = *(__int64 **)(a11 + 2712);
    result = _wlan_hdd_validate_context(v26, "wlan_hdd_set_channel");
    if ( !(_DWORD)result )
    {
      v28 = v26[2];
      if ( (unsigned int)wlan_reg_min_chan_freq() > *(_DWORD *)(*(_QWORD *)a12 + 4LL)
        || (v37 = wlan_reg_max_chan_freq(), v38 = *(_DWORD *)(*(_QWORD *)a12 + 4LL), v37 < v38) )
      {
        v39 = "%s: channel: %d is outside valid freq range";
LABEL_6:
        qdf_trace_msg(0x33u, 2u, v39, v29, v30, v31, v32, v33, v34, v35, v36, "wlan_hdd_set_channel");
        return 4294967274LL;
      }
      if ( a12[2] == 4 )
      {
        if ( (unsigned int)wlan_reg_min_chan_freq() > a12[4]
          || (v40 = wlan_reg_max_chan_freq(), v41 = a12[4], v40 < v41) )
        {
          v39 = "%s: center_freq2: %d is outside valid freq range";
          goto LABEL_6;
        }
        v42 = ieee80211_freq_khz_to_channel(1000 * v41);
        v38 = *(_DWORD *)(*(_QWORD *)a12 + 4LL);
      }
      else
      {
        v42 = 0;
      }
      if ( (unsigned int)wlan_hdd_validate_operation_channel(v26, v38) )
      {
        v39 = "%s: Invalid freq: %d";
        goto LABEL_6;
      }
      *(_DWORD *)(a1 + 720) = *(_DWORD *)(*(_QWORD *)a12 + 4LL);
      v43 = a1;
      if ( a12[2] == 4 )
      {
        *(_BYTE *)(a1 + 734) = v42;
        v44 = ieee80211_freq_khz_to_channel(1000 * a12[3]);
        v43 = a1;
      }
      else
      {
        v44 = 0;
        *(_DWORD *)(a1 + 740) = a12[3];
      }
      *(_BYTE *)(v43 + 733) = v44;
      if ( *(_DWORD *)(a11 + 2728) != 1 )
        return 0;
      v45 = *(_DWORD *)(*(_QWORD *)a12 + 4LL);
      *(_BYTE *)(v43 + 734) = v42;
      *(_DWORD *)(v43 + 720) = v45;
      v46 = _qdf_mem_malloc(0x4E4u, "wlan_hdd_set_channel", 5423);
      if ( !v46 )
        return 4294967284LL;
      v47 = v46;
      sme_get_config_param(v28, v46);
      if ( a13 < 2 )
      {
        v57 = 0;
        v56 = a1;
        *(_BYTE *)(v47 + 1235) = 0;
        goto LABEL_29;
      }
      v56 = a1;
      if ( a13 == 2 )
      {
        v57 = *(_DWORD *)(a1 + 720) - 20;
        goto LABEL_29;
      }
      if ( a13 == 3 )
      {
        v57 = *(_DWORD *)(a1 + 720) + 20;
LABEL_29:
        *(_DWORD *)(v56 + 724) = v57;
        *(_BYTE *)(v47 + 1235) = wlan_hdd_get_sap_obss() & 1;
        sme_update_config(v28, v47);
        _qdf_mem_free(v47);
        return 0;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Error!!! Invalid HT20/40 mode !",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wlan_hdd_set_channel");
      _qdf_mem_free(v47);
      return 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Called with dev = NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_set_channel");
    return 4294967277LL;
  }
  return result;
}
