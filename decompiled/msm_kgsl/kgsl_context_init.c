__int64 __fastcall kgsl_context_init(_QWORD *a1, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x20
  unsigned int v6; // w21
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned int v13; // w8
  unsigned int v14; // w27
  unsigned int v16; // w9
  int v17; // w7
  unsigned int v18; // w23
  __int64 v19; // x8
  int v20; // w2
  unsigned int v28; // w9
  unsigned int v31; // w10
  unsigned int v34; // w10
  char v35; // [xsp+0h] [xbp+0h]

  v2 = (_QWORD *)*a1;
  v3 = a1[1];
  raw_spin_lock(v3 + 380);
  if ( *(int *)(v3 + 376) >= 201 )
  {
    v19 = *(_QWORD *)(v3 + 8);
    if ( v19 )
      v20 = *(_DWORD *)(v19 + 112);
    else
      v20 = 0;
    dev_err(*v2, "Per process context limit reached for pid %u\n", v20);
    raw_spin_unlock(v3 + 380);
    kgsl_context_debug_info(v2);
    return (unsigned int)-28;
  }
  _X8 = (unsigned int *)(v3 + 376);
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 + 1, _X8) );
  raw_spin_unlock(v3 + 380);
  idr_preload(3264);
  raw_write_lock(v2 + 1401);
  v6 = idr_alloc(v2 + 1398, 0, 1, 812, 10240);
  v7 = raw_write_unlock(v2 + 1401);
  _ReadStatusReg(TPIDR_EL1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v9;
  if ( v9 && *(_QWORD *)(StatusReg + 16) )
  {
    if ( v6 == -28 )
    {
LABEL_6:
      kthread_flush_worker(v2[1622]);
      idr_preload(3264);
      raw_write_lock(v2 + 1401);
      v6 = idr_alloc(v2 + 1398, 0, 1, 812, 10240);
      v10 = raw_write_unlock(v2 + 1401);
      _ReadStatusReg(TPIDR_EL1);
      v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v11;
      if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule(v10);
    }
  }
  else
  {
    preempt_schedule(v7);
    if ( v6 == -28 )
      goto LABEL_6;
  }
  if ( (v6 & 0x80000000) == 0 )
  {
    *(_DWORD *)(a2 + 4) = v6;
    _mutex_init(a2 + 312, "&context->fault_lock", &kgsl_context_init___key);
    *(_QWORD *)(a2 + 296) = a2 + 296;
    *(_QWORD *)(a2 + 304) = a2 + 296;
    *(_DWORD *)a2 = 1;
    if ( v3 )
    {
      _X0 = (unsigned int *)(v3 + 36);
      v13 = *(_DWORD *)(v3 + 36);
      if ( v13 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v16 = __ldxr(_X0);
          while ( v16 == v13 && __stxr(v13 + 1, _X0) );
          v14 = v13;
          if ( v16 == v13 )
            break;
          v14 = 0;
          v13 = v16;
        }
        while ( v16 );
      }
      else
      {
        v14 = 0;
      }
      if ( (((v14 + 1) | v14) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X0, 0);
        if ( v14 )
          goto LABEL_23;
      }
      else if ( v14 )
      {
LABEL_23:
        *(_QWORD *)(a2 + 40) = v2;
        *(_QWORD *)(a2 + 16) = a1;
        *(_QWORD *)(a2 + 24) = v3;
        *(_DWORD *)(a2 + 12) = *(_DWORD *)(StatusReg + 1800);
        v18 = kgsl_sync_timeline_create(a2);
        if ( !v18 )
        {
          kgsl_add_event_group((int)v2, a2 + 64, a2, (int)kgsl_readtimestamp, a2, "context-%d", v6, v17, v35);
          return v18;
        }
        kgsl_process_private_put(v3);
        goto LABEL_39;
      }
    }
    v18 = -9;
LABEL_39:
    _X8 = (unsigned int *)(v3 + 376);
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 - 1, _X8) );
    raw_write_lock(v2 + 1401);
    idr_remove(v2 + 1398);
    raw_write_unlock(v2 + 1401);
    return v18;
  }
  if ( v6 == -28 )
  {
    dev_warn(*v2, "cannot have more than %zu contexts due to memstore limitation\n", 0x32Du);
    kgsl_context_debug_info(v2);
  }
  _X8 = (unsigned int *)(v3 + 376);
  __asm { PRFM            #0x11, [X8] }
  do
    v34 = __ldxr(_X8);
  while ( __stxr(v34 - 1, _X8) );
  return v6;
}
