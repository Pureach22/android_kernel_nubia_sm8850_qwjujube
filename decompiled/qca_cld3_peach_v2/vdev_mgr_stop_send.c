__int64 __fastcall vdev_mgr_stop_send(
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
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_MLME is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "vdev_mgr_stop_send");
LABEL_6:
    result = 4;
    goto LABEL_7;
  }
  if ( !*(_QWORD *)(a1 + 520) )
  {
    qdf_trace_msg(0x68u, 2u, "%s: VDEV is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "vdev_mgr_stop_param_update");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Param Update Error: %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "vdev_mgr_stop_send",
      4);
    goto LABEL_6;
  }
  result = tgt_vdev_mgr_stop_send();
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
