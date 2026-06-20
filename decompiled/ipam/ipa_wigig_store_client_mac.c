void __fastcall ipa_wigig_store_client_mac(int a1, int *a2)
{
  __int64 v3; // x0
  __int64 v4; // x8
  int v5; // w10
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v3 = ipa_wigig_client_to_idx(a1, &v8);
  if ( (_DWORD)v3 )
  {
    printk(&unk_3DFCDB, "ipa_wigig_store_client_mac");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d couldn't acquire idx\n", "ipa_wigig_store_client_mac", 1518);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d couldn't acquire idx\n", "ipa_wigig_store_client_mac", 1518);
    }
    goto LABEL_4;
  }
  if ( (unsigned int)(v8 - 1) < 5 )
  {
    v4 = ipa_wigig_ctx + 6LL * (unsigned int)(v8 - 1);
    v5 = *a2;
    *(_WORD *)(v4 + 740) = *((_WORD *)a2 + 2);
    *(_DWORD *)(v4 + 736) = v5;
LABEL_4:
    _ReadStatusReg(SP_EL0);
    return;
  }
  __break(0x5512u);
  ipa_wigig_clean_pipe_info(v3);
}
