__int64 __fastcall cam_ife_set_csid_rx_pkt_capture_debug(__int64 a1, unsigned __int64 a2)
{
  int v2; // w11

  if ( a2 >= 0xFFFFF )
    v2 = 0;
  else
    v2 = a2;
  byte_3A8579 = a2 < 0xFFFFF;
  dword_3A8500 = v2;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_set_csid_rx_pkt_capture_debug",
    18654,
    "Set CSID RX capture Debug value :%lld",
    a2);
  return 0;
}
