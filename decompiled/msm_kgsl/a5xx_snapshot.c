__int64 __fastcall a5xx_snapshot(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  unsigned int v5; // w21
  int v6; // w8
  __int64 i; // x21
  __int64 (__fastcall *v8)(); // x3
  __int64 result; // x0
  void *v10; // [xsp+8h] [xbp-18h] BYREF
  __int64 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  a5xx_hwcg_set(a1, 0);
  v4 = kgsl_regmap_read(a1 + 13200);
  *(_QWORD *)a2 = v4 | (unsigned __int64)(kgsl_regmap_read(a1 + 13200) << 32);
  v5 = kgsl_regmap_read(a1 + 13200);
  *(_QWORD *)(a2 + 8) = v5 | (unsigned __int64)(kgsl_regmap_read(a1 + 13200) << 32);
  *(_DWORD *)(a2 + 24) = kgsl_regmap_read(a1 + 13200);
  *(_DWORD *)(a2 + 28) = kgsl_regmap_read(a1 + 13200);
  kgsl_snapshot_add_section(a1, 513, a2, a5xx_snapshot_pre_crashdump_regs, 0);
  adreno_snapshot_registers(a1, a2, &a5xx_vbif_registers, 35);
  v10 = &a5xx_registers;
  v11 = 214;
  kgsl_snapshot_add_section(a1, 513, a2, a5xx_snapshot_registers, &v10);
  v6 = **(_DWORD **)(a1 + 14264);
  if ( v6 == 540 || v6 == 530 )
  {
    v10 = &a5xx_gpmu_registers;
    v11 = 4;
    kgsl_snapshot_add_section(a1, 513, a2, a5xx_snapshot_registers, &v10);
  }
  kgsl_snapshot_add_section(a1, 513, a2, a5xx_snapshot_dump_hlsq_sp_tp_regs, 0);
  kgsl_snapshot_indexed_registers(a1, a2, 2056, 2057, 0, 36);
  kgsl_snapshot_indexed_registers(a1, a2, 2074, 2836, 0, 29);
  kgsl_snapshot_indexed_registers(a1, a2, 2059, 2060, 0, 256);
  kgsl_snapshot_indexed_registers(a1, a2, 2095, 2096, 0, 1343);
  kgsl_snapshot_indexed_registers(a1, a2, 2090, 2091, 0, 1343);
  kgsl_snapshot_add_section(a1, 2305, a2, a5xx_snapshot_cp_meq, 0);
  kgsl_snapshot_add_section(a1, 2305, a2, a5xx_snapshot_cp_roq, 0);
  kgsl_snapshot_add_section(a1, 2305, a2, a5xx_snapshot_cp_merciu, 0);
  kgsl_snapshot_add_section(a1, 2305, a2, a5xx_snapshot_cp_pfp, 0);
  kgsl_snapshot_add_section(a1, 2305, a2, a5xx_snapshot_cp_pm4, 0);
  kgsl_regmap_write(a1 + 13200, 251658240);
  for ( i = 0; i != 400; i += 8 )
  {
    if ( *(_DWORD *)((char *)&a5xx_debugbus_blocks + i) == 3 )
      v8 = a5xx_snapshot_vbif_debugbus;
    else
      v8 = a5xx_snapshot_debugbus_block;
    kgsl_snapshot_add_section(a1, 2561, a2, v8, (char *)&a5xx_debugbus_blocks + i);
  }
  result = adreno_snapshot_preemption_record(a1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
