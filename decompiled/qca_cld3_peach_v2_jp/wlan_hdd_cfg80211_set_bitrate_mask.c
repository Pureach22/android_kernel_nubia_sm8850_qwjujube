__int64 __fastcall wlan_hdd_cfg80211_set_bitrate_mask(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int updated; // w24
  __int64 conparam; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x10
  unsigned int v37; // w25
  char v38; // w9
  __int64 v39; // x4
  const char *v40; // x2
  __int64 v41; // x28
  int v42; // w8
  unsigned int v43; // w8
  unsigned int v44; // w30
  unsigned int v45; // w24
  unsigned int v46; // w26
  unsigned int v47; // w27
  unsigned int v48; // w25
  unsigned int v49; // w22
  unsigned int v50; // w7
  unsigned int v51; // w23
  unsigned int v52; // w6
  unsigned int v53; // w8
  unsigned int v54; // w13
  unsigned int v55; // w8
  unsigned int v56; // w9
  unsigned int v57; // w14
  unsigned int v58; // w11
  unsigned int v59; // w15
  unsigned int v60; // w8
  unsigned int v61; // w0
  unsigned int v62; // w17
  unsigned int v63; // w16
  unsigned int v64; // w8
  unsigned int v65; // w9
  unsigned int v66; // w12
  unsigned int v67; // w8
  unsigned int v68; // w9
  unsigned int v69; // w10
  unsigned int v70; // w11
  unsigned int v71; // w8
  unsigned int v72; // w10
  unsigned int v73; // w9
  unsigned int v74; // w1
  int v75; // w8
  unsigned int v76; // w10
  unsigned int v77; // w1
  unsigned int v78; // w8
  unsigned int v79; // w9
  unsigned int v80; // w9
  unsigned int v81; // w19
  unsigned int v82; // w8
  unsigned int v83; // w21
  int v84; // w30
  unsigned int v85; // w20
  int v86; // w8
  char v87; // w2
  int v88; // w25
  int v89; // w22
  int v90; // w27
  int v91; // w6
  int v92; // w5
  int v93; // w2
  int v94; // w7
  int v95; // w10
  int v96; // w4
  unsigned int v97; // w3
  unsigned int v98; // w13
  int v99; // w11
  int v100; // w14
  unsigned int v101; // w15
  unsigned int v102; // w9
  int v103; // w24
  unsigned int v104; // w23
  int v105; // w13
  unsigned int v106; // w11
  int v107; // w20
  int v108; // w21
  unsigned int v109; // w26
  unsigned int v110; // w17
  int v111; // w0
  unsigned int v112; // w19
  int v113; // w16
  unsigned int v114; // w12
  int v115; // w1
  int v116; // w13
  unsigned int v117; // w9
  __int64 v118; // x1
  __int64 v119; // x0
  unsigned int v120; // w8
  __int64 v121; // x2
  __int64 v122; // x20
  __int64 v123; // x21
  unsigned int v124; // w19
  unsigned int v125; // w8
  unsigned int v126; // w0
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  unsigned int v135; // w22
  int v136; // w8
  unsigned int v137; // w9
  unsigned int v138; // w10
  unsigned int v139; // w8
  __int64 v140; // x2
  unsigned int v141; // w8
  __int64 v142; // x0
  unsigned int v143; // w8
  unsigned int v144; // w9
  unsigned int v145; // w9
  unsigned int v146; // w9
  unsigned int v147; // w9
  unsigned int v148; // w9
  unsigned int v149; // w9
  unsigned int v150; // w9
  unsigned int v151; // w9
  unsigned int v152; // w9
  __int64 v153; // [xsp+0h] [xbp-F0h]
  __int64 v154; // [xsp+8h] [xbp-E8h]
  __int64 v155; // [xsp+10h] [xbp-E0h]
  unsigned int v156; // [xsp+50h] [xbp-A0h]
  unsigned int v157; // [xsp+6Ch] [xbp-84h]
  unsigned int v158; // [xsp+7Ch] [xbp-74h]
  __int64 v159; // [xsp+A0h] [xbp-50h]
  unsigned int v160; // [xsp+B8h] [xbp-38h]
  unsigned int v161; // [xsp+BCh] [xbp-34h]
  unsigned int v162; // [xsp+C0h] [xbp-30h]
  int v163; // [xsp+C0h] [xbp-30h]
  unsigned int v164; // [xsp+C4h] [xbp-2Ch]
  __int64 v165; // [xsp+C8h] [xbp-28h]
  char v166; // [xsp+D0h] [xbp-20h]
  _QWORD v167[3]; // [xsp+D8h] [xbp-18h] BYREF

  v167[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v167[0] = 0;
  v8 = _osif_vdev_sync_op_start(a2, v167, "wlan_hdd_cfg80211_set_bitrate_mask");
  if ( (_DWORD)v8 )
  {
    updated = v8;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev_sync_op_start failure",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_hdd_cfg80211_set_bitrate_mask");
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return updated;
  }
  if ( a1 )
  {
    conparam = hdd_get_conparam(v8);
    if ( (_DWORD)conparam == 5 || (unsigned int)hdd_get_conparam(conparam) == 4 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in mode",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_set_bitrate_mask");
      updated = -22;
LABEL_7:
      _osif_vdev_sync_op_stop(v167[0], "wlan_hdd_cfg80211_set_bitrate_mask");
      goto LABEL_8;
    }
    updated = _hdd_validate_adapter(a2 + 2688, "__wlan_hdd_cfg80211_set_bitrate_mask");
    if ( updated )
      goto LABEL_7;
    updated = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_set_bitrate_mask");
    if ( updated )
      goto LABEL_7;
    v36 = 0;
    v37 = -1;
    v38 = 1;
    v155 = 0;
    v159 = a5;
    v153 = a1;
    v154 = a2;
    while ( 1 )
    {
      v165 = v36;
      v166 = v38;
      v41 = a5 + 60 * v36;
      v160 = updated;
      v161 = v37;
      v42 = *(_DWORD *)v41 & 0x55555555;
      v156 = *(_DWORD *)v41;
      v43 = ((((((((*(_DWORD *)v41 >> 1) & 0x55555555u) + v42) >> 2) & 0x33333333)
             + ((((*(_DWORD *)v41 >> 1) & 0x55555555) + v42) & 0x33333333)) >> 4)
           & 0x7070707)
          + (((((((*(_DWORD *)v41 >> 1) & 0x55555555u) + v42) >> 2) & 0x33333333)
            + ((((*(_DWORD *)v41 >> 1) & 0x55555555) + v42) & 0x33333333))
           & 0x7070707);
      v44 = (((*(unsigned __int8 *)(v41 + 4) - ((*(unsigned __int8 *)(v41 + 4) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 4) - ((*(unsigned __int8 *)(v41 + 4) >> 1) & 0x55555555)) & 0x33);
      v45 = ((((v43 >> 8) & 0xF000F) + (v43 & 0xF000F)) & 0x1F) + ((((v43 >> 8) & 0xF000F) + (v43 & 0xF000F)) >> 16);
      v46 = (((*(unsigned __int8 *)(v41 + 5) - ((*(unsigned __int8 *)(v41 + 5) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 5) - ((*(unsigned __int8 *)(v41 + 5) >> 1) & 0x55555555)) & 0x33);
      v47 = (((*(unsigned __int8 *)(v41 + 6) - ((*(unsigned __int8 *)(v41 + 6) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 6) - ((*(unsigned __int8 *)(v41 + 6) >> 1) & 0x55555555)) & 0x33);
      v48 = (((*(unsigned __int8 *)(v41 + 10) - ((*(unsigned __int8 *)(v41 + 10) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 10) - ((*(unsigned __int8 *)(v41 + 10) >> 1) & 0x55555555)) & 0x33);
      v49 = (((*(unsigned __int8 *)(v41 + 7) - ((*(unsigned __int8 *)(v41 + 7) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 7) - ((*(unsigned __int8 *)(v41 + 7) >> 1) & 0x55555555)) & 0x33);
      v50 = (((*(unsigned __int8 *)(v41 + 8) - ((*(unsigned __int8 *)(v41 + 8) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 8) - ((*(unsigned __int8 *)(v41 + 8) >> 1) & 0x55555555)) & 0x33);
      v164 = (((*(unsigned __int8 *)(v41 + 11) - ((*(unsigned __int8 *)(v41 + 11) >> 1) & 0x55555555u)) >> 2) & 0x33)
           + ((*(unsigned __int8 *)(v41 + 11) - ((*(unsigned __int8 *)(v41 + 11) >> 1) & 0x55555555)) & 0x33);
      v51 = (((*(unsigned __int8 *)(v41 + 9) - ((*(unsigned __int8 *)(v41 + 9) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 9) - ((*(unsigned __int8 *)(v41 + 9) >> 1) & 0x55555555)) & 0x33);
      v162 = (((*(unsigned __int8 *)(v41 + 12) - ((*(unsigned __int8 *)(v41 + 12) >> 1) & 0x55555555u)) >> 2) & 0x33)
           + ((*(unsigned __int8 *)(v41 + 12) - ((*(unsigned __int8 *)(v41 + 12) >> 1) & 0x55555555)) & 0x33);
      v52 = (((*(unsigned __int8 *)(v41 + 13) - ((*(unsigned __int8 *)(v41 + 13) >> 1) & 0x55555555u)) >> 2) & 0x33)
          + ((*(unsigned __int8 *)(v41 + 13) - ((*(unsigned __int8 *)(v41 + 13) >> 1) & 0x55555555)) & 0x33);
      v53 = (((((*(unsigned __int16 *)(v41 + 14) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 14) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 14) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 14) & 0x5555)) & 0x33333333);
      v157 = *(unsigned __int16 *)(v41 + 20);
      v54 = ((v53 >> 4) & 0xFFFFFF0F) + (v53 & 0xF0F0F0F);
      v55 = (((((*(unsigned __int16 *)(v41 + 16) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 16) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 16) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 16) & 0x5555)) & 0x33333333);
      v56 = (((((*(unsigned __int16 *)(v41 + 18) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 18) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 18) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 18) & 0x5555)) & 0x33333333);
      v57 = ((v55 >> 4) & 0xFFFFFF0F) + (v55 & 0xF0F0F0F);
      v58 = (((((*(unsigned __int16 *)(v41 + 22) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 22) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 22) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 22) & 0x5555)) & 0x33333333);
      v59 = ((v56 >> 4) & 0xFFFFFF0F) + (v56 & 0xF0F0F0F);
      v60 = ((*(unsigned __int16 *)(v41 + 24) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 24) & 0x5555);
      v61 = ((((((((v157 >> 1) & 0x55555555) + (v157 & 0x55555555)) >> 2) & 0x33333333)
             + ((((v157 >> 1) & 0x55555555) + (v157 & 0x55555555)) & 0x33333333)) >> 4)
           & 0xFFFFFF0F)
          + (((((((v157 >> 1) & 0x55555555) + (v157 & 0x55555555)) >> 2) & 0x33333333)
            + ((((v157 >> 1) & 0x55555555) + (v157 & 0x55555555)) & 0x33333333))
           & 0xF0F0F0F);
      v62 = ((v58 >> 4) & 0xFFFFFF0F) + (v58 & 0xF0F0F0F);
      v63 = (((((v60 >> 2) & 0x33333333) + (v60 & 0x33333333)) >> 4) & 0xFFFFFF0F)
          + ((((v60 >> 2) & 0x33333333) + (v60 & 0x33333333)) & 0xF0F0F0F);
      v64 = (((((*(unsigned __int16 *)(v41 + 26) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 26) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 26) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 26) & 0x5555)) & 0x33333333);
      v65 = (((((*(unsigned __int16 *)(v41 + 30) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 30) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 30) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 30) & 0x5555)) & 0x33333333);
      v66 = ((v64 >> 4) & 0xFFFFFF0F) + (v64 & 0xF0F0F0F);
      v67 = ((v65 >> 4) & 0xFFFFFF0F) + (v65 & 0xF0F0F0F);
      v68 = (((((*(unsigned __int16 *)(v41 + 32) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 32) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 32) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 32) & 0x5555)) & 0x33333333);
      v69 = ((*(unsigned __int16 *)(v41 + 34) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 34) & 0x5555);
      v70 = *(unsigned __int16 *)(v41 + 28);
      v71 = ((((v68 >> 4) & 0xFFFFFF0F) + (v68 & 0xF0F0F0F)) & 0xF)
          + (v67 & 0xF)
          + (v67 >> 8)
          + ((((v68 >> 4) & 0xFFFFFF0F) + (v68 & 0xF0F0F0F)) >> 8);
      v72 = (((((v69 >> 2) & 0x33333333) + (v69 & 0x33333333)) >> 4) & 0xFFFFFF0F)
          + ((((v69 >> 2) & 0x33333333) + (v69 & 0x33333333)) & 0xF0F0F0F);
      v73 = (((((*(unsigned __int16 *)(v41 + 36) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 36) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 36) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 36) & 0x5555)) & 0x33333333);
      v74 = ((*(unsigned __int16 *)(v41 + 38) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 38) & 0x5555);
      v75 = (v72 & 0xF) + v71 + (v72 >> 8);
      v76 = ((v74 >> 2) & 0x33333333) + (v74 & 0x33333333);
      v77 = ((((((((v70 >> 1) & 0x55555555) + (v70 & 0x55555555)) >> 2) & 0x33333333)
             + ((((v70 >> 1) & 0x55555555) + (v70 & 0x55555555)) & 0x33333333)) >> 4)
           & 0xFFFFFF0F)
          + (((((((v70 >> 1) & 0x55555555) + (v70 & 0x55555555)) >> 2) & 0x33333333)
            + ((((v70 >> 1) & 0x55555555) + (v70 & 0x55555555)) & 0x33333333))
           & 0xF0F0F0F);
      v78 = ((((v73 >> 4) & 0xFFFFFF0F) + (v73 & 0xF0F0F0F)) & 0xF)
          + v75
          + ((((v73 >> 4) & 0xFFFFFF0F) + (v73 & 0xF0F0F0F)) >> 8);
      v79 = ((*(unsigned __int16 *)(v41 + 40) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 40) & 0x5555);
      v80 = (((((v79 >> 2) & 0x33333333) + (v79 & 0x33333333)) >> 4) & 0xFFFFFF0F)
          + ((((v79 >> 2) & 0x33333333) + (v79 & 0x33333333)) & 0xF0F0F0F);
      v81 = (v80 & 0xF)
          + ((((v76 >> 4) & 0xFFFFFF0F) + (v76 & 0xF0F0F0F)) & 0xF)
          + v78
          + ((((v76 >> 4) & 0xFFFFFF0F) + (v76 & 0xF0F0F0F)) >> 8)
          + (v80 >> 8);
      v82 = (((((*(unsigned __int16 *)(v41 + 42) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 42) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 42) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 42) & 0x5555)) & 0x33333333);
      LOBYTE(v76) = v44 + (v44 >> 4);
      v83 = (((((*(unsigned __int16 *)(v41 + 44) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 44) & 0x5555u)) >> 2)
           & 0x33333333)
          + ((((*(unsigned __int16 *)(v41 + 44) >> 1) & 0x55555555) + (*(_WORD *)(v41 + 44) & 0x5555)) & 0x33333333);
      v84 = ((_BYTE)v49 + (unsigned __int8)(v49 >> 4)) & 0xF;
      v85 = ((v82 >> 4) & 0xFFFFFF0F) + (v82 & 0xF0F0F0F);
      v86 = ((_BYTE)v47 + (unsigned __int8)(v47 >> 4)) & 0xF;
      v87 = v48 + (v48 >> 4);
      v88 = ((_BYTE)v50 + (unsigned __int8)(v50 >> 4)) & 0xF;
      LOBYTE(v80) = v52 + (v52 >> 4);
      v89 = v76 & 0xF;
      v90 = ((_BYTE)v46 + (unsigned __int8)(v46 >> 4)) & 0xF;
      v91 = ((_BYTE)v162 + (unsigned __int8)(v162 >> 4)) & 0xF;
      v92 = v80 & 0xF;
      v93 = v87 & 0xF;
      v94 = ((_BYTE)v164 + (unsigned __int8)(v164 >> 4)) & 0xF;
      v95 = ((_BYTE)v51 + (unsigned __int8)(v51 >> 4)) & 0xF;
      v96 = v54 & 0xF;
      v97 = v54 >> 8;
      v98 = v57 >> 8;
      v99 = v57 & 0xF;
      v100 = v59 & 0xF;
      v101 = v59 >> 8;
      v102 = v45;
      v163 = v99;
      v103 = v90 + v89 + v86 + v84 + v88 + v95 + v45 + v93 + v94 + v91 + v92 + v97 + v96 + v98 + v99 + v101 + v100;
      v104 = v61 >> 8;
      v158 = v98;
      v105 = (v85 & 0xF) + v81 + (v85 >> 8);
      v106 = ((v83 >> 4) & 0xFFFFFF0F) + (v83 & 0xF0F0F0F);
      v107 = v61 & 0xF;
      v108 = v62 & 0xF;
      v109 = v62 >> 8;
      v110 = v66 >> 8;
      v111 = v63 & 0xF;
      v112 = v63 >> 8;
      v113 = v66 & 0xF;
      v114 = v77 >> 8;
      v115 = v77 & 0xF;
      if ( !(v103
           + v104
           + v107
           + v109
           + v108
           + v112
           + v111
           + v110
           + v113
           + v114
           + v115
           + (v106 & 0xF)
           + v105
           + (v106 >> 8)) )
      {
        v39 = v165;
        v40 = "%s: Multiple bitrate set not supported for band %u";
LABEL_13:
        qdf_trace_msg(
          0x33u,
          2u,
          v40,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_set_bitrate_mask",
          v39,
          v153,
          v154);
        a5 = v159;
        v37 = v161;
        updated = -22;
        goto LABEL_14;
      }
      v116 = v96;
      v39 = v165;
      if ( !v102 )
      {
        v40 = "%s: Legacy bit rate setting not supported for band %u";
        goto LABEL_13;
      }
      if ( v89 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 4);
        v118 = 0;
        goto LABEL_38;
      }
      if ( v90 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 5);
        v118 = 1;
        goto LABEL_38;
      }
      if ( v86 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 6);
        v118 = 2;
        goto LABEL_38;
      }
      if ( v84 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 7);
        v118 = 3;
        goto LABEL_38;
      }
      if ( v88 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 8);
        v118 = 4;
        goto LABEL_38;
      }
      if ( v95 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 9);
        v118 = 5;
        goto LABEL_38;
      }
      if ( v93 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 10);
        v118 = 6;
        goto LABEL_38;
      }
      if ( v94 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 11);
        v118 = 7;
        goto LABEL_38;
      }
      if ( v91 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 12);
        v118 = 8;
        goto LABEL_38;
      }
      if ( v92 == 1 )
      {
        v117 = *(unsigned __int8 *)(v41 + 13);
        v118 = 9;
LABEL_38:
        v119 = 2;
        v120 = __clz(__rbit32(v117));
        if ( v117 )
          v121 = v120;
        else
          v121 = 0xFFFFFFFFLL;
        goto LABEL_41;
      }
      if ( v116 + v97 == 1 )
      {
        v123 = v153;
        v122 = v154;
        v137 = 0;
        v124 = HIDWORD(v155);
        updated = v160;
        v138 = *(unsigned __int16 *)(v41 + 14);
        goto LABEL_73;
      }
      if ( v163 + v158 == 1 )
      {
        v138 = *(unsigned __int16 *)(v41 + 16);
        v137 = 1;
        goto LABEL_72;
      }
      if ( v100 + v101 == 1 )
      {
        v138 = *(unsigned __int16 *)(v41 + 18);
        v137 = 2;
        goto LABEL_72;
      }
      if ( v107 + v104 == 1 )
      {
        v138 = *(unsigned __int16 *)(v41 + 20);
        v137 = 3;
        goto LABEL_72;
      }
      if ( v108 + v109 == 1 )
      {
        v138 = *(unsigned __int16 *)(v41 + 22);
        v137 = 4;
        goto LABEL_72;
      }
      if ( v111 + v112 == 1 )
      {
        v138 = *(unsigned __int16 *)(v41 + 24);
        v137 = 5;
        goto LABEL_72;
      }
      if ( v113 + v110 == 1 )
      {
        v138 = *(unsigned __int16 *)(v41 + 26);
        v137 = 6;
        goto LABEL_72;
      }
      if ( v115 + v114 == 1 )
      {
        v138 = *(unsigned __int16 *)(v41 + 28);
        v137 = 7;
LABEL_72:
        v123 = v153;
        v122 = v154;
        v124 = HIDWORD(v155);
        updated = v160;
LABEL_73:
        v139 = __clz(__rbit32(v138));
        if ( v138 )
          v140 = v139;
        else
          v140 = 0xFFFFFFFFLL;
        v37 = hdd_assemble_rate_code(3, v137, v140);
        goto LABEL_42;
      }
      if ( v102 == 1 )
      {
        v141 = __clz(__rbit32(v156));
        if ( !v156 )
          v141 = -1;
        if ( (v166 & 1) == 0 )
          v141 += 4;
        if ( v141 >= 4 )
        {
          if ( (unsigned __int8)v141 > 0xBu )
            goto LABEL_88;
          v142 = 0;
        }
        else
        {
          v142 = 1;
        }
        if ( (unsigned __int8)v141 > 0xBu )
          goto LABEL_108;
        v161 = hdd_assemble_rate_code(v142, 0, hdd_legacy_rates[12 * (unsigned __int8)v141 + 6]);
      }
