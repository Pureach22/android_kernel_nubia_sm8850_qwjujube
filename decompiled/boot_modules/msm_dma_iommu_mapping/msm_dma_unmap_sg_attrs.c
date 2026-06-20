__int64 __fastcall msm_dma_unmap_sg_attrs(_BYTE *a1, __int64 a2, __int64 a3, unsigned int a4, _QWORD *a5, __int64 a6)
{
  _QWORD *v10; // x19
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  void *v13; // x0
  _QWORD *v15; // x24
  int v16; // w4
  int v23; // w8

  mutex_lock(&msm_iommu_map_mutex);
  v10 = (_QWORD *)iommu_root;
  if ( iommu_root )
  {
    v11 = a5[14];
    while ( 1 )
    {
      while ( 1 )
      {
        v12 = v10[12];
        if ( v12 <= v11 )
          break;
        v10 = (_QWORD *)v10[2];
        if ( !v10 )
          goto LABEL_7;
      }
      if ( v12 >= v11 )
        break;
      v10 = (_QWORD *)v10[1];
      if ( !v10 )
        goto LABEL_7;
    }
    mutex_unlock(&msm_iommu_map_mutex);
    mutex_lock(v10 + 6);
    v15 = v10 + 3;
    do
    {
      v15 = (_QWORD *)*v15;
      if ( v15 == v10 + 3 )
        goto LABEL_21;
    }
    while ( (_BYTE *)v15[5] != a1 );
    if ( !v15 )
    {
LABEL_21:
      _warn_printk("%s: (%pK) was never mapped for device  %p\n", "msm_dma_unmap_sg_attrs", a5, a1);
      v13 = v10 + 6;
      __break(0x800u);
      return mutex_unlock(v13);
    }
    v16 = *((_DWORD *)v15 + 15);
    if ( v16 != a4 )
    {
      _warn_printk("%s: (%pK) dir:%d differs from original dir:%d\n", "msm_dma_unmap_sg_attrs", a5, a4, v16);
      __break(0x800u);
    }
    if ( a6 && (a6 & 0x20) == 0 && (a1[844] & 0x40) == 0 )
      _dma_sync_sg_for_cpu(a1, v15[6], *((unsigned int *)v15 + 14), a4);
    _X0 = (unsigned int *)(v15 + 9);
    v15[10] = a6;
    __asm { PRFM            #0x11, [X0] }
    do
      v23 = __ldxr(_X0);
    while ( __stlxr(v23 - 1, _X0) );
    if ( v23 == 1 )
    {
      __dmb(9u);
      msm_iommu_map_release();
    }
    else if ( v23 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    mutex_unlock(v10 + 6);
    return msm_iommu_meta_put(v10);
  }
  else
  {
LABEL_7:
    _warn_printk("%s: (%pK) was never mapped\n", "msm_dma_unmap_sg_attrs", a5);
    v13 = &msm_iommu_map_mutex;
    __break(0x800u);
    return mutex_unlock(v13);
  }
}
