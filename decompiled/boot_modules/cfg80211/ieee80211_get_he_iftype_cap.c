_BYTE *__fastcall ieee80211_get_he_iftype_cap(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x8
  char v3; // w9
  _BYTE *result; // x0
  __int64 v5; // x9

  if ( a2 >= 0xCu )
  {
    __break(0x800u);
    return nullptr;
  }
  v2 = *(unsigned __int16 *)(a1 + 92);
  if ( !*(_WORD *)(a1 + 92) )
    return nullptr;
  v3 = a2 == 4 ? 3 : a2;
  result = (_BYTE *)(*(_QWORD *)(a1 + 96) + 2LL);
  v5 = 1LL << v3;
  while ( ((unsigned __int16)v5 & *((_WORD *)result - 1)) == 0 )
  {
    --v2;
    result += 128;
    if ( !v2 )
      return nullptr;
  }
  if ( result == (_BYTE *)&_ksymtab___cfg80211_alloc_event_skb + 2 || (*result & 1) == 0 )
    return nullptr;
  return result;
}
