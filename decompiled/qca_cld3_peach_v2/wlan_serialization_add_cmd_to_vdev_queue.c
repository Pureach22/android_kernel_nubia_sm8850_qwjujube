__int64 __fastcall wlan_serialization_add_cmd_to_vdev_queue(__int64 a1, __int64 a2, char a3)
{
  __int64 vdev_from_cmd; // x0
  __int64 vdev_obj; // x0
  __int64 v7; // x8
  __int64 v8; // x19
  __int64 result; // x0

  vdev_from_cmd = wlan_serialization_get_vdev_from_cmd(a2 + 32);
  vdev_obj = wlan_serialization_get_vdev_obj(vdev_from_cmd);
  v7 = 24;
  v8 = vdev_obj;
  if ( a3 )
    v7 = 0;
  result = wlan_serialization_add_cmd_to_queue(vdev_obj + v7);
  if ( (*(_BYTE *)(a2 + 52) & 4) != 0 )
    *(_BYTE *)(v8 + 48) = 1;
  return result;
}
