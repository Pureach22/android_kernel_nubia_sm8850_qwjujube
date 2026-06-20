__int64 __fastcall wlan_mlme_get_min_he_mcs_map(unsigned __int16 a1, unsigned __int16 a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w10
  unsigned int v4; // w12
  int v5; // w11
  unsigned int v6; // w13
  int v7; // w12
  unsigned int v8; // w13
  int v9; // w12
  unsigned int v10; // w14
  int v11; // w13
  unsigned int v12; // w14
  int v13; // w13
  unsigned int v14; // w15
  int v15; // w14
  unsigned int v16; // w15
  int v17; // w14
  unsigned int v18; // w16
  int v19; // w15
  unsigned int v20; // w16
  int v21; // w15
  unsigned int v22; // w17
  int v23; // w16
  unsigned int v24; // w17
  int v25; // w16
  unsigned int v26; // w0
  int v27; // w17
  unsigned int v28; // w10
  int v29; // w9
  unsigned int v30; // w9
  int v31; // w10

  v2 = a1 & 3;
  v3 = a1;
  if ( v2 != 3 )
  {
    if ( v2 >= (a2 & 3u) )
      v2 = a2 & 3;
    if ( (a2 & 3) == 3 )
      v2 = 3;
  }
  v4 = (a1 >> 2) & 3;
  v5 = 12;
  if ( v4 != 3 )
  {
    v6 = (a2 >> 2) & 3;
    if ( v4 >= v6 )
      v4 = (a2 >> 2) & 3;
    v7 = 4 * v4;
    if ( v6 == 3 )
      v5 = 12;
    else
      v5 = v7;
  }
  v8 = (a1 >> 4) & 3;
  v9 = 48;
  if ( v8 != 3 )
  {
    v10 = (a2 >> 4) & 3;
    if ( v8 >= v10 )
      v8 = (a2 >> 4) & 3;
    v11 = 16 * v8;
    if ( v10 == 3 )
      v9 = 48;
    else
      v9 = v11;
  }
  v12 = (unsigned __int8)a1 >> 6;
  v13 = 192;
  if ( v12 != 3 )
  {
    v14 = (unsigned __int8)a2 >> 6;
    if ( v12 >= v14 )
      v12 = (unsigned __int8)a2 >> 6;
    v15 = v12 << 6;
    if ( v14 == 3 )
      v13 = 192;
    else
      v13 = v15;
  }
  v16 = HIBYTE(a1) & 3;
  v17 = 768;
  if ( v16 != 3 )
  {
    v18 = HIBYTE(a2) & 3;
    if ( v16 >= v18 )
      v16 = HIBYTE(a2) & 3;
    v19 = v16 << 8;
    if ( v18 == 3 )
      v17 = 768;
    else
      v17 = v19;
  }
  v20 = (a1 >> 10) & 3;
  v21 = 3072;
  if ( v20 != 3 )
  {
    v22 = (a2 >> 10) & 3;
    if ( v20 >= v22 )
      v20 = (a2 >> 10) & 3;
    v23 = v20 << 10;
    if ( v22 == 3 )
      v21 = 3072;
    else
      v21 = v23;
  }
  v24 = (a1 >> 12) & 3;
  v25 = 12288;
  if ( v24 != 3 )
  {
    v26 = (a2 >> 12) & 3;
    if ( v24 >= v26 )
      v24 = (a2 >> 12) & 3;
    v27 = v24 << 12;
    if ( v26 == 3 )
      v25 = 12288;
    else
      v25 = v27;
  }
  v28 = v3 >> 14;
  if ( v28 == 3 )
  {
    v29 = 49152;
  }
  else
  {
    v30 = a2 >> 14;
    if ( v28 >= v30 )
      v28 = a2 >> 14;
    v31 = v28 << 14;
    if ( v30 == 3 )
      v29 = -16384;
    else
      v29 = v31;
  }
  return v2 | v5 | v9 | v13 | v17 | v21 | v25 | v29;
}
