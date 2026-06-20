__int64 __fastcall ipa_broadcast_wdi_quota_reach_ind(int a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  if ( (unsigned int)__ratelimit(&ipa_broadcast_wdi_quota_reach_ind__rs, "ipa_broadcast_wdi_quota_reach_ind") )
    printk(&unk_3C4D3E, "ipa_broadcast_wdi_quota_reach_ind");
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(
        v5,
        "ipa %s:%d Quota reached indication on fid(%d) Mbytes(%lu)\n",
        "ipa_broadcast_wdi_quota_reach_ind",
        3097,
        a1,
        a2);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(
        v6,
        "ipa %s:%d Quota reached indication on fid(%d) Mbytes(%lu)\n",
        "ipa_broadcast_wdi_quota_reach_ind",
        3097,
        a1,
        a2);
  }
  ipa3_broadcast_quota_reach_ind(0, 2, 0);
  return 0;
}
