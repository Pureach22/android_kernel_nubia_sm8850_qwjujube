__int64 __fastcall qcom_adreno_smmu_resume_translation(__int64 *a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x9
  int v5; // w8
  __int64 (*v6)(void); // x9

  v3 = *a1;
  v4 = *(_QWORD *)(v3 + 48);
  v5 = *(_DWORD *)(v3 + 24) + *((unsigned __int8 *)a1 + 48);
  if ( !v4 )
    return writel_relaxed_1(a2 & 1, (unsigned int *)(*(_QWORD *)(v3 + 8) + (v5 << *(_DWORD *)(v3 + 28)) + 8LL));
  v6 = *(__int64 (**)(void))(v4 + 8);
  if ( !v6 )
    return writel_relaxed_1(a2 & 1, (unsigned int *)(*(_QWORD *)(v3 + 8) + (v5 << *(_DWORD *)(v3 + 28)) + 8LL));
  if ( *((_DWORD *)v6 - 1) != -1008624849 )
    __break(0x8229u);
  return v6();
}
