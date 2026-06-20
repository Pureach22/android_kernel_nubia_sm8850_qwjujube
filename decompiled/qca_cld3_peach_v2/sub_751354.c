__int64 __fastcall sub_751354(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_stc_dump_periodic_stats(a1);
}
