unsigned __int8 *__fastcall ieee80211_bss_get_elem(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 )
    return cfg80211_find_elem_match(a2, (unsigned __int8 *)(v2 + 29), *(_DWORD *)(v2 + 24), nullptr, 0, 0);
  else
    return nullptr;
}
