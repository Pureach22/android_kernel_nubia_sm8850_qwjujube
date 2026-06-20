__int64 __fastcall cam_ois_fw_download_v2(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v7; // w8
  int v8; // w0
  __int64 result; // x0
  unsigned int v10; // w20
  __int64 v11; // x27
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x6
  _DWORD *v15; // x21
  int v16; // w28
  unsigned __int64 v17; // x22
  unsigned int v18; // w0
  __int64 v19; // x1
  int v20; // w0
  int v21; // w8
  int v22; // w8
  __int64 v23; // x20
  int v24; // w8
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x11
  __int64 v28; // x8
  __int64 v29; // x25
  unsigned int v30; // w26
  __int64 v31; // x9
  __int64 v32; // x0
  __int64 v33; // x22
  int v34; // w8
  int v35; // w9
  unsigned __int64 v36; // x27
  unsigned int v37; // w10
  int v38; // w8
  unsigned int v39; // w26
  unsigned __int16 *v40; // x20
  unsigned __int64 v41; // x8
  int v42; // w10
  __int64 v43; // x9
  __int64 v44; // x11
  int v45; // w12
  __int64 v46; // x4
  const char *v47; // x5
  __int64 v48; // x1
  int v49; // w0
  _QWORD *v50; // x0
  unsigned int v51; // w19
  const char *v52; // x5
  __int64 v53; // x4
  __int64 v54; // [xsp+28h] [xbp-98h]
  __int64 v55; // [xsp+30h] [xbp-90h]
  unsigned int v56; // [xsp+3Ch] [xbp-84h]
  _QWORD *v57; // [xsp+40h] [xbp-80h] BYREF
  __int64 v58; // [xsp+48h] [xbp-78h] BYREF
  int v59; // [xsp+50h] [xbp-70h]
  int v60; // [xsp+54h] [xbp-6Ch]
  __int64 v61; // [xsp+58h] [xbp-68h]
  __int64 v62; // [xsp+60h] [xbp-60h]
  __int64 v63; // [xsp+68h] [xbp-58h]
  _QWORD v64[10]; // [xsp+70h] [xbp-50h] BYREF

  v64[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a1 + 4616);
  v57 = nullptr;
  if ( v7 == 1 )
  {
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_download_v2",
        1154,
        "check version to decide FW download");
    v8 = cam_ois_apply_settings(a1, a1 + 4600);
    if ( v8 == -11 )
    {
      if ( *(_DWORD *)(a1 + 3656) == 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          2,
          "cam_ois_fw_download_v2",
          1159,
          "CCI HW is resetting: Reapplying FW init settings");
        usleep_range_state(1000, 1010, 2);
        v8 = cam_ois_apply_settings(a1, a1 + 4600);
      }
      else
      {
        v8 = -11;
      }
    }
    v10 = v8;
    if ( (delete_request(a1 + 4600) & 0x80000000) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        2,
        "cam_ois_fw_download_v2",
        1167,
        "Fail deleting i2c_fw_version_data: rc: %d",
        v10);
    if ( v10 == 1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        3,
        "cam_ois_fw_download_v2",
        1174,
        "OIS FW version not matched, load FW");
      result = 1;
    }
    else
    {
      if ( !v10 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          3,
          "cam_ois_fw_download_v2",
          1171,
          "OIS FW version matched, skipping FW download");
        result = 0;
        goto LABEL_92;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        2,
        "cam_ois_fw_download_v2",
        1176,
        "OIS FW version check failed,rc=%d",
        v10);
      result = v10;
    }
  }
  else
  {
    result = 0;
  }
  v11 = *(unsigned __int8 *)(a1 + 4572);
  if ( !*(_BYTE *)(a1 + 4572) )
    goto LABEL_92;
  v12 = 0;
  v13 = *(_QWORD *)(a1 + 4574);
  v14 = 0;
  v15 = (_DWORD *)(a1 + 3656);
  v16 = *(_BYTE *)(a1 + 4573) & 0xF;
  v56 = 0;
  _ReadStatusReg(SP_EL0);
  v54 = v11;
  while ( 2 )
  {
    v17 = *(unsigned int *)(v13 + 36);
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_download_v2",
        1191,
        "count: %d, fw_size: %d, data_type: %d, len_per_write: %d",
        v14,
        v17,
        *(unsigned __int8 *)(v13 + 45),
        (unsigned __int16)(*(_DWORD *)(v13 + 40) / (unsigned int)*(unsigned __int8 *)(v13 + 45)));
    v18 = request_firmware(&v57, v13, *(_QWORD *)(a1 + 24) + 16LL, a4, a5, a6, v14);
    if ( v18 )
    {
      v51 = v18;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_fw_download_v2",
        1197,
        "Failed to locate %s",
        (const char *)v13);
