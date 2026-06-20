__int64 __fastcall cam_ife_csid_ver2_handle_rx_irq(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  int v3; // w0
  __int64 v5; // x9
  int v6; // w19

  v2 = *a2;
  v3 = cam_irq_controller_handle_irq(a1, *(_QWORD *)(*a2 + 31000), 0);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v5 = *(_QWORD *)(v2 + 31120);
    v6 = v3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_handle_rx_irq",
      909,
      "CSID:%d Exit (rc=%d)",
      *(_DWORD *)(v5 + 4),
      v3);
    v3 = v6;
  }
  if ( v3 == 1 )
    return 0;
  else
    return 4294967274LL;
}
