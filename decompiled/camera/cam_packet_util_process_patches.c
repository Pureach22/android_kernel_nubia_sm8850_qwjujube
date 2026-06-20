__int64 __fastcall cam_packet_util_process_patches(
        __int64 unique_tbl,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        _QWORD *a6,
        __int64 a7)
{
  _DWORD *v7; // x20
  __int64 v8; // x8
  bool v9; // zf
  char v10; // w22
  unsigned int v11; // w28
  _QWORD *v12; // x19
  unsigned int v13; // w25
  _QWORD *v14; // x24
  unsigned __int64 v15; // x23
  char v16; // w20
  int *v17; // x22
  unsigned int v18; // w27
  __int64 v19; // x1
  bool v20; // cf
  int v21; // w8
  int v22; // w8
  unsigned int v23; // w20
  unsigned __int64 v24; // x27
  unsigned __int64 v25; // x7
  int v26; // w8
  _QWORD *v27; // x9
  unsigned __int64 v28; // x10
  int v29; // w8
  unsigned __int64 v30; // x6
  int v31; // w23
  _QWORD *v32; // x28
  unsigned __int64 v33; // x20
  char v34; // w24
  int v35; // w8
  int v36; // w8
  __int64 v37; // x23
  unsigned __int64 v38; // x8
  int v39; // w8
  _QWORD *v40; // x9
  __int64 v41; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x28
  unsigned int v44; // w8
  unsigned __int64 v45; // x20
  unsigned __int64 v46; // x8
  const char *v47; // x11
  const char *v48; // x12
  const char *v49; // x10
  unsigned int v50; // w24
  unsigned int v51; // w24
  __int64 v52; // x7
  const char *v53; // x5
  __int64 v54; // x4
  __int64 i; // x20
  int v56; // w0
  char v58; // [xsp+2Ch] [xbp-74h]
  _QWORD *v59; // [xsp+30h] [xbp-70h]
  _DWORD *v60; // [xsp+38h] [xbp-68h]
  _QWORD *v61; // [xsp+40h] [xbp-60h]
  _QWORD *v62; // [xsp+48h] [xbp-58h]
  char *v65; // [xsp+60h] [xbp-40h]
  _QWORD *v68; // [xsp+70h] [xbp-30h] BYREF
  _QWORD *v69; // [xsp+78h] [xbp-28h] BYREF
  int v70; // [xsp+84h] [xbp-1Ch] BYREF
  unsigned __int64 v71; // [xsp+88h] [xbp-18h] BYREF
  _QWORD v72[2]; // [xsp+90h] [xbp-10h] BYREF

  v7 = (_DWORD *)unique_tbl;
  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a6 )
    v9 = a7 == 0;
  else
    v9 = 1;
  v10 = !v9;
  v72[1] = v8;
  v70 = 0;
  v68 = (_QWORD *)a7;
  v69 = a6;
  if ( v9 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_packet_util_process_patches",
        465,
        "Unique src/dst table is not provided by the client, src_tbl: 0x%x, dst_tbl: 0x%x",
        (_DWORD)a6,
        a7);
    unique_tbl = cam_packet_util_get_unique_tbl(&v69, (__int64 *)&v68);
    if ( (_DWORD)unique_tbl )
    {
      v11 = unique_tbl;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_process_patches",
        468,
        "Failed at allocating mem for unique buf handle table");
      goto LABEL_131;
    }
  }
  v65 = (char *)v7 + (v7[10] & 0xFFFFFFFC) + 56;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   debug_mdl & 0x20000,
                   4,
                   "cam_packet_util_process_patches",
                   478,
                   "packet = %pK patch_desc = %pK size = %lu",
                   v7,
                   v65,
                   16);
  v12 = v68;
  if ( !v7[11] )
  {
    v11 = 0;
    goto LABEL_121;
  }
  v13 = 0;
  v58 = v10;
  v59 = v69;
  v60 = v7;
  v61 = v68 + 3;
  v62 = v69 + 3;
  while ( 2 )
  {
    v14 = v62;
    v15 = 0;
    v16 = 1;
    v71 = 0;
    v72[0] = 0;
    v17 = (int *)&v65[16 * v13];
    v18 = v17[2];
    if ( (v18 & 0x8000) != 0 )
      v19 = a4;
    else
      v19 = a3;
    while ( 1 )
    {
      v21 = *((_DWORD *)v14 - 6);
      if ( v21 == v18 )
      {
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         debug_mdl & 0x20000,
                         4,
                         "cam_packet_util_get_patch_iova",
                         314,
                         "Matched entry for src_buf_hdl: 0x%x with src_hdl[%d]: 0x%x",
                         v18,
                         v15,
                         v18);
        v24 = *v14;
        v25 = *(v14 - 2);
        v70 = *((_DWORD *)v14 - 2);
        goto LABEL_50;
      }
      if ( !v21 )
        break;
      v22 = debug_mdl;
      if ( !*v14 )
        goto LABEL_38;
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        v23 = v19;
        unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       debug_mdl & 0x20000,
                       4,
                       "cam_packet_util_get_patch_iova",
                       327,
                       "Index: %d is filled with differnt src_hdl: 0x%x",
                       v15,
                       v18);
        v19 = v23;
      }
      v20 = v15++ >= 0x31;
      v14 += 4;
      v16 = !v20;
      if ( v15 == 50 )
        goto LABEL_40;
    }
    v22 = debug_mdl;
