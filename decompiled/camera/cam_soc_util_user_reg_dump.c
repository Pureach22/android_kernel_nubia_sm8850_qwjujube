__int64 __fastcall cam_soc_util_user_reg_dump(
        _DWORD *a1,
        __int64 a2,
        __int64 a3,
        char *a4,
        __int64 a5,
        unsigned int a6)
{
  char *v6; // x26
  _DWORD *v8; // x22
  unsigned int v9; // w19
  int v10; // w24
  unsigned int v11; // w23
  int *v12; // x27
  int v13; // w28
  _DWORD *v14; // x20
  unsigned int v15; // w6
  unsigned int v16; // w7
  unsigned int cpu_buf; // w0
  int v18; // w6
  const char *v19; // x3
  __int64 v20; // x4
  _DWORD *v21; // x20
  unsigned int v22; // w0
  const char *v23; // x3
  __int64 v24; // x4
  const char *v25; // x5
  char *v26; // x6
  __int64 v27; // x7
  unsigned __int64 v28; // x6
  unsigned __int64 v29; // x9
  int v30; // w7
  int v31; // w8
  unsigned __int64 v32; // x10
  unsigned __int64 v33; // x6
  unsigned int v34; // w8
  const char *v35; // x3
  __int64 v36; // x4
  const char *v37; // x5
  __int64 v38; // x22
  unsigned int *v39; // x25
  unsigned __int64 v40; // x22
  unsigned int *v41; // x19
  __int64 v42; // x4
  const char *v43; // x5
  __int64 v44; // x6
  __int64 v45; // x8
  __int64 v46; // x25
  __int64 v47; // x9
  unsigned int *v48; // x28
  unsigned int v49; // w22
  int v50; // w26
  unsigned int v51; // w19
  __int64 v52; // x4
  const char *v53; // x5
  unsigned int v54; // w6
  __int64 v55; // x8
  unsigned int v56; // w0
  unsigned int v57; // w6
  char *v58; // x19
  __int64 v59; // x4
  const char *v60; // x5
  __int64 v61; // x8
  __int64 v62; // x8
  __int64 v63; // x8
  unsigned __int64 v64; // x20
  unsigned int *v65; // x19
  __int64 v66; // x4
  const char *v67; // x5
  __int64 v68; // x6
  __int64 v69; // x8
  __int64 v70; // x8
  int v71; // w20
  unsigned int v72; // w26
  int v73; // w0
  unsigned int v74; // w8
  __int64 v75; // x6
  __int64 v76; // x9
  __int64 v77; // x4
  const char *v78; // x5
  unsigned int v79; // w9
  __int64 v81; // [xsp+10h] [xbp-70h]
  __int64 v82; // [xsp+18h] [xbp-68h]
  _DWORD *v83; // [xsp+20h] [xbp-60h]
  __int64 v84; // [xsp+28h] [xbp-58h]
  __int64 v85; // [xsp+30h] [xbp-50h]
  unsigned int *v86; // [xsp+38h] [xbp-48h]
  char *v88; // [xsp+48h] [xbp-38h]
  unsigned int v89; // [xsp+54h] [xbp-2Ch]
  unsigned int v90; // [xsp+54h] [xbp-2Ch]
  unsigned int v91; // [xsp+58h] [xbp-28h]
  char *v92; // [xsp+58h] [xbp-28h]
  __int64 v93; // [xsp+60h] [xbp-20h]
  __int64 v94; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v95[2]; // [xsp+70h] [xbp-10h] BYREF

  v6 = a4;
  v8 = a1;
  v95[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && a1 && a3 && a4 )
  {
    if ( !a1[3] )
    {
LABEL_112:
      v11 = 0;
      goto LABEL_114;
    }
    v9 = a6;
    v93 = a2 + 16;
    v10 = 0;
    v88 = &a4[24 * a6];
    v85 = a2 + 36;
    v86 = (unsigned int *)(v88 + 304);
    v84 = a2 + 84;
    while ( 1 )
    {
      v12 = (int *)(v93 + 104LL * v10);
      v13 = *v12;
      if ( (unsigned int)(*v12 - 2) < 2 )
      {
        v14 = v12 + 2;
        v94 = 0;
        v95[0] = 0;
        if ( v12 != (int *)-8LL )
        {
          v15 = v12[2];
          v16 = v12[3];
          if ( v15 > 5 || v16 >= 6 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_dump_dmi_ctxt_reg_range_user_buf",
              5085,
              "Invalid number of requested writes, pre: %d post: %d",
              v15,
              v16);
            v11 = -22;
LABEL_113:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_user_reg_dump",
              5328,
              "Reg range read failed rc: %d reg_base_idx: %d",
              v11,
              v9);
            goto LABEL_114;
          }
          cpu_buf = cam_mem_get_cpu_buf(*(_DWORD *)(a3 + 16), &v94, v95);
          if ( cpu_buf )
          {
            v18 = *(_DWORD *)(a3 + 16);
            v11 = cpu_buf;
            v19 = "cam_soc_util_dump_dmi_ctxt_reg_range_user_buf";
            v20 = 5092;
LABEL_19:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              v19,
              v20,
              "Invalid handle %u rc %d",
              v18,
              v11);
            goto LABEL_113;
          }
          v28 = *(_QWORD *)(a3 + 8);
          v29 = v95[0] - v28;
          if ( v95[0] > v28 )
          {
            v30 = v12[2];
            v31 = v12[15];
            v32 = (8 * (v31 + v30)) | 4u;
            if ( v29 < v32 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x20000,
                2,
                "cam_soc_util_dump_dmi_ctxt_reg_range_user_buf",
                5111,
                "Dump Buffer exhaust read %d write %d remain %zu min %u",
                v31,
                v30,
                v29,
                v32);
              v11 = -28;
              goto LABEL_85;
            }
            v83 = v8;
            v38 = v94 + v28;
            *(_QWORD *)(v38 + 16) = 0;
            *(_QWORD *)(v38 + 24) = 0;
            *(_QWORD *)(v38 + 32) = 0;
            *(_QWORD *)(v38 + 40) = 0;
            *(_QWORD *)(v38 + 48) = 0;
            *(_QWORD *)(v38 + 56) = 0;
            *(_QWORD *)(v38 + 64) = 0;
            *(_QWORD *)(v38 + 72) = 0;
            *(_QWORD *)(v38 + 80) = 0;
            *(_QWORD *)(v38 + 88) = 0;
            *(_QWORD *)(v38 + 96) = 0;
            *(_QWORD *)(v38 + 104) = 0;
            *(_QWORD *)(v38 + 112) = 0;
            *(_QWORD *)(v38 + 120) = 0;
            *(_QWORD *)(v38 + 128) = 0;
            *(_QWORD *)(v38 + 136) = 0;
            *(_QWORD *)v38 = 0;
            *(_QWORD *)(v38 + 8) = 0;
            scnprintf(v38, 128, "DMI_DUMP:");
            *(_DWORD *)(v38 + 136) = 4;
            v82 = v38;
            v89 = v9;
            *(_DWORD *)(v38 + 144) = *((_DWORD *)v6 + 5);
            v81 = v38 + 144;
            if ( v9 >= 8 )
              goto LABEL_116;
            v91 = *v86;
            v39 = (unsigned int *)(v38 + 148);
            if ( *v14 )
            {
              v40 = 0;
              v41 = (unsigned int *)(v85 + 104LL * v10);
              do
              {
                if ( v40 == 5 )
                  goto LABEL_116;
                v44 = *(v41 - 1);
                if ( (v44 & 3) != 0 )
                {
                  v42 = 4848;
                  v43 = "Offset: 0x%X of %s is not memory aligned";
                }
                else
                {
                  if ( (unsigned int)v44 <= v91 )
                  {
                    if ( *((_DWORD *)v6 + 120) > v89 && (v45 = *((_QWORD *)v88 + 36)) != 0 )
                      cam_io_w_mb(*v41, v45 + v44);
                    else
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        0x20000,
                        1,
                        "cam_soc_util_w_mb",
                        831,
                        "No valid mapped starting address found");
                    *v39 = *(v41 - 1);
                    v39[1] = *v41;
                    v39 += 2;
                    goto LABEL_37;
                  }
                  v42 = 4853;
                  v43 = "Reg offset: 0x%X of %s out of range, reg_map size: 0x%X";
                }
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x20000,
                  1,
                  "cam_soc_util_reg_addr_validation",
                  v42,
                  v43);
LABEL_37:
                ++v40;
                v41 += 2;
              }
              while ( v40 < (unsigned int)*v14 );
            }
            v57 = v12[14];
            if ( (v57 & 3) != 0 )
            {
              v58 = v6;
              v59 = 4848;
              v60 = "Offset: 0x%X of %s is not memory aligned";
LABEL_68:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x20000,
                1,
                "cam_soc_util_reg_addr_validation",
                v59,
                v60);
              v11 = -22;
