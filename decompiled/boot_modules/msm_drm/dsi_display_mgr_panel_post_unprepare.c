__int64 __fastcall dsi_display_mgr_panel_post_unprepare(__int64 a1)
{
  __int64 *v3; // x8
  __int64 *v4; // x8
  __int64 *v5; // x9
  int v6; // w0
  __int64 v7; // x8
  unsigned int v8; // w19

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 1221) & 1) != 0 )
    {
      return 0;
    }
    else if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2212LL) & 1) != 0 )
    {
      mutex_lock(&unk_29BAC8);
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
          v6 = -22;
          goto LABEL_21;
        }
      }
      while ( (v5[100] & 1) != 0 );
      v6 = -22;
      if ( v4 )
      {
        if ( v5 != &_ksymtab_dss_reg_dump )
        {
          v6 = 0;
          *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2224LL) = 0;
          v7 = v4[33];
          if ( (*(_BYTE *)(v7 + 2224) & 1) == 0 )
          {
            if ( (*(_BYTE *)(v5[27] + 2224) & 1) != 0 )
              v6 = 0;
            else
              v6 = dsi_panel_post_unprepare(v7);
          }
        }
      }
LABEL_21:
      v8 = v6;
      mutex_unlock(&unk_29BAC8);
      return v8;
    }
    else
    {
      return dsi_panel_post_unprepare(*(_QWORD *)(a1 + 264));
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
    return 4294967274LL;
  }
}
