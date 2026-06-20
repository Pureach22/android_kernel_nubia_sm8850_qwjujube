__int64 __fastcall ieee80211_set_tx_key(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x9
  unsigned __int64 v11; // x11
  unsigned __int64 v14; // x10

  v2 = a1[2];
  v3 = *a1;
  _X10 = (unsigned __int64 *)(v2 + 216);
  __asm { PRFM            #0x11, [X10] }
  do
    v11 = __ldxr(_X10);
  while ( __stxr(v11 | 0x4000000, _X10) );
  *(_BYTE *)(v2 + 120) = *((_BYTE *)a1 + 551);
  if ( (*(_QWORD *)(v3 + 96) & 0x800000000000LL) == 0 )
  {
    _X8 = (unsigned __int64 *)(v2 + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
  }
  ieee80211_check_fast_xmit(v2);
  return 0;
}
