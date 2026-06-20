__int64 __fastcall wlan_hdd_cfg80211_link_layer_stats_callback(
        __int64 *a1,
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
  __int64 v63; // x22
  __int64 v64; // x24
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w3
  __int64 v82; // x21
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned int v91; // w8
  int *v92; // x26
  __int64 v93; // x0
  __int64 v94; // x22
  size_t v95; // x25
  _QWORD *v96; // x0
  _QWORD *v97; // x24
  unsigned int v98; // w8
  const void **v99; // x28
  unsigned int v100; // w27
  __int64 v102; // x8
  __int64 v103; // x23
  unsigned int v104; // w25
  void *v105; // x0
  void *v106; // x0
  __int64 *v107; // x20
  __int64 v108; // t1
  __int64 v109; // x20
  __int64 v110; // x0
  void *v111; // x0
  int v112; // w8
  int v113; // w10
  int v114; // w8
  _DWORD *v115; // x9
  __int64 v116; // x0
  unsigned int v117; // w8
  __int64 v118; // x10
  unsigned int *v119; // x12
  int v120; // w11
  int v121; // w11
  __int64 v122; // x13
  __int64 v123; // x10
  unsigned int v124; // w24
  void *v125; // x0
  unsigned int v126; // w8
  __int64 v127; // x0

  result = _wlan_hdd_validate_context(
             (__int64)a1,
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
  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)a1, *((unsigned __int8 *)a3 + 4));
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
    link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)a1, *(unsigned __int8 *)(v36 + 48));
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
  v64 = osif_request_priv(v35);
  if ( wlan_vdev_mlme_get_is_mlo_vdev(*a1, *(unsigned __int8 *)(v64 + 48)) )
  {
    if ( (wlan_vdev_mlme_get_is_mlo_link(*a1, *((unsigned __int8 *)a3 + 4)) & 1) != 0 && *a3 == 2 )
    {
      v81 = *(_DWORD *)(v64 + 28);
      if ( (v81 & 2) == 0 )
        *(_DWORD *)(v64 + 28) = v81 | 2;
      qdf_trace_msg(0x33u, 8u, "MLO_LL_STATS set request_bitmap = 0x%x", v73, v74, v75, v76, v77, v78, v79, v80);
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "Can't update req_bitmap for non MLO case", v65, v66, v67, v68, v69, v70, v71, v72);
  }
  if ( a3[2] == -1 )
  {
    hdd_debugfs_process_ll_stats(v63, a3, v35);
    return osif_request_put(v35);
  }
  v82 = osif_request_priv(v35);
  raw_spin_lock(v82 + 32);
  v91 = *a3;
  v92 = (int *)(v82 + 28);
  if ( (*a3 & *(_DWORD *)(v82 + 28)) == 0 )
  {
LABEL_67:
    raw_spin_unlock(v82 + 32);
    return osif_request_put(v35);
  }
  if ( (v91 & 1) == 0 )
  {
    if ( (v91 & 2) != 0 )
    {
      v110 = _qdf_mem_malloc(0x28u, "hdd_process_ll_stats", 2790);
      if ( !v110 )
        goto LABEL_77;
      v94 = v110;
      *(_DWORD *)(v110 + 16) = 2;
      *(_DWORD *)(v110 + 36) = a3[5];
      v111 = (void *)_qdf_mem_malloc(0x288u, "hdd_process_ll_stats", 2797);
      *(_QWORD *)(v94 + 24) = v111;
      if ( !v111 )
        goto LABEL_76;
      qdf_mem_copy(v111, a3 + 7, 0x288u);
      v112 = *v92;
      if ( !a3[5] )
      {
        v112 &= ~4u;
        *v92 = v112;
      }
      v113 = *(unsigned __int8 *)(v82 + 49);
      *(_DWORD *)(v82 + 28) = v112 & ~*(_DWORD *)(v94 + 16);
      if ( v113 != 1 )
        goto LABEL_65;
      v114 = 1 << *((_BYTE *)a3 + 4);
      v115 = (_DWORD *)(v82 + 52);
      goto LABEL_64;
    }
    if ( (v91 & 4) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: INVALID LL_STATS_NOTIFY RESPONSE",
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        "hdd_process_ll_stats");
LABEL_66:
      if ( !*v92 && (*(_BYTE *)(v82 + 49) != 1 || !*(_DWORD *)(v82 + 52)) )
        goto LABEL_77;
      goto LABEL_67;
    }
    v116 = _qdf_mem_malloc(0x28u, "hdd_process_ll_stats", 2825);
    if ( !v116 )
      goto LABEL_77;
    v117 = *v25;
    v94 = v116;
    if ( *v25 )
    {
      v118 = 0;
      v119 = a3 + 8;
      if ( v117 + 1 > 2 )
        v120 = v117 + 1;
      else
        v120 = 2;
      v121 = v120 - 1;
      do
      {
        v122 = v119[4];
        --v121;
        v118 += v122;
        v119 += 8 * v122 + 5;
      }
      while ( v121 );
      v123 = (32 * v118) | 4;
    }
    else
    {
      v123 = 4;
    }
    v124 = v123 + 20 * v117;
    *(_DWORD *)(v116 + 16) = 4;
    v125 = (void *)_qdf_mem_malloc(v123 + 20LL * v117, "hdd_process_ll_stats", 2843);
    *(_QWORD *)(v94 + 24) = v125;
    if ( !v125 )
      goto LABEL_76;
    qdf_mem_copy(v125, a3 + 7, v124);
