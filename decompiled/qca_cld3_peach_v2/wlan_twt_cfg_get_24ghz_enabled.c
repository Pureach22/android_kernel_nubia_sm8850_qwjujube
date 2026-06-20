__int64 __fastcall wlan_twt_cfg_get_24ghz_enabled(__int64 a1, char *a2)
{
  __int64 comp_private_obj; // x0
  char v4; // w8
  __int64 result; // x0

  comp_private_obj = wlan_twt_psoc_get_comp_private_obj(a1);
  if ( comp_private_obj )
  {
    v4 = *(_BYTE *)(comp_private_obj + 10);
    result = 0;
  }
  else
  {
    result = 4;
    v4 = 1;
  }
  *a2 = v4;
  return result;
}
