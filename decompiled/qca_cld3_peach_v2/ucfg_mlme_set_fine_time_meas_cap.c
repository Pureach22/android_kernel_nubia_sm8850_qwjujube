__int64 __fastcall ucfg_mlme_set_fine_time_meas_cap(__int64 a1, int a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 4;
  v4 = psoc_ext_obj_fl;
  *(_DWORD *)(v4 + 5660) = a2;
  return 0;
}
