__int64 __fastcall mlme_pdev_obj_destroy_handler(__int64 a1)
{
  __int64 cmpt_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2

  cmpt_obj = wlan_pdev_mlme_get_cmpt_obj();
  if ( !cmpt_obj )
  {
    v21 = "%s: PDEV MLME component object is NULL";
LABEL_6:
    qdf_trace_msg(0x68u, 2u, v21, v3, v4, v5, v6, v7, v8, v9, v10, "mlme_pdev_obj_destroy_handler");
    return 0;
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v21 = "%s: PSOC object is NULL";
    goto LABEL_6;
  }
  v12 = cmpt_obj;
  mlme_pdev_ops_ext_hdl_destroy();
  wlan_objmgr_pdev_component_obj_detach(a1, 0, v12);
  wlan_minidump_remove(v13, v14, v15, v16, v17, v18, v19, v20, v12, 144, v11);
  _qdf_mem_free(v12);
  return 0;
}
