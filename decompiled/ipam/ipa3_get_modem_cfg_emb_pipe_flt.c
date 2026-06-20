__int64 ipa3_get_modem_cfg_emb_pipe_flt()
{
  __int64 v0; // x8
  __int64 v2; // x0
  __int64 v3; // x0

  if ( ipa3_ctx )
  {
    LOBYTE(v0) = *(_BYTE *)(ipa3_ctx + 32262);
  }
  else
  {
    printk(&unk_3F5EB7, "ipa3_get_modem_cfg_emb_pipe_flt");
    v0 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d IPA driver has not been initialized\n", "ipa3_get_modem_cfg_emb_pipe_flt", 11573);
        v0 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v0 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d IPA driver has not been initialized\n", "ipa3_get_modem_cfg_emb_pipe_flt", 11573);
      LOBYTE(v0) = 0;
    }
  }
  return v0 & 1;
}
