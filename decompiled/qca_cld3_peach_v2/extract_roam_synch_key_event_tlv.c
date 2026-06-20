__int64 __fastcall extract_roam_synch_key_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11,
        void **a12,
        _BYTE *a13,
        unsigned __int8 *a14)
{
  __int64 v14; // x22
  unsigned int v15; // w20
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _BYTE *v28; // x23
  unsigned int v29; // w21
  _BYTE *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x8
  __int64 v44; // x10
  __int64 v45; // x11
  __int64 v46; // x8
  __int64 v47; // x10
  __int64 v48; // x11
  __int64 v49; // x8
  __int64 v50; // x10
  __int64 v51; // x11
  __int64 v52; // x8
  __int64 v53; // x10
  __int64 v54; // x11
  __int64 v55; // x8
  __int64 v56; // x10
  __int64 v57; // x11
  __int64 v58; // x8
  __int64 v59; // x10
  __int64 v60; // x11
  unsigned int v61; // w27
  unsigned __int8 *v62; // x28
  int v63; // w4
  unsigned int v64; // w8
  int v65; // w8
  __int64 v66; // x10
  int v67; // w8
  int v68; // w8
  int v69; // w9
  __int16 v70; // w8
  int v71; // w8
  int v72; // w0
  int v73; // w1
  int v74; // w2
  __int64 v75; // x22
  __int64 v76; // x4
  __int64 v77; // x5
  __int64 v78; // x6
  __int64 v79; // x7
  unsigned __int64 v80; // x9
  unsigned __int16 *v81; // x27
  unsigned __int64 v82; // x9
  unsigned __int16 *v83; // x27
  unsigned __int64 v84; // x9
  char *v85; // x26
  int v86; // w9
  int v87; // w8
  int v88; // w8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x6
  __int64 v98; // x7
  int v99; // w8
  int v100; // w9
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x6
  __int64 v110; // x7
  int v111; // w8
  int v112; // w9
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  __int64 v121; // x6
  __int64 v122; // x7
  int v123; // w8
  int v124; // w9
  unsigned __int16 v125; // w10
  __int64 v126; // x5
  char *v127; // x27
  unsigned __int8 v128; // w22
  unsigned int v129; // w26
  unsigned __int64 v130; // x9
  unsigned __int16 v131; // w10
  __int64 v132; // x5
  char *v133; // x27
  unsigned __int8 v134; // w22
  unsigned int v135; // w26
  __int64 v136; // x20
  unsigned int v137; // w20
  unsigned int v138; // w19
  __int64 v139; // x21
  unsigned __int8 *v140; // x25
  __int64 v141; // x26
  __int64 v142; // x20
  __int64 v144; // x21
  __int64 v145; // x21
  __int64 v146; // x25
  unsigned int v147; // w22
  __int64 v148; // x25
  __int64 v149; // x27
  __int64 v150; // x27
  __int64 v151; // x24
  __int64 v152; // [xsp+0h] [xbp-110h]
  __int64 v153; // [xsp+8h] [xbp-108h]
  __int64 v154; // [xsp+10h] [xbp-100h]
  __int64 v155; // [xsp+18h] [xbp-F8h]
  __int64 v156; // [xsp+20h] [xbp-F0h]
  __int64 v157; // [xsp+30h] [xbp-E0h]
  char v158[4]; // [xsp+50h] [xbp-C0h] BYREF
  _BYTE v159[4]; // [xsp+54h] [xbp-BCh] BYREF
  __int64 v160; // [xsp+58h] [xbp-B8h] BYREF
  __int64 v161; // [xsp+60h] [xbp-B0h]
  __int64 v162; // [xsp+68h] [xbp-A8h] BYREF
  __int64 v163; // [xsp+70h] [xbp-A0h]
  __int64 v164; // [xsp+78h] [xbp-98h]
  __int64 v165; // [xsp+80h] [xbp-90h]
  __int64 v166; // [xsp+88h] [xbp-88h]
  __int64 v167; // [xsp+90h] [xbp-80h]
  __int64 v168; // [xsp+98h] [xbp-78h]
  __int64 v169; // [xsp+A0h] [xbp-70h]
  __int64 v170; // [xsp+A8h] [xbp-68h]
  __int64 v171; // [xsp+B0h] [xbp-60h]
  __int64 v172; // [xsp+B8h] [xbp-58h]
  __int64 v173; // [xsp+C0h] [xbp-50h]
  __int64 v174; // [xsp+C8h] [xbp-48h]
  __int64 v175; // [xsp+D0h] [xbp-40h]
  __int64 v176; // [xsp+D8h] [xbp-38h]
  __int64 v177; // [xsp+E0h] [xbp-30h]
  __int64 v178; // [xsp+E8h] [xbp-28h]
  __int64 v179; // [xsp+F0h] [xbp-20h]
  __int64 v180; // [xsp+F8h] [xbp-18h]
  __int64 v181; // [xsp+100h] [xbp-10h]

  v181 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v159[0] = 0;
  if ( !a10 )
  {
    v136 = jiffies;
    if ( extract_roam_synch_key_event_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: received null buf from target",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_synch_key_event_tlv");
      extract_roam_synch_key_event_tlv___last_ticks = v136;
    }
    goto LABEL_97;
  }
  v14 = *a10;
  v15 = *((unsigned __int8 *)a10 + 8);
  v160 = v14;
  if ( !v14 )
  {
    v142 = jiffies;
    if ( extract_roam_synch_key_event_tlv___last_ticks_153 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: received ml keys param is null",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_synch_key_event_tlv");
      extract_roam_synch_key_event_tlv___last_ticks_153 = v142;
    }
