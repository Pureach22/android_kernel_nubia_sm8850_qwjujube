__int64 __fastcall cam_node_handle_ioctl(__int64 a1, int *a2)
{
  int *v3; // x20
  __int64 v4; // x1
  int v5; // w6
  __int64 (__fastcall *v6)(__int64, __int64 *); // x8
  __int64 v7; // x4
  __int64 v8; // x6
  __int64 v9; // x7
  int *v10; // x20
  __int64 v11; // x1
  unsigned int v12; // w0
  const char *v13; // x5
  unsigned int v14; // w20
  __int64 v15; // x4
  __int64 v16; // x1
  __int64 result; // x0
  const char *v18; // x5
  unsigned int v19; // w19
  __int64 v20; // x4
  int *v21; // x22
  __int64 v22; // x1
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x1
  __int64 v26; // x1
  int *v27; // x20
  __int64 v28; // x1
  unsigned int v29; // w0
  __int64 v30; // x1
  __int64 v31; // x1
  const char *v32; // x5
  __int64 v33; // x4
  int *v34; // x22
  __int64 v35; // x1
  __int64 v36; // x0
  int *v37; // x24
  __int64 v38; // x1
  size_t v39; // x21
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 *v42; // x1
  __int64 v43; // x2
  __int64 v44; // x0
  __int64 v45; // x20
  __int64 v46; // x22
  unsigned int v47; // w19
  int v48; // w9
  unsigned int v49; // w8
  unsigned int v50; // w10
  unsigned int v51; // w0
  const char *v52; // x5
  __int64 v53; // x4
  unsigned int v54; // w0
  __int64 v55; // x4
  unsigned int v56; // w0
  unsigned int v57; // w0
  __int64 v58; // x19
  int v59; // w8
  int *v60; // x20
  const char *v61; // x5
  __int64 v62; // x4
  __int128 v63; // [xsp+8h] [xbp-68h] BYREF
  __int64 v64; // [xsp+18h] [xbp-58h]
  __int64 v65; // [xsp+20h] [xbp-50h] BYREF
  unsigned __int64 v66; // [xsp+28h] [xbp-48h]
  __int64 v67; // [xsp+30h] [xbp-40h]
  __int64 v68; // [xsp+38h] [xbp-38h]
  __int64 v69; // [xsp+40h] [xbp-30h]
  __int64 v70; // [xsp+48h] [xbp-28h]
  __int64 v71; // [xsp+50h] [xbp-20h]
  __int64 v72; // [xsp+58h] [xbp-18h]
  __int64 v73; // [xsp+60h] [xbp-10h]
  __int64 v74; // [xsp+68h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( (debug_mdl & 2) != 0 && !debug_priority )
    {
      v60 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 2,
        4,
        "cam_node_handle_ioctl",
        877,
        "handle cmd %d",
        *a2);
      a2 = v60;
    }
    switch ( *a2 )
    {
      case 257:
      case 265:
        v3 = a2;
        v4 = *((_QWORD *)a2 + 2);
        v65 = 0;
        v66 = 0;
        if ( inline_copy_from_user_1((int)&v65, v4, 0x10u) )
          goto LABEL_48;
        v5 = *v3;
        if ( *v3 == 265 )
        {
          v6 = *(__int64 (__fastcall **)(__int64, __int64 *))(a1 + 128);
          if ( !v6 )
          {
            v7 = 95;
            v8 = a1;
            v9 = 265;
            goto LABEL_81;
          }
        }
        else
        {
          if ( v5 != 257 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              2,
              1,
              "__cam_node_handle_query_cap",
              101,
              "Invalid version number %u",
              v5);
LABEL_82:
            v19 = -22;
LABEL_83:
            v18 = "querycap is failed(rc = %d)";
            v20 = 894;
            goto LABEL_84;
          }
          v6 = *(__int64 (__fastcall **)(__int64, __int64 *))(a1 + 120);
          if ( !v6 )
          {
            v7 = 87;
            v8 = a1;
            v9 = 257;
LABEL_81:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
              3,
              2,
              1,
              "__cam_node_handle_query_cap",
              v7,
              "Node %s query cap version: %u get hw cap intf is NULL",
              v8,
              v9);
            goto LABEL_82;
          }
        }
        v40 = *(_QWORD *)(a1 + 112);
        if ( *((_DWORD *)v6 - 1) != 1863972096 )
          __break(0x8228u);
        v19 = v6(v40, &v65);
        if ( !v19 )
        {
          v41 = *((_QWORD *)v3 + 2);
          v42 = &v65;
          v43 = 16;
          goto LABEL_64;
        }
        goto LABEL_83;
      case 258:
        v27 = a2;
        v28 = *((_QWORD *)a2 + 2);
        v64 = 0;
        v63 = 0u;
        v67 = 0;
        if ( inline_copy_from_user_1((int)&v63, v28, 0x18u) )
          goto LABEL_48;
        LODWORD(v65) = 1;
        HIDWORD(v65) = v63;
        v66 = *(_QWORD *)((char *)&v63 + 4);
        LODWORD(v67) = HIDWORD(v63);
        v68 = v64;
        v29 = _cam_node_handle_acquire_dev(a1, &v65);
        if ( v29 )
        {
          v18 = "acquire device failed(rc = %d)";
          v19 = v29;
          v20 = 923;
LABEL_84:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            2,
            1,
            "cam_node_handle_ioctl",
            v20,
            v18,
            v19);
          result = v19;
        }
        else
        {
          v42 = (__int64 *)&v63;
          v41 = *((_QWORD *)v27 + 2);
          v43 = 24;
          LODWORD(v63) = HIDWORD(v65);
          *(_QWORD *)((char *)&v63 + 4) = v66;
          HIDWORD(v63) = v67;
          v64 = v68;
LABEL_64:
          if ( inline_copy_to_user_0(v41, v42, v43) )
            result = 4294967282LL;
          else
            result = 0;
        }
        break;
      case 259:
        v26 = *((_QWORD *)a2 + 2);
        v65 = 0;
        if ( inline_copy_from_user_1((int)&v65, v26, 8u) )
          goto LABEL_48;
        result = _cam_node_handle_start_dev(a1, &v65);
        if ( !(_DWORD)result )
          break;
        v18 = "start device failed(rc = %d)";
        v19 = result;
        v20 = 1074;
        goto LABEL_84;
      case 260:
        v16 = *((_QWORD *)a2 + 2);
        v65 = 0;
        if ( inline_copy_from_user_1((int)&v65, v16, 8u) )
          goto LABEL_48;
        result = _cam_node_handle_stop_dev(a1, &v65);
        if ( !(_DWORD)result )
          break;
        v18 = "stop device failed(rc = %d)";
        v19 = result;
        v20 = 1088;
        goto LABEL_84;
      case 261:
        v24 = *((_QWORD *)a2 + 2);
        v66 = 0;
        v67 = 0;
        v65 = 0;
        if ( inline_copy_from_user_1((int)&v65, v24, 0x18u) )
          goto LABEL_48;
        result = _cam_node_handle_config_dev(a1, &v65);
        if ( !(_DWORD)result )
          break;
        v18 = "config device failed(rc = %d)";
        v19 = result;
        v20 = 1102;
        goto LABEL_84;
      case 262:
        v30 = *((_QWORD *)a2 + 2);
        v65 = 0;
        if ( inline_copy_from_user_1((int)&v65, v30, 8u) )
          goto LABEL_48;
        result = _cam_node_handle_release_dev(a1, &v65);
        if ( !(_DWORD)result )
          break;
        v18 = "release device failed(rc = %d)";
        v19 = result;
        v20 = 1116;
        goto LABEL_84;
      case 264:
        v31 = *((_QWORD *)a2 + 2);
        v67 = 0;
        v68 = 0;
        v65 = 0;
        v66 = 0;
        if ( inline_copy_from_user_1((int)&v65, v31, 0x20u) )
          goto LABEL_48;
        result = _cam_node_handle_flush_dev(a1, &v65);
        if ( !(_DWORD)result )
          break;
        v18 = "flush device failed(rc = %d)";
        v19 = result;
        v20 = 1174;
        goto LABEL_84;
      case 337:
        v37 = a2;
        v38 = *((_QWORD *)a2 + 2);
        LODWORD(v65) = 0;
        if ( inline_copy_from_user_1((int)&v65, v38, 4u) )
          goto LABEL_48;
        if ( (_DWORD)v65 == 1 )
        {
          v39 = 32;
        }
        else
        {
          if ( (_DWORD)v65 != 2 )
          {
            v32 = "Unsupported api version %d";
            v33 = 1022;
            goto LABEL_41;
          }
          v39 = 120;
        }
        if ( mem_trace_en == 1 )
          v44 = cam_mem_trace_alloc(v39, 0xCC0u, 0, "cam_node_handle_ioctl", 0x403u);
        else
          v44 = _kvmalloc_node_noprof(v39, 0, 3520, 0xFFFFFFFFLL);
        v45 = v44;
        if ( v44 )
        {
          v46 = *((_QWORD *)v37 + 2);
          _check_object_size(v44, v39, 0);
          if ( inline_copy_from_user_1(v45, v46, v39) )
          {
            v47 = -14;
LABEL_104:
            v59 = (unsigned __int8)mem_trace_en;
            goto LABEL_109;
          }
          if ( (_DWORD)v65 == 2 )
          {
            v57 = _cam_node_handle_acquire_hw_v2(a1, v45);
            if ( v57 )
            {
              v47 = v57;
              v55 = 1051;
              goto LABEL_100;
            }
          }
          else if ( (_DWORD)v65 == 1 )
          {
            v54 = _cam_node_handle_acquire_hw_v1(a1, v45);
            if ( v54 )
            {
              v47 = v54;
              v55 = 1044;
LABEL_100:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                2,
                1,
                "cam_node_handle_ioctl",
                v55,
                "acquire hw failed(rc = %d)",
                v47);
              goto LABEL_104;
            }
          }
          v58 = *((_QWORD *)v37 + 2);
          _check_object_size(v45, v39, 1);
          if ( inline_copy_to_user_0(v58, v45, v39) )
            v47 = -14;
          else
            v47 = 0;
          goto LABEL_104;
        }
        v61 = "No memory for acquire HW";
        v62 = 1029;
