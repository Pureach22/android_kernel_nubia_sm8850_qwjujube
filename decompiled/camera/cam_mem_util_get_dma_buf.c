__int64 __fastcall cam_mem_util_get_dma_buf(__int64 a1, int a2, int a3, const void **a4, _QWORD *a5)
{
  int v9; // w23
  unsigned int v10; // w27
  int v11; // w8
  const char *v12; // x5
  __int64 v13; // x4
  unsigned __int64 v14; // x24
  _DWORD *v15; // x10
  _DWORD *v16; // x11
  int v17; // w8
  unsigned __int64 v18; // x25
  bool v19; // zf
  __int64 v20; // x23
  unsigned __int64 v21; // x0
  bool v22; // zf
  const void *v23; // x0
  int v24; // w0
  int v26; // w23
  _QWORD v27[2]; // [xsp+20h] [xbp-70h] BYREF
  _QWORD v28[2]; // [xsp+30h] [xbp-60h] BYREF
  _QWORD v29[5]; // [xsp+40h] [xbp-50h] BYREF
  _QWORD v30[2]; // [xsp+68h] [xbp-28h] BYREF
  __int64 v31; // [xsp+78h] [xbp-18h] BYREF
  __int64 v32; // [xsp+80h] [xbp-10h]
  __int64 v33; // [xsp+88h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  v28[1] = 0;
  v27[0] = 0;
  v27[1] = 0;
  v31 = 0;
  v32 = 0;
  v30[0] = 0;
  v30[1] = 0;
  if ( !a4 )
  {
    v12 = "Invalid params";
    v13 = 1574;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_get_dma_buf",
      v13,
      v12);
    LODWORD(v14) = -22;
    goto LABEL_92;
  }
  if ( byte_391C18 == 1 )
  {
    v9 = a3;
    ktime_get_real_ts64(v28);
    a3 = v9;
  }
  if ( (a2 & 0x20) != 0 )
  {
    if ( dword_391BBC == 2 && dword_391BC0 == 5 )
    {
      v10 = 0;
    }
    else
    {
      v10 = 1;
      LODWORD(v31) = 13;
      LODWORD(v30[0]) = 6;
      if ( (a2 & 0x1000) != 0 )
      {
        v11 = 42;
        goto LABEL_14;
      }
    }
  }
  else
  {
    v10 = 0;
    if ( (a2 & 0x8000) != 0 )
    {
      v11 = 11;
LABEL_14:
      v15 = (_DWORD *)((unsigned __int64)&v31 | (4LL * v10));
      v16 = (_DWORD *)((unsigned __int64)v30 & 0xFFFFFFFFFFFFFFFBLL | (4LL * (v10++ & 1)));
      *v15 = v11;
      *v16 = 6;
    }
  }
  if ( (a2 & 0x400) != 0 || (a2 & 0x20) == 0 && byte_391BB8 )
  {
    if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
    {
      v26 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400000,
        4,
        "cam_mem_util_get_dma_buf",
        1592,
        "Using CACHED heap, cam_flags=0x%x, force_cache_allocs=%d",
        a2,
        (unsigned __int8)byte_391BB8);
      a3 = v26;
      if ( (a2 & 0x20) == 0 )
      {
LABEL_21:
        v17 = 1;
        if ( (a2 & 0x8000) == 0 )
          goto LABEL_22;
LABEL_45:
        v18 = 0;
        v20 = qword_391BF0;
        goto LABEL_46;
      }
    }
    else if ( (a2 & 0x20) == 0 )
    {
      goto LABEL_21;
    }
LABEL_41:
    if ( dword_391BBC == 2 && dword_391BC0 == 5 )
    {
      v20 = qword_391BC8;
      a1 = cam_align_dma_buf_size(a1);
LABEL_44:
      v18 = 0;
      goto LABEL_46;
    }
    goto LABEL_45;
  }
  if ( (a2 & 0x20) != 0 )
  {
    if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400000,
        4,
        "cam_mem_util_get_dma_buf",
        1598,
        "Using CACHED heap for secure, cam_flags=0x%x, force_cache_allocs=%d",
        a2,
        (unsigned __int8)byte_391BB8);
    goto LABEL_41;
  }
  if ( !(qword_391BD8 | *((_QWORD *)&xmmword_391BE0 + 1)) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_get_dma_buf",
      1604,
      "Using UNCACHED heap not supported, cam_flags=0x%x, force_cache_allocs=%d",
      a2,
      (unsigned __int8)byte_391BB8);
    LODWORD(v14) = -22;
    goto LABEL_92;
  }
  v17 = 0;
  if ( (a2 & 0x8000) != 0 )
    goto LABEL_45;
