__int64 ipa3_wwan_platform_driver_register()
{
  unsigned int v0; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v0 = _platform_driver_register(rmnet_ipa_driver, &_this_module);
  if ( !v0 )
    goto LABEL_7;
  if ( !(unsigned int)__ratelimit(&ipa3_wwan_platform_driver_register__rs, "ipa3_wwan_platform_driver_register") )
  {
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_5;
    goto LABEL_4;
  }
  printk(&unk_3D0BA8, "ipa3_wwan_platform_driver_register");
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_4:
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d rmnet_ipa driver register fail rc=%d\n",
      "ipa3_wwan_platform_driver_register",
      6617,
      v0);
  }
LABEL_5:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d rmnet_ipa driver register fail rc=%d\n",
      "ipa3_wwan_platform_driver_register",
      6617,
      v0);
  }
LABEL_7:
  ipa_net_initialized = 1;
  return v0;
}
