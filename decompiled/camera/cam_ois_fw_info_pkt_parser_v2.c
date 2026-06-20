__int64 __fastcall cam_ois_fw_info_pkt_parser_v2(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  void **v7; // x24
  unsigned __int64 v8; // x21
  __int64 v9; // x22
  __int64 v10; // x0
  int v11; // w8
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x25
  __int64 v16; // x27
  unsigned __int64 v17; // x22
  _QWORD *v18; // x8
  _QWORD *v19; // x8
  __int64 v20; // x2
  __int64 v21; // x26
  unsigned int v22; // w0
  __int64 v23; // x2
  __int64 v24; // x26
  unsigned int v25; // w0
  unsigned int v26; // w0
  unsigned int v27; // w20
  unsigned int v28; // w20
  __int64 v29; // x4
  unsigned int v30; // w20
  _QWORD *v31; // x0
  _QWORD *v32; // x0
  _QWORD *v33; // x0

  if ( !a2 || a3 <= 0x1F )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_fw_info_pkt_parser_v2",
      831,
      "Invalid Args,o_ctrl %p,cmd_buf %p,len %d",
      (const void *)a1,
      a2,
      a3);
    return 4294967274LL;
  }
  if ( (cam_ois_fw_info_input_check((__int64)a2, a3) & 0x80000000) != 0 )
    return 4294967274LL;
  if ( (debug_mdl & 0x100000) == 0 || debug_priority )
  {
    if ( *((_BYTE *)a2 + 6) )
      goto LABEL_7;
    return 0;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x100000,
    4,
    "cam_ois_fw_info_pkt_parser_v2",
    843,
    "endianness %d, fw_count %d",
    *((unsigned __int8 *)a2 + 7),
    *((unsigned __int8 *)a2 + 6));
  if ( !*((_BYTE *)a2 + 6) )
    return 0;
LABEL_7:
  *(_DWORD *)(a1 + 4566) = *a2;
  *(_BYTE *)(a1 + 4571) = *((_BYTE *)a2 + 5);
  *(_BYTE *)(a1 + 4572) = *((_BYTE *)a2 + 6);
  *(_BYTE *)(a1 + 4573) = *((_BYTE *)a2 + 7);
  if ( mem_trace_en == 1 )
    v5 = cam_mem_trace_alloc(
           (unsigned __int64)*((unsigned __int8 *)a2 + 6) << 6,
           0xCC0u,
           0,
           "cam_ois_fw_info_pkt_parser_v2",
           0x352u);
  else
    v5 = _kvmalloc_node_noprof((unsigned __int64)*((unsigned __int8 *)a2 + 6) << 6, 0, 3520, 0xFFFFFFFFLL);
  v7 = (void **)(a1 + 4574);
  *(_QWORD *)(a1 + 4574) = v5;
  if ( !v5 )
    return 4294967284LL;
  memcpy(*v7, a2 + 8, (unsigned __int64)*((unsigned __int8 *)a2 + 6) << 6);
  v8 = (unsigned __int64)&a2[16 * (unsigned __int64)*((unsigned __int8 *)a2 + 6) + 8];
  if ( (a2[3] & 1) != 0 )
  {
    v9 = (unsigned int)a2[4];
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_info_pkt_parser_v2",
        860,
        "versionSize: %d",
        v9);
      if ( !(_DWORD)v9 )
        goto LABEL_19;
    }
    else if ( !(_DWORD)v9 )
    {
      goto LABEL_19;
    }
    if ( !*(_DWORD *)(a1 + 4616) )
    {
      *(_DWORD *)(a1 + 4616) = 1;
      v26 = cam_ois_parse_fw_setting(v8, (unsigned int)v9, a1 + 4600);
      if ( v26 )
      {
        v27 = v26;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_fw_info_pkt_parser_v2",
          867,
          "Failed to parse fw version settings");
        result = v27;
        goto LABEL_46;
      }
      v8 += v9;
    }
  }