LABEL_91:
      result = v51;
      goto LABEL_92;
    }
    if ( !v57 )
      goto LABEL_19;
    if ( *v57 - (unsigned __int64)*(unsigned int *)(v13 + 32) < v17 )
      goto LABEL_83;
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_download_v2",
        1205,
        "fw init");
    v19 = *(_QWORD *)(a1 + 4584) + 48 * v12;
    if ( *(_DWORD *)(v19 + 16) != 1 )
      goto LABEL_36;
    v20 = cam_ois_apply_settings(a1, v19);
    if ( v20 == -11 )
    {
      if ( *v15 != 1 )
      {
        v20 = -11;
        goto LABEL_94;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        2,
        "cam_ois_fw_download_v2",
        1212,
        "CCI HW is resetting: Reapplying FW init settings");
      usleep_range_state(1000, 1010, 2);
      v20 = cam_ois_apply_settings(a1, *(_QWORD *)(a1 + 4584) + 48 * v12);
    }
    if ( v20 )
    {
LABEL_94:
      v52 = "Cannot apply FW init settings %d";
      v51 = v20;
      v53 = 1220;
LABEL_97:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_fw_download_v2",
        v53,
        v52,
        v51);
      result = v51;
      if ( !v57 )
        goto LABEL_92;
      release_firmware(v57);
      goto LABEL_91;
    }
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_download_v2",
        1223,
        "OIS FW init settings success");
      v21 = debug_mdl;
      if ( (debug_mdl & 0x100000) == 0 )
        goto LABEL_39;
      goto LABEL_37;
    }
LABEL_36:
    v21 = debug_mdl;
    if ( (debug_mdl & 0x100000) == 0 )
      goto LABEL_39;
LABEL_37:
    if ( !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v21 & 0x100000LL,
        4,
        "cam_ois_fw_download_v2",
        1228,
        "send fw, operation %d",
        *(unsigned __int8 *)(v13 + 46));
LABEL_39:
    v22 = *(unsigned __int8 *)(v13 + 46);
    v23 = v57[1];
    v55 = *(unsigned int *)(v13 + 32);
    if ( v22 == 1 )
    {
      v56 = 0;
    }
    else
    {
      if ( v22 == 5 )
      {
        v24 = 2;
      }
      else
      {
        if ( v22 != 3 )
          goto LABEL_46;
        v24 = 1;
      }
      v56 = v24;
    }
