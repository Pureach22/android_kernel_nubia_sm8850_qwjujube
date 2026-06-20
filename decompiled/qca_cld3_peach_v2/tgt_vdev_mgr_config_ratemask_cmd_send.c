__int64 __fastcall tgt_vdev_mgr_config_ratemask_cmd_send(
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
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20

  v9 = *(_QWORD *)(a1 + 520);
  v10 = *(_QWORD *)(v9 + 216);
  v11 = *(unsigned __int8 *)(v9 + 168);
  if ( !v10 || (v12 = *(_QWORD *)(v10 + 80)) == 0 || (v13 = *(_QWORD *)(v12 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_10;
  }
  v14 = *(__int64 (**)(void))(v13 + 1496);
  if ( !v14 )
  {
LABEL_10:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: No Tx Ops",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tgt_vdev_mgr_config_ratemask_cmd_send",
      v11);
    return 4;
  }
  if ( *((_DWORD *)v14 - 1) != 62256120 )
    __break(0x8228u);
  result = v14();
  if ( (_DWORD)result )
  {
    v24 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: Tx Ops Error : %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "tgt_vdev_mgr_config_ratemask_cmd_send",
      v11,
      (unsigned int)result);
    return v24;
  }
  return result;
}
