__int64 __fastcall ucfg_mlme_get_neighbor_scan_max_chan_time(__int64 a1, __int16 *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int16 v4; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v4 = *(_WORD *)(psoc_ext_obj_fl + 1734);
    result = 0;
  }
  else
  {
    result = 4;
    v4 = 40;
  }
  *a2 = v4;
  return result;
}
