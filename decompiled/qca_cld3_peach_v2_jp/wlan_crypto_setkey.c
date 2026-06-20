__int64 __fastcall wlan_crypto_setkey(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w4
  __int64 result; // x0
  unsigned __int64 v14; // x8
  unsigned __int8 *v15; // x21
  unsigned __int8 v16; // w27
  __int64 v17; // x28
  unsigned int v18; // w9
  int v19; // w8
  __int16 v20; // w8
  __int16 v21; // w8
  int v22; // w23
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x8
  __int64 v25; // x22
  __int64 v26; // x8
  __int64 peer_by_mac_n_vdev; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x24
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w8
  __int64 v47; // x11
  unsigned int v48; // w26
  __int64 v49; // x0
  __int64 v50; // x25
  unsigned __int8 v51; // w26
  __int64 v52; // x8
  __int64 v53; // x9
  __int64 v54; // x0
  int v55; // w8
  __int64 v56; // x8
  const char *v57; // x2
  __int64 v58; // x2
  __int64 v59; // x0
  __int64 v60; // x26
  __int16 v61; // w24
  __int64 v62; // x0
  unsigned __int8 v63; // w10
  __int64 v64; // x24
  __int64 v65; // x0
  unsigned __int8 v66; // w9
  int v67; // w8
  const char *v68; // x2
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  const char *v77; // x2
  __int64 v78; // x24
  __int64 v79; // x24
  __int64 v80; // x0
  __int64 v81; // x24
  __int64 v82; // x0
  __int64 v83; // x26
  __int64 bsspeer; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x24
  unsigned __int8 v94; // w26
  __int64 v95; // x8
  __int64 v96; // x9
  __int64 v97; // x0
  __int64 v98; // x0
  int v99; // w8
  unsigned int v100; // w9
  unsigned __int64 v101; // x8
  _QWORD *v102; // x26
  _QWORD *v103; // x1
  char v104; // w8
  void *v105; // x0
  const void *v106; // x1
  size_t v107; // x2
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x22
  unsigned int v117; // w3
  __int64 v118; // x0
  void (__fastcall *v119)(__int64, __int64, int *); // x8
  __int64 (__fastcall *v120)(_QWORD); // x8
  __int64 v121; // x2
  unsigned int v122; // w8
  unsigned int v123; // w20
  unsigned int v124; // w19
  __int64 (__fastcall *v125)(__int64, __int64, int *); // x8
  int v126; // w8
  unsigned int v127; // w8
  __int64 comp_private_obj; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  int authmode; // w0
  unsigned __int8 v138; // [xsp+0h] [xbp-50h]
  unsigned __int8 v139; // [xsp+0h] [xbp-50h]
  unsigned __int8 v140; // [xsp+8h] [xbp-48h]
  unsigned __int8 v141; // [xsp+8h] [xbp-48h]
  __int64 v142; // [xsp+10h] [xbp-40h]
  __int64 v143; // [xsp+10h] [xbp-40h]
  __int64 v144; // [xsp+18h] [xbp-38h]
  __int64 v145; // [xsp+18h] [xbp-38h]
  __int64 v146; // [xsp+18h] [xbp-38h]
  __int64 v147; // [xsp+18h] [xbp-38h]
  int v148; // [xsp+20h] [xbp-30h] BYREF
  __int16 v149; // [xsp+24h] [xbp-2Ch]
  _QWORD v150[2]; // [xsp+28h] [xbp-28h] BYREF
  _QWORD v151[3]; // [xsp+38h] [xbp-18h] BYREF

  v151[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v149 = -1;
  v148 = -1;
  if ( !a1 || !a2 || (v12 = a2[4], v12 >= 0x31) )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: Invalid params vdev%pK, req_key%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_crypto_setkey",
      a1,
      a2);
    goto LABEL_5;
  }
  LODWORD(v14) = *a2;
  v15 = a2 + 8;
  v16 = a2[8];
  if ( !a2[4] )
    goto LABEL_10;
  if ( (unsigned int)v14 < 0x12 )
    goto LABEL_11;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          __break(0x5512u);
