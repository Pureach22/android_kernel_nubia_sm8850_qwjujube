__int64 __fastcall cam_isp_io_buf_get_entries_util(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v4; // w6
  unsigned int v5; // w6
  unsigned int v6; // w9
  __int64 v7; // x19
  int v8; // w8
  __int64 v9; // x8
  __int64 *v10; // x8
  int v11; // w19
  const char *v12; // x5
  __int64 v13; // x4
  unsigned int v14; // w8
  __int64 v15; // x8
  __int64 v16; // x20
  _DWORD *v17; // x21
  __int64 v18; // x22
  unsigned __int64 v19; // x8
  int v20; // w6
  _DWORD *v21; // x8
  _DWORD *v22; // x9
  unsigned int v23; // w10
  __int64 v24; // x11
  __int64 v25; // x8
  __int64 v26; // x9
  unsigned int v27; // w6
  unsigned int v28; // w8
  unsigned int v29; // w11
  unsigned int v30; // w7
  __int64 v31; // x8
  bool v32; // w10
  __int64 v34; // x19
  _DWORD *v35; // x22
  __int64 v36; // x23
  _DWORD *v37; // x20
  __int64 v38; // x21
  __int64 v39; // x22
  __int64 v40; // x23

  if ( (debug_mdl & 0x1000008) != 0 && debug_priority == 0 )
  {
    v34 = a1;
    v35 = a2;
    v36 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000008,
      4,
      "cam_isp_io_buf_get_entries_util",
      783,
      "req_id %llu resource_type:%d fence:%d direction %d format %d",
      *(_QWORD *)(**(_QWORD **)(a1 + 16) + 8LL),
      a2[47],
      a2[48],
      a2[56],
      a2[42]);
    a2 = v35;
    a3 = v36;
    a1 = v34;
  }
  v4 = a2[56];
  if ( v4 == 1 )
  {
    v10 = *(__int64 **)(a1 + 40);
    if ( !v10 )
    {
      v14 = -42;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_io_buf_get_entries_util",
          819,
          "No BUS Read supported hw_type %d io_cfg %d req:%d type:%d fence:%d",
          *(_DWORD *)(*(_QWORD *)(a1 + 48) + 8LL),
          *(_DWORD *)(**(_QWORD **)(a1 + 16) + 36LL),
          *(_QWORD *)(**(_QWORD **)(a1 + 16) + 8LL),
          a2[47],
          a2[48]);
        return (unsigned int)-42;
      }
      return v14;
    }
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 48) + 8LL) == 7 )
      v11 = a2[47];
    else
      v11 = 2;
    while ( 1 )
    {
      v10 = (__int64 *)*v10;
      *(_QWORD *)a3 = v10;
      if ( v10 == *(__int64 **)(a1 + 40) )
        break;
      if ( *((_DWORD *)v10 + 5) == v11 )
        goto LABEL_34;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_io_buf_get_entries_util",
      834,
      "No Read resource");
    return (unsigned int)-22;
  }
  if ( v4 != 2 )
  {
    v12 = "Invalid io config direction :%d";
    v13 = 840;
LABEL_56:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_io_buf_get_entries_util",
      v13,
      v12);
    return (unsigned int)-22;
  }
  v5 = a2[47];
  v6 = *(_DWORD *)(a1 + 80);
  if ( v5 < v6 || v5 >= *(_DWORD *)(a1 + 84) )
    return (unsigned int)-42;
  v7 = (unsigned __int8)a2[47];
  v8 = *(_DWORD *)(*(_QWORD *)(a1 + 48) + 8LL);
  if ( v8 == 2 )
  {
    v15 = *(_QWORD *)(a1 + 8);
    if ( *(_BYTE *)(v15 + 25) == 1 )
    {
      v16 = a1;
      v17 = a2;
      v18 = a3;
      ((void (__fastcall *)(__int64, _QWORD))cam_isp_validate_for_ife_scratch)(v15 + 8, v5);
      a2 = v17;
      a3 = v18;
      a1 = v16;
    }
  }
  else if ( v8 == 7 )
  {
    v9 = *(_QWORD *)(a1 + 8);
    if ( *(_BYTE *)(v9 + 24) == 1 && (unsigned int)v7 < *(_DWORD *)v9 + (unsigned int)(unsigned __int8)v6 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v37 = a2;
        v38 = a1;
        v39 = a3;
        v40 = *(_QWORD *)(a1 + 8);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_validate_for_sfe_scratch",
          736,
          "Buffer found for SFE port: 0x%x - skip scratch buffer",
          v5);
        v9 = v40;
        a2 = v37;
        a3 = v39;
        a1 = v38;
      }
      *(_DWORD *)(v9 + 4) |= 1 << v7;
    }
  }
  v19 = *(_QWORD *)(a1 + 32) + ((unsigned __int64)*(unsigned __int8 *)(*(_QWORD *)(a1 + 56) + v7) << 7);
  *(_QWORD *)a3 = v19;
  if ( !*(_DWORD *)(v19 + 16) )
  {
    v12 = "io res id:%d not valid";
    v13 = 807;
    goto LABEL_56;
  }
