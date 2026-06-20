__int64 __fastcall a5xx_preemption_schedule(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8
  int v3; // w0
  __int64 v4; // x23
  __int64 v5; // x8
  __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x22
  __int64 v10; // x20
  int v11; // w22
  int v12; // w21
  int rptr; // w25
  int v14; // w23
  int v15; // w24
  int v16; // w0
  unsigned int v23; // w9

  if ( (*(_QWORD *)(result + 14240) & 0x200) != 0 )
  {
    v1 = result;
    rt_mutex_lock(result + 11088);
    if ( *(_DWORD *)(v1 + 20488) == 5 )
    {
      v2 = *(_DWORD *)(v1 + 11120);
      if ( v2 == 32 || v2 == 2 )
      {
        v3 = kgsl_regmap_read(v1 + 13200);
        if ( v3 )
        {
          v10 = *(_QWORD *)v1;
          v11 = v3;
          v12 = *(_DWORD *)(*(_QWORD *)(v1 + 19640) + 28LL);
          rptr = adreno_get_rptr(*(_QWORD *)(v1 + 19640));
          v14 = *(_DWORD *)(*(_QWORD *)(v1 + 19640) + 20LL);
          v15 = *(_DWORD *)(*(_QWORD *)(v1 + 19648) + 28LL);
          v16 = adreno_get_rptr(*(_QWORD *)(v1 + 19648));
          dev_err(
            v10,
            "Preemption not complete: status=%X cur=%d R/W=%X/%X next=%d R/W=%X/%X\n",
            v11,
            v12,
            rptr,
            v14,
            v15,
            v16,
            *(_DWORD *)(*(_QWORD *)(v1 + 19648) + 20LL));
          _X8 = (unsigned int *)(v1 + 24448);
          __asm { PRFM            #0x11, [X8] }
          do
            v23 = __ldxr(_X8);
          while ( __stxr(v23 | 0x10, _X8) );
          __dmb(0xAu);
          kthread_queue_work(*(_QWORD *)(v1 + 24400), v1 + 24408);
        }
        else
        {
          timer_delete_sync(v1 + 20504);
          v4 = *(_QWORD *)(v1 + 19648);
          v5 = *(_QWORD *)(v1 + 19640);
          *(_QWORD *)(v1 + 19648) = 0;
          *(_QWORD *)(v1 + 19656) = v5;
          *(_QWORD *)(v1 + 19640) = v4;
          v6 = raw_spin_lock_irqsave(v4 + 1292);
          v7 = kgsl_regmap_read(v1 + 13200);
          v8 = *(unsigned int *)(v4 + 20);
          if ( v7 != (_DWORD)v8 )
            kgsl_regmap_write(v1 + 13200, v8);
          v9 = jiffies;
          *(_QWORD *)(v4 + 1248) = _msecs_to_jiffies((unsigned int)adreno_drawobj_timeout) + v9;
          raw_spin_unlock_irqrestore(v4 + 1292, v6);
          mod_timer(v1 + 19816);
          __dmb(0xAu);
          *(_DWORD *)(v1 + 20488) = 0;
          __dmb(0xAu);
        }
      }
    }
    a5xx_preemption_trigger(v1);
    return rt_mutex_unlock(v1 + 11088);
  }
  return result;
}
