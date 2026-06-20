__int64 __fastcall ipa3_get_wlan_stats(__int64 a1)
{
  _DWORD *v1; // x8
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  v1 = *(_DWORD **)(ipa3_ctx + 43176);
  if ( !v1 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_get_wlan_stats__rs, "ipa3_get_wlan_stats") )
    {
      printk(&unk_3B2FA1, "ipa3_get_wlan_stats");
      v3 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_7;
    }
    else
    {
      v3 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_7:
        v4 = *(_QWORD *)(v3 + 34152);
        if ( v4 )
        {
          ipc_log_string(v4, "ipa %s:%d uc_wdi_ctx.stats_notify NULL\n", "ipa3_get_wlan_stats", 8500);
          v3 = ipa3_ctx;
        }
        v5 = *(_QWORD *)(v3 + 34160);
        if ( v5 )
          ipc_log_string(v5, "ipa %s:%d uc_wdi_ctx.stats_notify NULL\n", "ipa3_get_wlan_stats", 8500);
      }
    }
    return 4294967282LL;
  }
  if ( *(v1 - 1) != 295462364 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64))v1)(0, a1);
  return 0;
}
