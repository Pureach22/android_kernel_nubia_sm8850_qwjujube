unsigned __int64 __fastcall drm_dp_bw_overhead(int a1, int a2, int a3, int a4, char a5)
{
  unsigned int v5; // w9
  int v6; // w10
  int v7; // w10
  int v8; // w11
  int v9; // w10
  char v10; // w12
  int v11; // w11
  int v13; // w13
  char v14; // w12
  char v15; // w12

  if ( a1 && a2 && a4 )
  {
    if ( (a5 & 4) != 0 )
      v5 = 16096000;
    else
      v5 = 16000000;
    if ( (~a5 & 0xA) == 0 )
      __break(0x800u);
    v6 = 4 / a1;
    if ( (a5 & 0x10) != 0 )
    {
      v13 = v6 - 1;
      if ( (a5 & 1) == 0 )
      {
        v13 = 0;
        v6 = 1;
      }
      if ( (a5 & 2) != 0 )
        v14 = 9;
      else
        v14 = 7;
      v11 = (((((a1 << v14) + (a2 + a3 - 1) / a3 * a4 - 1) / (a1 << v14) + v13) & ~v13) + v6) * a3;
      v9 = a4 * a2;
    }
    else
    {
      v7 = v6 - 1;
      if ( (a5 & 1) != 0 )
        v8 = v7;
      else
        v8 = 0;
      v9 = a4 * a2;
      if ( (a5 & 2) != 0 )
        v10 = 9;
      else
        v10 = 7;
      v11 = ((v9 + (a1 << v10) - 1) / (a1 << v10) + v8) & ~v8;
    }
    if ( (a5 & 2) != 0 )
      v15 = 5;
    else
      v15 = 3;
    if ( (a5 & 8) != 0 )
      v5 += 384256;
    return (v9 + (unsigned int)((v11 << v15) * a1) * (unsigned __int64)v5 - 1) / (unsigned int)v9;
  }
  else
  {
    _drm_dev_dbg(
      0,
      0,
      2,
      "Invalid BW overhead params: lane_count %d, hactive %d, bpp_x16 %d.%04d\n",
      a1,
      a2,
      a4 >> 4,
      625 * (a4 & 0xF));
    return 0;
  }
}
