__int64 __fastcall gen8_hwsched_context_detach(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 40);
  rt_mutex_lock(v1 + 11088);
  if ( !(unsigned int)send_context_unregister_hfi(v1, a1, *(unsigned int *)(a1 + 396)) )
  {
    kgsl_sharedmem_writel(*(_QWORD *)(v1 + 40), 40LL * *(unsigned int *)(a1 + 4), *(unsigned int *)(a1 + 392));
    kgsl_sharedmem_writel(*(_QWORD *)(v1 + 40), 40LL * *(unsigned int *)(a1 + 4) + 8, *(unsigned int *)(a1 + 392));
    adreno_profile_process_results(v1);
    *(_BYTE *)(a1 + 288) = 0;
  }
  return rt_mutex_unlock(v1 + 11088);
}
