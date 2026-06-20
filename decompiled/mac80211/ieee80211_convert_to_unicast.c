__int64 __fastcall ieee80211_convert_to_unicast(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v4; // x22
  __int64 *v8; // x23
  __int64 *v9; // x24
  __int64 *v10; // x27
  __int64 v11; // x25
  __int64 *v12; // x26
  __int64 v13; // x0
  _QWORD *v14; // x21
  __int64 v15; // x8
  _QWORD *v16; // x8
  __int64 v17; // x8
  _QWORD *v18; // x8
  __int64 *i; // x1
  __int64 v21; // x8
  _QWORD *v22; // x9

  v3 = *(_QWORD *)(a2 + 4304);
  v4 = a1[28];
  _rcu_read_lock(a1, a2);
  v8 = *(__int64 **)(v3 + 1616);
  v9 = (__int64 *)(v3 + 1616);
  if ( v8 == v9 )
  {
LABEL_15:
    v13 = sk_skb_reason_drop(0);
    return _rcu_read_unlock(v13);
  }
  v10 = nullptr;
  v11 = a2 + 2688;
  do
  {
    v12 = v10;
    if ( v11 != v8[10]
      || !(*((_DWORD *)v8 + 672) ^ *(_DWORD *)(v4 + 6)
         | *((unsigned __int16 *)v8 + 1346) ^ *(unsigned __int16 *)(v4 + 10)) )
    {
      goto LABEL_3;
    }
    v10 = v8;
    if ( v12 )
    {
      v13 = skb_clone(a1, 2080);
      if ( !v13 )
        goto LABEL_18;
      v14 = (_QWORD *)v13;
      if ( (unsigned int)skb_ensure_writable(v13, 14) )
      {
        v13 = consume_skb(v14);
        goto LABEL_18;
      }
      v15 = v14[28];
      *(_DWORD *)v15 = *((_DWORD *)v8 + 672);
      *(_WORD *)(v15 + 4) = *((_WORD *)v8 + 1346);
      v16 = *(_QWORD **)(a3 + 8);
      *v14 = a3;
      v14[1] = v16;
      *(_QWORD *)(a3 + 8) = v14;
      *v16 = v14;
      ++*(_DWORD *)(a3 + 16);
LABEL_3:
      v10 = v12;
    }
    v8 = (__int64 *)*v8;
  }
  while ( v8 != v9 );
  if ( !v10 )
    goto LABEL_15;
  v13 = skb_ensure_writable(a1, 14);
  if ( !(_DWORD)v13 )
  {
    v17 = a1[28];
    *(_DWORD *)v17 = *((_DWORD *)v10 + 672);
    *(_WORD *)(v17 + 4) = *((_WORD *)v10 + 1346);
    goto LABEL_14;
  }
LABEL_18:
  for ( i = *(__int64 **)a3; *(_QWORD *)a3 != a3 && i; i = *(__int64 **)a3 )
  {
    --*(_DWORD *)(a3 + 16);
    v21 = *i;
    v22 = (_QWORD *)i[1];
    *i = 0;
    i[1] = 0;
    *(_QWORD *)(v21 + 8) = v22;
    *v22 = v21;
    v13 = sk_skb_reason_drop(0);
  }
LABEL_14:
  v18 = *(_QWORD **)(a3 + 8);
  *a1 = a3;
  a1[1] = v18;
  *(_QWORD *)(a3 + 8) = a1;
  *v18 = a1;
  ++*(_DWORD *)(a3 + 16);
  return _rcu_read_unlock(v13);
}
