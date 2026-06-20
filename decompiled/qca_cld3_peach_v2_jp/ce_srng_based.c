__int64 __fastcall ce_srng_based(__int64 a1)
{
  unsigned __int64 v1; // x9

  v1 = *(unsigned int *)(hif_get_target_info_handle(a1) + 4);
  return (v1 < 0x2C) & (unsigned int)(0xFBFFFB00000uLL >> v1);
}
