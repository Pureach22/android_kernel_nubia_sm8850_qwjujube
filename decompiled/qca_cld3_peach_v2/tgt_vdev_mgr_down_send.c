__int64 __fastcall tgt_vdev_mgr_down_send(
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
  __int64 v10; // x20
  __int64 v11; // x21
  unsigned int v12; // w19
  __int64 v13; // x8
  __int64 v14; // x23
  int v16; // w24
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w20

  if ( !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_down_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 520);
  v11 = *(_QWORD *)(v10 + 216);
  v12 = *(unsigned __int8 *)(v10 + 168);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 || (v14 = *(_QWORD *)(v13 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_14;
  }
  if ( !*(_QWORD *)(v14 + 1440) )
  {
LABEL_14:
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_%d: No Tx Ops", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_down_send", v12);
    return 4;
  }
  v16 = *(_DWORD *)(v10 + 16);
  if ( !(unsigned int)wlan_util_is_vdev_active(*(_QWORD *)(v10 + 216), 0x31u) && v16 == 1 )
    utils_dfs_cancel_precac_timer(v11);
  v17 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 1440);
  if ( *((_DWORD *)v17 - 1) != -842498428 )
    __break(0x8228u);
  result = v17(v10, a2);
  if ( (_DWORD)result )
  {
    v27 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: Tx Ops Error : %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "tgt_vdev_mgr_down_send",
      v12,
      (unsigned int)result);
    return v27;
  }
  return result;
}
