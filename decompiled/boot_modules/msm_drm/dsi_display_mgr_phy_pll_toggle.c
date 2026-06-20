__int64 __fastcall dsi_display_mgr_phy_pll_toggle(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 *v5; // x8
  __int64 *v6; // x19
  unsigned int v7; // w9
  __int64 v8; // x0
  __int64 v9; // x21
  int v10; // w8
  unsigned int v11; // w19

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2212LL) & 1) == 0 )
  {
    if ( (a2 & 1) != 0 )
    {
      ((void (*)(void))dsi_display_phy_pll_toggle)();
      return ((__int64 (__fastcall *)(__int64, _QWORD))dsi_display_set_clk_src)(a1, 0);
    }
    else
    {
      ((void (*)(void))dsi_display_set_clk_src)();
      return ((__int64 (__fastcall *)(__int64, _QWORD))dsi_display_phy_pll_toggle)(a1, 0);
    }
  }
  v4 = mutex_lock(&unk_29BAC8);
  v5 = &disp_mgr;
  do
  {
    v5 = (__int64 *)*v5;
    if ( v5 == &disp_mgr )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: master display not found\n");
      v11 = -22;
LABEL_25:
      mutex_unlock(&unk_29BAC8);
      return v11;
    }
  }
  while ( (v5[100] & 1) == 0 );
  v6 = v5 - 6;
  if ( v5 == &_ksymtab_dss_reg_dump )
  {
    v11 = -22;
    goto LABEL_25;
  }
  v7 = *(_DWORD *)(a1 + 836);
  if ( v7 < 3 )
  {
    v8 = a1;
    v9 = *(_QWORD *)(v5[6 * v7 + 18] + 1344);
    if ( !v9 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] PLL res not found\n", *(const char **)(a1 + 32));
      mutex_unlock(&unk_29BAC8);
      return 4294967274LL;
    }
    v10 = *(_DWORD *)(v9 + 184);
    if ( (a2 & 1) != 0 )
    {
      if ( !v10 )
      {
        ((void (__fastcall *)(__int64 *, __int64))dsi_display_phy_pll_toggle)(v6, 1);
        v8 = a1;
      }
      ((void (__fastcall *)(__int64, _QWORD))dsi_display_set_clk_src)(v8, 0);
      v11 = 0;
      ++*(_DWORD *)(v9 + 184);
    }
    else
    {
      if ( v10 )
      {
        *(_DWORD *)(v9 + 184) = v10 - 1;
        ((void (__fastcall *)(__int64, __int64))dsi_display_set_clk_src)(a1, 1);
        if ( !*(_DWORD *)(v9 + 184) )
          ((void (__fastcall *)(__int64 *, _QWORD))dsi_display_phy_pll_toggle)(v6, 0);
      }
      else
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: unbalanced pll refcount\n");
      }
      v11 = 0;
    }
    goto LABEL_25;
  }
  __break(0x5512u);
  return dsi_display_mgr_panel_pre_prepare(v4);
}
