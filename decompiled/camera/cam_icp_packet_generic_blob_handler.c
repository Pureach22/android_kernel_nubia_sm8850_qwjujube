__int64 __fastcall cam_icp_packet_generic_blob_handler(unsigned int *a1, int a2, unsigned int a3, unsigned int *a4)
{
  unsigned int *v4; // x19
  const char *v6; // x20
  __int64 v7; // x21
  unsigned int *v8; // x25
  const char *v9; // x5
  __int64 v10; // x4
  _DWORD *v11; // x6
  __int64 v12; // x7
  unsigned int v13; // w23
  __int64 v15; // x0
  __int64 v16; // x1
  char v17; // w2
  __int64 v18; // x0
  unsigned __int64 v19; // x8
  __int64 v20; // x7
  __int64 v21; // x10
  const char *v22; // x8
  __int64 v23; // x11
  __int64 v24; // x12
  const char *v25; // x5
  _DWORD *v26; // x6
  __int64 v27; // x2
  __int64 v28; // x4
  __int64 v29; // x23
  int v31; // w6
  __int64 v32; // x7
  __int64 v33; // x7
  const char *v34; // x5
  _DWORD *v35; // x6
  __int64 v36; // x1
  __int64 v37; // x4
  int v38; // w8
  _DWORD *v39; // x21
  const char *v40; // x22
  unsigned int v41; // w0
  unsigned int v42; // w9
  unsigned int *v43; // x28
  unsigned int v44; // w6
  unsigned int v45; // w23
  const char *v46; // x8
  int v47; // w9
  __int64 v48; // x1
  unsigned int *v49; // x20
  int v50; // w8
  unsigned int v51; // w10
  unsigned int v52; // w10
  __int64 v53; // x6
  __int64 v54; // x1
  __int64 v55; // x2
  __int64 v56; // x4
  const char *v57; // x5
  int v58; // w0
  int v59; // w3
  int v60; // w1
  int v61; // w2
  unsigned int v62; // w0
  __int16 v63; // w8
  __int64 v64; // x7
  const char *v65; // x5
  __int64 v66; // x4
  __int64 v67; // x7
  const char *v68; // x8
  _DWORD *v69; // x24
  unsigned int v70; // w9
  unsigned int v71; // w10
  unsigned int v72; // w11
  char *v73; // x9
  unsigned int *v74; // x10
  __int64 v75; // x11
  __int64 v76; // x11
  int v77; // w10
  int v78; // w9
  const char *v79; // x28
  int v80; // [xsp+48h] [xbp-58h]
  __int64 v81; // [xsp+50h] [xbp-50h] BYREF
  __int64 v82; // [xsp+58h] [xbp-48h] BYREF
  __int64 v83; // [xsp+60h] [xbp-40h]
  __int64 v84; // [xsp+68h] [xbp-38h]
  __int64 v85; // [xsp+70h] [xbp-30h]
  __int64 v86; // [xsp+78h] [xbp-28h]
  __int64 v87; // [xsp+80h] [xbp-20h]
  __int64 v88; // [xsp+88h] [xbp-18h]
  int v89; // [xsp+90h] [xbp-10h]
  __int64 v90; // [xsp+98h] [xbp-8h]

  v4 = a4;
  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v89 = 0;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v82 = 0;
  v81 = 0;
  if ( !a3 || !a4 )
  {
    v9 = "Invalid blob info %pK %d";
    v10 = 7027;
    v11 = a4;
LABEL_10:
    v12 = a3;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _DWORD *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_packet_generic_blob_handler",
      v10,
      v9,
      v11,
      v12);
LABEL_12:
    v13 = -22;
    goto LABEL_13;
  }
  v6 = *(const char **)a1;
  v7 = a1[2];
  v8 = (unsigned int *)(*(_QWORD *)a1 + 28672LL);
  if ( a2 > 3 )
  {
    if ( a2 <= 5 )
    {
      if ( a2 != 4 )
      {
        if ( (v7 & 0x80000000) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_process_generic_blob_clk_v2",
            6918,
            "Invalid index %d",
            v7);
          goto LABEL_154;
        }
        if ( a3 <= 0x4F )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, __int64))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_process_generic_blob_clk_v2",
            6925,
            "%s: Mismatch blob size %d expected %lu",
            v6 + 29824,
            a3,
            80);
