__int64 __fastcall sde_cp_crtc_pre_ipc(char *a1)
{
  _QWORD *v2; // x2
  char is_client_registered; // w20
  int v4; // w6
  int v5; // w7
  _QWORD *v6; // x1
  __int64 v7; // x21
  __int64 result; // x0
  char *v9; // x1
  char v10; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    v2 = nullptr;
    return _drm_err("invalid drm_crtc %pK dev %pK\n", a1, v2);
  }
  v2 = *(_QWORD **)a1;
  if ( !*(_QWORD *)a1 || !v2[7] )
    return _drm_err("invalid drm_crtc %pK dev %pK\n", a1, v2);
  sde_cp_ad_set_prop((__int64)a1, 9);
  is_client_registered = 1;
  if ( (aiqe_is_client_registered(1, a1 + 7952) & 1) == 0 )
    is_client_registered = aiqe_is_client_registered(4, a1 + 7952);
  v6 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 8LL);
  if ( !v6 )
    return _drm_err("invalid sde kms %pK catalog %pK sde_crtc %pK\n", v6, nullptr, a1);
  v7 = v6[19];
  if ( !v7 )
    return _drm_err("invalid sde kms %pK catalog %pK sde_crtc %pK\n", v6, nullptr, a1);
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_cp_crtc_pre_ipc",
             3928,
             -1,
             is_client_registered & 1,
             -1059143953,
             v4,
             v5,
             v10);
  if ( (is_client_registered & 1) != 0 )
  {
    if ( (*(_QWORD *)(v7 + 22008) & 0x4000000000000LL) != 0 )
      v9 = "ssip_clk";
    else
      v9 = "lut_clk";
    return sde_power_set_clk_retention((unsigned int)*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 16, v9);
  }
  return result;
}
