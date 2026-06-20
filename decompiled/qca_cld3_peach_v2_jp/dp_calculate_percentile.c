__int64 __fastcall dp_calculate_percentile(unsigned __int64 *a1, unsigned __int8 a2)
{
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x10
  unsigned __int64 v4; // x11
  unsigned __int64 v5; // x12
  unsigned __int64 v6; // x13
  unsigned __int64 v7; // x14
  unsigned __int64 v8; // x15
  unsigned __int64 v9; // x16
  unsigned __int64 v10; // x17
  unsigned __int64 v11; // x2
  unsigned __int64 v12; // x3
  unsigned __int64 v13; // x4
  unsigned __int64 v14; // x5
  unsigned __int64 v15; // x6
  unsigned __int64 v16; // x7
  unsigned __int64 v17; // x19
  unsigned __int64 v18; // x20
  unsigned __int64 v19; // x21
  unsigned __int64 v20; // x22
  unsigned __int64 v21; // x23
  unsigned __int64 v22; // x24
  unsigned __int64 v23; // x25
  unsigned __int64 v24; // x26
  unsigned __int64 v25; // x27
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x0
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x1
  __int64 v31; // x8

  v2 = *a1;
  v3 = a1[1] + *a1;
  v4 = a1[2] + v3;
  v5 = a1[3] + v4;
  v6 = a1[4] + v5;
  v7 = a1[5] + v6;
  v8 = a1[6] + v7;
  v9 = a1[7] + v8;
  v10 = a1[8] + v9;
  v11 = a1[9] + v10;
  v12 = a1[10] + v11;
  v13 = a1[11] + v12;
  v14 = a1[12] + v13;
  v15 = a1[13] + v14;
  v16 = a1[14] + v15;
  v17 = a1[15] + v16;
  v18 = a1[16] + v17;
  v19 = a1[17] + v18;
  v20 = a1[18] + v19;
  v21 = a1[19] + v20;
  v22 = a1[20] + v21;
  v23 = a1[21] + v22;
  v24 = a1[22] + v23;
  v25 = a1[23] + v24;
  v26 = a1[25];
  v27 = a1[24] + v25;
  v28 = v26 + v27;
  if ( !v28 )
    return 0;
  v29 = v28 * a2 / 0x64;
  if ( v2 >= v29 )
  {
    v31 = 0;
  }
  else if ( v3 >= v29 )
  {
    v31 = 1;
  }
  else if ( v4 >= v29 )
  {
    v31 = 2;
  }
  else if ( v5 >= v29 )
  {
    v31 = 3;
  }
  else if ( v6 >= v29 )
  {
    v31 = 4;
  }
  else if ( v7 >= v29 )
  {
    v31 = 5;
  }
  else if ( v8 >= v29 )
  {
    v31 = 6;
  }
  else if ( v9 >= v29 )
  {
    v31 = 7;
  }
  else if ( v10 >= v29 )
  {
    v31 = 8;
  }
  else if ( v11 >= v29 )
  {
    v31 = 9;
  }
  else if ( v12 >= v29 )
  {
    v31 = 10;
  }
  else if ( v13 >= v29 )
  {
    v31 = 11;
  }
  else if ( v14 >= v29 )
  {
    v31 = 12;
  }
  else if ( v15 >= v29 )
  {
    v31 = 13;
  }
  else if ( v16 >= v29 )
  {
    v31 = 14;
  }
  else if ( v17 >= v29 )
  {
    v31 = 15;
  }
  else if ( v18 >= v29 )
  {
    v31 = 16;
  }
  else if ( v19 >= v29 )
  {
    v31 = 17;
  }
  else if ( v20 >= v29 )
  {
    v31 = 18;
  }
  else if ( v21 >= v29 )
  {
    v31 = 19;
  }
  else if ( v22 >= v29 )
  {
    v31 = 20;
  }
  else if ( v23 >= v29 )
  {
    v31 = 21;
  }
  else if ( v24 >= v29 )
  {
    v31 = 22;
  }
  else if ( v25 >= v29 )
  {
    v31 = 23;
  }
  else if ( v27 >= v29 )
  {
    v31 = 24;
  }
  else
  {
    if ( v28 < v29 )
      return 0;
    v31 = 25;
  }
  return latency_perc_bucket[v31];
}
