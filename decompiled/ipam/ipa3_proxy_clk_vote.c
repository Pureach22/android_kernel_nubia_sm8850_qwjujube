__int64 __fastcall ipa3_proxy_clk_vote(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x8
  int v3; // w10
  __int64 v4; // x0

  _ReadStatusReg(SP_EL0);
  v1 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    if ( (result & 1) != 0 && (result = ipa3_uc_loaded_check(), v1 = ipa3_ctx, !(_DWORD)result) )
    {
      if ( ipa3_ctx )
      {
        v4 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v4 )
        {
          ipc_log_string(v4, "ipa %s:%d Dup proxy vote. Ignore as uC is not yet loaded\n", "ipa3_proxy_clk_vote", 11534);
          v1 = ipa3_ctx;
        }
        result = *(_QWORD *)(v1 + 34160);
        if ( result )
          result = ipc_log_string(
                     result,
                     "ipa %s:%d Dup proxy vote. Ignore as uC is not yet loaded\n",
                     "ipa3_proxy_clk_vote",
                     11534);
      }
    }
    else
    {
      mutex_lock(v1 + 34256);
      v2 = ipa3_ctx;
      if ( *(_BYTE *)(ipa3_ctx + 34248) != 1 || *(_DWORD *)(ipa3_ctx + 34304) )
      {
        ipa3_inc_client_enable_clks();
        v2 = ipa3_ctx;
        v3 = *(_DWORD *)(ipa3_ctx + 34304);
        *(_BYTE *)(ipa3_ctx + 34248) = 1;
        *(_DWORD *)(v2 + 34304) = v3 + 1;
      }
      result = mutex_unlock(v2 + 34256);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
