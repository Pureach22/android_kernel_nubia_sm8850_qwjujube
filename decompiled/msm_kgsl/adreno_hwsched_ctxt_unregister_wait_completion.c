__int64 __fastcall adreno_hwsched_ctxt_unregister_wait_completion(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        void (__fastcall *a4)(_QWORD),
        __int64 a5)
{
  __int64 v10; // x26
  __int64 (*v11)(void); // x8
  __int64 v12; // x22
  int v13; // w25
  __int64 result; // x0
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x23
  int v17; // w8
  unsigned int v18; // w24
  int v19; // w8

  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  v11 = *(__int64 (**)(void))(v10 + 152);
  if ( *((_DWORD *)v11 - 1) != -944375624 )
    __break(0x8228u);
  v12 = v11();
  rt_mutex_unlock(a1 + 11088);
  v13 = wait_for_completion_timeout(a3 + 20, 7500);
  rt_mutex_lock(a1 + 11088);
  if ( v13 )
    return 0;
  if ( *((_DWORD *)a4 - 1) != 994519391 )
    __break(0x8238u);
  a4(a1);
  v15 = *(__int64 (__fastcall **)(_QWORD))(v10 + 152);
  if ( *((_DWORD *)v15 - 1) != -944375624 )
    __break(0x8228u);
  v16 = v15(a1);
  if ( (completion_done(a3 + 20) & 1) != 0 )
  {
    v17 = __ratelimit(
            &adreno_hwsched_ctxt_unregister_wait_completion__rs,
            "adreno_hwsched_ctxt_unregister_wait_completion");
    result = 0;
    if ( v17 )
    {
      v18 = 0;
      dev_err(
        a2,
        "Ack unprocessed for context unregister seq: %d ctx: %u ts: %u ticks=0x%llx/0x%llx\n",
        *a3 >> 20,
        *(unsigned int *)(a5 + 4),
        *(unsigned int *)(a5 + 8),
        v12,
        v16);
      return v18;
    }
  }
  else
  {
    v19 = __ratelimit(
            &adreno_hwsched_ctxt_unregister_wait_completion__rs_15,
            "adreno_hwsched_ctxt_unregister_wait_completion");
    result = 4294967186LL;
    if ( v19 )
    {
      v18 = -110;
      dev_err(
        a2,
        "Ack timeout for context unregister seq: %d ctx: %u ts: %u ticks=0x%llx/0x%llx\n",
        *a3 >> 20,
        *(unsigned int *)(a5 + 4),
        *(unsigned int *)(a5 + 8),
        v12,
        v16);
      return v18;
    }
  }
  return result;
}
