__int64 __fastcall populate_dot11f_ts_info(__int64 result, unsigned int *a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w9
  unsigned int v4; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w9

  v2 = *a2 & 0xFFFFFFFE | *(_WORD *)(result + 1) & 1;
  *a2 = v2;
  v3 = v2 & 0xFFFFFFE1 | (2 * ((*(unsigned __int16 *)(result + 1) >> 1) & 0xF));
  *a2 = v3;
  v4 = v3 & 0xFFFFFF9F | (32 * ((*(unsigned __int16 *)(result + 1) >> 5) & 3));
  *a2 = v4;
  v5 = v4 & 0xFFFFFE7F | (((*(unsigned __int16 *)(result + 1) >> 7) & 3) << 7);
  *a2 = v5;
  v6 = v5 & 0xFFFFFDFF | (((*(unsigned __int16 *)(result + 1) >> 9) & 1) << 9);
  *a2 = v6;
  v7 = v6 & 0xFFFFFBFF | (((*(unsigned __int16 *)(result + 1) >> 10) & 1) << 10);
  *a2 = v7;
  v8 = v7 & 0xFFFFC7FF | (((*(unsigned __int16 *)(result + 1) >> 11) & 7) << 11);
  *a2 = v8;
  v9 = v8 & 0xFFFF3FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(result + 1)) >> 6 << 14);
  *a2 = v9;
  *a2 = v9 & 0xFFFEFFFF | ((*(_BYTE *)(result + 3) & 1) << 16);
  return result;
}
