__int64 __fastcall dsi_display_mgr_panel_post_enable(__int64 a1)
{
  __int64 v1; // x8
  __int64 *v2; // x8
  __int64 *v3; // x21
  __int64 *v5; // x20
  __int64 v6; // x0
  int v7; // w0
  unsigned int v8; // w19

  if ( !a1 || (v1 = *(_QWORD *)(a1 + 264)) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
    return 4294967274LL;
  }
  if ( *(_BYTE *)(v1 + 2212) != 1 || (*(_BYTE *)(v1 + 2232) & 1) == 0 )
    return dsi_panel_post_enable(*(_QWORD *)(a1 + 264));
  if ( *(_BYTE *)(a1 + 848) != 1 )
    return 0;
  mutex_lock(&unk_29BAC8);
  v2 = &disp_mgr;
  while ( 1 )
  {
    v2 = (__int64 *)*v2;
    if ( v2 == &disp_mgr )
      break;
    if ( *((_BYTE *)v2 + 800) == 1 )
    {
      v3 = v2 - 6;
      goto LABEL_15;
    }
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: master display not found\n");
  v3 = nullptr;
LABEL_15:
  v5 = &disp_mgr;
  do
  {
    v5 = (__int64 *)*v5;
    if ( v5 == &disp_mgr )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: slave display not found\n");
LABEL_28:
      mutex_unlock(&unk_29BAC8);
      return 4294967274LL;
    }
  }
  while ( (v5[100] & 1) != 0 );
  if ( !v3 )
    goto LABEL_28;
  if ( v5 == &_ksymtab_dss_reg_dump )
    goto LABEL_28;
  v6 = v3[33];
  if ( !v6 || !v5[27] )
    goto LABEL_28;
  v7 = dsi_panel_post_enable(v6);
  if ( v7 )
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] panel post-enable failed on master, rc=%d\n",
      (const char *)v3[4],
      v7);
  v8 = dsi_panel_post_enable(v5[27]);
  if ( v8 )
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] panel post-enable failed on slave, rc=%d\n",
      (const char *)*(v5 - 2),
      v8);
  mutex_unlock(&unk_29BAC8);
  return v8;
}
