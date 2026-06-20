__int64 __fastcall cam_cci_i2c_write_async(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x24
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x11
  int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v22; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v24; // x26

  v4 = *(_QWORD *)(a1 + 240);
  if ( !v4 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_i2c_write_async",
      2133);
    return 4294967274LL;
  }
  if ( mem_trace_en == 1 )
  {
    v8 = cam_mem_trace_alloc(136, 0xCC0u, 0, "cam_cci_i2c_write_async", 0x859u);
    if ( v8 )
      goto LABEL_4;
LABEL_11:
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_i2c_write_async",
      2140);
    return 4294967284LL;
  }
  v8 = _kvmalloc_node_noprof(136, 0, 3520, 0xFFFFFFFFLL);
  if ( !v8 )
    goto LABEL_11;
LABEL_4:
  while ( 1 )
  {
    *(_QWORD *)(v8 + 88) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v8 + 96) = v8 + 96;
    *(_QWORD *)(v8 + 104) = v8 + 96;
    *(_QWORD *)(v8 + 112) = &cam_cci_write_async_helper;
    *(_QWORD *)v8 = v4;
    *(_QWORD *)(v8 + 8) = *(_QWORD *)a2;
    v9 = *(_QWORD *)(a2 + 32);
    v10 = *(_QWORD *)(a2 + 8);
    v11 = *(_QWORD *)(a2 + 16);
    *(_QWORD *)(v8 + 32) = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(v8 + 40) = v9;
    *(_QWORD *)(v8 + 16) = v10;
    *(_QWORD *)(v8 + 24) = v11;
    v13 = *(_QWORD *)(a2 + 56);
    v12 = *(_QWORD *)(a2 + 64);
    v14 = *(_QWORD *)(a2 + 40);
    v15 = *(_QWORD *)(a2 + 48);
    *(_DWORD *)(v8 + 80) = a3;
    *(_DWORD *)(v8 + 128) = a4;
    *(_QWORD *)(v8 + 64) = v13;
    *(_QWORD *)(v8 + 72) = v12;
    v16 = (unsigned __int8)mem_trace_en;
    *(_QWORD *)(v8 + 48) = v14;
    *(_QWORD *)(v8 + 56) = v15;
    v17 = *(unsigned int *)(a2 + 32);
    if ( !(_DWORD)v17 )
      break;
    if ( v16 )
    {
      v18 = cam_mem_trace_alloc(16 * v17, 0xCC0u, 0, "cam_cci_i2c_write_async", 0x871u);
      *(_QWORD *)(v8 + 32) = v18;
      if ( !v18 )
        goto LABEL_17;
    }
    else
    {
      v22 = _kvmalloc_node_noprof(16LL * *(unsigned int *)(a2 + 32), 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v8 + 32) = v22;
      if ( !v22 )
      {
LABEL_17:
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
          "cam_cci_i2c_write_async",
          2164);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v8, 0);
        else
          kvfree(v8);
        return 4294967284LL;
      }
    }
    memcpy(*(void **)(v8 + 32), *(const void **)(a2 + 24), 16LL * *(unsigned int *)(a2 + 32));
    *(_DWORD *)(v8 + 44) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(v8 + 48) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(v8 + 40) = *(_DWORD *)(a2 + 32);
    *(_WORD *)(v8 + 52) = *(_WORD *)(a2 + 44);
    v19 = ktime_get_with_offset(1);
    v20 = *(unsigned int *)(v8 + 80);
    *(_QWORD *)(v8 + 120) = v19;
    if ( (unsigned int)v20 < 2 )
    {
      queue_work_on(32, *(_QWORD *)(v4 + 8 * v20 + 5280), v8 + 88);
      return 0;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v24 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_cci_i2c_write_async__alloc_tag;
    v8 = _kvmalloc_node_noprof(136, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v24;
    if ( !v8 )
      goto LABEL_11;
  }
  if ( v16 )
    cam_mem_trace_free((_QWORD *)v8, 0);
  else
    kvfree(v8);
  return 4294967274LL;
}
