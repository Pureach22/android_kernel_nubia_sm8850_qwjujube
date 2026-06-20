__int64 __fastcall lim_get_bw_for_mcs_set(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int max_bw; // w0
  int v7; // w8

  if ( a1 && a2 )
  {
    max_bw = wlan_mlme_get_max_bw();
    v7 = *(_DWORD *)(a2 + 7036);
    if ( v7 )
    {
      if ( a3 == 2 && v7 == 2 && max_bw > 2 )
      {
        return 3;
      }
      else if ( (v7 | 2) == 3
             && *(_DWORD *)(a2 + 7176) != a3
             && (wlan_is_dnw_in_progress(*(_QWORD *)(a1 + 21632), *(unsigned __int8 *)(a2 + 10)) & 1) != 0 )
      {
        return *(unsigned int *)(a2 + 7176);
      }
    }
    else if ( max_bw > 2 && a3 == 2 )
    {
      return 3;
    }
  }
  return a3;
}
