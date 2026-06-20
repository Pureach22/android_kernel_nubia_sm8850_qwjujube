__int64 ipa3_proxy_clk_unvote()
{
  __int64 v0; // x8
  int v1; // w10
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_ctx )
  {
    mutex_lock(ipa3_ctx + 34256);
    v0 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 34248) == 1 )
    {
      ipa3_dec_client_disable_clks();
      v0 = ipa3_ctx;
      v1 = *(_DWORD *)(ipa3_ctx + 34304) - 1;
      *(_DWORD *)(ipa3_ctx + 34304) = v1;
      if ( !v1 )
        *(_BYTE *)(v0 + 34248) = 0;
    }
    result = mutex_unlock(v0 + 34256);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
