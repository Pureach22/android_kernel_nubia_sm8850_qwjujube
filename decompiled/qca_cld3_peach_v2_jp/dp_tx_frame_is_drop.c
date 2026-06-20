bool dp_tx_frame_is_drop()
{
  __int64 v0; // x19
  __int64 v1; // x0

  v0 = dp_peer_ast_hash_find_by_pdevid();
  v1 = dp_peer_ast_hash_find_by_pdevid();
  return v0 && v1 && *(unsigned __int16 *)(v0 + 2) == *(unsigned __int16 *)(v1 + 2);
}
