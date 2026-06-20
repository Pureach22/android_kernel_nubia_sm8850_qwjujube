__int64 ipa3_free_coal_close_frame()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x2

  v0 = ipa3_ctx;
  v1 = *(_QWORD *)(ipa3_ctx + 48728);
  if ( v1 )
  {
    kfree(v1);
    v0 = ipa3_ctx;
  }
  v2 = *(_QWORD *)(v0 + 48736);
  if ( v2 )
  {
    kfree(v2);
    v0 = ipa3_ctx;
  }
  result = *(_QWORD *)(v0 + 48744);
  if ( result )
  {
    result = kfree(result);
    v0 = ipa3_ctx;
  }
  v4 = *(_QWORD *)(v0 + 48752);
  if ( v4 )
    return dma_free_attrs(*(_QWORD *)(v0 + 34216), *(unsigned int *)(v0 + 48768), v4, *(_QWORD *)(v0 + 48760), 0);
  return result;
}
