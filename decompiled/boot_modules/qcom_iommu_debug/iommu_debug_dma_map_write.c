size_t __fastcall iommu_debug_dma_map_write(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x1
  void *v4; // x0
  _QWORD *v5; // x24
  size_t v6; // x19
  __int64 v8; // x20
  __int64 v9; // x1
  __int64 v10; // x0
  _BYTE *v11; // x23
  _BYTE *v12; // x0
  _BYTE *v13; // x22
  unsigned __int64 v14; // x21
  __int64 v16; // x23
  __int64 v17; // x1
  __int64 v18; // x22
  __int64 v19; // x0
  __int64 v20; // x20
  __int64 v21; // x1
  unsigned int v22; // [xsp+4h] [xbp-8Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-88h] BYREF
  __int64 v24; // [xsp+10h] [xbp-80h] BYREF
  unsigned __int64 v25; // [xsp+18h] [xbp-78h] BYREF
  _QWORD v26[12]; // [xsp+20h] [xbp-70h] BYREF
  int v27; // [xsp+80h] [xbp-10h]
  __int64 v28; // [xsp+88h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  memset(v26, 0, sizeof(v26));
  v25 = 0;
  v23 = 0;
  v22 = 0;
  if ( a3 >= 0x64 )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs, "iommu_debug_dma_map_write") )
    {
      v4 = &unk_CEDD;
LABEL_17:
      printk(v4, v3);
      goto LABEL_14;
    }
    goto LABEL_14;
  }
  v5 = *(_QWORD **)(a1 + 32);
  v6 = a3;
  v8 = v5[4];
  _check_object_size(v26, a3, 0);
  if ( inline_copy_from_user((int)v26, a2, v6) )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_25, "iommu_debug_dma_map_write") )
      printk(&unk_D091, v9);
    v6 = -14;
    goto LABEL_15;
  }
  v10 = strnchr(v26, v6, 44);
  if ( !v10
    || (v11 = (_BYTE *)v10, (v12 = (_BYTE *)strnchr(v10 + 1, v6, 44)) == nullptr)
    || (v13 = v12, *v12 = 0, *v11 = 0, (unsigned int)kstrtoull(v26, 0, &v25))
    || (v14 = v25, (unsigned int)kstrtoull(v11 + 1, 0, &v23))
    || (unsigned int)kstrtouint(v13 + 1, 0, &v22) )
  {
LABEL_13:
    if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_33, "iommu_debug_dma_map_write") )
    {
      v4 = &unk_D5F9;
      goto LABEL_17;
    }
LABEL_14:
    v6 = -22;
    goto LABEL_15;
  }
  mutex_lock(&test_virt_addr_lock);
  v16 = test_virt_addr;
  if ( (unsigned __int64)test_virt_addr < 0xFFFFFFFFFFFFF001LL )
  {
    mutex_unlock(&test_virt_addr_lock);
    if ( !v16 )
    {
      if ( !(unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_39, "iommu_debug_dma_map_write") )
        goto LABEL_14;
      v4 = &unk_D696;
      goto LABEL_17;
    }
    if ( test_virt_addr > v14 || v14 + v23 > test_virt_addr + 0x100000 )
    {
      if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_35, "iommu_debug_dma_map_write") )
        printk(&unk_D3C6, v14);
      goto LABEL_14;
    }
    if ( v22 > 3 )
      goto LABEL_13;
    v18 = qword_D970[v22];
    mutex_lock(v5 + 7);
    if ( !v5[5] )
    {
      if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_26, "iommu_debug_dma_map_write") )
        printk(&unk_CE32, "iommu_debug_dma_map_write");
      mutex_unlock(v5 + 7);
      goto LABEL_14;
    }
    v19 = dma_map_single_attrs(v8, v14, v23, v18);
    v24 = v19;
    if ( v19 == -1 )
    {
      if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_27, "iommu_debug_dma_map_write") )
        printk(&unk_D7EA, v21);
      v6 = -22;
    }
    else
    {
      v20 = v19;
      if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_29, "iommu_debug_dma_map_write") )
      {
        printk(&unk_CFD4, v14);
        v20 = v24;
      }
      v5[17] = v20;
      if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_31, "iommu_debug_dma_map_write") )
        printk(&unk_D2C0, &v24);
    }
    mutex_unlock(v5 + 7);
  }
  else
  {
    mutex_unlock(&test_virt_addr_lock);
    if ( (unsigned int)__ratelimit(&iommu_debug_dma_map_write__rs_37, "iommu_debug_dma_map_write") )
      printk(&unk_D4A7, v17);
    v6 = -12;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v6;
}
