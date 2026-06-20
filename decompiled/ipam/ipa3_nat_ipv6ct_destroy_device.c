__int64 __fastcall ipa3_nat_ipv6ct_destroy_device(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  _QWORD *v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d In\n", "ipa3_nat_ipv6ct_destroy_device", 435);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d In\n", "ipa3_nat_ipv6ct_destroy_device", 435);
  }
  mutex_lock(a1 + 16);
  v5 = *(_QWORD **)(a1 + 296);
  if ( v5 )
  {
    if ( *(_BYTE *)(ipa3_ctx + 29864) == 1 )
    {
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), 128, *v5, v5[1], 0);
      kfree(*(_QWORD *)(a1 + 296));
      *(_BYTE *)(ipa3_ctx + 29864) = 0;
    }
    *(_QWORD *)(a1 + 296) = 0;
  }
  device_destroy(*(_QWORD *)(a1 + 64), *(unsigned int *)(a1 + 216));
  unregister_chrdev_region(*(unsigned int *)(a1 + 216), 1);
  class_destroy(*(_QWORD *)(a1 + 64));
  *(_BYTE *)(a1 + 222) = 0;
  result = mutex_unlock(a1 + 16);
  v7 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_destroy_device", 463);
      v7 = ipa3_ctx;
    }
    result = *(_QWORD *)(v7 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_destroy_device", 463);
  }
  return result;
}
