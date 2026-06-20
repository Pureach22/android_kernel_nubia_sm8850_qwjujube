bool __fastcall cm_ese_open_present(__int64 a1, __int64 a2, char a3)
{
  return wlan_vdev_is_open_mode(a1) && (a3 & 1) != 0 && (*(_BYTE *)(a2 + 1562) & 1) != 0;
}
