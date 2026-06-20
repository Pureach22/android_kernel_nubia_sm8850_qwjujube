__int64 __fastcall hal_reo_enable_pn_in_dest_peach(__int64 a1)
{
  hal_write32_mb_1(a1, 10715240, 1);
  return 1;
}
