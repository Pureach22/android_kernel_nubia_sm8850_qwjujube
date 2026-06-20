bool __fastcall ipa_rm_peers_list_has_last_peer(_BOOL8 result)
{
  if ( result )
    return *(_DWORD *)(result + 12) == 1;
  return result;
}
