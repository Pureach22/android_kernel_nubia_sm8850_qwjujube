__int64 __fastcall cam_vfe_top_ver3_dump_info(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x0

  v1 = *(_QWORD *)(a1 + 10432);
  if ( v1 )
  {
    if ( (unsigned int)__ratelimit(&cam_vfe_top_ver3_dump_info__rs, "cam_vfe_top_ver3_dump_info") )
      v2 = 3;
    else
      v2 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v2,
      8,
      3,
      "cam_vfe_top_ver3_dump_info",
      128,
      "VFE%d src_clk_rate:%luHz",
      *(_DWORD *)(v1 + 20),
      *(_QWORD *)(v1 + 2800));
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_dump_info",
      121,
      "Null soc_info");
    return 4294967274LL;
  }
}
