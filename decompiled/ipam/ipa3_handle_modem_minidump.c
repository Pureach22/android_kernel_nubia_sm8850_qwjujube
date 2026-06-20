long double ipa3_handle_modem_minidump()
{
  long double result; // q0
  int v1; // w0
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( (ipa_minidump_enabled() & 1) != 0 )
  {
    v1 = ipa_retrieve_and_dump();
    v2 = ipa3_ctx;
    if ( v1 )
    {
      if ( ipa3_ctx )
      {
        v3 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v3 )
        {
          result = ipc_log_string(v3, "ipa %s:%d IPA ELF DUMP Failed", "ipa3_handle_modem_minidump", 4050);
          v2 = ipa3_ctx;
        }
        v4 = *(_QWORD *)(v2 + 34160);
        if ( v4 )
          return ipc_log_string(v4, "ipa %s:%d IPA ELF DUMP Failed", "ipa3_handle_modem_minidump", 4050);
      }
    }
    else if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        result = ipc_log_string(v5, "ipa %s:%d IPA ELF DUMP Success", "ipa3_handle_modem_minidump", 4052);
        v2 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v2 + 34160);
      if ( v6 )
        return ipc_log_string(v6, "ipa %s:%d IPA ELF DUMP Success", "ipa3_handle_modem_minidump", 4052);
    }
  }
  return result;
}
