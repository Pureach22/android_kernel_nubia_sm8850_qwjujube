__int64 __fastcall cam_cpas_subdev_cmd(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x6
  int v4; // w0
  size_t v5; // x19
  const char *v6; // x5
  __int64 v7; // x4
  __int64 v8; // x0
  _QWORD *v9; // x21
  __int64 v10; // x22
  __int64 v11; // x1
  int v12; // w0
  int v13; // w0
  const char *v14; // x3
  const char *v15; // x5
  __int64 v16; // x4
  __int64 v17; // x1
  int v18; // w6
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x12
  __int64 v22; // x11
  _DWORD *v23; // x8
  __int64 v24; // x10
  __int64 v25; // x0
  __int64 v26; // x0
  int v27; // w19
  __int64 v28; // x10
  __int64 v29; // x11
  _DWORD *v30; // x22
  __int64 v31; // x11
  __int64 v32; // x10
  __int64 v33; // x12
  __int64 v34; // x11
  __int64 v35; // x23
  __int64 v36; // x0
  __int64 v37; // x6
  int v38; // w0
  __int64 v40; // x20
  int v41; // w21
  __int64 v42; // x8
  __int64 v43; // x20
  __int64 v44; // x19
  int v45; // w0
  const char *v46; // x5
  __int64 v47; // x4
  int v48; // w0
  const char *v49; // x5
  __int64 v50; // x4
  unsigned int client_env_object; // w0
  __int64 v52; // x6
  const char *v53; // x5
  __int64 v54; // x1
  __int64 v55; // x4
  __int64 v56; // x0
  __int64 (__fastcall *v57)(__int64, _QWORD, _QWORD *, __int64); // x8
  unsigned int v58; // w0
  __int64 v59; // x6
  const char *v60; // x5
  __int64 v61; // x1
  __int64 v62; // x4
  __int64 v63; // x21
  _DWORD *v64; // x22
  __int64 v65; // x0
  int v66; // w0
  bool v67; // zf
  const char *v68; // x10
  const char *v69; // x9
  unsigned int v70; // w0
  __int64 v71; // x0
  void (__fastcall *v72)(__int64, __int64, _QWORD, _QWORD); // x8
  __int64 v73; // x0
  __int64 (__fastcall *v74)(__int64, __int64, _QWORD, _QWORD); // x8
  unsigned int v75; // w0
  int v76; // w0
  __int64 v77; // [xsp+20h] [xbp-270h] BYREF
  int v78[3]; // [xsp+28h] [xbp-268h]
  int v79; // [xsp+34h] [xbp-25Ch] BYREF
  _DWORD *v80; // [xsp+38h] [xbp-258h] BYREF
  __int64 v81; // [xsp+40h] [xbp-250h] BYREF
  __int64 (__fastcall *v82)(__int64, _QWORD, _QWORD *, __int64); // [xsp+48h] [xbp-248h] BYREF
  __int64 v83; // [xsp+50h] [xbp-240h]
  int v84; // [xsp+5Ch] [xbp-234h] BYREF
  _QWORD s[70]; // [xsp+60h] [xbp-230h] BYREF

  s[69] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v80 = nullptr;
  v79 = 0;
  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_subdev_cmd",
      1744,
      "Invalid input cmd");
