__int64 __fastcall cam_smmu_map_stage2_buffer_and_add_to_list(
        unsigned int a1,
        int a2,
        int a3,
        __int64 *a4,
        _QWORD *a5,
        __int64 a6,
        _QWORD *a7)
{
  unsigned __int64 v14; // x0
  __int64 v15; // x21
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x27
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x9
  __int64 v22; // x8
  _QWORD *v23; // x2
  _QWORD *v24; // x1
  _QWORD *v25; // x8
  __int64 v26; // x22

  *a4 = 0;
  *a5 = 0;
  v14 = dma_buf_attach(a6, *(_QWORD *)(iommu_cb_set + 14280LL * a1));
  v15 = v14;
  if ( v14 && v14 < 0xFFFFFFFFFFFFF001LL )
  {
    cam_update_dma_map_attributes(v14, 2);
    if ( qword_3940E8 == 0x500000002LL )
      cam_update_dma_map_attributes(v15, 4);
    v16 = cam_compat_dmabuf_map_attach();
    v17 = v16;
    if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_stage2_buffer_and_add_to_list",
        3634,
        "Error: dma buf map attachment failed");
LABEL_25:
      dma_buf_detach(a6, v15);
      LODWORD(v15) = v17;
      return (unsigned int)v15;
    }
    v18 = *(_QWORD *)v16;
    if ( qword_3940E8 == 0x500000002LL )
      v19 = *(_QWORD *)(v18 + 16);
    else
      v19 = *(unsigned int *)(v18 + 8)
          + (((*(_QWORD *)v18 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
          + 0x5000000000LL;
    *a4 = v19;
    *a5 = *(unsigned int *)(*(_QWORD *)v16 + 24LL);
    if ( mem_trace_en == 1 )
    {
      v20 = cam_mem_trace_alloc(88, 0xCC0u, 0, "cam_smmu_map_stage2_buffer_and_add_to_list", 0xE41u);
      if ( !v20 )
        goto LABEL_24;
    }
    else
    {
      v20 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
      if ( !v20 )
      {
LABEL_24:
        cam_compat_dmabuf_unmap_attach();
        LODWORD(v17) = -12;
        goto LABEL_25;
      }
    }
    *(_DWORD *)(v20 + 64) = a2;
    *(_QWORD *)(v20 + 72) = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a6 + 8) + 40LL) + 64LL);
    *(_QWORD *)(v20 + 40) = *a4;
    v21 = *a5;
    *(_DWORD *)(v20 + 24) = a3;
    *(_DWORD *)(v20 + 28) = 1;
    *(_QWORD *)v20 = a6;
    *(_QWORD *)(v20 + 8) = v15;
    *(_QWORD *)(v20 + 16) = v17;
    *(_QWORD *)(v20 + 80) = v21;
    *(_DWORD *)(v20 + 32) = 1;
    *a7 = v20 + 32;
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    {
      v26 = v20;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_map_stage2_buffer_and_add_to_list",
        3671,
        "idx=%d, ion_fd=%d, i_ino=%lu, dev=%pOFfp, paddr=0x%llx, len=%zu",
        a1,
        a2,
        *(_QWORD *)(v20 + 72),
        *(const void **)(*(_QWORD *)(iommu_cb_set + 14280LL * a1) + 744LL),
        *a4,
        *a5);
      v20 = v26;
    }
    v22 = iommu_cb_set + 14280LL * a1;
    v23 = *(_QWORD **)(v22 + 8400);
    v24 = (_QWORD *)(v22 + 8400);
    v25 = (_QWORD *)(v20 + 48);
    if ( (_QWORD *)v23[1] != v24 || v25 == v24 || v23 == v25 )
    {
      _list_add_valid_or_report(v20 + 48);
      LODWORD(v15) = 0;
    }
    else
    {
      LODWORD(v15) = 0;
      v23[1] = v25;
      *(_QWORD *)(v20 + 48) = v23;
      *(_QWORD *)(v20 + 56) = v24;
      *v24 = v25;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_stage2_buffer_and_add_to_list",
      3619,
      "Error: dma buf attach failed, idx=%d, ion_fd=%d",
      a1,
      a2);
  }
  return (unsigned int)v15;
}
