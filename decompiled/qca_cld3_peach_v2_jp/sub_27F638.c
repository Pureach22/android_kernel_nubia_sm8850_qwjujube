__int64 __fastcall sub_27F638(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_reset_all_intfs_connectivity_stats(a1);
}
