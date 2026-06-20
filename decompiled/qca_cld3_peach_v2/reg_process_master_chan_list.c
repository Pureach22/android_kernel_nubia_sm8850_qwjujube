__int64 __fastcall reg_process_master_chan_list(__int64 *a1)
{
  __int64 v1; // x27
  __int64 v3; // x20
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 psoc_tx_ops; // x0
  _DWORD *v15; // x8
  __int64 v16; // x26
  __int64 v17; // x24
  const char *v18; // x2
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w23
  __int64 v36; // x21
  __int64 v37; // x25
  _BYTE *v38; // x8
  __int64 v39; // x8
  int v40; // w11
  bool v41; // zf
  __int64 v42; // x13
  int v43; // w14
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  _WORD *v52; // x17
  int v53; // w9
  unsigned int v54; // w8
  __int64 v55; // x10
  unsigned int v56; // w21
  unsigned int v57; // w11
  _WORD *v58; // x12
  __int64 v59; // x13
  unsigned int v60; // w14
  unsigned int v61; // w15
  _WORD *v62; // x11
  __int64 v63; // x10
  _WORD *v64; // x11
  unsigned int v65; // w12
  _WORD *v66; // x15
  __int64 v67; // x9
  _WORD *v68; // x10
  unsigned int v69; // w12
  __int64 v70; // x11
  unsigned int v71; // w13
  unsigned int v72; // w14
  _WORD *v73; // x10
  __int64 v74; // x9
  _WORD *v75; // x10
  unsigned int v76; // w11
  __int64 v77; // x20
  __int64 v78; // x0
  void (__fastcall *v79)(__int64, __int64, char *); // x8
  __int64 v80; // x1
  __int64 v81; // x22
  int v82; // w19
  unsigned int v83; // w19
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double (*v93)(void); // x8
  __int64 v94; // x20
  double v95; // d0
  unsigned int *v96; // x8
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  char *v105; // x24
  __int64 v106; // x8
  __int16 *v107; // x9
  __int16 v108; // w11
  int v109; // w11
  unsigned int v110; // w11
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  unsigned int v119; // w24
  int v120; // w8
  int v121; // w8
  __int64 pdev_by_id; // x0
  __int64 v123; // x22
  __int64 v124; // x0
  void (__fastcall *v125)(__int64, __int64); // x8
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int64 v134; // x21
  __int64 pdev_obj; // x0
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 v144; // x23
  __int64 v145; // [xsp+8h] [xbp-48h]
  int v146; // [xsp+10h] [xbp-40h]
  unsigned int v147; // [xsp+14h] [xbp-3Ch]
  unsigned int v148; // [xsp+18h] [xbp-38h]
  unsigned int v149; // [xsp+1Ch] [xbp-34h]
  const void *v150; // [xsp+20h] [xbp-30h]
  char *v151; // [xsp+28h] [xbp-28h]
  __int64 v152; // [xsp+30h] [xbp-20h]
  char v153[4]; // [xsp+3Ch] [xbp-14h] BYREF
  char v154[4]; // [xsp+40h] [xbp-10h] BYREF
  int v155; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v156; // [xsp+48h] [xbp-8h]

  v156 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v153[0] = 0;
  psoc_obj = reg_get_psoc_obj(v3);
  if ( !psoc_obj )
  {
    v18 = "%s: psoc reg component is NULL";
LABEL_71:
    qdf_trace_msg(0x51u, 2u, v18, v5, v6, v7, v8, v9, v10, v11, v12, "__reg_process_master_chan_list");
    goto LABEL_72;
  }
  v13 = psoc_obj;
  psoc_tx_ops = reg_get_psoc_tx_ops(v3);
  if ( !psoc_tx_ops )
    goto LABEL_72;
  v15 = *(_DWORD **)(psoc_tx_ops + 136);
  v16 = *((unsigned __int8 *)a1 + 13);
  v17 = psoc_tx_ops;
  if ( v15 )
  {
    if ( *(v15 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, char *))v15)(v3, (unsigned int)v16, v153);
  }
  else
  {
    v153[0] = *((_BYTE *)a1 + 13);
  }
  if ( (reg_ignore_default_country(v13, a1) & 1) != 0
    && !(unsigned int)((__int64 (__fastcall *)(__int64, __int64 *, __int64))reg_set_curr_country)(v13, a1, v17) )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: WLAN restart - Ignore default CC for phy_id: %u",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "__reg_process_master_chan_list",
      (unsigned int)v16);
    v56 = 0;
    goto LABEL_73;
  }
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: process reg master chan list",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "__reg_process_master_chan_list");
  v35 = *(unsigned __int8 *)(v13 + 91095);
  LODWORD(v36) = *((_DWORD *)a1 + 2);
  v152 = v16;
  if ( *(_BYTE *)(v13 + 91095) )
    v37 = 22;
  else
    v37 = 21;
  if ( !(_DWORD)v36 )
  {
    v147 = v37;
    if ( (unsigned int)v16 <= 2 )
      goto LABEL_19;
LABEL_94:
    __break(0x5512u);
    goto LABEL_95;
  }
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: Set country code failed, status code %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "reg_soc_vars_reset_on_failure",
    (unsigned int)v36);
  if ( (_DWORD)v36 != 1 )
  {
LABEL_72:
    v56 = 16;
    goto LABEL_73;
  }
  v147 = v37;
  if ( (unsigned int)v16 >= 3 )
    goto LABEL_94;
  v38 = (_BYTE *)(v13 + v16);
  v38[91128] = 0;
  v38[91134] = 0;
  v38[91137] = 1;
