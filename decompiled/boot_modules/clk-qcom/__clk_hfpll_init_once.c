__int64 __fastcall _clk_hfpll_init_once(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x2
  unsigned int v5; // w21
  unsigned __int64 rate; // x0
  int v7; // w8
  __int64 v8; // x2
  __int64 v9; // x1

  if ( !*(_DWORD *)(result - 8) )
  {
    v1 = *(_QWORD *)(result - 16);
    v2 = *(_QWORD *)(result + 24);
    v3 = result;
    v4 = *(unsigned int *)(v1 + 44);
    if ( (_DWORD)v4 )
      regmap_write(*(_QWORD *)(result + 24), *(unsigned int *)(v1 + 24), v4);
    regmap_write(v2, *(unsigned int *)(v1 + 8), 0);
    result = regmap_write(v2, *(unsigned int *)(v1 + 12), 1);
    if ( *(_DWORD *)(v1 + 16) )
    {
      v5 = *(_DWORD *)(v1 + 48);
      rate = clk_hw_get_rate(v3);
      v7 = *(_DWORD *)(v1 + 52);
      if ( v7 )
      {
        if ( rate <= *(_QWORD *)(v1 + 56) )
          v7 = 0;
        v5 |= v7;
      }
      result = regmap_write(v2, *(unsigned int *)(v1 + 16), v5);
    }
    v8 = *(unsigned int *)(v1 + 36);
    if ( (_DWORD)v8 )
      result = regmap_write(v2, *(unsigned int *)(v1 + 4), v8);
    v9 = *(unsigned int *)(v1 + 20);
    if ( (_DWORD)v9 )
      result = regmap_write(v2, v9, *(unsigned int *)(v1 + 40));
    *(_DWORD *)(v3 - 8) = 1;
  }
  return result;
}
