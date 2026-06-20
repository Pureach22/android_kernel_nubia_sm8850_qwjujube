__int64 ipa3_clean_modem_rule()
{
  __int64 v0; // x0
  __int64 v1; // x20
  unsigned int v2; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  v0 = _kmalloc_large_noprof(42296, 3520);
  if ( v0 )
  {
    *(_BYTE *)v0 = 0;
    v1 = v0;
    *(_DWORD *)(v0 + 4) = 0;
    *(_BYTE *)(v0 + 27656) = 0;
    v2 = ipa3_qmi_filter_request_ex_send();
    kfree(v1);
  }
  else
  {
    printk(&unk_3DDBC8, "ipa3_clean_modem_rule");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d mem allocated failed!\n", "ipa3_clean_modem_rule", 818);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d mem allocated failed!\n", "ipa3_clean_modem_rule", 818);
    }
    return (unsigned int)-12;
  }
  return v2;
}
