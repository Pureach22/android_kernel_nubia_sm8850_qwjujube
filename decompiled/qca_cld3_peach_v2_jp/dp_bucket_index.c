__int64 __fastcall dp_bucket_index(unsigned int a1, unsigned __int16 *a2, char a3)
{
  unsigned int v3; // w11
  unsigned int v4; // w9
  unsigned int v6; // w8
  unsigned int v8; // w10
  unsigned int v9; // w8
  unsigned int v10; // w10
  unsigned int v11; // w8
  unsigned int v12; // w10
  unsigned int v13; // w8
  unsigned int v14; // w10
  unsigned int v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w8

  v3 = 1000 * *a2;
  if ( (a3 & 1) != 0 )
  {
    v4 = 1000 * a2[1];
  }
  else
  {
    v3 = *a2;
    v4 = a2[1];
  }
  if ( v3 <= a1 && v4 >= a1 )
    return 0;
  v6 = 1000 * a2[2];
  if ( (a3 & 1) == 0 )
    v6 = a2[2];
  if ( v4 <= a1 && v6 >= a1 )
    return 1;
  v8 = a2[3];
  if ( (a3 & 1) != 0 )
    v8 *= 1000;
  if ( v6 <= a1 && v8 >= a1 )
    return 2;
  v9 = a2[4];
  if ( (a3 & 1) != 0 )
    v9 *= 1000;
  if ( v8 <= a1 && v9 >= a1 )
    return 3;
  v10 = a2[5];
  if ( (a3 & 1) != 0 )
    v10 *= 1000;
  if ( v9 <= a1 && v10 >= a1 )
    return 4;
  v11 = a2[6];
  if ( (a3 & 1) != 0 )
    v11 *= 1000;
  if ( v10 <= a1 && v11 >= a1 )
    return 5;
  v12 = a2[7];
  if ( (a3 & 1) != 0 )
    v12 *= 1000;
  if ( v11 <= a1 && v12 >= a1 )
    return 6;
  v13 = a2[8];
  if ( (a3 & 1) != 0 )
    v13 *= 1000;
  if ( v12 <= a1 && v13 >= a1 )
    return 7;
  v14 = a2[9];
  if ( (a3 & 1) != 0 )
    v14 *= 1000;
  if ( v13 <= a1 && v14 >= a1 )
    return 8;
  v15 = a2[10];
  if ( (a3 & 1) != 0 )
    v15 *= 1000;
  if ( v14 <= a1 && v15 >= a1 )
    return 9;
  v16 = a2[11];
  if ( (a3 & 1) != 0 )
    v16 *= 1000;
  if ( v15 <= a1 && v16 >= a1 )
    return 10;
  v17 = a2[12];
  if ( (a3 & 1) != 0 )
    v17 *= 1000;
  if ( v17 < a1 || v16 > a1 )
    return 12;
  else
    return 11;
}
