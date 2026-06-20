__int64 __fastcall vdev_mgr_peer_flush_tids_send(
        __int64 a1,
        const void *a2,
        int a3,
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
  char v12; // w8
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a4, a5, a6, a7, a8, a9, a10, a11, "vdev_mgr_peer_flush_tids_send");
LABEL_7:
    result = 4;
    goto LABEL_8;
  }
  v11 = *(_QWORD *)(a1 + 520);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "vdev_mgr_peer_flush_tids_param_update");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Param Update Error: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "vdev_mgr_peer_flush_tids_send",
      4);
    goto LABEL_7;
  }
  v12 = *(_BYTE *)(v11 + 168);
  v23 = a3;
  LOBYTE(v24[0]) = v12;
  qdf_mem_copy((char *)v24 + 1, a2, 6u);
  result = tgt_vdev_mgr_peer_flush_tids_send(a1, &v23);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
