__int64 __fastcall cam_icp_v1_process_cmd(
        const char *a1,
        unsigned int a2,
        unsigned __int8 *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  const char *v6; // x3
  const char *v7; // x5
  __int64 v8; // x6
  __int64 v9; // x4
  const char *v10; // x3
  const char *v11; // x5
  __int64 v12; // x4
  __int64 result; // x0
  __int64 v15; // x20
  __int64 v16; // x0
  __int64 v17; // x19
  unsigned int v18; // w21
  unsigned int updated; // w19
  unsigned int v20; // w0
  __int64 v21; // x6
  const char *v22; // x3
  const char *v23; // x5
  unsigned int v24; // w19
  __int64 v25; // x4
  const char *v26; // x6
  const char *v27; // x7
  unsigned __int64 v28; // x6
  unsigned __int64 v29; // x8
  const char *v30; // x5
  __int64 v31; // x4
  __int64 v32; // x1
  __int64 v34; // x0
  unsigned __int8 *v35; // x22
  __int64 v36; // x21
  _QWORD *v37; // x20
  __int64 v38; // x0
  int v39; // w0
  int v40; // w6
  __int64 v41; // x4
  __int64 v42; // x8
  int v43; // w0
  const char *v44; // x3
  const char *v45; // x5
  __int64 v46; // x4
  int v47; // w0
  int v48; // w21
  __int64 v49; // x21
  int v50; // w0
  const char *v51; // x5
  __int64 v52; // x4
  const char *v53; // x9
  unsigned int v54; // w8
  __int64 v55; // x1
  const char *v56; // x19
  int fw_size; // w0
  unsigned int v59; // w20
  __int64 v60; // x21
  __int64 v61; // x0
  unsigned __int64 v62; // x7
  int v63; // w0
  unsigned int v64; // [xsp+4h] [xbp-1Ch] BYREF
  const char *v65; // [xsp+8h] [xbp-18h] BYREF
  __int64 v66; // [xsp+10h] [xbp-10h]
  __int64 v67; // [xsp+18h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v10 = "cam_icp_v1_process_cmd";
    v11 = "Invalid arguments";
    v12 = 687;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      v10,
      v12,
      v11);
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  if ( a2 >= 0x13 )
  {
    v6 = "cam_icp_v1_process_cmd";
    v7 = "Invalid command : %x";
    v8 = a2;
    v9 = 692;
LABEL_4:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      v6,
      v9,
      v7,
      v8);
    goto LABEL_7;
  }
  result = 0;
  v15 = *((_QWORD *)a1 + 460);
  v8 = (unsigned int)a4;
  switch ( a2 )
  {
    case 0u:
      *(_DWORD *)(v15 + 16) = 0;
      *(_QWORD *)(v15 + 24) = 0;
      *(_QWORD *)(v15 + 32) = 0;
      v16 = raw_spin_lock_irqsave(a1 + 48);
      *(_QWORD *)(v15 + 40) = 0;
      *(_QWORD *)(v15 + 48) = 0;
      raw_spin_unlock_irqrestore(a1 + 48, v16);
      v17 = *((_QWORD *)a1 + 51);
      LODWORD(v65) = 0;
      if ( !(unsigned int)cam_common_read_poll_timeout((const void *)(v17 + 512), 0x64u, 10000, 0x80u, 128, &v65) )
        goto LABEL_64;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v1_power_collapse",
        383,
        "WFI poll timed out: status=0x%08x",
        (_DWORD)v65);
      result = 0;
      goto LABEL_8;
    case 1u:
      if ( !a3 )
      {
        v44 = "cam_icp_v1_boot";
        v45 = "Invalid args: icp_v1_dev=%pK args=%pK";
        v46 = 433;
        v26 = a1;
        v27 = nullptr;
        goto LABEL_91;
      }
      if ( (_DWORD)a4 != 48 )
      {
        v10 = "cam_icp_v1_boot";
        v11 = "Invalid boot args size";
        v12 = 438;
        goto LABEL_6;
      }
      *(_DWORD *)(v15 + 16) = *(_DWORD *)a3;
      *(_QWORD *)(v15 + 24) = *((_QWORD *)a3 + 1);
      *(_QWORD *)(v15 + 32) = *((_QWORD *)a3 + 2);
      v34 = raw_spin_lock_irqsave(a1 + 48);
      v35 = a3;
      *(_QWORD *)(v15 + 48) = *((_QWORD *)a3 + 4);
      *(_QWORD *)(v15 + 40) = *((_QWORD *)a3 + 3);
      raw_spin_unlock_irqrestore(a1 + 48, v34);
      v36 = *((_QWORD *)a1 + 12);
      v37 = *((_QWORD **)a1 + 460);
      v64 = 0;
      v38 = *(_QWORD *)(v36 + 760);
      v65 = nullptr;
      if ( (unsigned int)of_property_read_string(v38, "fw_name", &v65) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          3,
          "cam_icp_v1_download_fw",
          71,
          "FW image name not found. Use default name: CAMERA_ICP.elf");
        v39 = firmware_request_nowarn(v37, "CAMERA_ICP.elf", v36 + 16);
        if ( v39 )
        {
          v40 = v39;
          v41 = 75;
LABEL_98:
          v48 = v40;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_v1_download_fw",
            v41,
            "Failed to locate fw: %d");
          goto LABEL_109;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          3,
          "cam_icp_v1_download_fw",
          80,
          "Downloading firmware %s",
          v65);
        v47 = firmware_request_nowarn(v37, v65, v36 + 16);
        if ( v47 )
        {
          v40 = v47;
          v41 = 84;
          goto LABEL_98;
        }
      }
      if ( !*v37 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_v1_download_fw",
          90,
          "Invalid elf size");
        v48 = -22;
        goto LABEL_108;
      }
      v49 = *(_QWORD *)(*v37 + 8LL);
      v50 = cam_icp_validate_fw(v49, 40);
      if ( v50 )
      {
        v48 = v50;
        v51 = "fw elf validation failed";
        v52 = 98;
LABEL_107:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_v1_download_fw",
          v52,
          v51);
        goto LABEL_108;
      }
      fw_size = cam_icp_get_fw_size(v49, &v64);
      if ( fw_size )
      {
        v48 = fw_size;
        v51 = "unable to get fw size";
        v52 = 104;
        goto LABEL_107;
      }
      v62 = v37[4];
      if ( v62 >= v64 )
      {
        v63 = cam_icp_program_fw(v49, v37[3]);
        if ( !v63 )
        {
          release_firmware(*v37);
          v32 = v35[40];
          goto LABEL_41;
        }
        v48 = v63;
        v51 = "fw program is failed";
        v52 = 117;
        goto LABEL_107;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v1_download_fw",
        110,
        "mismatch in fw size: %u %llu",
        v64,
        v62);
      v48 = -22;
