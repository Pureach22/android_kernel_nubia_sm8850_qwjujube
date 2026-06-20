__int64 __fastcall _qrtr_bind(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x19
  unsigned int v6; // w22
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x21
  __int64 v10; // x1
  __int64 v11; // x22
  unsigned int v12; // w0
  __int64 v14; // x0
  __int64 v15; // x23
  __int64 v17; // x1
  unsigned int v19; // w8
  int v21; // w8
  __int64 v22; // x9
  __int64 v24; // x1
  unsigned int v30; // w8
  int v31; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 24);
  if ( !a3 && *(_DWORD *)(a2 + 8) == *(_DWORD *)(v5 + 848) )
  {
    v6 = 0;
    goto LABEL_43;
  }
  v7 = raw_spin_lock_irqsave(&qrtr_port_lock);
  v8 = *(_DWORD *)(a2 + 8);
  v9 = v7;
  v31 = v8;
  if ( v8 )
  {
    if ( v8 >= 0x4000 )
      goto LABEL_11;
    if ( (capable(12) & 1) == 0 && !(unsigned int)in_egroup_p(2906) && !(unsigned int)in_egroup_p(0) )
    {
      v6 = -13;
      goto LABEL_42;
    }
    v8 = v31;
    if ( v31 == -2 )
    {
      raw_spin_lock(&qrtr_ports);
      v10 = 0;
    }
    else
    {
LABEL_11:
      v11 = v8;
      raw_spin_lock(&qrtr_ports);
      v10 = v11;
    }
    v12 = _xa_insert(&qrtr_ports, v10, v5, 2080);
  }
  else
  {
    raw_spin_lock(&qrtr_ports);
    v12 = _xa_alloc_cyclic(&qrtr_ports, &v31, v5, 0x400000007FFFLL, &qrtr_ports_next, 2080);
  }
  v6 = v12;
  raw_spin_unlock(&qrtr_ports);
  if ( v6 == -16 )
  {
    v6 = -98;
LABEL_42:
    raw_spin_unlock_irqrestore(&qrtr_port_lock, v9);
    goto LABEL_43;
  }
  if ( (v6 & 0x80000000) != 0 )
    goto LABEL_42;
  _X0 = (unsigned int *)(v5 + 128);
  __asm { PRFM            #0x11, [X0] }
  do
    v30 = __ldxr(_X0);
  while ( __stxr(v30 + 1, _X0) );
  if ( v30 )
  {
    if ( (((v30 + 1) | v30) & 0x80000000) == 0 )
      goto LABEL_19;
    v24 = 1;
  }
  else
  {
    v24 = 2;
  }
  refcount_warn_saturate(_X0, v24);
LABEL_19:
  if ( v31 == -2 )
  {
    _rcu_read_lock();
    v32[0] = 1;
    v14 = xa_find(&qrtr_ports, v32, -1, 8);
    if ( v14 )
    {
      v15 = v14;
      do
      {
        _X24 = (unsigned int *)(v15 + 128);
        __asm { PRFM            #0x11, [X24] }
        do
          v19 = __ldxr(_X24);
        while ( __stxr(v19 + 1, _X24) );
        if ( v19 )
        {
          if ( (((v19 + 1) | v19) & 0x80000000) == 0 )
            goto LABEL_26;
          v17 = 1;
        }
        else
        {
          v17 = 2;
        }
        refcount_warn_saturate(v15 + 128, v17);
LABEL_26:
        *(_DWORD *)(v15 + 284) = 102;
        sk_error_report(v15);
        __asm { PRFM            #0x11, [X24] }
        do
          v21 = __ldxr(_X24);
        while ( __stlxr(v21 - 1, _X24) );
        if ( v21 == 1 )
        {
          __dmb(9u);
          sk_free(v15);
        }
        else if ( v21 <= 0 )
        {
          refcount_warn_saturate(v15 + 128, 3);
        }
        v15 = xa_find_after(&qrtr_ports, v32, -1, 8);
      }
      while ( v15 );
    }
    _rcu_read_unlock();
  }
  raw_spin_unlock_irqrestore(&qrtr_port_lock, v9);
  if ( !a3 )
    qrtr_port_remove((_DWORD *)v5);
  v22 = *(_QWORD *)(v5 + 96);
  v6 = 0;
  *(_DWORD *)(v5 + 848) = v31;
  *(_QWORD *)(v5 + 96) = v22 & 0xFFFFFFFFFFFFFEFFLL;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v6;
}
