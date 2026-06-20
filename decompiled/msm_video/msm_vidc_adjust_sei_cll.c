__int64 __fastcall msm_vidc_adjust_sei_cll(__int64 a1, __int64 a2)
{
  int v3; // w20
  int v4; // w9
  __int64 v5; // x8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 6704);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          14,
          64,
          "msm_vidc_adjust_sei_cll")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(_DWORD *)(a1 + 312);
  v5 = *(_QWORD *)(a1 + 15104);
  if ( v4 != 8 && v4 != 2 || v4 == 2 && v5 != 2 || v4 == 8 && v5 != 3 )
    v3 = 0;
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    14,
    v3,
    "msm_vidc_adjust_sei_cll");
  return 0;
}