LABEL_69:
              v6 = v58;
              if ( v12[3] )
              {
                v64 = 0;
                v65 = (unsigned int *)(v84 + 104LL * v10);
                do
                {
                  if ( v64 == 5 )
                    goto LABEL_116;
                  v68 = *(v65 - 1);
                  if ( (v68 & 3) != 0 )
                  {
                    v66 = 4848;
                    v67 = "Offset: 0x%X of %s is not memory aligned";
                  }
                  else
                  {
                    if ( (unsigned int)v68 <= v91 )
                    {
                      if ( *((_DWORD *)v6 + 120) > v89 && (v69 = *((_QWORD *)v88 + 36)) != 0 )
                        cam_io_w_mb(*v65, v69 + v68);
                      else
                        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                          3,
                          0x20000,
                          1,
                          "cam_soc_util_w_mb",
                          831,
                          "No valid mapped starting address found");
                      v11 = 0;
                      goto LABEL_73;
                    }
                    v66 = 4853;
                    v67 = "Reg offset: 0x%X of %s out of range, reg_map size: 0x%X";
                  }
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x20000,
                    1,
                    "cam_soc_util_reg_addr_validation",
                    v66,
                    v67);
                  v11 = -22;
LABEL_73:
                  ++v64;
                  v65 += 2;
                }
                while ( v64 < (unsigned int)v12[3] );
              }
              v9 = v89;
              v70 = (((__int64)v39 - v81) >> 2) * *(unsigned int *)(v82 + 136);
              *(_QWORD *)(v82 + 128) = v70;
              v63 = v70 + *(_QWORD *)(a3 + 8);
              goto LABEL_84;
            }
            v58 = v6;
            if ( v57 > v91 )
            {
              v59 = 4853;
              v60 = "Reg offset: 0x%X of %s out of range, reg_map size: 0x%X";
              goto LABEL_68;
            }
            if ( !v12[15] )
            {
              v11 = 0;
              goto LABEL_69;
            }
            v71 = 0;
            v72 = 0;
            v11 = 0;
            while ( 1 )
            {
              v74 = v12[14];
              LODWORD(v75) = v74;
              if ( v13 != 2 )
              {
                v75 = v71 + v74;
                if ( (v74 & 3) != 0 )
                {
                  v77 = 4848;
                  v78 = "Offset: 0x%X of %s is not memory aligned";
LABEL_105:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x20000,
                    1,
                    "cam_soc_util_reg_addr_validation",
                    v77,
                    v78,
                    v75,
                    "mc_reg_read");
                  v11 = -22;
                  goto LABEL_91;
                }
                if ( (unsigned int)v75 > v91 )
                {
                  v77 = 4853;
                  v78 = "Reg offset: 0x%X of %s out of range, reg_map size: 0x%X";
                  goto LABEL_105;
                }
                v11 = 0;
              }
              if ( *(_BYTE *)a5 != 1 || (unsigned int)(*(_DWORD *)(a5 + 12) - 1) > 1 )
                goto LABEL_97;
              if ( v74 < *(_DWORD *)(a5 + 4) )
                break;
              v79 = *(_DWORD *)(a5 + 8);
              *v39 = v74;
              if ( v74 > v79 )
                goto LABEL_98;
              v73 = 4660;
