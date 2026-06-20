__int64 __fastcall sub_2CD84(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __asm { STZ2G           X21, [X6,#0x4C0]! }
  return cvp_clock_reg_print(a1, a2, a3, a4, a5, a6, a7);
}
