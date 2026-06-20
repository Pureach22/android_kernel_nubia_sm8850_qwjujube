__int64 __fastcall msm_vidc_adjust_enc_lowlatency_mode(__int64 a1, __int64 a2)
{
  int v3; // w20
  int v4; // w8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 15608);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          67,
          119,
          "msm_vidc_adjust_enc_lowlatency_mode")
      & 1) == 0 )
    return 4294967274LL;
  v4 = *(_DWORD *)(a1 + 1828);
  if ( v4 == 1 || v4 == 4 || *(_DWORD *)(a1 + 308) != 2 && *(_QWORD *)(a1 + 16952) == 1 && *(_QWORD *)(a1 + 12920) )
    v3 = 1;
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    67,
    v3,
    "msm_vidc_adjust_enc_lowlatency_mode");
  return 0;
}
