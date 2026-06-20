__int64 __fastcall sde_crtc_update_cont_splash_settings(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 result; // x0
  void *v5; // x0

  if ( !a1 || !*(_QWORD *)(a1 + 2008) || !*(_QWORD *)a1 || (v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v5 = &unk_25E167;
    return printk(v5, "sde_crtc_update_cont_splash_settings");
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 || !*(_QWORD *)(v3 + 152) )
  {
    v5 = &unk_27D28A;
    return printk(v5, "sde_crtc_update_cont_splash_settings");
  }
  sde_crtc_setup_mixers(a1);
  sde_cp_crtc_refresh_status_properties(a1);
  *(_BYTE *)(a1 + 172) = 1;
  result = sde_power_clk_get_rate((int)v2 + 16, *(char **)(v3 + 1992));
  if ( !result )
    result = *(_QWORD *)(v3 + 2016);
  *(_QWORD *)(a1 + 7456) = result;
  *(_QWORD *)(a1 + 7456) = *(_QWORD *)(v3 + 2016);
  return result;
}
