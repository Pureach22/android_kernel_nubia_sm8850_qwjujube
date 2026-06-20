__int64 __fastcall rmnet_sch_next_to_drop(_DWORD *a1)
{
  unsigned int v1; // w10
  unsigned int v2; // w11
  unsigned int v3; // w8
  unsigned int v4; // w14
  unsigned int v5; // w1
  unsigned int v6; // w17
  int v7; // w12
  unsigned int v8; // w16
  int v9; // w13
  bool v10; // cf
  bool v11; // zf
  unsigned int v12; // w10
  unsigned int v13; // w15
  int v14; // w13
  unsigned int v15; // w9
  int v16; // w13
  int v17; // w2
  int v18; // w13
  unsigned int v19; // w2
  int v20; // w3
  unsigned int v21; // w13
  unsigned int v22; // w17
  int v23; // w0
  unsigned int v24; // w8

  v2 = a1[8];
  v1 = a1[9];
  v3 = a1[4];
  v4 = a1[14];
  v5 = a1[28];
  v6 = a1[29];
  v7 = v3 - v1;
  v8 = a1[24];
  if ( (int)(v3 - v1) < 0 )
    v7 = -1;
  v9 = v3 - v1;
  if ( v3 <= v1 )
    v7 = -1;
  v10 = v3 >= v1;
  v11 = v3 == v1;
  v12 = a1[18];
  v13 = a1[19];
  v14 = 4 * (v9 < -1);
  if ( !v11 && v10 )
    v15 = v14;
  else
    v15 = 4;
  v16 = v4 - v13;
  if ( (int)(v4 - v13) >= v7 )
    v17 = 1;
  else
    v17 = v15;
  if ( v16 <= v7 )
    v16 = v7;
  if ( v4 > v13 )
  {
    v15 = v17;
    v7 = v16;
  }
  v18 = v8 - v6;
  v19 = a1[34];
  if ( (int)(v8 - v6) >= v7 )
    v20 = 2;
  else
    v20 = v15;
  if ( v18 <= v7 )
    v18 = v7;
  if ( v8 > v6 )
  {
    v7 = v18;
    v15 = v20;
  }
  v21 = a1[38];
  v22 = a1[39];
  if ( (int)(v19 - v22) >= v7 )
    v23 = 3;
  else
    v23 = v15;
  if ( v19 > v22 )
    v15 = v23;
  v24 = 4 * (v3 <= v2);
  if ( v4 > v12 )
    v24 = 1;
  if ( v8 > v5 )
    v24 = 2;
  if ( v19 > v21 )
    v24 = 3;
  if ( v15 >= 4 )
    return v24;
  else
    return v15;
}
