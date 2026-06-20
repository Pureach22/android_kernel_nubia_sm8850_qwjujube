__int64 __fastcall reg_get_max_bandwidth(__int64 a1, unsigned int *a2)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x12
  __int64 v4; // x11
  unsigned __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x13
  bool v8; // zf
  unsigned int v9; // w8
  unsigned int *v10; // x12
  unsigned int *v11; // x14
  unsigned int v12; // w11
  __int64 v13; // x15
  unsigned __int64 v14; // x8
  unsigned int *v15; // x9
  unsigned __int64 v16; // x8
  unsigned int v17; // w10
  bool v18; // cc
  unsigned int v19; // w9
  int v20; // w10
  int v21; // w10
  int v22; // w10
  unsigned int v23; // w10

  v2 = *(unsigned int *)(a1 + 16);
  v3 = 0;
  v4 = a1 + 28;
  v5 = -1;
  v6 = 2;
  do
  {
    ++v5;
    v7 = v3 + 96;
    --v6;
    if ( v5 >= v2 )
      break;
    v8 = v4 + v3 == (_QWORD)a2;
    v3 += 96;
  }
  while ( !v8 );
  if ( (_DWORD)v2 == (_DWORD)v5 )
  {
    v9 = 0;
  }
  else
  {
    v10 = (unsigned int *)(v4 + v7);
    v11 = a2;
    do
    {
      v12 = *v11;
      if ( v7 == 96 )
        break;
      v13 = a1 + v7;
      v7 -= 96;
      v11 = (unsigned int *)(v13 - 164);
    }
    while ( *(_DWORD *)(v13 - 160) >= v12 );
    v14 = (unsigned int)(v2 - 1);
    if ( v5 > v14 )
      v14 = v5;
    v15 = a2;
    v16 = v14 + v6;
    while ( --v16 )
    {
      v17 = v15[1];
      v15 = v10;
      v18 = *v10 > v17;
      v10 += 24;
      if ( v18 )
        goto LABEL_18;
    }
    v17 = v15[1];
LABEL_18:
    v9 = v17 - v12;
  }
  v19 = a2[21];
  if ( v9 >= 0x27100 )
    v20 = 160000;
  else
    v20 = v9;
  if ( (v19 & 0x40000) != 0 )
    v9 = v20;
  if ( v9 >= 0x13880 )
    v21 = 80000;
  else
    v21 = v9;
  if ( (v19 & 0x10000) != 0 )
    v9 = v21;
  if ( v9 >= 0x9C40 )
    v22 = 40000;
  else
    v22 = v9;
  if ( (v19 & 0x8000) != 0 )
    v9 = v22;
  if ( v9 >= 0x4E20 )
    v23 = 20000;
  else
    v23 = v9;
  if ( (~v19 & 0x6000) != 0 )
    return v9;
  else
    return v23;
}
