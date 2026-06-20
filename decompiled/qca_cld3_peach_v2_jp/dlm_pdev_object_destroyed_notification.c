__int64 __fastcall dlm_pdev_object_destroyed_notification(__int64 a1)
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x20u);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    dlm_flush_reject_ap_list(comp_private_obj);
    if ( *(_DWORD *)(v11 + 80) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "qdf_list_destroy");
    qdf_mutex_destroy(v11);
    wlan_objmgr_pdev_component_obj_detach(a1, 0x20u, v11);
    _qdf_mem_free(v11);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: DLM Pdev obj is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dlm_pdev_object_destroyed_notification");
    return 16;
  }
}
