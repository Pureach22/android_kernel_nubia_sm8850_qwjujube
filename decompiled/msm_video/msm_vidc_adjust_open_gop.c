__int64 __fastcall msm_vidc_adjust_open_gop(__int64 a1, __int64 a2)
{
  int v3; // w20

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 36608);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          192,
          65,
          "msm_vidc_adjust_open_gop")
      & 1) == 0 )
    return 4294967274LL;
  if ( *(_DWORD *)(a1 + 312) != 2
    || *(_DWORD *)(a1 + 1828)
    || (unsigned __int64)(*(_QWORD *)(a1 + 15272) - 1LL) > 2
    || *(_DWORD *)(a1 + 1832) != 3 )
  {
    v3 = 0;
  }
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    192,
    v3,
    "msm_vidc_adjust_open_gop");
  return 0;
}
