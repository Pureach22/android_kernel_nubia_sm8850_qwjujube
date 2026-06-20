__int64 __fastcall a6xx_gmu_device_snapshot(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x21
  _QWORD *v5; // x23
  __int64 v6; // x24
  int v7; // w8
  _QWORD *v8; // x8
  unsigned int v9; // w8
  int v10; // w8
  void *v11; // x2
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x3
  int *v15; // x23
  int v16; // w22
  const char *v17; // x0
  __int64 result; // x0
  const char *v19; // x0
  char v20; // w8
  void *v21; // [xsp+8h] [xbp-18h] BYREF
  __int64 v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (_QWORD *)to_a6xx_gmu(a1);
  kgsl_snapshot_add_section(a1, 5889, a2, a6xx_gmu_snapshot_itcm, v4);
  adreno_snapshot_gmu_versions(a1, a2);
  v5 = (_QWORD *)(a1 + 1560);
  v6 = 32;
  v22 = 0;
  do
  {
    if ( v5[5] )
    {
      v8 = (_QWORD *)v4[5];
      v21 = v5;
      if ( v5 == v8 )
      {
        v7 = 1;
      }
      else if ( v5 == (_QWORD *)v4[3] )
      {
        v7 = 2;
      }
      else if ( v5 == (_QWORD *)v4[2] )
      {
        v7 = 4;
      }
      else if ( v5 == *(_QWORD **)(a1 + 8664) )
      {
        v7 = 9;
      }
      else if ( v5 == *(_QWORD **)(a1 + 8672) )
      {
        v7 = 10;
      }
      else
      {
        v7 = 5;
      }
      LODWORD(v22) = v7;
      kgsl_snapshot_add_section(a1, 5889, a2, adreno_snapshot_gmu_mem, &v21);
    }
    --v6;
    v5 += 26;
  }
  while ( v6 );
  v9 = **(_DWORD **)(a1 + 14264) - 615;
  if ( v9 <= 0xF && ((1 << v9) & 0x801B) != 0 )
    adreno_snapshot_registers(a1, a2, &a6xx_gmu_tcm_registers, 2);
  adreno_snapshot_registers(a1, a2, &a6xx_gmu_registers, 36);
  v10 = **(_DWORD **)(a1 + 14264);
  if ( (unsigned int)(v10 - 621) < 2 )
    goto LABEL_22;
  if ( v10 == 663 )
  {
    v11 = &a663_gmu_gpucc_registers;
    v12 = a1;
    v13 = a2;
    v14 = 25;
  }
  else
  {
    if ( v10 == 662 )
    {
LABEL_22:
      v11 = &a662_gmu_gpucc_registers;
      v12 = a1;
      v13 = a2;
      v14 = 27;
      goto LABEL_25;
    }
    v11 = &a6xx_gmu_gpucc_registers;
    v12 = a1;
    v13 = a2;
    v14 = 19;
  }
LABEL_25:
  adreno_snapshot_registers(v12, v13, v11, v14);
  v15 = *(int **)(a1 + 14264);
  v16 = *v15;
  if ( *v15 == 660
    || (v17 = *((const char **)v15 + 3)) != nullptr && !strcmp(v17, "qcom,adreno-gpu-a642l")
    || v16 == 662
    || v16 == 643 )
  {
    adreno_snapshot_registers(a1, a2, &a660_gmu_registers, 18);
    v15 = *(int **)(a1 + 14264);
    v16 = *v15;
  }
  if ( (unsigned int)(v16 - 620) > 0x28 || ((1LL << ((unsigned __int8)v16 - 108)) & 0x10040000001LL) == 0 )
  {
    v19 = *((const char **)v15 + 3);
    if ( !v19 || strcmp(v19, "qcom,adreno-gpu-a642l") )
    {
      v20 = v16 - 106;
      if ( (unsigned int)(v16 - 618) > 0x3E )
        goto LABEL_45;
      if ( ((1LL << v20) & 0x300002000018LL) == 0 )
      {
        if ( ((1LL << v20) & 0x1003) != 0 )
          goto LABEL_46;
        if ( ((1LL << v20) & 0x4000000000400000LL) != 0 )
        {
          adreno_snapshot_registers(a1, a2, &a6xx_rscc_snapshot_registers, 23);
          goto LABEL_34;
        }
LABEL_45:
        if ( (unsigned int)(v16 - 615) >= 2 )
          goto LABEL_34;
LABEL_46:
        adreno_snapshot_registers(a1, a2, &a630_rscc_snapshot_registers, 22);
        goto LABEL_34;
      }
    }
  }
  v21 = &a650_rscc_registers;
  v22 = 185;
  kgsl_snapshot_add_section(a1, 513, a2, a6xx_snapshot_rscc_registers, &v21);
LABEL_34:
  if ( a6xx_gmu_gx_is_on(a1)
    && (kgsl_regmap_write(a1 + 13200, 0),
        __dsb(0xEu),
        adreno_snapshot_registers(a1, a2, &a6xx_gmu_gx_registers, 18),
        (adreno_smmu_is_stalled(a1) & 1) != 0) )
  {
    result = dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Not dumping dtcm because SMMU is stalled\n");
  }
  else
  {
    result = kgsl_snapshot_add_section(a1, 5889, a2, a6xx_gmu_snapshot_dtcm, v4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
