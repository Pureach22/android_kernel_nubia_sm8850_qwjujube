__int64 __fastcall cam_ife_csid_ver2_reset_out_of_sync_cnt(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 result; // x0

  v1 = *a1;
  v2 = *(_QWORD *)(*a1 + 24);
  if ( v2 )
  {
    *(_DWORD *)(v2 + 236) = 0;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_reset_out_of_sync_cnt",
        8912,
        "Reset out of sync cnt for res:%s",
        (const char *)(v1 + 128));
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_reset_out_of_sync_cnt",
      8905,
      "Invalid res %s",
      (const char *)(v1 + 128));
    return 4294967274LL;
  }
  return result;
}