LABEL_49:
    LODWORD(v5) = -22;
    goto LABEL_61;
  }
  v2 = *a2;
  if ( (int)v2 > 339 )
  {
    if ( (_DWORD)v2 == 340 )
    {
      memset(s, 0, 0x228u);
      v13 = inline_copy_from_user_3((int)s, *((_QWORD *)a2 + 2), 0x228u);
      if ( v13 )
      {
        LODWORD(v5) = v13;
        v6 = "Failed in copy from user, rc=%d";
        v7 = 1809;
        goto LABEL_59;
      }
      LODWORD(v5) = cam_cpas_get_hw_info(
                      (_DWORD *)s + 1,
                      (_QWORD *)((char *)&s[1] + 4),
                      (_QWORD *)((char *)&s[3] + 4),
                      &v80,
                      &v79,
                      (char *)&s[5] + 4,
                      &s[38]);
      if ( !(_DWORD)v5 )
      {
        v26 = *((_QWORD *)a2 + 2);
        LODWORD(s[1]) = *v80;
        LODWORD(v5) = inline_copy_to_user_2(v26, s, 552);
        if ( (_DWORD)v5 )
        {
          v6 = "Failed in copy to user, rc=%d";
          v7 = 1825;
          goto LABEL_59;
        }
      }
      goto LABEL_61;
    }
    if ( (_DWORD)v2 != 342 )
    {
      if ( (_DWORD)v2 != 343 )
      {
LABEL_23:
        v14 = "cam_cpas_subdev_cmd";
        v15 = "Unknown op code %d for CPAS";
        v16 = 1883;
LABEL_48:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          4,
          1,
          v14,
          v16,
          v15,
          v2);
        goto LABEL_49;
      }
      v8 = a2[1];
      if ( !(_DWORD)v8 )
      {
        v14 = "cam_cpas_subdev_cmd";
        v15 = "Invalid cmd size from user, size=%d";
        v16 = 1846;
        v2 = 0;
        goto LABEL_48;
      }
      if ( mem_trace_en == 1 )
      {
        v9 = (_QWORD *)cam_mem_trace_alloc(v8, 0xCC0u, 0, "cam_cpas_subdev_cmd", 0x73Bu);
        if ( v9 )
          goto LABEL_15;
      }
      else
      {
        v9 = (_QWORD *)_kvmalloc_node_noprof(a2[1], 0, 3520, 0xFFFFFFFFLL);
        if ( v9 )
        {
LABEL_15:
          v5 = a2[1];
          if ( (v5 & 0x80000000) != 0 )
          {
            __break(0x800u);
            goto LABEL_17;
          }
          v10 = *((_QWORD *)a2 + 2);
          _check_object_size(v9, a2[1], 0);
          LODWORD(v5) = inline_copy_from_user_3((int)v9, v10, v5);
          if ( (_DWORD)v5 )
          {
LABEL_17:
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v9, 0);
            else
              kvfree(v9);
            v6 = "Failed in copy from user, rc=%d";
            v7 = 1859;
            goto LABEL_59;
          }
          v38 = cam_packet_util_process_generic_blob(a2[1], v9, cam_cpas_handle_generic_query_blob, 0);
          if ( v38 )
          {
            LODWORD(v5) = v38;
            goto LABEL_66;
          }
          v5 = a2[1];
          if ( (v5 & 0x80000000) != 0 )
          {
            __break(0x800u);
          }
          else
          {
            v40 = *((_QWORD *)a2 + 2);
            _check_object_size(v9, v5, 1);
            LODWORD(v5) = inline_copy_to_user_2(v40, v9, v5);
            if ( !(_DWORD)v5 )
              goto LABEL_66;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_subdev_cmd",
            1872,
            "Failed in copy to user, rc=%d",
            v5);
LABEL_66:
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v9, 0);
          else
            kvfree(v9);
          goto LABEL_61;
        }
      }
      v6 = "memory allocation is failed rc = %d";
      v7 = 1876;
      v37 = 4294967284LL;
      LODWORD(v5) = -12;
LABEL_60:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_subdev_cmd",
        v7,
        v6,
        v37);
      goto LABEL_61;
    }
    v17 = *((_QWORD *)a2 + 2);
    v77 = 0;
    *(_QWORD *)v78 = 0;
    LODWORD(v5) = inline_copy_from_user_3((int)&v77, v17, 0x10u);
    if ( (_DWORD)v5 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_subdev_cmd",
        1836,
        "Failed in copy from user, rc=%d",
        v5);
      goto LABEL_61;
    }
    v2 = (unsigned int)v77;
    if ( (_DWORD)v77 )
    {
      v14 = "cam_cpas_handle_custom_config_cmd";
      v15 = "Invalid custom command %d for CPAS";
      v16 = 1453;
      goto LABEL_48;
    }
    v81 = 0;
    if ( HIDWORD(v77) < 8 )
      goto LABEL_49;
    v2 = inline_copy_from_user_3((int)&v81, v78[0], 8u);
    if ( (_DWORD)v2 )
    {
      v14 = "cam_cpas_handle_custom_config_cmd";
      v15 = "Failed in copy from user, rc=%d";
      v16 = 1443;
      goto LABEL_48;
    }
    v41 = v81;
    v82 = nullptr;
    v83 = 0;
    if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_handle_fd_port_config",
        1319,
        "cpas intf not initialized");
      goto LABEL_49;
    }
    v42 = *(_QWORD *)(g_cpas_intf + 480);
    v43 = *(_QWORD *)(v42 + 112);
    if ( !v43 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_handle_fd_port_config",
        1334,
        "cpas_hw handle not initialized");
      goto LABEL_49;
    }
    v44 = *(_QWORD *)(v43 + 3680);
    mutex_lock(*(_QWORD *)(v42 + 112));
    if ( *(_DWORD *)(v44 + 2792) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_handle_fd_port_config",
        1329,
        "FD port config can not be updated during the session");
      mutex_unlock(v43);
      goto LABEL_49;
    }
    v45 = cam_cpas_util_vote_default_ahb_axi(v43, 1);
    if ( v45 )
    {
      LODWORD(v5) = v45;
      v46 = "failed to vote for the default ahb/axi clock, rc=%d";
      v47 = 1342;
LABEL_78:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_handle_fd_port_config",
        v47,
        v46,
        (unsigned int)v5);
