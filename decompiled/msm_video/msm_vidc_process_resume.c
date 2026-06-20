__int64 __fastcall msm_vidc_process_resume(__int64 a1)
{
  __int64 v2; // x1
  __int64 result; // x0
  unsigned int v4; // w20

  msm_vidc_scale_power(a1, 1);
  if ( (is_sub_state(a1, 2) & 1) == 0 || (is_sub_state(a1, 8) & 1) == 0 )
  {
    if ( (is_sub_state(a1, 1) & 1) == 0 || (is_sub_state(a1, 4) & 1) == 0 )
    {
      v2 = 0;
      return msm_vidc_change_sub_state(a1, v2, 0, "msm_vidc_process_resume");
    }
    if ( (is_sub_state(a1, 16) & 1) != 0 )
    {
      result = venus_hfi_session_resume(a1, 0, 16777223);
      if ( (_DWORD)result )
        return result;
      v4 = 21;
    }
    else
    {
      v4 = 5;
    }
    if ( (is_sub_state(a1, 32) & 1) == 0 || *(_DWORD *)(a1 + 308) == 1 )
    {
LABEL_23:
      v2 = v4;
      return msm_vidc_change_sub_state(a1, v2, 0, "msm_vidc_process_resume");
    }
    result = venus_hfi_session_resume(a1, 1, 16777223);
    if ( (_DWORD)result )
      return result;
LABEL_27:
    v2 = v4 | 0x20;
    return msm_vidc_change_sub_state(a1, v2, 0, "msm_vidc_process_resume");
  }
  if ( (is_sub_state(a1, 1) & 1) != 0 && (is_sub_state(a1, 4) & 1) != 0 )
  {
    v2 = 10;
    return msm_vidc_change_sub_state(a1, v2, 0, "msm_vidc_process_resume");
  }
  if ( (is_sub_state(a1, 16) & 1) != 0 )
  {
    result = venus_hfi_session_resume(a1, 0, 16777228);
    if ( (_DWORD)result )
      return result;
    v4 = 26;
  }
  else
  {
    v4 = 10;
  }
  if ( (is_sub_state(a1, 32) & 1) == 0 || *(_DWORD *)(a1 + 308) == 1 )
    goto LABEL_23;
  result = venus_hfi_session_resume(a1, 1, 16777228);
  if ( !(_DWORD)result )
    goto LABEL_27;
  return result;
}