LABEL_34:
  if ( *(_BYTE *)(a1 + 92) != 1 )
    return 0;
  v20 = a2[56];
  v21 = *(_DWORD **)(a1 + 16);
  if ( v20 != 1 )
  {
    if ( v20 == 2 )
    {
      v22 = v21 + 14;
      v23 = v21[14];
      if ( v23 < v21[11] )
      {
        v24 = 12;
        goto LABEL_42;
      }
    }
    goto LABEL_55;
  }
  v22 = v21 + 18;
  v23 = v21[18];
  if ( v23 >= v21[15] )
  {
LABEL_55:
    v12 = "dir: %d max_ln:%d max_out: %u in: %u out %u";
    v13 = 864;
    goto LABEL_56;
  }
  v24 = 16;
LABEL_42:
  v25 = *(_QWORD *)&v21[v24];
  *v22 = v23 + 1;
  v26 = v25 + ((unsigned __int64)v23 << 6);
  *(_DWORD *)v26 = a2[47];
  *(_DWORD *)(v26 + 16) = a2[48];
  *(_DWORD *)(v26 + 20) = a2[49];
  if ( *(_DWORD *)(a1 + 88) != 3 )
  {
    v14 = 0;
    *(_DWORD *)(v26 + 4) = 0;
    return v14;
  }
  if ( !a2 || (v27 = a2[62], v27 > 4) || ((1 << v27) & 0x16) == 0 )
  {
    v12 = "Invalid IO cfg flag : %u for res_id: %u, req_id: %u";
    v13 = 876;
    goto LABEL_56;
  }
  *(_DWORD *)(v26 + 4) = v27;
  v28 = a2[62];
  v29 = __clz(__rbit32(v28));
  if ( v28 )
    v30 = v29;
  else
    v30 = -1;
  if ( **(_BYTE **)a1 != 1 )
    return 0;
  if ( v30 < 3 )
  {
    v31 = *(_QWORD *)(*(_QWORD *)a3 + 8LL * v30 + 48);
    *(_QWORD *)(v26 + 8) = v31;
    if ( v31 )
    {
      v32 = *(_BYTE *)(*(_QWORD *)a3 + 121LL) != 1 || v30 == *(_DWORD *)(*(_QWORD *)a3 + 96LL);
      v14 = 0;
      *(_BYTE *)(v26 + 24) = v32;
      return v14;
    }
    v12 = "[FRMHDR] No frameheader buffer configured for res_id: %u, ctxt_id: %u, req_id: %llu";
    v13 = 889;
    goto LABEL_56;
  }
  __break(0x5512u);
  return cam_isp_add_io_buffers_util(a1, a2);
}
