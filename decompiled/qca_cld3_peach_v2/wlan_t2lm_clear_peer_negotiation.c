__int64 __fastcall wlan_t2lm_clear_peer_negotiation(
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
  __int64 v9; // x20
  __int64 first_vdev_by_ml_peer; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2

  v9 = *(_QWORD *)(a1 + 784);
  if ( !v9 )
  {
    v29 = "%s: ml peer is null";
    return qdf_trace_msg(0x99u, 2u, v29, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_t2lm_clear_peer_negotiation");
  }
  first_vdev_by_ml_peer = mlo_get_first_vdev_by_ml_peer(*(_QWORD *)(a1 + 784));
  if ( !first_vdev_by_ml_peer )
  {
    v29 = "%s: VDEV is null";
    return qdf_trace_msg(0x99u, 2u, v29, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_t2lm_clear_peer_negotiation");
  }
  v11 = first_vdev_by_ml_peer;
  if ( mlo_mgr_is_link_switch_in_progress(first_vdev_by_ml_peer) )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Do not clear TTLM during link switch",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_t2lm_clear_peer_negotiation");
  }
  else
  {
    qdf_mem_set((void *)(v9 + 220), 0x9Cu, 0);
    v20 = (_DWORD *)(&off_0 + 4);
    *(_WORD *)(v9 + 216) = 0;
    *(_DWORD *)(v9 + 220) = 4;
    *(_DWORD *)(v9 + 272) = 4;
    *(_DWORD *)(v9 + 324) = 4;
  }
  return wlan_objmgr_vdev_release_ref(v11, 0x5Au, v20, v21, v22, v23, v24, v25, v26, v27, v28);
}
