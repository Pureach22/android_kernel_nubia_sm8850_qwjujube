__int64 __fastcall cam_ife_mgr_handle_reg_dump(__int64 a1, unsigned int *a2, int a3, int a4)
{
  __int64 v7; // x22
  __int64 v8; // x6
  __int64 v9; // x0
  char v10; // w10
  char v11; // w8
  signed int v12; // w28
  unsigned __int64 StatusReg; // x27
  int *v14; // x23
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  int cpu_buf; // w0
  const void *v22; // x6
  unsigned __int64 v23; // x8
  __int64 v24; // x8
  int v25; // w0
  const char *v26; // x5
  __int64 v27; // x2
  __int64 v28; // x4
  unsigned int v29; // w25
  unsigned __int64 v31; // [xsp+28h] [xbp-28h] BYREF
  const void *v32; // [xsp+30h] [xbp-20h] BYREF
  __int64 v33; // [xsp+38h] [xbp-18h] BYREF
  __int64 v34; // [xsp+40h] [xbp-10h]
  __int64 v35; // [xsp+48h] [xbp-8h]

  v7 = a1;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v32 = nullptr;
  v31 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           debug_mdl & 8,
           4,
           "cam_ife_mgr_handle_reg_dump",
           1078,
           "Reg dump req_type: %u ctx_idx: %u req:%llu",
           a4,
           *(_DWORD *)(a1 + 56),
           *(_QWORD *)(a1 + 9304));
  if ( (*(_BYTE *)(v7 + 9377) & 1) == 0 )
  {
    v8 = *(unsigned int *)(v7 + 56);
    v26 = "regdump can't possible as HW not initialized, ctx_idx: %u";
    v27 = 2;
    v28 = 1082;
    goto LABEL_46;
  }
  if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
  {
    v8 = *(unsigned int *)(v7 + 56);
    if ( byte_3A857B == 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_ife_mgr_handle_reg_dump",
        1089,
        "regdump enabled for presil mode, ctx_idx: %u",
        v8);
      goto LABEL_8;
    }
    v26 = "regdump disabled by default for presil mode, ctx: %u";
    v27 = 1;
    v28 = 1092;
LABEL_46:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      v27,
      "cam_ife_mgr_handle_reg_dump",
      v28,
      v26,
      v8);
LABEL_47:
    v29 = 0;
    goto LABEL_48;
  }
LABEL_8:
  if ( a2 && a3 )
  {
    if ( !*(_DWORD *)(v7 + 8848) )
    {
      if ( (unsigned int)__ratelimit(&cam_ife_mgr_handle_reg_dump__rs, "cam_ife_mgr_handle_reg_dump") )
        v9 = 3;
      else
        v9 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v9,
        8,
        2,
        "cam_ife_mgr_handle_reg_dump",
        1108,
        "Reg dump values might be from more than one request, ctx_idx: %u",
        *(_DWORD *)(v7 + 56));
    }
    if ( a4 == 13 && (byte_3A85C8 & 1) != 0 )
    {
      v10 = *(_DWORD *)(v7 + 9520) ? (*(_DWORD *)(v7 + 9524) != 0) + 1 : *(_DWORD *)(v7 + 9524) != 0;
      v11 = *(_DWORD *)(v7 + 9528) ? v10 + 1 : v10;
      if ( (*(_BYTE *)(*(_QWORD *)(v7 + 72) + 81035LL) & 1) == 0 && v11 != 1 )
      {
        LOBYTE(v33) = 1;
        HIDWORD(v33) = dword_3A85CC;
        LODWORD(v34) = dword_3A85D0;
      }
    }
    v12 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v14 = (int *)&a2[6 * v12];
      v15 = cam_packet_util_validate_cmd_desc(v14);
      if ( (_DWORD)v15 )
      {
        v29 = v15;
        goto LABEL_48;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        v15 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_handle_reg_dump",
                1134,
                "Reg dump cmd meta data: %u req_type: %u ctx_idx: %u req:%llu",
                v14[5],
                a4,
                *(_DWORD *)(v7 + 56),
                *(_QWORD *)(v7 + 9304));
      if ( v14[5] != a4 )
        goto LABEL_27;
      if ( (*(_DWORD *)(StatusReg + 16) & 0x100) != 0 )
      {
        if ( (unsigned int)v12 > 9 )
        {
          __break(0x5512u);
          return cam_ife_mgr_csid_stop_hw(v15, v16, v17, v18, v19, v20);
        }
        v24 = v7 + 9144 + 16LL * v12;
        v22 = *(const void **)v24;
        v23 = *(_QWORD *)(v24 + 8);
        v32 = v22;
        v31 = v23;
        if ( !v22 )
        {
LABEL_40:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_handle_reg_dump",
            1151,
            "Invalid cpu_addr=%pK mem_handle=%d",
            v22,
            *v14);
          if ( (*(_DWORD *)(StatusReg + 16) & 0x100) == 0 )
            cam_mem_put_cpu_buf(*v14);
          goto LABEL_42;
        }
      }
      else
      {
        cpu_buf = cam_mem_get_cpu_buf(*v14, &v32, &v31);
        if ( cpu_buf )
        {
          v29 = cpu_buf;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_handle_reg_dump",
            1145,
            "Failed in Get cpu addr, rc=%d, mem_handle =%d",
            cpu_buf,
            *v14);
          goto LABEL_48;
        }
        v22 = v32;
        v23 = v31;
        if ( !v32 )
          goto LABEL_40;
      }
      if ( !v23 )
        goto LABEL_40;
LABEL_42:
      v25 = cam_soc_util_reg_dump_to_cmd_buf(
              (const void *)v7,
              &a2[6 * v12],
              *(_QWORD *)(v7 + 9304),
              cam_ife_mgr_regspace_data_cb,
              0,
              (__int64)&v33,
              0,
              (__int64)v32,
              v31);
      if ( v25 )
      {
        v29 = v25;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_handle_reg_dump",
          1165,
          "Reg dump failed at idx: %d, rc: %d req_id: %llu meta type: %u ctx_idx: %u",
          v12,
          v25,
          *(_QWORD *)(v7 + 9304),
          a4,
          *(_DWORD *)(v7 + 56));
        if ( (*(_DWORD *)(StatusReg + 16) & 0x100) == 0 )
          cam_mem_put_cpu_buf(*v14);
        goto LABEL_48;
      }
      if ( (*(_DWORD *)(StatusReg + 16) & 0x100) == 0 )
        cam_mem_put_cpu_buf(*v14);
LABEL_27:
      if ( a3 == ++v12 )
        goto LABEL_47;
    }
  }
  v29 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_handle_reg_dump",
      1101,
      "Invalid args for reg dump req_id: [%llu] ctx idx: [%u] meta_type: [%u] num_reg_dump_buf: [%u] reg_dump_buf_desc: [%pK]",
      *(_QWORD *)(v7 + 9304),
      *(_DWORD *)(v7 + 56),
      a4,
      a3,
      a2);
    goto LABEL_47;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return v29;
}
