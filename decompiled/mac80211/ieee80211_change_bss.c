__int64 __fastcall ieee80211_change_bss(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x8
  _QWORD *v4; // x19
  __int64 v8; // x23
  __int64 lock; // x0
  unsigned int **v10; // x8
  __int64 v11; // x24
  __int64 v12; // x23
  unsigned int *v13; // x9
  __int64 v14; // x8
  __int64 v15; // x20
  __int64 v16; // x8
  unsigned int v17; // w10
  unsigned int v18; // w10
  __int64 v19; // x10
  unsigned int v20; // w10
  unsigned int v21; // w10
  unsigned int v22; // w10
  int v23; // w9
  __int64 v24; // x9
  char v25; // w10

  v3 = *a3;
  if ( (v3 & 0x80000000) != 0 )
  {
    if ( *(_WORD *)(a2 + 8488) )
    {
      LODWORD(v4) = -22;
    }
    else
    {
      v4 = (_QWORD *)(a2 + 6304);
      if ( (unsigned __int64)(a2 + 6304) < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_10;
    }
    return (unsigned int)v4;
  }
  if ( (unsigned int)v3 >= 0xF )
    goto LABEL_44;
  v4 = *(_QWORD **)(a2 + 8 * v3 + 7256);
  if ( !v4 )
  {
    LODWORD(v4) = -67;
    return (unsigned int)v4;
  }
  if ( (unsigned __int64)v4 >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)v4;
LABEL_10:
  if ( !v4[67] )
  {
    LODWORD(v4) = -2;
    return (unsigned int)v4;
  }
  v8 = *(_QWORD *)(*v4 + 1616LL);
  lock = _rcu_read_lock(a1, a2);
  v10 = *(unsigned int ***)(v4[118] + 832LL);
  if ( !v10 )
  {
    _rcu_read_unlock(lock);
    goto LABEL_20;
  }
  v11 = **v10;
  _rcu_read_unlock(lock);
  if ( (unsigned int)v11 >= 6 )
    goto LABEL_44;
  v12 = *(_QWORD *)(*(_QWORD *)(v8 + 72) + 8 * v11 + 328);
  if ( !v12 )
  {
LABEL_20:
    LODWORD(v4) = -22;
    return (unsigned int)v4;
  }
  v13 = a3;
  if ( !*((_QWORD *)a3 + 2) )
  {
    v16 = a2;
    v15 = 0;
LABEL_22:
    v17 = v13[1];
    if ( (v17 & 0x80000000) == 0 )
    {
      v15 |= 2uLL;
      *(_BYTE *)(v4[118] + 45LL) = v17 != 0;
    }
    v18 = v13[2];
    if ( (v18 & 0x80000000) == 0 )
    {
      v15 |= 4uLL;
      *(_BYTE *)(v4[118] + 46LL) = v18 != 0;
    }
    v19 = v4[118];
    if ( (*(_BYTE *)(v19 + 47) & 1) == 0 && (*(_DWORD *)(v12 + 16) | 2) == 3 )
    {
      v15 |= 8uLL;
      *(_BYTE *)(v19 + 47) = 1;
    }
    v20 = v13[3];
    if ( (v20 & 0x80000000) == 0 )
    {
      v15 |= 8uLL;
      *(_BYTE *)(v4[118] + 47LL) = v20 != 0;
    }
    v21 = v13[7];
    if ( (v21 & 0x80000000) == 0 )
    {
      *(_DWORD *)(v16 + 4312) = *(_DWORD *)(v16 + 4312) & 0xFFFFFFF7 | (8 * (v21 != 0));
      ieee80211_check_fast_rx_iface(v16 + 2688);
      v13 = a3;
      v16 = a2;
    }
    v22 = v13[8];
    if ( (v22 & 0x80000000) == 0 )
    {
      v15 |= 0x10uLL;
      *(_WORD *)(v4[118] + 112LL) = v22;
    }
    if ( ((char)v13[9] & 0x80000000) == 0 )
    {
      v15 |= 0x80000uLL;
      *(_BYTE *)(v4[118] + 237LL) &= 0x80u;
      *(_BYTE *)(v4[118] + 237LL) |= v13[9] & 0x7F;
    }
    v23 = *((char *)v13 + 37);
    if ( v23 < 1 )
    {
      if ( v23 )
        goto LABEL_41;
      v24 = v4[118];
      v25 = *(_BYTE *)(v24 + 237) & 0x7F;
    }
    else
    {
      v24 = v4[118];
      v25 = *(_BYTE *)(v24 + 237) | 0x80;
    }
    v15 |= 0x80000uLL;
    *(_BYTE *)(v24 + 237) = v25;
LABEL_41:
    ieee80211_link_info_change_notify(v16 + 2688, v4, v15);
    LODWORD(v4) = 0;
    return (unsigned int)v4;
  }
  v14 = *(unsigned int *)(v12 + 16);
  if ( (unsigned int)v14 < 6 )
  {
    if ( (unsigned int)ieee80211_parse_bitrates(*(unsigned int *)(v4[118] + 144LL), *(_QWORD *)(a1 + 8 * v14 + 328)) )
    {
      ((void (__fastcall *)(_QWORD *))ieee80211_check_rate_mask)(v4);
      v15 = 32;
      v16 = a2;
      v13 = a3;
      goto LABEL_22;
    }
    goto LABEL_20;
  }
LABEL_44:
  __break(0x5512u);
  return ieee80211_set_txq_params();
}
