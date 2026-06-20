__int64 __fastcall ucfg_mlme_set_obss_color_collision_offload_enabled(__int64 a1, char a2)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 4;
  *(_BYTE *)(psoc_ext_obj_fl + 2810) = a2 != 0;
  return 0;
}
