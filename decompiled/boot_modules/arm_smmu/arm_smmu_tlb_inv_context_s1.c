__int64 __fastcall arm_smmu_tlb_inv_context_s1(unsigned __int16 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  void (*v4)(void); // x8

  __dsb(0xEu);
  v2 = *(_QWORD *)a1;
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 48LL);
  if ( v3 && (v4 = *(void (**)(void))(v3 + 8)) != nullptr )
  {
    if ( *((_DWORD *)v4 - 1) != -1008624849 )
      __break(0x8228u);
    v4();
  }
  else
  {
    writel_relaxed_0(
      a1[25],
      (unsigned int *)(*(_QWORD *)(v2 + 8)
                     + ((*(_DWORD *)(*(_QWORD *)a1 + 24LL) + *((unsigned __int8 *)a1 + 48)) << *(_DWORD *)(v2 + 28))
                     + 1552LL));
  }
  return arm_smmu_tlb_sync_context(a1);
}
