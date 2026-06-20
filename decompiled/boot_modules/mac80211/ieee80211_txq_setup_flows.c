__int64 __fastcall ieee80211_txq_setup_flows(__int64 a1)
{
  __int64 *v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x10
  _QWORD *v7; // x8
  __int64 v8; // x9
  char v9; // w10
  __int64 v10; // x11
  char v11; // w9
  __int64 v12; // x11
  char v13; // w10
  __int64 v14; // x9
  char v15; // w11
  __int64 v16; // x10
  char v17; // w9
  __int64 v18; // x8
  __int64 v19; // x0
  unsigned int v20; // w8
  _QWORD *v21; // x10
  _DWORD *v22; // x8
  int v23; // w9
  int v24; // w9
  int v25; // w9
  unsigned int v27; // w21
  __int64 v28; // x0

  *(_QWORD *)(a1 + 208) = 0;
  v2 = (__int64 *)(a1 + 208);
  *(_QWORD *)(a1 + 232) = 0;
  *(_QWORD *)(a1 + 240) = 0;
  *(_QWORD *)(a1 + 264) = 0;
  *(_QWORD *)(a1 + 272) = 0;
  *(_QWORD *)(a1 + 256) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 224) = 0;
  *(_QWORD *)(a1 + 224) = a1 + 224;
  *(_QWORD *)(a1 + 232) = a1 + 224;
  *(_DWORD *)(a1 + 244) = 4096;
  *(_DWORD *)(a1 + 260) = 300;
  *(_QWORD *)(a1 + 248) = 0x100000000002000LL;
  v3 = _kvmalloc_node_noprof(56LL * *(unsigned int *)(a1 + 244), 0, 3520, 0xFFFFFFFFLL);
  *v2 = v3;
  if ( !v3 )
    return 4294967284LL;
  v4 = bitmap_zalloc(*(unsigned int *)(a1 + 244), 3264);
  *(_QWORD *)(a1 + 216) = v4;
  if ( !v4 )
  {
    kvfree(*v2);
    *v2 = 0;
    return 4294967284LL;
  }
  if ( *(_DWORD *)(a1 + 244) )
  {
    v5 = 0;
    do
    {
      v6 = *(_QWORD *)(a1 + 208) + 56LL * (int)v5++;
      *(_QWORD *)(v6 + 8) = v6 + 8;
      *(_QWORD *)(v6 + 16) = v6 + 8;
      *(_QWORD *)(v6 + 24) = v6 + 24;
      *(_QWORD *)(v6 + 32) = v6 + 24;
      *(_DWORD *)(v6 + 40) = 0;
    }
    while ( v5 < *(_DWORD *)(a1 + 244) );
  }
  v7 = *(_QWORD **)(a1 + 72);
  v8 = v7[41];
  if ( v8 )
    v9 = *(_BYTE *)(v8 + 52);
  else
    v9 = 0;
  v10 = v7[42];
  v11 = (v10 != 0) | v9;
  if ( v10 && (v9 & 1) == 0 )
    v11 = *(_BYTE *)(v10 + 52);
  v12 = v7[43];
  v13 = (v12 != 0) | v11;
  if ( v12 && (v11 & 1) == 0 )
    v13 = *(_BYTE *)(v12 + 52);
  v14 = v7[44];
  v15 = (v14 != 0) | v13;
  if ( v14 && (v13 & 1) == 0 )
    v15 = *(_BYTE *)(v14 + 52);
  v16 = v7[45];
  v17 = (v16 != 0) | v15;
  if ( v16 && (v15 & 1) == 0 )
    v17 = *(_BYTE *)(v16 + 52);
  v18 = v7[46];
  if ( v18 && (v17 & 1) == 0 )
  {
    if ( (*(_BYTE *)(v18 + 52) & 1) != 0 )
      goto LABEL_28;
    goto LABEL_27;
  }
  if ( !((v18 != 0) | v17 & 1) )
LABEL_27:
    *(_DWORD *)(a1 + 252) = 0x400000;
LABEL_28:
  *(_BYTE *)(a1 + 306) = 0;
  *(_DWORD *)(a1 + 296) = 97656;
  *(_QWORD *)(a1 + 288) = 0x7FFFFFFF00004C4BLL;
  *(_WORD *)(a1 + 304) = 1;
  v19 = _kvmalloc_node_noprof(24LL * *(unsigned int *)(a1 + 244), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 280) = v19;
  if ( v19 )
  {
    if ( *(_DWORD *)(a1 + 244) )
    {
      v20 = 0;
      do
      {
        v21 = (_QWORD *)(*(_QWORD *)(a1 + 280) + 24LL * (int)v20++);
        v21[1] = 0;
        v21[2] = 0;
        *v21 = 0;
      }
      while ( v20 < *(_DWORD *)(a1 + 244) );
    }
    v22 = *(_DWORD **)(a1 + 72);
    v23 = v22[351];
    if ( v23 )
    {
      *(_DWORD *)(a1 + 248) = v23;
      v24 = v22[352];
      if ( v24 )
        goto LABEL_34;
    }
    else
    {
      v22[351] = *(_DWORD *)(a1 + 248);
      v22 = *(_DWORD **)(a1 + 72);
      v24 = v22[352];
      if ( v24 )
      {
LABEL_34:
        *(_DWORD *)(a1 + 252) = v24;
        v25 = v22[353];
        if ( v25 )
        {
LABEL_35:
          *(_DWORD *)(a1 + 260) = v25;
          return 0;
        }
        goto LABEL_38;
      }
    }
    v22[352] = *(_DWORD *)(a1 + 252);
    v22 = *(_DWORD **)(a1 + 72);
    v25 = v22[353];
    if ( v25 )
      goto LABEL_35;
LABEL_38:
    v22[353] = *(_DWORD *)(a1 + 260);
    return 0;
  }
  raw_spin_lock_bh(a1 + 240);
  if ( *(_DWORD *)(a1 + 244) )
  {
    v27 = 0;
    do
      fq_flow_reset(v2, *(_QWORD *)(a1 + 208) + 56LL * (int)v27++);
    while ( v27 < *(_DWORD *)(a1 + 244) );
  }
  kvfree(*(_QWORD *)(a1 + 208));
  v28 = *(_QWORD *)(a1 + 216);
  *(_QWORD *)(a1 + 208) = 0;
  bitmap_free(v28);
  *(_QWORD *)(a1 + 216) = 0;
  raw_spin_unlock_bh(a1 + 240);
  return 4294967284LL;
}
