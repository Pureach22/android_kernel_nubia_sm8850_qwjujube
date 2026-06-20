__int64 __fastcall cam_mem_util_unmap_cpu_va(const void *a1, __int64 a2)
{
  __int64 result; // x0

  if ( !a1 || !a2 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x400000,
             1,
             "cam_mem_util_unmap_cpu_va",
             223,
             "Invalid input args %pK %llX",
             a1,
             a2);
  cam_compat_util_put_dmabuf_va(a1, a2);
  result = dma_buf_end_cpu_access(a1, 0);
  if ( (_DWORD)result )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x400000,
             1,
             "cam_mem_util_unmap_cpu_va",
             237,
             "Failed in end cpu access, dmabuf=%pK",
             a1);
  return result;
}
