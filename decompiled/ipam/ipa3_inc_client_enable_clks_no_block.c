__int64 ipa3_inc_client_enable_clks_no_block()
{
  unsigned int v1; // w10
  unsigned int v7; // w12
  __int64 result; // x0

  _X9 = (unsigned int *)(ipa3_ctx + 30552);
  v1 = *(_DWORD *)(ipa3_ctx + 30552);
  do
  {
    if ( !v1 )
      return 0xFFFFFFFFLL;
    __asm { PRFM            #0x11, [X9] }
    while ( 1 )
    {
      v7 = __ldxr(_X9);
      if ( v7 != v1 )
        break;
      if ( !__stlxr(v1 + 1, _X9) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v7 == v1;
    v1 = v7;
  }
  while ( !_ZF );
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( !result )
      return result;
    ipc_log_string(
      result,
      "ipa %s:%d active clients = %d\n",
      "ipa3_inc_client_enable_clks_no_block",
      7045,
      *(_DWORD *)(ipa3_ctx + 30552));
  }
  return 0;
}
