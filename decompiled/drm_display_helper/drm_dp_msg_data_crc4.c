__int64 __fastcall drm_dp_msg_data_crc4(__int64 a1, unsigned __int8 a2)
{
  int v2; // w8
  int v3; // w10
  unsigned __int8 v4; // w14
  int v5; // w15
  int v6; // w16
  unsigned int v7; // w17
  unsigned int v8; // w17
  int v9; // w17
  int v11; // w8
  int v12; // w8
  int v13; // w8
  int v14; // w8
  int v15; // w8
  int v16; // w8
  int v17; // w8

  if ( a2 )
  {
    v2 = 0;
    v3 = -8 * a2;
    v4 = 0;
    v5 = 7;
    LOBYTE(v6) = 0x80;
    do
    {
      v7 = (unsigned __int8)(v6 & *(_BYTE *)(a1 + v4));
      v6 = (unsigned __int8)v6 >> 1;
      v8 = v7 >> v5--;
      if ( !v6 )
      {
        ++v4;
        LOBYTE(v6) = 0x80;
        v5 = 7;
      }
      v9 = v8 | (2 * v2);
      if ( (v2 & 0x80) != 0 )
        v2 = v9 ^ 0xD5;
      else
        v2 = v9;
    }
    while ( !__CFADD__(v3++, 1) );
  }
  else
  {
    v2 = 0;
  }
  if ( (v2 & 0x80) != 0 )
    v11 = (2 * v2) ^ 0xD5;
  else
    v11 = 2 * v2;
  if ( (v11 & 0x80) != 0 )
    v12 = (2 * v11) ^ 0xD5;
  else
    v12 = 2 * v11;
  if ( (v12 & 0x80) != 0 )
    v13 = (2 * v12) ^ 0xD5;
  else
    v13 = 2 * v12;
  if ( (v13 & 0x80) != 0 )
    v14 = (2 * v13) ^ 0xD5;
  else
    v14 = 2 * v13;
  if ( (v14 & 0x80) != 0 )
    v15 = (2 * v14) ^ 0xD5;
  else
    v15 = 2 * v14;
  if ( (v15 & 0x80) != 0 )
    v16 = (2 * v15) ^ 0xD5;
  else
    v16 = 2 * v15;
  if ( (v16 & 0x80) != 0 )
    v17 = (2 * v16) ^ 0xD5;
  else
    v17 = 2 * v16;
  if ( (v17 & 0x80) != 0 )
    return (2 * v17) ^ 0xD5u;
  else
    return (unsigned int)(2 * v17);
}
