__int64 __fastcall cam_sfe_bus_rd_out_done_bottom_half(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w20
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(_DWORD *)(a2 + 20);
  v5[0] = a2;
  cam_sfe_bus_rd_put_evt_payload(*(_QWORD *)(v2 + 8), v5);
  if ( (v3 & 2) != 0 && (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_rd_out_done_bottom_half",
      733,
      "Received SFE:%d BUS RD RUP",
      **(_DWORD **)(v2 + 8));
    if ( (v3 & 4) == 0 )
      goto LABEL_8;
  }
  else if ( (v3 & 4) == 0 )
  {
    goto LABEL_8;
  }
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_rd_out_done_bottom_half",
      737,
      "Received SFE:%d BUS RD0 BUF DONE",
      **(_DWORD **)(v2 + 8));
LABEL_8:
  if ( (v3 & 8) != 0 && (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_rd_out_done_bottom_half",
      741,
      "Received SFE:%d BUS RD1 BUF DONE",
      **(_DWORD **)(v2 + 8));
    if ( (v3 & 0x10) == 0 )
      goto LABEL_15;
  }
  else if ( (v3 & 0x10) == 0 )
  {
    goto LABEL_15;
  }
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_rd_out_done_bottom_half",
      745,
      "Received SFE:%d BUS RD2 BUF DONE",
      **(_DWORD **)(v2 + 8));
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return 4294967274LL;
}
