__int64 __fastcall cfg80211_mlme_mgmt_tx(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x12
  __int16 *v6; // x9
  __int16 v7; // w10
  __int64 v9; // x11
  unsigned __int64 v10; // x12
  unsigned __int64 v11; // x15
  int v12; // w14
  __int64 v13; // x11
  __int64 v14; // x11
  int v15; // w11
  int v16; // w12
  int v17; // w13
  int v18; // w14
  int v19; // w10
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 (__fastcall *v22)(_QWORD); // x8
  __int64 v23; // x11
  __int64 v24; // x13
  char v25; // w8
  __int64 v26; // x11
  int v27; // w11
  int v28; // w12
  unsigned int v29; // w13
  unsigned __int64 StatusReg; // x19
  __int64 v31; // x8

  v4 = *a2;
  v5 = *(_QWORD *)(*a2 + 72);
  if ( !v5 || !*(_QWORD *)(*(_QWORD *)a1 + 520LL) )
    return 4294967201LL;
  if ( *(_QWORD *)(a3 + 24) < 0x19u )
    return 4294967274LL;
  v6 = *(__int16 **)(a3 + 16);
  v7 = *v6;
  if ( (*v6 & 0xC) != 0 )
    return 4294967274LL;
  v9 = *((unsigned int *)a2 + 2);
  if ( (((unsigned __int64)*(unsigned __int16 *)(v5 + 4 * v9) >> ((unsigned __int8)v7 >> 4)) & 1) == 0 )
    return 4294967274LL;
  if ( (v7 & 0xF0) != 0xD0 || *((_BYTE *)v6 + 24) == 4 )
    goto LABEL_9;
  if ( (unsigned int)v9 > 9 )
  {
LABEL_43:
    if ( (_DWORD)v9 == 1 )
    {
      v26 = a2[35];
      if ( !v26 )
        return 4294967189LL;
      v16 = *(_DWORD *)(v26 + 184);
      v17 = *((_DWORD *)v6 + 4);
      v15 = *(unsigned __int16 *)(v26 + 188);
      v18 = (unsigned __int16)v6[10];
      goto LABEL_46;
    }
    return 4294967201LL;
  }
  if ( ((1 << v9) & 0x218) == 0 )
  {
    if ( ((1 << v9) & 0x104) != 0 )
    {
      if ( (*((_BYTE *)a2 + 164) & 1) == 0 )
        return 4294967189LL;
      v15 = *((unsigned __int16 *)a2 + 142);
      v16 = *((_DWORD *)a2 + 70);
      if ( *((_DWORD *)v6 + 4) ^ v16 | (unsigned __int16)(v6[10] ^ v15) )
        return 4294967189LL;
      v17 = *((_DWORD *)v6 + 1);
      v18 = (unsigned __int16)v6[4];
LABEL_46:
      if ( v17 ^ v16 | v18 ^ v15 )
        return 4294967189LL;
LABEL_9:
      v10 = 15;
      v11 = 0;
      v12 = 1;
      if ( !*((_WORD *)a2 + 736) )
        v10 = 1;
      do
      {
        if ( (!*((_WORD *)a2 + 736)
           || (((unsigned __int64)*((unsigned __int16 *)a2 + 736) >> ((unsigned __int8)v12 - 1)) & 1) != 0)
          && !(LODWORD(a2[9 * v11 + 49]) ^ *(_DWORD *)(v6 + 5) | WORD2(a2[9 * v11 + 49]) ^ (unsigned __int16)v6[7]) )
        {
          goto LABEL_31;
        }
        v11 = v12++;
      }
      while ( v10 > v11 );
      v13 = a2[4];
      if ( v13 )
        v14 = *(_QWORD *)(v13 + 1008);
      else
        v14 = (__int64)a2 + 70;
      if ( !(*(_DWORD *)v14 ^ *(_DWORD *)(v6 + 5) | *(unsigned __int16 *)(v14 + 4) ^ (unsigned __int16)v6[7]) )
        goto LABEL_31;
      v19 = v7 & 0xF0;
      if ( v19 == 176 )
      {
LABEL_30:
        if ( (*(_BYTE *)(v4 + 120) & 1) == 0 )
          return 4294967274LL;
        goto LABEL_31;
      }
      if ( v19 != 208 )
      {
        if ( v19 != 192 )
          return 4294967274LL;
        goto LABEL_30;
      }
      if ( *((_BYTE *)v6 + 24) != 4 )
        return 4294967274LL;
      v25 = *(_BYTE *)(v4 + 113);
      if ( (*((_BYTE *)a2 + 164) & 1) != 0 )
      {
        if ( (v25 & 8) == 0 )
          return 4294967274LL;
      }
      else if ( (v25 & 4) == 0 )
      {
        return 4294967274LL;
      }
      goto LABEL_31;
    }
    if ( (_DWORD)v9 == 7 )
    {
      if ( !(*((_DWORD *)v6 + 4) ^ *(_DWORD *)(v6 + 5) | (unsigned __int16)v6[10] ^ (unsigned __int16)v6[7]) )
        goto LABEL_9;
      return 4294967274LL;
    }
    goto LABEL_43;
  }
  v23 = a2[4];
  if ( v23 )
    v24 = *(_QWORD *)(v23 + 1008);
  else
    v24 = (__int64)a2 + 70;
  v27 = (unsigned __int16)v6[10];
  v28 = *((_DWORD *)v6 + 4);
  if ( !(*(_DWORD *)v24 ^ v28 | (unsigned __int16)(*(_WORD *)(v24 + 4) ^ v27)) )
    goto LABEL_9;
  v29 = *(_DWORD *)(a3 + 48);
  if ( (v29 & 0x80000000) != 0 )
    return 4294967274LL;
  if ( v29 < 0xF )
  {
    if ( !(LODWORD(a2[9 * v29 + 49]) ^ v28 | WORD2(a2[9 * v29 + 49]) ^ v27) )
      goto LABEL_9;
    return 4294967274LL;
  }
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    a1 = _traceiter_rdev_mgmt_tx(0, a1 + 992, a2, a3);
    v31 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v31;
    if ( !v31 || (a1 = v3, !*(_QWORD *)(StatusReg + 16)) )
    {
      preempt_schedule_notrace(a1, a2, a3);
      a1 = v3;
    }
  }
LABEL_31:
  v20 = *(_QWORD *)a1;
  v21 = a1 + 992;
  v22 = *(__int64 (__fastcall **)(_QWORD))(v20 + 520);
  if ( *((_DWORD *)v22 - 1) != 1910527928 )
    __break(0x8228u);
  return v22(v21);
}
