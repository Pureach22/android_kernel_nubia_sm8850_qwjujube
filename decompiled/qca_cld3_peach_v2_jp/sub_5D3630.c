__int64 sub_5D3630()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_fisa_calc_flow_stats_avg();
}