LABEL_10:
          if ( (_DWORD)v14 != 14 )
          {
            if ( (*((_WORD *)a2 + 3) & 0x80) == 0
              || (v58 = *((unsigned __int16 *)a2 + 1), (_WORD)v58 == 0xFFFF)
              || (unsigned int)v14 <= 0xC && ((1 << v14) & 0x1940) != 0 )
            {
              qdf_trace_msg(0x1Cu, 2u, "%s: req_key len zero", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_setkey");
              result = 51;
            }
            else
            {
              wlan_crypto_default_key(a1, a2 + 8, v58, 0);
              result = 0;
            }
            goto LABEL_6;
          }
LABEL_11:
          v17 = wlan_crypto_cipher_ops[(unsigned int)v14];
          if ( v17 )
          {
            if ( (unsigned int)v14 > 0xE || ((1 << v14) & 0x5940) == 0 )
            {
              if ( (_DWORD)v14 && *(_DWORD *)(v17 + 16) >> 3 != v12 )
                goto LABEL_70;
              if ( !(_DWORD)v14 && (v12 > 0x10 || ((1 << v12) & 0x12020) == 0) )
              {
                qdf_trace_msg(
                  0x1Cu,
                  2u,
                  "%s: wep key len invalid. keylen: %d",
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  "wlan_crypto_setkey");
                result = 51;
                goto LABEL_6;
              }
            }
          }
          else if ( (unsigned int)v14 > 0xC || ((1 << v14) & 0x1940) == 0 )
          {
LABEL_70:
            v68 = "%s: cipher invalid";
            goto LABEL_71;
          }
          v18 = *((unsigned __int16 *)a2 + 1);
          if ( v18 == 0xFFFF )
          {
            v19 = *((unsigned __int16 *)a2 + 3);
            if ( v19 != 3 )
            {
              v20 = v19 | 3;
LABEL_30:
              *((_WORD *)a2 + 3) = v20;
            }
          }
          else
          {
            if ( v18 >= 4 )
            {
              result = 52;
              if ( (unsigned int)v14 > 0xC || ((1 << v14) & 0x1940) == 0 )
                goto LABEL_6;
            }
            v21 = *((_WORD *)a2 + 3);
            *((_WORD *)a2 + 3) = v21 | 3;
            if ( (v16 & 1) != 0 )
            {
              v20 = v21 | 7;
              goto LABEL_30;
            }
          }
          v22 = *(_DWORD *)(a1 + 16);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a1 + 1272);
          }
          else
          {
            raw_spin_lock_bh(a1 + 1272);
            *(_QWORD *)(a1 + 1280) |= 1uLL;
          }
          qdf_mem_copy(&v148, (const void *)(a1 + 74), 6u);
          v24 = *(_QWORD *)(a1 + 152);
          if ( !v24 || (v25 = *(_QWORD *)(v24 + 80)) == 0 )
          {
            v56 = *(_QWORD *)(a1 + 1280);
            if ( (v56 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 1280) = v56 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 1272);
            }
            else
            {
              raw_spin_unlock(a1 + 1272);
            }
            v57 = "%s: psoc NULL";
            goto LABEL_54;
          }
          v26 = *(_QWORD *)(a1 + 1280);
          if ( (v26 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 1280) = v26 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 1272);
            if ( *a2 )
              goto LABEL_39;
          }
          else
          {
            raw_spin_unlock(a1 + 1272);
            if ( *a2 )
              goto LABEL_39;
          }
          comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
          if ( comp_private_obj )
          {
            authmode = wlan_crypto_get_authmode(comp_private_obj);
            if ( authmode != -1 && (authmode & 8) != 0 )
              *((_WORD *)a2 + 3) |= 0x80u;
          }
          else
          {
            qdf_trace_msg(
              0x1Cu,
              2u,
              "%s: crypto_priv NULL",
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              "wlan_crypto_get_param");
          }
