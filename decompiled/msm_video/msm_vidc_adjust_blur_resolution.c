__int64 __fastcall msm_vidc_adjust_blur_resolution(__int64 a1, __int64 a2)
{
  int v3; // w20

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 12248);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          47,
          73,
          "msm_vidc_adjust_blur_resolution")
      & 1) == 0 )
    return 4294967274LL;
  if ( *(_QWORD *)(a1 + 16616) == 1 )
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      47,
      v3,
      "msm_vidc_adjust_blur_resolution");
  return 0;
}
