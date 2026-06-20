__int64 __fastcall ieee80211_sta_update_pending_airtime(
        __int64 result,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int16 a4,
        int a5)
{
  __int64 v11; // x8
  const char *v12; // x1
  unsigned int v13; // w9
  unsigned int v15; // w9
  unsigned int v17; // w10
  unsigned int v19; // w9
  unsigned int v21; // w10
  unsigned int v27; // w9
  unsigned int v28; // w9
  unsigned int v30; // w10
  unsigned int v32; // w14
  unsigned int v34; // w10
  unsigned int v36; // w12
  unsigned int *v37; // [xsp+8h] [xbp-18h]
  __int64 v38; // [xsp+10h] [xbp-10h]
  unsigned int v39; // [xsp+1Ch] [xbp-4h]

  if ( (*(_BYTE *)(*(_QWORD *)(result + 72) + 117LL) & 1) != 0 )
  {
    if ( (a5 & 1) != 0 )
    {
      if ( a2 )
      {
        _X8 = a3;
        if ( a3 > 3u )
          goto LABEL_24;
        a5 = a4;
        _X8 = (unsigned int *)(a2 + 40LL * a3 + 556);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v27 = __ldxr(_X8);
          v28 = v27 - a4;
        }
        while ( __stlxr(v28, _X8) );
        __dmb(0xBu);
        if ( (v28 & 0x80000000) != 0 )
        {
          __asm { PRFM            #0x11, [X8] }
          while ( 1 )
          {
            v36 = __ldxr(_X8);
            if ( v36 != v28 )
              break;
            if ( !__stlxr(0, _X8) )
            {
              __dmb(0xBu);
              break;
            }
          }
        }
      }
      else
      {
        a5 = a4;
      }
      _X8 = result + 444;
      while ( 1 )
      {
        __asm { PRFM            #0x11, [X8] }
        do
          v15 = __ldxr((unsigned int *)_X8);
        while ( __stxr(v15 - a5, (unsigned int *)_X8) );
        if ( a3 <= 4u )
          break;
LABEL_24:
        __break(0x5512u);
      }
      _X10 = (unsigned int *)(result + 4LL * a3 + 448);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v19 = __ldxr(_X10);
        v13 = v19 - a5;
      }
      while ( __stlxr(v13, _X10) );
      __dmb(0xBu);
      if ( (v13 & 0x80000000) != 0 && (ieee80211_sta_update_pending_airtime___already_done & 1) == 0 )
      {
        v37 = (unsigned int *)_X8;
        v38 = result + 4LL * a3 + 448;
        v11 = *(_QWORD *)(result + 72);
        ieee80211_sta_update_pending_airtime___already_done = 1;
        v12 = *(const char **)(v11 + 504);
        if ( !v12 )
          v12 = *(const char **)(v11 + 392);
        v39 = v13;
        result = _warn_printk("Device %s AC %d pending airtime underflow: %u, %u", v12, a3, v13, a5);
        v13 = v39;
        __break(0x800u);
        _X8 = (unsigned __int64)v37;
        _X10 = (unsigned int *)v38;
      }
      else if ( (v13 & 0x80000000) == 0 )
      {
        return result;
      }
      __asm { PRFM            #0x11, [X10] }
      while ( 1 )
      {
        v32 = __ldxr(_X10);
        if ( v32 != v13 )
          break;
        if ( !__stlxr(0, _X10) )
        {
          __dmb(0xBu);
          break;
        }
      }
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr((unsigned int *)_X8);
      while ( __stxr(v34 - v13, (unsigned int *)_X8) );
    }
    else
    {
      if ( a2 )
      {
        _X8 = a3;
        if ( a3 >= 4u )
          goto LABEL_24;
        _X8 = a4;
        _X9 = (unsigned int *)(a2 + 40LL * a3 + 556);
        __asm { PRFM            #0x11, [X9] }
        do
          v30 = __ldxr(_X9);
        while ( __stxr(v30 + a4, _X9) );
      }
      else
      {
        _X8 = a4;
      }
      _X9 = (unsigned int *)(result + 444);
      __asm { PRFM            #0x11, [X9] }
      do
        v17 = __ldxr(_X9);
      while ( __stxr(v17 + _X8, _X9) );
      if ( a3 > 4u )
        goto LABEL_24;
      _X9 = (unsigned int *)(result + 4LL * a3 + 448);
      __asm { PRFM            #0x11, [X9] }
      do
        v21 = __ldxr(_X9);
      while ( __stxr(v21 + _X8, _X9) );
    }
  }
  return result;
}
