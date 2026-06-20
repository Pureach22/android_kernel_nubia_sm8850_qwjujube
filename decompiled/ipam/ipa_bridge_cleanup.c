__int64 __fastcall ipa_bridge_cleanup(unsigned int a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x10
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v12; // x0
  long double v13; // q0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0

  if ( !ipa_gsb_ctx )
  {
    printk(&unk_3C85BE, "ipa_bridge_cleanup");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_cleanup", 623);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_cleanup", 623);
    }
    return 4294967282LL;
  }
  if ( a1 < 5 )
  {
    v2 = a1;
    mutex_lock(ipa_gsb_ctx + 48LL * a1 + 136);
    if ( *(_QWORD *)(ipa_gsb_ctx + 8LL * a1 + 96) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v3 = ipa3_get_ipc_logbuf();
        ipc_log_string(v3, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_cleanup", 639, a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v4 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v4, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_cleanup", 639, a1);
      }
      v5 = *(_QWORD *)(ipa_gsb_ctx + 8LL * a1 + 96);
      if ( *(_BYTE *)(v5 + 104) != 1 )
      {
        ipa_gsb_dereg_intf_props((const char *)v5);
        v6 = 8LL * a1;
        ipa_gsb_delete_partial_hdr(*(_QWORD *)(ipa_gsb_ctx + 8 * v2 + 96));
        raw_spin_lock_bh(ipa_gsb_ctx + 4 * v2 + 376);
        kfree(*(_QWORD *)(ipa_gsb_ctx + v6 + 96));
        v7 = ipa_gsb_ctx + v2;
        v8 = ipa_gsb_ctx + 4 * v2 + 376;
        *(_QWORD *)(ipa_gsb_ctx + v6 + 96) = 0;
        *(_BYTE *)(v7 + 80) = 0;
        raw_spin_unlock_bh(v8);
        mutex_unlock(ipa_gsb_ctx + 48LL * (unsigned int)v2 + 136);
        mutex_lock(ipa_gsb_ctx + 16);
        --*(_DWORD *)(ipa_gsb_ctx + 76);
        if ( ipa3_get_ipc_logbuf() )
        {
          v9 = ipa3_get_ipc_logbuf();
          ipc_log_string(v9, "ipa_gsb %s:%d num_iface %d\n", "ipa_bridge_cleanup", 656, *(_DWORD *)(ipa_gsb_ctx + 76));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v10 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v10, "ipa_gsb %s:%d num_iface %d\n", "ipa_bridge_cleanup", 656, *(_DWORD *)(ipa_gsb_ctx + 76));
        }
        if ( *(_DWORD *)(ipa_gsb_ctx + 76) )
        {
          mutex_unlock(ipa_gsb_ctx + 16);
          return 0;
        }
        else
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v12 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v12,
              "ipa_gsb %s:%d deregister ipa pm hdl: %d\n",
              "ipa_gsb_deregister_pm",
              612,
              *(_DWORD *)(ipa_gsb_ctx + 396));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v14 = ipa3_get_ipc_logbuf_low();
            v13 = ipc_log_string(
                    v14,
                    "ipa_gsb %s:%d deregister ipa pm hdl: %d\n",
                    "ipa_gsb_deregister_pm",
                    612,
                    *(_DWORD *)(ipa_gsb_ctx + 396));
          }
          ((void (__fastcall *)(_QWORD, long double))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_gsb_ctx + 396), v13);
          ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_gsb_ctx + 396));
          v15 = dent_1;
          *(_DWORD *)(ipa_gsb_ctx + 396) = -1;
          debugfs_remove(v15);
          ipc_log_context_destroy(*(_QWORD *)ipa_gsb_ctx);
          ipc_log_context_destroy(*(_QWORD *)(ipa_gsb_ctx + 8));
          mutex_unlock(ipa_gsb_ctx + 16);
          kfree(ipa_gsb_ctx);
          ipa_gsb_ctx = 0;
          return 0;
        }
      }
      printk(&unk_3F07CD, "ipa_bridge_cleanup");
      if ( ipa3_get_ipc_logbuf() )
      {
        v22 = ipa3_get_ipc_logbuf();
        ipc_log_string(v22, "ipa_gsb %s:%d cannot cleanup when iface is connected\n", "ipa_bridge_cleanup", 642);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v23 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v23, "ipa_gsb %s:%d cannot cleanup when iface is connected\n", "ipa_bridge_cleanup", 642);
      }
    }
    else
    {
      printk(&unk_3AB2AC, "ipa_bridge_cleanup");
      if ( ipa3_get_ipc_logbuf() )
      {
        v20 = ipa3_get_ipc_logbuf();
        ipc_log_string(v20, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_cleanup", 634, a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v21 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v21, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_cleanup", 634, a1);
      }
    }
    mutex_unlock(ipa_gsb_ctx + 48LL * (unsigned int)v2 + 136);
    return 4294967282LL;
  }
  printk(&unk_3E7C9B, "ipa_bridge_cleanup");
  if ( ipa3_get_ipc_logbuf() )
  {
    v18 = ipa3_get_ipc_logbuf();
    ipc_log_string(v18, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_cleanup", 628, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v19 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v19, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_cleanup", 628, a1);
  }
  return 4294967274LL;
}
