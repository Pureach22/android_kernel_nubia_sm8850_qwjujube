__int64 __fastcall wlan_twt_cfg_get_bcast_responder(__int64 a1, _BYTE *a2)
{
  __int64 comp_private_obj; // x0
  char v4; // w8
  __int64 result; // x0

  comp_private_obj = wlan_twt_psoc_get_comp_private_obj(a1);
  if ( comp_private_obj )
  {
    v4 = *(_BYTE *)(comp_private_obj + 9);
    result = 0;
  }
  else
  {
    v4 = 0;
    result = 4;
  }
  *a2 = v4;
  return result;
}
