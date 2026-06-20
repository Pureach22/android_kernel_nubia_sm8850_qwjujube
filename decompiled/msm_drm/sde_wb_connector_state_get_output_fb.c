__int64 __fastcall sde_wb_connector_state_get_output_fb(_QWORD *a1)
{
  if ( a1 && *a1 && *(_DWORD *)(*a1 + 156LL) == 15 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    return a1[55];
  }
  else
  {
    printk(&unk_223EAA, "sde_wb_connector_state_get_output_fb");
    return 0;
  }
}
