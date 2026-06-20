__int64 __fastcall ipa3_read_dbg_cnt(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int reg_n; // w0
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
  {
    printk(&unk_3E60BA, "ipa3_read_dbg_cnt");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d IPA_DEBUG_CNT_REG is not supported in IPA 4.0\n", "ipa3_read_dbg_cnt", 2210);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d IPA_DEBUG_CNT_REG is not supported in IPA 4.0\n", "ipa3_read_dbg_cnt", 2210);
    }
    result = -1;
  }
  else
  {
    ipa3_inc_client_enable_clks();
    reg_n = ipahal_read_reg_n(56, 0);
    v8 = scnprintf(dbg_buff, 4096, "IPA_DEBUG_CNT_REG_0=0x%x\n", reg_n);
    ipa3_dec_client_disable_clks();
    result = simple_read_from_buffer(a2, a3, a4, dbg_buff, v8);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
