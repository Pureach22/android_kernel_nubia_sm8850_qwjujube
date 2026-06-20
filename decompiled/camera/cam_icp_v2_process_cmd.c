__int64 __fastcall cam_icp_v2_process_cmd(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  _BYTE *v6; // x21
  __int64 v7; // x22
  unsigned __int8 *v8; // x23
  __int64 v9; // x24
  __int64 v10; // x19
  __int64 result; // x0
  __int64 v12; // x20
  int v13; // w21
  __int64 v14; // x0
  int v15; // w20
  __int64 v16; // x0
  int v17; // w0
  const char *v18; // x3
  const char *v19; // x5
  __int64 v20; // x4
  unsigned int v21; // w20
  __int64 v22; // x8
  unsigned int v23; // w11
  unsigned int v24; // w10
  __int64 v25; // x23
  int v26; // w0
  unsigned int v27; // w20
  unsigned int v28; // w20
  unsigned int v29; // w20
  unsigned int v30; // w20
  unsigned int v31; // w20
  unsigned int v32; // w20
  __int64 v33; // x19
  __int64 v34; // x6
  const char *v35; // x3
  const char *v36; // x5
  unsigned int v37; // w19
  __int64 v38; // x2
  __int64 v39; // x4
  __int64 v40; // x8
  __int64 v41; // x19
  __int64 v42; // x21
  unsigned int v43; // w20
  int updated; // w0
  unsigned int v45; // w0
  int v46; // w21
  const char *v47; // x6
  unsigned __int8 *v49; // x8
  __int64 v50; // x23
  __int64 v51; // x21
  __int64 v52; // x0
  unsigned int v53; // w24
  __int64 v54; // x22
  unsigned int v55; // w0
  unsigned int v56; // w20
  __int64 v57; // x8
  __int64 v58; // x19
  __int64 v59; // x8
  char *v60; // x6
  __int64 v61; // x19
  char *v62; // x20
  __int64 v64; // x0
  __int64 v65; // x8
  unsigned int v66; // w10
  __int64 v67; // x1
  __int64 v68; // x2
  __int64 v69; // x19
  __int64 v70; // x20
  __int64 v71; // x0
  const char *v72; // x6
  const char *v73; // x7
  const char *v74; // x7
  const char *v75; // x8
  const char *v76; // x3
  const char *v77; // x5
  __int64 v78; // x4
  unsigned int v79; // w6
  __int64 v80; // x20
  unsigned __int8 *v81; // x21
  __int64 v82; // x0
  __int64 v83; // x21
  _QWORD *v84; // x22
  __int64 v85; // x0
  unsigned int v86; // w0
  __int64 v87; // x0
  void *v88; // x0
  void *v89; // x20
  __int64 v90; // x0
  unsigned int v91; // w0
  unsigned int v92; // w0
  const char *v93; // x3
  const char *v94; // x5
  __int64 v95; // x4
  __int64 v96; // x8
  __int64 v97; // x21
  unsigned int v98; // w0
  const char *v99; // x5
  __int64 v100; // x4
  __int64 v101; // x21
  __int64 v102; // x25
  __int64 v103; // x24
  unsigned int v104; // w0
  unsigned int fw_size; // w0
  __int64 v106; // x21
  __int64 v107; // x0
  unsigned __int64 size; // x0
  __int64 v109; // x2
  __int64 v110; // x0
  __int64 v111; // x22
  unsigned int v112; // w0
  unsigned __int64 v113; // x7
  unsigned int v114; // w0
  unsigned __int64 StatusReg; // x20
  __int64 v116; // x25
  __int64 v117; // [xsp+38h] [xbp-298h]
  unsigned int v118; // [xsp+44h] [xbp-28Ch]
  __int64 v119; // [xsp+48h] [xbp-288h] BYREF
  char *v120; // [xsp+50h] [xbp-280h] BYREF
  char *v121[4]; // [xsp+58h] [xbp-278h] BYREF
  char *v122; // [xsp+78h] [xbp-258h] BYREF
  __int64 v123; // [xsp+80h] [xbp-250h]
  __int64 v124; // [xsp+88h] [xbp-248h]
  __int64 v125; // [xsp+90h] [xbp-240h]
  __int64 v126; // [xsp+98h] [xbp-238h]
  __int64 v127; // [xsp+A0h] [xbp-230h]
  __int64 v128; // [xsp+A8h] [xbp-228h]
  __int64 v129; // [xsp+B0h] [xbp-220h]
  __int64 v130; // [xsp+B8h] [xbp-218h]
  __int64 v131; // [xsp+C0h] [xbp-210h]
  _QWORD s[65]; // [xsp+C8h] [xbp-208h] BYREF

  s[64] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v10 = a1;
    result = 0;
    switch ( a2 )
    {
      case 0u:
        v12 = *(_QWORD *)(v10 + 3680);
        if ( !v12 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "prepare_shutdown",
            439,
            "invalid args:core_info is NULL icp_v2_info=%pK",
            (const void *)v10);
          v18 = "cam_icp_v2_shutdown";
          v19 = "prepare shutdown failed";
          v20 = 907;
          goto LABEL_12;
        }
        v7 = *(_QWORD *)(v10 + 3392);
        v8 = a3;
        *(_DWORD *)(v12 + 80) = 0;
        v13 = a4;
        *(_QWORD *)(v12 + 88) = 0;
        *(_QWORD *)(v12 + 96) = 0;
        v14 = raw_spin_lock_irqsave(v10 + 48);
        *(_QWORD *)v12 = 0;
        *(_QWORD *)(v12 + 8) = 0;
        raw_spin_unlock_irqrestore(v10 + 48, v14);
        if ( v13 == 1 )
        {
          v6 = (_BYTE *)(v12 + 105);
          if ( (*(_BYTE *)(v12 + 105) & 1) != 0 )
          {
            v15 = *v8;
            result = qcom_scm_pas_shutdown(*(unsigned int *)(v7 + 12));
            if ( v15 == 1 )
            {
              v8 = *(unsigned __int8 **)(v10 + 96);
              LODWORD(v7) = result;
              v16 = *((_QWORD *)v8 + 95);
              memset(s, 0, 96);
              v130 = 0;
              v131 = 0;
              v128 = 0;
              v129 = 0;
              v126 = 0;
              v127 = 0;
              v124 = 0;
              v125 = 0;
              v122 = nullptr;
              v123 = 0;
              if ( (unsigned int)_of_parse_phandle_with_args(v16, "memory-region", 0, 0, 0, &v122) || !v122 )
                goto LABEL_188;
              v17 = of_address_to_resource(v122, 0, s);
              if ( v17 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  256,
                  1,
                  "cam_icp_v2_fw_coredump",
                  55,
                  "Failed to get firmware resource address rc=%d",
                  v17);
                goto LABEL_188;
              }
              v9 = s[1] - s[0];
              v87 = memremap();
              if ( !v87 )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  256,
                  1,
                  "cam_icp_v2_fw_coredump",
                  64,
                  "Unable to map firmware carve out");
LABEL_188:
                result = (unsigned int)v7;
                *v6 = 0;
                goto LABEL_14;
              }
              v10 = v87;
              v88 = (void *)vmalloc_noprof(v9 + 1);
              if ( v88 )
                goto LABEL_140;
              goto LABEL_186;
            }
