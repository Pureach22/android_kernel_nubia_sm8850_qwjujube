__int64 __fastcall gen8_gmu_probe(__int64 a1, __int64 a2)
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
  __int64 v14; // x9
  int v15; // w8
  __int64 v16; // x9
  int v17; // w9
  __int64 v18; // x0
  unsigned int v19; // w8
  unsigned int v20; // w20
  unsigned __int64 v27; // x9

  v3 = 150000000;
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 200LL);
  *(_QWORD *)(a1 + 1544) = a2;
  *(_QWORD *)(a1 + 8232) = 0;
  *(_QWORD *)(a1 + 8240) = 0;
  if ( v5 )
    v3 = v5;
  *(_QWORD *)(a1 + 8248) = 0;
  *(_QWORD *)(a1 + 23976) = v3;
  *(_QWORD *)(a1 + 8256) = 0;
  *(_QWORD *)(a1 + 8264) = 0;
  *(_QWORD *)(a1 + 8272) = 0;
  *(_DWORD *)(a1 + 8280) = 0;
  *(_QWORD *)(a2 + 656) = a2 + 664;
  if ( !(unsigned int)dma_set_mask(a2 + 16, -1) )
    dma_set_coherent_mask(a2 + 16, -1);
  *(_QWORD *)(*(_QWORD *)(a1 + 1544) + 648LL) = 0;
  resource_byname = (_QWORD *)platform_get_resource_byname(*(_QWORD *)(a1 + 11168), 512, "rscc");
  if ( resource_byname
    && (v7 = devm_ioremap(*(_QWORD *)(a1 + 11168) + 16LL, *resource_byname, resource_byname[1] - *resource_byname + 1LL),
        (*(_QWORD *)(a1 - 776) = v7) == 0) )
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
        *(_QWORD *)(a1 + 8224) = &gen8_gmu_vma;
        qword_18A28 = 0;
        dword_18A24 = 0;
        qword_18A40 = 0;
        dword_18A3C = 0;
        qword_18A58 = 0;
        dword_18A54 = 0;
        qword_18A70 = 0;
        dword_18A6C = 0;
        qword_18A88 = 0;
        dword_18A84 = 0;
        qword_18AA0 = 0;
        dword_18A9C = 0;
        v11 = kgsl_regmap_add_region(a1 + 13200, v10, "gmu", 0, 0);
        v12 = *(_QWORD *)(a1 + 1544);
        if ( v11 )
        {
          v20 = v11;
          dev_err(v12 + 16, "Unable to map the GMU registers\n");
          kgsl_regmap_add_region(a1 + 13200, *(_QWORD *)(a1 + 1544), "gmu_ao_blk_dec0", 0, 0);
          v9 = v20;
          goto LABEL_12;
        }
        kgsl_regmap_add_region(a1 + 13200, v12, "gmu_ao_blk_dec0", 0, 0);
        v9 = gen8_build_rpmh_tables(a1);
        if ( v9 )
        {
LABEL_12:
          v13 = v9;
          gen8_gmu_remove(a1);
          return v13;
        }
        v14 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 32LL);
        if ( (v14 & 0x40) != 0 )
        {
          if ( (v14 & 0x2000000) != 0 )
          {
            *(_BYTE *)(a1 + 20442) = 1;
            v17 = 6;
            *(_DWORD *)(a1 + 23996) = 73216;
          }
          else
          {
            v17 = 3;
          }
          *(_DWORD *)(a1 - 816) = v17;
          v16 = 24040;
          *(_DWORD *)(a1 + 24036) = 5760;
          v15 = 3840;
        }
        else
        {
          v15 = 0;
          v16 = -816;
        }
        *(_DWORD *)(a1 + v16) = v15;
        gen8_gmu_acd_probe(a1, a1 - 1824);
        _X8 = (unsigned __int64 *)(a1 + 1528);
        __asm { PRFM            #0x11, [X8] }
        do
          v27 = __ldxr(_X8);
        while ( __stxr(v27 | 0x10, _X8) );
        *(_QWORD *)(a1 + 1520) = gen8_gmudev;
        *(_BYTE *)(a1 - 768) = 0;
        *(_DWORD *)(a1 - 764) = 3;
        *(_BYTE *)(a1 - 656) = 0;
        *(_DWORD *)(a1 + 1536) = 0;
        *(_WORD *)(a1 + 8680) = 0;
        *(_QWORD *)(a1 - 652) = 0x400000001LL;
        kobject_init_and_add(a1 - 760, &log_kobj_type_1, a2 + 16, "log");
        kobject_init_and_add(a1 - 640, &stats_kobj_type_1, a2 + 16, "stats");
        v18 = *(_QWORD *)(a1 + 1544);
        *(_DWORD *)(a1 - 852) = 0;
        v19 = kgsl_request_irq(v18, "gmu", gen8_gmu_irq_handler, a1);
        result = 0;
        *(_DWORD *)(a1 - 1824) = v19;
        if ( (v19 & 0x80000000) != 0 )
        {
          v9 = v19;
          goto LABEL_12;
        }
      }
    }
  }
  return result;
}
