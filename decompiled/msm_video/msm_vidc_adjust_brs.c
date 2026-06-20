__int64 __fastcall msm_vidc_adjust_brs(__int64 a1, __int64 a2)
{
  int v3; // w20
  int v4; // w22
  __int64 v5; // x21
  int v7; // w8
  __int64 v8; // x8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 16448);
  if ( (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) == 0 )
  {
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            72,
            119,
            "msm_vidc_adjust_brs")
        & 1) == 0 )
      return 4294967274LL;
    v4 = *(_DWORD *)(a1 + 1828);
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            72,
            140,
            "msm_vidc_adjust_brs")
        & 1) == 0 )
      return 4294967274LL;
    v5 = *(_QWORD *)(a1 + 27872);
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            72,
            139,
            "msm_vidc_adjust_brs")
        & 1) == 0 )
      return 4294967274LL;
    if ( v4 )
    {
      v3 = 0;
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 312);
      if ( v7 == 2 || v7 == 1 )
        v8 = 1;
      else
        v8 = *(unsigned int *)(a1 + 1832);
      if ( v5 == 1 && *(_QWORD *)(a1 + 27704) == v8 )
        v3 = 0;
    }
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      72,
      v3,
      "msm_vidc_adjust_brs");
  }
  return 0;
}
