__int64 __fastcall wlan_mlme_cfg_get_aux_supported_modes(
        __int64 a1,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v12; // x2
  __int64 result; // x0
  __int64 psoc_ext_obj_fl; // x0
  __int64 v17; // x8

  if ( a2 )
  {
    v12 = "%s: current only support aux0";
LABEL_3:
    qdf_trace_msg(0x68u, 2u, v12, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_mlme_cfg_get_aux_supported_modes");
    return 0;
  }
  if ( a3 < 0xB )
  {
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
    if ( !psoc_ext_obj_fl )
    {
      v12 = "%s: MLME obj is NULL";
      goto LABEL_3;
    }
    v17 = psoc_ext_obj_fl + 12LL * a3;
    result = 1;
    *a4 = *(_DWORD *)(v17 + 1132);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: invalid hw mode id %d.",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_mlme_cfg_get_aux_supported_modes",
      a3);
    return 0;
  }
  return result;
}
