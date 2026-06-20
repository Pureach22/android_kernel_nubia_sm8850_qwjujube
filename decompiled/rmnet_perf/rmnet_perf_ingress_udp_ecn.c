__int64 __fastcall rmnet_perf_ingress_udp_ecn(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w20
  void *ecn_map; // x0
  __int64 v7; // x0
  unsigned int v8; // w8
  unsigned int v9; // w20
  int v11; // w9
  int v12; // w8
  unsigned int v13; // w8
  unsigned int v14; // w9
  int v15; // w8
  __int64 v16; // x9
  __int64 v17; // x20
  int v18; // w21
  int v19; // w22
  int v20; // w8
  int v21; // w9
  int *v22; // x8
  __int64 v23; // x9
  __int64 v24; // x8
  char v25; // w9
  unsigned int v26; // w10
  int v27; // w11
  __int64 v28; // x9
  _WORD *v29; // x8
  int v30; // w10
  unsigned int v31; // w9
  unsigned int v32; // w8
  __int64 v33; // x21
  __int64 v34; // [xsp+8h] [xbp-18h] BYREF
  int v35; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+18h] [xbp-8h]

  v4 = a2;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  _rcu_read_lock(a1, a2, a3, a4);
  ecn_map = rmnet_perf_get_ecn_map();
  v7 = xa_load(ecn_map, *(unsigned int *)(a1 + 152));
  if ( !v7 )
    goto LABEL_5;
  v8 = *(_DWORD *)(v7 + 20) + 1;
  *(_DWORD *)(v7 + 20) = v8;
  if ( (int)(*(_DWORD *)(a1 + 112) - (*(_DWORD *)(a1 + 116) + v4)) <= 7 )
  {
    if ( !a1 )
      goto LABEL_5;
    v33 = v7;
    v7 = skb_copy_bits(a1, v4, &v34, 8);
    if ( (v7 & 0x80000000) != 0 )
      goto LABEL_5;
    v8 = *(_DWORD *)(v33 + 20);
    v7 = v33;
  }
  else if ( !(*(_QWORD *)(a1 + 224) + (int)v4) )
  {
    goto LABEL_5;
  }
  if ( v8 < *(_DWORD *)(v7 + 16) )
    goto LABEL_5;
  v11 = *(unsigned __int8 *)(v7 + 28);
  v12 = *(_DWORD *)(v7 + 24) + 1;
  *(_DWORD *)(v7 + 20) = 0;
  *(_DWORD *)(v7 + 24) = v12;
  if ( v11 == 1
    || (v13 = *(_DWORD *)(a1 + 112), v14 = v13 - *(_DWORD *)(a1 + 116), v4 > v14)
    && (v13 < v4 || (v7 = _pskb_pull_tail(a1, v4 - v14)) == 0) )
  {
    v7 = sk_skb_reason_drop(0, a1, 2);
    v9 = 1;
    goto LABEL_6;
  }
  v15 = *(unsigned __int16 *)(a1 + 180);
  v16 = *(unsigned __int16 *)(a1 + 120);
  if ( v15 == 43144 || v15 == 129 )
  {
    if ( *(_WORD *)(a1 + 120) )
    {
      if ( (unsigned int)v16 <= 3 )
      {
        v9 = 0;
        __break(0x800u);
        goto LABEL_6;
      }
      v17 = v16 - 4;
    }
    else
    {
      v17 = 14;
    }
    v18 = 0;
    v19 = -(int)v17;
    while ( 1 )
    {
      v20 = *(_DWORD *)(a1 + 112);
      v21 = *(_DWORD *)(a1 + 116);
      v35 = 0;
      if ( v19 + v18 + v20 - v21 < 4 )
      {
        if ( !a1 )
          goto LABEL_5;
        v7 = skb_copy_bits(a1, (unsigned int)v17, &v35, 4);
        v22 = (int)v7 >= 0 ? &v35 : nullptr;
        if ( !v22 )
          goto LABEL_5;
      }
      else
      {
        v22 = (int *)(*(_QWORD *)(a1 + 224) + v17);
        if ( !v22 )
          goto LABEL_5;
      }
      if ( v18 == -28 )
        goto LABEL_5;
      v15 = *((unsigned __int16 *)v22 + 1);
      if ( v15 != 43144 && v15 != 129 )
        break;
      v17 += 4;
      v18 -= 4;
    }
  }
  if ( v15 != 56710 )
  {
    if ( v15 == 8 )
    {
      v23 = *(_QWORD *)(a1 + 216);
      v24 = v23 + *(unsigned __int16 *)(a1 + 184);
      if ( v24 + 20 <= v23 + (unsigned __int64)*(unsigned int *)(a1 + 208) )
      {
        v25 = *(_BYTE *)(v24 + 1);
        v26 = (v25 + 1) & 3;
        if ( v26 >= 2 )
        {
          v27 = *(unsigned __int16 *)(v24 + 10);
          v9 = 0;
          *(_BYTE *)(v24 + 1) = v25 | 3;
          *(_WORD *)(v24 + 10) = v27
                               + ((_WORD)v26 << 8)
                               - 1025
                               + ((v27 + (unsigned int)(unsigned __int16)(((_WORD)v26 << 8) - 1025)) >> 16);
          goto LABEL_6;
        }
      }
    }
    goto LABEL_5;
  }
  v28 = *(_QWORD *)(a1 + 216);
  v29 = (_WORD *)(v28 + *(unsigned __int16 *)(a1 + 184));
  if ( (unsigned __int64)(v29 + 20) > v28 + (unsigned __int64)*(unsigned int *)(a1 + 208)
    || (*v29 & 0x3000) == 0
    || (v30 = *(_DWORD *)v29, v31 = *(_DWORD *)v29 | 0x3000, *(_DWORD *)v29 = v31, (*(_BYTE *)(a1 + 128) & 0x60) != 0x40) )
  {
LABEL_5:
    v9 = 0;
    goto LABEL_6;
  }
  v9 = 0;
  v32 = v31 + __CFADD__(*(_DWORD *)(a1 + 140), ~v30) + *(_DWORD *)(a1 + 140) + ~v30;
  if ( v32 < v31 )
    ++v32;
  *(_DWORD *)(a1 + 140) = v32;
LABEL_6:
  _rcu_read_unlock(v7);
  _ReadStatusReg(SP_EL0);
  return v9;
}
