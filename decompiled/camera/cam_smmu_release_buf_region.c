__int64 __fastcall cam_smmu_release_buf_region(unsigned int a1, int a2)
{
  unsigned int v2; // w6
  __int64 v4; // x19
  __int64 v5; // x0
  _BYTE *v6; // x22
  _QWORD *v7; // x24
  _QWORD *v8; // x23
  __int64 v9; // x0
  __int64 result; // x0
  const char *v11; // x5
  __int64 v12; // x4
  _DWORD *subregion; // x0
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v2 = HIWORD(a2) & 0xFFF;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( v2 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_release_buf_region",
      2570,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v2,
      a2);
    goto LABEL_12;
  }
  v4 = iommu_cb_set + 14280LL * v2;
  if ( (unsigned int)cam_smmu_get_multiregion_client_dev_idx(v4, a2 >> 28, a1, &v14) )
  {
LABEL_12:
    result = 4294967274LL;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 == 4 )
  {
    if ( *(_BYTE *)(v4 + 85) )
      goto LABEL_5;
    goto LABEL_16;
  }
  if ( a1 != 6 )
  {
    v11 = "Region not supported for release %d";
    v12 = 2585;
    goto LABEL_18;
  }
  if ( !*(_BYTE *)(v4 + 86) )
  {
LABEL_16:
    v11 = "region: %d not supported";
    v12 = 2590;
LABEL_18:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_release_buf_region",
      v12,
      v11,
      a1);
    goto LABEL_12;
  }
LABEL_5:
  v5 = mutex_lock(v4 + 8432);
  if ( a1 == 4 )
  {
    v6 = (_BYTE *)(v4 + 104);
    v7 = (_QWORD *)(v4 + 224);
    v8 = (_QWORD *)(v4 + 264);
    goto LABEL_7;
  }
  if ( v14 < 3 )
  {
    if ( *(_BYTE *)(v4 + 672LL * v14 + 5017) != 1 )
    {
      v6 = (_BYTE *)(v4 + 672LL * v14 + 5016);
      v7 = (_QWORD *)(v4 + 672LL * v14 + 4936);
      v8 = (_QWORD *)(v4 + 672LL * v14 + 4976);
LABEL_7:
      if ( (*v6 & 1) != 0 )
      {
        v9 = iommu_unmap(*(_QWORD *)(v4 + 8), *v7, v7[1]);
        if ( v9 != v7[1] )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_release_buf_region",
            2644,
            "Failed: Unmapped = %zu, requested = %zu",
            v9);
        cam_compat_dmabuf_unmap_attach();
        dma_buf_detach(*v8, v8[1]);
        *v6 = 0;
        mutex_unlock(v4 + 8432);
        result = 0;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_release_buf_region",
          2633,
          "Trying to release freed region cb: %s region: %d",
          *(const char **)(v4 + 32),
          a1);
        mutex_unlock(v4 + 8432);
        result = 4294967284LL;
      }
      goto LABEL_13;
    }
    subregion = cam_smmu_find_subregion(0, (_DWORD *)(v4 + 672LL * v14 + 4360));
    if ( subregion && (unsigned __int64)subregion <= 0xFFFFFFFFFFFFF000LL )
    {
      v6 = subregion + 22;
      v7 = subregion + 2;
      v8 = subregion + 12;
      goto LABEL_7;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_release_buf_region",
      2610,
      "Failed to find uncached subregion on cb: %s",
      *(const char **)(v4 + 32));
    mutex_unlock(v4 + 8432);
    goto LABEL_12;
  }
  __break(0x5512u);
  return cam_smmu_buffer_tracker_putref(v5);
}
