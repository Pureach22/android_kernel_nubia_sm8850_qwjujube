__int64 __fastcall ieee80211_set_tx_key(__int64 *a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x9
  unsigned __int64 v12; // x11
  unsigned __int64 v15; // x10

  v3 = a1[2];
  v4 = *a1;
  _X10 = (unsigned __int64 *)(v3 + 216);
  __asm { PRFM            #0x11, [X10] }
  do
    v12 = __ldxr(_X10);
  while ( __stxr(v12 | 0x4000000, _X10) );
  *(_BYTE *)(v3 + 120) = *((_BYTE *)a1 + 551);
  if ( (a2 & 1) != 0 || (*(_QWORD *)(v4 + 96) & 0x800000000000LL) == 0 )
  {
    _X8 = (unsigned __int64 *)(v3 + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
  }
  return ieee80211_check_fast_xmit(v3);
}
