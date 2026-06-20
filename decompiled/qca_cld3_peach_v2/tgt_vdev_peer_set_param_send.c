__int64 __fastcall tgt_vdev_peer_set_param_send(
        __int64 a1,
        unsigned __int8 *a2,
        int a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  unsigned int v13; // w19
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 (*v16)(void); // x8
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  int v32; // w8
  unsigned int v33; // w20
  int v34; // [xsp+8h] [xbp-18h]

  v12 = *(_QWORD *)(a1 + 216);
  v13 = *(unsigned __int8 *)(a1 + 168);
  if ( !v12 || (v14 = *(_QWORD *)(v12 + 80)) == 0 || (v15 = *(_QWORD *)(v14 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_11;
  }
  v16 = *(__int64 (**)(void))(v15 + 1640);
  if ( !v16 )
  {
LABEL_11:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: No Tx Ops",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "tgt_vdev_peer_set_param_send",
      v13);
    return 4;
  }
  if ( *((_DWORD *)v16 - 1) != 297747150 )
    __break(0x8228u);
  result = v16();
  if ( (_DWORD)result )
  {
    if ( a2 )
    {
      v29 = *a2;
      v30 = a2[1];
      v31 = a2[2];
      v32 = a2[5];
    }
    else
    {
      v31 = 0;
      v29 = 0;
      v30 = 0;
      v32 = 0;
    }
    v34 = a3;
    v33 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: peer %02x:%02x:%02x:**:**:%02x param_id %d param_value %d Error %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "tgt_vdev_peer_set_param_send",
      v13,
      v29,
      v30,
      v31,
      v32,
      v34,
      a4,
      result);
    return v33;
  }
  return result;
}
