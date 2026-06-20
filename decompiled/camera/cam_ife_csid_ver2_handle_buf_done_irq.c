__int64 __fastcall cam_ife_csid_ver2_handle_buf_done_irq(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  int v3; // w0
  unsigned int v5; // w22
  __int64 v6; // x9
  int v7; // w19

  v2 = *a2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v5 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_handle_buf_done_irq",
      874,
      "CSID:%u Enter",
      *(_DWORD *)(*(_QWORD *)(v2 + 31120) + 4LL));
    a1 = v5;
  }
  v3 = cam_irq_controller_handle_irq(a1, *(_QWORD *)(v2 + 31112), 0);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v6 = *(_QWORD *)(v2 + 31120);
    v7 = v3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_handle_buf_done_irq",
      877,
      "CSID:%u Exit (rc=%d)",
      *(_DWORD *)(v6 + 4),
      v3);
    v3 = v7;
  }
  if ( v3 == 1 )
    return 0;
  else
    return 4294967274LL;
}
