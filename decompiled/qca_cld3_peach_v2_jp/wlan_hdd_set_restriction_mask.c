__int64 __fastcall wlan_hdd_set_restriction_mask(__int64 result)
{
  *(_DWORD *)(result + 848) = *(_DWORD *)(result + 2496);
  return result;
}
