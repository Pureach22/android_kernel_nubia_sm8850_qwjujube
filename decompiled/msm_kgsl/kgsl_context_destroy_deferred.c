__int64 __fastcall kgsl_context_destroy_deferred(_QWORD *a1)
{
  a1[45] = 0xFFFFFFFE00000LL;
  a1[46] = a1 + 46;
  a1[47] = a1 + 46;
  a1[48] = deferred_context_destroy;
  return queue_work_on(32, qword_3A908, a1 + 45);
}
