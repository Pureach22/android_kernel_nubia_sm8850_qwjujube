bool __fastcall ieee80211_multicast_to_unicast(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x8
  int v4; // w9

  v2 = *(_DWORD *)(a2 + 7408);
  v3 = *(_QWORD *)(a1 + 224);
  if ( v2 != 3 && (v2 != 4 || *(_QWORD *)(a2 + 4968) || (*(_BYTE *)(a2 + 2769) & 1) != 0)
    || *(_BYTE *)(*(_QWORD *)(a2 + 4720) + 316LL) != 1 )
  {
    return 0;
  }
  v4 = *(unsigned __int16 *)(v3 + 12);
  if ( v4 == 129 )
  {
    if ( *(_DWORD *)(a1 + 112) < 0x12u )
      return 0;
    v4 = *(unsigned __int16 *)(v3 + 16);
  }
  return v4 == 8 || v4 == 56710 || v4 == 1544;
}
