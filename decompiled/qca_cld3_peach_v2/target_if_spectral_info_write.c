__int64 __fastcall target_if_spectral_info_write(
        __int64 *a1,
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
  __int64 result; // x0
  __int64 v15; // x19
  unsigned __int64 StatusReg; // x8
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  unsigned __int64 v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x24
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 (*v51)(void); // x8
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x23
  _QWORD *vdev; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x22
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x9
  __int64 v81; // x10
  int v82; // w8
  __int16 v83; // w11
  __int64 v84; // x10
  __int64 *v85; // x9
  _DWORD *v86; // x8
  __int64 v87; // x0
  unsigned __int64 v90; // x8
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned int v99; // w0
  int v100; // w0
  unsigned int v101; // w21
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  _QWORD v110[5]; // [xsp+A0h] [xbp-40h] BYREF
  __int64 v111; // [xsp+C8h] [xbp-18h]
  __int64 v112; // [xsp+D0h] [xbp-10h]
  __int64 v113; // [xsp+D8h] [xbp-8h]

  v113 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 2 )
  {
    if ( !a4 )
      goto LABEL_38;
    v15 = (__int64)&a1[13 * a2 + 122];
    if ( a3 != 2 )
    {
      if ( a3 == 1 )
      {
        if ( a5 == 1 )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(&a1[13 * a2 + 122]);
          }
          else
          {
            raw_spin_lock_bh(&a1[13 * a2 + 122]);
            *(_QWORD *)(v15 + 8) |= 1uLL;
          }
          v19 = target_if_send_vdev_spectral_enable_cmd(a1, a2, 0, 0, 1, *a4);
          qdf_trace_msg(
            0x56u,
            8u,
            "%s: %s: TARGET_IF_SPECTRAL_INFO_ENABLED with val=%u status=%d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "target_if_log_write_spectral_enabled",
            "target_if_spectral_info_write",
            *a4,
            v19);
          if ( (v19 & 0x80000000) == 0 )
          {
            v36 = *(_QWORD *)(v15 + 8);
            *(_BYTE *)(v15 + 16) = *a4;
            goto LABEL_35;
          }
          goto LABEL_40;
        }
      }
      else if ( a5 == 1 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v90 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v90 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v90 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(&a1[13 * a2 + 122]);
        }
        else
        {
          raw_spin_lock_bh(&a1[13 * a2 + 122]);
          *(_QWORD *)(v15 + 8) |= 1uLL;
        }
        v19 = target_if_send_vdev_spectral_enable_cmd(a1, a2, 1, *a4, 0, 0);
        qdf_trace_msg(
          0x56u,
          8u,
          "%s: %s: TARGET_IF_SPECTRAL_INFO_ACTIVE with val=%u status=%d",
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          "target_if_log_write_spectral_active",
          "target_if_spectral_info_write",
          *a4,
          v19);
        if ( (v19 & 0x80000000) == 0 )
        {
          v36 = *(_QWORD *)(v15 + 8);
          *(_BYTE *)(v15 + 17) = *a4;
LABEL_35:
          *(_BYTE *)(v15 + 100) = 1;
          if ( (v36 & 1) == 0 )
          {
LABEL_36:
            raw_spin_unlock(v15);
LABEL_37:
            result = 0;
            goto LABEL_39;
          }
LABEL_45:
          *(_QWORD *)(v15 + 8) = v36 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v15);
          goto LABEL_37;
        }
LABEL_40:
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: target_if_send_vdev_spectral_enable_cmd failed with error=%d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "target_if_spectral_info_write",
          v19);
        qdf_spin_unlock_bh_21(v15);
        result = v19;
        goto LABEL_39;
      }
