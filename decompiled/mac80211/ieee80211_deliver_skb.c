__int64 __fastcall ieee80211_deliver_skb(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x1
  __int64 v6; // x10
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x9
  int v10; // w8
  __int64 v11; // x22
  __int64 v12; // x8
  __int64 v13; // x2
  __int64 v14; // x3
  int v15; // w8
  int v16; // w10
  int v17; // w11
  unsigned __int64 v23; // x12
  unsigned __int64 v26; // x9

  result = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)(a1 + 8);
  v4 = *(_QWORD *)(result + 1608);
  v5 = *(_QWORD *)(v3 + 224);
  v6 = *(unsigned int *)(v3 + 112);
  v7 = *(_QWORD *)(v4 + 160);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  _X11 = (unsigned __int64 *)(StatusReg + v7);
  while ( 1 )
  {
    ++_X11;
    __asm { PRFM            #0x11, [X11] }
    do
      v23 = __ldxr(_X11);
    while ( __stxr(v23 + v6, _X11) );
    _X8 = (unsigned __int64 *)(v7 + StatusReg);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v26 = __ldxr(_X8);
      StatusReg = v26 + 1;
      v6 = __stxr(StatusReg, _X8);
    }
    while ( (_DWORD)v6 );
    if ( !*(_QWORD *)(a1 + 40) )
      break;
    v7 = *(unsigned int *)(a1 + 68);
    if ( (unsigned int)v7 < 0x12 )
    {
      ++*(_QWORD *)(*(_QWORD *)(a1 + 48) + 8 * v7 + 176);
      break;
    }
    __break(0x5512u);
  }
  v10 = *(_DWORD *)(result + 4720);
  if ( (unsigned int)(v10 - 3) > 1
    || (*(_BYTE *)(result + 1624) & 8) != 0
    || *(unsigned __int16 *)(v5 + 12) == *(unsigned __int16 *)(*(_QWORD *)(a1 + 24) + 1940LL)
    || v10 == 4 && *(_QWORD *)(result + 2280) )
  {
    goto LABEL_21;
  }
  if ( (*(_DWORD *)v5 & 1) == 0 )
  {
    if ( *(_DWORD *)(v5 + 6) ^ *(_DWORD *)v5 | *(unsigned __int16 *)(v5 + 10) ^ *(unsigned __int16 *)(v5 + 4) )
    {
      result = sta_info_get(result, v5);
      if ( result )
      {
        v11 = v3;
        goto LABEL_24;
      }
    }
    goto LABEL_21;
  }
  if ( v10 == 3 )
  {
    v12 = 2576;
LABEL_17:
    if ( !*(_DWORD *)(result + v12) )
      goto LABEL_21;
    goto LABEL_18;
  }
  if ( !*(_QWORD *)(result + 2280) )
  {
    v12 = 2288;
    goto LABEL_17;
  }
LABEL_18:
  result = skb_copy(v3, 2080);
  v11 = result;
  if ( result )
    goto LABEL_22;
  result = net_ratelimit();
  if ( (_DWORD)result )
    result = printk(&unk_B84B9, v4 + 296, v13, v14);
LABEL_21:
  v11 = 0;
LABEL_22:
  if ( v3 )
  {
    *(_WORD *)(v3 + 180) = eth_type_trans(v3, v4);
    result = ieee80211_deliver_skb_to_local_stack(v3, a1);
  }
LABEL_24:
  if ( v11 )
  {
    v15 = *(_DWORD *)(v11 + 144);
    v16 = *(_DWORD *)(v11 + 224);
    v17 = *(_DWORD *)(v11 + 216);
    *(_WORD *)(v11 + 180) = 256;
    *(_DWORD *)(v11 + 144) = v15 + 256;
    *(_WORD *)(v11 + 184) = v16 - v17;
    *(_WORD *)(v11 + 186) = v16 - v17;
    return _dev_queue_xmit(v11, 0);
  }
  return result;
}
