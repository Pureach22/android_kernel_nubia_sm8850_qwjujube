__int64 __fastcall rndis_ipa_debugfs_atomic_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _DWORD *v7; // x23
  int v8; // w22
  __int64 result; // x0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD **)(a1 + 32);
  v10 = 0;
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_debugfs_atomic_read", 2559);
  v8 = scnprintf(&v10, 4, "%d\n", *v7);
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_debugfs_atomic_read", 2565);
  result = simple_read_from_buffer(a2, a3, a4, &v10, v8);
  _ReadStatusReg(SP_EL0);
  return result;
}
