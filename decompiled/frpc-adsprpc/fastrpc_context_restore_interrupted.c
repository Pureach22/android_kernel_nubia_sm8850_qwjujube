__int64 __fastcall fastrpc_context_restore_interrupted(_QWORD *a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x10
  __int64 v5; // x8
  int v6; // w11
  __int64 v7; // x20
  int v8; // w4
  int v9; // w2
  _QWORD **v10; // x3
  __int64 *v11; // x9
  _QWORD *v12; // x2
  __int64 *v13; // x1

  raw_spin_lock(a1 + 40);
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = a1[6];
  do
  {
    if ( (_QWORD *)v5 == a1 + 6 )
    {
      v7 = 0;
      goto LABEL_14;
    }
    v6 = *(_DWORD *)(v5 + 28);
    v7 = v5;
    v5 = *(_QWORD *)v5;
  }
  while ( v6 != *(_DWORD *)(StatusReg + 1800) );
  v8 = *(_DWORD *)(a2 + 4);
  v9 = *(_DWORD *)(v7 + 36);
  v10 = *(_QWORD ***)(v7 + 184);
  if ( v8 == v9 && v10 == a1 )
  {
    v11 = *(__int64 **)(v7 + 8);
    if ( *v11 == v7 && *(_QWORD *)(v5 + 8) == v7 )
    {
      *(_QWORD *)(v5 + 8) = v11;
      *v11 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v7);
    }
    v12 = a1 + 4;
    *(_QWORD *)v7 = 0xDEAD000000000100LL;
    *(_QWORD *)(v7 + 8) = 0xDEAD000000000122LL;
    v13 = (__int64 *)a1[5];
    if ( (_QWORD *)v7 == a1 + 4 || (__int64 *)v7 == v13 || (_QWORD *)*v13 != v12 )
    {
      _list_add_valid_or_report(v7, v13, v12);
    }
    else
    {
      a1[5] = v7;
      *(_QWORD *)v7 = v12;
      *(_QWORD *)(v7 + 8) = v13;
      *v13 = v7;
    }
  }
  else
  {
    dev_err(
      *v10[17],
      "interrupted sc (0x%x) or fl (%pK) does not match with invoke sc (0x%x) or fl (%pK)\n",
      v9,
      v10,
      v8,
      a1);
    v7 = -22;
  }
LABEL_14:
  raw_spin_unlock(a1 + 40);
  return v7;
}
