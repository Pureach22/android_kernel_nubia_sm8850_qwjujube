__int64 __fastcall wlan_dp_fb_sort_targeted_wtg_dist(_DWORD *a1, _DWORD *a2)
{
  if ( *a1 > *a2 )
    return 0xFFFFFFFFLL;
  else
    return *a1 < *a2;
}