LABEL_19:
  v1 = v13 + 30364LL * (unsigned int)v16;
  v146 = v35 ^ 1;
  v37 = v1 + 8;
  reg_init_channel_map(*((unsigned int *)a1 + 6));
  v39 = 0;
  v40 = 1;
  do
  {
    v42 = v37 + 36LL * (unsigned __int8)(v40 - 1);
    *(_BYTE *)(v42 + 4) = *(_BYTE *)(channel_map + v39 + 4);
    v43 = *(_DWORD *)(channel_map + v39);
    *(_QWORD *)(v42 + 8) = 0x100000000LL;
    *(_DWORD *)v42 = v43;
    if ( (*(_BYTE *)(v13 + 93256) & 1) == 0 )
      *(_BYTE *)(v42 + 25) = 0;
    v41 = v40++ == 102;
    v39 += 12;
  }
  while ( !v41 );
  *(_BYTE *)(v13 + 91098) = *((_BYTE *)a1 + 12);
  *(_DWORD *)(v1 + 4) = *((_DWORD *)a1 + 7);
  *(_DWORD *)v1 = *((_DWORD *)a1 + 6);
  *(_WORD *)(v1 + 29622) = *((_WORD *)a1 + 8);
  *(_DWORD *)(v1 + 29616) = *((unsigned __int16 *)a1 + 7);
  qdf_mem_copy((void *)(v1 + 29607), (char *)a1 + 18, 3u);
  qdf_mem_copy((void *)(v13 + 91099), (char *)a1 + 18, 3u);
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: set cur_country %.2s",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "__reg_process_master_chan_list",
    v13 + 91099);
  v16 = *((unsigned int *)a1 + 12);
  v52 = (_WORD *)a1[8];
  v149 = *((_DWORD *)a1 + 8);
  if ( !(_DWORD)v16 )
  {
    v54 = 0;
    goto LABEL_47;
  }
  v53 = *((_DWORD *)a1 + 9);
  if ( (_DWORD)v16 == 1 )
  {
    v54 = 0;
    v55 = 0;
LABEL_41:
    v62 = &v52[7 * (unsigned int)v55];
    v63 = v16 - v55;
    v64 = v62 + 2;
    do
    {
      v65 = (unsigned __int16)*v64;
      if ( v65 >= (unsigned __int16)v53 )
        v65 = (unsigned __int16)v53;
      *v64 = v65;
      v64 += 7;
      if ( v54 <= v65 )
        v54 = v65;
      --v63;
    }
    while ( v63 );
    goto LABEL_47;
  }
  v55 = (unsigned int)v16 & 0xFFFFFFFE;
  v54 = 0;
  v57 = 0;
  v58 = v52 + 9;
  v59 = v55;
  do
  {
    v60 = (unsigned __int16)*(v58 - 7);
    v61 = (unsigned __int16)v53;
    if ( v60 >= (unsigned __int16)v53 )
      v60 = (unsigned __int16)v53;
    if ( (unsigned __int16)*v58 < (unsigned int)(unsigned __int16)v53 )
      v61 = (unsigned __int16)*v58;
    *(v58 - 7) = v60;
    if ( v54 <= v60 )
      v54 = v60;
    if ( v57 <= v61 )
      v57 = v61;
    v59 -= 2;
    *v58 = v61;
    v58 += 14;
  }
  while ( v59 );
  if ( v54 <= v57 )
    v54 = v57;
  if ( v55 != v16 )
    goto LABEL_41;
