__int64 __fastcall cam_flash_pmic_pkt_parser(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int cpu_buf; // w0
  unsigned int v5; // w19
  __int64 v6; // x0
  __int64 v7; // x1
  unsigned int current; // w20
  unsigned int *v9; // x8
  unsigned __int64 v10; // x7
  __int64 v11; // x9
  unsigned int v12; // w10
  unsigned __int64 v13; // x6
  int v14; // w6
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x22
  unsigned int v18; // w10
  __int64 v19; // x10
  int *v20; // x23
  unsigned int v21; // w0
  __int64 v22; // x20
  __int64 v23; // x8
  unsigned int v24; // w0
  unsigned int v25; // w6
  __int64 v26; // x4
  __int64 v27; // x9
  __int64 v28; // x10
  unsigned __int64 v29; // x9
  const char *v30; // x5
  __int64 v31; // x4
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x21
  unsigned __int64 v34; // x8
  unsigned int *v35; // x21
  int v36; // w6
  unsigned int v37; // w10
  unsigned __int64 v38; // x21
  _BYTE *v39; // x20
  int v40; // w6
  const char *v41; // x5
  __int64 v42; // x4
  unsigned int *v43; // x20
  __int64 v44; // x24
  unsigned __int64 v45; // x20
  unsigned int v46; // w22
  __int64 v47; // x4
  const char *v48; // x5
  __int64 v49; // x4
  unsigned int v50; // w21
  unsigned int v51; // w0
  __int64 v52; // x8
  __int64 v53; // x4
  int v54; // w8
  _DWORD *v55; // x8
  __int64 v56; // x4
  __int64 v57; // x6
  char v58; // w9
  _DWORD *v59; // x8
  __int64 v60; // x4
  int v61; // w6
  unsigned __int64 v62; // x7
  unsigned __int64 v63; // x6
  unsigned int v64; // w8
  int v65; // w12
  __int64 v66; // x10
  __int64 v67; // x8
  __int64 (__fastcall *v68)(_QWORD); // x8
  unsigned int v69; // w0
  __int64 v70; // x8
  char v71; // w9
  _DWORD *v72; // x8
  __int64 v73; // [xsp+8h] [xbp-68h] BYREF
  __int64 v74; // [xsp+10h] [xbp-60h] BYREF
  __int64 v75; // [xsp+18h] [xbp-58h]
  __int64 v76; // [xsp+20h] [xbp-50h]
  __int64 v77; // [xsp+28h] [xbp-48h]
  __int64 v78; // [xsp+30h] [xbp-40h] BYREF
  unsigned __int64 v79; // [xsp+38h] [xbp-38h]
  __int64 v80; // [xsp+40h] [xbp-30h]
  unsigned int *v81; // [xsp+48h] [xbp-28h] BYREF
  unsigned __int64 v82; // [xsp+50h] [xbp-20h] BYREF
  __int64 v83; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v84[2]; // [xsp+60h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  v84[0] = 0;
  v81 = nullptr;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      1658,
      "fctrl/arg is NULL");
    result = 4294967274LL;
    goto LABEL_6;
  }
  if ( inline_copy_from_user_13(&v78, *(_QWORD *)(a2 + 16)) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      1671,
      "Copy cmd handle from user failed");
    result = 4294967282LL;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  cpu_buf = cam_mem_get_cpu_buf(v80, v84, &v82);
  if ( cpu_buf )
  {
    v5 = cpu_buf;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      1679,
      "Failed in getting the packet: %d",
      cpu_buf);
    result = v5;
    goto LABEL_6;
  }
  if ( v82 < 0x40 || v79 >= v82 - 64 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      1689,
      "Inval cam_packet strut size: %zu, len_of_buff: %zu",
      64);
    current = -22;
    goto LABEL_14;
  }
  v6 = cam_packet_util_copy_pkt_to_kmd(v84[0] + v79, &v81, v82 - v79);
  if ( (_DWORD)v6 )
  {
    current = v6;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      1699,
      "Copying packet to KMD failed");