LABEL_110:
            *v6 = 0;
            goto LABEL_14;
          }
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_v2_shutdown",
            912,
            "Invalid args size %u",
            v13);
          v6 = (_BYTE *)(v12 + 105);
          if ( *(_BYTE *)(v12 + 105) == 1 )
          {
            result = qcom_scm_pas_shutdown(*(unsigned int *)(v7 + 12));
            goto LABEL_110;
          }
        }
        v79 = *(_DWORD *)(v12 + 36);
        if ( (v79 & 0x80000000) != 0 )
        {
          v18 = "cam_icp_v2_shutdown";
          v19 = "No reg base idx found for ICP_SYS: %d";
          v20 = 926;
          goto LABEL_12;
        }
        if ( v79 > 7 )
        {
LABEL_185:
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v116 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &cam_icp_v2_fw_coredump__alloc_tag;
          v88 = (void *)vmalloc_noprof(v9 + 1);
          *(_QWORD *)(StatusReg + 80) = v116;
          if ( v88 )
          {
LABEL_140:
            v89 = v88;
            memcpy(v88, (const void *)v10, v9 + 1);
            dev_coredumpv(v8 + 16, v89, v9 + 1, 3264);
LABEL_187:
            memunmap(v10);
            goto LABEL_188;
          }
LABEL_186:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_v2_fw_coredump",
            71,
            "Failed to dynamically allocate memory of size: %llu",
            v9 + 1);
          goto LABEL_187;
        }
        cam_io_w_mb(0, *(_QWORD *)(v10 + 24LL * v79 + 384) + 4LL);
        result = 0;
        *v6 = 0;
        goto LABEL_14;
      case 1u:
        v46 = a4;
        if ( a3[41] )
          v47 = "Y";
        else
          v47 = "N";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          3,
          "cam_icp_v2_download_fw",
          1015,
          "Loading Secure PIL : %s",
          v47);
        v49 = a3;
        if ( a3[41] == 1 )
        {
          if ( !a3 )
          {
            v76 = "cam_icp_v2_boot";
            v77 = "invalid args: icp_v2_info=%pK args=%pK";
            v78 = 856;
            goto LABEL_121;
          }
          if ( v46 != 48 )
          {
            v18 = "cam_icp_v2_boot";
            v19 = "invalid boot args size";
            v20 = 861;
            goto LABEL_12;
          }
          v50 = *(_QWORD *)(v10 + 3680);
          if ( !v50 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "prepare_boot",
              389,
              "invalid args: core_info is NULL icp_v2_info=%pK args=%pK",
              (const void *)v10,
              a3);
            v18 = "cam_icp_v2_boot";
            v19 = "prepare boot failed";
            v20 = 870;
            goto LABEL_12;
          }
          v51 = *(_QWORD *)(v10 + 3392);
          v52 = raw_spin_lock_irqsave(v10 + 48);
          *(_QWORD *)(v50 + 8) = *((_QWORD *)a3 + 4);
          *(_QWORD *)v50 = *((_QWORD *)a3 + 3);
          raw_spin_unlock_irqrestore(v10 + 48, v52);
          v53 = *(_DWORD *)(v51 + 12);
          v54 = *(_QWORD *)(v10 + 96);
          v119 = 0;
          v120 = nullptr;
          memset(v121, 0, sizeof(v121));
          memset(s, 0, 96);
          if ( !v54 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              766,
              "invalid args");
            v56 = -22;
            goto LABEL_148;
          }
          v55 = of_property_read_string(*(_QWORD *)(v54 + 760), "fw_name", &v120);
          if ( v55 )
          {
            v56 = v55;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              773,
              "FW image name not found");
