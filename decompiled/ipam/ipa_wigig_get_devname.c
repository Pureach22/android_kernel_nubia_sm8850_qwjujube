__int64 __fastcall ipa_wigig_get_devname(__int64 a1)
{
  __int64 v2; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v5; // w19
  __int64 v6; // x20
  size_t v7; // x0
  __int64 v9; // x0
  __int64 v10; // x1

  mutex_lock(ipa_wigig_ctx + 16);
  v2 = *(_QWORD *)ipa_wigig_ctx;
  if ( *(_QWORD *)ipa_wigig_ctx == ipa_wigig_ctx || v2 != *(_QWORD *)(ipa_wigig_ctx + 8) )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_wigig %s:%d list is not singular, was an IF registered?\n",
        "ipa_wigig_get_devname",
        308);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wigig %s:%d list is not singular, was an IF registered?\n",
        "ipa_wigig_get_devname",
        308);
    }
    v5 = -14;
    goto LABEL_10;
  }
  v6 = v2 - 48;
  v7 = strnlen((const char *)(v2 - 48), 0x20u);
  if ( v7 < 0x21 )
  {
    sized_strscpy(a1, v6);
    v5 = 0;
LABEL_10:
    mutex_unlock(ipa_wigig_ctx + 16);
    return v5;
  }
  v9 = _fortify_panic(2, 32, v7 + 1);
  return ipa_wigig_client_to_idx(v9, v10);
}
