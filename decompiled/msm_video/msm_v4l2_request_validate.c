__int64 msm_v4l2_request_validate()
{
  if ( (msm_vidc_debug & 4) != 0 )
    printk(&unk_90476, "low ", 0xFFFFFFFFLL, "codec", "msm_v4l2_request_validate");
  return vb2_request_validate();
}
