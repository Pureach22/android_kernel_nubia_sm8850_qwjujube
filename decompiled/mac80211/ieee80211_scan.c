__int64 __fastcall ieee80211_scan(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  unsigned int v3; // w10
  int v4; // w10

  v2 = *(_QWORD *)(a2 + 64);
  v3 = *(_DWORD *)(v2 + 4704);
  if ( *(_BYTE *)(v2 + 5832) == 1 )
  {
    if ( v3 > 0xA )
      return 4294967201LL;
    v4 = 1 << v3;
    if ( (v4 & 0x586) != 0 )
      return (unsigned int)ieee80211_request_scan(v2 - 16);
    if ( (v4 & 0x208) == 0 )
      return 4294967201LL;
LABEL_10:
    if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 1600) + 464LL) + 184LL) )
      return (unsigned int)ieee80211_request_scan(v2 - 16);
    goto LABEL_11;
  }
  if ( v3 > 0xA )
    return 4294967201LL;
  if ( ((1 << v3) & 0x586) != 0 )
    return (unsigned int)ieee80211_request_scan(v2 - 16);
  if ( v3 != 3 )
  {
    if ( v3 != 9 )
      return 4294967201LL;
    goto LABEL_10;
  }
LABEL_11:
  if ( *(_QWORD *)(v2 + 4136) )
  {
    if ( (*(_BYTE *)(a1 + 109) & 1) == 0 )
      return 4294967201LL;
    if ( (*(_BYTE *)(a2 + 36) & 4) == 0 )
      return 4294967201LL;
  }
  return (unsigned int)ieee80211_request_scan(v2 - 16);
}
