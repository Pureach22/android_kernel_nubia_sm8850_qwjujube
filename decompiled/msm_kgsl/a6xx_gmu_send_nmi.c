__int64 __fastcall a6xx_gmu_send_nmi(__int64 a1, char a2, char a3)
{
  __int64 (*v6)(void); // x8
  __int64 v7; // x21
  __int64 result; // x0
  __int64 v9; // x3
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 152LL);
  if ( *((_DWORD *)v6 - 1) != -944375624 )
    __break(0x8228u);
  v7 = v6();
  v10[0] = 0;
  result = gmu_core_regread(a1, 129232, (char *)v10 + 4);
  if ( (v10[0] & 0xC000000000LL) == 0 )
  {
    result = adreno_smmu_is_stalled(a1);
    if ( (result & 1) != 0 )
    {
      result = dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Skipping NMI because SMMU is stalled\n");
      goto LABEL_9;
    }
  }
  if ( (a2 & 1) == 0 )
    goto LABEL_11;
  do
  {
    gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
    __dsb(0xEu);
    if ( (*(_BYTE *)(a1 + 20656) & 0x20) != 0 )
      gmu_core_regwrite(a1, 117744, 0);
    gmu_core_regread(a1, 129069, v10);
    LODWORD(v10[0]) |= 0x200u;
    gmu_core_regwrite(a1, 129069, LODWORD(v10[0]));
    __dsb(0xEu);
    result = _const_udelay(859000);
LABEL_9:
    v9 = *(unsigned int *)(a1 + 1536);
    if ( ((1LL << a3) & v9) == 0 )
      break;
    result = dev_err(
               *(_QWORD *)(a1 + 1544) + 16LL,
               "GMU always on ticks: %llx gf_policy: 0x%x gf_trigger: 0x%lx\n",
               v7,
               v9,
               1LL << a3);
    __break(0x800u);
LABEL_11:
    __dmb(9u);
    if ( *(_DWORD *)(a1 - 368) )
      break;
    result = gmu_core_regread(a1, 129052, v10);
  }
  while ( (v10[0] & 0xE00LL) == 0 );
  _ReadStatusReg(SP_EL0);
  return result;
}
