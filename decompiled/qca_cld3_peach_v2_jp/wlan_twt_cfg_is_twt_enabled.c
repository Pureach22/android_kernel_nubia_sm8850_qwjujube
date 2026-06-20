__int64 __fastcall wlan_twt_cfg_is_twt_enabled(__int64 a1)
{
  char *comp_private_obj; // x0
  char v2; // w8

  comp_private_obj = (char *)wlan_twt_psoc_get_comp_private_obj(a1);
  if ( comp_private_obj )
    v2 = *comp_private_obj;
  else
    v2 = 0;
  return v2 & 1;
}
