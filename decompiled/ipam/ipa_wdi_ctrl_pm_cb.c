long double __fastcall ipa_wdi_ctrl_pm_cb(__int64 a1, int a2)
{
  __int64 ipc_logbuf; // x0
  long double result; // q0
  __int64 ipc_logbuf_low; // x0
  void (__fastcall *v6)(__int64, __int64, long double); // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d received ctrl pm event %d\n", "ipa_wdi_ctrl_pm_cb", 185, a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    result = ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d received ctrl pm event %d\n", "ipa_wdi_ctrl_pm_cb", 185, a2);
  }
  if ( !a2 )
  {
    if ( dword_204EB0 && (v6 = (void (__fastcall *)(__int64, __int64, long double))off_204E98) != nullptr )
    {
      v7 = qword_204EB8;
      if ( *((_DWORD *)off_204E98 - 1) != -1297827279 )
        __break(0x8228u);
      v6(v7, 1, result);
    }
    else
    {
      printk(&unk_3F9F05, "ipa_wdi_ctrl_pm_cb");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          result = ipc_log_string(v9, "ipa %s:%d clock cb not registered", "ipa_wdi_ctrl_pm_cb", 190);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          return ipc_log_string(v10, "ipa %s:%d clock cb not registered", "ipa_wdi_ctrl_pm_cb", 190);
      }
    }
  }
  return result;
}
