__int64 __fastcall wlan_mlme_set_bt_profile_con(__int64 a1, char a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_BYTE *)(result + 1284) = a2 & 1;
  return result;
}
