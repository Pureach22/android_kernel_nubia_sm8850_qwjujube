__int64 __fastcall dp_pdev_obj_create_notification(
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
  __int64 v18; // x0
  __int64 comp_private_obj; // x0
  __int64 v20; // x20
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19
  __int64 result; // x0
  const char *v32; // x2
  unsigned int v33; // w0

  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP PDEV OBJ create notification",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_pdev_obj_create_notification");
  v18 = *(_QWORD *)(a1 + 80);
  if ( !v18 )
  {
    v32 = "%s: psoc is NULL in pdev";
    v33 = 87;
LABEL_7:
    qdf_trace_msg(v33, 2u, v32, v10, v11, v12, v13, v14, v15, v16, v17, "dp_pdev_obj_create_notification");
    return 16;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v18, 0x2Eu);
  if ( !comp_private_obj )
  {
    v32 = "%s: Failed to get dp_ctx from psoc";
    v33 = 69;
    goto LABEL_7;
  }
  v20 = comp_private_obj;
  v21 = wlan_objmgr_pdev_component_obj_attach(a1, 0x2Eu, comp_private_obj, 0, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( v21 )
  {
    v30 = v21;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to attach dp_ctx to pdev",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dp_pdev_obj_create_notification");
    return v30;
  }
  else
  {
    *(_QWORD *)(v20 + 8) = a1;
    result = wlan_dp_stc_attach(v20);
    if ( (_DWORD)result )
    {
      wlan_dp_spm_flow_table_detach(v20);
      return 0;
    }
  }
  return result;
}
