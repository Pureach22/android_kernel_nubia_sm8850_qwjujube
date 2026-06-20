__int64 __fastcall cam_ois_fw_info_pkt_parser(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  unsigned int v5; // w20
  __int64 v6; // x0
  void **v7; // x23
  _DWORD *v8; // x20
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 result; // x0
  int v12; // w8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  _QWORD *v18; // x10
  _QWORD *v19; // x10
  unsigned int v20; // w8
  int v21; // w22
  __int64 v22; // x11
  char *v23; // x12
  unsigned int v24; // w10
  __int64 v25; // x8
  __int64 v26; // x2
  unsigned int v27; // w24
  __int64 v28; // x1
  __int64 v29; // x4
  const char *v30; // x5
  __int64 v31; // x8
  unsigned int v32; // w0
  unsigned int v33; // w0
  unsigned int v34; // w20
  unsigned int v35; // w20
  unsigned int v36; // w20
  _QWORD *v37; // x0
  _QWORD *v38; // x0
  _QWORD *v39; // x0
  __int64 v40; // [xsp+8h] [xbp-8h]

  if ( !a2 || a3 <= 0x9F )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_fw_info_pkt_parser",
      675,
      "Invalid Args,o_ctrl %p,cmd_buf %p,len %d",
      (const void *)a1,
      a2,
      a3);
    return 4294967274LL;
  }
  v5 = *((unsigned __int8 *)a2 + 6);
  if ( (debug_mdl & 0x100000) == 0 || debug_priority )
  {
    if ( v5 <= 2 )
      goto LABEL_6;
    goto LABEL_61;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x100000,
    4,
    "cam_ois_fw_info_pkt_parser",
    682,
    "endianness %d, fw_count %d",
    *((unsigned __int8 *)a2 + 7),
    v5);
  if ( v5 > 2 )
  {
LABEL_61:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_fw_info_pkt_parser",
      759,
      "Exceed max fw count");
    return 4294967274LL;
  }
LABEL_6:
  *(_DWORD *)(a1 + 4566) = *a2;
  *(_BYTE *)(a1 + 4571) = *((_BYTE *)a2 + 5);
  *(_BYTE *)(a1 + 4572) = *((_BYTE *)a2 + 6);
  *(_BYTE *)(a1 + 4573) = *((_BYTE *)a2 + 7);
  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(
           (unsigned __int64)*((unsigned __int8 *)a2 + 6) << 6,
           0xCC0u,
           0,
           "cam_ois_fw_info_pkt_parser",
           0x2B1u);
  else
    v6 = _kvmalloc_node_noprof((unsigned __int64)*((unsigned __int8 *)a2 + 6) << 6, 0, 3520, 0xFFFFFFFFLL);
  v7 = (void **)(a1 + 4574);
  *(_QWORD *)(a1 + 4574) = v6;
  if ( !v6 )
    return 4294967284LL;
  memcpy(*v7, a2 + 2, (unsigned __int64)*((unsigned __int8 *)a2 + 6) << 6);
  v8 = a2 + 40;
  if ( (a2[35] & 1) != 0 )
  {
    v9 = (unsigned int)a2[36];
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_info_pkt_parser",
        700,
        "versionSize: %d",
        v9);
      if ( !(_DWORD)v9 )
        goto LABEL_16;
    }
    else if ( !(_DWORD)v9 )
    {
      goto LABEL_16;
    }
    if ( !*(_DWORD *)(a1 + 4616) )
    {
      *(_DWORD *)(a1 + 4616) = 1;
      v33 = cam_ois_parse_fw_setting(a2 + 40, (unsigned int)v9, a1 + 4600);
      if ( v33 )
      {
        v34 = v33;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_fw_info_pkt_parser",
          708,
          "Failed to parse fw version settings");
        result = v34;
LABEL_44:
        v36 = result;
        if ( *v7 )
        {
          v37 = *v7;
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v37, 0);
          else
            kvfree(v37);
          result = v36;
          *v7 = nullptr;
        }
        if ( *(_QWORD *)(a1 + 4584) )
        {
          v38 = *(_QWORD **)(a1 + 4584);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v38, 0);
          else
            kvfree(v38);
          result = v36;
          *(_QWORD *)(a1 + 4584) = 0;
        }
        if ( *(_QWORD *)(a1 + 4592) )
        {
          v39 = *(_QWORD **)(a1 + 4592);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v39, 0);
          else
            kvfree(v39);
          *(_QWORD *)(a1 + 4592) = 0;
          return v36;
        }
        return result;
      }
      v8 = (_DWORD *)((char *)v8 + v9);
    }
  }
