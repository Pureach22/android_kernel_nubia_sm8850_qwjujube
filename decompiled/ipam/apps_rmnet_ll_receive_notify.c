void __fastcall apps_rmnet_ll_receive_notify(__int64 a1, int a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0

  if ( a3 )
  {
    if ( a2 )
    {
      printk(&unk_3E4C79, "apps_rmnet_ll_receive_notify");
      v13 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          ipc_log_string(
            v14,
            "ipa %s:%d Invalid evt %d received in rmnet_ll\n",
            "apps_rmnet_ll_receive_notify",
            946,
            a2);
          v13 = ipa3_ctx;
        }
        v15 = *(_QWORD *)(v13 + 34160);
        if ( v15 )
          ipc_log_string(
            v15,
            "ipa %s:%d Invalid evt %d received in rmnet_ll\n",
            "apps_rmnet_ll_receive_notify",
            946,
            a2);
      }
    }
    else
    {
      v4 = *(int *)(a3 + 112);
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v5 )
          ipc_log_string(v5, "ipa %s:%d Rx packet was received", "apps_rmnet_ll_receive_notify", 934);
      }
      v6 = *(void (__fastcall **)(__int64, __int64))(rmnet_ll_ipa3_ctx + 608);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -72220 )
          __break(0x8228u);
        v6(1, a3);
        v7 = rmnet_ll_ipa3_ctx;
        v8 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 24) + v4;
        ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 8);
        *(_QWORD *)(v7 + 24) = v8;
        return;
      }
    }
    sk_skb_reason_drop(0, a3, 2);
    ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 36);
    return;
  }
  printk(&unk_3A7C0D, "apps_rmnet_ll_receive_notify");
  v9 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d Rx packet is invalid", "apps_rmnet_ll_receive_notify", 929);
      v9 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( v11 )
      ipc_log_string(v11, "ipa %s:%d Rx packet is invalid", "apps_rmnet_ll_receive_notify", 929);
  }
}
