unsigned int *__fastcall kgsl_reclaim_foreground_work(__int64 a1)
{
  unsigned int *v1; // x19

  v1 = (unsigned int *)(a1 - 408);
  if ( (*(_QWORD *)(a1 - 16) & 2) != 0 )
    kgsl_reclaim_to_pinned_state(a1 - 408);
  return kgsl_process_private_put(v1);
}
