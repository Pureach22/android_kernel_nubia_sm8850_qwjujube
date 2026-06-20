__int64 __fastcall ieee80211_mgd_ssid_mismatch(__int64 a1, __int64 a2)
{
  const void *v2; // x8
  size_t v3; // x2
  __int64 result; // x0
  __int64 v7; // x0

  v2 = *(const void **)(a2 + 48);
  if ( !v2 )
    return 0;
  v3 = *(unsigned __int8 *)(a2 + 697);
  if ( !*(_BYTE *)(a2 + 697) )
    return 0;
  if ( *(_QWORD *)(a1 + 4792) != v3 )
    return 1;
  if ( (unsigned int)v3 >= 0x21 )
  {
    v7 = _fortify_panic(22);
    return ieee80211_check_tim(v7);
  }
  else
  {
    result = bcmp(v2, &ieee80211_mgd_ssid_mismatch_zero_ssid, v3);
    if ( (_DWORD)result )
      return bcmp(*(const void **)(a2 + 48), (const void *)(a1 + 4760), *(_QWORD *)(a1 + 4792)) != 0;
  }
  return result;
}
