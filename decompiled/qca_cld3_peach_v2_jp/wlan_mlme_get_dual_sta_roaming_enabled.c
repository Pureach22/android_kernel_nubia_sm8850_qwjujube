__int64 __fastcall wlan_mlme_get_dual_sta_roaming_enabled(__int64 a1)
{
  _BYTE *psoc_ext_obj_fl; // x0
  __int64 v3; // x0

  psoc_ext_obj_fl = (_BYTE *)mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl && (psoc_ext_obj_fl[1512] & 1) == 0 )
  {
    if ( psoc_ext_obj_fl[1510] == 1 && psoc_ext_obj_fl[1511] == 1 )
    {
      v3 = mlme_get_psoc_ext_obj_fl(a1);
      if ( !v3 )
        return v3 & 1;
      if ( *(_BYTE *)(v3 + 1081) == 1 )
      {
        LOBYTE(v3) = policy_mgr_is_hw_dbs_capable(a1);
        return v3 & 1;
      }
    }
    LOBYTE(v3) = 0;
    return v3 & 1;
  }
  LOBYTE(v3) = 1;
  return v3 & 1;
}
