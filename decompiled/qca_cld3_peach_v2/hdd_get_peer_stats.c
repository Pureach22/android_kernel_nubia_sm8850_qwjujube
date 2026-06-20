__int64 __fastcall hdd_get_peer_stats(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  __int64 *v13; // x8
  _QWORD *v14; // x22
  __int64 v15; // x0
  _QWORD *peer_by_mac; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  __int64 v36; // x8
  _DWORD *v37; // x8
  __int64 v38; // x1
  __int64 v39; // x0
  char is_enabled; // w0
  __int64 v41; // x8
  __int64 result; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 peer_stats; // x0
  __int64 v52; // x20
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x8
  __int64 v70; // x9
  void *v71; // x0
  int v72; // w8
  __int64 v73; // x8
  void *v74; // x0
  int v75; // w8
  int v76; // w8
  int v77; // w22
  unsigned int v78; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v79; // [xsp+8h] [xbp-18h] BYREF
  int v80; // [xsp+10h] [xbp-10h]
  __int64 v81; // [xsp+18h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_get_peer_stats", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *(__int64 **)(a1 + 24);
  v80 = 0;
  v14 = context;
  v79 = 0;
  v15 = *v13;
  v78 = 0;
  peer_by_mac = wlan_objmgr_get_peer_by_mac(v15, (_BYTE *)(a2 + 32), 0x51u);
  if ( !peer_by_mac )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Peer not found with MAC %02x:%02x:%02x:**:**:%02x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_get_peer_stats",
      *(unsigned __int8 *)(a2 + 32),
      *(unsigned __int8 *)(a2 + 33),
      *(unsigned __int8 *)(a2 + 34),
      *(unsigned __int8 *)(a2 + 37));
    goto LABEL_14;
  }
  v25 = peer_by_mac[12];
  wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 0x51u, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( !v25 )
  {
LABEL_14:
    result = 4294967274LL;
    goto LABEL_18;
  }
  v26 = _qdf_mem_malloc(0x11C0u, "hdd_get_peer_stats", 1881);
  if ( !v26 )
  {
    result = 4294967284LL;
    goto LABEL_18;
  }
  v35 = v26;
  if ( !v14 || !*v14 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v27, v28, v29, v30, v31, v32, v33, v34, "cdp_host_get_peer_stats");
LABEL_16:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: cdp_host_get_peer_stats failed",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hdd_get_peer_stats");
    _qdf_mem_free(v35);
    result = 4294967274LL;
    goto LABEL_18;
  }
  v36 = *(_QWORD *)(*v14 + 32LL);
  if ( !v36 )
    goto LABEL_16;
  v37 = *(_DWORD **)(v36 + 144);
  if ( !v37 )
    goto LABEL_16;
  v38 = *(unsigned __int8 *)(v25 + 168);
  if ( *(v37 - 1) != -1642106733 )
    __break(0x8228u);
  v39 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))v37)(v14, v38, a2 + 32, v26);
  if ( (_DWORD)v39 )
    goto LABEL_16;
  *(_DWORD *)(a2 + 228) = *(_DWORD *)(v35 + 4080);
  is_enabled = ucfg_ipa_is_enabled(v39);
  v41 = *(_QWORD *)(v35 + 2976) + *(_QWORD *)(v35 + 2960);
  if ( (is_enabled & 1) != 0 )
    LODWORD(v41) = *(_DWORD *)(a2 + 232) + v41;
  *(_DWORD *)(a2 + 232) = v41;
  _qdf_mem_free(v35);
  peer_stats = wlan_cfg80211_mc_cp_stats_get_peer_stats(
                 v25,
                 (const void *)(a2 + 32),
                 &v78,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50);
  v52 = peer_stats;
  if ( v78 || !peer_stats )
  {
    wlan_cfg80211_mc_cp_stats_free_stats_event(peer_stats);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get peer stats info",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "hdd_get_peer_stats");
    result = 4294967274LL;
  }
  else
  {
    if ( (cds_dp_get_vdev_stats(*(unsigned __int8 *)(v25 + 168), &v79) & 1) != 0 )
      *(_DWORD *)(a2 + 236) = v80;
    else
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to get dp vdev stats",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "hdd_get_peer_stats");
    *(_DWORD *)(a2 + 240) = 0;
    *(_DWORD *)(a2 + 244) = *(_DWORD *)(*(_QWORD *)(v52 + 160) + 8LL);
    *(_DWORD *)(a2 + 248) = *(_DWORD *)(*(_QWORD *)(v52 + 160) + 40LL);
    *(_DWORD *)(a2 + 252) = *(_DWORD *)(*(_QWORD *)(v52 + 160) + 44LL);
    v69 = *(_QWORD *)(v52 + 160);
    v70 = *(unsigned int *)(v69 + 104);
    if ( (_DWORD)v70 )
    {
      v71 = (void *)_qdf_mem_malloc(4 * v70, "hdd_get_peer_stats", 1930);
      *(_QWORD *)(a2 + 480) = v71;
      v69 = *(_QWORD *)(v52 + 160);
      if ( v71 )
      {
        v72 = *(_DWORD *)(v69 + 104);
        *(_DWORD *)(a2 + 468) = v72;
        qdf_mem_copy(v71, *(const void **)(*(_QWORD *)(v52 + 160) + 112LL), (unsigned int)(4 * v72));
        v69 = *(_QWORD *)(v52 + 160);
      }
    }
    v73 = *(unsigned int *)(v69 + 108);
    if ( (_DWORD)v73 )
    {
      v74 = (void *)_qdf_mem_malloc(4 * v73, "hdd_get_peer_stats", 1943);
      *(_QWORD *)(a2 + 488) = v74;
      if ( v74 )
      {
        v75 = *(_DWORD *)(*(_QWORD *)(v52 + 160) + 108LL);
        *(_DWORD *)(a2 + 472) = v75;
        qdf_mem_copy(v74, *(const void **)(*(_QWORD *)(v52 + 160) + 120LL), (unsigned int)(4 * v75));
      }
    }
    if ( *(_DWORD *)(v52 + 48)
      || (qdf_trace_msg(
            0x33u,
            8u,
            "%s: Failed to get peer adv stats info",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "hdd_get_peer_stats"),
          *(_DWORD *)(a2 + 256) = 0,
          *(_DWORD *)(v52 + 48)) )
    {
      v76 = 0;
      while ( 1 )
      {
        v77 = v76;
        if ( !(unsigned int)qdf_mem_cmp((const void *)(a2 + 32), (const void *)(*(_QWORD *)(v52 + 56) + 24LL * v76), 6u) )
          break;
        v76 = v77 + 1;
        if ( (unsigned int)(v77 + 1) >= *(_DWORD *)(v52 + 48) )
          goto LABEL_38;
      }
      *(_DWORD *)(a2 + 256) = *(_DWORD *)(*(_QWORD *)(v52 + 56) + 24LL * v77 + 8);
    }
LABEL_38:
    wlan_cfg80211_mc_cp_stats_free_stats_event(v52);
    result = v78;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
