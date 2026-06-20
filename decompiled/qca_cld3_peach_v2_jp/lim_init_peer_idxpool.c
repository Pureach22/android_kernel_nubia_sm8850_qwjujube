__int64 __fastcall lim_init_peer_idxpool(__int64 result, __int64 a2)
{
  __int64 v2; // x10
  __int64 v3; // x9
  unsigned int v4; // w11
  bool v5; // zf

  v2 = 1;
  v3 = *(unsigned __int8 *)(result + 12272);
  **(_BYTE **)(a2 + 7240) = 0;
  if ( *(_DWORD *)(a2 + 88) == 2 )
    v4 = 2;
  else
    v4 = 1;
  if ( *(_DWORD *)(a2 + 88) == 2 )
    v2 = 2;
  *(_BYTE *)(a2 + 7248) = v4;
  if ( v4 < (unsigned int)v3 )
  {
    do
    {
      v5 = v3 == v2 + 1;
      *(_BYTE *)(*(_QWORD *)(a2 + 7240) + v2) = v2 + 1;
      ++v2;
    }
    while ( !v5 );
    v2 = v3;
    LOBYTE(v4) = v3;
  }
  *(_BYTE *)(*(_QWORD *)(a2 + 7240) + v2) = 0;
  *(_BYTE *)(a2 + 7249) = v4;
  return result;
}
