bool __fastcall wma_is_tx_chainmask_valid(
        int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w9
  _DWORD *v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  _DWORD *v14; // x9
  _BOOL4 v15; // w8
  __int64 v16; // x11

  v10 = *(_DWORD *)(a2 + 504);
  v11 = (_DWORD *)(a2 + 1072);
  if ( v10 <= 0xA )
  {
    if ( *v11 == v10 )
    {
      v12 = 0;
    }
    else if ( *(_DWORD *)(a2 + 1328) == v10 )
    {
      v12 = 1;
    }
    else if ( *(_DWORD *)(a2 + 1584) == v10 )
    {
      v12 = 2;
    }
    else if ( *(_DWORD *)(a2 + 1840) == v10 )
    {
      v12 = 3;
    }
    else if ( *(_DWORD *)(a2 + 2096) == v10 )
    {
      v12 = 4;
    }
    else if ( *(_DWORD *)(a2 + 2352) == v10 )
    {
      v12 = 5;
    }
    else if ( *(_DWORD *)(a2 + 2608) == v10 )
    {
      v12 = 6;
    }
    else
    {
      if ( *(_DWORD *)(a2 + 2864) != v10 )
      {
LABEL_25:
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid MAC PHY capabilities handle",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wma_is_tx_chainmask_valid");
        return 0;
      }
      v12 = 7;
    }
    v11 += 64 * v12;
  }
  if ( !v11 )
    goto LABEL_25;
  if ( !*(_BYTE *)(a2 + 486) )
    return 0;
  v13 = *(unsigned __int8 *)(a2 + 486) - 1LL;
  v14 = v11 + 24;
  do
  {
    v15 = (*v14 & a1) != 0;
    if ( (*v14 & a1) != 0 )
      break;
    v16 = v13--;
    v14 += 64;
  }
  while ( v16 );
  return v15;
}
