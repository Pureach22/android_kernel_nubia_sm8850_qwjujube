__int64 __fastcall cam_isp_validate_bw_limiter_blob(unsigned int a1, _DWORD *a2)
{
  unsigned int v2; // w8

  v2 = *a2 - 1;
  if ( v2 >= max_sfe_out_res + max_ife_out_res )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_validate_bw_limiter_blob",
      12347,
      "Invalid num_ports:%u in bw limit config",
      *a2);
    return 4294967274LL;
  }
  if ( 40 * (unsigned __int64)v2 + 48 > a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_validate_bw_limiter_blob",
      12370,
      "Invalid blob size %u expected %lu",
      a1);
    return 4294967274LL;
  }
  return 0;
}
