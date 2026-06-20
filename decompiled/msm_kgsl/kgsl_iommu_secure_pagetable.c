__int64 __fastcall kgsl_iommu_secure_pagetable(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x8
  __int64 v4; // x8

  if ( *(_BYTE *)(a1 + 40) != 1 )
    return -1;
  v2 = (_QWORD *)_kmalloc_cache_noprof(clk_set_rate, 3520, 360);
  if ( !v2 )
    return -12;
  kgsl_mmu_pagetable_init(a1, (__int64)v2, 1);
  v2[12] = &secure_pt_ops;
  v2[13] = -1;
  v3 = 4026531840LL;
  v2[20] = 4026531840LL;
  v2[21] = 0x100000000LL;
  if ( (*(_QWORD *)(a1 + 48) & 1LL) != 0 )
    v3 = 0x100000000LL;
  v2[15] = 0;
  v2[16] = v3;
  v4 = 0x1EFFFF000LL;
  if ( (*(_QWORD *)(a1 + 48) & 1LL) == 0 )
    v4 = 0x100000000LL;
  v2[17] = v4;
  kgsl_mmu_pagetable_add(a1, (__int64)v2);
  return (__int64)v2;
}
