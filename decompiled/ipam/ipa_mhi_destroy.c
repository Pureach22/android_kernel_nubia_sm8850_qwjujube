void ipa_mhi_destroy()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  long double v3; // q0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  long double v14; // q0
  __int64 v15; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_destroy", 2147);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_destroy", 2147);
  }
  if ( ipa_mhi_client_ctx )
  {
    ipa3_deregister_client_callback(42);
    if ( (unsigned int)ipa_mhi_destroy_all_channels() )
    {
      printk(&unk_3B0E5F, "ipa_mhi_destroy");
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v13,
          "ipa_mhi_client %s:%d ipa_mhi_destroy_all_channels failed %d\n",
          "ipa_mhi_destroy",
          2159,
          -1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v15 = ipa3_get_ipc_logbuf_low();
        v14 = ipc_log_string(
                v15,
                "ipa_mhi_client %s:%d ipa_mhi_destroy_all_channels failed %d\n",
                "ipa_mhi_destroy",
                2159,
                -1);
      }
      ((void (__fastcall *)(long double))ipa_assert)(v14);
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v2 = ipa3_get_ipc_logbuf();
        ipc_log_string(v2, "ipa_mhi_client %s:%d All channels are disconnected\n", "ipa_mhi_destroy", 2162);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v4 = ipa3_get_ipc_logbuf_low();
        v3 = ipc_log_string(v4, "ipa_mhi_client %s:%d All channels are disconnected\n", "ipa_mhi_destroy", 2162);
      }
      ((void (__fastcall *)(_QWORD, long double))ipa_pm_deactivate_sync)(
        *(unsigned int *)(ipa_mhi_client_ctx + 1308),
        v3);
      ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_mhi_client_ctx + 1308));
      v5 = *(unsigned int *)(ipa_mhi_client_ctx + 1312);
      *(_DWORD *)(ipa_mhi_client_ctx + 1308) = -1;
      ((void (__fastcall *)(__int64))ipa_pm_deactivate_sync)(v5);
      v6 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_mhi_client_ctx + 1312));
      *(_DWORD *)(ipa_mhi_client_ctx + 1312) = -1;
      ipa_dma_destroy(v6);
      debugfs_remove(dent_2);
      destroy_workqueue(*(_QWORD *)(ipa_mhi_client_ctx + 32));
      kfree(ipa_mhi_client_ctx);
      ipa_mhi_client_ctx = 0;
      if ( ipa3_get_ipc_logbuf() )
      {
        v7 = ipa3_get_ipc_logbuf();
        ipc_log_string(v7, "ipa_mhi_client %s:%d IPA MHI was reset, ready for re-init\n", "ipa_mhi_destroy", 2170);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v8 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v8, "ipa_mhi_client %s:%d IPA MHI was reset, ready for re-init\n", "ipa_mhi_destroy", 2170);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v9 = ipa3_get_ipc_logbuf();
        ipc_log_string(v9, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_destroy", 2172);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v10, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_destroy", 2172);
      }
    }
  }
  else
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v11 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v11,
        "ipa_mhi_client %s:%d IPA MHI was not initialized, already destroyed\n",
        "ipa_mhi_destroy",
        2149);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v12,
        "ipa_mhi_client %s:%d IPA MHI was not initialized, already destroyed\n",
        "ipa_mhi_destroy",
        2149);
    }
  }
}
