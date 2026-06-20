__int64 __fastcall sub_430D5C(__int64 a1, void *a2)
{
  __int64 v2; // x21

  __arm_mte_set_tag((void *)(v2 + 1728), a2);
  __arm_mte_set_tag((void *)(v2 + 1744), a2);
  return dot11f_unpack_ie_ese_traf_strm_rate_set(a1, a2);
}