LABEL_46:
    v25 = *(_QWORD *)(a1 + 3696);
    v26 = *(_QWORD *)(a1 + 3704);
    v27 = *(_QWORD *)(a1 + 3688);
    v64[7] = *(_QWORD *)(a1 + 3712);
    v64[5] = v25;
    v64[6] = v26;
    v28 = *(_QWORD *)(a1 + 3664);
    v29 = *(unsigned __int8 *)(v13 + 45);
    v30 = *(_DWORD *)(v13 + 40) / (unsigned int)v29;
    v64[0] = *(_QWORD *)v15;
    v64[1] = v28;
    v31 = *(_QWORD *)(a1 + 3672);
    v64[3] = *(_QWORD *)(a1 + 3680);
    v64[4] = v27;
    v64[2] = v31;
    v62 = 0;
    v63 = 0;
    v61 = 0;
    v32 = vmalloc_noprof(16 * (unsigned int)(unsigned __int16)v30);
    v33 = v32;
    if ( !v32 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "write_ois_fw",
        1072,
        "Failed in allocating i2c_array: size: %u",
        16 * (unsigned __int16)v30);
      goto LABEL_73;
    }
    v34 = *(unsigned __int8 *)(v13 + 45);
    v35 = *(unsigned __int8 *)(v13 + 44);
    v36 = (unsigned __int16)v30;
    v37 = *(_DWORD *)(v13 + 36);
    v58 = v32;
    v60 = v35;
    LODWORD(v61) = v34;
    v38 = *(_DWORD *)(v13 + 48);
    v59 = (unsigned __int16)v30;
    WORD2(v61) = v38;
    if ( v37 < (unsigned int)v29 )
      goto LABEL_69;
    v39 = 0;
    v40 = (unsigned __int16 *)(v23 + v55);
    while ( !(_DWORD)v36 )
    {
LABEL_64:
      if ( (_BYTE)v56 )
      {
        if ( (camera_io_dev_write_continuous(v64, &v58, v56) & 0x80000000) != 0 )
        {
LABEL_66:
          v46 = 1122;
          v47 = "Failed in Applying i2c wrt settings";
          goto LABEL_68;
        }
      }
      else if ( (camera_io_dev_write(v64, &v58) & 0x80000000) != 0 )
      {
        goto LABEL_66;
      }
      v39 += v36;
      if ( v39 >= *(_DWORD *)(v13 + 36) / (unsigned int)v29 )
        goto LABEL_69;
    }
    v41 = 0;
    while ( 1 )
    {
      v43 = 16 * v41;
      *(_DWORD *)(v58 + 16 * v41) = v39 + v41 + *(_DWORD *)(v13 + 52);
      if ( v16 == 1 )
        break;
      if ( v16 )
        goto LABEL_55;
      v44 = 0;
      v42 = 0;
      do
      {
        v45 = *((unsigned __int8 *)v40 + v44++);
        v42 = v45 | (v42 << 8);
      }
      while ( v29 != v44 );
LABEL_54:
      *(_DWORD *)(v58 + 16 * v41 + 4) = v42;
LABEL_55:
      ++v41;
      v40 = (unsigned __int16 *)((char *)v40 + v29);
      *(_DWORD *)(v58 + v43 + 8) = *(_DWORD *)(v13 + 48);
      *(_DWORD *)(v58 + v43 + 12) = 0;
      if ( v41 >= v36 )
        goto LABEL_64;
    }
    if ( (_DWORD)v29 == 2 )
    {
      v42 = *v40;
      goto LABEL_54;
    }
    if ( (_DWORD)v29 == 1 )
    {
      v42 = *(unsigned __int8 *)v40;
      goto LABEL_54;
    }
    v46 = 1101;
    v47 = "Unsupported data type";
LABEL_68:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "write_ois_fw",
      v46,
      v47);
LABEL_69:
    vfree(v33);
    v11 = v54;
LABEL_73:
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_download_v2",
        1242,
        "fw finalize");
    v48 = *(_QWORD *)(a1 + 4592) + 48 * v12;
    if ( *(_DWORD *)(v48 + 16) != 1 )
    {
LABEL_83:
      v50 = v57;
      if ( !v57 )
        goto LABEL_19;
      goto LABEL_84;
    }
    v49 = cam_ois_apply_settings(a1, v48);
    if ( v49 != -11 )
      goto LABEL_80;
    if ( *v15 != 1 )
    {
      v49 = -11;
LABEL_96:
      v52 = "Cannot apply FW finalize settings %d";
      v51 = v49;
      v53 = 1257;
      goto LABEL_97;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      2,
      "cam_ois_fw_download_v2",
      1249,
      "CCI HW is resetting: Reapplying FW finalize settings");
    usleep_range_state(1000, 1010, 2);
    v49 = cam_ois_apply_settings(a1, *(_QWORD *)(a1 + 4592) + 48 * v12);
LABEL_80:
    if ( v49 )
      goto LABEL_96;
    if ( (debug_mdl & 0x100000) == 0 || debug_priority )
      goto LABEL_83;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x100000,
      4,
      "cam_ois_fw_download_v2",
      1260,
      "OIS FW finalize settings success");
    v50 = v57;
    if ( v57 )
    {
LABEL_84:
      release_firmware(v50);
      v57 = nullptr;
    }
LABEL_19:
    ++v12;
    v13 += 64;
    v14 = (unsigned int)v12;
    if ( v12 != v11 )
      continue;
    break;
  }
  result = 0;
LABEL_92:
  _ReadStatusReg(SP_EL0);
  return result;
}
