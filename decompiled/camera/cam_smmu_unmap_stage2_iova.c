__int64 __fastcall cam_smmu_unmap_stage2_iova(unsigned int a1, unsigned int a2, __int64 a3, char a4)
{
  unsigned int v4; // w19
  __int64 v6; // x8
  __int64 v10; // x8
  __int64 *v11; // x21
  __int64 v12; // x9
  __int64 v13; // x7
  char v14; // w8
  int v15; // w9
  bool v16; // nf
  unsigned int v17; // w21
  const char *v19; // x5
  __int64 v20; // x4
  const void *v21; // x7
  __int64 v22; // x0
  __int64 **v23; // x8
  __int64 *v24; // x9
  __int64 *v25; // x0

  v4 = HIWORD(a1) & 0xFFF;
  if ( a1 == -1 || v4 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_stage2_iova",
      3809,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v4,
      a1);
    return 4294967274LL;
  }
  v6 = iommu_cb_set + 14280LL * v4;
  if ( (*(_BYTE *)(v6 + 80) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_stage2_iova",
      3815,
      "Error: can't unmap secure mem from non secure cb");
    return 4294967274LL;
  }
  mutex_lock(v6 + 8432);
  if ( *(_DWORD *)(iommu_cb_set + 14280LL * v4 + 8480) != (a1 & 0xFFFFFFF) )
  {
    v19 = "Error: hdl is not valid, table_hdl = %x, hdl = %x";
    v20 = 3823;
LABEL_22:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_stage2_iova",
      v20,
      v19);
    goto LABEL_23;
  }
  v10 = iommu_cb_set + 14280LL * v4;
  v11 = *(__int64 **)(v10 + 8400);
  v12 = v10 + 8400;
  v13 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 8) + 40LL) + 64LL);
  if ( v11 == (__int64 *)(v10 + 8400) )
  {
LABEL_20:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_find_mapping_by_sec_buf_idx",
      1489,
      "Error: Cannot find fd %d i_ino %lu by index %d",
      a2,
      v13,
      v4);
    goto LABEL_21;
  }
  v14 = a4;
  while ( *((_DWORD *)v11 + 4) != a2 || v11[3] != v13 )
  {
    v11 = (__int64 *)*v11;
    if ( v11 == (__int64 *)v12 )
      goto LABEL_20;
  }
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 0x40,
      4,
      "cam_smmu_find_mapping_by_sec_buf_idx",
      1484,
      "find ion_fd %d, i_ino %lu",
      a2);
    v14 = a4;
    if ( v11 != &_ksymtab_cam_cdm_get_iommu_handle )
      goto LABEL_13;
    goto LABEL_21;
  }
  if ( v11 == &_ksymtab_cam_cdm_get_iommu_handle )
  {
LABEL_21:
    v19 = "Error: Invalid params! idx = %d, fd = %d";
    v20 = 3833;
    goto LABEL_22;
  }
LABEL_13:
  v15 = *((_DWORD *)v11 - 5) - 1;
  v16 = *((_DWORD *)v11 - 5) - 2 < 0;
  *((_DWORD *)v11 - 5) = v15;
  if ( v16 == __OFSUB__(v15, 1) )
  {
    v17 = 0;
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_unmap_stage2_iova",
        3842,
        "idx: %d fd = %d map_count: %d",
        v4,
        a2,
        v15);
      v17 = 0;
    }
    goto LABEL_24;
  }
  *((_DWORD *)v11 - 5) = 0;
  if ( (v14 & 1) == 0 && *((_DWORD *)v11 - 4) >= 2u )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_stage2_iova",
      3851,
      "[SMMU_BT] Error: can't unmap buffer as it's still active, idx: %d, cb: %s, fd: 0x%x, ino: 0x%x, ref_count: %d",
      v4,
      *(const char **)(iommu_cb_set + 14280LL * v4 + 32),
      a2,
      v11[3],
      *((_DWORD *)v11 - 4));
    v17 = -1;
    goto LABEL_24;
  }
  v21 = (const void *)*(v11 - 4);
  if ( *(v11 - 6) )
  {
    if ( v21 )
    {
      v22 = *(v11 - 5);
      if ( v22 )
      {
        cam_update_dma_map_attributes(v22, 2);
        cam_compat_dmabuf_unmap_attach();
        dma_buf_detach(*(v11 - 6), *(v11 - 5));
        v23 = (__int64 **)v11[1];
        *(v11 - 6) = 0;
        if ( *v23 == v11 && (v24 = (__int64 *)*v11, *(__int64 **)(*v11 + 8) == v11) )
        {
          v24[1] = (__int64)v23;
          *v23 = v24;
        }
        else
        {
          _list_del_entry_valid_or_report(v11);
        }
        *v11 = (__int64)v11;
        v11[1] = (__int64)v11;
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_secure_unmap_buf_and_remove_from_list",
            3789,
            "unmap fd: %d, i_ino : %lu, idx : %d",
            *((_DWORD *)v11 + 4),
            v11[3],
            v4);
        v25 = v11 - 6;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v25, 0);
        else
          kvfree(v25);
        v17 = 0;
        goto LABEL_24;
      }
    }
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_secure_unmap_buf_and_remove_from_list",
    3769,
    "Error: Invalid params dev = %pK, table = %pK",
    *(const void **)(iommu_cb_set + 14280LL * v4),
    v21);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_secure_unmap_buf_and_remove_from_list",
    3772,
    "Error:dma_buf = %pK, attach = %pK\n",
    (const void *)*(v11 - 6),
    (const void *)*(v11 - 5));
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_unmap_stage2_iova",
    3859,
    "Error: unmap or remove list fail");
LABEL_23:
  v17 = -22;
LABEL_24:
  mutex_unlock(iommu_cb_set + 14280LL * v4 + 8432);
  return v17;
}
