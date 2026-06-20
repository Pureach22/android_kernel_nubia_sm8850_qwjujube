__int64 __fastcall geni_i2c_sg_init(__int64 a1, int a2, unsigned int *a3, int *a4, int a5, __int64 a6)
{
  unsigned int v6; // w8
  unsigned int v7; // w8
  int v9; // w9
  unsigned int v12; // w8
  __int64 result; // x0
  __int64 v15; // x8

  if ( !*(_DWORD *)(a1 + 8952) )
  {
    v6 = (*a3)++;
    if ( *(_DWORD *)(a1 + 8956) == 3400000 )
      *a3 = v6 + 2;
  }
  if ( (*(_BYTE *)(a1 + 9085) & 1) == 0 )
  {
    v7 = *a3;
    return sg_init_table(*(_QWORD *)(a1 + 8920), v7);
  }
  v7 = *a3;
  if ( a2 && a5 - 1 != a2 )
    return sg_init_table(*(_QWORD *)(a1 + 8920), v7);
  if ( a5 == 1 )
    v9 = 2;
  else
    v9 = 1;
  v12 = v7 + v9;
  *a3 = v12;
  result = sg_init_table(*(_QWORD *)(a1 + 8920), v12);
  if ( !a2 )
  {
    v15 = *(_QWORD *)(a1 + 8920) + 32LL * *a4;
    *(_QWORD *)v15 = (*(_QWORD *)v15 & 3LL | ((unsigned __int64)((a6 << 8 >> 8) + 0x8000000000LL) >> 12 << 6))
                   - 0x140000000LL;
    *(_DWORD *)(v15 + 8) = a6 & 0xFFF;
    *(_DWORD *)(v15 + 12) = 16;
    ++*a4;
  }
  return result;
}
