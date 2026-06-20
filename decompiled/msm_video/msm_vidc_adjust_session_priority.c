__int64 __fastcall msm_vidc_adjust_session_priority(__int64 a1, __int64 a2)
{
  int v2; // w8

  if ( a2 )
    v2 = *(_DWORD *)(a2 + 196);
  else
    v2 = *(_DWORD *)(a1 + 33416);
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    173,
    v2,
    "msm_vidc_adjust_session_priority");
  return 0;
}
