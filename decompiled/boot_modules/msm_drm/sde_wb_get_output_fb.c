__int64 __fastcall sde_wb_get_output_fb(__int64 a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x20

  if ( a1 && *(_QWORD *)(a1 + 96) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    mutex_lock(a1 + 48);
    v2 = *(_QWORD **)(*(_QWORD *)(a1 + 96) + 2512LL);
    if ( v2 && *v2 && *(_DWORD *)(*v2 + 156LL) == 15 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "\n");
      v3 = v2[55];
    }
    else
    {
      printk(&unk_223EAA, "sde_wb_connector_state_get_output_fb");
      v3 = 0;
    }
    mutex_unlock(a1 + 48);
  }
  else
  {
    printk(&unk_223EAA, "sde_wb_get_output_fb");
    return 0;
  }
  return v3;
}
