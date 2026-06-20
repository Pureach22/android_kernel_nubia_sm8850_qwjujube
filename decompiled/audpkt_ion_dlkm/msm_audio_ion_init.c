// Alternative name is 'init_module'
__int64 msm_audio_ion_init()
{
  return _platform_driver_register(msm_audio_ion_driver, &_this_module);
}
