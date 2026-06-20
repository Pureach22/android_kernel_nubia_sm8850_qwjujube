__int64 __fastcall wlan_mlme_get_mgmt_hw_tx_retry_count(__int64 a1, unsigned int a2)
{
  __int64 psoc_ext_obj_fl; // x8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  result = 0;
  if ( a2 <= 2 )
  {
    if ( psoc_ext_obj_fl )
      return *(unsigned __int8 *)(psoc_ext_obj_fl + a2 + 1112);
  }
  return result;
}
