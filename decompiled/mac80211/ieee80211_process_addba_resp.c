__int64 __fastcall ieee80211_process_addba_resp(__int64 result, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x22
  __int64 v4; // x19
  __int64 v5; // x8
  unsigned int v6; // w23
  __int64 v7; // x9
  __int64 v8; // x21
  __int64 v9; // x25
  __int64 v12; // x9
  int v13; // w8
  __int64 v14; // x20
  __int64 v15; // x0
  unsigned __int64 v18; // x10
  unsigned __int64 v25; // x10

  v3 = *(unsigned __int16 *)(a3 + 29);
  v4 = (v3 >> 2) & 0xF;
  v5 = a2 + 8 * v4;
  if ( (unsigned int)v3 >> 6 >= *(unsigned __int16 *)(result + 138) )
    v6 = *(unsigned __int16 *)(result + 138);
  else
    v6 = (unsigned int)v3 >> 6;
  if ( (v3 & 1) == 0 && (v7 = *(_QWORD *)(v5 + 2736)) != 0 )
  {
    _X9 = (unsigned __int64 *)(v7 - 8);
    __asm { PRFM            #0x11, [X9] }
    do
      v18 = __ldxr(_X9);
    while ( __stxr(v18 | 4, _X9) );
    v8 = *(_QWORD *)(v5 + 904);
    if ( !v8 )
      return result;
  }
  else
  {
    v8 = *(_QWORD *)(v5 + 904);
    if ( !v8 )
      return result;
  }
  if ( *(unsigned __int8 *)(a3 + 26) == *(unsigned __int8 *)(v8 + 146) )
  {
    v9 = result;
    result = timer_delete_sync(v8 + 56);
    if ( (*(_QWORD *)(v8 + 128) & 0x20) == 0 && (*(_QWORD *)(v8 + 128) & 8) == 0 )
    {
      result = a2;
      v12 = a3;
      if ( *(_WORD *)(a3 + 27) || !v6 )
      {
        return _ieee80211_stop_tx_ba_session(a2, v4, 0);
      }
      else
      {
        _X11 = (unsigned __int64 *)(v8 + 128);
        __asm { PRFM            #0x11, [X11] }
        do
          v25 = __ldxr(_X11);
        while ( __stlxr(v25 | 2, _X11) );
        __dmb(0xBu);
        if ( (v25 & 2) == 0 )
        {
          *(_WORD *)(v8 + 150) = v6;
          *(_BYTE *)(v8 + 157) = v3 & 1;
          if ( (*(_QWORD *)(v8 + 128) & 1) != 0 )
          {
            ieee80211_agg_tx_operational(v9, a2, v4);
            result = a2;
            v12 = a3;
          }
          *(_BYTE *)(result + v4 + 1288) = 0;
          v13 = *(unsigned __int16 *)(v12 + 31);
          *(_WORD *)(v8 + 144) = v13;
          if ( v13 )
          {
            v14 = jiffies;
            v15 = _usecs_to_jiffies((unsigned int)(v13 << 10));
            result = mod_timer(v8 + 16, v15 + v14);
            *(_QWORD *)(v8 + 136) = jiffies;
          }
        }
      }
    }
  }
  return result;
}
