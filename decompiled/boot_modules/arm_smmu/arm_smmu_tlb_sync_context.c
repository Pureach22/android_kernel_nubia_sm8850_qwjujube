__int64 __fastcall arm_smmu_tlb_sync_context(__int64 *a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  const char **v5; // x8
  const char *v6; // x3

  v2 = *a1;
  v3 = raw_spin_lock_irqsave((char *)a1 + 132);
  if ( (unsigned int)_arm_smmu_tlb_sync(
                       v2,
                       *(_DWORD *)(v2 + 24) + (unsigned int)*((unsigned __int8 *)a1 + 48),
                       2032,
                       2036)
    && (unsigned int)__ratelimit(&arm_smmu_tlb_sync_context__rs, "arm_smmu_tlb_sync_context") )
  {
    v5 = (const char **)a1[1];
    v6 = v5[14];
    if ( !v6 )
      v6 = *v5;
    dev_err(*(_QWORD *)v2, "TLB sync on cb%d failed for device %s\n", *((unsigned __int8 *)a1 + 48), v6);
  }
  return raw_spin_unlock_irqrestore((char *)a1 + 132, v3);
}