LABEL_97:
    v137 = 4;
LABEL_98:
    _ReadStatusReg(SP_EL0);
    return v137;
  }
  v19 = _qdf_mem_malloc(0x1F8u, "extract_roam_synch_key_event_tlv", 3935);
  *a12 = (void *)v19;
  if ( !v19 )
  {
    v137 = 2;
    goto LABEL_98;
  }
  v179 = 0;
  v180 = 0;
  v177 = 0;
  v178 = 0;
  v175 = 0;
  v176 = 0;
  v173 = 0;
  v174 = 0;
  v171 = 0;
  v172 = 0;
  v170 = 0;
  v169 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944);
  if ( !v169 )
    goto LABEL_83;
  v170 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944);
  if ( !v170 )
    goto LABEL_83;
  v171 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944);
  if ( !v171 )
    goto LABEL_83;
  v172 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944);
  if ( !v172 )
    goto LABEL_83;
  v173 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944);
  if ( !v173
    || (v174 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944)) == 0
    || (v175 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944)) == 0
    || (v176 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944)) == 0
    || (v177 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944)) == 0
    || (v178 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944)) == 0
    || (v179 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944)) == 0
    || (v180 = _qdf_mem_malloc(0x1B0u, "extract_roam_synch_key_event_tlv", 3944)) == 0 )
  {
LABEL_83:
    v137 = 2;
    goto LABEL_84;
  }
  v28 = *a12;
  v29 = 0;
  v28[9] = -1;
  v28[177] = -1;
  v28[345] = -1;
  v30 = a13;
  while ( 2 )
  {
    if ( v29 > 0xB )
      goto LABEL_108;
    while ( 1 )
    {
      v61 = v159[0];
      if ( v15 <= v159[0] )
        goto LABEL_108;
      v62 = (unsigned __int8 *)*(&v169 + v29);
      LODWORD(v152) = *(_DWORD *)(v14 + 68);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: link_id:%d key_ix:%d key_cipher:%d key_len:%d key_flags:%d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "extract_roam_synch_key_event_tlv",
        *(unsigned int *)(v14 + 4),
        *(unsigned int *)(v14 + 8),
        *(unsigned int *)(v14 + 12),
        *(unsigned int *)(v14 + 64),
        v152);
      if ( !is_valid_keyix(*(_DWORD *)(v14 + 8)) )
      {
        v144 = jiffies;
        if ( extract_roam_synch_key_event_tlv___last_ticks_156 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: invalid key index:%d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "extract_roam_synch_key_event_tlv",
            *(unsigned int *)(v14 + 8));
          extract_roam_synch_key_event_tlv___last_ticks_156 = v144;
        }
LABEL_103:
        v137 = 4;
        goto LABEL_84;
      }
      v63 = *(_DWORD *)(v14 + 4);
      if ( v63 != 15 )
      {
        if ( v63 != 255 )
        {
          v65 = (unsigned __int8)v28[9];
          v66 = 0;
          if ( v65 != 255 && v63 != v65 )
          {
            v67 = (unsigned __int8)v28[177];
            if ( v67 == 255 )
            {
              v66 = 1;
            }
            else
            {
              v66 = 1;
              if ( v63 != v67 )
              {
                v68 = (unsigned __int8)v28[345];
                if ( v68 == 255 )
                {
                  v66 = 2;
                }
                else
                {
                  v66 = 2;
                  if ( v63 != v68 )
                    goto LABEL_105;
                }
              }
            }
          }
          v157 = v66;
          v62[16] = *(_DWORD *)(v14 + 56);
          v85 = &v28[168 * (unsigned int)v66];
          v62[17] = BYTE1(*(_DWORD *)(v14 + 56));
          v62[18] = *(_WORD *)(v14 + 58);
          v62[19] = *(_BYTE *)(v14 + 59);
          *((_WORD *)v62 + 10) = *(_DWORD *)(v14 + 60);
          v85[9] = *(_DWORD *)(v14 + 4);
          v86 = *((_DWORD *)v62 + 4);
          *((_WORD *)v85 + 2) = *((_WORD *)v62 + 10);
          *(_DWORD *)v85 = v86;
          v62[1] = 1;
          *((_WORD *)v62 + 2) = *(_DWORD *)(v14 + 8);
          v87 = *(_DWORD *)(v14 + 12);
          if ( (v87 & 0xF0) != 0 )
            v88 = 0;
          else
            v88 = dword_B34348[v87 & 0xF];
          *((_DWORD *)v62 + 2) = v88;
          qdf_mem_copy(v62 + 104, (const void *)(v14 + 16), 8u);
          *v62 = *(_DWORD *)(v14 + 64);
          wmi_fill_keys_from_tlv(&v160, v62 + 384, v62, v159, v15);
          if ( is_igtk(*((_WORD *)v62 + 2)) )
          {
            *((_DWORD *)v62 + 3) = 1;
            if ( v62 == (unsigned __int8 *)-16LL )
            {
              v99 = 0;
              v97 = 0;
              v98 = 0;
              v100 = 0;
            }
            else
            {
              v97 = v62[16];
              v98 = v62[17];
              v99 = v62[18];
              v100 = v62[21];
            }
            v125 = *((_WORD *)v62 + 2);
            v126 = (unsigned __int8)v85[9];
            v127 = v85;
            v128 = v125 - 4;
            v129 = (unsigned __int8)(v125 - 4);
            LODWORD(v156) = (unsigned __int8)(v125 - 6);
            LODWORD(v155) = v129;
            LODWORD(v154) = v125;
            LODWORD(v153) = v100;
            LODWORD(v152) = v99;
            v72 = qdf_trace_msg(
                    0x31u,
                    8u,
                    "%s: ML_KEY: Slot:%d link_id:%d addr: %02x:%02x:%02x:**:**:%02xKey is IGTK key_ix:%d igtk_idx:%d bigtk:%d",
                    v89,
                    v90,
                    v91,
                    v92,
                    v93,
                    v94,
                    v95,
                    v96,
                    "extract_roam_synch_key_event_tlv",
                    v157,
                    v126,
                    v97,
                    v98,
                    v152,
                    v153,
                    v154,
                    v155,
                    v156);
            if ( v129 <= 1 )
            {
              v30 = a13;
              ++v29;
              *(_QWORD *)&v127[8 * v128 + 48] = v62;
              v127[149] = v128;
              goto LABEL_79;
            }
          }
          else if ( is_bigtk(*((_WORD *)v62 + 2)) )
          {
            *((_DWORD *)v62 + 3) = 1;
            if ( v62 == (unsigned __int8 *)-16LL )
            {
              v111 = 0;
              v109 = 0;
              v110 = 0;
              v112 = 0;
            }
            else
            {
              v109 = v62[16];
              v110 = v62[17];
              v111 = v62[18];
              v112 = v62[21];
            }
            v131 = *((_WORD *)v62 + 2);
            v132 = (unsigned __int8)v85[9];
            v133 = v85;
            v134 = v131 - 6;
            v135 = (unsigned __int8)(v131 - 6);
            LODWORD(v156) = v135;
            LODWORD(v155) = (unsigned __int8)(v131 - 4);
            LODWORD(v154) = v131;
            LODWORD(v153) = v112;
            LODWORD(v152) = v111;
            v72 = qdf_trace_msg(
                    0x31u,
                    8u,
                    "%s: ML_KEY: Slot:%d link_id:%d addr: %02x:%02x:%02x:**:**:%02xKey is BIGTK key_ix:%d igtk_idx:%d bigtk:%d",
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106,
                    v107,
                    v108,
                    "extract_roam_synch_key_event_tlv",
                    v157,
                    v132,
                    v109,
                    v110,
                    v152,
                    v153,
                    v154,
                    v155,
                    v156);
            if ( v135 <= 1 )
            {
              v30 = a13;
              ++v29;
              *(_QWORD *)&v133[8 * v134 + 64] = v62;
              v133[150] = v134;
              goto LABEL_79;
            }
          }
          else
          {
            if ( is_gtk(*((_WORD *)v62 + 2)) )
            {
              if ( v62 == (unsigned __int8 *)-16LL )
              {
                v123 = 0;
                v121 = 0;
                v122 = 0;
                v124 = 0;
              }
              else
              {
                v121 = v62[16];
                v122 = v62[17];
                v123 = v62[18];
                v124 = v62[21];
              }
              LODWORD(v154) = *((unsigned __int16 *)v62 + 2);
              LODWORD(v153) = v124;
              LODWORD(v152) = v123;
              v72 = qdf_trace_msg(
                      0x31u,
                      8u,
                      "%s: ML_KEY: Slot:%d link_id:%d addr: %02x:%02x:%02x:**:**:%02x Key is GTK key_ix:%d",
                      v113,
                      v114,
                      v115,
                      v116,
                      v117,
                      v118,
                      v119,
                      v120,
                      "extract_roam_synch_key_event_tlv",
                      v157,
                      (unsigned __int8)v85[9],
                      v121,
                      v122,
                      v152,
                      v153,
                      v154);
              v130 = *((unsigned __int16 *)v62 + 2);
              *((_DWORD *)v62 + 3) = 1;
            }
            else
            {
              v72 = qdf_trace_msg(
                      0x31u,
                      8u,
                      "%s: Key is Pairwise. Shouldn't reach here",
                      v113,
                      v114,
                      v115,
                      v116,
                      v117,
                      v118,
                      v119,
                      v120,
                      "extract_roam_synch_key_event_tlv");
              v130 = *((unsigned __int16 *)v62 + 2);
              *((_DWORD *)v62 + 3) = 0;
            }
            if ( v130 <= 3 )
            {
              v30 = a13;
              *(_QWORD *)&v85[8 * v130 + 16] = v62;
              ++v29;
              goto LABEL_79;
            }
          }
          goto LABEL_127;
        }
LABEL_105:
        v146 = jiffies;
        if ( extract_roam_synch_key_event_tlv___last_ticks_163 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: Not able to find a entry for link:%d j=%d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "extract_roam_synch_key_event_tlv");
          extract_roam_synch_key_event_tlv___last_ticks_163 = v146;
        }
        v30 = a13;
        goto LABEL_108;
      }
      *(_WORD *)a14 = *(_DWORD *)(v14 + 56);
      a14[2] = *(_WORD *)(v14 + 58);
      a14[3] = *(_BYTE *)(v14 + 59);
      *((_WORD *)a14 + 2) = *(_DWORD *)(v14 + 60);
      v64 = *(_DWORD *)(v14 + 64);
      if ( !v64 )
      {
        v145 = jiffies;
        if ( extract_roam_synch_key_event_tlv___last_ticks_158 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: Received key_len as 0 for tlv:%d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "extract_roam_synch_key_event_tlv",
            v61);
          extract_roam_synch_key_event_tlv___last_ticks_158 = v145;
          v137 = 4;
          goto LABEL_84;
        }
        goto LABEL_103;
      }
      if ( (*(_BYTE *)(v14 + 68) & 8) == 0 )
        break;
      v167 = 0;
      v168 = 0;
      v165 = 0;
      v166 = 0;
      v163 = 0;
      v164 = 0;
      v161 = 0;
      v162 = 0;
      v158[0] = 0;
      if ( v64 >= 0x31 )
        *(_DWORD *)(v14 + 64) = 48;
      wmi_fill_keys_from_tlv(&v160, (char *)&v162 + 6, v158, v159, v15);
      HIWORD(v168) = (unsigned __int8)v158[0];
      if ( a14 )
      {
        v39 = *a14;
        v40 = a14[1];
        v41 = a14[2];
        v42 = a14[5];
      }
      else
      {
        v41 = 0;
        v39 = 0;
        v40 = 0;
        v42 = 0;
      }
      LODWORD(v152) = (unsigned __int8)v158[0];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: ML_KEY: Got LTF keyseed key for MLD: %02x:%02x:%02x:**:**:%02x key_seed_len:%d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "extract_roam_synch_key_event_tlv",
        v39,
        v40,
        v41,
        v42,
        v152);
      v43 = v164;
      v14 = v160;
      v44 = v161;
      v45 = v162;
      *((_QWORD *)v28 + 12) = v163;
      *((_QWORD *)v28 + 13) = v43;
      *((_QWORD *)v28 + 10) = v44;
      *((_QWORD *)v28 + 11) = v45;
      v46 = v168;
      v47 = v165;
      v48 = v166;
      *((_QWORD *)v28 + 16) = v167;
      *((_QWORD *)v28 + 17) = v46;
      *((_QWORD *)v28 + 14) = v47;
      *((_QWORD *)v28 + 15) = v48;
      v49 = v168;
      v51 = v165;
      v50 = v166;
      *((_QWORD *)v28 + 37) = v167;
      *((_QWORD *)v28 + 38) = v49;
      *((_QWORD *)v28 + 35) = v51;
      *((_QWORD *)v28 + 36) = v50;
      v52 = v164;
      v53 = v161;
      v54 = v162;
      *((_QWORD *)v28 + 33) = v163;
      *((_QWORD *)v28 + 34) = v52;
      *((_QWORD *)v28 + 31) = v53;
      *((_QWORD *)v28 + 32) = v54;
      v55 = v168;
      v57 = v165;
      v56 = v166;
      *((_QWORD *)v28 + 58) = v167;
      *((_QWORD *)v28 + 59) = v55;
      *((_QWORD *)v28 + 56) = v57;
      *((_QWORD *)v28 + 57) = v56;
      v58 = v164;
      v59 = v161;
      v60 = v162;
      *((_QWORD *)v28 + 54) = v163;
      *((_QWORD *)v28 + 55) = v58;
      v30 = a13;
      *((_QWORD *)v28 + 52) = v59;
      *((_QWORD *)v28 + 53) = v60;
      if ( !v14 )
        goto LABEL_108;
    }
    v69 = 0;
    v62[1] = 1;
    *v62 = *(_DWORD *)(v14 + 64);
    *((_WORD *)v62 + 1) = *(_DWORD *)(v14 + 68);
    v70 = *(_DWORD *)(v14 + 8);
    *((_DWORD *)v62 + 3) = 0;
    *((_WORD *)v62 + 2) = v70;
    v71 = *(_DWORD *)(v14 + 12);
    if ( (v71 & 0xF0) == 0 )
      v69 = dword_B34348[v71 & 0xF];
    *((_DWORD *)v62 + 2) = v69;
    *v62 = *(_DWORD *)(v14 + 64);
    v72 = wmi_fill_keys_from_tlv(&v160, v62 + 384, v62, v159, v15);
    v75 = jiffies;
    if ( extract_roam_synch_key_event_tlv___last_ticks_161 - jiffies + 125 < 0 )
    {
      if ( a14 )
      {
        v76 = *a14;
        v77 = a14[1];
        v78 = a14[2];
        v79 = a14[5];
      }
      else
      {
        v78 = 0;
        v76 = 0;
        v77 = 0;
        v79 = 0;
      }
      LODWORD(v152) = *v62;
      v72 = qdf_trace_msg(
              0x31u,
              2u,
              "%s: ML_KEY: Got Pairwise key for MLD: %02x:%02x:%02x:**:**:%02x rem_len:%d",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "extract_roam_synch_key_event_tlv",
              v76,
              v77,
              v78,
              v79,
              v152);
      extract_roam_synch_key_event_tlv___last_ticks_161 = v75;
    }
    v80 = *((unsigned __int16 *)v62 + 2);
    if ( v80 <= 3 )
    {
      *(_QWORD *)&v28[8 * v80 + 16] = v62;
      if ( v29 == 11 )
        goto LABEL_49;
      v81 = (unsigned __int16 *)*(&v169 + v29 + 1);
      v72 = (unsigned int)memcpy(v81, v62, 0x1B0u);
      v82 = v81[2];
      if ( v82 <= 3 )
      {
        *(_QWORD *)&v28[8 * v82 + 184] = v81;
        if ( v29 == 10 )
        {
LABEL_49:
          v30 = a13;
          v29 = 12;
          goto LABEL_79;
        }
        v83 = (unsigned __int16 *)*(&v169 + v29 + 2);
        v72 = (unsigned int)memcpy(v83, v62, 0x1B0u);
        v84 = v83[2];
        if ( v84 <= 3 )
        {
          v30 = a13;
          *(_QWORD *)&v28[8 * v84 + 352] = v83;
          if ( v29 == 9 )
            v29 = 12;
          else
            v29 += 3;
LABEL_79:
          v14 = v160;
          if ( !v160 )
          {
LABEL_108:
            if ( (unsigned __int8)v28[9] == 255 )
            {
              v148 = jiffies;
              if ( extract_roam_synch_key_event_tlv___last_ticks_169 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x31u,
                  2u,
                  "%s: Free keys for invalid entry at index:%d",
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  "extract_roam_synch_key_event_tlv",
                  0);
                extract_roam_synch_key_event_tlv___last_ticks_169 = v148;
              }
              wlan_crypto_free_key((__int64)(v28 + 16), v20, v21, v22, v23, v24, v25, v26, v27);
              v147 = 0;
              v30 = a13;
              v169 = 0;
            }
            else
            {
              v147 = 1;
            }
            if ( (unsigned __int8)v28[177] == 255 )
            {
              v149 = jiffies;
              if ( extract_roam_synch_key_event_tlv___last_ticks_169 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x31u,
                  2u,
                  "%s: Free keys for invalid entry at index:%d",
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  "extract_roam_synch_key_event_tlv",
                  1);
                extract_roam_synch_key_event_tlv___last_ticks_169 = v149;
              }
              wlan_crypto_free_key((__int64)(v28 + 184), v20, v21, v22, v23, v24, v25, v26, v27);
              v30 = a13;
              v170 = 0;
            }
            else
            {
              ++v147;
            }
            if ( (unsigned __int8)v28[345] != 255 )
            {
              *v30 = ++v147;
              goto LABEL_123;
            }
            v150 = jiffies;
            if ( extract_roam_synch_key_event_tlv___last_ticks_169 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x31u,
                2u,
                "%s: Free keys for invalid entry at index:%d",
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                "extract_roam_synch_key_event_tlv",
                2);
              extract_roam_synch_key_event_tlv___last_ticks_169 = v150;
            }
            wlan_crypto_free_key((__int64)(v28 + 352), v20, v21, v22, v23, v24, v25, v26, v27);
            v171 = 0;
            *a13 = v147;
            if ( v147 )
            {
LABEL_123:
              v151 = jiffies;
              if ( extract_roam_synch_key_event_tlv___last_ticks_171 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x31u,
                  2u,
                  "%s: ML_KEYS: total_entries filled:%d total_num_tlv:%d dst_key_count:%d",
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  "extract_roam_synch_key_event_tlv",
                  v147,
                  v15,
                  v29);
                v137 = 0;
                v138 = 0;
                extract_roam_synch_key_event_tlv___last_ticks_171 = v151;
              }
              else
              {
                v137 = 0;
                v138 = 0;
              }
LABEL_85:
              v139 = 0;
              while ( 2 )
              {
                v140 = (unsigned __int8 *)*(&v169 + v139);
                if ( v140 )
                {
                  v141 = jiffies;
                  if ( extract_roam_synch_key_event_tlv___last_ticks_173 - jiffies + 125 < 0 )
                  {
                    qdf_trace_msg(
                      0x31u,
                      2u,
                      "%s: flush keybuf :%d, key is valid %d",
                      v20,
                      v21,
                      v22,
                      v23,
                      v24,
                      v25,
                      v26,
                      v27,
                      "extract_roam_synch_key_event_tlv",
                      v138,
                      v140[1]);
                    extract_roam_synch_key_event_tlv___last_ticks_173 = v141;
                    if ( (v138 & 1) == 0 )
                      goto LABEL_93;
                  }
                  else if ( (v138 & 1) == 0 )
                  {
LABEL_93:
                    if ( (v140[1] & 1) != 0 )
                      goto LABEL_87;
                  }
                  qdf_trace_msg(
                    0x31u,
                    2u,
                    "%s: Free key allocated at idx:%d",
                    v20,
                    v21,
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    "extract_roam_synch_key_event_tlv",
                    (unsigned int)v139);
                  qdf_mem_set(v140, 0x1B0u, 0);
                  _qdf_mem_free((__int64)v140);
                }
LABEL_87:
                if ( ++v139 == 12 )
                  goto LABEL_98;
                continue;
              }
            }
            v137 = 0;
LABEL_84:
            qdf_mem_set(*a12, 0x1F8u, 0);
            _qdf_mem_free((__int64)*a12);
            v138 = 1;
            goto LABEL_85;
          }
          continue;
        }
      }
    }
    break;
  }
LABEL_127:
  __break(0x5512u);
  __break(1u);
  return extract_roam_ml_info_tlv(v72, v73, v74);
}
