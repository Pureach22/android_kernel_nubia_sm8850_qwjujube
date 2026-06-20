__int64 __fastcall rndis_ipa_cleanup_module(__int64 a1, __int64 a2)
{
  if ( ipa_rndis_logbuf )
    ipc_log_context_destroy(ipa_rndis_logbuf);
  ipa_rndis_logbuf = 0;
  return printk(&unk_3F149A, a2);
}
