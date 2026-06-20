__int64 __fastcall ipv4_packet_match(__int64 a1, char *a2, __int64 a3)
{
  _BOOL4 v3; // w19
  int v4; // w8
  int v5; // w9
  _BOOL4 v6; // w22
  _BOOL4 v7; // w23
  _BOOL4 v8; // w20
  _BOOL4 v9; // w21
  char v10; // w9
  int v11; // w8
  __int64 v12; // x1
  unsigned __int16 *v13; // x24
  unsigned __int16 *v14; // x0
  unsigned int v15; // w9
  unsigned int v16; // w9
  __int64 v18; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-20h] BYREF
  int v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a3 + 43) )
    v3 = a2[9] == *(_BYTE *)(a3 + 42);
  else
    v3 = 1;
  v4 = *(unsigned __int16 *)(a3 + 34);
  v5 = *(unsigned __int16 *)(a3 + 38);
  v6 = *(_WORD *)(a3 + 34) == 0;
  v7 = v5 == 0;
  if ( *(_BYTE *)(a3 + 40) )
  {
    v8 = ((*(_DWORD *)(a3 + 16) ^ *((_DWORD *)a2 + 3)) & *(_DWORD *)(a3 + 64)) == 0;
    if ( *(_BYTE *)(a3 + 41) )
      goto LABEL_6;
LABEL_9:
    v9 = 1;
    if ( !(v4 | v5) )
      goto LABEL_7;
    goto LABEL_10;
  }
  v8 = 1;
  if ( !*(_BYTE *)(a3 + 41) )
    goto LABEL_9;
LABEL_6:
  v9 = ((*(_DWORD *)a3 ^ *((_DWORD *)a2 + 4)) & *(_DWORD *)(a3 + 48)) == 0;
  if ( !(v4 | v5) )
  {
LABEL_7:
    v6 = 1;
    v7 = 1;
    goto LABEL_24;
  }
LABEL_10:
  v10 = *a2;
  v11 = (unsigned __int8)a2[9];
  v20 = 0;
  v19[0] = 0;
  v19[1] = 0;
  v12 = 4 * (v10 & 0xFu);
  v18 = 0;
  if ( v11 == 17 )
  {
    v13 = (unsigned __int16 *)a3;
    v14 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *))rmnet_shs_header_ptr)(
                                a1,
                                v12,
                                8,
                                &v18);
    if ( v14 )
      goto LABEL_13;
LABEL_19:
    v6 = 0;
    v7 = 0;
    goto LABEL_24;
  }
  if ( v11 != 6 )
    goto LABEL_24;
  v13 = (unsigned __int16 *)a3;
  v14 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *))rmnet_shs_header_ptr)(
                              a1,
                              v12,
                              20,
                              v19);
  if ( !v14 )
    goto LABEL_19;
LABEL_13:
  if ( v13[17] )
  {
    v15 = bswap32(*v14) >> 16;
    if ( v15 >= bswap32(v13[16]) >> 16 )
    {
      v6 = v15 <= bswap32(v13[40]) >> 16;
      if ( !v13[19] )
        goto LABEL_24;
      goto LABEL_21;
    }
    v6 = 0;
  }
  if ( !v13[19] )
    goto LABEL_24;
LABEL_21:
  v16 = bswap32(v14[1]) >> 16;
  v7 = v16 >= bswap32(v13[18]) >> 16 && v16 <= bswap32(v13[41]) >> 16;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return (v8 && v9 && v3 && v6) & (unsigned int)v7;
}
