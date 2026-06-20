__int64 __fastcall adreno_hwsched_wait_ack_completion(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        void (__fastcall *a4)(_QWORD))
{
  __int64 v8; // x24
  __int64 (*v9)(void); // x8
  __int64 v10; // x19
  __int64 result; // x0
  __int64 (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x23

  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  v9 = *(__int64 (**)(void))(v8 + 152);
  if ( *((_DWORD *)v9 - 1) != -944375624 )
    __break(0x8228u);
  v10 = v9();
  if ( (unsigned int)wait_for_completion_timeout(a3 + 20, 250) )
  {
    if ( adreno_hwsched_wait_ack_completion_unprocessed )
    {
      ++adreno_hwsched_wait_ack_completion_processed;
      return 0;
    }
    return 0;
  }
  if ( *((_DWORD *)a4 - 1) != 994519391 )
    __break(0x8237u);
  a4(a1);
  v12 = *(__int64 (__fastcall **)(_QWORD))(v8 + 152);
  if ( *((_DWORD *)v12 - 1) != -944375624 )
    __break(0x8228u);
  v13 = v12(a1);
  if ( (completion_done(a3 + 20) & 1) == 0 )
  {
    dev_err(a2, "Ack timeout for id:%d sequence=%d ticks=0x%llx/0x%llx\n", (unsigned __int8)*a3, *a3 >> 20, v10, v13);
    gmu_core_fault_snapshot(a1, 9);
    return 4294967186LL;
  }
  ++adreno_hwsched_wait_ack_completion_unprocessed;
  result = __ratelimit(&adreno_hwsched_wait_ack_completion__rs, "adreno_hwsched_wait_ack_completion");
  if ( (_DWORD)result )
  {
    dev_err(
      a2,
      "Ack unprocessed for id:%d sequence=%d count=%d/%d ticks=0x%llx/0x%llx\n",
      (unsigned __int8)*a3,
      *a3 >> 20,
      adreno_hwsched_wait_ack_completion_unprocessed,
      adreno_hwsched_wait_ack_completion_processed,
      v10,
      v13);
    return 0;
  }
  return result;
}
