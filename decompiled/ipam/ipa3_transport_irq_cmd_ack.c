__int64 __fastcall ipa3_transport_irq_cmd_ack(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0

  if ( a1 )
  {
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v2 )
        ipc_log_string(
          v2,
          "ipa %s:%d got ack for cmd=%d\n",
          "ipa3_transport_irq_cmd_ack",
          900,
          *(unsigned __int16 *)(a1 + 36));
    }
    return complete(a1 + 64);
  }
  else
  {
    result = _warn_printk("desc is NULL");
    __break(0x800u);
  }
  return result;
}
