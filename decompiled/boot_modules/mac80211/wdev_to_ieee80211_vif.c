__int64 __fastcall wdev_to_ieee80211_vif(__int64 a1)
{
  if ( (*(_QWORD *)(a1 + 1616) & 1) == 0 )
    return 0;
  if ( (*(_BYTE *)(a1 + 1608) & 0x20) != 0 )
    return a1 + 4704;
  return 0;
}
