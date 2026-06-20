__int64 __fastcall msm_vidc_adjust_all_intra(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  int v5; // w23
  int v6; // w24
  __int64 v7; // x4
  __int64 v8; // x2

  v1 = *(_QWORD *)(a1 + 16112);
  if ( (((__int64 (*)(void))is_parent_available)() & 1) == 0 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 15776);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          70,
          69,
          "msm_vidc_adjust_all_intra")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 15944);
  v5 = *(_DWORD *)(a1 + 1888);
  v6 = *(_DWORD *)(a1 + 1892);
  v7 = (unsigned int)msm_vidc_get_fps(a1) * ((unsigned int)(v5 + 15) >> 4) * ((unsigned int)(v6 + 15) >> 4);
  if ( (unsigned int)v7 <= *(_DWORD *)(*(_QWORD *)(a1 + 320) + 4240LL) )
  {
    if ( v3 | v4 )
      v8 = (int)v1;
    else
      v8 = 1;
  }
  else
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_849BE, "high", a1 + 340, "msm_vidc_adjust_all_intra", v7);
    }
    v8 = 0;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    70,
    v8,
    "msm_vidc_adjust_all_intra");
  return 0;
}
