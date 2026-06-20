__int64 __fastcall reset_rb_preempt_record_0(__int64 a1, __int64 a2)
{
  memset(*(void **)(*(_QWORD *)(a2 + 184) + 8LL), 0, *(_QWORD *)(*(_QWORD *)(a2 + 184) + 40LL));
  kgsl_sharedmem_writel(*(_QWORD *)(a2 + 184), 0, 2923011438LL);
  kgsl_sharedmem_writel(*(_QWORD *)(a2 + 184), 16, 524);
  kgsl_sharedmem_writeq(*(_QWORD *)(a2 + 184), 32, *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(a2 + 28));
  kgsl_sharedmem_writeq(*(_QWORD *)(a2 + 184), 40, *(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL));
  return kgsl_sharedmem_writeq(
           *(_QWORD *)(a2 + 184),
           56,
           *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(a2 + 28) + 4);
}