LABEL_38:
    if ( (v22 & 0x20000) != 0 && !debug_priority )
    {
      v51 = v19;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v22 & 0x20000LL,
        4,
        "cam_packet_util_get_patch_iova",
        321,
        "New src handle detected 0x%x",
        v18);
      v19 = v51;
      v26 = debug_mdl;
      if ( (debug_mdl & 0x20000) == 0 )
        goto LABEL_43;
    }
    else
    {
LABEL_40:
      v26 = debug_mdl;
      if ( (debug_mdl & 0x20000) == 0 )
        goto LABEL_43;
    }
    if ( !debug_priority )
    {
      v50 = v19;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v26 & 0x20000LL,
        4,
        "cam_packet_util_get_patch_iova",
        332,
        "src_hdl 0x%x not found in table entries",
        v18);
      v19 = v50;
    }
LABEL_43:
    unique_tbl = ((__int64 (__fastcall *)(_QWORD, __int64, unsigned __int64 *, _QWORD *, int *, __int64))cam_mem_get_io_buf)(
                   v18,
                   v19,
                   &v71,
                   v72,
                   &v70,
                   a2);
    v11 = unique_tbl;
    if ( (unique_tbl & 0x80000000) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_get_patch_iova",
        338,
        "unable to get iova for src_hdl: 0x%x",
        v18);
      goto LABEL_116;
    }
    if ( (v16 & 1) != 0 )
    {
      v27 = &v59[4 * (unsigned int)v15];
      if ( !*(_DWORD *)v27 )
      {
        v27[1] = v72[0];
        v28 = v71;
        *(_DWORD *)v27 = v18;
        v29 = v70;
        v27[3] = v28;
        *((_DWORD *)v27 + 4) = v29;
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        {
          unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         debug_mdl & 0x20000,
                         4,
                         "cam_packet_util_get_patch_iova",
                         349,
                         "Updated table index: %d with src_buf_hdl: 0x%x flags: %x",
                         v15,
                         v18,
                         v29);
          if ( v11 )
            goto LABEL_116;
LABEL_49:
          v24 = v71;
          v25 = v72[0];
LABEL_50:
          v30 = (unsigned int)v17[3];
          if ( v25 <= v30 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_packet_util_process_patches",
              496,
              "Invalid src buf patch offset: patch:src_offset: 0x%x, src_buf_size: %zu",
              v30,
              v25);
            v11 = -22;
            goto LABEL_120;
          }
          v31 = *v17;
          v32 = v61;
          v33 = 0;
          v34 = 1;
          v71 = 0;
          v72[0] = 0;
          while ( 1 )
          {
            v35 = *((_DWORD *)v32 - 6);
            if ( v35 == v31 )
            {
              if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
                unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                               3,
                               debug_mdl & 0x20000,
                               4,
                               "cam_packet_util_get_patch_kva",
                               371,
                               "Matched entry for dst_buf_hdl: 0x%x with dst_tbl[%d].handle: 0x%x",
                               v31,
                               v33,
                               v31);
              v37 = *v32;
              v38 = *(v32 - 2);
              goto LABEL_79;
            }
            if ( !v35 )
              break;
            v36 = debug_mdl;
            if ( !*v32 )
              goto LABEL_67;
            if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
              unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             debug_mdl & 0x20000,
                             4,
                             "cam_packet_util_get_patch_kva",
                             384,
                             "Index: %d is filled with differnt dst_hdl: 0x%x",
                             v33,
                             v31);
            v20 = v33++ >= 0x31;
            v32 += 4;
            v34 = !v20;
            if ( v33 == 50 )
              goto LABEL_69;
          }
          v36 = debug_mdl;
