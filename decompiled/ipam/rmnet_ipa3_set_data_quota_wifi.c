__int64 __fastcall rmnet_ipa3_set_data_quota_wifi(__int64 a1)
{
  unsigned __int8 v2; // w8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 + 24);
  v9 = *(_QWORD *)(a1 + 16);
  v10 = v2;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d iface name %s, quota %lu\n",
      "rmnet_ipa3_set_data_quota_wifi",
      4556,
      (const char *)a1,
      *(_QWORD *)(a1 + 16));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d iface name %s, quota %lu\n",
      "rmnet_ipa3_set_data_quota_wifi",
      4556,
      (const char *)a1,
      *(_QWORD *)(a1 + 16));
  }
  if ( (int)ipa3_ctx_get_type(0) < 17
    || (unsigned int)ipa3_ctx_get_type(0) == 20
    || (unsigned int)ipa3_ctx_get_type(0) == 23 )
  {
    LODWORD(result) = ipa3_set_wlan_quota((__int64)&v9);
    if ( BYTE1(v10) )
      result = (unsigned int)result;
    else
      result = 4294967282LL;
  }
  else
  {
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d use ipa-uc for quota\n", "rmnet_ipa3_set_data_quota_wifi", 4561);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d use ipa-uc for quota\n", "rmnet_ipa3_set_data_quota_wifi", 4561);
    }
    result = ipa3_uc_quota_monitor(*(unsigned __int8 *)(a1 + 24));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
