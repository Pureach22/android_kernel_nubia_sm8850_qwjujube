__int64 __fastcall cam_ife_csid_ver2_irq_line_test(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x22
  unsigned int v5; // w0
  unsigned int v6; // w19
  unsigned int *v8; // x10
  __int64 v9; // x22
  int v10; // w19
  __int64 v11; // x0
  char v12; // w21
  int v13; // w0
  int v14; // w6

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3680);
    v2 = *(_QWORD *)(v1 + 31128);
    v3 = *(_QWORD *)(v2 + 384);
    v4 = **(_QWORD **)(v1 + 31136);
    v5 = cam_ife_csid_enable_soc_resources(v2 + 96, *(_DWORD *)(v2 + 2968));
    if ( v5 )
    {
      v6 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_irq_line_test",
        9672,
        "CSID[%u] Enable soc failed",
        *(_DWORD *)(*(_QWORD *)(v1 + 31120) + 4LL));
      return v6;
    }
    else
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v8 = *(unsigned int **)(v4 + 120);
        v9 = v2;
        v10 = *(_DWORD *)(*(_QWORD *)(v1 + 31120) + 4LL);
        v11 = v3 + *v8;
        v12 = debug_mdl;
        v13 = cam_io_r_mb(v11);
        v14 = v10;
        v2 = v9;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v12 & 8,
          4,
          "cam_ife_csid_ver2_irq_line_test",
          9678,
          "CSID[%u] hw-version:0x%x",
          v14,
          v13);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_irq_line_test",
        9684,
        "CSID[%u] IRQ line test failed",
        *(_DWORD *)(*(_QWORD *)(v1 + 31120) + 4LL));
      cam_ife_csid_disable_soc_resources(v2 + 96);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_irq_line_test",
      9661,
      "CSID: Invalid args");
    return 4294967274LL;
  }
}
