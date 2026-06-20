__int64 __fastcall msm_vidc_adjust_entropy_mode(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w19
  __int64 v6; // x20
  __int64 v7; // x2

  if ( a2 )
    v5 = *(_DWORD *)(a2 + 196);
  else
    v5 = *(_DWORD *)(result + 11240);
  if ( *(_DWORD *)(result + 312) != 1 )
  {
    if ( !result )
      return result;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8A3EA, "err ", result + 340, "msm_vidc_adjust_entropy_mode", a5);
    return 0;
  }
  v6 = result;
  if ( (((__int64 (*)(void))is_parent_available)() & 1) != 0 )
  {
    if ( *(_QWORD *)(v6 + 15104) >= 2u )
      v7 = v5;
    else
      v7 = 0;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
      v6,
      41,
      v7,
      "msm_vidc_adjust_entropy_mode");
    return 0;
  }
  return 4294967274LL;
}
