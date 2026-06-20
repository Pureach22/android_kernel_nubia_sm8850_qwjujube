__int64 cleanup_module()
{
  __int64 result; // x0

  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_exit");
  result = platform_driver_unregister(msm_vidc_driver);
  if ( (msm_vidc_debug & 2) != 0 )
    return printk(&unk_838C0, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_exit");
  return result;
}
