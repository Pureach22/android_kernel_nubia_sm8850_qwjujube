__int64 __fastcall ieee80211_rx_handlers_result(__int64 result, int a2)
{
  __int64 v2; // x20
  __int64 *v3; // x21
  __int64 *v4; // x22
  __int64 v5; // x23
  _BYTE *v6; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v8; // x21
  __int64 v9; // x22
  int v10; // w8
  unsigned int v11; // w23
  char v12; // w10
  unsigned __int64 v19; // x9
  __int64 v20; // x0
  __int64 v21; // x10
  unsigned __int64 v24; // x12

  if ( a2 )
  {
    v6 = *(_BYTE **)(result + 8);
    if ( a2 != 1 )
    {
      if ( *(_QWORD *)(result + 40) )
        ++*(_QWORD *)(*(_QWORD *)(result + 48) + 144LL);
      if ( (a2 & 0xFFFF0000) == 0x10000 )
        return sk_skb_reason_drop(0);
    }
    StatusReg = (unsigned __int8)v6[76];
    if ( StatusReg >= 6 )
    {
      __break(0x5512u);
      goto LABEL_17;
    }
    v8 = *(_QWORD *)(result + 16);
    v9 = (v6[71] & 7) != 0
       ? 0LL
       : *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 72) + 8 * StatusReg + 328) + 8LL) + 12LL * (unsigned __int8)v6[73];
    v10 = *(_DWORD *)(result + 64);
    v2 = *(_QWORD *)(result + 8);
    if ( (v10 & 1) != 0 )
      return sk_skb_reason_drop(0);
    *(_DWORD *)(result + 64) = v10 | 1;
    if ( !*(_DWORD *)(v8 + 1324) )
      return sk_skb_reason_drop(0);
    v11 = ieee80211_rx_radiotap_hdrlen(v8, v2 + 40, v2);
    if ( v11 > *(_DWORD *)(v2 + 224) - *(_DWORD *)(v2 + 216) )
    {
      if ( (unsigned int)pskb_expand_head(v2, v11, 0, 2080) )
        return sk_skb_reason_drop(0);
    }
    ieee80211_add_rx_radiotap_header(v8, v2, v9, v11, 0);
    v12 = *(_BYTE *)(v2 + 128) & 0xBB;
    *(_WORD *)(v2 + 186) = *(_DWORD *)(v2 + 224) - *(_DWORD *)(v2 + 216);
    *(_BYTE *)(v2 + 128) = v12 | 0x23;
    *(_WORD *)(v2 + 180) = 1024;
    v4 = *(__int64 **)(v8 + 4616);
    v3 = (__int64 *)(v8 + 4616);
    if ( v4 == v3 )
      return sk_skb_reason_drop(0);
    v5 = 0;
    do
    {
      if ( (v4[204] & 1) != 0 && *((_DWORD *)v4 + 1180) == 6 && (v4[283] & 0x20) != 0 )
      {
        if ( v5 )
        {
          v20 = skb_clone(v2, 2080);
          if ( v20 )
          {
            *(_QWORD *)(v20 + 16) = v5;
            ((void (*)(void))netif_receive_skb)();
          }
        }
        v5 = v4[201];
        v21 = *(unsigned int *)(v2 + 112);
        v6 = *(_BYTE **)(v5 + 160);
        StatusReg = _ReadStatusReg(TPIDR_EL1);
        _X11 = (unsigned __int64 *)&v6[StatusReg + 8];
        __asm { PRFM            #0x11, [X11] }
        do
          v24 = __ldxr(_X11);
        while ( __stxr(v24 + v21, _X11) );
LABEL_17:
        _X8 = (unsigned __int64 *)&v6[StatusReg];
        __asm { PRFM            #0x11, [X8] }
        do
          v19 = __ldxr(_X8);
        while ( __stxr(v19 + 1, _X8) );
      }
      v4 = (__int64 *)*v4;
    }
    while ( v4 != v3 );
    if ( !v5 )
    {
      return sk_skb_reason_drop(0);
    }
    else
    {
      *(_QWORD *)(v2 + 16) = v5;
      return netif_receive_skb(v2);
    }
  }
  return result;
}
