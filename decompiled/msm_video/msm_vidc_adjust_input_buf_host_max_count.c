__int64 __fastcall msm_vidc_adjust_input_buf_host_max_count(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v4; // x2

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 12584);
  if ( (msm_vidc_is_super_buffer(a1) & 1) != 0 )
    v4 = 256;
  else
    v4 = v3;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    49,
    v4,
    "msm_vidc_adjust_input_buf_host_max_count");
  return 0;
}
