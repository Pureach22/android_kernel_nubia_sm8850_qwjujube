__int64 __fastcall cam_mem_mgr_request_mem(__int64 *a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int dma_buf; // w0
  unsigned int v6; // w19
  __int64 result; // x0
  const char *v8; // x5
  __int64 v9; // x4
  _QWORD *v10; // x6
  unsigned int v11; // w0
  unsigned int v12; // w24
  unsigned int v13; // w19
  int v14; // w21
  unsigned int slot; // w20
  char *v16; // x21
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  const void *v21; // x8
  char *v22; // x27
  __int64 v23; // x28
  __int64 v24; // x10
  unsigned int v25; // w21
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x9
  int v29; // w10
  int v30; // w9
  __int64 v31; // x10
  __int64 v32; // [xsp+28h] [xbp-58h]
  __int64 v33; // [xsp+30h] [xbp-50h]
  unsigned int v34; // [xsp+40h] [xbp-40h]
  int v35; // [xsp+44h] [xbp-3Ch]
  __int64 v36; // [xsp+50h] [xbp-30h] BYREF
  __int64 v37; // [xsp+58h] [xbp-28h]
  __int64 v38; // [xsp+60h] [xbp-20h] BYREF
  _QWORD *v39; // [xsp+68h] [xbp-18h] BYREF
  int v40; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+78h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = nullptr;
  v36 = 0;
  v37 = 0;
  if ( !cam_mem_mgr_state )
  {
    v8 = "failed. mem_mgr not initialized";
    v9 = 3122;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_request_mem",
      v9,
      v8);
    result = 4294967274LL;
    goto LABEL_11;
  }
  if ( !a1 || !a2 )
  {
    v8 = "Invalid params";
    v9 = 3127;
    goto LABEL_10;
  }
  v2 = *((_DWORD *)a1 + 5);
  if ( (v2 & 0xC01) == 0 )
  {
    v8 = "Invalid flags for request mem";
    v9 = 3134;
    goto LABEL_10;
  }
  dma_buf = cam_mem_util_get_dma_buf(*a1, v2, 1, &v39);
  if ( dma_buf )
  {
    v6 = dma_buf;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_request_mem",
      3142,
      "ION alloc failed for shared buffer");
    result = v6;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = v39;
  if ( !v39 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_request_mem",
      3145,
      "ION alloc returned NULL buffer");
    result = 0;
    goto LABEL_11;
  }
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_mgr_request_mem",
      3148,
      "Got dma_buf = %pK",
      v39);
    v10 = v39;
  }
  *((_DWORD *)a1 + 5) |= 8u;
  v11 = cam_mem_util_map_cpu_va(v10, &v38, &v36);
  if ( v11 )
  {
    v12 = v11;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_request_mem",
      3158,
      "Failed to get kernel vaddr");
LABEL_35:
    dma_buf_put(v39);
LABEL_36:
    result = v12;
    goto LABEL_11;
  }
  if ( !*((_DWORD *)a1 + 4) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_request_mem",
      3163,
      "Invalid SMMU handle");
    v12 = -22;
LABEL_34:
    cam_mem_util_unmap_cpu_va(v39, v38);
    goto LABEL_35;
  }
  if ( (*((_DWORD *)a1 + 5) & 0x801) == 1 )
    v13 = 3;
  else
    v13 = 1;
  v12 = cam_smmu_map_kernel_iova();
  if ( (v12 & 0x80000000) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_request_mem",
      3184,
      "SMMU mapping failed");
    goto LABEL_34;
  }
  v14 = *((_DWORD *)a1 + 4);
  slot = cam_mem_get_slot();
  if ( (slot & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_request_mem",
      3192,
      "Failed in getting mem slot, idx=%d",
      slot);
    cam_mem_mgr_print_tbl();
    cam_smmu_unmap_kernel_iova(*((unsigned int *)a1 + 4), v39, v13);
    v12 = -12;
    goto LABEL_34;
  }
  v35 = v14;
  v16 = (char *)&tbl + 296 * slot;
  v17 = mutex_lock(v16 + 72);
  if ( slot <= 0x800 )
  {
    v21 = v39;
    v22 = v16 + 64;
    *((_DWORD *)v16 + 30) = -1;
    *((_QWORD *)v16 + 8) = v21;
    *((_QWORD *)v16 + 16) = 0;
    *((_DWORD *)v16 + 38) = *((_DWORD *)a1 + 5);
    raw_spin_lock_bh(v16 + 352);
    v34 = slot | 0xFFFF0000;
    *((_DWORD *)v16 + 34) = slot | 0xFFFF0000;
    raw_spin_unlock_bh(v16 + 352);
    v23 = v37;
    v24 = *((_QWORD *)v16 + 22);
    v40 = 0;
    *((_QWORD *)v16 + 20) = v38;
    v25 = a1[2] & 0xFFFFFFF;
    v32 = v24;
    v33 = *a1;
    if ( (cam_mem_mgr_get_hwva_entry_idx(v25, &v40) & 1) != 0 )
    {
      v26 = v32 + 40LL * v40;
      *(_WORD *)(v26 + 32) = 257;
      *(_DWORD *)v26 = v25;
      *(_QWORD *)(v26 + 8) = v23;
      *(_QWORD *)(v26 + 16) = v33;
      *(_QWORD *)(v26 + 24) = 0;
    }
    v27 = *a1;
    v22[122] = 0;
    *((_DWORD *)v22 + 26) = 1;
    *((_QWORD *)v22 + 10) = v27;
    *((_DWORD *)v22 + 36) = 1;
    *((_DWORD *)v22 + 37) = 1;
    *((_DWORD *)v22 + 70) = 0;
    mutex_unlock((char *)&tbl + 296 * slot + 72);
    v29 = v37;
    v28 = v38;
    *(_DWORD *)(a2 + 16) = v34;
    *(_QWORD *)a2 = v28;
    *(_DWORD *)(a2 + 8) = v29;
    *(_DWORD *)(a2 + 12) = v35;
    v30 = debug_mdl;
    v31 = *a1;
    *(_DWORD *)(a2 + 32) = v13;
    *(_QWORD *)(a2 + 24) = v31;
    if ( (v30 & 0x400000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v30 & 0x400000LL,
        4,
        "cam_mem_mgr_request_mem",
        3228,
        "idx=%d, dmabuf=%pK, i_ino=%lu, flags=0x%x, mem_handle=0x%x",
        slot,
        v39,
        0,
        *((_DWORD *)a1 + 5),
        v34);
    goto LABEL_36;
  }
  __break(1u);
  return cam_mem_util_get_dma_buf(v17, v18, v19, v20);
}
