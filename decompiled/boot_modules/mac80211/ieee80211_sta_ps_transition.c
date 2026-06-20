__int64 __fastcall ieee80211_sta_ps_transition(__int64 a1, char a2)
{
  __int64 v3; // x0
  unsigned __int64 v10; // x9
  unsigned __int64 v12; // x10
  unsigned __int64 v14; // x10

  if ( (*(_QWORD *)(*(_QWORD *)(a1 - 2616) + 96LL) & 0x100000) == 0 )
    __break(0x800u);
  _X8 = (unsigned __int64 *)(a1 - 2472);
  if ( ((*(_QWORD *)(a1 - 2472) >> 2) & 1) == (a2 & 1) )
    return 4294967274LL;
  v3 = a1 - 2688;
  if ( (a2 & 1) != 0 )
  {
    sta_ps_start(v3);
  }
  else if ( (*_X8 & 0x200) != 0 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  }
  else
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 | 0x2000000, _X8) );
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    ieee80211_sta_ps_deliver_wakeup();
  }
  return 0;
}
