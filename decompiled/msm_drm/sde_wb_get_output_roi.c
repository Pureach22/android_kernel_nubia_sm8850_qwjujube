__int64 __fastcall sde_wb_get_output_roi(__int64 a1, _WORD *a2)
{
  _QWORD *v4; // x22
  unsigned int v5; // w21

  if ( a1 && a2 && *(_QWORD *)(a1 + 96) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    mutex_lock(a1 + 48);
    v4 = *(_QWORD **)(*(_QWORD *)(a1 + 96) + 2512LL);
    if ( v4 && *v4 && *(_DWORD *)(*v4 + 156LL) == 15 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "\n");
      v5 = 0;
      *a2 = v4[116];
      a2[1] = v4[120];
      a2[2] = v4[124];
      a2[3] = v4[128];
    }
    else
    {
      printk(&unk_223EAA, "sde_wb_connector_state_get_output_roi");
      v5 = -22;
    }
    mutex_unlock(a1 + 48);
  }
  else
  {
    printk(&unk_223EAA, "sde_wb_get_output_roi");
    return (unsigned int)-22;
  }
  return v5;
}
