__int64 __fastcall cam_ife_csid_ver2_rx_err_process_bottom_half(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x26
  __int64 *v5; // x8
  int v6; // w22
  char v7; // w9
  __int64 v8; // x10
  __int64 v9; // x21
  unsigned int *v10; // x27
  _BYTE *v11; // x25
  unsigned __int64 v12; // x20
  __int64 v13; // x24
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 v17; // x8
  unsigned int v18; // w24
  int v19; // w28
  __int64 v20; // x6
  __int64 v21; // x7
  __int64 v22; // x6
  __int64 v23; // x7
  __int64 v24; // x6
  __int64 v25; // x7
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v28; // x7
  __int64 v29; // x8
  unsigned int v30; // w24
  int v31; // w28
  __int64 v32; // x6
  __int64 v33; // x7
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 v36; // x8
  unsigned int v37; // w24
  int v38; // w28
  __int64 v39; // x6
  __int64 v40; // x7
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x8
  __int64 v44; // x6
  __int64 v45; // x7
  __int64 v46; // x6
  __int64 v47; // x7
  unsigned __int16 v48; // w24
  __int64 v49; // x6
  __int64 v50; // x7
  __int64 v51; // x6
  __int64 v52; // x7
  __int64 v53; // x6
  __int64 v54; // x7
  __int64 v55; // x6
  __int64 v56; // x7
  __int64 v57; // x6
  __int64 v58; // x7
  unsigned int v59; // w0
  __int64 v60; // x7
  int v61; // w11
  __int64 v62; // x6
  const char *v63; // x7
  unsigned int v64; // w24
  __int64 v65; // x6
  __int64 v66; // x7
  __int64 v67; // x6
  __int64 v68; // x7
  __int64 v69; // x7
  unsigned int v70; // w0
  __int64 v71; // x9
  unsigned int *v72; // x24
  unsigned int v73; // w8
  unsigned __int64 v74; // x28
  __int64 v75; // x8
  unsigned int v76; // w20
  __int64 v77; // x6
  __int64 v78; // x7
  __int64 v79; // x6
  __int64 v80; // x7
  __int64 v81; // x7
  unsigned int v82; // w0
  unsigned __int64 v83; // x8
  unsigned int v84; // w0
  __int64 v85; // x6
  __int64 v86; // x7
  unsigned int v87; // w23
  __int64 v88; // x6
  __int64 v89; // x7
  __int64 v90; // x0
  char v91; // w10
  int v92; // w6
  int v93; // w21
  char v94; // [xsp+0h] [xbp-60h]
  char v95; // [xsp+0h] [xbp-60h]
  char v96; // [xsp+0h] [xbp-60h]
  char v97; // [xsp+0h] [xbp-60h]
  char v98; // [xsp+0h] [xbp-60h]
  char v99; // [xsp+0h] [xbp-60h]
  char v100; // [xsp+0h] [xbp-60h]
  char v101; // [xsp+0h] [xbp-60h]
  char v102; // [xsp+0h] [xbp-60h]
  char v103; // [xsp+0h] [xbp-60h]
  char v104; // [xsp+0h] [xbp-60h]
  char v105; // [xsp+0h] [xbp-60h]
  char v106; // [xsp+0h] [xbp-60h]
  char v107; // [xsp+0h] [xbp-60h]
  char v108; // [xsp+0h] [xbp-60h]
  char v109; // [xsp+0h] [xbp-60h]
  char v110; // [xsp+0h] [xbp-60h]
  char v111; // [xsp+0h] [xbp-60h]
  char v112; // [xsp+0h] [xbp-60h]
  char v113; // [xsp+0h] [xbp-60h]
  char v114; // [xsp+0h] [xbp-60h]
  char v115; // [xsp+0h] [xbp-60h]
  char v116; // [xsp+0h] [xbp-60h]
  char v117; // [xsp+0h] [xbp-60h]
  char v118; // [xsp+0h] [xbp-60h]
  char v119; // [xsp+0h] [xbp-60h]
  int v120; // [xsp+10h] [xbp-50h]
  __int64 v121; // [xsp+20h] [xbp-40h]
  int v122; // [xsp+2Ch] [xbp-34h]
  __int64 v123; // [xsp+30h] [xbp-30h]
  unsigned __int64 v124; // [xsp+38h] [xbp-28h] BYREF
  int v125; // [xsp+44h] [xbp-1Ch] BYREF
  __int64 v126; // [xsp+48h] [xbp-18h] BYREF
  __int16 v127; // [xsp+50h] [xbp-10h]
  __int64 v128; // [xsp+58h] [xbp-8h]

  v3 = result;
  v4 = result + 28672;
  v128 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(__int64 **)(result + 31136);
  v124 = 0;
  v6 = *(_DWORD *)(a2 + 16);
  v125 = 0;
  v7 = *(_BYTE *)(result + 2148);
  v8 = *(_QWORD *)(result + 31128);
  v9 = *v5;
  v10 = *(unsigned int **)(*v5 + 128);
  v11 = *(_BYTE **)(*v5 + 624);
  LODWORD(v5) = v10[a3 + 77];
  *(_BYTE *)(result + 31160) = 0;
  v12 = (unsigned int)v5 & v6;
  if ( (v7 & 1) == 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_csid_ver2_rx_err_process_bottom_half",
                 2130,
                 "CSID[%u] bottom-half after stop [0x%x]",
                 *(_DWORD *)(*(_QWORD *)(result + 31120) + 4LL),
                 v12);
    goto LABEL_123;
  }
  LODWORD(v13) = a3;
  v121 = v8;
  raw_spin_lock(result + 30968);
  if ( *(_DWORD *)(*(_QWORD *)(v3 + 31128) + 92LL) != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_rx_err_process_bottom_half",
      2137,
      "CSID[%u] powered down state",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL));
