__int64 __fastcall ieee80211_sta_pspoll(__int64 result)
{
  unsigned __int64 v7; // x9

  _X8 = (unsigned __int64 *)(result - 2472);
  if ( (*(_QWORD *)(result - 2472) & 0x40000) == 0 )
  {
    if ( (*_X8 & 0x200) != 0 )
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v7 = __ldxr(_X8);
      while ( __stxr(v7 | 0x400, _X8) );
    }
    else
    {
      return ieee80211_sta_ps_deliver_poll_response(result - 2688);
    }
  }
  return result;
}
