__int64 __fastcall debugfs_alter_esd_check_mode(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  unsigned __int64 v8; // x0
  const char *v9; // x19
  size_t v10; // x22
  __int64 v11; // x23
  int configs; // w0

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v8 = _kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 256);
  v9 = (const char *)v8;
  if ( v8 < 0x11 )
    return -12;
  if ( a3 >= 0xFF )
    v10 = 255;
  else
    v10 = a3;
  _check_object_size(v8, v10, 0);
  if ( inline_copy_from_user_7((__int64)v9, a2, v10) )
    goto LABEL_11;
  v9[v10] = 0;
  v11 = *(_QWORD *)(v4 + 264);
  if ( !v11 || *(_BYTE *)(v11 + 1720) != 1 )
    goto LABEL_11;
  if ( !strcmp(v9, "te_signal_check\n") )
  {
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: TE based ESD check for panels is not allowed\n");
LABEL_11:
    LODWORD(a3) = -22;
    goto LABEL_12;
  }
  if ( strcmp(v9, "reg_read\n") )
  {
LABEL_18:
    if ( !strcmp(v9, "esd_sw_sim_success\n") )
      *(_DWORD *)(v11 + 1724) = 4;
    if ( !strcmp(v9, "esd_sw_sim_failure\n") )
      *(_DWORD *)(v11 + 1724) = 5;
    LODWORD(a3) = v10;
    goto LABEL_12;
  }
  drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: ESD check is switched to reg read by user\n");
  configs = dsi_panel_parse_esd_reg_read_configs(*(_QWORD *)(v4 + 264));
  if ( !configs )
  {
    *(_DWORD *)(v11 + 1724) = 0;
    if ( (dsi_display_is_te_based_esd(v4) & 1) != 0 )
      dsi_display_change_te_irq_status(v4, 0);
    goto LABEL_18;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to alter esd check mode,rc=%d\n", configs);
LABEL_12:
  kfree(v9);
  return (int)a3;
}
