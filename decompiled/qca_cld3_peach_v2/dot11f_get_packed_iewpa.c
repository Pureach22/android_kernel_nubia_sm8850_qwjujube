__int64 __fastcall dot11f_get_packed_iewpa(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8

  if ( *(_BYTE *)a2 )
  {
    v3 = *a3;
    *a3 += 2;
    if ( *(_BYTE *)(a2 + 4) )
    {
      *a3 = v3 + 6;
      if ( *(_WORD *)(a2 + 10) )
      {
        v4 = v3 + 8;
        *a3 = v4;
        v5 = v4 + 4 * *(unsigned __int16 *)(a2 + 10);
        *a3 = v5;
        if ( *(_WORD *)(a2 + 28) )
        {
          v6 = v5 + 2;
          *a3 = v6;
          v7 = v6 + 4 * *(unsigned __int16 *)(a2 + 28);
          *a3 = v7;
          if ( *(_WORD *)(a2 + 46) )
            *a3 = v7 + 2;
        }
      }
    }
  }
  return 0;
}
