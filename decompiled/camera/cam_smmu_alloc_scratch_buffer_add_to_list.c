__int64 __fastcall cam_smmu_alloc_scratch_buffer_add_to_list(
        unsigned int a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned int a4,
        _QWORD *a5)
{
  unsigned __int64 v5; // x25
  int v6; // w8
  __int64 v12; // x1
  void *v13; // x28
  __int64 v14; // x0
  __int64 v15; // x23
  unsigned int v16; // w8
  __int64 v17; // x1
  __int64 v18; // x0
  __int64 v19; // x25
  __int64 v20; // x0
  unsigned int v21; // w20
  __int64 v22; // x8
  __int64 v23; // x20
  unsigned int v24; // w10
  unsigned int v25; // w9
  unsigned int v26; // w8
  bool v27; // cc
  int v28; // w8
  unsigned __int64 v29; // x27
  __int64 v30; // x4
  unsigned int next_zero_area_off; // w26
  unsigned int v32; // w20
  __int64 v33; // x10
  __int64 v34; // x8
  __int64 v35; // x0
  unsigned int v36; // w8
  __int64 v37; // x1
  unsigned int v38; // w20
  char v39; // w8
  __int64 v40; // x8
  _QWORD *v41; // x2
  _QWORD *v42; // x1
  _QWORD *v43; // x8
  __int64 v44; // x22
  unsigned __int64 StatusReg; // x20
  __int64 v47; // x27
  __int64 v48; // x0
  _QWORD *v49; // [xsp+8h] [xbp-8h]

  v5 = a2 / a3;
  v6 = debug_priority;
  v12 = debug_mdl & 0x40;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12,
      4,
      "cam_smmu_alloc_scratch_buffer_add_to_list",
      3296,
      "nents = %lu, idx = %d, virt_len  = %zx",
      v5,
      a1,
      a2);
    v6 = debug_priority;
    v12 = debug_mdl & 0x40;
    if ( (debug_mdl & 0x40) == 0 )
      goto LABEL_6;
  }
  else if ( (debug_mdl & 0x40) == 0 )
  {
    goto LABEL_6;
  }
  if ( !v6 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12,
      4,
      "cam_smmu_alloc_scratch_buffer_add_to_list",
      3298,
      "phys_len = %zx, iommu_dir = %d, virt_addr = %pK",
      a3,
      a4,
      a5);
