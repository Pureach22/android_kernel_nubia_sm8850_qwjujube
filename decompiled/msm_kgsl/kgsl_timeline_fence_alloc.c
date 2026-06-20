__int64 __fastcall kgsl_timeline_fence_alloc(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned int v6; // w9
  unsigned int v7; // w22
  unsigned int v13; // w10
  _QWORD *v14; // x21
  _QWORD *v15; // x23
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 v17; // x0
  _QWORD *v18; // x2
  __int64 v19; // x9
  _QWORD *v20; // x8
  _QWORD *v21; // x1

  v4 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( !v4 )
    return -12;
  if ( !a1 )
    goto LABEL_35;
  _X8 = (unsigned int *)(a1 + 32);
  v6 = *(_DWORD *)(a1 + 32);
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
  v14 = (_QWORD *)v4;
  if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(a1 + 32, 0);
    v4 = (__int64)v14;
    if ( v7 )
      goto LABEL_14;
LABEL_35:
    *(_QWORD *)(v4 + 64) = 0;
    kfree(v4);
    return -2;
  }
  if ( !v7 )
    goto LABEL_35;
LABEL_14:
  *(_QWORD *)(v4 + 64) = a1;
  dma_fence_init(v14, &timeline_fence_ops, a1 + 28, *(_QWORD *)a1, a2);
  v15 = v14 + 9;
  v14[9] = v14 + 9;
  v14[10] = v14 + 9;
  raw_spin_lock_irq(a1 + 28);
  if ( (v14[6] & 1) == 0 )
  {
    v16 = *(__int64 (__fastcall **)(_QWORD))(v14[1] + 32LL);
    if ( !v16 )
      goto LABEL_20;
    if ( *((_DWORD *)v16 - 1) != 1879296680 )
      __break(0x8228u);
    if ( (v16(v14) & 1) != 0 )
    {
      dma_fence_signal_locked(v14);
    }
    else
    {
LABEL_20:
      v17 = raw_spin_lock_irqsave(a1 + 24);
      v18 = (_QWORD *)(a1 + 40);
      v19 = v17;
      v20 = (_QWORD *)(a1 + 40);
      while ( 1 )
      {
        v20 = (_QWORD *)*v20;
        if ( v20 == v18 )
          break;
        if ( v14[5] < *(v20 - 4) )
        {
          v21 = (_QWORD *)v20[1];
          if ( v15 != v20 && v21 != v15 && (_QWORD *)*v21 == v20 )
          {
            v20[1] = v15;
            v14[9] = v20;
LABEL_31:
            v14[10] = v21;
            *v21 = v15;
            goto LABEL_32;
          }
          goto LABEL_37;
        }
      }
      v21 = *(_QWORD **)(a1 + 48);
      if ( v15 != v18 && v21 != v15 && (_QWORD *)*v21 == v18 )
      {
        *(_QWORD *)(a1 + 48) = v15;
        v14[9] = v18;
        goto LABEL_31;
      }
LABEL_37:
      _list_add_valid_or_report(v14 + 9, v21);
LABEL_32:
      raw_spin_unlock_irqrestore(a1 + 24, v19);
    }
  }
  raw_spin_unlock_irq(a1 + 28, *(unsigned int *)(a1 + 8));
  log_kgsl_timeline_fence_alloc_event(*(unsigned int *)(a1 + 8), a2);
  return (__int64)v14;
}
