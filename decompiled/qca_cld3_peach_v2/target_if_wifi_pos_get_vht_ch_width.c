__int64 __fastcall target_if_wifi_pos_get_vht_ch_width(__int64 a1, int *a2)
{
  __int64 v2; // x8
  int v3; // w8
  int v5; // w8

  *a2 = 8;
  if ( !a1 )
    return 4;
  v2 = *(_QWORD *)(a1 + 2800);
  if ( !v2 )
    return 4;
  *a2 = 2;
  v3 = *(_DWORD *)(v2 + 696);
  if ( (v3 & 8) != 0 )
  {
    v5 = 4;
  }
  else
  {
    if ( (v3 & 4) == 0 )
      return 0;
    v5 = 3;
  }
  *a2 = v5;
  return 0;
}
