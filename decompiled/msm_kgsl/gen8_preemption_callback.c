__int64 __fastcall gen8_preemption_callback(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x21
  int v3; // w0
  __int64 v4; // x23
  __int64 v5; // x8
  __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x22
  unsigned int v16; // w8

  v1 = (_QWORD *)result;
  v2 = result + 20480;
  _X9 = (unsigned int *)(result + 20488);
  __asm { PRFM            #0x11, [X9] }
  while ( 1 )
  {
    v16 = __ldxr(_X9);
    if ( v16 != 2 )
      break;
    if ( !__stlxr(4u, _X9) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v16 == 2 )
  {
    v3 = kgsl_regmap_read(result + 13200);
    if ( (v3 & 1) != 0 )
    {
      dev_err(*v1, "preempt interrupt with non-zero status: %X\n", v3);
      __dmb(0xAu);
      *(_DWORD *)(v2 + 8) = 5;
      __dmb(0xAu);
      return kthread_queue_work(v1[3050], v1 + 3051);
    }
    else
    {
      ++*(_DWORD *)(v2 + 104);
      gmu_core_regwrite(v1, 128997, 0);
      timer_delete(v1 + 2563);
      kgsl_regmap_read(v1 + 1650);
      v4 = v1[2456];
      v5 = v1[2455];
      v1[2456] = 0;
      v1[2457] = v5;
      v1[2455] = v4;
      v6 = raw_spin_lock_irqsave(v4 + 1292);
      v7 = kgsl_regmap_read(v1 + 1650);
      v8 = *(unsigned int *)(v4 + 20);
      if ( v7 != (_DWORD)v8 )
        kgsl_regmap_write(v1 + 1650, v8);
      v9 = jiffies;
      *(_QWORD *)(v4 + 1248) = _msecs_to_jiffies((unsigned int)adreno_drawobj_timeout) + v9;
      raw_spin_unlock_irqrestore(v4 + 1292, v6);
      mod_timer(v1 + 2477);
      __dmb(0xAu);
      *(_DWORD *)(v2 + 8) = 0;
      __dmb(0xAu);
      return gen8_preemption_trigger((__int64)v1, 1);
    }
  }
  return result;
}
