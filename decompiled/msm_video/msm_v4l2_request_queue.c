__int64 msm_v4l2_request_queue()
{
  if ( (msm_vidc_debug & 4) != 0 )
    printk(&unk_90476, "low ", 0xFFFFFFFFLL, "codec", "msm_v4l2_request_queue");
  return v4l2_m2m_request_queue();
}
