__int64 __fastcall cam_hw_cdm_bl_write(__int64 a1, unsigned int a2, int a3, int a4, char a5, unsigned int a6)
{
  __int64 v6; // x24
  __int64 v12; // x25
  unsigned int v13; // w19
  __int64 v14; // x0
  int v15; // w9
  unsigned int v17; // w25

  v6 = *(_QWORD *)(a1 + 3680);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v17 = a6;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_bl_write",
      814,
      "%s%d Base: 0x%x, Len: %u, Tag: %u, set_arb: %u, fifo_idx: %u",
      *(const char **)(a1 + 152),
      *(_DWORD *)(a1 + 116),
      a2,
      a3,
      a4,
      a5 & 1,
      a6);
    a6 = v17;
    if ( v17 < 4 )
      goto LABEL_4;
LABEL_13:
    __break(0x5512u);
    return cam_hw_cdm_commit_bl_write();
  }
  if ( a6 >= 4 )
    goto LABEL_13;
LABEL_4:
  v12 = a6;
  if ( cam_cdm_write_hw_reg(a1, **(_DWORD **)(*(_QWORD *)(v6 + 232) + 8LL * a6 + 8), a2) )
  {
    v13 = 1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_bl_write",
      819,
      "Failed to write CDM base to BL base");
  }
  else
  {
    v14 = a1;
    if ( (a5 & 1) != 0 )
      v15 = 0x100000;
    else
      v15 = 0;
    v13 = 0;
    if ( cam_cdm_write_hw_reg(
           v14,
           *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 232) + 8 * v12 + 8) + 4LL),
           a3 & 0xFFFFF | (a4 << 24) | v15) )
    {
      v13 = 1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_bl_write",
        827,
        "Failed to write CDM BL len");
    }
  }
  return v13;
}
