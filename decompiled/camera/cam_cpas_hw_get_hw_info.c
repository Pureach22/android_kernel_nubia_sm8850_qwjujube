__int64 __fastcall cam_cpas_hw_get_hw_info(_QWORD *a1, char *dest, int a3)
{
  __int64 result; // x0

  if ( !a1 || !dest )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_get_hw_info",
      3407,
      "Invalid arguments %pK %pK",
      a1,
      dest);
    return 4294967274LL;
  }
  if ( a3 != 308 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_get_hw_info",
      3413,
      "HW_CAPS size mismatch %zd %d",
      0x134u,
      a3);
    return 4294967274LL;
  }
  memcpy(dest, (const void *)(a1[460] + 8LL), 0x134u);
  memcpy(dest + 48, (const void *)(a1[424] + 1064LL), 0x104u);
  result = 0;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_hw_get_hw_info",
      3427,
      "fuse info->num_fuses %d",
      *((_DWORD *)dest + 12));
    return 0;
  }
  return result;
}