LABEL_148:
            v93 = "cam_icp_v2_boot";
            v94 = "firmware loading failed rc=%d";
            v95 = 877;
            goto LABEL_161;
          }
          if ( strlen(v120) >= 0x1C )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              779,
              "Invalid fw name %s",
              v120);
            v56 = -22;
            goto LABEL_148;
          }
          scnprintf(v121, 32, "%s.mbn", v120);
          v90 = *(_QWORD *)(v54 + 760);
          v130 = 0;
          v131 = 0;
          v128 = 0;
          v129 = 0;
          v126 = 0;
          v127 = 0;
          v124 = 0;
          v125 = 0;
          v122 = nullptr;
          v123 = 0;
          if ( (unsigned int)_of_parse_phandle_with_args(v90, "memory-region", 0, 0, 0, &v122) || !v122 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              788,
              "firmware memory region not found");
            v56 = -19;
            goto LABEL_148;
          }
          v118 = v53;
          v91 = of_address_to_resource(v122, 0, s);
          if ( v91 )
          {
            v56 = v91;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              795,
              "missing firmware resource address rc=%d",
              v91);
            goto LABEL_148;
          }
          v117 = v51;
          v101 = s[0];
          v102 = s[1];
          v103 = v54;
          v104 = firmware_request_nowarn(&v119, v121, v54 + 16);
          if ( v104 )
          {
            v56 = v104;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              806,
              "error requesting %s firmware rc=%d",
              (const char *)v121,
              v104);
            goto LABEL_148;
          }
          size = qcom_mdt_get_size(v119);
          if ( (size & 0x8000000000000000LL) != 0 || v102 - v101 + 1 < size )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              815,
              "carveout[sz=%zu] not big enough for firmware[sz=%zd]",
              v102 - v101 + 1,
              size);
            v56 = -22;
            goto LABEL_179;
          }
          if ( arm64_use_ng_mappings )
            v109 = 0x68000000000F0BLL;
          else
            v109 = 0x6800000000070BLL;
          v110 = ioremap_prot(v101, v102 - v101 + 1, v109);
          if ( !v110 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              822,
              "unable to map firmware carveout");
            v56 = -12;
            goto LABEL_179;
          }
          v111 = v110;
          v112 = qcom_mdt_load(v103 + 16, v119, v121, v118, v110, v101, v102 - v101 + 1, 0);
          if ( v112 )
          {
            v56 = v112;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "__load_firmware",
              830,
              "failed to load firmware rc=%d",
              v112);
            iounmap(v111);
