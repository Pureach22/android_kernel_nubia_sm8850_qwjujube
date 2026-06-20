__int64 __fastcall wlan_cp_stats_peer_rx_pnerr(__int64 result)
{
  __int64 v1; // x19
  __int64 (__fastcall *v2)(__int64, __int64); // x8

  if ( result )
  {
    v1 = result;
    result = wlan_objmgr_peer_get_comp_private_obj(result, 0x1Bu);
    if ( result )
    {
      v2 = *(__int64 (__fastcall **)(__int64, __int64))(result + 40);
      if ( v2 )
      {
        if ( *((_DWORD *)v2 - 1) != 1016170858 )
          __break(0x8228u);
        return v2(v1, 1);
      }
    }
  }
  return result;
}