LABEL_6:
  v13 = &unk_2FD000;
  if ( mem_trace_en == 1 )
    v14 = cam_mem_trace_alloc(16, 0xCC0u, 0, "cam_smmu_alloc_scratch_buffer_add_to_list", 0xCE8u);
  else
    v14 = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
  v15 = v14;
  if ( !v14 )
    return (unsigned int)-12;
  if ( (sg_alloc_table(v14, (unsigned int)v5, 3264) & 0x80000000) != 0 )
  {
    v32 = -22;
    goto LABEL_57;
  }
  v16 = 64 - __clz((a3 - 1) >> 12);
  if ( a3 > 0x1000 )
    v17 = v16;
  else
    v17 = 0;
  v18 = _alloc_pages_noprof(3264, v17, 0, 0);
  v19 = v18;
  if ( !v18 )
  {
    v32 = -12;
LABEL_56:
    sg_free_table(v15);
LABEL_57:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v15, 0);
    else
      kvfree(v15);
    return v32;
  }
  if ( *(_DWORD *)(v15 + 8) )
  {
    if ( (v18 & 3) != 0 )
    {
      __break(0x800u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v47 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_smmu_alloc_scratch_buffer_add_to_list__alloc_tag_148;
      v35 = _kvmalloc_node_noprof(136, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v47;
      if ( !v35 )
        goto LABEL_62;
      goto LABEL_41;
    }
    v20 = *(_QWORD *)v15;
    v21 = 0;
    do
    {
      v22 = *(_QWORD *)v20;
      *(_DWORD *)(v20 + 8) = 0;
      *(_DWORD *)(v20 + 12) = a3;
      ++v21;
      *(_QWORD *)v20 = v22 & 3 | v19;
      v20 = sg_next();
    }
    while ( v21 < *(_DWORD *)(v15 + 8) );
  }
  v23 = iommu_cb_set + 14280LL * a1;
  v24 = *(_DWORD *)(v23 + 128);
  v13 = *(void **)(v23 + 8);
  v25 = 64 - __clz((a2 - 1) >> 12);
  if ( a2 - 1 >= 0x1000 )
    v26 = v25;
  else
    v26 = 0;
  v27 = v26 > v24;
  v49 = a5;
  v28 = -1 << (v26 - v24);
  v29 = (((a2 + 4095) >> 12) + (1 << v24) - 1) >> v24;
  if ( v27 )
    v30 = (unsigned int)~v28;
  else
    v30 = 0;
  next_zero_area_off = bitmap_find_next_zero_area_off(
                         *(_QWORD *)(v23 + 112),
                         *(_QWORD *)(v23 + 120),
                         0,
                         (unsigned int)(v29 + 1),
                         v30,
                         0);
  if ( *(_QWORD *)(v23 + 120) < (unsigned __int64)next_zero_area_off )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_alloc_scratch_buffer_add_to_list",
      3335,
      "Could not find valid iova for scratch buffer");
LABEL_27:
    v32 = -12;
LABEL_36:
    v36 = 64 - __clz((a3 - 1) >> 12);
    if ( a3 > 0x1000 )
      v37 = v36;
    else
      v37 = 0;
    _free_pages(v19, v37);
    goto LABEL_56;
  }
  _bitmap_set(*(_QWORD *)(v23 + 112), next_zero_area_off, (unsigned int)(v29 + 1));
  v33 = *(_QWORD *)(v23 + 136);
  v34 = next_zero_area_off << (*(_DWORD *)(v23 + 128) + 12);
  if ( byte_3940F8 )
    a4 |= 4u;
  a5 = (_QWORD *)(v33 + v34);
  if ( cam_iommu_map_sg((__int64)v13, v33 + v34, *(_QWORD *)v15, *(unsigned int *)(v15 + 8), a4) != a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_alloc_scratch_buffer_add_to_list",
      3347,
      "iommu_map_sg() failed");
    v32 = 0;
    goto LABEL_36;
  }
  if ( mem_trace_en == 1 )
  {
    v35 = cam_mem_trace_alloc(136, 0xCC0u, 0, "cam_smmu_alloc_scratch_buffer_add_to_list", 0xD18u);
    if ( !v35 )
    {
LABEL_62:
      v48 = iommu_unmap(v13, a5, a2);
      if ( v48 != a2 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_alloc_scratch_buffer_add_to_list",
          3386,
          "Unmapped only %zx instead of %zx",
          v48,
          a2);
      goto LABEL_27;
    }
  }
  else
  {
    v35 = _kvmalloc_node_noprof(136, 0, 3520, 0xFFFFFFFFLL);
    if ( !v35 )
      goto LABEL_62;
  }
LABEL_41:
  *(_QWORD *)v35 = 0;
  *(_QWORD *)(v35 + 8) = 0;
  v38 = a1;
  *(_QWORD *)(v35 + 16) = v15;
  *(_DWORD *)(v35 + 72) = -559038737;
  *(_DWORD *)(v35 + 32) = a4;
  *(_DWORD *)(v35 + 36) = 1;
  v39 = debug_mdl;
  *(_QWORD *)(v35 + 48) = a5;
  *(_QWORD *)(v35 + 80) = 0;
  *(_QWORD *)(v35 + 88) = a2;
  *(_QWORD *)(v35 + 96) = a3;
  *(_DWORD *)(v35 + 28) = 2;
  if ( (v39 & 0x40) != 0 && !debug_priority )
  {
    v44 = v35;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v39 & 0x40,
      4,
      "cam_smmu_alloc_scratch_buffer_add_to_list",
      3372,
      "paddr = %pK, len = %zx, phys_len = %zx",
      a5,
      a2,
      a3);
    v35 = v44;
  }
  v40 = iommu_cb_set + 14280LL * v38;
  v41 = *(_QWORD **)(v40 + 8400);
  v42 = (_QWORD *)(v40 + 8400);
  v43 = (_QWORD *)(v35 + 56);
  if ( (_QWORD *)v41[1] != v42 || v43 == v42 || v41 == v43 )
  {
    _list_add_valid_or_report(v35 + 56);
  }
  else
  {
    v41[1] = v43;
    *(_QWORD *)(v35 + 56) = v41;
    *(_QWORD *)(v35 + 64) = v42;
    *v42 = v43;
  }
  v32 = 0;
  *v49 = a5;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40,
      4,
      "cam_smmu_alloc_scratch_buffer_add_to_list",
      3379,
      "mapped virtual address = %lx",
      a5);
    return 0;
  }
  return v32;
}
