__int64 __fastcall ipa_hw_stats_get_ep_bit_n_idx(__int64 a1, _DWORD *a2)
{
  __int64 ep_mapping; // x0
  unsigned int v4; // w20

  ep_mapping = ipa_get_ep_mapping(a1);
  if ( (_DWORD)ep_mapping == -1 )
    return 0;
  v4 = ep_mapping;
  *a2 = ipahal_get_ep_reg_idx(ep_mapping);
  return ipahal_get_ep_bit(v4);
}
