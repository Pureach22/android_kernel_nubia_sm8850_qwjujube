__int64 __fastcall wlan_dp_lb_sort_cpu_load(_DWORD *a1, _DWORD *a2)
{
  if ( *a1 > *a2 )
    return 0xFFFFFFFFLL;
  else
    return *a1 < *a2;
}