LABEL_67:
          if ( (v36 & 0x20000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              *(_QWORD *)&v36 & 0x20000LL,
              4,
              "cam_packet_util_get_patch_kva",
              377,
              "New dst handle detected 0x%x",
              v31);
            v39 = debug_mdl;
            if ( (debug_mdl & 0x20000) != 0 )
              goto LABEL_70;
          }
          else
          {
LABEL_69:
            v39 = debug_mdl;
            if ( (debug_mdl & 0x20000) != 0 )
            {
LABEL_70:
              if ( !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  *(_QWORD *)&v39 & 0x20000LL,
                  4,
                  "cam_packet_util_get_patch_kva",
                  388,
                  "dst_hdl 0x%x is not found in table entries",
                  v31);
            }
          }
          unique_tbl = cam_mem_get_cpu_buf(v31, v72, &v71);
          v11 = unique_tbl;
          if ( (unique_tbl & 0x80000000) != 0 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_packet_util_get_patch_kva",
              393,
              "unable to get kva for dst_hdl: 0x%x",
              v31);
            goto LABEL_118;
          }
          if ( (v34 & 1) == 0
            || (v40 = &v12[4 * (unsigned int)v33], *(_DWORD *)v40)
            || (v40[1] = v71, v41 = v72[0], *(_DWORD *)v40 = v31, v40[3] = v41, (debug_mdl & 0x20000) == 0)
            || debug_priority )
          {
            if ( !(_DWORD)unique_tbl )
              goto LABEL_78;
LABEL_118:
            v52 = (unsigned int)*v17;
            v53 = "get_kva failed for patch[%d], dst_buf_hdl: 0x%x: rc: %d";
            v54 = 508;
            goto LABEL_119;
          }
          unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         debug_mdl & 0x20000,
                         4,
                         "cam_packet_util_get_patch_kva",
                         404,
                         "Updated table index: %d with dst_buf_hdl: 0x%x CPU va: 0x%lx",
                         v33,
                         v31,
                         v41);
          if ( v11 )
            goto LABEL_118;
LABEL_78:
          v38 = v71;
          v37 = v72[0];
LABEL_79:
          v20 = v38 >= 8;
          v42 = v38 - 8;
          if ( !v20 || (v43 = (unsigned int)v17[1], v42 < v43) )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_packet_util_process_patches",
              516,
              "Invalid dst buf patch offset");
            v11 = -22;
            goto LABEL_120;
          }
          v44 = v17[3];
          if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          {
            unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           debug_mdl & 0x20000,
                           4,
                           "cam_packet_util_process_patches",
                           523,
                           "i = %d patch info = %x %x %x %x",
                           v13,
                           *v17,
                           v43,
                           v17[2],
                           v17[3]);
            v43 = (unsigned int)v17[1];
            v44 = v17[3];
          }
          v45 = v24 + v44;
          LODWORD(v46) = v24 + v44;
          if ( (a5 & 1) != 0 )
          {
            unique_tbl = cam_smmu_is_expanded_memory(unique_tbl);
            LODWORD(v46) = v45;
            if ( (unique_tbl & 1) != 0 )
            {
              LODWORD(v46) = v45;
              if ( (v70 & 0x840) == 0 )
              {
                if ( (_BYTE)v45 )
                  unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                 3,
                                 0x20000,
                                 1,
                                 "cam_packet_util_process_patches",
                                 537,
                                 "Buffer address 0x%lx not aligned to 256bytes",
                                 v45);
                v46 = v45 >> 8;
              }
            }
          }
          *(_DWORD *)(v37 + v43) = v46;
          if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          {
            if ( (v70 & 0x800) != 0 )
              v47 = "Y";
            else
              v47 = "N";
            if ( (v70 & 0x40) != 0 )
              v48 = "Y";
            else
              v48 = "N";
            if ( (v70 & 0x10000) != 0 )
              v49 = "Y";
            else
              v49 = "N";
            unique_tbl = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           debug_mdl & 0x20000,
                           4,
                           "cam_packet_util_process_patches",
                           550,
                           "patch is done for dst 0x%lx with base iova 0x%lx final iova 0x%lx patched value 0x%x, shared="
                           "%s, cmd=%s, HwAndCDM %s",
                           v37 + v43,
                           v24,
                           v45,
                           v46,
                           v47,
                           v48,
                           v49);
          }
          if ( ++v13 >= v60[11] )
          {
            v11 = 0;
            goto LABEL_120;
          }
          continue;
        }
      }
    }
    break;
  }
  if ( !(_DWORD)unique_tbl )
    goto LABEL_49;
LABEL_116:
  v52 = (unsigned int)v17[2];
  v53 = "get_iova failed for patch[%d], src_buf_hdl: 0x%x: rc: %d";
  v54 = 489;
LABEL_119:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_packet_util_process_patches",
    v54,
    v53,
    v13,
    v52,
    v11);
LABEL_120:
  v10 = v58;
LABEL_121:
  for ( i = 0; i != 200; i += 4 )
  {
    v56 = v12[i];
    if ( !v56 )
      break;
    cam_mem_put_cpu_buf(v56);
  }
  if ( (v10 & 1) == 0 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v69, 0);
    else
      kvfree(v69);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v12, 0);
    else
      kvfree(v12);
  }
LABEL_131:
  _ReadStatusReg(SP_EL0);
  return v11;
}
