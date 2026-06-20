__int64 __fastcall wlan_dp_fb_sort_flow_map_tbl(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w9
  bool v4; // cc
  _BOOL4 v5; // w8

  v2 = *(unsigned __int8 *)(a1 + 16);
  v3 = *(unsigned __int8 *)(a2 + 16);
  v4 = v2 > v3;
  v5 = v2 < v3;
  if ( v4 )
    return 0xFFFFFFFFLL;
  else
    return v5;
}
