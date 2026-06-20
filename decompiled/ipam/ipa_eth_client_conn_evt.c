__int64 __fastcall ipa_eth_client_conn_evt(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  _WORD *v5; // x20
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_eth %s:%d enter\n", "ipa_eth_client_conn_evt", 781);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_eth %s:%d enter\n", "ipa_eth_client_conn_evt", 781);
  }
  v4 = _kmalloc_cache_noprof(ipc_log_string, 3520, 36);
  v5 = (_WORD *)v4;
  if ( v4 )
  {
    v6 = *(_QWORD *)(a1 + 16);
    v7 = *(_QWORD *)(a1 + 24);
    *(_DWORD *)(v4 + 32) = *(_DWORD *)(a1 + 32);
    *(_QWORD *)(v4 + 16) = v6;
    *(_QWORD *)(v4 + 24) = v7;
    v8 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)v4 = *(_QWORD *)a1;
    *(_QWORD *)(v4 + 8) = v8;
    v15 = 2359315;
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v9,
        "ipa_eth %s:%d send IPA_PERIPHERAL_CONNECT, len:%d, buff %pK",
        "ipa_eth_client_conn_evt",
        791,
        36,
        v5);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v10,
        "ipa_eth %s:%d send IPA_PERIPHERAL_CONNECT, len:%d, buff %pK",
        "ipa_eth_client_conn_evt",
        791,
        36,
        v5);
    }
    v11 = ipa_send_msg((unsigned __int8 *)&v15, v5, ipa_eth_msg_free_cb);
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(v12, "ipa_eth %s:%d exit\n", "ipa_eth_client_conn_evt", 794);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa_eth %s:%d exit\n", "ipa_eth_client_conn_evt", 794);
    }
  }
  else
  {
    v11 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
