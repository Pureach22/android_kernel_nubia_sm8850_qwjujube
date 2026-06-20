__int64 __fastcall target_if_spectral_info_read(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned __int8 *a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v15; // x22
  __int64 v17; // x19
  unsigned __int64 StatusReg; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x5
  const char *v38; // x2
  const char *v39; // x3
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  __int64 v49; // x25
  __int16 v50; // w9
  __int64 v51; // x25
  _QWORD *vdev; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x22
  __int64 cmpt_obj; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int *v71; // x8
  unsigned int default_sscan_bw; // w0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x8

  if ( a2 >= 2 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "target_if_spectral_info_read",
      a2);
    return 4294967274LL;
  }
  if ( !a4 )
    return 4294967274LL;
  if ( a3 == 2 )
  {
    if ( a5 == 80 )
      goto LABEL_6;
    return 4294967274LL;
  }
  if ( a5 != 1 )
    return 4294967274LL;
LABEL_6:
  v15 = a1 + 976;
  v17 = a1 + 976 + 104LL * a2;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 976 + 104LL * a2);
    if ( *(_BYTE *)(v17 + 100) )
    {
LABEL_10:
      if ( a3 == 2 )
      {
        qdf_mem_copy(a4, (const void *)(v17 + 20), 0x50u);
        qdf_trace_msg(
          0x56u,
          8u,
          "%s: %s: TARGET_IF_SPECTRAL_INFO_PARAMS. Returning following params:\n"
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
          "ss_frequency1=%u\n"
          "ss_frequency2=%u\n"
          "ss_completion_timeout=%u\n",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "target_if_log_read_spectral_params",
          "target_if_spectral_info_read",
          *((unsigned __int16 *)a4 + 3),
          *((unsigned __int16 *)a4 + 1),
          *((unsigned __int16 *)a4 + 2),
          *((unsigned __int16 *)a4 + 6),
          *((unsigned __int16 *)a4 + 7),
          *((unsigned __int16 *)a4 + 8),
          *((unsigned __int16 *)a4 + 9),
          (char)a4[20],
          *((unsigned __int16 *)a4 + 11),
          *((unsigned __int16 *)a4 + 12),
          *((unsigned __int16 *)a4 + 13),
          *((unsigned __int16 *)a4 + 14),
          *((unsigned __int16 *)a4 + 15),
          (char)a4[32],
          *((unsigned __int16 *)a4 + 17),
          *((unsigned __int16 *)a4 + 18),
          *((unsigned __int16 *)a4 + 19),
          *((unsigned __int16 *)a4 + 20),
          *((unsigned __int16 *)a4 + 21),
          *((_DWORD *)a4 + 15),
          *((_DWORD *)a4 + 16),
          *((_DWORD *)a4 + 19));
        v48 = *(_QWORD *)(v17 + 8);
        if ( (v48 & 1) == 0 )
        {
LABEL_19:
          raw_spin_unlock(v17);
          return 0;
        }
LABEL_16:
        *(_QWORD *)(v17 + 8) = v48 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v17);
        return 0;
      }
      if ( a3 == 1 )
      {
        qdf_mem_copy(a4, (const void *)(v17 + 16), 1u);
        v37 = *a4;
        v38 = "%s: %s: TARGET_IF_SPECTRAL_INFO_ENABLED. Returning val=%u";
        v39 = "target_if_log_read_spectral_enabled";
      }
      else
      {
        qdf_mem_copy(a4, (const void *)(v17 + 17), 1u);
        v37 = *a4;
        v38 = "%s: %s: TARGET_IF_SPECTRAL_INFO_ACTIVE. Returning val=%u";
        v39 = "target_if_log_read_spectral_active";
      }
LABEL_18:
      qdf_trace_msg(0x56u, 8u, v38, v29, v30, v31, v32, v33, v34, v35, v36, v39, "target_if_spectral_info_read", v37);
      v48 = *(_QWORD *)(v17 + 8);
      if ( (v48 & 1) == 0 )
        goto LABEL_19;
      goto LABEL_16;
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 976 + 104LL * a2);
    *(_QWORD *)(v17 + 8) |= 1uLL;
    if ( *(_BYTE *)(v17 + 100) )
      goto LABEL_10;
  }
  v49 = v15 + 104LL * a2;
  if ( *(_DWORD *)(a1 + 1252) == 2 )
    v50 = 224;
  else
    v50 = 35;
  *(_WORD *)(v49 + 16) = 0;
  v51 = v49 + 16;
  *(_WORD *)(v51 + 6) = v50;
  *(_DWORD *)(v51 + 8) = 0;
  *(_QWORD *)(v51 + 16) = 0x100070001LL;
  *(_QWORD *)(v51 + 24) = 0x8000C0050FFA0LL;
  *(_QWORD *)(v51 + 32) = 0xF000000000LL;
  *(_DWORD *)(v51 + 40) = 65538;
  *(_WORD *)(v51 + 44) = 1;
  vdev = target_if_spectral_get_vdev((__int64 *)a1, a2, v21, v22, v23, v24, v25, v26, v27, v28);
  v61 = (__int64)vdev;
  if ( vdev )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj((__int64)vdev, v53, v54, v55, v56, v57, v58, v59, v60);
    if ( cmpt_obj )
      v71 = (unsigned int *)*(unsigned __int8 *)(cmpt_obj + 401);
    else
      v71 = nullptr;
    *(_WORD *)(v51 + 46) = (_WORD)v71;
    wlan_objmgr_vdev_release_ref(v61, 0x1Bu, v71, v63, v64, v65, v66, v67, v68, v69, v70);
    *(_WORD *)(v51 + 12) = 1;
    *(_WORD *)(v51 + 4) = 1;
    *(_QWORD *)(v51 + 64) = 0;
    default_sscan_bw = get_default_sscan_bw(a1, a2, 0);
    if ( default_sscan_bw < 8 )
    {
      *(_WORD *)(v51 + 72) = default_sscan_bw;
      *(_DWORD *)(v51 + 80) = 0;
      *(_BYTE *)(v51 + 84) = 1;
      if ( a3 == 2 )
      {
        qdf_mem_copy(a4, (const void *)(v17 + 20), 0x50u);
        target_if_log_read_spectral_params_catch_validate(a4);
        v48 = *(_QWORD *)(v17 + 8);
        if ( (v48 & 1) == 0 )
          goto LABEL_19;
        goto LABEL_16;
      }
      if ( a3 == 1 )
      {
        qdf_mem_copy(a4, (const void *)(v17 + 16), 1u);
        v37 = *a4;
        v38 = "%s: %s: TARGET_IF_SPECTRAL_INFO_ENABLED on initial cache validation\nReturning val=%u\n";
        v39 = "target_if_log_read_spectral_enabled_catch_validate";
      }
      else
      {
        qdf_mem_copy(a4, (const void *)(v17 + 17), 1u);
        v37 = *a4;
        v38 = "%s: %s: TARGET_IF_SPECTRAL_INFO_ACTIVE on initial cache validation\nReturning val=%u";
        v39 = "target_if_log_read_spectral_active_catch_validate";
      }
      goto LABEL_18;
    }
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid sscan BW %u",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "target_if_spectral_info_init_defaults",
      default_sscan_bw);
  }
  v81 = *(_QWORD *)(v17 + 8);
  if ( (v81 & 1) != 0 )
  {
    *(_QWORD *)(v17 + 8) = v81 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v17);
  }
  else
  {
    raw_spin_unlock(v17);
  }
  if ( v61 )
    return 4294967274LL;
  else
    return 4294967294LL;
}
