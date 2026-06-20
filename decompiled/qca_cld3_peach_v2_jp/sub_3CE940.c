__int64 __fastcall sub_3CE940(unsigned __int64 a1)
{
  unsigned __int128 *v1; // x12

  __stxp(__PAIR128__((unsigned __int64)v1, a1), v1);
  return lim_get_ht_max_mcs_idx(a1);
}