LABEL_47:
  v36 = *((unsigned int *)a1 + 13);
  v35 = *((unsigned __int16 *)a1 + 22);
  v66 = (_WORD *)a1[9];
  v150 = v52;
  v148 = *((_DWORD *)a1 + 10);
  if ( !(_DWORD)v36 )
    goto LABEL_69;
  if ( (_DWORD)v36 == 1 )
  {
    v67 = 0;
LABEL_63:
    v73 = &v66[7 * (unsigned int)v67];
    v74 = v36 - v67;
    v75 = v73 + 2;
    do
    {
      v76 = (unsigned __int16)*v75;
      if ( v76 >= v35 )
        v76 = v35;
      *v75 = v76;
      v75 += 7;
      if ( v54 <= v76 )
        v54 = v76;
      --v74;
    }
    while ( v74 );
    goto LABEL_69;
  }
  v67 = (unsigned int)v36 & 0xFFFFFFFE;
  v68 = v66 + 9;
  v69 = v54;
  v70 = v67;
  do
  {
    v71 = (unsigned __int16)*(v68 - 7);
    v72 = (unsigned __int16)*v68;
    if ( v71 >= v35 )
      v71 = v35;
    if ( v72 >= v35 )
      v72 = v35;
    *(v68 - 7) = v71;
    if ( v54 <= v71 )
      v54 = v71;
    if ( v69 <= v72 )
      v69 = v72;
    v70 -= 2;
    *v68 = v72;
    v68 += 14;
  }
  while ( v70 );
  if ( v54 <= v69 )
    v54 = v69;
  if ( v67 != v36 )
    goto LABEL_63;
