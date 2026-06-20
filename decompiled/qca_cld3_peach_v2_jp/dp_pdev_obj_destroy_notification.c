__int64 __fastcall dp_pdev_obj_destroy_notification(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 comp_private_obj; // x0
  __int64 v19; // x19
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  const char *v31; // x2
  unsigned int v32; // w0

  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP PDEV OBJ destroy notification",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_pdev_obj_destroy_notification");
  if ( !*(_QWORD *)(a1 + 80) )
  {
    v31 = "%s: psoc is NULL in pdev";
    v32 = 87;
LABEL_7:
    qdf_trace_msg(v32, 2u, v31, v10, v11, v12, v13, v14, v15, v16, v17, "dp_pdev_obj_destroy_notification");
    return 16;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    v31 = "%s: Failed to get dp_ctx from pdev";
    v32 = 69;
    goto LABEL_7;
  }
  v19 = comp_private_obj;
  v20 = wlan_objmgr_pdev_component_obj_detach(a1, 0x2Eu, comp_private_obj);
  if ( v20 )
  {
    v29 = v20;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to detach dp_ctx from pdev",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dp_pdev_obj_destroy_notification");
    return v29;
  }
  else
  {
    if ( !*(_QWORD *)(v19 + 8) )
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: DP Pdev is NULL",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "dp_pdev_obj_destroy_notification");
    *(_QWORD *)(v19 + 8) = 0;
    return 0;
  }
}