LABEL_14:
    cam_mem_put_cpu_buf(v80);
    result = current;
    goto LABEL_6;
  }
  v9 = v81;
  v10 = *(unsigned int *)(a1 + 6712);
  v11 = a1;
  v12 = *v81;
  v13 = *((_QWORD *)v81 + 1);
  if ( (*v81 & 0xFFFFFF) != 0 && (_DWORD)v10 && v13 <= v10 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      2,
      "cam_flash_pmic_pkt_parser",
      1709,
      "reject request %lld, last request to flush %d",
      v13,
      v10);
    current = -22;
    goto LABEL_154;
  }
  if ( v13 > v10 )
  {
    *(_DWORD *)(a1 + 6712) = 0;
    v12 = *v9;
  }
  v14 = v12 & 0xFFFFFF;
  if ( (v12 & 0xFFFFFF) > 1 )
  {
    if ( v14 != 2 )
    {
      if ( v14 == 127 )
      {
        v22 = *((_QWORD *)v9 + 1) & 0x1FLL;
        if ( *(_DWORD *)(a1 + 6200) <= 1u )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            4096,
            2,
            "cam_flash_pmic_pkt_parser",
            2123,
            "Rxed NOP packets without linking");
          v23 = a1 + 56LL * (unsigned int)v22;
          current = -22;
          *(_BYTE *)(v23 + 3696) = 0;
          goto LABEL_154;
        }
        v28 = a1 + 56LL * (unsigned int)v22;
        *(_BYTE *)(v28 + 3696) = 0;
        *(_QWORD *)(v28 + 3704) = 0;
        *(_BYTE *)(v28 + 3726) = 127;
        if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_pmic_pkt_parser",
            2134,
            "NOP Packet is Received: req_id: %llu",
            *((_QWORD *)v9 + 1));
          v11 = a1;
        }
        goto LABEL_139;
      }
