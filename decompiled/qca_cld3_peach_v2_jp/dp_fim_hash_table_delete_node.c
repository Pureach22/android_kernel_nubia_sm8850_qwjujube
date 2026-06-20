__int64 __fastcall dp_fim_hash_table_delete_node(__int64 a1, _DWORD *a2, __int64 a3, int a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x24
  bool v10; // zf
  int v11; // w28
  _QWORD *v12; // x27
  _QWORD *v13; // x26
  _QWORD *v14; // x8
  _QWORD *v15; // x9
  __int64 v16; // x8

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
  v9 = 0;
  if ( a2 )
    v10 = a3 == 0;
  else
    v10 = 1;
  v11 = !v10;
  do
  {
    v12 = *(_QWORD **)(a1 + 24 + 8 * v9);
    while ( v12 )
    {
      v13 = v12;
      v12 = (_QWORD *)*v12;
      if ( a4 <= 1 )
      {
        v14 = v12;
        if ( !a4 )
          goto LABEL_30;
        if ( v13[12] - jiffies + 30000LL < 0 )
          goto LABEL_29;
      }
      else if ( a4 == 2 )
      {
        if ( v11 && v13[13] == *(_QWORD *)(a3 + 48) )
        {
LABEL_29:
          v14 = (_QWORD *)*v13;
LABEL_30:
          v15 = (_QWORD *)v13[1];
          *v15 = v14;
          if ( v14 )
            v14[1] = v15;
          v13[1] = 0xDEAD000000000122LL;
          if ( a1 )
            --*(_DWORD *)(a1 + 2116);
          call_rcu(v13 + 2, dp_fim_free_cb);
        }
      }
      else
      {
        if ( a4 == 3 )
        {
          if ( !a2 )
            continue;
        }
        else if ( !v11 || *(unsigned __int8 *)(a3 + 56) < (unsigned int)*((unsigned __int8 *)v13 + 112) )
        {
          continue;
        }
        if ( fpm_flow_regex_match(a2, (_DWORD *)v13 + 8) )
          goto LABEL_29;
      }
    }
    ++v9;
  }
  while ( v9 != 256 );
  v16 = *(_QWORD *)(a1 + 16);
  if ( (v16 & 1) == 0 )
    return raw_spin_unlock(a1 + 8);
  *(_QWORD *)(a1 + 16) = v16 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 8);
}
