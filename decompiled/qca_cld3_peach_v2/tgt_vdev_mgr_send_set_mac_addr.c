__int64 __fastcall tgt_vdev_mgr_send_set_mac_addr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 (__fastcall *v15)(__int64, __int64); // x8
  __int64 v16; // x0
  __int64 v17; // x1
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

  v11 = *(_QWORD *)(a3 + 216);
  v12 = *(unsigned __int8 *)(a3 + 168);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 || (v14 = *(_QWORD *)(v13 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_10;
  }
  v15 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 1632);
  if ( !v15 )
  {
LABEL_10:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: No Tx Ops",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "tgt_vdev_mgr_send_set_mac_addr",
      v12);
    return 4;
  }
  v16 = a1 & 0xFFFFFFFFFFFFLL;
  v17 = a2 & 0xFFFFFFFFFFFFLL;
  if ( *((_DWORD *)v15 - 1) != -817933966 )
    __break(0x8228u);
  result = v15(v16, v17);
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
      "tgt_vdev_mgr_send_set_mac_addr",
      v12,
      (unsigned int)result);
    return v27;
  }
  return result;
}
