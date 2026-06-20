__int64 __fastcall sub_4D3520(__int64 a1, __int64 a2)
{
  __int128 v2; // q20
  __int128 v3; // q25

  *(_OWORD *)(a2 - 176) = v2;
  *(_OWORD *)(a2 - 160) = v3;
  return wma_update_tdls_peer_state(a1, a2);
}
