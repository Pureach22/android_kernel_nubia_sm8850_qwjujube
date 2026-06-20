void __fastcall ipahal_get_aggr_force_close_valmask(__int16 a1, __int64 a2)
{
  unsigned int v2; // w3
  int v3; // w8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf; // x0
  long double v7; // q0
  __int64 ipc_logbuf_low; // x0

  if ( a2 )
  {
    *(_QWORD *)a2 = 0;
    v2 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx < 0xCu )
    {
      v3 = 0x3FFFFFFF;
LABEL_21:
      *(_DWORD *)a2 = v3 & (1 << a1);
      *(_DWORD *)(a2 + 4) = v3;
      return;
    }
    if ( v2 < 0xE )
    {
      v3 = 0xFFFFF;
      goto LABEL_21;
    }
    if ( v2 < 0x10 )
      goto LABEL_7;
    if ( v2 == 16 )
    {
      v3 = 0x1FFFF;
      goto LABEL_21;
    }
    if ( v2 < 0x12 )
    {
      v3 = 0x7FFFFFFF;
      goto LABEL_21;
    }
    if ( v2 < 0x14 )
    {
LABEL_7:
      v3 = 0x7FFFFF;
      goto LABEL_21;
    }
    if ( v2 <= 0x18 )
    {
      if ( (a1 & 0x1FE0) != 0 )
        v3 = 15;
      else
        v3 = -1;
      goto LABEL_21;
    }
    printk(&unk_3DA5BA, "ipahal_get_aggr_force_close_valmask");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d unknown ipa ver %d\n",
        "ipahal_get_aggr_force_close_valmask",
        5780,
        *(_DWORD *)ipahal_ctx);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v7 = ipc_log_string(
             ipc_logbuf_low,
             "ipahal %s:%d unknown ipa ver %d\n",
             "ipahal_get_aggr_force_close_valmask",
             5780,
             *(_DWORD *)ipahal_ctx);
    }
    ((void (__fastcall *)(long double))ipa_assert)(v7);
  }
  else
  {
    printk(&unk_3C8D08, "ipahal_get_aggr_force_close_valmask");
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(v4, "ipahal %s:%d Input error\n", "ipahal_get_aggr_force_close_valmask", 5735);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v5, "ipahal %s:%d Input error\n", "ipahal_get_aggr_force_close_valmask", 5735);
    }
  }
}
