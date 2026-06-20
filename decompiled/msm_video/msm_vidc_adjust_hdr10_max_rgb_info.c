__int64 __fastcall msm_vidc_adjust_hdr10_max_rgb_info(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 v5; // x2

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 8888);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          27,
          64,
          "msm_vidc_adjust_hdr10_max_rgb_info")
      & 1) == 0 )
    return 4294967274LL;
  if ( *(_QWORD *)(a1 + 15104) == 2 && *(_DWORD *)(a1 + 312) == 2 )
    v5 = v3;
  else
    v5 = 0;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    27,
    v5,
    "msm_vidc_adjust_hdr10_max_rgb_info");
  return 0;
}
