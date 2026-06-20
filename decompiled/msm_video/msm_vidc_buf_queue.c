__int64 __fastcall msm_vidc_buf_queue(__int64 a1, __int64 a2)
{
  msm_vidc_scale_power(a1, *(_DWORD *)(a2 + 24) == 1);
  return ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_queue_buffer)(a1, a2);
}
