__int64 __fastcall vdev_mgr_create_send(
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
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x2
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_MLME is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "vdev_mgr_create_send");
LABEL_9:
    result = 4;
    goto LABEL_10;
  }
  v9 = *(_QWORD *)(a1 + 504);
  if ( !v9 )
  {
    v11 = "%s: VDEV is NULL";
LABEL_8:
    qdf_trace_msg(0x68u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "vdev_mgr_create_param_update");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Param Update Error: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "vdev_mgr_create_send",
      4);
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(v9 + 152) )
  {
    v11 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  result = tgt_vdev_mgr_create_send();
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
