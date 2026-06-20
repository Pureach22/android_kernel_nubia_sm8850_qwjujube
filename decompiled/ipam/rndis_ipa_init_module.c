__int64 rndis_ipa_init_module()
{
  __int64 v0; // x1

  ipa_rndis_logbuf = ipc_log_context_create(50, "ipa_rndis", 0x10000);
  if ( !ipa_rndis_logbuf )
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3CB80E, "rndis_ipa_init_module");
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d failed to create IPC log, continue...\n",
        "rndis_ipa_init_module",
        2575);
  }
  printk(&unk_3A5D4C, v0);
  return 0;
}
