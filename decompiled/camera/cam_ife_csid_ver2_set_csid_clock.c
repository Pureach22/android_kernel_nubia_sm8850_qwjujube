__int64 __fastcall cam_ife_csid_ver2_set_csid_clock(__int64 a1, __int64 *a2)
{
  __int64 v2; // x7
  char v4; // w9
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = *a2;
  v4 = debug_mdl;
  result = 0;
  *(_QWORD *)(a1 + 32184) = *a2;
  if ( (v4 & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v4 & 8,
      4,
      "cam_ife_csid_ver2_set_csid_clock",
      8343,
      "CSID:%d, clk_rate=%lld",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      v2);
    return 0;
  }
  return result;
}
