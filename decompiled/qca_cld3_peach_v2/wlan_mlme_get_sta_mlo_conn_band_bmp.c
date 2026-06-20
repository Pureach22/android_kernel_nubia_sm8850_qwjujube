__int64 __fastcall wlan_mlme_get_sta_mlo_conn_band_bmp(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return *(unsigned __int8 *)(result + 3593);
  return result;
}
