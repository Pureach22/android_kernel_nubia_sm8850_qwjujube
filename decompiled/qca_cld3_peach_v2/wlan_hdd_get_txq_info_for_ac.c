__int64 __fastcall wlan_hdd_get_txq_info_for_ac(__int64 result, int a2, _BYTE *a3, _BYTE *a4)
{
  if ( *(_DWORD *)(result + 40) == 11 && a2 == 4 )
  {
    *a4 = 33;
    *a3 = 13;
  }
  else
  {
    *a4 = 4;
    *a3 = 4 * a2 - 3;
  }
  return result;
}
