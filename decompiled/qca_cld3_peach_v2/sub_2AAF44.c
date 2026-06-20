__int64 __fastcall sub_2AAF44(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_clear_rps_cpu_mask(a1);
}
