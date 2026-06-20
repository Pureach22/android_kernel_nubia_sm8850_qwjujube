__int64 __fastcall cam_mem_util_buffer_alloc(__int64 a1, __int64 a2, const void **a3, int *a4, _QWORD *a5)
{
  int v8; // w23
  unsigned int dma_buf; // w0
  unsigned int v11; // w20
  __int64 result; // x0
  int v14; // w8
  unsigned __int64 v20; // x9

  v8 = a2;
  dma_buf = cam_mem_util_get_dma_buf(a1, a2, 0, a3);
  if ( dma_buf )
  {
    v11 = dma_buf;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_buffer_alloc",
      1985,
      "Error allocating dma buf : len=%llu, flags=0x%x",
      a1,
      v8);
    return v11;
  }
  else
  {
    _X8 = *((unsigned __int64 **)*a3 + 1);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 + 1, _X8) );
    if ( !v20 && (get_file___already_done & 1) == 0 )
    {
      get_file___already_done = 1;
      _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
      __break(0x800u);
    }
    v14 = dma_buf_fd(*a3, 0x80000);
    *a4 = v14;
    if ( v14 < 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_util_buffer_alloc",
        1998,
        "get fd fail, *fd=%d",
        v14);
      dma_buf_put(*a3);
      return 4294967274LL;
    }
    else
    {
      result = 0;
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_util_buffer_alloc",
          2004,
          "Alloc success : len=%zu, *dmabuf=%pK, fd=%d, i_ino=%lu",
          a1,
          *a3,
          v14,
          *a5);
        return 0;
      }
    }
  }
  return result;
}