LABEL_19:
  if ( mem_trace_en == 1 )
    v10 = cam_mem_trace_alloc(48LL * *((unsigned __int8 *)a2 + 6), 0xCC0u, 0, "cam_ois_fw_info_pkt_parser_v2", 0x369u);
  else
    v10 = _kvmalloc_node_noprof(48LL * *((unsigned __int8 *)a2 + 6), 0, 3520, 0xFFFFFFFFLL);
  v11 = (unsigned __int8)mem_trace_en;
  *(_QWORD *)(a1 + 4584) = v10;
  if ( v11 == 1 )
    v12 = cam_mem_trace_alloc(48LL * *((unsigned __int8 *)a2 + 6), 0xCC0u, 0, "cam_ois_fw_info_pkt_parser_v2", 0x36Au);
  else
    v12 = _kvmalloc_node_noprof(48LL * *((unsigned __int8 *)a2 + 6), 0, 3520, 0xFFFFFFFFLL);
  v13 = v12;
  v14 = *(_QWORD *)(a1 + 4584);
  result = 0;
  *(_QWORD *)(a1 + 4592) = v13;
  if ( !v14 || !v13 )
    goto LABEL_46;
  if ( !*((_BYTE *)a2 + 6) )
    return 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  while ( 1 )
  {
    v18 = (_QWORD *)(*(_QWORD *)(a1 + 4584) + v16);
    *v18 = v18;
    v18[1] = v18;
    v19 = (_QWORD *)(*(_QWORD *)(a1 + 4592) + v16);
    *v19 = v19;
    v19[1] = v19;
    if ( *(_DWORD *)((char *)*v7 + v15 + 56) )
    {
      v20 = *(_QWORD *)(a1 + 4584) + v16;
      *(_DWORD *)(v20 + 16) = 1;
      v21 = *(unsigned int *)((char *)*v7 + v15 + 56);
      v22 = cam_ois_parse_fw_setting(v8, (unsigned int)v21, v20);
      if ( v22 )
      {
        v28 = v22;
        v29 = 890;
        goto LABEL_45;
      }
      v8 += v21;
      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100000,
          4,
          "cam_ois_fw_info_pkt_parser_v2",
          894,
          "count:%d, init size %d",
          v17,
          v21);
    }
    if ( *(_DWORD *)((char *)*v7 + v15 + 60) )
      break;
LABEL_30:
    ++v17;
    result = 0;
    v16 += 48;
    v15 += 64;
    if ( v17 >= *((unsigned __int8 *)a2 + 6) )
      return result;
  }
  v23 = *(_QWORD *)(a1 + 4592) + v16;
  *(_DWORD *)(v23 + 16) = 1;
  v24 = *(unsigned int *)((char *)*v7 + v15 + 60);
  v25 = cam_ois_parse_fw_setting(v8, (unsigned int)v24, v23);
  if ( !v25 )
  {
    v8 += v24;
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_info_pkt_parser_v2",
        908,
        "count:%d, finalize size %d",
        v17,
        v24);
    goto LABEL_30;
  }
  v28 = v25;
  v29 = 904;
LABEL_45:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x100000,
    1,
    "cam_ois_fw_info_pkt_parser_v2",
    v29,
    "Failed to parse fw setting");
  result = v28;
LABEL_46:
  v30 = result;
  if ( *v7 )
  {
    v31 = *v7;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v31, 0);
    else
      kvfree(v31);
    result = v30;
    *v7 = nullptr;
  }
  if ( *(_QWORD *)(a1 + 4584) )
  {
    v32 = *(_QWORD **)(a1 + 4584);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v32, 0);
    else
      kvfree(v32);
    result = v30;
    *(_QWORD *)(a1 + 4584) = 0;
  }
  if ( *(_QWORD *)(a1 + 4592) )
  {
    v33 = *(_QWORD **)(a1 + 4592);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v33, 0);
    else
      kvfree(v33);
    *(_QWORD *)(a1 + 4592) = 0;
    return v30;
  }
  return result;
}
