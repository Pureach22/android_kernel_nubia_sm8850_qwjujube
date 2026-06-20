__int64 __fastcall sub_8A2A0(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x26
  void *v5; // x29

  __arm_mte_set_tag((void *)(v4 + 1872), v5);
  __arm_mte_set_tag((void *)(v4 + 1888), v5);
  return _traceiter_rdev_return_chandef(a1, a2, a3, a4);
}
