__int64 __fastcall kgsl_mem_entry_commit_process(__int64 a1)
{
  raw_spin_lock(*(_QWORD *)(a1 + 256) + 32LL);
  idr_replace(*(_QWORD *)(a1 + 256) + 40LL, a1, *(unsigned int *)(a1 + 248));
  return raw_spin_unlock(*(_QWORD *)(a1 + 256) + 32LL);
}
