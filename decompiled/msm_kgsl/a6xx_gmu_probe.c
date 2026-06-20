__int64 __fastcall a6xx_gmu_probe(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v5; // x9
  _QWORD *resource_byname; // x0
  __int64 v7; // x0
  __int64 result; // x0
  unsigned int v9; // w0
  int *v10; // x8
  int v11; // w21
  unsigned int v12; // w9
  void *v13; // x8
  __int64 v14; // x1
  unsigned int v15; // w0
  unsigned int v16; // w20
  int v17; // w8
  const char *v18; // x0
  unsigned int v19; // w8
  unsigned int v20; // w20
  unsigned __int64 v27; // x9

  v3 = 150000000;
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 192LL);
  *(_QWORD *)(a1 + 1544) = a2;
  if ( v5 )
    v3 = v5;
  *(_QWORD *)(a1 + 23976) = v3;
  *(_QWORD *)(a2 + 656) = a2 + 664;
  if ( !(unsigned int)dma_set_mask(a2 + 16, -1) )
    dma_set_coherent_mask(a2 + 16, -1);
  *(_QWORD *)(*(_QWORD *)(a1 + 1544) + 648LL) = 0;
  resource_byname = (_QWORD *)platform_get_resource_byname(*(_QWORD *)(a1 + 11168), 512, "rscc");
  if ( resource_byname )
  {
    v7 = devm_ioremap(*(_QWORD *)(a1 + 11168) + 16LL, *resource_byname, resource_byname[1] - *resource_byname + 1LL);
    *(_QWORD *)(a1 - 344) = v7;
    if ( !v7 )
    {
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "rscc ioremap failed\n");
      return 4294967284LL;
    }
  }
  gmu_core_rdpm_probe(a1);
  *(_QWORD *)(a1 + 8304) = 0xF0000000F18LL;
  result = kgsl_pwrctrl_probe_gdscs(a1, a2);
  if ( !(_DWORD)result )
  {
    result = ((__int64 (__fastcall *)(__int64))gmu_core_clk_probe)(a1);
    if ( (result & 0x80000000) == 0 )
    {
      v9 = gmu_core_iommu_init(a1);
      if ( v9 )
        goto LABEL_15;
      v10 = *(int **)(a1 + 14264);
      v11 = *v10;
      v12 = *v10 - 620;
      if ( v12 <= 0x28 && ((1LL << v12) & 0x10040000001LL) != 0
        || (v18 = *((const char **)v10 + 3)) != nullptr && !strcmp(v18, "qcom,adreno-gpu-a642l")
        || (unsigned int)(v11 - 621) <= 0x2A && ((1LL << ((unsigned __int8)v11 - 109)) & 0x60000400003LL) != 0 )
      {
        v13 = &a6xx_gmu_vma;
      }
      else
      {
        v13 = &a6xx_gmu_vma_legacy;
      }
      v14 = *(_QWORD *)(a1 + 1544);
      *(_QWORD *)(a1 + 8224) = v13;
      v15 = kgsl_regmap_add_region(a1 + 13200, v14, "kgsl_gmu_reg", 0, 0);
      if ( v15 )
      {
        v20 = v15;
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unable to map the GMU registers\n");
        v9 = v20;
        goto LABEL_15;
      }
      v9 = a6xx_build_rpmh_tables(a1);
      if ( v9 )
      {
LABEL_15:
        v16 = v9;
        a6xx_gmu_remove(a1);
        return v16;
      }
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x40) != 0 )
      {
        *(_QWORD *)(a1 + 24036) = 0xF0000001680LL;
        v17 = 3;
      }
      else
      {
        v17 = 0;
      }
      *(_DWORD *)(a1 - 448) = v17;
      a6xx_gmu_acd_probe(a1, a1 - 1648);
      _X8 = (unsigned __int64 *)(a1 + 1528);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 | 0x10, _X8) );
      *(_QWORD *)(a1 + 1520) = a6xx_gmudev;
      *(_BYTE *)(a1 - 336) = 0;
      *(_DWORD *)(a1 - 332) = 3;
      *(_WORD *)(a1 + 8680) = 0;
      *(_BYTE *)(a1 - 208) = 0;
      *(_QWORD *)(a1 - 204) = 0x400000001LL;
      kobject_init_and_add(a1 - 328, &log_kobj_type, a2 + 16, "log");
      kobject_init_and_add(a1 - 192, &stats_kobj_type, a2 + 16, "stats");
      v19 = kgsl_request_irq(*(_QWORD *)(a1 + 1544), "kgsl_gmu_irq", a6xx_gmu_irq_handler, a1);
      result = 0;
      *(_DWORD *)(a1 - 1648) = v19;
      if ( (v19 & 0x80000000) != 0 )
      {
        v9 = v19;
        goto LABEL_15;
      }
    }
  }
  return result;
}
