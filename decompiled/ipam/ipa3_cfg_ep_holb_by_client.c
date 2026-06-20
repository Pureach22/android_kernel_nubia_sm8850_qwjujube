__int64 __fastcall ipa3_cfg_ep_holb_by_client(__int64 a1, _DWORD *a2)
{
  unsigned int ep_mapping; // w0

  ep_mapping = ipa_get_ep_mapping(a1);
  return ipa3_cfg_ep_holb(ep_mapping, a2);
}
