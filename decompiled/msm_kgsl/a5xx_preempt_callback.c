__int64 __fastcall a5xx_preempt_callback(__int64 result)
{
  _QWORD *v1; // x19
  int v3; // w0
  __int64 v4; // x23
  __int64 v5; // x8
  __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x22
  unsigned int v15; // w8

  v1 = (_QWORD *)result;
  _X21 = (unsigned int *)(result + 20488);
  __asm { PRFM            #0x11, [X21] }
  while ( 1 )
  {
    v15 = __ldxr(_X21);
    if ( v15 != 2 )
      break;
    if ( !__stlxr(4u, _X21) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v15 == 2 )
  {
    v3 = kgsl_regmap_read(result + 13200);
    if ( v3 )
    {
      dev_err(*v1, "preempt interrupt with non-zero status: %X\n", v3);
      __dmb(0xAu);
      *_X21 = 5;
      __dmb(0xAu);
      return kthread_queue_work(v1[3050], v1 + 3051);
    }
    else
    {
      timer_delete(v1 + 2563);
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
      *_X21 = 0;
      __dmb(0xAu);
      return a5xx_preemption_trigger((__int64)v1);
    }
  }
  return result;
}
