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

  qword_92E5B8 = (__int64)target_if_spectral_set_rxfilter;
  qword_92E5C0 = (__int64)target_if_spectral_get_rxfilter;
  spectral_ops = (__int64)target_if_spectral_get_tsf64;
  qword_92E5B0 = (__int64)target_if_spectral_get_capability;
  qword_92E5D8 = (__int64)target_if_sops_start_spectral_scan;
  qword_92E5E0 = (__int64)target_if_sops_stop_spectral_scan;
  qword_92E5C8 = (__int64)target_if_sops_is_spectral_active;
  qword_92E5D0 = (__int64)target_if_sops_is_spectral_enabled;
  qword_92E5E8 = (__int64)target_if_spectral_get_extension_channel;
  qword_92E5F0 = (__int64)target_if_spectral_get_ctl_noisefloor;
  qword_92E5F8 = (__int64)target_if_spectral_get_ext_noisefloor;
  qword_92E600 = (__int64)target_if_spectral_sops_configure_params;
  v11 = *(_DWORD *)(result + 1252);
  qword_92E608 = (__int64)target_if_spectral_sops_get_params;
  qword_92E610 = (__int64)target_if_spectral_get_ent_mask;
  qword_92E618 = (__int64)target_if_spectral_get_macaddr;
  qword_92E620 = (__int64)target_if_spectral_get_current_channel;
  qword_92E628 = (__int64)target_if_spectral_reset_hw;
  qword_92E630 = (__int64)target_if_spectral_get_chain_noise_floor;
  if ( v11 == 2 )
  {
    qword_92E650 = 0;
    qword_92E640 = (__int64)target_if_spectral_process_report_gen3;
    qword_92E648 = 0;
  }
  else if ( v11 == 1 )
  {
    qword_92E638 = (__int64)&target_if_process_phyerr_gen2;
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
