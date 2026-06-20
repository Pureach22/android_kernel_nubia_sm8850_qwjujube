__int64 __fastcall cam_csiphy_reg_dump(__int64 a1)
{
  char *v1; // x19
  unsigned __int64 v2; // x21
  int v3; // w22
  _QWORD *v4; // x20
  __int64 v5; // x21
  __int64 v6; // x27
  unsigned __int8 v7; // w26
  unsigned __int8 v8; // w23
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v11; // x6
  unsigned int v12; // w19
  int v13; // w0
  char v14; // w0
  unsigned __int8 v15; // w8

  if ( !a1 )
  {
    v9 = "invalid input %d";
    v10 = 139;
    v11 = 4294967274LL;
    v12 = -22;
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_reg_dump",
      v10,
      v9,
      v11);
    return v12;
  }
  v1 = *(char **)(a1 + 288);
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 224) + 8LL) - **(_QWORD **)(a1 + 224) + 1LL;
  if ( !v1 || (v2 & 0x3FFFC) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_io_dump",
      38,
      "Invalid params. base_addr: 0x%p num_regs: %u",
      v1,
      (unsigned __int16)((unsigned int)v2 >> 2));
    v12 = -22;
LABEL_18:
    v9 = "generating dump failed %d";
    v10 = 146;
    v11 = v12;
    goto LABEL_19;
  }
  v3 = *(_DWORD *)(a1 + 20);
  if ( mem_trace_en == 1 )
  {
    v4 = (_QWORD *)cam_mem_trace_alloc(250, 0xCC0u, 0, "cam_csiphy_io_dump", 0x2Au);
    if ( v4 )
      goto LABEL_6;
    goto LABEL_17;
  }
  v4 = (_QWORD *)_kvmalloc_node_noprof(250, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
  {
LABEL_17:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_io_dump",
      44,
      "Could not allocate the memory for buffer");
    v12 = -12;
    goto LABEL_18;
  }
LABEL_6:
  v5 = (unsigned __int16)(v2 >> 2);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    3,
    "cam_csiphy_io_dump",
    48,
    "Base: 0x%pK num_regs: %u",
    v1,
    v5);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    3,
    "cam_csiphy_io_dump",
    49,
    "CSIPHY:%d Dump",
    v3);
  v6 = 0;
  v7 = 0;
  v8 = -6;
  do
  {
    while ( 1 )
    {
      v13 = cam_io_r_mb(&v1[4 * v6]);
      v14 = scnprintf((char *)v4 + v7, v8, "0x%x=0x%x\n", 4 * (int)v6, v13);
      v15 = v7 + v14;
      v8 = -6 - (v7 + v14);
      if ( v8 >= 0x15u )
        break;
      *((_BYTE *)v4 + v15 - 1) = 0;
      printk(&unk_43DF12);
      ++v6;
      v7 = 0;
      v8 = -6;
      if ( v6 == v5 )
        goto LABEL_13;
    }
    ++v6;
    v7 += v14;
  }
  while ( v6 != v5 );
  if ( v15 )
  {
    *((_BYTE *)v4 + (unsigned int)v15 - 1) = 0;
    printk(&unk_43DF12);
  }
LABEL_13:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v4, 0);
  else
    kvfree(v4);
  return 0;
}
