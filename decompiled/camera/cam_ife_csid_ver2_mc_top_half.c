__int64 __fastcall cam_ife_csid_ver2_mc_top_half(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v4; // w19
  __int64 v5; // x0

  if ( *(_QWORD *)a2 )
  {
    *(_BYTE *)(a2 + 32) = 1;
    result = cam_ife_csid_ver2_path_top_half(a1, (__int64 *)a2);
    if ( (_DWORD)result )
    {
      v4 = result;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_mc_top_half",
        1108,
        "Multi context top half fail");
      return v4;
    }
    else
    {
      *(_BYTE *)(*(_QWORD *)(a2 + 24) + 48LL) = 1;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_mc_top_half__rs, "cam_ife_csid_ver2_mc_top_half") )
      v5 = 3;
    else
      v5 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v5,
      8,
      1,
      "cam_ife_csid_ver2_mc_top_half",
      1100,
      "No private returned");
    return 4294967277LL;
  }
  return result;
}
