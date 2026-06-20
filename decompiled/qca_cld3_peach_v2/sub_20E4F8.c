__int64 __fastcall sub_20E4F8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        void *a8)
{
  __int64 v8; // x13

  __arm_mte_set_tag((void *)(v8 - 1696), a8);
  __arm_mte_set_tag((void *)(v8 - 1680), a8);
  return wlan_reg_get_5g_bonded_channel_and_state_for_pwrmode();
}
