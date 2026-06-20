__int64 __fastcall target_if_log_read_spectral_params_catch_validate(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v10; // [xsp+0h] [xbp-90h]
  int v11; // [xsp+8h] [xbp-88h]
  int v12; // [xsp+10h] [xbp-80h]
  int v13; // [xsp+18h] [xbp-78h]
  int v14; // [xsp+20h] [xbp-70h]
  int v15; // [xsp+28h] [xbp-68h]
  int v16; // [xsp+30h] [xbp-60h]
  int v17; // [xsp+38h] [xbp-58h]
  int v18; // [xsp+40h] [xbp-50h]
  int v19; // [xsp+48h] [xbp-48h]
  int v20; // [xsp+50h] [xbp-40h]
  int v21; // [xsp+58h] [xbp-38h]
  int v22; // [xsp+60h] [xbp-30h]
  int v23; // [xsp+68h] [xbp-28h]
  int v24; // [xsp+70h] [xbp-20h]
  int v25; // [xsp+78h] [xbp-18h]
  int v26; // [xsp+80h] [xbp-10h]

  v21 = *(unsigned __int16 *)(a1 + 34);
  v23 = *(unsigned __int16 *)(a1 + 38);
  v26 = *(_DWORD *)(a1 + 76);
  v22 = *(unsigned __int16 *)(a1 + 36);
  v20 = *(char *)(a1 + 32);
  v25 = *(unsigned __int16 *)(a1 + 42);
  v24 = *(unsigned __int16 *)(a1 + 40);
  v19 = *(unsigned __int16 *)(a1 + 30);
  v18 = *(unsigned __int16 *)(a1 + 28);
  v17 = *(unsigned __int16 *)(a1 + 26);
  v16 = *(unsigned __int16 *)(a1 + 24);
  v15 = *(unsigned __int16 *)(a1 + 22);
  v14 = *(char *)(a1 + 20);
  v13 = *(unsigned __int16 *)(a1 + 18);
  v12 = *(unsigned __int16 *)(a1 + 16);
  v11 = *(unsigned __int16 *)(a1 + 14);
  v10 = *(unsigned __int16 *)(a1 + 12);
  return qdf_trace_msg(
           0x56u,
           8u,
           "%s: %s: TARGET_IF_SPECTRAL_INFO_PARAMS on initial cache validation\n"
           "Returning following params:\n"
           "ss_count = %u\n"
           "ss_period = %u\n"
           "ss_recapture = %u\n"
           "ss_spectral_pri = %u\n"
           "ss_fft_size = %u\n"
           "ss_gc_ena = %u\n"
           "ss_restart_ena = %u\n"
           "ss_noise_floor_ref = %d\n"
           "ss_init_delay = %u\n"
           "ss_nb_tone_thr = %u\n"
           "ss_str_bin_thr = %u\n"
           "ss_wb_rpt_mode = %u\n"
           "ss_rssi_rpt_mode = %u\n"
           "ss_rssi_thr = %d\n"
           "ss_pwr_format = %u\n"
           "ss_rpt_mode = %u\n"
           "ss_bin_scale = %u\n"
           "ss_dbm_adj = %u\n"
           "ss_chn_mask = %u\n"
           "ss_completion_timeout = %u",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "target_if_log_read_spectral_params_catch_validate",
           "target_if_spectral_info_read",
           *(unsigned __int16 *)(a1 + 6),
           *(unsigned __int16 *)(a1 + 2),
           *(unsigned __int16 *)(a1 + 4),
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           v26);
}
