__int64 __fastcall gen8_snapshot_indexed_registers(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 v14; // x8
  __int64 (__fastcall *v15)(_QWORD); // x8
  char v16; // w8
  int v17; // w8
  _DWORD v19[6]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (adreno_smmu_is_stalled(a1) & 1) != 0 )
    goto LABEL_14;
  v14 = *(_QWORD *)(a1 + 88);
  if ( v14 )
  {
    v15 = *(__int64 (__fastcall **)(_QWORD))(v14 + 16);
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != -55574103 )
        __break(0x8228u);
      if ( (v15(a1 + 56) & 1) != 0 )
        goto LABEL_14;
    }
  }
  if ( *(_BYTE *)(a1 + 11305) != 1
    || !gen8_capturescript
    || (unsigned __int64)gen8_capturescript > 0xFFFFFFFFFFFFF000LL
    || !gen8_crashdump_registers
    || (unsigned __int64)gen8_crashdump_registers > 0xFFFFFFFFFFFFF000LL
    || gen8_crashdump_timedout )
  {
LABEL_14:
    v17 = (a7 & 7) << 16;
    if ( a7 == -1 )
      v17 = 0;
    kgsl_regmap_write(a1 + 13200, v17 & 0xFFFF0FFF | ((a6 & 0xF) << 12) | 0x800000);
    kgsl_snapshot_indexed_registers_v2(a1, a2, a3, a4, 0, a5, a6, a7);
    v16 = 1;
  }
  else
  {
    v19[0] = a3;
    v19[1] = a4;
    v19[2] = 0;
    v19[3] = a5;
    v19[4] = a6;
    v19[5] = a7;
    kgsl_snapshot_add_section(a1, 1282, a2, gen8_snapshot_dump_indexed_regs, v19);
    v16 = gen8_crashdump_timedout ^ 1;
  }
  _ReadStatusReg(SP_EL0);
  return v16 & 1;
}
