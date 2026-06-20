__int64 __fastcall wma_send_peer_assoc(__int64 *a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x26
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _DWORD *v16; // x19
  __int64 v17; // x24
  unsigned int v18; // w23
  _DWORD *v19; // x25
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w23
  unsigned int v29; // w8
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w22
  __int64 v40; // x27
  unsigned int v41; // w23
  __int64 v42; // x5
  int v43; // w6
  unsigned int v44; // w24
  unsigned int v45; // w9
  unsigned int v46; // w8
  unsigned int v47; // w10
  bool v48; // cc
  unsigned __int64 v49; // x14
  int v50; // w15
  char v51; // w16
  char v52; // w17
  char v53; // w15
  __int16 v54; // w10
  unsigned int v55; // w9
  unsigned int v56; // w11
  __int16 v57; // w11
  __int16 v58; // w11
  __int16 v59; // w11
  __int16 v60; // w11
  __int16 v61; // w11
  __int16 v62; // w11
  __int16 v63; // w11
  __int16 v64; // w11
  __int16 v65; // w11
  __int16 v66; // w11
  __int16 v67; // w10
  unsigned int v68; // w9
  unsigned int v69; // w8
  char v70; // w27
  unsigned __int64 v71; // x10
  void *v72; // x0
  const void *v73; // x1
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int16 v82; // w9
  __int16 v83; // w8
  int v84; // w9
  int v85; // w9
  int v86; // w8
  int v87; // w8
  int v88; // w8
  __int16 v89; // w8
  __int64 peer; // x0
  __int64 v91; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v93; // x8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // w8
  __int16 v103; // w8
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned int v112; // w8
  unsigned int v113; // w0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  const char *v122; // x2
  unsigned int v123; // w1
  unsigned __int64 v124; // x8
  int v125; // w8
  int v126; // w8
  size_t v127; // x2
  size_t v128; // x2
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  int v137; // w8
  int v138; // w8
  char v139; // w9
  unsigned int v140; // w4
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  bool is_vdev_in_ap_mode; // w0
  char v158; // w24
  __int64 v159; // x0
  __int64 v160; // x23
  __int64 comp_private_obj; // x0
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  char v178; // w8
  int param; // w22
  unsigned int v180; // w23
  unsigned int v181; // w24
  unsigned __int16 v182; // w0
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  _BYTE v192[4]; // [xsp+1Ch] [xbp-124h] BYREF
  __int64 v193; // [xsp+20h] [xbp-120h] BYREF
  size_t n[17]; // [xsp+28h] [xbp-118h] BYREF
  _DWORD v195[34]; // [xsp+B0h] [xbp-90h] BYREF
  __int64 v196; // [xsp+138h] [xbp-8h]

  v196 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[2];
  v192[0] = 0;
  memset(v195, 0, sizeof(v195));
  memset(n, 0, sizeof(n));
  v7 = _qdf_mem_malloc(0x1DCu, "wma_send_peer_assoc", 1723);
  if ( v7 )
  {
    v16 = (_DWORD *)v7;
    v17 = a3 + 60;
    v18 = *(unsigned __int16 *)(*(_QWORD *)(a1[2] + 8) + 2764LL);
    v19 = (_DWORD *)(a1[65] + 488LL * *(unsigned __int8 *)(a3 + 131));
    if ( v18 >= 0x100 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: set mcs_limit %x",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wma_mask_tx_ht_rate",
        *(unsigned __int16 *)(*(_QWORD *)(a1[2] + 8) + 2764LL));
      v45 = (unsigned __int8)v18 >> 3;
      v46 = 0;
      v47 = 0;
      do
      {
        if ( v47 < v45 )
        {
          *(_BYTE *)(v17 + v47++) = -1;
          v46 += 8;
        }
        else if ( v47 <= v45 )
        {
          v48 = v46 > (unsigned __int8)v18;
          v49 = (unsigned __int64)v46 >> 3;
          v50 = 1 << (v46++ & 7);
          v51 = *(_BYTE *)(v17 + v49);
          v52 = v51 & ~(_BYTE)v50;
          v53 = v51 | v50;
          if ( v48 )
            v53 = v52;
          *(_BYTE *)(v17 + v49) = v53;
          if ( v46 >= 8 * (v47 + 1) )
            ++v47;
        }
        else
        {
          *(_BYTE *)(v17 + v47) = 0;
          v46 += 8;
          ++v47;
        }
      }
      while ( v46 < 0x80 );
    }
    qdf_mem_set(v195, 0x88u, 0);
    qdf_mem_set(n, 0x88u, 0);
    qdf_mem_set(v16, 0x1DCu, 0);
    v28 = *(unsigned __int8 *)(a3 + 152);
    v29 = *(_DWORD *)(a3 + 24);
    if ( a2 - 1 <= 1 && v29 >= 2 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: ch_width %d sent in 11G, configure to 40MHz",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wma_send_peer_assoc",
        v29);
      v29 = 1;
      *(_DWORD *)(a3 + 24) = 1;
    }
    v30 = wma_peer_phymode(
            a2,
            *(unsigned __int8 *)(a3 + 8),
            *(unsigned __int8 *)(a3 + 21),
            v29,
            *(unsigned __int8 *)(a3 + 115),
            v28,
            0);
    v39 = v30;
    v40 = *(_QWORD *)(*(_QWORD *)v19 + 40LL);
    if ( v19[41] == 1 )
    {
      v41 = *(_DWORD *)(v40 + 28);
      if ( v30 > v41 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "Peer phymode %d is not allowed. Set it equal to sap/go phymode %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v30,
          v41);
        v39 = v41;
      }
    }
    if ( (*(_BYTE *)(*(_QWORD *)(v6 + 8) + 2766LL) & 1) != 0 || wlan_reg_is_6ghz_chan_freq(*(_WORD *)v40) )
    {
      v42 = 0;
      v43 = 0;
      goto LABEL_12;
    }
    v54 = *(_WORD *)(a3 + 36);
    v55 = v195[0];
    if ( v54 )
    {
      v56 = ++v195[0];
      if ( v55 > 0x83 )
        goto LABEL_183;
      *((_BYTE *)&v195[1] + v55) = v54;
      v42 = 1;
      v55 = v56;
      v57 = *(_WORD *)(a3 + 38);
      if ( !v57 )
      {
LABEL_31:
        v58 = *(_WORD *)(a3 + 40);
        if ( !v58 )
          goto LABEL_32;
        goto LABEL_46;
      }
    }
    else
    {
      v42 = 0;
      v57 = *(_WORD *)(a3 + 38);
      if ( !v57 )
        goto LABEL_31;
    }
    v195[0] = v55 + 1;
    if ( v55 > 0x83 )
      goto LABEL_183;
    *((_BYTE *)&v195[1] + v55) = v57;
    v42 = (unsigned int)(v42 + 1);
    ++v55;
    v58 = *(_WORD *)(a3 + 40);
    if ( !v58 )
    {
LABEL_32:
      v59 = *(_WORD *)(a3 + 42);
      if ( !v59 )
        goto LABEL_33;
      goto LABEL_48;
    }
