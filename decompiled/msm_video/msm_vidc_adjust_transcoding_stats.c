__int64 __fastcall msm_vidc_adjust_transcoding_stats(_DWORD *a1, __int64 a2)
{
  int v3; // w22
  __int64 v4; // x4
  __int64 v6; // x4
  unsigned int v7; // w20

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = a1[2138];
  if ( (((__int64 (__fastcall *)(_DWORD *, __int64, __int64, const char *))is_parent_available)(
          a1,
          25,
          119,
          "msm_vidc_adjust_transcoding_stats")
      & 1) == 0 )
    return 4294967274LL;
  v4 = (unsigned int)a1[457];
  if ( (_DWORD)v4 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_911B9, "high", a1 + 85, "msm_vidc_adjust_transcoding_stats", v4);
    }
LABEL_18:
    v3 = 0;
    goto LABEL_19;
  }
  v6 = *(unsigned int *)((char *)a1 + 19474);
  if ( (unsigned int)v6 >= 0x3D )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_8980F, "high", a1 + 85, "msm_vidc_adjust_transcoding_stats", v6);
    goto LABEL_18;
  }
  v7 = a1[150];
  if ( (res_is_greater_than(v7, (unsigned int)a1[151], 4096, 2304) & 1) != 0 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_80030, "high", a1 + 85, "msm_vidc_adjust_transcoding_stats", v7);
    goto LABEL_18;
  }
LABEL_19:
  ((void (__fastcall *)(_DWORD *, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    25,
    v3,
    "msm_vidc_adjust_transcoding_stats");
  return 0;
}
