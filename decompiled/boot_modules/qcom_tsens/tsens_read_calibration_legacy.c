__int64 __fastcall tsens_read_calibration_legacy(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned int v6; // w8
  __int64 v7; // x9
  int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w8
  __int64 v11; // x10
  int v12; // w10
  int v13; // w11
  int v14; // w9
  __int64 v15; // x10
  int v16; // w9
  int v17; // w10
  __int64 v18; // x13
  int v19; // w10
  int v20; // w11
  unsigned int v21; // w16
  int v22; // w15
  unsigned int v23; // w15
  unsigned __int8 *v24; // x15
  int v25; // w17
  int v26; // w6
  __int64 v27; // x7
  int v28; // w6
  int v29; // w17
  int v30; // w6
  __int64 v31; // x7
  int v32; // w9
  unsigned int v33; // w12
  int v34; // w10
  unsigned int v35; // w10
  unsigned int v36; // w10
  unsigned int v37; // w9

  v6 = a2[13];
  if ( a2[14] )
    v7 = a6;
  else
    v7 = a5;
  if ( v6 > 0x1E )
    v8 = ((2 * *(_DWORD *)(v7 + 4LL * a2[12] + 4)) << ~(_BYTE)v6) | (*(_DWORD *)(v7 + 4LL * a2[12]) >> v6);
  else
    v8 = *(_DWORD *)(v7 + 4LL * a2[12]) >> v6;
  v9 = a2[16];
  v10 = v8 & 3;
  if ( a2[17] )
    v11 = a6;
  else
    v11 = a5;
  if ( v9 > 0x1F )
    v12 = ((2 * *(_DWORD *)(v11 + 4LL * a2[15] + 4)) << ~(_BYTE)v9) | (*(_DWORD *)(v11 + 4LL * a2[15]) >> v9);
  else
    v12 = *(_DWORD *)(v11 + 4LL * a2[15]) >> v9;
  v13 = *a2;
  v14 = a2[19];
  if ( (v12 & 1) != 0 )
    v10 = 0;
  if ( a2[20] )
    v15 = a6;
  else
    v15 = a5;
  if ( (unsigned int)(v13 + v14) > 0x20 )
    v16 = ((2 * *(_DWORD *)(v15 + 4LL * a2[18] + 4)) << ~(_BYTE)v14) | (*(_DWORD *)(v15 + 4LL * a2[18]) >> v14);
  else
    v16 = *(_DWORD *)(v15 + 4LL * a2[18]) >> v14;
  v17 = a2[22];
  if ( a2[23] )
    v18 = a6;
  else
    v18 = a5;
  if ( (unsigned int)(v13 + v17) > 0x20 )
    v19 = ((2 * *(_DWORD *)(v18 + 4LL * a2[21] + 4)) << ~(_BYTE)v17) | (*(_DWORD *)(v18 + 4LL * a2[21]) >> v17);
  else
    v19 = *(_DWORD *)(v18 + 4LL * a2[21]) >> v17;
  v20 = -1 << v13;
  if ( *(_DWORD *)(a1 + 8) )
  {
    v21 = 0;
    do
    {
      v24 = &a2[6 * v21 + 24];
      v25 = a2[8];
      v26 = v24[1];
      if ( v24[2] )
        v27 = a6;
      else
        v27 = a5;
      if ( (unsigned int)(v25 + v26) > 0x20 )
        v28 = ((2 * *(_DWORD *)(v27 + 4LL * *v24 + 4)) << ~(_BYTE)v26) | (*(_DWORD *)(v27 + 4LL * *v24) >> v26);
      else
        v28 = *(_DWORD *)(v27 + 4LL * *v24) >> v26;
      *(_DWORD *)(a3 + 4LL * (int)v21) = v28 & ~(-1 << v25);
      v29 = a2[8];
      v30 = v24[4];
      if ( v24[5] )
        v31 = a6;
      else
        v31 = a5;
      if ( (unsigned int)(v29 + v30) <= 0x20 )
        v22 = *(_DWORD *)(v31 + 4LL * v24[3]) >> v30;
      else
        v22 = ((2 * *(_DWORD *)(v31 + 4LL * v24[3] + 4)) << ~(_BYTE)v30) | (*(_DWORD *)(v31 + 4LL * v24[3]) >> v30);
      *(_DWORD *)(a4 + 4LL * (int)v21++) = v22 & ~(-1 << v29);
      v23 = *(_DWORD *)(a1 + 8);
    }
    while ( v21 < v23 );
  }
  else
  {
    v23 = 0;
  }
  v32 = v16 & ~v20;
  switch ( v10 )
  {
    case 1u:
      if ( v23 )
      {
        v36 = 0;
        do
          *(_DWORD *)(a3 + 4LL * (int)v36++) += v32 << *((_DWORD *)a2 + 1);
        while ( v36 < *(_DWORD *)(a1 + 8) );
      }
      break;
    case 2u:
LABEL_50:
      if ( v23 )
      {
        v35 = 0;
        do
        {
          *(_DWORD *)(a3 + 4LL * (int)v35) = (*(_DWORD *)(a3 + 4LL * (int)v35) + v32) << *((_DWORD *)a2 + 1);
          ++v35;
        }
        while ( v35 < *(_DWORD *)(a1 + 8) );
      }
      return v10;
    case 3u:
      if ( !v23 )
        return v10;
      v33 = 0;
      v34 = v19 & ~v20;
      do
      {
        *(_DWORD *)(a4 + 4LL * (int)v33) = (*(_DWORD *)(a4 + 4LL * (int)v33) + v34) << *((_DWORD *)a2 + 1);
        ++v33;
        v23 = *(_DWORD *)(a1 + 8);
      }
      while ( v33 < v23 );
      goto LABEL_50;
    default:
      if ( v23 )
      {
        v37 = 0;
        do
        {
          *(_DWORD *)(a3 + 4LL * (int)v37) = 500;
          *(_DWORD *)(a4 + 4LL * (int)v37++) = 780;
        }
        while ( v37 < *(_DWORD *)(a1 + 8) );
      }
      break;
  }
  return v10;
}
