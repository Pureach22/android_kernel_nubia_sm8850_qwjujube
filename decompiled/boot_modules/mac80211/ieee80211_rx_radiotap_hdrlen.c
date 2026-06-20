__int64 __fastcall ieee80211_rx_radiotap_hdrlen(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w9
  unsigned int v7; // w8
  unsigned int v8; // w9
  int v9; // w10
  unsigned int v10; // w9
  unsigned int v11; // w9
  unsigned int v12; // w21
  int v13; // w0
  unsigned int v14; // w10
  bool v15; // zf
  int v16; // w8

  if ( *(_BYTE *)(a2 + 39) )
    v6 = 4 * _sw_hweight8(*(unsigned __int8 *)(a2 + 39)) + 16;
  else
    v6 = 16;
  v7 = *(_DWORD *)(a2 + 24);
  if ( (v7 & 0x30000) != 0 )
    v6 = ((v6 + 7) & 0xFFFFFFF8) + 8;
  v8 = v6 + (((unsigned int)*(_QWORD *)(a1 + 96) >> 4) & 1);
  if ( !*(_BYTE *)(a2 + 39) )
    ++v8;
  v9 = *(_BYTE *)(a2 + 31) & 7;
  v10 = (v8 + 1) & 0xFFFFFFFE;
  if ( v9 == 1 )
    v10 += 3;
  if ( (v7 & 0x200) != 0 )
    v10 = ((v10 + 3) & 0xFFFFFFFC) + 8;
  if ( v9 == 2 )
    v10 = ((v10 + 1) & 0xFFFFFFFE) + 12;
  if ( *(int *)(a1 + 148) >= 0 )
    v10 = ((v10 + 7) & 0xFFFFFFF8) + 12;
  if ( v9 == 3 )
  {
    if ( (v7 & 0x4000000) != 0 )
      v10 = ((v10 + 1) & 0xFFFFFFFE) + 12;
    if ( (v7 & 0x8000000) != 0 )
      v10 = ((v10 + 1) & 0xFFFFFFFE) + 12;
  }
  v11 = v10 + ((v7 >> 29) & 1);
  if ( (v7 & 0x10000000) != 0 )
    v12 = ((v11 + 1) & 0xFFFFFFFE) + 4;
  else
    v12 = v11;
  if ( *(_BYTE *)(a2 + 39) )
  {
    v13 = _sw_hweight8(*(unsigned __int8 *)(a2 + 39));
    v7 = *(_DWORD *)(a2 + 24);
    v12 += 2 * v13;
  }
  if ( (v7 & 0x100000) != 0 )
  {
    v14 = v7 >> 26;
    v15 = (v7 & 0x8000000) == 0;
    v16 = ((int)(32 * v7) >> 31) & 0xC;
    if ( !v15 )
      v16 += 12;
    return ((v12 + 3) & 0xFFFFFFFC)
         + *(_DWORD *)(a3 + 216)
         + *(unsigned __int16 *)(a3 + 186)
         - (*(_DWORD *)(a3 + 224)
          + (v14 & 4))
         - v16;
  }
  return v12;
}
