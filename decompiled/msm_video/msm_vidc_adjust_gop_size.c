__int64 __fastcall msm_vidc_adjust_gop_size(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 v4; // x21
  bool v5; // w8
  unsigned int v7; // w9

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 15776);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          68,
          65,
          "msm_vidc_adjust_gop_size")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 15272);
  if ( *(_DWORD *)(a1 + 312) == 2 )
  {
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            68,
            192,
            "msm_vidc_adjust_gop_size")
        & 1) != 0 )
    {
      v5 = *(_QWORD *)(a1 + 36608) != 0;
      if ( !v4 )
        goto LABEL_15;
LABEL_11:
      if ( !v5 )
      {
        v7 = (v3 + ((unsigned int)(1 << v4) >> 1)) >> v4;
        if ( v7 )
          v3 = v7 << v4;
        else
          v3 = 1 << v4;
      }
      goto LABEL_15;
    }
    return 4294967274LL;
  }
  v5 = 0;
  if ( v4 )
    goto LABEL_11;
LABEL_15:
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    68,
    v3,
    "msm_vidc_adjust_gop_size");
  return 0;
}
