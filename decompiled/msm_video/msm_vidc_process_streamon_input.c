__int64 __fastcall msm_vidc_process_streamon_input(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  __int64 v4; // x1

  msm_vidc_scale_power(a1, 1);
  result = venus_hfi_start(a1, 0);
  if ( !(_DWORD)result )
  {
    if ( (is_sub_state(a1, 16) & 1) == 0
      || (result = msm_vidc_change_sub_state(a1, 16, 0, "msm_vidc_process_streamon_input"), !(_DWORD)result) )
    {
      if ( ((is_sub_state(a1, 2) & 1) != 0 || (is_sub_state(a1, 1) & 1) != 0 || (is_sub_state(a1, 64) & 1) != 0)
        && (is_sub_state(a1, 16) & 1) == 0 )
      {
        result = venus_hfi_session_pause(a1, 0);
        if ( (_DWORD)result )
          return result;
        v3 = 16;
      }
      else
      {
        v3 = 0;
      }
      if ( (is_state(a1, 0) & 1) != 0 )
      {
        v4 = 1;
      }
      else if ( (is_state(a1, 2) & 1) != 0 )
      {
        v4 = 3;
      }
      else
      {
        v4 = 5;
      }
      result = msm_vidc_change_state(a1, v4, "msm_vidc_state_change_streamon");
      if ( !(_DWORD)result )
        return msm_vidc_change_sub_state(a1, 0, v3, "msm_vidc_process_streamon_input");
    }
  }
  return result;
}
