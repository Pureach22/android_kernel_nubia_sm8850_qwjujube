__int64 __fastcall spectral_scan_activate_service(__int64 a1)
{
  return register_cld_cmd_cb(29, spectral_scan_msg_handler, *(_QWORD *)(a1 + 96));
}
