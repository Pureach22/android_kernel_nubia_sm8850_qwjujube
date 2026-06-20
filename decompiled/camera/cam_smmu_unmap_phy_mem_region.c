__int64 __fastcall cam_smmu_unmap_phy_mem_region(int a1, int a2, int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x21
  __int64 v5; // x6
  unsigned int v6; // w22
  __int64 result; // x0
  long double v10; // q0
  long double v11; // q1
  long double v12; // q2
  _BYTE *v13; // x25
  _QWORD *v14; // x23
  _DWORD *v15; // x26
  unsigned int v16; // w22
  const char *v17; // x5
  __int64 v18; // x4
  __int64 v19; // x20
  __int64 v20; // x0
  unsigned __int64 v27; // x10
  _QWORD *v28; // [xsp+18h] [xbp-38h] BYREF
  _BYTE *v29; // [xsp+20h] [xbp-30h] BYREF
  bool v30; // [xsp+2Ch] [xbp-24h] BYREF
  _QWORD *v31; // [xsp+30h] [xbp-20h] BYREF
  _DWORD *v32; // [xsp+38h] [xbp-18h] BYREF
  unsigned int v33; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+48h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v30 = 0;
  v28 = nullptr;
  v29 = nullptr;
  if ( a1 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_phy_mem_region",
      2115,
      "Error: Invalid handle");
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  v3 = HIWORD(a1) & 0xFFF;
  if ( v3 >= dword_394060 )
  {
    v17 = "Error: handle or index invalid. idx = %d hdl = %x";
    v18 = 2124;
    v5 = v3;
LABEL_16:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_phy_mem_region",
      v18,
      v17,
      v5,
      (unsigned int)a1);
    goto LABEL_17;
  }
  v4 = iommu_cb_set + 14280LL * v3;
  v5 = *(unsigned int *)(v4 + 8480);
  if ( (_DWORD)v5 != (a1 & 0xFFFFFFF) )
  {
    v17 = "Error: hdl is not valid, table_hdl = %x, hdl = %x";
    v18 = 2132;
    goto LABEL_16;
  }
  v6 = a1 >> 28;
  result = cam_smmu_get_multiregion_client_dev_idx(iommu_cb_set + 14280LL * v3, a1 >> 28, a2, &v33);
  if ( (_DWORD)result )
    goto LABEL_18;
  v31 = nullptr;
  v32 = nullptr;
  result = cam_smmu_retrieve_region_info(v4, a2, a3, v33, &v30, &v32, &v31, &v29, v10, v11, v12, &v28);
  if ( (_DWORD)result )
    goto LABEL_18;
  if ( !v30 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_phy_mem_region",
      2152,
      "region: %u not supported for this SMMU handle cb: %s",
      a2,
      *(const char **)(v4 + 32));
    goto LABEL_17;
  }
  mutex_lock(iommu_cb_set + 14280LL * v3 + 8432);
  v13 = v29;
  if ( (*v29 & 1) != 0 )
  {
    v14 = v31;
    v15 = v32;
    --*v32;
    _X9 = &v14[v6 >> 6];
    __asm { PRFM            #0x11, [X9] }
    do
      v27 = __ldxr(_X9);
    while ( __stxr(v27 & ~(1LL << v6), _X9) );
    if ( (int)*v15 < 1 )
    {
      v19 = v28[1];
      v20 = iommu_unmap(*(_QWORD *)(v4 + 8), *v28, v19);
      if ( v20 == v19 )
      {
        v16 = 0;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_unmap_phy_mem_region",
          2183,
          "Only %zu unmapped out of total %zu",
          v20,
          v19);
        v16 = -22;
      }
      *v13 = 0;
      *v15 = 0;
      *v14 = 0;
    }
    else
    {
      v16 = 0;
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_unmap_phy_mem_region",
          2171,
          "Mapping for region: %u on cb: %s still in use refcnt: %d mapping_mask: 0x%x",
          a2,
          *(const char **)(v4 + 32),
          *v15,
          *v14);
        v16 = 0;
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_phy_mem_region",
      2161,
      "Trying to free region: %u that is not allocated on cb: %s",
      a2,
      *(const char **)(v4 + 32));
    v16 = -12;
  }
  mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
  result = v16;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
