__int64 __fastcall msm_vidc_adjust_peak_bitrate(__int64 a1, __int64 a2)
{
  int v3; // w20
  int v4; // w8
  int v6; // w8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 11072);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          40,
          119,
          "msm_vidc_adjust_peak_bitrate")
      & 1) != 0 )
  {
    v4 = *(_DWORD *)(a1 + 1828);
    if ( v4 != 4 && v4 != 1 )
      return 0;
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            40,
            66,
            "msm_vidc_adjust_peak_bitrate")
        & 1) != 0 )
    {
      if ( *(_QWORD *)(a1 + 15440) > v3 || (*(_DWORD *)(a1 + 11088) & 0x10) == 0 )
        v6 = *(_QWORD *)(a1 + 15440);
      else
        v6 = v3;
      ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
        a1,
        40,
        v6,
        "msm_vidc_adjust_peak_bitrate");
      return 0;
    }
  }
  return 4294967274LL;
}
