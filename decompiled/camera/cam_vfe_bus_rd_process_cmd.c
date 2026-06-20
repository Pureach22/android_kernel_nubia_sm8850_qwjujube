__int64 __fastcall cam_vfe_bus_rd_process_cmd(const char *a1, int a2, __int64 a3, int a4)
{
  __int64 v4; // x24
  unsigned int v5; // w8
  __int64 v6; // x19
  __int64 (__fastcall *v7)(_QWORD); // x8
  const char *v8; // x20
  __int64 v9; // x22
  unsigned int v10; // w21
  __int64 v11; // x8
  __int64 v12; // x23
  int v13; // w0
  unsigned int (__fastcall *v14)(_QWORD); // x8
  const char *v15; // x3
  const char *v16; // x5
  __int64 v17; // x4
  int v18; // w0
  const char *v19; // x5
  __int64 v20; // x0
  const char *v21; // x3
  __int64 v22; // x4
  __int64 v25; // x0
  __int64 v26; // x23
  __int64 v27; // x24
  int v28; // w6
  char v29; // w10
  _DWORD *v30; // x28
  __int64 v31; // x1
  int v32; // w7
  int v33; // w8
  int v34; // w7
  int v35; // w8
  int v36; // w6
  int v37; // w9
  __int64 v38; // x28
  __int64 v39; // x26
  __int64 v40; // x20
  __int64 v41; // x8
  int v42; // w6
  unsigned int v43; // w19
  unsigned __int64 v44; // x25
  int *v45; // x22
  _DWORD *v46; // x21
  _DWORD *v47; // x27
  int v48; // w6
  unsigned int v49; // w8
  int v50; // w9
  __int64 v51; // x10
  int v52; // w8
  __int64 v53; // x9
  int v54; // w8
  int v55; // w8
  __int64 v56; // x28
  __int64 v57; // x24
  int v58; // w8
  __int64 v59; // x20
  __int64 (__fastcall *v60)(_QWORD); // x8
  int v61; // w0
  __int64 v62; // x8
  unsigned int v63; // w6
  int v64; // w20
  char v65; // w9
  _DWORD *v66; // x8
  __int64 v67; // x0
  __int64 v68; // x19
  _DWORD *v69; // x9
  __int64 v70; // x0
  __int64 v71; // x21
  __int64 v72; // x19
  __int64 v73; // x8
  __int64 v74; // x0
  int v75; // [xsp+0h] [xbp-40h]
  int v76; // [xsp+8h] [xbp-38h]
  __int64 v77; // [xsp+18h] [xbp-28h]
  __int64 v78; // [xsp+18h] [xbp-28h]
  __int64 v79; // [xsp+18h] [xbp-28h]
  __int64 v80; // [xsp+18h] [xbp-28h]
  __int64 v81; // [xsp+18h] [xbp-28h]
  __int64 v82; // [xsp+20h] [xbp-20h]
  const char *v83; // [xsp+28h] [xbp-18h]
  const char *v84; // [xsp+28h] [xbp-18h]
  const char *v85; // [xsp+28h] [xbp-18h]
  __int64 v86; // [xsp+28h] [xbp-18h]
  _QWORD v87[2]; // [xsp+30h] [xbp-10h] BYREF

  v87[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v18 = __ratelimit(&cam_vfe_bus_rd_process_cmd__rs, "cam_vfe_bus_rd_process_cmd");
    v19 = "Invalid input arguments";
    if ( v18 )
      v20 = 3;
    else
      v20 = 2;
    v21 = "cam_vfe_bus_rd_process_cmd";
    v22 = 1197;
    goto LABEL_26;
  }
  v5 = 0;
  if ( a2 <= 6 )
  {
    if ( a2 != 2 )
    {
      if ( a2 == 5 )
        goto LABEL_28;
      goto LABEL_31;
    }
    v39 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
    if ( v39 )
    {
      v40 = *(_QWORD *)(v39 + 88);
      if ( v40 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v72 = a3;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_rd_update_rm",
            900,
            "#of RM: %d",
            *(_DWORD *)(v39 + 16));
          a3 = v72;
        }
        v41 = *(_QWORD *)(a3 + 40);
        v42 = *(_DWORD *)(v41 + 20);
        if ( v42 == *(_DWORD *)(v39 + 16) )
        {
          if ( v42 )
          {
            v43 = 0;
            v86 = v40;
            v44 = 0;
            v8 = (const char *)(v39 + 24);
            v45 = (int *)(*(_QWORD *)(v39 + 8) + 68LL);
            v46 = (_DWORD *)(*(_QWORD *)(v41 + 56) + 32LL);
            v82 = *(_QWORD *)(v39 + 8);
            do
            {
              if ( v44 == 2 )
              {
LABEL_103:
                __break(0x5512u);
                goto LABEL_104;
              }
              v47 = *(_DWORD **)(*(_QWORD *)&v8[8 * v44] + 24LL);
              v48 = v47[18];
              v49 = *(v46 - 2);
              switch ( v48 )
              {
                case 0:
                  v49 *= 16;
                  goto LABEL_63;
                case 1:
                case 2:
                case 3:
                case 4:
                case 6:
                case 7:
                case 8:
                case 16:
                case 18:
                  v49 *= 2;
                  goto LABEL_63;
                case 5:
                case 9:
                  v49 *= 4;
                  goto LABEL_63;
                case 10:
                  v49 *= 8;
                  goto LABEL_63;
                case 11:
                  v49 = 12 * ((v49 + 2) / 3) / 3;
                  goto LABEL_63;
                case 12:
                  goto LABEL_63;
                case 13:
                  v58 = 5 * v49;
                  goto LABEL_79;
                case 14:
                  v49 = (3 * v49 + 1) >> 1;
                  goto LABEL_63;
                case 15:
                  v58 = 7 * v49;
LABEL_79:
                  v49 = (unsigned int)(v58 + 3) >> 2;
LABEL_63:
                  v47[13] = v49;
                  break;
                default:
                  v56 = v4;
                  v57 = a3;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_vfe_bus_rd_pxls_to_bytes",
                    198,
                    "Invalid unpacker_fmt:%d",
                    v48);
                  LOWORD(v49) = *((_WORD *)v47 + 26);
                  a3 = v57;
                  v4 = v56;
                  break;
              }
              v50 = *(v46 - 1);
              v51 = *((_QWORD *)v47 + 2);
              v47[14] = v50;
              v52 = (unsigned __int16)v49 | ((unsigned __int16)v50 << 16);
              *(v45 - 5) = *(_DWORD *)(v51 + 8);
              *(v45 - 4) = v52;
              if ( (debug_mdl & 8) != 0 && !debug_priority )
              {
                v80 = a3;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_rd_update_rm",
                  935,
                  "VFE:%d RM:%d image_size:0x%X",
                  **((_DWORD **)v47 + 1),
                  *v47,
                  v52);
                a3 = v80;
              }
              v53 = *((_QWORD *)v47 + 2);
              v47[15] = *v46;
              *(v45 - 3) = *(_DWORD *)(v53 + 12);
              v54 = v47[15];
              *(v45 - 2) = v54;
              if ( (debug_mdl & 8) != 0 && !debug_priority )
              {
                v81 = a3;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_rd_update_rm",
                  943,
                  "VFE:%d RM:%d image_stride:0x%X",
                  **((_DWORD **)v47 + 1),
                  *v47,
                  v54);
                a3 = v81;
              }
              *(v45 - 1) = *(_DWORD *)(*((_QWORD *)v47 + 2) + 4LL);
              v55 = v47[9] + *(_QWORD *)(**(_QWORD **)(a3 + 40) + 8 * v44);
              *v45 = v55;
              if ( (debug_mdl & 8) != 0 && !debug_priority )
              {
                v79 = a3;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_rd_update_rm",
                  952,
                  "VFE:%d RM:%d image_address:0x%X",
                  **((_DWORD **)v47 + 1),
                  *v47,
                  v55);
                a3 = v79;
                v55 = *v45;
              }
              v47[25] = v55;
              ++v44;
              v43 += 3;
              v45 += 6;
              v46 += 12;
            }
            while ( v44 < *(unsigned int *)(v39 + 16) );
            v59 = a3;
            v60 = *(__int64 (__fastcall **)(_QWORD))(v86 + 24);
            if ( *((_DWORD *)v60 - 1) != 2010610996 )
              __break(0x8228u);
            v61 = v60(v43);
            v62 = v59;
            v63 = *(_DWORD *)(v59 + 24);
            v64 = 4 * v61;
            if ( 4 * v61 <= v63 )
            {
              v69 = *(_DWORD **)(v86 + 120);
              v70 = *(_QWORD *)(v62 + 16);
              v71 = v62;
              if ( *(v69 - 1) != -1401492769 )
                __break(0x8229u);
              ((void (__fastcall *)(__int64, _QWORD, __int64))v69)(v70, v43, v82 + 48);
              v5 = 0;
              *(_DWORD *)(v71 + 28) = v64;
            }
            else
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_bus_rd_update_rm",
                967,
                "Failed! Buf size:%d insufficient, expected size:%d",
                v63,
                v61);
              v5 = -12;
            }
          }
          else
          {
            v65 = debug_mdl;
            v5 = 0;
            *(_DWORD *)(a3 + 28) = 0;
            if ( (v65 & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v65 & 8,
                4,
                "cam_vfe_bus_rd_update_rm",
                981,
                "No reg val pairs. num_rms: %u",
                *(_DWORD *)(v39 + 16));
              v5 = 0;
            }
          }
          goto LABEL_28;
        }
        v15 = "cam_vfe_bus_rd_update_rm";
        v16 = "Failed! Invalid number buffers:%d required:%d";
        v17 = 905;
        goto LABEL_86;
      }
    }
    v21 = "cam_vfe_bus_rd_update_rm";
    v19 = "Failed! Invalid data";
    v20 = 3;
    v22 = 894;
    goto LABEL_26;
  }
  if ( a2 == 7 )
  {
LABEL_28:
    _ReadStatusReg(SP_EL0);
    return v5;
  }
  if ( a2 == 23 )
  {
    v26 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
    if ( v26 && *(_QWORD *)(v26 + 88) )
    {
      if ( !*(_DWORD *)(v26 + 16) )
      {
LABEL_84:
        v5 = 0;
        *((_DWORD *)a1 + 74) = *(_DWORD *)(a3 + 32);
        *((_DWORD *)a1 + 75) = *(_DWORD *)(a3 + 36);
        goto LABEL_28;
      }
      v27 = 0;
      v8 = "VFE:%d RM:%d format:0x%x unpacker_cfg:0x%x";
      while ( 1 )
      {
        if ( v27 == 2 )
          goto LABEL_103;
        v28 = *(_DWORD *)(a3 + 60);
        v29 = debug_mdl;
        v30 = *(_DWORD **)(*(_QWORD *)(v26 + 24 + 8 * v27) + 24LL);
        v31 = debug_mdl & 8;
        v30[16] = v28;
        v32 = *(_DWORD *)(a3 + 64);
        v30[18] = v32;
        v30[17] = *(_DWORD *)(a3 + 68);
        v30[15] = *(_DWORD *)(a3 + 56);
        v30[20] = *(_DWORD *)(a3 + 36);
        v30[21] = *(_DWORD *)(a3 + 32);
        v30[12] = *(_DWORD *)(a3 + 28);
        v30[22] = *(_DWORD *)(a3 + 24);
        v30[11] = *(_DWORD *)(a3 + 20);
        v33 = debug_priority;
        v30[10] = *(_DWORD *)(a3 + 16);
        if ( (v29 & 8) != 0 && !v33 )
        {
          v84 = a1;
          v77 = a3;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v31,
            4,
            "cam_vfe_bus_rd_update_fs_cfg",
            1033,
            "VFE:%d RM:%d format:0x%x unpacker_cfg:0x%x",
            v28,
            v32,
            v75,
            v76);
          a1 = v84;
          a3 = v77;
          v33 = debug_priority;
          v31 = debug_mdl & 8;
          if ( (debug_mdl & 8) != 0 )
          {
LABEL_44:
            if ( !v33 )
            {
              v85 = a1;
              v78 = a3;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v31,
                4,
                "cam_vfe_bus_rd_update_fs_cfg",
                1037,
                "latency_buf_alloc:0x%x stride:0x%x go_cmd_sel:0x%x",
                v30[17],
                v30[15],
                v30[20]);
              a1 = v85;
              a3 = v78;
              v33 = debug_priority;
              v31 = debug_mdl & 8;
            }
          }
        }
        else if ( v31 )
        {
          goto LABEL_44;
        }
        if ( v31 && !v33 )
        {
          v35 = v30[11];
          v34 = v30[12];
          v36 = v30[21];
          v37 = v30[10];
          v38 = a3;
          v83 = a1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v31,
            4,
            "cam_vfe_bus_rd_update_fs_cfg",
            1041,
            "fs_sync_en:%d hbi_cnt:0x%x fs_mode:0x%x min_vbi:0x%x",
            v36,
            v34,
            v35,
            v37);
          a1 = v83;
          a3 = v38;
        }
        if ( ++v27 >= (unsigned __int64)*(unsigned int *)(v26 + 16) )
          goto LABEL_84;
      }
    }
    v21 = "cam_vfe_bus_rd_update_fs_cfg";
    v19 = "Failed! Invalid data";
    v20 = 3;
    v22 = 1010;
