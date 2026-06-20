__int64 __fastcall a5xx_preemption_worker(__int64 a1)
{
  int v2; // w8
  __int64 v4; // x0
  __int64 v5; // x20
  int v6; // w21
  int rptr; // w24
  int v8; // w22
  int v9; // w23
  int v10; // w0
  unsigned int v17; // w9

  rt_mutex_lock(a1 - 9456);
  if ( *(_DWORD *)(a1 - 56) == 3 )
  {
    v2 = *(_DWORD *)(a1 - 9424);
    if ( (v2 == 32 || v2 == 2) && !(unsigned int)kgsl_regmap_read(a1 - 7344) )
    {
      __dmb(0xAu);
      *(_DWORD *)(a1 - 56) = 5;
      __dmb(0xAu);
    }
    else
    {
      v4 = *(_QWORD *)(a1 - 904);
      v5 = *(_QWORD *)(a1 - 20544);
      v6 = *(_DWORD *)(v4 + 28);
      rptr = adreno_get_rptr(v4);
      v8 = *(_DWORD *)(*(_QWORD *)(a1 - 904) + 20LL);
      v9 = *(_DWORD *)(*(_QWORD *)(a1 - 896) + 28LL);
      v10 = adreno_get_rptr(*(_QWORD *)(a1 - 896));
      dev_err(
        v5,
        "Preemption timed out: cur=%d R/W=%X/%X, next=%d R/W=%X/%X\n",
        v6,
        rptr,
        v8,
        v9,
        v10,
        *(_DWORD *)(*(_QWORD *)(a1 - 896) + 20LL));
      _X8 = (unsigned int *)(a1 + 3904);
      __asm { PRFM            #0x11, [X8] }
      do
        v17 = __ldxr(_X8);
      while ( __stxr(v17 | 0x10, _X8) );
      __dmb(0xAu);
    }
    kthread_queue_work(*(_QWORD *)(a1 + 3856), a1 + 3864);
  }
  return rt_mutex_unlock(a1 - 9456);
}
