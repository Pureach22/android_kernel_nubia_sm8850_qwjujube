__int64 __fastcall sub_B444(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  void *v5; // x9

  __arm_mte_set_tag((void *)(a5 + 496), v5);
  return _traceiter_gh_rm_mem_notify(a1, a2, a3, a4, a5 + 496);
}
