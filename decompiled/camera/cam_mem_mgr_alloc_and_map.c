__int64 __fastcall cam_mem_mgr_alloc_and_map(__int64 a1)
{
  const char *v2; // x5
  __int64 v3; // x4
  __int64 v4; // x6
  __int64 v5; // x20
  int v6; // w8
  int v7; // w6
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v10; // x6
  const char *v11; // x5
  __int64 v12; // x4
  __int64 result; // x0
  unsigned int v14; // w0
  __int64 v15; // x7
  int v16; // w8
  int v17; // w9
  unsigned int v18; // w19
  __int64 v19; // x0
  unsigned int slot; // w20
  size_t v21; // x0
  int v22; // w22
  int v23; // w8
  int v24; // w23
  unsigned int v25; // w0
  unsigned int v26; // w21
  __int64 v27; // x0
  __int64 v28; // x0
  char *v29; // x24
  __int64 v30; // x8
  unsigned int v31; // w9
  int v32; // w8
  unsigned int v33; // w0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x10
  unsigned __int64 v37; // x2
  int v38; // w8
  int v39; // w9
  int v40; // w6
  __int64 v41; // x0
  __int64 v42; // x1
  __int64 v43; // x2
  __int64 v44; // x3
  __int64 v45; // x4
  __int64 v46; // [xsp+38h] [xbp-38h] BYREF
  char v47[8]; // [xsp+40h] [xbp-30h] BYREF
  __int64 v48; // [xsp+48h] [xbp-28h] BYREF
  __int64 v49; // [xsp+50h] [xbp-20h]
  int v50; // [xsp+5Ch] [xbp-14h] BYREF
  _QWORD v51[2]; // [xsp+60h] [xbp-10h] BYREF

  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 0;
  v50 = -1;
  v48 = 0;
  v46 = 0;
  if ( !cam_mem_mgr_state )
  {
    v2 = "failed. mem_mgr not initialized";
    v3 = 2182;
    goto LABEL_27;
  }
  if ( !a1 )
  {
    v2 = " Invalid argument";
    v3 = 2187;
    goto LABEL_27;
  }
  if ( *(_DWORD *)(a1 + 4) > (unsigned int)dword_391BA8 )
  {
    v2 = "Num of mmu hdl %d exceeded maximum(%d)";
    v3 = 2193;
LABEL_27:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_alloc_and_map",
      v3,
      v2);
    result = 4294967274LL;
LABEL_28:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v4 = *(_QWORD *)(a1 + 72);
  v49 = v4;
  if ( byte_391BB9 == 1 && (*(_BYTE *)(a1 + 225) & 8) != 0 )
  {
    v5 = v4 + 4096;
    v49 = v4 + 4096;
    if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400000,
        4,
        "cam_mem_mgr_alloc_and_map",
        2203,
        "Pad 4k size, actual %llu, allocating %zu",
        v4,
        v4 + 4096);
  }
  else
  {
    v5 = v4;
  }
  if ( (cam_presil_mode_enabled() & 1) != 0 )
  {
    v6 = debug_mdl;
    v7 = *(_DWORD *)(a1 + 224) | 8;
    *(_DWORD *)(a1 + 224) = v7;
    if ( (v6 & 0x400000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v6 & 0x400000LL,
        4,
        "cam_mem_mgr_alloc_and_map",
        2208,
        "PRESIL BUF add KMD_ACCESS, need for bufcopy 0x%08x",
        v7);
  }
  if ( *(_DWORD *)(a1 + 4) >= 0x11u )
  {
    v8 = "Num of mmu hdl exceeded maximum(%d)";
    v9 = 2017;
    v10 = 16;
LABEL_16:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_check_alloc_flags",
      v9,
      v8,
      v10);
LABEL_26:
    v2 = "Invalid flags: flags = 0x%X, rc=%d";
    v3 = 2213;
    goto LABEL_27;
  }
  v10 = *(unsigned int *)(a1 + 224);
  if ( (*(_DWORD *)(a1 + 224) & 0x28) == 0x28 )
  {
    v11 = "Kernel mapping in secure mode not allowed";
    v12 = 2023;
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_check_alloc_flags",
      v12,
      v11);
    goto LABEL_26;
  }
  if ( (v10 & 0x8000) != 0 && (v10 & 0x28) != 0 )
  {
    v11 = "Kernel mapping and secure mode not allowed in no pixel mode";
    v12 = 2031;
    goto LABEL_25;
  }
  if ( (v10 & 0x20000) != 0 && (v10 & 0x18868) != 0 )
  {
    v8 = "UBWC-P buffer not supported with this combinatation of flags 0x%x";
    v9 = 2044;
    goto LABEL_16;
  }
  v14 = cam_mem_util_buffer_alloc(v5, (unsigned int)v10, v51, &v50, &v46);
  if ( v14 )
  {
    v15 = *(_QWORD *)(a1 + 80);
    v16 = *(_DWORD *)(a1 + 224);
    v17 = *(_DWORD *)(a1 + 4);
    v18 = v14;
    v19 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_mgr_alloc_and_map",
            2222,
            "Ion Alloc failed, len=%llu, align=%llu, flags=0x%x, num_hdl=%d",
            v5,
            v15,
            v16,
            v17);
    cam_mem_mgr_print_tbl(v19);
