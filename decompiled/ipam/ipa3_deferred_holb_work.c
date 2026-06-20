__int64 ipa3_deferred_holb_work()
{
  unsigned int v0; // w19
  __int64 v1; // x0
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  void (__fastcall *v5)(__int64, __int64, __int64, __int64); // x8
  __int64 result; // x0
  int v7; // w19
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0

  _ReadStatusReg(SP_EL0);
  v0 = *(_DWORD *)(ipa3_ctx + 34916);
  ipa3_inc_client_enable_clks();
  v1 = ipa3_uc_enable_holb_monitor(v0);
  if ( (_DWORD)v1 )
  {
    v7 = v1;
    printk(&unk_3C795F, "ipa3_deferred_holb_work");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Failed to enable HOLB monitoring %d\n", "ipa3_deferred_holb_work", 389, v7);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d Failed to enable HOLB monitoring %d\n", "ipa3_deferred_holb_work", 389, v7);
    }
  }
  else if ( (*(_BYTE *)(ipa3_ctx + 34856) & 1) == 0 && (v1 = ipa3_uc_setup_event_ring(v1, v2, v3, v4), (_DWORD)v1) )
  {
    printk(&unk_3FE923, "ipa3_deferred_holb_work");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d failed to set uc event ring\n", "ipa3_deferred_holb_work", 394);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d failed to set uc event ring\n", "ipa3_deferred_holb_work", 394);
    }
  }
  else
  {
    v5 = (void (__fastcall *)(__int64, __int64, __int64, __int64))off_2014D0;
    if ( off_2014D0 )
    {
      if ( *((_DWORD *)off_2014D0 - 1) != -440107680 )
        __break(0x8228u);
      v5(v1, v2, v3, v4);
    }
  }
  result = ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return result;
}
