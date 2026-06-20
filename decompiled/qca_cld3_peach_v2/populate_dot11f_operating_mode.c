__int64 __fastcall populate_dot11f_operating_mode(__int64 a1, _BYTE *a2, __int64 a3)
{
  int v3; // w10
  unsigned int v5; // w10
  unsigned int v6; // w10

  v3 = (unsigned __int8)a2[1];
  *a2 = 1;
  v5 = v3 & 0xFFFFFFFC | *(_BYTE *)(a3 + 7172) & 3;
  a2[1] = v5;
  v6 = v5 & 0xFFFFFF8F | (16 * ((*(unsigned __int8 *)(a3 + 7172) >> 4) & 7));
  a2[1] = v6;
  a2[1] = *(_BYTE *)(a3 + 7172) & 0x80 | v6 & 0x7F;
  return 0;
}
