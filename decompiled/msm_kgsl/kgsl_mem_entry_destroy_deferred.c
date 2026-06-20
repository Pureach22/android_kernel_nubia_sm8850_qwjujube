__int64 __fastcall kgsl_mem_entry_destroy_deferred(_QWORD *a1)
{
  a1[42] = 0xFFFFFFFE00000LL;
  a1[43] = a1 + 43;
  a1[44] = a1 + 43;
  a1[45] = deferred_destroy;
  return queue_work_on(32, qword_3A908, a1 + 42);
}
