__int64 __fastcall arm_smmu_tlb_add_page_s2_v1(__int64 a1, __int64 a2, __int64 a3, unsigned __int16 *a4)
{
  __int64 v4; // x0
  __int64 v5; // x8
  unsigned int v6; // w3
  __int64 (*v7)(void); // x8

  v4 = *(_QWORD *)a4;
  if ( (*(_BYTE *)(*(_QWORD *)a4 + 32LL) & 1) != 0 )
    __dsb(0xEu);
  v5 = *(_QWORD *)(v4 + 48);
  v6 = a4[25];
  if ( !v5 )
    return writel_relaxed_0(v6, (unsigned int *)(*(_QWORD *)(v4 + 8) + 100LL));
  v7 = *(__int64 (**)(void))(v5 + 8);
  if ( !v7 )
    return writel_relaxed_0(v6, (unsigned int *)(*(_QWORD *)(v4 + 8) + 100LL));
  if ( *((_DWORD *)v7 - 1) != -1008624849 )
    __break(0x8228u);
  return v7();
}
