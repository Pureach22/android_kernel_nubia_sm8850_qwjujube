__int64 __fastcall ipa3_set_wlan_quota(__int64 a1)
{
  void (__fastcall *v1)(__int64, __int64); // x8
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  v1 = *(void (__fastcall **)(__int64, __int64))(ipa3_ctx + 43176);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != 295462364 )
      __break(0x8228u);
    v1(1, a1);
    return 0;
  }
  else
  {
    printk(&unk_3B2FA1, "ipa3_set_wlan_quota");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d uc_wdi_ctx.stats_notify NULL\n", "ipa3_set_wlan_quota", 8518);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d uc_wdi_ctx.stats_notify NULL\n", "ipa3_set_wlan_quota", 8518);
    }
    return 4294967282LL;
  }
}
