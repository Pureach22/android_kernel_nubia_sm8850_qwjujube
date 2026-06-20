__int64 __fastcall qcom_adreno_smmu_write_sctlr(__int64 a1, int a2, unsigned int a3)
{
  __int64 v3; // x9
  unsigned __int64 v4; // x8
  __int64 v5; // x1
  int v6; // w8
  _DWORD *v7; // x9

  v3 = *(_QWORD *)(a1 + 48);
  v4 = (unsigned __int64)*(unsigned int *)(a1 + 340) >> a2;
  v5 = (unsigned int)(*(_DWORD *)(a1 + 24) + a2);
  if ( (v4 & 1) != 0 )
    v6 = 384;
  else
    v6 = 256;
  if ( !v3 )
    return writel_relaxed_1(v6 | a3, (unsigned int *)(*(_QWORD *)(a1 + 8) + (int)((_DWORD)v5 << *(_DWORD *)(a1 + 28))));
  v7 = *(_DWORD **)(v3 + 8);
  if ( !v7 )
    return writel_relaxed_1(v6 | a3, (unsigned int *)(*(_QWORD *)(a1 + 8) + (int)((_DWORD)v5 << *(_DWORD *)(a1 + 28))));
  if ( *(v7 - 1) != -1008624849 )
    __break(0x8229u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v7)(a1, v5, 0, v6 | a3);
}