LABEL_122:
    result = raw_spin_unlock(v3 + 30968);
LABEL_123:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v13 = (unsigned int)v13;
  v123 = (unsigned int)v13;
  if ( !(_DWORD)v12 )
  {
    v122 = 0;
LABEL_92:
    v71 = v13;
    v72 = &v10[v13];
    v73 = v72[79];
    v74 = v73 & v6;
    if ( (v73 & v6) != 0 )
    {
      v124 = 0;
      v75 = *(_QWORD *)&v11[8 * v71];
      if ( (v75 & 0x1000) != 0 && ((v74 >> v11[28]) & 1) != 0 )
      {
        cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "CPHY_SOT_RECEPTION: Less SOTs on lane/s", v15, v16, v94);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_rx_err_process_bottom_half",
          2357,
          "CSID[%u] Partly fatal errors: %s",
          *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
          (const char *)(v4 + 2488));
        v75 = *(_QWORD *)&v11[8 * v123];
      }
      v124 = 0;
      if ( (v75 & 0x80000) != 0 && ((v74 >> v11[35]) & 1) != 0 )
      {
        v122 |= 0x10000u;
        if ( (*(_BYTE *)(v3 + 2215) & 1) != 0 || *(_DWORD *)(v3 + 2140) > *(_DWORD *)(v4 + 3584) )
        {
          v120 = v12;
          cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[20]);
          v76 = cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[28]);
          cam_print_to_buffer(
            v4 + 2488,
            0x400u,
            &v124,
            1u,
            8u,
            "LONG_PACKET_PAYLOAD_CRC occurred at [%llu: %09llu]",
            *(_QWORD *)(a2 + 24),
            *(_QWORD *)(a2 + 32),
            v94);
          cam_print_to_buffer(
            v4 + 2488,
            0x400u,
            &v124,
            1u,
            8u,
            "Sensor: The calculated CRC of a long packet does not match the transmitted (expected) CRC, possible corruption",
            v77,
            v78,
            v115);
          cam_print_to_buffer(
            v4 + 2488,
            0x400u,
            &v124,
            1u,
            8u,
            "Debug: First frame CRC: Check sensor data rate / settle count in XML for proper PHY configuration; Streaming"
            " state: Check sensor constraints for exposure control else perform PHY CDR-EQ Tuning",
            v79,
            v80,
            v116);
          if ( *(_DWORD *)(v3 + 2072) == 1 )
          {
            v82 = cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[21]);
            cam_print_to_buffer(
              v4 + 2488,
              0x400u,
              &v124,
              1u,
              8u,
              "Total CRC Errors: %u, Virtual Channel: %u, Data Type: %u, Word Count: %u",
              v76,
              v82 >> 22,
              BYTE2(v82) & 0x3F);
          }
          else
          {
            cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "Total CRC Errors: %u", v76, v81, v117);
          }
          LODWORD(v12) = v120;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_ver2_rx_err_process_bottom_half",
            2397,
            "CSID[%u] Partly fatal errors: %s",
            *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
            (const char *)(v4 + 2488));
        }
      }
      LODWORD(v12) = v74 | v12;
      cam_ife_csid_ver2_send_cdr_sweep_csi2_rx_vals(v3, v9, v6);
    }
    v83 = v72[81] & v6;
    if ( (v72[81] & v6) != 0 )
    {
      v124 = 0;
      if ( (*(_QWORD *)&v11[8 * v123] & 0x200000) != 0 && ((v83 >> v11[37]) & 1) != 0 )
      {
        v84 = cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[18]);
        v85 = *(_QWORD *)(a2 + 24);
        v86 = *(_QWORD *)(a2 + 32);
        v87 = v84;
        cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "MMAPPED_VC_DT occurred at [%llu: %09llu]", v85, v86, v94);
        cam_print_to_buffer(
          v4 + 2488,
          0x400u,
          &v124,
          1u,
          8u,
          "SW: A long packet has a VC_DT combination that is configured for more than one IPP or RDIs",
          v88,
          v89,
          v118);
        cam_print_to_buffer(
          v4 + 2488,
          0x400u,
          &v124,
          1u,
          8u,
          "Virtual Channel: %u, Data Type: %u",
          v87 >> 22,
          HIWORD(v87) & 0x3F,
          v119);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx_err_process_bottom_half",
        2427,
        "CSID[%u] Non-fatal-errors: %s",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        (const char *)(v4 + 2488));
    }
    if ( (unsigned int)__ratelimit(
                         &cam_ife_csid_ver2_rx_err_process_bottom_half__rs,
                         "cam_ife_csid_ver2_rx_err_process_bottom_half") )
      v90 = 3;
    else
      v90 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v90,
      8,
      2,
      "cam_ife_csid_ver2_rx_err_process_bottom_half",
      2432,
      "CSID[%u] Rx Status 0x%x",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
      v6);
    v91 = *(_BYTE *)(v3 + 2157);
    v92 = *(_DWORD *)(v3 + 2068) - *(_DWORD *)(*(_QWORD *)(v9 + 120) + 588LL);
    v125 = v92;
    if ( (v91 & 1) == 0 && *(_BYTE *)(v3 + 2153) == 1 )
    {
      if ( v122 )
        v93 = v122;
      else
        v93 = 32;
      if ( v92 < 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_ife_csid_ver2_rx_err_process_bottom_half",
          2441,
          "Can't notify csiphy, incorrect phy selected=%d",
          v92);
      else
        cam_subdev_notify_message(65544, 2u, (__int64)&v125);
      cam_ife_csid_ver2_handle_event_err(v3, v12, v93, 0, 0);
      *(_BYTE *)(v3 + 2157) = 1;
    }
    goto LABEL_122;
  }
  v127 = 0;
  v126 = 0;
  v17 = *(_QWORD *)&v11[8 * (unsigned int)v13];
  if ( (v17 & 0x8000) != 0 && ((v12 >> v11[31]) & 1) != 0 )
  {
    v18 = scnprintf(&v126, 10, " %zu", 0);
    v19 = 1;
    v17 = *(_QWORD *)&v11[8 * v123];
    if ( (v17 & 0x10000) == 0 )
      goto LABEL_16;
  }
  else
  {
    v19 = 0;
    v18 = 0;
    if ( (v17 & 0x10000) == 0 )
      goto LABEL_16;
  }
  if ( ((v12 >> v11[31]) & 2) != 0 )
  {
    if ( v18 > 0xA )
      goto LABEL_124;
    v19 = 1;
    v18 += scnprintf((char *)&v126 + v18, 10 - v18, " %zu", 1u);
    v17 = *(_QWORD *)&v11[8 * v123];
  }
