void __fastcall apps_rmnet_ctl_receive_notify(__int64 a1, int a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0

  if ( a3 )
  {
    if ( a2 )
    {
      printk(&unk_3DC5AE, "apps_rmnet_ctl_receive_notify");
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(
            v15,
            "ipa %s:%d Invalid evt %d received in rmnet_ctl\n",
            "apps_rmnet_ctl_receive_notify",
            721,
            a2);
          v14 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v14 + 34160);
        if ( v16 )
          ipc_log_string(
            v16,
            "ipa %s:%d Invalid evt %d received in rmnet_ctl\n",
            "apps_rmnet_ctl_receive_notify",
            721,
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
          ipc_log_string(v5, "ipa %s:%d Rx packet was received", "apps_rmnet_ctl_receive_notify", 709);
      }
      v6 = *(void (__fastcall **)(__int64, __int64))(rmnet_ctl_ipa3_ctx + 608);
      if ( v6 )
      {
        v7 = *(_QWORD *)(rmnet_ctl_ipa3_ctx + 632);
        if ( *((_DWORD *)v6 - 1) != -72220 )
          __break(0x8228u);
        v6(v7, a3);
        v8 = rmnet_ctl_ipa3_ctx;
        v9 = *(_QWORD *)(rmnet_ctl_ipa3_ctx + 24) + v4;
        ++*(_DWORD *)(rmnet_ctl_ipa3_ctx + 8);
        *(_QWORD *)(v8 + 24) = v9;
        return;
      }
    }
    sk_skb_reason_drop(0, a3, 2);
    ++*(_DWORD *)(rmnet_ctl_ipa3_ctx + 36);
    return;
  }
  printk(&unk_3A7C0D, "apps_rmnet_ctl_receive_notify");
  v10 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d Rx packet is invalid", "apps_rmnet_ctl_receive_notify", 704);
      v10 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v10 + 34160);
    if ( v12 )
      ipc_log_string(v12, "ipa %s:%d Rx packet is invalid", "apps_rmnet_ctl_receive_notify", 704);
  }
}