LABEL_179:
            release_firmware(v119);
            goto LABEL_148;
          }
          iounmap(v111);
          release_firmware(v119);
          result = qcom_scm_pas_auth_and_reset(*(unsigned int *)(v117 + 12));
          if ( !(_DWORD)result )
          {
            *(_BYTE *)(v50 + 105) = 1;
            goto LABEL_14;
          }
          v56 = result;
          v93 = "cam_icp_v2_boot";
          v94 = "auth and reset failed rc=%d";
          v95 = 884;
          goto LABEL_161;
        }
        if ( !a3 )
        {
          v76 = "cam_icp_v2_non_sec_boot";
          v77 = "invalid args: icp_v2_dev=%pK args=%pK";
          v78 = 707;
          goto LABEL_121;
        }
        if ( v46 != 48 )
        {
          v18 = "cam_icp_v2_non_sec_boot";
          v19 = "invalid boot args size";
          v20 = 712;
          goto LABEL_12;
        }
        if ( *(_DWORD *)(v10 + 216) >= 6u )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_v2_non_sec_boot",
            719,
            "check reg config in DT v 0x%x n %d",
            *(unsigned int *)(*(_QWORD *)(v10 + 3392) + 8LL));
          goto LABEL_13;
        }
        v80 = *(_QWORD *)(v10 + 3680);
        if ( !v80 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "prepare_boot",
            389,
            "invalid args: core_info is NULL icp_v2_info=%pK args=%pK",
            (const void *)v10,
            v49);
          v18 = "cam_icp_v2_non_sec_boot";
          v19 = "prepare boot failed";
          v20 = 725;
          goto LABEL_12;
        }
        v81 = v49;
        *(_DWORD *)(v80 + 80) = *(_DWORD *)v49;
        *(_QWORD *)(v80 + 88) = *((_QWORD *)v49 + 1);
        *(_QWORD *)(v80 + 96) = *((_QWORD *)v49 + 2);
        v82 = raw_spin_lock_irqsave(v10 + 48);
        *(_QWORD *)(v80 + 8) = *((_QWORD *)v81 + 4);
        *(_QWORD *)v80 = *((_QWORD *)v81 + 3);
        raw_spin_unlock_irqrestore(v10 + 48, v82);
        v83 = *(_QWORD *)(v10 + 96);
        v84 = *(_QWORD **)(v10 + 3680);
        LODWORD(v121[0]) = 0;
        v85 = *(_QWORD *)(v83 + 760);
        memset(s, 0, 32);
        v122 = nullptr;
        v86 = of_property_read_string(v85, "fw_name", &v122);
        if ( v86 )
        {
          v56 = v86;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            1,
            "__cam_non_sec_load_fw",
            622,
            "FW image name not found");
