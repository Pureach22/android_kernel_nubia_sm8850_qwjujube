__int64 __fastcall ucfg_cm_get_roam_intra_band(__int64 a1, _WORD *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 4;
  v4 = psoc_ext_obj_fl;
  *a2 = *(unsigned __int8 *)(v4 + 1977);
  return 0;
}
