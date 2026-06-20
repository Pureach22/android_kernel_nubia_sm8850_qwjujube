__int64 __fastcall cam_ife_csid_ver2_process_top_info(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v6; // x19
  int v7; // w8
  unsigned __int64 v8; // x23
  _BYTE *v11; // x24
  __int64 v12; // x8
  __int64 v13; // x23
  __int64 v14; // x24
  unsigned int v15; // w20
  int v16; // w21
  int v17; // w22
  int v18; // w0
  __int64 v19; // x8
  int v20; // w0

  v6 = result;
  v7 = *(_DWORD *)(result + 4LL * a3 + 2184);
  v8 = v7 & a2;
  if ( (v7 & a2) == 0 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
             3,
             8,
             1,
             "cam_ife_csid_ver2_process_top_info",
             3074,
             "CSID:%u Unexpected Scenario top_idx:%u",
             *(unsigned int *)(*(_QWORD *)(result + 31120) + 4LL),
             a3);
  v11 = *(_BYTE **)(**(_QWORD **)(result + 31136) + 616LL);
  v12 = *(_QWORD *)&v11[8 * a3];
  if ( (v12 & 1) != 0 && ((v8 >> v11[16]) & 1) != 0 )
  {
    cam_cpas_log_votes(1);
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_ife_csid_ver2_process_top_info",
               3083,
               "CSID:%d INFO_VOTE_UP timestamp:(%lld.%09lld)",
               *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL),
               a4,
               a5);
    v12 = *(_QWORD *)&v11[8 * a3];
  }
  if ( (v12 & 2) != 0 && ((v8 >> v11[17]) & 1) != 0 )
  {
    cam_cpas_log_votes(1);
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_ife_csid_ver2_process_top_info",
               3091,
               "CSID:%d INFO_VOTE_DN timestamp:(%lld.%09lld)",
               *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL),
               a4,
               a5);
    v12 = *(_QWORD *)&v11[8 * a3];
  }
  if ( (v12 & 4) != 0 && ((v8 >> v11[18]) & 1) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_process_top_info",
      3098,
      "CSID:%d ERR_NO_VOTE_DN timestamp:(%lld.%09lld)",
      *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL),
      a4,
      a5);
    v13 = **(_QWORD **)(v6 + 31136);
    v14 = *(_QWORD *)(*(_QWORD *)(v6 + 31128) + 384LL);
    v15 = cam_io_r_mb(v14 + *(unsigned int *)(*(_QWORD *)(v13 + 120) + 108LL));
    v16 = cam_io_r_mb(v14 + *(unsigned int *)(*(_QWORD *)(v13 + 120) + 112LL));
    v17 = cam_io_r_mb(v14 + *(unsigned int *)(*(_QWORD *)(v13 + 120) + 116LL));
    v18 = cam_io_r_mb(v14 + *(unsigned int *)(*(_QWORD *)(v13 + 120) + 120LL));
    v19 = *(_QWORD *)(v13 + 120);
    LODWORD(v13) = v18;
    v20 = cam_io_r_mb(v14 + *(unsigned int *)(v19 + 124));
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, int, _DWORD, int))cam_print_log)(
             3,
             8,
             3,
             "cam_ife_csid_hw_ver2_drv_err_handler",
             2567,
             "CSID[%u] DRV cfg0:0x%x cfg1:0x%x cfg2:0x%x qtimer_val [start:end] [0x%x : 0x%x]",
             *(unsigned int *)(*(_QWORD *)(v6 + 31120) + 4LL),
             v15,
             v16,
             v17,
             v13,
             v20);
  }
  return result;
}