LABEL_116:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          2,
          1,
          "cam_node_handle_ioctl",
          v62,
          v61);
        result = 4294967284LL;
        break;
      case 338:
        v34 = a2;
        v35 = *((_QWORD *)a2 + 2);
        LODWORD(v65) = 0;
        if ( inline_copy_from_user_1((int)&v65, v35, 4u) )
          goto LABEL_48;
        if ( (_DWORD)v65 != 1 )
        {
          v32 = "Unsupported api version %d";
          v33 = 1135;
          goto LABEL_41;
        }
        if ( (mem_trace_en & 1) != 0 )
          v36 = cam_mem_trace_alloc(16, 0xCC0u, 0, "cam_node_handle_ioctl", 0x474u);
        else
          v36 = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
        v45 = v36;
        if ( !v36 )
        {
          v61 = "No memory for release HW";
          v62 = 1142;
          goto LABEL_116;
        }
        if ( inline_copy_from_user_1(v36, *((_QWORD *)v34 + 2), 0x10u) )
          goto LABEL_88;
        if ( (_DWORD)v65 == 1 )
        {
          v56 = _cam_node_handle_release_hw_v1(a1, v45);
          if ( v56 )
          {
            v47 = v56;
            v52 = "release device failed(rc = %d)";
            v53 = 1157;
            goto LABEL_96;
          }
        }
        v47 = 0;
        goto LABEL_108;
      case 339:
        v10 = a2;
        v11 = *((_QWORD *)a2 + 2);
        v68 = 0;
        v69 = 0;
        v66 = 0;
        v67 = 0;
        v65 = 0;
        if ( inline_copy_from_user_1((int)&v65, v11, 0x28u) )
          goto LABEL_48;
        v12 = _cam_node_handle_dump_dev(a1, &v65);
        if ( v12 )
        {
          v13 = "Dump device %s failed(rc = %d) ";
          v14 = v12;
          v15 = 1195;
LABEL_27:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            2,
            1,
            "cam_node_handle_ioctl",
            v15,
            v13,
            a1,
            v14);
          result = v14;
        }
        else
        {
          result = inline_copy_to_user_0(*((_QWORD *)v10 + 2), &v65, 40);
          if ( result )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              2,
              1,
              "cam_node_handle_ioctl",
              1202,
              "Dump device %s copy_to_user fail",
              (const char *)a1);
