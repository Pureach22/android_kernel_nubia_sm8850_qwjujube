__int64 __fastcall dp_mon_pool_frag_unmap_and_free(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w22
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 24);
    if ( !*(_DWORD *)a2 )
      goto LABEL_13;
  }
  else
  {
    raw_spin_lock_bh(a2 + 24);
    *(_QWORD *)(a2 + 32) |= 1uLL;
    if ( !*(_DWORD *)a2 )
      goto LABEL_13;
  }
  v5 = 0;
  do
  {
    v6 = *(_QWORD *)(a2 + 8) + 32LL * (int)v5;
    v7 = *(_DWORD *)(v6 + 16);
    if ( (v7 & 1) != 0 )
    {
      v8 = *(_QWORD *)v6;
      if ( (v7 & 2) == 0 )
      {
        _qdf_mem_unmap_page(*(_QWORD *)(a1 + 24), *(_QWORD *)(v6 + 8), *(unsigned __int16 *)(a2 + 42), 2);
        v9 = *(_QWORD *)(a2 + 8) + 32LL * (int)v5;
        *(_DWORD *)(v9 + 16) |= 2u;
        *(_DWORD *)(*(_QWORD *)(a2 + 8) + 32LL * (int)v5 + 24) = v5;
      }
      if ( v8 )
        page_frag_free(v8);
    }
    ++v5;
  }
  while ( v5 < *(_DWORD *)a2 );
LABEL_13:
  v10 = *(_QWORD *)(a2 + 32);
  if ( (v10 & 1) == 0 )
    return raw_spin_unlock(a2 + 24);
  *(_QWORD *)(a2 + 32) = v10 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a2 + 24);
}
