__int64 __fastcall a5xx_irq_storm_worker(__int64 a1)
{
  __int64 v2; // x1
  unsigned __int64 v10; // x10

  rt_mutex_lock(a1 - 9680);
  do
    kgsl_regmap_write(a1 - 7568, 0x100000);
  while ( (kgsl_regmap_read(a1 - 7568) & 0x100000) != 0 );
  v2 = *(_DWORD *)(a1 + 120) | 0x100000u;
  *(_DWORD *)(a1 + 120) = v2;
  kgsl_regmap_write(a1 - 7568, v2);
  _X8 = (unsigned __int64 *)(a1 - 6528);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 & 0xFFFFFFFFFFFFDFFFLL, _X8) );
  dev_warn(*(_QWORD *)(a1 - 20768), "Re-enabled A5XX_INT_CP_CACHE_FLUSH_TS\n");
  rt_mutex_unlock(a1 - 9680);
  return kthread_queue_work(*(_QWORD *)(a1 + 3632), a1 + 3640);
}
