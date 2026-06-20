__int64 __fastcall ieee80211_rx_8023(__int64 result, __int64 *a2, int a3)
{
  __int64 v3; // x10
  _QWORD *v5; // x24
  __int64 v6; // x20
  unsigned __int64 StatusReg; // x9
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 v12; // x22
  _QWORD *v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  unsigned __int64 v16; // x9
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x9
  unsigned __int64 v20; // x9
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x9
  unsigned __int64 v24; // x9
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x9
  unsigned __int64 v28; // x9
  __int64 v29; // x9
  __int64 v30; // x10
  __int64 v31; // x9
  unsigned __int64 v32; // x9
  __int64 v33; // x8
  __int64 v34; // x9
  __int64 v35; // x8
  _QWORD *v36; // x8
  __int64 v37; // x10
  __int64 v38; // x22
  int v39; // w8
  int v40; // w10
  int v41; // w11
  unsigned __int64 v47; // x12
  unsigned __int64 v50; // x9

  v6 = *(_QWORD *)(result + 8);
  StatusReg = *(unsigned int *)(result + 76);
  v9 = *(_QWORD *)(result + 40);
  v10 = result;
  v12 = *(_QWORD *)(v6 + 224);
  if ( (StatusReg & 0x80000000) != 0 )
  {
    v13 = (_QWORD *)(v9 + 1640);
    if ( (*((_BYTE *)a2 + 29) & 4) == 0 )
      goto LABEL_5;
  }
  else
  {
    if ( (unsigned int)StatusReg >= 0x10 )
      goto LABEL_57;
    v13 = *(_QWORD **)(v9 + 8 * StatusReg + 2568);
    if ( !v13 )
    {
      __break(0x800u);
      return consume_skb(*(_QWORD *)(result + 8));
    }
    if ( (*((_BYTE *)a2 + 29) & 4) == 0 )
    {
LABEL_5:
      v5 = v13 + 14;
      if ( (*(_BYTE *)(v6 + 65) & 1) != 0 )
        goto LABEL_14;
      goto LABEL_9;
    }
  }
  v14 = v13[13];
  v5 = (_QWORD *)(_ReadStatusReg(TPIDR_EL1) + v14);
  if ( (*(_BYTE *)(v6 + 65) & 1) != 0 )
    goto LABEL_14;
LABEL_9:
  *((_DWORD *)v5 + 10) = *(char *)(v6 + 78);
  if ( (*((_BYTE *)a2 + 29) & 4) == 0 )
  {
    v15 = v13[39];
    if ( v15 )
      v16 = (unsigned __int64)(7 * v15 - ((__int64)*(char *)(v6 + 78) << 10)) >> 3;
    else
      v16 = -1024LL * *(char *)(v6 + 78);
    v13[39] = v16;
  }
LABEL_14:
  if ( *(_BYTE *)(v6 + 79) )
  {
    *((_BYTE *)v5 + 44) = *(_BYTE *)(v6 + 79);
    if ( (*(_BYTE *)(v6 + 79) & 1) != 0 )
    {
      v17 = *(char *)(v6 + 80);
      *((_BYTE *)v5 + 45) = *(_BYTE *)(v6 + 80);
      if ( (*((_BYTE *)a2 + 29) & 4) == 0 )
      {
        v18 = v13[40];
        v19 = -v17;
        if ( v18 )
          v20 = (unsigned __int64)(7 * v18 + (v19 << 10)) >> 3;
        else
          v20 = v19 << 10;
        v13[40] = v20;
      }
    }
    if ( (*(_BYTE *)(v6 + 79) & 2) != 0 )
    {
      v21 = *(char *)(v6 + 81);
      *((_BYTE *)v5 + 46) = *(_BYTE *)(v6 + 81);
      if ( (*((_BYTE *)a2 + 29) & 4) == 0 )
      {
        v22 = v13[41];
        v23 = -v21;
        if ( v22 )
          v24 = (unsigned __int64)(7 * v22 + (v23 << 10)) >> 3;
        else
          v24 = v23 << 10;
        v13[41] = v24;
      }
    }
    if ( (*(_BYTE *)(v6 + 79) & 4) != 0 )
    {
      v25 = *(char *)(v6 + 82);
      *((_BYTE *)v5 + 47) = *(_BYTE *)(v6 + 82);
      if ( (*((_BYTE *)a2 + 29) & 4) == 0 )
      {
        v26 = v13[42];
        v27 = -v25;
        if ( v26 )
          v28 = (unsigned __int64)(7 * v26 + (v27 << 10)) >> 3;
        else
          v28 = v27 << 10;
        v13[42] = v28;
      }
    }
    if ( (*(_BYTE *)(v6 + 79) & 8) != 0 )
    {
      v29 = *(char *)(v6 + 83);
      *((_BYTE *)v5 + 48) = *(_BYTE *)(v6 + 83);
      if ( (*((_BYTE *)a2 + 29) & 4) == 0 )
      {
        v30 = v13[43];
        v31 = -v29;
        if ( v30 )
          v32 = (unsigned __int64)(7 * v30 + (v31 << 10)) >> 3;
        else
          v32 = v31 << 10;
        v13[43] = v32;
      }
    }
  }
  v5[1] = jiffies;
  result = sta_stats_encode_rate((_BYTE *)(v6 + 40));
  v33 = v5[3];
  v34 = *v5;
  *((_DWORD *)v5 + 13) = result;
  v5[3] = v33 + 1;
  *v5 = v34 + 1;
  v35 = *a2;
  v3 = *(unsigned int *)(v6 + 112);
  *(_QWORD *)(v6 + 16) = *a2;
  v9 = *(_QWORD *)(v35 + 160);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  _X11 = (unsigned __int64 *)(StatusReg + v9);
  while ( 1 )
  {
    ++_X11;
    __asm { PRFM            #0x11, [X11] }
    do
      v47 = __ldxr(_X11);
    while ( __stxr(v47 + v3, _X11) );
    _X8 = (unsigned __int64 *)(v9 + StatusReg);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v50 = __ldxr(_X8);
      StatusReg = v50 + 1;
      v3 = __stxr(StatusReg, _X8);
    }
    while ( (_DWORD)v3 );
    v9 = *(unsigned int *)(v10 + 68);
    if ( (unsigned int)v9 <= 0x11 )
      break;
LABEL_57:
    __break(0x5512u);
  }
  v36 = &v5[v9];
  v37 = v36[8] + 1LL;
  v5[7] += a3;
  v36[8] = v37;
  if ( (*((_BYTE *)a2 + 29) & 2) == 0 )
    goto LABEL_52;
  if ( (*(_DWORD *)v12 & 1) != 0 )
  {
    result = skb_copy(v6, 2080);
    v38 = v6;
    v6 = result;
    if ( !result )
      goto LABEL_51;
LABEL_48:
    v39 = *(_DWORD *)(v6 + 144);
    v40 = *(_DWORD *)(v6 + 224);
    v41 = *(_DWORD *)(v6 + 216);
    *(_WORD *)(v6 + 180) = 256;
    *(_DWORD *)(v6 + 144) = v39 + 256;
    *(_WORD *)(v6 + 184) = v40 - v41;
    *(_WORD *)(v6 + 186) = v40 - v41;
    result = _dev_queue_xmit(v6, 0);
    v6 = v38;
    if ( !v38 )
      return result;
    goto LABEL_52;
  }
  if ( !(*(_DWORD *)(v12 + 6) ^ *(_DWORD *)v12 | *(unsigned __int16 *)(v12 + 10) ^ *(unsigned __int16 *)(v12 + 4)) )
  {
    v38 = v6;
    goto LABEL_51;
  }
  result = sta_info_get(*(_QWORD *)(v10 + 24), v12);
  if ( result )
  {
    v38 = 0;
    if ( !v6 )
    {
LABEL_51:
      v6 = v38;
      if ( !v38 )
        return result;
      goto LABEL_52;
    }
    goto LABEL_48;
  }
  if ( v6 )
  {
LABEL_52:
    *(_WORD *)(v6 + 180) = eth_type_trans(v6, *a2);
    return ieee80211_deliver_skb_to_local_stack(v6, (__int64 *)v10);
  }
  return result;
}
