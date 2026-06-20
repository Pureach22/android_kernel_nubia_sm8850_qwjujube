size_t __fastcall iommu_debug_map_write(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x1
  void *v4; // x0
  size_t v5; // x19
  __int64 v6; // x23
  __int64 v8; // x1
  __int64 v9; // x0
  _BYTE *v10; // x22
  __int64 v11; // x0
  _BYTE *v12; // x21
  _BYTE *v13; // x0
  _BYTE *v14; // x20
  __int64 v16; // x0
  unsigned int v17; // w0
  unsigned int v18; // w20
  unsigned int v19; // [xsp+4h] [xbp-8Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-88h] BYREF
  __int64 v21; // [xsp+10h] [xbp-80h] BYREF
  __int64 v22; // [xsp+18h] [xbp-78h] BYREF
  _QWORD v23[12]; // [xsp+20h] [xbp-70h] BYREF
  int v24; // [xsp+80h] [xbp-10h]
  __int64 v25; // [xsp+88h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  memset(v23, 0, sizeof(v23));
  v21 = 0;
  v22 = 0;
  v20 = 0;
  v19 = 0;
  if ( a3 >= 0x64 )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_map_write__rs, "iommu_debug_map_write") )
    {
      v4 = &unk_CEDD;
LABEL_18:
      printk(v4, v3);
      goto LABEL_15;
    }
    goto LABEL_15;
  }
  v5 = a3;
  v6 = *(_QWORD *)(a1 + 32);
  _check_object_size(v23, a3, 0);
  if ( inline_copy_from_user((int)v23, a2, v5)
    && (unsigned int)__ratelimit(&iommu_debug_map_write__rs_8, "iommu_debug_map_write") )
  {
    printk(&unk_D091, v8);
  }
  v9 = strnchr(v23, v5, 44);
  if ( !v9 )
    goto LABEL_31;
  v10 = (_BYTE *)v9;
  v11 = strnchr(v9 + 1, v5, 44);
  if ( !v11
    || (v12 = (_BYTE *)v11, (v13 = (_BYTE *)strnchr(v11 + 1, v5, 44)) == nullptr)
    || (v14 = v13, *v13 = 0, *v12 = 0, *v10 = 0, (unsigned int)kstrtoull(v23, 0, &v22))
    || (unsigned int)kstrtoull(v10 + 1, 0, &v21)
    || (unsigned int)kstrtoull(v12 + 1, 0, &v20)
    || (unsigned int)kstrtoint(v14 + 1, 0, &v19) )
  {
LABEL_31:
    if ( (unsigned int)__ratelimit(&iommu_debug_map_write__rs_14, "iommu_debug_map_write") )
    {
      v4 = &unk_CB1B;
      goto LABEL_18;
    }
LABEL_15:
    v5 = -22;
    goto LABEL_16;
  }
  mutex_lock(v6 + 56);
  v16 = *(_QWORD *)(v6 + 40);
  if ( !v16 )
  {
    if ( (unsigned int)__ratelimit(&iommu_debug_map_write__rs_10, "iommu_debug_map_write") )
      printk(&unk_CE32, "iommu_debug_map_write");
    mutex_unlock(v6 + 56);
    goto LABEL_15;
  }
  v17 = iommu_map(v16, v22, v21, v20, v19, 3264);
  if ( v17 )
  {
    v18 = v17;
    if ( (unsigned int)__ratelimit(&iommu_debug_map_write__rs_11, "iommu_debug_map_write") )
      printk(&unk_CF54, v18);
    v5 = -5;
  }
  else
  {
    printk(&unk_CA47, &v22);
  }
  mutex_unlock(v6 + 56);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v5;
}
