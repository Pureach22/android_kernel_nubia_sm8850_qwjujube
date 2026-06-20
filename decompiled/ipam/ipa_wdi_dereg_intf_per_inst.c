__int64 __fastcall ipa_wdi_dereg_intf_per_inst(const char *a1, unsigned int a2)
{
  __int64 v3; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x24
  char *v8; // x21
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 v11; // x0
  __int64 v12; // x0
  char **v13; // x8
  char *v14; // x9
  unsigned int v15; // w21
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0

  if ( !a1 )
  {
    printk(&unk_3A87F8, "ipa_wdi_dereg_intf_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d no netdev name.\n", "ipa_wdi_dereg_intf_per_inst", 2023);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d no netdev name.\n", "ipa_wdi_dereg_intf_per_inst", 2023);
    }
    return (unsigned int)-22;
  }
  if ( a2 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_dereg_intf_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_dereg_intf_per_inst", 2028, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_dereg_intf_per_inst", 2028, a2);
    }
    return (unsigned int)-14;
  }
  v3 = ipa_wdi_ctx_list[a2];
  if ( !v3 )
  {
    printk(&unk_3F0CD4, "ipa_wdi_dereg_intf_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(v21, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_dereg_intf_per_inst", 2033);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_dereg_intf_per_inst", 2033);
      return (unsigned int)-1;
    }
    return (unsigned int)-1;
  }
  if ( a2 == 1 && *(_DWORD *)(v3 + 144) <= 1u )
  {
    printk(&unk_3E2714, "ipa_wdi_dereg_intf_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v23,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_dereg_intf_per_inst",
        2042,
        *(_DWORD *)(qword_204E60 + 144));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v24,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_dereg_intf_per_inst",
        2042,
        *(_DWORD *)(qword_204E60 + 144));
      return (unsigned int)-1;
    }
    return (unsigned int)-1;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa_wdi %s:%d Deregister Instance hdl %d\n", "ipa_wdi_dereg_intf_per_inst", 2050, a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v6, "ipa_wdi %s:%d Deregister Instance hdl %d\n", "ipa_wdi_dereg_intf_per_inst", 2050, a2);
  }
  mutex_lock(ipa_wdi_ctx_list[a2] + 48);
  v7 = ipa_wdi_ctx_list[a2];
  v8 = (char *)v7;
  do
  {
    v8 = *(char **)v8;
    if ( v8 == (char *)v7 )
    {
      v10 = 0;
      goto LABEL_25;
    }
  }
  while ( strcmp(v8 - 48, a1) );
  v9 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
  v10 = v9;
  if ( v9 )
  {
    *(_WORD *)v9 = 513;
    *(_DWORD *)(v9 + 4) = *((_DWORD *)v8 - 3);
    *(_DWORD *)(v9 + 12) = *((_DWORD *)v8 - 2);
    if ( ipa3_get_ipc_logbuf() )
    {
      v11 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v11,
        "ipa_wdi %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
        "ipa_wdi_dereg_intf_per_inst",
        2069,
        *(_DWORD *)(v10 + 4),
        *(_DWORD *)(v10 + 12));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v12,
        "ipa_wdi %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
        "ipa_wdi_dereg_intf_per_inst",
        2069,
        *(_DWORD *)(v10 + 4),
        *(_DWORD *)(v10 + 12));
    }
    if ( (unsigned int)ipa_del_hdr((_BYTE *)v10) )
    {
      printk(&unk_3B9DD7, "ipa_wdi_dereg_intf_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v25 = ipa3_get_ipc_logbuf();
        ipc_log_string(v25, "ipa_wdi %s:%d fail to delete partial header\n", "ipa_wdi_dereg_intf_per_inst", 2072);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v26 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v26, "ipa_wdi %s:%d fail to delete partial header\n", "ipa_wdi_dereg_intf_per_inst", 2072);
LABEL_57:
        v15 = -14;
        goto LABEL_26;
      }
    }
    else
    {
      if ( !(unsigned int)((__int64 (__fastcall *)(char *))ipa_deregister_intf)(v8 - 48) )
      {
        v13 = *((char ***)v8 + 1);
        if ( *v13 == v8 && (v14 = *(char **)v8, *(char **)(*(_QWORD *)v8 + 8LL) == v8) )
        {
          *((_QWORD *)v14 + 1) = v13;
          *v13 = v14;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
        }
        *(_QWORD *)v8 = 0xDEAD000000000100LL;
        *((_QWORD *)v8 + 1) = 0xDEAD000000000122LL;
        kfree(v8 - 48);
LABEL_25:
        v15 = 0;
LABEL_26:
        kfree(v10);
        mutex_unlock(ipa_wdi_ctx_list[a2] + 48);
        return v15;
      }
      printk(&unk_3C2907, "ipa_wdi_dereg_intf_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v27 = ipa3_get_ipc_logbuf();
        ipc_log_string(v27, "ipa_wdi %s:%d fail to del interface props\n", "ipa_wdi_dereg_intf_per_inst", 2078);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v28 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v28, "ipa_wdi %s:%d fail to del interface props\n", "ipa_wdi_dereg_intf_per_inst", 2078);
        goto LABEL_57;
      }
    }
    v15 = -14;
    goto LABEL_26;
  }
  printk(&unk_3BCBC0, "ipa_wdi_dereg_intf_per_inst");
  if ( ipa3_get_ipc_logbuf() )
  {
    v29 = ipa3_get_ipc_logbuf();
    ipc_log_string(v29, "ipa_wdi %s:%d fail to alloc %d bytes\n", "ipa_wdi_dereg_intf_per_inst", 2059, 20);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v30 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v30, "ipa_wdi %s:%d fail to alloc %d bytes\n", "ipa_wdi_dereg_intf_per_inst", 2059, 20);
  }
  mutex_unlock(ipa_wdi_ctx_list[a2] + 48);
  return (unsigned int)-12;
}
