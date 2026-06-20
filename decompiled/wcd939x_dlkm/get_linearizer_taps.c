__int64 __fastcall get_linearizer_taps(__int64 result, unsigned int *a2)
{
  _DWORD *v3; // x20
  __int64 v4; // x8
  unsigned int v5; // w8
  unsigned int v6; // w9
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9
  __int64 v10; // x10
  unsigned __int64 v11; // x12
  unsigned int v12; // w8

  if ( !result )
    goto LABEL_8;
  v3 = (_DWORD *)result;
  result = wcd_usbss_get_sbu_switch_orientation(result);
  if ( (_DWORD)result == 2 )
  {
    v4 = 41;
    goto LABEL_6;
  }
  result = wcd_usbss_get_sbu_switch_orientation(result);
  if ( (_DWORD)result != 1 )
  {
LABEL_8:
    v12 = 232;
    goto LABEL_9;
  }
  v4 = 32;
LABEL_6:
  v5 = v3[v4] + ((unsigned int)(v3[24] + v3[17]) >> 1) - ((unsigned int)(v3[26] + v3[19]) >> 1) + v3[60];
  v6 = v5 + (v3[15] & 0x7FFFFFFF);
  v7 = v6 + (v3[14] & 0x7FFFFFFF);
  v8 = ((unsigned __int64)v5 << 12) / v7;
  v9 = ((unsigned __int64)v6 << 12) / v7;
  v10 = (int)v3[29];
  v11 = (unsigned __int64)((((v10 & 0xFFFFFFFFFFFFFuLL) << 10) * (unsigned __int128)0x28F5C28F5C28F5C3uLL) >> 64) >> 2;
  v12 = v3[30]
      + (1000 * (_DWORD)v9 + 10 * (_DWORD)v10 * (_DWORD)v8 + ((unsigned int)(v11 + 4096) >> 1)) / ((int)v11 + 4096);
  if ( v12 >= 0x3FF )
    v12 = 1023;
LABEL_9:
  *a2 = v12;
  return result;
}
