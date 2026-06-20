__int64 __fastcall dot11f_get_packed_iewapi(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8

  if ( *(_BYTE *)a2 )
  {
    v3 = *a3;
    *a3 += 4;
    v4 = v3 + 4 * *(unsigned __int16 *)(a2 + 4) + 6;
    *a3 = v4;
    v5 = v4 + 4 * *(unsigned __int16 *)(a2 + 22);
    *a3 = v5 + 6;
    if ( *(_WORD *)(a2 + 46) )
    {
      v6 = v5 + 8;
      *a3 = v6;
      *a3 = v6 + 16 * *(unsigned __int16 *)(a2 + 46);
    }
  }
  return 0;
}