LABEL_26:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v20,
      8,
      1,
      v21,
      v22,
      v19);
LABEL_27:
    v5 = -22;
    goto LABEL_28;
  }
  if ( a2 != 34 )
  {
LABEL_31:
    if ( (unsigned int)__ratelimit(&cam_vfe_bus_rd_process_cmd__rs_34, "cam_vfe_bus_rd_process_cmd") )
      v25 = 3;
    else
      v25 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      v25,
      8,
      1,
      "cam_vfe_bus_rd_process_cmd",
      1219,
      "Invalid camif process command:%d",
      (unsigned int)a2);
    goto LABEL_27;
  }
  v87[0] = 0;
  if ( a4 != 56 )
  {
    v21 = "cam_vfe_bus_rd_add_go_cmd";
    v19 = "invalid ars size";
    v20 = 3;
    v22 = 1060;
    goto LABEL_26;
  }
  if ( !*(_QWORD *)a3 )
  {
    v21 = "cam_vfe_bus_rd_add_go_cmd";
    v19 = "Invalid args";
    v20 = 3;
    v22 = 1065;
    goto LABEL_26;
  }
  v6 = *(_QWORD *)(*(_QWORD *)a3 + 48LL);
  if ( !v6 )
  {
    v21 = "cam_vfe_bus_rd_add_go_cmd";
    v19 = "Invalid CDM ops";
    v20 = 3;
    v22 = 1074;
    goto LABEL_26;
  }
  if ( !*((_DWORD *)a1 + 4) )
  {
    v10 = 0;
    goto LABEL_97;
  }
  v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 24);
  v8 = a1;
  v9 = a3;
  if ( *((_DWORD *)v7 - 1) != 2010610996 )
    __break(0x8228u);
  v10 = 4 * v7(1);
  if ( v10 > *(_DWORD *)(v9 + 24) )
    goto LABEL_21;
  v11 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v8 + 3) + 24LL) + 8LL);
  v12 = *(unsigned int *)(*(_QWORD *)(v11 + 40) + 20LL);
  v13 = cam_io_r_mb(*(_QWORD *)(v11 + 8) + v12);
  LODWORD(v87[0]) = v12;
  HIDWORD(v87[0]) = v13 | 1;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_rd_add_go_cmd",
      1096,
      "VFE:%d Bus RD go_cmd: 0x%x offset 0x%x",
      **((unsigned int **)v8 + 1));
  a3 = v9;
  if ( *((_DWORD *)v8 + 4) < 2u )
  {
LABEL_97:
    v66 = *(_DWORD **)(v6 + 120);
    v67 = *(_QWORD *)(a3 + 16);
    v68 = a3;
    if ( *(v66 - 1) != -1401492769 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD *))v66)(v67, 1, v87);
    v5 = 0;
    *(_DWORD *)(v68 + 28) = v10;
    goto LABEL_28;
  }
  v14 = *(unsigned int (__fastcall **)(_QWORD))(v6 + 24);
  if ( *((_DWORD *)v14 - 1) != 2010610996 )
    __break(0x8228u);
  if ( *(_DWORD *)(v9 + 24) < 4 * v14(1) )
  {
LABEL_21:
    v15 = "cam_vfe_bus_rd_add_go_cmd";
    v16 = "buf size:%d is not sufficient, expected: %d";
    v17 = 1084;
LABEL_86:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v15,
      v17,
      v16);
    goto LABEL_27;
  }
LABEL_104:
  v73 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v8 + 4) + 24LL) + 8LL);
  v74 = cam_io_r_mb(*(_QWORD *)(v73 + 8) + *(unsigned int *)(*(_QWORD *)(v73 + 40) + 20LL));
  __break(0x5512u);
  return cam_vfe_bus_rd_handle_irq_top_half(v74);
}
