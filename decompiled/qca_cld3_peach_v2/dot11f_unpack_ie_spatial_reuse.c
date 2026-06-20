__int64 __fastcall dot11f_unpack_ie_spatial_reuse(__int64 a1, char *a2, char a3, _BYTE *a4)
{
  char v5; // w20
  char v6; // w8
  _BYTE *v7; // x19

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( !a3 )
  {
    *a4 = 0;
    return 4;
  }
  v5 = a3 - 1;
  v7 = a2 + 1;
  v6 = *a2;
  a4[1] = *a2;
  if ( (v6 & 4) != 0 )
  {
    if ( a3 == 1 )
      goto LABEL_15;
    v7 = a2 + 2;
    v5 = a3 - 2;
    a4[2] = a2[1];
  }
  if ( (v6 & 8) == 0 )
    return 0;
  if ( !v5 || (a4[3] = *v7, v5 == 1) || (a4[4] = v7[1], (unsigned __int8)(v5 - 2) <= 7u) )
  {
LABEL_15:
    *a4 = 0;
    return 4;
  }
  qdf_mem_copy(a4 + 5, v7 + 2, 8u);
  if ( (unsigned __int8)(v5 - 10) <= 7u )
  {
    *a4 = 0;
    return 4;
  }
  qdf_mem_copy(a4 + 13, v7 + 10, 8u);
  return 0;
}
