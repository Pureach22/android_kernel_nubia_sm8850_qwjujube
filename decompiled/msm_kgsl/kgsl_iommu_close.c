__int64 __fastcall kgsl_iommu_close(__int64 a1)
{
  __int64 v2; // x8
  __int64 *v3; // x20
  _DWORD *v4; // x8
  __int64 v5; // x0
  __int64 *v6; // x20
  _DWORD *v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 result; // x0

  kgsl_mmu_putpagetable(*(_QWORD **)(a1 + 16));
  kgsl_mmu_putpagetable(*(_QWORD **)(a1 + 24));
  _flush_workqueue(qword_3A900);
  v2 = *(_QWORD *)(a1 + 696);
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  if ( v2 )
  {
    v3 = *(__int64 **)(*(_QWORD *)(a1 + 624) + 168LL);
    kgsl_iommu_enable_clk(a1);
    v4 = (_DWORD *)v3[2];
    v5 = *v3;
    if ( *(v4 - 1) != 985432076 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v4)(v5, 0);
    kgsl_iommu_disable_clk(a1);
  }
  if ( *(_QWORD *)(a1 + 136) )
  {
    v6 = *(__int64 **)(*(_QWORD *)(a1 + 64) + 168LL);
    kgsl_iommu_enable_clk(a1);
    v7 = (_DWORD *)v6[2];
    v8 = *v6;
    if ( *(v7 - 1) != 985432076 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v7)(v8, 0);
    kgsl_iommu_disable_clk(a1);
    v9 = *(_QWORD *)(a1 + 136);
    if ( v9 )
    {
      iommu_detach_device(v9, *(_QWORD *)(a1 + 64) + 16LL);
      iommu_domain_free(*(_QWORD *)(a1 + 136));
      v10 = *(_QWORD *)(a1 + 64);
      *(_QWORD *)(a1 + 136) = 0;
      platform_device_put(v10);
      *(_QWORD *)(a1 + 64) = 0;
    }
  }
  v11 = *(_QWORD *)(a1 + 696);
  if ( v11 )
  {
    iommu_detach_device(v11, *(_QWORD *)(a1 + 624) + 16LL);
    iommu_domain_free(*(_QWORD *)(a1 + 696));
    v12 = *(_QWORD *)(a1 + 624);
    *(_QWORD *)(a1 + 696) = 0;
    platform_device_put(v12);
    *(_QWORD *)(a1 + 624) = 0;
  }
  v13 = *(_QWORD *)(a1 + 416);
  if ( v13 )
  {
    iommu_detach_device(v13, *(_QWORD *)(a1 + 344) + 16LL);
    iommu_domain_free(*(_QWORD *)(a1 + 416));
    v14 = *(_QWORD *)(a1 + 344);
    *(_QWORD *)(a1 + 416) = 0;
    platform_device_put(v14);
    *(_QWORD *)(a1 + 344) = 0;
  }
  kgsl_free_secure_page(kgsl_secure_guard_page);
  kgsl_secure_guard_page = 0;
  if ( kgsl_guard_page )
  {
    _free_pages(kgsl_guard_page, 0);
    kgsl_guard_page = 0;
  }
  v15 = *(_QWORD *)(a1 + 952);
  if ( (*(_WORD *)(v15 + 504) & 7) == 0 )
    _pm_runtime_disable(v15 + 16, 1);
  result = kmem_cache_destroy(addr_entry_cache);
  addr_entry_cache = 0;
  return result;
}