LABEL_154:
          v65 = "Failed at processing generic blob clk v2, rc: %d";
          v66 = 7046;
          goto LABEL_155;
        }
        v32 = *(unsigned int *)(*(_QWORD *)a1 + 29228LL);
        if ( (_DWORD)v32 != 2 )
        {
          if ( (_DWORD)v32 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_process_generic_blob_clk_v2",
              6935,
              "%s: Mismatch blob versions %d expected v2 %d",
              v6 + 29824,
              v32,
              2);
            goto LABEL_154;
          }
          *(_DWORD *)(*(_QWORD *)a1 + 29228LL) = 2;
        }
        v33 = a4[5];
        if ( (unsigned int)v33 >= 0xD )
        {
          v34 = "%s: Invalid num paths: %d";
          v35 = v6 + 29824;
          v36 = 0x2000000;
          v37 = 6942;
LABEL_153:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _DWORD *, __int64))cam_print_log)(
            3,
            v36,
            1,
            "cam_icp_process_generic_blob_clk_v2",
            v37,
            v34,
            v35,
            v33);
          goto LABEL_154;
        }
        v64 = (unsigned int)(v33 - 1);
        if ( (unsigned int)v64 >= 0x4924924 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, __int64))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_process_generic_blob_clk_v2",
            6954,
            "%s: Size exceeds limit paths:%u size per path:%lu",
            v6 + 29824,
            v64,
            56);
          goto LABEL_154;
        }
        v19 = 56LL * (unsigned int)v64 + 80;
        if ( v19 > a3 )
        {
          v34 = "%s: Invalid blob size: %u";
          v35 = v6 + 29824;
          v36 = 256;
          v37 = 6963;
          v33 = a3;
          goto LABEL_153;
        }
        if ( (unsigned int)v7 < 0x29 )
        {
          v67 = *(_QWORD *)a4;
          v68 = &v6[504 * (unsigned int)v7];
          *((_QWORD *)v68 + 768) = *(_QWORD *)a4;
          v69 = v68 + 6144;
          v70 = a4[2];
          *((_DWORD *)v68 + 1538) = v70;
          v71 = a4[3];
          *((_DWORD *)v68 + 1539) = v71;
          v72 = a4[5];
          *((_DWORD *)v68 + 1541) = v72;
          if ( v72 )
          {
            v19 = 0;
            v73 = (char *)&v6[504 * (unsigned int)v7 + 6200];
            v74 = a4 + 7;
            do
            {
              if ( v19 == 12 )
                goto LABEL_172;
              ++v19;
              *((_DWORD *)v73 - 8) = *(v74 - 1);
              *((_DWORD *)v73 - 7) = *v74;
              *((_DWORD *)v73 - 6) = v74[1];
              *((_DWORD *)v73 - 5) = 0;
              *((_QWORD *)v73 - 2) = *(_QWORD *)(v74 + 3);
              *((_QWORD *)v73 - 1) = *(_QWORD *)(v74 + 5);
              v75 = *(_QWORD *)(v74 + 7);
              v74 += 14;
              *(_QWORD *)v73 = v75;
              v73 += 40;
            }
            while ( v19 < a4[5] );
            v70 = v69[2];
            v71 = v69[3];
            v67 = *(_QWORD *)v69;
            LODWORD(v19) = v69[5];
          }
          else
          {
            LODWORD(v19) = 0;
          }
          v76 = (__int64)&v6[32 * v7 + 4864];
          *(_QWORD *)v76 = v67;
          *(_DWORD *)(v76 + 8) = v70;
          *(_DWORD *)(v76 + 12) = v71;
          if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x2000100,
              4,
              "cam_icp_process_generic_blob_clk_v2",
              6994,
              "%s: budget=%llu, frame_cycle=%u, rt_flag=%d, num_paths=%d, index=%d, ctx_data=%pK",
              v6 + 29824,
              v67,
              v70,
              v71,
              v19,
              v7,
              v6);
            LODWORD(v19) = v69[5];
            if ( (_DWORD)v19 )
              goto LABEL_166;
          }
          else if ( (_DWORD)v19 )
          {
LABEL_166:
            v77 = debug_priority;
            v78 = debug_mdl;
            v4 = nullptr;
            v79 = &v6[504 * (unsigned int)v7 + 6200];
            while ( 1 )
            {
              if ( (v78 & 0x2000100) != 0 && !v77 )
              {
                if ( (unsigned __int64)v4 > 0xB )
                  goto LABEL_172;
                ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v78 & 0x2000100,
                  4,
                  "cam_icp_process_generic_blob_clk_v2",
                  7004,
                  "%s: [%d] : path_type=%d, trans_type=%d, camnoc=%lld, mnoc_ab=%lld, mnoc_ib=%lld",
                  v6 + 29824,
                  (_DWORD)v4,
                  *((_DWORD *)v79 - 6),
                  *((_DWORD *)v79 - 7),
                  *((_QWORD *)v79 - 2),
                  *((_QWORD *)v79 - 1),
                  *(_QWORD *)v79);
                v78 = debug_mdl;
                v77 = debug_priority;
                LODWORD(v19) = v69[5];
              }
              v4 = (unsigned int *)((char *)v4 + 1);
              v13 = 0;
              v79 += 40;
              if ( (unsigned __int64)v4 >= (unsigned int)v19 )
                goto LABEL_13;
            }
          }
