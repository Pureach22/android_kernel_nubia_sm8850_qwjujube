__int64 tpg_hw_v_1_4_stop()
{
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "tpg_hw_v_1_4_stop",
      761,
      "TPG V1.4 HWL stop");
  tpg_hw_v_1_4_reset();
  return 0;
}