LABEL_16:
  if ( (v17 & 0x20000) != 0 && ((v12 >> v11[31]) & 4) != 0 )
  {
    if ( v18 > 0xA )
      goto LABEL_124;
    v18 += scnprintf((char *)&v126 + v18, 10 - v18, " %zu", 2u);
    v19 = 1;
    v17 = *(_QWORD *)&v11[8 * v123];
  }
  if ( (v17 & 0x40000) != 0 && ((v12 >> v11[31]) & 8) != 0 )
  {
    if ( v18 > 0xA )
      goto LABEL_124;
    scnprintf((char *)&v126 + v18, 10 - v18, " %zu", 3u);
  }
  else if ( !v19 )
  {
    v122 = 0;
    goto LABEL_28;
  }
  cam_print_to_buffer(
    v4 + 2488,
    0x400u,
    &v124,
    1u,
    8u,
    "DLn_FIFO_OVERFLOW, Lanes:%s, occurred at [%llu: %09llu]",
    (__int64)&v126,
    *(_QWORD *)(a2 + 24),
    *(_QWORD *)(a2 + 32));
  cam_print_to_buffer(
    v4 + 2488,
    0x400u,
    &v124,
    1u,
    8u,
    "System: Data has been lost when transferring from PHY to CSID",
    v20,
    v21,
    v95);
  cam_print_to_buffer(
    v4 + 2488,
    0x400u,
    &v124,
    1u,
    8u,
    "Debug: Check PHY clock, CSID clock and possible skew among the data lanes",
    v22,
    v23,
    v96);
  cam_print_to_buffer(
    v4 + 2488,
    0x400u,
    &v124,
    1u,
    8u,
    "DPHY: Enable skew calibration for datarate > 1.5Gbps/lane",
    v24,
    v25,
    v97);
  cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "CPHY: Perform CDR tuning", v26, v27, v98);
  cam_print_to_buffer(
    v4 + 2488,
    0x400u,
    &v124,
    1u,
    8u,
    "Current CSID clock rate: %lluHz",
    *(_QWORD *)(v3 + 32184),
    v28,
    v99);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_rx_err_process_bottom_half",
    2174,
    "CSID[%u] Fatal Errors: %s",
    *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
    (const char *)(v4 + 2488));
  v122 = 512;