LABEL_38:
      result = 4294967274LL;
      goto LABEL_39;
    }
    if ( a5 != 80 )
      goto LABEL_38;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v39 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v39 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v39 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&a1[13 * a2 + 122]);
    }
    else
    {
      raw_spin_lock_bh(&a1[13 * a2 + 122]);
      *(_QWORD *)(v15 + 8) |= 1uLL;
    }
    LOWORD(v112) = 0;
    v111 = 0;
    memset(v110, 0, sizeof(v110));
    if ( a1 && (v48 = *a1) != 0 )
    {
      v49 = *(_QWORD *)(v48 + 80);
      if ( v49 )
      {
        v50 = *(_QWORD *)(v49 + 2136);
        if ( v50 )
        {
          v51 = *(__int64 (**)(void))(v50 + 264);
          if ( *((_DWORD *)v51 - 1) != -373219892 )
            __break(0x8228u);
          v52 = v51();
          if ( v52 )
          {
            v61 = v52;
            vdev = target_if_spectral_get_vdev(a1, a2, v53, v54, v55, v56, v57, v58, v59, v60);
            if ( vdev )
            {
              v71 = (__int64)vdev;
              qdf_mem_set(v110, 0x32u, 0);
              LOBYTE(v110[0]) = *(_BYTE *)(v71 + 168);
              wlan_objmgr_vdev_release_ref(
                v71,
                0x1Bu,
                (unsigned int *)LOBYTE(v110[0]),
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79);
              v81 = *((_QWORD *)a4 + 2);
              v80 = *((_QWORD *)a4 + 3);
              v82 = *((_DWORD *)a4 + 3);
              LOWORD(v111) = a2;
              v83 = *((_WORD *)a4 + 3);
              *(_QWORD *)((char *)&v110[1] + 4) = v81;
              v84 = *((_QWORD *)a4 + 4);
              *(_QWORD *)((char *)&v110[2] + 4) = v80;
              LODWORD(v80) = *((_DWORD *)a4 + 10);
              *(_QWORD *)((char *)&v110[3] + 4) = v84;
              HIDWORD(v110[4]) = v80;
              LODWORD(v80) = *((_DWORD *)a4 + 15);
              LODWORD(v84) = *((_DWORD *)a4 + 16);
              WORD1(v110[0]) = v83;
              WORD1(v111) = v80;
              LOWORD(v80) = *((_WORD *)a4 + 34);
              WORD2(v111) = v84;
              LODWORD(v84) = *(_DWORD *)(a4 + 2);
              LOWORD(v112) = v80;
              v85 = *(__int64 **)(v48 + 1240);
              HIDWORD(v110[0]) = v84;
              LODWORD(v110[1]) = v82;
              v86 = *(_DWORD **)(v61 + 8);
              if ( v85 )
                v87 = *v85;
              else
                v87 = 0;
              if ( *(v86 - 1) != -454649350 )
                __break(0x8228u);
              v100 = ((__int64 (__fastcall *)(__int64, _QWORD *))v86)(v87, v110);
            }
            else
            {
              v100 = 17;
            }
LABEL_43:
            v101 = v100;
            qdf_trace_msg(
              0x56u,
              8u,
              "%s: %s: TARGET_IF_SPECTRAL_INFO_PARAMS. Params:\n"
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
              "status = %d\n"
              "ss_completion_timeout = %u",
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              "target_if_log_write_spectral_params",
              "target_if_spectral_info_write",
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
              *((_DWORD *)a4 + 19),
              v100,
              v110[0],
              v110[1],
              v110[2],
              v110[3],
              v110[4],
              v111,
              v112,
              v113);
            if ( (v101 & 0x80000000) != 0 )
            {
              qdf_trace_msg(
                0x56u,
                2u,
                "%s: target_if_send_vdev_spectral_configure_cmd failed with error=%d",
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                v109,
                "target_if_spectral_info_write",
                v101);
              qdf_spin_unlock_bh_21(v15);
              result = v101;
              goto LABEL_39;
            }
            qdf_mem_copy((void *)(v15 + 20), a4, 0x50u);
            v36 = *(_QWORD *)(v15 + 8);
            *(_BYTE *)(v15 + 100) = 1;
            if ( (v36 & 1) == 0 )
              goto LABEL_36;
            goto LABEL_45;
          }
        }
        else
        {
          qdf_trace_msg(
            0x56u,
            2u,
            "%s: rx_ops is null",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "get_target_if_spectral_handle_from_psoc",
            a1);
        }
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: psoc spectral object is null",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "target_if_send_vdev_spectral_configure_cmd");
        v99 = 16;
      }
      else
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: psoc is null",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "target_if_send_vdev_spectral_configure_cmd",
          a1);
        v99 = 4;
      }
    }
    else
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: null params: spectral %pK, spectral_config %pK, pdev: %pK.",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "target_if_send_vdev_spectral_configure_cmd",
        a1,
        a4,
        0);
      v99 = 29;
    }
    v100 = qdf_status_to_os_return(v99);
    goto LABEL_43;
  }
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
    "target_if_spectral_info_write",
    a2);
  result = 4294967274LL;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
