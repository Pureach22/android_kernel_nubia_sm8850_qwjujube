_BYTE *__fastcall ieee80211_get_he_iftype_cap_vif(__int64 a1, __int64 a2)
{
  unsigned int v3; // w9
  __int64 v4; // x8
  __int64 v5; // x9
  _BYTE *result; // x0

  v3 = (unsigned __int8)ieee80211_vif_type_p2p(a2);
  if ( v3 >= 0xC )
  {
    __break(0x800u);
    return nullptr;
  }
  v4 = *(unsigned __int16 *)(a1 + 92);
  if ( !*(_WORD *)(a1 + 92) )
    return nullptr;
  if ( v3 == 4 )
    LOBYTE(v3) = 3;
  v5 = 1LL << v3;
  for ( result = (_BYTE *)(*(_QWORD *)(a1 + 96) + 2LL); ((unsigned __int16)v5 & *((_WORD *)result - 1)) == 0; result += 128 )
  {
    if ( !--v4 )
      return nullptr;
  }
  if ( result == byte_2 || (*result & 1) == 0 )
    return nullptr;
  return result;
}
