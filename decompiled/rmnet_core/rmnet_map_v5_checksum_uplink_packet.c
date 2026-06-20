__int64 __fastcall rmnet_map_v5_checksum_uplink_packet(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 result; // x0
  bool v9; // zf
  __int64 v10; // x8
  __int16 v11; // w8
  int v12; // w8
  int v13; // w9
  unsigned __int8 *v14; // x10
  __int64 v15; // x9
  int v16; // w10
  __int64 v17; // x8

  result = skb_push(a1, 4);
  *(_DWORD *)result = 4;
  if ( (*(_BYTE *)(a2 + 11) & 0x10) != 0 )
  {
    if ( *(_DWORD *)(a1 + 144) == 14286874 )
    {
      ++*(_QWORD *)(a3 + 3096);
      *(_WORD *)result |= 0x2000u;
    }
    if ( (a4 & 1) != 0 )
    {
      v9 = (*(_DWORD *)(a1 + 144) & 0xFFFF0200) == -1687354880;
      v10 = 3160;
      if ( (*(_DWORD *)(a1 + 144) & 0xFFFF0200) == 0x9B6D0200 )
        v10 = 3096;
      ++*(_QWORD *)(a3 + v10);
      if ( v9 )
        v11 = 0x2000;
      else
        v11 = 4096;
      *(_WORD *)result |= v11;
    }
  }
  if ( (*(_BYTE *)(a2 + 8) & 0x40) != 0 )
  {
    v12 = *(unsigned __int8 *)(a1 + 128);
    if ( (~v12 & 0x60) == 0 )
    {
      v13 = *(unsigned __int16 *)(a1 + 180);
      if ( v13 == 56710 )
      {
        v14 = (unsigned __int8 *)(result + 10);
        v15 = result + 44;
      }
      else
      {
        if ( v13 != 8 )
        {
          ++*(_QWORD *)(a3 + 2752);
          goto LABEL_24;
        }
        v14 = (unsigned __int8 *)(result + 13);
        v15 = result + 4 + 4LL * (*(_BYTE *)(result + 4) & 0xF);
      }
      v16 = *v14;
      if ( v16 != 6 )
      {
        if ( v16 != 17 || v15 == -6 )
          goto LABEL_24;
LABEL_23:
        *(_BYTE *)(a1 + 128) = v12 & 0x9F;
        *(_WORD *)result |= 0x8000u;
        v17 = 2792;
LABEL_25:
        ++*(_QWORD *)(a3 + v17);
        return result;
      }
      if ( v15 != -16 )
        goto LABEL_23;
    }
LABEL_24:
    v17 = 2784;
    goto LABEL_25;
  }
  return result;
}
