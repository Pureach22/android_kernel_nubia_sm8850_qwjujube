__int64 __fastcall msm_vidc_process_drain(__int64 a1)
{
  __int64 result; // x0

  result = venus_hfi_session_drain(a1, 0);
  if ( !(_DWORD)result )
  {
    result = msm_vidc_change_sub_state(a1, 0, 1, "msm_vidc_process_drain");
    if ( !(_DWORD)result )
    {
      msm_vidc_scale_power(a1, 1);
      return 0;
    }
  }
  return result;
}