LABEL_39:
          if ( (v16 & 1) != 0 )
            break;
          peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(
                                 v25,
                                 *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 40LL),
                                 &v148,
                                 a2 + 8,
                                 19);
          if ( !peer_by_mac_n_vdev )
          {
            v57 = "%s: peer NULL";
LABEL_54:
            qdf_trace_msg(0x1Cu, 2u, v57, v28, v29, v30, v31, v32, v33, v34, v35, "wlan_crypto_setkey");
            goto LABEL_5;
          }
          v36 = peer_by_mac_n_vdev;
          qdf_mem_copy(&v148, a2 + 8, 6u);
          v37 = wlan_objmgr_peer_get_comp_private_obj(v36, 14);
          if ( !v37 )
          {
            qdf_trace_msg(
              0x1Cu,
              2u,
              "%s: crypto_priv NULL",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wlan_crypto_peer_get_comp_params");
            qdf_trace_msg(
              0x1Cu,
              2u,
              "%s: crypto_priv NULL",
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              "wlan_crypto_setkey");
            LODWORD(result) = 4;
            goto LABEL_157;
          }
          v46 = *a2;
          v47 = v37;
          if ( v46 > 0xC || ((1 << v46) & 0x1940) == 0 )
          {
            if ( *((unsigned __int16 *)a2 + 1) == 0xFFFF )
              v48 = 0;
            else
              v48 = *((unsigned __int16 *)a2 + 1);
            if ( v48 >= 4 )
            {
              v77 = "%s: invalid keyid %d";
              goto LABEL_104;
            }
            v50 = *(_QWORD *)(v37 + 288 + 8LL * v48);
            if ( v50 )
              goto LABEL_112;
            v143 = v37 + 288;
            v146 = v37;
            v98 = _qdf_mem_malloc(0x1B0u, "wlan_crypto_setkey", 1001);
            *(_QWORD *)(v143 + 8LL * v48) = v98;
            if ( v98 )
            {
              v47 = v146;
              v50 = v98;
              goto LABEL_112;
            }
LABEL_156:
            LODWORD(result) = 2;
LABEL_157:
            v124 = result;
            wlan_objmgr_peer_release_ref(v36, 19);
            result = v124;
            goto LABEL_6;
          }
          v48 = *((unsigned __int16 *)a2 + 1);
          if ( (v48 & 0xFFFC | 2) != 6 )
          {
            v77 = "%s: igtk/bigtk key invalid keyid %d";
LABEL_104:
            qdf_trace_msg(0x1Cu, 2u, v77, v38, v39, v40, v41, v42, v43, v44, v45, "wlan_crypto_setkey", v48);
            LODWORD(result) = 52;
            goto LABEL_157;
          }
          v144 = v37;
          v49 = _qdf_mem_malloc(0x1B0u, "wlan_crypto_setkey", 967);
          if ( !v49 )
            goto LABEL_156;
          v50 = v49;
          if ( (*((_WORD *)a2 + 1) & 0xFFFE) == 4 )
          {
            v51 = v48 - 4;
            v47 = v144;
            LODWORD(v14) = v51;
            if ( v51 <= 1u )
            {
              v52 = v51;
              v53 = v144 + 320;
              v54 = *(_QWORD *)(v144 + 320 + 8LL * v51);
              if ( v54 )
              {
                _qdf_mem_free(v54);
                v53 = v144 + 320;
                v52 = v51;
                v47 = v144;
              }
              *(_QWORD *)(v53 + 8 * v52) = v50;
              v55 = *a2;
              *(_BYTE *)(v47 + 421) = v51;
              *(_DWORD *)(v47 + 416) = v55;
              goto LABEL_112;
            }
          }
          else
          {
            v94 = v48 - 6;
            v47 = v144;
            LODWORD(v14) = v94;
            if ( v94 <= 1u )
            {
              v95 = v94;
              v96 = v144 + 336;
              v97 = *(_QWORD *)(v144 + 336 + 8LL * v94);
              if ( v97 )
              {
                _qdf_mem_free(v97);
                v96 = v144 + 336;
                v95 = v94;
                v47 = v144;
              }
              *(_QWORD *)(v96 + 8 * v95) = v50;
              *(_BYTE *)(v47 + 422) = v94;
LABEL_112:
              *(_QWORD *)(v50 + 32) = v17;
              *(_BYTE *)v50 = a2[4];
              *(_WORD *)(v50 + 2) = *((_WORD *)a2 + 3);
              v99 = *((unsigned __int16 *)a2 + 1);
              if ( v99 == 0xFFFF )
                LOWORD(v99) = 0;
              *(_WORD *)(v50 + 4) = v99;
              if ( (*((_WORD *)a2 + 3) & 0x80) != 0 )
              {
                v100 = *a2 - 6;
                if ( v100 < 7 && ((0x65u >> v100) & 1) != 0 )
                {
                  v101 = 0xC0B0606080606uLL >> (8 * (v100 & 0x1F));
                  goto LABEL_120;
                }
                *(_BYTE *)(v47 + 420) = v99;
                *(_WORD *)(v50 + 2) |= 0x80u;
              }
              LOBYTE(v101) = *a2;
LABEL_120:
              v147 = v47;
              if ( (unsigned __int8)v101 == 13 || (unsigned __int8)v101 == 4 )
              {
                qmemcpy(v151, "\\6\\6\\6\\6\\6\\6\\6\\7", 16);
                if ( v22 == 1 )
                  v102 = v151;
                else
                  v102 = v150;
                if ( v22 == 1 )
                  v103 = v150;
                else
                  v103 = v151;
                qmemcpy(v150, "\\6\\6\\6\\6\\6\\6\\6\\6", sizeof(v150));
                if ( v22 == 1 )
                  v104 = 57;
                else
                  v104 = 56;
                *((_BYTE *)v102 + 15) = v104;
                qdf_mem_copy((void *)(v50 + 64), v103, 0x10u);
                v105 = (void *)(v50 + 80);
                v106 = v102;
                v107 = 16;
              }
              else
              {
                qdf_mem_copy((void *)(v50 + 96), a2 + 24, 8u);
                qdf_mem_copy((void *)(v50 + 104), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 112), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 120), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 128), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 136), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 144), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 152), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 160), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 168), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 176), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 184), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 192), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 200), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 208), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 216), a2 + 16, 8u);
                qdf_mem_copy((void *)(v50 + 224), a2 + 16, 8u);
                v105 = (void *)(v50 + 232);
                v106 = a2 + 16;
                v107 = 8;
              }
              qdf_mem_copy(v105, v106, v107);
              v116 = *(_QWORD *)(v25 + 2128);
              if ( !v116 )
              {
                qdf_trace_msg(
                  0x1Cu,
                  2u,
                  "%s: tx_ops is NULL",
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  "wlan_crypto_setkey");
                result = 4;
                goto LABEL_154;
              }
              qdf_mem_copy((void *)(v50 + 384), a2 + 32, 0x30u);
              *(_BYTE *)(v50 + 1) = 1;
              v117 = *a2;
              if ( v117 > 0xE )
                goto LABEL_160;
              if ( ((1 << v117) & 0x1940) != 0 )
              {
                v118 = v147;
                if ( (*(_BYTE *)(v147 + 17) & 0x40) != 0 || (*((_WORD *)a2 + 1) & 0xFFFE) == 6 )
                {
                  v119 = *(void (__fastcall **)(__int64, __int64, int *))(v116 + 712);
                  if ( v119 )
                  {
                    if ( *((_DWORD *)v119 - 1) != -871156935 )
                      __break(0x8228u);
                    v119(a1, v50, &v148);
                    v118 = v147;
                    LOBYTE(v117) = *a2;
                  }
                }
                wlan_crypto_set_mgmtcipher(v118, (unsigned int)(1 << v117));
                result = 0;
                goto LABEL_143;
              }
              if ( v117 == 14 )
              {
                *(_QWORD *)(v50 + 40) = a2;
                result = 4;
              }
              else
              {
LABEL_160:
                v125 = *(__int64 (__fastcall **)(__int64, __int64, int *))(v116 + 712);
                if ( v125 )
                {
                  if ( *((_DWORD *)v125 - 1) != -871156935 )
                    __break(0x8228u);
                  v126 = v125(a1, v50, &v148);
                  result = 4;
                  if ( v126 )
                  {
LABEL_154:
                    if ( !v36 )
                      goto LABEL_6;
                    goto LABEL_157;
                  }
                }
                else
                {
                  result = 4;
                }
              }
