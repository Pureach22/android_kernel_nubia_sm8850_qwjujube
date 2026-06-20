__int64 __fastcall target_if_psoc_tgt_info_mem_free(
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
  if ( a1 )
  {
    ((void (__fastcall *)(__int64))init_deinit_chainmask_table_free)(a1 + 760);
    init_deinit_dbr_ring_cap_free(a1);
    init_deinit_spectral_scaling_params_free(a1);
    init_deinit_scan_radio_cap_free(a1);
    init_deinit_msdu_idx_qtype_map_free(a1);
    init_deinit_aux_dev_cap_free(a1);
    init_deinit_rcc_aoa_cap_ext2_free(a1);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: tgt_psoc_info is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_psoc_tgt_info_mem_free");
    return 4;
  }
}
