__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _gpr_driver_register(qcom_audio_prm_driver, &_this_module);
  if ( v0 )
    printk(&unk_6FEF, "audio_prm_module_init");
  _mutex_init(&unk_6D28, "&g_prm.lock", &audio_prm_module_init___key);
  return v0;
}
