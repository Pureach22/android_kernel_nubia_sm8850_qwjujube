__int64 __fastcall sub_8C500(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x16
  void *v7; // x29

  __arm_mte_set_tag((void *)(v6 - 2800), v7);
  return _traceiter_cfg80211_reg_can_beacon(a1, a2, a3, a4, a5, a6);
}
