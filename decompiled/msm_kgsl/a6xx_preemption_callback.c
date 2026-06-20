__int64 __fastcall a6xx_preemption_callback(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x21
  int v3; // w0
  int *v4; // x8
  int v5; // w20
  const char *v6; // x0
  __int64 v7; // x23
  __int64 v8; // x8
  __int64 v9; // x20
  int v10; // w0
  __int64 v11; // x1
  __int64 v12; // x22
  unsigned int v19; // w8

  v1 = (_QWORD *)result;
  v2 = result + 20480;
  _X9 = (unsigned int *)(result + 20488);
  __asm { PRFM            #0x11, [X9] }
  while ( 1 )
  {
    v19 = __ldxr(_X9);
    if ( v19 != 2 )
      break;
    if ( !__stlxr(4u, _X9) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v19 == 2 )
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
      if ( (gmu_core_isenabled(v1) & 1) != 0 )
      {
        v4 = (int *)v1[1783];
        v5 = *v4;
        if ( *v4 == 660
          || (v6 = *((const char **)v4 + 3)) != nullptr && !strcmp(v6, "qcom,adreno-gpu-a642l")
          || (unsigned int)(v5 - 643) <= 0x14 && ((1 << (v5 + 125)) & 0x180001) != 0 )
        {
          gmu_core_regwrite(v1, 129220, 0);
        }
        else
        {
          gmu_core_regrmw(v1, 146198, 2, 0);
        }
      }
      timer_delete(v1 + 2563);
      kgsl_regmap_read(v1 + 1650);
      v7 = v1[2456];
      v8 = v1[2455];
      v1[2456] = 0;
      v1[2457] = v8;
      v1[2455] = v7;
      v9 = raw_spin_lock_irqsave(v7 + 1292);
      v10 = kgsl_regmap_read(v1 + 1650);
      v11 = *(unsigned int *)(v7 + 20);
      if ( v10 != (_DWORD)v11 )
        kgsl_regmap_write(v1 + 1650, v11);
      v12 = jiffies;
      *(_QWORD *)(v7 + 1248) = _msecs_to_jiffies((unsigned int)adreno_drawobj_timeout) + v12;
      raw_spin_unlock_irqrestore(v7 + 1292, v9);
      mod_timer(v1 + 2477);
      __dmb(0xAu);
      *(_DWORD *)(v2 + 8) = 0;
      __dmb(0xAu);
      return a6xx_preemption_trigger((__int64)v1, 1);
    }
  }
  return result;
}
