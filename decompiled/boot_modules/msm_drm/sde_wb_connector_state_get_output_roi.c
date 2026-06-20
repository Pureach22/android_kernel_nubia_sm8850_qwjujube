__int64 __fastcall sde_wb_connector_state_get_output_roi(_QWORD *a1, _WORD *a2)
{
  __int64 result; // x0

  if ( a1 && a2 && *a1 && *(_DWORD *)(*a1 + 156LL) == 15 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    result = 0;
    *a2 = a1[116];
    a2[1] = a1[120];
    a2[2] = a1[124];
    a2[3] = a1[128];
  }
  else
  {
    printk(&unk_223EAA, "sde_wb_connector_state_get_output_roi");
    return 4294967274LL;
  }
  return result;
}
