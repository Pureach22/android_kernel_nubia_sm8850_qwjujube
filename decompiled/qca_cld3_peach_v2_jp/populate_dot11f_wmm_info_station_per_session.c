__int64 __fastcall populate_dot11f_wmm_info_station_per_session(__int64 result, __int64 a2, _BYTE *a3)
{
  char v3; // w8
  int v4; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  char v7; // w11

  v3 = *(_BYTE *)(*(_QWORD *)(result + 8) + 5454LL);
  a3[1] = 1;
  v4 = a3[2] & 0xFE | *(_BYTE *)(a2 + 7273) & 1;
  a3[2] = v4;
  v5 = v4 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a2 + 7273) >> 1) & 1));
  a3[2] = v5;
  v6 = v5 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a2 + 7273) >> 2) & 1));
  a3[2] = v6;
  v7 = *(_BYTE *)(a2 + 7273);
  *a3 = 1;
  a3[2] = v7 & 8 | (32 * (v3 & 3)) | v6 & 0x97;
  return result;
}
