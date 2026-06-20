__int64 __fastcall cam_icp_proc_mini_dump(__int64 *a1, const void *a2, unsigned __int64 a3)
{
  __int64 v3; // x7
  unsigned __int64 v4; // x6

  if ( a1 )
  {
    v3 = *a1;
    if ( a2 && v3 )
    {
      v4 = a1[1];
      if ( v4 >= a3 )
      {
        _memcpy_fromio(*a1, a2);
        a1[2] = a3;
        return 0;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          2,
          "cam_icp_proc_mini_dump",
          183,
          "Insufficient Len %lu fw_len %llu",
          v4,
          a3);
        return 4294967268LL;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_proc_mini_dump",
        177,
        "invalid params %pK, 0x%zx",
        a2,
        v3);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_proc_mini_dump",
      171,
      "Invalid param %pK",
      nullptr);
    return 4294967274LL;
  }
}
