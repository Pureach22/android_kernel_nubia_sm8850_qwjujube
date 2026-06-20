__int64 __fastcall _cfg80211_ibss_joined(__int64 result, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x21
  __int64 v4; // x19
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x9
  unsigned int v12; // w9
  unsigned int v15; // w9
  unsigned int v16; // w9
  unsigned int v19; // w10
  unsigned int v26; // w8
  unsigned int v27; // w8

  v3 = *(_QWORD **)(result + 992);
  if ( *((_DWORD *)v3 + 2) != 1 )
    goto LABEL_14;
  if ( !*((_BYTE *)v3 + 356) )
    return result;
  v4 = result;
  result = _cfg80211_get_bss(*v3, a3, a2, 0, 0, 2, 2, 1);
  if ( !result )
  {
LABEL_14:
    __break(0x800u);
    return result;
  }
  v6 = v3[35];
  v7 = result;
  if ( !v6 )
    goto LABEL_9;
  while ( 1 )
  {
    _X10 = (unsigned int *)(v6 + 80);
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v15 = __ldxr(_X10);
      v16 = v15 - 1;
    }
    while ( __stlxr(v16, _X10) );
    __dmb(0xBu);
    if ( (v16 & 0x80000000) != 0 )
    {
      __break(0x800u);
      v8 = *(_QWORD *)(v6 + 152);
      if ( v8 )
      {
LABEL_7:
        _X9 = (unsigned int *)(v8 - 32);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v26 = __ldxr(_X9);
          v27 = v26 - 1;
        }
        while ( __stlxr(v27, _X9) );
        __dmb(0xBu);
        if ( (v27 & 0x80000000) != 0 )
          __break(0x800u);
      }
    }
    else
    {
      v8 = *(_QWORD *)(v6 + 152);
      if ( v8 )
        goto LABEL_7;
    }
    cfg80211_put_bss(*v3, v3[35] + 112LL);
LABEL_9:
    _X8 = (unsigned int *)(v7 - 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 + 1, _X8) );
    v9 = *(_QWORD *)(v7 + 40);
    if ( v9 )
    {
      _X9 = (unsigned int *)(v9 - 32);
      __asm { PRFM            #0x11, [X9] }
      do
        v19 = __ldxr(_X9);
      while ( __stxr(v19 + 1, _X9) );
    }
    v3[35] = v7 - 112;
    ((void (__fastcall *)(_QWORD *))cfg80211_upload_connect_keys)(v3);
    v6 = *v3;
    if ( *v3 )
      return nl80211_send_ibss_bssid(v6 - 992, v4, a2, 3264);
    __break(0x800u);
  }
}
