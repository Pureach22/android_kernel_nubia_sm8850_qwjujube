__int64 __fastcall ieee80211_tx_prepare(__int64 a1, __int64 *a2, _BYTE *a3, __int64 a4)
{
  __int64 v4; // x21
  bool v5; // w23
  unsigned __int16 *v6; // x22
  _QWORD *v7; // x20
  int v8; // w8
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x24
  char v13; // w8
  __int64 *v14; // x23
  __int64 v15; // x24
  __int64 *v16; // x23
  __int64 v17; // x25
  __int64 v18; // x10
  int v19; // w11
  int v20; // w12
  __int64 **v21; // x10
  __int64 *v22; // x11
  int v23; // w9
  __int64 *v24; // x19
  __int64 v25; // x9
  _QWORD *v26; // x10
  int v28; // w8
  int v29; // w8
  __int64 v30; // x19
  int v31; // w8
  __int64 *v32; // x20
  __int64 v33; // x19
  __int64 v34; // x24
  unsigned __int64 bss; // x0
  __int64 *v36; // x24
  __int64 v37; // x19
  __int64 v38; // x25
  unsigned __int64 v39; // x0
  unsigned __int64 v45; // x9
  unsigned __int64 v48; // x12

  v4 = *(_QWORD *)(a1 + 1616);
  a2[7] = 0;
  a2[8] = 0;
  a2[5] = a1;
  a2[6] = 0;
  a2[3] = 0;
  a2[4] = v4;
  v5 = a3 != nullptr;
  *a2 = a4;
  a2[1] = (__int64)(a2 + 1);
  a2[2] = (__int64)(a2 + 1);
  v6 = *(unsigned __int16 **)(a4 + 224);
  *(_DWORD *)(a4 + 80) &= ~0x40u;
  if ( !a3 )
  {
    if ( *(_DWORD *)(a1 + 4720) == 4 )
    {
      a3 = *(_BYTE **)(a1 + 2280);
      a2[6] = (__int64)a3;
      if ( a3 )
        goto LABEL_7;
      if ( (*(_BYTE *)(a1 + 81) & 1) != 0 )
        return 1;
    }
    else
    {
      if ( *(unsigned __int16 *)(a2[5] + 1940) == *(unsigned __int16 *)(*a2 + 180) )
      {
        v32 = a2;
        v33 = a1;
        v34 = a4;
        bss = sta_info_get_bss(a1, v6 + 2);
        a2 = v32;
        a4 = v34;
        a3 = (_BYTE *)bss;
        a1 = v33;
        v32[6] = (__int64)a3;
      }
      else
      {
        a3 = (_BYTE *)a2[6];
      }
      if ( a3 )
        goto LABEL_7;
    }
    v7 = a2 + 6;
    if ( (v6[2] & 1) != 0 )
      goto LABEL_33;
    v36 = a2;
    v37 = a1;
    v38 = a4;
    v39 = sta_info_get(a1, v6 + 2);
    a2 = v36;
    a4 = v38;
    a3 = (_BYTE *)v39;
    a1 = v37;
    *v7 = a3;
LABEL_4:
    v7 = a2 + 6;
    if ( !a3 )
      goto LABEL_33;
    goto LABEL_8;
  }
  if ( (unsigned __int64)a3 >= 0xFFFFFFFFFFFFF001LL )
  {
    a3 = (_BYTE *)a2[6];
    goto LABEL_4;
  }
  a2[6] = (__int64)a3;
LABEL_7:
  v7 = a2 + 6;
  v5 = 1;
LABEL_8:
  v8 = *v6;
  if ( (v8 & 0x8C) != 0x88
    || (v8 & 0xFC) == 0xC8
    || (*(_QWORD *)(v4 + 96) & 0x80) == 0
    || (*(_QWORD *)(v4 + 96) & 0x200000) != 0 )
  {
    goto LABEL_33;
  }
  _ZF = (~v8 & 0x300) == 0;
  v10 = 12;
  if ( _ZF )
    v10 = 15;
  v11 = v6[v10] & 0xF;
  v12 = *(_QWORD *)&a3[8 * v11 + 904];
  if ( v12 )
    v13 = 1;
  else
    v13 = v5;
  if ( (v13 & 1) == 0 )
  {
    v14 = a2;
    v15 = a4;
    ieee80211_aggr_check(a1, a3, a4);
    a3 = (_BYTE *)*v7;
    a4 = v15;
    a2 = v14;
    v12 = *(_QWORD *)(*v7 + 8 * v11 + 904);
  }
  if ( !v12 )
    goto LABEL_33;
  if ( (*(_QWORD *)(v12 + 128) & 4) != 0 )
  {
LABEL_32:
    *(_QWORD *)(v12 + 136) = jiffies;
    goto LABEL_33;
  }
  if ( (*(_QWORD *)(v12 + 128) & 0x10) != 0 || *(_QWORD *)&a3[8 * v11 + 2736] )
  {
LABEL_33:
    v28 = *((_DWORD *)a2 + 17);
    if ( (v6[2] & 1) != 0 )
    {
      *((_DWORD *)a2 + 17) = v28 & 0xFFFFFFFD;
      v29 = *(_DWORD *)(a4 + 40) | 4;
      *(_DWORD *)(a4 + 40) = v29;
      if ( (v29 & 0x40000000) != 0 )
      {
LABEL_41:
        if ( *v7 )
        {
          _X8 = (unsigned __int64 *)(*v7 + 216LL);
          __asm { PRFM            #0x11, [X8] }
          do
            v45 = __ldxr(_X8);
          while ( __stlxr(v45 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
          __dmb(0xBu);
          v31 = *(_DWORD *)(a4 + 40);
          if ( (v45 & 0x40) != 0 )
          {
            v30 = a4;
            *(_DWORD *)(a4 + 40) = v31 | 8;
            ieee80211_check_fast_xmit(*v7);
            v31 = *(_DWORD *)(v30 + 40);
            a4 = v30;
          }
        }
        else
        {
          v31 = v29 | 8;
        }
        *(_DWORD *)(a4 + 40) = v31 | 0x10;
        return 0;
      }
    }
    else
    {
      *((_DWORD *)a2 + 17) = v28 | 2;
      v29 = *(_DWORD *)(a4 + 40);
      if ( (v29 & 0x40000000) != 0 )
        goto LABEL_41;
    }
    if ( (*((_BYTE *)a2 + 68) & 2) == 0
      || (v29 & 0x40) != 0
      || (unsigned int)(*(_DWORD *)(a4 + 112) + 4) <= *(_DWORD *)(*(_QWORD *)(v4 + 72) + 200LL) )
    {
      v29 |= 0x40000000u;
      *(_DWORD *)(a4 + 40) = v29;
    }
    goto LABEL_41;
  }
  v16 = a2;
  v17 = a4;
  raw_spin_lock(a3 + 148);
  v18 = *v7;
  v12 = *(_QWORD *)(*v7 + 8 * v11 + 904);
  if ( !v12 )
  {
    raw_spin_unlock(v18 + 148);
    a4 = v17;
    a2 = v16;
    goto LABEL_33;
  }
  if ( (*(_QWORD *)(v12 + 128) & 4) != 0 )
  {
    raw_spin_unlock(v18 + 148);
    a4 = v17;
    a2 = v16;
    goto LABEL_32;
  }
  if ( (*(_BYTE *)(v17 + 42) & 2) != 0 )
  {
    _X10 = (unsigned __int64 *)(v18 + 216);
    __asm { PRFM            #0x11, [X10] }
    do
      v48 = __ldxr(_X10);
    while ( __stxr(v48 & 0xFFFFFFFFFFFBFFFFLL, _X10) );
  }
  v19 = *(_DWORD *)(v17 + 40);
  v20 = *(_DWORD *)(v17 + 80) | 0x40;
  *(_QWORD *)(v17 + 64) = v16[5] + 4720;
  *(_DWORD *)(v17 + 80) = v20;
  *(_DWORD *)(v17 + 40) = v19 & 0xEE39E083;
  v21 = (__int64 **)(v12 + 96);
  v22 = *(__int64 **)(v12 + 104);
  *(_QWORD *)v17 = v12 + 96;
  *(_QWORD *)(v17 + 8) = v22;
  *(_QWORD *)(v12 + 104) = v17;
  *v22 = v17;
  v23 = *(_DWORD *)(v12 + 112);
  *(_DWORD *)(v12 + 112) = v23 + 1;
  if ( (unsigned int)(v23 + 1) < 0x41 || (v24 = *v21, *v21 == (__int64 *)v21) || !v24 )
  {
    raw_spin_unlock(*v7 + 148LL);
    return 2;
  }
  else
  {
    *(_DWORD *)(v12 + 112) = v23;
    v25 = *v24;
    v26 = (_QWORD *)v24[1];
    *v24 = 0;
    v24[1] = 0;
    *(_QWORD *)(v25 + 8) = v26;
    *v26 = v25;
    raw_spin_unlock(v16[6] + 148);
    ieee80211_free_txskb(v16[4], (__int64)v24);
    return 2;
  }
}
