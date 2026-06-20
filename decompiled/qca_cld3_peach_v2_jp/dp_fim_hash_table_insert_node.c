__int64 __fastcall dp_fim_hash_table_insert_node(__int64 a1, unsigned int a2, unsigned __int64 *a3)
{
  int v5; // w21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 *v7; // x9
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // t1
  __int64 v10; // x8

  v5 = HIBYTE(a2) ^ HIWORD(a2) ^ (a2 >> 8) ^ a2;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 8);
  }
  else
  {
    raw_spin_lock_bh(a1 + 8);
    *(_QWORD *)(a1 + 16) |= 1uLL;
  }
  v7 = (unsigned __int64 *)(a1 + 8LL * (unsigned __int8)v5);
  v9 = v7[3];
  v7 += 3;
  v8 = v9;
  *a3 = v9;
  a3[1] = (unsigned __int64)v7;
  atomic_store((unsigned __int64)a3, v7);
  if ( v9 )
    *(_QWORD *)(v8 + 8) = a3;
  if ( a1 )
    ++*(_DWORD *)(a1 + 2116);
  v10 = *(_QWORD *)(a1 + 16);
  if ( (v10 & 1) == 0 )
    return raw_spin_unlock(a1 + 8);
  *(_QWORD *)(a1 + 16) = v10 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 8);
}