LABEL_69:
  *(_DWORD *)(v13 + 93972) = v54;
  v151 = (char *)v66;
  *(_WORD *)(v1 + 30362) = *((_DWORD *)a1 + 11);
  qdf_mem_set((void *)(v1 + 29624), 0x2D0u, 0);
  *(_BYTE *)(v1 + 29632) = v36 + v16;
  if ( (unsigned __int8)(v36 + v16) >= 0xBu )
  {
    v18 = "%s: number of reg rules exceeds limit";
    goto LABEL_71;
  }
  if ( !((_BYTE)v36 + (_BYTE)v16) )
  {
LABEL_95:
    v145 = v17;
    v105 = v151;
    if ( !(_DWORD)v36 )
      goto LABEL_121;
    goto LABEL_99;
  }
  if ( !(_DWORD)v16 )
  {
    if ( !(_DWORD)v36 )
      goto LABEL_125;
    goto LABEL_98;
  }
  qdf_mem_copy((void *)(v1 + 29634), v150, (unsigned int)(14 * v16));
  if ( (_DWORD)v36 )
  {
    if ( (unsigned int)v16 > 0xA )
      goto LABEL_94;
LABEL_98:
    v145 = v17;
    v105 = v151;
    qdf_mem_copy((void *)(v1 + 14LL * (unsigned int)v16 + 29634), v151, (unsigned int)(14 * v36));
LABEL_99:
    v106 = (unsigned int)(v36 - 1);
    if ( (_DWORD)v36 != 1 )
    {
      v107 = (__int16 *)(v105 + 18);
      do
      {
        v109 = (unsigned __int16)*(v107 - 8);
        if ( v109 == (unsigned __int16)*(v107 - 2) )
        {
          v110 = (unsigned __int16)(*(v107 - 1) - v109) + (unsigned __int16)(v109 - *(v107 - 9));
          if ( v110 >= v35 )
            v110 = v35;
          if ( v110 > 0x13F )
          {
            v108 = 320;
          }
          else if ( v110 > 0x9F )
          {
            v108 = 160;
          }
          else if ( v110 > 0x4F )
          {
            v108 = 80;
          }
          else if ( v110 > 0x27 )
          {
            v108 = 40;
          }
          else if ( v110 > 0x13 )
          {
            v108 = 20;
          }
          else if ( v110 > 9 )
          {
            v108 = 10;
          }
          else if ( v110 >= 5 )
          {
            v108 = 5;
          }
          else
          {
            v108 = 0;
          }
          *(v107 - 7) = v108;
          *v107 = v108;
        }
        --v106;
        v107 += 7;
      }
      while ( v106 );
    }
LABEL_121:
    v17 = v145;
    if ( !(_DWORD)v16 )
      goto LABEL_123;
  }
  reg_populate_band_channels(0, 13, v150, (unsigned int)v16, v149, v37);
LABEL_123:
  if ( (_DWORD)v36 )
  {
    reg_populate_band_channels(14, 41, v151, (unsigned int)v36, v148, v37);
    reg_populate_band_channels(42, 101, v151, (unsigned int)v36, v148, v37);
  }
LABEL_125:
  *(_BYTE *)(v13 + v152 + 91092) = 1;
  v56 = reg_send_ctl_info(v13, a1, v17);
  if ( v56 )
    goto LABEL_73;
  if ( *(_BYTE *)(v13 + 91128 + v152) == 1 )
  {
    *(_BYTE *)(v13 + 91128 + v152) = 0;
    *(_DWORD *)(v13 + 91112) = 4;
    *(_BYTE *)(v13 + 91165) = 1;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: new user country is set",
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      "__reg_process_master_chan_list");
    reg_run_11d_state_machine(v3);
    v119 = v147;
    goto LABEL_136;
  }
  v119 = v147;
  if ( *(_BYTE *)(v13 + 91131 + v152) == 1 )
  {
    *(_BYTE *)(v13 + 91131 + v152) = 0;
    *(_DWORD *)(v13 + 91112) = 4;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: new init country is set",
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      "__reg_process_master_chan_list");
    goto LABEL_136;
  }
  if ( *(_BYTE *)(v13 + 91134 + v152) == 1 )
  {
    *(_BYTE *)(v13 + 91134 + v152) = 0;
    v120 = 5;
LABEL_134:
    *(_DWORD *)(v13 + 91112) = v120;
    *(_BYTE *)(v13 + 91165) = 0;
LABEL_135:
    reg_run_11d_state_machine(v3);
    goto LABEL_136;
  }
  if ( *(_BYTE *)(v13 + 91137 + v152) == 1 )
  {
    *(_BYTE *)(v13 + 91137 + v152) = 0;
    v120 = 2;
    goto LABEL_134;
  }
  if ( !*(_DWORD *)(v13 + 91112) && *(unsigned __int8 *)(v13 + 91098) == (unsigned __int8)(v152 + 1) )
    *(_DWORD *)(v13 + 91112) = 3;
  qdf_mem_copy((void *)(v1 + 29604), (char *)a1 + 18, 3u);
  *(_WORD *)(v1 + 29612) = *((_WORD *)a1 + 8);
  *(_WORD *)(v1 + 29610) = *((_WORD *)a1 + 7);
  if ( *(_DWORD *)(v13 + 91112) == 3 )
  {
    qdf_mem_copy((void *)(v13 + 91102), (char *)a1 + 18, 3u);
    *(_WORD *)(v13 + 91106) = *((_WORD *)a1 + 8);
    *(_WORD *)(v13 + 91108) = *((_WORD *)a1 + 7);
    if ( (reg_is_world_alpha2((char *)a1 + 18) & 1) != 0 )
    {
      *(_DWORD *)(v13 + 91112) = 2;
      goto LABEL_135;
    }
  }
