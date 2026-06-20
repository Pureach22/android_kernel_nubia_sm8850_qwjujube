__int64 __fastcall cam_smmu_reserve_buf_region(
        unsigned int a1,
        int a2,
        unsigned __int64 a3,
        _QWORD *a4,
        unsigned __int64 *a5)
{
  unsigned int v5; // w6
  __int64 v7; // x19
  __int64 result; // x0
  __int64 v12; // x0
  _BYTE *v13; // x27
  __int64 *v14; // x26
  unsigned __int64 *v15; // x24
  unsigned __int64 v16; // x8
  const char *v17; // x5
  __int64 v18; // x4
  unsigned __int64 subregion; // x0
  unsigned __int64 v20; // x0
  int v21; // w20
  unsigned __int64 v22; // x0
  __int64 v23; // x4
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x7
  unsigned int v26; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v5 = HIWORD(a2) & 0xFFF;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  if ( v5 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_reserve_buf_region",
      2414,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v5,
      a2);
    goto LABEL_11;
  }
  v7 = iommu_cb_set + 14280LL * v5;
  result = cam_smmu_get_multiregion_client_dev_idx(v7, a2 >> 28, a1, &v26);
  if ( (_DWORD)result )
    goto LABEL_12;
  if ( a1 == 4 )
  {
    if ( *(_BYTE *)(v7 + 85) )
      goto LABEL_5;
    goto LABEL_15;
  }
  if ( a1 != 6 )
  {
    v17 = "Region not supported for reserving %d";
    v18 = 2430;
    goto LABEL_17;
  }
  if ( !*(_BYTE *)(v7 + 86) )
  {
LABEL_15:
    v17 = "Reserve for region %d not supported";
    v18 = 2436;
LABEL_17:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_reserve_buf_region",
      v18,
      v17,
      a1);
    goto LABEL_11;
  }
LABEL_5:
  v12 = mutex_lock(v7 + 8432);
  if ( a1 == 4 )
  {
    v13 = (_BYTE *)(v7 + 104);
    v14 = (__int64 *)(v7 + 224);
    v15 = (unsigned __int64 *)(v7 + 264);
LABEL_7:
    v16 = a3;
LABEL_8:
    if ( *v13 != 1 )
    {
      if ( v16 && v16 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_reserve_buf_region",
            2494,
            "Map region=%d iova=0x%x len=0x%x",
            a1,
            *v14,
            v14[1]);
          v16 = a3;
        }
        *v15 = v16;
        v20 = dma_buf_attach(v16, *(_QWORD *)v7);
        v21 = v20;
        v15[1] = v20;
        if ( v20 && v20 < 0xFFFFFFFFFFFFF001LL )
        {
          v22 = cam_compat_dmabuf_map_attach();
          v21 = v22;
          v15[2] = v22;
          if ( v22 && v22 < 0xFFFFFFFFFFFFF001LL )
          {
            if ( byte_3940F8 )
              v23 = 7;
            else
              v23 = 3;
            v24 = cam_iommu_map_sg(*(_QWORD *)(v7 + 8), *v14, *(_QWORD *)v22, *(unsigned int *)(v22 + 12), v23);
            v25 = v14[1];
            if ( (v24 & 0x8000000000000000LL) == 0 && v25 >= v24 )
            {
              *a4 = *(unsigned int *)v14;
              *a5 = v24;
              *v13 = 1;
              mutex_unlock(v7 + 8432);
              result = 0;
              goto LABEL_12;
            }
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_reserve_buf_region",
              2525,
              "IOMMU mapping failed for size=%zu available iova_len=%zu",
              v24,
              v25);
            cam_compat_dmabuf_unmap_attach();
            v21 = -22;
          }
          else
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_reserve_buf_region",
              2509,
              "Error: dma buf map attachment failed");
          }
          dma_buf_detach(*v15, v15[1]);
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_reserve_buf_region",
            2501,
            "Error: dma buf attach failed");
        }
        dma_buf_put(*v15);
        LODWORD(a3) = v21;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_reserve_buf_region",
          2489,
          "Error: dma get buf failed. rc = %d",
          v16);
      }
      mutex_unlock(v7 + 8432);
      result = (unsigned int)a3;
      goto LABEL_12;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_reserve_buf_region",
      2480,
      "Trying to allocate twice for region %d",
      a1);
    mutex_unlock(v7 + 8432);
    result = 4294967284LL;
LABEL_12:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v26 < 3 )
  {
    if ( *(_BYTE *)(v7 + 672LL * v26 + 5017) != 1 )
    {
      v16 = a3;
      v14 = (__int64 *)(v7 + 672LL * v26 + 4936);
      v15 = (unsigned __int64 *)(v7 + 672LL * v26 + 4976);
      v13 = (_BYTE *)(v7 + 672LL * v26 + 5016);
      goto LABEL_8;
    }
    subregion = cam_smmu_find_subregion(0);
    if ( subregion && subregion <= 0xFFFFFFFFFFFFF000LL )
    {
      v14 = (__int64 *)(subregion + 8);
      v15 = (unsigned __int64 *)(subregion + 48);
      v13 = (_BYTE *)(subregion + 88);
      goto LABEL_7;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_reserve_buf_region",
      2459,
      "Failed to find free uncached subregion on cb: %s",
      *(const char **)(v7 + 32));
    mutex_unlock(v7 + 8432);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  __break(0x5512u);
  return cam_smmu_find_subregion(v12);
}
