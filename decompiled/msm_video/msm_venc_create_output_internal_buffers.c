__int64 __fastcall msm_venc_create_output_internal_buffers(__int64 a1)
{
  __int64 result; // x0

  result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_create_internal_buffers)(a1, 7);
  if ( !(_DWORD)result )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_create_internal_buffers)(a1, 9);
    if ( !(_DWORD)result )
    {
      result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_create_internal_buffers)(a1, 10);
      if ( !(_DWORD)result )
      {
        result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_create_internal_buffers)(a1, 11);
        if ( !(_DWORD)result )
          return ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_create_internal_buffers)(a1, 12);
      }
    }
  }
  return result;
}
