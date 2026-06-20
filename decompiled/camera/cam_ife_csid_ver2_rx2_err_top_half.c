__int64 __fastcall cam_ife_csid_ver2_rx2_err_top_half(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int v4; // w0
  unsigned int v5; // w19
  __int64 result; // x0
  __int64 v7; // x0
  unsigned int evt_payload; // w0
  unsigned int v9; // w22
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x1
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a2;
  v16 = 0;
  if ( v2 )
  {
    v4 = cam_ife_csid_ver2_rx_err_process_top_half(v2, *(unsigned int **)(a2 + 16), 1u, &v16);
    if ( v4 )
    {
      v5 = v4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_rx2_err_top_half",
        1700,
        "CSID:%d rx_idx:%d",
        *(_DWORD *)(*(_QWORD *)(v2 + 31120) + 4LL),
        1);
      result = v5;
    }
    else
    {
      v15 = 0;
      evt_payload = cam_ife_csid_ver2_get_evt_payload(v2, &v15, (_QWORD **)(v2 + 30936), v2 + 30976);
      if ( evt_payload )
      {
        v9 = evt_payload;
        if ( (unsigned int)__ratelimit(
                             &cam_ife_csid_ver2_rx2_err_top_half__rs_346,
                             "cam_ife_csid_ver2_rx2_err_top_half") )
          v10 = 3;
        else
          v10 = 2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
          v10,
          8,
          3,
          "cam_ife_csid_ver2_rx2_err_top_half",
          1710,
          "CSID:%d status: 0x%X",
          *(unsigned int *)(*(_QWORD *)(v2 + 31120) + 4LL),
          **(unsigned int **)(a2 + 16));
        result = v9;
      }
      else
      {
        v11 = v15;
        *(_DWORD *)((char *)&qword_10 + v15) = v16;
        v12 = ktime_get_with_offset(1);
        v13 = ns_to_timespec64(v12);
        result = 0;
        *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v11) = v13;
        *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v11 + 8) = v14;
        *(_QWORD *)(a2 + 24) = v11;
      }
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_rx2_err_top_half__rs, "cam_ife_csid_ver2_rx2_err_top_half") )
      v7 = 3;
    else
      v7 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v7,
      8,
      1,
      "cam_ife_csid_ver2_rx2_err_top_half",
      1692,
      "No private returned");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
