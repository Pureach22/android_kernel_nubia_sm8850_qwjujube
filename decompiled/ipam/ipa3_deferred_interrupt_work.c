__int64 __fastcall ipa3_deferred_interrupt_work(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  void (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 v8; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(
        v3,
        "ipa %s:%d call handler from workq for interrupt %d...\n",
        "ipa3_deferred_interrupt_work",
        82,
        *(_DWORD *)(a1 + 40));
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(
        v4,
        "ipa %s:%d call handler from workq for interrupt %d...\n",
        "ipa3_deferred_interrupt_work",
        82,
        *(_DWORD *)(a1 + 40));
  }
  v5 = *(_QWORD *)(a1 + 48);
  v6 = *(_QWORD *)(a1 + 56);
  v7 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 32);
  v8 = *(unsigned int *)(a1 + 40);
  if ( *((_DWORD *)v7 - 1) != -2051554579 )
    __break(0x8228u);
  v7(v8, v5, v6);
  kfree(*(_QWORD *)(a1 + 56));
  return kfree(a1);
}