LABEL_34:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_pmic_pkt_parser",
        2139,
        "Wrong Opcode : %d",
        v14);
      current = -22;
      goto LABEL_154;
    }
    v27 = v9[6];
    *(_BYTE *)(a1 + 5488) = 1;
    v20 = (int *)((char *)v9 + v27 + 56);
    v6 = cam_mem_get_cpu_buf(*v20, &v83, &v82);
    if ( (_DWORD)v6 )
    {
      v25 = v6;
      v26 = 1969;
      goto LABEL_39;
    }
    if ( v82 < 8 || (v32 = (unsigned int)v20[1], v82 - 8 < v32) )
    {
      v30 = "Not enough buffer";
      v31 = 1976;
      goto LABEL_52;
    }
    v38 = v82 - v32;
    v39 = (_BYTE *)(v83 + v32);
    v40 = *(unsigned __int8 *)(v83 + v32 + 5);
    switch ( v40 )
    {
      case 12:
        if ( v38 <= 0x17 )
        {
          v41 = "Not enough buffer";
          v42 = 2067;
          goto LABEL_136;
        }
        if ( !v39 )
        {
          v41 = "flash_rer_info Null";
          v42 = 2074;
          goto LABEL_136;
        }
        if ( *(_DWORD *)v39 >= 3u )
        {
          v41 = "led count out of limit";
          v42 = 2080;
          goto LABEL_136;
        }
        *(_BYTE *)(a1 + 5508) = 12;
        *(_BYTE *)(a1 + 5518) = v39[4];
        v54 = *(_DWORD *)v39;
        *(_QWORD *)(a1 + 5496) = 0;
        *(_DWORD *)(a1 + 5504) = v54;
        *(_WORD *)(a1 + 5512) = *((_WORD *)v39 + 3);
        *(_WORD *)(a1 + 5514) = *((_DWORD *)v39 + 2);
        *(_WORD *)(a1 + 5516) = *((_DWORD *)v39 + 3);
        if ( *(_DWORD *)v39 )
        {
          *(_DWORD *)(a1 + 5520) = *((_DWORD *)v39 + 4);
          if ( *(_DWORD *)v39 >= 2u )
          {
            *(_DWORD *)(a1 + 5524) = *((_DWORD *)v39 + 5);
            if ( *(_DWORD *)v39 > 2u )
              goto LABEL_175;
          }
        }
        v55 = *(_DWORD **)(a1 + 6216);
        if ( *(v55 - 1) != 1413211269 )
          __break(0x8228u);
        current = ((__int64 (__fastcall *)(__int64, _QWORD))v55)(a1, 0);
        if ( !current )
          goto LABEL_138;
        v48 = "apply_setting failed: %d";
        v49 = 2104;
        break;
      case 13:
        if ( v38 <= 7 )
        {
          v41 = "Not enough buffer";
          v42 = 2051;
          goto LABEL_136;
        }
        current = cam_flash_pmic_query_current(a1, v83 + v32);
        if ( !current )
          goto LABEL_138;
        v48 = "Query current failed with rc=%d";
        v49 = 2061;
        break;
      case 14:
        if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_pmic_pkt_parser",
            1988,
            "Widget Flash Operation");
          if ( v38 <= 0x1F )
            goto LABEL_65;
        }
        else if ( v38 <= 0x1F )
        {
LABEL_65:
          v41 = "Not enough buffer";
          v42 = 1990;
LABEL_136:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_pmic_pkt_parser",
            v42,
            v41);
          goto LABEL_137;
        }
        if ( !v39 )
        {
          v41 = "flash_operation_info Null";
          v42 = 1999;
          goto LABEL_136;
        }
        v50 = *(_DWORD *)v39;
        v6 = cam_common_mem_kdup(&v73, v39, 0x20u);
        if ( (_DWORD)v6 )
        {
          current = v6;
          v47 = 2009;
          goto LABEL_134;
        }
        v70 = v73;
        if ( v50 != *(_DWORD *)v73 )
        {
          v56 = 2015;
          goto LABEL_161;
        }
        if ( v50 >= 3 )
        {
          v53 = 2023;
          goto LABEL_159;
        }
        *(_DWORD *)(a1 + 5504) = v50;
        *(_QWORD *)(a1 + 5496) = 0;
        v71 = *(_BYTE *)(v70 + 4);
        *(_BYTE *)(a1 + 5508) = 14;
        *(_BYTE *)(a1 + 5518) = v71;
        if ( *(_DWORD *)v70 )
        {
          *(_DWORD *)(a1 + 5520) = *(_DWORD *)(v70 + 8);
          if ( *(_DWORD *)v70 >= 2u )
          {
            *(_DWORD *)(a1 + 5524) = *(_DWORD *)(v70 + 12);
            if ( *(_DWORD *)v70 > 2u )
              goto LABEL_175;
          }
        }
        v72 = *(_DWORD **)(a1 + 6216);
        if ( *(v72 - 1) != 1413211269 )
          __break(0x8228u);
        current = ((__int64 (__fastcall *)(__int64, _QWORD))v72)(a1, 0);
        if ( !current )
          goto LABEL_172;
        v60 = 2044;
        goto LABEL_171;
      default:
        v41 = "Wrong cmd_type : %d";
        v42 = 2109;
        goto LABEL_136;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      v49,
      v48,
      current);
    goto LABEL_138;
  }
  if ( !v14 )
  {
    v20 = (int *)((char *)v9 + v9[6] + 56);
    v24 = cam_mem_get_cpu_buf(*v20, &v83, &v82);
    if ( v24 )
    {
      v25 = v24;
      v26 = 1726;
LABEL_39:
      current = v25;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_pmic_pkt_parser",
        v26,
        "Fail in get buffer: %d");
      goto LABEL_154;
    }
    if ( v82 < 8 || (v29 = (unsigned int)v20[1], v82 - 8 < v29) )
    {
      v30 = "Not enough buffer";
      v31 = 1732;
LABEL_52:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_pmic_pkt_parser",
        v31,
        v30);
      cam_mem_put_cpu_buf(*v20);
      current = -22;
      goto LABEL_154;
    }
    v35 = (unsigned int *)(v83 + v29);
    v36 = *(unsigned __int8 *)(v83 + v29 + 5);
    if ( v36 != 16 )
    {
      if ( v36 != 10 )
      {
        v41 = "Wrong cmd_type = %d";
        v42 = 1822;
        goto LABEL_136;
      }
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_pmic_pkt_parser",
          1744,
          "INIT_INFO CMD CALLED");
      *(_QWORD *)(a1 + 6112) = 0;
      current = 0;
      *(_BYTE *)(a1 + 6104) = 1;
      v37 = *v35;
      *(_BYTE *)(a1 + 5508) = 10;
      *(_WORD *)(a1 + 6204) = (unsigned __int8)v37;
      *(_DWORD *)(a1 + 6200) = 2;
LABEL_138:
      cam_mem_put_cpu_buf(*v20);
      v11 = a1;
      if ( current )
        goto LABEL_154;
