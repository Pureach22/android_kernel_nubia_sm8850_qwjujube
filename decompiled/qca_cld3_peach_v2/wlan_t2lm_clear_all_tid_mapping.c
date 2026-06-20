__int64 __fastcall wlan_t2lm_clear_all_tid_mapping(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v11; // x22
  __int64 bsspeer; // x0
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _DWORD *v39; // x22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x22

  if ( !a1 )
  {
    v30 = "%s: Vdev is null";
    return qdf_trace_msg(0x99u, 2u, v30, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_t2lm_clear_all_tid_mapping");
  }
  result = wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (result & 1) == 0 )
    return result;
  v11 = *(_QWORD *)(a1 + 1360);
  if ( !v11 )
  {
    v30 = "%s: mlo dev ctx is null";
    return qdf_trace_msg(0x99u, 2u, v30, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_t2lm_clear_all_tid_mapping");
  }
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x5Au);
  if ( !bsspeer )
  {
    v30 = "%s: peer is null";
    return qdf_trace_msg(0x99u, 2u, v30, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_t2lm_clear_all_tid_mapping");
  }
  v13 = bsspeer;
  if ( mlo_mgr_is_link_switch_in_progress(a1) )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Do not clear TTLM during link switch",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_t2lm_clear_all_tid_mapping");
  }
  else
  {
    qdf_mem_set((void *)(v11 + 2240), 0x38u, 0);
    *(_DWORD *)(v11 + 2244) = 2;
    *(_BYTE *)(v11 + 2248) = 1;
    *(_BYTE *)(v11 + 2293) = 0;
    qdf_mem_set((void *)(v11 + 2296), 0x38u, 0);
    *(_DWORD *)(v11 + 2300) = 4;
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Clear the T2LM info received in assoc rsp",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wlan_t2lm_clear_all_tid_mapping");
    v39 = *(_DWORD **)(*(_QWORD *)(a1 + 1360) + 2224LL);
    qdf_mem_set(v39 + 80, 0x38u, 0);
    v39[81] = 4;
    qdf_mem_set(v39 + 94, 0x38u, 0);
    v39[95] = 4;
    wlan_t2lm_clear_peer_negotiation(v13, v40, v41, v42, v43, v44, v45, v46, v47);
    v56 = *(_QWORD *)(v13 + 784);
    if ( v56 )
    {
      qdf_mem_set((void *)(v56 + 384), 0x9Cu, 0);
      *(_BYTE *)(v56 + 380) = 0;
      *(_DWORD *)(v56 + 376) = 0;
      *(_QWORD *)(v56 + 540) = 0x8700000000LL;
      *(_DWORD *)(v56 + 384) = 4;
      *(_DWORD *)(v56 + 436) = 4;
      *(_DWORD *)(v56 + 488) = 4;
    }
    else
    {
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: ml peer is null",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wlan_t2lm_clear_ongoing_negotiation");
    }
    wlan_mlo_t2lm_timer_stop(a1);
  }
  return wlan_objmgr_peer_release_ref(v13, 0x5Au, v22, v23, v24, v25, v26, v27, v28, v29);
}
