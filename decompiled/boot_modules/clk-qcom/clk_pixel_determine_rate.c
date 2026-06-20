__int64 __fastcall clk_pixel_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x0
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x0
  unsigned __int64 v7; // x20
  __int64 v9; // x9
  unsigned __int64 v10; // x10
  unsigned int v11; // w8
  unsigned __int64 v12; // x20
  __int64 v13; // x20
  unsigned __int64 v14; // x20

  v2 = a2[5];
  if ( !v2 )
    return 4294967274LL;
  v4 = 8LL * a2[1] / 3uLL;
  v5 = clk_hw_round_rate(v2, v4);
  if ( v5 < v4 - 100000 || v5 > v4 + 100000 )
  {
    v7 = (unsigned __int64)(9LL * a2[1]) >> 1;
    v5 = clk_hw_round_rate(a2[5], v7);
    if ( v5 < v7 - 100000 || v5 > v7 + 100000 )
    {
      v12 = (unsigned __int64)(9LL * a2[1]) >> 2;
      v5 = clk_hw_round_rate(a2[5], v12);
      if ( v5 < v12 - 100000 || v5 > v12 + 100000 )
      {
        v13 = a2[1];
        v5 = clk_hw_round_rate(a2[5], v13);
        if ( v5 < v13 - 100000 || v5 > v13 + 100000 )
        {
          v14 = (unsigned __int64)(3LL * a2[1]) >> 1;
          v5 = clk_hw_round_rate(a2[5], v14);
          v11 = -22;
          if ( v5 < v14 - 100000 || v5 > v14 + 100000 )
            return v11;
          v9 = 2;
          v10 = 3;
        }
        else
        {
          v10 = 1;
          v9 = 1;
        }
      }
      else
      {
        v9 = 4;
        v10 = 9;
      }
    }
    else
    {
      v9 = 2;
      v10 = 9;
    }
  }
  else
  {
    v9 = 3;
    v10 = 8;
  }
  v11 = 0;
  a2[4] = v5;
  a2[1] = v5 * v9 / v10;
  return v11;
}