LABEL_62:
    v126 = a3[3];
    *(_DWORD *)(v94 + 32) = v126;
    if ( v126 )
    {
LABEL_65:
      qdf_list_insert_back((_QWORD *)v82, (_QWORD *)v94);
      goto LABEL_66;
    }
    v114 = *(_DWORD *)(v94 + 16);
    v115 = (_DWORD *)(v82 + 28);
LABEL_64:
    *v115 &= ~v114;
    goto LABEL_65;
  }
  if ( !a3[5] )
    goto LABEL_77;
  v93 = _qdf_mem_malloc(0x28u, "hdd_process_ll_stats", 2720);
  if ( !v93 )
    goto LABEL_77;
  v94 = v93;
  v95 = 80LL * a3[5];
  *(_DWORD *)(v93 + 16) = 1;
  v96 = (_QWORD *)_qdf_mem_malloc(v95, "hdd_process_ll_stats", 2727);
  if ( !v96 )
    goto LABEL_76;
  v97 = v96;
  *(_QWORD *)(v94 + 24) = v96;
  qdf_mem_copy(v96, a3 + 7, (unsigned int)v95);
  v98 = a3[5];
  if ( !v98 )
  {
LABEL_58:
    *(_DWORD *)(v94 + 36) = v98;
    goto LABEL_62;
  }
  v99 = (const void **)(a3 + 25);
  v100 = 1;
  while ( 1 )
  {
    v102 = *((unsigned int *)v99 - 6);
    v103 = *((unsigned int *)v99 - 1);
    if ( (_DWORD)v102 && *(v99 - 2) )
    {
      v104 = 4 * v102;
      v105 = (void *)_qdf_mem_malloc(4 * v102, "hdd_process_ll_stats", 2744);
      v97[7] = v105;
      if ( !v105 )
      {
        if ( (int)(v100 - 1) < 1 )
        {
          v109 = (__int64)v97;
        }
        else
        {
          do
          {
            v109 = (__int64)(v97 - 10);
            _qdf_mem_free(*(v97 - 3));
            _qdf_mem_free(*(v97 - 1));
            --v100;
            v97 -= 10;
          }
          while ( v100 > 1 );
        }
        goto LABEL_75;
      }
      qdf_mem_copy(v105, *(v99 - 2), v104);
    }
    if ( (_DWORD)v103 )
      break;
LABEL_32:
    v98 = a3[5];
    v99 += 10;
    v97 += 10;
    if ( v100++ >= v98 )
      goto LABEL_58;
  }
  v106 = (void *)_qdf_mem_malloc(32 * v103, "hdd_process_ll_stats", 2763);
  v97[9] = v106;
  if ( v106 )
  {
    qdf_mem_copy(v106, *v99, (unsigned int)(32 * v103));
    goto LABEL_32;
  }
  _qdf_mem_free(v97[7]);
  if ( (int)(v100 - 1) >= 1 )
  {
    v107 = v97 - 1;
    do
    {
      _qdf_mem_free(*(v107 - 2));
      v108 = *v107;
      v107 -= 10;
      _qdf_mem_free(v108);
      --v100;
    }
    while ( v100 > 1 );
  }
  v109 = *(_QWORD *)(v94 + 24);
LABEL_75:
  _qdf_mem_free(v109);
LABEL_76:
  _qdf_mem_free(v94);
LABEL_77:
  v127 = raw_spin_unlock(v82 + 32);
  sme_radio_tx_mem_free(v127);
  osif_request_complete(v35);
  return osif_request_put(v35);
}
