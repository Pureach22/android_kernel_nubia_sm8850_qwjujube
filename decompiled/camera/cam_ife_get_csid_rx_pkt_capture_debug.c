__int64 __fastcall cam_ife_get_csid_rx_pkt_capture_debug(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  const void *v8; // x29
  const void *v9; // x30

  *a2 = (unsigned int)dword_3A8500;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_get_csid_rx_pkt_capture_debug",
    &print_fmt_cam_req_mgr_connect_device[6],
    "Get CSID RX capture Debug value :%lld",
    dword_3A8500,
    a8,
    v8,
    v9);
  return 0;
}
