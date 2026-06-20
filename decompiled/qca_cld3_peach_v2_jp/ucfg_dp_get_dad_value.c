__int64 __fastcall ucfg_dp_get_dad_value(
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
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  char v18; // w8

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_get_vdev_priv_obj");
    goto LABEL_5;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_5:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get DP link",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "ucfg_dp_get_dad_value");
    v18 = 0;
    return v18 & 1;
  }
  v18 = *(_BYTE *)(*(_QWORD *)(comp_private_obj + 32) + 3073LL);
  return v18 & 1;
}
