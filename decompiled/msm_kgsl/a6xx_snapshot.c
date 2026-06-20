__int64 __fastcall a6xx_snapshot(_QWORD *a1, __int64 a2)
{
  __int64 i; // x22
  int *v5; // x8
  int v6; // w22
  unsigned int v7; // w9
  __int64 (__fastcall *v8)(); // x3
  void *v9; // x2
  _QWORD *v10; // x0
  __int64 v11; // x1
  __int64 v12; // x3
  bool v13; // w21
  __int64 result; // x0
  unsigned int v15; // w22
  unsigned int v16; // w22
  int *v17; // x8
  int v18; // w22
  const char *v19; // x0
  int v20; // w8
  __int64 v21; // x9
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x27
  const char *v25; // x0
  int v26; // w22
  int *v27; // x24
  int v28; // w22
  const char *v29; // x0
  const char *v30; // x0
  const char *v31; // x0
  const char *v32; // x0
  int *v33; // x8
  int v34; // w22
  const char *v35; // x0
  unsigned int v36; // w0
  int *v37; // x8
  int v38; // w22
  unsigned int v39; // w9
  unsigned int v40; // w22
  __int64 v41; // x24
  int *v42; // x8
  int v43; // w28
  const char *v44; // x0
  __int64 j; // x22
  __int64 v46; // x22
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 v49; // x9
  __int64 v50; // x8
  int *v51; // x8
  int v52; // w21
  const char *v53; // x0
  const char *v54; // x0
  unsigned __int64 v55; // x24
  unsigned int v56; // w22
  char *v57; // [xsp+0h] [xbp-20h] BYREF
  __int64 v58; // [xsp+8h] [xbp-18h]
  __int64 v59; // [xsp+10h] [xbp-10h]
  __int64 v60; // [xsp+18h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*((_DWORD *)a1 + 3295) )
  {
    kgsl_regmap_write(a1 + 1650, 4026531840LL);
    kgsl_regmap_write(a1 + 1650, 251658240);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 1985229328);
    kgsl_regmap_write(a1 + 1650, 4275878552LL);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 4026531840LL);
    kgsl_regmap_write(a1 + 1650, 251658240);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 1985229328);
    kgsl_regmap_write(a1 + 1650, 4275878552LL);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 0);
    for ( i = 0; i != 312; i += 8 )
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, (char *)&a6xx_dbgc_debugbus_blocks + i);
    v5 = (int *)a1[1783];
    v6 = *v5;
    v7 = *v5 - 620;
    if ( v7 <= 0x28 && ((1LL << v7) & 0x10040000001LL) != 0
      || (v25 = *((const char **)v5 + 3)) != nullptr && !strcmp(v25, "qcom,adreno-gpu-a642l")
      || (unsigned int)(v6 - 621) <= 0x2A && ((1LL << ((unsigned __int8)v6 - 109)) & 0x60000400003LL) != 0 )
    {
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &a650_dbgc_debugbus_blocks);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_156878);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_156880);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_156888);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_156890);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_156898);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_1568A0);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_1568A8);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_1568B0);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_1568B8);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_1568C0);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_1568C8);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_dbgc_debugbus_block, &unk_1568D0);
      v6 = *(_DWORD *)a1[1783];
    }
    if ( v6 == 630 )
      v8 = a6xx_snapshot_vbif_debugbus_block;
    else
      v8 = a6xx_snapshot_dbgc_debugbus_block;
    kgsl_snapshot_add_section(a1, 2561, a2, v8, &a6xx_vbif_debugbus_blocks);
    if ( (kgsl_regmap_valid_offset(a1 + 1650, 99328) & 1) != 0 )
    {
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_cx_dbgc_debugbus_block, &a6xx_cx_dbgc_debugbus_blocks);
      kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_cx_dbgc_debugbus_block, &unk_1568E8);
      if ( *(_DWORD *)a1[1783] != 630 )
        kgsl_snapshot_add_section(a1, 2561, a2, a6xx_snapshot_cx_dbgc_debugbus_block, &a6xx_vbif_debugbus_blocks);
    }
  }
  if ( *((_BYTE *)a1 + 20439) == 1 )
  {
    v57 = (char *)&a650_isense_registers;
    v58 = 31;
    kgsl_snapshot_add_section(a1, 513, a2, kgsl_snapshot_dump_registers, &v57);
  }
  if ( (gmu_core_isenabled(a1) & 1) == 0 )
  {
    if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1[1396] + 760LL)) )
    {
      v9 = &a6xx_holi_gmu_wrapper_registers;
      v10 = a1;
      v11 = a2;
      v12 = 7;
    }
    else
    {
      v9 = &a6xx_gmu_wrapper_registers;
      v10 = a1;
      v11 = a2;
      v12 = 6;
    }
    adreno_snapshot_registers(v10, v11, v9, v12);
  }
  v13 = a6xx_gmu_sptprac_is_on((__int64)a1);
  result = adreno_gx_is_on((__int64)a1);
  if ( (result & 1) != 0 )
  {
    v15 = kgsl_regmap_read(a1 + 1650);
    *(_QWORD *)a2 = v15 | (unsigned __int64)(kgsl_regmap_read(a1 + 1650) << 32);
    v16 = kgsl_regmap_read(a1 + 1650);
    *(_QWORD *)(a2 + 8) = v16 | (unsigned __int64)(kgsl_regmap_read(a1 + 1650) << 32);
    *(_DWORD *)(a2 + 24) = kgsl_regmap_read(a1 + 1650);
    *(_DWORD *)(a2 + 28) = kgsl_regmap_read(a1 + 1650);
    v17 = (int *)a1[1783];
    v18 = *v17;
    if ( *v17 == 660
      || (v19 = *((const char **)v17 + 3)) != nullptr && !strcmp(v19, "qcom,adreno-gpu-a642l")
      || v18 == 662
      || v18 == 643 )
    {
      kgsl_regmap_write(a1 + 1650, 1);
    }
    kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_pre_crashdump_regs, 0);
    v20 = *(_DWORD *)a1[1783];
    v21 = (unsigned int)(v20 - 618);
    if ( (unsigned int)v21 <= 0x3E )
    {
      if ( ((1LL << ((unsigned __int8)v20 - 106)) & 0x4000000000400003LL) != 0 )
      {
LABEL_33:
        adreno_snapshot_registers(a1, a2, &a6xx_gbif_registers, 4);
        if ( !v13 )
          goto LABEL_59;
LABEL_34:
        crash_dump_valid = 0;
        if ( *((_BYTE *)a1 + 11305) == 1
          && a6xx_capturescript
          && (unsigned __int64)a6xx_capturescript <= 0xFFFFFFFFFFFFF000LL
          && a6xx_crashdump_registers
          && (unsigned __int64)a6xx_crashdump_registers <= 0xFFFFFFFFFFFFF000LL
          && (adreno_smmu_is_stalled((__int64)a1) & 1) == 0 )
        {
          if ( (*(_BYTE *)(a1[1783] + 33LL) & 8) == 0 )
            kgsl_regmap_write(a1 + 1650, 1);
          kgsl_regmap_write(a1 + 1650, *(unsigned int *)(a6xx_capturescript + 24));
          kgsl_regmap_write(a1 + 1650, *(unsigned int *)(a6xx_capturescript + 28));
          v22 = kgsl_regmap_write(a1 + 1650, 1);
          v23 = ktime_get(v22);
          __dsb(0xDu);
          if ( *(_DWORD *)a6xx_cd_reg_end == -1431655766 )
          {
            v24 = v23 + 500000000;
            do
            {
              v23 = ktime_get(v23);
              if ( v23 > v24 )
                break;
              if ( (a1[1413] & 1) == 0 )
                v23 = usleep_range_state(100, 1000, 2);
              __dsb(0xDu);
            }
            while ( *(_DWORD *)a6xx_cd_reg_end == -1431655766 );
          }
          v26 = kgsl_regmap_read(a1 + 1650);
          if ( (*(_BYTE *)(a1[1783] + 33LL) & 8) == 0 )
            kgsl_regmap_write(a1 + 1650, 0);
          if ( (v26 & 2) != 0 )
            crash_dump_valid = 1;
          else
            dev_err(*a1, "Crash dump timed out: 0x%X\n", v26);
        }
LABEL_59:
        v27 = (int *)a1[1783];
        v28 = *v27;
        if ( (*v27 == 660
           || (v29 = *((const char **)v27 + 3)) != nullptr && !strcmp(v29, "qcom,adreno-gpu-a642l")
           || v28 == 643
           || v28 == 662
           || a6xx_reg_list != &a660_registers)
          && (kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_registers, &a6xx_reg_list),
              v27 = (int *)a1[1783],
              v28 = *v27,
              *v27 == 660)
          || (v30 = *((const char **)v27 + 3)) != nullptr && !strcmp(v30, "qcom,adreno-gpu-a642l")
          || v28 == 643
          || v28 == 662
          || off_B8A0 != &a660_registers )
        {
          kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_registers, &off_B8A0);
          v27 = (int *)a1[1783];
          v28 = *v27;
          if ( *v27 == 660 )
            goto LABEL_129;
        }
        if ( (v31 = *((const char **)v27 + 3)) != nullptr && !strcmp(v31, "qcom,adreno-gpu-a642l")
          || v28 == 643
          || v28 == 662
          || off_B8C0 != &a660_registers )
        {
LABEL_129:
          kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_registers, &off_B8C0);
          v27 = (int *)a1[1783];
          v28 = *v27;
          if ( *v27 == 660 )
            goto LABEL_83;
        }
        if ( (v32 = *((const char **)v27 + 3)) != nullptr && !strcmp(v32, "qcom,adreno-gpu-a642l")
          || v28 == 643
          || v28 == 662
          || off_B8E0 != &a660_registers )
        {
LABEL_83:
          kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_registers, &off_B8E0);
        }
        kgsl_snapshot_indexed_registers(a1, a2, 2312, 2313, 0, 51);
        kgsl_snapshot_indexed_registers(a1, a2, 2314, 2315, 0, 256);
        kgsl_snapshot_indexed_registers(a1, a2, 2320, 2321, 0, 0x8000);
        v33 = (int *)a1[1783];
        v34 = *v33;
        if ( *v33 == 660
          || (v35 = *((const char **)v33 + 3)) != nullptr && !strcmp(v35, "qcom,adreno-gpu-a642l")
          || v34 == 662
          || v34 == 643 )
        {
          kgsl_snapshot_indexed_registers(a1, a2, 2857, 2858, 0, 51);
          kgsl_snapshot_indexed_registers(a1, a2, 2826, 2827, 0, 256);
          kgsl_snapshot_indexed_registers(a1, a2, 2855, 2856, 0, 0x8000);
          v36 = kgsl_regmap_read(a1 + 1650);
          kgsl_snapshot_indexed_registers(a1, a2, 2828, 2869, 0, v36 >> 14);
          kgsl_snapshot_indexed_registers(a1, a2, 2880, 2870, 0, 64);
        }
        kgsl_snapshot_add_section(a1, 2305, a2, a6xx_snapshot_cp_roq, 0);
        v37 = (int *)a1[1783];
        v38 = *v37;
        v39 = *v37 - 620;
        if ( v39 <= 0x28 && ((1LL << v39) & 0x10040000001LL) != 0
          || (v54 = *((const char **)v37 + 3)) != nullptr && !strcmp(v54, "qcom,adreno-gpu-a642l")
          || (unsigned int)(v38 - 621) <= 0x2A && ((1LL << ((unsigned __int8)v38 - 109)) & 0x60000400003LL) != 0 )
        {
          v40 = kgsl_regmap_read(a1 + 1650);
          kgsl_regmap_write(a1 + 1650, v40 | 4);
          kgsl_snapshot_indexed_registers(a1, a2, 2318, 2319, 0, 8448);
          kgsl_regmap_write(a1 + 1650, v40);
          if ( !v13 )
          {
LABEL_108:
            v51 = (int *)a1[1783];
            v52 = *v51;
            if ( *v51 == 660
              || (v53 = *((const char **)v51 + 3)) != nullptr && !strcmp(v53, "qcom,adreno-gpu-a642l")
              || v52 == 662
              || v52 == 643 )
            {
              if ( !(unsigned int)kgsl_regmap_read(a1 + 1650) )
                dev_err(*a1, "Interface signals may have changed during snapshot\n");
              kgsl_regmap_write(a1 + 1650, 0);
            }
            result = adreno_snapshot_preemption_record(a1, a2);
            goto LABEL_117;
          }
        }
        else
        {
          v55 = *(_QWORD *)(a2 + 88);
          v56 = kgsl_regmap_read(a1 + 1650);
          kgsl_regmap_write(a1 + 1650, 0);
          kgsl_snapshot_indexed_registers(a1, a2, 2318, 2319, 0, 8448);
          if ( v55 < *(_QWORD *)(a2 + 88) )
            *(_DWORD *)(v55 + 32792) = v56;
          kgsl_regmap_write(a1 + 1650, v56);
          if ( !v13 )
            goto LABEL_108;
        }
        v41 = 0;
        v57 = nullptr;
        v58 = 0;
        do
        {
          v42 = (int *)a1[1783];
          v43 = *v42;
          if ( *v42 == 660
            || (v44 = *((const char **)v42 + 3)) != nullptr && !strcmp(v44, "qcom,adreno-gpu-a642l")
            || v43 == 643
            || v43 == 662
            || *(_UNKNOWN **)((char *)&a6xx_clusters + v41 + 8) != &a660_fe_cluster )
          {
            v57 = (char *)&a6xx_clusters + v41;
            LODWORD(v58) = 0;
            kgsl_snapshot_add_section(a1, 5377, a2, a6xx_snapshot_mvc, &v57);
            LODWORD(v58) = 1;
            kgsl_snapshot_add_section(a1, 5377, a2, a6xx_snapshot_mvc, &v57);
          }
          v41 += 40;
        }
        while ( v41 != 280 );
        for ( j = 0; j != 520; j += 40 )
        {
          v57 = (char *)&a6xx_dbgahb_ctx_clusters + j;
          v58 = 0;
          kgsl_snapshot_add_section(a1, 5377, a2, a6xx_snapshot_cluster_dbgahb, &v57);
          LODWORD(v58) = 1;
          kgsl_snapshot_add_section(a1, 5377, a2, a6xx_snapshot_cluster_dbgahb, &v57);
        }
        kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_non_ctx_dbgahb, &a6xx_non_ctx_dbgahb);
        kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_non_ctx_dbgahb, &dword_B7F0);
        kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_non_ctx_dbgahb, &dword_B808);
        v46 = 0;
        v58 = 0;
        do
        {
          v47 = *(_QWORD *)((char *)&a6xx_shader_blocks + v46 + 8);
          v57 = (char *)&a6xx_shader_blocks + v46;
          LODWORD(v58) = 0;
          v59 = v47;
          kgsl_snapshot_add_section(a1, 4609, a2, a6xx_snapshot_shader_memory, &v57);
          v48 = *(_QWORD *)((char *)&a6xx_shader_blocks + v46 + 8)
              + *(unsigned int *)((char *)&a6xx_shader_blocks + v46 + 4);
          v57 = (char *)&a6xx_shader_blocks + v46;
          LODWORD(v58) = 1;
          v59 = v48;
          kgsl_snapshot_add_section(a1, 4609, a2, a6xx_snapshot_shader_memory, &v57);
          v49 = *(_QWORD *)((char *)&a6xx_shader_blocks + v46 + 8);
          v50 = (unsigned int)(2 * *(_DWORD *)((char *)&a6xx_shader_blocks + v46 + 4));
          v57 = (char *)&a6xx_shader_blocks + v46;
          LODWORD(v58) = 2;
          v59 = v49 + v50;
          kgsl_snapshot_add_section(a1, 4609, a2, a6xx_snapshot_shader_memory, &v57);
          v46 += 16;
        }
        while ( v46 != 720 );
        if ( (adreno_smmu_is_stalled((__int64)a1) & 1) == 0 )
          memset(*(void **)(a6xx_crashdump_registers + 8), 170, *(_QWORD *)(a6xx_crashdump_registers + 40));
        goto LABEL_108;
      }
      if ( v21 == 12 )
      {
        adreno_snapshot_registers(a1, a2, &a6xx_vbif_registers, 42);
        if ( !v13 )
          goto LABEL_59;
        goto LABEL_34;
      }
    }
    if ( (unsigned int)(v20 - 615) >= 2 )
    {
      adreno_snapshot_registers(a1, a2, &a6xx_gbif_reinit_registers, 6);
      if ( !v13 )
        goto LABEL_59;
      goto LABEL_34;
    }
    goto LABEL_33;
  }
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return result;
}
