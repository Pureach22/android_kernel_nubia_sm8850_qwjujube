__int64 __fastcall rmnet_perf_ingress_tcp_ecn(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w20
  __int64 v5; // x19
  void *ecn_map; // x0
  __int64 v7; // x0
  _QWORD *v8; // x22
  int v9; // w9
  int v10; // w8
  unsigned int v11; // w8
  unsigned int v12; // w9
  __int64 v14; // x21
  int v15; // w8
  _QWORD v16[2]; // [xsp+0h] [xbp-20h] BYREF
  int v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v4 = a2;
  v5 = a1;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v16[0] = 0;
  v16[1] = 0;
  _rcu_read_lock(a1, a2, a3, a4);
  ecn_map = rmnet_perf_get_ecn_map();
  v7 = xa_load(ecn_map, *(unsigned int *)(v5 + 152));
  if ( !v7 )
    goto LABEL_10;
  ++*(_DWORD *)(v7 + 20);
  if ( (int)(*(_DWORD *)(v5 + 112) - (*(_DWORD *)(v5 + 116) + v4)) <= 19 )
  {
    if ( !v5 )
      goto LABEL_11;
    v14 = v7;
    v8 = v16;
    v15 = skb_copy_bits(v5, v4, v16, 20);
    v7 = v14;
    if ( v15 < 0 )
      goto LABEL_10;
  }
  else
  {
    v8 = (_QWORD *)(*(_QWORD *)(v5 + 224) + (int)v4);
    if ( !v8 )
    {
LABEL_10:
      LODWORD(v5) = 0;
      goto LABEL_11;
    }
  }
  if ( (*((_BYTE *)v8 + 13) & 0x87) != 0 || *(_DWORD *)(v7 + 20) < *(_DWORD *)(v7 + 16) )
    goto LABEL_10;
  v9 = *(unsigned __int8 *)(v7 + 28);
  v10 = *(_DWORD *)(v7 + 24) + 1;
  *(_DWORD *)(v7 + 20) = 0;
  *(_DWORD *)(v7 + 24) = v10;
  if ( v9 != 1 )
  {
    v11 = *(_DWORD *)(v5 + 112);
    v12 = v11 - *(_DWORD *)(v5 + 116);
    if ( v4 <= v12 || v11 >= v4 && _pskb_pull_tail(v5, v4 - v12) )
    {
      v7 = INET_ECN_set_ce(v5);
      goto LABEL_10;
    }
  }
  v7 = sk_skb_reason_drop(0, v5, 2);
  LODWORD(v5) = 1;
LABEL_11:
  _rcu_read_unlock(v7);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
