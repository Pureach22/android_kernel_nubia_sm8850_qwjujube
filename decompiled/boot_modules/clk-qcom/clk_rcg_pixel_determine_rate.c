__int64 __fastcall clk_rcg_pixel_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x20
  unsigned __int64 v4; // x0
  __int64 v6; // x20
  __int64 v7; // x9
  unsigned __int64 v8; // x10
  unsigned int v9; // w8
  unsigned __int64 v11; // x20

  v3 = 2LL * a2[1];
  v4 = clk_hw_round_rate(a2[5], v3);
  if ( v4 >= v3 - 100000 && v4 <= v3 + 100000 )
  {
    v7 = 1;
    v8 = 2;
LABEL_9:
    v9 = 0;
    a2[4] = v4;
    a2[1] = v4 * v7 / v8;
    return v9;
  }
  v6 = 3LL * a2[1];
  v4 = clk_hw_round_rate(a2[5], v6);
  if ( v4 >= v6 - 100000 && v4 <= v6 + 100000 )
  {
    v7 = 1;
    v8 = 3;
    goto LABEL_9;
  }
  v11 = 16LL * a2[1] / 3uLL;
  v4 = clk_hw_round_rate(a2[5], v11);
  v9 = -22;
  if ( v4 >= v11 - 100000 && v4 <= v11 + 100000 )
  {
    v7 = 3;
    v8 = 16;
    goto LABEL_9;
  }
  return v9;
}
