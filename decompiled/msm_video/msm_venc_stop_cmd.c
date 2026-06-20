__int64 __fastcall msm_venc_stop_cmd(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9769A, "high", a1 + 340, a4, a5);
  return msm_vidc_process_drain();
}
