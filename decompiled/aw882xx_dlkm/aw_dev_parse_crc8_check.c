__int64 __fastcall aw_dev_parse_crc8_check(unsigned __int8 *a1, int a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w10
  unsigned int v4; // t1
  unsigned int v5; // w8
  int v6; // w11
  unsigned int v7; // w8
  int v8; // w11
  unsigned int v9; // w8
  int v10; // w11
  unsigned int v11; // w8
  int v12; // w11
  unsigned int v13; // w8
  int v14; // w11
  unsigned int v15; // w8
  int v16; // w11
  unsigned int v17; // w8

  v2 = 0;
  while ( a2 )
  {
    v4 = *a1++;
    v3 = v4;
    --a2;
    if ( (((unsigned __int8)v4 ^ (unsigned __int8)v2) & 1) != 0 )
      v5 = (v2 >> 1) ^ 0x8C;
    else
      v5 = v2 >> 1;
    v6 = v5 ^ (v3 >> 1);
    v7 = v5 >> 1;
    if ( (v6 & 1) != 0 )
      v7 ^= 0x8Cu;
    v8 = v7 ^ (v3 >> 2);
    v9 = v7 >> 1;
    if ( (v8 & 1) != 0 )
      v9 ^= 0x8Cu;
    v10 = v9 ^ (v3 >> 3);
    v11 = v9 >> 1;
    if ( (v10 & 1) != 0 )
      v11 ^= 0x8Cu;
    v12 = v11 ^ (v3 >> 4);
    v13 = v11 >> 1;
    if ( (v12 & 1) != 0 )
      v13 ^= 0x8Cu;
    v14 = v13 ^ (v3 >> 5);
    v15 = v13 >> 1;
    if ( (v14 & 1) != 0 )
      v15 ^= 0x8Cu;
    v16 = v15 ^ (v3 >> 6);
    v17 = v15 >> 1;
    if ( (v16 & 1) != 0 )
      v17 ^= 0x8Cu;
    if ( (v17 & 1) == v3 >> 7 )
      v2 = v17 >> 1;
    else
      v2 = (v17 >> 1) ^ 0x8C;
  }
  return v2;
}
