__int64 __fastcall msm_vidc_adjust_transform_8x8(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w19
  __int64 v6; // x20
  __int64 v7; // x8

  if ( a2 )
    v5 = *(_DWORD *)(a2 + 196);
  else
    v5 = *(_DWORD *)(result + 11408);
  if ( *(_DWORD *)(result + 312) != 1 )
  {
    if ( !result )
      return result;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8A3EA, "err ", result + 340, "msm_vidc_adjust_transform_8x8", a5);
    return 0;
  }
  v6 = result;
  if ( (((__int64 (*)(void))is_parent_available)() & 1) != 0 )
  {
    v7 = *(_QWORD *)(v6 + 15104);
    if ( v7 != 4 && v7 != 17 )
      v5 = 0;
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      v6,
      42,
      v5,
      "msm_vidc_adjust_transform_8x8");
    return 0;
  }
  return 4294967274LL;
}
