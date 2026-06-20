__int64 __fastcall msm_vidc_adjust_delta_based_rc(__int64 a1, __int64 a2)
{
  int v3; // w20
  int v4; // w8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 10568);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          37,
          119,
          "msm_vidc_adjust_delta_based_rc")
      & 1) == 0 )
    return 4294967274LL;
  if ( (*(_DWORD *)(a1 + 1828) & 0xFFFFFFFE) == 2 )
    v4 = 0;
  else
    v4 = v3;
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    37,
    v4,
    "msm_vidc_adjust_delta_based_rc");
  return 0;
}
