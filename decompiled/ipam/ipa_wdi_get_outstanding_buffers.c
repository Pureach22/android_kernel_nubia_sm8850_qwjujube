__int64 __fastcall ipa_wdi_get_outstanding_buffers(unsigned int a1, _DWORD *a2)
{
  __int64 v2; // x8
  unsigned int v3; // w3
  unsigned int v5; // w20
  __int64 v6; // x0
  unsigned int ep_mapping; // w21
  unsigned int v8; // w1
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a2 )
  {
    if ( a1 < 2 )
    {
      v2 = ipa_wdi_ctx_list[a1];
      if ( v2 )
      {
        v3 = *(_DWORD *)(v2 + 144);
        if ( a1 != 1 || v3 > 1 )
        {
          if ( v3 < 2 )
          {
            v5 = 11;
            v6 = 10;
          }
          else if ( (unsigned int)(*(_DWORD *)(v2 + 184) + 1) >= 2 )
          {
            v5 = 17;
            v6 = 14;
          }
          else
          {
            v5 = 13;
            v6 = 12;
          }
          ep_mapping = ipa_get_ep_mapping(v6);
          v8 = ipa_get_ep_mapping(v5);
          result = 4294967282LL;
          if ( (v8 & 0x80000000) == 0 && (ep_mapping & 0x80000000) == 0 )
            return ipa3_get_outstanding_buffers_wdi3(ep_mapping, v8, a2);
          return result;
        }
        printk(&unk_3E2714, "ipa_wdi_get_outstanding_buffers");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
            "ipa_wdi_get_outstanding_buffers",
            2306,
            *(_DWORD *)(qword_204E60 + 144));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
            "ipa_wdi_get_outstanding_buffers",
            2306,
            *(_DWORD *)(qword_204E60 + 144));
          return 0xFFFFFFFFLL;
        }
      }
      else
      {
        printk(&unk_3F0CD4, "ipa_wdi_get_outstanding_buffers");
        if ( ipa3_get_ipc_logbuf() )
        {
          v15 = ipa3_get_ipc_logbuf();
          ipc_log_string(v15, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_get_outstanding_buffers", 2298);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v16 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v16, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_get_outstanding_buffers", 2298);
          return 0xFFFFFFFFLL;
        }
      }
      return 0xFFFFFFFFLL;
    }
    printk(&unk_3F6766, "ipa_wdi_get_outstanding_buffers");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_get_outstanding_buffers", 2293, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_get_outstanding_buffers", 2293, a1);
    }
    return 4294967282LL;
  }
  else
  {
    printk(&unk_3E81D6, "ipa_wdi_get_outstanding_buffers");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa_wdi %s:%d invalid params out=%pK\n", "ipa_wdi_get_outstanding_buffers", 2288, nullptr);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v11, "ipa_wdi %s:%d invalid params out=%pK\n", "ipa_wdi_get_outstanding_buffers", 2288, nullptr);
    }
    return 4294967274LL;
  }
}