LABEL_139:
      v64 = *v81 & 0xFFFFF;
      if ( v64 == 127 || v64 == 1 )
      {
        v76 = 0;
        v77 = 0;
        v65 = *(_DWORD *)(v11 + 6024);
        v66 = *((_QWORD *)v81 + 1);
        LODWORD(v74) = *(_DWORD *)(v11 + 6032);
        HIDWORD(v74) = v65;
        v75 = v66;
        if ( v64 == 1 )
        {
          LOBYTE(v77) = 1;
          LODWORD(v76) = 1;
        }
        v67 = *(_QWORD *)(v11 + 6096);
        if ( v67 )
        {
          v68 = *(__int64 (__fastcall **)(_QWORD))(v67 + 16);
          if ( v68 )
          {
            if ( *((_DWORD *)v68 - 1) != -1947527126 )
              __break(0x8228u);
            v69 = v68(&v74);
            if ( v69 )
            {
              current = v69;
              if ( v69 == -53 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  4096,
                  3,
                  "cam_flash_pmic_pkt_parser",
                  2175,
                  "Failed in adding request: %llu to request manager, it has been flushed",
                  *((_QWORD *)v81 + 1));
              else
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  4096,
                  1,
                  "cam_flash_pmic_pkt_parser",
                  2179,
                  "Failed in adding request: %llu to request manager",
                  *((_QWORD *)v81 + 1));
              goto LABEL_154;
            }
            current = 0;
            if ( (debug_mdl & 0x1000) == 0 || debug_priority )
              goto LABEL_154;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x1000,
              4,
              "cam_flash_pmic_pkt_parser",
              2184,
              "add req %lld to req_mgr, trigger_eof %d",
              v75,
              (unsigned __int8)v77);
          }
        }
      }
      current = 0;
LABEL_154:
      cam_common_mem_free((__int64)v81);
      goto LABEL_14;
    }
    v45 = v82 - v29;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      3,
      "cam_flash_pmic_pkt_parser",
      1759,
      "INIT_FIRE Operation for dev_hdl: 0x%x",
      *(_DWORD *)(a1 + 6024));
    if ( v45 <= 0x1F )
    {
      v41 = "Not enough buffer";
      v42 = 1762;
      goto LABEL_136;
    }
    if ( !v35 )
    {
      v41 = "flash_operation_info Null";
      v42 = 1771;
      goto LABEL_136;
    }
    v46 = *v35;
    v6 = cam_common_mem_kdup(&v73, v35, 0x20u);
    if ( (_DWORD)v6 )
    {
      current = v6;
      v47 = 1781;
LABEL_134:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_pmic_pkt_parser",
        v47,
        "Alloc and copy flash operation info failed");
      goto LABEL_138;
    }
    v52 = v73;
    if ( v46 != *(_DWORD *)v73 )
    {
      v56 = 1787;
      v57 = v46;
LABEL_162:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_pmic_pkt_parser",
        v56,
        "Count changed: userspace: %d, kernel: %d",
        v57);
      goto LABEL_163;
    }
    if ( v46 >= 3 )
    {
      v53 = 1795;
LABEL_159:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_pmic_pkt_parser",
        v53,
        "led count out of limit");
LABEL_163:
      cam_common_mem_free(v73);
      goto LABEL_137;
    }
    *(_DWORD *)(a1 + 5504) = v46;
    *(_QWORD *)(a1 + 5496) = 0;
    v58 = *(_BYTE *)(v52 + 4);
    *(_BYTE *)(a1 + 5508) = 16;
    *(_BYTE *)(a1 + 5518) = v58;
    if ( *(_DWORD *)v52 )
    {
      *(_DWORD *)(a1 + 5520) = *(_DWORD *)(v52 + 8);
      if ( *(_DWORD *)v52 > 1u )
      {
        *(_DWORD *)(a1 + 5524) = *(_DWORD *)(v52 + 12);
        if ( *(_DWORD *)v52 > 2u )
          goto LABEL_175;
      }
    }
    v59 = *(_DWORD **)(a1 + 6216);
    if ( *(v59 - 1) != 1413211269 )
      __break(0x8228u);
    current = ((__int64 (__fastcall *)(__int64, _QWORD))v59)(a1, 0);
    if ( !current )
    {
LABEL_172:
      cam_common_mem_free(v73);
      goto LABEL_138;
    }
    v60 = 1816;
