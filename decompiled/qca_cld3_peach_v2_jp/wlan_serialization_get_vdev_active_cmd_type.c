__int64 __fastcall wlan_serialization_get_vdev_active_cmd_type(__int64 a1)
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
  unsigned int v15; // w20
  const char *v16; // x2
  __int64 v18; // [xsp+0h] [xbp-10h] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  v18 = 0;
  pdev_obj = wlan_serialization_get_pdev_obj(v2);
  if ( !pdev_obj )
  {
    v16 = "%s: invalid ser_pdev_obj";
LABEL_7:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v16,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_serialization_get_vdev_active_cmd_type",
      v18,
      v19);
    v15 = 34;
    goto LABEL_10;
  }
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, 34);
  vdev_obj = wlan_serialization_get_vdev_obj(a1);
  if ( !vdev_obj )
  {
    v16 = "%s: invalid ser_vdev_obj";
    goto LABEL_7;
  }
  vdev_queue_obj = wlan_serialization_get_vdev_queue_obj(vdev_obj, 1);
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  if ( (unsigned int)wlan_serialization_peek_front(vdev_queue_obj, &v18) )
    v15 = 34;
  else
    v15 = *(_DWORD *)(v18 + 16);
  wlan_serialization_release_lock(pdev_queue_obj + 88);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v15;
}