LABEL_46:
    v195[0] = v55 + 1;
    if ( v55 > 0x83 )
      goto LABEL_183;
    *((_BYTE *)&v195[1] + v55) = v58;
    v42 = (unsigned int)(v42 + 1);
    ++v55;
    v59 = *(_WORD *)(a3 + 42);
    if ( !v59 )
    {
LABEL_33:
      v60 = *(_WORD *)(a3 + 44);
      if ( v60 )
        goto LABEL_34;
      goto LABEL_50;
    }
LABEL_48:
    v195[0] = v55 + 1;
    if ( v55 > 0x83 )
      goto LABEL_183;
    *((_BYTE *)&v195[1] + v55) = v59;
    v42 = (unsigned int)(v42 + 1);
    ++v55;
    v60 = *(_WORD *)(a3 + 44);
    if ( v60 )
    {
LABEL_34:
      v195[0] = v55 + 1;
      if ( v55 > 0x83 )
        goto LABEL_183;
      *((_BYTE *)&v195[1] + v55) = v60;
      v43 = 1;
      ++v55;
      v61 = *(_WORD *)(a3 + 46);
      if ( !v61 )
      {
LABEL_36:
        v62 = *(_WORD *)(a3 + 48);
        if ( !v62 )
          goto LABEL_37;
        goto LABEL_53;
      }
LABEL_51:
      v195[0] = v55 + 1;
      if ( v55 > 0x83 )
        goto LABEL_183;
      *((_BYTE *)&v195[1] + v55) = v61;
      ++v43;
      ++v55;
      v62 = *(_WORD *)(a3 + 48);
      if ( !v62 )
      {
LABEL_37:
        v63 = *(_WORD *)(a3 + 50);
        if ( !v63 )
          goto LABEL_38;
        goto LABEL_55;
      }
LABEL_53:
      v195[0] = v55 + 1;
      if ( v55 > 0x83 )
        goto LABEL_183;
      *((_BYTE *)&v195[1] + v55) = v62;
      ++v43;
      ++v55;
      v63 = *(_WORD *)(a3 + 50);
      if ( !v63 )
      {
LABEL_38:
        v64 = *(_WORD *)(a3 + 52);
        if ( !v64 )
          goto LABEL_39;
        goto LABEL_57;
      }
LABEL_55:
      v195[0] = v55 + 1;
      if ( v55 > 0x83 )
        goto LABEL_183;
      *((_BYTE *)&v195[1] + v55) = v63;
      ++v43;
      ++v55;
      v64 = *(_WORD *)(a3 + 52);
      if ( !v64 )
      {
LABEL_39:
        v65 = *(_WORD *)(a3 + 54);
        if ( !v65 )
          goto LABEL_40;
        goto LABEL_59;
      }
LABEL_57:
      v195[0] = v55 + 1;
      if ( v55 > 0x83 )
        goto LABEL_183;
      *((_BYTE *)&v195[1] + v55) = v64;
      ++v43;
      ++v55;
      v65 = *(_WORD *)(a3 + 54);
      if ( !v65 )
      {
LABEL_40:
        v66 = *(_WORD *)(a3 + 56);
        if ( !v66 )
        {
LABEL_41:
          v67 = *(_WORD *)(a3 + 58);
          if ( !v67 )
          {
LABEL_12:
            if ( v39 == 1 && !v43 )
              goto LABEL_66;
            if ( v39 != 2 )
              goto LABEL_67;
LABEL_65:
            if ( !(_DWORD)v42 )
            {
LABEL_66:
              qdf_trace_msg(
                0x36u,
                3u,
                "%s: Invalid phy rates. phymode 0x%x, 11b_rates %d, 11a_rates %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "wma_send_peer_assoc",
                v39,
                v42);
              _qdf_mem_free((__int64)v16);
              v44 = 4;
              goto LABEL_180;
            }
LABEL_67:
            v68 = n[0];
            v69 = 0;
            v70 = 1;
            while ( 1 )
            {
              v71 = (unsigned __int64)v69 >> 3;
              if ( ((*(unsigned __int8 *)(v17 + v71) >> (v69 & 7)) & 1) != 0 )
              {
                LODWORD(n[0]) = v68 + 1;
                if ( v68 > 0x83 )
                  goto LABEL_183;
                *((_BYTE *)n + v68++ + 4) = v69;
                if ( v69 < 0x10 )
                  v70 = v71 + 1;
              }
              if ( v68 == 33 )
                break;
              if ( ++v69 == 77 )
              {
                if ( *(_BYTE *)(a3 + 21) && !v68 )
                {
                  v193 = 0x706050403020100LL;
                  qdf_trace_msg(
                    0x36u,
                    3u,
                    "%s: Peer is marked as HT capable but supported mcs rate is 0",
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    "wma_send_peer_assoc");
                  LODWORD(n[0]) = 8;
                  qdf_mem_copy((char *)n + 4, &v193, 8u);
                }
                break;
              }
            }
            if ( wma_is_vdev_in_ap_mode((__int64)a1, *(_BYTE *)(a3 + 131), v31, v32, v33, v34, v35, v36, v37, v38)
              || *(_BYTE *)(a3 + 8) == 4 )
            {
              v72 = (char *)v16 + 355;
              v73 = (const void *)(a3 + 9);
            }
            else
            {
              v72 = (char *)v16 + 355;
              v73 = (const void *)a3;
            }
            qdf_mem_copy(v72, v73, 6u);
            wma_objmgr_set_peer_mlme_phymode((__int64)a1, (_BYTE *)v16 + 355, v39);
            *v16 = *(unsigned __int8 *)(a3 + 131);
            v16[1] = 1;
            v82 = *((_WORD *)v16 + 176);
            v83 = v82 | 2;
            v16[2] = *(unsigned __int16 *)(a3 + 6);
            *((_WORD *)v16 + 176) = v82 | 2;
            if ( *(_BYTE *)(a3 + 18) )
            {
              v83 = v82 | 6;
              *((_WORD *)v16 + 176) = v82 | 6;
            }
            if ( *(_BYTE *)(a3 + 19) )
            {
              *((_WORD *)v16 + 176) = v83 | 8;
              qdf_trace_msg(
                0x36u,
                8u,
                "Set WMI_PEER_APSD: uapsd Mask %d",
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                *(unsigned __int8 *)(a3 + 19));
            }
            if ( *(_BYTE *)(a3 + 21) )
            {
              v84 = v16[8] | 8;
              *((_WORD *)v16 + 176) |= 0x14u;
              v16[8] = v84;
            }
            if ( *(_BYTE *)(a3 + 115) )
            {
              v85 = v16[8] | 8;
              *((_WORD *)v16 + 176) |= 0x2014u;
              v16[8] = v85;
            }
            if ( *(_DWORD *)(a3 + 24) )
            {
              v86 = v16[8];
              v16[8] = v86 | 2;
              if ( !*(_BYTE *)(a3 + 34) )
                goto LABEL_95;
              v87 = v86 | 6;
            }
            else
            {
              if ( !*(_BYTE *)(a3 + 35) )
                goto LABEL_95;
              v87 = v16[8] | 4;
            }
            v16[8] = v87;
LABEL_95:
            v88 = *(_DWORD *)(a3 + 24);
            if ( v88 <= 2 )
            {
              if ( v88 == 1 )
              {
                v89 = *((_WORD *)v16 + 176);
                goto LABEL_103;
              }
              if ( v88 == 2 )
              {
                v89 = *((_WORD *)v16 + 176) | 0x40;
                goto LABEL_103;
              }
            }
            else if ( (unsigned int)(v88 - 3) < 2 || v88 == 7 )
            {
              v89 = *((_WORD *)v16 + 176) | 0xC0;
LABEL_103:
              *((_WORD *)v16 + 176) = v89 | 0x20;
            }
            v16[9] = *(_DWORD *)(a3 + 140);
            if ( *(_BYTE *)(a3 + 113) )
            {
              *((_BYTE *)v16 + 354) |= 0x10u;
              peer = wlan_objmgr_get_peer(a1[3], *(_BYTE *)(a1[4] + 40), (_BYTE *)(a3 + 9), 8u);
              if ( peer )
              {
                v91 = peer;
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
                  || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(peer + 760);
                  v93 = *(_QWORD *)(v91 + 768);
                }
                else
                {
                  raw_spin_lock_bh(peer + 760);
                  v93 = *(_QWORD *)(v91 + 768) | 1LL;
                  *(_QWORD *)(v91 + 768) = v93;
                }
                *(_DWORD *)(v91 + 68) = 5;
                if ( (v93 & 1) != 0 )
                {
                  *(_QWORD *)(v91 + 768) = v93 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v91 + 760);
                }
                else
                {
                  raw_spin_unlock(v91 + 760);
                }
                wlan_objmgr_peer_release_ref(v91, 8u, v94, v95, v96, v97, v98, v99, v100, v101);
              }
            }
            if ( *(_BYTE *)(a3 + 105) )
              *((_WORD *)v16 + 176) |= 1u;
            if ( *(_BYTE *)(a3 + 240) )
              *((_WORD *)v16 + 176) |= 0x100u;
            if ( *(_BYTE *)(a3 + 128) || *(_BYTE *)(a3 + 129) )
              *((_WORD *)v16 + 176) |= 0x200u;
            v102 = *(_DWORD *)(a3 + 28);
            if ( v102 )
            {
              if ( v102 == 3 )
              {
                v103 = 4096;
              }
              else
              {
                if ( v102 != 1 )
                  goto LABEL_127;
                v103 = 2048;
              }
            }
            else
            {
              v103 = 1024;
            }
            *((_WORD *)v16 + 176) |= v103;
LABEL_127:
            wma_set_twt_peer_caps(a3, v16);
            if ( *(_BYTE *)(a3 + 8) == 4 )
              *((_BYTE *)v16 + 354) |= 2u;
            v112 = *(unsigned __int8 *)(a3 + 132);
            if ( *(_BYTE *)(a3 + 132) || *(_DWORD *)(a3 + 108) == 5 )
            {
              if ( (*(_BYTE *)(a3 + 243) & 1) == 0 )
              {
                *((_WORD *)v16 + 176) |= 0x8000u;
                wlan_acquire_peer_key_wakelock(
                  *(_QWORD *)v19,
                  (unsigned __int8 *)v16 + 355,
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110,
                  v111);
                v112 = *(unsigned __int8 *)(a3 + 132);
              }
              if ( v112 >= 2 )
                *((_BYTE *)v16 + 354) |= 1u;
            }
            if ( *(_DWORD *)(a3 + 108) == 5
              && (v113 = wma_vdev_set_param(
                           *a1,
                           *(unsigned __int8 *)(a3 + 131),
                           0x2Fu,
                           0,
                           v104,
                           v105,
                           v106,
                           v107,
                           v108,
                           v109,
                           v110,
                           v111)) != 0 )
            {
              v44 = v113;
              v122 = "%s: Set wmi_vdev_param_drop_unencry Param status:%d";
              v123 = 2;
            }
            else
            {
              v16[3] = *(unsigned __int16 *)(a3 + 134);
              v16[4] = *(unsigned __int16 *)(a3 + 16);
              v16[5] = *(unsigned __int16 *)(a3 + 136);
              v16[6] = (0x2000 << *(_BYTE *)(a3 + 32)) - 1;
              v124 = *(unsigned __int8 *)(a3 + 33);
              if ( v124 > 7 )
                v125 = 0;
              else
                v125 = wma_mpdu_spacing[v124];
              v16[7] = v125;
              if ( *(_BYTE *)(a3 + 61) )
              {
                if ( *(_BYTE *)(a3 + 62) )
                  v126 = 512;
                else
                  v126 = 1;
                v16[8] |= v126;
              }
              v127 = v195[0];
              v16[13] = v195[0];
              qdf_mem_copy(v16 + 14, &v195[1], v127);
              v128 = LODWORD(n[0]);
              v16[47] = n[0];
              qdf_mem_copy(v16 + 48, (char *)n + 4, v128);
              *((_BYTE *)v16 + 341) = v70;
              if ( v19[66] <= 1u )
              {
                v16[9] &= ~0x80u;
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "Num tx_streams: %d, Disabled txSTBC",
                  v129,
                  v130,
                  v131,
                  v132,
                  v133,
                  v134,
                  v135,
                  v136,
                  (unsigned int)v19[66]);
              }
              v137 = *(unsigned __int8 *)(a3 + 115);
              *((_BYTE *)v16 + 342) = v137;
              if ( v137 )
              {
                v16[81] = *(unsigned __int16 *)(a3 + 80);
                v16[82] = *(unsigned __int16 *)(a3 + 78);
                v16[83] = *(unsigned __int16 *)(a3 + 84);
                v138 = *(unsigned __int16 *)(a3 + 82);
                v16[84] = v138;
                v139 = *(_BYTE *)(a3 + 116);
                if ( !v139 )
                {
                  if ( (~v138 & 0xC) != 0 )
                    v139 = 2;
                  else
                    v139 = 1;
                }
                *((_BYTE *)v16 + 341) = v139;
                if ( *(_BYTE *)(a3 + 130) )
                  v16[84] = v138 | (~(-1 << v139) << 16) | 0x1000000;
                if ( *(_BYTE *)(a3 + 119) && (*(_BYTE *)(a3 + 117) || *(_BYTE *)(a3 + 118)) )
                {
                  v140 = v16[86] | 0x80000000;
                  v16[86] = v140;
                  if ( *(_BYTE *)(a3 + 117) )
                  {
                    v140 |= *(unsigned __int8 *)(a3 + 117) + 0x7FFFFFFF;
                    v16[86] = v140;
                  }
                  if ( *(_BYTE *)(a3 + 118) )
                    v16[86] = v140 | (8 * *(unsigned __int8 *)(a3 + 118) - 8);
                  qdf_trace_msg(
                    0x36u,
                    8u,
                    "%s: peer_bw_rxnss_override %0X",
                    v129,
                    v130,
                    v131,
                    v132,
                    v133,
                    v134,
                    v135,
                    v136,
                    "wma_send_peer_assoc");
                }
              }
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: rx_max_rate %d, rx_mcs %x, tx_max_rate %d, tx_mcs: %x num rates %d need 4 way %d",
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                v136,
                "wma_send_peer_assoc",
                (unsigned int)v16[81],
                (unsigned int)v16[82],
                (unsigned int)v16[83],
                (unsigned int)v16[84],
                LODWORD(n[0]),
                *((unsigned __int16 *)v16 + 176) >> 15);
              wlan_mlme_get_vht_mimo_cap(*(_QWORD *)(v6 + 21552), v192);
              if ( (unsigned int)v192[0] + 1 < *((unsigned __int8 *)v16 + 341) )
              {
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: peer Nss %d is more than supported %d",
                  v141,
                  v142,
                  v143,
                  v144,
                  v145,
                  v146,
                  v147,
                  v148,
                  "wma_send_peer_assoc");
                *((_BYTE *)v16 + 341) = v192[0] + 1;
              }
              v149 = ((double (__fastcall *)(_DWORD *, __int64))wma_populate_peer_he_cap)(v16, a3);
              is_vdev_in_ap_mode = wma_is_vdev_in_ap_mode(
                                     (__int64)a1,
                                     *(_BYTE *)(a3 + 131),
                                     v149,
                                     v150,
                                     v151,
                                     v152,
                                     v153,
                                     v154,
                                     v155,
                                     v156);
              v158 = *((_BYTE *)v16 + 341);
              if ( !is_vdev_in_ap_mode )
                *((_BYTE *)v19 + 236) = v158;
              v159 = wlan_objmgr_get_peer(a1[3], *(_BYTE *)(a1[4] + 40), (_BYTE *)v16 + 355, 8u);
              if ( v159 )
              {
                v160 = v159;
                comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v159, 0);
                if ( comp_private_obj )
                  *(_BYTE *)(comp_private_obj + 52) = v158;
                wlan_objmgr_peer_release_ref(v160, 8u, v162, v163, v164, v165, v166, v167, v168, v169);
              }
              v16[10] = wmi_host_to_fw_phymode(v39);
              v178 = *(_BYTE *)(a3 + 150);
              if ( !v178 )
                v178 = *((_BYTE *)v16 + 341);
              *((_BYTE *)v16 + 340) = v178;
              if ( !wma_is_vdev_in_ap_mode(
                      (__int64)a1,
                      *(_BYTE *)(a3 + 131),
                      v170,
                      v171,
                      v172,
                      v173,
                      v174,
                      v175,
                      v176,
                      v177)
                || (param = *(_DWORD *)(a3 + 252)) == 0 )
              {
                param = wlan_crypto_get_param(*(_QWORD *)v19, 7u);
              }
              v180 = wlan_crypto_get_param(*(_QWORD *)v19, 0);
              v181 = wlan_crypto_get_param(*(_QWORD *)v19, 1u);
              v182 = cm_crypto_authmode_to_wmi_authmode(v180, param, v181);
              *((_WORD *)v16 + 236) = v182;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: vdev:%d AKM: 0x%x auth_mode:0x%x uc_cipher:0x%x",
                v183,
                v184,
                v185,
                v186,
                v187,
                v188,
                v189,
                v190,
                "wma_send_peer_assoc",
                *(unsigned __int8 *)(a3 + 131),
                v182,
                v180,
                v181);
              v44 = wmi_unified_peer_assoc_send(*a1);
              if ( !v44 )
                goto LABEL_179;
              v122 = "%s: Failed to send peer assoc command status = %d";
              v123 = 1;
            }
            qdf_trace_msg(0x36u, v123, v122, v114, v115, v116, v117, v118, v119, v120, v121, "wma_send_peer_assoc", v44);
