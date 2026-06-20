__int64 __fastcall mlme_psoc_obj_destroy_handler(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    wlan_minidump_remove(v3, v4, v5, v6, v7, v8, v9, v10, comp_private_obj, 2024, a1);
    wlan_objmgr_psoc_component_obj_detach(a1, 0, v11);
    mlme_psoc_ops_ext_hdl_destroy();
    _qdf_mem_free(v11);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC MLME component object is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "mlme_psoc_get_priv");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC MLME component object is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlme_psoc_obj_destroy_handler");
    return 16;
  }
}