LABEL_22:
  if ( (a2 & 0x20000) == 0 )
  {
    if ( v17 )
    {
      if ( (a2 & 0x80000) != 0 )
        v18 = 0;
      else
        v18 = xmmword_391BE0;
      if ( (a2 & 0x40000) != 0 )
      {
        v20 = 0;
      }
      else
      {
        if ( qword_391BD0 )
          v19 = a3 == 0;
        else
          v19 = 0;
        if ( v19 )
          v20 = qword_391BD0;
        else
          v20 = qword_391BC8;
      }
    }
    else
    {
      if ( (a2 & 0x80000) != 0 )
        v18 = 0;
      else
        v18 = *((_QWORD *)&xmmword_391BE0 + 1);
      if ( (a2 & 0x40000) != 0 )
        v20 = 0;
      else
        v20 = qword_391BD8;
    }
    goto LABEL_46;
  }
  if ( !qword_391BF8 )
  {
    v12 = "ubwc-p heap is not available, can't allocate";
    v13 = 1619;
    goto LABEL_8;
  }
  v18 = 0;
  if ( qword_391C00 )
    v22 = a3 == 0;
  else
    v22 = 0;
  if ( v22 )
    v20 = qword_391C00;
  else
    v20 = qword_391BF8;
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_util_get_dma_buf",
      1628,
      "Allocating from ubwc-p heap %pK, size=%d, flags=0x%x",
      (const void *)v20,
      a1,
      a2);
    goto LABEL_44;
  }
LABEL_46:
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_util_get_dma_buf",
      1693,
      "Using heaps : try=%pK, heap=%pK",
      (const void *)v18,
      (const void *)v20);
  *a4 = nullptr;
  if ( !(v18 | v20) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_get_dma_buf",
      1700,
      "No heap available for allocation, can't allocate flag: 0x%x",
      a2);
    LODWORD(v14) = -22;
    goto LABEL_92;
  }
  if ( v18 )
  {
    v21 = dma_heap_buffer_alloc(v18, a1, 2, 0);
    v14 = v21;
    *a4 = (const void *)v21;
    if ( v21 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( v21 )
        goto LABEL_58;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        2,
        "cam_mem_util_get_dma_buf",
        1710,
        "Failed in allocating from try heap, heap=%pK, len=%zu, err=%d",
        (const void *)v18,
        a1,
        v21);
      *a4 = nullptr;
    }
  }
  if ( !v20 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_get_dma_buf",
      1718,
      "No default heap selected, flags = 0x%x",
      a2);
    LODWORD(v14) = -12;
    goto LABEL_92;
  }
  v14 = dma_heap_buffer_alloc(v20, a1, 2, 0);
  *a4 = (const void *)v14;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_get_dma_buf",
      1730,
      "Failed in allocating from heap, heap=%pK, len=%zu, err=%d",
      (const void *)v20,
      a1,
      v14);
    *a4 = nullptr;
    goto LABEL_92;
  }
LABEL_58:
  *a5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 8) + 40LL) + 64LL);
  if ( (a2 & 0x20) != 0 )
  {
    if ( (a2 & 0x8000) == 0 && dword_391BBC == 2 && dword_391BC0 == 5 )
      goto LABEL_78;
LABEL_75:
    if ( v10 )
    {
      v23 = *a4;
      v29[1] = &v31;
      v29[3] = 0;
      v29[4] = 0;
      v29[0] = v10;
      v29[2] = v30;
      v24 = mem_buf_lend(v23, v29);
      if ( v24 )
      {
        LODWORD(v14) = v24;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_util_mem_buf_lend",
          1502,
          "Failed in buf lend rc=%d, buf=%pK, num_vmids: %d, vmids [0]=0x%x, [1]=0x%x, [2]=0x%x",
          v24,
          *a4,
          v10,
          v31,
          HIDWORD(v31),
          v32);
        dma_buf_put(*a4);
        goto LABEL_92;
      }
    }
    goto LABEL_78;
  }
  if ( (a2 & 0x8000) != 0 )
    goto LABEL_75;
LABEL_78:
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_util_get_dma_buf",
      1746,
      "Allocate success, len=%zu, *buf=%pK, i_ino=%lu",
      a1,
      *a4,
      *a5);
  if ( byte_391C18 == 1 )
    ktime_get_real_ts64(v27);
  LODWORD(v14) = 0;
LABEL_92:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v14;
}
