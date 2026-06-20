__int64 __fastcall msm_vidc_alloc_and_queue_input_internal_buffers(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4

  result = msm_vdec_get_input_internal_buffers(a1);
  if ( !(_DWORD)result )
  {
    result = msm_vdec_release_input_internal_buffers(a1, v3, v4, v5, v6);
    if ( !(_DWORD)result )
    {
      result = msm_vdec_create_input_internal_buffers(a1);
      if ( !(_DWORD)result )
        return msm_vdec_queue_input_internal_buffers(a1);
    }
  }
  return result;
}
