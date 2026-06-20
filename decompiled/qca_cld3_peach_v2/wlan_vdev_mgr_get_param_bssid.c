void *__fastcall wlan_vdev_mgr_get_param_bssid(__int64 a1, void *a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  if ( comp_private_obj )
    return qdf_mem_copy(a2, (const void *)(comp_private_obj + 184), 6u);
  else
    return (void *)qdf_trace_msg(
                     0x68u,
                     2u,
                     "%s: VDEV_MLME is NULL",
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     "wlan_vdev_mgr_get_param_bssid");
}
