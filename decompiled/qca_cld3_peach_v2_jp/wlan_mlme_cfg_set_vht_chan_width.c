__int64 __fastcall wlan_mlme_cfg_set_vht_chan_width(__int64 a1, unsigned __int8 a2)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  *(_BYTE *)(psoc_ext_obj_fl + 2616) = a2;
  if ( (unsigned int)a2 - 1 <= 1 )
    *(_WORD *)(psoc_ext_obj_fl + 2681) = 256;
  return 0;
}
