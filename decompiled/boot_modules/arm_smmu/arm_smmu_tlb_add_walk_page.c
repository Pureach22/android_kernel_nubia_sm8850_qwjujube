__int64 __fastcall arm_smmu_tlb_add_walk_page(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x10
  _QWORD *v6; // x8

  v3 = (unsigned __int64)((a2 << 8 >> 8) + 0x8000000000LL) >> 12;
  v4 = raw_spin_lock_irqsave(a1 + 160);
  v5 = *(_QWORD *)(a1 + 168);
  *(_BYTE *)(a1 + 176) = 1;
  v6 = (_QWORD *)((v3 << 6) - 0x13FFFFFF8LL);
  *v6 = v5;
  *(_QWORD *)(a1 + 168) = v6;
  return raw_spin_unlock_irqrestore(a1 + 160, v4);
}
