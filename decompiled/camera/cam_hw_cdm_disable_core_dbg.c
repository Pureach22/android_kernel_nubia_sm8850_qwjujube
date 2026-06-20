__int64 __fastcall cam_hw_cdm_disable_core_dbg(__int64 a1)
{
  bool v1; // w8
  __int64 result; // x0

  v1 = cam_cdm_write_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(a1 + 3680) + 232LL) + 72LL), 0);
  result = 0;
  if ( v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_disable_core_dbg",
      249,
      "Failed to Write CDM HW core debug");
    return 4294967291LL;
  }
  return result;
}
