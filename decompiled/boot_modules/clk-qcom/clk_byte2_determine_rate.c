__int64 __fastcall clk_byte2_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  unsigned int v4; // w8
  unsigned __int64 v5; // x20
  __int64 v7; // x21
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x8
  int v10; // w8

  v3 = a2[5];
  v4 = -22;
  if ( v3 )
  {
    v5 = a2[1];
    if ( v5 )
    {
      v7 = -1LL << *(_BYTE *)(a1 - 43);
      v8 = clk_hw_round_rate(v3, a2[1]);
      a2[4] = v8;
      v9 = (v5 + 2 * v8 - 1) / v5;
      if ( (unsigned int)v7 <= -(int)v9 )
        v10 = -(int)v9;
      else
        v10 = v7;
      if ( v10 != -1 )
        v8 = 2 * (v8 % (unsigned int)-v10) / (unsigned int)-v10 + 2 * (v8 / (unsigned int)-v10);
      v4 = 0;
      a2[1] = v8;
    }
  }
  return v4;
}
