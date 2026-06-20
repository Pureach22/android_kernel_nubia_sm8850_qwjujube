__int64 __fastcall wlan_hdd_cfg80211_link_layer_stats_callback(
        __int64 a1,
        unsigned int a2,
        unsigned int *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x23
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x19
  __int64 v36; // x22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 link_info_by_vdev; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x25
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x20
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x20
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w8
  int *v82; // x26
  __int64 v83; // x0
  __int64 v84; // x22
  size_t v85; // x25
  _QWORD *v86; // x0
  _QWORD *v87; // x24
  unsigned int v88; // w8
  const void **v89; // x28
  unsigned int v90; // w27
  __int64 v92; // x8
  __int64 v93; // x23
  unsigned int v94; // w25
  void *v95; // x0
  void *v96; // x0
  __int64 *v97; // x21
  __int64 v98; // t1
  __int64 v99; // x21
  __int64 v100; // x0
  void *v101; // x0
  int v102; // w8
  int v103; // w10
  int v104; // w8
  _DWORD *v105; // x9
  __int64 v106; // x0
  unsigned int v107; // w8
  __int64 v108; // x10
  unsigned int *v109; // x12
  int v110; // w11
  int v111; // w11
  __int64 v112; // x13
  __int64 v113; // x10
  unsigned int v114; // w24
  void *v115; // x0
  unsigned int v116; // w8
  __int64 v117; // x0

  result = _wlan_hdd_validate_context(
             a1,
             (__int64)"wlan_hdd_cfg80211_link_layer_stats_callback",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12);
  if ( (_DWORD)result )
    return result;
  if ( a2 != 4338 )
    return qdf_trace_msg(
             0x33u,
             3u,
             "%s: invalid event type %d",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "wlan_hdd_cfg80211_link_layer_stats_callback",
             a2);
  v25 = a3 + 7;
  qdf_trace_msg(
    0x33u,
    8u,
    "LL_STATS RESP paramID = 0x%x, ifaceId = %u, respId= %u , moreResultToFollow = %u, num radio = %u result = %pK",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    *a3,
    *((unsigned __int8 *)a3 + 4),
    a3[2],
    a3[3],
    a3[5],
    a3 + 7);
  v26 = osif_request_get(a4);
  if ( !v26 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Obsolete request",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             "wlan_hdd_cfg80211_link_layer_stats_callback");
  v35 = v26;
  v36 = osif_request_priv(v26);
  if ( *(_DWORD *)(v36 + 24) != a3[2] )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Request id %d response id %d request bitmap 0x%x response bitmap 0x%x",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_hdd_cfg80211_link_layer_stats_callback");
    return osif_request_put(v35);
  }
  link_info_by_vdev = hdd_get_link_info_by_vdev(a1, *((unsigned __int8 *)a3 + 4));
  if ( !link_info_by_vdev )
  {
    v54 = jiffies;
    if ( wlan_hdd_cfg80211_link_layer_stats_callback___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: invalid vdev_id %d sent by FW",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "wlan_hdd_cfg80211_link_layer_stats_callback",
        *((unsigned __int8 *)a3 + 4));
      wlan_hdd_cfg80211_link_layer_stats_callback___last_ticks = v54;
    }
    link_info_by_vdev = hdd_get_link_info_by_vdev(a1, *(unsigned __int8 *)(v36 + 48));
    if ( !link_info_by_vdev )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: invalid vdev %d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "wlan_hdd_cfg80211_link_layer_stats_callback",
        *(unsigned __int8 *)(v36 + 48));
      return osif_request_put(v35);
    }
  }
  v63 = link_info_by_vdev;
  osif_request_priv(v35);
  qdf_trace_msg(0x33u, 8u, "Can't update req_bitmap for non MLO case", v64, v65, v66, v67, v68, v69, v70, v71);
  if ( a3[2] == -1 )
  {
    hdd_debugfs_process_ll_stats(v63, a3, v35);
    return osif_request_put(v35);
  }
  v72 = osif_request_priv(v35);
  raw_spin_lock(v72 + 32);
  v81 = *a3;
  v82 = (int *)(v72 + 28);
  if ( (*a3 & *(_DWORD *)(v72 + 28)) == 0 )
  {
LABEL_60:
    raw_spin_unlock(v72 + 32);
    return osif_request_put(v35);
  }
  if ( (v81 & 1) == 0 )
  {
    if ( (v81 & 2) != 0 )
    {
      v100 = _qdf_mem_malloc(0x28u, "hdd_process_ll_stats", 2790);
      if ( !v100 )
        goto LABEL_70;
      v84 = v100;
      *(_DWORD *)(v100 + 16) = 2;
      *(_DWORD *)(v100 + 36) = a3[5];
      v101 = (void *)_qdf_mem_malloc(0x288u, "hdd_process_ll_stats", 2797);
      *(_QWORD *)(v84 + 24) = v101;
      if ( !v101 )
        goto LABEL_69;
      qdf_mem_copy(v101, a3 + 7, 0x288u);
      v102 = *v82;
      if ( !a3[5] )
      {
        v102 &= ~4u;
        *v82 = v102;
      }
      v103 = *(unsigned __int8 *)(v72 + 49);
      *(_DWORD *)(v72 + 28) = v102 & ~*(_DWORD *)(v84 + 16);
      if ( v103 != 1 )
        goto LABEL_58;
      v104 = 1 << *((_BYTE *)a3 + 4);
      v105 = (_DWORD *)(v72 + 52);
      goto LABEL_57;
    }
    if ( (v81 & 4) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: INVALID LL_STATS_NOTIFY RESPONSE",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "hdd_process_ll_stats");
LABEL_59:
      if ( !*v82 && (*(_BYTE *)(v72 + 49) != 1 || !*(_DWORD *)(v72 + 52)) )
        goto LABEL_70;
      goto LABEL_60;
    }
    v106 = _qdf_mem_malloc(0x28u, "hdd_process_ll_stats", 2825);
    if ( !v106 )
      goto LABEL_70;
    v107 = *v25;
    v84 = v106;
    if ( *v25 )
    {
      v108 = 0;
      v109 = a3 + 8;
      if ( v107 + 1 > 2 )
        v110 = v107 + 1;
      else
        v110 = 2;
      v111 = v110 - 1;
      do
      {
        v112 = v109[4];
        --v111;
        v108 += v112;
        v109 += 8 * v112 + 5;
      }
      while ( v111 );
      v113 = (32 * v108) | 4;
    }
    else
    {
      v113 = 4;
    }
    v114 = v113 + 20 * v107;
    *(_DWORD *)(v106 + 16) = 4;
    v115 = (void *)_qdf_mem_malloc(v113 + 20LL * v107, "hdd_process_ll_stats", 2843);
    *(_QWORD *)(v84 + 24) = v115;
    if ( !v115 )
      goto LABEL_69;
    qdf_mem_copy(v115, a3 + 7, v114);
LABEL_55:
    v116 = a3[3];
    *(_DWORD *)(v84 + 32) = v116;
    if ( v116 )
    {
LABEL_58:
      qdf_list_insert_back((_QWORD *)v72, (_QWORD *)v84);
      goto LABEL_59;
    }
    v104 = *(_DWORD *)(v84 + 16);
    v105 = (_DWORD *)(v72 + 28);
LABEL_57:
    *v105 &= ~v104;
    goto LABEL_58;
  }
  if ( !a3[5] )
    goto LABEL_70;
  v83 = _qdf_mem_malloc(0x28u, "hdd_process_ll_stats", 2720);
  if ( !v83 )
    goto LABEL_70;
  v84 = v83;
  v85 = 80LL * a3[5];
  *(_DWORD *)(v83 + 16) = 1;
  v86 = (_QWORD *)_qdf_mem_malloc(v85, "hdd_process_ll_stats", 2727);
  if ( !v86 )
    goto LABEL_69;
  v87 = v86;
  *(_QWORD *)(v84 + 24) = v86;
  qdf_mem_copy(v86, a3 + 7, (unsigned int)v85);
  v88 = a3[5];
  if ( !v88 )
  {
LABEL_51:
    *(_DWORD *)(v84 + 36) = v88;
    goto LABEL_55;
  }
  v89 = (const void **)(a3 + 25);
  v90 = 1;
  while ( 1 )
  {
    v92 = *((unsigned int *)v89 - 6);
    v93 = *((unsigned int *)v89 - 1);
    if ( (_DWORD)v92 && *(v89 - 2) )
    {
      v94 = 4 * v92;
      v95 = (void *)_qdf_mem_malloc(4 * v92, "hdd_process_ll_stats", 2744);
      v87[7] = v95;
      if ( !v95 )
      {
        if ( (int)(v90 - 1) < 1 )
        {
          v99 = (__int64)v87;
        }
        else
        {
          do
          {
            v99 = (__int64)(v87 - 10);
            _qdf_mem_free(*(v87 - 3));
            _qdf_mem_free(*(v87 - 1));
            --v90;
            v87 -= 10;
          }
          while ( v90 > 1 );
        }
        goto LABEL_68;
      }
      qdf_mem_copy(v95, *(v89 - 2), v94);
    }
    if ( (_DWORD)v93 )
      break;
LABEL_25:
    v88 = a3[5];
    v89 += 10;
    v87 += 10;
    if ( v90++ >= v88 )
      goto LABEL_51;
  }
  v96 = (void *)_qdf_mem_malloc(32 * v93, "hdd_process_ll_stats", 2763);
  v87[9] = v96;
  if ( v96 )
  {
    qdf_mem_copy(v96, *v89, (unsigned int)(32 * v93));
    goto LABEL_25;
  }
  _qdf_mem_free(v87[7]);
  if ( (int)(v90 - 1) >= 1 )
  {
    v97 = v87 - 1;
    do
    {
      _qdf_mem_free(*(v97 - 2));
      v98 = *v97;
      v97 -= 10;
      _qdf_mem_free(v98);
      --v90;
    }
    while ( v90 > 1 );
  }
  v99 = *(_QWORD *)(v84 + 24);
LABEL_68:
  _qdf_mem_free(v99);
LABEL_69:
  _qdf_mem_free(v84);
LABEL_70:
  v117 = raw_spin_unlock(v72 + 32);
  sme_radio_tx_mem_free(v117);
  osif_request_complete(v35);
  return osif_request_put(v35);
}
