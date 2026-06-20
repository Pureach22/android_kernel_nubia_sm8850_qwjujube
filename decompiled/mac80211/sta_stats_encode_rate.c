__int64 __fastcall sta_stats_encode_rate(_BYTE *a1)
{
  unsigned int v1; // w9
  unsigned int v2; // w10
  int v3; // w9
  int v4; // w8

  v1 = (unsigned __int8)a1[31];
  v2 = v1 >> 3;
  v3 = v1 & 7;
  v4 = ((a1[30] & 4) << 11) & 0xF0FF | ((v2 & 0xF) << 8);
  if ( v3 <= 1 )
  {
    if ( v3 )
      return v4 | (unsigned __int8)a1[33] | 0x8000u;
    else
      return a1[33] & 0xF | (16 * (a1[36] & 0xF)) | v4 | 0x4000u;
  }
  else
  {
    switch ( v3 )
    {
      case 4:
        return a1[33] & 0xF
             | (unsigned __int8)(16 * (a1[34] & 0xF))
             | ((a1[32] & 0xF) << 17) & 0xFF9FFFFF
             | ((((unsigned __int8)a1[32] >> 4) & 3) << 21)
             | v4
             | 0x18000;
      case 3:
        return a1[33] & 0xF
             | (unsigned __int8)(16 * (a1[34] & 0xF))
             | ((a1[32] & 7) << 17) & 0xFF8FFFFF
             | ((((unsigned __int8)a1[32] >> 3) & 3) << 20) & 0xFFBFFFFF
             | ((((unsigned __int8)a1[32] >> 5) & 1) << 22)
             | v4
             | 0x10000;
      case 2:
        return a1[33] & 0xF | (16 * (a1[34] & 0xF)) | v4 | 0xC000u;
      default:
        __break(0x800u);
        return 0;
    }
  }
}
