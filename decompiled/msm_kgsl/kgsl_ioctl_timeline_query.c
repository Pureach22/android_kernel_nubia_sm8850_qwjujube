__int64 __fastcall kgsl_ioctl_timeline_query(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  unsigned __int64 v6; // x19
  __int64 v7; // x1
  __int64 v8; // x22
  __int64 v9; // x21
  int v16; // w8

  if ( *(_DWORD *)(a3 + 12) )
    return -22;
  v5 = kgsl_timeline_by_id(*a1, *(_DWORD *)(a3 + 8));
  if ( !v5 )
    return -19;
  v6 = v5;
  raw_spin_lock_irq(v5 + 28);
  v8 = *(_QWORD *)(v6 + 64);
  v9 = *(_QWORD *)(v6 + 16);
  if ( v8 != v6 + 56 )
  {
    while ( !kgsl_check_timestamp(*(_QWORD *)(*(_QWORD *)(v8 - 16) + 40LL), *(_QWORD *)(v8 - 16), *(_DWORD *)(v8 - 8)) )
    {
      v8 = *(_QWORD *)(v8 + 8);
      if ( v8 == v6 + 56 )
        goto LABEL_10;
    }
    v9 = *(_QWORD *)(v8 - 24);
  }
LABEL_10:
  raw_spin_unlock_irq(v6 + 28, v7);
  *(_QWORD *)a3 = v9;
  if ( v6 <= 0xFFFFFFFFFFFFF000LL )
  {
    _X0 = (unsigned int *)(v6 + 32);
    __asm { PRFM            #0x11, [X0] }
    do
      v16 = __ldxr(_X0);
    while ( __stlxr(v16 - 1, _X0) );
    if ( v16 == 1 )
    {
      __dmb(9u);
      kgsl_timeline_destroy((__int64)_X0);
    }
    else if ( v16 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return 0;
}
