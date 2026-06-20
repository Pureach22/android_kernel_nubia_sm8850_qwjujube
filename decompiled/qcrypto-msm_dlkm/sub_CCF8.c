__int64 sub_CCF8()
{
  __int64 v0; // x12
  void *v1; // x17

  __arm_mte_set_tag((void *)(v0 + 64), v1);
  __arm_mte_set_tag((void *)(v0 + 80), v1);
  return qcrypto_setkey_des();
}