LABEL_16:
  if ( mem_trace_en == 1 )
    v10 = cam_mem_trace_alloc(48LL * *((unsigned __int8 *)a2 + 6), 0xCC0u, 0, "cam_ois_fw_info_pkt_parser", 0x2CBu);
  else
    v10 = _kvmalloc_node_noprof(48LL * *((unsigned __int8 *)a2 + 6), 0, 3520, 0xFFFFFFFFLL);
  v12 = (unsigned __int8)mem_trace_en;
  *(_QWORD *)(a1 + 4584) = v10;
  if ( v12 == 1 )
    v13 = cam_mem_trace_alloc(48LL * *((unsigned __int8 *)a2 + 6), 0xCC0u, 0, "cam_ois_fw_info_pkt_parser", 0x2CCu);
  else
    v13 = _kvmalloc_node_noprof(48LL * *((unsigned __int8 *)a2 + 6), 0, 3520, 0xFFFFFFFFLL);
  v14 = v13;
  v15 = *(_QWORD *)(a1 + 4584);
  result = 4294967284LL;
  *(_QWORD *)(a1 + 4592) = v14;
  if ( !v15 || !v14 )
    goto LABEL_44;
  if ( *(_BYTE *)(a1 + 4572) )
  {
    v16 = 0;
    v17 = 0;
    do
    {
      ++v17;
      v18 = (_QWORD *)(*(_QWORD *)(a1 + 4584) + v16);
      *v18 = v18;
      v18[1] = v18;
      v19 = (_QWORD *)(*(_QWORD *)(a1 + 4592) + v16);
      v16 += 48;
      *v19 = v19;
      v19[1] = v19;
    }
    while ( v17 < *(unsigned __int8 *)(a1 + 4572) );
    if ( *(_BYTE *)(a1 + 4572) )
    {
      v20 = 0;
      v21 = 0;
      while ( 1 )
      {
        v22 = v20 >> 1;
        v23 = (char *)*v7 + 64 * v22;
        v24 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 20);
        if ( (v20 & 1) != 0 )
        {
          v31 = *(_QWORD *)(a1 + 4592);
          v26 = v31 + 48LL * (unsigned int)v22;
          v27 = *((_DWORD *)v23 + 15);
          if ( !v24 )
          {
LABEL_35:
            if ( !v27 )
              goto LABEL_30;
            goto LABEL_36;
          }
          v28 = debug_mdl & 0x100000;
          v40 = v31 + 48LL * (unsigned int)v22;
          v29 = 738;
          v30 = "finalize size %d";
        }
        else
        {
          v25 = *(_QWORD *)(a1 + 4584);
          v26 = v25 + 48LL * (unsigned int)v22;
          v27 = *((_DWORD *)v23 + 14);
          if ( !v24 )
            goto LABEL_35;
          v28 = debug_mdl & 0x100000;
          v40 = v25 + 48LL * (unsigned int)v22;
          v29 = 733;
          v30 = "init size %d";
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          v28,
          4,
          "cam_ois_fw_info_pkt_parser",
          v29,
          v30,
          v27);
        v26 = v40;
        if ( !v27 )
          goto LABEL_30;
LABEL_36:
        *(_DWORD *)(v26 + 16) = 1;
        v32 = cam_ois_parse_fw_setting(v8, v27, v26);
        if ( v32 )
        {
          v35 = v32;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x100000,
            1,
            "cam_ois_fw_info_pkt_parser",
            752,
            "Failed to parse fw setting");
          result = v35;
          goto LABEL_44;
        }
LABEL_30:
        ++v21;
        v8 = (_DWORD *)((char *)v8 + v27);
        v20 = (unsigned __int8)v21;
        result = 0;
        if ( (unsigned __int8)v21 >= 2 * (unsigned int)*(unsigned __int8 *)(a1 + 4572) )
          return result;
      }
    }
  }
  return 0;
}
