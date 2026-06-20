__int64 __fastcall wlan_serialization_get_active_cmd(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 pdev_obj; // x0
  __int64 pdev_queue_obj; // x21
  __int64 cmd; // x0
  __int64 v18; // x20
  const char *v19; // x2
  const char *v20; // x2
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( a1 )
  {
    v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 9);
    if ( v12 )
    {
      v13 = v12;
      v14 = *(_QWORD *)(v12 + 216);
      if ( v14 )
      {
        pdev_obj = wlan_serialization_get_pdev_obj(v14);
        if ( pdev_obj )
        {
          pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, a3);
          wlan_serialization_acquire_lock(pdev_queue_obj + 88);
          cmd = wlan_serialization_find_cmd(pdev_queue_obj, 2, 0, a3, 0, v13, 0);
          if ( cmd )
            v18 = *(_QWORD *)(cmd + 72);
          else
            v18 = 0;
          wlan_serialization_release_lock(pdev_queue_obj + 88);
          goto LABEL_15;
        }
        v20 = "%s: invalid ser_pdev_obj";
      }
      else
      {
        v20 = "%s: invalid pdev";
      }
      qdf_trace_msg(0x4Cu, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_serialization_get_active_cmd");
      v18 = 0;
LABEL_15:
      wlan_objmgr_vdev_release_ref(v13, 9u, v21, v22, v23, v24, v25, v26, v27, v28, v29);
      return v18;
    }
    v19 = "%s: invalid vdev";
  }
  else
  {
    v19 = "%s: invalid psoc";
  }
  qdf_trace_msg(0x4Cu, 2u, v19, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_serialization_get_active_cmd");
  return 0;
}