LABEL_175:
          v13 = 0;
          goto LABEL_13;
        }
        goto LABEL_172;
      }
      v12 = a4[1];
      if ( (_DWORD)v12 )
      {
        LOWORD(v19) = debug_mdl;
        if ( (debug_mdl & 0x100) == 0 || debug_priority )
          goto LABEL_43;
        goto LABEL_173;
      }
      v9 = "%s: Invalid number of regions for FW unmap %u";
      v11 = v6 + 29824;
      v10 = 7092;
      goto LABEL_11;
    }
    if ( a2 == 6 )
    {
      if ( (cam_presil_mode_enabled(a1) & 1) == 0 )
        goto LABEL_175;
      if ( v4[1] )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
          3,
          256,
          3,
          "cam_icp_packet_generic_blob_handler",
          7117,
          "%s: Pre-sil Hangdump enabled %u entries index %d",
          v6 + 29824);
        v13 = cam_icp_process_presil_hangdump_info(v6, v4, (unsigned int)v7);
        goto LABEL_13;
      }
      v25 = "%s: Pre-sil Hangdump disabled %u";
      v26 = v6 + 29824;
      v27 = 3;
      v28 = 7112;
LABEL_39:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _DWORD *))cam_print_log)(
        3,
        256,
        v27,
        "cam_icp_packet_generic_blob_handler",
        v28,
        v25,
        v26);
      goto LABEL_175;
    }
    if ( a2 == 7 )
    {
      if ( a3 <= 0x47 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_packet_generic_blob_handler",
          7128,
          "%s: Mismatch blob size %d expected %lu",
          v6 + 29824,
          a3,
          72);
        goto LABEL_12;
      }
      v31 = *a4;
      if ( ((unsigned __int64)(*a4 - 1) << 6) + 72 > a3 )
      {
        v9 = "%s: Invalid blob size: %u";
        v11 = v6 + 29824;
        v10 = 7139;
        goto LABEL_10;
      }
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_packet_generic_blob_handler",
          7146,
          "num of blob cache config = %d sys cache config = %d",
          v31,
          *(_DWORD *)(*(_QWORD *)a1 + 30004LL));
        if ( !*v4 )
          goto LABEL_175;
      }
      else if ( !v31 )
      {
        goto LABEL_175;
      }
      v38 = 0;
      v39 = v8 + 334;
      v40 = (const char *)(v8 + 349);
      v6 = (const char *)(v8 + 354);
      while ( 1 )
      {
        v42 = v8[333];
        v43 = &v4[16 * (__int64)v38 + 2];
        v80 = v38;
        if ( !v42 )
        {
          v44 = v43[1];
          v51 = 0;
LABEL_90:
          v50 = 0;
          v49 = &v39[5 * v51];
          *v49 = v44;
          v49[1] = v43[4];
          v49[2] = v43[5];
          v52 = v43[6];
          *((_BYTE *)v49 + 16) = 0;
          v8[333] = v42 + 1;
          v49[3] = v52;
          goto LABEL_91;
        }
        v44 = v43[1];
        if ( *v39 == v44 )
        {
          v45 = 0;
          v46 = (const char *)(v8 + 334);
        }
        else
        {
          if ( v42 == 1 )
          {
            v51 = 1;
            goto LABEL_90;
          }
          if ( v8[339] == v44 )
          {
            v45 = 1;
            v46 = (const char *)(v8 + 339);
          }
          else
          {
            if ( v42 == 2 )
            {
              v51 = 2;
              goto LABEL_90;
            }
            if ( v8[344] == v44 )
            {
              v45 = 2;
              v46 = (const char *)(v8 + 344);
            }
            else
            {
              if ( v42 == 3 )
              {
                v51 = 3;
                goto LABEL_90;
              }
              if ( *(_DWORD *)v40 == v44 )
              {
                v45 = 3;
                v46 = v40;
              }
              else
              {
                if ( v42 == 4 )
                {
                  v51 = 4;
                  goto LABEL_90;
                }
                LODWORD(v19) = *(_DWORD *)v6;
                if ( *(_DWORD *)v6 != v44 )
                {
                  if ( v42 != 5 )
                    goto LABEL_172;
                  v51 = 5;
                  goto LABEL_90;
                }
                v45 = 4;
                v46 = v6;
              }
            }
          }
        }
        v47 = debug_priority;
        v48 = debug_mdl & 0x100;
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v48,
            4,
            "cam_icp_packet_generic_blob_handler",
            7158,
            "matched scid = %d, old param: i = %d, op_type: %d mode: %d staling distance = %d",
            v44,
            v45,
            *((_DWORD *)v46 + 3),
            *((_DWORD *)v46 + 2),
            *((_DWORD *)v46 + 1));
          v47 = debug_priority;
          v48 = debug_mdl & 0x100;
          if ( (debug_mdl & 0x100) != 0 )
          {
LABEL_84:
            if ( !v47 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v48,
                4,
                "cam_icp_packet_generic_blob_handler",
                7165,
                "new param: j = %d, op_type: %d mode: %d staling distance = %d",
                v80,
                v43[6],
                v43[5],
                v43[4]);
          }
        }
        else if ( (debug_mdl & 0x100) != 0 )
        {
          goto LABEL_84;
        }
        v49 = &v39[5 * v45];
        v50 = 1;
