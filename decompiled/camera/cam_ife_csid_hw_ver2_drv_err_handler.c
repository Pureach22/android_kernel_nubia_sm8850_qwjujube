__int64 __fastcall cam_ife_csid_hw_ver2_drv_err_handler(__int64 a1)
{
  __int64 v2; // x23
  __int64 v3; // x24
  int v4; // w20
  int v5; // w21
  int v6; // w22
  int v7; // w0
  __int64 v8; // x8
  int v9; // w0

  v2 = **(_QWORD **)(a1 + 31136);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
  v4 = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v2 + 120) + 108LL));
  v5 = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v2 + 120) + 112LL));
  v6 = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v2 + 120) + 116LL));
  v7 = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v2 + 120) + 120LL));
  v8 = *(_QWORD *)(v2 + 120);
  LODWORD(v2) = v7;
  v9 = cam_io_r_mb(v3 + *(unsigned int *)(v8 + 124));
  return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           8,
           3,
           "cam_ife_csid_hw_ver2_drv_err_handler",
           2567,
           "CSID[%u] DRV cfg0:0x%x cfg1:0x%x cfg2:0x%x qtimer_val [start:end] [0x%x : 0x%x]",
           *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
           v4,
           v5,
           v6,
           v2,
           v9);
}
