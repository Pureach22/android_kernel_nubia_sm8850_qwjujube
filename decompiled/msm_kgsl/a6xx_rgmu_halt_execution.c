__int64 __fastcall a6xx_rgmu_halt_execution(__int64 a1, __int64 a2, char a3)
{
  __int64 (*v5)(void); // x8
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x3
  int v9; // [xsp+Ch] [xbp-14h] BYREF
  int v10; // [xsp+10h] [xbp-10h] BYREF
  int v11; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
  if ( *((_DWORD *)v5 - 1) != -944375624 )
    __break(0x8228u);
  result = v5();
  if ( *(_BYTE *)(a1 + 13192) == 1 )
  {
    v7 = result;
    v11 = 0;
    v9 = 0;
    v10 = 0;
    gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
    __dsb(0xEu);
    gmu_core_regread(a1, 129085, &v11);
    gmu_core_regread(a1, 129084, &v10);
    gmu_core_regread(a1, 146192, &v9);
    dev_err(*(_QWORD *)(a1 - 88) + 16LL, "RGMU Fault PCC_DEBUG:0x%x PCC_STATUS:0x%x FENCE_CTRL:0x%x\n", v11, v10, v9);
    gmu_core_regwrite(a1, 129080, 0);
    result = gmu_core_regwrite(a1, 146192, 0);
    v8 = *(unsigned int *)(a1 + 1536);
    if ( ((1LL << a3) & v8) != 0 )
    {
      dev_err(
        *(_QWORD *)(a1 - 88) + 16LL,
        "GMU always on ticks: %llx gf_policy: 0x%x gf_trigger: 0x%lx\n",
        v7,
        v8,
        1LL << a3);
      __break(0x800u);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