LABEL_91:
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_llcc_sys_cache_config_util",
            6803,
            "scid_match = %d, current_info details scid_id = %d staling_distance = %d  staling_mode = %d op_type = %d activated = %d",
            v50,
            *v49,
            v49[1],
            v49[2],
            v49[3],
            *((unsigned __int8 *)v49 + 16));
          if ( !v43[3] )
            goto LABEL_97;
        }
        else if ( !v43[3] )
        {
          goto LABEL_97;
        }
        v53 = *v49;
        if ( *((_BYTE *)v49 + 16) != 1 )
        {
          v54 = 256;
          v55 = 1;
          v56 = 6819;
          v57 = "scid = %d already in deactivated state";
          goto LABEL_96;
        }
        v41 = cam_cpas_deactivate_llcc(v53);
        if ( !v41 )
        {
          *((_BYTE *)v49 + 16) = 0;
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          {
            v54 = debug_mdl & 0x100;
            v55 = 4;
            v56 = 6816;
            v57 = "llcc deactivate is success activated = %d";
            v53 = 0;
LABEL_96:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              v54,
              v55,
              "cam_icp_llcc_sys_cache_config_util",
              v56,
              v57,
              v53);
          }
LABEL_97:
          if ( v43[7] )
          {
            if ( (v49[4] & 1) != 0 )
            {
              if ( v49[1] != v43[4] || v49[3] != v43[6] || v49[2] != v43[5] )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  256,
                  1,
                  "cam_icp_llcc_sys_cache_config_util",
                  6846,
                  "configuration of llcc cache is failed scid = %d",
                  *v49);
              goto LABEL_103;
            }
            v58 = v43[1];
            *v49 = v58;
            v59 = v43[4];
            v49[1] = v59;
            v60 = v43[5];
            v49[2] = v60;
            v61 = v43[6];
            v49[3] = v61;
            v62 = cam_cpas_configure_staling_llcc(v58, v60, v61, v59);
            if ( v62 )
            {
              v13 = v62;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_llcc_sys_cache_config_util",
                6839,
                "llcc staling configuration is failing cache: %d mode %d op_type %d staling_distance %d",
                *v49,
                v49[2],
                v49[3],
                v49[1]);
