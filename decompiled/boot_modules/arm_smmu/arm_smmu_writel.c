__int64 __fastcall arm_smmu_writel(__int64 a1, int a2, int a3, unsigned int a4)
{
  __int64 v4; // x8
  __int64 (*v5)(void); // x8

  v4 = *(_QWORD *)(a1 + 48);
  if ( !v4 )
    return writel_relaxed_0(a4, *(_QWORD *)(a1 + 8) + (a2 << *(_DWORD *)(a1 + 28)) + a3);
  v5 = *(__int64 (**)(void))(v4 + 8);
  if ( !v5 )
    return writel_relaxed_0(a4, *(_QWORD *)(a1 + 8) + (a2 << *(_DWORD *)(a1 + 28)) + a3);
  if ( *((_DWORD *)v5 - 1) != -1008624849 )
    __break(0x8228u);
  return v5();
}
