__int64 __fastcall msm_vdec_streamoff_output(__int64 a1)
{
  __int64 v1; // x19

  if ( a1 )
  {
    v1 = a1;
    cancel_delayed_work(a1 + 3688);
  }
  else
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return msm_vidc_session_streamoff(a1, 1);
    v1 = 0;
    printk(&unk_8E20F, "err ", 0xFFFFFFFFLL, "codec", "cancel_batch_work");
  }
  a1 = v1;
  return msm_vidc_session_streamoff(a1, 1);
}
