__int64 __fastcall msm_vidc_alloc_and_queue_session_internal_buffers(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  const char *v5; // x4

  if ( a2 == 8 || a2 == 13 )
  {
    result = msm_vidc_get_internal_buffers(a1, a2);
    if ( !(_DWORD)result )
    {
      result = ((__int64 (__fastcall *)(__int64, _QWORD))msm_vidc_create_internal_buffers)(a1, a2);
      if ( !(_DWORD)result )
        return msm_vidc_queue_internal_buffers(a1, a2);
    }
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      if ( a2 <= 0xF )
        v5 = buf_type_name_arr[a2];
      else
        v5 = "UNKNOWN BUF";
      printk(&unk_835F8, "err ", a1 + 340, "msm_vidc_alloc_and_queue_session_internal_buffers", v5);
    }
    return 4294967274LL;
  }
  return result;
}
