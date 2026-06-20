_BYTE *__fastcall wifi_pos_init_11az_context(_BYTE *result)
{
  __int64 v1; // x8
  __int64 i; // x9
  _BYTE *v3; // x14
  _BYTE *v4; // x14

  v1 = 0;
  for ( i = 0; i != 96; i += 6 )
  {
    v3 = &result[v1];
    v1 += 380;
    *((_WORD *)v3 + 2) = -1;
    *(_DWORD *)v3 = -1;
    *((_DWORD *)v3 + 3) = -1;
    *((_WORD *)v3 + 8) = -1;
    v3[18] = 0;
    *((_WORD *)v3 + 184) = 0;
    *((_DWORD *)v3 + 1521) = -1;
    *((_WORD *)v3 + 3044) = -1;
    v4 = &result[i + 12165];
    *((_WORD *)v4 + 2) = -1;
    *(_DWORD *)v4 = -1;
  }
  result[6080] = 0;
  result[12164] = 0;
  result[12261] = 0;
  return result;
}
