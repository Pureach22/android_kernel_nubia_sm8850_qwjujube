__int64 __fastcall a5xx_start(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x8
  int v7; // w8
  int v8; // w20
  int v9; // w9
  int v10; // w8
  int v11; // w9
  int v12; // w0
  int v13; // w20
  int v14; // w9
  int v15; // w8
  int v16; // w20
  __int64 v17; // x8
  unsigned int v18; // w20
  unsigned int v19; // w21
  unsigned int v20; // w22
  __int64 v21; // x1
  unsigned int v22; // w8
  __int64 v23; // x1
  int v24; // w8
  __int64 v25; // x0
  __int64 v26; // x1
  int v27; // w8
  unsigned int v28; // w20
  int v29; // w8
  __int64 v30; // x1
  __int64 i; // x20
  int v32; // w8
  __int64 v34; // x1

  v1 = *(_QWORD *)(a1 + 14264);
  result = kgsl_mmu_start();
  if ( (_DWORD)result )
    return result;
  adreno_get_bus_counters(a1, v4, v5);
  adreno_perfcounter_restore(a1);
  v6 = *(_QWORD *)(a1 + 14264);
  if ( *(_DWORD *)v6 == 530 && (*(_BYTE *)(v6 + 32) & 8) != 0 && !*(_DWORD *)(a1 + 20640) )
    adreno_perfcounter_get(a1, 34, 27, a1 + 20640, 0, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  if ( **(_DWORD **)(a1 + 14264) == 540 )
  {
    v7 = *(_DWORD *)(a1 + 20752);
    v8 = 0;
    *(_DWORD *)(a1 + 20368) = 0;
    if ( !v7 )
      v8 = adreno_perfcounter_get(a1, 34, 43, a1 + 20752, 0, 1);
    v9 = *(_DWORD *)(a1 + 20756);
    v10 = 0;
    *(_DWORD *)(a1 + 20372) = 0;
    if ( !v9 )
      v10 = adreno_perfcounter_get(a1, 34, 44, a1 + 20756, 0, 1);
    v11 = *(_DWORD *)(a1 + 20760);
    v12 = 0;
    v13 = v10 | v8;
    *(_DWORD *)(a1 + 20376) = 0;
    if ( !v11 )
      v12 = adreno_perfcounter_get(a1, 34, 45, a1 + 20760, 0, 1);
    v14 = *(_DWORD *)(a1 + 20764);
    v15 = 0;
    v16 = v13 | v12;
    *(_DWORD *)(a1 + 20380) = 0;
    if ( !v14 )
      v15 = adreno_perfcounter_get(a1, 34, 46, a1 + 20764, 0, 1);
    if ( v16 | v15 && (setup_throttling_counters___already_done & 1) == 0 )
    {
      setup_throttling_counters___already_done = 1;
      _warn_printk("Unable to get one or more clock throttling registers\n");
      __break(0x800u);
    }
  }
  kgsl_regmap_multi_write(a1 + 13200, *(_QWORD *)(v1 + 152), *(unsigned int *)(v1 + 160));
  kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
  kgsl_regmap_write(a1 + 13200, 6);
  kgsl_regmap_write(a1 + 13200, 1);
  if ( (*(_BYTE *)(a1 + 20656) & 4) != 0 )
  {
    kgsl_regmap_write(a1 + 13200, 4026531840LL);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
  }
  kgsl_regmap_write(a1 + 13200, 1074003967);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 2);
  kgsl_regmap_write(a1 + 13200, 4294901760LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  kgsl_regmap_write(a1 + 13200, 4294901760LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14256));
  kgsl_regmap_write(a1 + 13200, 0);
  kgsl_regmap_write(
    a1 + 13200,
    (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 64LL) + *(_DWORD *)(a1 + 14256) - 1));
  kgsl_regmap_write(a1 + 13200, 0);
  v17 = (unsigned int)(**(_DWORD **)(a1 + 14264) - 505);
  if ( (unsigned int)v17 > 0x23 )
    goto LABEL_27;
  v18 = 1073741872;
  v19 = 537922826;
  if ( ((1LL << (**(_BYTE **)(a1 + 14264) + 7)) & 0xB) != 0 )
  {
    v20 = 1024;
    v21 = 32;
    goto LABEL_28;
  }
  if ( ((1LL << (**(_BYTE **)(a1 + 14264) + 7)) & 0x800000080LL) != 0 )
  {
    v20 = 1024;
    v18 = -2147483552;
    v21 = 64;
    v19 = 1075845910;
    goto LABEL_28;
  }
  if ( v17 == 5 )
  {
    v21 = 32;
    v20 = 32;
  }
  else
  {
LABEL_27:
    v21 = 64;
    v18 = -2147483552;
    v19 = 1075845910;
    v20 = 64;
  }
