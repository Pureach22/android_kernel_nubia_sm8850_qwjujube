__int64 __fastcall ipa_uc_offload_conn_pipes(unsigned int *a1, const void *a2)
{
  __int64 v2; // x3
  _DWORD *v3; // x2
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int *v18; // x19
  __int64 v19; // x0
  __int64 v20; // x0

  if ( !a1 || !a2 )
  {
    printk(&unk_3B99D8, "ipa_uc_offload_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_uc_offload %s:%d bad parm. in=%pK out=%pK\n",
        "ipa_uc_offload_conn_pipes",
        475,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_uc_offload %s:%d bad parm. in=%pK out=%pK\n",
        "ipa_uc_offload_conn_pipes",
        475,
        a1,
        a2);
    }
    return 4294967274LL;
  }
  v2 = *a1;
  if ( (unsigned int)(v2 - 4) <= 0xFFFFFFFC )
  {
    printk(&unk_3E7FA3, "ipa_uc_offload_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa_uc_offload %s:%d invalid client handle %d\n", "ipa_uc_offload_conn_pipes", 482, *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v11, "ipa_uc_offload %s:%d invalid client handle %d\n", "ipa_uc_offload_conn_pipes", 482, *a1);
    }
    return 4294967274LL;
  }
  v3 = (_DWORD *)ipa_uc_offload_ctx[v2];
  if ( !v3 )
  {
    printk(&unk_3DCEEA, "ipa_uc_offload_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_uc_offload %s:%d Invalid ctx %d\n", "ipa_uc_offload_conn_pipes", 488, *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa_uc_offload %s:%d Invalid ctx %d\n", "ipa_uc_offload_conn_pipes", 488, *a1);
    }
    return 4294967274LL;
  }
  if ( v3[1] == 1 )
  {
    if ( (*v3 & 0xFFFFFFFE) == 2 )
      return ipa_uc_ntn_conn_pipes((__int64)(a1 + 2), (__int64)a2, (__int64)v3);
    v18 = (unsigned int *)ipa_uc_offload_ctx[v2];
    printk(&unk_3B9A09, "ipa_uc_offload_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_uc_offload %s:%d Invalid Proto :%d\n", "ipa_uc_offload_conn_pipes", 505, *v18);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_uc_offload %s:%d Invalid Proto :%d\n", "ipa_uc_offload_conn_pipes", 505, *v18);
    }
    return 4294967274LL;
  }
  v15 = ipa_uc_offload_ctx[v2];
  printk(&unk_3E7FD4, "ipa_uc_offload_conn_pipes");
  if ( ipa3_get_ipc_logbuf() )
  {
    v16 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v16,
      "ipa_uc_offload %s:%d Invalid state %d\n",
      "ipa_uc_offload_conn_pipes",
      493,
      *(_DWORD *)(v15 + 4));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v17 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v17,
      "ipa_uc_offload %s:%d Invalid state %d\n",
      "ipa_uc_offload_conn_pipes",
      493,
      *(_DWORD *)(v15 + 4));
  }
  return 0xFFFFFFFFLL;
}
