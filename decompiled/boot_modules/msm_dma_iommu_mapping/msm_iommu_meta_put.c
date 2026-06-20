__int64 __fastcall msm_iommu_meta_put(__int64 a1)
{
  int v8; // w8

  mutex_lock(&msm_iommu_map_mutex);
  _X0 = (unsigned int *)(a1 + 40);
  __asm { PRFM            #0x11, [X0] }
  do
    v8 = __ldxr(_X0);
  while ( __stlxr(v8 - 1, _X0) );
  if ( v8 == 1 )
  {
    __dmb(9u);
    if ( *(_QWORD *)(a1 + 24) != a1 + 24 )
    {
      _warn_printk(
        "%s: DMA Buffer %pK being destroyed with outstanding iommu mappings!\n",
        "msm_iommu_meta_destroy",
        *(const void **)(a1 + 96));
      __break(0x800u);
    }
    rb_erase(a1, &iommu_root);
    kfree(a1);
  }
  else if ( v8 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  return mutex_unlock(&msm_iommu_map_mutex);
}
