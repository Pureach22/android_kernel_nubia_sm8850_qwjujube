__int64 __fastcall ipa_pm_destroy(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v2; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0

  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v2 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v2, "ipa_pm %s:%d IPA PM destroy started\n", "ipa_pm_destroy", 715);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v4 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v4, "ipa_pm %s:%d IPA PM destroy started\n", "ipa_pm_destroy", 715);
  }
  if ( ipa_pm_ctx )
  {
    destroy_workqueue(*(_QWORD *)(ipa_pm_ctx + 576));
    kfree(ipa_pm_ctx);
    result = 0;
    ipa_pm_ctx = 0;
  }
  else
  {
    v6 = printk(&unk_3E1390, "ipa_pm_destroy");
    v7 = ipa3_get_ipc_logbuf(v6);
    if ( v7 )
    {
      v8 = ipa3_get_ipc_logbuf(v7);
      v7 = ipc_log_string(v8, "ipa_pm %s:%d Already destroyed\n", "ipa_pm_destroy", 718);
    }
    v9 = ipa3_get_ipc_logbuf_low(v7);
    if ( v9 )
    {
      v10 = ipa3_get_ipc_logbuf_low(v9);
      ipc_log_string(v10, "ipa_pm %s:%d Already destroyed\n", "ipa_pm_destroy", 718);
    }
    return 0xFFFFFFFFLL;
  }
  return result;
}
