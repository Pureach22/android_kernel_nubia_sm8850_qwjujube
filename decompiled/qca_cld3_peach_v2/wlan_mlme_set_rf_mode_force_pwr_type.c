__int64 __fastcall wlan_mlme_set_rf_mode_force_pwr_type(__int64 a1, unsigned __int8 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  unsigned int v4; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    if ( a2 > 2u || (*(_BYTE *)(psoc_ext_obj_fl + 1089) & 1) == 0 )
      a2 = -1;
    v4 = 0;
    *(_BYTE *)(psoc_ext_obj_fl + 1090) = a2;
  }
  else
  {
    return 16;
  }
  return v4;
}
