size_t __fastcall iommu_debug_unmap_write(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x1
  void *v4; // x0
  __int64 v5; // x21
  size_t v6; // x19
  __int64 v8; // x1
  _BYTE *v9; // x0
  _BYTE *v10; // x20
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // [xsp+0h] [xbp-80h] BYREF
  __int64 v16; // [xsp+8h] [xbp-78h] BYREF
  _QWORD v17[12]; // [xsp+10h] [xbp-70h] BYREF
  int v18; // [xsp+70h] [xbp-10h]
  __int64 v19; // [xsp+78h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  v15 = 0;
  v16 = 0;
  if ( a3 >= 0x64 )
  {
    if ( !(unsigned int)__ratelimit(&iommu_debug_unmap_write__rs, "iommu_debug_unmap_write") )
    {
LABEL_17:
      v6 = -22;
      goto LABEL_18;
    }
    v4 = &unk_CEDD;
LABEL_4:
    printk(v4, v3);
    goto LABEL_17;
  }
  v5 = *(_QWORD *)(a1 + 32);
  if ( !*(_QWORD *)(v5 + 40) )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_unmap_write__rs_16, "iommu_debug_unmap_write") )
      printk(&unk_CE32, "iommu_debug_unmap_write");
    goto LABEL_17;
  }
  v6 = a3;
  _check_object_size(v17, a3, 0);
  if ( inline_copy_from_user((int)v17, a2, v6) )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_unmap_write__rs_17, "iommu_debug_unmap_write") )
      printk(&unk_D091, v8);
    v6 = -14;
  }
  else
  {
    v9 = (_BYTE *)strnchr(v17, v6, 44);
    if ( !v9 || (v10 = v9, *v9 = 0, (unsigned int)kstrtoull(v17, 0, &v16)) || (unsigned int)kstrtoull(v10 + 1, 0, &v15) )
    {
      if ( !(unsigned int)__ratelimit(&iommu_debug_unmap_write__rs_23, "iommu_debug_unmap_write") )
        goto LABEL_17;
      v4 = &unk_CDDB;
      goto LABEL_4;
    }
    mutex_lock(v5 + 56);
    v12 = *(_QWORD *)(v5 + 40);
    if ( !v12 )
    {
      if ( (unsigned int)__ratelimit(&iommu_debug_unmap_write__rs_18, "iommu_debug_unmap_write") )
        printk(&unk_D732, v14);
      mutex_unlock(v5 + 56);
      goto LABEL_17;
    }
    v13 = iommu_unmap(v12, v16, v15);
    if ( v13 == v15 )
    {
      printk(&unk_D5DD, &v16);
    }
    else
    {
      if ( (unsigned int)__ratelimit(&iommu_debug_unmap_write__rs_20, "iommu_debug_unmap_write") )
        printk(&unk_D815, v15);
      v6 = -5;
    }
  }
  mutex_unlock(v5 + 56);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v6;
}
