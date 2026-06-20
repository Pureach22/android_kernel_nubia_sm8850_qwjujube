__int64 __fastcall dot11f_get_packed_ie_he_cap(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8

  if ( *(_BYTE *)a2 )
  {
    v3 = *a3 + 21;
    *a3 = v3;
    v4 = ((*(_QWORD *)(a2 + 1) >> 51) & 2) + v3;
    *a3 = v4;
    v5 = ((*(_QWORD *)(a2 + 1) >> 51) & 2) + v4;
    *a3 = v5;
    v6 = ((*(_QWORD *)(a2 + 1) >> 52) & 2) + v5;
    *a3 = v6;
    v7 = ((*(_QWORD *)(a2 + 1) >> 52) & 2) + v6;
    *a3 = v7;
    if ( (*(_BYTE *)(a2 + 14) & 4) != 0 )
      *a3 = v7 + *(unsigned __int8 *)(a2 + 32);
  }
  return 0;
}