LABEL_160:
          v93 = "cam_icp_v2_non_sec_boot";
          v94 = "firmware download failed rc=%d";
          v95 = 733;
          goto LABEL_161;
        }
        if ( strlen(v122) >= 0x1C )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "__cam_non_sec_load_fw",
            628,
            "Invalid fw name %s",
            v122);
          v56 = -22;
          goto LABEL_160;
        }
        scnprintf(s, 32, "%s.elf", v122);
        v92 = firmware_request_nowarn(v84 + 8, s, v83 + 16);
        if ( v92 )
        {
          v56 = v92;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "__cam_non_sec_load_fw",
            639,
            "Failed to locate %s fw: %d",
            (const char *)s,
            v92);
          goto LABEL_160;
        }
        v96 = v84[8];
        if ( v96 )
        {
          v97 = *(_QWORD *)(v96 + 8);
          v98 = cam_icp_validate_fw(v97, 94);
          if ( v98 )
          {
            v56 = v98;
            v99 = "fw elf validation failed";
            v100 = 653;
          }
          else
          {
            fw_size = cam_icp_get_fw_size(v97, v121);
            if ( fw_size )
            {
              v56 = fw_size;
              v99 = "unable to get fw size";
              v100 = 659;
            }
            else
            {
              v113 = v84[12];
              if ( v113 < LODWORD(v121[0]) )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  256,
                  1,
                  "__cam_non_sec_load_fw",
                  665,
                  "mismatch in fw size: %u %llu",
                  LODWORD(v121[0]),
                  v113);
                v56 = -22;
                goto LABEL_159;
              }
              v114 = cam_icp_program_fw(v97, v84[11]);
              if ( !v114 )
              {
                release_firmware(v84[8]);
                result = _cam_icp_v2_power_resume(v10);
                if ( !(_DWORD)result )
                  goto LABEL_14;
                v56 = result;
                v93 = "cam_icp_v2_non_sec_boot";
                v94 = "ICP boot failed rc=%d";
                v95 = 739;
LABEL_161:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                  3,
                  256,
                  1,
                  v93,
                  v95,
                  v94,
                  v56);
                v106 = *(_QWORD *)(v10 + 3680);
                if ( v106 )
                {
                  *(_DWORD *)(v106 + 80) = 0;
                  *(_QWORD *)(v106 + 88) = 0;
                  *(_QWORD *)(v106 + 96) = 0;
                  v107 = raw_spin_lock_irqsave(v10 + 48);
                  *(_QWORD *)v106 = 0;
                  *(_QWORD *)(v106 + 8) = 0;
                  raw_spin_unlock_irqrestore(v10 + 48, v107);
                }
                else
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    256,
                    1,
                    "prepare_shutdown",
                    439,
                    "invalid args:core_info is NULL icp_v2_info=%pK",
                    (const void *)v10);
                }
                result = v56;
                goto LABEL_14;
              }
              v56 = v114;
              v99 = "fw program is failed";
              v100 = 673;
            }
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            1,
            "__cam_non_sec_load_fw",
            v100,
            v99);
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            1,
            "__cam_non_sec_load_fw",
            644,
            "Invalid elf size");
          v56 = -22;
        }
