__int64 __fastcall utils_dfs_convert_freq_to_index(__int64 result, _BYTE *a2)
{
  int v2; // w8
  int v3; // w9
  int v4; // w8
  int v5; // w8

  v2 = (unsigned __int16)(((int)result - 5000) / 5u);
  v3 = v2 - 52;
  v4 = v2 - 49;
  if ( (unsigned __int16)(((int)result - 5000) / 5u) >= 0x34u )
    v4 = v3;
  v5 = v4 >> 2;
  if ( (unsigned __int8)((unsigned __int8)v5 >> 1) >= 0xFu )
    LOBYTE(v5) = -1;
  *a2 = v5;
  return result;
}
