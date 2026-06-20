__int64 __fastcall ieee80211_sta_block_awake(__int64 a1, __int64 a2, char a3)
{
  __int64 result; // x0
  unsigned __int64 v10; // x10
  unsigned __int64 v12; // x8
  unsigned __int64 v14; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v18; // x11

  _X9 = (unsigned __int64 *)(a2 - 2472);
  if ( (a3 & 1) != 0 )
  {
    __asm { PRFM            #0x11, [X9] }
    do
      v10 = __ldxr(_X9);
    while ( __stxr(v10 | 0x200, _X9) );
    return ieee80211_clear_fast_xmit(a2 - 2688);
  }
  if ( (*_X9 & 0x200) == 0 )
    return result;
  if ( (*_X9 & 4) == 0 )
  {
    __asm { PRFM            #0x11, [X9] }
    do
      v12 = __ldxr(_X9);
    while ( __stxr(v12 | 0x2000000, _X9) );
    __asm { PRFM            #0x11, [X9] }
    do
      v14 = __ldxr(_X9);
    while ( __stxr(v14 & 0xFFFFFFFFFFFFFDFFLL, _X9) );
    return ieee80211_queue_work();
  }
  if ( (*_X9 & 0x400) != 0 || (*_X9 & 0x20000) != 0 )
  {
    __asm { PRFM            #0x11, [X9] }
    do
      v16 = __ldxr(_X9);
    while ( __stxr(v16 & 0xFFFFFFFFFFFFFDFFLL, _X9) );
    return ieee80211_queue_work();
  }
  __asm { PRFM            #0x11, [X9] }
  do
    v18 = __ldxr(_X9);
  while ( __stxr(v18 & 0xFFFFFFFFFFFFFDFFLL, _X9) );
  return ieee80211_check_fast_xmit(a2 - 2688);
}