LABEL_28:
  v124 = 0;
  v29 = *(_QWORD *)&v11[8 * v123];
  if ( (v29 & 0x100000000LL) != 0 && ((v12 >> v11[48]) & 1) != 0 )
  {
    v30 = scnprintf(&v126, 10, " %zu", 0);
    v31 = 1;
    v29 = *(_QWORD *)&v11[8 * v123];
    if ( (v29 & 0x200000000LL) == 0 )
      goto LABEL_36;
  }
  else
  {
    v31 = 0;
    v30 = 0;
    if ( (v29 & 0x200000000LL) == 0 )
      goto LABEL_36;
  }
  if ( ((v12 >> v11[48]) & 2) != 0 )
  {
    if ( v30 > 0xA )
      goto LABEL_124;
    v31 = 1;
    v30 += scnprintf((char *)&v126 + v30, 10 - v30, " %zu", 1u);
    v29 = *(_QWORD *)&v11[8 * v123];
  }
LABEL_36:
  if ( (v29 & 0x400000000LL) != 0 && ((v12 >> v11[48]) & 4) != 0 )
  {
    if ( v30 > 0xA )
      goto LABEL_124;
    v30 += scnprintf((char *)&v126 + v30, 10 - v30, " %zu", 2u);
    v31 = 1;
    v29 = *(_QWORD *)&v11[8 * v123];
  }
  if ( (v29 & 0x800000000LL) != 0 && ((v12 >> v11[48]) & 8) != 0 )
  {
    if ( v30 > 0xA )
      goto LABEL_124;
    scnprintf((char *)&v126 + v30, 10 - v30, " %zu", 3u);
    goto LABEL_45;
  }
  if ( v31 )
  {
LABEL_45:
    v122 |= 0x80000u;
    cam_print_to_buffer(
      v4 + 2488,
      0x400u,
      &v124,
      1u,
      8u,
      "DLn_SOT_LOST, Lanes:%s, occurred at [%llu: %09llu]",
      (__int64)&v126,
      *(_QWORD *)(a2 + 24),
      *(_QWORD *)(a2 + 32));
    cam_print_to_buffer(
      v4 + 2488,
      0x400u,
      &v124,
      1u,
      8u,
      "Sensor: Timing signals are missed received in the CPHY packet",
      v32,
      v33,
      v100);
    cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "Debug: Check PHY/sensor config", v34, v35, v101);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_rx_err_process_bottom_half",
      2199,
      "CSID[%u] Fatal Errors: %s",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
      (const char *)(v4 + 2488));
  }
  v124 = 0;
  v36 = *(_QWORD *)&v11[8 * v123];
  if ( (v36 & 0x10000000) == 0 || ((v12 >> v11[44]) & 1) == 0 )
  {
    v38 = 0;
    v37 = 0;
    if ( (v36 & 0x20000000) == 0 )
      goto LABEL_54;
LABEL_51:
    if ( ((v12 >> v11[44]) & 2) != 0 )
    {
      if ( v37 > 0xA )
        goto LABEL_124;
      v38 = 1;
      v37 += scnprintf((char *)&v126 + v37, 10 - v37, " %zu", 1u);
      v36 = *(_QWORD *)&v11[8 * v123];
    }
    goto LABEL_54;
  }
  v37 = scnprintf(&v126, 10, " %zu", 0);
  v38 = 1;
  v36 = *(_QWORD *)&v11[8 * v123];
  if ( (v36 & 0x20000000) != 0 )
    goto LABEL_51;
