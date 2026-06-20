__int64 __fastcall mlme_pdev_obj_create_handler(
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
  __int64 v9; // x20
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2

  if ( !a1 )
  {
    v29 = "%s:  PDEV is NULL";
LABEL_8:
    qdf_trace_msg(0x68u, 2u, v29, a2, a3, a4, a5, a6, a7, a8, a9, "mlme_pdev_obj_create_handler");
    return 16;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v29 = "%s: PSOC is NULL";
    goto LABEL_8;
  }
  v11 = _qdf_mem_malloc(0x90u, "mlme_pdev_obj_create_handler", 49);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s:  MLME component object alloc failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "mlme_pdev_obj_create_handler");
    return 2;
  }
  v20 = (_QWORD *)v11;
  wlan_minidump_log(v12, v13, v14, v15, v16, v17, v18, v19, v11, 144, v9);
  *v20 = a1;
  if ( !(unsigned int)mlme_pdev_ops_ext_hdl_create() )
  {
    wlan_objmgr_pdev_component_obj_attach(a1, 0, (__int64)v20, 0, v21, v22, v23, v24, v25, v26, v27, v28);
    return 0;
  }
  wlan_minidump_remove(v21, v22, v23, v24, v25, v26, v27, v28, (__int64)v20, 144, v9);
  _qdf_mem_free((__int64)v20);
  return 16;
}
