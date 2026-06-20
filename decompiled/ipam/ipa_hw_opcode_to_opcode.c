__int64 __fastcall ipa_hw_opcode_to_opcode(unsigned __int8 a1)
{
  int v1; // w19
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v1 = a1;
  if ( a1 <= 7u )
  {
    switch ( a1 )
    {
      case 1u:
        return 0;
      case 2u:
        return 1;
      case 4u:
        return 2;
    }
  }
  else if ( a1 > 0x1Fu )
  {
    if ( a1 == 32 )
      return 5;
    if ( a1 == 64 )
      return 6;
  }
  else
  {
    if ( a1 == 8 )
      return 3;
    if ( a1 == 16 )
      return 4;
  }
  if ( !(unsigned int)__ratelimit(&ipa_hw_opcode_to_opcode__rs, "ipa_hw_opcode_to_opcode") )
  {
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_16;
    goto LABEL_15;
  }
  printk(&unk_3E53CD, "ipa_hw_opcode_to_opcode");
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_15:
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d unsupported Status Opcode 0x%x\n", "ipa_hw_opcode_to_opcode", 1629, v1);
  }
LABEL_16:
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d unsupported Status Opcode 0x%x\n", "ipa_hw_opcode_to_opcode", 1629, v1);
    return 0;
  }
  return result;
}
