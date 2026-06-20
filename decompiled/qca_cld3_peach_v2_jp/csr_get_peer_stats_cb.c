__int64 __fastcall csr_get_peer_stats_cb(
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
  __int64 psoc_ext_obj_fl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x8
  const char *v23; // x2
  const char *v25; // x2

  if ( !a2 )
  {
    v23 = "%s: Invalid mac ctx";
    return qdf_trace_msg(0x34u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "csr_get_peer_stats_cb");
  }
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a2 + 21552));
  if ( !psoc_ext_obj_fl )
  {
    v23 = "%s: NULL mlme psoc object";
    return qdf_trace_msg(0x34u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "csr_get_peer_stats_cb");
  }
  qdf_mc_timer_stop(psoc_ext_obj_fl + 7440);
  v21 = *(_QWORD *)(a1 + 40);
  if ( !v21 )
  {
    v25 = "%s: no peer stats";
LABEL_11:
    qdf_trace_msg(0x34u, 8u, v25, v13, v14, v15, v16, v17, v18, v19, v20, "csr_get_peer_stats_cb");
    goto LABEL_12;
  }
  *(_DWORD *)(a2 + 21600) = *(char *)(v21 + 8);
  *(_DWORD *)(a2 + 21604) = **(_DWORD **)(a1 + 40);
  *(_DWORD *)(a2 + 21608) = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 4LL);
  v22 = *(_QWORD *)(a1 + 72);
  if ( !v22 )
  {
    v25 = "%s: no peer extended stats";
    goto LABEL_11;
  }
  *(_DWORD *)(a2 + 21616) = *(_DWORD *)(v22 + 28);
LABEL_12:
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: peer rssi %d tx_rate %d rx_rate %d rx_mc_bc_cnt %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "csr_get_peer_stats_cb",
    *(unsigned int *)(a2 + 21600),
    *(unsigned int *)(a2 + 21604),
    *(unsigned int *)(a2 + 21608),
    *(unsigned int *)(a2 + 21616));
  return csr_continue_peer_disconnect_after_get_stats(a2);
}
