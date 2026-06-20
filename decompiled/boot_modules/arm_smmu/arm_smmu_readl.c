__int64 __fastcall arm_smmu_readl(__int64 a1, int a2, int a3)
{
  __int64 (**v3)(void); // x8
  __int64 (*v4)(void); // x8

  v3 = *(__int64 (***)(void))(a1 + 48);
  if ( !v3 )
    return readl_relaxed_0(*(_QWORD *)(a1 + 8) + (a2 << *(_DWORD *)(a1 + 28)) + a3);
  v4 = *v3;
  if ( !v4 )
    return readl_relaxed_0(*(_QWORD *)(a1 + 8) + (a2 << *(_DWORD *)(a1 + 28)) + a3);
  if ( *((_DWORD *)v4 - 1) != 616069899 )
    __break(0x8228u);
  return v4();
}
