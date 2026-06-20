__int64 __fastcall dp_rx_peer_metadata_peer_id_get_be(__int64 a1, unsigned int a2)
{
  return ((unsigned __int8)((*(_DWORD *)(a1 + 13356) & a2) >> *(_BYTE *)(a1 + 13352)) << *(_DWORD *)(a1 + 13328))
       | ((*(_DWORD *)(a1 + 13340) & a2) >> *(_BYTE *)(a1 + 13336));
}
