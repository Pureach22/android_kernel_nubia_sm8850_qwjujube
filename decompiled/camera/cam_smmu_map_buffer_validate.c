__int64 __fastcall cam_smmu_map_buffer_validate(
        unsigned __int64 *a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        __int64 *a5,
        unsigned __int64 *a6,
        int a7,
        char a8,
        __int64 a9)
{
  unsigned __int64 v14; // x0
  const void *v15; // x20
  const void **v16; // x0
  const void **v17; // x22
  __int64 v18; // x8
  __int64 v19; // x26
  unsigned int v20; // w0
  __int64 v21; // x4
  unsigned __int64 v22; // x0
  unsigned __int64 *v23; // x8
  unsigned __int64 v24; // x27
  unsigned int v25; // w24
  __int64 result; // x0
  unsigned __int64 v27; // x0
  __int64 *v28; // x9
  unsigned __int64 v29; // x26
  __int64 v30; // x10
  __int64 v31; // x11
  int v32; // w10
  __int64 v33; // x1
  __int64 v34; // x8
  __int64 v35; // x10
  __int64 v36; // x8
  _QWORD *v37; // x0
  unsigned __int64 *v38; // x9
  __int64 *v39; // x11
  unsigned int v40; // w8
  int v41; // w10
  _QWORD *v42; // x0
  unsigned __int64 *v43; // x24
  __int64 *v44; // x25
  int dma_map_attributes; // w0
  __int64 v46; // [xsp+20h] [xbp-70h]
  unsigned __int64 v47; // [xsp+28h] [xbp-68h]
  const void *v48; // [xsp+30h] [xbp-60h]
  __int64 v49; // [xsp+38h] [xbp-58h]
  unsigned int v50; // [xsp+40h] [xbp-50h]
  __int64 v54; // [xsp+60h] [xbp-30h] BYREF
  __int64 v55; // [xsp+68h] [xbp-28h]
  __int64 v56; // [xsp+70h] [xbp-20h] BYREF
  __int64 v57; // [xsp+78h] [xbp-18h]
  const void *v58[2]; // [xsp+80h] [xbp-10h] BYREF

  v58[1] = *(const void **)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v58[0] = nullptr;
  v55 = 0;
  v56 = 0;
  v54 = 0;
  if ( a1 && (unsigned __int64)a1 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( a9 )
    {
      if ( byte_3940D5 == 1 )
        ktime_get_real_ts64(&v56);
      v14 = dma_buf_attach(a1, *(_QWORD *)(iommu_cb_set + 14280LL * a2));
      v15 = (const void *)v14;
      if ( v14 && v14 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( a7 == 1 )
        {
          v16 = (const void **)cam_compat_dmabuf_map_attach();
          v17 = v16;
          if ( v16 && (unsigned __int64)v16 < 0xFFFFFFFFFFFFF001LL )
          {
            if ( *v16 )
            {
              v50 = a2;
              v18 = iommu_cb_set + 14280LL * a2;
              v19 = *(_QWORD *)(v18 + 8);
              if ( v19 )
              {
                v20 = cam_smmu_alloc_iova(*a6, a3, *(unsigned int *)(v18 + 8480), v58);
                if ( (v20 & 0x80000000) == 0 )
                {
                  if ( byte_3940F8 )
                    v21 = 7;
                  else
                    v21 = 3;
                  v22 = cam_iommu_map_sg(v19, (__int64)v58[0], (__int64)*v17, *((unsigned int *)v17 + 3), v21);
                  v23 = a6;
                  v24 = v22;
                  if ( (v22 & 0x8000000000000000LL) != 0 || v22 < *a6 )
                  {
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      64,
                      1,
                      "cam_smmu_map_buffer_validate",
                      2772,
                      "IOMMU mapping failed");
                    if ( (unsigned int)cam_smmu_free_iova(
                                         v58[0],
                                         v24,
                                         a3,
                                         *(unsigned int *)(iommu_cb_set + 14280LL * a2 + 8480)) )
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        64,
                        1,
                        "cam_smmu_map_buffer_validate",
                        2777,
                        "IOVA free failed");
                    v25 = -12;
                    goto LABEL_68;
                  }
                  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x40,
                      4,
                      "cam_smmu_map_buffer_validate",
                      2783,
                      "iommu_map_sg returned iova=%pK, size=%zu",
                      v58[0],
                      v22);
                    v23 = a6;
                  }
                  v28 = a5;
                  *a5 = (__int64)v58[0];
                  *v23 = v24;
                  v30 = iommu_cb_set + 14280LL * a2;
                  v29 = v24;
                  v31 = 8608;
LABEL_31:
                  *(_QWORD *)(v30 + v31) += v24;
                  v32 = debug_priority;
                  v33 = debug_mdl & 0x40;
                  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v33,
                      4,
                      "cam_smmu_map_buffer_validate",
                      2814,
                      "DMA buf: %pK, device: %pK, attach: %pK, table: %pK",
                      a1,
                      *(const void **)(iommu_cb_set + 14280LL * v50),
                      v15,
                      v17);
                    v28 = a5;
                    v23 = a6;
                    v32 = debug_priority;
                    v33 = debug_mdl & 0x40;
                    if ( (debug_mdl & 0x40) == 0 )
                      goto LABEL_36;
                  }
                  else if ( (debug_mdl & 0x40) == 0 )
                  {
                    goto LABEL_36;
                  }
                  if ( !v32 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v33,
                      4,
                      "cam_smmu_map_buffer_validate",
                      2817,
                      "table sgl: %pK, rc: %d, dma_address: 0x%x",
                      *v17,
                      0,
                      *((_QWORD *)*v17 + 2));
                    v28 = a5;
                    v23 = a6;
                    v32 = debug_priority;
                    v33 = debug_mdl & 0x40;
                  }
LABEL_36:
                  if ( v33 && !v32 )
                  {
                    v48 = v58[0];
                    v49 = *v28;
                    v46 = v33;
                    v47 = *v23;
                    dma_map_attributes = cam_get_dma_map_attributes((__int64)v15);
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v46,
                      4,
                      "cam_smmu_map_buffer_validate",
                      2821,
                      "iova=%pK, region_id=%d, paddr=0x%llx, len=%zu, dma_map_attrs=%d",
                      v48,
                      a7,
                      v49,
                      v47,
                      dma_map_attributes);
                  }
                  if ( byte_3940D5 == 1 )
                  {
                    ktime_get_real_ts64(&v54);
                    v34 = v55;
                    if ( v55 >= v57 )
                    {
                      v35 = v54 - v56;
                    }
                    else
                    {
                      v34 = v55 + 1000000000;
                      v35 = v54 + ~v56;
                    }
                    v36 = (unsigned __int128)((v34 - v57) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
                    trace_cam_log_event(
                      "SMMUMapProfile",
                      *a6,
                      (v36 >> 7) + ((unsigned __int64)v36 >> 63) + 1000000 * v35);
                  }
                  if ( mem_trace_en == 1 )
                    v37 = (_QWORD *)cam_mem_trace_alloc(136, 0xCC0u, 0, "cam_smmu_map_buffer_validate", 0xB0Fu);
                  else
                    v37 = (_QWORD *)_kvmalloc_node_noprof(136, 0, 3520, 0xFFFFFFFFLL);
                  v39 = a5;
                  v38 = a6;
                  v40 = a3;
                  v41 = a7;
                  *(_QWORD *)a9 = v37;
                  if ( v37 )
                  {
                    *v37 = a1;
                    *(_QWORD *)(*(_QWORD *)a9 + 8LL) = v15;
                    *(_QWORD *)(*(_QWORD *)a9 + 16LL) = v17;
                    *(_QWORD *)(*(_QWORD *)a9 + 48LL) = *a5;
                    *(_QWORD *)(*(_QWORD *)a9 + 88LL) = *a6;
                    *(_DWORD *)(*(_QWORD *)a9 + 24LL) = a4;
                    *(_DWORD *)(*(_QWORD *)a9 + 36LL) = 1;
                    *(_DWORD *)(*(_QWORD *)a9 + 28LL) = a7;
                    *(_DWORD *)(*(_QWORD *)a9 + 128LL) = a3;
                    if ( *a5 && *a6 )
                    {
                      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
                      {
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          debug_mdl & 0x40,
                          4,
                          "cam_smmu_map_buffer_validate",
                          2858,
                          "idx=%d, dma_buf=%pK, dev=%pOFfp, paddr=0x%llx, len=%zu",
                          a2,
                          a1,
                          *(const void **)(*(_QWORD *)(iommu_cb_set + 14280LL * v50) + 744LL),
                          *a5,
                          *a6);
                        if ( a7 != 1 )
                          goto LABEL_60;
                      }
                      else if ( a7 != 1 )
                      {
LABEL_60:
                        result = 0;
                        goto LABEL_70;
                      }
                      cam_compat_dmabuf_unmap_attach();
                      goto LABEL_60;
                    }
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      64,
                      1,
                      "cam_smmu_map_buffer_validate",
                      2848,
                      "Error: Space Allocation failed");
                    v42 = *(_QWORD **)a9;
                    if ( mem_trace_en == 1 )
                      cam_mem_trace_free(v42, 0);
                    else
                      kvfree(v42);
                    v39 = a5;
                    v38 = a6;
                    v40 = a3;
                    v41 = a7;
                    *(_QWORD *)a9 = 0;
                  }
                  if ( v41 == 1 )
                  {
                    v43 = v38;
                    v44 = v39;
                    cam_smmu_free_iova(v58[0], v29, v40, *(unsigned int *)(iommu_cb_set + 14280LL * v50 + 8480));
                    iommu_unmap(*(_QWORD *)(iommu_cb_set + 14280LL * v50 + 8), *v44, *v43);
                  }
                  v25 = -28;
                  goto LABEL_68;
                }
                v25 = v20;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  64,
                  1,
                  "cam_smmu_map_buffer_validate",
                  2762,
                  "IOVA alloc failed for shared memory, size=%zu, idx=%d, handle=%d",
                  *a6,
                  a2,
                  *(_DWORD *)(iommu_cb_set + 14280LL * a2 + 8480));
              }
              else
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  64,
                  1,
                  "cam_smmu_map_buffer_validate",
                  2752,
                  "CB has no domain set");
                v25 = 0;
              }
            }
            else
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                64,
                1,
                "cam_smmu_map_buffer_validate",
                2746,
                "Error: table sgl is null");
              v25 = -22;
            }
