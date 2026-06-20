__int64 __fastcall policy_mgr_update_hw_mode_list(__int64 a1, __int64 a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int64 v40; // x27
  unsigned int v41; // w20
  __int64 v42; // x21
  int *v43; // x24
  unsigned int v44; // w25
  __int64 v45; // x2
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  _BOOL4 v54; // w19
  int v56; // w21
  char v57; // w25
  char v58; // w22
  char v59; // w23
  char v60; // w20
  char v61; // w28
  int v62; // w24
  char v63; // w26
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x9
  _BOOL4 v74; // w21
  unsigned __int64 v75; // x9
  _BOOL4 v76; // w22
  __int64 v77; // x10
  __int64 v78; // x8
  __int64 v79; // x9
  char v80; // w19
  char v81; // w20
  char v82; // w26
  __int64 v83; // x0
  __int64 v84; // x24
  __int64 result; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // [xsp+0h] [xbp-70h]
  __int64 v95; // [xsp+8h] [xbp-68h]
  unsigned __int8 v96; // [xsp+14h] [xbp-5Ch]
  __int64 v97; // [xsp+18h] [xbp-58h]
  _BOOL4 v98; // [xsp+20h] [xbp-50h]
  unsigned int v99; // [xsp+24h] [xbp-4Ch]
  __int64 v101; // [xsp+34h] [xbp-3Ch] BYREF
  int v102; // [xsp+3Ch] [xbp-34h]
  __int64 v103; // [xsp+40h] [xbp-30h]
  __int64 v104; // [xsp+48h] [xbp-28h] BYREF
  __int64 v105; // [xsp+50h] [xbp-20h]
  int v106; // [xsp+58h] [xbp-18h]
  _QWORD v107[2]; // [xsp+60h] [xbp-10h] BYREF

  v107[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v106 = 0;
  v104 = 0;
  v105 = 0;
  v103 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *(_DWORD *)(a2 + 824) )
    {
      v12 = context;
      v13 = *(_QWORD *)(context + 1192);
      if ( v13 )
      {
        _qdf_mem_free(v13);
        *(_QWORD *)(v12 + 1192) = 0;
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: DBS list is freed",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "policy_mgr_update_hw_mode_list");
      }
      qdf_mem_set((void *)(v12 + 1204), 0x100u, 0);
      qdf_mem_set((void *)(v12 + 1460), 0x20u, 0);
      v22 = *(unsigned int *)(a2 + 824);
      *(_DWORD *)(v12 + 1184) = v22;
      v23 = _qdf_mem_malloc(8 * v22, "policy_mgr_update_hw_mode_list", 1683);
      *(_QWORD *)(v12 + 1192) = v23;
      if ( v23 )
      {
        *(_DWORD *)(v12 + 1528) = 0;
        qdf_mem_set((void *)(v12 + 1532), 0x80u, 0);
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Updated HW mode list: Num modes:%d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "policy_mgr_update_hw_mode_list",
          *(unsigned int *)(v12 + 1184));
        if ( *(_DWORD *)(v12 + 1184) )
        {
          v40 = 0;
          v41 = 0;
          v97 = a2 + 1072;
          v94 = v12;
          while ( 1 )
          {
            if ( v41 >= 9 )
LABEL_76:
              __break(0x5512u);
            v42 = v41 + 1;
            v43 = (int *)(v97 + ((unsigned __int64)v41 << 8));
            policy_mgr_get_hw_mode_params(v43, (__int64)&v104, v32, v33, v34, v35, v36, v37, v38, v39);
            v44 = v43[4];
            v45 = (unsigned int)v43[2];
            v101 = 0;
            v102 = 0;
            if ( (v44 & 0x7FFFFFF) - 8 <= 2 )
              break;
            policy_mgr_update_mac_freq_info(v12, v44, v45, v43);
            if ( v44 > 5 || ((1 << v44) & 0x2E) == 0 )
              goto LABEL_13;
            if ( (unsigned int)v42 > 8 )
              goto LABEL_76;
            v43 = (int *)(v97 + (v42 << 8));
            policy_mgr_get_hw_mode_params(v43, (__int64)&v101, v46, v47, v48, v49, v50, v51, v52, v53);
            policy_mgr_update_mac_freq_info(v12, v44, (unsigned int)v43[2], v43);
            v98 = ((v44 - 1) & 0xFFFFFFFB) == 0;
            v99 = v41 + 2;
            if ( (!*(_DWORD *)(v12 + 1268) && !*(_DWORD *)(v12 + 1276)
               || !*(_DWORD *)(v12 + 1284) && !*(_DWORD *)(v12 + 1292))
              && (!*(_DWORD *)(v12 + 1200)
               || !*(_DWORD *)(v12 + 1332) && !*(_DWORD *)(v12 + 1340)
               || !*(_DWORD *)(v12 + 1348) && !*(_DWORD *)(v12 + 1356)
               || !*(_DWORD *)(v12 + 1300) && !*(_DWORD *)(v12 + 1308)
               || !*(_DWORD *)(v12 + 1316) && !*(_DWORD *)(v12 + 1324)) )
            {
              goto LABEL_44;
            }
            v95 = 0;
            v54 = v44 == 5 || (v44 & 6) == 2;
LABEL_45:
            v56 = v104;
            v57 = BYTE4(v104);
            v58 = v105;
            v59 = BYTE4(v105);
            v61 = v101;
            v60 = BYTE4(v101);
            v62 = *v43;
            v63 = v102;
            v64 = policy_mgr_get_context(a1);
            v96 = v56;
            if ( v64 )
            {
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFFFFFuLL;
              v73 = (unsigned int)(v56 << 28);
              v74 = v54;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= v73;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xF0FFFFFFuLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= (unsigned __int64)(v57 & 0xF) << 24;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFF0FFFuLL;
              v75 = (unsigned __int64)(v58 & 0xF) << 12;
              v76 = v98;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= v75;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFF0FFFFFuLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= (unsigned __int64)(v61 & 0xF) << 20;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFF0FFFFuLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= (unsigned __int64)(v60 & 0xF) << 16;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFFF0FFuLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= (unsigned __int64)(v63 & 0xF) << 8;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFFFF7FuLL;
              v77 = 128;
              if ( !v98 )
                v77 = 0;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= v77;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFFFFBFuLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFFFFDFuLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= (unsigned int)(32 * v54);
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFFFFE7uLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= 8LL * (v59 & 3);
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= 0xFFFFFFF8uLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= v62 & 7;
              v78 = *(_QWORD *)(v64 + 1192);
              v79 = (unsigned int)*(_QWORD *)(v78 + 8 * v40);
              *(_QWORD *)(v78 + 8 * v40) >>= 32;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) &= ~1uLL;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= v95;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) <<= 32;
              *(_QWORD *)(*(_QWORD *)(v64 + 1192) + 8 * v40) |= v79;
            }
            else
            {
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: Invalid Context",
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                "policy_mgr_set_hw_mode_params");
              v76 = v98;
              v74 = v54;
            }
            v80 = v106;
            v81 = v103;
            v82 = BYTE4(v103);
            v107[0] = 0;
            v83 = policy_mgr_get_context(a1);
            if ( v83 )
            {
              v84 = v83;
              if ( !v74 && !v76 )
              {
                if ( (v59 & 1) != 0 )
                {
                  LODWORD(v107[0]) = 0;
                  WORD2(v107[0]) = 1;
                  HIWORD(v107[0]) = v96;
                  ((void (__fastcall *)(__int64, _QWORD *))policy_mgr_add_radio_comb)(v83, v107);
                }
                if ( (v59 & 2) == 0 )
                  goto LABEL_9;
                LODWORD(v107[0]) = 0;
                WORD2(v107[0]) = 2;
                HIWORD(v107[0]) = v96;
                ((void (__fastcall *)(__int64, _QWORD *))policy_mgr_add_radio_comb)(v84, v107);
                if ( (v80 & 1) == 0 )
                  goto LABEL_9;
                LODWORD(v107[0]) = 0;
                WORD2(v107[0]) = 4;
                HIWORD(v107[0]) = v96;
                goto LABEL_70;
              }
              if ( (v59 & 1) != 0 && (v81 & 2) != 0 )
              {
                LODWORD(v107[0]) = 1;
                WORD2(v107[0]) = 513;
                BYTE6(v107[0]) = v96;
                HIBYTE(v107[0]) = v61;
                ((void (__fastcall *)(__int64, _QWORD *))policy_mgr_add_radio_comb)(v83, v107);
                if ( (v82 & 1) != 0 )
                {
                  LODWORD(v107[0]) = 1;
                  WORD2(v107[0]) = 1025;
                  BYTE6(v107[0]) = v96;
                  HIBYTE(v107[0]) = v61;
                  ((void (__fastcall *)(__int64, _QWORD *))policy_mgr_add_radio_comb)(v84, v107);
                }
              }
              if ( (v59 & 2) == 0 )
                goto LABEL_9;
              if ( (v81 & 1) != 0 )
              {
                LODWORD(v107[0]) = 1;
                WORD2(v107[0]) = 513;
                BYTE6(v107[0]) = v61;
                HIBYTE(v107[0]) = v96;
                ((void (__fastcall *)(__int64, _QWORD *))policy_mgr_add_radio_comb)(v84, v107);
                if ( (v80 & 1) != 0 )
                {
                  LODWORD(v107[0]) = 1;
                  WORD2(v107[0]) = 1025;
                  BYTE6(v107[0]) = v61;
                  HIBYTE(v107[0]) = v96;
                  ((void (__fastcall *)(__int64, _QWORD *))policy_mgr_add_radio_comb)(v84, v107);
                }
              }
              if ( (v81 & 2) == 0 )
                goto LABEL_9;
              if ( (v80 & 1) != 0 )
              {
                BYTE6(v107[0]) = v61;
                LODWORD(v107[0]) = 2;
                WORD2(v107[0]) = 1026;
                HIBYTE(v107[0]) = v96;
LABEL_70:
                ((void (__fastcall *)(__int64, _QWORD *))policy_mgr_add_radio_comb)(v84, v107);
                goto LABEL_9;
              }
              if ( (v82 & 1) != 0 )
              {
                BYTE6(v107[0]) = v96;
                LODWORD(v107[0]) = 2;
                WORD2(v107[0]) = 1026;
                HIBYTE(v107[0]) = v61;
                goto LABEL_70;
              }
            }
            else
            {
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: Invalid Context",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "policy_mgr_update_radio_combination_matrix");
            }
LABEL_9:
            v12 = v94;
            ++v40;
            v41 = v99;
            if ( v40 >= *(unsigned int *)(v94 + 1184) )
              goto LABEL_72;
          }
          policy_mgr_update_mac_freq_info(v12, v44 & 0x7FFFFFF, v45, v43);
          v44 &= 0x7FFFFFFu;
