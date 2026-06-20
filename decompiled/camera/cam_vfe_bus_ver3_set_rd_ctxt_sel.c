_QWORD *__fastcall cam_vfe_bus_ver3_set_rd_ctxt_sel(_QWORD *result, int a2)
{
  __int64 v2; // x9
  __int64 v3; // x19
  unsigned int v4; // w20
  _QWORD *v5; // [xsp+18h] [xbp-8h]

  v2 = result[10];
  if ( (*(_BYTE *)(v2 + 232) & 8) != 0 )
  {
    v3 = *(unsigned int *)(v2 + 20);
    v4 = a2 << *(_DWORD *)(v2 + 84);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v5 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_set_rd_ctxt_sel",
        5036,
        "AHB write for RD ctxt: %u, reg: 0x%x, val: 0x%x, VFE: %u",
        a2,
        v3,
        v4,
        *(_DWORD *)(result[3] + 4LL));
      result = v5;
    }
    return (_QWORD *)cam_io_w_mb(v4, result[2] + v3);
  }
  else if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       debug_mdl & 8,
                       4,
                       "cam_vfe_bus_ver3_set_rd_ctxt_sel",
                       5027,
                       "Skipping read select for old hardware");
  }
  return result;
}
