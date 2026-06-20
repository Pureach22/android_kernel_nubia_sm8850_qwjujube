__int64 __fastcall ipa3_ap_freeze(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x19
  __int64 v9; // x11
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  int v19; // w10
  unsigned __int64 v20; // x19
  __int64 v21; // x21
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d Enter\n", "ipa3_ap_freeze", 12014);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d Enter\n", "ipa3_ap_freeze", 12014);
  }
  result = of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,ipa");
  if ( (_DWORD)result )
  {
    v6 = ipa3_ctx;
    v7 = *(unsigned int *)(ipa3_ctx + 34308);
    if ( !(_DWORD)v7 )
    {
LABEL_18:
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d Enter hibernate freeze\n", "ipa3_ap_freeze", 12028);
          v6 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v6 + 34160);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d Enter hibernate freeze\n", "ipa3_ap_freeze", 12028);
          v6 = ipa3_ctx;
        }
        if ( v6 )
        {
          v15 = *(_QWORD *)(v6 + 34152);
          if ( v15 )
          {
            ipc_log_string(v15, "ipa %s:%d Entry\n", "ipa3_deepsleep_suspend", 12069);
            v6 = ipa3_ctx;
          }
          v16 = *(_QWORD *)(v6 + 34160);
          if ( v16 )
            ipc_log_string(v16, "ipa %s:%d Entry\n", "ipa3_deepsleep_suspend", 12069);
        }
      }
      ipa3_inc_client_enable_clks_no_log();
      v18 = ipa3_ctx;
      v19 = *(unsigned __int8 *)(ipa3_ctx + 45390);
      *(_BYTE *)(ipa3_ctx + 45220) = 1;
      if ( v19 == 1 )
      {
        v17 = napi_disable(v18 + 48128);
        v18 = ipa3_ctx;
      }
      *(_BYTE *)(v18 + 34657) = 0;
      ipa3_teardown_apps_pipes(v17);
      gsi_deregister_device(*(_QWORD *)(ipa3_ctx + 43296), 0);
      idr_destroy(ipa3_ctx + 28584);
      idr_destroy(ipa3_ctx + 28608);
      if ( *(_DWORD *)(ipa3_ctx + 34308) )
      {
        v20 = 0;
        v21 = 17928;
        do
        {
          if ( (ipa_is_ep_support_flt((unsigned int)v20) & 1) != 0 )
          {
            if ( v20 > 0x23 )
              goto LABEL_54;
            *(_QWORD *)(ipa3_ctx + v21 - 152) = 0;
            *(_QWORD *)(ipa3_ctx + v21) = 0;
          }
          ++v20;
          v21 += 304;
        }
        while ( v20 < *(unsigned int *)(ipa3_ctx + 34308) );
      }
      ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(13);
      v22 = ipa3_interrupts_destroy((unsigned int)dword_1F7DCC, *(_QWORD *)(ipa3_ctx + 34208) + 16LL);
      v23 = ipa3_uc_interface_destroy(v22);
      v24 = ipa3_nat_ipv6ct_destroy_devices(v23);
      v25 = ipa3_free_coal_close_frame(v24);
      v26 = ipa3_free_dma_task_for_gsi(v25);
      ipahal_destroy(v26);
      *(_BYTE *)(ipa3_ctx + 43637) = 0;
      v27 = atomic_notifier_chain_unregister(&panic_notifier_list, &ipa3_panic_blk);
      v28 = ipa3_wigig_deinit_i(v27);
      ipa3_debugfs_remove(v28);
      _ipa3_dec_client_disable_clks();
      v30 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v31 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v31 )
        {
          ipc_log_string(v31, "ipa %s:%d Exit\n", "ipa3_deepsleep_suspend", 12102);
          v30 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v30 + 34160);
        if ( v29 )
        {
          v29 = ipc_log_string(v29, "ipa %s:%d Exit\n", "ipa3_deepsleep_suspend", 12102);
          v30 = ipa3_ctx;
        }
        if ( v30 )
        {
          v32 = *(_QWORD *)(v30 + 34152);
          if ( v32 )
          {
            ipc_log_string(v32, "ipa %s:%d Exit hibernate freeze\n", "ipa3_ap_freeze", 12030);
            v30 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v30 + 34160);
          if ( v29 )
            v29 = ipc_log_string(v29, "ipa %s:%d Exit hibernate freeze\n", "ipa3_ap_freeze", 12030);
        }
      }
      ipa_pm_deactivate_all_deferred(v29);
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(v34, "ipa %s:%d Exit\n", "ipa3_ap_freeze", 12034);
          v33 = ipa3_ctx;
        }
        result = *(_QWORD *)(v33 + 34160);
        if ( !result )
          return result;
        ipc_log_string(result, "ipa %s:%d Exit\n", "ipa3_ap_freeze", 12034);
      }
      return 0;
    }
    v8 = 0;
    v9 = ipa3_ctx + 640;
    while ( 1 )
    {
      if ( v8 == 36 )
      {
LABEL_54:
        __break(0x5512u);
        return ipa3_ap_resume();
      }
      if ( *(_QWORD *)v9 && *(_DWORD *)(*(_QWORD *)v9 + 4LL) )
        break;
      ++v8;
      v9 += 480;
      if ( v7 == v8 )
        goto LABEL_18;
    }
    printk(&unk_3C3105, "ipa3_ap_freeze");
    v10 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967285LL;
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d EP %d is in polling state, do not suspend\n", "ipa3_ap_freeze", 12023, v8);
      v10 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v10 + 34160);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d EP %d is in polling state, do not suspend\n", "ipa3_ap_freeze", 12023, v8);
      return 4294967285LL;
    }
    else
    {
      return 4294967285LL;
    }
  }
  return result;
}
