bool __fastcall ipa_rm_peers_list_is_empty(__int64 a1)
{
  return !a1 || *(_DWORD *)(a1 + 12) < 1;
}
