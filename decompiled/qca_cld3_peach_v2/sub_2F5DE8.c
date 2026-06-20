__int64 __fastcall sub_2F5DE8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        void *a8)
{
  __arm_mte_set_tag((void *)(a4 - 3200), a8);
  __arm_mte_set_tag((void *)(a4 - 3184), a8);
  return cm_get_ml_partner_info(a1);
}
