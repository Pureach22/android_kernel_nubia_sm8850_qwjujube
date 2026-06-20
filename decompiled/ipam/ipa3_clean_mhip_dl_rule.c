__int64 ipa3_clean_mhip_dl_rule()
{
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v2; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  _WORD s[262]; // [xsp+Ch] [xbp-214h] BYREF
  __int64 v6; // [xsp+218h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  s[260] = 257;
  result = ipa3_qmi_rmv_offload_request_send(s);
  if ( (_DWORD)result )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    if ( ipc_logbuf )
    {
      v2 = ipa3_get_ipc_logbuf();
      ipc_logbuf = ipc_log_string(v2, "ipa-wan %s:%d clean dl rule cache failed\n", "ipa3_clean_mhip_dl_rule", 840);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v4 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v4, "ipa-wan %s:%d clean dl rule cache failed\n", "ipa3_clean_mhip_dl_rule", 840);
    }
    result = 4294967282LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