LABEL_159:
        release_firmware(v84[8]);
        goto LABEL_160;
      case 2u:
        result = cam_icp_v2_core_control(v10, 0);
        goto LABEL_14;
      case 3u:
        result = cam_icp_v2_core_control(v10, 1);
        goto LABEL_14;
      case 6u:
        v41 = *(_QWORD *)(v10 + 3680);
        if ( !v41 )
        {
          v18 = "cam_icp_v2_send_fw_init";
          v19 = "Core info is NULL";
          v20 = 1089;
          goto LABEL_12;
        }
        result = hfi_send_system_cmd(*(unsigned int *)(v41 + 52), 65537, 0, 0, a5, a6, a2);
        if ( !(_DWORD)result )
          goto LABEL_14;
        v34 = *(unsigned int *)(v41 + 52);
        v35 = "cam_icp_v2_send_fw_init";
        v36 = "Fail to send sys init command for hfi handle: %d";
        v37 = result;
        v38 = 1;
        v39 = 1096;
        goto LABEL_79;
      case 7u:
        v57 = *(_QWORD *)(v10 + 3680);
        if ( !v57 )
          goto LABEL_13;
        result = cam_icp_proc_cpas_vote(*(unsigned int *)(v57 + 44), a3);
        goto LABEL_14;
      case 8u:
        v58 = *(_QWORD *)(v10 + 3680);
        if ( !v58 || (*(_BYTE *)(v58 + 104) & 1) != 0 )
          goto LABEL_13;
        result = cam_cpas_start(*(_DWORD *)(v58 + 44), (__int64)a3, (__int64)(a3 + 16));
        if ( (_DWORD)result )
        {
          v35 = "__icp_v2_cpas_start";
          v36 = "failed to start cpas rc=%d";
          v37 = result;
          v38 = 1;
          v39 = 204;
          goto LABEL_78;
        }
        *(_BYTE *)(v58 + 104) = 1;
        goto LABEL_14;
      case 9u:
        v69 = *(_QWORD *)(v10 + 3680);
        if ( !v69 || *(_BYTE *)(v69 + 104) != 1 )
          goto LABEL_13;
        result = cam_cpas_stop(*(_DWORD *)(v69 + 44));
        if ( (_DWORD)result )
        {
          v35 = "cam_icp_v2_cpas_stop";
          v36 = "failed to stop cpas rc=%d";
          v37 = result;
          v38 = 1;
          v39 = 239;
          goto LABEL_78;
        }
        *(_BYTE *)(v69 + 104) = 0;
        goto LABEL_14;
      case 0xAu:
        v65 = *(_QWORD *)(v10 + 3680);
        s[1] = 0;
        if ( !a3 || !v65 )
        {
          if ( v65 )
            v74 = "Non-NULL";
          else
            v74 = "NULL";
          if ( a3 )
            v75 = "Non-NULL";
          else
            v75 = "NULL";
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_v2_ubwc_configure",
            93,
            "Invalid args: soc info is %s core info is %s cmd args is %s",
            "Non-NULL",
            v74,
            v75);
          goto LABEL_13;
        }
        if ( (_DWORD)a4 == 8 )
        {
          v66 = *(_DWORD *)a3;
          v67 = a3[4];
          v68 = *(unsigned int *)(v65 + 52);
          s[0] = *(_QWORD *)(v10 + 3392) + 16LL;
          LODWORD(s[1]) = v66;
          result = cam_icp_proc_ubwc_configure(s, v67, v68);
          goto LABEL_14;
        }
        v19 = "Invalid ubwc cfg arg size: %u";
        v18 = "cam_icp_v2_ubwc_configure";
        v20 = 99;
        goto LABEL_12;
      case 0xBu:
        v33 = *(_QWORD *)(v10 + 3680);
        if ( !v33 )
        {
          v18 = "cam_icp_v2_pc_prep";
          v19 = "Invalid core info is NULL";
          v20 = 1108;
          goto LABEL_12;
        }
        result = hfi_send_system_cmd(*(unsigned int *)(v33 + 52), 65538, 0, 0, a5, a6, a2);
        if ( !(_DWORD)result )
          goto LABEL_14;
        v34 = *(unsigned int *)(v33 + 52);
        v35 = "cam_icp_v2_pc_prep";
        v36 = "Fail to send PC collapse command for hfi handle: %d";
        v37 = result;
        v38 = 1;
        v39 = 1115;
        goto LABEL_79;
      case 0xCu:
        s[0] = 0;
        s[1] = 0;
        if ( !a3 )
        {
          v18 = "__cam_icp_v2_update_clk_rate";
          v19 = "Invalid args is NULL";
          v20 = 1036;
          goto LABEL_12;
        }
        v42 = *(_QWORD *)(v10 + 3680);
        if ( !v42 )
        {
          v18 = "__cam_icp_v2_update_clk_rate";
          v19 = "Invalid args";
          v20 = 1043;
          goto LABEL_12;
        }
        if ( (_DWORD)a4 != 4 )
        {
          v18 = "__cam_icp_v2_update_clk_rate";
          v19 = "Invalid icp update clk args";
          v20 = 1048;
          goto LABEL_12;
        }
        v43 = *(_DWORD *)a3;
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "__cam_icp_v2_update_clk_rate",
            1054,
            "Update ICP clock to level [%d]",
            v43);
        updated = cam_icp_soc_update_clk_rate(v10 + 96, v43, *(unsigned int *)(v42 + 52));
        if ( updated )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            2,
            "__cam_icp_v2_update_clk_rate",
            1059,
            "Failed to update clk to level: %d rc: %d",
            v43,
            updated);
        v45 = *(_DWORD *)(v42 + 44);
        LODWORD(s[0]) = 0;
        LODWORD(s[1]) = v43;
        result = cam_cpas_update_ahb_vote(v45, (__int64)s);
        if ( (_DWORD)result )
        {
          v35 = "__cam_icp_v2_update_clk_rate";
          v36 = "Failed to update ahb vote rc: %d";
          v37 = result;
          v38 = 2;
          v39 = 1067;
LABEL_78:
          v34 = v37;
LABEL_79:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            256,
            v38,
            v35,
            v39,
            v36,
            v34);
          result = v37;
        }
        goto LABEL_14;
      case 0xDu:
        goto LABEL_14;
      case 0xEu:
        v40 = *(_QWORD *)(v10 + 3680);
        if ( v40 )
        {
          result = cam_icp_proc_mini_dump(a3, *(_QWORD *)(v40 + 88), *(_QWORD *)(v40 + 96), a4, a5, a6, a2);
          goto LABEL_14;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "__cam_icp_v2_fw_mini_dump",
          1076,
          "Invalid param %pK",
          nullptr);
        goto LABEL_13;
      case 0xFu:
        if ( !a3 )
        {
          v18 = "cam_icp_v2_process_cmd";
          v19 = "Invalid args";
          v20 = 1204;
          goto LABEL_12;
        }
        v21 = *(_DWORD *)a3;
        v122 = nullptr;
        memset(s, 0, 0x200u);
        v22 = *(_QWORD *)(v10 + 3680);
        v23 = *(_DWORD *)(v22 + 24);
        if ( v23 >= 8 )
          goto LABEL_185;
        v24 = *(_DWORD *)(v22 + 56);
        if ( v24 > 7 )
          goto LABEL_185;
        v25 = *(_QWORD *)(v10 + 384 + 24LL * v23);
        if ( (v21 & 1) != 0 )
        {
          v26 = cam_io_r_mb(*(_QWORD *)(v10 + 384 + 24LL * v24) + *(unsigned int *)(*(_QWORD *)(v22 + 16) + 24LL));
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            3,
            "__cam_icp_v2_core_reg_dump",
            955,
            "ICP PFault status:0x%x",
            v26);
        }
        if ( (v21 & 2) != 0 )
        {
          v27 = cam_io_r_mb(v25 + 32);
          cam_io_r_mb(v25 + 36);
          cam_io_r_mb(v25 + 40);
          cam_io_r_mb(v25 + 44);
          cam_print_to_buffer(
            (__int64)s,
            0x200u,
            (unsigned __int64 *)&v122,
            3u,
            0x100u,
            "GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x",
            0,
            v27,
            1);
          v28 = cam_io_r_mb(v25 + 48);
          cam_io_r_mb(v25 + 52);
          cam_io_r_mb(v25 + 56);
          cam_io_r_mb(v25 + 60);
          cam_print_to_buffer(
            (__int64)s,
            0x200u,
            (unsigned __int64 *)&v122,
            3u,
            0x100u,
            "GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x",
            4,
            v28,
            5);
          v29 = cam_io_r_mb(v25 + 64);
          cam_io_r_mb(v25 + 68);
          cam_io_r_mb(v25 + 72);
          cam_io_r_mb(v25 + 76);
          cam_print_to_buffer(
            (__int64)s,
            0x200u,
            (unsigned __int64 *)&v122,
            3u,
            0x100u,
            "GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x",
            8,
            v29,
            9);
          v30 = cam_io_r_mb(v25 + 80);
          cam_io_r_mb(v25 + 84);
          cam_io_r_mb(v25 + 88);
          cam_io_r_mb(v25 + 92);
          cam_print_to_buffer(
            (__int64)s,
            0x200u,
            (unsigned __int64 *)&v122,
            3u,
            0x100u,
            "GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x",
            12,
            v30,
            13);
          v31 = cam_io_r_mb(v25 + 96);
          cam_io_r_mb(v25 + 100);
          cam_io_r_mb(v25 + 104);
          cam_io_r_mb(v25 + 108);
          cam_print_to_buffer(
            (__int64)s,
            0x200u,
            (unsigned __int64 *)&v122,
            3u,
            0x100u,
            "GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x",
            16,
            v31,
            17);
          v32 = cam_io_r_mb(v25 + 112);
          cam_io_r_mb(v25 + 116);
          cam_io_r_mb(v25 + 120);
          cam_io_r_mb(v25 + 124);
          cam_print_to_buffer(
            (__int64)s,
            0x200u,
            (unsigned __int64 *)&v122,
            3u,
            0x100u,
            "GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x GP_%d: 0x%x",
            20,
            v32,
            21);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            3,
            "__cam_icp_v2_core_reg_dump",
            968,
            "ICP CSR GP registers - %s",
            (const char *)s);
        }
        result = 0;
        goto LABEL_14;
      case 0x10u:
        v59 = *(_QWORD *)(v10 + 3680);
        if ( !a3 || !v59 )
        {
          if ( v59 )
            v72 = "Non-NULL";
          else
            v72 = "NULL";
          if ( a3 )
            v73 = "Non-NULL";
          else
            v73 = "NULL";
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_v2_set_hfi_handle",
            1127,
            "Core info is %s and args is %s",
            v72,
            v73);
          goto LABEL_13;
        }
        if ( (_DWORD)a4 == 4 )
        {
          result = 0;
          *(_DWORD *)(v59 + 52) = *(_DWORD *)a3;
          goto LABEL_14;
        }
        v19 = "Invalid set hfi handle command arg size:%u";
        v18 = "cam_icp_v2_set_hfi_handle";
        v20 = 1133;
        goto LABEL_12;
      case 0x11u:
        if ( !a3 )
        {
          v76 = "cam_icp_v2_prepare_boot";
          v77 = "invalid args: icp_v2_info=%pK args=%pK";
          v78 = 413;
LABEL_121:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            256,
            1,
            v76,
            v78,
            v77,
            v10,
            0);
          goto LABEL_13;
        }
        if ( (_DWORD)a4 != 48 )
        {
          v18 = "cam_icp_v2_prepare_boot";
          v19 = "invalid boot args size";
          v20 = 418;
          goto LABEL_12;
        }
        v60 = (char *)v10;
        v61 = *(_QWORD *)(v10 + 3680);
        if ( !v61 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "prepare_boot",
            389,
            "invalid args: core_info is NULL icp_v2_info=%pK args=%pK",
            v60,
            a3);
          v18 = "cam_icp_v2_prepare_boot";
          v19 = "prepare boot failed";
          v20 = 424;
          goto LABEL_12;
        }
        if ( (a3[41] & 1) == 0 )
        {
          *(_DWORD *)(v61 + 80) = *(_DWORD *)a3;
          *(_QWORD *)(v61 + 88) = *((_QWORD *)a3 + 1);
          *(_QWORD *)(v61 + 96) = *((_QWORD *)a3 + 2);
        }
        v62 = v60;
        v64 = raw_spin_lock_irqsave(v60 + 48);
        *(_QWORD *)(v61 + 8) = *((_QWORD *)a3 + 4);
        *(_QWORD *)v61 = *((_QWORD *)a3 + 3);
        raw_spin_unlock_irqrestore(v62 + 48, v64);
        result = 0;
        *(_BYTE *)(*((_QWORD *)v62 + 460) + 105LL) = 1;
        goto LABEL_14;
      case 0x12u:
        v70 = *(_QWORD *)(v10 + 3680);
        if ( v70 )
        {
          *(_DWORD *)(v70 + 80) = 0;
          *(_QWORD *)(v70 + 88) = 0;
          *(_QWORD *)(v70 + 96) = 0;
          v71 = raw_spin_lock_irqsave(v10 + 48);
          *(_QWORD *)v70 = 0;
          *(_QWORD *)(v70 + 8) = 0;
          raw_spin_unlock_irqrestore(v10 + 48, v71);
          result = 0;
          *(_BYTE *)(*(_QWORD *)(v10 + 3680) + 105LL) = 0;
          goto LABEL_14;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "prepare_shutdown",
          439,
          "invalid args:core_info is NULL icp_v2_info=%pK",
          (const void *)v10);
        v18 = "cam_icp_v2_prepare_shutdown";
        v19 = "prepare shutdown failed";
        v20 = 465;
        goto LABEL_12;
      default:
        v18 = "cam_icp_v2_process_cmd";
        v19 = "invalid command type=%u";
        v20 = 1220;
        goto LABEL_12;
    }
  }
  v18 = "cam_icp_v2_process_cmd";
  v19 = "ICP device info cannot be NULL";
  v20 = 1149;
LABEL_12:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    v18,
    v20,
    v19);
LABEL_13:
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
