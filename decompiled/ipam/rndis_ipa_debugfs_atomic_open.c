__int64 __fastcall rndis_ipa_debugfs_atomic_open(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x0

  v3 = *(_QWORD *)(a1 + 696);
  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_debugfs_atomic_open", 2543);
    v4 = ipa_rndis_logbuf;
    *(_QWORD *)(a2 + 32) = v3 + 56;
    if ( v4 )
      ipc_log_string(v4, "RNDIS_IPA %s:%d end\n", "rndis_ipa_debugfs_atomic_open", 2547);
  }
  else
  {
    *(_QWORD *)(a2 + 32) = v3 + 56;
  }
  return 0;
}
