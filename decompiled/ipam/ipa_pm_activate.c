__int64 __fastcall ipa_pm_activate(unsigned int a1)
{
  __int64 v1; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 v10; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0

  if ( !ipa_pm_ctx )
  {
    v8 = printk(&unk_3F575E, "ipa_pm_activate");
    ipc_logbuf = ipa3_get_ipc_logbuf(v8);
    if ( ipc_logbuf )
    {
      v10 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v10, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_activate", 1021);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v12 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v12, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_activate", 1021);
    }
    return 4294967274LL;
  }
  if ( a1 > 0x23 || (v1 = *(_QWORD *)(ipa_pm_ctx + 8LL * a1)) == 0 )
  {
    v3 = printk(&unk_3B8628, "ipa_pm_activate");
    v4 = ipa3_get_ipc_logbuf(v3);
    if ( v4 )
    {
      v5 = ipa3_get_ipc_logbuf(v4);
      v4 = ipc_log_string(v5, "ipa_pm %s:%d Invalid Param\n", "ipa_pm_activate", 1026);
    }
    v6 = ipa3_get_ipc_logbuf_low(v4);
    if ( v6 )
    {
      v7 = ipa3_get_ipc_logbuf_low(v6);
      ipc_log_string(v7, "ipa_pm %s:%d Invalid Param\n", "ipa_pm_activate", 1026);
    }
    return 4294967274LL;
  }
  return ipa_pm_activate_helper(v1, 0);
}
