__int64 __fastcall wlan_twt_cfg_set_requestor_flag(__int64 a1, char a2)
{
  __int64 comp_private_obj; // x0
  __int64 v4; // x8

  comp_private_obj = wlan_twt_psoc_get_comp_private_obj(a1);
  if ( !comp_private_obj )
    return 4;
  v4 = comp_private_obj;
  *(_BYTE *)(v4 + 13) = a2 & 1;
  return 0;
}
