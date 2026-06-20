__int64 __fastcall msm_dma_buf_freed(unsigned __int64 a1)
{
  _QWORD *v2; // x19
  unsigned __int64 v3; // x8
  _QWORD *v5; // x20
  _QWORD *v6; // x21
  int v13; // w8

  mutex_lock(&msm_iommu_map_mutex);
  v2 = (_QWORD *)iommu_root;
  if ( !iommu_root )
    return mutex_unlock(&msm_iommu_map_mutex);
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = v2[12];
      if ( v3 <= a1 )
        break;
      v2 = (_QWORD *)v2[2];
      if ( !v2 )
        return mutex_unlock(&msm_iommu_map_mutex);
    }
    if ( v3 >= a1 )
      break;
    v2 = (_QWORD *)v2[1];
    if ( !v2 )
      return mutex_unlock(&msm_iommu_map_mutex);
  }
  mutex_unlock(&msm_iommu_map_mutex);
  mutex_lock(v2 + 6);
  v5 = v2 + 3;
  v6 = (_QWORD *)v2[3];
  if ( v6 != v2 + 3 )
  {
    do
    {
      _X0 = (unsigned int *)(v6 + 9);
      v6 = (_QWORD *)*v6;
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( __stlxr(v13 - 1, _X0) );
      if ( v13 == 1 )
      {
        __dmb(9u);
        msm_iommu_map_release((__int64)_X0);
      }
      else if ( v13 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
    while ( v6 != v5 );
  }
  if ( (_QWORD *)*v5 != v5 )
  {
    _warn_printk(
      "%s: DMA buffer %pK destroyed with outstanding iommu mappings\n",
      "msm_dma_buf_freed",
      (const void *)v2[12]);
    __break(0x800u);
  }
  v2[3] = v2 + 3;
  v2[4] = v5;
  mutex_unlock(v2 + 6);
  return msm_iommu_meta_put((__int64)v2);
}
