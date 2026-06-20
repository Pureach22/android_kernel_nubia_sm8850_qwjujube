__int64 __fastcall create_ext_reg_rules_from_wmi(unsigned int a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x12
  __int16 v8; // w11

  if ( !a1 )
    return 0;
  result = _qdf_mem_malloc(14LL * a1, "create_ext_reg_rules_from_wmi", 17267);
  if ( result )
  {
    v5 = 0;
    v6 = a2 + 8;
    do
    {
      v7 = result + v5;
      v5 += 14;
      *(_WORD *)v7 = *(_DWORD *)(v6 - 4);
      *(_WORD *)(v7 + 2) = *(_WORD *)(v6 - 2);
      *(_WORD *)(v7 + 4) = *(_DWORD *)v6;
      *(_BYTE *)(v7 + 6) = *(_WORD *)(v6 + 2);
      *(_BYTE *)(v7 + 7) = *(_BYTE *)(v6 + 3);
      *(_WORD *)(v7 + 8) = *(_DWORD *)(v6 + 4);
      *(_BYTE *)(v7 + 10) = *(_BYTE *)(v6 + 8) & 1;
      v8 = *(_WORD *)(v6 + 10);
      v6 += 20;
      *(_WORD *)(v7 + 12) = v8;
    }
    while ( 14LL * a1 != v5 );
  }
  return result;
}
