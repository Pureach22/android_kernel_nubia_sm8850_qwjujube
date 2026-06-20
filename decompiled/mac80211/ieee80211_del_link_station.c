__int64 __fastcall ieee80211_del_link_station(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 bss; // x0
  int v5; // w1
  __int64 v6; // x9
  unsigned int v7; // w8

  bss = sta_info_get_bss(a2 + 2688, *(_QWORD *)a3);
  if ( bss )
  {
    v5 = *(_DWORD *)(a3 + 8);
    v6 = *(unsigned __int16 *)(bss + 2872);
    v7 = -22;
    if ( 1LL << v5 != v6 && ((1LL << v5) & v6) != 0 )
    {
      ieee80211_sta_remove_link();
      return 0;
    }
  }
  else
  {
    return (unsigned int)-2;
  }
  return v7;
}
