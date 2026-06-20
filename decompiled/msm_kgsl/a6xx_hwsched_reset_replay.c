__int64 __fastcall a6xx_hwsched_reset_replay(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  _QWORD *i; // x23
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v16; // x10

  v2 = to_a6xx_gmu(a1);
  v3 = to_a6xx_hwsched_hfi(a1);
  raw_read_lock(v3 + 4);
  for ( i = *(_QWORD **)(v3 + 16); i != (_QWORD *)(v3 + 16); i = (_QWORD *)*i )
  {
    if ( *((unsigned __int8 *)i - 112) == 129 )
      complete(i - 4);
  }
  raw_read_unlock(v3 + 4);
  adreno_hwsched_unregister_contexts(a1);
  if ( (*(_QWORD *)(v2 + 1296) & 2) == 0 )
    return 0;
  a6xx_disable_gpu_irq(a1);
  a6xx_gmu_irq_disable(a1);
  a6xx_hwsched_hfi_stop(a1);
  a6xx_gmu_suspend(a1, 1);
  adreno_hwsched_reset_hfi_mem(a1);
  if ( *(_BYTE *)(a1 + 20832) == 1 )
  {
    v5 = *(_QWORD *)(a1 + 20824);
    if ( v5 )
    {
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20848) == 1 )
  {
    v6 = *(_QWORD *)(a1 + 20840);
    if ( v6 )
    {
      if ( v6 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20864) == 1 )
  {
    v7 = *(_QWORD *)(a1 + 20856);
    if ( v7 )
    {
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  _X8 = (unsigned __int64 *)(v2 + 1296);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  v8 = a6xx_hwsched_boot(a1);
  if ( !(_DWORD)v8 )
  {
    adreno_hwsched_replay(a1);
    return 0;
  }
  __break(0x800u);
  return a6xx_hwsched_boot(v8);
}
