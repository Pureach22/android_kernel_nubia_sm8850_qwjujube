__int64 __fastcall lim_get_vht_max_mcs_idx(__int64 a1)
{
  return mlme_get_max_vht_mcs_idx(*(unsigned __int8 *)(a1 + 6), *(unsigned __int8 *)(a1 + 10));
}
