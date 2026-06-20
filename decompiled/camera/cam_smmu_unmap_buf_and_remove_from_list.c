__int64 __fastcall cam_smmu_unmap_buf_and_remove_from_list(_QWORD *a1, unsigned int a2)
{
  const void *v3; // x8
  const void *v4; // x7
  __int64 v5; // x8
  unsigned __int64 v6; // x21
  int v7; // w20
  char v8; // w23
  int v9; // w8
  __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 result; // x0
  _QWORD *v14; // x8
  _QWORD *v15; // x9
  __int64 v16; // x10
  __int64 v17; // x21
  __int64 v18; // x26
  int dma_map_attributes; // w0
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x9
  _QWORD v29[2]; // [xsp+18h] [xbp-28h] BYREF
  _QWORD v30[3]; // [xsp+28h] [xbp-18h] BYREF

  v30[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (const void *)*a1;
  v4 = (const void *)a1[2];
  v30[0] = 0;
  v30[1] = 0;
  v29[0] = 0;
  v29[1] = 0;
  if ( !v3 || !v4 || !a1[1] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_buf_and_remove_from_list",
      2973,
      "Error: Invalid params dev = %pK, table = %pK",
      *(const void **)(iommu_cb_set + 14280LL * a2),
      v4);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_buf_and_remove_from_list",
      2976,
      "Error:dma_buf = %pK, attach = %pK",
      (const void *)*a1,
      (const void *)a1[1]);
    result = 4294967274LL;
    goto LABEL_34;
  }
  v5 = iommu_cb_set + 14280LL * a2;
  _X10 = (unsigned __int64 *)(v5 + 8672);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v27 = __ldxr(_X10);
    v28 = v27 + 1;
  }
  while ( __stlxr(v28, _X10) );
  __dmb(0xBu);
  v6 = v5 + 56 * (v28 % 0x64);
  ktime_get_real_ts64(v6 + 8680);
  *(_BYTE *)(v6 + 8696) = 0;
  *(_DWORD *)(v6 + 8700) = *((_DWORD *)a1 + 18);
  *(_QWORD *)(v6 + 8704) = a1[10];
  *(_QWORD *)(v6 + 8712) = a1[6];
  *(_QWORD *)(v6 + 8720) = a1[11];
  v7 = *((_DWORD *)a1 + 7);
  *(_DWORD *)(v6 + 8728) = v7;
  v8 = debug_mdl;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    v17 = a1[6];
    v18 = a1[11];
    dma_map_attributes = cam_get_dma_map_attributes(a1[1]);
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v8 & 0x40,
      4,
      "cam_smmu_unmap_buf_and_remove_from_list",
      2986,
      "region_id=%d, paddr=0x%llx, len=%d, dma_map_attrs=%d",
      v7,
      v17,
      v18,
      dma_map_attributes);
  }
  if ( byte_3940D5 == 1 )
    ktime_get_real_ts64(v30);
  v9 = *((_DWORD *)a1 + 7);
  if ( v9 == 3 )
  {
    if ( *((_BYTE *)a1 + 104) == 1 )
      cam_update_dma_map_attributes(a1[1], 2);
    cam_compat_dmabuf_unmap_attach();
    v11 = iommu_cb_set + 14280LL * a2;
    v12 = 8600;
    goto LABEL_24;
  }
  if ( v9 == 1 )
  {
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_unmap_buf_and_remove_from_list",
        2994,
        "Removing SHARED buffer paddr = 0x%llx, len = %zu",
        a1[6],
        a1[11]);
    v10 = iommu_unmap(*(_QWORD *)(iommu_cb_set + 14280LL * a2 + 8), a1[6], a1[11]);
    if ( v10 != a1[11] )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_unmap_buf_and_remove_from_list",
        3003,
        "IOMMU unmap failed");
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_unmap_buf_and_remove_from_list",
        3006,
        "Unmapped = %zu, requested = %zu",
        v10,
        a1[11]);
      v10 = a1[11];
    }
    if ( (unsigned int)cam_smmu_free_iova(
                         a1[6],
                         v10,
                         *((unsigned int *)a1 + 32),
                         *(unsigned int *)(iommu_cb_set + 14280LL * a2 + 8480)) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_unmap_buf_and_remove_from_list",
        3014,
        "IOVA free failed");
    v11 = iommu_cb_set + 14280LL * a2;
    v12 = 8608;
LABEL_24:
    *(_QWORD *)(v11 + v12) -= a1[11];
  }
  dma_buf_detach(*a1, a1[1]);
  if ( byte_3940D5 == 1 )
    ktime_get_real_ts64(v29);
  v14 = (_QWORD *)a1[8];
  *a1 = 0;
  v15 = a1 + 7;
  if ( (_QWORD *)*v14 == a1 + 7 && (v16 = *v15, *(_QWORD **)(*v15 + 8LL) == v15) )
  {
    *(_QWORD *)(v16 + 8) = v14;
    *v14 = v16;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 + 7);
  }
  a1[7] = a1 + 7;
  a1[8] = v15;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(a1, 0);
  else
    kvfree(a1);
  result = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
