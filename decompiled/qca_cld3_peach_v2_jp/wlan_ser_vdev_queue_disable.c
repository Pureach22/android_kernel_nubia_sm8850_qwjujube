__int64 __fastcall wlan_ser_vdev_queue_disable(
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
  __int64 pdev_obj; // x0
  __int64 v12; // x20
  __int64 vdev_obj; // x0
  __int64 vdev_queue_obj; // x0
  __int64 v15; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v25; // x2

  v10 = *(_QWORD *)(a1 + 152);
  if ( v10 )
  {
    pdev_obj = wlan_serialization_get_pdev_obj(v10);
    if ( pdev_obj )
    {
      v12 = pdev_obj;
      vdev_obj = wlan_serialization_get_vdev_obj(a1);
      if ( vdev_obj )
      {
        vdev_queue_obj = wlan_serialization_get_vdev_queue_obj(vdev_obj, 1);
        if ( vdev_queue_obj )
        {
          v15 = vdev_queue_obj;
          wlan_serialization_acquire_lock(v12 + 192);
          *(_BYTE *)(v15 + 48) = 1;
          wlan_serialization_release_lock(v12 + 192);
          qdf_trace_msg(
            0x4Cu,
            8u,
            "%s: Disabling the serialization for vdev:%d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "wlan_ser_vdev_queue_disable",
            *(unsigned __int8 *)(a1 + 104));
          return 0;
        }
        v25 = "%s: invalid vdev_queue object";
      }
      else
      {
        v25 = "%s: invalid ser_vdev_obj";
      }
    }
    else
    {
      v25 = "%s: invalid ser_pdev_obj";
    }
  }
  else
  {
    v25 = "%s: invalid PDEV object";
  }
  qdf_trace_msg(0x4Cu, 2u, v25, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ser_vdev_queue_disable");
  return 4;
}
