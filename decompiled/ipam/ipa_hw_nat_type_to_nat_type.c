__int64 __fastcall ipa_hw_nat_type_to_nat_type(__int64 result)
{
  int v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( (unsigned int)result >= 3 )
  {
    v1 = result;
    if ( (unsigned int)__ratelimit(&ipa_hw_nat_type_to_nat_type__rs, "ipa_hw_nat_type_to_nat_type") )
    {
      printk(&unk_3FFD8A, "ipa_hw_nat_type_to_nat_type");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_5:
        result = ipa3_get_ipc_logbuf_low();
        if ( result )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d unsupported Status NAT type 0x%x\n",
            "ipa_hw_nat_type_to_nat_type",
            1651,
            v1);
          return 0;
        }
        return result;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_5;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d unsupported Status NAT type 0x%x\n",
      "ipa_hw_nat_type_to_nat_type",
      1651,
      v1);
    goto LABEL_5;
  }
  return result;
}