LABEL_143:
              if ( v17 )
              {
                v120 = *(__int64 (__fastcall **)(_QWORD))(v17 + 24);
                if ( *((_DWORD *)v120 - 1) != -1018027511 )
                  __break(0x8228u);
                result = v120(v50);
              }
              if ( (*((_WORD *)a2 + 3) & 0x80) != 0 )
              {
                v121 = *((unsigned __int16 *)a2 + 1);
                if ( (_DWORD)v121 != 0xFFFF )
                {
                  v122 = *a2;
                  if ( (v122 > 0xC || ((1 << v122) & 0x1940) == 0) && (v16 & 1) != 0 )
                  {
                    v123 = result;
                    wlan_crypto_default_key(a1, v15, v121, 0);
                    result = v123;
                  }
                }
              }
              goto LABEL_154;
            }
          }
        }
        v59 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
        if ( !v59 )
        {
          qdf_trace_msg(
            0x1Cu,
            2u,
            "%s: crypto_priv NULL",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "wlan_crypto_vdev_get_comp_params");
          v57 = "%s: crypto_priv NULL";
          goto LABEL_54;
        }
        v12 = *a2;
        v47 = v59;
        v60 = v59 + 288;
        if ( v12 <= 0xE )
          break;
LABEL_79:
        if ( *a2 && (*(_DWORD *)(v59 + 8) & (1 << v12)) == 0 )
        {
          v78 = v59;
          qdf_trace_msg(
            0x1Cu,
            2u,
            "%s: Set BroadCast key without Mcast cipher set for %d",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "wlan_crypto_setkey");
          v47 = v78;
        }
        LODWORD(v14) = *((unsigned __int16 *)a2 + 1);
        if ( (unsigned int)v14 <= 3 )
        {
          v50 = *(_QWORD *)(v60 + 8LL * *((unsigned __int16 *)a2 + 1));
          if ( v50 )
            goto LABEL_88;
          v79 = v47;
          v80 = _qdf_mem_malloc(0x1B0u, "wlan_crypto_setkey", 896);
          v14 = *((unsigned __int16 *)a2 + 1);
          if ( v14 <= 3 )
          {
            *(_QWORD *)(v60 + 8 * v14) = v80;
            LODWORD(v14) = *((unsigned __int16 *)a2 + 1);
            if ( (unsigned int)v14 <= 3 )
            {
              v50 = *(_QWORD *)(v60 + 8LL * *((unsigned __int16 *)a2 + 1));
              if ( !v50 )
              {
LABEL_89:
                result = 2;
                goto LABEL_6;
              }
              v47 = v79;
LABEL_88:
              v63 = 0;
              v66 = 0;
              *(_BYTE *)(v47 + 420) = v14;
              goto LABEL_95;
            }
          }
        }
      }
      if ( ((1 << v12) & 0x1940) == 0 )
      {
        if ( v12 == 14 )
        {
          v68 = "%s: FILS key is not for BroadCast pkt";
LABEL_71:
          qdf_trace_msg(0x1Cu, 2u, v68, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_setkey");
          result = 53;
          goto LABEL_6;
        }
        goto LABEL_79;
      }
      v61 = *((_WORD *)a2 + 1);
      if ( (v61 & 0xFFFC | 2) != 6 )
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: igtk/bigtk key invalid keyid %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_crypto_setkey",
          *((unsigned __int16 *)a2 + 1));
        result = 52;
        goto LABEL_6;
      }
      v145 = v59;
      v62 = _qdf_mem_malloc(0x1B0u, "wlan_crypto_setkey", 859);
      if ( !v62 )
        goto LABEL_89;
      v50 = v62;
      if ( (*((_WORD *)a2 + 1) & 0xFFFE) != 4 )
        break;
      v63 = v61 - 4;
      v47 = v145;
      LODWORD(v14) = (unsigned __int8)(v61 - 4);
      if ( (unsigned int)v14 <= 1 )
      {
        v64 = (unsigned __int8)(v61 - 4);
        v65 = *(_QWORD *)(v145 + 320 + 8LL * v63);
        if ( v65 )
        {
          v138 = v63;
          _qdf_mem_free(v65);
          v63 = v138;
          v47 = v145;
        }
        *(_QWORD *)(v145 + 320 + 8 * v64) = v50;
        v66 = 0;
        v67 = *a2;
        *(_BYTE *)(v47 + 421) = v63;
        *(_DWORD *)(v47 + 416) = v67;
        goto LABEL_95;
      }
    }
    v66 = v61 - 6;
    v47 = v145;
    LODWORD(v14) = (unsigned __int8)(v61 - 6);
    if ( (unsigned int)v14 <= 1 )
    {
      v81 = (unsigned __int8)(v61 - 6);
      v82 = *(_QWORD *)(v145 + 336 + 8LL * v66);
      if ( v82 )
      {
        v140 = v66;
        _qdf_mem_free(v82);
        v66 = v140;
        v47 = v145;
      }
      *(_QWORD *)(v145 + 336 + 8 * v81) = v50;
      v63 = 0;
      *(_BYTE *)(v47 + 422) = v66;
LABEL_95:
      if ( v22 )
      {
        v36 = 0;
        goto LABEL_112;
      }
      v139 = v63;
      v141 = v66;
      v142 = v60;
      v83 = v47;
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 19);
      if ( bsspeer )
      {
        v93 = bsspeer;
        qdf_mem_copy(&v148, (const void *)(bsspeer + 48), 6u);
        wlan_objmgr_peer_release_ref(v93, 19);
        v36 = 0;
        v47 = v83;
        goto LABEL_112;
      }
      qdf_trace_msg(0x1Cu, 2u, "%s: peer NULL", v85, v86, v87, v88, v89, v90, v91, v92, "wlan_crypto_setkey");
      v127 = *a2;
      if ( v127 <= 0xC && ((1 << v127) & 0x1940) != 0 )
      {
        *(_QWORD *)(v83 + 8LL * v139 + 320) = 0;
        *(_QWORD *)(v83 + 8LL * v141 + 336) = 0;
        *(_DWORD *)(v83 + 416) = 17;
        goto LABEL_168;
      }
      v14 = *((unsigned __int16 *)a2 + 1);
      if ( v14 <= 3 )
        break;
    }
  }
  *(_QWORD *)(v142 + 8 * v14) = 0;
LABEL_168:
  _qdf_mem_free(v50);
LABEL_5:
  result = 4;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
