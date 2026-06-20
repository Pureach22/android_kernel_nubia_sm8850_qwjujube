__int64 __fastcall cam_mem_util_map_cpu_va(_QWORD *a1, _QWORD *a2, _QWORD *a3)
{
  int v6; // w0
  unsigned int dmabuf_va; // w19

  v6 = dma_buf_begin_cpu_access(a1, 0);
  if ( v6 )
  {
    dmabuf_va = v6;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_map_cpu_va",
      199,
      "dma begin access failed rc=%d",
      v6);
  }
  else
  {
    dmabuf_va = cam_compat_util_get_dmabuf_va(a1, a2);
    if ( dmabuf_va )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_util_map_cpu_va",
        205,
        "kernel vmap failed: rc = %d",
        dmabuf_va);
      *a3 = 0;
      dma_buf_end_cpu_access(a1, 0);
    }
    else
    {
      *a3 = *a1;
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_util_map_cpu_va",
          211,
          "vaddr = %llu, len = %zu",
          *a2);
        return 0;
      }
    }
  }
  return dmabuf_va;
}