LABEL_108:
      release_firmware(*v37);
LABEL_109:
      v59 = v48;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v1_boot",
        446,
        "firmware download failed rc=%d",
        v48);
      v60 = *((_QWORD *)a1 + 460);
      *(_DWORD *)(v60 + 16) = 0;
      *(_QWORD *)(v60 + 24) = 0;
      *(_QWORD *)(v60 + 32) = 0;
      v61 = raw_spin_lock_irqsave(a1 + 48);
      *(_QWORD *)(v60 + 40) = 0;
      *(_QWORD *)(v60 + 48) = 0;
      raw_spin_unlock_irqrestore(a1 + 48, v61);
      result = v59;
LABEL_8:
      _ReadStatusReg(SP_EL0);
      return result;
    case 2u:
      v17 = *((_QWORD *)a1 + 51);
      LODWORD(v65) = 0;
      if ( (unsigned int)cam_common_read_poll_timeout((const void *)(v17 + 512), 0x64u, 10000, 0x80u, 128, &v65) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_v1_power_collapse",
          383,
          "WFI poll timed out: status=0x%08x",
          (_DWORD)v65);
        result = 4294967186LL;
      }
      else
      {
LABEL_64:
        v43 = cam_io_r(v17 + 8);
        cam_io_w_mb(v43 & 0xFFFFFDEF, v17 + 8);
        result = 0;
      }
      goto LABEL_8;
    case 3u:
      v32 = *a3;
