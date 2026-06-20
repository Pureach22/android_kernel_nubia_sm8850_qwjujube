__int64 __fastcall cam_common_evt_inject_set(const char *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  size_t v4; // x0
  unsigned __int64 v5; // x2
  const char *v6; // x1
  unsigned int v7; // w20
  unsigned int v8; // w0
  const char *v9; // x5
  __int64 v10; // x4
  unsigned int v11; // w0
  unsigned int v12; // w0
  const char *v13; // x5
  __int64 v14; // x4
  unsigned __int64 v15; // x6
  __int64 (__fastcall *v16)(_QWORD); // x8
  int v17; // w6
  unsigned __int64 StatusReg; // x22
  __int64 v19; // x23
  char *stringp; // [xsp+8h] [xbp-D8h] BYREF
  _QWORD v22[26]; // [xsp+10h] [xbp-D0h] BYREF

  v22[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  stringp = nullptr;
  memset(v22, 0, 200);
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(56, 0xCC0u, 0, "cam_common_evt_inject_set", 0x2A2u);
  else
    v2 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
  v3 = v2;
  if ( !v2 )
  {
LABEL_45:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_evt_inject_set",
      676,
      "no free memory");
    v7 = -12;
    goto LABEL_46;
  }
  while ( 1 )
  {
    v4 = strnlen(a1, 0xC8u);
    if ( v4 == -1 )
    {
      _fortify_panic(2, -1, 0);
LABEL_43:
      _fortify_panic(7, 200, v5);
      goto LABEL_44;
    }
    if ( v4 == 200 )
      v5 = 200;
    else
      v5 = v4 + 1;
    if ( v5 >= 0xC9 )
      goto LABEL_43;
    v6 = a1;
    a1 = (const char *)v22;
    if ( (unsigned int)sized_strscpy(v22, v6) == -7 )
    {
      v7 = -7;
      goto LABEL_15;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      3,
      "cam_common_evt_inject_set",
      684,
      "parsing input param for cam event injection: %s",
      (const char *)v22);
    stringp = (char *)v22;
    v8 = cam_common_evt_inject_generic_command_parser(v3, &stringp);
    if ( v8 )
    {
      v7 = v8;
      v9 = "Fail to parse common params %d";
      v10 = 692;
      goto LABEL_14;
    }
    if ( *(_BYTE *)(v3 + 16) )
    {
      if ( *(_BYTE *)(v3 + 16) != 1 )
      {
        v13 = "Invalid Injection id: %u";
        v14 = 729;
        goto LABEL_25;
      }
      v11 = cam_common_evt_inject_generic_command_parser(v3, &stringp);
      if ( v11 )
      {
        v7 = v11;
        v9 = "Fail to parse event notify type param %d";
        v10 = 701;
LABEL_14:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_common_evt_inject_set",
          v10,
          v9,
          v7);
LABEL_15:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v3, 0);
        else
          kvfree(v3);
        goto LABEL_46;
      }
      v17 = *(_DWORD *)(v3 + 32);
      if ( v17 != 1 && v17 != 6 && v17 != 4 )
      {
        v13 = "Invalid event notification type: %u";
        v14 = 720;
        goto LABEL_25;
      }
    }
    v12 = cam_common_evt_inject_generic_command_parser(v3, &stringp);
    if ( v12 )
    {
      v7 = v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_common_evt_inject_set",
        739,
        "Command Parsed failed with Inject id: %u rc: %d",
        *(unsigned __int8 *)(v3 + 16),
        v12);
      goto LABEL_15;
    }
    v15 = *(unsigned __int8 *)(v3 + 52);
    if ( v15 < 3 )
      break;
LABEL_44:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_common_evt_inject_set__alloc_tag;
    v3 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v3 )
      goto LABEL_45;
  }
  v16 = (__int64 (__fastcall *)(_QWORD))g_inject_evt_info[v15];
  if ( !v16 )
  {
    v13 = "Handler for HW_id [%hhu] not registered";
    v14 = 748;
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_evt_inject_set",
      v14,
      v13);
    v7 = 0;
    goto LABEL_15;
  }
  if ( *((_DWORD *)v16 - 1) != -1066802076 )
    __break(0x8228u);
  v7 = v16(v3);
  if ( v7 )
    goto LABEL_15;
  if ( (byte_394041 & 1) == 0 )
  {
    qword_394030 = (__int64)&qword_394030;
    qword_394038 = (__int64)&qword_394030;
    byte_394041 = 1;
  }
  list_add(v3);
  v7 = 0;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v7;
}
