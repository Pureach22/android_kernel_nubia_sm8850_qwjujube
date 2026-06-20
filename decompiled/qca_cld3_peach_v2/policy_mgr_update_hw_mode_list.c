__int64 __fastcall policy_mgr_update_hw_mode_list(__int64 a1, __int64 a2)
{
  __int64 v3; // x26
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int64 v41; // x28
  unsigned int v42; // w23
  __int64 v43; // x8
  __int64 v44; // x21
  __int64 v45; // x22
  __int64 v46; // x19
  int *v47; // x25
  unsigned int v48; // w26
  __int64 v49; // x2
  __int64 v50; // x23
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  bool v67; // zf
  int v68; // w8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // w8
  char v78; // w20
  int v79; // w21
  char v80; // w27
  char v81; // w19
  char v82; // w26
  char v83; // w24
  char v84; // w25
  __int64 v85; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x10
  __int64 v95; // x8
  __int64 v96; // x9
  char v97; // w27
  char v98; // w24
  char v99; // w20
  __int64 v100; // x0
  __int64 v101; // x25
  char v102; // w9
  __int64 result; // x0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // [xsp+8h] [xbp-88h]
  char v113; // [xsp+10h] [xbp-80h]
  __int64 v114; // [xsp+18h] [xbp-78h]
  char v115; // [xsp+28h] [xbp-68h]
  __int64 v116; // [xsp+30h] [xbp-60h]
  unsigned int v117; // [xsp+3Ch] [xbp-54h]
  __int64 v118; // [xsp+40h] [xbp-50h]
  __int64 v119; // [xsp+4Ch] [xbp-44h]
  __int64 v120; // [xsp+54h] [xbp-3Ch] BYREF
  int v121; // [xsp+5Ch] [xbp-34h]
  __int64 v122; // [xsp+60h] [xbp-30h]
  __int64 v123; // [xsp+68h] [xbp-28h] BYREF
  __int64 v124; // [xsp+70h] [xbp-20h]
  int v125; // [xsp+78h] [xbp-18h]
  _QWORD v126[2]; // [xsp+80h] [xbp-10h] BYREF

  v3 = a1;
  v126[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v125 = 0;
  v123 = 0;
  v124 = 0;
  v122 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *(_DWORD *)(a2 + 824) )
    {
      v13 = context;
      v14 = *(_QWORD *)(context + 1192);
      if ( v14 )
      {
        _qdf_mem_free(v14);
        *(_QWORD *)(v13 + 1192) = 0;
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: DBS list is freed",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "policy_mgr_update_hw_mode_list");
      }
      qdf_mem_set((void *)(v13 + 1204), 0x100u, 0);
      qdf_mem_set((void *)(v13 + 1460), 0x20u, 0);
      v23 = *(unsigned int *)(a2 + 824);
      *(_DWORD *)(v13 + 1184) = v23;
      v24 = _qdf_mem_malloc(8 * v23, "policy_mgr_update_hw_mode_list", 1683);
      *(_QWORD *)(v13 + 1192) = v24;
      if ( v24 )
      {
        *(_DWORD *)(v13 + 1528) = 0;
        qdf_mem_set((void *)(v13 + 1532), 0x80u, 0);
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Updated HW mode list: Num modes:%d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "policy_mgr_update_hw_mode_list",
          *(unsigned int *)(v13 + 1184));
        if ( *(_DWORD *)(v13 + 1184) )
        {
          v41 = 0;
          v42 = 0;
          v43 = a2 + 1072;
          v44 = a2 + 3120;
          v116 = v43;
          v112 = v13;
          do
          {
            if ( v42 >= 9 )
LABEL_77:
              __break(0x5512u);
            v45 = v3;
            v46 = v42 + 1;
            v47 = (int *)(v116 + ((unsigned __int64)v42 << 8));
            policy_mgr_get_hw_mode_params(v47, (__int64)&v123, v33, v34, v35, v36, v37, v38, v39, v40);
            v48 = v47[4];
            v49 = (unsigned int)v47[2];
            v120 = 0;
            v121 = 0;
            v118 = v44;
            if ( (v48 & 0x7FFFFFF) - 8 > 2 )
            {
              policy_mgr_update_mac_freq_info(v13, v48, v49, v47);
              if ( v48 <= 5 && ((1 << v48) & 0x2E) != 0 )
              {
                if ( (unsigned int)v46 > 8 )
                  goto LABEL_77;
                v47 = (int *)(v116 + (v46 << 8));
                policy_mgr_get_hw_mode_params(v47, (__int64)&v120, v59, v60, v61, v62, v63, v64, v65, v66);
                policy_mgr_update_mac_freq_info(v13, v48, (unsigned int)v47[2], v47);
                v117 = v42 + 2;
                HIDWORD(v119) = ((v48 - 1) & 0xFFFFFFFB) == 0;
                if ( (*(_DWORD *)(v13 + 1268) || *(_DWORD *)(v13 + 1276))
                  && (*(_DWORD *)(v13 + 1284) || *(_DWORD *)(v13 + 1292))
                  || *(_DWORD *)(v13 + 1200)
                  && (*(_DWORD *)(v13 + 1332) || *(_DWORD *)(v13 + 1340))
                  && (*(_DWORD *)(v13 + 1348) || *(_DWORD *)(v13 + 1356))
                  && (*(_DWORD *)(v13 + 1300) || *(_DWORD *)(v13 + 1308))
                  && (*(_DWORD *)(v13 + 1316) || *(_DWORD *)(v13 + 1324)) )
                {
                  v114 = 0;
                  v67 = v48 == 5 || (v48 & 6) == 2;
                  v50 = v45;
                  v68 = v67;
                  LODWORD(v119) = v68;
                }
                else
                {
                  LODWORD(v119) = 0;
                  v50 = v45;
                  v114 = 0;
                }
                goto LABEL_46;
              }
            }
            else
            {
              policy_mgr_update_mac_freq_info(v13, v48 & 0x7FFFFFF, v49, v47);
              v48 &= 0x7FFFFFFu;
            }
            if ( (v48 & 0xFFFFFFFD) == 8 )
            {
              if ( v41 > 8 || (unsigned int)v46 > 8 )
                goto LABEL_77;
              v117 = v42 + 2;
              v50 = v45;
              v47 = (int *)(v116 + (v46 << 8));
              v51 = wlan_mlme_set_eml_params(v45, v44);
              policy_mgr_get_hw_mode_params(v47, (__int64)&v120, v51, v52, v53, v54, v55, v56, v57, v58);
              policy_mgr_update_mac_freq_info(v13, v48, (unsigned int)v47[2], v47);
              v119 = 0;
              goto LABEL_43;
            }
            if ( v48 == 9 )
            {
              if ( v41 > 8 )
                goto LABEL_77;
              v50 = v45;
              v69 = wlan_mlme_set_eml_params(v45, v44);
              policy_mgr_get_hw_mode_params(v47, (__int64)&v120, v69, v70, v71, v72, v73, v74, v75, v76);
              v119 = 0;
              v117 = v46;
LABEL_43:
              v114 = 1;
              goto LABEL_46;
            }
            v119 = 0;
            v50 = v45;
            v114 = 0;
            v117 = v46;
LABEL_46:
            v77 = *v47;
            v78 = v121;
            v79 = v123;
            v80 = BYTE4(v123);
            v82 = v124;
            v81 = BYTE4(v124);
            v84 = v120;
            v83 = BYTE4(v120);
            v113 = v77;
            v85 = policy_mgr_get_context(v50);
            v115 = v84;
            if ( v85 )
            {
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFFFFFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= (unsigned int)(v79 << 28);
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xF0FFFFFFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= (unsigned __int64)(v80 & 0xF) << 24;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFF0FFFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= (unsigned __int64)(v82 & 0xF) << 12;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFF0FFFFFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= (unsigned __int64)(v84 & 0xF) << 20;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFF0FFFFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= (unsigned __int64)(v83 & 0xF) << 16;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFFF0FFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= (unsigned __int64)(v78 & 0xF) << 8;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFFFF7FuLL;
              v94 = 128;
              if ( !HIDWORD(v119) )
                v94 = 0;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= v94;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFFFFBFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFFFFDFuLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= (unsigned int)(32 * v119);
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFFFFE7uLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= 8LL * (v81 & 3);
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= 0xFFFFFFF8uLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= v113 & 7;
              v95 = *(_QWORD *)(v85 + 1192);
              v96 = (unsigned int)*(_QWORD *)(v95 + 8 * v41);
              *(_QWORD *)(v95 + 8 * v41) >>= 32;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) &= ~1uLL;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= v114;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) <<= 32;
              *(_QWORD *)(*(_QWORD *)(v85 + 1192) + 8 * v41) |= v96;
            }
            else
            {
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: Invalid Context",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "policy_mgr_set_hw_mode_params");
            }
            v42 = v117;
            v97 = v125;
            v98 = v122;
            v99 = BYTE4(v122);
            v3 = v45;
            v126[0] = 0;
            v100 = policy_mgr_get_context(v45);
            if ( v100 )
            {
              v101 = v100;
              if ( !v119 )
              {
                if ( (v81 & 1) != 0 )
                {
                  LODWORD(v126[0]) = 0;
                  WORD2(v126[0]) = 1;
                  HIWORD(v126[0]) = (unsigned __int8)v79;
                  policy_mgr_add_radio_comb(v100, v126);
                }
                if ( (v81 & 2) == 0 )
                  goto LABEL_9;
                LODWORD(v126[0]) = 0;
                WORD2(v126[0]) = 2;
                HIWORD(v126[0]) = (unsigned __int8)v79;
                policy_mgr_add_radio_comb(v101, v126);
                if ( (v97 & 1) == 0 )
                  goto LABEL_9;
                LODWORD(v126[0]) = 0;
                WORD2(v126[0]) = 4;
                HIWORD(v126[0]) = (unsigned __int8)v79;
                goto LABEL_71;
              }
              if ( (v81 & 1) != 0 && (v98 & 2) != 0 )
              {
                LODWORD(v126[0]) = 1;
                WORD2(v126[0]) = 513;
                BYTE6(v126[0]) = v79;
                HIBYTE(v126[0]) = v115;
                policy_mgr_add_radio_comb(v100, v126);
                if ( (v99 & 1) != 0 )
                {
                  LODWORD(v126[0]) = 1;
                  WORD2(v126[0]) = 1025;
                  BYTE6(v126[0]) = v79;
                  HIBYTE(v126[0]) = v115;
                  policy_mgr_add_radio_comb(v101, v126);
                }
              }
              v102 = v115;
              if ( (v81 & 2) == 0 )
                goto LABEL_9;
              if ( (v98 & 1) != 0 )
              {
                LODWORD(v126[0]) = 1;
                WORD2(v126[0]) = 513;
                BYTE6(v126[0]) = v115;
                HIBYTE(v126[0]) = v79;
                policy_mgr_add_radio_comb(v101, v126);
                v102 = v115;
                if ( (v97 & 1) != 0 )
                {
                  LODWORD(v126[0]) = 1;
                  WORD2(v126[0]) = 1025;
                  BYTE6(v126[0]) = v115;
                  HIBYTE(v126[0]) = v79;
                  policy_mgr_add_radio_comb(v101, v126);
                  v102 = v115;
                }
              }
              if ( (v98 & 2) == 0 )
                goto LABEL_9;
              if ( (v97 & 1) != 0 )
              {
                BYTE6(v126[0]) = v102;
                LODWORD(v126[0]) = 2;
                WORD2(v126[0]) = 1026;
                HIBYTE(v126[0]) = v79;
LABEL_71:
                policy_mgr_add_radio_comb(v101, v126);
                goto LABEL_9;
              }
              if ( (v99 & 1) != 0 )
              {
                BYTE6(v126[0]) = v79;
                LODWORD(v126[0]) = 2;
                WORD2(v126[0]) = 1026;
                HIBYTE(v126[0]) = v102;
                goto LABEL_71;
              }
            }
            else
            {
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: Invalid Context",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "policy_mgr_update_radio_combination_matrix");
            }
LABEL_9:
            v13 = v112;
            ++v41;
            v44 = v118 + 184;
          }
          while ( v41 < *(unsigned int *)(v112 + 1184) );
        }
        v104 = ((double (__fastcall *)(__int64, _QWORD))policy_mgr_fill_curr_mac_freq_by_hwmode)(v13, 0);
        policy_mgr_dump_freq_range((_DWORD *)v13, v104, v105, v106, v107, v108, v109, v110, v111);
        result = 0;
      }
      else
      {
        *(_DWORD *)(v13 + 1184) = 0;
        result = 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Number of HW modes: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "policy_mgr_update_hw_mode_list",
        0);
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_update_hw_mode_list");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