LABEL_90:
              v39[1] = v73;
              v39 += 2;
LABEL_91:
              ++v72;
              v71 += 4;
              if ( v72 >= v12[15] )
                goto LABEL_69;
            }
            LODWORD(v75) = v12[14];
LABEL_97:
            v74 = v75;
            *v39 = v75;
LABEL_98:
            if ( *((_DWORD *)v58 + 120) > v89 && (v76 = *((_QWORD *)v88 + 36)) != 0 )
            {
              v73 = cam_io_r_mb(v76 + v74);
            }
            else
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x20000,
                1,
                "cam_soc_util_r_mb",
                878,
                "No valid mapped starting address found");
              v73 = 0;
            }
            goto LABEL_90;
          }
          v35 = "cam_soc_util_dump_dmi_ctxt_reg_range_user_buf";
          v36 = 5098;
          v37 = "Dump offset overshoot offset %zu len %zu";
LABEL_31:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x20000,
            2,
            v35,
            v36,
            v37);
          v11 = -28;
          goto LABEL_85;
        }
        v23 = "cam_soc_util_dump_dmi_ctxt_reg_range_user_buf";
        v24 = 5077;
        v25 = "Invalid input args soc_info: %pK, dump_args: %pK";
        v26 = v6;
        v27 = a3;
