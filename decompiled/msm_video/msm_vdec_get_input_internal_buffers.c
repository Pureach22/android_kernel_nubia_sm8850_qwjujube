__int64 __fastcall msm_vdec_get_input_internal_buffers(__int64 a1)
{
  __int64 result; // x0

  result = msm_vidc_get_internal_buffers(a1, 7);
  if ( !(_DWORD)result )
  {
    result = msm_vidc_get_internal_buffers(a1, 9);
    if ( !(_DWORD)result )
    {
      result = msm_vidc_get_internal_buffers(a1, 10);
      if ( !(_DWORD)result )
      {
        result = msm_vidc_get_internal_buffers(a1, 11);
        if ( !(_DWORD)result )
          return msm_vidc_get_internal_buffers(a1, 15);
      }
    }
  }
  return result;
}
