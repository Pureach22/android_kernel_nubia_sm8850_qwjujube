__int64 __fastcall ll_lt_sap_deinit(
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
  __int64 *comp_private_obj; // x0
  __int64 v11; // x1
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x20
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v31; // x4
  const char *v32; // x2
  unsigned int v33; // w1

  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "ll_sap_get_vdev_priv_obj");
    goto LABEL_6;
  }
  comp_private_obj = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
LABEL_6:
    v31 = *(unsigned __int8 *)(a1 + 104);
    v32 = "%s: vdev %d ll_sap obj null";
    v33 = 2;
    goto LABEL_7;
  }
  v20 = comp_private_obj;
  v21 = *comp_private_obj;
  if ( v21 )
  {
    bs_sm_destroy(v21, v11);
    _qdf_mem_free(*v20);
    *v20 = 0;
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: vdev %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "ll_lt_sap_deinit",
      *(unsigned __int8 *)(a1 + 104));
    return 0;
  }
  v31 = *(unsigned __int8 *)(a1 + 104);
  v32 = "%s: vdev %d Bearer switch context is NULL";
  v33 = 8;
LABEL_7:
  qdf_trace_msg(0xA1u, v33, v32, v12, v13, v14, v15, v16, v17, v18, v19, "ll_lt_sap_deinit", v31);
  return 4;
}
