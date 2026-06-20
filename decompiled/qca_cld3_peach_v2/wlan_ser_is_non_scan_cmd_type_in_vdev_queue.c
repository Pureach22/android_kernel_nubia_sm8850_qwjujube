bool __fastcall wlan_ser_is_non_scan_cmd_type_in_vdev_queue(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  __int64 pdev_queue_obj; // x0
  __int64 v14; // x20
  __int64 vdev_obj; // x0
  __int64 v16; // x22
  __int64 list_from_vdev_queue; // x0
  _BOOL4 v18; // w19
  const char *v20; // x2

  if ( !a1 )
  {
    v20 = "%s: invalid cmd";
LABEL_14:
    qdf_trace_msg(0x4Cu, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ser_is_non_scan_cmd_type_in_vdev_queue");
    return 0;
  }
  if ( a2 )
  {
    if ( *(_QWORD *)(a1 + 216) )
    {
      pdev_obj = wlan_serialization_get_pdev_obj(*(_QWORD *)(a1 + 216));
      if ( pdev_obj )
      {
        pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, a2);
        if ( pdev_queue_obj )
        {
          v14 = pdev_queue_obj;
          vdev_obj = wlan_serialization_get_vdev_obj(a1);
          if ( vdev_obj )
          {
            v16 = vdev_obj;
            wlan_serialization_acquire_lock(v14 + 88);
            list_from_vdev_queue = wlan_serialization_get_list_from_vdev_queue(v16, a2, 0);
            v18 = wlan_serialization_find_cmd(list_from_vdev_queue, 2, 0, a2, 0, a1, 1) != 0;
            wlan_serialization_release_lock(v14 + 88);
            return v18;
          }
          v20 = "%s: invalid ser vdev obj";
        }
        else
        {
          v20 = "%s: pdev_queue is invalid";
        }
      }
      else
      {
        v20 = "%s: invalid ser pdev obj";
      }
    }
    else
    {
      v20 = "%s: invalid pdev";
    }
    goto LABEL_14;
  }
  qdf_trace_msg(
    0x4Cu,
    2u,
    "%s: invalid cmd type %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_ser_is_non_scan_cmd_type_in_vdev_queue",
    0);
  return 0;
}
