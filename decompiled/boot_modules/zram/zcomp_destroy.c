__int64 __fastcall zcomp_destroy(_QWORD *a1)
{
  _cpuhp_state_remove_instance(61, a1 + 2, 1);
  free_percpu(*a1);
  return kfree(a1);
}