LABEL_22:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *, __int64))cam_print_log)(
          3,
          0x20000,
          1,
          v23,
          v24,
          v25,
          v26,
          v27);
        v11 = -22;
        goto LABEL_113;
      }
      if ( v13 != 1 )
        break;
      v21 = v12 + 2;
      v94 = 0;
      v95[0] = 0;
      if ( v12 == (int *)-8LL )
      {
        v23 = "cam_soc_util_dump_cont_reg_range_user_buf";
        v24 = 5220;
        v25 = "Invalid input args soc_info: %pK, dump_out_buffer: %pK reg_read: %pK";
        v26 = v6;
        v27 = a3;
        goto LABEL_22;
      }
      v22 = cam_mem_get_cpu_buf(*(_DWORD *)(a3 + 16), &v94, v95);
      if ( v22 )
      {
        v18 = *(_DWORD *)(a3 + 16);
        v11 = v22;
        v19 = "cam_soc_util_dump_cont_reg_range_user_buf";
        v20 = 5227;
        goto LABEL_19;
      }
      v33 = *(_QWORD *)(a3 + 8);
      if ( v95[0] <= v33 )
      {
        v35 = "cam_soc_util_dump_cont_reg_range_user_buf";
        v36 = 5232;
        v37 = "Dump offset overshoot %zu %zu";
        goto LABEL_31;
      }
      v34 = v12[3];
      if ( v95[0] - v33 < 8 * v34 + 148 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x20000,
          2,
          "cam_soc_util_dump_cont_reg_range_user_buf",
          5244,
          "Dump Buffer exhaust read_values %d remain %zu min %u",
          v34);
        v11 = -28;
        goto LABEL_85;
      }
      v83 = v8;
      v46 = v94 + v33;
      *(_QWORD *)(v46 + 16) = 0;
      *(_QWORD *)(v46 + 24) = 0;
      *(_QWORD *)(v46 + 32) = 0;
      *(_QWORD *)(v46 + 40) = 0;
      *(_QWORD *)(v46 + 48) = 0;
      *(_QWORD *)(v46 + 56) = 0;
      *(_QWORD *)(v46 + 64) = 0;
      *(_QWORD *)(v46 + 72) = 0;
      *(_QWORD *)(v46 + 80) = 0;
      *(_QWORD *)(v46 + 88) = 0;
      *(_QWORD *)(v46 + 96) = 0;
      *(_QWORD *)(v46 + 104) = 0;
      *(_QWORD *)(v46 + 112) = 0;
      *(_QWORD *)(v46 + 120) = 0;
      *(_QWORD *)(v46 + 128) = 0;
      *(_QWORD *)(v46 + 136) = 0;
      *(_QWORD *)v46 = 0;
      *(_QWORD *)(v46 + 8) = 0;
      scnprintf(v46, 128, "%s_REG:", *((const char **)v6 + 3));
      *(_DWORD *)(v46 + 136) = 4;
      *(_DWORD *)(v46 + 144) = *((_DWORD *)v6 + 5);
      v47 = v46 + 144;
      if ( v9 >= 8 )
LABEL_116:
        __break(0x5512u);
      v48 = (unsigned int *)(v46 + 148);
      if ( v12[3] )
      {
        v90 = v9;
        v49 = 0;
        v92 = v6;
        v50 = 0;
        v51 = *v86;
        while ( 1 )
        {
          v54 = v50 + *v21;
          if ( (*v21 & 3) != 0 )
          {
            v52 = 4848;
            v53 = "Offset: 0x%X of %s is not memory aligned";
          }
          else
          {
            if ( v54 <= v51 )
            {
              *v48 = v54;
              if ( *((_DWORD *)v92 + 120) > v90 && (v55 = *((_QWORD *)v88 + 36)) != 0 )
              {
                v56 = cam_io_r(v55 + (unsigned int)(v50 + *v21));
              }
              else
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x20000,
                  1,
                  "cam_soc_util_r",
                  853,
                  "No valid mapped starting address found");
                v56 = 0;
              }
              v11 = 0;
              v48[1] = v56;
              v48 += 2;
              goto LABEL_52;
            }
            v52 = 4853;
            v53 = "Reg offset: 0x%X of %s out of range, reg_map size: 0x%X";
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_reg_addr_validation",
            v52,
            v53);
          v11 = -22;
LABEL_52:
          ++v49;
          v50 += 4;
          if ( v49 >= v12[3] )
          {
            v61 = *(unsigned int *)(v46 + 136);
            v6 = v92;
            v9 = v90;
            v47 = v46 + 144;
            goto LABEL_65;
          }
        }
      }
      v11 = 0;
      v61 = 4;
LABEL_65:
      v62 = (((__int64)v48 - v47) >> 2) * v61;
      *(_QWORD *)(v46 + 128) = v62;
      v63 = *(_QWORD *)(a3 + 8) + v62;
LABEL_84:
      *(_QWORD *)(a3 + 8) = v63 + 144;
      v8 = v83;
LABEL_85:
      cam_mem_put_cpu_buf(*(_DWORD *)(a3 + 16));
      if ( v11 )
        goto LABEL_113;
      if ( (unsigned int)++v10 >= v8[3] )
        goto LABEL_112;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_user_reg_dump",
      5320,
      "Invalid Reg dump read type: %d",
      v13);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_user_reg_dump",
      5295,
      "Invalid input parameters %pK %pK %pK",
      (const void *)a3,
      a1,
      a4);
  }
  v11 = -22;
LABEL_114:
  _ReadStatusReg(SP_EL0);
  return v11;
}
