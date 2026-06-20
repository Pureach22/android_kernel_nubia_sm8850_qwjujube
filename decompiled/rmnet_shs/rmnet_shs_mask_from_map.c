__int64 __fastcall rmnet_shs_mask_from_map(unsigned int *a1)
{
  unsigned int v1; // w8
  _DWORD *v2; // x9
  int v3; // w10
  __int64 result; // x0
  __int64 v5; // x12
  int v6; // w13
  unsigned int v7; // w11
  int v8; // w12
  unsigned int v9; // w15

  v1 = *a1;
  if ( !*a1 )
    return 0;
  v2 = a1 + 6;
  if ( v1 == 1 )
  {
    v3 = 0;
    LODWORD(result) = 0;
    goto LABEL_4;
  }
  v3 = 0;
  if ( !(_BYTE)v1 )
  {
    LODWORD(result) = 0;
    do
    {
LABEL_4:
      v5 = (unsigned __int8)v3++;
      result = (unsigned int)result | (1 << *((_WORD *)v2 + v5));
    }
    while ( v1 > (unsigned __int8)v3 );
    return result;
  }
  LODWORD(result) = 0;
  if ( v1 - 1 > 0xFF )
    goto LABEL_4;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v3 = v1 & 0x1FE;
  do
  {
    v9 = v6 & 0xFE;
    v6 += 2;
    v7 |= 1 << *((_WORD *)v2 + v9);
    v8 |= 1 << *((_WORD *)v2 + (v9 | 1));
  }
  while ( v3 != v6 );
  result = v8 | v7;
  if ( v1 != v3 )
    goto LABEL_4;
  return result;
}
