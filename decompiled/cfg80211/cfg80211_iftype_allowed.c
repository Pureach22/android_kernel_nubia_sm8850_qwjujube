unsigned __int64 __fastcall cfg80211_iftype_allowed(__int64 a1, int a2, char a3, char a4)
{
  __int64 v5; // x9
  _BOOL4 v6; // w8

  if ( a4 == 1 )
  {
    v5 = (1LL << a2) & *(unsigned __int16 *)(a1 + 92);
    v6 = v5 != 0;
    if ( a2 != 4 || v5 )
      return v6;
    return (*(unsigned __int8 *)(a1 + 100) >> 5) & 1;
  }
  if ( !a4 )
  {
    if ( a2 != 4 || (a3 & 1) == 0 )
      return ((unsigned __int64)*(unsigned __int16 *)(a1 + 96) >> a2) & 1;
    return (*(unsigned __int8 *)(a1 + 100) >> 5) & 1;
  }
  return 0;
}
