__int64 __fastcall ucfg_mlme_stats_get_cfg_values(__int64 a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *psoc_ext_obj_fl; // x0
  int v10; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = (_DWORD *)mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    *a2 = psoc_ext_obj_fl[849];
    *a3 = psoc_ext_obj_fl[850];
    *a4 = psoc_ext_obj_fl[851];
    v10 = psoc_ext_obj_fl[852];
    result = 0;
  }
  else
  {
    v10 = 0;
    *a2 = -55;
    result = 4;
    *a3 = -65;
    *a4 = -80;
  }
  *a5 = v10;
  return result;
}
