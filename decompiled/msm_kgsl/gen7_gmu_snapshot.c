__int64 __fastcall gen7_gmu_snapshot(_QWORD *a1, __int64 a2)
{
  _QWORD *v4; // x21
  _QWORD *v5; // x23
  _QWORD *v6; // x24
  __int64 v7; // x25
  int v8; // w8
  _QWORD *v9; // x8
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned __int64 v12; // t2
  __int64 result; // x0
  _QWORD *v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  gen7_snapshot_external_core_regs();
  v4 = (_QWORD *)to_gen7_gmu((__int64)a1);
  v5 = *(_QWORD **)(a1[1783] + 208LL);
  kgsl_snapshot_add_section(a1, 5889, a2, gen7_gmu_snapshot_itcm, v4);
  adreno_snapshot_gmu_versions(a1, a2);
  v6 = a1 + 195;
  v7 = 32;
  v15 = 0;
  do
  {
    if ( v6[5] )
    {
      v9 = (_QWORD *)v4[6];
      v14 = v6;
      if ( v6 == v9 )
      {
        v8 = 1;
      }
      else if ( v6 == (_QWORD *)v4[2] )
      {
        v8 = 2;
      }
      else if ( v6 == (_QWORD *)v4[3] || v6 == (_QWORD *)v4[4] )
      {
        v8 = 8;
      }
      else if ( v6 == (_QWORD *)a1[1083] )
      {
        v8 = 9;
      }
      else if ( v6 == (_QWORD *)a1[1084] )
      {
        v8 = 10;
      }
      else
      {
        v8 = 5;
      }
      LODWORD(v15) = v8;
      kgsl_snapshot_add_section(a1, 5889, a2, adreno_snapshot_gmu_mem, &v14);
    }
    --v7;
    v6 += 26;
  }
  while ( v7 );
  kgsl_snapshot_add_section(a1, 514, a2, adreno_snapshot_registers_v2, v5[9]);
  kgsl_snapshot_add_section(a1, 514, a2, gen7_snapshot_rscc_registers, v5[11]);
  if ( !gen7_gmu_gx_is_on((__int64)a1)
    || (kgsl_regmap_write(a1 + 1650, 0),
        __dsb(0xEu),
        kgsl_snapshot_add_section(a1, 514, a2, adreno_snapshot_registers_v2, v5[10]),
        (adreno_smmu_is_stalled((__int64)a1) & 1) == 0)
    || (v10 = *(_DWORD *)a1[1783], v10 - 459264 < 2)
    || v10 == 460288
    || v10 >> 1 == 230528
    || (HIDWORD(v12) = v10 - 461568, LODWORD(v12) = v10 - 461568, v11 = v12 >> 8, v11 <= 6) && ((1 << v11) & 0x59) != 0 )
  {
    kgsl_snapshot_add_section(a1, 5889, a2, gen7_gmu_snapshot_dtcm, v4);
  }
  else
  {
    dev_err(a1[193] + 16LL, "Not dumping dtcm because SMMU is stalled\n");
  }
  gen7_snapshot(a1, a2);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  result = gmu_core_regwrite(a1, 129427, 32774);
  _ReadStatusReg(SP_EL0);
  return result;
}
