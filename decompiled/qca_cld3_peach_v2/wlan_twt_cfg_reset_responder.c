__int64 __fastcall wlan_twt_cfg_reset_responder(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v2; // x8

  comp_private_obj = wlan_twt_psoc_get_comp_private_obj(a1);
  if ( !comp_private_obj )
    return 4;
  v2 = comp_private_obj;
  *(_BYTE *)(v2 + 1) = *(_BYTE *)(v2 + 2);
  return 0;
}
