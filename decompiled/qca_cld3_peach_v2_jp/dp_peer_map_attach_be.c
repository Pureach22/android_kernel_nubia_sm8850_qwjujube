__int64 __fastcall dp_peer_map_attach_be(__int64 a1)
{
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 17651) != 1 || (result = dp_peer_ast_hash_attach(a1), !(_DWORD)result) )
  {
    *(_DWORD *)(a1 + 13276) = *(_DWORD *)(a1 + 13272);
    return 0;
  }
  return result;
}
