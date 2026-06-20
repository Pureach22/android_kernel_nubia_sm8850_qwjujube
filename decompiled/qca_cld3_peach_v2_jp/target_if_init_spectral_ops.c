__int64 __fastcall target_if_init_spectral_ops(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  int v11; // w8

  qword_865340 = (__int64)target_if_spectral_set_rxfilter;
  qword_865348 = (__int64)target_if_spectral_get_rxfilter;
  spectral_ops = (__int64)target_if_spectral_get_tsf64;
  qword_865338 = (__int64)target_if_spectral_get_capability;
  qword_865360 = (__int64)target_if_sops_start_spectral_scan;
  qword_865368 = (__int64)target_if_sops_stop_spectral_scan;
  qword_865350 = (__int64)target_if_sops_is_spectral_active;
  qword_865358 = (__int64)target_if_sops_is_spectral_enabled;
  qword_865370 = (__int64)target_if_spectral_get_extension_channel;
  qword_865378 = (__int64)target_if_spectral_get_ctl_noisefloor;
  qword_865380 = (__int64)target_if_spectral_get_ext_noisefloor;
  qword_865388 = (__int64)target_if_spectral_sops_configure_params;
  v11 = *(_DWORD *)(result + 1252);
  qword_865390 = (__int64)target_if_spectral_sops_get_params;
  qword_865398 = (__int64)target_if_spectral_get_ent_mask;
  qword_8653A0 = (__int64)target_if_spectral_get_macaddr;
  qword_8653A8 = (__int64)target_if_spectral_get_current_channel;
  qword_8653B0 = (__int64)target_if_spectral_reset_hw;
  qword_8653B8 = (__int64)target_if_spectral_get_chain_noise_floor;
  if ( v11 == 2 )
  {
    qword_8653D8 = 0;
    qword_8653C8 = (__int64)target_if_spectral_process_report_gen3;
    qword_8653D0 = 0;
  }
  else if ( v11 == 1 )
  {
    qword_8653C0 = (__int64)&target_if_process_phyerr_gen2;
  }
  else
  {
    return qdf_trace_msg(
             0x56u,
             2u,
             "%s: Invalid Spectral generation",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_init_spectral_ops",
             v9,
             v10);
  }
  return result;
}
