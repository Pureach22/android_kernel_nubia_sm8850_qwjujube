__int64 __fastcall dsi_display_hfi_panel_enable_supplies(__int64 a1, char a2)
{
  __int64 v2; // x8
  unsigned int v5; // w20
  const char *v6; // x2

  v2 = *(_QWORD *)(a1 + 264);
  if ( v2 )
  {
    mutex_lock(v2 + 1040);
    if ( (a2 & 1) != 0 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2224LL) & 1) == 0 )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: powering on panel\n");
        v5 = dsi_panel_power_on(*(_QWORD *)(a1 + 264));
        if ( !v5 )
        {
          *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2224LL) = 1;
          goto LABEL_12;
        }
        v6 = "*ERROR* [msm-dsi-error]: dsi panel failed to enable power supplies\n";
        goto LABEL_10;
      }
    }
    else if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2224LL) )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: powering off panel\n");
      v5 = dsi_panel_power_off(*(_QWORD *)(a1 + 264));
      if ( !v5 )
      {
        *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2224LL) = 0;
        goto LABEL_12;
      }
      v6 = "*ERROR* [msm-dsi-error]: dsi panel failed to disable power supplies\n";
LABEL_10:
      drm_dev_printk(0, &unk_248D72, v6);
LABEL_12:
      mutex_unlock(*(_QWORD *)(a1 + 264) + 1040LL);
      return v5;
    }
    v5 = 0;
    goto LABEL_12;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid panel\n");
  return (unsigned int)-22;
}
