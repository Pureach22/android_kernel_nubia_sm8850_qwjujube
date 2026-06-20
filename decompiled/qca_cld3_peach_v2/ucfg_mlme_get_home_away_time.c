__int64 __fastcall ucfg_mlme_get_home_away_time(__int64 a1, _WORD *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int16 v4; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v4 = *(_WORD *)(psoc_ext_obj_fl + 1982);
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
