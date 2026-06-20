size_t __fastcall iommu_debug_dma_unmap_write(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x1
  void *v4; // x0
  __int64 v5; // x23
  size_t v6; // x19
  __int64 v8; // x20
  __int64 v9; // x1
  __int64 v10; // x0
  _BYTE *v11; // x22
  _BYTE *v12; // x0
  _BYTE *v13; // x21
  __int64 v14; // x21
  __int64 v16; // [xsp+8h] [xbp-88h] BYREF
  unsigned int v17; // [xsp+14h] [xbp-7Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-78h] BYREF
  _QWORD v19[12]; // [xsp+20h] [xbp-70h] BYREF
  int v20; // [xsp+80h] [xbp-10h]
  __int64 v21; // [xsp+88h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  v18 = 0;
  v17 = 0;
  v16 = 0;
  if ( a3 >= 0x64 )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_dma_unmap_write__rs, "iommu_debug_dma_unmap_write") )
    {
      v4 = &unk_CEDD;
LABEL_22:
      printk(v4, v3);
      goto LABEL_19;
    }
    goto LABEL_19;
  }
  v5 = *(_QWORD *)(a1 + 32);
  v6 = a3;
  v8 = *(_QWORD *)(v5 + 32);
  _check_object_size(v19, a3, 0);
  if ( inline_copy_from_user((int)v19, a2, v6) )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_dma_unmap_write__rs_42, "iommu_debug_dma_unmap_write") )
      printk(&unk_D091, v9);
    v6 = -14;
  }
  else
  {
    v10 = strnchr(v19, v6, 44);
    if ( !v10
      || (v11 = (_BYTE *)v10, (v12 = (_BYTE *)strnchr(v10 + 1, v6, 44)) == nullptr)
      || (v13 = v12, *v12 = 0, *v11 = 0, (unsigned int)kstrtoull(v19, 0, &v16))
      || (unsigned int)kstrtoull(v11 + 1, 0, &v18)
      || (unsigned int)kstrtouint(v13 + 1, 0, &v17)
      || v17 > 3 )
    {
      if ( (unsigned int)__ratelimit(&iommu_debug_dma_unmap_write__rs_46, "iommu_debug_dma_unmap_write") )
      {
        v4 = &unk_D0AC;
        goto LABEL_22;
      }
LABEL_19:
      v6 = -22;
      goto LABEL_20;
    }
    v14 = qword_D970[v17];
    mutex_lock(v5 + 56);
    if ( !*(_QWORD *)(v5 + 40) )
    {
      if ( (unsigned int)__ratelimit(&iommu_debug_dma_unmap_write__rs_43, "iommu_debug_dma_unmap_write") )
        printk(&unk_CE32, "iommu_debug_dma_unmap_write");
      mutex_unlock(v5 + 56);
      goto LABEL_19;
    }
    dma_unmap_page_attrs(v8, v16, v18, 1, v14);
    if ( (unsigned int)__ratelimit(&iommu_debug_dma_unmap_write__rs_44, "iommu_debug_dma_unmap_write") )
      printk(&unk_D855, &v16);
  }
  mutex_unlock(v5 + 56);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v6;
}
