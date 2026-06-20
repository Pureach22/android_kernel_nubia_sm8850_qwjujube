__int64 __fastcall action_oui_psoc_create_notification(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  qdf_trace_msg(0x63u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "action_oui_psoc_create_notification");
  v10 = _qdf_mem_malloc(0x5D00u, "action_oui_psoc_create_notification", 331);
  if ( v10 )
  {
    v19 = v10;
    if ( (unsigned int)wlan_objmgr_psoc_component_obj_attach(a1, 0x1Cu, v10, 0) )
    {
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: Failed to attach priv with psoc",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "action_oui_psoc_create_notification");
      _qdf_mem_free(v19);
      v28 = 4;
    }
    else
    {
      target_if_action_oui_register_tx_ops(v19 + 23768);
      *(_QWORD *)v19 = a1;
      *(_BYTE *)(v19 + 8) = *(_DWORD *)(cfg_psoc_get_values(a1) + 31760);
      qdf_trace_msg(
        0x63u,
        8u,
        "%s: psoc priv attached",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "action_oui_psoc_create_notification");
      v28 = 0;
    }
  }
  else
  {
    v28 = 2;
  }
  qdf_trace_msg(0x63u, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "action_oui_psoc_create_notification");
  return v28;
}
