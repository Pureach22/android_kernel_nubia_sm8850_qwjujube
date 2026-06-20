__int64 __fastcall msm_vidc_adjust_bitrate_boost(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 v4; // x21
  unsigned int max_bitrate; // w0

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 12080);
  if ( (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) != 0 )
    return 0;
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          46,
          71,
          "msm_vidc_adjust_bitrate_boost")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 16280);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          46,
          119,
          "msm_vidc_adjust_bitrate_boost")
      & 1) == 0 )
    return 4294967274LL;
  if ( !*(_DWORD *)(a1 + 1828) )
  {
    if ( v4 )
    {
      v3 = 25;
      goto LABEL_12;
    }
    max_bitrate = msm_vidc_get_max_bitrate(a1);
    if ( !v3 || *(_DWORD *)(a1 + 15440) / (unsigned int)(100 / v3) + *(_DWORD *)(a1 + 15440) <= max_bitrate )
      goto LABEL_12;
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_94180, "high", a1 + 340, "msm_vidc_adjust_bitrate_boost", max_bitrate);
    }
  }
  v3 = 0;
LABEL_12:
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    46,
    v3,
    "msm_vidc_adjust_bitrate_boost");
  return 0;
}
