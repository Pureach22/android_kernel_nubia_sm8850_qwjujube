__int64 msm_vidc_release_video_device()
{
  __int64 result; // x0

  if ( (msm_vidc_debug & 1) != 0 )
    return printk(&unk_83927, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_release_video_device");
  return result;
}