LABEL_13:
          if ( (v44 & 0xFFFFFFFD) == 8 )
          {
            if ( v40 > 8 || (unsigned int)v42 > 8 )
              goto LABEL_76;
            v99 = v41 + 2;
            v43 = (int *)(v97 + (v42 << 8));
            policy_mgr_get_hw_mode_params(v43, (__int64)&v101, v46, v47, v48, v49, v50, v51, v52, v53);
            policy_mgr_update_mac_freq_info(v12, v44, (unsigned int)v43[2], v43);
            v98 = 0;
            v54 = 0;
            goto LABEL_42;
          }
          if ( v44 == 9 )
          {
            if ( v40 > 8 )
              goto LABEL_76;
            policy_mgr_get_hw_mode_params(v43, (__int64)&v101, v46, v47, v48, v49, v50, v51, v52, v53);
            v54 = 0;
            v98 = 0;
            v99 = v41 + 1;
LABEL_42:
            v95 = 1;
            goto LABEL_45;
          }
          v98 = 0;
          v99 = v41 + 1;
LABEL_44:
          v54 = 0;
          v95 = 0;
          goto LABEL_45;
        }
LABEL_72:
        v86 = ((double (__fastcall *)(__int64, _QWORD))policy_mgr_fill_curr_mac_freq_by_hwmode)(v12, 0);
        policy_mgr_dump_freq_range((_DWORD *)v12, v86, v87, v88, v89, v90, v91, v92, v93);
        result = 0;
      }
      else
      {
        *(_DWORD *)(v12 + 1184) = 0;
        result = 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Number of HW modes: %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "policy_mgr_update_hw_mode_list",
        0);
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_update_hw_mode_list");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
