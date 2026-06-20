__int64 __fastcall kgsl_ioctl_syncsource_create(__int64 a1, __int64 a2, int *a3)
{
  unsigned int *v3; // x19
  unsigned int v5; // w8
  unsigned int v6; // w20
  unsigned int v12; // w9
  int *v13; // x22
  __int64 v14; // x0
  __int64 v15; // x20
  unsigned __int64 StatusReg; // x23
  int v17; // w21
  __int64 v18; // x0
  __int64 v19; // x8
  int *v21; // x21

  v3 = *(unsigned int **)(a1 + 8);
  if ( !v3 )
    return -22;
  _X0 = v3 + 9;
  v5 = v3[9];
  if ( v5 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v12 = __ldxr(_X0);
      while ( v12 == v5 && __stxr(v5 + 1, _X0) );
      v6 = v5;
      if ( v12 == v5 )
        break;
      v6 = 0;
      v5 = v12;
    }
    while ( v12 );
  }
  else
  {
    v6 = 0;
  }
  if ( (((v6 + 1) | v6) & 0x80000000) != 0 )
  {
    v21 = a3;
    refcount_warn_saturate(_X0, 0);
    a3 = v21;
    if ( v6 )
      goto LABEL_13;
    return -22;
  }
  if ( !v6 )
    return -22;
LABEL_13:
  v13 = a3;
  v14 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  v15 = v14;
  if ( v14 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)v14 = 1;
    snprintf((char *)(v14 + 4), 0x20u, "kgsl-syncsource-pid-%d", *(_DWORD *)(*(_QWORD *)(StatusReg + 1864) + 1800LL));
    *(_QWORD *)(v15 + 40) = v3;
    *(_QWORD *)(v15 + 48) = v15 + 48;
    *(_QWORD *)(v15 + 56) = v15 + 48;
    *(_DWORD *)(v15 + 64) = 0;
    idr_preload(3264);
    raw_spin_lock(v3 + 92);
    v17 = idr_alloc(v3 + 86, v15, 1, 0, 10240);
    if ( v17 >= 1 )
    {
      *(_DWORD *)(v15 + 36) = v17;
      *v13 = v17;
      v17 = 0;
    }
    v18 = raw_spin_unlock(v3 + 92);
    _ReadStatusReg(TPIDR_EL1);
    v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v19;
    if ( v19 && *(_QWORD *)(StatusReg + 16) )
    {
      if ( !v17 )
        return 0;
    }
    else
    {
      preempt_schedule(v18);
      if ( !v17 )
        return 0;
    }
  }
  else
  {
    v17 = -12;
  }
  kgsl_process_private_put(v3);
  kfree(v15);
  return v17;
}
