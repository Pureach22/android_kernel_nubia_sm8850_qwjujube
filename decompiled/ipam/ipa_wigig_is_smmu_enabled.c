__int64 ipa_wigig_is_smmu_enabled()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  _WORD v5[2]; // [xsp+0h] [xbp-10h] BYREF
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_is_smmu_enabled", 222);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_is_smmu_enabled", 222);
  }
  v6 = 2;
  ipa_get_smmu_params(&v6, v5);
  if ( ipa3_get_ipc_logbuf() )
  {
    v2 = ipa3_get_ipc_logbuf();
    ipc_log_string(v2, "ipa_wigig %s:%d exit (%d)\n", "ipa_wigig_is_smmu_enabled", 227, LOBYTE(v5[0]));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v3 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v3, "ipa_wigig %s:%d exit (%d)\n", "ipa_wigig_is_smmu_enabled", 227, LOBYTE(v5[0]));
  }
  _ReadStatusReg(SP_EL0);
  return LOBYTE(v5[0]);
}