LABEL_117:
      mutex_unlock(v43);
      goto LABEL_61;
    }
    v48 = cam_cpas_soc_enable_resources(v43 + 96);
    if ( v48 )
    {
      LODWORD(v5) = v48;
      v49 = "failed in soc_enable_resources, rc=%d";
      v50 = 1349;
LABEL_81:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_handle_fd_port_config",
        v50,
        v49,
        (unsigned int)v5);
LABEL_116:
      cam_cpas_util_vote_default_ahb_axi(v43, 0);
      goto LABEL_117;
    }
    client_env_object = get_client_env_object(&v82);
    if ( client_env_object )
    {
      v52 = client_env_object;
      v53 = "Failed getting mink env object, rc: %d";
      v54 = 4;
      v55 = 1355;
LABEL_84:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v54,
        1,
        "cam_cpas_handle_fd_port_config",
        v55,
        v53,
        v52);
      LODWORD(v5) = -22;
LABEL_115:
      cam_cpas_soc_disable_resources(v43 + 96, 1u, 1u);
      goto LABEL_116;
    }
    v84 = 283;
    v57 = v82;
    v56 = v83;
    s[2] = 0;
    s[3] = 0;
    s[0] = &v84;
    s[1] = 4;
    if ( *((_DWORD *)v82 - 1) != 816020464 )
      __break(0x8228u);
    v58 = v57(v56, 0, s, 4097);
    if ( v58 )
    {
      v59 = v58;
      v60 = "Failed getting mink sc_object, rc: %d";
      v61 = 4;
      v62 = 1362;
    }
    else
    {
      v84 = v41;
      v64 = (_DWORD *)s[2];
      v63 = s[3];
      s[0] = &v84;
      s[1] = 4;
      v65 = s[3];
      if ( *(_DWORD *)(s[2] - 4LL) != 816020464 )
        __break(0x8236u);
      v66 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v64)(v65, 3, s, 1);
      if ( v66 )
      {
        if ( v66 == 10 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_handle_fd_port_config",
            1370,
            "Dynamic FD port config not allowed",
            10);
          LODWORD(v5) = -1;
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_handle_fd_port_config",
            1373,
            "Mink secure call failed, rc: %d",
            v66);
          LODWORD(v5) = -22;
        }
        if ( *(v64 - 1) != 816020464 )
          __break(0x8236u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v64)(v63, 0xFFFF, 0, 0);
        goto LABEL_112;
      }
      if ( *(v64 - 1) != 816020464 )
        __break(0x8236u);
      v70 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v64)(v63, 0xFFFF, 0, 0);
      if ( !v70 )
      {
        v74 = (__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v82;
        v73 = v83;
        if ( *((_DWORD *)v82 - 1) != 816020464 )
          __break(0x8228u);
        v75 = v74(v73, 0xFFFF, 0, 0);
        if ( !v75 )
        {
          v76 = cam_cpas_soc_disable_resources(v43 + 96, 1u, 1u);
          if ( !v76 )
          {
            LODWORD(v5) = cam_cpas_util_vote_default_ahb_axi(v43, 0);
            if ( !(_DWORD)v5 )
              goto LABEL_117;
            v46 = "failed remove the vote on ahb/axi clock, rc=%d";
            v47 = 1402;
            goto LABEL_78;
          }
          LODWORD(v5) = v76;
          v49 = "failed in soc_disable_resources, rc=%d";
          v50 = 1395;
          goto LABEL_81;
        }
        v52 = v75;
        v53 = "Failed releasing mink env object, rc: %d";
        v54 = 0x8000;
        v55 = 1388;
        goto LABEL_84;
      }
      v59 = v70;
      v60 = "Failed releasing secure camera object, rc: %d";
      v61 = 0x8000;
      v62 = 1381;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v61,
      1,
      "cam_cpas_handle_fd_port_config",
      v62,
      v60,
      v59);
    LODWORD(v5) = -22;
