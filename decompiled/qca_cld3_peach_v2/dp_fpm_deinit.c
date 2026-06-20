__int64 __fastcall dp_fpm_deinit(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x22
  unsigned __int64 v4; // x26
  __int64 *v5; // x27
  __int64 v6; // x8
  __int64 *v7; // x28
  __int64 v8; // x8
  __int64 *v9; // x9
  char v10; // w10
  __int64 v11; // x23
  __int64 context; // x0
  __int64 v13; // x19
  __int64 v14; // x8
  __int64 v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(a1 + 3712);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1);
  }
  else
  {
    raw_spin_lock_bh(v1);
    *(_QWORD *)(v1 + 8) |= 1uLL;
  }
  v3 = 0;
  v4 = _ReadStatusReg(SP_EL0);
  do
  {
    v5 = *(__int64 **)(v1 + 16 + 8 * v3);
    if ( v5 )
    {
      while ( 1 )
      {
        v7 = v5;
        v5 = (__int64 *)*v5;
        qdf_atomic_notfier_call();
        v8 = *v7;
        v9 = (__int64 *)v7[1];
        *v9 = *v7;
        if ( v8 )
          *(_QWORD *)(v8 + 8) = v9;
        v7[1] = 0xDEAD000000000122LL;
        v10 = *(_BYTE *)(v1 + 84);
        *(_DWORD *)(v1 + 80) &= ~(unsigned int)(1LL << v7[5]);
        *(_BYTE *)(v1 + 84) = v10 - 1;
        if ( (v7[12] & 2) == 0 )
          goto LABEL_11;
        v11 = *((unsigned __int8 *)v7 + 101);
        context = dp_get_context();
        if ( !context )
          goto LABEL_11;
        if ( (unsigned int)v11 > 0x1F )
          goto LABEL_11;
        v13 = *(_QWORD *)(context + 1552);
        if ( !v13 )
          goto LABEL_11;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v4 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v4 + 16) & 0xFF00) != 0 )
        {
          break;
        }
        raw_spin_lock_bh(v13 + 264);
        *(_QWORD *)(v13 + 272) |= 1uLL;
        v14 = *(_QWORD *)(v13 + 8 * v11);
        if ( v14 )
          goto LABEL_22;
LABEL_9:
        v6 = *(_QWORD *)(v13 + 272);
        if ( (v6 & 1) != 0 )
        {
          *(_QWORD *)(v13 + 272) = v6 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v13 + 264);
        }
        else
        {
          raw_spin_unlock(v13 + 264);
        }
LABEL_11:
        call_rcu(v7 + 2, fpm_free_cb);
        if ( !v5 )
          goto LABEL_6;
      }
      raw_spin_lock(v13 + 264);
      v14 = *(_QWORD *)(v13 + 8 * v11);
      if ( !v14 )
        goto LABEL_9;
LABEL_22:
      --*(_BYTE *)(v14 + 17);
      goto LABEL_9;
    }
LABEL_6:
    ++v3;
  }
  while ( v3 != 8 );
  v15 = *(_QWORD *)(v1 + 8);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(v1 + 8) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v1);
  }
  else
  {
    raw_spin_unlock(v1);
  }
  _qdf_mem_free(*(_QWORD *)(a1 + 3712));
  *(_QWORD *)(a1 + 3712) = 0;
  result = qdf_trace_msg(0x45u, 5u, "%s: deinit success", v16, v17, v18, v19, v20, v21, v22, v23, "dp_fpm_deinit");
  _ReadStatusReg(SP_EL0);
  return result;
}
