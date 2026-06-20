__int64 __fastcall wlan_green_ap_pdev_obj_destroy_notification(
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
  __int64 v19; // x19
  const char *v20; // x2
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( !a1 )
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: pdev context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_green_ap_pdev_obj_destroy_notification");
    return 4;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !comp_private_obj )
  {
    v20 = "%s: green ap context is already NULL";
    goto LABEL_7;
  }
  v19 = comp_private_obj;
  qdf_trace_msg(
    0x5Du,
    4u,
    "%s: Deleting green ap pdev obj, green ap ctx: %pK, pdev: %pK",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_green_ap_pdev_obj_destroy_notification",
    comp_private_obj,
    a1);
  if ( (unsigned int)wlan_objmgr_pdev_component_obj_detach(a1, 0x16u, v19) )
  {
    v20 = "%s: Failed to detach green ap ctx in psoc ctx";
LABEL_7:
    qdf_trace_msg(0x5Du, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "wlan_green_ap_pdev_obj_destroy_notification");
    return 16;
  }
  timer_delete_sync(v19 + 32);
  _qdf_mem_free(v19);
  qdf_trace_msg(
    0x5Du,
    4u,
    "%s: green ap deletion successful",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wlan_green_ap_pdev_obj_destroy_notification");
  return 0;
}
