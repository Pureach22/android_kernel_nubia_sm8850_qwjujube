__int64 __fastcall set_sch_edca_params(__int64 a1, __int64 a2, __int64 a3)
{
  int *v3; // x8
  int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x11
  unsigned __int8 v9; // w17
  __int64 result; // x0
  _BYTE *v11; // x16
  __int64 v12; // x15
  char v13; // w0
  unsigned int v14; // w17
  unsigned __int8 v15; // w16
  bool v16; // cc
  unsigned int v17; // w0

  v3 = (int *)(a3 + 7232);
  if ( !a3 )
    v3 = (int *)(a1 + 4840);
  v4 = *v3;
  if ( v4 == 2 )
  {
    v5 = 16;
    v6 = 14;
    v7 = 12;
  }
  else if ( v4 == 1 )
  {
    v5 = 11;
    v6 = 9;
    v7 = 7;
  }
  else
  {
    v5 = 6;
    v6 = 4;
    v7 = 2;
  }
  v8 = 0;
  do
  {
    v11 = (_BYTE *)(a2 + 68 * v8);
    v12 = a3 + 7096 + 5 * v8;
    v13 = *(_BYTE *)v12 & 0xEF | (16 * (*v11 & 1));
    *(_BYTE *)v12 = v13;
    *(_BYTE *)v12 = v13 & 0xF0 | v11[4] & 0xF;
    v14 = (unsigned __int16)(*(_WORD *)&v11[4 * v7 + 4] + (*(_WORD *)&v11[4 * v7] << 8));
    if ( *(_WORD *)&v11[4 * v7 + 4] + (*(_WORD *)&v11[4 * v7] << 8) )
    {
      v15 = 0;
      do
      {
        v16 = v14 > 1;
        ++v15;
        v14 >>= 1;
      }
      while ( v16 );
    }
    else
    {
      v15 = 0;
    }
    if ( v15 >= 0xFu )
      v15 = 15;
    *(_BYTE *)(v12 + 1) = *(_BYTE *)(v12 + 1) & 0xF0 | v15;
    v17 = (unsigned __int16)(*(_WORD *)(a2 + 68 * v8 + 4 * v6 + 4) + (*(_WORD *)(a2 + 68 * v8 + 4 * v6) << 8));
    if ( *(_WORD *)(a2 + 68 * v8 + 4 * v6 + 4) + (*(_WORD *)(a2 + 68 * v8 + 4 * v6) << 8) )
    {
      v9 = 0;
      do
      {
        v16 = v17 > 1;
        ++v9;
        v17 >>= 1;
      }
      while ( v16 );
    }
    else
    {
      v9 = 0;
    }
    result = a2 + 68 * v8++;
    if ( v9 >= 0xFu )
      v9 = 15;
    *(_BYTE *)(v12 + 1) = v15 | (16 * v9);
    *(_WORD *)(v12 + 2) = *(_DWORD *)(result + 4 * v5);
  }
  while ( v8 != 4 );
  return result;
}
