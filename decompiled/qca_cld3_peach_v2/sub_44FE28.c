__int64 __fastcall sub_44FE28(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __arm_mte_increment_tag((void *)(a3 + 960), 5u);
  return dot11f_pack_t2lm_neg_req(a1, a2, a3, a4, a5);
}
