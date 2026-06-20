__int64 __fastcall kgsl_mem_entry_attach_to_process(__int64 a1, unsigned int *a2, __int64 a3)
{
  unsigned int v6; // w9
  unsigned int v7; // w21
  unsigned int v13; // w10
  __int64 v14; // x21
  unsigned int v15; // w21
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x9
  unsigned int *v19; // x8
  __int64 v20; // x8
  __int64 (*v21)(void); // x8
  __int64 v22; // x22
  __int64 v23; // x8
  __int64 v24; // x8
  void (__fastcall *v25)(_QWORD); // x8

  if ( !a2 )
    return (unsigned int)-9;
  _X8 = a2 + 9;
  v6 = a2[9];
  if ( v6 )
  {
    do
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v13 = __ldxr(_X8);
      while ( v13 == v6 && __stxr(v6 + 1, _X8) );
      v7 = v6;
      if ( v13 == v6 )
        break;
      v7 = 0;
      v6 = v13;
    }
    while ( v13 );
  }
  else
  {
    v7 = 0;
  }
  if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
  {
    v22 = a1;
    refcount_warn_saturate(a2 + 9, 0);
    a1 = v22;
    if ( v7 )
      goto LABEL_13;
    return (unsigned int)-9;
  }
  if ( !v7 )
    return (unsigned int)-9;
LABEL_13:
  if ( (*(_BYTE *)(a3 + 83) & 0x10) == 0 )
  {
    v14 = a1;
    if ( (unsigned int)kgsl_mmu_get_mmutype(a1) != 1 )
    {
      if ( (*(_DWORD *)(a3 + 56) & 0x10) != 0 )
        v19 = (unsigned int *)(v14 + 80);
      else
        v19 = a2 + 16;
      if ( !*(_QWORD *)v19
        || (v20 = *(_QWORD *)(*(_QWORD *)v19 + 96LL)) == 0
        || (v21 = *(__int64 (**)(void))(v20 + 72)) == nullptr )
      {
        v15 = -12;
LABEL_40:
        kgsl_process_private_put(a2);
        return v15;
      }
      if ( *((_DWORD *)v21 - 1) != -1528462336 )
        __break(0x8228u);
      v15 = v21();
      if ( v15 )
        goto LABEL_40;
    }
  }
  idr_preload(3264);
  raw_spin_lock(a2 + 8);
  v15 = idr_alloc(a2 + 10, 0, 1, 0, 10240);
  v16 = raw_spin_unlock(a2 + 8);
  _ReadStatusReg(TPIDR_EL1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v18;
  if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
  {
    preempt_schedule(v16);
    if ( (v15 & 0x80000000) == 0 )
      goto LABEL_18;
    goto LABEL_33;
  }
  if ( (v15 & 0x80000000) != 0 )
  {
LABEL_33:
    if ( (*(_BYTE *)(a3 + 83) & 0x10) == 0 )
    {
      v23 = *(_QWORD *)(a3 + 8);
      if ( v23 )
      {
        v24 = *(_QWORD *)(v23 + 96);
        if ( v24 )
        {
          v25 = *(void (__fastcall **)(_QWORD))(v24 + 80);
          if ( v25 )
          {
            if ( *((_DWORD *)v25 - 1) != 1555154090 )
              __break(0x8228u);
            v25(a3 + 8);
          }
        }
      }
    }
    goto LABEL_40;
  }
LABEL_18:
  *(_DWORD *)(a3 + 248) = v15;
  v15 = 0;
  *(_QWORD *)(a3 + 256) = a2;
  return v15;
}
