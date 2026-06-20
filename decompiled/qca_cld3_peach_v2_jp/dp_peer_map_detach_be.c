__int64 __fastcall dp_peer_map_detach_be(__int64 result, __int64 a2)
{
  if ( *(_BYTE *)(result + 17651) == 1 )
    return dp_peer_ast_hash_detach(result, a2);
  return result;
}
