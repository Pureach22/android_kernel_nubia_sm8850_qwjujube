__int64 __fastcall a6xx_gpc_err_int_callback(_QWORD *a1)
{
  unsigned int v9; // w9

  dev_crit(*a1, "RBBM: GPC error\n");
  adreno_irqctrl((__int64)a1, 0);
  _X8 = (unsigned int *)(a1 + 3056);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 | 1, _X8) );
  __dmb(0xAu);
  return kthread_queue_work(a1[3050], a1 + 3051);
}