LABEL_112:
              v40 = (const char *)(v8 + 349);
              goto LABEL_76;
            }
            if ( (debug_mdl & 0x100) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x100,
                4,
                "cam_icp_llcc_sys_cache_config_util",
                6843,
                "llcc configuration is success rc = %d change_params = %d",
                0,
                v43[7]);
          }
LABEL_103:
          if ( !v43[2] )
          {
            v13 = 0;
            goto LABEL_107;
          }
          if ( (v49[4] & 1) != 0 )
          {
            v13 = 0;
LABEL_107:
            v40 = (const char *)(v8 + 349);
            v6 = (const char *)(v8 + 354);
            goto LABEL_77;
          }
          v13 = cam_cpas_activate_llcc(*v49);
          if ( !v13 )
          {
            v63 = debug_mdl;
            *((_BYTE *)v49 + 16) = 1;
            if ( (v63 & 0x100) != 0 )
            {
              v40 = (const char *)(v8 + 349);
              v6 = (const char *)(v8 + 354);
              if ( !debug_priority )
              {
                ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v63 & 0x100,
                  4,
                  "cam_icp_llcc_sys_cache_config_util",
                  6860,
                  "llcc activation is success rc = %d activated = %d",
                  0,
                  1);
                v13 = 0;
              }
              goto LABEL_77;
            }
            goto LABEL_107;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_llcc_sys_cache_config_util",
            6855,
            "llcc staling activation is failing cache: %d",
            *v49);
          goto LABEL_112;
        }
        v13 = v41;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_llcc_sys_cache_config_util",
          6811,
          "llcc activation is failing cache: %d rc = %d",
          *v49,
          v41);
LABEL_76:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_packet_generic_blob_handler",
          7175,
          "%d: llcc cache configuration failed %d",
          v43[1],
          v13);
        v6 = (const char *)(v8 + 354);
LABEL_77:
        v38 = v80 + 1;
        if ( v80 + 1 >= *v4 )
          goto LABEL_13;
      }
    }
