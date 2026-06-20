__int64 __fastcall cam_ife_csid_ver2_handle_path_irq(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  int v5; // w0
  unsigned int v7; // w23
  const char *v8; // x7
  int v9; // w19

  v2 = *a2;
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*a2 + 16) + 112LL) + 3680LL);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v7 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_handle_path_irq",
      939,
      "CSID:%u %s Enter",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
      (const char *)(v2 + 128));
    a1 = v7;
  }
  v4 = *(unsigned int *)(v2 + 4);
  if ( (unsigned int)v4 >= 0xC )
  {
    __break(0x5512u);
    return cam_ife_csid_ver2_path_top_half();
  }
  else
  {
    v5 = cam_irq_controller_handle_irq(a1, *(_QWORD *)(v3 + 8 * v4 + 31016), 0);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v8 = (const char *)(v2 + 128);
      v9 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_handle_path_irq",
        942,
        "CSID:%u %s Exit (rc=%d)",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        v8,
        v5);
      v5 = v9;
    }
    if ( v5 == 1 )
      return 0;
    else
      return 4294967274LL;
  }
}
