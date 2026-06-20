__int64 __fastcall pe_get_current_stas_count(__int64 a1)
{
  unsigned int v1; // w9
  __int64 result; // x0
  unsigned __int8 v4; // w10
  __int64 v5; // x8
  __int64 v6; // x13

  v1 = *(unsigned __int16 *)(a1 + 3992);
  if ( !*(_WORD *)(a1 + 3992) )
    return 0;
  result = 0;
  v4 = 0;
  v5 = *(_QWORD *)(a1 + 12264);
  do
  {
    v6 = v5 + 10792LL * v4;
    if ( *(_BYTE *)(v6 + 70) == 1 )
      result = (unsigned int)result + *(unsigned __int8 *)(v6 + 7250);
    ++v4;
  }
  while ( v1 > v4 );
  return result;
}