LABEL_28:
  kgsl_regmap_write(a1 + 13200, v21);
  kgsl_regmap_write(a1 + 13200, v20);
  kgsl_regmap_write(a1 + 13200, v18);
  kgsl_regmap_write(a1 + 13200, v19);
  v22 = **(_DWORD **)(a1 + 14264) - 505;
  if ( v22 > 7 )
    v23 = 3223322624LL;
  else
    v23 = *((unsigned int *)&unk_17DE54 + v22);
  kgsl_regmap_write(a1 + 13200, v23);
  v24 = *(_DWORD *)(a1 + 20656);
  if ( (v24 & 1) != 0 && *(_DWORD *)(a1 + 14288) >= 0x5FF077u )
  {
    kgsl_regmap_rmw(a1 + 13200, 3328, 0, 256);
    v24 = *(_DWORD *)(a1 + 20656);
  }
  if ( (v24 & 8) != 0 )
    kgsl_regmap_rmw(a1 + 13200, 3268, 0, 512);
  kgsl_regmap_write(a1 + 13200, 0x20000000);
  kgsl_regmap_write(a1 + 13200, 0x2000000);
  if ( (*(_QWORD *)(a1 + 14240) & 0x1000) != 0 )
  {
    if ( (unsigned int)adreno_active_count_get(a1) )
    {
      dev_err(*(_QWORD *)a1, "Active count failed while turning on ISDB\n");
      goto LABEL_41;
    }
    kgsl_regmap_write(a1 + 13200, 117440511);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    v25 = a1 + 13200;
    v26 = 0;
  }
  else
  {
    v25 = a1 + 13200;
    v26 = 2801795071LL;
  }
  kgsl_regmap_write(v25, v26);
LABEL_41:
  kgsl_regmap_write(a1 + 13200, 63);
  v27 = *(_DWORD *)(a1 + 20652);
  if ( v27 )
    v28 = ((_BYTE)v27 - 1) & 3;
  else
    v28 = 0;
  kgsl_regmap_write(a1 + 13200, v28 << 7);
  kgsl_regmap_write(a1 + 13200, 2 * v28);
  v29 = **(_DWORD **)(a1 + 14264);
  if ( v29 == 540 || v29 == 512 )
    kgsl_regmap_write(a1 + 13200, v28);
  kgsl_regmap_rmw(a1 + 13200, 3680, 0, 1024);
  if ( (*(_BYTE *)(a1 + 20656) & 0x10) != 0 )
  {
    kgsl_regmap_rmw(a1 + 13200, 3680, 0, 0x800000);
    kgsl_regmap_rmw(a1 + 13200, 3588, 0x40000, 0);
  }
  if ( *(_BYTE *)(a1 + 96) == 1 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 4026531840LL);
    kgsl_regmap_write(a1 + 13200, 0);
    if ( (*(_QWORD *)(a1 + 104) & 1LL) != 0 )
      v30 = 4294963200LL;
    else
      v30 = 0x10000000;
    kgsl_regmap_write(a1 + 13200, v30);
  }
  a5xx_preemption_start(a1);
  kgsl_regmap_write(a1 + 13200, 7);
  for ( i = 0; i != 204; i += 12 )
    kgsl_regmap_write(
      a1 + 13200,
      (4 * *(_DWORD *)((char *)&a5xx_protected_blocks + i + 4))
    | (*(_DWORD *)((char *)&a5xx_protected_blocks + i + 8) << 24)
    | 0x60000000u);
  v32 = **(_DWORD **)(a1 + 14264);
  if ( v32 == 540 || v32 == 530 )
    v34 = 1896873984;
  else
    v34 = 1880096768;
  kgsl_regmap_write(a1 + 13200, v34);
  return 0;
}
