__int64 __fastcall dp_mlo_peer_find_hash_attach_wrapper(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  int v4; // w9
  unsigned int v5; // w10
  bool v6; // cc
  int v7; // w21
  __int64 v8; // x0
  __int64 v9; // x9
  unsigned int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x10

  if ( !a1 )
    return 16;
  v2 = a1 + 20480;
  v3 = 2 * *(_DWORD *)(a1 + 13320);
  if ( v3 )
  {
    v4 = -1;
    v5 = 2 * *(_DWORD *)(a1 + 13320);
    do
    {
      v6 = v5 > 1;
      ++v4;
      v5 >>= 1;
    }
    while ( v6 );
    if ( 1 << v4 == v3 )
      v7 = v4;
    else
      v7 = v4 + 1;
  }
  else
  {
    v7 = 0;
  }
  *(_DWORD *)(a1 + 23444) = v7;
  *(_DWORD *)(a1 + 23440) = (1 << v7) - 1;
  v8 = _qdf_mem_malloc(16LL * (1 << v7), "dp_mlo_peer_find_hash_attach_be", 2933);
  *(_QWORD *)(a1 + 23448) = v8;
  if ( !v8 )
    return 2;
  if ( v7 != 31 )
  {
    v9 = 0;
    if ( 1 << v7 <= 1 )
      v10 = 1;
    else
      v10 = 1 << v7;
    v11 = 16LL * v10;
    do
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 23448) + v9) = 0;
      v12 = *(_QWORD *)(a1 + 23448) + v9;
      v9 += 16;
      *(_QWORD *)(v12 + 8) = v12;
    }
    while ( v11 != v9 );
  }
  *(_DWORD *)(v2 + 2944) = 0;
  *(_QWORD *)(a1 + 23432) = 0;
  return 0;
}
