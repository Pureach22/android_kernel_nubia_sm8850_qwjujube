__int64 __fastcall wlan_scan_vdev_created_notification(__int64 a1)
{
  void *v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  unsigned int v12; // w19
  const char *v13; // x2
  unsigned int v14; // w1

  v2 = qdf_mem_malloc_atomic_fl(0x20u, (__int64)"wlan_scan_vdev_created_notification", 0x53u);
  if ( !v2 )
  {
    v13 = "%s: Failed to allocate memory";
    v14 = 2;
    v12 = 2;
LABEL_6:
    qdf_trace_msg(0x15u, v14, v13, v3, v4, v5, v6, v7, v8, v9, v10, "wlan_scan_vdev_created_notification");
    return v12;
  }
  v11 = (__int64)v2;
  v12 = wlan_objmgr_vdev_component_obj_attach(a1, 3u, (__int64)v2, 0);
  if ( !v12 )
  {
    v13 = "%s: vdev scan object attach successful";
    v14 = 8;
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x15u,
    2u,
    "%s: Failed to attach vdev scan component",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_scan_vdev_created_notification");
  _qdf_mem_free(v11);
  return v12;
}
