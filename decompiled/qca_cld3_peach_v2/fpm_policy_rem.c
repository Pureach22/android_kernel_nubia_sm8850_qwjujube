__int64 __fastcall fpm_policy_rem(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x23
  unsigned int v14; // w22
  __int64 *v15; // x28
  __int64 v16; // x8
  __int64 *v17; // x24
  __int64 v18; // x8
  __int64 *v19; // x9
  char v20; // w10
  __int64 v21; // x27
  __int64 context; // x0
  __int64 v23; // x22
  __int64 v24; // x8
  __int64 v25; // x8
  unsigned __int64 v27; // [xsp+10h] [xbp-50h]

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: fpm_ctx is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "fpm_policy_rem");
    v14 = 4;
    goto LABEL_32;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1);
  }
  else
  {
    raw_spin_lock_bh(a1);
    *(_QWORD *)(a1 + 8) |= 1uLL;
  }
  v13 = 0;
  v14 = 4;
  v27 = _ReadStatusReg(SP_EL0);
  do
  {
    v15 = *(__int64 **)(a1 + 16 + 8 * v13);
    if ( v15 )
    {
      while ( 1 )
      {
        v17 = (__int64 *)*v15;
        if ( v15[5] != a2 )
          goto LABEL_13;
        qdf_atomic_notfier_call();
        v18 = *v15;
        v19 = (__int64 *)v15[1];
        *v19 = *v15;
        if ( v18 )
          *(_QWORD *)(v18 + 8) = v19;
        v15[1] = 0xDEAD000000000122LL;
        v20 = *(_BYTE *)(a1 + 84);
        *(_DWORD *)(a1 + 80) &= ~(unsigned int)(1LL << v15[5]);
        *(_BYTE *)(a1 + 84) = v20 - 1;
        if ( (v15[12] & 2) != 0 )
        {
          v21 = *((unsigned __int8 *)v15 + 101);
          context = dp_get_context();
          if ( context )
          {
            if ( (unsigned int)v21 <= 0x1F )
            {
              v23 = *(_QWORD *)(context + 1552);
              if ( v23 )
                break;
            }
          }
        }
LABEL_12:
        call_rcu(v15 + 2, fpm_free_cb);
        v14 = 0;
LABEL_13:
        v15 = v17;
        if ( !v17 )
          goto LABEL_7;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v27 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v23 + 264);
        v24 = *(_QWORD *)(v23 + 8 * v21);
        if ( !v24 )
          goto LABEL_10;
      }
      else
      {
        raw_spin_lock_bh(v23 + 264);
        *(_QWORD *)(v23 + 272) |= 1uLL;
        v24 = *(_QWORD *)(v23 + 8 * v21);
        if ( !v24 )
        {
LABEL_10:
          v16 = *(_QWORD *)(v23 + 272);
          if ( (v16 & 1) != 0 )
          {
            *(_QWORD *)(v23 + 272) = v16 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v23 + 264);
          }
          else
          {
            raw_spin_unlock(v23 + 264);
          }
          goto LABEL_12;
        }
      }
      --*(_BYTE *)(v24 + 17);
      goto LABEL_10;
    }
LABEL_7:
    ++v13;
  }
  while ( v13 != 8 );
  v25 = *(_QWORD *)(a1 + 8);
  if ( (v25 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 8) = v25 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1);
  }
  else
  {
    raw_spin_unlock(a1);
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v14;
}
