__int64 __fastcall pmo_init(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  const char *v25; // x2
  __int64 context; // x0
  __int64 v27; // x20
  unsigned int handler; // w0
  unsigned int v30; // w0

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "pmo_init");
  if ( (unsigned int)pmo_allocate_ctx(v8, v9, v10, v11, v12, v13, v14, v15) )
  {
    v24 = 5;
    v25 = "%s: unable to allocate psoc ctx";
  }
  else
  {
    context = pmo_get_context();
    if ( context )
    {
      v27 = context;
      handler = wlan_objmgr_register_psoc_create_handler(
                  4u,
                  (__int64)pmo_psoc_object_created_notification,
                  context,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23);
      if ( handler
        || (handler = wlan_objmgr_register_psoc_destroy_handler(
                        4u,
                        (__int64)pmo_psoc_object_destroyed_notification,
                        v27,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        v22,
                        v23)) != 0 )
      {
        v24 = handler;
        v25 = "%s: unable to register psoc create handle";
      }
      else
      {
        v30 = wlan_objmgr_register_vdev_create_handler(
                4u,
                (__int64)pmo_vdev_object_created_notification,
                v27,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23);
        if ( v30 )
        {
          v24 = v30;
        }
        else
        {
          v24 = wlan_objmgr_register_vdev_destroy_handler(
                  4u,
                  (__int64)pmo_vdev_object_destroyed_notification,
                  v27,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23);
          if ( !v24 )
            goto LABEL_9;
        }
        v25 = "%s: unable to register vdev create handle";
      }
    }
    else
    {
      v24 = 4;
      v25 = "%s: unable to get pmo ctx";
    }
  }
  qdf_trace_msg(0x4Du, 2u, v25, v16, v17, v18, v19, v20, v21, v22, v23, "pmo_init");
LABEL_9:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v16, v17, v18, v19, v20, v21, v22, v23, "pmo_init");
  return v24;
}
