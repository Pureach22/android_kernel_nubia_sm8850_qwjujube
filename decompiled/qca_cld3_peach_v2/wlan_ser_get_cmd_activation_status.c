__int64 __fastcall wlan_ser_get_cmd_activation_status(__int64 a1)
{
  __int64 v2; // x0
  __int64 pdev_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 pdev_queue_obj; // x19
  __int64 vdev_obj; // x0
  __int64 vdev_queue_obj; // x20
  int v15; // w0
  unsigned int v16; // w20
  const char *v17; // x2
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 216);
  v19 = 0;
  pdev_obj = wlan_serialization_get_pdev_obj(v2);
  if ( !pdev_obj )
  {
    v17 = "%s: invalid ser_pdev_obj";
LABEL_8:
    qdf_trace_msg(0x4Cu, 2u, v17, v4, v5, v6, v7, v8, v9, v10, v11, "wlan_ser_get_cmd_activation_status", v19, v20);
    v16 = 16;
    goto LABEL_9;
  }
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, 1);
  vdev_obj = wlan_serialization_get_vdev_obj(a1);
  if ( !vdev_obj )
  {
    v17 = "%s: invalid ser_vdev_obj";
    goto LABEL_8;
  }
  vdev_queue_obj = wlan_serialization_get_vdev_queue_obj(vdev_obj, 1);
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  v15 = wlan_serialization_peek_front(vdev_queue_obj, &v19);
  v16 = 16;
  if ( !v15 )
    v16 = ~(8 * *(_QWORD *)(v19 + 64)) & 0x10;
  wlan_serialization_release_lock(pdev_queue_obj + 88);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v16;
}
