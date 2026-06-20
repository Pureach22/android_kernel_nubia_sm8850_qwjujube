// Alternative name is 'cleanup_module'
__int64 msm_audio_ion_exit()
{
  return platform_driver_unregister(msm_audio_ion_driver);
}
