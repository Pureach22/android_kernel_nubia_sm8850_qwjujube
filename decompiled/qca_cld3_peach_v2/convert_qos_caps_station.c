void __fastcall convert_qos_caps_station(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // w9
  int v4; // w8
  unsigned int v5; // w8
  unsigned int v6; // w8
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w8

  v3 = *(_BYTE *)(a2 + 2);
  *(_WORD *)a2 = 302;
  v4 = *(_BYTE *)(a3 + 1) & 0x80 | v3 & 0x7F;
  *(_BYTE *)(a2 + 2) = v4;
  v5 = v4 & 0xFFFFFF9F | (32 * ((*(unsigned __int8 *)(a3 + 1) >> 5) & 3));
  *(_BYTE *)(a2 + 2) = v5;
  v6 = v5 & 0xFFFFFFEF | (16 * ((*(unsigned __int8 *)(a3 + 1) >> 4) & 1));
  *(_BYTE *)(a2 + 2) = v6;
  v7 = v6 & 0xFFFFFFF7 | (8 * ((*(unsigned __int8 *)(a3 + 1) >> 3) & 1));
  *(_BYTE *)(a2 + 2) = v7;
  v8 = v7 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a3 + 1) >> 2) & 1));
  *(_BYTE *)(a2 + 2) = v8;
  v9 = v8 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a3 + 1) >> 1) & 1));
  *(_BYTE *)(a2 + 2) = v9;
  *(_BYTE *)(a2 + 2) = v9 & 0xFE | *(_BYTE *)(a3 + 1) & 1;
}
