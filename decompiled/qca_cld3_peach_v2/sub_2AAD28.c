__int64 __fastcall sub_2AAD28(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_set_rps_cpu_mask(a1);
}
