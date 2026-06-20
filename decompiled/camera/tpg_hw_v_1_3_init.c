__int64 __fastcall tpg_hw_v_1_3_init(__int64 a1)
{
  __int64 v2; // x19

  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    v2 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "tpg_hw_v_1_3_init",
      756,
      "TPG V1.3 HWL init");
    a1 = v2;
  }
  tpg_hw_v_1_3_reset(a1);
  return 0;
}