LABEL_54:
  if ( (v36 & 0x40000000) != 0 && ((v12 >> v11[44]) & 4) != 0 )
  {
    if ( v37 > 0xA )
      goto LABEL_124;
    v37 += scnprintf((char *)&v126 + v37, 10 - v37, " %zu", 2u);
    v38 = 1;
    v36 = *(_QWORD *)&v11[8 * v123];
  }
  if ( (v36 & 0x80000000) == 0 || ((v12 >> v11[44]) & 8) == 0 )
  {
    if ( !v38 )
      goto LABEL_64;
    goto LABEL_63;
  }
  if ( v37 <= 0xA )
  {
    scnprintf((char *)&v126 + v37, 10 - v37, " %zu", 3u);
LABEL_63:
    v122 |= 0x8000u;
    cam_print_to_buffer(
      v4 + 2488,
      0x400u,
      &v124,
      1u,
      8u,
      "DLn_EOT_LOST, Lanes:%s, occurred at [%llu: %09llu]",
      (__int64)&v126,
      *(_QWORD *)(a2 + 24),
      *(_QWORD *)(a2 + 32));
    cam_print_to_buffer(
      v4 + 2488,
      0x400u,
      &v124,
      1u,
      8u,
      "Sensor: Timing signals are missed received in the CPHY packet",
      v39,
      v40,
      v102);
    cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "Debug: Check PHY/sensor config", v41, v42, v103);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_rx_err_process_bottom_half",
      2224,
      "CSID[%u] Fatal Errors: %s",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
      (const char *)(v4 + 2488));
