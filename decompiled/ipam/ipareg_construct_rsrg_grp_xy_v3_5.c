__int64 __fastcall ipareg_construct_rsrg_grp_xy_v3_5(__int64 result, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v3 = *a3 | *a2 & 0x3F;
  *a3 = v3;
  v4 = ((a2[1] & 0x3F) << 8) | v3;
  *a3 = v4;
  if ( (_DWORD)result != 81 )
  {
    v5 = ((a2[2] & 0x3F) << 16) | v4;
    *a3 = v5;
    *a3 = ((a2[3] & 0x3F) << 24) | v5;
  }
  return result;
}
