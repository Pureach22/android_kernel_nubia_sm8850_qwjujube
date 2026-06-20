__int64 __fastcall pe_get_active_session_count(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v2; // x9
  int v3; // w10
  __int64 result; // x0
  unsigned int v5; // w12
  int v6; // w13
  int v7; // w11
  int v8; // w12
  unsigned int v9; // w15

  v1 = *(unsigned __int16 *)(a1 + 3992);
  if ( !*(_WORD *)(a1 + 3992) )
    return 0;
  v2 = *(_QWORD *)(a1 + 12264);
  LOBYTE(v3) = v1 - 1;
  if ( v1 == 1 )
  {
    LODWORD(result) = 0;
    goto LABEL_4;
  }
  LODWORD(result) = 0;
  if ( !(_BYTE)v1 )
  {
    LOBYTE(v3) = 0;
    do
    {
LABEL_4:
      v5 = (unsigned __int8)v3;
      LOBYTE(v3) = v3 + 1;
      if ( *(_BYTE *)(v2 + 10792LL * v5 + 70) )
        result = (unsigned int)(result + 1);
      else
        result = (unsigned int)result;
    }
    while ( v1 > (unsigned __int8)v3 );
    return result;
  }
  LOBYTE(v3) = 0;
  if ( (unsigned __int16)(v1 - 1) > 0xFFu )
    goto LABEL_4;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v3 = v1 & 0x1FE;
  do
  {
    v9 = v6 & 0xFE;
    v6 += 2;
    if ( *(_BYTE *)(v2 + 10792LL * v9 + 70) )
      ++v7;
    if ( *(_BYTE *)(v2 + 10792LL * (v9 | 1) + 70) )
      ++v8;
  }
  while ( v3 != v6 );
  result = (unsigned int)(v8 + v7);
  if ( v3 != v1 )
    goto LABEL_4;
  return result;
}
