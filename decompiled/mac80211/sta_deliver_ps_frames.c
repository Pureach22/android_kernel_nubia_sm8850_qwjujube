__int64 __fastcall sta_deliver_ps_frames(__int64 result)
{
  unsigned __int64 StatusReg; // x9
  __int64 v2; // x8
  __int64 v3; // x9
  _QWORD *v4; // x0
  unsigned int v5; // w1
  unsigned __int8 v6; // w2
  unsigned int v7; // w3
  unsigned __int64 v14; // x9
  int v15; // w8
  unsigned __int64 v18; // x9

  if ( (*(_BYTE *)(result + 34) & 1) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v2 = result;
    *(_DWORD *)(StatusReg + 16) += 512;
    v3 = *(_QWORD *)(result + 48);
    v4 = (_QWORD *)(result - 168);
    if ( (v3 & 4) != 0 )
    {
      _X10 = (unsigned __int64 *)(v2 + 48);
      __asm { PRFM            #0x11, [X10] }
      do
        v14 = __ldxr(_X10);
      while ( __stlxr(v14 & 0xFFFFFFFFFFFFFBFFLL, _X10) );
      __dmb(0xBu);
      if ( (v14 & 0x400) != 0 )
      {
        v15 = *(unsigned __int8 *)(v2 + 2531);
        v5 = 1;
        v7 = 0;
        if ( v15 == 15 )
          v6 = 0;
        else
          v6 = v15;
      }
      else
      {
        _X10 = (unsigned __int64 *)(v2 + 48);
        __asm { PRFM            #0x11, [X10] }
        do
          v18 = __ldxr(_X10);
        while ( __stlxr(v18 & 0xFFFFFFFFFFFDFFFFLL, _X10) );
        __dmb(0xBu);
        if ( (v18 & 0x20000) == 0 || !*(_BYTE *)(v2 + 2531) )
          return local_bh_enable_1(v4);
        v5 = *(unsigned __int8 *)(v2 + 2532);
        if ( v5 <= 3 )
          v5 = dword_C1540[*(unsigned __int8 *)(v2 + 2532)];
        v6 = ~*(_BYTE *)(v2 + 2531);
        v7 = 1;
      }
      v4 = ieee80211_sta_ps_deliver_response(v4, v5, v6, v7);
    }
    else
    {
      v4 = ieee80211_sta_ps_deliver_wakeup(v4);
    }
    return local_bh_enable_1(v4);
  }
  return result;
}
