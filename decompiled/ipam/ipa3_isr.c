__int64 ipa3_isr()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_ctx )
  {
    v0 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v0 )
      ipc_log_string(v0, "ipa %s:%d Enter\n", "ipa3_isr", 404);
  }
  if ( (unsigned int)ipa3_inc_client_enable_clks_no_block() )
  {
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d defer interrupt processing\n", "ipa3_isr", 407);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d defer interrupt processing\n", "ipa3_isr", 407);
        v1 = ipa3_ctx;
      }
    }
    queue_work_on(32, *(_QWORD *)(v1 + 31944), &ipa3_interrupt_defer_work);
  }
  else
  {
    ((void (__fastcall *)(__int64))ipa3_process_interrupts)(1);
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d Exit\n", "ipa3_isr", 413);
    }
    ipa3_dec_client_disable_clks_no_block();
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
