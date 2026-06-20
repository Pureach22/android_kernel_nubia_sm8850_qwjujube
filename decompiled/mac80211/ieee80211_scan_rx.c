_QWORD *__fastcall ieee80211_scan_rx(_QWORD *result, __int64 a2)
{
  _WORD *v2; // x20
  __int64 v4; // x19
  unsigned __int64 v5; // x9
  int v6; // w10
  __int64 v7; // x8
  __int64 v8; // x22
  __int64 v9; // x10
  __int64 v10; // x9
  __int64 v11; // x2
  unsigned int v12; // w24
  char v13; // w9
  char v14; // w8
  unsigned __int64 v21; // x8
  unsigned __int64 v24; // x9
  _QWORD *v25; // [xsp+8h] [xbp-8h]

  v2 = *(_WORD **)(a2 + 224);
  v4 = (__int64)result;
  v5 = 36;
  v6 = *v2 & 0xFC;
  if ( v6 != 128 && v6 != 80 )
  {
    if ( v6 != 28 )
      return result;
    v5 = 18;
    if ( (*v2 & 0x1FC) != 0x11C )
      v5 = 4;
  }
  if ( v5 <= *(unsigned int *)(a2 + 112) )
  {
    _X9 = result + 587;
    __asm { PRFM            #0x11, [X9] }
    do
      v21 = __ldxr(_X9);
    while ( __stlxr(v21 & 0xFFFFFFFFFFFFFFBFLL, _X9) );
    __dmb(0xBu);
    if ( (v21 & 0x40) != 0 )
    {
      _X8 = result + 587;
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 | 0x80, _X8) );
      wiphy_delayed_work_queue(result[9], result + 612, 0);
    }
    result = (_QWORD *)ieee80211_get_channel_khz(
                         *(_QWORD *)(v4 + 72),
                         ((*(unsigned __int16 *)(a2 + 68) << 18 >> 31) & 0x1F4) + 1000 * (*(_WORD *)(a2 + 68) & 0x1FFFu));
    if ( result )
    {
      if ( (*((_BYTE *)result + 12) & 1) == 0 )
      {
        if ( (*v2 & 0xFC) == 0x50 )
        {
          v7 = *(_QWORD *)(v4 + 4968);
          v8 = *(_QWORD *)(v4 + 4856);
          if ( !(v7 | v8) )
            return result;
          v25 = result;
          v9 = *(_QWORD *)(v4 + 4752);
          v10 = *(_QWORD *)(v4 + 4864);
          v11 = v9 ? *(unsigned int *)(v9 + 36) : 0LL;
          v12 = v10 ? *(_DWORD *)(v10 + 40) : 0;
          v13 = ieee80211_scan_accept_presp(v7, result, v11, v2 + 2);
          result = v25;
          if ( (v13 & 1) == 0 )
          {
            v14 = ieee80211_scan_accept_presp(v8, v25, v12, v2 + 2);
            result = v25;
            if ( (v14 & 1) == 0 )
              return result;
          }
        }
        else if ( (unsigned __int16)(v2[3] & v2[2] & v2[4]) != 0xFFFF )
        {
          return result;
        }
        if ( *(_DWORD *)(v4 + 1316) != *(_DWORD *)(v4 + 1320) )
        {
          result = ieee80211_bss_info_update(v4, a2 + 40, v2, *(unsigned int *)(a2 + 112), (__int64)result);
          if ( result )
            return (_QWORD *)cfg80211_put_bss(*(_QWORD *)(v4 + 72), result - 12);
        }
      }
    }
  }
  return result;
}
