__int64 __fastcall dfs_process_radar_ind_on_home_chan(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int16 *v10; // x22
  unsigned __int16 v11; // w8
  __int64 v14; // x12
  _BOOL4 v15; // w10
  _BOOL4 v16; // w9
  _BOOL4 v17; // w10
  _BOOL4 v18; // w11
  bool v19; // zf
  int v20; // w12
  _BOOL4 v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w20
  int v31; // w23
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  unsigned int v41; // w1
  unsigned __int8 v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  char radar_affected_channels; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w8
  __int64 result; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w19
  __int64 v71; // x9
  char v72; // w8
  unsigned int v73; // w21
  __int64 v74; // x24
  unsigned int multiplier; // w22
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  int v92; // w8
  int v93; // w9
  unsigned int v94; // [xsp+0h] [xbp-50h] BYREF
  _BYTE v95[4]; // [xsp+4h] [xbp-4Ch] BYREF
  _QWORD v96[4]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v97[5]; // [xsp+28h] [xbp-28h] BYREF

  v97[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int16 **)(a1 + 14888);
  memset(v97, 0, 32);
  memset(v96, 0, sizeof(v96));
  if ( !v10 )
  {
    v40 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs->dfs_curchan is NULL";
    v41 = 2;
LABEL_32:
    qdf_trace_msg(0x27u, v41, v40, a3, a4, a5, a6, a7, a8, a9, a10, "dfs_radar_found_event_basic_sanity");
    result = 16;
    goto LABEL_45;
  }
  v11 = v10[8];
  if ( (v11 & 0xA) != 2 )
  {
    v14 = *((_QWORD *)v10 + 1);
    v15 = (~v14 & 0x4000100) == 0;
    if ( (~v14 & 0x8000100) == 0 )
      v15 = 1;
    if ( (~v14 & 0x400000100LL) == 0 )
      v15 = 1;
    if ( (~v14 & 0x1400000000LL) == 0 )
      v15 = 1;
    if ( (~v14 & 0x800000100LL) == 0 )
      v15 = 1;
    if ( (~v14 & 0x1800000000LL) == 0 )
      v15 = 1;
    v16 = (~v14 & 0x10000000100LL) == 0 || v15;
    v17 = (~v14 & 0x11000000000LL) == 0;
    v18 = (~v14 & 0x20000000100LL) == 0;
    v19 = (~v14 & 0x21000000000LL) == 0;
    v20 = v11 & 0xC;
    v21 = v19;
    if ( v20 != 4 || !v21 && !v18 && !v17 && !v16 )
    {
      v40 = "WLAN_DEBUG_DFS_ALWAYS : %s: radar event on non-DFS chan";
      v41 = 8;
      goto LABEL_32;
    }
  }
  v94 = 0;
  dfs_compute_radar_found_cfreq(a1, a2, &v94, a3, a4, a5, a6, a7, a8, a9, a10);
  v30 = v94;
  v31 = a2[2];
  if ( a2[5] == 1 )
  {
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: Radar found on second segment.Radarfound Freq=%d MHz.Secondary Chan cfreq=%d MHz.",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dfs_process_radar_ind_on_home_chan",
      v31 + v94,
      v94);
  }
  else
  {
    v42 = utils_dfs_freq_to_chan(v31 + v94);
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: Radar found on channel=%d, freq=%d MHz. Primary beaconning chan:%d, freq=%d MHz.",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "dfs_process_radar_ind_on_home_chan",
      v42,
      (unsigned int)(v31 + v30),
      *((unsigned __int8 *)v10 + 18),
      *v10);
  }
  radar_affected_channels = dfs_find_radar_affected_channels(
                              a1,
                              (__int64)a2,
                              v97,
                              v30,
                              v32,
                              v33,
                              v34,
                              v35,
                              v36,
                              v37,
                              v38,
                              v39);
  v60 = *(_DWORD *)(a1 + 14960);
  v95[0] = radar_affected_channels;
  *(_DWORD *)(a1 + 224) = 0;
  if ( !v60 )
  {
    v71 = *(_QWORD *)(a1 + 14888);
    *(_BYTE *)(a1 + 152) |= 4u;
    v72 = *(_BYTE *)(v71 + 18);
    *(_DWORD *)(a1 + 160) = 1;
    *(_BYTE *)(a1 + 153) = v72;
    timer_delete_sync(a1 + 168);
    v73 = *(_DWORD *)(a1 + 160);
    v74 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    *(_QWORD *)(a1 + 184) = v74 + _msecs_to_jiffies(v73) * multiplier;
    add_timer(a1 + 168);
LABEL_44:
    utils_dfs_deliver_event(*(_QWORD *)(a1 + 14936), (unsigned int)(v31 + v30), 0);
    result = 0;
    goto LABEL_45;
  }
  result = dfs_radar_add_channel_list_to_nol_for_freq(
             a1,
             (__int64)v97,
             (__int64)v96,
             v95,
             v52,
             v53,
             v54,
             v55,
             v56,
             v57,
             v58,
             v59);
  if ( !(_DWORD)result )
  {
    dfs_mlme_set_tx_flag(*(_QWORD *)(a1 + 14936), 0);
    if ( a1 )
    {
      if ( (*(_BYTE *)(a1 + 1) & 1) == 0
        || (qdf_trace_msg(
              0x27u,
              8u,
              "WLAN_DEBUG_DFS : %s: found_on_second=%d is_pre=%d",
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              "dfs_process_radar_ind_on_home_chan",
              *(unsigned __int8 *)(a1 + 228),
              0),
            (*(_BYTE *)(a1 + 1) & 1) == 0) )
      {
LABEL_39:
        if ( (*(_BYTE *)(a1 + 14954) & 1) == 0
          && *(_BYTE *)(a1 + 228) == 1
          && (v92 = *(_DWORD *)(a1 + 8),
              v93 = *(unsigned __int8 *)(a1 + 229),
              *(_BYTE *)(a1 + 228) = 0,
              *(_DWORD *)(a1 + 8) = v92 & 0xDFFFFFFF,
              v93 == 1) )
        {
          *(_BYTE *)(a1 + 229) = 0;
        }
        else
        {
          dfs_mlme_mark_dfs(
            *(_QWORD *)(a1 + 14936),
            *(unsigned __int8 *)(*(_QWORD *)(a1 + 14888) + 18LL),
            **(unsigned __int16 **)(a1 + 14888),
            *(unsigned __int16 *)(*(_QWORD *)(a1 + 14888) + 24LL),
            *(_QWORD *)(*(_QWORD *)(a1 + 14888) + 8LL),
            0);
        }
        goto LABEL_44;
      }
    }
    else
    {
      qdf_trace_msg(
        0x27u,
        8u,
        "WLAN_DEBUG_DFS : %s: found_on_second=%d is_pre=%d",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "dfs_process_radar_ind_on_home_chan",
        228,
        0);
    }
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS : %s: Radar found on dfs detector: %d",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "dfs_process_radar_ind_on_home_chan",
      (unsigned int)a2[4]);
    goto LABEL_39;
  }
  if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
  {
    v70 = result;
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS : %s: radar event received on invalid channel",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "dfs_process_radar_ind_on_home_chan");
    result = v70;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
