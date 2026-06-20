__int64 tpg_hw_v_1_3_start()
{
  if ( (debug_mdl & 0x200000000LL) == 0 || debug_priority )
    return 0;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 0x200000000LL,
    4,
    "tpg_hw_v_1_3_start",
    715,
    "TPG V1.3 HWL start");
  return 0;
}
