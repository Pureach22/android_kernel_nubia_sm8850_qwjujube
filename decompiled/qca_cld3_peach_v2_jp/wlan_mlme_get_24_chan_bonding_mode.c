__int64 __fastcall wlan_mlme_get_24_chan_bonding_mode(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0

  result = cfg_psoc_get_values(a1);
  *a2 = *(_DWORD *)(result + 7336);
  return result;
}
