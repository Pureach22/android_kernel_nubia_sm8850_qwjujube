__int64 __fastcall ipa3_get_outstanding_buffers_wdi3(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  _ReadStatusReg(SP_EL0);
  if ( a3 )
  {
    ipa3_inc_client_enable_clks();
    *a3 = gsi_get_outstanding_buffers(a2);
    a3[1] = gsi_get_outstanding_buffers(a1);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  else
  {
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d invalid params out\n", "ipa3_get_outstanding_buffers_wdi3", 1604);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d invalid params out\n", "ipa3_get_outstanding_buffers_wdi3", 1604);
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
