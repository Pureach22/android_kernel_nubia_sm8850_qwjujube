__int64 cleanup_module()
{
  return gpr_driver_unregister(qcom_audio_prm_driver);
}
