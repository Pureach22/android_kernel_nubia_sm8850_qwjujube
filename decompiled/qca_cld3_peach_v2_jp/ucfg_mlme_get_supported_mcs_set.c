__int64 __fastcall ucfg_mlme_get_supported_mcs_set(__int64 a1, void *a2, size_t *a3)
{
  __int64 psoc_ext_obj_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    return wlan_mlme_get_cfg_str(a2, psoc_ext_obj_fl + 2856, a3, v6, v7, v8, v9, v10, v11, v12, v13);
  else
    return 4;
}