LABEL_171:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      v60,
      "Apply setting failed: %d",
      current);
    goto LABEL_172;
  }
  if ( v14 != 1 )
    goto LABEL_34;
  v15 = a1 + 56 * (*((_QWORD *)v9 + 1) & 0x1FLL);
  v16 = v9[6];
  v17 = v15 + 3696;
  if ( *(_BYTE *)(v15 + 3696) == 1 )
  {
    v18 = *(_DWORD *)(v15 + 3712);
    *(_QWORD *)(v17 + 8) = 0;
    *(_BYTE *)v17 = 0;
    if ( v18 )
    {
      *(_DWORD *)(v17 + 32) = 0;
      if ( v18 != 1 )
      {
        *(_DWORD *)(v17 + 36) = 0;
        if ( v18 > 2 )
          goto LABEL_175;
      }
    }
  }
  v19 = *((_QWORD *)v9 + 1);
  v20 = (int *)((char *)v9 + v16 + 56);
  *(_BYTE *)v17 = 1;
  *(_QWORD *)(v17 + 8) = v19;
  v21 = cam_mem_get_cpu_buf(*v20, &v83, &v82);
  if ( v21 )
  {
    current = v21;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_pkt_parser",
      1851,
      "Fail in get buffer: 0x%x",
      *v20);
    goto LABEL_154;
  }
  v33 = v82;
  if ( v82 < 8 || (v34 = (unsigned int)v20[1], v82 - 8 < v34) )
  {
    v30 = "not enough buffer";
    v31 = 1858;
    goto LABEL_52;
  }
  v43 = (unsigned int *)(v83 + v34);
  if ( *(_BYTE *)(v83 + v34 + 5) != 11 )
  {
    v41 = "Wrong cmd_type = %d";
    v42 = 1953;
    goto LABEL_136;
  }
  v44 = (unsigned int)v20[1];
  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_flash_pmic_pkt_parser",
      1873,
      "CAMERA_SENSOR_FLASH_CMD_TYPE_FIRE cmd called, req:%lld",
      *((_QWORD *)v81 + 1));
  if ( *(_DWORD *)(a1 + 6200) <= 1u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      2,
      "cam_flash_pmic_pkt_parser",
      1878,
      "Rxed Flash fire ops without linking");
    *(_BYTE *)v17 = 0;
LABEL_137:
    current = -22;
    goto LABEL_138;
  }
  if ( v33 - v44 <= 0x1F )
  {
    v41 = "Not enough buffer";
    v42 = 1884;
    goto LABEL_136;
  }
  if ( !v43 )
  {
    v41 = "flash_operation_info Null";
    v42 = 1893;
    goto LABEL_136;
  }
  v50 = *v43;
  v51 = cam_common_mem_kdup(&v73, v43, 0x20u);
  if ( v51 )
  {
    current = v51;
    v47 = 1903;
    goto LABEL_134;
  }
  v6 = v73;
  if ( v50 != *(_DWORD *)v73 )
  {
    v56 = 1909;
LABEL_161:
    v57 = v50;
    goto LABEL_162;
  }
  if ( v50 >= 3 )
  {
    v53 = 1917;
    goto LABEL_159;
  }
  v61 = *(char *)(v73 + 4);
  *(_BYTE *)(v17 + 30) = *(_BYTE *)(v73 + 4);
  *(_DWORD *)(v17 + 16) = *(_DWORD *)v6;
  if ( !*(_DWORD *)v6
    || (*(_DWORD *)(v17 + 32) = *(_DWORD *)(v6 + 8), *(_DWORD *)v6 < 2u)
    || (*(_DWORD *)(v17 + 36) = *(_DWORD *)(v6 + 12), *(_DWORD *)v6 <= 2u) )
  {
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_pmic_pkt_parser",
        1932,
        "FLASH_CMD_TYPE op:%d, req:%lld",
        v61,
        *((_QWORD *)v81 + 1));
      v6 = v73;
      if ( *(_BYTE *)(v17 + 30) == 4 )
        goto LABEL_126;
    }
    else if ( (unsigned __int8)v61 == 4 )
    {
LABEL_126:
      v62 = *(_QWORD *)(v6 + 16) / 0xF4240uLL;
      *(_QWORD *)(v17 + 40) = v62;
      v63 = *(_QWORD *)(v6 + 24) / 0xF4240uLL;
      *(_QWORD *)(v17 + 48) = v63;
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_pmic_pkt_parser",
          1946,
          "PRECISE FLASH: active wait tme:%llu duration: %llu",
          v63,
          v62);
        v6 = v73;
      }
    }
    cam_common_mem_free(v6);
    current = 0;
    goto LABEL_138;
  }
LABEL_175:
  __break(0x5512u);
  return cam_flash_pmic_query_current(v6, v7);
}
