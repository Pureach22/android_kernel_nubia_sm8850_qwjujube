__int64 __fastcall ieee80211_set_qos_map(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x1

  if ( a3 )
  {
    v5 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
    if ( !v5 )
      return 4294967284LL;
    v6 = *(_QWORD *)(a3 + 32);
    v7 = *(_QWORD *)(a3 + 40);
    *(_QWORD *)(v5 + 48) = *(_QWORD *)(a3 + 48);
    *(_QWORD *)(v5 + 32) = v6;
    *(_QWORD *)(v5 + 40) = v7;
    *(_DWORD *)(v5 + 55) = *(_DWORD *)(a3 + 55);
    v8 = *(_QWORD *)(a3 + 8);
    *(_QWORD *)v5 = *(_QWORD *)a3;
    *(_QWORD *)(v5 + 8) = v8;
    v9 = *(_QWORD *)(a3 + 24);
    *(_QWORD *)(v5 + 16) = *(_QWORD *)(a3 + 16);
    *(_QWORD *)(v5 + 24) = v9;
  }
  else
  {
    v5 = 0;
  }
  v10 = *(_QWORD *)(a2 + 4640);
  atomic_store(v5, (unsigned __int64 *)(a2 + 4640));
  if ( v10 )
    kvfree_call_rcu(v10 + 64, v10);
  return 0;
}
