__int64 __fastcall msm_vidc_adjust_dec_slice_mode(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v4; // x21
  __int64 v5; // x22

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 13256);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          53,
          67,
          "msm_vidc_adjust_dec_slice_mode")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 15608);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          53,
          48,
          "msm_vidc_adjust_dec_slice_mode")
      & 1) == 0 )
    return 4294967274LL;
  v5 = *(_QWORD *)(a1 + 12416);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          53,
          7,
          "msm_vidc_adjust_dec_slice_mode")
      & 1) == 0 )
    return 4294967274LL;
  if ( !v4 || !v5 || (*(_BYTE *)(a1 + 5544) & 0x80) == 0 || (~*(_DWORD *)(a1 + 5528) & 9LL) != 0 )
    v3 = 0;
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    53,
    v3,
    "msm_vidc_adjust_dec_slice_mode");
  return 0;
}
