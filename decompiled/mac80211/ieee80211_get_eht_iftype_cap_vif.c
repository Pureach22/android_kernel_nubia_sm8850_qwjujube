__int64 __fastcall ieee80211_get_eht_iftype_cap_vif(__int64 a1, unsigned int *a2)
{
  unsigned int v3; // w9
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x9
  __int64 result; // x0
  char v8; // t1

  v3 = (unsigned __int8)ieee80211_vif_type_p2p(a2);
  if ( v3 >= 0xC )
  {
    __break(0x800u);
    return 0;
  }
  v4 = *(unsigned __int16 *)(a1 + 92);
  if ( !*(_WORD *)(a1 + 92) )
    return 0;
  v5 = *(_QWORD *)(a1 + 96);
  if ( v3 == 4 )
    LOBYTE(v3) = 3;
  v6 = 1LL << v3;
  while ( ((unsigned __int16)v6 & *(_WORD *)v5) == 0 )
  {
    --v4;
    v5 += 128;
    if ( !v4 )
      return 0;
  }
  if ( !v5 )
    return 0;
  v8 = *(_BYTE *)(v5 + 59);
  result = v5 + 59;
  if ( (v8 & 1) == 0 )
    return 0;
  return result;
}
