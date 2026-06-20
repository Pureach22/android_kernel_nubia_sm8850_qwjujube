__int64 __fastcall wlan_serialization_pdev_destroy_handler(__int64 a1)
{
  __int64 pdev_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w20

  pdev_obj = wlan_serialization_get_pdev_obj(a1);
  if ( pdev_obj )
  {
    v11 = pdev_obj;
    v12 = wlan_objmgr_pdev_component_obj_detach(a1, 2u, pdev_obj);
    wlan_serialization_destroy_pdev_list(v11);
    wlan_serialization_destroy_cmd_pool(v11);
    wlan_serialization_destroy_lock(v11 + 88);
    wlan_serialization_destroy_pdev_list(v11 + 104);
    wlan_serialization_destroy_cmd_pool(v11 + 104);
    wlan_serialization_destroy_lock(v11 + 192);
    wlan_minidump_remove(v11, 208, *(_QWORD *)(a1 + 80), 55, "wlan_ser_pdev_obj");
    _qdf_mem_free(v11);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: ser_pdev_obj NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_serialization_pdev_destroy_handler");
    return 4;
  }
  return v12;
}