LABEL_48:
            result = 4294967282LL;
          }
        }
        break;
      case 341:
        v25 = *((_QWORD *)a2 + 2);
        v72 = 0;
        v73 = 0;
        v70 = 0;
        v71 = 0;
        v68 = 0;
        v69 = 0;
        v66 = 0;
        v67 = 0;
        v65 = 0;
        if ( inline_copy_from_user_1((int)&v65, v25, 0x48u) )
          goto LABEL_48;
        result = _cam_node_handle_synx_test(a1, &v65);
        if ( !(_DWORD)result )
          break;
        v13 = "Synx test on %s failed(rc = %d)";
        v14 = result;
        v15 = 1219;
        goto LABEL_27;
      case 344:
        v21 = a2;
        v22 = *((_QWORD *)a2 + 2);
        LODWORD(v63) = 0;
        v67 = 0;
        v68 = 0;
        v65 = 0;
        v66 = 0;
        if ( inline_copy_from_user_1((int)&v63, v22, 4u) )
          goto LABEL_48;
        if ( (_DWORD)v63 != 2 )
        {
          v32 = "Unsupported api version %d";
          v33 = 955;
LABEL_41:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            2,
            1,
            "cam_node_handle_ioctl",
            v33,
            v32);
          goto LABEL_42;
        }
        if ( (mem_trace_en & 1) != 0 )
          v23 = cam_mem_trace_alloc(64, 0xCC0u, 0, "cam_node_handle_ioctl", 0x3C0u);
        else
          v23 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
        v45 = v23;
        if ( !v23 )
        {
          v61 = "No memory for acquire HW";
          v62 = 962;
          goto LABEL_116;
        }
        if ( inline_copy_from_user_1(v23, *((_QWORD *)v21 + 2), 0x40u) )
        {
LABEL_88:
          v47 = -14;
        }
        else
        {
          v48 = *(_DWORD *)(v45 + 4);
          LODWORD(v65) = *(_DWORD *)v45;
          HIDWORD(v65) = v48;
          v49 = *(_DWORD *)(v45 + 8);
          v50 = *(_DWORD *)(v45 + 12);
          LODWORD(v67) = *(_DWORD *)(v45 + 16);
          v66 = __PAIR64__(v50, v49);
          v68 = *(_QWORD *)(v45 + 24);
          v51 = _cam_node_handle_acquire_dev(a1, &v65);
          if ( v51 )
          {
            v47 = v51;
            v52 = "acquire hw failed(rc = %d)";
            v53 = 985;
LABEL_96:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              2,
              1,
              "cam_node_handle_ioctl",
              v53,
              v52,
              v47);
          }
          else
          {
            *(_QWORD *)v45 = v65;
            *(_QWORD *)(v45 + 8) = v66;
            *(_DWORD *)(v45 + 16) = v67;
            *(_QWORD *)(v45 + 24) = v68;
            if ( inline_copy_to_user_0(*((_QWORD *)v21 + 2), v45, 64) )
              v47 = -14;
            else
              v47 = 0;
          }
        }
LABEL_108:
        v59 = (unsigned __int8)mem_trace_en;
LABEL_109:
        if ( v59 == 1 )
          cam_mem_trace_free((_QWORD *)v45, 0);
        else
          kvfree(v45);
        result = v47;
        break;
      default:
        v32 = "Unknown op code %d";
        v33 = 1223;
        goto LABEL_41;
    }
  }
  else
  {
LABEL_42:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
