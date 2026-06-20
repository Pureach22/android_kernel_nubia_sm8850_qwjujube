__int64 __fastcall wlan_mlme_get_tx_retry_multiplier(__int64 a1, _DWORD *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  int v4; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v4 = *(_DWORD *)(psoc_ext_obj_fl + 1108);
    result = 0;
  }
  else
  {
    v4 = 0;
    result = 16;
  }
  *a2 = v4;
  return result;
}