LABEL_64:
    v13 = v123;
    v124 = 0;
    v43 = *(_QWORD *)&v11[8 * v123];
    if ( (v43 & 0x2000) != 0 && ((v12 >> v11[29]) & 1) != 0 )
    {
      v122 |= 0x400u;
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "CPHY_PACKET_HEADER_CRC occurred at [%llu: %09llu]",
        *(_QWORD *)(a2 + 24),
        *(_QWORD *)(a2 + 32),
        v94);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Sensor: All CPHY packet headers received are corrupted",
        v44,
        v45,
        v104);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Debug: Check sensor data rate in output pixel clock in XML for proper PHY configuration",
        v46,
        v47,
        v105);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx_err_process_bottom_half",
        2239,
        "CSID[%u] Fatal Errors: %s",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        (const char *)(v4 + 2488));
      v43 = *(_QWORD *)&v11[8 * v123];
    }
    v124 = 0;
    if ( (v43 & 0x800000) != 0 && ((v12 >> v11[39]) & 1) != 0 )
    {
      v122 |= 0x800u;
      v48 = cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[18]);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "STREAM_UNDERFLOW occurred at [%llu: %09llu]",
        *(_QWORD *)(a2 + 24),
        *(_QWORD *)(a2 + 32),
        v94);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Sensor: Long packet payload size is less than payload header size, resulting a corrupted frame",
        v49,
        v50,
        v106);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Debug: Perform PHY Tuning/Check sensor limitations",
        v51,
        v52,
        v107);
      v53 = v48;
      v13 = v123;
      cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "Word Count: %u", v53, v54, v108);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx_err_process_bottom_half",
        2259,
        "CSID[%u] Fatal Errors: %s",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        (const char *)(v4 + 2488));
      v43 = *(_QWORD *)&v11[8 * v123];
    }
    v124 = 0;
    if ( (v43 & 0x100000) != 0 && ((v12 >> v11[36]) & 1) != 0 )
    {
      v122 |= 0x400u;
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "DPHY_PACKET_HEADER_ECC_DETECTED occurred on [%llu: %09llu]",
        *(_QWORD *)(a2 + 24),
        *(_QWORD *)(a2 + 32),
        v94);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Sensor: A short or long packet is corrupted and cannot be recovered",
        v55,
        v56,
        v109);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Debug: Check sensor datarate in output pixel clock in XML for proper PHY configuration",
        v57,
        v58,
        v110);
      v59 = cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[19]);
      cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "Error Correction Code: 0x%x", v59, v60, v111);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx_err_process_bottom_half",
        2278,
        "CSID[%u] Fatal Errors: %s",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        (const char *)(v4 + 2488));
      v43 = *(_QWORD *)&v11[8 * v13];
    }
    v124 = 0;
    if ( (v43 & 0x1000000) != 0 && ((v12 >> v11[40]) & 1) != 0 )
    {
      v122 |= 0x2000u;
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "UNBOUNDED_FRAME: Frame started with EOF or No EOF",
        v15,
        v16,
        v94);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx_err_process_bottom_half",
        2288,
        "CSID[%u] Fatal Errors: %s",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        (const char *)(v4 + 2488));
      v43 = *(_QWORD *)&v11[8 * v13];
    }
    v124 = 0;
    if ( (v43 & 0x800) != 0 && ((v12 >> v11[27]) & 1) != 0 )
    {
      v61 = *(_DWORD *)(v3 + 2072);
      if ( (*(_DWORD *)(v3 + 2096) & 0x10) != 0 )
        v62 = 89;
      else
        v62 = 78;
      v122 |= 0x8000u;
      if ( v61 )
        v63 = "cphy";
      else
        v63 = "dphy";
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "CPHY_EOT_RECEPTION: No EOT on lane/s, is_EPD: %c, PHY_Type: %s(%u)",
        v62,
        (__int64)v63,
        v61);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx_err_process_bottom_half",
        2301,
        "CSID[%u] Fatal Errors: %s",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        (const char *)(v4 + 2488));
      v43 = *(_QWORD *)&v11[8 * v13];
    }
    v124 = 0;
    if ( (v43 & 0x80000) != 0 && ((v12 >> v11[35]) & 1) != 0 )
    {
      v122 |= 0x10000u;
      cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[20]);
      v64 = cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[28]);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "LONG_PACKET_PAYLOAD_CRC occurred at [%llu: %09llu]",
        *(_QWORD *)(a2 + 24),
        *(_QWORD *)(a2 + 32),
        v94);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Sensor: The calculated CRC of a long packet does not match the transmitted (expected) CRC, possible corruption",
        v65,
        v66,
        v112);
      cam_print_to_buffer(
        v4 + 2488,
        0x400u,
        &v124,
        1u,
        8u,
        "Debug: First frame CRC: Check sensor data rate / settle count in XML for proper PHY configuration; Streaming sta"
        "te: Check sensor constraints for exposure control else perform PHY CDR-EQ Tuning",
        v67,
        v68,
        v113);
      if ( *(_DWORD *)(v3 + 2072) == 1 )
      {
        v70 = cam_io_r_mb(*(_QWORD *)(v121 + 384) + v10[21]);
        cam_print_to_buffer(
          v4 + 2488,
          0x400u,
          &v124,
          1u,
          8u,
          "Total CRC Errors: %u, Virtual Channel: %u, Data Type: %u, Word Count: %u",
          v64,
          v70 >> 22,
          BYTE2(v70) & 0x3F);
      }
      else
      {
        cam_print_to_buffer(v4 + 2488, 0x400u, &v124, 1u, 8u, "Total CRC Errors: %u", v64, v69, v114);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx_err_process_bottom_half",
        2338,
        "CSID[%u] Fatal Errors: %s",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        (const char *)(v4 + 2488));
      v13 = v123;
    }
    *(_BYTE *)(v3 + 2153) = 1;
    cam_ife_csid_ver2_send_cdr_sweep_csi2_rx_vals(v3, v9, v6);
    goto LABEL_92;
  }
LABEL_124:
  __break(0x5512u);
  return cam_ife_csid_ver2_handle_rx2_irq();
}