LABEL_136:
  v121 = *((_DWORD *)a1 + 88);
  if ( v121 )
    qdf_mem_copy((void *)(v13 + 93960), (const void *)a1[43], (unsigned int)(4 * v121));
  pdev_by_id = wlan_objmgr_get_pdev_by_id(v3, v153[0], v119);
  if ( !pdev_by_id )
  {
    v56 = 0;
    goto LABEL_73;
  }
  v123 = pdev_by_id;
  v155 = v146;
  v124 = reg_get_psoc_tx_ops(v3);
  if ( v124 )
  {
    v134 = v124;
    pdev_obj = reg_get_pdev_obj(v123);
    if ( pdev_obj )
    {
      v144 = pdev_obj;
      reg_propagate_mas_chan_list_to_pdev(v3, v123, &v155);
      v125 = *(void (__fastcall **)(__int64, __int64))(v134 + 48);
      if ( v125 )
      {
        if ( *((_DWORD *)v125 - 1) != -145496263 )
          __break(0x8228u);
        v125(v123, v144);
      }
      v56 = 0;
      goto LABEL_149;
    }
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      "reg_propagate_mas_chan_list_and_fill_legacy_list");
  }
  v56 = 16;
LABEL_149:
  wlan_objmgr_pdev_release_ref(v123, v119, (unsigned int *)v125, v126, v127, v128, v129, v130, v131, v132, v133);
LABEL_73:
  v77 = *a1;
  v78 = reg_get_psoc_tx_ops(*a1);
  if ( !v78 )
  {
LABEL_88:
    v56 = 16;
    goto LABEL_89;
  }
  if ( !*(_QWORD *)(v78 + 32) )
    goto LABEL_89;
  v79 = *(void (__fastcall **)(__int64, __int64, char *))(v78 + 136);
  v80 = *((unsigned __int8 *)a1 + 13);
  v81 = v78;
  v82 = *((unsigned __int8 *)a1 + 21);
  v154[0] = 0;
  if ( v79 )
  {
    if ( *((_DWORD *)v79 - 1) != 13449260 )
      __break(0x8228u);
    v79(v77, v80, v154);
    LOBYTE(v80) = v154[0];
  }
  else
  {
    v154[0] = v80;
  }
  if ( v82 )
    v83 = 22;
  else
    v83 = 21;
  v84 = wlan_objmgr_get_pdev_by_id(v77, v80, v83);
  if ( !v84 )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev obj is NULL",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "reg_process_master_chan_list");
    goto LABEL_88;
  }
  v93 = *(double (**)(void))(v81 + 32);
  v94 = v84;
  if ( *((_DWORD *)v93 - 1) != -1127411852 )
    __break(0x8228u);
  v95 = v93();
  wlan_objmgr_pdev_release_ref(v94, v83, v96, v95, v97, v98, v99, v100, v101, v102, v103);
LABEL_89:
  _ReadStatusReg(SP_EL0);
  return v56;
}
