__int64 __fastcall pkt_status_parse_exception(char a1, __int64 a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a2 <= 31 )
  {
    if ( a2 > 7 )
    {
      switch ( a2 )
      {
        case 8LL:
          return 3;
        case 10LL:
          return 5;
        case 16LL:
          return 6;
      }
    }
    else
    {
      switch ( a2 )
      {
        case 0LL:
          return 0;
        case 1LL:
          return 1;
        case 4LL:
          return 2;
      }
    }
  }
  else if ( a2 <= 128 )
  {
    switch ( a2 )
    {
      case 32LL:
        return 7;
      case 64LL:
        if ( (a1 & 1) != 0 )
          return 9;
        else
          return 8;
      case 128LL:
        return 10;
    }
  }
  else if ( a2 > 135 )
  {
    if ( a2 == 136 )
      return 13;
    if ( a2 == 229 )
      return 14;
  }
  else
  {
    if ( a2 == 129 )
      return 11;
    if ( a2 == 131 )
      return 12;
  }
  printk(&unk_3EDE3A, "pkt_status_parse_exception");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d unsupported Status Exception type 0x%llx\n",
      "pkt_status_parse_exception",
      1318,
      a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipahal %s:%d unsupported Status Exception type 0x%llx\n",
      "pkt_status_parse_exception",
      1318,
      a2);
  }
  __break(0x800u);
  return 0;
}
