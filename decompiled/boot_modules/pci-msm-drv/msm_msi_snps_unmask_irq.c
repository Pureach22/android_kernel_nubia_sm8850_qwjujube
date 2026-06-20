__int64 __fastcall msm_msi_snps_unmask_irq(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v4; // x0
  char v5; // w8
  __int64 v6; // x19
  unsigned int v7; // w8

  v1 = *(_QWORD *)(a1 + 48);
  v2 = *(_QWORD *)(v1 + 8);
  v3 = *(_QWORD *)(*(_QWORD *)v1 + 16LL);
  v4 = raw_spin_lock_irqsave(v3 + 144);
  v5 = *(_DWORD *)(v1 + 16);
  v6 = v4;
  v7 = *(_DWORD *)(v2 + 24) & ~(unsigned int)(1LL << v5);
  *(_DWORD *)(v2 + 24) = v7;
  if ( *(_BYTE *)(v3 + 148) == 1 )
    writel_relaxed(v7, *(unsigned int **)(v2 + 8));
  return raw_spin_unlock_irqrestore(v3 + 144, v6);
}
