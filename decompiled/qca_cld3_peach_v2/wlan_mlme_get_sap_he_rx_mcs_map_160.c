__int64 __fastcall wlan_mlme_get_sap_he_rx_mcs_map_160(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    return *(unsigned __int16 *)(psoc_ext_obj_fl + 3440);
  else
    return *(unsigned int *)(cfg_psoc_get_values(a1) + 7664);
}
