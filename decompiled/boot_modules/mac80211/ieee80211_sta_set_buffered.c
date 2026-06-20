__int64 __fastcall ieee80211_sta_set_buffered(__int64 result, unsigned __int8 a2, char a3)
{
  __int64 v3; // x9
  __int64 v4; // x0
  __int64 v6; // x8
  unsigned __int64 v8; // x10
  unsigned __int64 v14; // x10

  if ( a2 >= 0x10u )
  {
    __break(0x800u);
  }
  else
  {
    v3 = result;
    v4 = result - 2688;
    _X9 = (unsigned __int64 *)(v3 - 2264);
    v6 = 1LL << a2;
    if ( (a3 & 1) != 0 )
    {
      __asm { PRFM            #0x11, [X9] }
      do
        v8 = __ldxr(_X9);
      while ( __stxr(v8 | v6, _X9) );
    }
    else
    {
      __asm { PRFM            #0x11, [X9] }
      do
        v14 = __ldxr(_X9);
      while ( __stxr(v14 & ~v6, _X9) );
    }
    return _sta_info_recalc_tim(v4, 0);
  }
  return result;
}
