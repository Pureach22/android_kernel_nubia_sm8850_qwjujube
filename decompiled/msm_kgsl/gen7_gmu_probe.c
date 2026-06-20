__int64 __fastcall gen7_gmu_probe(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v5; // x9
  _QWORD *resource_byname; // x0
  __int64 v7; // x0
  __int64 result; // x0
  unsigned int v9; // w0
  __int64 v10; // x1
  unsigned int v11; // w0
  __int64 v12; // x1
  unsigned int v13; // w20
  int v14; // w8
  __int64 v15; // x0
  unsigned int v16; // w8
  unsigned int v17; // w20
  unsigned __int64 v24; // x9

  v3 = 150000000;
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 216LL);
  *(_QWORD *)(a1 + 1544) = a2;
  if ( v5 )
    v3 = v5;
  *(_QWORD *)(a1 + 23976) = v3;
  *(_QWORD *)(a2 + 656) = a2 + 664;
  if ( !(unsigned int)dma_set_mask(a2 + 16, -1) )
    dma_set_coherent_mask(a2 + 16, -1);
  *(_QWORD *)(*(_QWORD *)(a1 + 1544) + 648LL) = 0;
  resource_byname = (_QWORD *)platform_get_resource_byname(*(_QWORD *)(a1 + 11168), 512, "rscc");
  if ( resource_byname
    && (v7 = devm_ioremap(*(_QWORD *)(a1 + 11168) + 16LL, *resource_byname, resource_byname[1] - *resource_byname + 1LL),
        (*(_QWORD *)(a1 - 672) = v7) == 0) )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "rscc ioremap failed\n");
    return 4294967284LL;
  }
  else
  {
    gmu_core_rdpm_probe(a1);
    *(_QWORD *)(a1 + 8304) = 0xF0000000F14LL;
    result = kgsl_pwrctrl_probe_gdscs(a1, a2);
    if ( !(_DWORD)result )
    {
      result = ((__int64 (__fastcall *)(__int64))gmu_core_clk_probe)(a1);
      if ( !(_DWORD)result )
      {
        v9 = gmu_core_iommu_init(a1);
        if ( v9 )
          goto LABEL_12;
        v10 = *(_QWORD *)(a1 + 1544);
        *(_QWORD *)(a1 + 8224) = &gen7_gmu_vma;
        qword_C4A8 = 0;
        dword_C4A4 = 0;
        qword_C4C0 = 0;
        dword_C4BC = 0;
        qword_C4D8 = 0;
        dword_C4D4 = 0;
        qword_C4F0 = 0;
        dword_C4EC = 0;
        qword_C508 = 0;
        dword_C504 = 0;
        qword_C520 = 0;
        dword_C51C = 0;
        v11 = kgsl_regmap_add_region(a1 + 13200, v10, "gmu", 0, 0);
        v12 = *(_QWORD *)(a1 + 1544);
        if ( v11 )
        {
          v17 = v11;
          dev_err(v12 + 16, "Unable to map the GMU registers\n");
          kgsl_regmap_add_region(a1 + 13200, *(_QWORD *)(a1 + 1544), "gmu_ao_blk_dec0", 0, 0);
          v9 = v17;
          goto LABEL_12;
        }
        kgsl_regmap_add_region(a1 + 13200, v12, "gmu_ao_blk_dec0", 0, 0);
        v9 = gen7_build_rpmh_tables(a1);
        if ( v9 )
        {
LABEL_12:
          v13 = v9;
          gen7_gmu_remove(a1);
          return v13;
        }
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x40) != 0 )
        {
          *(_QWORD *)(a1 + 24036) = 0xF0000001680LL;
          v14 = 3;
        }
        else
        {
          v14 = 0;
        }
        *(_DWORD *)(a1 - 768) = v14;
        gen7_gmu_acd_probe(a1, a1 - 1776);
        _X8 = (unsigned __int64 *)(a1 + 1528);
        __asm { PRFM            #0x11, [X8] }
        do
          v24 = __ldxr(_X8);
        while ( __stxr(v24 | 0x10, _X8) );
        *(_QWORD *)(a1 + 1520) = gen7_gmudev;
        *(_BYTE *)(a1 - 664) = 0;
        *(_DWORD *)(a1 - 660) = 3;
        *(_BYTE *)(a1 - 544) = 0;
        *(_WORD *)(a1 + 8680) = 0;
        *(_QWORD *)(a1 - 540) = 0x400000001LL;
        kobject_init_and_add(a1 - 656, &log_kobj_type_0, a2 + 16, "log");
        kobject_init_and_add(a1 - 528, &stats_kobj_type_0, a2 + 16, "stats");
        v15 = *(_QWORD *)(a1 + 1544);
        *(_DWORD *)(a1 - 804) = 0;
        v16 = kgsl_request_irq(v15, "gmu", gen7_gmu_irq_handler, a1);
        result = 0;
        *(_DWORD *)(a1 - 1776) = v16;
        if ( (v16 & 0x80000000) != 0 )
        {
          v9 = v16;
          goto LABEL_12;
        }
      }
    }
  }
  return result;
}
