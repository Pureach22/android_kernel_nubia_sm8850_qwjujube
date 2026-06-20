__int64 __fastcall ipa_wigig_read_conn_clients(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x22
  unsigned int v9; // w23
  int v10; // w27
  int v11; // w0
  int v12; // w27
  const char *v13; // x3
  int v14; // w24
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v17; // w0
  __int64 v18; // x19
  __int64 v20; // [xsp+8h] [xbp-18h]
  __int64 v21; // [xsp+10h] [xbp-10h]

  v7 = _kmalloc_cache_noprof(dma_alloc_attrs, 3520, 4096);
  v8 = v7;
  if ( !v7 )
    return -12;
  v20 = a2;
  v21 = a3;
  if ( ipa_wigig_ctx )
  {
    if ( *(_BYTE *)(ipa_wigig_ctx + 910) )
    {
      v9 = 0;
      v10 = 0;
      do
      {
        v14 = *(unsigned __int8 *)(ipa_wigig_ctx + 910);
        if ( v9 - 1 < 4 )
        {
          v11 = scnprintf(v8 + v10, 4096 - v10, "IPA_CLIENT_WIGIG%d_CONS", v9);
        }
        else if ( v9 )
        {
          printk(&unk_3F9FCB, "ipa_wigig_read_conn_clients");
          if ( ipa3_get_ipc_logbuf() )
          {
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d invalid pipe %d\n", "ipa_wigig_read_conn_clients", 1964, v9);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d invalid pipe %d\n", "ipa_wigig_read_conn_clients", 1964, v9);
          }
          v11 = scnprintf(v8 + v10, 4096 - v10, "invalid pipe %d", v9);
        }
        else
        {
          v11 = scnprintf(v8 + v10, 4096 - v10, "IPA_CLIENT_WIGIG_PROD");
        }
        v12 = v11 + v10;
        if ( ((1 << v9) & v14) != 0 )
          v13 = "is";
        else
          v13 = "not";
        ++v9;
        v10 = v12 + scnprintf(v8 + v12, 4096 - v12, " %s connected\n", v13);
      }
      while ( v9 != 5 );
      goto LABEL_21;
    }
    v17 = scnprintf(v7, 4096, "no WIGIG pipes connected\n");
  }
  else
  {
    v17 = scnprintf(v7, 4096, "IPA WIGIG not initialized\n");
  }
  v10 = v17;
LABEL_21:
  v18 = simple_read_from_buffer(v20, v21, a4, v8, v10);
  kfree(v8);
  return v18;
}
