__int64 __fastcall msm_vidc_adjust_roi_info_iris4(__int64 a1, __int64 a2)
{
  int v3; // w20
  unsigned int v4; // w8
  __int64 v5; // x8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 8216);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          23,
          119,
          "msm_vidc_adjust_roi_info_iris4")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(_DWORD *)(a1 + 1828);
  if ( v4 > 4
    || ((1 << v4) & 0x13) == 0
    || *(_DWORD *)(a1 + 1880) != *(_DWORD *)(a1 + 1896)
    || *(_DWORD *)(a1 + 1884) != *(_DWORD *)(a1 + 1900)
    || *(_DWORD *)(a1 + 1888) != *(_DWORD *)(a1 + 1904)
    || *(_DWORD *)(a1 + 1892) != *(_DWORD *)(a1 + 1908)
    || (v5 = *(_QWORD *)(a1 + 23168), v5 == 270)
    || v5 == 90 )
  {
    v3 = 0;
  }
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    23,
    v3,
    "msm_vidc_adjust_roi_info_iris4");
  return 0;
}
