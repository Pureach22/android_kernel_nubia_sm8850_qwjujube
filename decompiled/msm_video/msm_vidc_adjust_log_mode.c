__int64 __fastcall msm_vidc_adjust_log_mode(_DWORD *a1, __int64 a2)
{
  int *v3; // x21
  int v4; // w20
  int v5; // w8
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x0

  v3 = a1 + 9320;
  if ( a2 )
    v4 = *(_DWORD *)(a2 + 196);
  else
    v4 = *v3;
  if ( (((__int64 (__fastcall *)(_DWORD *, __int64, __int64, const char *))is_parent_available)(
          a1,
          196,
          82,
          "msm_vidc_adjust_log_mode")
      & 1) == 0 )
    return 4294967274LL;
  v5 = a1[4532];
  if ( v5 > 127 )
  {
    if ( v5 != 256 && v5 != 128 )
      goto LABEL_13;
  }
  else if ( v5 != 8 && v5 != 16 )
  {
    goto LABEL_13;
  }
  if ( (((__int64 (__fastcall *)(_DWORD *, __int64, __int64, const char *))is_parent_available)(
          a1,
          196,
          119,
          "msm_vidc_adjust_log_mode")
      & 1) == 0 )
    return 4294967274LL;
  if ( !a1[457] )
  {
    ((void (__fastcall *)(_DWORD *, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      196,
      v4,
      "msm_vidc_adjust_log_mode");
    return 0;
  }
LABEL_13:
  if ( (v3[4] & 0x80) != 0 )
    return 0;
  v6 = *(_QWORD *)v3;
  result = 0;
  *(_QWORD *)v3 = 0;
  if ( a1 && v6 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v8 = cap_name(196);
      printk(&unk_80B2B, "high", a1 + 85, "msm_vidc_adjust_log_mode", v8);
    }
    return 0;
  }
  return result;
}
