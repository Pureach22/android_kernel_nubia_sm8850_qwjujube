__int64 __fastcall cam_tpg_cmd_buf_parse(__int64 a1, unsigned __int8 *a2)
{
  __int64 request; // x0
  _QWORD *v5; // x20
  unsigned int cpu_buf; // w21
  int v7; // w25
  int v8; // w8
  int *v9; // x28
  int v10; // w0
  unsigned __int64 v11; // x9
  size_t v12; // x7
  size_t v13; // x6
  __int64 v14; // x0
  unsigned __int64 v15; // x24
  __int64 v16; // x0
  __int64 v17; // x27
  int v18; // w8
  int v19; // w8
  int v20; // w7
  __int64 v21; // x8
  int v22; // w6
  __int64 v23; // x9
  __int64 v24; // x11
  __int64 v25; // x10
  __int64 v26; // x9
  __int64 v27; // x10
  __int64 v28; // x11
  __int64 v29; // x8
  int v30; // w8
  __int64 v31; // x1
  __int64 v32; // x4
  const char *v33; // x5
  const char *v34; // x5
  __int64 v35; // x4
  size_t v37; // [xsp+0h] [xbp-40h]
  size_t v38; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v39[2]; // [xsp+30h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    cpu_buf = -22;
    goto LABEL_85;
  }
  request = tpg_hw_create_request(a1 + 4568, *((_QWORD *)a2 + 1));
  if ( !request )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_cmd_buf_parse",
      622,
      "TPG[%d] Unable to create hw request ",
      *(_DWORD *)(a1 + 564));
    cpu_buf = -22;
    goto LABEL_85;
  }
  v5 = (_QWORD *)request;
  cpu_buf = tpg_hw_request_set_opcode(request, *a2);
  if ( (cpu_buf & 0x80000000) != 0 )
    goto LABEL_70;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_cmd_buf_parse",
      631,
      "Queue TPG requests for request id %lld",
      *v5);
    if ( *((_DWORD *)a2 + 7) )
      goto LABEL_7;
LABEL_84:
    tpg_hw_add_request(a1 + 4568, v5);
    goto LABEL_85;
  }
  if ( !*((_DWORD *)a2 + 7) )
    goto LABEL_84;
LABEL_7:
  v7 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v8 = *((_DWORD *)a2 + 6);
    v38 = 0;
    v9 = (int *)&a2[24 * v7 + 56 + (v8 & 0xFFFFFFFC)];
    if ( !v9 )
    {
      cpu_buf = -22;
      goto LABEL_70;
    }
    v10 = *v9;
    v39[0] = 0;
    cpu_buf = cam_mem_get_cpu_buf(v10, v39, &v38);
    if ( (cpu_buf & 0x80000000) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_validate_cmd_descriptor",
        445,
        "Failed to get cmd buf Mem address : %d",
        cpu_buf);
      goto LABEL_70;
    }
    v11 = (unsigned int)v9[1];
    v12 = v38 - v11;
    if ( v38 <= v11 )
    {
      v34 = "Buffer Offset: %d past length of buffer %zu";
      v35 = 452;
      v13 = (unsigned int)v11;
      v12 = v38;
      goto LABEL_67;
    }
    v13 = (unsigned int)v9[2];
    if ( v12 < v13 || v9[3] > (unsigned int)v13 )
    {
      v34 = "Got Invalid command descriptorcmd desc size: %zu remain len: %zu cmd desc length: %zu";
      v35 = 464;
      LODWORD(v37) = v9[3];
      goto LABEL_67;
    }
    if ( v12 <= 0xF )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_validate_cmd_descriptor",
        473,
        "Got invalid cmd descriptor buffer sizeremain len: %zu TPG command header size: %zu",
        v38 - v11,
        0x10u);
      goto LABEL_68;
    }
    v14 = v39[0] + ((unsigned int)v11 & 0xFFFFFFFC);
    v15 = *(_QWORD *)(v14 + 4);
    if ( (v15 & 0x8000000000000000LL) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_validate_cmd_descriptor",
        490,
        "Got invalid cmd header sizecmd header size: %zu,cmd desc offset: %d",
        v15,
        v11);
      goto LABEL_68;
    }
    if ( v15 + v11 > v38 )
    {
      v34 = "Cmd header offset mismatchcmd desc offset: %d cmd header size: %zu len of buff: %zu";
      v35 = 500;
      v13 = (unsigned int)v11;
      v12 = *(_QWORD *)(v14 + 4);
      v37 = v38;
LABEL_67:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, size_t, size_t, size_t))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_validate_cmd_descriptor",
        v35,
        v34,
        v13,
        v12,
        v37);
LABEL_68:
      cpu_buf = -22;
      goto LABEL_69;
    }
    v16 = kmemdup_noprof(v14, *(_QWORD *)(v14 + 4), 3264);
    v17 = v16;
    if ( !v16 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_validate_cmd_descriptor",
        507,
        "Local cmd_header mem allocation failed");
      cpu_buf = -12;
