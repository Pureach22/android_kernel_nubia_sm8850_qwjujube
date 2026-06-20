__int64 __fastcall dp_mst_sim_encode_sideband_msg_hdr(__int64 result, _BYTE *a2, unsigned int *a3)
{
  unsigned int v3; // w13
  int v4; // w12
  unsigned __int8 v5; // w11
  int v6; // w3
  _BYTE *v7; // x8
  char v8; // w9
  char v9; // w10
  char v10; // w14
  char v11; // w10
  unsigned int v12; // w9
  int v13; // w13
  char v14; // w10
  unsigned int v15; // w4
  unsigned int v16; // w4
  char v18; // w11
  bool v19; // zf
  char v20; // w12
  char v21; // w12
  char v22; // w11
  char v23; // w12
  char v24; // w11
  char v25; // w12
  char v26; // w11

  *a2 = *(_BYTE *)(result + 1) & 0xF | (16 * *(_BYTE *)result);
  if ( *(unsigned __int8 *)result >= 2u )
  {
    a2[1] = *(_BYTE *)(result + 2);
    if ( *(unsigned __int8 *)result <= 3u )
    {
      v3 = 2;
    }
    else
    {
      a2[2] = *(_BYTE *)(result + 3);
      if ( *(unsigned __int8 *)result < 6u )
      {
        v3 = 3;
      }
      else
      {
        a2[3] = *(_BYTE *)(result + 4);
        if ( *(unsigned __int8 *)result < 8u )
        {
          v3 = 4;
        }
        else
        {
          a2[4] = *(_BYTE *)(result + 5);
          if ( *(unsigned __int8 *)result < 0xAu )
          {
            v3 = 5;
          }
          else
          {
            a2[5] = *(_BYTE *)(result + 6);
            if ( *(unsigned __int8 *)result < 0xCu )
            {
              v3 = 6;
            }
            else
            {
              a2[6] = *(_BYTE *)(result + 7);
              if ( *(unsigned __int8 *)result < 0xEu )
              {
                v3 = 7;
              }
              else
              {
                a2[7] = *(_BYTE *)(result + 8);
                if ( *(unsigned __int8 *)result < 0x10u )
                {
                  v3 = 8;
                }
                else
                {
                  a2[8] = *(_BYTE *)(result + 9);
                  if ( *(unsigned __int8 *)result > 0x11u )
                  {
                    __break(0x5512u);
                    return dp_mst_sim_msg_data_crc4(result, a2);
                  }
                  v3 = 9;
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v3 = 1;
  }
  v4 = 0;
  v5 = 0;
  LOBYTE(v6) = 0x80;
  v7 = &a2[v3];
  *v7 = (*(_BYTE *)(result + 11) << 6) | (*(_BYTE *)(result + 10) << 7) | *(_BYTE *)(result + 12) & 0x3F;
  v8 = *(_BYTE *)(result + 14);
  v9 = *(_BYTE *)(result + 13);
  v10 = *(_BYTE *)(result + 15);
  LODWORD(result) = 7;
  v11 = (v8 << 6) | (v9 << 7);
  v12 = v3 + 2;
  v13 = -12 - 8 * v3;
  v14 = v11 | (16 * v10);
  v7[1] = v14;
  do
  {
    v15 = (unsigned __int8)(v6 & a2[v5]);
    v6 = (unsigned __int8)v6 >> 1;
    v16 = v15 >> result;
    LODWORD(result) = result - 1;
    if ( v6 )
    {
      result = (unsigned int)result;
    }
    else
    {
      ++v5;
      LOBYTE(v6) = 0x80;
      result = 7;
    }
    v4 = v16 | (2 * v4);
    if ( (v4 & 0x10) != 0 )
      v4 ^= 0x13u;
  }
  while ( !__CFADD__(v13++, 1) );
  v18 = 2 * v4;
  v19 = (v4 & 8) == 0;
  v20 = (2 * v4) ^ 0x13;
  if ( !v19 )
    v18 = v20;
  v21 = 2 * v18;
  v19 = (v18 & 8) == 0;
  v22 = (2 * v18) ^ 0x13;
  if ( v19 )
    v22 = v21;
  v23 = 2 * v22;
  v19 = (v22 & 8) == 0;
  v24 = (2 * v22) ^ 0x13;
  if ( v19 )
    v24 = v23;
  v25 = 2 * v24;
  v19 = (v24 & 8) == 0;
  v26 = (2 * v24) ^ 3;
  if ( v19 )
    v26 = v25;
  v7[1] = v26 & 0xF | v14;
  *a3 = v12;
  return result;
}
