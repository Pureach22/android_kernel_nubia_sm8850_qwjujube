__int64 __fastcall wlan_vdev_set_wfd_mode(__int64 result, unsigned __int8 a2)
{
  *(_DWORD *)(result + 96) = a2;
  return result;
}
