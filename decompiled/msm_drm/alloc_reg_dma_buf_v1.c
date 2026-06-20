__int64 __fastcall alloc_reg_dma_buf_v1(unsigned int a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  _QWORD *v6; // x20
  unsigned __int64 v7; // x8
  _QWORD *v8; // x0
  __int64 v9; // x21
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x21
  int v12; // w0
  int v13; // w22
  __int64 v14; // x0
  int iova; // w0
  unsigned __int64 vaddr; // x8
  __int64 v17; // x9
  __int64 v18; // x10

  if ( a1 - 0x10000 <= 0xFFFF0000 )
  {
    _drm_err("invalid buffer size %lu, max %lu\n", a1 >> 2, 0x3FFF);
    return -22;
  }
  if ( a2 >= 2 )
  {
    _drm_err("invalid dpu idx %d\n", a2);
    return -22;
  }
  v5 = _kmalloc_cache_noprof(_drm_debug, 3520, 56);
  if ( v5 )
  {
    v6 = (_QWORD *)v5;
    v7 = msm_gem_new(*(_QWORD *)reg_dma_0[a2], a1 + 255, 0x40000);
    v8 = v6;
    v9 = -22;
    *v6 = v7;
    if ( !v7 || v7 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_23;
    v10 = msm_gem_smmu_address_space_get(*(_QWORD *)reg_dma_0[a2], 0);
    if ( v10 == -19 )
    {
      _drm_dev_dbg(0, 0, 0, "IOMMU not present, relying on VRAM\n");
      v11 = 0;
    }
    else
    {
      v11 = v10;
      if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
      {
        _drm_err("failed to get aspace %d", v10);
        v13 = v11;
        goto LABEL_22;
      }
      v12 = msm_gem_address_space_register_cb(v10, sde_reg_dma_aspace_cb_locked, v6);
      if ( v12 )
      {
        v13 = v12;
        _drm_err("failed to register callback %d", v12);
LABEL_22:
        mutex_lock(*(_QWORD *)reg_dma_0[a2] + 128LL);
        msm_gem_free_object(*v6);
        mutex_unlock(*(_QWORD *)reg_dma_0[a2] + 128LL);
        v9 = v13;
        v8 = v6;
LABEL_23:
        kfree(v8);
        return v9;
      }
    }
    v14 = *v6;
    v6[1] = v11;
    iova = msm_gem_get_iova(v14, v11, v6 + 3);
    if ( iova )
    {
      v13 = iova;
      _drm_err("failed to get the iova rc %d\n", iova);
    }
    else
    {
      vaddr = msm_gem_get_vaddr(*v6);
      result = (__int64)v6;
      v6[4] = vaddr;
      if ( vaddr && vaddr < 0xFFFFFFFFFFFFF001LL )
      {
        v17 = v6[3];
        *((_DWORD *)v6 + 4) = a1;
        v18 = (((_DWORD)v17 + 255) & 0xFFFFFF00) - (unsigned int)v17;
        v6[3] = v18 + v17;
        v6[4] = vaddr + v18;
        *((_DWORD *)v6 + 10) = 1;
        return result;
      }
      _drm_err("failed to get va rc %d\n", 0);
      msm_gem_put_iova(*v6, v11);
      v13 = -22;
    }
    msm_gem_address_space_unregister_cb(v11, sde_reg_dma_aspace_cb_locked, v6);
    goto LABEL_22;
  }
  return -12;
}
