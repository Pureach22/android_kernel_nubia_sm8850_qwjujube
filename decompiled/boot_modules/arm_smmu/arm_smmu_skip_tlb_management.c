__int64 __fastcall arm_smmu_skip_tlb_management(__int64 a1, char a2)
{
  __int64 v2; // x21
  __int64 v5; // x0

  v2 = a1 - 24;
  v5 = raw_spin_lock_irqsave(a1 - 24);
  *(_BYTE *)(a1 + 121) = a2;
  return raw_spin_unlock_irqrestore(v2, v5);
}
