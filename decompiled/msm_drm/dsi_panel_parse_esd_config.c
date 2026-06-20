__int64 __fastcall dsi_panel_parse_esd_config(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, const char *); // x9
  __int64 v3; // x0
  char v4; // w0
  unsigned int (__fastcall *v5)(__int64, const char *, char **); // x8
  __int64 v6; // x0
  __int64 result; // x0
  const char *v8; // x20
  const char *v9; // x4
  int v10; // w8
  int configs; // w0
  unsigned int v12; // w20
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v3 = *(_QWORD *)(a1 + 1816);
  s1[0] = nullptr;
  *(_DWORD *)(a1 + 1724) = 6;
  if ( *((_DWORD *)v2 - 1) != -834495637 )
    __break(0x8229u);
  v4 = v2(v3, "qcom,esd-check-enabled");
  *(_BYTE *)(a1 + 1720) = v4 & 1;
  if ( (v4 & 1) == 0 )
    goto LABEL_19;
  v5 = *(unsigned int (__fastcall **)(__int64, const char *, char **))(a1 + 1880);
  v6 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v5 - 1) != 173720059 )
    __break(0x8228u);
  if ( !v5(v6, "qcom,mdss-dsi-panel-status-check-mode", s1) )
  {
    v8 = s1[0];
    if ( !strcmp(s1[0], "bta_check") )
    {
      v9 = "bta_trigger";
      v10 = 1;
    }
    else
    {
      if ( !strcmp(v8, "reg_read") )
      {
        *(_DWORD *)(a1 + 1724) = 0;
        configs = dsi_panel_parse_esd_reg_read_configs(a1);
        if ( configs )
        {
          v12 = configs;
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: failed to parse esd reg read mode params, rc=%d\n",
            configs);
          result = v12;
          goto LABEL_9;
        }
        v9 = "register_read";
        goto LABEL_18;
      }
      if ( !strcmp(v8, "te_signal_check") )
      {
        v10 = *(_DWORD *)(a1 + 1352);
        if ( v10 != 2 )
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: TE-ESD not valid for video mode\n");
          goto LABEL_8;
        }
        v9 = "te_check";
      }
      else if ( !strcmp(v8, "rw_low_detection") )
      {
        v9 = nullptr;
        v10 = 3;
      }
      else
      {
        if ( strcmp(v8, "esd_sw_sim_success") )
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: No valid panel-status-check-mode string\n");
          goto LABEL_8;
        }
        v9 = "sim_success";
        v10 = 4;
      }
    }
    *(_DWORD *)(a1 + 1724) = v10;
LABEL_18:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: ESD enabled with mode: %s\n", v9);
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: status check method not defined!\n");
LABEL_8:
  result = 4294967274LL;
LABEL_9:
  *(_BYTE *)(a1 + 1720) = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
