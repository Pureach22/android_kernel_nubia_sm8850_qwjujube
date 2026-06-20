__int64 __fastcall dp_peer_map_attach_be(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  int v4; // w9
  unsigned int v5; // w10
  bool v6; // cc

  if ( *(_BYTE *)(a1 + 17707) != 1 || (result = dp_peer_ast_hash_attach(a1), !(_DWORD)result) )
  {
    v3 = *(_DWORD *)(a1 + 13320);
    if ( v3 )
    {
      v4 = -1;
      v5 = *(_DWORD *)(a1 + 13320);
      do
      {
        v6 = v5 > 1;
        ++v4;
        v5 >>= 1;
      }
      while ( v6 );
      if ( 1 << v4 == v3 )
        v3 = v4;
      else
        v3 = v4 + 1;
    }
    *(_DWORD *)(a1 + 13328) = v3;
    *(_DWORD *)(a1 + 13324) = 1 << (v3 + 1);
    *(_DWORD *)(a1 + 13332) = ~(-1 << v3);
    return 0;
  }
  return result;
}
