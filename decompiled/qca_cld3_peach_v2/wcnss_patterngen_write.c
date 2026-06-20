size_t __fastcall wcnss_patterngen_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  __int64 v5; // x8
  __int64 v6; // x22
  int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  char *v45; // x20
  char *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  char *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned __int16 v64; // w0
  unsigned int v65; // w25
  const char *v66; // x2
  __int64 v67; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x23
  int v77; // w9
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x0
  __int64 v87; // x21
  __int64 v88; // x0
  unsigned __int16 *v89; // x24
  unsigned __int64 v90; // x23
  int v91; // w8
  __int64 v92; // x9
  const char *v93; // x22
  char v94; // w0
  unsigned int v95; // w8
  const char *v96; // x25
  char v97; // w22
  char v98; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned __int64 v107; // x9
  char v108; // w10
  char *v109; // x11
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  const char *s; // [xsp+8h] [xbp-28h]
  __int64 *v127; // [xsp+10h] [xbp-20h] BYREF
  char v128[4]; // [xsp+18h] [xbp-18h] BYREF
  char v129[4]; // [xsp+1Ch] [xbp-14h] BYREF
  char *stringp[2]; // [xsp+20h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v127 = nullptr;
  v6 = *(_QWORD *)(v5 + 696);
  v7 = _osif_vdev_sync_op_start(v6, &v127, (__int64)"wcnss_patterngen_write");
  if ( !v7 )
  {
    stringp[0] = nullptr;
    v129[0] = 0;
    v128[0] = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v8, v9, v10, v11, v12, v13, v14, v15, "__wcnss_patterngen_write");
    if ( *(_DWORD *)(v6 + 2688) == 1885692259 )
    {
      v24 = *(_QWORD *)(v6 + 2712);
      v25 = _wlan_hdd_validate_context(v24, (__int64)"__wcnss_patterngen_write", v16, v17, v18, v19, v20, v21, v22, v23);
      if ( v25 )
      {
        a3 = v25;
LABEL_9:
        _osif_vdev_sync_op_stop((__int64)v127, (__int64)"wcnss_patterngen_write");
        goto LABEL_10;
      }
      if ( !wlan_hdd_validate_modules_state(v24, v26, v27, v28, v29, v30, v31, v32, v33) )
        goto LABEL_8;
      if ( (sme_is_feature_supported_by_fw(28) & 1) != 0 )
      {
        if ( a3 <= 0x1000 )
        {
          v36 = _qdf_mem_malloc(a3 + 1, "__wcnss_patterngen_write", 265);
          if ( !v36 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Memory allocation for cmd failed!",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "__wcnss_patterngen_write");
            a3 = -12;
            goto LABEL_9;
          }
          v45 = (char *)v36;
          _check_object_size(v36, a3, 0);
          if ( inline_copy_from_user_2((__int64)v45, a2, a3) )
          {
            _qdf_mem_free((__int64)v45);
            a3 = -14;
            goto LABEL_9;
          }
          v45[a3] = 0;
          stringp[0] = v45;
          v46 = strsep(stringp, " ");
          if ( !v46 || (unsigned int)kstrtou8(v46, 0, v129) )
            goto LABEL_26;
          if ( (unsigned __int8)v129[0] >= 6u )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Pattern index: %d is not in the range (0 ~ %d)",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "__wcnss_patterngen_write");
LABEL_26:
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Invalid input. Input format is: ptrn_idx duration pattern",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "__wcnss_patterngen_write");
LABEL_27:
            _qdf_mem_free((__int64)v45);
            goto LABEL_8;
          }
          v55 = strsep(stringp, " ");
          if ( !v55 || (unsigned int)kstrtou8(v55, 0, v128) )
            goto LABEL_26;
          if ( v128[0] )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: device mode %d",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "__wcnss_patterngen_write",
              *(unsigned int *)(v6 + 2728));
            if ( !*(_DWORD *)(v6 + 2728) && !hdd_cm_is_vdev_associated(*(_DWORD **)(v6 + 55520)) )
            {
              v66 = "%s: Not in Connected state!";
              goto LABEL_44;
            }
            s = strsep(stringp, " ");
            if ( !s )
              goto LABEL_26;
            s[strlen(s) - 1] = 0;
            v64 = strlen(s);
            if ( (v64 & 1) != 0 )
            {
              v66 = "%s: Malformed pattern!";
              goto LABEL_44;
            }
            v65 = v64;
            if ( (unsigned int)v64 - 3074 <= 0xFFFFF419 )
            {
              v66 = "%s: Not an 802.3 frame!";
LABEL_44:
              qdf_trace_msg(0x33u, 2u, v66, v56, v57, v58, v59, v60, v61, v62, v63, "__wcnss_patterngen_write");
              goto LABEL_26;
            }
            v88 = _qdf_mem_malloc(0x610u, "__wcnss_patterngen_write", 379);
            if ( v88 )
            {
              v89 = (unsigned __int16 *)v88;
              v90 = 0;
              v91 = 500 * (unsigned __int8)v128[0];
              *(_BYTE *)(v88 + 6) = v129[0];
              *(_WORD *)(v88 + 8) = v65 >> 1;
              v92 = v6 + 4305;
              v93 = s;
              *(_DWORD *)(v88 + 12) = v91;
              LOWORD(v91) = *(_WORD *)(v92 + 4);
              LODWORD(v92) = *(_DWORD *)v92;
              *(_WORD *)(v88 + 4) = v91;
              *(_DWORD *)v88 = v92;
              do
              {
                v94 = hex_to_bin(*(unsigned __int8 *)v93);
                v95 = *((unsigned __int8 *)v93 + 1);
                v96 = v93;
                v97 = v94;
                v98 = hex_to_bin(v95);
                if ( v90 == 1536 )
                  goto LABEL_59;
                v107 = v89[4];
                v108 = v98 + 16 * v97;
                v109 = (char *)v89 + v90++;
                v93 = v96 + 2;
                v109[16] = v108;
              }
              while ( v90 < v107 );
              if ( (unsigned int)sme_add_periodic_tx_ptrn(
                                   *(_QWORD *)(v24 + 16),
                                   v89,
                                   v99,
                                   v100,
                                   v101,
                                   v102,
                                   v103,
                                   v104,
                                   v105,
                                   v106) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: sme_add_periodic_tx_ptrn() failed!",
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  v116,
                  v117,
                  "__wcnss_patterngen_write");
                v86 = (__int64)v89;
                goto LABEL_51;
              }
              if ( (unsigned __int8)v129[0] <= 5uLL )
              {
                if ( (hdd_periodic_pattern_map[(unsigned __int8)v129[0]] & 1) == 0 )
                  hdd_periodic_pattern_map[(unsigned __int8)v129[0]] = 1;
                _qdf_mem_free((__int64)v45);
                _qdf_mem_free((__int64)v89);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: exit",
                  v118,
                  v119,
                  v120,
                  v121,
                  v122,
                  v123,
                  v124,
                  v125,
                  "__wcnss_patterngen_write");
                goto LABEL_9;
              }
              goto LABEL_59;
            }
          }
          else
          {
            if ( (unsigned __int8)v129[0] > 5uLL )
              goto LABEL_59;
            if ( (hdd_periodic_pattern_map[(unsigned __int8)v129[0]] & 1) == 0 )
            {
              v87 = jiffies;
              if ( _wcnss_patterngen_write___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: WoW pattern %d is not in the table.",
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  "__wcnss_patterngen_write");
                _wcnss_patterngen_write___last_ticks = v87;
              }
              goto LABEL_27;
            }
            v67 = _qdf_mem_malloc(7u, "__wcnss_patterngen_write", 317);
            if ( v67 )
            {
              v76 = v67;
              *(_BYTE *)(v67 + 6) = v129[0];
              v77 = *(_DWORD *)(v6 + 4305);
              *(_WORD *)(v67 + 4) = *(_WORD *)(v6 + 4309);
              *(_DWORD *)v67 = v77;
              if ( (unsigned int)sme_del_periodic_tx_ptrn(
                                   *(_QWORD *)(v24 + 16),
                                   (int *)v67,
                                   v68,
                                   v69,
                                   v70,
                                   v71,
                                   v72,
                                   v73,
                                   v74,
                                   v75) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: sme_del_periodic_tx_ptrn() failed!",
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  "__wcnss_patterngen_write");
                v86 = v76;
LABEL_51:
                _qdf_mem_free(v86);
                goto LABEL_26;
              }
              if ( (unsigned __int8)v129[0] <= 5uLL )
              {
                hdd_periodic_pattern_map[(unsigned __int8)v129[0]] = 0;
                _qdf_mem_free((__int64)v45);
                _qdf_mem_free(v76);
                goto LABEL_9;
              }
LABEL_59:
              __break(0x5512u);
              JUMPOUT(0x687780);
            }
          }
          _qdf_mem_free((__int64)v45);
          a3 = -12;
          goto LABEL_9;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command length is larger than %d bytes",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "__wcnss_patterngen_write",
          4096);
LABEL_8:
        a3 = -22;
        goto LABEL_9;
      }
      v34 = "%s: Periodic Tx Pattern Offload feature is not supported in firmware!";
    }
    else
    {
      v34 = "%s: Invalid adapter or adapter has invalid magic";
    }
    qdf_trace_msg(0x33u, 2u, v34, v16, v17, v18, v19, v20, v21, v22, v23, "__wcnss_patterngen_write");
    goto LABEL_8;
  }
  a3 = v7;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return a3;
}