LABEL_69:
      cam_mem_put_cpu_buf(*v9);
      goto LABEL_70;
    }
    if ( v15 < 0xC )
      goto LABEL_86;
    v18 = *(_DWORD *)v16;
    *(_QWORD *)(v16 + 4) = v15;
    if ( v18 <= 2 )
      break;
    if ( v18 == 3 )
    {
      if ( v15 != 54 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "cam_tpg_validate_cmd_descriptor",
          557,
          "Got invalid illumination config command");
        goto LABEL_68;
      }
      cam_mem_put_cpu_buf(*v9);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_cmd_buf_parse",
        683,
        "TPG[%d] ILLUMINATION CONFIG not supported now ",
        *(_DWORD *)(a1 + 564));
    }
    else
    {
      if ( v18 != 4 )
      {
LABEL_73:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "cam_tpg_validate_cmd_descriptor",
          595,
          "invalid config command");
        goto LABEL_68;
      }
      if ( v15 != 48 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "cam_tpg_validate_cmd_descriptor",
          570,
          "Got invalid settings config command recv: %d exp: %d",
          v15,
          48);
        goto LABEL_68;
      }
      v20 = *(_DWORD *)(v16 + 16);
      v21 = *(unsigned int *)(v16 + 20);
      v22 = v9[1];
      if ( v38 - 32 * v21 < (unsigned int)(v20 + v22) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "cam_tpg_validate_cmd_descriptor",
          583,
          "Got invalid setting config, cmd offset: %u, setting array offset: %u, num reg settings: %u, size of reg settin"
          "g: %zu, len of buf: %zu",
          v22,
          v20,
          v21,
          0x20u,
          v38);
        goto LABEL_68;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x200000000LL,
        3,
        "cam_tpg_validate_cmd_descriptor",
        588,
        "Got settings config command");
      cam_mem_put_cpu_buf(*v9);
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "cam_tpg_cmd_buf_parse",
          676,
          "TPG[%d] Got TPG Settings Config",
          *(_DWORD *)(a1 + 564));
      cpu_buf = tpg_hw_copy_settings_config(a1 + 4568, v17);
    }
LABEL_54:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v17, 0);
    else
      kvfree(v17);
    if ( (unsigned int)++v7 >= *((_DWORD *)a2 + 7) )
      goto LABEL_84;
  }
  if ( v18 == 1 )
  {
    if ( v15 != 70 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_validate_cmd_descriptor",
        518,
        "Got invalid global config command recv: %d exp: %d",
        v15,
        70);
      goto LABEL_68;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "cam_tpg_validate_cmd_descriptor",
      522,
      "Got global config cmd");
    cam_mem_put_cpu_buf(*v9);
    v24 = *(_QWORD *)(v17 + 48);
    v23 = *(_QWORD *)(v17 + 56);
    v25 = *(_QWORD *)(v17 + 40);
    *(_QWORD *)((char *)v5 + 74) = *(_QWORD *)(v17 + 62);
    *(_QWORD *)((char *)v5 + 68) = v23;
    *(_QWORD *)((char *)v5 + 60) = v24;
    *(_QWORD *)((char *)v5 + 52) = v25;
    *(_QWORD *)((char *)v5 + 12) = *(_QWORD *)v17;
    v26 = *(_QWORD *)(v17 + 24);
    v27 = *(_QWORD *)(v17 + 8);
    v28 = *(_QWORD *)(v17 + 16);
    *(_QWORD *)((char *)v5 + 44) = *(_QWORD *)(v17 + 32);
    v29 = *(_QWORD *)((char *)v5 + 58);
    *(_QWORD *)((char *)v5 + 36) = v26;
    *(_QWORD *)((char *)v5 + 28) = v28;
    *(_QWORD *)((char *)v5 + 20) = v27;
    *(_QWORD *)(a1 + 4592) = v29;
    goto LABEL_54;
  }
  if ( v18 != 2 )
    goto LABEL_73;
  if ( (v15 & 0x7FFFFFFFFFFFFFFCLL) == 0xC )
LABEL_86:
    __break(1u);
  v19 = *(_DWORD *)(v16 + 12);
  if ( v15 != 1160 && v19 == 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_validate_cmd_descriptor",
      531,
      "Got invalid stream config command recv: %d exp: %d",
      v15,
      1160);
    goto LABEL_68;
  }
  if ( v19 == 1 )
  {
    if ( v15 == 93 )
      goto LABEL_45;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_validate_cmd_descriptor",
      547,
      "Got invalid stream config cmd recv: %d exp: %d",
      v15,
      93);
    goto LABEL_68;
  }
  if ( v19 == 2 && v15 != 105 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_validate_cmd_descriptor",
      539,
      "Got invalid stream config cmd recv: %d exp: %d",
      v15,
      105);
    goto LABEL_68;
  }
LABEL_45:
  cam_mem_put_cpu_buf(*v9);
  if ( (v15 & 0x7FFFFFFFFFFFFFFCLL) == 0xC )
    goto LABEL_86;
  v30 = *(_DWORD *)(v17 + 12);
  if ( (unsigned int)(v30 - 1) < 2 )
  {
    cpu_buf = tpg_hw_add_stream(a1 + 4568, v5, v17);
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    {
      v31 = debug_mdl & 0x200000000LL;
      v32 = 668;
      v33 = "Stream config";
      goto LABEL_57;
    }
LABEL_53:
    if ( (cpu_buf & 0x80000000) != 0 )
      goto LABEL_79;
    goto LABEL_54;
  }
  if ( v30 != 3 )
    goto LABEL_54;
  cpu_buf = tpg_hw_add_stream_v3(a1 + 4568, v5, v17);
  if ( (debug_mdl & 0x200000000LL) == 0 || debug_priority )
    goto LABEL_53;
  v31 = debug_mdl & 0x200000000LL;
  v32 = 662;
  v33 = "Stream config v3";
LABEL_57:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    v31,
    4,
    "cam_tpg_cmd_buf_parse",
    v32,
    v33);
  if ( (cpu_buf & 0x80000000) == 0 )
    goto LABEL_54;
LABEL_79:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v17, 0);
  else
    kvfree(v17);
LABEL_70:
  tpg_hw_free_request(a1 + 4568, v5);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
LABEL_85:
  _ReadStatusReg(SP_EL0);
  return cpu_buf;
}
