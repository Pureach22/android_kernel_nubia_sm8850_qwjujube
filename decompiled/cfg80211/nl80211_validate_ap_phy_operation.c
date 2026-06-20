__int64 __fastcall nl80211_validate_ap_phy_operation(__int64 *a1)
{
  __int64 v1; // x8

  v1 = *a1;
  if ( (a1[97] || a1[98]) && (*(_BYTE *)(v1 + 13) & 0x20) != 0
    || (a1[99] || a1[100]) && (*(_BYTE *)(v1 + 14) & 0x10) != 0 )
  {
    return 4294967201LL;
  }
  else
  {
    return 0;
  }
}
