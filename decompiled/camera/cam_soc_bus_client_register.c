__int64 __fastcall cam_soc_bus_client_register(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, char a5)
{
  _QWORD *v9; // x20
  __int64 *v10; // x21
  int v11; // w26
  unsigned __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x6
  __int64 v15; // x7
  unsigned __int64 v16; // x0
  unsigned int v17; // w0
  unsigned int v18; // w22
  __int64 v19; // x6
  __int64 v20; // x4
  unsigned int v21; // w0
  __int64 v22; // x0
  int v23; // w8
  __int64 v24; // x4
  __int64 v25; // x8
  unsigned int v27; // w0
  __int64 *v28; // x8
  int v29; // w9
  __int64 v30; // x6
  __int64 v31; // x7
  int v32; // w8
  bool v33; // zf
  const char *v34; // x9

  if ( mem_trace_en == 1 )
  {
    v9 = (_QWORD *)cam_mem_trace_alloc(16, 0xCC0u, 0, "cam_soc_bus_client_register", 0xD8u);
    if ( v9 )
      goto LABEL_3;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_bus_client_register",
      218,
      "soc bus client is NULL");
    return (unsigned int)-12;
  }
  v9 = (_QWORD *)_kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
  if ( !v9 )
    goto LABEL_13;
LABEL_3:
  *a3 = v9;
  if ( mem_trace_en == 1 )
  {
    v10 = (__int64 *)cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_soc_bus_client_register", 0xE1u);
    if ( v10 )
      goto LABEL_5;
    goto LABEL_15;
  }
  v10 = (__int64 *)_kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  if ( !v10 )
  {
LABEL_15:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    *a3 = 0;
    return (unsigned int)-12;
  }
LABEL_5:
  *v9 = v10;
  v9[1] = a4;
  v11 = *(unsigned __int8 *)(a4 + 16);
  v12 = cam_wrapper_icc_get(a1 + 16, *(unsigned int *)(a4 + 8), *(unsigned int *)(a4 + 12), *(_QWORD *)a4, a5 & 1);
  if ( v11 == 1 )
  {
    v10[1] = v12;
    v13 = v9[1];
    v14 = *(unsigned int *)(v13 + 8);
    v15 = *(unsigned int *)(v13 + 12);
    if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL )
    {
      v16 = cam_wrapper_icc_get(a1 + 16, (unsigned int)v14, (unsigned int)v15, *(_QWORD *)v13, a5 & 1);
      v10[2] = v16;
      if ( v16 && v16 < 0xFFFFFFFFFFFFF001LL )
      {
        cam_wrapper_icc_set_tag(v10[1], 3);
        cam_wrapper_icc_set_tag(v10[2], 4);
        v17 = cam_wrapper_icc_set_bw(v10[1], 0, 0);
        if ( v17 )
        {
          v18 = v17;
          v19 = *(_QWORD *)v9[1];
          v20 = 274;
LABEL_21:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_bus_client_register",
            v20,
            "Bus client[%s] update request failed, rc = %d",
            v19,
            v18);
          if ( *(_BYTE *)(v9[1] + 16LL) == 1 )
          {
            cam_wrapper_icc_put(v10[1]);
            v22 = v10[2];
          }
          else
          {
            v22 = *v10;
          }
          cam_wrapper_icc_put(v22);
          goto LABEL_33;
        }
        v27 = cam_wrapper_icc_set_bw(v10[2], 0, 0);
        if ( v27 )
        {
          v18 = v27;
          v19 = *(_QWORD *)v9[1];
          v20 = 282;
          goto LABEL_21;
        }
        goto LABEL_43;
      }
      v25 = v9[1];
      v14 = *(unsigned int *)(v25 + 8);
      v15 = *(unsigned int *)(v25 + 12);
      v23 = 2;
      v24 = 257;
    }
    else
    {
      v23 = 1;
      v24 = 244;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_bus_client_register",
      v24,
      "Failed to register DRV bus client Bus Client=[%s] : src=%d, dst=%d bus_path:%d",
      v14,
      v15,
      v23);
LABEL_32:
    v18 = -22;
LABEL_33:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v10, 0);
    else
      kvfree(v10);
    *v9 = 0;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    *a3 = 0;
    return v18;
  }
  *v10 = v12;
  if ( !v12 || v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_bus_client_register",
      291,
      "failed to register HLOS bus client");
    goto LABEL_32;
  }
  v21 = cam_wrapper_icc_set_bw(v12, 0, 0);
  if ( v21 )
  {
    v18 = v21;
    v19 = *(_QWORD *)v9[1];
    v20 = 300;
    goto LABEL_21;
  }
LABEL_43:
  v18 = 0;
  if ( (debug_mdl & 0x2020000) != 0 && !debug_priority )
  {
    v28 = (__int64 *)v9[1];
    v29 = *((unsigned __int8 *)v28 + 16);
    v30 = *v28;
    v31 = *((unsigned int *)v28 + 2);
    v32 = *((_DWORD *)v28 + 3);
    v33 = v29 == 0;
    v34 = "Y";
    if ( v33 )
      v34 = "N";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, const char *))cam_print_log)(
      3,
      debug_mdl & 0x2020000,
      4,
      "cam_soc_bus_client_register",
      308,
      "Register Bus Client=[%s] : src=%d, dst=%d is_drv_port:%s",
      v30,
      v31,
      v32,
      v34);
    return 0;
  }
  return v18;
}
