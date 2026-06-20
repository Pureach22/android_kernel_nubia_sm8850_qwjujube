__int64 __fastcall dsi_display_mgr_panel_pre_prepare(__int64 a1)
{
  __int64 *v3; // x8
  __int64 *v4; // x20
  __int64 *v5; // x21
  unsigned int v6; // w0
  unsigned int v7; // w19

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2212LL) & 1) == 0 )
    return dsi_panel_pre_prepare(*(_QWORD *)(a1 + 264));
  mutex_lock(&unk_29BAC8);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2224LL) & 1) != 0 )
    goto LABEL_4;
  v3 = &disp_mgr;
  while ( 1 )
  {
    v3 = (__int64 *)*v3;
    if ( v3 == &disp_mgr )
      break;
    if ( *((_BYTE *)v3 + 800) == 1 )
    {
      v4 = v3 - 6;
      goto LABEL_12;
    }
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: master display not found\n");
  v4 = nullptr;
LABEL_12:
  v5 = &disp_mgr;
  do
  {
    v5 = (__int64 *)*v5;
    if ( v5 == &disp_mgr )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: slave display not found\n");
LABEL_20:
      mutex_unlock(&unk_29BAC8);
      return 4294967274LL;
    }
  }
  while ( (v5[100] & 1) != 0 );
  if ( !v4 || v5 == &_ksymtab_dss_reg_dump )
    goto LABEL_20;
  v6 = dsi_panel_pre_prepare(v4[33]);
  if ( v6 )
  {
    v7 = v6;
    mutex_unlock(&unk_29BAC8);
    return v7;
  }
  *(_BYTE *)(v4[33] + 2224) = 1;
  *(_BYTE *)(v5[27] + 2224) = 1;
LABEL_4:
  mutex_unlock(&unk_29BAC8);
  return 0;
}
