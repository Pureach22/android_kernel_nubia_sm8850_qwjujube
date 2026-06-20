__int64 __fastcall gen7_preemption_schedule(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  int v3; // w8
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x20
  int v8; // w22
  int v9; // w21
  int rptr; // w25
  int v11; // w23
  int v12; // w24
  int v13; // w0
  unsigned int v20; // w9

  if ( (*(_QWORD *)(result + 14240) & 0x200) != 0 )
  {
    v1 = result;
    v2 = result + 20480;
    rt_mutex_lock(result + 11088);
    if ( *(_DWORD *)(v2 + 8) == 5 )
    {
      v3 = *(_DWORD *)(v1 + 11120);
      if ( v3 == 32 || v3 == 2 )
      {
        v4 = kgsl_regmap_read(v1 + 13200);
        if ( (v4 & 1) != 0 )
        {
          v7 = *(_QWORD *)v1;
          v8 = v4;
          v9 = *(_DWORD *)(*(_QWORD *)(v1 + 19640) + 28LL);
          rptr = adreno_get_rptr(*(_QWORD *)(v1 + 19640));
          v11 = *(_DWORD *)(*(_QWORD *)(v1 + 19640) + 20LL);
          v12 = *(_DWORD *)(*(_QWORD *)(v1 + 19648) + 28LL);
          v13 = adreno_get_rptr(*(_QWORD *)(v1 + 19648));
          dev_err(
            v7,
            "Preemption not complete: status=%X cur=%d R/W=%X/%X next=%d R/W=%X/%X\n",
            v8,
            v9,
            rptr,
            v11,
            v12,
            v13,
            *(_DWORD *)(*(_QWORD *)(v1 + 19648) + 20LL));
          _X8 = (unsigned int *)(v1 + 24448);
          __asm { PRFM            #0x11, [X8] }
          do
            v20 = __ldxr(_X8);
          while ( __stxr(v20 | 0x10, _X8) );
          __dmb(0xAu);
          kthread_queue_work(*(_QWORD *)(v1 + 24400), v1 + 24408);
        }
        else
        {
          ++*(_DWORD *)(v2 + 104);
          timer_delete_sync(v1 + 20504);
          kgsl_regmap_read(v1 + 13200);
          v5 = *(_QWORD *)(v1 + 19640);
          v6 = *(_QWORD *)(v1 + 19648);
          *(_QWORD *)(v1 + 19648) = 0;
          *(_QWORD *)(v1 + 19656) = v5;
          *(_QWORD *)(v1 + 19640) = v6;
          update_wptr_0((_QWORD *)v1, 1, 0);
          mod_timer(v1 + 19816);
          __dmb(0xAu);
          *(_DWORD *)(v2 + 8) = 0;
          __dmb(0xAu);
        }
      }
    }
    gen7_preemption_trigger(v1, 0);
    return rt_mutex_unlock(v1 + 11088);
  }
  return result;
}
