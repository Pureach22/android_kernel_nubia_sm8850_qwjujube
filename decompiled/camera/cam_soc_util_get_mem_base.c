__int64 __fastcall cam_soc_util_get_mem_base(__int64 a1, __int64 a2, const char *a3, int a4)
{
  __int64 v7; // x2
  __int64 result; // x0

  if ( a4 && !_request_region(&iomem_resource, a1, a2, a3, 0) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_mem_base",
      4233,
      "Error Mem region request Failed:%s",
      a3);
    return 0;
  }
  if ( arm64_use_ng_mappings )
    v7 = 0x68000000000F13LL;
  else
    v7 = 0x68000000000713LL;
  result = ioremap_prot(a1, a2, v7);
  if ( !result )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_mem_base",
      4241,
      "get mem base failed");
    return 0;
  }
  return result;
}
