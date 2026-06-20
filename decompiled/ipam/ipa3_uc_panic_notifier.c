__int64 __fastcall ipa3_uc_panic_notifier(const void *a1, __int64 a2, const void *a3)
{
  __int64 v3; // x8
  __int64 v6; // x0
  __int64 v8; // x0
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d this=%pK evt=%lu ptr=%pK\n", "ipa3_uc_panic_notifier", 800, a1, a2, a3);
      v3 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v3 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d this=%pK evt=%lu ptr=%pK\n", "ipa3_uc_panic_notifier", 800, a1, a2, a3);
  }
  if ( !(unsigned int)ipa3_uc_state_check() && !(unsigned int)ipa3_inc_client_enable_clks_no_block() )
  {
    **(_BYTE **)(ipa3_ctx + 34752) = 4;
    *(_DWORD *)(ipa3_ctx + 34772) = **(unsigned __int8 **)(ipa3_ctx + 34752);
    __dsb(0xEu);
    if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
    {
      v10 = 66;
      v11 = 23;
    }
    else
    {
      v10 = 58;
      v11 = 0;
    }
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))ipahal_write_reg_mn)(v10, 0, v11, 1);
    _const_udelay(429500);
    ipa3_dec_client_disable_clks();
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d err_fatal issued\n", "ipa3_uc_panic_notifier", 827);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d err_fatal issued\n", "ipa3_uc_panic_notifier", 827);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
