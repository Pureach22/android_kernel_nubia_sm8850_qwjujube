__int64 __fastcall wlan_ll_sap_get_target_tsf(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "ll_sap_get_vdev_priv_obj");
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
LABEL_8:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll_sap obj null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_ll_sap_get_target_tsf",
      *(unsigned __int8 *)(a1 + 104));
    wlan_objmgr_vdev_release_ref(a1, 0x69u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
    return 4;
  }
  if ( a2 == 2 )
    return *(_QWORD *)(comp_private_obj + 24);
  if ( a2 == 1 )
  {
    v31 = comp_private_obj;
    result = *(_QWORD *)(comp_private_obj + 16);
    if ( !result )
      return *(_QWORD *)(v31 + 24);
  }
  else if ( a2 )
  {
    return 0;
  }
  else
  {
    return *(_QWORD *)(comp_private_obj + 16);
  }
  return result;
}
