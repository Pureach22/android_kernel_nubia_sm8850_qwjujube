__int64 __fastcall kgsl_iommu_destroy_default_pagetable(__int64 a1)
{
  __int64 v1; // x9
  _QWORD *v3; // x20
  _QWORD *v4; // x21

  v1 = *(_QWORD *)(a1 + 112);
  v3 = *(_QWORD **)(v1 + 13056);
  v4 = (_QWORD *)(v1 + 13056);
  while ( v3 != v4 )
  {
    if ( (*(_BYTE *)(v3 - 18) & 8) == 0 )
      kgsl_iommu_default_unmap(a1, (__int64)(v3 - 27));
    v3 = (_QWORD *)*v3;
  }
  return kfree(a1);
}
