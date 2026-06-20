__int64 __fastcall tpg_hw_v_1_0_init(__int64 a1)
{
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_hw_v_1_0_init",
    280,
    "TPG V1.0 HWL init");
  tpg_hw_v_1_0_reset(a1);
  return 0;
}
