__int64 __fastcall cam_mem_mgr_alloc_presil_copy_buf(unsigned int a1, const void **a2, int *a3, _QWORD *a4)
{
  unsigned int v8; // w0
  unsigned int v9; // w19
  __int64 result; // x0
  int v11; // w0
  unsigned int v12; // w19
  int v13; // w8
  const void *v14; // x10
  __int64 v15; // x6
  int v16; // w22
  __int64 v17; // [xsp+30h] [xbp-30h] BYREF
  __int64 v18; // [xsp+38h] [xbp-28h] BYREF
  const void *v19; // [xsp+40h] [xbp-20h] BYREF
  int v20; // [xsp+4Ch] [xbp-14h] BYREF
  const void *v21[2]; // [xsp+50h] [xbp-10h] BYREF

  v21[1] = *(const void **)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = nullptr;
  v20 = -1;
  v19 = nullptr;
  v17 = 0;
  if ( a2 && a3 && a4 )
  {
    v8 = cam_mem_util_buffer_alloc(a1, 24, v21, &v20, &v17);
    if ( v8 )
    {
      v9 = v8;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_mgr_alloc_presil_copy_buf",
        2372,
        "Ion Alloc failed len=%llu flags=0x%x dmabuf=0x%x fd=%d i_no=%d heap_type=0x%x",
        a1,
        24,
        LODWORD(v21[0]),
        v20,
        v17,
        2);
      result = v9;
    }
    else
    {
      v18 = 0;
      v11 = cam_mem_util_map_cpu_va((_QWORD *)v21[0], &v19, &v18);
      if ( v11 )
      {
        v12 = v11;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_mgr_alloc_presil_copy_buf",
          2378,
          "dmabuf: %pK mapping failed: %d",
          v21[0],
          v11);
        dma_buf_put(v21[0]);
        result = v12;
      }
      else
      {
        v13 = v20;
        if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        {
          v15 = a1;
          v16 = v20;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x400000,
            4,
            "cam_mem_mgr_alloc_presil_copy_buf",
            2386,
            "Success len=%llu flags=0x%x dmabuf 0x%x fd=%d i_no=%d heap_type=0x%x kvaddr %pK klen %d",
            v15,
            24,
            LODWORD(v21[0]),
            v20,
            v17,
            2,
            v19,
            v18);
          v13 = v16;
        }
        v14 = v19;
        result = 0;
        *a2 = v21[0];
        *a4 = v14;
        *a3 = (v13 << 16) | 0x7FFF;
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_alloc_presil_copy_buf",
      2358,
      "Invalid argument %pK %pK %pK",
      a3,
      a2,
      a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
