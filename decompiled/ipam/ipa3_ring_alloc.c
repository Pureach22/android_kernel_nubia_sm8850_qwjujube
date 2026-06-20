__int64 __fastcall ipa3_ring_alloc(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w22
  __int64 result; // x0
  unsigned int i; // w23
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0

  v4 = a4;
  result = dma_alloc_attrs(a1, a2, a3, a4, 0);
  if ( !result )
  {
    for ( i = 0; i < 5; ++i )
    {
      v10 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v11 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d Fail to dma alloc retry cnt = %d\n", "ipa3_ring_alloc", 6833, i);
          v10 = ipa3_ctx;
        }
        v12 = *(_QWORD *)(v10 + 34160);
        if ( v12 )
          ipc_log_string(v12, "ipa %s:%d Fail to dma alloc retry cnt = %d\n", "ipa3_ring_alloc", 6833, i);
      }
      result = dma_alloc_attrs(a1, a2, a3, v4, 0);
      if ( result )
        return result;
    }
    if ( v4 != 2080 || (result = dma_alloc_attrs(a1, a2, a3, 3264, 0)) == 0 )
    {
      v13 = printk(&unk_3E6451, "ipa3_ring_alloc");
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d fail to dma alloc %zu bytes\n", "ipa3_ring_alloc", 6842, a2);
          v14 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v14 + 34160);
        if ( v13 )
          v13 = ipc_log_string(v13, "ipa %s:%d fail to dma alloc %zu bytes\n", "ipa3_ring_alloc", 6842, a2);
      }
      ((void (__fastcall *)(__int64))ipa_assert)(v13);
      return 0;
    }
  }
  return result;
}
