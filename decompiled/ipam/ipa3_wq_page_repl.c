__int64 __fastcall ipa3_wq_page_repl(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  _DWORD *v3; // x8
  unsigned int v4; // w20
  unsigned int v5; // w9
  unsigned int v6; // w27
  unsigned int v7; // w9
  int v8; // w8
  int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x0

  v1 = result;
  v2 = result - 328;
  *(_DWORD *)(*(_QWORD *)(result + 40) + 20LL) = 0;
  v3 = *(_DWORD **)(result + 40);
  v4 = v3[3];
  while ( 1 )
  {
    v5 = (v4 + 1) % v3[4];
    if ( v5 != v3[2] )
      break;
LABEL_10:
    if ( v3[3] != v3[2] )
      return result;
    v9 = *(_DWORD *)(*(_QWORD *)(v1 + 1296) + 4LL);
    if ( v9 == 95 || v9 == 35 )
    {
      ++*(_DWORD *)(ipa3_ctx + 32848);
      v9 = *(_DWORD *)(*(_QWORD *)(v1 + 1296) + 4LL);
    }
    if ( v9 == 121 )
      ++*(_DWORD *)(ipa3_ctx + 32856);
    result = __ratelimit(&ipa3_wq_page_repl__rs, "ipa3_wq_page_repl");
    if ( (_DWORD)result )
      result = printk(&unk_3A6A59, "ipa3_wq_page_repl");
    v3 = *(_DWORD **)(v1 + 40);
  }
  v6 = v4;
  while ( 1 )
  {
    v4 = v5;
    result = ipa3_alloc_rx_pkt_page(1, v2);
    if ( !result )
      break;
    *(_QWORD *)(result + 80) = v2;
    *(_QWORD *)(**(_QWORD **)(v1 + 40) + 8LL * v6) = result;
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)(v1 + 40) + 12LL) = v4;
    v8 = *(_DWORD *)(*(_QWORD *)(v1 + 1296) + 4LL);
    if ( v8 == 35 || v8 == 95 )
    {
      v3 = *(_DWORD **)(v1 + 40);
      v7 = v3[4];
      if ( (v3[3] - v3[2]) % v7 > *(_DWORD *)(ipa3_ctx + 48792) )
        return result;
    }
    else
    {
      v3 = *(_DWORD **)(v1 + 40);
      v7 = v3[4];
    }
    v6 = v4;
    v5 = (v4 + 1) % v7;
    if ( v5 == v3[2] )
      goto LABEL_10;
  }
  result = printk(&unk_3E3A54, "ipa3_wq_page_repl");
  v10 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d ipa3_alloc_rx_pkt_page fails\n", "ipa3_wq_page_repl", 2879);
      v10 = ipa3_ctx;
    }
    result = *(_QWORD *)(v10 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d ipa3_alloc_rx_pkt_page fails\n", "ipa3_wq_page_repl", 2879);
  }
  return result;
}
