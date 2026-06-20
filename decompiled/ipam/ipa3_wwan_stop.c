__int64 __fastcall ipa3_wwan_stop(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  long double v4; // q0
  int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x8
  int v9; // w20
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 v18; // x9

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d [%s]\n", "ipa3_wwan_stop", 3091, (const char *)(a1 + 296));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d [%s]\n", "ipa3_wwan_stop", 3091, (const char *)(a1 + 296));
  }
  mutex_lock(rmnet_ipa3_ctx + 2064);
  if ( *(_DWORD *)(a1 + 2928) == 1 )
  {
    *(_DWORD *)(a1 + 2928) = 0;
    *(_DWORD *)(a1 + 2896) = 0;
    v5 = ((__int64 (__fastcall *)(__int64))ipa_deregister_intf)(a1 + 296);
    if ( v5 )
    {
      v9 = v5;
      printk(&unk_3A7E3E, "__ipa_wwan_close");
      if ( ipa3_get_ipc_logbuf() )
      {
        v10 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v10,
          "ipa-wan %s:%d [%s]: ipa_deregister_intf failed %d\n",
          "__ipa_wwan_close",
          3069,
          (const char *)(a1 + 296),
          v9);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        v4 = ipc_log_string(
               v11,
               "ipa-wan %s:%d [%s]: ipa_deregister_intf failed %d\n",
               "__ipa_wwan_close",
               3069,
               (const char *)(a1 + 296),
               v9);
      }
    }
  }
  v6 = *(_QWORD *)(a1 + 24);
  *(_QWORD *)(v6 + 328) = jiffies;
  __dmb(0xBu);
  _X8 = (unsigned __int64 *)(v6 + 336);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 | 1, _X8) );
  v7 = rmnet_ipa3_ctx;
  if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1056) )
  {
    ipa_teardown_pipes(v4);
    v7 = rmnet_ipa3_ctx;
  }
  mutex_unlock(v7 + 2064);
  return 0;
}
