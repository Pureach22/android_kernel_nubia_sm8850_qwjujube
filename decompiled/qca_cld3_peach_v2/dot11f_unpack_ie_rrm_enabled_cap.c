__int64 __fastcall dot11f_unpack_ie_rrm_enabled_cap(__int64 a1, _BYTE *a2, char a3, __int64 a4)
{
  unsigned int v5; // w9
  unsigned int v6; // w10
  unsigned int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w10

  if ( *(_BYTE *)a4 )
    return 32;
  *(_BYTE *)a4 = 1;
  if ( !a3 )
    goto LABEL_9;
  v5 = *(_DWORD *)(a4 + 1) & 0xFFFFFF00
     | *a2 & 1
     | *a2 & 2
     | *a2 & 4
     | *a2 & 8
     | *a2 & 0x10
     | *a2 & 0x20
     | *a2 & 0x40
     | *a2 & 0x80;
  *(_DWORD *)(a4 + 1) = v5;
  if ( a3 == 1
    || (v6 = (unsigned __int8)a2[1],
        v7 = (v5 & 0xFFFF00FF
            | ((v6 & 1) << 8) & 0x81FF
            | (((v6 >> 1) & 1) << 9) & 0xFFFF83FF
            | (((v6 >> 2) & 1) << 10) & 0xFFFF87FF
            | (((v6 >> 3) & 1) << 11) & 0xFFFF8FFF
            | (((v6 >> 4) & 7) << 12))
           + ((v6 << 8) & 0x8000),
        *(_DWORD *)(a4 + 1) = v7,
        a3 == 2)
    || (v8 = v7 & 0xFF00FFFF
           | ((a2[2] & 1) << 16) & 0xFF01FFFF
           | ((((unsigned __int8)a2[2] >> 1) & 1) << 17) & 0xFF03FFFF
           | ((((unsigned __int8)a2[2] >> 2) & 7) << 18) & 0xFF1FFFFF
           | (a2[2] >> 5 << 21),
        *(_DWORD *)(a4 + 1) = v8,
        a3 == 3)
    || (v9 = (unsigned __int8)a2[3],
        *(_DWORD *)(a4 + 1) = v8 & 0xFFFFFF
                            | ((v9 & 7) << 24) & 0x87FFFFFF
                            | (((v9 >> 3) & 1) << 27) & 0x8FFFFFFF
                            | (((v9 >> 4) & 1) << 28) & 0x9FFFFFFF
                            | (((v9 >> 5) & 1) << 29) & 0xBFFFFFFF
                            | (((v9 >> 6) & 1) << 30)
                            | (v9 >> 7 << 31),
        a3 == 4) )
  {
LABEL_9:
    *(_BYTE *)a4 = 0;
    return 4;
  }
  else
  {
    *(_BYTE *)(a4 + 5) = a2[4];
    return 0;
  }
}
