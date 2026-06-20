bool __fastcall wlan_serialization_any_vdev_cmd_active(__int64 a1)
{
  return *(_QWORD *)(a1 + 72) != 0;
}
