__int64 __fastcall rmnet_map_v4_checksum_uplink_packet(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w9
  __int64 v6; // x8
  int v7; // w10
  int v8; // w9
  int v9; // w11
  unsigned int v10; // w9
  int v11; // w10
  __int64 v12; // x10
  int v13; // w10
  int v14; // w9
  int v15; // w11
  unsigned int v16; // w9
  int v17; // w9
  __int64 v18; // x9
  __int64 v19; // x8

  result = skb_push(a1, 4);
  if ( (*(_BYTE *)(a2 + 184) & 0x12) != 0 && (~*(unsigned __int8 *)(a1 + 128) & 0x60) == 0 )
  {
    v5 = *(unsigned __int16 *)(a1 + 180);
    v6 = result + 4;
    if ( v5 == 56710 )
    {
      v13 = *(unsigned __int8 *)(result + 10);
      *(_WORD *)result = bswap32(*(_DWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 182) - v6) >> 16;
      v14 = *(unsigned __int16 *)(a1 + 142);
      v15 = v14 & 0x3FFF | 0x8000;
      v16 = v14 | 0xC000;
      if ( v13 != 17 )
        v16 = v15;
      *(_WORD *)(result + 2) = __rev16(v16);
      *(_BYTE *)(a1 + 128) &= 0x9Fu;
      v17 = *(unsigned __int8 *)(result + 10);
      if ( v17 == 6 )
      {
        v18 = 56;
      }
      else
      {
        if ( v17 != 17 )
          goto LABEL_21;
        v18 = 46;
      }
      *(_WORD *)(v6 + v18) = ~*(_WORD *)(v6 + v18);
      goto LABEL_21;
    }
    if ( v5 == 8 )
    {
      v7 = *(unsigned __int8 *)(result + 13);
      *(_WORD *)result = bswap32(*(_DWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 182) - v6) >> 16;
      v8 = *(unsigned __int16 *)(a1 + 142);
      v9 = v8 & 0x3FFF | 0x8000;
      v10 = v8 | 0xC000;
      if ( v7 != 17 )
        v10 = v9;
      *(_WORD *)(result + 2) = __rev16(v10);
      *(_BYTE *)(a1 + 128) &= 0x9Fu;
      v11 = *(unsigned __int8 *)(result + 13);
      if ( v11 == 6 )
      {
        v12 = 16;
        goto LABEL_18;
      }
      if ( v11 == 17 )
      {
        v12 = 6;
LABEL_18:
        *(_WORD *)(v6 + 4LL * (*(_BYTE *)(result + 4) & 0xF) + v12) = ~*(_WORD *)(v6
                                                                                + 4LL * (*(_BYTE *)(result + 4) & 0xF)
                                                                                + v12);
        v19 = 2792;
        goto LABEL_22;
      }
LABEL_21:
      v19 = 2792;
      goto LABEL_22;
    }
    ++*(_QWORD *)(a2 + 2752);
  }
  v19 = 2784;
  *(_DWORD *)result = 0;
LABEL_22:
  ++*(_QWORD *)(a2 + v19);
  return result;
}
