__int64 __fastcall populate_dot11f_wmm_info_ap(__int64 result, _BYTE *a2, __int64 a3)
{
  char v3; // w10
  char v4; // w10
  char *v5; // x9
  char v6; // w9

  v3 = a2[2];
  a2[1] = 1;
  v4 = v3 & 0xF0 | *(_BYTE *)(a3 + 7156) & 0xF;
  a2[2] = v4;
  if ( *(_DWORD *)(a3 + 88) == 1 )
    v5 = (char *)(a3 + 1936);
  else
    v5 = (char *)(result + 8896);
  v6 = *v5;
  *a2 = 1;
  a2[2] = v4 & 0x7F | (v6 << 7);
  return result;
}
