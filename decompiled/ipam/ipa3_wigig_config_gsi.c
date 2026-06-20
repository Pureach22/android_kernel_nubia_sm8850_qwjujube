__int64 __fastcall ipa3_wigig_config_gsi(char a1, char a2, __int64 *a3, unsigned int *a4, __int64 a5, __int64 a6)
{
  __int64 v11; // x8
  __int64 v12; // x0
  const char *v13; // x4
  const char *v14; // x5
  __int64 v15; // x0
  const char *v16; // x4
  const char *v17; // x5
  __int64 *v18; // x8
  __int64 *v19; // x26
  unsigned __int16 *v20; // x9
  __int64 *v21; // x10
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v25; // x19
  int v26; // w0
  unsigned int v27; // w0
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x10
  int v31; // w25
  unsigned int *v32; // x10
  int v33; // w23
  unsigned int *v34; // x9
  unsigned int *v35; // x8
  __int64 v36; // x20
  unsigned int v37; // w10
  int v38; // w8
  unsigned int *v39; // x9
  int v40; // w27
  __int64 v41; // x21
  unsigned int v42; // w22
  unsigned int v43; // w10
  _QWORD *v44; // x8
  unsigned int v45; // w24
  __int64 v46; // x26
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  unsigned int v55; // w27
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  int v60; // w8
  unsigned __int16 v61; // w24
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  int v68; // w27
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  unsigned int v87; // w0
  __int64 v88; // x8
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x9
  __int64 v92; // x10
  __int64 v93; // x0
  int v94; // w0
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 result; // x0
  int v98; // w19
  __int64 v99; // x8
  __int64 v100; // x0
  __int64 v101; // x0
  unsigned int v102; // w20
  __int64 v103; // x8
  __int64 v104; // x0
  __int64 v105; // x0
  int v106; // w20
  __int64 v107; // x8
  __int64 v108; // x0
  __int64 v109; // x0
  unsigned int v110; // w20
  __int64 v111; // x8
  __int64 v112; // x0
  __int64 v113; // x0
  __int64 v114; // [xsp+8h] [xbp-138h]
  __int64 v115; // [xsp+10h] [xbp-130h]
  _DWORD v117[2]; // [xsp+20h] [xbp-120h] BYREF
  unsigned __int64 v118; // [xsp+28h] [xbp-118h]
  __int64 v119; // [xsp+30h] [xbp-110h]
  __int128 v120; // [xsp+38h] [xbp-108h] BYREF
  __int64 v121; // [xsp+48h] [xbp-F8h]
  __int64 v122; // [xsp+50h] [xbp-F0h]
  __int64 v123; // [xsp+58h] [xbp-E8h]
  __int64 v124; // [xsp+60h] [xbp-E0h]
  __int64 v125; // [xsp+68h] [xbp-D8h]
  __int64 v126; // [xsp+70h] [xbp-D0h]
  __int64 v127; // [xsp+78h] [xbp-C8h]
  __int64 v128; // [xsp+80h] [xbp-C0h]
  __int64 v129; // [xsp+88h] [xbp-B8h]
  __int64 v130; // [xsp+90h] [xbp-B0h]
  __int64 (__fastcall *v131)(); // [xsp+98h] [xbp-A8h]
  __int64 v132; // [xsp+A0h] [xbp-A0h]
  __int64 v133; // [xsp+A8h] [xbp-98h]
  __int64 v134; // [xsp+B0h] [xbp-90h] BYREF
  __int64 v135; // [xsp+B8h] [xbp-88h]
  __int64 v136; // [xsp+C0h] [xbp-80h]
  __int64 v137; // [xsp+C8h] [xbp-78h]
  __int64 v138; // [xsp+D0h] [xbp-70h]
  __int64 v139; // [xsp+D8h] [xbp-68h]
  __int64 v140; // [xsp+E0h] [xbp-60h]
  __int64 v141; // [xsp+E8h] [xbp-58h]
  __int64 v142; // [xsp+F0h] [xbp-50h]
  __int64 v143; // [xsp+F8h] [xbp-48h]
  __int64 v144; // [xsp+100h] [xbp-40h]
  __int64 v145; // [xsp+108h] [xbp-38h]
  __int64 (__fastcall *v146)(); // [xsp+110h] [xbp-30h]
  __int64 v147; // [xsp+118h] [xbp-28h]
  __int64 v148; // [xsp+120h] [xbp-20h]
  __int64 v149; // [xsp+128h] [xbp-18h]
  __int64 v150; // [xsp+130h] [xbp-10h]

  v150 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = ipa3_ctx;
  v148 = 0;
  v149 = 0;
  v146 = nullptr;
  v147 = 0;
  v144 = 0;
  v145 = 0;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = nullptr;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v121 = 0;
  v120 = 0u;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      if ( (a1 & 1) != 0 )
        v13 = "Rx";
      else
        v13 = "Tx";
      if ( (a2 & 1) != 0 )
        v14 = "smmu en";
      else
        v14 = "smmu dis";
      ipc_log_string(v12, "ipa %s:%d %s, %s\n", "ipa3_wigig_config_gsi", 629, v13, v14);
      v11 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v11 + 34160);
    if ( v15 )
    {
      if ( (a1 & 1) != 0 )
        v16 = "Rx";
      else
        v16 = "Tx";
      if ( (a2 & 1) != 0 )
        v17 = "smmu en";
      else
        v17 = "smmu dis";
      ipc_log_string(v15, "ipa %s:%d %s, %s\n", "ipa3_wigig_config_gsi", 629, v16, v17);
    }
  }
  v138 = 0;
  v139 = 0;
  v146 = ipa_gsi_evt_ring_err_cb_1;
  v147 = 0;
  v134 = 9;
  LODWORD(v135) = 16;
  BYTE2(v138) = int_modc;
  v144 = 0;
  v145 = 1;
  LOWORD(v138) = int_modt;
  v18 = a3 + 3;
  v148 = 0;
  v149 = 0;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v137 = 0;
  if ( (a2 & 1) != 0 )
  {
    v19 = nullptr;
    v20 = (unsigned __int16 *)(a3 + 3);
    v21 = a3 + 2;
    v18 = a3 + 5;
  }
  else
  {
    v20 = (unsigned __int16 *)(a3 + 1);
    v21 = a3;
    v19 = a3;
    a3 = nullptr;
  }
  v22 = *v21;
  v23 = *v18;
  v24 = *(_QWORD *)(ipa3_ctx + 43296);
  HIDWORD(v135) = *v20;
  v25 = a6;
  v136 = v22;
  v140 = v23;
  v26 = gsi_alloc_evt_ring(&v134, v24, a6 + 16);
  if ( v26 )
  {
    v98 = v26;
    printk(&unk_3C95F6, "ipa3_wigig_config_gsi");
    v99 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v100 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v100 )
      {
        ipc_log_string(v100, "ipa %s:%d Error allocating event ring: %d\n", "ipa3_wigig_config_gsi", 661, v98);
        v99 = ipa3_ctx;
      }
      v101 = *(_QWORD *)(v99 + 34160);
      if ( v101 )
        ipc_log_string(v101, "ipa %s:%d Error allocating event ring: %d\n", "ipa3_wigig_config_gsi", 661, v98);
    }
    goto LABEL_157;
  }
  if ( (a1 & 1) != 0 )
  {
    v27 = gsi_write_evt_ring_scratch(*(_QWORD *)(a6 + 16), (unsigned __int8)rx_hwtail_mod_threshold);
    if ( v27 )
    {
      v110 = v27;
      printk(&unk_3A7BBA, "ipa3_wigig_config_gsi");
      v111 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v112 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v112 )
        {
          ipc_log_string(
            v112,
            "ipa %s:%d Error writing WIGIG event ring scratch: %d\n",
            "ipa3_wigig_config_gsi",
            676,
            v110);
          v111 = ipa3_ctx;
        }
        v113 = *(_QWORD *)(v111 + 34160);
        if ( v113 )
          ipc_log_string(
            v113,
            "ipa %s:%d Error writing WIGIG event ring scratch: %d\n",
            "ipa3_wigig_config_gsi",
            676,
            v110);
      }
      goto LABEL_156;
    }
  }
  v28 = v136;
  v29 = v137;
  v122 = 0;
  v123 = 0;
  *(_DWORD *)(a6 + 24) = HIDWORD(v135);
  *(_QWORD *)(a6 + 32) = v28;
  *(_QWORD *)(a6 + 40) = v29;
  v30 = *(_QWORD *)(a6 + 16);
  LODWORD(v122) = 16;
  v31 = *(_DWORD *)(a5 + 4);
  HIDWORD(v120) = 0;
  v121 = 0;
  LODWORD(v120) = 9;
  *(_QWORD *)((char *)&v120 + 4) = a1 & 1;
  LODWORD(v28) = *(_DWORD *)(a5 + 20);
  v115 = v30;
  v121 = v30;
  LOBYTE(v30) = *(_BYTE *)(a5 + 24);
  v126 = 0;
  v127 = 1;
  LODWORD(v128) = 1;
  v124 = 0;
  v130 = 0;
  v132 = 0;
  BYTE8(v120) = v31;
  v125 = 0;
  HIDWORD(v128) = v28;
  v129 = (unsigned __int8)v30;
  v133 = 0;
  v131 = ipa_gsi_chan_err_cb_1;
  if ( (a1 & 1) != 0 )
  {
    v32 = a4;
    if ( (a2 & 1) != 0 )
    {
      v33 = *((unsigned __int16 *)a3 + 36);
      v34 = (unsigned int *)(a3 + 11);
      v114 = a3[8];
      v124 = v114;
      v35 = a4 + 6;
      v32 = a4 + 4;
    }
    else
    {
      v34 = (unsigned int *)(v19 + 7);
      v124 = v19[4];
      v33 = *((unsigned __int16 *)v19 + 20);
      v114 = v124;
      v35 = a4 + 2;
    }
    HIDWORD(v122) = v33;
    v41 = *(_QWORD *)v32;
    v42 = *v34;
    LODWORD(v36) = v34[1];
    v43 = 7936 - (__clz(*v35) << 8);
    v44 = (_QWORD *)ipa3_ctx;
    v45 = v43 & 0xFFFF00;
    v46 = v43 & 0xFFFF00 | BYTE4(v41);
    if ( !ipa3_ctx )
      goto LABEL_91;
    v47 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v47 )
    {
      ipc_log_string(
        v47,
        "ipa %s:%d rx scratch: status_ring_hwtail_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        756,
        v42);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v48 = v44[4270];
    if ( v48 )
    {
      ipc_log_string(
        v48,
        "ipa %s:%d rx scratch: status_ring_hwtail_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        756,
        v42);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v49 = v44[4269];
    if ( v49 )
    {
      ipc_log_string(
        v49,
        "ipa %s:%d rx scratch: status_ring_hwtail_address_msb 0x%X\n",
        "ipa3_wigig_config_gsi",
        758,
        v36);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v50 = v44[4270];
    if ( v50 )
    {
      ipc_log_string(
        v50,
        "ipa %s:%d rx scratch: status_ring_hwtail_address_msb 0x%X\n",
        "ipa3_wigig_config_gsi",
        758,
        v36);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v51 = v44[4269];
    if ( v51 )
    {
      ipc_log_string(
        v51,
        "ipa %s:%d rx scratch: data_buffers_base_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        760,
        v41);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v52 = v44[4270];
    if ( v52 )
    {
      ipc_log_string(
        v52,
        "ipa %s:%d rx scratch: data_buffers_base_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        760,
        v41);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v53 = v44[4269];
    if ( v53 )
    {
      ipc_log_string(
        v53,
        "ipa %s:%d rx scratch: data_buffers_base_address_msb 0x%X\n",
        "ipa3_wigig_config_gsi",
        762,
        BYTE4(v41));
      v44 = (_QWORD *)ipa3_ctx;
    }
    v54 = v44[4270];
    if ( v54 )
    {
      ipc_log_string(
        v54,
        "ipa %s:%d rx scratch: data_buffers_base_address_msb 0x%X\n",
        "ipa3_wigig_config_gsi",
        762,
        BYTE4(v41));
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v55 = v45 >> 8;
    v56 = v44[4269];
    if ( v56 )
    {
      ipc_log_string(v56, "ipa %s:%d rx scratch: fixed_data_buffer_size_pow_2 %d\n", "ipa3_wigig_config_gsi", 764, v55);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v57 = v44[4270];
    if ( v57 )
    {
      ipc_log_string(v57, "ipa %s:%d rx scratch: fixed_data_buffer_size_pow_2 %d\n", "ipa3_wigig_config_gsi", 764, v55);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v58 = v44[4269];
    if ( v58 )
    {
      ipc_log_string(v58, "ipa %s:%d rx scratch 0x[%X][%X][%X][%X]\n", "ipa3_wigig_config_gsi", 769, v42, v36, v41, v46);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v59 = v44[4270];
    if ( v59 )
    {
      ipc_log_string(
        v59,
        "ipa %s:%d rx scratch 0x[%X][%X][%X][%X]\n",
        "ipa3_wigig_config_gsi",
        769,
        v42,
        (unsigned int)v36,
        (unsigned int)v41,
        (unsigned int)v46);
LABEL_91:
      v44 = (_QWORD *)ipa3_ctx;
    }
  }
  else
  {
    if ( (a2 & 1) != 0 )
    {
      v36 = a3[10];
      v37 = a4[5];
      v38 = *((unsigned __int16 *)a3 + 36) << 12;
      v124 = a3[2];
      v33 = *((unsigned __int16 *)a3 + 12);
      v114 = v124;
      v39 = (unsigned int *)(a3 + 11);
      v40 = v38 & 0xFFF0000 | BYTE4(v36);
      HIDWORD(v122) = v33;
    }
    else
    {
      v36 = v19[6];
      v39 = (unsigned int *)(v19 + 7);
      v37 = *a4;
      v124 = *v19;
      v114 = v124;
      v33 = *((unsigned __int16 *)v19 + 4);
      v60 = *((unsigned __int16 *)v19 + 20) << 12;
      HIDWORD(v122) = v33;
      v40 = v60 & 0xFFF0000 | BYTE4(v36);
    }
    v61 = 31 - __clz(v37);
    v44 = (_QWORD *)ipa3_ctx;
    v42 = *v39;
    v46 = v61 << 8;
    LODWORD(v41) = v40 & 0xFFFF00FF | ((unsigned __int8)tx_hwtail_mod_threshold << 8);
    if ( !ipa3_ctx )
      goto LABEL_91;
    v62 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v62 )
    {
      ipc_log_string(
        v62,
        "ipa %s:%d tx scratch: status_ring_hwtail_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        821,
        v42);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v63 = v44[4270];
    if ( v63 )
    {
      ipc_log_string(
        v63,
        "ipa %s:%d tx scratch: status_ring_hwtail_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        821,
        v42);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v64 = v44[4269];
    if ( v64 )
    {
      ipc_log_string(
        v64,
        "ipa %s:%d tx scratch: status_ring_hwhead_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        823,
        v36);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v65 = v44[4270];
    if ( v65 )
    {
      ipc_log_string(
        v65,
        "ipa %s:%d tx scratch: status_ring_hwhead_address_lsb 0x%X\n",
        "ipa3_wigig_config_gsi",
        823,
        v36);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v66 = v44[4269];
    if ( v66 )
    {
      ipc_log_string(
        v66,
        "ipa %s:%d tx scratch: status_ring_hwhead_hwtail_8_msb 0x%X\n",
        "ipa3_wigig_config_gsi",
        825,
        (unsigned __int8)v40);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v67 = v44[4270];
    if ( v67 )
    {
      ipc_log_string(
        v67,
        "ipa %s:%d tx scratch: status_ring_hwhead_hwtail_8_msb 0x%X\n",
        "ipa3_wigig_config_gsi",
        825,
        (unsigned __int8)v40);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v68 = HIWORD(v40);
    v69 = v44[4269];
    if ( v69 )
    {
      ipc_log_string(v69, "ipa %s:%d tx scratch:status_ring_num_elem %d\n", "ipa3_wigig_config_gsi", 827, v68);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v70 = v44[4270];
    if ( v70 )
    {
      ipc_log_string(v70, "ipa %s:%d tx scratch:status_ring_num_elem %d\n", "ipa3_wigig_config_gsi", 827, v68);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v71 = v44[4269];
    if ( v71 )
    {
      ipc_log_string(v71, "ipa %s:%d tx scratch:fixed_data_buffer_size_pow_2 %d\n", "ipa3_wigig_config_gsi", 829, v61);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v72 = v44[4270];
    if ( v72 )
    {
      ipc_log_string(v72, "ipa %s:%d tx scratch:fixed_data_buffer_size_pow_2 %d\n", "ipa3_wigig_config_gsi", 829, v61);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( !v44 )
      goto LABEL_91;
    v73 = v44[4269];
    if ( v73 )
    {
      ipc_log_string(v73, "ipa %s:%d tx scratch 0x[%X][%X][%X][%X]\n", "ipa3_wigig_config_gsi", 834, v42, v36, v41, v46);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v74 = v44[4270];
    if ( v74 )
    {
      ipc_log_string(
        v74,
        "ipa %s:%d tx scratch 0x[%X][%X][%X][%X]\n",
        "ipa3_wigig_config_gsi",
        834,
        v42,
        (unsigned int)v36,
        (unsigned int)v41,
        (unsigned int)v46);
      goto LABEL_91;
    }
  }
  if ( v44 )
  {
    v75 = v44[4269];
    if ( v75 )
    {
      ipc_log_string(v75, "ipa %s:%d ch_id: %d\n", "ipa3_wigig_config_gsi", 837, (unsigned __int8)v31);
      v44 = (_QWORD *)ipa3_ctx;
    }
    v76 = v44[4270];
    if ( v76 )
    {
      ipc_log_string(v76, "ipa %s:%d ch_id: %d\n", "ipa3_wigig_config_gsi", 837, (unsigned __int8)v31);
      v44 = (_QWORD *)ipa3_ctx;
    }
    if ( v44 )
    {
      v77 = v44[4269];
      if ( v77 )
      {
        ipc_log_string(v77, "ipa %s:%d evt_ring_hdl: %ld\n", "ipa3_wigig_config_gsi", 838, v115);
        v44 = (_QWORD *)ipa3_ctx;
      }
      v78 = v44[4270];
      if ( v78 )
      {
        ipc_log_string(v78, "ipa %s:%d evt_ring_hdl: %ld\n", "ipa3_wigig_config_gsi", 838, v115);
        v44 = (_QWORD *)ipa3_ctx;
      }
      if ( v44 )
      {
        v79 = v44[4269];
        if ( v79 )
        {
          ipc_log_string(v79, "ipa %s:%d re_size: %d\n", "ipa3_wigig_config_gsi", 839, 16);
          v44 = (_QWORD *)ipa3_ctx;
        }
        v80 = v44[4270];
        if ( v80 )
        {
          ipc_log_string(v80, "ipa %s:%d re_size: %d\n", "ipa3_wigig_config_gsi", 839, 16);
          v44 = (_QWORD *)ipa3_ctx;
        }
        if ( v44 )
        {
          v81 = v44[4269];
          if ( v81 )
          {
            ipc_log_string(v81, "ipa %s:%d GSI channel ring len: %d\n", "ipa3_wigig_config_gsi", 840, v33);
            v44 = (_QWORD *)ipa3_ctx;
          }
          v82 = v44[4270];
          if ( v82 )
          {
            ipc_log_string(v82, "ipa %s:%d GSI channel ring len: %d\n", "ipa3_wigig_config_gsi", 840, v33);
            v44 = (_QWORD *)ipa3_ctx;
          }
          if ( v44 )
          {
            v83 = v44[4269];
            if ( v83 )
            {
              ipc_log_string(v83, "ipa %s:%d channel ring  base addr = 0x%llX\n", "ipa3_wigig_config_gsi", 842, v114);
              v44 = (_QWORD *)ipa3_ctx;
            }
            v84 = v44[4270];
            if ( v84 )
            {
              ipc_log_string(v84, "ipa %s:%d channel ring  base addr = 0x%llX\n", "ipa3_wigig_config_gsi", 842, v114);
              v44 = (_QWORD *)ipa3_ctx;
            }
            if ( v44 )
            {
              v85 = v44[4269];
              if ( v85 )
              {
                ipc_log_string(v85, "ipa %s:%d Allocating GSI channel\n", "ipa3_wigig_config_gsi", 844);
                v44 = (_QWORD *)ipa3_ctx;
              }
              v86 = v44[4270];
              if ( v86 )
              {
                ipc_log_string(v86, "ipa %s:%d Allocating GSI channel\n", "ipa3_wigig_config_gsi", 844);
                v44 = (_QWORD *)ipa3_ctx;
              }
            }
          }
        }
      }
    }
  }
  v87 = gsi_alloc_channel(&v120, v44[5412], v25 + 8);
  if ( v87 )
  {
    v102 = v87;
    printk(&unk_3ADC1B, "ipa3_wigig_config_gsi");
    v103 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v104 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v104 )
      {
        ipc_log_string(v104, "ipa %s:%d gsi_alloc_channel failed %d\n", "ipa3_wigig_config_gsi", 849, v102);
        v103 = ipa3_ctx;
      }
      v105 = *(_QWORD *)(v103 + 34160);
      if ( v105 )
        ipc_log_string(v105, "ipa %s:%d gsi_alloc_channel failed %d\n", "ipa3_wigig_config_gsi", 849, v102);
    }
    goto LABEL_156;
  }
  v88 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v89 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v89 )
    {
      ipc_log_string(v89, "ipa %s:%d Writing Channel scratch\n", "ipa3_wigig_config_gsi", 853);
      v88 = ipa3_ctx;
    }
    v90 = *(_QWORD *)(v88 + 34160);
    if ( v90 )
      ipc_log_string(v90, "ipa %s:%d Writing Channel scratch\n", "ipa3_wigig_config_gsi", 853);
  }
  v91 = v124;
  v92 = v126;
  v93 = *(_QWORD *)(v25 + 8);
  v117[0] = v42;
  v117[1] = v36;
  *(_DWORD *)(v25 + 48) = HIDWORD(v122);
  *(_QWORD *)(v25 + 56) = v91;
  *(_QWORD *)(v25 + 64) = v92;
  v118 = (unsigned int)v41 | (unsigned __int64)(v46 << 32);
  v119 = 0;
  v94 = gsi_write_channel_scratch(v93, v117);
  if ( v94 )
  {
    v106 = v94;
    printk(&unk_3EFB51, "ipa3_wigig_config_gsi");
    v107 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v108 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v108 )
      {
        ipc_log_string(v108, "ipa %s:%d gsi_write_channel_scratch failed %d\n", "ipa3_wigig_config_gsi", 863, v106);
        v107 = ipa3_ctx;
      }
      v109 = *(_QWORD *)(v107 + 34160);
      if ( v109 )
        ipc_log_string(v109, "ipa %s:%d gsi_write_channel_scratch failed %d\n", "ipa3_wigig_config_gsi", 863, v106);
    }
    gsi_dealloc_channel(*(_QWORD *)(v25 + 8));
LABEL_156:
    gsi_dealloc_evt_ring(*(_QWORD *)(v25 + 16));
LABEL_157:
    result = 4294967282LL;
    goto LABEL_158;
  }
  v95 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_134:
    result = 0;
    goto LABEL_158;
  }
  v96 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v96 )
  {
    ipc_log_string(v96, "ipa %s:%d exit\n", "ipa3_wigig_config_gsi", 867);
    v95 = ipa3_ctx;
  }
  result = *(_QWORD *)(v95 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_wigig_config_gsi", 867);
    goto LABEL_134;
  }
LABEL_158:
  _ReadStatusReg(SP_EL0);
  return result;
}
