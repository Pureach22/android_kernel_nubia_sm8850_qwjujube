__int64 __fastcall msm_vidc_adjust_profile(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x2

  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          64,
          82,
          "msm_vidc_adjust_profile")
      & 1) == 0 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 18128);
  if ( v2 == 16 || v2 == 8 )
  {
    if ( *(_DWORD *)(a1 + 312) == 8 )
    {
      v3 = 3;
    }
    else if ( *(_QWORD *)(a1 + 15104) == 5 )
    {
      v3 = 5;
    }
    else
    {
      v3 = 2;
    }
  }
  else if ( *(_DWORD *)(a1 + 312) == 8 )
  {
    v3 = 1;
  }
  else
  {
    v3 = 4LL * (*(_QWORD *)(a1 + 15104) == 4);
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    64,
    v3,
    "msm_vidc_adjust_profile");
  return 0;
}