LABEL_38:
    v25 = "%s: Invalid blob type %d";
    v26 = v6 + 29824;
    v27 = 2;
    v28 = 7182;
    goto LABEL_39;
  }
  if ( a2 == 1 )
  {
    if ( (v7 & 0x80000000) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_process_generic_blob_clk",
        6874,
        "Invalid index %d",
        v7);
    }
    else
    {
      if ( (unsigned int)__ratelimit(&cam_icp_process_generic_blob_clk__rs, "cam_icp_process_generic_blob_clk") )
        v18 = 3;
      else
        v18 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        v18,
        0x2000000,
        2,
        "cam_icp_process_generic_blob_clk",
        6879,
        "Using deprecated blob type GENERIC_BLOB_CLK");
      if ( a3 == 32 )
      {
        v20 = v8[139];
        if ( (_DWORD)v20 == 1 )
        {
LABEL_34:
          if ( (unsigned int)v7 >= 0x29 )
          {
LABEL_172:
            __break(0x5512u);
LABEL_173:
            ((void (__fastcall *)(__int64, unsigned __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
              3,
              v19 & 0x100,
              4,
              "cam_icp_packet_generic_blob_handler",
              7096,
              "%s: Processing blob for unmapping %u regions",
              v6 + 29824);
LABEL_43:
            v15 = (__int64)v6;
            v16 = (__int64)v4;
            v17 = 0;
LABEL_44:
            v13 = cam_icp_process_stream_settings(v15, v16, v17);
            goto LABEL_13;
          }
          v21 = *((_QWORD *)v4 + 2);
          v22 = &v6[32 * v7];
          v23 = *(_QWORD *)v4;
          v24 = *((_QWORD *)v4 + 1);
          v13 = 0;
          *((_QWORD *)v22 + 611) = *((_QWORD *)v4 + 3);
          *((_QWORD *)v22 + 610) = v21;
          *((_QWORD *)v22 + 609) = v24;
          *((_QWORD *)v22 + 608) = v23;
          if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x2000100,
              4,
              "cam_icp_process_generic_blob_clk",
              6903,
              "%s: budget:%llu fc: %u %d BW %lld %lld",
              v6 + 29824,
              *((_QWORD *)v22 + 608),
              *((_DWORD *)v22 + 1218),
              *((_DWORD *)v22 + 1219),
              *((_QWORD *)v22 + 610),
              *((_QWORD *)v22 + 611));
            goto LABEL_175;
          }
          goto LABEL_13;
        }
        if ( !(_DWORD)v20 )
        {
          LOWORD(v19) = 1;
          v8[139] = 1;
          goto LABEL_34;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_process_generic_blob_clk",
          6893,
          "%s: Mismatch blob versions %d expected v1 %d",
          v6 + 29824,
          v20,
          1);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_process_generic_blob_clk",
          6883,
          "%s: Mismatch blob size %d expected %lu",
          v6 + 29824,
          a3,
          32);
      }
    }
    v65 = "Failed at processing generic blob clk, rc: %d";
    v66 = 7040;
LABEL_155:
    v13 = -22;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_packet_generic_blob_handler",
      v66,
      v65,
      4294967274LL);
    goto LABEL_13;
  }
  if ( a2 != 2 )
  {
    if ( a2 == 3 )
    {
      v12 = a4[1];
      if ( (_DWORD)v12 )
      {
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_packet_generic_blob_handler",
            7080,
            "%s: Processing blob for mapping %u regions",
            v6 + 29824);
        v15 = (__int64)v6;
        v16 = (__int64)v4;
        v17 = 1;
        goto LABEL_44;
      }
      v9 = "%s: Invalid number of regions for FW map %u";
      v11 = v6 + 29824;
      v10 = 7076;
      goto LABEL_11;
    }
    goto LABEL_38;
  }
  v29 = *((_QWORD *)v6 + 1);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_packet_generic_blob_handler",
      7050,
      "%s: CAM_ICP_CMD_GENERIC_BLOB_CFG_IO",
      v6 + 29824);
  if ( inline_copy_from_user_6((__int64)&v82, *v4, 0x3Cu) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_packet_generic_blob_handler",
      7055,
      "%s: Failed in copy from user",
      v6 + 29824);
    v13 = -14;
  }
  else
  {
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_packet_generic_blob_handler",
        7060,
        "%s: buf handle %d",
        v6 + 29824,
        HIDWORD(v83));
    v13 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 *, _QWORD, _QWORD))cam_mem_get_io_buf)(
            HIDWORD(v83),
            *(unsigned int *)(v29 + 148),
            *((_QWORD *)a1 + 2),
            &v81,
            0,
            0);
    if ( v13 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_packet_generic_blob_handler",
        7064,
        "%s: Failed in blob update",
        v6 + 29824);
    }
    else if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_packet_generic_blob_handler",
        7067,
        "%s: io buf addr %llu",
        v6 + 29824,
        **((_QWORD **)a1 + 2));
      goto LABEL_175;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v13;
}
