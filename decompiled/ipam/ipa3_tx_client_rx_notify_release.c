__int64 __fastcall ipa3_tx_client_rx_notify_release(__int64 result, unsigned int a2)
{
  signed int v2; // w22
  const void *v4; // x19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x9
  __int64 (__fastcall *v9)(__int64, __int64, const void *); // x8
  __int64 v10; // x0
  unsigned int v16; // w9

  v4 = (const void *)result;
  _X8 = (unsigned int *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      result = ipc_log_string(
                 result,
                 "ipa %s:%d Received data desc anchor:%pK\n",
                 "ipa3_tx_client_rx_notify_release",
                 6107,
                 v4);
  }
  if ( a2 >= 0x24 )
  {
    __break(0x5512u);
  }
  else
  {
    v2 = a2;
    _X8 = (unsigned int *)(ipa3_ctx + 480LL * (int)a2 + 552);
  }
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 + 1, _X8) );
  ++*(_DWORD *)(ipa3_ctx + 480LL * v2 + 580);
  v6 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( !v7
      || (result = ipc_log_string(
                     v7,
                     "ipa %s:%d ep=%d fifo_desc_free_count=%d\n",
                     "ipa3_tx_client_rx_notify_release",
                     6114,
                     a2,
                     *(_DWORD *)(ipa3_ctx + 480LL * v2 + 552)),
          (v6 = ipa3_ctx) != 0) )
    {
      result = *(_QWORD *)(v6 + 34160);
      if ( result )
      {
        result = ipc_log_string(
                   result,
                   "ipa %s:%d calling client notify callback with priv:%pK\n",
                   "ipa3_tx_client_rx_notify_release",
                   6116,
                   *(const void **)(v6 + 480LL * v2 + 536));
        v6 = ipa3_ctx;
      }
    }
  }
  v8 = v6 + 480LL * v2;
  v9 = *(__int64 (__fastcall **)(__int64, __int64, const void *))(v8 + 544);
  if ( v9 )
  {
    v10 = *(_QWORD *)(v8 + 536);
    if ( *((_DWORD *)v9 - 1) != 420538815 )
      __break(0x8228u);
    result = v9(v10, 1, v4);
    ++*(_DWORD *)(ipa3_ctx + 480LL * v2 + 588);
  }
  return result;
}