LABEL_112:
    v72 = (void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v82;
    v71 = v83;
    if ( *((_DWORD *)v82 - 1) != 816020464 )
      __break(0x8228u);
    v72(v71, 0xFFFF, 0, 0);
    goto LABEL_115;
  }
  if ( (_DWORD)v2 != 257 )
  {
    if ( (_DWORD)v2 == 263 )
    {
      LODWORD(v5) = 0;
      goto LABEL_61;
    }
    if ( (_DWORD)v2 == 265 )
    {
      memset(s, 0, 0x12Cu);
      v4 = inline_copy_from_user_3((int)s, *((_QWORD *)a2 + 2), 0x12Cu);
      if ( v4 )
      {
        LODWORD(v5) = v4;
        v6 = "Failed in copy from user, rc=%d";
        v7 = 1782;
LABEL_59:
        v37 = (unsigned int)v5;
        goto LABEL_60;
      }
      if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
      {
        if ( s != (_QWORD *)-24LL )
        {
          v27 = *(_DWORD *)(g_cpas_intf + 488);
          v29 = *(_QWORD *)(g_cpas_intf + 492);
          v28 = *(_QWORD *)(g_cpas_intf + 500);
          v30 = (_DWORD *)(g_cpas_intf + 524);
          LODWORD(s[0]) = v27;
          s[1] = v29;
          s[2] = v28;
          v31 = *(_QWORD *)(g_cpas_intf + 480);
          v32 = *(_QWORD *)(g_cpas_intf + 508);
          v33 = *(_QWORD *)(g_cpas_intf + 516);
          v80 = (_DWORD *)(g_cpas_intf + 524);
          v34 = *(_QWORD *)(v31 + 112);
          s[3] = v32;
          s[4] = v33;
          v35 = *(_QWORD *)(v34 + 3392);
          v79 = *(_DWORD *)(g_cpas_intf + 532);
          memcpy(&s[5], (const void *)(g_cpas_intf + 536), 0x104u);
          if ( (debug_mdl & 4) != 0 && !debug_priority )
          {
            v69 = "Y";
            if ( !*(_BYTE *)(v35 + 1644) )
              v69 = "N";
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 4,
              4,
              "cam_cpas_get_hw_info",
              514,
              "Family %d, version %d.%d cam_caps %d, domain_id: %s",
              v27,
              LODWORD(s[1]),
              HIDWORD(s[1]),
              (_DWORD)v30,
              v69);
            v30 = v80;
          }
          v36 = *((_QWORD *)a2 + 2);
          HIDWORD(s[0]) = *v30;
          LODWORD(v5) = inline_copy_to_user_2(v36, s, 300);
          if ( (_DWORD)v5 )
          {
            v6 = "Failed in copy to user, rc=%d";
            v7 = 1798;
            goto LABEL_59;
          }
          goto LABEL_61;
        }
        goto LABEL_62;
      }
LABEL_44:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_get_hw_info",
        469,
        "cpas intf not initialized");
      LODWORD(v5) = -19;
      goto LABEL_61;
    }
    goto LABEL_23;
  }
  v11 = *((_QWORD *)a2 + 2);
  memset(s, 0, 40);
  v12 = inline_copy_from_user_3((int)s, v11, 0x28u);
  if ( v12 )
  {
    LODWORD(v5) = v12;
    v6 = "Failed in copy from user, rc=%d";
    v7 = 1756;
    goto LABEL_59;
  }
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
    goto LABEL_44;
  if ( s == (_QWORD *)-24LL )
  {
LABEL_62:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_hw_info",
      475,
      "invalid input %pK %pK %pK %pK %pK",
      s,
      &s[1],
      nullptr,
      &v80,
      &v79);
    goto LABEL_49;
  }
  v18 = *(_DWORD *)(g_cpas_intf + 488);
  v20 = *(_QWORD *)(g_cpas_intf + 492);
  v19 = *(_QWORD *)(g_cpas_intf + 500);
  LODWORD(s[0]) = v18;
  s[1] = v20;
  s[2] = v19;
  v21 = *(_QWORD *)(g_cpas_intf + 516);
  v22 = *(_QWORD *)(g_cpas_intf + 480);
  s[3] = *(_QWORD *)(g_cpas_intf + 508);
  s[4] = v21;
  v23 = (_DWORD *)(g_cpas_intf + 524);
  LODWORD(v21) = *(_DWORD *)(g_cpas_intf + 532);
  v24 = *(_QWORD *)(*(_QWORD *)(v22 + 112) + 3392LL);
  v80 = (_DWORD *)(g_cpas_intf + 524);
  v79 = v21;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    v67 = *(_BYTE *)(v24 + 1644) == 0;
    v68 = "Y";
    if ( v67 )
      v68 = "N";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_get_hw_info",
      514,
      "Family %d, version %d.%d cam_caps %d, domain_id: %s",
      v18,
      LODWORD(s[1]),
      HIDWORD(s[1]),
      (_DWORD)v23,
      v68);
    v23 = v80;
  }
  v25 = *((_QWORD *)a2 + 2);
  HIDWORD(s[0]) = *v23;
  LODWORD(v5) = inline_copy_to_user_2(v25, s, 40);
  if ( (_DWORD)v5 )
  {
    v6 = "Failed in copy to user, rc=%d";
    v7 = 1771;
    goto LABEL_59;
  }
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
