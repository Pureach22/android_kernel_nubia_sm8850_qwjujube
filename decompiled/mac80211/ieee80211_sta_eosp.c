__int64 __fastcall ieee80211_sta_eosp(__int64 result)
{
  unsigned __int64 v7; // x10

  _X8 = (unsigned __int64 *)(result - 2472);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 & 0xFFFFFFFFFFFBFFFFLL, _X8) );
  return result;
}
