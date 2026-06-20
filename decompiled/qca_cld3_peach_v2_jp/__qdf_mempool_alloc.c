__int64 __fastcall _qdf_mempool_alloc(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x9
  _QWORD *v5; // x10
  __int64 v6; // x11
  __int64 v7; // x0
  _QWORD *v8; // x19

  if ( !a2 )
    return 0;
  if ( prealloc_disabled == 1 )
    return _qdf_mem_malloc(*(_QWORD *)(a2 + 8), "__qdf_mempool_alloc", 1302);
  raw_spin_lock_bh(a2 + 48);
  v5 = (_QWORD *)(a2 + 32);
  v4 = *(_QWORD **)(a2 + 32);
  if ( v4 )
  {
    v6 = *v4;
    *v5 = *v4;
    if ( !v6 )
      *(_QWORD *)(a2 + 40) = v5;
    --*(_DWORD *)(a2 + 56);
  }
  v7 = a2 + 48;
  v8 = v4;
  raw_spin_unlock_bh(v7);
  return (__int64)v8;
}
