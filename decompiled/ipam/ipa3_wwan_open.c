__int64 __fastcall ipa3_wwan_open(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  long double v5; // q0
  __int64 v6; // x0
  int v7; // w8
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v11; // w20
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned __int64 v22; // x10

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d [%s] wwan_open()\n", "ipa3_wwan_open", 3046, (const char *)(a1 + 296));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d [%s] wwan_open()\n", "ipa3_wwan_open", 3046, (const char *)(a1 + 296));
  }
  mutex_lock(rmnet_ipa3_ctx + 2064);
  if ( ipa3_get_ipc_logbuf() )
  {
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa-wan %s:%d [%s] __wwan_open() NAPI\n", "__ipa_wwan_open", 3007, (const char *)(a1 + 296));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(
           v6,
           "ipa-wan %s:%d [%s] __wwan_open() NAPI\n",
           "__ipa_wwan_open",
           3007,
           (const char *)(a1 + 296));
  }
  if ( *(_DWORD *)(a1 + 2928) != 1 )
    *(_DWORD *)(a1 + 2896) = 0;
  v7 = HIDWORD(qword_2017A8);
  *(_DWORD *)(a1 + 2928) = 1;
  if ( v7 && (prod_pipes_setup_complete & 1) == 0 && (v8 = ipa_setup_prod_pipes(a1, 0, v5)) != 0 )
  {
    v11 = v8;
    printk(&unk_3C52F4, "__ipa_wwan_open");
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(v12, "ipa-wan %s:%d Setup WWAN Producer Pipes failed\n", "__ipa_wwan_open", 3015);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa-wan %s:%d Setup WWAN Producer Pipes failed\n", "__ipa_wwan_open", 3015);
    }
  }
  else if ( HIDWORD(qword_2017B8)
         && (cons_pipes_setup_complete & 1) == 0
         && (v9 = ((__int64 (__fastcall *)(__int64, _QWORD, long double))ipa_setup_cons_pipes)(a1, 0, v5)) != 0 )
  {
    v11 = v9;
    printk(&unk_3FC5EB, "__ipa_wwan_open");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipa-wan %s:%d Setup WWAN Consumer Pipes failed\n", "__ipa_wwan_open", 3022);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipa-wan %s:%d Setup WWAN Consumer Pipes failed\n", "__ipa_wwan_open", 3022);
    }
  }
  else
  {
    if ( byte_2018C2 == 1 )
      napi_enable(a1 + 2936);
    _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 + 24) + 336LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    v11 = 0;
  }
  mutex_unlock(rmnet_ipa3_ctx + 2064);
  return v11;
}
