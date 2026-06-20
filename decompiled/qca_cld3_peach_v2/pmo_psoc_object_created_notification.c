__int64 __fastcall pmo_psoc_object_created_notification(
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
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x19
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w19
  const char *v37; // x2

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_psoc_object_created_notification");
  if ( !pmo_get_context() )
  {
    v37 = "%s: unable to get pmo ctx";
LABEL_6:
    qdf_trace_msg(0x4Du, 2u, v37, v10, v11, v12, v13, v14, v15, v16, v17, "pmo_psoc_object_created_notification");
    v36 = 16;
    goto LABEL_8;
  }
  v18 = _qdf_mem_malloc(0x420u, "pmo_psoc_object_created_notification", 160);
  if ( !v18 )
  {
    v36 = 2;
    goto LABEL_8;
  }
  v27 = v18;
  if ( !(unsigned int)wlan_objmgr_psoc_component_obj_attach(a1, 4u, v18, 0) )
  {
    *(_DWORD *)(v27 + 1040) = 0;
    *(_QWORD *)(v27 + 1048) = 0;
    _qdf_wake_lock_create((_QWORD *)(v27 + 584), (__int64)"pmo_wow_wl");
    if ( (unsigned int)qdf_event_create((_DWORD *)(v27 + 496)) )
    {
      v37 = "%s: target suspend event initialization failed";
    }
    else
    {
      if ( !(unsigned int)qdf_event_create((_DWORD *)(v27 + 536)) )
      {
        *(_DWORD *)(v27 + 580) = 0;
        target_if_pmo_register_tx_ops(v27 + 128);
        v36 = 0;
        goto LABEL_8;
      }
      v37 = "%s: target resume event initialization failed";
    }
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x4Du,
    2u,
    "%s: Failed to attach psoc_ctx with psoc",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "pmo_psoc_object_created_notification");
  _qdf_mem_free(v27);
  v36 = 16;
LABEL_8:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "pmo_psoc_object_created_notification");
  return v36;
}
