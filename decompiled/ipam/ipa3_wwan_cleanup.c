__int64 ipa3_wwan_cleanup()
{
  long double v0; // q0
  __int64 v1; // x0
  int v2; // w0
  __int64 v3; // x0
  int v4; // w0
  unsigned __int64 v5; // x0
  _QWORD *v6; // x8
  __int64 result; // x0
  int v8; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x0

  platform_driver_unregister(rmnet_ipa_driver);
  v1 = *(_QWORD *)(rmnet_ipa3_ctx + 1064);
  if ( v1 )
  {
    v2 = qcom_unregister_ssr_notifier(v1, &ipa3_lcl_mdm_ssr_notifier, v0);
    if ( v2 )
    {
      v8 = v2;
      printk(&unk_3BC3F7, "ipa3_wwan_cleanup");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa-wan %s:%d Failed to unregister subsys %s notifier ret=%d\n",
          "ipa3_wwan_cleanup",
          6897,
          "mpss",
          v8);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        v0 = ipc_log_string(
               ipc_logbuf_low,
               "ipa-wan %s:%d Failed to unregister subsys %s notifier ret=%d\n",
               "ipa3_wwan_cleanup",
               6897,
               "mpss",
               v8);
      }
    }
  }
  v3 = *(_QWORD *)(rmnet_ipa3_ctx + 1072);
  if ( v3 )
  {
    v4 = qcom_unregister_ssr_notifier(v3, &ipa3_rmt_mdm_ssr_notifier, v0);
    if ( v4 )
    {
      v11 = v4;
      printk(&unk_3BC3F7, "ipa3_wwan_cleanup");
      if ( ipa3_get_ipc_logbuf() )
      {
        v12 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v12,
          "ipa-wan %s:%d Failed to unregister subsys %s notifier ret=%d\n",
          "ipa3_wwan_cleanup",
          6912,
          "esoc0",
          v11);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v13 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v13,
          "ipa-wan %s:%d Failed to unregister subsys %s notifier ret=%d\n",
          "ipa3_wwan_cleanup",
          6912,
          "esoc0",
          v11);
      }
    }
  }
  v5 = *(_QWORD *)(rmnet_ipa3_ctx + 1952);
  if ( v5 <= 0xFFFFFFFFFFFFF000LL )
  {
    debugfs_remove(v5);
    v6 = (_QWORD *)rmnet_ipa3_ctx;
    *(_QWORD *)(rmnet_ipa3_ctx + 1952) = 0;
    v6[245] = 0;
    v6[246] = 0;
    v6[247] = 0;
  }
  ipa3_qmi_cleanup();
  result = kfree(rmnet_ipa3_ctx);
  rmnet_ipa3_ctx = 0;
  return result;
}
