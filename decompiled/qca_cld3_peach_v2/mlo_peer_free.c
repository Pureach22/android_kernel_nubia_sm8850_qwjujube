__int64 __fastcall mlo_peer_free(
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
  __int64 v9; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v9 = *(_QWORD *)(a1 + 192);
  if ( !v9 )
    return qdf_trace_msg(0x8Fu, 2u, "%s: ML DEV is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "mlo_peer_free");
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: ML Peer %02x:%02x:%02x:**:**:%02x is freed",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "mlo_peer_free",
    *(unsigned __int8 *)(a1 + 104),
    *(unsigned __int8 *)(a1 + 105),
    *(unsigned __int8 *)(a1 + 106),
    *(unsigned __int8 *)(a1 + 109));
  wlan_t2lm_timer_stop(v9 + 2352);
  mlo_t2lm_reset_established_and_upcoming_mapping(v9);
  ttlm_sm_destroy(a1);
  qdf_mutex_destroy(a1 + 120);
  qdf_mutex_destroy(a1 + 552);
  mlo_ap_ml_peerid_free(*(_DWORD *)(a1 + 100));
  mlo_peer_free_aid(v9, a1, v11, v12, v13, v14, v15, v16, v17, v18);
  mlo_peer_free_primary_umac(v9, a1);
  return _qdf_mem_free(a1);
}