LABEL_68:
            cam_compat_dmabuf_unmap_attach();
            goto LABEL_69;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_map_buffer_validate",
            2740,
            "Error: dma map attachment failed");
          v25 = (unsigned int)v17;
        }
        else if ( a7 == 3 )
        {
          if ( (a8 & 1) == 0 )
            cam_update_dma_map_attributes(v14, 1);
          v27 = cam_compat_dmabuf_map_attach();
          v17 = (const void **)v27;
          if ( v27 && v27 < 0xFFFFFFFFFFFFF001LL )
          {
            v28 = a5;
            v29 = 0;
            v50 = a2;
            *a5 = *(_QWORD *)(*(_QWORD *)v27 + 16LL);
            v23 = a6;
            v24 = *a1;
            *a6 = *a1;
            v30 = iommu_cb_set + 14280LL * a2;
            v31 = 8600;
            goto LABEL_31;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_map_buffer_validate",
            2797,
            "Error: dma map attachment failed, size=%zu, rc %d dma_dir %d",
            *a1,
            v27,
            a4);
          v25 = (unsigned int)v17;
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_map_buffer_validate",
            2805,
            "Error: Wrong region id passed");
          v25 = -22;
        }
LABEL_69:
        dma_buf_detach(a1, v15);
        result = v25;
        goto LABEL_70;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_buffer_validate",
        2732,
        "Error: dma buf attach failed");
      result = (unsigned int)v15;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_buffer_validate",
        2722,
        "Error: mapping_info is invalid");
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_buffer_validate",
      2716,
      "Error: dma get buf failed. rc = %d",
      (_DWORD)a1);
    result = (unsigned int)a1;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
