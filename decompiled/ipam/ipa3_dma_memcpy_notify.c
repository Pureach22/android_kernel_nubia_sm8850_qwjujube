__int64 __fastcall ipa3_dma_memcpy_notify(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  _DWORD *v5; // x9
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x0

  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d ENTER.\n", "ipa3_dma_memcpy_notify", 5733);
  }
  if ( *(_QWORD *)(a1 + 1632) == a1 + 1632 )
  {
    result = printk(&unk_3EC3E0, "ipa3_dma_memcpy_notify");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d descriptor list is empty!\n", "ipa3_dma_memcpy_notify", 5735);
        v7 = ipa3_ctx;
      }
      result = *(_QWORD *)(v7 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d descriptor list is empty!\n", "ipa3_dma_memcpy_notify", 5735);
    }
    __break(0x800u);
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 1624);
    v4 = *(_QWORD *)(v3 + 368);
    v5 = *(_DWORD **)(v3 + 376);
    if ( *(v5 - 1) != 420538815 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v5)(v4, 0, 0);
    if ( ipa3_ctx )
    {
      result = *(_QWORD *)(ipa3_ctx + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d EXIT\n", "ipa3_dma_memcpy_notify", 5740);
    }
  }
  return result;
}
