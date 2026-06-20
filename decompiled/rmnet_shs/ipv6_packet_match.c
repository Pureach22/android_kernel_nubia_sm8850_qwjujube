__int64 __fastcall ipv6_packet_match(__int64 a1, __int64 a2, __int64 a3)
{
  _BOOL4 v4; // w21
  _BOOL4 v5; // w22
  int v6; // w8
  _BOOL4 v7; // w23
  int v8; // w9
  int v9; // w10
  bool v10; // zf
  int v11; // w9
  _BOOL4 v12; // w24
  _BOOL4 v13; // w25
  __int64 result; // x0
  unsigned int v17; // w0
  int v18; // w8
  unsigned __int16 *v19; // x0
  unsigned __int16 *v20; // x8
  unsigned int v21; // w9
  unsigned int v22; // w10
  unsigned int v23; // w9
  _WORD v24[2]; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v25[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-20h] BYREF
  int v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a3 + 40) )
  {
    v4 = ((*(_OWORD *)(a3 + 16) ^ *(_OWORD *)(a2 + 8)) & *(_OWORD *)(a3 + 64)) == 0;
    if ( *(_BYTE *)(a3 + 41) )
      goto LABEL_3;
LABEL_6:
    v5 = 1;
    if ( *(_BYTE *)(a3 + 43) )
      goto LABEL_4;
    goto LABEL_7;
  }
  v4 = 1;
  if ( !*(_BYTE *)(a3 + 41) )
    goto LABEL_6;
LABEL_3:
  v5 = ((*(_OWORD *)a3 ^ *(_OWORD *)(a2 + 24)) & *(_OWORD *)(a3 + 48)) == 0;
  if ( *(_BYTE *)(a3 + 43) )
  {
LABEL_4:
    v6 = *(unsigned __int8 *)(a2 + 6);
    v7 = *(unsigned __int8 *)(a3 + 42) == v6;
    goto LABEL_8;
  }
LABEL_7:
  LOBYTE(v6) = *(_BYTE *)(a2 + 6);
  v7 = 1;
LABEL_8:
  v8 = *(unsigned __int16 *)(a3 + 34);
  v9 = *(unsigned __int16 *)(a3 + 38);
  v25[0] = v6;
  v10 = v8 == 0;
  v11 = v8 | v9;
  v12 = v10;
  v13 = v9 == 0;
  if ( v11 )
  {
    v28 = 0;
    v27[0] = 0;
    v27[1] = 0;
    v26 = 0;
    v24[0] = 0;
    v17 = ipv6_skip_exthdr(a1, 40, v25, v24);
    if ( (v17 & 0x80000000) != 0 )
    {
      result = 0;
      goto LABEL_14;
    }
    v18 = *(unsigned __int8 *)(a2 + 6);
    if ( v18 == 17 )
    {
      v19 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64 *))rmnet_shs_header_ptr)(
                                  a1,
                                  v17,
                                  8,
                                  &v26);
      if ( v19 )
      {
        v20 = (unsigned __int16 *)a3;
        if ( !*(_WORD *)(a3 + 34) )
          goto LABEL_30;
        v21 = bswap32(*v19) >> 16;
        if ( v21 >= bswap32(*(unsigned __int16 *)(a3 + 32)) >> 16 )
        {
          v22 = *(unsigned __int16 *)(a3 + 82);
          goto LABEL_29;
        }
LABEL_26:
        v12 = 0;
        goto LABEL_30;
      }
    }
    else
    {
      if ( v18 != 6 )
        goto LABEL_13;
      v19 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(
                                  a1,
                                  v17,
                                  20,
                                  v27);
      if ( v19 )
      {
        v20 = (unsigned __int16 *)a3;
        if ( !*(_WORD *)(a3 + 34) )
          goto LABEL_30;
        v21 = bswap32(*v19) >> 16;
        if ( v21 >= bswap32(*(unsigned __int16 *)(a3 + 32)) >> 16 )
        {
          v22 = *(unsigned __int16 *)(a3 + 80);
LABEL_29:
          v12 = v21 <= bswap32(v22) >> 16;
LABEL_30:
          if ( v20[19] )
          {
            v23 = bswap32(v19[1]) >> 16;
            v13 = v23 >= bswap32(v20[18]) >> 16 && v23 <= bswap32(v20[41]) >> 16;
          }
          goto LABEL_13;
        }
        goto LABEL_26;
      }
    }
    v12 = 0;
    v13 = 0;
    goto LABEL_13;
  }
  v12 = 1;
  v13 = 1;
LABEL_13:
  result = (v4 && v5 && v12 && v13) & (unsigned int)v7;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
