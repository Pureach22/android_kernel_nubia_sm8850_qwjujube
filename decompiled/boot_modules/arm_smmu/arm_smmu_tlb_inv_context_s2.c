__int64 __fastcall arm_smmu_tlb_inv_context_s2(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x3
  __int64 v3; // x8
  _DWORD *v4; // x8
  __int64 v5; // x20

  v1 = *(_QWORD **)a1;
  __dsb(0xEu);
  v2 = *(unsigned __int16 *)(a1 + 50);
  v3 = v1[6];
  if ( v3 && (v4 = *(_DWORD **)(v3 + 8)) != nullptr )
  {
    if ( *(v4 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64, __int64))v4)(v1, 0, 100, v2);
  }
  else
  {
    writel_relaxed_0(*(unsigned __int16 *)(a1 + 50), (unsigned int *)(v1[1] + 100LL));
  }
  v5 = raw_spin_lock_irqsave(v1 + 28);
  if ( (unsigned int)_arm_smmu_tlb_sync((__int64)v1, 0, 112, 0x74u)
    && (unsigned int)__ratelimit(&arm_smmu_tlb_sync_global__rs, "arm_smmu_tlb_sync_global") )
  {
    dev_err(*v1, "TLB global sync failed!\n");
  }
  return raw_spin_unlock_irqrestore(v1 + 28, v5);
}
