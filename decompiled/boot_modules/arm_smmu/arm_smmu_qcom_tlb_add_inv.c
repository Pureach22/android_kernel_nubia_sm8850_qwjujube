__int64 __fastcall arm_smmu_qcom_tlb_add_inv(__int64 a1)
{
  __int64 v2; // x0

  v2 = raw_spin_lock_irqsave(a1 + 160);
  *(_BYTE *)(a1 + 176) = *(_BYTE *)(a1 + 305) ^ 1;
  return raw_spin_unlock_irqrestore(a1 + 160, v2);
}
