__int64 ipa_reset_all_teth_stats()
{
  _BYTE *v0; // x8
  unsigned int v1; // w19
  unsigned int teth_stats; // w0
  __int64 v3; // x19
  unsigned int v5; // w19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0

  v0 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v0 || *v0 != 1 || v0[64976] != 1 )
    return 0;
  v1 = 0;
  while ( (v1 & 1) != 0 || (unsigned int)ipa_get_ep_mapping(v1) == -1 )
  {
    if ( ++v1 == 134 )
      goto LABEL_9;
  }
  teth_stats = ipa_get_teth_stats();
  if ( !teth_stats )
  {
LABEL_9:
    v3 = -31104;
    do
    {
      memset((void *)(*(_QWORD *)(ipa3_ctx + 43800) + v3 + 32280), 0, 0x360u);
      v3 += 864;
    }
    while ( v3 );
    return 0;
  }
  v5 = teth_stats;
  printk(&unk_3B2480, "ipa_reset_all_teth_stats");
  v6 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d ipa_get_teth_stats failed %d\n", "ipa_reset_all_teth_stats", 1393, v5);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d ipa_get_teth_stats failed %d\n", "ipa_reset_all_teth_stats", 1393, v5);
  }
  return v5;
}