LABEL_61:
    result = v18;
    goto LABEL_28;
  }
  if ( !v51[0] )
  {
    v28 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_mgr_alloc_and_map",
            2228,
            "Ion Alloc return NULL dmabuf! fd=%d, i_ino=%lu, len=%d",
            v50,
            v46,
            v5);
    cam_mem_mgr_print_tbl(v28);
    result = 0;
    goto LABEL_28;
  }
  slot = cam_mem_get_slot();
  if ( (slot & 0x80000000) != 0 )
  {
    v34 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_mgr_alloc_and_map",
            2235,
            "Failed in getting mem slot, idx=%d",
            slot);
    cam_mem_mgr_print_tbl(v34);
    v18 = -12;
    goto LABEL_60;
  }
  if ( cam_dma_buf_set_name(v51[0], a1 + 96) )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_alloc_and_map",
      2242,
      "set dma buffer name(%s) failed",
      (const char *)(a1 + 96));
  v21 = *(unsigned int *)(a1 + 224);
  v22 = v50;
  if ( (v21 & 0x821) != 0 )
  {
    v23 = ((int)((_DWORD)v21 << 31) >> 31) & 3;
    if ( (v21 & 0x800) != 0 )
      v23 = 1;
    if ( (v21 & 0x20) != 0 )
      v24 = 3;
    else
      v24 = v23;
    if ( slot > 0x7FF )
      goto LABEL_75;
    v25 = cam_mem_util_map_hw_va(v21);
    if ( v25 )
    {
      v26 = v25;
      v27 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x400000,
              1,
              "cam_mem_mgr_alloc_and_map",
              2274,
              "Failed in map_hw_va len=%llu, flags=0x%x, fd=%d, region=%d, num_hdl=%d, rc=%d",
              v49,
              *(_DWORD *)(a1 + 224),
              v22,
              v24,
              *(_DWORD *)(a1 + 4),
              v25);
      v18 = v26;
      if ( v26 == -114 )
      {
        if ( *(_QWORD *)v51[0] == v49 )
          v18 = -114;
        else
          v18 = -53;
        cam_mem_mgr_print_tbl(v27);
      }
      goto LABEL_58;
    }
  }
  v29 = (char *)&tbl + 296 * slot;
  v21 = mutex_lock(v29 + 72);
  if ( slot > 0x800uLL )
  {
LABEL_75:
    __break(1u);
LABEL_76:
    _fortify_panic(2, 128, v21 + 1);
    goto LABEL_77;
  }
  v30 = v46;
  v31 = slot + (v22 << 16);
  *((_DWORD *)v29 + 30) = v22;
  *((_QWORD *)v29 + 8) = 0;
  *((_QWORD *)v29 + 16) = v30;
  LODWORD(v30) = *(_DWORD *)(a1 + 224);
  *((_DWORD *)v29 + 34) = v31;
  v29[187] = 1;
  *((_DWORD *)v29 + 38) = v30;
  v32 = *(_DWORD *)(a1 + 224);
  if ( (v32 & 0x20) != 0 )
  {
    *((_DWORD *)v29 + 34) = v31 | 0x8000;
    v32 = *(_DWORD *)(a1 + 224);
  }
  if ( (v32 & 8) != 0 )
  {
    v33 = cam_mem_util_map_cpu_va(v51[0], &v48, v47);
    if ( v33 )
    {
      v18 = v33;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_mgr_alloc_and_map",
        2298,
        "dmabuf: %pK mapping failed: %d",
        v51[0]);
      mutex_unlock(v29 + 72);
LABEL_58:
      cam_mem_put_slot(slot);
LABEL_60:
      dma_buf_put(v51[0]);
      goto LABEL_61;
    }
    v32 = *(_DWORD *)(a1 + 224);
  }
  if ( (v32 & 0x4000) != 0 )
    qword_391BA0 = slot;
  v35 = v48;
  v36 = v49;
  *((_QWORD *)v29 + 8) = v51[0];
  *((_QWORD *)v29 + 20) = v35;
  *((_QWORD *)v29 + 18) = v36;
  LODWORD(v35) = *(_DWORD *)(a1 + 4);
  v29[186] = 0;
  *((_DWORD *)v29 + 42) = v35;
  if ( (*(_BYTE *)(a1 + 224) & 8) != 0 )
    *((_DWORD *)v29 + 52) = 1;
  *((_DWORD *)v29 + 87) = 1;
  *((_DWORD *)v29 + 53) = 0;
  v21 = strnlen((const char *)(a1 + 96), 0x80u);
  if ( v21 >= 0x81 )
    goto LABEL_76;
  if ( v21 == 128 )
    v37 = 128;
  else
    v37 = v21 + 1;
  if ( v37 < 0x81 )
  {
    sized_strscpy(v29 + 216, a1 + 96);
    *((_DWORD *)v29 + 86) = 0;
    mutex_unlock(v29 + 72);
    v38 = *((_DWORD *)v29 + 34);
    result = 0;
    v39 = debug_mdl;
    *(_DWORD *)(a1 + 256) = v38;
    v40 = *((_DWORD *)v29 + 30);
    *(_QWORD *)(a1 + 264) = 0;
    *(_DWORD *)(a1 + 260) = v40;
    if ( (v39 & 0x400000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v39 & 0x400000LL,
        4,
        "cam_mem_mgr_alloc_and_map",
        2330,
        "fd=%d, flags=0x%x, num_hdl=%d, idx=%d, buf handle=%x, len=%zu, i_ino=%lu, name:%s",
        v40,
        *(_DWORD *)(a1 + 224),
        *(_DWORD *)(a1 + 4),
        slot,
        v38,
        *((_QWORD *)v29 + 18),
        *((_QWORD *)v29 + 16),
        (const char *)(a1 + 96));
      result = 0;
    }
    goto LABEL_28;
  }
LABEL_77:
  v41 = _fortify_panic(7, 128, v37);
  return cam_mem_util_buffer_alloc(v41, v42, v43, v44, v45);
}
