__int64 __fastcall msm_vdec_release_input_internal_buffers(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0

  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_vdec_release_input_internal_buffers", a5);
  result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_release_internal_buffers)(a1, 7);
  if ( !(_DWORD)result )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_release_internal_buffers)(a1, 9);
    if ( !(_DWORD)result )
    {
      result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_release_internal_buffers)(a1, 10);
      if ( !(_DWORD)result )
      {
        result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_release_internal_buffers)(a1, 11);
        if ( !(_DWORD)result )
          return ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_release_internal_buffers)(a1, 15);
      }
    }
  }
  return result;
}
