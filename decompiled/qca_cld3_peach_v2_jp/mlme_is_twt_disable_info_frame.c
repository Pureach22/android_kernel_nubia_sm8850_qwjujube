__int64 __fastcall mlme_is_twt_disable_info_frame(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  char v2; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    v2 = *(_BYTE *)(psoc_ext_obj_fl + 3547);
  else
    v2 = 0;
  return v2 & 1;
}
