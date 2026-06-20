__int64 __fastcall ipa_eth_client_unreg_intf(const char **a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x22
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 *v10; // x8
  __int64 v11; // x9
  unsigned int v12; // w20
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0

  if ( a1 )
  {
    if ( ipa_eth_ctx )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_eth %s:%d unregister interface for netdev %s\n",
          "ipa_eth_client_unreg_intf",
          1127,
          *a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_eth %s:%d unregister interface for netdev %s\n",
          "ipa_eth_client_unreg_intf",
          1127,
          *a1);
      }
      mutex_lock(ipa_eth_ctx + 192);
      v4 = ipa_eth_ctx + 288;
      v5 = ipa_eth_ctx + 288;
      do
      {
        v5 = *(_QWORD *)v5;
        if ( v5 == v4 )
        {
          v7 = 0;
          goto LABEL_22;
        }
      }
      while ( strcmp((const char *)(v5 + 16), *a1) );
      v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
      v7 = v6;
      if ( v6 )
      {
        *(_WORD *)v6 = 513;
        *(_DWORD *)(v6 + 4) = *(_DWORD *)(v5 + 52);
        *(_DWORD *)(v6 + 12) = *(_DWORD *)(v5 + 56);
        if ( ipa3_get_ipc_logbuf() )
        {
          v8 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v8,
            "ipa_eth %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
            "ipa_eth_client_unreg_intf",
            1151,
            *(_DWORD *)(v7 + 4),
            *(_DWORD *)(v7 + 12));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v9 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v9,
            "ipa_eth %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
            "ipa_eth_client_unreg_intf",
            1151,
            *(_DWORD *)(v7 + 4),
            *(_DWORD *)(v7 + 12));
        }
        if ( (unsigned int)ipa_del_hdr((_BYTE *)v7) )
        {
          printk(&unk_3E2270, "ipa_eth_client_unreg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v18 = ipa3_get_ipc_logbuf();
            ipc_log_string(v18, "ipa_eth %s:%d fail to delete partial header\n", "ipa_eth_client_unreg_intf", 1154);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v19 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v19, "ipa_eth %s:%d fail to delete partial header\n", "ipa_eth_client_unreg_intf", 1154);
LABEL_43:
            v12 = -14;
            goto LABEL_23;
          }
        }
        else
        {
          if ( !(unsigned int)((__int64 (__fastcall *)(__int64))ipa_deregister_intf)(v5 + 16) )
          {
            v10 = *(__int64 **)(v5 + 8);
            if ( *v10 == v5 && (v11 = *(_QWORD *)v5, *(_QWORD *)(*(_QWORD *)v5 + 8LL) == v5) )
            {
              *(_QWORD *)(v11 + 8) = v10;
              *v10 = v11;
            }
            else
            {
              _list_del_entry_valid_or_report(v5);
            }
            *(_QWORD *)v5 = 0xDEAD000000000100LL;
            *(_QWORD *)(v5 + 8) = 0xDEAD000000000122LL;
            kfree(v5);
LABEL_22:
            v12 = 0;
LABEL_23:
            kfree(v7);
            mutex_unlock(ipa_eth_ctx + 192);
            return v12;
          }
          printk(&unk_3A4FEA, "ipa_eth_client_unreg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v20 = ipa3_get_ipc_logbuf();
            ipc_log_string(v20, "ipa_eth %s:%d fail to del interface props\n", "ipa_eth_client_unreg_intf", 1160);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v21 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v21, "ipa_eth %s:%d fail to del interface props\n", "ipa_eth_client_unreg_intf", 1160);
            goto LABEL_43;
          }
        }
        v12 = -14;
        goto LABEL_23;
      }
      printk(&unk_3D99D4, "ipa_eth_client_unreg_intf");
      if ( ipa3_get_ipc_logbuf() )
      {
        v22 = ipa3_get_ipc_logbuf();
        ipc_log_string(v22, "ipa_eth %s:%d fail to alloc %d bytes\n", "ipa_eth_client_unreg_intf", 1141, 20);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v23 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v23, "ipa_eth %s:%d fail to alloc %d bytes\n", "ipa_eth_client_unreg_intf", 1141, 20);
      }
      mutex_unlock(ipa_eth_ctx + 192);
      return (unsigned int)-12;
    }
    else
    {
      printk(&unk_3AB226, "ipa_eth_client_unreg_intf");
      if ( ipa3_get_ipc_logbuf() )
      {
        v16 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v16,
          "ipa_eth %s:%d disconn called before register readiness\n",
          "ipa_eth_client_unreg_intf",
          1116);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v17 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v17,
          "ipa_eth %s:%d disconn called before register readiness\n",
          "ipa_eth_client_unreg_intf",
          1116);
      }
      return (unsigned int)-14;
    }
  }
  else
  {
    printk(&unk_3DCBF3, "ipa_eth_client_unreg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipa_eth %s:%d invalid params intf=%pK\n", "ipa_eth_client_unreg_intf", 1112, nullptr);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipa_eth %s:%d invalid params intf=%pK\n", "ipa_eth_client_unreg_intf", 1112, nullptr);
    }
    return (unsigned int)-22;
  }
}
