__int64 __fastcall wlan_serialization_remove_cmd_from_vdev_queue(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 vdev_from_cmd; // x0
  __int64 vdev_obj; // x0
  __int64 v10; // x8

  vdev_from_cmd = wlan_serialization_get_vdev_from_cmd(a3);
  vdev_obj = wlan_serialization_get_vdev_obj(vdev_from_cmd);
  v10 = 24;
  if ( a4 )
    v10 = 0;
  return wlan_serialization_remove_cmd_from_queue(vdev_obj + v10, a3, a2, a1, 1);
}
