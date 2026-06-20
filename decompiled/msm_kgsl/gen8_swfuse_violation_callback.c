__int64 __fastcall gen8_swfuse_violation_callback(_QWORD *a1)
{
  int v2; // w20
  __int64 result; // x0
  unsigned int v10; // w9

  v2 = kgsl_regmap_read(a1 + 1650);
  kgsl_regmap_write(a1 + 1650, 0);
  result = __ratelimit(&gen8_swfuse_violation_callback__rs, "gen8_swfuse_violation_callback");
  if ( (_DWORD)result )
  {
    result = dev_crit(*a1, "RBBM: SW Feature Fuse violation status=0x%8.8x\n", v2);
    if ( (v2 & 6) == 0 )
      return result;
  }
  else if ( (v2 & 6) == 0 )
  {
    return result;
  }
  adreno_irqctrl((__int64)a1, 0);
  _X8 = (unsigned int *)(a1 + 3056);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | 2, _X8) );
  __dmb(0xAu);
  return kthread_queue_work(a1[3050], a1 + 3051);
}