LABEL_88:
      v143 = *(unsigned __int16 *)(v41 + 30);
      v144 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v144 >> 4) & 0xFFFFFF0F) + (v144 & 0xF0F0F0F)) & 0xF)
         + ((((v144 >> 4) & 0xFFFFFF0F) + (v144 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 0;
LABEL_104:
        v119 = 4;
        v152 = __clz(__rbit32(v143));
        if ( v143 )
          v121 = v152;
        else
          v121 = 0xFFFFFFFFLL;
LABEL_41:
        v123 = v153;
        v122 = v154;
        v37 = hdd_assemble_rate_code(v119, v118, v121);
        v124 = HIDWORD(v155);
        updated = v160;
        goto LABEL_42;
      }
      v143 = *(unsigned __int16 *)(v41 + 32);
      v145 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v145 >> 4) & 0xFFFFFF0F) + (v145 & 0xF0F0F0F)) & 0xF)
         + ((((v145 >> 4) & 0xFFFFFF0F) + (v145 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 1;
        goto LABEL_104;
      }
      v143 = *(unsigned __int16 *)(v41 + 34);
      v146 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v146 >> 4) & 0xFFFFFF0F) + (v146 & 0xF0F0F0F)) & 0xF)
         + ((((v146 >> 4) & 0xFFFFFF0F) + (v146 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 2;
        goto LABEL_104;
      }
      v143 = *(unsigned __int16 *)(v41 + 36);
      v147 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v147 >> 4) & 0xFFFFFF0F) + (v147 & 0xF0F0F0F)) & 0xF)
         + ((((v147 >> 4) & 0xFFFFFF0F) + (v147 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 3;
        goto LABEL_104;
      }
      v143 = *(unsigned __int16 *)(v41 + 38);
      v148 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v148 >> 4) & 0xFFFFFF0F) + (v148 & 0xF0F0F0F)) & 0xF)
         + ((((v148 >> 4) & 0xFFFFFF0F) + (v148 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 4;
        goto LABEL_104;
      }
      v143 = *(unsigned __int16 *)(v41 + 40);
      v149 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v149 >> 4) & 0xFFFFFF0F) + (v149 & 0xF0F0F0F)) & 0xF)
         + ((((v149 >> 4) & 0xFFFFFF0F) + (v149 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 5;
        goto LABEL_104;
      }
      v143 = *(unsigned __int16 *)(v41 + 42);
      v150 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v150 >> 4) & 0xFFFFFF0F) + (v150 & 0xF0F0F0F)) & 0xF)
         + ((((v150 >> 4) & 0xFFFFFF0F) + (v150 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 6;
        goto LABEL_104;
      }
      v123 = v153;
      v122 = v154;
      updated = v160;
      v37 = v161;
      v143 = *(unsigned __int16 *)(v41 + 44);
      v124 = HIDWORD(v155);
      v151 = (((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) >> 2) & 0x33333333)
           + ((((v143 >> 1) & 0x55555555) + (v143 & 0x55555555)) & 0x33333333);
      if ( ((((v151 >> 4) & 0xFFFFFF0F) + (v151 & 0xF0F0F0F)) & 0xF)
         + ((((v151 >> 4) & 0xFFFFFF0F) + (v151 & 0xF0F0F0F)) >> 8) == 1 )
      {
        v118 = 7;
        goto LABEL_104;
      }
LABEL_42:
      if ( v37 != -1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: wmi_vdev_param_fixed_rate val %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_set_bitrate_mask",
          v37);
        updated = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(v122 + 55512) + 8LL), 27, v37, 1);
        if ( updated )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to set firmware, errno %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_set_bitrate_mask",
            updated);
      }
      v125 = *(_DWORD *)(v41 + 52);
      if ( v125 >= 3 )
      {
        if ( !(_BYTE)v124 )
        {
          v136 = *(_DWORD *)(v41 + 48);
          if ( v136 )
          {
            LODWORD(v155) = v136 != 1;
            updated = sme_update_ht_config(
                        *(_QWORD *)(v123 + 1552),
                        *(unsigned __int8 *)(*(_QWORD *)(v122 + 55512) + 8LL),
                        5);
            if ( updated )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: cfg set failed, value %d status %d",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                "__wlan_hdd_cfg80211_set_bitrate_mask",
                *(unsigned int *)(v41 + 48),
                updated);
          }
          a5 = v159;
          HIDWORD(v155) = 0;
          goto LABEL_14;
        }
      }
      else
      {
        v124 = v125 + 9;
        LODWORD(v155) = (unsigned __int8)*(_DWORD *)(v41 + 52) + 1;
      }
      v126 = sme_set_auto_rate_he_sgi(
               *(_QWORD *)(v123 + 1552),
               *(unsigned __int8 *)(*(_QWORD *)(v122 + 55512) + 8LL),
               v124);
      v135 = v124;
      a5 = v159;
      if ( v126 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: auto rate GI %d set fail, status %d",
          v127,
          v128,
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          "__wlan_hdd_cfg80211_set_bitrate_mask",
          (unsigned __int8)v135,
          v126);
      HIDWORD(v155) = v135;
      updated = sme_update_ht_config(*(_QWORD *)(v123 + 1552), *(unsigned __int8 *)(*(_QWORD *)(v122 + 55512) + 8LL), 5);
      if ( updated )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: cfg set failed, value %d status %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_set_bitrate_mask",
          (unsigned int)v155,
          updated);
LABEL_14:
      v38 = 0;
      v36 = 1;
      if ( (v166 & 1) == 0 )
        goto LABEL_7;
    }
  }
  __break(0x800u);
LABEL_108:
  __break(1u);
  return wlan_hdd_cfg80211_set_pmksa();
}
