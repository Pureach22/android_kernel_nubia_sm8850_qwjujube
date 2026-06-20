__int64 __fastcall vdev_mgr_peer_delete_all_send(
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Invalid input",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "vdev_mgr_peer_delete_all_send",
      v19,
      v20);
LABEL_6:
    result = 4;
    goto LABEL_7;
  }
  v9 = *(_QWORD *)(a1 + 520);
  if ( !v9 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "vdev_mgr_peer_delete_all_param_update",
      v19,
      v20);
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Param Update Error: %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "vdev_mgr_peer_delete_all_send",
      4);
    goto LABEL_6;
  }
  LOBYTE(v19) = *(_BYTE *)(v9 + 168);
  result = tgt_vdev_mgr_peer_delete_all_send(v9, &v19);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