LABEL_179:
            _qdf_mem_free((__int64)v16);
            goto LABEL_180;
          }
          goto LABEL_63;
        }
LABEL_61:
        v195[0] = v55 + 1;
        if ( v55 > 0x83 )
          goto LABEL_183;
        *((_BYTE *)&v195[1] + v55) = v66;
        ++v43;
        ++v55;
        v67 = *(_WORD *)(a3 + 58);
        if ( !v67 )
          goto LABEL_12;
LABEL_63:
        v195[0] = v55 + 1;
        if ( v55 <= 0x83 )
        {
          *((_BYTE *)&v195[1] + v55) = v67;
          if ( v39 != 2 )
            goto LABEL_67;
          goto LABEL_65;
        }
LABEL_183:
        __break(1u);
      }
LABEL_59:
      v195[0] = v55 + 1;
      if ( v55 > 0x83 )
        goto LABEL_183;
      *((_BYTE *)&v195[1] + v55) = v65;
      ++v43;
      ++v55;
      v66 = *(_WORD *)(a3 + 56);
      if ( !v66 )
        goto LABEL_41;
      goto LABEL_61;
    }
LABEL_50:
    v43 = 0;
    v61 = *(_WORD *)(a3 + 46);
    if ( !v61 )
      goto LABEL_36;
    goto LABEL_51;
  }
  v44 = 2;
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Failed to allocate peer_assoc_params param",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "wma_send_peer_assoc");
LABEL_180:
  _ReadStatusReg(SP_EL0);
  return v44;
}
