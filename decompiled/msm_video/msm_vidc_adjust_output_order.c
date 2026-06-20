__int64 __fastcall msm_vidc_adjust_output_order(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v4; // x21
  bool v5; // zf

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 12416);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          48,
          151,
          "msm_vidc_adjust_output_order")
      & 1) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 29720);
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            48,
            150,
            "msm_vidc_adjust_output_order")
        & 1) != 0 )
    {
      if ( v4 )
        v5 = 1;
      else
        v5 = *(_QWORD *)(a1 + 29552) == 0;
      if ( !v5 )
        v3 = 1;
      if ( (is_valid_cap(a1, 168) & 1) == 0 )
        goto LABEL_15;
      if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
              a1,
              48,
              168,
              "msm_vidc_adjust_output_order")
          & 1) != 0 )
      {
        if ( *(_QWORD *)(a1 + 32576) == 1 )
          v3 = 1;
LABEL_15:
        ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
          a1,
          48,
          v3,
          "msm_vidc_adjust_output_order");
        return 0;
      }
    }
  }
  return 4294967274LL;
}
