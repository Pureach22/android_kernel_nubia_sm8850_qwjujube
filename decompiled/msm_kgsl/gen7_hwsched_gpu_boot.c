__int64 __fastcall gen7_hwsched_gpu_boot(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v4; // x8
  void (__fastcall *v5)(_QWORD); // x8
  unsigned int v6; // w0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  __int64 v10; // x8
  unsigned __int64 v17; // x10

  v2 = kgsl_mmu_start(a1);
  if ( v2 || (v2 = gen7_gmu_oob_set(a1, 0)) != 0 )
  {
LABEL_3:
    gen7_gmu_oob_clear(a1, 0);
    gen7_hwsched_gmu_power_off(a1);
    return v2;
  }
  *(_QWORD *)(a1 + 20376) = 0;
  *(_QWORD *)(a1 + 20368) = 0;
  *(_QWORD *)(a1 + 20360) = 0;
  *(_QWORD *)(a1 + 20352) = 0;
  *(_QWORD *)(a1 + 20344) = 0;
  *(_QWORD *)(a1 + 20336) = 0;
  *(_DWORD *)(a1 + 20384) = 0;
  ((void (__fastcall *)(__int64))gen7_start)(a1);
  adreno_coresight_start(a1);
  adreno_perfcounter_start(a1);
  v4 = *(_QWORD *)(a1 + 88);
  if ( v4 )
  {
    v5 = *(void (__fastcall **)(_QWORD))(v4 + 40);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -919125270 )
        __break(0x8228u);
      v5(a1 + 56);
    }
  }
  gen7_enable_gpu_irq(a1);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 24LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 28LL));
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 4) != 0 )
  {
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 24LL));
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 28LL));
    if ( *(_BYTE *)(a1 + 20440) == 1 )
    {
      kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 24LL));
      kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 28LL));
    }
  }
  v6 = gen7_hwsched_boot_gpu(a1);
  if ( v6 )
  {
    v2 = v6;
    if ( *(_BYTE *)(a1 + 20832) == 1 )
    {
      v7 = *(_QWORD *)(a1 + 20824);
      if ( v7 )
      {
        if ( v7 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *(_BYTE *)(a1 + 20848) == 1 )
    {
      v8 = *(_QWORD *)(a1 + 20840);
      if ( v8 )
      {
        if ( v8 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *(_BYTE *)(a1 + 20864) == 1 )
    {
      v9 = *(_QWORD *)(a1 + 20856);
      if ( v9 )
      {
        if ( v9 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    goto LABEL_3;
  }
  v10 = *(_QWORD *)(a1 + 11240);
  if ( v10 )
    *(_BYTE *)(v10 + 245) = 1;
  ++*(_DWORD *)(a1 + 12968);
  _X8 = (unsigned __int64 *)(a1 + 1528);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
  gen7_gmu_oob_clear(a1, 0);
  return 0;
}
