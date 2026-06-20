__int64 __fastcall p2p_roc_timeout(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *current_roc_ctx; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x19
  const char *v28; // x2

  qdf_trace_msg(0x4Eu, 8u, "%s: p2p soc obj:%pK", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_roc_timeout", a1);
  if ( !a1 )
  {
    v28 = "%s: Invalid p2p soc object";
    return qdf_trace_msg(0x4Eu, 2u, v28, v10, v11, v12, v13, v14, v15, v16, v17, "p2p_roc_timeout");
  }
  current_roc_ctx = p2p_find_current_roc_ctx(a1);
  if ( !current_roc_ctx )
    return qdf_trace_msg(
             0x4Eu,
             8u,
             "%s: No P2P roc is pending",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "p2p_roc_timeout");
  v27 = (__int64)current_roc_ctx;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p soc obj:%pK, roc ctx:%pK, vdev_id:%d, scan_id:%d, tx ctx:%pK, freq:%d, phy_mode:%d, duration:%d, roc_type:%d, roc_state:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "p2p_roc_timeout",
    current_roc_ctx[2],
    current_roc_ctx,
    *((unsigned int *)current_roc_ctx + 6),
    *((unsigned int *)current_roc_ctx + 7),
    current_roc_ctx[4],
    *((_DWORD *)current_roc_ctx + 10),
    *((unsigned __int8 *)current_roc_ctx + 44),
    *((_DWORD *)current_roc_ctx + 12),
    *((_DWORD *)current_roc_ctx + 13),
    *((_DWORD *)current_roc_ctx + 56));
  if ( *(_DWORD *)(v27 + 224) == 4 )
  {
    v28 = "%s: Cancellation already in progress";
    return qdf_trace_msg(0x4Eu, 2u, v28, v10, v11, v12, v13, v14, v15, v16, v17, "p2p_roc_timeout");
  }
  return p2p_execute_cancel_roc_req(v27, v10, v11, v12, v13, v14, v15, v16, v17);
}
