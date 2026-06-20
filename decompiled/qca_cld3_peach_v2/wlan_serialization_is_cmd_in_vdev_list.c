bool __fastcall wlan_serialization_is_cmd_in_vdev_list(__int64 a1, __int64 a2, unsigned int a3)
{
  return wlan_serialization_find_cmd(a2, 0, 0, 0, 0, a1, a3) != 0;
}