LABEL_41:
      cam_icp_v1_power_resume(a1, v32);
      result = 0;
      goto LABEL_8;
    case 6u:
      if ( !v15 )
      {
        v10 = "cam_icp_v1_send_fw_init";
        v11 = "Invalid core info is NULL";
        v12 = 576;
        goto LABEL_6;
      }
      result = hfi_send_system_cmd(*(unsigned int *)(v15 + 60), 65537, 0, 0, a5, a6, (unsigned int)a4);
      if ( (_DWORD)result )
      {
        v21 = *(unsigned int *)(v15 + 60);
        v22 = "cam_icp_v1_send_fw_init";
        v23 = "Fail to send sys init command for hfi handle: %d";
        v24 = result;
        v25 = 583;
        goto LABEL_58;
      }
      goto LABEL_8;
    case 7u:
      if ( !a3 )
      {
        v10 = "cam_icp_v1_process_cmd";
        v11 = "cmd args NULL";
        v12 = 720;
        goto LABEL_6;
      }
      if ( !v15 )
        goto LABEL_54;
      cam_icp_proc_cpas_vote(*(unsigned int *)(v15 + 56), a3);
      result = 0;
      goto LABEL_8;
    case 8u:
      if ( !a3 )
      {
        v10 = "cam_icp_v1_process_cmd";
        v11 = "cmd args NULL";
        v12 = 743;
        goto LABEL_6;
      }
      if ( (*(_BYTE *)(v15 + 64) & 1) != 0 )
        goto LABEL_54;
      result = cam_cpas_start(*(_DWORD *)(v15 + 56), (__int64)a3, (__int64)(a3 + 16));
      *(_BYTE *)(v15 + 64) = 1;
      goto LABEL_8;
    case 9u:
      if ( *(_BYTE *)(v15 + 64) == 1 )
      {
        cam_cpas_stop(*(_DWORD *)(v15 + 56));
        result = 0;
        *(_BYTE *)(v15 + 64) = 0;
      }
      else
      {
LABEL_54:
        result = 0;
      }
      goto LABEL_8;
    case 0xAu:
      v42 = *((_QWORD *)a1 + 424);
      v66 = 0;
      if ( !v42 )
      {
        v10 = "cam_icp_v1_ubwc_config";
        v11 = "ICP private soc info is NULL";
        v12 = 651;
        goto LABEL_6;
      }
      if ( !a3 )
      {
        v10 = "cam_icp_v1_ubwc_config";
        v11 = "Invalid ubwc cmd args is NULL";
        v12 = 656;
        goto LABEL_6;
      }
      if ( (_DWORD)a4 != 8 )
      {
        v6 = "cam_icp_v1_ubwc_config";
        v7 = "Invalid ubwc cmd size:%u";
        v9 = 661;
        goto LABEL_4;
      }
      if ( *(_BYTE *)(v42 + 68) == 1 )
      {
        result = hfi_cmd_ubwc_config(*(unsigned int *)(v15 + 60), v42 + 16);
      }
      else
      {
        v53 = (const char *)(v42 + 16);
        v54 = *(_DWORD *)(v15 + 60);
        v55 = a3[4];
        v65 = v53;
        result = cam_icp_proc_ubwc_configure(&v65, v55, v54);
      }
      goto LABEL_8;
    case 0xBu:
      if ( !v15 )
      {
        v10 = "cam_icp_v1_pc_prep";
        v11 = "Invalid ICP core info is NULL";
        v12 = 595;
        goto LABEL_6;
      }
      result = hfi_send_system_cmd(*(unsigned int *)(v15 + 60), 65538, 0, 0, a5, a6, (unsigned int)a4);
      if ( (_DWORD)result )
      {
        v21 = *(unsigned int *)(v15 + 60);
        v22 = "cam_icp_v1_pc_prep";
        v23 = "Fail to send PC collapse command for hfi handle: %d";
        v24 = result;
        v25 = 602;
LABEL_58:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          v22,
          v25,
          v23,
          v21);
        result = v24;
      }
      goto LABEL_8;
    case 0xCu:
      v65 = nullptr;
      v66 = 0;
      if ( !a3 || !v15 )
      {
        v44 = "cam_icp_v1_clk_update";
        if ( v15 )
          v26 = "Non-NULL";
        else
          v26 = "NULL";
        if ( a3 )
          v27 = "Non-NULL";
        else
          v27 = "NULL";
        v45 = "Invalid args: core info is %s cmd args is %s";
        v46 = 619;
        goto LABEL_91;
      }
      if ( (_DWORD)a4 != 4 )
      {
        v10 = "cam_icp_v1_clk_update";
        v11 = "Invalid icp clock update command";
        v12 = 624;
        goto LABEL_6;
      }
      v18 = *(_DWORD *)a3;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_v1_clk_update",
          629,
          "Update ICP clock to level [%d]",
          v18);
      updated = cam_icp_soc_update_clk_rate(a1 + 96, v18, *(unsigned int *)(v15 + 60));
      if ( updated )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_v1_clk_update",
          632,
          "Failed to update clk to level: %d rc: %d",
          v18,
          updated);
      v20 = *(_DWORD *)(v15 + 56);
      LODWORD(v65) = 0;
      LODWORD(v66) = v18;
      cam_cpas_update_ahb_vote(v20, (__int64)&v65);
      result = updated;
      goto LABEL_8;
    case 0xDu:
      if ( !a3 || !v15 )
      {
        v44 = "cam_icp_v1_fw_dump";
        v45 = "invalid params %pK %pK";
        v27 = (const char *)a3;
        v46 = 137;
        v26 = *((const char **)a1 + 460);
        goto LABEL_91;
      }
      v26 = *(const char **)(v15 + 24);
      v27 = *(const char **)a3;
      if ( !v26 || !v27 )
      {
        v44 = "cam_icp_v1_fw_dump";
        v45 = "invalid params %pK, 0x%zx";
        v46 = 142;
        goto LABEL_91;
      }
      v28 = *((_QWORD *)a3 + 1);
      v29 = *((_QWORD *)a3 + 2);
      if ( v28 <= v29 )
      {
        v30 = "Dump offset overshoot len %zu offset %zu";
        v31 = 151;
      }
      else
      {
        if ( v28 - v29 >= *(_QWORD *)(v15 + 32) + 144LL )
        {
          v56 = &v27[v29];
          scnprintf(&v27[v29], 128, "ICP_FW:");
          *((_DWORD *)v56 + 34) = 1;
          *((_QWORD *)v56 + 16) = *(_QWORD *)(v15 + 32);
          _memcpy_fromio(v56 + 144, *(_QWORD *)(v15 + 24));
          result = 0;
          *((_QWORD *)a3 + 2) += *((_QWORD *)v56 + 16) + 144LL;
          goto LABEL_8;
        }
        v30 = "Dump buffer exhaust required %llu len %llu";
        v31 = 157;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        2,
        "cam_icp_v1_fw_dump",
        v31,
        v30);
      result = 4294967268LL;
      goto LABEL_8;
    case 0xEu:
      if ( !v15 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_v1_fw_mini_dump",
          177,
          "Invalid param %pK",
          nullptr);
        goto LABEL_7;
      }
      result = cam_icp_proc_mini_dump(a3, *(_QWORD *)(v15 + 24), *(_QWORD *)(v15 + 32), a4, a5, a6, (unsigned int)a4);
      goto LABEL_8;
    case 0x10u:
      if ( !a3 || !v15 )
      {
        v44 = "cam_icp_v1_process_cmd";
        if ( v15 )
          v26 = "Non-NULL";
        else
          v26 = "NULL";
        if ( a3 )
          v27 = "Non-NULL";
        else
          v27 = "NULL";
        v45 = "Core info is %s and args is %s";
        v46 = 729;
LABEL_91:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, const char *))cam_print_log)(
          3,
          256,
          1,
          v44,
          v46,
          v45,
          v26,
          v27);
        goto LABEL_7;
      }
      if ( (_DWORD)a4 != 4 )
      {
        v6 = "cam_icp_v1_process_cmd";
        v7 = "Invalid set hfi handle command arg size:%u";
        v9 = 735;
        goto LABEL_4;
      }
      result = 0;
      *(_DWORD *)(v15 + 60) = *(_DWORD *)a3;
      goto LABEL_8;
    default:
      goto LABEL_8;
  }
}
