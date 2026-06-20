__int64 __fastcall pre_cac_adapter_is_active(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char v19; // w8

  if ( !a1 )
  {
    qdf_trace_msg(0x98u, 8u, "%s: vdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "pre_cac_adapter_is_active");
LABEL_6:
    v19 = 0;
    return v19 & 1;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Du);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s:%u: vdev id: %d, vdev_priv is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "pre_cac_adapter_is_active",
      116,
      *(unsigned __int8 *)(a1 + 104));
    goto LABEL_6;
  }
  v19 = *(_BYTE *)(comp_private_obj + 2);
  return v19 & 1;
}
