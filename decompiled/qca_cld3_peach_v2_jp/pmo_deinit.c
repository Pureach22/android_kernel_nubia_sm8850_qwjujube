__int64 __fastcall pmo_deinit(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int handler; // w0
  unsigned int v17; // w19
  const char *v18; // x2
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v28; // w0

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "pmo_deinit");
  if ( pmo_get_context() )
  {
    handler = wlan_objmgr_unregister_psoc_create_handler(
                4u,
                (__int64)pmo_psoc_object_created_notification,
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                v15);
    if ( handler
      || (handler = wlan_objmgr_unregister_psoc_destroy_handler(
                      4u,
                      (__int64)pmo_psoc_object_destroyed_notification,
                      v8,
                      v9,
                      v10,
                      v11,
                      v12,
                      v13,
                      v14,
                      v15)) != 0 )
    {
      v17 = handler;
      v18 = "%s: unable to unregister psoc create handle";
    }
    else
    {
      v28 = wlan_objmgr_unregister_vdev_create_handler(
              4u,
              (__int64)pmo_vdev_object_created_notification,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15);
      if ( v28 )
      {
        v17 = v28;
      }
      else
      {
        v17 = wlan_objmgr_unregister_vdev_destroy_handler(
                4u,
                (__int64)pmo_vdev_object_destroyed_notification,
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                v15);
        if ( !v17 )
          goto LABEL_7;
      }
      v18 = "%s: unable to unregister vdev create handle";
    }
  }
  else
  {
    v17 = 16;
    v18 = "%s: unable to get pmo ctx";
  }
  qdf_trace_msg(0x4Du, 2u, v18, v8, v9, v10, v11, v12, v13, v14, v15, "pmo_deinit");
LABEL_7:
  pmo_free_ctx(v8, v9, v10, v11, v12, v13, v14, v15);
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "pmo_deinit");
  return v17;
}
