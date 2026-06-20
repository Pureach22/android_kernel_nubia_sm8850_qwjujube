__int64 __fastcall ipa_wigig_dereg_intf(const char *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x23
  char *v5; // x20
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x0
  char **v10; // x8
  char *v11; // x9
  unsigned int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0

  if ( a1 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d netdev %s\n", "ipa_wigig_dereg_intf", 488, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d netdev %s\n", "ipa_wigig_dereg_intf", 488, a1);
    }
    if ( ipa_wigig_ctx )
    {
      mutex_lock(ipa_wigig_ctx + 16);
      v4 = ipa_wigig_ctx;
      v5 = (char *)ipa_wigig_ctx;
      do
      {
        v5 = *(char **)v5;
        if ( v5 == (char *)v4 )
        {
          v7 = 0;
          v12 = -14;
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_25;
          goto LABEL_24;
        }
      }
      while ( strcmp(v5 - 48, a1) );
      v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
      v7 = v6;
      if ( v6 )
      {
        *(_WORD *)v6 = 513;
        *(_DWORD *)(v6 + 4) = *((_DWORD *)v5 - 2);
        *(_DWORD *)(v6 + 12) = *((_DWORD *)v5 - 1);
        if ( ipa3_get_ipc_logbuf() )
        {
          v8 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v8,
            "ipa_wigig %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
            "ipa_wigig_dereg_intf",
            515,
            *(_DWORD *)(v7 + 4),
            *(_DWORD *)(v7 + 12));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v9 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v9,
            "ipa_wigig %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
            "ipa_wigig_dereg_intf",
            515,
            *(_DWORD *)(v7 + 4),
            *(_DWORD *)(v7 + 12));
        }
        if ( (unsigned int)ipa_del_hdr((_BYTE *)v7) )
        {
          printk(&unk_3E83D5, "ipa_wigig_dereg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v20 = ipa3_get_ipc_logbuf();
            ipc_log_string(v20, "ipa_wigig %s:%d fail to delete partial header\n", "ipa_wigig_dereg_intf", 519);
          }
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_54;
          v21 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v21, "ipa_wigig %s:%d fail to delete partial header\n", "ipa_wigig_dereg_intf", 519);
        }
        else
        {
          if ( !(unsigned int)((__int64 (__fastcall *)(char *))ipa_deregister_intf)(v5 - 48) )
          {
            if ( !(unsigned int)ipa_wigig_send_wlan_msg(7, v5 - 48, (int *)v5 - 4) )
            {
              v10 = *((char ***)v5 + 1);
              if ( *v10 == v5 && (v11 = *(char **)v5, *(char **)(*(_QWORD *)v5 + 8LL) == v5) )
              {
                *((_QWORD *)v11 + 1) = v10;
                *v10 = v11;
              }
              else
              {
                _list_del_entry_valid_or_report(v5);
              }
              *(_QWORD *)v5 = 0xDEAD000000000100LL;
              *((_QWORD *)v5 + 1) = 0xDEAD000000000122LL;
              kfree(v5 - 48);
              v12 = 0;
              if ( !ipa3_get_ipc_logbuf() )
              {
LABEL_25:
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v14 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(v14, "ipa_wigig %s:%d exit\n", "ipa_wigig_dereg_intf", 545);
                }
                goto LABEL_27;
              }
LABEL_24:
              v13 = ipa3_get_ipc_logbuf();
              ipc_log_string(v13, "ipa_wigig %s:%d exit\n", "ipa_wigig_dereg_intf", 545);
              goto LABEL_25;
            }
            printk(&unk_3A5654, "ipa_wigig_dereg_intf");
            if ( ipa3_get_ipc_logbuf() )
            {
              v24 = ipa3_get_ipc_logbuf();
              ipc_log_string(v24, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_dereg_intf", 533);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v25 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v25, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_dereg_intf", 533);
              goto LABEL_53;
            }
LABEL_54:
            v12 = -14;
            goto LABEL_27;
          }
          printk(&unk_3B3A7C, "ipa_wigig_dereg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v22 = ipa3_get_ipc_logbuf();
            ipc_log_string(v22, "ipa_wigig %s:%d fail to del interface props\n", "ipa_wigig_dereg_intf", 525);
          }
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_54;
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v23, "ipa_wigig %s:%d fail to del interface props\n", "ipa_wigig_dereg_intf", 525);
        }
LABEL_53:
        v12 = -14;
LABEL_27:
        kfree(v7);
        mutex_unlock(ipa_wigig_ctx + 16);
        return v12;
      }
      mutex_unlock(ipa_wigig_ctx + 16);
      return (unsigned int)-12;
    }
    else
    {
      printk(&unk_3CE6D1, "ipa_wigig_dereg_intf");
      if ( ipa3_get_ipc_logbuf() )
      {
        v18 = ipa3_get_ipc_logbuf();
        ipc_log_string(v18, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_dereg_intf", 491);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v19 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v19, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_dereg_intf", 491);
      }
      return (unsigned int)-1;
    }
  }
  else
  {
    printk(&unk_3F682B, "ipa_wigig_dereg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(v16, "ipa_wigig %s:%d no netdev name\n", "ipa_wigig_dereg_intf", 484);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v17, "ipa_wigig %s:%d no netdev name\n", "ipa_wigig_dereg_intf", 484);
    }
    return (unsigned int)-22;
  }
}
