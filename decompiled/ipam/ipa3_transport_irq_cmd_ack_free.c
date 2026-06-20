__int64 __fastcall ipa3_transport_irq_cmd_ack_free(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int v11; // w8
  unsigned int v12; // w8

  if ( a1 )
  {
    result = complete(a1);
    _X9 = (unsigned int *)(a1 + 32);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v11 = __ldxr(_X9);
      v12 = v11 - 1;
    }
    while ( __stlxr(v12, _X9) );
    __dmb(0xBu);
    if ( !v12 )
      return kfree(a1);
  }
  else
  {
    result = printk(&unk_3E39DD, "ipa3_transport_irq_cmd_ack_free");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d comp is NULL\n", "ipa3_transport_irq_cmd_ack_free", 919);
        v3 = ipa3_ctx;
      }
      result = *(_QWORD *)(v3 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d comp is NULL\n", "ipa3_transport_irq_cmd_ack_free", 919);
    }
  }
  return result;
}
