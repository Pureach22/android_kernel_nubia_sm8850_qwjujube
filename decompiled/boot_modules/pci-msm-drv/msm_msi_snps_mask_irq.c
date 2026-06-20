__int64 __fastcall msm_msi_snps_mask_irq(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x0

  v1 = *(_QWORD *)(a1 + 48);
  v2 = *(_QWORD *)(v1 + 8);
  v3 = *(_QWORD *)(*(_QWORD *)v1 + 16LL);
  v4 = raw_spin_lock_irqsave(v3 + 144);
  *(_DWORD *)(v2 + 24) |= 1LL << *(_DWORD *)(v1 + 16);
  return raw_spin_unlock_irqrestore(v3 + 144, v4);
}
