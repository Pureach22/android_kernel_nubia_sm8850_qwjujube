__int64 __fastcall wlan_mlme_clear_user_set_link_num(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_BYTE *)(result + 3591) = 0;
  return result;
}
