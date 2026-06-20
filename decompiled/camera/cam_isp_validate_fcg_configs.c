__int64 __fastcall cam_isp_validate_fcg_configs(__int64 a1, unsigned int a2, unsigned int a3)
{
  const char *v4; // x5
  __int64 v5; // x4

  if ( *(_DWORD *)(a1 + 8) - 1 >= a2 )
  {
    v4 = "Invalid num of channels/contexts %u in FCG config, ctx_idx: %u";
    v5 = 12685;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 12) - 1 < a3 )
      return 0;
    v4 = "Invalid num of predictions %u in FCG config, ctx_idx: %u";
    v5 = 12692;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_validate_fcg_configs",
    v5,
    v4);
  return 4294967274LL;
}
