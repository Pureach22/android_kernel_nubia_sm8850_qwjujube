__int64 ipa3_disable_prefetch()
{
  unsigned __int8 v0; // w19
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  _QWORD v5[5]; // [xsp+8h] [xbp-28h] BYREF

  v5[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v5, 0, 32);
  v0 = ((__int64 (*)(void))ipa3_get_qmb_master_sel)();
  v1 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d disabling prefetch for qmb %d\n", "ipa3_disable_prefetch", 13773, v0);
      v1 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v1 + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d disabling prefetch for qmb %d\n", "ipa3_disable_prefetch", 13773, v0);
  }
  ipahal_read_reg_n_fields(93, 0, v5);
  if ( v0 )
    BYTE1(v5[0]) = 1;
  else
    LOBYTE(v5[0]) = 1;
  result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(93, 0, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
