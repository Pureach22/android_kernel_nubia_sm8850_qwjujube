__int64 __fastcall msm_vidc_adjust_output_buf_host_max_count(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 12752);
  if ( (msm_vidc_is_super_buffer(a1) & 1) != 0
    || *(_DWORD *)(a1 + 312) == 8
    || *(_DWORD *)(a1 + 308) != 2 && *(_QWORD *)(a1 + 16952) == 1 && *(_QWORD *)(a1 + 12920) )
  {
    v3 = 256;
  }
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    50,
    v3,
    "msm_vidc_adjust_output_buf_host_max_count");
  return 0;
}
