void ipa3_dec_client_disable_clks_no_block()
{
  unsigned int v1; // w10
  unsigned int v7; // w12
  __int64 v8; // x0

  _X9 = (unsigned int *)(ipa3_ctx + 30552);
  v1 = *(_DWORD *)(ipa3_ctx + 30552);
  do
  {
    if ( v1 == 1 )
    {
      queue_delayed_work_on(32, *(_QWORD *)(ipa3_ctx + 31944), &ipa_dec_clients_disable_clks_on_wq_work, 0);
      return;
    }
    __asm { PRFM            #0x11, [X9] }
    while ( 1 )
    {
      v7 = __ldxr(_X9);
      if ( v7 != v1 )
        break;
      if ( !__stlxr(v1 - 1, _X9) )
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
    v8 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v8 )
      ipc_log_string(
        v8,
        "ipa %s:%d active clients = %d\n",
        "ipa3_dec_client_disable_clks_no_block",
        7177,
        *(_DWORD *)(ipa3_ctx + 30552));
  }
}
