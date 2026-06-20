__int64 __fastcall sub_C344(int a1, int a2, size_t a3)
{
  __int64 v3; // x12
  void *v4; // x17

  __arm_mte_set_tag((void *)(v3 + 64), v4);
  __arm_mte_set_tag((void *)(v3 + 80), v4);
  return qcrypto_setkey_aes(a1, a2, a3);
}
