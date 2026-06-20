void __fastcall ipahal_pkt_status_parse_thin(const void *a1, const void *a2)
{
  unsigned __int16 *v4; // x7
  long double v5; // q0
  __int64 ipc_logbuf_low; // x0
  void (__fastcall *v7)(const void *, const void *, long double); // x8
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0

  if ( a1 && a2 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v5 = ipc_log_string(
             ipc_logbuf_low,
             "ipahal %s:%d Parse_thin Status Packet\n",
             "ipahal_pkt_status_parse_thin",
             1963);
    }
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    {
      __break(0x5512u);
      atomic_load(v4);
      ipahal_pkt_status_exception_str(v5);
    }
    else
    {
      v7 = *(void (__fastcall **)(const void *, const void *, long double))&ipahal_pkt_status_objs[10
                                                                                                 * *(unsigned int *)ipahal_ctx
                                                                                                 + 4];
      if ( *((_DWORD *)v7 - 1) != 1173459368 )
        __break(0x8228u);
      v7(a1, a2, v5);
    }
  }
  else
  {
    printk(&unk_3C2A04, "ipahal_pkt_status_parse_thin");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Input Error: unparsed_status=%pK status=%pK\n",
        "ipahal_pkt_status_parse_thin",
        1960,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v9,
        "ipahal %s:%d Input Error: unparsed_status=%pK status=%pK\n",
        "ipahal_pkt_status_parse_thin",
        1960,
        a1,
        a2);
    }
  }
}
