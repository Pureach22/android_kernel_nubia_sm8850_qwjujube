__int64 __fastcall msm_vidc_adjust_early_notify_line_count(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x2

  if ( a2 )
    v3 = *(int *)(a2 + 196);
  else
    v3 = *(_QWORD *)(a1 + 13592);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          55,
          54,
          "msm_vidc_adjust_early_notify_line_count")
      & 1) == 0 )
    return 4294967274LL;
  if ( *(_QWORD *)(a1 + 13424) )
    v4 = v3;
  else
    v4 = 0;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    55,
    v4,
    "msm_vidc_adjust_early_notify_line_count");
  return 0;
}
